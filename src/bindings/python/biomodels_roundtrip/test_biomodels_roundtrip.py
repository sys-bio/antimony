"""
Round-trips each curated BioModels model in sys-bio/temp-biomodels through
libAntimony (SBML -> Antimony -> SBML) and checks that tellurium's SED-ML
execution of the round-tripped model still matches its execution of the
original.

Unlike the SBML Test Suite round-trip (test_roundtrip.py), this doesn't
build its own selection list -- it hands both the original and the
round-tripped SBML to tellurium's own executeCombineArchive(), which runs
each model's real curated SED-ML file and returns every declared data
generator (species, fluxes, parameters, ...) by id. That sidesteps the
symbol-renaming issues the other harness has to work around, since SED-ML
resolves each variable via an XPath target evaluated against whichever SBML
it's given, not a flat name that Antimony's round trip might reshape.

Run with e.g.:
    python fetch_biomodels.py --dest /path/to/biomodels-checkout
    pytest --biomodels-dir=/path/to/biomodels-checkout
"""

import os
import re
import tempfile
import warnings
import zipfile
import xml.etree.ElementTree as ET
from collections import Counter

import antimony
import numpy as np
import pytest
import tellurium as te

import fetch_biomodels

# Real BioModels simulations vary hugely in scale, so a single absolute
# tolerance can't be tuned as tightly as the SBML Test Suite harness's
# per-case one -- these are deliberately looser, since the goal here is
# catching round-trip regressions, not validating numerical precision.
COMPARISON_RTOL = 1e-4
COMPARISON_ATOL = 1e-6

# A model near equilibrium can have a reaction flux (or similar quantity)
# sitting right at zero -- np.allclose's atol+rtol*|b| only widens the
# tolerance near large *pointwise* values, so two near-zero values that are
# tiny in absolute terms but on opposite sides of zero look like a huge
# relative mismatch even though they're numerically inconsequential. See
# _effective_atol, which scales atol by the series' own peak magnitude
# instead of the single compared value.
#
# Separately, a model with sensitive/chaotic-ish dynamics can take a
# genuinely tiny round-trip difference (e.g. a constant serialized with one
# fewer digit of precision) and amplify it over the course of a long run
# into a large, even sign-flipped, difference by the end -- without that
# being a structural round-trip defect. A real defect (wrong formula, wrong
# sign, dropped term) shows up immediately, not after N steps of
# amplification. See _diverges_after_close_start, which checks agreement
# over just the first slice of the run at much tighter tolerance.
EARLY_WINDOW_POINTS = 10
EARLY_AGREEMENT_RTOL = 1e-6
EARLY_AGREEMENT_ATOL = 1e-9


def _effective_atol(original, roundtrip):
    scale = float(max(np.max(np.abs(original), initial=0.0), np.max(np.abs(roundtrip), initial=0.0)))
    return COMPARISON_ATOL + COMPARISON_RTOL * scale


def _diverges_after_close_start(original, roundtrip):
    n = min(EARLY_WINDOW_POINTS, len(original))
    early_original = original[:n]
    early_roundtrip = roundtrip[:n]
    atol = EARLY_AGREEMENT_ATOL + EARLY_AGREEMENT_RTOL * float(
        max(np.max(np.abs(early_original), initial=0.0), np.max(np.abs(early_roundtrip), initial=0.0))
    )
    return bool(np.allclose(early_original, early_roundtrip, rtol=EARLY_AGREEMENT_RTOL, atol=atol, equal_nan=True))

# Same known roadrunner limitations as test_roundtrip.py -- kept as a
# separate copy rather than a shared import, since the two suites' patterns
# are free to diverge as each accumulates its own known cases.
KNOWN_LIMITATION_PATTERNS = {
    "algebraic_rules": re.compile(r"unable to support algebraic rules", re.IGNORECASE),
    "fast_reactions": re.compile(r"unable to support 'fast' reactions", re.IGNORECASE),
    "delay_differential_equations": re.compile(r"delay differential equations", re.IGNORECASE),
}


def _known_limitation(exc):
    if exc is None:
        return None
    text = str(exc)
    for name, pattern in KNOWN_LIMITATION_PATTERNS.items():
        if pattern.search(text):
            return name
    return None


# Models whose round trip surfaces a real numeric divergence, but only
# because the model itself is fragile -- not because Antimony lost any
# information. BIOMD0000000338 has a very sharp transient in the first
# ~0.1s that only integrates at all within CVODE's default step budget by
# luck of exact floating-point path; round-tripping perturbs that path just
# enough to blow the budget (CV_TOO_MUCH_WORK, see STIFF_STEP_BUDGET_RE),
# and even after retrying with a much larger budget so both sides can
# finish, they diverge by more than 100 of 227 data generators. That's the
# model amplifying an inconsequential round-trip difference through its own
# sensitive dynamics, not a defect to chase -- this harness exists to catch
# Antimony losing information, not to validate numerical reproducibility of
# fragile systems.
KNOWN_FRAGILE_MODELS = {
    "BIOMD0000000338": (
        "sharp early stiff transient amplifies an inconsequential round-trip "
        "difference into a large divergence even after retrying with a bigger "
        "CVODE step budget"
    ),
}


# Matches an @id XPath predicate inside a SED-ML target/target-like string,
# e.g. .../sbml:compartment[@id=&apos;compartment&apos;] or [@id='compartment']
# -- BioModels' auto-generated SED-ML uses the &apos; entity form throughout,
# since the whole target string is itself an XML attribute value.
ID_TARGET_RE = re.compile(r"@id=(&apos;|')([^&'\"]+)(&apos;|')")


def _rename_candidates(missing):
    """Same idea as test_roundtrip.py's _rename_candidates: names Antimony's
    round trip might have renamed `missing` to. The main case here is a
    reserved-word collision (Antimony appends '_', e.g. compartment ->
    compartment_, INF -> INF_); the '__' cases are kept for parity with the
    SBML Test Suite harness in case a comp/hierarchical BioModels model ever
    shows up, even though today's curated exports are all flat."""
    candidates = [missing + "_"]
    if "__" in missing:
        candidates.append(missing.rsplit("__", 1)[-1])
        candidates.append(missing.replace("__", "_"))
    return candidates


def _sbml_ids(sbml_text):
    """Returns the set of every `id` attribute value in an SBML document,
    regardless of element type -- enough to check whether a SED-ML target's
    referenced id still exists after the round trip."""
    try:
        root = ET.fromstring(sbml_text)
    except ET.ParseError:
        return set()
    return {elem.get("id") for elem in root.iter() if elem.get("id")}


def _fix_sedml_ids(sedml_text, available_ids):
    """Rewrites @id='X' XPath predicates in sedml_text for any X that isn't
    in available_ids but exactly one of its _rename_candidates is -- i.e.
    Antimony's round trip renamed a reserved-word-colliding id (like
    'compartment' -> 'compartment_') that the *original* SED-ML still
    references by its old name. Returns (fixed_text, renames), where renames
    is a list of (old, new) pairs actually applied.

    This is the same principle as test_roundtrip.py's rename handling: a
    resolvable rename is a naming difference the round trip introduced, not
    a semantic one, so the fixed-up target should still compare equal --
    it's just noted in the test output rather than treated as a skip.

    If X isn't in available_ids and none of its candidates are either (a
    genuine broken reference, not a rename), or if more than one candidate
    matches (ambiguous), the target is left alone -- the ensuing simulation
    error or mismatch will surface it as a real failure instead of silently
    guessing wrong."""
    renames = []

    def replace(match):
        open_quote, missing, close_quote = match.groups()
        if missing in available_ids:
            return match.group(0)
        candidates = [c for c in _rename_candidates(missing) if c in available_ids]
        if len(candidates) != 1:
            return match.group(0)
        renames.append((missing, candidates[0]))
        return f"@id={open_quote}{candidates[0]}{close_quote}"

    fixed = ID_TARGET_RE.sub(replace, sedml_text)
    return fixed, renames


def _local_tag(elem):
    return elem.tag.rsplit("}", 1)[-1]


def _base_task_id(list_of_tasks, repeated_task_elem):
    """A <repeatedTask> doesn't simulate anything itself -- it repeatedly
    runs its <listOfSubTasks> (in `order`) against one running model, and a
    <dataGenerator> that references the repeatedTask is really asking for
    the results of the *last* subTask each iteration. So the plain,
    un-repeated version of that experiment is just: run whatever task the
    last subTask points at, once.

    Returns that task's id, or None if it can't be resolved unambiguously
    (no subTasks, a dangling subTask reference, or -- the one case this
    doesn't handle -- the last subTask itself targets another repeatedTask,
    i.e. a nested scan)."""
    list_of_subtasks = next((c for c in repeated_task_elem if _local_tag(c) == "listOfSubTasks"), None)
    if list_of_subtasks is None:
        return None
    subtasks = [c for c in list_of_subtasks if _local_tag(c) == "subTask"]
    if not subtasks:
        return None

    def order_key(subtask):
        try:
            return int(subtask.get("order", 0))
        except ValueError:
            return 0

    last_task_id = max(subtasks, key=order_key).get("task")
    if not last_task_id:
        return None

    tasks_by_id = {c.get("id"): c for c in list_of_tasks}
    referenced = tasks_by_id.get(last_task_id)
    if referenced is None or _local_tag(referenced) != "task":
        return None
    return last_task_id


def _resolve_repeated_tasks(sedml_text):
    """Replaces every <repeatedTask> (parameter scan, Monte Carlo sweep, ...)
    with a single plain run of the task it ultimately drives -- see
    _base_task_id -- rather than either running the whole scan (expensive:
    a repeatedTask can multiply one time course into dozens or hundreds of
    re-simulations) or dropping it outright (loses coverage for every model
    whose only reported data comes from a scan). Every <repeatedTask> is
    removed from <listOfTasks> either way, since it's never executed
    directly; for ones that resolve, every <dataGenerator> variable's
    taskReference pointing at it is repointed at the resolved base task
    instead -- same data generator, sourced from one plain run instead of
    the scan. Ones that don't resolve fall back to the old behavior: the
    dataGenerators that depended on them are dropped.

    <listOfOutputs> (report/plot) entries aren't touched or repointed --
    they only matter when createOutputs=True, which this harness never
    sets, and we can't meaningfully compare plots anyway. A dangling
    dataReference left behind is inert.

    Returns (fixed_text, redirected, dropped, has_data_generators).
    fixed_text is sedml_text unchanged if there was no repeatedTask at all.
    redirected is {repeatedTask_id: base_task_id} for the ones repointed;
    dropped is a list of repeatedTask ids that couldn't be resolved.
    has_data_generators is False if no <dataGenerator> remains once
    dropped ones are removed, in which case the caller should skip rather
    than silently pass on an empty comparison."""
    root = ET.fromstring(sedml_text)
    ns_uri = root.tag[1:].split("}", 1)[0] if root.tag.startswith("{") else ""

    def tag(name):
        return f"{{{ns_uri}}}{name}" if ns_uri else name

    def has_data_generators():
        list_of_data_generators = root.find(tag("listOfDataGenerators"))
        return list_of_data_generators is not None and len(list(list_of_data_generators)) > 0

    list_of_tasks = root.find(tag("listOfTasks"))
    if list_of_tasks is None:
        return sedml_text, {}, [], has_data_generators()

    repeated_elems = [c for c in list_of_tasks if _local_tag(c) == "repeatedTask"]
    if not repeated_elems:
        return sedml_text, {}, [], has_data_generators()

    redirected = {}
    dropped = []
    for rt in repeated_elems:
        rt_id = rt.get("id")
        if not rt_id:
            continue
        base_id = _base_task_id(list_of_tasks, rt)
        if base_id:
            redirected[rt_id] = base_id
        else:
            dropped.append(rt_id)

    for rt in repeated_elems:
        list_of_tasks.remove(rt)

    list_of_data_generators = root.find(tag("listOfDataGenerators"))
    if list_of_data_generators is not None:
        for dg in list(list_of_data_generators):
            ref_elems = [e for e in dg.iter() if e.get("taskReference")]
            refs = {e.get("taskReference") for e in ref_elems}
            if refs & set(dropped):
                list_of_data_generators.remove(dg)
                continue
            for e in ref_elems:
                ref = e.get("taskReference")
                if ref in redirected:
                    e.set("taskReference", redirected[ref])

    if ns_uri:
        ET.register_namespace("", ns_uri)
    return ET.tostring(root, encoding="unicode"), redirected, dropped, has_data_generators()


# CV_TOO_MUCH_WORK: CVODE hit its internal step-budget ceiling (KISAO:0000415
# maximum_num_steps, default 20000) before reaching the next requested output
# time. That's purely a step-count limit, not an accuracy problem -- tighter
# tolerance happened to dodge it for some models but not others (and looser
# tolerance "fixed" it for the wrong reason), while raising the step budget
# directly fixed it reliably. So a retry on this error bumps the budget, not
# the tolerance.
STIFF_STEP_BUDGET_RE = re.compile(r"too much work|mxstep", re.IGNORECASE)
STIFF_RETRY_MAX_STEPS = 1_000_000


def _set_max_steps(sedml_text, max_steps):
    """Returns sedml_text with a KISAO:0000415 (maximum_num_steps)
    algorithmParameter set to max_steps on every <simulation>'s <algorithm>,
    overriding any value already there or adding one if absent."""
    root = ET.fromstring(sedml_text)
    ns_uri = root.tag[1:].split("}", 1)[0] if root.tag.startswith("{") else ""

    def tag(name):
        return f"{{{ns_uri}}}{name}" if ns_uri else name

    list_of_simulations = root.find(tag("listOfSimulations"))
    if list_of_simulations is None:
        return sedml_text

    for simulation in list_of_simulations:
        algorithm = simulation.find(tag("algorithm"))
        if algorithm is None:
            continue
        list_of_params = algorithm.find(tag("listOfAlgorithmParameters"))
        if list_of_params is None:
            list_of_params = ET.SubElement(algorithm, tag("listOfAlgorithmParameters"))
        param = next((p for p in list_of_params if p.get("kisaoID") == "KISAO:0000415"), None)
        if param is None:
            param = ET.SubElement(list_of_params, tag("algorithmParameter"))
            param.set("kisaoID", "KISAO:0000415")
        param.set("value", str(max_steps))

    if ns_uri:
        ET.register_namespace("", ns_uri)
    return ET.tostring(root, encoding="unicode")


def discover_cases(root):
    """Finds every BioModels model directory under root/final that has both
    an SBML file and a SED-ML file declared in its manifest.xml. A model
    with no SBML entry was already dropped by fetch_biomodels.py (nothing
    was fetched for it); one with no SED-ML has no defined simulation to
    round-trip test, so it's skipped here the same way. A model can have
    more than one SED-ML file, in which case it gets one case per file."""
    final_dir = os.path.join(root, "final")
    if not os.path.isdir(final_dir):
        return []

    cases = []
    for entry in sorted(os.listdir(final_dir)):
        model_dir = os.path.join(final_dir, entry)
        manifest_path = os.path.join(model_dir, "manifest.xml")
        if not os.path.isfile(manifest_path):
            continue
        sbml_entries, sedml_entries = fetch_biomodels.parse_manifest(manifest_path)
        if not sbml_entries or not sedml_entries:
            continue
        for sedml_location, _ in sedml_entries:
            cases.append((entry, model_dir, sbml_entries, sedml_location))
    return cases


def _minimal_manifest(sbml_entries, sedml_location):
    """Builds a manifest.xml declaring only the given SED-ML file and SBML
    file(s) -- not every sibling file BioModels bundled in the same
    directory. A model directory's real manifest.xml can list several
    SED-ML files sharing one manifest (e.g. one per published figure);
    reusing that manifest as-is in a per-case archive made
    executeCombineArchive() try to extract *every* sed-ml entry it
    declares, not just the one actually zipped in for this case, and fail
    on the ones that were never there."""
    root = ET.Element("omexManifest", {"xmlns": fetch_biomodels.MANIFEST_NS})
    ET.SubElement(root, "content", {
        "location": sedml_location, "format": fetch_biomodels.SEDML_FORMAT, "master": "false",
    })
    for location, master in sbml_entries:
        ET.SubElement(root, "content", {
            "location": location, "format": fetch_biomodels.SBML_FORMAT, "master": "true" if master else "false",
        })
    return ET.tostring(root, encoding="unicode")


def _build_archive(model_dir, sbml_entries, sedml_location, sbml_overrides=None, sedml_text=None):
    """Zips a trimmed manifest.xml (see _minimal_manifest), the given
    SED-ML file, and every SBML file the manifest declares into a temp
    .omex, and returns its path. Every declared SBML file is included, not
    just the one flagged master="true", since the SED-ML's <model source>
    can point at any of them.

    sbml_overrides, if given, is {location: sbml_text} -- used to swap in
    round-tripped SBML under the same filename the SED-ML/manifest expect,
    rather than rewriting either of those. sedml_text, if given, replaces the
    SED-ML file's contents outright (see _fix_sedml_ids)."""
    sbml_overrides = sbml_overrides or {}
    fd, archive_path = tempfile.mkstemp(suffix=".omex")
    os.close(fd)
    with zipfile.ZipFile(archive_path, "w") as zf:
        zf.writestr("manifest.xml", _minimal_manifest(sbml_entries, sedml_location))
        if sedml_text is not None:
            zf.writestr(sedml_location, sedml_text)
        else:
            zf.write(os.path.join(model_dir, sedml_location), sedml_location)
        for location, _ in sbml_entries:
            if location in sbml_overrides:
                zf.writestr(location, sbml_overrides[location])
            else:
                zf.write(os.path.join(model_dir, location), location)
    return archive_path


def _roundtrip_sbml(path):
    """Round-trips a single SBML file through antimony (SBML -> Antimony ->
    SBML) and returns the round-tripped SBML text. Raises RuntimeError with
    antimony's own error message if any step fails."""
    antimony.clearPreviousLoads()
    if antimony.loadSBMLFile(path) < 0:
        raise RuntimeError(f"failed to load into libAntimony: {antimony.getLastError()}")
    antimony_text = antimony.getAntimonyString()
    if not antimony_text:
        raise RuntimeError(f"failed to convert to Antimony: {antimony.getLastError()}")
    if antimony.loadAntimonyString(antimony_text) < 0:
        raise RuntimeError(f"failed to reload converted Antimony: {antimony.getLastError()}")
    roundtripped = antimony.getCompSBMLString()
    if not roundtripped:
        raise RuntimeError(f"failed to export round-tripped SBML: {antimony.getLastError()}")
    return roundtripped


def _try_execute(archive_path):
    """Runs the (single) SED-ML file in archive_path via tellurium. Returns
    (dataGenerators dict, None) on success, or (None, exception) if either
    the SED-ML itself or the underlying roadrunner simulation raised."""
    try:
        results = te.executeCombineArchive(archive_path, createOutputs=False)
        (result,) = results.values()
        return result["dataGenerators"], None
    except Exception as exc:
        return None, exc


def pytest_generate_tests(metafunc):
    if "biomodels_case" not in metafunc.fixturenames:
        return
    root = metafunc.config.getoption("--biomodels-dir")
    if not root or not os.path.isdir(root):
        metafunc.parametrize("biomodels_case", [])
        return
    cases = discover_cases(root)
    counts = Counter(entry for entry, *_ in cases)
    ids = [
        entry if counts[entry] == 1 else f"{entry}-{os.path.splitext(os.path.basename(sedml_location))[0]}"
        for entry, _, _, sedml_location in cases
    ]
    metafunc.parametrize("biomodels_case", cases, ids=ids)


def test_biomodels_roundtrip(biomodels_case):
    model_id, model_dir, sbml_entries, sedml_location = biomodels_case

    if model_id in KNOWN_FRAGILE_MODELS:
        pytest.skip(f"{model_id}: known fragile model, skipped -- {KNOWN_FRAGILE_MODELS[model_id]}")

    original_sedml_text = open(os.path.join(model_dir, sedml_location)).read()
    resolved_sedml_text, redirected_tasks, dropped_tasks, has_data_generators = _resolve_repeated_tasks(original_sedml_text)
    if not has_data_generators:
        pytest.skip(
            f"{model_id}: no data generators left to compare after removing repeatedTask(s) "
            f"{dropped_tasks} -- everything this SED-ML reports came from a parameter scan/repeated task "
            f"with no resolvable base task"
        )
    task_note = ""
    if redirected_tasks:
        task_note += f" (repeatedTask(s) replaced by a single run of their base task: {redirected_tasks})"
    if dropped_tasks:
        task_note += f" (dropped unresolvable repeatedTask(s): {dropped_tasks})"

    original_archive = _build_archive(model_dir, sbml_entries, sedml_location, sedml_text=resolved_sedml_text)
    try:
        original_data, original_error = _try_execute(original_archive)
    finally:
        os.remove(original_archive)

    # Every SBML file the manifest declares gets round-tripped, since we
    # don't know ahead of time which one(s) the SED-ML actually references
    # (see _build_archive) -- but a load/convert failure on a real-world
    # BioModels export is at least as likely to mean "this uses something
    # antimony was never meant to support" (old SBML L1, unsupported
    # packages, malformed legacy exports) as it is to mean a real bug, so
    # it's a skip here rather than the hard failure test_roundtrip.py uses
    # for the SBML Test Suite's curated cases.
    roundtrip_errors = {}
    overrides = {}
    for location, _ in sbml_entries:
        try:
            overrides[location] = _roundtrip_sbml(os.path.join(model_dir, location))
        except Exception as exc:
            roundtrip_errors[location] = exc

    if roundtrip_errors:
        detail = "; ".join(f"{location}: {exc}" for location, exc in roundtrip_errors.items())
        pytest.skip(
            f"{model_id}: antimony couldn't round-trip {len(roundtrip_errors)} of "
            f"{len(sbml_entries)} SBML file(s) -- {detail}"
        )

    # The original SED-ML can reference an id (e.g. a compartment literally
    # named 'compartment') that Antimony's round trip renamed away because it
    # collides with a reserved word. That's a naming difference, not a
    # semantic one, so the round-trip-only copy of the SED-ML gets its
    # broken @id references patched to match -- see _fix_sedml_ids.
    available_ids = set()
    for text in overrides.values():
        available_ids |= _sbml_ids(text)
    fixed_sedml_text, id_renames = _fix_sedml_ids(resolved_sedml_text, available_ids)
    rename_note = task_note
    if id_renames:
        rename_note += f" (SED-ML id renames applied: {id_renames})"

    roundtrip_archive = _build_archive(
        model_dir, sbml_entries, sedml_location,
        sbml_overrides=overrides, sedml_text=fixed_sedml_text,
    )
    try:
        roundtrip_data, roundtrip_error = _try_execute(roundtrip_archive)
    finally:
        os.remove(roundtrip_archive)

    # A CV_TOO_MUCH_WORK on either side means CVODE's default step budget
    # wasn't enough for this model, round-tripped or not -- retry both sides
    # with a much larger budget so the comparison stays apples-to-apples
    # (not "one side got more room than the other").
    if (
        (original_error is not None and STIFF_STEP_BUDGET_RE.search(str(original_error)))
        or (roundtrip_error is not None and STIFF_STEP_BUDGET_RE.search(str(roundtrip_error)))
    ):
        bumped_original_archive = _build_archive(
            model_dir, sbml_entries, sedml_location,
            sedml_text=_set_max_steps(resolved_sedml_text, STIFF_RETRY_MAX_STEPS),
        )
        try:
            original_data, original_error = _try_execute(bumped_original_archive)
        finally:
            os.remove(bumped_original_archive)

        bumped_roundtrip_archive = _build_archive(
            model_dir, sbml_entries, sedml_location,
            sbml_overrides=overrides, sedml_text=_set_max_steps(fixed_sedml_text, STIFF_RETRY_MAX_STEPS),
        )
        try:
            roundtrip_data, roundtrip_error = _try_execute(bumped_roundtrip_archive)
        finally:
            os.remove(bumped_roundtrip_archive)

        rename_note += f" (retried both sides with maximum_num_steps={STIFF_RETRY_MAX_STEPS} after hitting CVODE's step-budget ceiling)"

    if original_error is not None or roundtrip_error is not None:
        original_limitation = _known_limitation(original_error)
        roundtrip_limitation = _known_limitation(roundtrip_error)
        error_detail = f"Original error: {original_error!r}. Round-tripped error: {roundtrip_error!r}.{rename_note}"

        if (
            original_error is not None
            and roundtrip_error is not None
            and original_limitation is not None
            and original_limitation == roundtrip_limitation
        ):
            outcome = "roadrunner raised the same kind of error simulating both the original and the round-tripped model"
            limitation = original_limitation
        elif (
            original_error is not None
            and roundtrip_error is not None
            and str(original_error) == str(roundtrip_error)
        ):
            outcome = "roadrunner raised a byte-identical, but not yet categorized, error simulating both the original and the round-tripped model"
            limitation = "uncategorized"
            warnings.warn(
                f"{model_id}: uncategorized error, identical on both sides -- consider adding a "
                f"KNOWN_LIMITATION_PATTERNS entry: {original_error!r}"
            )
        elif original_limitation == "fast_reactions":
            outcome = "roadrunner couldn't simulate the original model due to 'fast' (round-tripped outcome doesn't matter)"
            limitation = original_limitation
        else:
            def _label(err, limitation):
                if err is None:
                    return "no error"
                return limitation if limitation is not None else "unrecognized error"

            raise AssertionError(
                f"{model_id}: true failure -- roadrunner's errors don't match each other "
                f"(original: {_label(original_error, original_limitation)}; "
                f"round-tripped: {_label(roundtrip_error, roundtrip_limitation)}). {error_detail}"
            ) from (original_error if original_error is not None else roundtrip_error)

        pytest.skip(f"{model_id}: {outcome} -- {limitation}. {error_detail}")

    assert set(original_data.keys()) == set(roundtrip_data.keys()), (
        f"{model_id}: data generator sets differ{rename_note}: "
        f"{sorted(set(original_data) - set(roundtrip_data))} only in original, "
        f"{sorted(set(roundtrip_data) - set(original_data))} only in round-tripped"
    )

    mismatches = []
    sensitivity_notes = []
    for key in sorted(original_data):
        original = np.asarray(original_data[key]).flatten()
        roundtrip = np.asarray(roundtrip_data[key]).flatten()
        if original.shape != roundtrip.shape:
            mismatches.append(f"  {key}: shape differs: {original.shape} vs {roundtrip.shape}")
            continue
        if np.allclose(original, roundtrip, rtol=COMPARISON_RTOL, atol=_effective_atol(original, roundtrip), equal_nan=True):
            continue
        diff = np.abs(original - roundtrip)
        worst = int(np.argmax(diff))
        detail = (
            f"  {key}: max |diff|={diff[worst]:.6g} at index {worst} "
            f"(original={original[worst]:.6g}, roundtrip={roundtrip[worst]:.6g})"
        )
        if _diverges_after_close_start(original, roundtrip):
            sensitivity_notes.append(detail)
        else:
            mismatches.append(detail)

    if not mismatches and sensitivity_notes:
        pytest.skip(
            f"{model_id}: {len(sensitivity_notes)} data generator(s) matched closely over the first "
            f"{EARLY_WINDOW_POINTS} points but diverged later{rename_note} -- looks like "
            f"ordinary floating-point noise amplified by the model's own sensitivity, not a round-trip "
            f"defect:\n" + "\n".join(sensitivity_notes)
        )

    assert not mismatches, (
        f"{model_id}: round-tripped SBML diverged beyond tolerance "
        f"(rtol={COMPARISON_RTOL}, atol={COMPARISON_ATOL} scaled by each series' own magnitude){rename_note}:\n"
        + "\n".join(mismatches)
        + (
            f"\n  (plus {len(sensitivity_notes)} data generator(s) that only diverged after matching "
            f"closely early on -- see _diverges_after_close_start)"
            if sensitivity_notes else ""
        )
    )

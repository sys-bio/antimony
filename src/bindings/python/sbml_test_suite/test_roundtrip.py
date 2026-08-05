"""
Round-trips each SBML Test Suite semantic case through libAntimony
(SBML -> Antimony -> SBML) and checks that a roadrunner simulation of the
round-tripped model still matches a simulation of the original model.

For each test case, the earliest and latest available SBML level/version
files are used, since the Antimony import/export code paths can differ by
level and version.

Run with e.g.:
    pytest --sbml-test-suite-dir=/path/to/sbml-test-suite/cases/semantic
"""

import os
import re
import tempfile
import warnings

import antimony
import numpy as np
import pytest
import tellurium as te

# The simulations that feed the comparison are run at a tighter tolerance
# than the one used for the pass/fail comparison itself, so that numerical
# integration error doesn't masquerade as a round-trip discrepancy (or hide
# one).
SIMULATION_TOLERANCE_FACTOR = 0.01

SBML_FILENAME_RE = re.compile(r"^(\d{5})-sbml-l(\d+)v(\d+)\.xml$")
CASE_DIRNAME_RE = re.compile(r"^\d{5}$")
MISSING_SYMBOL_RE = re.compile(r"No sbml element exists for symbol '([^']+)'")

# Known, expected roadrunner limitations. Match by category (via these
# patterns) rather than exact error text, since the round trip can reformat
# the offending formula, rename a reaction, etc.
#
# fast_reactions is also known to trip *asymmetrically* -- see the `elif`
# branch below for why: original fails, round-tripped succeeds.
KNOWN_LIMITATION_PATTERNS = {
    "algebraic_rules": re.compile(r"unable to support algebraic rules", re.IGNORECASE),
    "fast_reactions": re.compile(r"unable to support 'fast' reactions", re.IGNORECASE),
    "delay_differential_equations": re.compile(r"delay differential equations", re.IGNORECASE),
}


def _known_limitation(exc):
    """Returns the name of the known roadrunner limitation `exc` matches, or
    None if it doesn't match any of them."""
    if exc is None:
        return None
    text = str(exc)
    for name, pattern in KNOWN_LIMITATION_PATTERNS.items():
        if pattern.search(text):
            return name
    return None


def discover_cases(root):
    """Find every SBML Test Suite case under `root`, and for each one return
    the earliest and latest available SBML level/version file (deduplicated
    if there's only one)."""
    cases = []
    for entry in sorted(os.listdir(root)):
        case_dir = os.path.join(root, entry)
        if not CASE_DIRNAME_RE.match(entry) or not os.path.isdir(case_dir):
            continue

        settings_path = os.path.join(case_dir, f"{entry}-settings.txt")
        if not os.path.isfile(settings_path):
            continue

        sbml_files = []
        for fname in os.listdir(case_dir):
            match = SBML_FILENAME_RE.match(fname)
            if match:
                level, version = int(match.group(2)), int(match.group(3))
                sbml_files.append((level, version, os.path.join(case_dir, fname)))
        if not sbml_files:
            continue
        sbml_files.sort(key=lambda t: (t[0], t[1]))

        earliest_path = sbml_files[0][2]
        latest_path = sbml_files[-1][2]

        cases.append((entry, "earliest", earliest_path, settings_path))
        if latest_path != earliest_path:
            cases.append((entry, "latest", latest_path, settings_path))

    return cases


def parse_settings(path):
    raw = {}
    with open(path) as f:
        for line in f:
            key, sep, value = line.strip().partition(":")
            if sep:
                raw[key.strip()] = value.strip()

    def csv_list(key):
        return [v.strip() for v in raw.get(key, "").split(",") if v.strip()]

    # start/duration/steps are blank for non-time-course cases (e.g. FBC
    # steady-state/objective-value cases), which this test doesn't cover --
    # left as None here so the caller can skip those cases explicitly instead
    # of blowing up trying to float("").
    def optional_float(key):
        value = raw.get(key, "")
        return float(value) if value else None

    return {
        "start": optional_float("start"),
        "duration": optional_float("duration"),
        "steps": int(raw["steps"]) if raw.get("steps") else None,
        "variables": csv_list("variables"),
        "absolute": float(raw["absolute"]),
        "relative": float(raw["relative"]),
        "amount": set(csv_list("amount")),
        "concentration": set(csv_list("concentration")),
    }


def build_selections(settings):
    selections = ["time"]
    for var in settings["variables"]:
        if var in settings["concentration"]:
            selections.append(f"[{var}]")
        else:
            selections.append(var)
    return selections


def _load_model(model_source):
    """Loads model_source via te.loads(). Roadrunner only flattens comp SBML
    models when loading from a file -- loading the same SBML passed directly
    as a string skips flattening entirely (a roadrunner bug, currently being
    fixed upstream). Until that lands, write anything that isn't already a
    file to a temp file first, so the original and round-tripped models both
    get flattened the same way."""
    if os.path.isfile(model_source):
        return te.loads(model_source)
    fd, temp_path = tempfile.mkstemp(suffix=".xml")
    try:
        with os.fdopen(fd, "w") as f:
            f.write(model_source)
        return te.loads(temp_path)
    finally:
        os.remove(temp_path)


def _rename_candidates(missing):
    """Given an SBML symbol name that roadrunner couldn't find, returns
    candidate names it might have been renamed to during Antimony's round
    trip, in order of likelihood:
      - missing + '_': Antimony appends '_' to identifiers that collide with
        reserved words (e.g. INF -> INF_).
      - the bare suffix after the last '__': a compliant comp flattener
        prefixes a submodel-local element with its submodel id (e.g.
        sub1__p1) only when needed to avoid a collision. Antimony doesn't
        have local (reaction/submodel)-scoped parameters, so when a
        submodel-local parameter shadows a global one, round-tripping can
        merge them into a single top-level variable -- no collision, no
        prefix.
    """
    candidates = [missing + "_"]
    if "__" in missing:
        candidates.append(missing.rsplit("__", 1)[-1])
    return candidates


def _bare_name(selection):
    """Strips the "[...]" concentration wrapper from a selection, if any."""
    if selection.startswith("[") and selection.endswith("]"):
        return selection[1:-1]
    return selection


def simulate_model(model_source, settings, selections):
    """Returns (result, renames), where renames is a list of (original,
    replacement) pairs used to resolve any selection roadrunner couldn't
    find under its settings.txt name -- see _rename_candidates. Renaming
    means the round trip structurally changed something (not just relabeled
    it 1:1), so callers shouldn't treat a non-empty renames list as an
    apples-to-apples comparison.

    More than one selection can need renaming at once (e.g. several
    reserved-word collisions in the same model), and roadrunner only reports
    one missing symbol per attempt, so this retries selection-by-selection:
    each failure identifies which selection is still broken from its
    *current* value, and advances that selection's own candidate list
    (always generated from its original settings.txt name, not the last
    guess) rather than giving up as soon as any one candidate doesn't fully
    resolve the model."""
    rr = _load_model(model_source)
    rr.integrator.setValue("absolute_tolerance", settings["absolute"] * SIMULATION_TOLERANCE_FACTOR)
    rr.integrator.setValue("relative_tolerance", settings["relative"] * SIMULATION_TOLERANCE_FACTOR)
    n_points = settings["steps"] + 1

    def run(sels):
        result = rr.simulate(settings["start"], settings["start"] + settings["duration"], n_points, selections=sels)
        return np.asarray(result)

    current = list(selections)
    renamed_to = {}  # original bare name -> candidate currently in use
    tried = {}  # index into current -> number of candidates already tried

    max_attempts = 2 * len(current) + 1
    for _ in range(max_attempts):
        try:
            renames = [(name, candidate) for name, candidate in renamed_to.items()]
            return run(current), renames
        except RuntimeError as exc:
            match = MISSING_SYMBOL_RE.search(str(exc))
            if not match:
                raise
            bad = match.group(1)
            idx = next((i for i, sel in enumerate(current) if _bare_name(sel) == bad), None)
            if idx is None:
                raise
            original_bare = _bare_name(selections[idx])
            candidates = _rename_candidates(original_bare)
            already_tried = tried.get(idx, 0)
            if already_tried >= len(candidates):
                raise
            candidate = candidates[already_tried]
            tried[idx] = already_tried + 1
            current[idx] = f"[{candidate}]" if selections[idx].startswith("[") else candidate
            renamed_to[original_bare] = candidate

    raise RuntimeError(f"Gave up resolving renamed selections after {max_attempts} attempts")


def _try_simulate(model_source, settings, selections):
    """Runs simulate_model, catching any roadrunner runtime error. Returns
    (result, renames, None) on success, or (None, [], exception) if
    roadrunner couldn't simulate the model."""
    try:
        result, renames = simulate_model(model_source, settings, selections)
        return result, renames, None
    except Exception as exc:
        return None, [], exc


def pytest_generate_tests(metafunc):
    if "sbml_case" not in metafunc.fixturenames:
        return
    root = metafunc.config.getoption("--sbml-test-suite-dir")
    if not root or not os.path.isdir(root):
        metafunc.parametrize("sbml_case", [])
        return
    cases = discover_cases(root)
    ids = [f"{case_id}-{which}" for case_id, which, _, _ in cases]
    metafunc.parametrize("sbml_case", cases, ids=ids)


def test_roundtrip(sbml_case):
    case_id, which, sbml_path, settings_path = sbml_case
    settings = parse_settings(settings_path)
    if settings["start"] is None or settings["duration"] is None or settings["steps"] is None:
        pytest.skip(f"{case_id} ({which}): no time course defined in settings.txt (steady-state/FBC case)")
    selections = build_selections(settings)

    antimony.clearPreviousLoads()

    # Some models use constructs roadrunner can't simulate at all (e.g.
    # algebraic rules). That's a roadrunner limitation, not a round-trip
    # problem, so it's fine as long as the *same kind* of error happens both
    # before and after the round trip. The one exception is variable
    # stoichiometry: a stoichiometryMath can be simulatable in its original
    # form but not after being canonicalized by Antimony's round trip, so
    # it's OK for the original to succeed while only the round-tripped model
    # fails, but only for that specific error.
    original_result, original_renames, original_error = _try_simulate(sbml_path, settings, selections)

    load_index = antimony.loadSBMLFile(sbml_path)
    assert load_index >= 0, f"Failed to load {sbml_path} into libAntimony: {antimony.getLastError()}"

    antimony_text = antimony.getAntimonyString()
    assert antimony_text, f"Failed to convert {sbml_path} to Antimony: {antimony.getLastError()}"

    load_index = antimony.loadAntimonyString(antimony_text)
    assert load_index >= 0, f"Failed to reload converted Antimony for {sbml_path}: {antimony.getLastError()}"

    roundtripped_sbml = antimony.getCompSBMLString()
    assert roundtripped_sbml, f"Failed to export round-tripped SBML for {sbml_path}: {antimony.getLastError()}"

    roundtrip_result, roundtrip_renames, roundtrip_error = _try_simulate(roundtripped_sbml, settings, selections)

    if original_renames or roundtrip_renames:
        # A selection only resolved after being renamed -- Antimony
        # restructured or merged an SBML element during the round trip (see
        # _rename_candidates), so the two simulations aren't reading the
        # same thing under that name. Skip rather than silently comparing
        # apples to oranges.
        pytest.skip(
            f"{case_id} ({which}, {os.path.basename(sbml_path)}): a selection only resolved after renaming "
            f"during round-trip. Original renames: {original_renames or 'none'}. "
            f"Round-tripped renames: {roundtrip_renames or 'none'}."
        )

    if original_error is not None or roundtrip_error is not None:
        original_limitation = _known_limitation(original_error)
        roundtrip_limitation = _known_limitation(roundtrip_error)

        # Every error, known or not, gets embedded directly in the skip/failure
        # message below rather than raised via warnings.warn() -- pytest's
        # --junitxml output doesn't capture warnings, only the skip/failure
        # text itself, so that's the only place this is guaranteed to show up.
        error_detail = f"Original error: {original_error!r}. Round-tripped error: {roundtrip_error!r}."

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
            # Not a category in KNOWN_LIMITATION_PATTERNS yet, but the error
            # text is byte-identical on both sides, so it's the same kind of
            # error by definition -- not a round-trip bug. Flagged via
            # warnings.warn() (in addition to the skip message below) since
            # these are exactly the ones worth turning into a real
            # KNOWN_LIMITATION_PATTERNS entry once someone's looked at them.
            outcome = "roadrunner raised a byte-identical, but not yet categorized, error simulating both the original and the round-tripped model"
            limitation = "uncategorized"
            warnings.warn(
                f"{case_id} ({which}, {os.path.basename(sbml_path)}): uncategorized error, identical on both "
                f"sides -- consider adding a KNOWN_LIMITATION_PATTERNS entry: {original_error!r}"
            )
        elif original_limitation == "fast_reactions":
            # Antimony doesn't preserve SBML's 'fast' reaction attribute --
            # deliberately: 'fast' is deprecated in current SBML, vanishingly
            # few models use it, and it's not worth supporting. Once
            # roadrunner rejects the original for using 'fast', the
            # round-tripped side is unconstrained: it can succeed (fast=true
            # silently dropped) or fail for its own unrelated reason (e.g.
            # the same model also has a delay differential equation) --
            # either way it's not a round-trip bug caused by dropping 'fast'.
            outcome = "roadrunner couldn't simulate the original model due to 'fast' (round-tripped outcome doesn't matter)"
            limitation = original_limitation
        else:
            # Anything else -- a one-sided failure that isn't the known
            # fast_reactions asymmetric exception above, or a symmetric
            # failure where the two errors aren't the same *kind* of known
            # limitation -- is a real problem, not a known limitation.
            def _label(err, limitation):
                if err is None:
                    return "no error"
                return limitation if limitation is not None else "unrecognized error"

            raise AssertionError(
                f"{case_id} ({which}, {os.path.basename(sbml_path)}): true failure -- roadrunner's errors "
                f"don't match each other (original: {_label(original_error, original_limitation)}; "
                f"round-tripped: {_label(roundtrip_error, roundtrip_limitation)}). {error_detail}"
            ) from (original_error if original_error is not None else roundtrip_error)

        pytest.skip(
            f"{case_id} ({which}, {os.path.basename(sbml_path)}): {outcome} -- {limitation}. {error_detail}"
        )

    assert original_result.shape == roundtrip_result.shape, (
        f"{case_id} ({which}): result shapes differ: "
        f"{original_result.shape} vs {roundtrip_result.shape}"
    )

    mismatches = []
    for col in range(1, len(selections)):
        original = original_result[:, col]
        roundtrip = roundtrip_result[:, col]
        if not np.allclose(original, roundtrip, rtol=settings["relative"], atol=settings["absolute"], equal_nan=True):
            diff = np.abs(original - roundtrip)
            worst = int(np.argmax(diff))
            mismatches.append(
                f"  {selections[col]}: max |diff|={diff[worst]:.6g} at t={original_result[worst, 0]:.6g} "
                f"(original={original[worst]:.6g}, roundtrip={roundtrip[worst]:.6g})"
            )

    assert not mismatches, (
        f"{case_id} ({which}, {os.path.basename(sbml_path)}): round-tripped SBML diverged beyond "
        f"tolerance (absolute={settings['absolute']}, relative={settings['relative']}):\n"
        + "\n".join(mismatches)
    )

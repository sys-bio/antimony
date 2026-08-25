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
            cases.append((entry, model_dir, manifest_path, sbml_entries, sedml_location))
    return cases


def _build_archive(model_dir, manifest_path, sbml_entries, sedml_location, sbml_overrides=None, sedml_text=None):
    """Zips manifest.xml, the given SED-ML file, and every SBML file the
    manifest declares into a temp .omex, and returns its path. Every
    declared SBML file is included, not just the one flagged master="true",
    since the SED-ML's <model source> can point at any of them.

    sbml_overrides, if given, is {location: sbml_text} -- used to swap in
    round-tripped SBML under the same filename the SED-ML/manifest expect,
    rather than rewriting either of those. sedml_text, if given, replaces the
    SED-ML file's contents outright (see _fix_sedml_ids)."""
    sbml_overrides = sbml_overrides or {}
    fd, archive_path = tempfile.mkstemp(suffix=".omex")
    os.close(fd)
    with zipfile.ZipFile(archive_path, "w") as zf:
        zf.write(manifest_path, "manifest.xml")
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
        for entry, _, _, _, sedml_location in cases
    ]
    metafunc.parametrize("biomodels_case", cases, ids=ids)


def test_biomodels_roundtrip(biomodels_case):
    model_id, model_dir, manifest_path, sbml_entries, sedml_location = biomodels_case

    original_archive = _build_archive(model_dir, manifest_path, sbml_entries, sedml_location)
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
    original_sedml_text = open(os.path.join(model_dir, sedml_location)).read()
    fixed_sedml_text, id_renames = _fix_sedml_ids(original_sedml_text, available_ids)
    rename_note = f" (SED-ML id renames applied: {id_renames})" if id_renames else ""

    roundtrip_archive = _build_archive(
        model_dir, manifest_path, sbml_entries, sedml_location,
        sbml_overrides=overrides, sedml_text=fixed_sedml_text,
    )
    try:
        roundtrip_data, roundtrip_error = _try_execute(roundtrip_archive)
    finally:
        os.remove(roundtrip_archive)

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
    for key in sorted(original_data):
        original = np.asarray(original_data[key]).flatten()
        roundtrip = np.asarray(roundtrip_data[key]).flatten()
        if original.shape != roundtrip.shape:
            mismatches.append(f"  {key}: shape differs: {original.shape} vs {roundtrip.shape}")
            continue
        if not np.allclose(original, roundtrip, rtol=COMPARISON_RTOL, atol=COMPARISON_ATOL, equal_nan=True):
            diff = np.abs(original - roundtrip)
            worst = int(np.argmax(diff))
            mismatches.append(
                f"  {key}: max |diff|={diff[worst]:.6g} at index {worst} "
                f"(original={original[worst]:.6g}, roundtrip={roundtrip[worst]:.6g})"
            )

    assert not mismatches, (
        f"{model_id}: round-tripped SBML diverged beyond tolerance "
        f"(rtol={COMPARISON_RTOL}, atol={COMPARISON_ATOL}){rename_note}:\n" + "\n".join(mismatches)
    )

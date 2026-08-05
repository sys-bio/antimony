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

# Known, expected roadrunner limitations. Match by category (via these
# patterns) rather than exact error text, since the round trip can reformat
# the offending formula, rename a reaction, etc.
#
# Two of these are also known to trip *asymmetrically*, each in its own
# specific direction -- see the two `elif` branches below for why:
#   - variable_stoichiometry: original succeeds, round-tripped fails.
#   - fast_reactions: original fails, round-tripped succeeds.
KNOWN_LIMITATION_PATTERNS = {
    "variable_stoichiometry": re.compile(r"variable stoichiometr", re.IGNORECASE),
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


def simulate_model(model_source, settings, selections):
    rr = te.loads(model_source)
    rr.integrator.setValue("absolute_tolerance", settings["absolute"] * SIMULATION_TOLERANCE_FACTOR)
    rr.integrator.setValue("relative_tolerance", settings["relative"] * SIMULATION_TOLERANCE_FACTOR)
    n_points = settings["steps"] + 1
    result = rr.simulate(settings["start"], settings["start"] + settings["duration"], n_points, selections=selections)
    return np.asarray(result)


def _try_simulate(model_source, settings, selections):
    """Runs simulate_model, catching any roadrunner runtime error. Returns
    (result, None) on success, or (None, exception) if roadrunner couldn't
    simulate the model."""
    try:
        return simulate_model(model_source, settings, selections), None
    except Exception as exc:
        return None, exc


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
    original_result, original_error = _try_simulate(sbml_path, settings, selections)

    load_index = antimony.loadSBMLFile(sbml_path)
    assert load_index >= 0, f"Failed to load {sbml_path} into libAntimony: {antimony.getLastError()}"

    antimony_text = antimony.getAntimonyString()
    assert antimony_text, f"Failed to convert {sbml_path} to Antimony: {antimony.getLastError()}"

    load_index = antimony.loadAntimonyString(antimony_text)
    assert load_index >= 0, f"Failed to reload converted Antimony for {sbml_path}: {antimony.getLastError()}"

    roundtripped_sbml = antimony.getCompSBMLString()
    assert roundtripped_sbml, f"Failed to export round-tripped SBML for {sbml_path}: {antimony.getLastError()}"

    roundtrip_result, roundtrip_error = _try_simulate(roundtripped_sbml, settings, selections)

    if original_error is not None or roundtrip_error is not None:
        original_limitation = _known_limitation(original_error)
        roundtrip_limitation = _known_limitation(roundtrip_error)

        if (
            original_error is not None
            and roundtrip_error is not None
            and original_limitation is not None
            and original_limitation == roundtrip_limitation
        ):
            outcome = "roadrunner raised the same kind of error simulating both the original and the round-tripped model"
            limitation = original_limitation
        elif original_error is None and roundtrip_limitation == "variable_stoichiometry":
            outcome = "roadrunner could simulate the original model but not the round-tripped model"
            limitation = roundtrip_limitation
        elif roundtrip_error is None and original_limitation == "fast_reactions":
            # Antimony doesn't preserve SBML's 'fast' reaction attribute --
            # deliberately: 'fast' is deprecated in current SBML, vanishingly
            # few models use it, and it's not worth supporting. So the
            # original model can fail here (roadrunner won't simulate a
            # fast reaction) while the round-tripped model -- which no
            # longer has fast=true at all -- simulates fine. That's expected,
            # not a round-trip bug.
            outcome = "roadrunner could simulate the round-tripped model but not the original model"
            limitation = original_limitation
        else:
            # Anything else -- a one-sided failure that isn't one of the two
            # known asymmetric exceptions above, or a symmetric failure
            # where the two errors aren't the same *kind* of known
            # limitation -- is a real problem, not a known limitation.
            raise original_error if original_error is not None else roundtrip_error

        warnings.warn(
            f"{case_id} ({which}, {os.path.basename(sbml_path)}): {outcome} -- {limitation}. "
            f"Original error: {original_error!r}. Round-tripped error: {roundtrip_error!r}."
        )
        pytest.skip(f"{case_id} ({which}): roadrunner simulation error(s) ({limitation}), see warnings")

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

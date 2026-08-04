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

# Known, expected roadrunner limitation: it refuses to simulate a model with
# a named stoichiometry governed by an assignment/rate rule (a variable
# stoichiometry), even though that's valid SBML. This can trip on the
# original model, the round-tripped model, or both (Antimony's canonical
# output for a variable stoichiometry -- a named speciesReference with an
# assignment rule -- doesn't always match the input's encoding, e.g. an L1/L2
# stoichiometryMath). Anything else that keeps a simulation from running is
# treated as a real failure, not this known limitation.
UNSUPPORTED_VARIABLE_STOICHIOMETRY_RE = re.compile(r"variable stoichiometr", re.IGNORECASE)


def _is_unsupported_variable_stoichiometry(exc):
    return exc is not None and bool(UNSUPPORTED_VARIABLE_STOICHIOMETRY_RE.search(str(exc)))


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

    return {
        "start": float(raw["start"]),
        "duration": float(raw["duration"]),
        "steps": int(raw["steps"]),
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
    selections = build_selections(settings)

    antimony.clearPreviousLoads()

    # Some models use constructs roadrunner can't simulate at all (e.g.
    # algebraic rules, or named/variable stoichiometries). That's a
    # roadrunner limitation, not a round-trip problem, so the same thing should
    # happen both before and after the round trip.  One exception: 
    # StoichioMetryMath can be obviously constant and therefore simulatable
    # but not after being round-tripped through Antimony.
    original_result, original_error = _try_simulate(sbml_path, settings, selections)

    load_index = antimony.loadSBMLFile(sbml_path)
    assert load_index >= 0, f"Failed to load {sbml_path} into libAntimony: {antimony.getLastError()}"

    antimony_text = antimony.getAntimonyString()
    assert antimony_text, f"Failed to convert {sbml_path} to Antimony: {antimony.getLastError()}"

    load_index = antimony.loadAntimonyString(antimony_text)
    assert load_index >= 0, f"Failed to reload converted Antimony for {sbml_path}: {antimony.getLastError()}"

    roundtripped_sbml = antimony.getSBMLString()
    assert roundtripped_sbml, f"Failed to export round-tripped SBML for {sbml_path}: {antimony.getLastError()}"

    roundtrip_result, roundtrip_error = _try_simulate(roundtripped_sbml, settings, selections)

    if original_error is not None or roundtrip_error is not None:
        # Only the known "variable stoichiometry" limitation is treated as
        # non-fatal. Anything else that kept a simulation from running is a
        # real problem and should surface as one.
        if not (
            _is_unsupported_variable_stoichiometry(original_error)
            or _is_unsupported_variable_stoichiometry(roundtrip_error)
        ):
            raise original_error if original_error is not None else roundtrip_error

        if original_error is not None and roundtrip_error is not None:
            outcome = "roadrunner could not simulate either the original or the round-tripped model"
        elif original_error is not None:
            outcome = "roadrunner could simulate the round-tripped model but not the original model"
        else:
            outcome = "roadrunner could simulate the original model but not the round-tripped model"
        warnings.warn(
            f"{case_id} ({which}, {os.path.basename(sbml_path)}): {outcome} -- variable "
            f"stoichiometries aren't supported by roadrunner. "
            f"Original error: {original_error!r}. Round-tripped error: {roundtrip_error!r}."
        )
        pytest.skip(f"{case_id} ({which}): unsupported variable stoichiometry, see warnings")

    assert original_result.shape == roundtrip_result.shape, (
        f"{case_id} ({which}): result shapes differ: "
        f"{original_result.shape} vs {roundtrip_result.shape}"
    )

    mismatches = []
    for col in range(1, len(selections)):
        original = original_result[:, col]
        roundtrip = roundtrip_result[:, col]
        if not np.allclose(original, roundtrip, rtol=settings["relative"], atol=settings["absolute"]):
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

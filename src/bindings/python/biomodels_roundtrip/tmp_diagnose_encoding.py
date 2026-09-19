"""Temporary diagnostic: pins down which antimony call (SBML -> Antimony vs.
Antimony -> SBML) produces a non-UTF-8 string for the handful of BioModels
notes that trip a UnicodeDecodeError in the SWIG bindings during round-trip
testing. Delete this file and its CI step once the cause is found.
"""

import os

import antimony

MODEL_IDS = [
    "BIOMD0000000178",
    "BIOMD0000000294",
    "BIOMD0000000554",
    "BIOMD0000000625",
    "BIOMD0000000630",
    "BIOMD0000000634",
]


def main():
    biomodels_dir = os.path.join(os.environ["RUNNER_WORKSPACE"], "biomodels")

    for model_id in MODEL_IDS:
        path = os.path.join(biomodels_dir, "final", model_id, f"{model_id}_url.xml")
        print(f"--- {model_id} ---", flush=True)
        if not os.path.isfile(path):
            print(f"  file not found: {path}", flush=True)
            continue

        antimony.clearPreviousLoads()
        if antimony.loadSBMLFile(path) < 0:
            print(f"  loadSBMLFile failed: {antimony.getLastError()}", flush=True)
            continue

        try:
            antimony_text = antimony.getAntimonyString()
            print(f"  getAntimonyString OK, len {len(antimony_text)}", flush=True)
        except UnicodeDecodeError as e:
            print(f"  getAntimonyString is where it breaks: {e}", flush=True)
            continue

        if antimony.loadAntimonyString(antimony_text) < 0:
            print(f"  loadAntimonyString failed: {antimony.getLastError()}", flush=True)
            continue

        try:
            roundtripped = antimony.getCompSBMLString()
            print(f"  getCompSBMLString OK, len {len(roundtripped)}", flush=True)
        except UnicodeDecodeError as e:
            print(f"  getCompSBMLString is where it breaks: {e}", flush=True)
            continue

        print("  round-tripped cleanly", flush=True)


if __name__ == "__main__":
    main()

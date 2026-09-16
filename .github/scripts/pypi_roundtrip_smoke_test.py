#!/usr/bin/env python
"""Round-trips BIOMD0000000012 (the repressilator model from issue #177,
https://github.com/sys-bio/antimony/issues/177) through antimony: SBML ->
Antimony -> SBML. Uses whichever antimony build is importable -- for this
workflow, the one \'pip install antimony\' fetched from PyPI, not this
checkout\'s own build.
"""

import sys
import urllib.request

import antimony

MODEL_URL = (
    "https://raw.githubusercontent.com/sys-bio/temp-biomodels/main/"
    "final/BIOMD0000000012/BIOMD0000000012_url.xml"
)


def main():
    print(f"antimony version: {antimony.getVersionStr()}")

    with urllib.request.urlopen(MODEL_URL) as response:
        sbml_text = response.read().decode("utf-8")

    antimony.clearPreviousLoads()

    if antimony.loadSBMLString(sbml_text) < 0:
        sys.exit(f"failed to load SBML: {antimony.getLastError()}")

    antimony_text = antimony.getAntimonyString()
    if not antimony_text:
        sys.exit(f"failed to convert to Antimony: {antimony.getLastError()}")

    if antimony.loadAntimonyString(antimony_text) < 0:
        sys.exit(f"failed to reload converted Antimony: {antimony.getLastError()}")

    roundtripped = antimony.getCompSBMLString()
    if not roundtripped:
        sys.exit(f"failed to export round-tripped SBML: {antimony.getLastError()}")

    print("Round trip succeeded.")


if __name__ == "__main__":
    main()

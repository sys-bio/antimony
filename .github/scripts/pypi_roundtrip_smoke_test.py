#!/usr/bin/env python
"""Round-trips BIOMD0000000012 (the repressilator model from issue #177,
https://github.com/sys-bio/antimony/issues/177) through antimony: SBML ->
Antimony -> SBML. Uses whichever antimony build is importable -- for this
workflow, the wheel pulled from a specific CI artifact, not this
checkout's own build.

Writes the intermediate Antimony text to a file (and prints it) before
attempting to reload it, so a failure here still shows the exact string
that triggered it. Windows console output defaults to a codepage that
can't represent every character antimony might emit (e.g. a Greek letter
carried through from an SBML name/annotation), so stdout is reconfigured
to UTF-8 and the file is written as UTF-8 regardless of platform.
"""

import sys
import urllib.request

import antimony

MODEL_URL = (
    "https://raw.githubusercontent.com/sys-bio/temp-biomodels/main/"
    "final/BIOMD0000000012/BIOMD0000000012_url.xml"
)

GENERATED_ANTIMONY_PATH = "generated_antimony.txt"


def main():
    sys.stdout.reconfigure(encoding="utf-8", errors="backslashreplace")
    sys.stderr.reconfigure(encoding="utf-8", errors="backslashreplace")

    print(f"antimony version: {antimony.getVersionStr()}")

    with urllib.request.urlopen(MODEL_URL) as response:
        sbml_text = response.read().decode("utf-8")

    antimony.clearPreviousLoads()

    if antimony.loadSBMLString(sbml_text) < 0:
        sys.exit(f"failed to load SBML: {antimony.getLastError()}")

    antimony_text = antimony.getAntimonyString()
    if not antimony_text:
        sys.exit(f"failed to convert to Antimony: {antimony.getLastError()}")

    with open(GENERATED_ANTIMONY_PATH, "w", encoding="utf-8") as f:
        f.write(antimony_text)

    non_ascii = [(i, ch) for i, ch in enumerate(antimony_text) if ord(ch) > 127]
    print(f"generated Antimony text: {len(antimony_text)} chars, "
          f"{len(non_ascii)} non-ASCII, saved to {GENERATED_ANTIMONY_PATH}")
    if non_ascii:
        print("non-ASCII characters (index, char, codepoint):")
        for i, ch in non_ascii:
            print(f"  {i}: {ch!r} (U+{ord(ch):04X})")

    print("----- BEGIN generated Antimony string -----")
    print(antimony_text)
    print("----- END generated Antimony string -----")

    if antimony.loadAntimonyString(antimony_text) < 0:
        sys.exit(f"failed to reload converted Antimony: {antimony.getLastError()}")

    roundtripped = antimony.getCompSBMLString()
    if not roundtripped:
        sys.exit(f"failed to export round-tripped SBML: {antimony.getLastError()}")

    print("Round trip succeeded.")


if __name__ == "__main__":
    main()

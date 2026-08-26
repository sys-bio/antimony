"""
Fetches the SBML and SED-ML files needed to round-trip test the BioModels
curated in sys-bio/temp-biomodels, without pulling the rest of that repo's
~1.6GB of MATLAB/COPASI/PDF/plot clutter.

Uses a two-phase partial git clone:
  1. Sparse-checkout every final/<model>/manifest.xml (cheap, ~1000 tiny
     files) and parse them to find which files are actually SBML/SED-ML.
  2. Extend the sparse-checkout to those exact paths and re-materialize.

A model directory with no SBML content entry in its manifest is left alone
entirely -- there's nothing to fetch or round-trip test.

Run with e.g.:
    python fetch_biomodels.py --dest /path/to/biomodels-checkout
"""

import argparse
import os
import subprocess
import xml.etree.ElementTree as ET

MANIFEST_NS = "http://identifiers.org/combine.specifications/omex-manifest"
SBML_FORMAT = "http://identifiers.org/combine.specifications/sbml"
SEDML_FORMAT = "http://identifiers.org/combine.specifications/sed-ml"
SBML_FORMAT_SUFFIX = "/sbml"
SEDML_FORMAT_SUFFIX = "/sed-ml"


def run_git(args, cwd):
    subprocess.run(["git"] + args, cwd=cwd, check=True)


def clone(repo, ref, dest):
    if not os.path.isdir(os.path.join(dest, ".git")):
        run_git(
            [
                "clone", "--filter=blob:none", "--no-checkout", "--depth", "1",
                "--branch", ref, "--single-branch",
                f"https://github.com/{repo}.git", dest,
            ],
            cwd=os.path.dirname(os.path.abspath(dest)),
        )
    sparse_checkout_path = os.path.join(dest, ".git", "info", "sparse-checkout")
    run_git(["sparse-checkout", "init", "--no-cone"], cwd=dest)
    with open(sparse_checkout_path, "w") as f:
        f.write("/final/*/manifest.xml\n")
    run_git(["checkout", ref], cwd=dest)


def parse_manifest(manifest_path):
    """Returns (sbml_entries, sedml_entries), each a list of (location,
    master) pairs for content entries whose format matches, relative to the
    manifest's own directory."""
    root = ET.parse(manifest_path).getroot()
    sbml_entries = []
    sedml_entries = []
    for content in root:
        if content.tag.rsplit("}", 1)[-1] != "content":
            continue
        location = content.get("location")
        if not location or location == ".":
            continue
        fmt = (content.get("format") or "").lower()
        master = content.get("master", "false").lower() == "true"
        if fmt.endswith(SBML_FORMAT_SUFFIX):
            sbml_entries.append((location, master))
        elif fmt.endswith(SEDML_FORMAT_SUFFIX):
            sedml_entries.append((location, master))
    return sbml_entries, sedml_entries


def discover(dest):
    """Walks every final/<model>/manifest.xml already checked out (phase 1)
    and returns {model_id: (sbml_entries, sedml_entries)} for models that
    have at least one SBML entry. Models with none are dropped here --
    that's the only place this decision needs to be made, since phase 2 only
    fetches files for models present in the returned dict."""
    final_dir = os.path.join(dest, "final")
    found = {}
    for entry in sorted(os.listdir(final_dir)):
        manifest_path = os.path.join(final_dir, entry, "manifest.xml")
        if not os.path.isfile(manifest_path):
            continue
        sbml_entries, sedml_entries = parse_manifest(manifest_path)
        if not sbml_entries:
            continue
        found[entry] = (sbml_entries, sedml_entries)
    return found


def fetch_files(dest, found):
    """Extends the sparse-checkout to every discovered SBML/SED-ML file and
    re-materializes the working tree against the new pattern set."""
    sparse_checkout_path = os.path.join(dest, ".git", "info", "sparse-checkout")
    lines = ["/final/*/manifest.xml"]
    for model_id, (sbml_entries, sedml_entries) in found.items():
        for location, _ in sbml_entries + sedml_entries:
            lines.append(f"/final/{model_id}/{location}")
    with open(sparse_checkout_path, "w") as f:
        f.write("\n".join(lines) + "\n")
    run_git(["sparse-checkout", "reapply"], cwd=dest)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", default="sys-bio/temp-biomodels")
    parser.add_argument("--ref", default="main")
    parser.add_argument("--dest", required=True, help="Directory to check the repo out into (created if needed).")
    args = parser.parse_args()

    os.makedirs(args.dest, exist_ok=True)
    clone(args.repo, args.ref, args.dest)

    found = discover(args.dest)
    total_models = len(os.listdir(os.path.join(args.dest, "final")))
    with_sedml = sum(1 for _, sedml_entries in found.values() if sedml_entries)
    print(
        f"{total_models} model directories found; {len(found)} have at least one SBML file "
        f"({with_sedml} of those also have a SED-ML file and will be tested)."
    )

    fetch_files(args.dest, found)
    print(f"Fetched SBML/SED-ML files into {args.dest}")


if __name__ == "__main__":
    main()

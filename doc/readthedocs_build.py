#!/usr/bin/env python3
"""Builds the Doxygen documentation site for Read the Docs.

Read the Docs has no libSBML/SBMLNetwork toolchain, so a full CMake
configure isn't an option here. This script instead performs the same
'@VAR@' substitutions CMakeLists.txt's 'docs' target performs before
invoking doxygen, then runs doxygen directly against
doc/doxygen.antimony.cfg.
"""

import os
import re
import shutil
import subprocess
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
DOC = ROOT / "doc"
BUILD = DOC / "_readthedocs_doxygen_build"

# ANTIMONY_DOXYGEN_EXECUTABLE lets .readthedocs.yaml pin a specific Doxygen
# build (see the pre_build step there for why); local runs fall back to
# whatever 'doxygen' resolves to on PATH.
#
# A Cygwin-built doxygen doesn't recognize 'C:/...' as an absolute path (only
# POSIX-style paths); mirrors antimony_doxygen_path() in CMakeLists.txt.
DOXYGEN_EXECUTABLE = (
    os.environ.get("ANTIMONY_DOXYGEN_EXECUTABLE") or shutil.which("doxygen") or "doxygen"
)
DOXYGEN_IS_CYGWIN = "cygwin" in DOXYGEN_EXECUTABLE.lower()


def cmake_set_value(name, cmakelists_text):
    match = re.search(rf'SET\(\s*{name}\s+"?([^")\n]*)"?\s*\)', cmakelists_text)
    if not match:
        raise SystemExit(f"Could not find SET({name} ...) in CMakeLists.txt")
    return match.group(1)


def doxygen_path(path):
    path = str(path)
    if not DOXYGEN_IS_CYGWIN:
        return path
    match = re.match(r"^([A-Za-z]):[\\/](.*)$", path)
    if not match:
        return path
    drive = match.group(1).lower()
    rest = match.group(2).replace("\\", "/")
    return f"/cygdrive/{drive}/{rest}"


def main():
    cmakelists_text = (ROOT / "CMakeLists.txt").read_text(encoding="utf-8")
    major = cmake_set_value("LIBANTIMONY_VERSION_MAJOR", cmakelists_text)
    minor = cmake_set_value("LIBANTIMONY_VERSION_MINOR", cmakelists_text)
    patch = cmake_set_value("LIBANTIMONY_VERSION_PATCH", cmakelists_text)
    release = cmake_set_value("LIBANTIMONY_VERSION_RELEASE", cmakelists_text)
    version_string = f"v{major}.{minor}{patch}{release}"

    output_dir = BUILD / "html"
    output_dir.mkdir(parents=True, exist_ok=True)

    api_header = BUILD / "antimony_api.h"
    api_header.write_text(
        (ROOT / "src" / "antimony_api.h.in")
        .read_text(encoding="utf-8")
        .replace("@LIBANTIMONY_VERSION_STRING@", version_string),
        encoding="utf-8",
    )

    mainpage = BUILD / "antimony-mainpage.txt"
    mainpage.write_text(
        (DOC / "antimony-mainpage.txt.in")
        .read_text(encoding="utf-8")
        .replace("@LIBANTIMONY_VERSION_STRING@", version_string),
        encoding="utf-8",
    )

    cfg_text = (
        (DOC / "doxygen.antimony.cfg")
        .read_text(encoding="utf-8")
        .replace("@LIBANTIMONY_VERSION_STRING@", version_string)
        .replace("@ANTIMONY_API_FOR_DOXYGEN@", doxygen_path(api_header))
        # antimony_api.h is generated into this staging directory rather
        # than living in src/ alongside the other headers, so without this,
        # doxygen's "Files" view buries it under that directory's name
        # instead of showing it at the top level.
        .replace("@ANTIMONY_API_DIR_FOR_DOXYGEN@", doxygen_path(api_header.parent))
        # Same reasoning as above, for enums.h -- otherwise it's buried
        # under a "src" directory entry instead of showing at the top level.
        .replace("@ANTIMONY_SRC_DIR_FOR_DOXYGEN@", doxygen_path(ROOT / "src"))
        .replace("@ANTIMONY_MAINPAGE_FOR_DOXYGEN@", doxygen_path(mainpage))
        .replace("@ANTIMONY_DOXYGEN_OUTPUT_FOR_DOXYGEN@", doxygen_path(output_dir))
    )
    doxyfile = BUILD / "doxygen.antimony.cfg"
    doxyfile.write_text(cfg_text, encoding="utf-8")

    subprocess.run(
        [DOXYGEN_EXECUTABLE, doxygen_path(doxyfile)], cwd=DOC, check=True
    )
    print(f"Doxygen HTML written to {output_dir}")

    # The pages under doc/ link to doc/examples/ (e.g. the BioModels
    # translations), but doxygen doesn't copy that directory itself.
    # cellml_files/ and cellml_files.zip are excluded: CellML translation
    # is currently disabled and nothing links to them.
    shutil.copytree(
        DOC / "examples",
        output_dir / "examples",
        ignore=shutil.ignore_patterns("cellml_files", "cellml_files.zip"),
        dirs_exist_ok=True,
    )
    print(f"Copied doc/examples to {output_dir / 'examples'}")

    # Referenced via raw <img>/<A HREF> tags rather than doxygen's own
    # \image or \include commands, so doxygen doesn't know to copy them.
    for name in (
        "Screenshot-windows.png",
        "Screenshot-macosx.png",
        "Screenshot-linux.png",
        "AntimonyTutorial.pdf",
    ):
        shutil.copy2(DOC / name, output_dir / name)
    print("Copied screenshots and AntimonyTutorial.pdf to " + str(output_dir))


if __name__ == "__main__":
    main()

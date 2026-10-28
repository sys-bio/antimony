These docs can be read at

http://antimony.readthedocs.io/

The following instructions are for developers wishing to rebuild/test the docs:

Rebuilding AntimonyTutorial docs
=================================

The other doc formats (AntimonyTutorial.htm, .docx, .rst, .pdf, and
QTAntimony_src/Tutorial.xxd) are generated from doc/AntimonyTutorial.md via
a CMake target, not a plain script. Defined in CMakeLists.txt (~line 719).

From your build directory (e.g. build-release or build-debug):

    cmake --build . --target docs

Requires pandoc on PATH (for .htm/.docx/.rst/.pdf) and xxd (for
QTAntimony_src/Tutorial.xxd). Not part of the default build, so it must be
run explicitly.

Testing the Read the Docs build locally
========================================

doc/readthedocs_build.py replicates the Doxygen half of the 'docs' target
(the antimony-*.txt pages) the way Read the Docs itself builds it, without
needing the full CMake/libSBML configure. From the repository root:

    python doc/readthedocs_build.py

Output goes to doc/_readthedocs_doxygen_build/html/. Requires Doxygen
<= 1.11 on PATH (newer versions duplicate markdown link text, see
https://github.com/doxygen/doxygen/issues/11207) -- set
ANTIMONY_DOXYGEN_EXECUTABLE to point at a specific binary otherwise.

Comparing the tutorial against Tellurium's copy
================================================

Tellurium keeps a hand-maintained copy of the tutorial (docs/antimony.rst in
the tellurium repo). doc/sync_tellurium_docs.py reports which sections of the
generated doc/AntimonyTutorial.rst have changed relative to that copy, so only
those need to be copied over by hand. Run the 'docs' target first so the .rst
is current, then, from the repository root:

    python doc/sync_tellurium_docs.py path/to/tellurium/docs/antimony.rst

Sections are matched by heading, so differences in RST rendering and
Tellurium-specific sections are tolerated. The script only prints a report
and never modifies either file. It exits with status 1 if any sections
changed or are new, and 0 otherwise. Use --ignore HEADING (repeatable) to
skip additional sections.

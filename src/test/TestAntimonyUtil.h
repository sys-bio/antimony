/**
 * \file    TestAntimonyUtil.h
 * \brief   Comparison helpers shared across multiple antimony gtest binaries.
 *
 * Each TestAntimony*.cpp file below is now compiled into its own separate
 * test executable (see src/test/CMakeLists.txt), so helper functions that
 * used to be reachable across files via `extern` declarations (relying on
 * everything being linked into one big test_antimony binary) need to live
 * somewhere every executable that needs them can link against. This file
 * (plus TestAntimonyUtil.cpp) is compiled into every test_antimony_* target
 * via SharedTestFiles, alongside main.cpp.
 * ---------------------------------------------------------------------- -->*/
#ifndef TESTANTIMONYUTIL_H
#define TESTANTIMONYUTIL_H

#include <string>

// Loads <base>.txt as antimony, compares its SBML translation against
// <base>.xml, then loads that SBML back in, converts it to antimony, and
// compares it against <base>_rt.txt (also converted to antimony and back,
// to normalize formatting).
void compareFileTranslation(const std::string& base);

// Loads <base>.xml as SBML, compares its antimony translation against
// <base>.txt, then converts back to SBML and confirms it round-trips.
void compareFileTranslationWithRenaming(const std::string& base);

// Like compareFileTranslation, but for the final round-trip check, compares
// the SBML-loaded antimony text directly against the literal contents of
// <base>_rt.txt instead of reparsing that file through Antimony and
// reprinting it. Use this when the SBML path and a direct top-to-bottom
// Antimony parse are expected to produce the same content but in a
// different variable declaration order (e.g. because SBML visits
// Parameters before Reactions, while Antimony declares symbols in the
// order they're first mentioned in a reaction), so reparsing the reference
// file would just reintroduce the direct-parse order instead of confirming
// a match.
void compareFileTranslationWithDifferences(const std::string& base);

// Loads the given antimony string, compares its SBML translation against
// the SBML in the given file (relative to TestDataDirectory).
void compareStringTranslation(const std::string& antimony, const std::string& sbml);

#endif // TESTANTIMONYUTIL_H

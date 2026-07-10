/**
 * \file    TestAntimonyUtil.cpp
 * \brief   Comparison helpers shared across multiple antimony gtest binaries.
 *          See TestAntimonyUtil.h for why this file exists.
 * ---------------------------------------------------------------------- -->*/

#include "TestAntimonyUtil.h"

#include "libutil.h"
#include "antimony_api.h"
#include "sbml/SBMLTypes.h"
#include "stringx.h"

#include <string>
#include "gtest/gtest.h"

using namespace std;
using namespace libsbml;

extern char *TestDataDirectory;

void compareFileTranslation(const string& base)
{
  clearPreviousLoads();
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string sbmlfile = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  EXPECT_STREQ(atosbml, matching.c_str());

  //Now check the roundtripped version:
  ret = loadSBMLString(matching.c_str());
  char* roundtrip = getAntimonyString(NULL);
  EXPECT_TRUE(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  EXPECT_TRUE(ret != -1);
  matching = getAntimonyString(NULL);
  EXPECT_STREQ(roundtrip, matching.c_str());

  delete doc;
  freeAll();
}

void compareFileTranslationWithRenaming(const string& base)
{
  clearPreviousLoads();
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".xml";
  long ret = loadSBMLFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* sbmltoa = getAntimonyString(NULL);
  EXPECT_TRUE(sbmltoa != NULL);
  char* sbmlrt = getSBMLString(NULL);
  EXPECT_TRUE(sbmlrt != NULL);

  filename = dir + base + ".txt";
  ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* matching = getAntimonyString(NULL);
  EXPECT_STREQ(sbmltoa, matching);

  //Now check the roundtripped version:
  char* roundtrip = getSBMLString(NULL);
  EXPECT_TRUE(roundtrip != NULL);
  EXPECT_STREQ(roundtrip, sbmlrt);

  freeAll();
}

void compareStringTranslation(const string& antimony, const string& sbml)
{
  clearPreviousLoads();
  long ret = loadAntimonyString(antimony.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string dir(TestDataDirectory);
  string sbmlfile = dir + sbml;
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matchingdoc = writeSBMLToStdString(doc);

  EXPECT_STREQ(atosbml, matchingdoc.c_str());
  delete doc;
  freeAll();
}

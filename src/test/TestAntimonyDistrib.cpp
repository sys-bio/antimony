/**
 * \file    TestAntimonyHierarchy.c
 * \brief   Test Antimony's hierarchy constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include <sbml/SBMLTypes.h>
#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/packages/comp/common/CompExtensionTypes.h>

#include <string>
#include "gtest/gtest.h"

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

void compareDistributionsAnt(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "distributions/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string sbmlfile = dir + "distributions/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string matching = writeSBMLToStdString(doc);
  EXPECT_STREQ(elideMetaIdsFromSBMLstring(atosbml).c_str(), matching.c_str());

  delete doc;
  freeAll();
}

void compareDistributionsSBML(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);

  string filename = dir + "distributions/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* matching = getAntimonyString(NULL);
  EXPECT_TRUE(matching != NULL);

  string sbmlfile = dir + "distributions/" + base + ".xml";
  ret = loadSBMLFile(sbmlfile.c_str());
  EXPECT_TRUE(ret != -1);
  char* sbml2ant = getAntimonyString(NULL);

  EXPECT_STREQ(sbml2ant, matching);

  //And check the round-tripped version:
  ret = loadAntimonyString(sbml2ant);
  EXPECT_TRUE(ret != -1);
  char* sbmlrt = getCompSBMLString(NULL);
  string roundtrip = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string sbmlmatch = writeSBMLToStdString(doc);

  EXPECT_STREQ(elideMetaIdsFromSBMLstring(sbmlrt).c_str(), sbmlmatch.c_str());

  delete doc;
  freeAll();
}

TEST(AntimonyDistrib, test_numeric_distributions)
{
  compareDistributionsAnt("numeric_distributions");
  compareDistributionsSBML("numeric_distributions_rev");
}

TEST(AntimonyDistrib, test_numeric_distributions_extended)
{
  compareDistributionsAnt("numeric_distributions_extended");
  compareDistributionsSBML("numeric_distributions_extended");
}

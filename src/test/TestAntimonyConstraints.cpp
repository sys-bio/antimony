/**
 * \file    TestAntimonyConstraints.c
 * \brief   Test Antimony's constraint constructs.
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

void compareConstraints(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "constraints/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string sbmlfile = dir + "constraints/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  EXPECT_STREQ(atosbml, matching.c_str());

  //And check the round-tripped Antimony:
  char* ant_rt = getAntimonyString(NULL);

  ret = loadSBMLString(matching.c_str());
  EXPECT_TRUE(ret != 1);
  char* sbml2ant = getAntimonyString(NULL);
  EXPECT_STREQ(ant_rt, sbml2ant);

  delete doc;
  freeAll();
}

TEST(AntimonyConstraints, test_numeric_constraints)
{
  compareConstraints("numeric_constraints");
}

TEST(AntimonyConstraints, test_numeric_constraints_neg)
{
  compareConstraints("numeric_constraints_neg");
}

TEST(AntimonyConstraints, test_three_level_constraints)
{
  compareConstraints("three_level_constraints");
}

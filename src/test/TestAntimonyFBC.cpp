/**
 * \file    TestAntimonyFBC.c
 * \brief   Test Antimony's FBC constructs.
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

void compareFBCAnt(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "fbc/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string sbmlfile = dir + "fbc/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string matching = writeSBMLToStdString(doc);
  EXPECT_STREQ(elideMetaIdsFromSBMLstring(atosbml).c_str(), matching.c_str());

  delete doc;
  freeAll();
}

void compareFBCSBML(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);

  string filename = dir + "fbc/" + base + "_rt.txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* matching = getAntimonyString(NULL);
  EXPECT_TRUE(matching != NULL);

  string sbmlfile = dir + "fbc/" + base + ".xml";
  ret = loadSBMLFile(sbmlfile.c_str());
  EXPECT_TRUE(ret != -1);
  char* sbml2ant = getAntimonyString(NULL);

  EXPECT_STREQ(sbml2ant, matching);

  //And check the round-tripped version:
  ret = loadAntimonyString(sbml2ant);
  EXPECT_TRUE(ret != -1);
  char* sbmlrt = getSBMLString(NULL);
  string roundtrip = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string sbmlmatch = writeSBMLToStdString(doc);

  EXPECT_STREQ(elideMetaIdsFromSBMLstring(sbmlrt).c_str(), sbmlmatch.c_str());

  delete doc;
  freeAll();
}

TEST(AntimonyFBC, test_simple_flux)
{
  compareFBCAnt("simple_flux");
  compareFBCSBML("simple_flux");
}

TEST(AntimonyFBC, test_simple_flux2)
{
  compareFBCAnt("simple_flux2");
  compareFBCSBML("simple_flux2");
}

TEST(AntimonyFBC, test_simple_flux3)
{
  compareFBCAnt("simple_flux3");
  compareFBCSBML("simple_flux3");
}

TEST(AntimonyFBC, test_simple_flux3_reverse)
{
  compareFBCAnt("simple_flux3_reverse");
  compareFBCSBML("simple_flux3_reverse");
}

TEST(AntimonyFBC, test_simple_fluxeq_neq)
{
  compareFBCAnt("simple_flux_eq_neq");
  compareFBCSBML("simple_flux_eq_neq");
}

TEST(AntimonyFBC, test_simple_flux_neg)
{
  compareFBCAnt("simple_flux_neg");
  compareFBCSBML("simple_flux_neg");
}

TEST(AntimonyFBC, test_two_sided_flux)
{
  compareFBCAnt("two_sided_flux");
  compareFBCSBML("two_sided_flux");
}

TEST(AntimonyFBC, test_two_sided_flux_complete)
{
  compareFBCAnt("two_sided_flux_complete");
  compareFBCSBML("two_sided_flux_complete");
}

TEST(AntimonyFBC, test_simple_objective)
{
  compareFBCAnt("simple_objective");
  compareFBCSBML("simple_objective");
}

TEST(AntimonyFBC, test_simple_objective2)
{
  compareFBCAnt("simple_objective2");
  compareFBCSBML("simple_objective2");
}

TEST(AntimonyFBC, test_simple_objective3)
{
  compareFBCAnt("simple_objective3");
  compareFBCSBML("simple_objective3");
}

TEST(AntimonyFBC, test_simple_objective4)
{
  compareFBCAnt("simple_objective4");
  compareFBCSBML("simple_objective4");
}

TEST(AntimonyFBC, test_simple_objective5)
{
  compareFBCAnt("simple_objective5");
  compareFBCSBML("simple_objective5");
}

TEST(AntimonyFBC, test_formula_objective)
{
  compareFBCAnt("formula_objective");
  compareFBCSBML("formula_objective");
}

TEST(AntimonyFBC, test_formula_objective2)
{
  compareFBCAnt("formula_objective2");
  compareFBCSBML("formula_objective2");
}

TEST(AntimonyFBC, test_simple_flux_and_objective)
{
  compareFBCAnt("simple_flux_and_objective");
  compareFBCSBML("simple_flux_and_objective");
}

TEST(AntimonyFBC, test_fluxes_and_objectives)
{
  compareFBCAnt("fluxes_and_objectives");
  compareFBCSBML("fluxes_and_objectives");
}

TEST(AntimonyFBC, test_geneProducts)
{
  compareFBCAnt("geneProducts");
  compareFBCSBML("geneProducts");
}

TEST(AntimonyFBC, test_geneProductAssociations)
{
  compareFBCAnt("geneProductAssociations");
  compareFBCSBML("geneProductAssociations");
}

TEST(AntimonyFBC, test_chemicalFormula)
{
  compareFBCAnt("chemicalFormula");
  compareFBCSBML("chemicalFormula");
}

TEST(AntimonyFBC, test_charge)
{
  compareFBCAnt("charge");
  compareFBCSBML("charge");
}

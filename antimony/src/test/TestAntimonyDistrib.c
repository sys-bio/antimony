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
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareDistributionsAnt(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "distributions/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + "distributions/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string matching = writeSBMLToStdString(doc);
  fail_unless(elideMetaIdsFromSBMLstring(atosbml) == matching);

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
  fail_unless(ret != -1);
  char* matching = getAntimonyString(NULL);
  fail_unless(matching != NULL);

  string sbmlfile = dir + "distributions/" + base + ".xml";
  ret = loadSBMLFile(sbmlfile.c_str());
  fail_unless(ret != -1);
  char* sbml2ant = getAntimonyString(NULL);

  fail_unless(string(sbml2ant) == string(matching));

  //And check the round-tripped version:
  ret = loadAntimonyString(sbml2ant);
  fail_unless(ret != -1);
  char* sbmlrt = getCompSBMLString(NULL);
  string roundtrip = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  elideMetaIds(doc);
  string sbmlmatch = writeSBMLToStdString(doc);

  fail_unless(elideMetaIdsFromSBMLstring(sbmlrt) == sbmlmatch);

  delete doc;
  freeAll();
}

START_TEST (test_numeric_distributions)
{
  compareDistributionsAnt("numeric_distributions");
  compareDistributionsSBML("numeric_distributions_rev");
}
END_TEST


START_TEST (test_numeric_distributions_extended)
{
  compareDistributionsAnt("numeric_distributions_extended");
  compareDistributionsSBML("numeric_distributions_extended");
}
END_TEST


Suite *
create_suite_Distrib(void)
{
  Suite *suite = suite_create("Antimony Distributions");
  TCase *tcase = tcase_create("Antimony Distributions");

  //tcase_add_test( tcase, test_);
  //tcase_add_test( tcase, test_);

  tcase_add_test( tcase, test_numeric_distributions);
  tcase_add_test( tcase, test_numeric_distributions_extended);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



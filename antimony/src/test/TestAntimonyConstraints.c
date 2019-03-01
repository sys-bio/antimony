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
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareConstraints(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "constraints/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + "constraints/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  fail_unless(string(atosbml) == string(matching));

  //And check the round-tripped Antimony:
  char* ant_rt = getAntimonyString(NULL);

  ret = loadSBMLString(matching.c_str());
  fail_unless(ret != 1);
  char* sbml2ant = getAntimonyString(NULL);
  fail_unless(string(ant_rt) == string(sbml2ant));

  delete doc;
  freeAll();
}

START_TEST (test_numeric_constraints)
{
  compareConstraints("numeric_constraints");
}
END_TEST

START_TEST (test_numeric_constraints_neg)
{
  compareConstraints("numeric_constraints_neg");
}
END_TEST

START_TEST (test_three_level_constraints)
{
  compareConstraints("three_level_constraints");
}
END_TEST


Suite *
create_suite_Constraints(void)
{
  Suite *suite = suite_create("Antimony Constraints");
  TCase *tcase = tcase_create("Antimony Constraints");

  //tcase_add_test( tcase, test_);
  //tcase_add_test( tcase, test_);

  tcase_add_test( tcase, test_numeric_constraints);
  tcase_add_test( tcase, test_numeric_constraints_neg);
  tcase_add_test( tcase, test_three_level_constraints);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



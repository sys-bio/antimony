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
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareFBCAnt(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + "fbc/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + "fbc/" + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  char* matching = writeSBMLToString(doc);
  fail_unless(string(atosbml) == string(matching));

  delete doc;
  delete atosbml;
  delete matching;
}

void compareFBCSBML(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);

  string filename = dir + "fbc/" + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* matching = getAntimonyString(NULL);
  fail_unless(matching != NULL);

  string sbmlfile = dir + "fbc/" + base + ".xml";
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
  delete matching;
  matching = writeSBMLToString(doc);

  fail_unless(string(sbmlrt) == string(matching));

  delete doc;
  delete sbml2ant;
  delete matching;
  delete sbmlrt;
}

START_TEST (test_simple_flux)
{
  compareFBCAnt("simple_flux");
  compareFBCSBML("simple_flux");
}
END_TEST


START_TEST (test_simple_flux2)
{
  compareFBCAnt("simple_flux2");
  compareFBCSBML("simple_flux2");
}
END_TEST


START_TEST (test_simple_flux3)
{
  compareFBCAnt("simple_flux3");
  compareFBCSBML("simple_flux3");
}
END_TEST


START_TEST (test_simple_flux3_reverse)
{
  compareFBCAnt("simple_flux3_reverse");
  compareFBCSBML("simple_flux3_reverse");
}
END_TEST


START_TEST (test_simple_fluxeq_neq)
{
  compareFBCAnt("simple_flux_eq_neq");
  compareFBCSBML("simple_flux_eq_neq");
}
END_TEST


START_TEST (test_simple_flux_neg)
{
  compareFBCAnt("simple_flux_neg");
  compareFBCSBML("simple_flux_neg");
}
END_TEST


START_TEST (test_two_sided_flux)
{
  compareFBCAnt("two_sided_flux");
  compareFBCSBML("two_sided_flux");
}
END_TEST


START_TEST (test_two_sided_flux_complete)
{
  compareFBCAnt("two_sided_flux_complete");
  compareFBCSBML("two_sided_flux_complete");
}
END_TEST


Suite *
create_suite_FBC(void)
{
  Suite *suite = suite_create("Antimony FBC");
  TCase *tcase = tcase_create("Antimony FBC");

  //tcase_add_test( tcase, test_);

  tcase_add_test( tcase, test_simple_flux);
  tcase_add_test( tcase, test_simple_flux2);
  tcase_add_test( tcase, test_simple_flux3);
  tcase_add_test( tcase, test_simple_flux3_reverse);
  tcase_add_test( tcase, test_simple_fluxeq_neq);
  tcase_add_test( tcase, test_simple_flux_neg);
  tcase_add_test( tcase, test_two_sided_flux);
  tcase_add_test( tcase, test_two_sided_flux_complete);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



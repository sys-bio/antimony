/**
 * \file    TestAntimonyImport.c
 * \brief   Test Antimony's behavior when importing SBML.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <iostream>

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareFileImport(const string& base)
{
    clearPreviousLoads();
    // load document
    string dir(TestDataDirectory);
    string sbmlfile = dir + base + ".xml";
    long ret = loadSBMLFile(sbmlfile.c_str());
    fail_unless(ret != -1);
    char* sbml2ant = getAntimonyString(NULL);
    fail_unless(sbml2ant != NULL);

    string antimonyfile = dir + base + ".txt";
    ret = loadAntimonyFile(antimonyfile.c_str());
    fail_unless(ret != -1);

    char* roundtrip = getAntimonyString(NULL);
    fail_unless(string(roundtrip) == string(sbml2ant));

    freeAll();
}



START_TEST (test_import_RateOf)
{
    compareFileImport("BIOMD0000000696");
}
END_TEST


START_TEST(test_import_GAMMA)
{
    compareFileImport("BIOMD0000000118");
}
END_TEST


START_TEST(test_import_same_unit_name)
{
    compareFileImport("same_unit_name");
}
END_TEST


START_TEST(test_import_default_compartment)
{
    compareFileImport("default_compartment");
}
END_TEST




Suite *
create_suite_Import (void)
{
  Suite *suite = suite_create("Antimony Import");
  TCase *tcase = tcase_create("Antimony Import");

  tcase_add_test(tcase, test_import_default_compartment);
  tcase_add_test(tcase, test_import_GAMMA);
  tcase_add_test(tcase, test_import_RateOf);
  tcase_add_test(tcase, test_import_same_unit_name);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



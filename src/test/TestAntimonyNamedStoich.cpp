/**
 * \file    TestAntimonyNamedStoich.c
 * \brief   Test Antimony's Named Stoichiometry constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "sbml/SBMLTypes.h"
#include "stringx.h"

#include <string>
#include <check.h>

using namespace std;
using namespace libsbml;

BEGIN_C_DECLS

extern char *TestDataDirectory;
extern void compareFileTranslation(const string& base);
extern void compareFileTranslationWithRenaming(const string& base);
extern void compareStringTranslation(const string& antimony, const string& sbml);


START_TEST(test_NamedStoichBasic)
{
    compareStringTranslation("J0: sr1 a->;", "namedstoich_basic.xml");
}
END_TEST

START_TEST(test_NamedStoichBasic_file)
{
    compareFileTranslation("namedstoich_basic");
}
END_TEST


START_TEST(test_NamedStoichValue)
{
    compareStringTranslation("J0: sr1 a->;; sr1 = 2", "namedstoich_value.xml");
}
END_TEST

START_TEST(test_NamedStoichValue_file)
{
    compareFileTranslation("namedstoich_value");
}
END_TEST


START_TEST(test_NamedStoichAssignment)
{
    compareStringTranslation("J0: sr1 a->;; sr1 := 2+1", "namedstoich_assignment.xml");
}
END_TEST

START_TEST(test_NamedStoichAssignment_file)
{
    compareFileTranslation("namedstoich_assignment");
}
END_TEST


START_TEST(test_NamedStoichRate)
{
    compareStringTranslation("J0: sr1 a->;; sr1' = 1.1", "namedstoich_rate.xml");
}
END_TEST

START_TEST(test_NamedStoichRate_file)
{
    compareFileTranslation("namedstoich_rate");
}
END_TEST






Suite *
create_suite_NamedStoich (void)
{
  Suite *suite = suite_create("Antimony Named Stoichiometries");
  TCase *tcase = tcase_create("Antimony Named Stoichiometries");


  tcase_add_test(tcase, test_NamedStoichBasic);
  tcase_add_test(tcase, test_NamedStoichBasic_file);
  tcase_add_test(tcase, test_NamedStoichValue);
  tcase_add_test(tcase, test_NamedStoichValue_file);
  tcase_add_test(tcase, test_NamedStoichAssignment);
  tcase_add_test(tcase, test_NamedStoichAssignment_file);
  tcase_add_test(tcase, test_NamedStoichRate);
  tcase_add_test(tcase, test_NamedStoichRate_file);


  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



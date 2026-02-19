/**
 * \file    TestAntimonyUnits.c
 * \brief   Test Antimony's unit constructs.
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

extern char* TestDataDirectory;

extern void compareFileTranslation(const string& base);
extern void compareFileTranslationWithRenaming(const string& base);
extern void compareStringTranslation(const string& antimony, const string& sbml);

START_TEST (test_parameter_units)
{
  compareFileTranslation("parameter_units");
}
END_TEST

START_TEST (test_parameter_units_txt)
{
  compareStringTranslation("a=3 moles", "parameter_units.xml");
}
END_TEST


START_TEST(test_parameter_has_units)
{
  compareFileTranslation("parameter_has_units");
}
END_TEST

START_TEST(test_parameter_has_units_txt)
{
  compareStringTranslation("a=3/2; a has moles", "parameter_has_units.xml");
}
END_TEST


START_TEST(test_defined_unit)
{
  compareFileTranslation("defined_unit");
}
END_TEST

START_TEST(test_defined_unit_txt)
{
  compareStringTranslation("a=3 mmol; unit mmol = 1e-3 mole", "defined_unit.xml");
}
END_TEST


START_TEST(test_defined_complicated_unit)
{
  compareFileTranslation("defined_complicated_unit");
}
END_TEST

START_TEST(test_defined_complicated_unit_txt)
{
  compareStringTranslation("a=3 kph; unit kph = 1e3 meter / 360 second", "defined_complicated_unit.xml");
}
END_TEST


START_TEST(test_species_conc_default)
{
  compareFileTranslation("species_conc_default");
}
END_TEST

START_TEST(test_species_conc_default_txt)
{
  compareStringTranslation("species a=3 M; unit M = mole / liter", "species_conc_default.xml");
}
END_TEST


START_TEST(test_species_conc_in_comp)
{
  compareFileTranslation("species_conc_in_comp");
}
END_TEST

START_TEST(test_species_conc_in_comp_txt)
{
  compareStringTranslation("species a in C; a = 3 mM; C = 1e-3 liter; unit mM = 1e-3 mole / liter", "species_conc_in_comp.xml");
}
END_TEST


START_TEST(test_subst_species_amt_default)
{
  compareFileTranslation("subst_species_amt_default");
}
END_TEST

START_TEST(test_subst_species_amt_default_txt)
{
  compareStringTranslation("substanceOnly species a = 3 mole", "subst_species_amt_default.xml");
}
END_TEST


START_TEST(test_subst_species_amt_in_comp)
{
  compareFileTranslation("subst_species_amt_in_comp");
}
END_TEST

START_TEST(test_subst_species_amt_in_comp_txt)
{
  compareStringTranslation("substanceOnly species a in C; a = 3 mole; C = 2 mL; unit mL = 1e-3 liter", "subst_species_amt_in_comp.xml");
}
END_TEST



Suite *
create_suite_Units (void)
{
  Suite *suite = suite_create("Antimony Units");
  TCase *tcase = tcase_create("Antimony Units");

  tcase_add_test(tcase, test_parameter_units);
  tcase_add_test(tcase, test_parameter_units_txt);
  tcase_add_test(tcase, test_parameter_has_units);
  tcase_add_test(tcase, test_parameter_has_units_txt);
  tcase_add_test(tcase, test_defined_unit);
  tcase_add_test(tcase, test_defined_unit_txt);
  tcase_add_test(tcase, test_defined_complicated_unit);
  tcase_add_test(tcase, test_defined_complicated_unit_txt);
  tcase_add_test(tcase, test_species_conc_default);
  tcase_add_test(tcase, test_species_conc_default_txt);
  tcase_add_test(tcase, test_species_conc_in_comp);
  tcase_add_test(tcase, test_species_conc_in_comp_txt);
  tcase_add_test(tcase, test_subst_species_amt_default);
  tcase_add_test(tcase, test_subst_species_amt_default_txt);
  tcase_add_test(tcase, test_subst_species_amt_in_comp);
  tcase_add_test(tcase, test_subst_species_amt_in_comp_txt);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



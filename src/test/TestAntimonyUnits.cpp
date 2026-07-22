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
#include "gtest/gtest.h"

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

#include "TestAntimonyUtil.h"

TEST(AntimonyUnits, test_parameter_units)
{
  compareFileTranslation("parameter_units");
}

TEST(AntimonyUnits, test_parameter_units_txt)
{
  compareStringTranslation("a=3 moles", "parameter_units.xml");
}

TEST(AntimonyUnits, test_parameter_has_units)
{
  compareFileTranslation("parameter_has_units");
}

TEST(AntimonyUnits, test_parameter_has_units_txt)
{
  compareStringTranslation("a=3/2; a has moles", "parameter_has_units.xml");
}

TEST(AntimonyUnits, test_defined_unit)
{
  compareFileTranslation("defined_unit");
}

TEST(AntimonyUnits, test_defined_unit_txt)
{
  compareStringTranslation("a=3 mmol; unit mmol = 1e-3 mole", "defined_unit.xml");
}

TEST(AntimonyUnits, test_defined_complicated_unit)
{
  compareFileTranslation("defined_complicated_unit");
}

TEST(AntimonyUnits, test_defined_complicated_unit_txt)
{
  compareStringTranslation("a=3 kph; unit kph = 1e3 meter / 360 second", "defined_complicated_unit.xml");
}

TEST(AntimonyUnits, test_species_conc_default)
{
  compareFileTranslation("species_conc_default");
}

TEST(AntimonyUnits, test_species_conc_default_txt)
{
  compareStringTranslation("species a=3 M; unit M = mole / liter", "species_conc_default.xml");
}

TEST(AntimonyUnits, test_species_conc_in_comp)
{
  compareFileTranslation("species_conc_in_comp");
}

TEST(AntimonyUnits, test_species_conc_in_comp_txt)
{
  compareStringTranslation("species a in C; a = 3 mM; C = 1e-3 liter; unit mM = 1e-3 mole / liter", "species_conc_in_comp.xml");
}

TEST(AntimonyUnits, test_subst_species_amt_default)
{
  compareFileTranslation("subst_species_amt_default");
}

TEST(AntimonyUnits, test_subst_species_amt_default_txt)
{
  compareStringTranslation("substanceOnly species a = 3 mole", "subst_species_amt_default.xml");
}

TEST(AntimonyUnits, test_subst_species_amt_in_comp)
{
  compareFileTranslation("subst_species_amt_in_comp");
}

TEST(AntimonyUnits, test_subst_species_amt_in_comp_txt)
{
  compareStringTranslation("substanceOnly species a in C; a = 3 mole; C = 2 mL; unit mL = 1e-3 liter", "subst_species_amt_in_comp.xml");
}

TEST(AntimonyUnits, test_unit_as_port)
{
  compareFileTranslation("unit_as_port");
}

TEST(AntimonyUnits, test_global_units)
{
  compareFileTranslation("global_units");
}

TEST(AntimonyUnits, test_global_units_txt)
{
  compareStringTranslation("length = meters; area = meters^2; volume = meters^3; substance = moles; extent = dimensionless; time_unit = seconds*60", "global_units.xml");
}

// https://github.com/sys-bio/antimony/issues/37 : a model unit that's just
// an alias for base 'kind' or another unit should just reference that.
TEST(AntimonyUnits, test_global_units_alias_txt)
{
  compareStringTranslation("m3 = meter^3; m2 = meter^2; unit bigm3 = m3; volume = m3; area = m2; substance = mole; "
    "length = metre; extent = mole; time_unit = second; "
    "a = 3; a has volume", "global_units_alias.xml");
}

TEST(AntimonyUnits, test_global_units_alias)
{
  compareFileTranslation("global_units_alias");
}

TEST(AntimonyUnits, test_autopromoted_units)
{
  compareFileTranslation("autopromoted_units");
  compareStringTranslation("model foo(p);unit mM = 10e-3 meter;p = 1 mM;end;F : foo(P)", "autopromoted_units.xml");
}


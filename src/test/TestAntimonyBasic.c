/**
 * \file    TestAntimonyBasic.c
 * \brief   Test Antimony's basic constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "sbml/SBMLTypes.h"
#include "stringx.h"

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareFileTranslation(const string& base)
{
  clearPreviousLoads();
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  fail_unless(string(atosbml) == matching);

  //Now check the roundtripped version:
  ret = loadSBMLString(matching.c_str());
  char* roundtrip = getAntimonyString(NULL);
  fail_unless(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  fail_unless(ret != -1);
  matching = getAntimonyString(NULL);
  fail_unless(string(roundtrip) == string(matching));

  delete doc;
  freeAll();
}

void compareFileTranslationWithRenaming(const string& base)
{
  clearPreviousLoads();
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".xml";
  long ret = loadSBMLFile(filename.c_str());
  fail_unless(ret != -1);
  char* sbmltoa = getAntimonyString(NULL);
  fail_unless(sbmltoa != NULL);
  char* sbmlrt = getSBMLString(NULL);
  fail_unless(sbmlrt != NULL);


  filename = dir + base + ".txt";
  ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* matching = getAntimonyString(NULL);
  fail_unless(string(sbmltoa) == string(matching));

  //Now check the roundtripped version:
  char* roundtrip = getSBMLString(NULL);
  fail_unless(roundtrip != NULL);
  fail_unless(string(roundtrip) == string(sbmlrt));

  freeAll();
}

void compareStringTranslation(const string& antimony, const string& sbml)
{
  clearPreviousLoads();
  long ret = loadAntimonyString(antimony.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string dir(TestDataDirectory);
  string sbmlfile = dir + sbml;
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matchingdoc = writeSBMLToStdString(doc);

  fail_unless(string(atosbml) == matchingdoc);
  delete doc;
  freeAll();
}

START_TEST (test_parameter)
{
  compareFileTranslation("parameter");
}
END_TEST

START_TEST (test_parameter_txt)
{
  compareStringTranslation("a=3", "parameter.xml");
}
END_TEST


START_TEST (test_reaction)
{
  compareFileTranslation("reaction");
}
END_TEST

START_TEST (test_reaction_txt)
{
  compareStringTranslation("J0: a->; k1", "reaction.xml");
}
END_TEST


START_TEST (test_compartment)
{
  compareFileTranslation("compartment");
}
END_TEST

START_TEST (test_compartment_txt)
{
  compareStringTranslation("x in y", "compartment.xml");
}
END_TEST


START_TEST (test_species)
{
  compareFileTranslation("species");
}
END_TEST

START_TEST (test_species_txt)
{
  compareStringTranslation("species x in y", "species.xml");
}
END_TEST


START_TEST (test_reactionIn)
{
  compareFileTranslation("reactionIn");
}
END_TEST

START_TEST (test_reactionIn_txt)
{
  compareStringTranslation("J0 in C: ->a; k1", "reactionIn.xml");
}
END_TEST


START_TEST (test_event)
{
  compareFileTranslation("event");
}
END_TEST

START_TEST (test_event_txt)
{
  compareStringTranslation("at(time>3): x=3", "event.xml");
}
END_TEST


START_TEST (test_eventPriority)
{
  compareFileTranslation("eventPriority");
}
END_TEST

START_TEST (test_eventPriority_txt)
{
  compareStringTranslation("at(time>3), priority=2: x=3", "eventPriority.xml");
}
END_TEST


START_TEST (test_eventDelay)
{
  compareFileTranslation("eventDelay");
}
END_TEST

START_TEST (test_eventDelay_txt)
{
  compareStringTranslation("at 2 after (time>3): x=3", "eventDelay.xml");
}
END_TEST


START_TEST (test_eventT0)
{
  compareFileTranslation("eventT0");
}
END_TEST

START_TEST (test_eventT0_txt)
{
  compareStringTranslation("at(time>3), t0=false: x=3", "eventT0.xml");
}
END_TEST


START_TEST (test_eventFromTrigger)
{
  compareFileTranslation("eventFromTrigger");
}
END_TEST

START_TEST (test_eventFromTrigger_txt)
{
  compareStringTranslation("at(time>3), fromTrigger=false: x=3", "eventFromTrigger.xml");
}
END_TEST


START_TEST (test_eventPersistent)
{
  compareFileTranslation("eventPersistent");
}
END_TEST

START_TEST (test_eventPersistent_txt)
{
  compareStringTranslation("at(time>3), persistent=false: x=3", "eventPersistent.xml");
}
END_TEST


START_TEST (test_initialValue)
{
  compareFileTranslation("initialValue");
}
END_TEST

START_TEST (test_initialValue_txt)
{
  compareStringTranslation("x=3", "initialValue.xml");
}
END_TEST


START_TEST (test_initialConcentration)
{
  compareFileTranslation("initialConcentration");
}
END_TEST

START_TEST (test_initialConcentration_txt)
{
  compareStringTranslation("species x=3", "initialConcentration.xml");
}
END_TEST


START_TEST (test_initialAmount)
{
  compareFileTranslation("initialAmount");
}
END_TEST

START_TEST (test_initialAmount_txt)
{
  compareStringTranslation("species x in C=3/C", "initialAmount.xml");
}
END_TEST


START_TEST (test_initialAssignment)
{
  compareFileTranslation("initialAssignment");
}
END_TEST

START_TEST (test_initialAssignment_txt)
{
  compareStringTranslation("x=4/6", "initialAssignment.xml");
}
END_TEST


START_TEST (test_interactionGeneric)
{
  compareFileTranslation("interactionGeneric");
}
END_TEST

START_TEST (test_interactionGeneric_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -( J0;", "interactionGeneric.xml");
}
END_TEST


START_TEST (test_interactionActivation)
{
  compareFileTranslation("interactionActivation");
}
END_TEST

START_TEST (test_interactionActivation_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -o J0;", "interactionActivation.xml");
}
END_TEST


START_TEST (test_interactionInhibition)
{
  compareFileTranslation("interactionInhibition");
}
END_TEST

START_TEST (test_interactionInhibition_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -| J0;", "interactionInhibition.xml");
}
END_TEST


START_TEST (test_rateRule)
{
  compareFileTranslation("rateRule");
}
END_TEST

START_TEST (test_rateRule_txt)
{
  compareStringTranslation("x'=4.4", "rateRule.xml");
}
END_TEST


START_TEST (test_assignmentRule)
{
  compareFileTranslation("assignmentRule");
}
END_TEST

START_TEST (test_assignmentRule_txt)
{
  compareStringTranslation("x:=4.8", "assignmentRule.xml");
}
END_TEST


START_TEST (test_units)
{
  compareFileTranslation("units");
}
END_TEST

START_TEST (test_units_txt)
{
  compareStringTranslation("unit mL = .001*liters", "units.xml");
}
END_TEST


START_TEST (test_compound_units1)
{
  compareFileTranslation("compound_units1");
}
END_TEST

START_TEST (test_compound_units1_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * 1 meters^2", "compound_units1.xml");
}
END_TEST


START_TEST (test_compound_units2)
{
  compareFileTranslation("compound_units2");
}
END_TEST

START_TEST (test_compound_units2_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * meters^2 / seconds^3 / ampere", "compound_units2.xml");
}
END_TEST


START_TEST (test_compound_units3)
{
  compareFileTranslation("compound_units3");
}
END_TEST

START_TEST (test_compound_units3_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * 1 meters^2 / 1 seconds^3 / 1 ampere", "compound_units3.xml");
}
END_TEST


START_TEST (test_compound_units4)
{
  compareFileTranslation("compound_units4");
}
END_TEST

START_TEST (test_compound_units4_txt)
{
  compareStringTranslation("unit persecondsq = 1 / seconds^2", "compound_units4.xml");
}
END_TEST


START_TEST (test_names)
{
  compareFileTranslation("names");
}
END_TEST

START_TEST (test_names_txt)
{
  compareStringTranslation("x is \"This Name!\"", "names.xml");
}
END_TEST

START_TEST (test_global_units)
{
  compareFileTranslation("global_units");
}
END_TEST

START_TEST (test_global_units_txt)
{
  compareStringTranslation("length = meters; area = meters^2; volume = meters^3; substance = moles; extent = dimensionless; time_unit = seconds*60", "global_units.xml");
}
END_TEST

START_TEST (test_parameter_inf)
{
  compareFileTranslation("parameter_inf");
}
END_TEST

START_TEST (test_parameter_inf_txt)
{
  compareStringTranslation("a=inf", "parameter_inf.xml");
}
END_TEST

START_TEST (test_parameter_neginf)
{
  compareFileTranslation("parameter_neginf");
}
END_TEST

START_TEST (test_parameter_neginf_txt)
{
  compareStringTranslation("a=-inf", "parameter_neginf.xml");
}
END_TEST

START_TEST (test_parameter_nan)
{
  compareFileTranslation("parameter_nan");
}
END_TEST

START_TEST (test_parameter_nan_txt)
{
  compareStringTranslation("a=nan", "parameter_nan.xml");
}
END_TEST

START_TEST (test_substance_only_species)
{
  compareFileTranslation("substance_only_species");
}
END_TEST

START_TEST (test_substance_only_species_txt)
{
  compareStringTranslation("substanceOnly species S1", "substance_only_species.xml");
}
END_TEST

START_TEST (test_fixname_in_submodel)
{
  compareFileTranslationWithRenaming("fixname_test");
}
END_TEST

START_TEST (test_right_half_reaction)
{
  compareFileTranslation("rxn_right");
}
END_TEST

START_TEST (test_right_half_reaction_txt)
{
  compareStringTranslation("-> S1;", "rxn_right.xml");
}
END_TEST

START_TEST (test_right_half_reaction_mod)
{
  compareFileTranslation("rxn_right_mod");
}
END_TEST

START_TEST (test_right_half_reaction_mod_txt)
{
  compareStringTranslation("module foo()\n -> S1;\n  end", "rxn_right_mod.xml");
}
END_TEST




Suite *
create_suite_Basic (void)
{
  Suite *suite = suite_create("Antimony Basic");
  TCase *tcase = tcase_create("Antimony Basic");


  tcase_add_test( tcase, test_fixname_in_submodel);

  tcase_add_test( tcase, test_parameter);
  tcase_add_test( tcase, test_parameter_txt);
  tcase_add_test( tcase, test_reaction);
  tcase_add_test( tcase, test_reaction_txt);
  tcase_add_test( tcase, test_compartment);
  tcase_add_test( tcase, test_compartment_txt);
  tcase_add_test( tcase, test_species);
  tcase_add_test( tcase, test_species_txt);
  tcase_add_test( tcase, test_reactionIn);
  tcase_add_test( tcase, test_reactionIn_txt);
  tcase_add_test( tcase, test_event);
  tcase_add_test( tcase, test_event_txt);
  tcase_add_test( tcase, test_eventPriority);
  tcase_add_test( tcase, test_eventPriority_txt);
  tcase_add_test( tcase, test_eventDelay);
  tcase_add_test( tcase, test_eventDelay_txt);
  tcase_add_test( tcase, test_eventT0);
  tcase_add_test( tcase, test_eventT0_txt);
  tcase_add_test( tcase, test_eventFromTrigger);
  tcase_add_test( tcase, test_eventFromTrigger_txt);
  tcase_add_test( tcase, test_eventPersistent);
  tcase_add_test( tcase, test_eventPersistent_txt);
  tcase_add_test( tcase, test_initialValue);
  tcase_add_test( tcase, test_initialValue_txt);
  tcase_add_test( tcase, test_initialConcentration);
  tcase_add_test( tcase, test_initialConcentration_txt);
  tcase_add_test( tcase, test_initialAmount);
  tcase_add_test( tcase, test_initialAmount_txt);
  tcase_add_test( tcase, test_initialAssignment);
  tcase_add_test( tcase, test_initialAssignment_txt);
  tcase_add_test( tcase, test_interactionGeneric);
  tcase_add_test( tcase, test_interactionGeneric_txt);
  tcase_add_test( tcase, test_interactionActivation);
  tcase_add_test( tcase, test_interactionActivation_txt);
  tcase_add_test( tcase, test_interactionInhibition);
  tcase_add_test( tcase, test_interactionInhibition_txt);
  tcase_add_test( tcase, test_rateRule);
  tcase_add_test( tcase, test_rateRule_txt);
  tcase_add_test( tcase, test_assignmentRule);
  tcase_add_test( tcase, test_assignmentRule_txt);
  tcase_add_test( tcase, test_units);
  tcase_add_test( tcase, test_units_txt);
  tcase_add_test( tcase, test_compound_units1);
  tcase_add_test( tcase, test_compound_units1_txt);
  tcase_add_test( tcase, test_compound_units2);
  tcase_add_test( tcase, test_compound_units2_txt);
  tcase_add_test( tcase, test_compound_units3);
  tcase_add_test( tcase, test_compound_units3_txt);
  tcase_add_test( tcase, test_names);
  tcase_add_test( tcase, test_names_txt);
  tcase_add_test( tcase, test_compound_units4);
  tcase_add_test( tcase, test_compound_units4_txt);
  tcase_add_test( tcase, test_global_units);
  tcase_add_test( tcase, test_global_units_txt);
  tcase_add_test( tcase, test_parameter_inf);
  tcase_add_test( tcase, test_parameter_inf_txt);
  tcase_add_test( tcase, test_parameter_neginf);
  tcase_add_test( tcase, test_parameter_neginf_txt);
  tcase_add_test( tcase, test_parameter_nan);
  tcase_add_test( tcase, test_parameter_nan_txt);
  tcase_add_test( tcase, test_substance_only_species);
  tcase_add_test( tcase, test_substance_only_species_txt);
  tcase_add_test( tcase, test_right_half_reaction);
  tcase_add_test( tcase, test_right_half_reaction_txt);
  tcase_add_test( tcase, test_right_half_reaction_mod);
  tcase_add_test( tcase, test_right_half_reaction_mod_txt);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



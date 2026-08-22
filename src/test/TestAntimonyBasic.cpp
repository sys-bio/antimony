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
#include "gtest/gtest.h"

#include "TestAntimonyUtil.h"

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

// compareFileTranslation, compareFileTranslationWithRenaming, and
// compareStringTranslation are defined in TestAntimonyUtil.cpp -- they used
// to live here and be reached from other files via `extern` declarations,
// but now that each suite is its own executable, they need to be in shared
// sources instead. See TestAntimonyUtil.h.

TEST(AntimonyBasic, test_annot_transfer)
{
  string dir(TestDataDirectory);
  long ret = loadSBMLFile((dir + "BIOMD0000000002.xml").c_str());
  char* stosbml = getCompSBMLString(NULL);
  freeAll();
}

TEST(AntimonyBasic, test_parameter)
{
  compareFileTranslation("parameter");
}

TEST(AntimonyBasic, test_parameter_txt)
{
  compareStringTranslation("a=3", "parameter.xml");
}

TEST(AntimonyBasic, test_reaction)
{
  compareFileTranslation("reaction");
}

TEST(AntimonyBasic, test_reaction_txt)
{
  compareStringTranslation("J0: a->; k1", "reaction.xml");
}

TEST(AntimonyBasic, test_compartment)
{
  compareFileTranslation("compartment");
}

TEST(AntimonyBasic, test_compartment_txt)
{
  compareStringTranslation("x in y", "compartment.xml");
}

TEST(AntimonyBasic, test_species)
{
  compareFileTranslation("species");
}

TEST(AntimonyBasic, test_species_txt)
{
  compareStringTranslation("species x in y", "species.xml");
}

TEST(AntimonyBasic, test_reactionIn)
{
  compareFileTranslation("reactionIn");
}

TEST(AntimonyBasic, test_reactionIn_txt)
{
  compareStringTranslation("J0 in C: ->a; k1", "reactionIn.xml");
}

TEST(AntimonyBasic, test_event)
{
  compareFileTranslation("event");
}

TEST(AntimonyBasic, test_event_txt)
{
  compareStringTranslation("at(time>3): x=3", "event.xml");
}

TEST(AntimonyBasic, test_eventPriority)
{
  compareFileTranslation("eventPriority");
}

TEST(AntimonyBasic, test_eventPriority_txt)
{
  compareStringTranslation("at(time>3), priority=2: x=3", "eventPriority.xml");
}

TEST(AntimonyBasic, test_eventDelay)
{
  compareFileTranslation("eventDelay");
}

TEST(AntimonyBasic, test_eventDelay_txt)
{
  compareStringTranslation("at 2 after (time>3): x=3", "eventDelay.xml");
}

TEST(AntimonyBasic, test_eventT0)
{
  compareFileTranslation("eventT0");
}

TEST(AntimonyBasic, test_eventT0_txt)
{
  compareStringTranslation("at(time>3), t0=false: x=3", "eventT0.xml");
}

TEST(AntimonyBasic, test_eventFromTrigger)
{
  compareFileTranslation("eventFromTrigger");
}

TEST(AntimonyBasic, test_eventFromTrigger_txt)
{
  compareStringTranslation("at(time>3), fromTrigger=false: x=3", "eventFromTrigger.xml");
}

TEST(AntimonyBasic, test_eventPersistent)
{
  compareFileTranslation("eventPersistent");
}

TEST(AntimonyBasic, test_eventPersistent_txt)
{
  compareStringTranslation("at(time>3), persistent=false: x=3", "eventPersistent.xml");
}

TEST(AntimonyBasic, test_event_nonBoolean)
{
    compareFileTranslation("event_nonBoolean");
}

TEST(AntimonyBasic, test_event_nonBoolean_txt)
{
    compareStringTranslation("at 5: x=3", "event_nonBoolean.xml");
}

TEST(AntimonyBasic, test_initialValue)
{
  compareFileTranslation("initialValue");
}

TEST(AntimonyBasic, test_initialValue_txt)
{
  compareStringTranslation("x=3", "initialValue.xml");
}

TEST(AntimonyBasic, test_initialConcentration)
{
  compareFileTranslation("initialConcentration");
}

TEST(AntimonyBasic, test_initialConcentration_txt)
{
  compareStringTranslation("species x=3", "initialConcentration.xml");
}

TEST(AntimonyBasic, test_initialAmount)
{
  compareFileTranslation("initialAmount");
}

TEST(AntimonyBasic, test_initialAmountsAndConcentrations)
{
  compareFileTranslation("initialAmountsAndConcentrations");
}

TEST(AntimonyBasic, test_initialAmount_txt)
{
  compareStringTranslation("species x in C=3/C", "initialAmount.xml");
}

TEST(AntimonyBasic, test_initialAssignment)
{
  compareFileTranslation("initialAssignment");
}

TEST(AntimonyBasic, test_initialAssignment_txt)
{
  compareStringTranslation("x=4/6", "initialAssignment.xml");
}

TEST(AntimonyBasic, test_interactionGeneric)
{
  compareFileTranslation("interactionGeneric");
}

TEST(AntimonyBasic, test_interactionGeneric_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -( J0;", "interactionGeneric.xml");
}

TEST(AntimonyBasic, test_interactionActivation)
{
  compareFileTranslation("interactionActivation");
}

TEST(AntimonyBasic, test_interactionActivation_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -o J0;", "interactionActivation.xml");
}

TEST(AntimonyBasic, test_interactionActivationDashO)
{
    compareFileTranslation("interactionActivationDashO");
}

TEST(AntimonyBasic, test_interactionActivationDashO_txt)
{
    compareStringTranslation("J0: S1->; - o*S2;Ji: S2 -o J0;", "interactionActivationDashO.xml");
}

TEST(AntimonyBasic, test_interactionInhibition)
{
  compareFileTranslation("interactionInhibition");
}

TEST(AntimonyBasic, test_interactionInhibition_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -| J0;", "interactionInhibition.xml");
}

TEST(AntimonyBasic, test_rateRule)
{
  compareFileTranslation("rateRule");
}

TEST(AntimonyBasic, test_rateRule_txt)
{
  compareStringTranslation("x'=4.4", "rateRule.xml");
}

TEST(AntimonyBasic, test_assignmentRule)
{
  compareFileTranslation("assignmentRule");
}

TEST(AntimonyBasic, test_assignmentRule_txt)
{
  compareStringTranslation("x:=4.8", "assignmentRule.xml");
}

TEST(AntimonyBasic, test_units)
{
  compareFileTranslation("units");
}

TEST(AntimonyBasic, test_units_txt)
{
  compareStringTranslation("unit mL = .001*liters", "units.xml");
}

TEST(AntimonyBasic, test_compound_units1)
{
  compareFileTranslation("compound_units1");
}

TEST(AntimonyBasic, test_compound_units1_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * 1 meters^2", "compound_units1.xml");
}

TEST(AntimonyBasic, test_compound_units2)
{
  compareFileTranslation("compound_units2");
}

TEST(AntimonyBasic, test_compound_units2_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * meters^2 / seconds^3 / ampere", "compound_units2.xml");
}

TEST(AntimonyBasic, test_compound_units3)
{
  compareFileTranslation("compound_units3");
}

TEST(AntimonyBasic, test_compound_units3_txt)
{
  compareStringTranslation("unit voltage = 1000 grams * 1 meters^2 / 1 seconds^3 / 1 ampere", "compound_units3.xml");
}

TEST(AntimonyBasic, test_compound_units4)
{
  compareFileTranslation("compound_units4");
}

TEST(AntimonyBasic, test_compound_units4_txt)
{
  compareStringTranslation("unit persecondsq = 1 / seconds^2", "compound_units4.xml");
}

TEST(AntimonyBasic, test_names)
{
  compareFileTranslation("names");
}

TEST(AntimonyBasic, test_names_txt)
{
  compareStringTranslation("x is \"This Name!\"", "names.xml");
}

TEST(AntimonyBasic, test_parameter_inf)
{
  compareFileTranslation("parameter_inf");
}

TEST(AntimonyBasic, test_parameter_inf_txt)
{
  compareStringTranslation("a=inf", "parameter_inf.xml");
}

TEST(AntimonyBasic, test_parameter_neginf)
{
  compareFileTranslation("parameter_neginf");
}

TEST(AntimonyBasic, test_parameter_neginf_txt)
{
  compareStringTranslation("a=-inf", "parameter_neginf.xml");
}

TEST(AntimonyBasic, test_parameter_nan)
{
  compareFileTranslation("parameter_nan");
}

TEST(AntimonyBasic, test_parameter_nan_txt)
{
  compareStringTranslation("a=nan", "parameter_nan.xml");
}

TEST(AntimonyBasic, test_substance_only_species)
{
  compareFileTranslation("substance_only_species");
}

TEST(AntimonyBasic, test_substance_only_species_txt)
{
  compareStringTranslation("substanceOnly species S1", "substance_only_species.xml");
}

TEST(AntimonyBasic, test_fixname_in_submodel)
{
  compareFileTranslationWithRenaming("fixname_test");
}

TEST(AntimonyBasic, test_right_half_reaction)
{
  compareFileTranslation("rxn_right");
}

TEST(AntimonyBasic, test_right_half_reaction_txt)
{
  compareStringTranslation("-> S1;", "rxn_right.xml");
}

TEST(AntimonyBasic, test_right_half_reaction_mod)
{
  compareFileTranslation("rxn_right_mod");
}

TEST(AntimonyBasic, test_right_half_reaction_mod_txt)
{
  compareStringTranslation("module foo()\n -> S1;\n  end", "rxn_right_mod.xml");
}

TEST(AntimonyBasic, test_module_name)
{
  compareFileTranslation("module_name");
}

TEST(AntimonyBasic, test_module_name_txt)
{
  compareStringTranslation("module foo()\n a=3;\n  end\nfoo is \"foo!\"", "module_name.xml");
}

TEST(AntimonyBasic, test_function_name)
{
  compareFileTranslation("function_name");
}

TEST(AntimonyBasic, test_function_name_txt)
{
  compareStringTranslation("function foo()\n 3;\n  end\nfoo is \"foo!\"", "function_name.xml");
}

TEST(AntimonyBasic, test_empty_cvterm_txt)
{
  compareStringTranslation("a hasPart \"\"", "empty_cvterm.xml");
}

TEST(AntimonyBasic, test_negparen)
{
  compareFileTranslation("negparen");
}

TEST(AntimonyBasic, test_negparen_txt)
{
  compareStringTranslation("a=-(x+2)", "negparen.xml");
}

TEST(AntimonyBasic, test_algrule)
{
    compareFileTranslation("algrule");
    compareStringTranslation("0=x-2", "algrule.xml");
}

TEST(AntimonyBasic, test_algrule_id)
{
    compareFileTranslation("algrule_id");
    compareStringTranslation("alg1: 0=x-2", "algrule_id.xml");
}

TEST(AntimonyBasic, test_algrule_idname)
{
    compareFileTranslation("algrule_idname");
    compareStringTranslation("alg1: 0=x-2; alg1 is \"algebraic rule 1\"", "algrule_idname.xml");
}

TEST(AntimonyBasic, test_name_as_id)
{
    //string sbml = "<?xml version = \"1.0\" encoding=\"UTF-8\"?>\n"
    //    "<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n"
    //    "  <model metaid=\"foo\" name=\"2foo-4-U+ \"/>\n"
    //    "</sbml>\n";
    string sbml = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n"
        "  <model metaid=\"foo\" name=\"2foo-4-U+ \"/>\n"
        "</sbml>\n";

    clearPreviousLoads();
    long ret = loadSBMLString(sbml.c_str());
    EXPECT_TRUE(ret != -1);
    char* sbml2a = getAntimonyString(NULL);
    string _2foo = "_2foo_4_U__";
    EXPECT_TRUE(string(sbml2a).find(_2foo) != string::npos);
    freeAll();

}

TEST(AntimonyBasic, test_floating_species_in_asnt_rule)
{
  compareFileTranslation("floating_species_in_asnt_rule");
}

TEST(AntimonyBasic, test_floating_species_in_rate_rule)
{
  compareFileTranslation("floating_species_in_rate_rule");
}

TEST(AntimonyBasic, test_kineticLaw_set_formula)
{
  compareFileTranslation("kl_set_formula");
}

TEST(AntimonyBasic, test_neg_reactant_and_product)
{
  compareFileTranslation("neg_reactant_and_product");
}

TEST(AntimonyBasic, test_neg_2_reactant_and_product)
{
  compareFileTranslation("neg_2_reactant_and_product");
}

TEST(AntimonyBasic, test_subtracted_reactant_and_product)
{
  compareFileTranslation("subtracted_reactant_and_product");
}

TEST(AntimonyBasic, test_subtracted_2_reactant_and_product)
{
  compareFileTranslation("subtracted_2_reactant_and_product");
}

TEST(AntimonyBasic, test_empty_rxn)
{
  compareFileTranslation("empty_rxn");
}

TEST(AntimonyBasic, test_empty_rxn_kl)
{
  compareFileTranslation("empty_rxn_kl");
}

TEST(AntimonyBasic, test_empty_event)
{
  compareFileTranslation("empty_event");
}

TEST(AntimonyBasic, test_speciesConversionFactor)
{
  compareFileTranslation("speciesConversionFactor");
}

TEST(AntimonyBasic, test_speciesConversionFactor_empty)
{
  compareFileTranslation("speciesConversionFactor_empty");
}

TEST(AntimonyBasic, test_modelConversionFactor)
{
  compareFileTranslation("model_conversion_factor");
}

TEST(AntimonyBasic, test_boolean_priority)
{
  compareFileTranslation("boolean_priority");
}

TEST(AntimonyBasic, test_function_flattening_with_predefined_constants)
{
  setRemoveFunctionDefinitions(true);
  compareFileTranslation("functions_with_constants");
  setRemoveFunctionDefinitions(false);
}

TEST(AntimonyBasic, test_table_example)
{
  compareFileTranslation("table_example");
}


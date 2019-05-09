/**
 * \file    TestAntimonySBO.c
 * \brief   Test Antimony's annotation syntax.
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

extern void compareFileTranslation(const string& base);
extern void compareFileTranslationWithRenaming(const string& base);
extern void compareStringTranslation(const string& antimony, const string& sbml);

START_TEST (test_SBO_param_txt1)
{
  compareStringTranslation("a.sboTerm = 25", "SBO_param.xml");
}
END_TEST

START_TEST (test_SBO_param_txt2)
{
  compareStringTranslation("a.sboTerm = SBO:0000025", "SBO_param.xml");
}
END_TEST

START_TEST (test_SBO_param)
{
  compareFileTranslation("SBO_param");
}
END_TEST

START_TEST (test_SBO_param2_txt1)
{
  compareStringTranslation("a = 3; a.sboTerm = 25", "SBO_param2.xml");
}
END_TEST

START_TEST (test_SBO_param2_txt2)
{
  compareStringTranslation("a = 3; a.sboTerm = SBO:0000025", "SBO_param2.xml");
}
END_TEST

START_TEST (test_SBO_param2)
{
  compareFileTranslation("SBO_param2");
}
END_TEST

START_TEST (test_SBO_species_txt)
{
  compareStringTranslation("species a.sboTerm = 25", "SBO_species.xml");
}
END_TEST

START_TEST (test_SBO_species)
{
  compareFileTranslation("SBO_species");
}
END_TEST

START_TEST (test_SBO_compartment_txt)
{
  compareStringTranslation("compartment a.sboTerm = 25", "SBO_compartment.xml");
}
END_TEST

START_TEST (test_SBO_compartment)
{
  compareFileTranslation("SBO_compartment");
}
END_TEST

START_TEST (test_SBO_module_txt)
{
  compareStringTranslation("model foo(); end; foo.sboTerm = 8", "SBO_module.xml");
}
END_TEST

START_TEST (test_SBO_module)
{
  compareFileTranslation("SBO_module");
}
END_TEST

START_TEST (test_SBO_function_txt)
{
  compareStringTranslation("function foo(); 3; end; foo.sboTerm = 8", "SBO_function.xml");
}
END_TEST

START_TEST (test_SBO_function)
{
  compareFileTranslation("SBO_function");
}
END_TEST

START_TEST (test_SBO_localvar_txt)
{
  compareStringTranslation("model foo(); sboTerm = 5; end", "SBO_localvar.xml");
}
END_TEST

START_TEST (test_SBO_localvar)
{
  compareFileTranslation("SBO_localvar");
}
END_TEST

START_TEST (test_SBO_submodel_txt)
{
  compareStringTranslation("model foo(); end; A: foo(); A.sboTerm = 8", "SBO_submodel.xml");
}
END_TEST

START_TEST (test_SBO_submodel)
{
  compareFileTranslation("SBO_submodel");
}
END_TEST

START_TEST (test_SBO_submodel_shadowed_txt)
{
  compareStringTranslation("model foo();  sboTerm=1;end;A: foo();A.sboTerm is b;A.sboTerm = 3;A.SBOTERM = 27;foo.sboTerm = 83", "SBO_submodel_shadowed.xml");
}
END_TEST

START_TEST (test_SBO_submodel_shadowed)
{
  compareFileTranslation("SBO_submodel_shadowed");
}
END_TEST

START_TEST (test_SBO_reaction_txt)
{
  compareStringTranslation("J0: A->;; J0.sboTerm = 888", "SBO_reaction.xml");
}
END_TEST

START_TEST (test_SBO_reaction)
{
  compareFileTranslation("SBO_reaction");
}
END_TEST

START_TEST (test_SBO_event_txt)
{
  compareStringTranslation("E0: at(time>3): b=4; E0.sboTerm=901", "SBO_event.xml");
}
END_TEST

START_TEST (test_SBO_event)
{
  compareFileTranslation("SBO_event");
}
END_TEST




Suite *
create_suite_SBO (void)
{
  Suite *suite = suite_create("Antimony SBO Terms");
  TCase *tcase = tcase_create("Antimony SBO Terms");

  tcase_add_test( tcase, test_SBO_param_txt1);
  tcase_add_test( tcase, test_SBO_param_txt2);
  tcase_add_test( tcase, test_SBO_param);
  tcase_add_test( tcase, test_SBO_param2_txt1);
  tcase_add_test( tcase, test_SBO_param2_txt2);
  tcase_add_test( tcase, test_SBO_param2);
  tcase_add_test( tcase, test_SBO_species_txt);
  tcase_add_test( tcase, test_SBO_species);
  tcase_add_test( tcase, test_SBO_compartment_txt);
  tcase_add_test( tcase, test_SBO_compartment);
  tcase_add_test( tcase, test_SBO_module_txt);
  tcase_add_test( tcase, test_SBO_module);
  tcase_add_test( tcase, test_SBO_function_txt);
  tcase_add_test( tcase, test_SBO_function);
  tcase_add_test( tcase, test_SBO_localvar_txt);
  tcase_add_test( tcase, test_SBO_localvar);
  tcase_add_test( tcase, test_SBO_submodel_txt);
  tcase_add_test( tcase, test_SBO_submodel);
  tcase_add_test( tcase, test_SBO_submodel_shadowed_txt);
  tcase_add_test( tcase, test_SBO_submodel_shadowed);
  tcase_add_test( tcase, test_SBO_reaction_txt);
  tcase_add_test( tcase, test_SBO_reaction);
  tcase_add_test( tcase, test_SBO_event_txt);
  tcase_add_test( tcase, test_SBO_event);



  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



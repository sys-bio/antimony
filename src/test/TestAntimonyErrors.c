/**
 * \file    TestAntimonyErrors.c
 * \brief   Test Antimony's basic constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "sbml/SBMLTypes.h"

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

START_TEST (unknown_file1)
{
  string filename = "nosuchfile.txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  freeAll();
}
END_TEST


START_TEST (unknown_file2)
{
  string filename = "nosuchfile.xml";
  long ret = loadSBMLFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Unable to read SBML file 'nosuchfile.xml' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (00002 [Error]) File unreadable.\n\n");
  fail_unless(error == expected);
  freeAll();
}
END_TEST


START_TEST (unknown_file3)
{
#ifndef NCELLML
  string filename = "nosuchfile.cellml";
  long ret = loadCellMLFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Unable to read CellML file 'nosuchfile.cellml' due to errors encountered when parsing the file.  Error(s) from the CellML API:\n\nservererror\n");
  fail_unless(error == expected);
  freeAll();
#endif
}
END_TEST


START_TEST (unknown_file4)
{
  string filename = "nosuchfile.txt";
  long ret = loadFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  freeAll();
}
END_TEST


START_TEST (unknown_file5)
{
  string filename = "nosuchdir/nosuchfile.txt";
  long ret = loadFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchdir/nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  freeAll();
}
END_TEST


START_TEST (unknown_models)
{
  char* nomod = getSBMLString("");
  fail_unless(nomod == NULL);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("No such module: ''.  Existing modules: '__main'");
  fail_unless(error == expected);
  nomod = getAntimonyString("");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
#ifndef NCELLML
  nomod = getCellMLString("");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
#endif

  nomod = getSBMLString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  expected = "No such module: 'nosuchmodel'.  Existing modules: '__main'";
  fail_unless(error == expected);
  nomod = getAntimonyString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
#ifndef NCELLML
  nomod = getCellMLString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
#endif
  freeAll();
}
END_TEST

void testError(const string& antimony, const string& error)
{
  clearPreviousLoads();
  long ret = loadAntimonyString(antimony.c_str());
  fail_unless(ret == -1);
  char* err = getLastError();
  fail_unless(err != NULL);
  fail_unless(error == (string)(err));
  freeAll();
}


START_TEST (no_end)
{
  testError("model foo\n  a=3\n", "Error in model string, line 2:  syntax error, unexpected end of file");
}
END_TEST


START_TEST (no_replace_ar_with_ia)
{
  testError("a:=3; a=4", "Error in model string, line 1:  Cannot set 'a' to have the initial value '4' because it already has an assignment rule, which applies at all times, including time=0.");
}
END_TEST

START_TEST (no_ar_and_rr1)
{
  testError("a:=3; a'=4", "Error in model string, line 1:  The variable 'a' is associated with an assignment rule, and may not additionally have a rate rule.");
}
END_TEST

START_TEST (no_ar_and_rr2)
{
  testError("a'=3; a:=4", "Error in model string, line 1:  The variable 'a' is associated with a rate rule, and may not additionally have an assignment rule.");
}
END_TEST

START_TEST (unknown_cvterm)
{
  testError("a=3; a foo \"BQB_incorrect\"", "Error in model string, line 1:  Unrecognized qualifier \"foo\"");
}
END_TEST

START_TEST (unknown_cvterm_mod)
{
  testError("model foo() a=3; end; foo bar \"BQB_incorrect\"", "Error in model string, line 1:  Unrecognized qualifier \"bar\"");
}
END_TEST

START_TEST (unknown_cvterm_func)
{
  testError("function foo(x) x+3; end; foo bar \"BQB_incorrect\"", "Error in model string, line 1:  Unrecognized qualifier \"bar\"");
}
END_TEST

START_TEST (no_sboterm_in_functions)
{
  testError("a = b.sboTerm", "Error in model string, line 1:  Unable to use the variable 'b.sboTerm', or any other variable of type 'SBO Term', inside a mathematical expression.");
}
END_TEST

START_TEST (no_interaction_in_functions)
{
  testError("Int1: a -| J0;; a = Int1", "Error in model string, line 1:  Unable to use the variable 'Int1', or any other variable of type 'Interaction', inside a mathematical expression.");
}
END_TEST

START_TEST (no_submod_in_functions)
{
  testError("model foo();end;A: foo();b = A", "Error in model string, line 1:  Unable to use the variable 'A', or any other variable of type 'Module', inside a mathematical expression.");
}
END_TEST

START_TEST (no_event_in_functions)
{
  testError("E0: at(time>3): b=3;b = E0", "Error in model string, line 1:  Unable to use the variable 'E0', or any other variable of type 'Event', inside a mathematical expression.");
}
END_TEST

START_TEST (no_deletions_in_functions)
{
  testError("model foo();  a=3;end;A: foo();delete A.a;x = A.a", "Error in model string, line 1:  Unable to use the variable 'A.a', or any other variable of type 'Deleted element', inside a mathematical expression.");
}
END_TEST

START_TEST (no_sboterm_synchronization1)
{
  testError("a is b.sboTerm", "Error in model string, line 1:  Unable to synchronize two symbols when one of them ('b.sboTerm') is an SBO term.");
}
END_TEST

START_TEST (no_sboterm_synchronization2)
{
  testError("b.sboTerm is a", "Error in model string, line 1:  Unable to synchronize two symbols when one of them ('b.sboTerm') is an SBO term.");
}
END_TEST

START_TEST (test_SBO_species_txt)
{
  testError("species a.sboTerm = 25", "Error in model string, line 1:  Unable to use the symbol 'a.sboTerm' in any context other than setting the value of an SBO term (i.e. 'a.sboTerm = 327' or 'a.sboTerm = SBO:0000327'.");
}
END_TEST

START_TEST (test_SBO_compartment_txt)
{
  testError("compartment a.sboTerm = 25", "Error in model string, line 1:  Unable to use the symbol 'a.sboTerm' in any context other than setting the value of an SBO term (i.e. 'a.sboTerm = 327' or 'a.sboTerm = SBO:0000327'.");
}
END_TEST

START_TEST (test_SBO_in_txt)
{
  testError("b in a.sboTerm", "Error in model string, line 1:  Unable to use the symbol 'a.sboTerm' in any context other than setting the value of an SBO term (i.e. 'a.sboTerm = 327' or 'a.sboTerm = SBO:0000327'.");
}
END_TEST

START_TEST (empty_interaction)
{
  testError("a-|;", "Error in model string, line 1:  When defining reaction '_J0':  Cannot create an interaction with a target of nothing.");
}
END_TEST

START_TEST (no_module_subelements)
{
  testError("module foo();end;foo.x = 3", "Error in model string, line 1:  Invalid syntax 'foo.x'. The only thing that can be set on 'foo' this way is 'sboTerm'.");
}
END_TEST

START_TEST (no_function_subelements)
{
  testError("function foo();3;end;foo.x = 3", "Error in model string, line 1:  Invalid syntax 'foo.x'. The only thing that can be set on 'foo' this way is 'sboTerm'.");
}
END_TEST

START_TEST (no_vectors1)
{
  testError("a = {3, 4}", "Error in model string, line 1:  Curly brackets detected in formula: '{3, 4}': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
}
END_TEST

START_TEST (no_vectors2)
{
  testError("A -> B; {3, 4}", "Error in model string, line 1:  Curly brackets detected in the reaction rate: '{3, 4}': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
}
END_TEST

START_TEST (no_vectors3)
{
  testError("at time>{3, 4}: a=3", "Error in model string, line 1:  Curly brackets detected in the event trigger: 'time > {3, 4}': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
}
END_TEST

START_TEST (no_uncertval_vectors)
{
  testError("a.mean = {3, 4}", "Error in model string, line 1:  Unable to set the value of 'a.mean' to be '{3, 4}':  this uncertainty parameter must only be a single value or a single variable.");
}
END_TEST

START_TEST (wrong_uncertspan_vector1)
{
  testError("a.confidenceInterval = 5", "Error in model string, line 1:  Unable to set the value of 'a.confidenceInterval' to be '5':  an uncertainty parameter of type confidenceInterval must be a vector of length two, marked with curly brackets (i.e. '{3, 8}').");
}
END_TEST

START_TEST (wrong_uncertspan_vector2)
{
  testError("a.range = {5, 2, 4}", "Error in model string, line 1:  Unable to set the value of 'a.range' to be '{5, 2, 4}':  an uncertainty parameter of type range must be a vector of length two, marked with curly brackets (i.e. '{3, 8}').");
}
END_TEST

START_TEST (wrong_uncertspan_units)
{
  testError("a.range = {5 moles, 2 seconds}", "Error in model string, line 1:  Unable to set the value of 'a.range' to be '{5 mole, 2 second}':  the units of both elements in the vector must be the same.");
}
END_TEST

START_TEST (uncertval_must_be_single1)
{
  testError("a.mean = 3+4", "Error in model string, line 1:  Unable to set the value of 'a.mean' to be '3 + 4':  this uncertainty parameter must only be a single value or a single variable.");
}
END_TEST

START_TEST (uncertval_must_be_single2)
{
  testError("a.mean = plus()", "Error in model string, line 1:  Unable to set the value of 'a.mean' to be 'plus()':  this uncertainty parameter must only be a single value or a single variable.");
}
END_TEST

/*
START_TEST (no_replace_ar_with_ia)
{
  testError("a:=3; a=4", "");
}
END_TEST
*/

Suite *
create_suite_Errors (void)
{
  Suite *suite = suite_create("Antimony Errors");
  TCase *tcase = tcase_create("Antimony Errors");

  tcase_add_test( tcase, unknown_file1);
  tcase_add_test( tcase, unknown_file2);
  tcase_add_test( tcase, unknown_file3);
  tcase_add_test( tcase, unknown_file4);
  tcase_add_test( tcase, unknown_file5);
  tcase_add_test( tcase, unknown_models);
  tcase_add_test( tcase, no_end);
  tcase_add_test( tcase, no_replace_ar_with_ia);
  tcase_add_test( tcase, no_ar_and_rr1);
  tcase_add_test( tcase, no_ar_and_rr2);
  tcase_add_test( tcase, unknown_cvterm);
  tcase_add_test( tcase, unknown_cvterm_mod);
  tcase_add_test( tcase, unknown_cvterm_func);

  tcase_add_test( tcase, no_sboterm_in_functions);
  tcase_add_test( tcase, no_interaction_in_functions);
  tcase_add_test( tcase, no_submod_in_functions);
  tcase_add_test( tcase, no_event_in_functions);
  tcase_add_test( tcase, no_deletions_in_functions);

  tcase_add_test( tcase, no_sboterm_synchronization1);
  tcase_add_test( tcase, no_sboterm_synchronization2);
  tcase_add_test( tcase, test_SBO_species_txt);
  tcase_add_test( tcase, test_SBO_compartment_txt);
  tcase_add_test( tcase, test_SBO_in_txt);

  tcase_add_test( tcase, empty_interaction);
  tcase_add_test( tcase, no_module_subelements);
  tcase_add_test( tcase, no_function_subelements);

  tcase_add_test( tcase, no_vectors1);
  tcase_add_test( tcase, no_vectors2);
  tcase_add_test( tcase, no_vectors3);
  tcase_add_test( tcase, no_uncertval_vectors);
  tcase_add_test( tcase, wrong_uncertspan_vector1);
  tcase_add_test( tcase, wrong_uncertspan_vector2);
  tcase_add_test( tcase, wrong_uncertspan_units);
  tcase_add_test( tcase, uncertval_must_be_single1);
  tcase_add_test( tcase, uncertval_must_be_single2);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



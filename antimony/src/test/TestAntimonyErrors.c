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

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



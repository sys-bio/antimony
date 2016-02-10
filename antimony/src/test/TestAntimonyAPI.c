/**
 * \file    TestAntimonyAPI.c
 * \brief   Test Antimony's API constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

START_TEST (test_getAntimonyString)
{
  loadString("a=3");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\n// Variable initializations:\na = 3;\n");

  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel1)
{
  loadString("a=3\nmodel foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "__main");


  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel2)
{
  loadString("a=3\nmodel *foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\n// Variable initializations:\na = 3;\n\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel3)
{
  loadString("model foo()\nb=10\nend\na=3");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "__main");


  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel4)
{
  loadString("model foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel5)
{
  loadString("model foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "bar");


  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel6)
{
  loadString("model *foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == "// Created by libAntimony v2.8.1\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
}
END_TEST


Suite *
create_suite_API (void)
{
  Suite *suite = suite_create("Antimony API");
  TCase *tcase = tcase_create("Antimony API");

  tcase_add_test( tcase, test_whatIsMainModel6);

  tcase_add_test( tcase, test_getAntimonyString);
  tcase_add_test( tcase, test_whatIsMainModel1);
  tcase_add_test( tcase, test_whatIsMainModel2);
  tcase_add_test( tcase, test_whatIsMainModel3);
  tcase_add_test( tcase, test_whatIsMainModel4);
  tcase_add_test( tcase, test_whatIsMainModel5);
  tcase_add_test( tcase, test_whatIsMainModel6);


  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



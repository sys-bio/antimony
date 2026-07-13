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
#include "gtest/gtest.h"

using namespace std;

extern string TestDataDirectory;

#include "TestAntimonyUtil.h"

TEST(AntimonySBO, test_SBO_param_txt1)
{
  compareStringTranslation("a.sboTerm = 25", "SBO_param.xml");
}

TEST(AntimonySBO, test_SBO_param_txt2)
{
  compareStringTranslation("a.sboTerm = SBO:0000025", "SBO_param.xml");
}

TEST(AntimonySBO, test_SBO_param)
{
  compareFileTranslation("SBO_param");
}

TEST(AntimonySBO, test_SBO_param2_txt1)
{
  compareStringTranslation("a = 3; a.sboTerm = 25", "SBO_param2.xml");
}

TEST(AntimonySBO, test_SBO_param2_txt2)
{
  compareStringTranslation("a = 3; a.sboTerm = SBO:0000025", "SBO_param2.xml");
}

TEST(AntimonySBO, test_SBO_param2)
{
  compareFileTranslation("SBO_param2");
}

TEST(AntimonySBO, test_SBO_module_txt)
{
  compareStringTranslation("model foo(); end; foo.sboTerm = 8", "SBO_module.xml");
}

TEST(AntimonySBO, test_SBO_module)
{
  compareFileTranslation("SBO_module");
}

TEST(AntimonySBO, test_SBO_function_txt)
{
  compareStringTranslation("function foo(); 3; end; foo.sboTerm = 8", "SBO_function.xml");
}

TEST(AntimonySBO, test_SBO_function)
{
  compareFileTranslation("SBO_function");
}

TEST(AntimonySBO, test_SBO_localvar_txt)
{
  compareStringTranslation("model foo(); sboTerm = 5; end", "SBO_localvar.xml");
}

TEST(AntimonySBO, test_SBO_localvar)
{
  compareFileTranslation("SBO_localvar");
}

TEST(AntimonySBO, test_SBO_submodel_txt)
{
  compareStringTranslation("model foo(); end; A: foo(); A.sboTerm = 8", "SBO_submodel.xml");
}

TEST(AntimonySBO, test_SBO_submodel)
{
  compareFileTranslation("SBO_submodel");
}

TEST(AntimonySBO, test_SBO_submodel_shadowed_txt)
{
  compareStringTranslation("model foo();  sboTerm=1;end;A: foo();A.sboTerm is b;A.sboTerm = 3;A.SBOTERM = 27;foo.sboTerm = 83", "SBO_submodel_shadowed.xml");
}

TEST(AntimonySBO, test_SBO_submodel_shadowed)
{
  compareFileTranslation("SBO_submodel_shadowed");
}

TEST(AntimonySBO, test_SBO_reaction_txt)
{
  compareStringTranslation("J0: A->;; J0.sboTerm = 888", "SBO_reaction.xml");
}

TEST(AntimonySBO, test_SBO_reaction)
{
  compareFileTranslation("SBO_reaction");
}

TEST(AntimonySBO, test_SBO_event_txt)
{
  compareStringTranslation("E0: at(time>3): b=4; E0.sboTerm=901", "SBO_event.xml");
}

TEST(AntimonySBO, test_SBO_event)
{
  compareFileTranslation("SBO_event");
}

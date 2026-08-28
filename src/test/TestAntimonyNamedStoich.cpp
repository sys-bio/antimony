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
#include "gtest/gtest.h"

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

#include "TestAntimonyUtil.h"

TEST(AntimonyNamedStoich, test_NamedStoichBasic)
{
    compareStringTranslation("J0: sr1 a->;", "namedstoich_basic.xml");
}

TEST(AntimonyNamedStoich, test_NamedStoichBasic_file)
{
    compareFileTranslation("namedstoich_basic");
}

TEST(AntimonyNamedStoich, test_NamedStoichValue)
{
    compareStringTranslation("J0: sr1 a->;; sr1 = 2", "namedstoich_value.xml");
}

TEST(AntimonyNamedStoich, test_NamedStoichValue_file)
{
    compareFileTranslation("namedstoich_value");
}

TEST(AntimonyNamedStoich, test_NamedStoichAssignment)
{
    compareStringTranslation("J0: sr1 a->;; sr1 := 2+1", "namedstoich_assignment.xml");
}

TEST(AntimonyNamedStoich, test_NamedStoichAssignment_file)
{
    compareFileTranslation("namedstoich_assignment");
}

TEST(AntimonyNamedStoich, test_NamedStoichRate)
{
    compareStringTranslation("J0: sr1 a->;; sr1' = 1.1", "namedstoich_rate.xml");
}

TEST(AntimonyNamedStoich, test_NamedStoichRate_file)
{
    compareFileTranslation("namedstoich_rate");
}

TEST(AntimonyNamedStoich, test_stoichiometries_with_same_name)
{
    compareFileTranslationWithDifferences("stoichiometries_with_same_name");
}

TEST(AntimonyNamedStoich, test_stoichiometries_with_same_name_in_multiple_reactions)
{
    compareFileTranslationWithDifferences("stoichiometries_with_same_name_in_multiple_reactions");
}

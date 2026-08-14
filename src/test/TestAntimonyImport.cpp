/**
 * \file    TestAntimonyImport.c
 * \brief   Test Antimony's behavior when importing SBML.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <iostream>

#include <string>
#include "gtest/gtest.h"

using namespace std;

extern string TestDataDirectory;

void compareFileImport(const string& base)
{
    clearPreviousLoads();
    // load document
    string dir(TestDataDirectory);
    string sbmlfile = dir + base + ".xml";
    long ret = loadSBMLFile(sbmlfile.c_str());
    EXPECT_TRUE(ret != -1);
    char* sbml2ant = getAntimonyString(NULL);
    EXPECT_TRUE(sbml2ant != NULL);

    string antimonyfile = dir + base + ".txt";
    ret = loadAntimonyFile(antimonyfile.c_str());
    EXPECT_TRUE(ret != -1);

    char* roundtrip = getAntimonyString(NULL);
    EXPECT_STREQ(roundtrip, sbml2ant);

    freeAll();
}

TEST(AntimonyImport, test_import_RateOf)
{
    compareFileImport("BIOMD0000000696");
}

TEST(AntimonyImport, test_import_GAMMA)
{
    compareFileImport("BIOMD0000000118");
}

TEST(AntimonyImport, test_import_same_unit_name)
{
    compareFileImport("same_unit_name");
}

TEST(AntimonyImport, test_import_default_compartment)
{
    compareFileImport("default_compartment");
}

TEST(AntimonyImport, test_import_volume)
{
    compareFileImport("volume");
}

// Tests reactions with multiple reactants/products, all with stoichiometry math.
// Originally MODEL1504010000_url.xml
TEST(AntimonyImport, test_import_MODEL1504010000_url)
{
    compareFileImport("oxphos_nad_redacted");
}

// SBML Test Suite case 1155:  a submodel event's delay is deleted via
// comp:Deletion, leaving the rest of the event (trigger and assignments)
// intact.  The event (and the variables its assignments target) should be
// promoted to new top-level elements aliased back to the submodel with
// 'is', rather than reprinted as a submodel-qualified redefinition.
TEST(AntimonyImport, test_import_case01155)
{
    compareFileImport("case01155");
}

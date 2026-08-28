/**
 * \file    TestAntimonyImport.c
 * \brief   Test Antimony's behavior when importing SBML.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <iostream>

#include <sstream>
#include <string>
#include <vector>
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
    string sbml2antStr(sbml2ant);

    // Check SBML import warnings exist, then strip them for round-trip 
    // check through Antimony.
    char* sbmlWarnings = getWarnings();
    if (sbmlWarnings != NULL) {
        istringstream warningstream(sbmlWarnings);
        string warningline;
        string header = "\n// Warnings from automatic translation:\n";
        while (getline(warningstream, warningline)) {
            header += "//    " + warningline + "\n";
        }
        header += "\n";
        size_t pos = sbml2antStr.find(header);
        EXPECT_NE(pos, string::npos) << "Expected translation-warnings header not found in the SBML import output.";
        if (pos != string::npos) {
            sbml2antStr.erase(pos, header.size());
        }
    }

    string antimonyfile = dir + base + ".txt";
    ret = loadAntimonyFile(antimonyfile.c_str());
    EXPECT_TRUE(ret != -1);

    char* roundtrip = getAntimonyString(NULL);
    EXPECT_STREQ(roundtrip, sbml2antStr.c_str());

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

TEST(AntimonyImport, test_two_default_compartments)
{
  compareFileImport("two_default_compartments");
}

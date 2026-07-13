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

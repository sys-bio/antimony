/**
 * \file    TestAntimonyCompressed.cpp
 * \brief   Test that Antimony reads compressed (bzip2 and zip) SBML files.
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <string>
#include "gtest/gtest.h"

using namespace std;

extern string TestDataDirectory;

// Loads a file with the given loader and returns its translation to Antimony.
static string loadAndTranslate(const string& filename, bool useLoadFile)
{
    clearPreviousLoads();
    string path = TestDataDirectory + filename;
    long ret = useLoadFile ? loadFile(path.c_str()) : loadSBMLFile(path.c_str());
    EXPECT_NE(ret, -1) << path << ": " << (getLastError() ? getLastError() : "");
    char* ant = getAntimonyString(NULL);
    EXPECT_TRUE(ant != NULL);
    return ant ? string(ant) : string();
}

TEST(AntimonyCompressed, loadSBMLFile_bzip2)
{
    string plain = loadAndTranslate("SBO_compartment.xml", false);
    ASSERT_FALSE(plain.empty());
    EXPECT_EQ(loadAndTranslate("SBO_compartment.xml.bz2", false), plain);
}

TEST(AntimonyCompressed, loadSBMLFile_zip)
{
    string plain = loadAndTranslate("SBO_compartment.xml", false);
    ASSERT_FALSE(plain.empty());
    EXPECT_EQ(loadAndTranslate("SBO_compartment.xml.zip", false), plain);
}

TEST(AntimonyCompressed, loadFile_bzip2)
{
    string plain = loadAndTranslate("SBO_compartment.xml", true);
    ASSERT_FALSE(plain.empty());
    EXPECT_EQ(loadAndTranslate("SBO_compartment.xml.bz2", true), plain);
}

TEST(AntimonyCompressed, loadFile_zip)
{
    string plain = loadAndTranslate("SBO_compartment.xml", true);
    ASSERT_FALSE(plain.empty());
    EXPECT_EQ(loadAndTranslate("SBO_compartment.xml.zip", true), plain);
}

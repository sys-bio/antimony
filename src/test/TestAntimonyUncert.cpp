/**
 * \file    TestAntimonyUncert.c
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
using namespace libsbml;

extern string TestDataDirectory;

#include "TestAntimonyUtil.h"

//We need this version because in some cases, loading the Antimony version and then retriving it
// directly ends up with spacing changes.  Instead, we need to convert it to SBML and *then* back
// to Antimony again.  (It's the difference between "{-25, 25}" and "{ - 25, 25}".)
void compareFileTranslationExtraRoundtrips(const string& base)
{
  clearPreviousLoads();
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  string sbmlfile = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  EXPECT_STREQ(atosbml, matching.c_str());

  //Now check the roundtripped version:
  ret = loadSBMLString(matching.c_str());
  char* roundtrip = getAntimonyString(NULL);
  EXPECT_TRUE(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  EXPECT_TRUE(ret != -1);
  string rtsbml = getSBMLString(NULL);
  ret = loadSBMLString(rtsbml.c_str());
  matching = getAntimonyString(NULL);
  EXPECT_STREQ(roundtrip, matching.c_str());

  delete doc;
  freeAll();
}

TEST(AntimonyUncert, test_mean_txt)
{
  compareStringTranslation("a.mean = 25", "mean.xml");
}

TEST(AntimonyUncert, test_mean)
{
  compareFileTranslation("mean");
}

TEST(AntimonyUncert, test_standardDeviation_txt)
{
  compareStringTranslation("a.standardDeviation = 25", "standardDeviation.xml");
}

TEST(AntimonyUncert, test_standardDeviation)
{
  compareFileTranslation("standardDeviation");
}

TEST(AntimonyUncert, test_coefficientOfVariation_txt)
{
  compareStringTranslation("a.coefficientOfVariation = 25", "coefficientOfVariation.xml");
}

TEST(AntimonyUncert, test_coefficientOfVariation)
{
  compareFileTranslation("coefficientOfVariation");
}

TEST(AntimonyUncert, test_kurtosis_txt)
{
  compareStringTranslation("a.kurtosis = 25", "kurtosis.xml");
}

TEST(AntimonyUncert, test_kurtosis)
{
  compareFileTranslation("kurtosis");
}

TEST(AntimonyUncert, test_median_txt)
{
  compareStringTranslation("a.median = 25", "median.xml");
}

TEST(AntimonyUncert, test_median)
{
  compareFileTranslation("median");
}

TEST(AntimonyUncert, test_mode_txt)
{
  compareStringTranslation("a.mode = 25", "mode.xml");
}

TEST(AntimonyUncert, test_mode)
{
  compareFileTranslation("mode");
}

TEST(AntimonyUncert, test_sampleSize_txt)
{
  compareStringTranslation("a.sampleSize = 25", "sampleSize.xml");
}

TEST(AntimonyUncert, test_sampleSize)
{
  compareFileTranslation("sampleSize");
}

TEST(AntimonyUncert, test_skewness_txt)
{
  compareStringTranslation("a.skewness = 25", "skewness.xml");
}

TEST(AntimonyUncert, test_skewness)
{
  compareFileTranslation("skewness");
}

TEST(AntimonyUncert, test_standardError_txt)
{
  compareStringTranslation("a.standardError = 25", "standardError.xml");
}

TEST(AntimonyUncert, test_standardError)
{
  compareFileTranslation("standardError");
}

TEST(AntimonyUncert, test_variance_txt)
{
  compareStringTranslation("a.variance = 25", "variance.xml");
}

TEST(AntimonyUncert, test_variance)
{
  compareFileTranslation("variance");
}

TEST(AntimonyUncert, test_confidenceInterval_txt)
{
  compareStringTranslation("a.confidenceInterval = {0, 25}", "confidenceInterval.xml");
}

TEST(AntimonyUncert, test_confidenceInterval)
{
  compareFileTranslation("confidenceInterval");
}

TEST(AntimonyUncert, test_credibleInterval_txt)
{
  compareStringTranslation("a.credibleInterval = {0, x}", "credibleInterval.xml");
}

TEST(AntimonyUncert, test_credibleInterval)
{
  compareFileTranslation("credibleInterval");
}

TEST(AntimonyUncert, test_interquartileRange_txt)
{
  compareStringTranslation("a.interquartileRange = {x, y}", "interquartileRange.xml");
}

TEST(AntimonyUncert, test_interquartileRange)
{
  compareFileTranslation("interquartileRange");
}

TEST(AntimonyUncert, test_range_txt)
{
  compareStringTranslation("a.range = {-25, 25}", "range.xml");
}

TEST(AntimonyUncert, test_range)
{
  compareFileTranslationExtraRoundtrips("range");
}

TEST(AntimonyUncert, test_externalParameter1_txt)
{
  compareStringTranslation("a.externalParameter = {-20, -15}; a.externalParameter is \"http://my.url/\"", "externalParameter1.xml");
}

TEST(AntimonyUncert, test_externalParameter1)
{
  compareFileTranslationExtraRoundtrips("externalParameter1");
}

TEST(AntimonyUncert, test_externalParameter2_txt)
{
  compareStringTranslation("a.externalParameter = x; a.externalParameter is \"http://my.url/\"", "externalParameter2.xml");
}

TEST(AntimonyUncert, test_externalParameter2)
{
  compareFileTranslation("externalParameter2");
}

TEST(AntimonyUncert, test_externalParameter3_txt)
{
  compareStringTranslation("a.externalParameter = -x; a.externalParameter is \"http://my.url/\"", "externalParameter3.xml");
}

TEST(AntimonyUncert, test_externalParameter3)
{
  compareFileTranslation("externalParameter3");
}

TEST(AntimonyUncert, test_distribution_txt)
{
  compareStringTranslation("a.distribution = normal(3, x)", "distribution.xml");
}

TEST(AntimonyUncert, test_distribution)
{
  compareFileTranslation("distribution");
}

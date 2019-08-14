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
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

extern void compareFileTranslation(const string& base);
extern void compareFileTranslationWithRenaming(const string& base);
extern void compareStringTranslation(const string& antimony, const string& sbml);

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
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matching = writeSBMLToStdString(doc);
  fail_unless(string(atosbml) == matching);

  //Now check the roundtripped version:
  ret = loadSBMLString(matching.c_str());
  char* roundtrip = getAntimonyString(NULL);
  fail_unless(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  fail_unless(ret != -1);
  string rtsbml = getSBMLString(NULL);
  ret = loadSBMLString(rtsbml.c_str());
  matching = getAntimonyString(NULL);
  fail_unless(string(roundtrip) == string(matching));

  delete doc;
  freeAll();
}



START_TEST (test_mean_txt)
{
  compareStringTranslation("a.mean = 25", "mean.xml");
}
END_TEST

START_TEST (test_mean)
{
  compareFileTranslation("mean");
}
END_TEST

START_TEST (test_standardDeviation_txt)
{
  compareStringTranslation("a.standardDeviation = 25", "standardDeviation.xml");
}
END_TEST

START_TEST (test_standardDeviation)
{
  compareFileTranslation("standardDeviation");
}
END_TEST

START_TEST (test_coefficientOfVariation_txt)
{
  compareStringTranslation("a.coefficientOfVariation = 25", "coefficientOfVariation.xml");
}
END_TEST

START_TEST (test_coefficientOfVariation)
{
  compareFileTranslation("coefficientOfVariation");
}
END_TEST


START_TEST (test_kurtosis_txt)
{
  compareStringTranslation("a.kurtosis = 25", "kurtosis.xml");
}
END_TEST

START_TEST (test_kurtosis)
{
  compareFileTranslation("kurtosis");
}
END_TEST


START_TEST (test_median_txt)
{
  compareStringTranslation("a.median = 25", "median.xml");
}
END_TEST

START_TEST (test_median)
{
  compareFileTranslation("median");
}
END_TEST


START_TEST (test_mode_txt)
{
  compareStringTranslation("a.mode = 25", "mode.xml");
}
END_TEST

START_TEST (test_mode)
{
  compareFileTranslation("mode");
}
END_TEST


START_TEST (test_sampleSize_txt)
{
  compareStringTranslation("a.sampleSize = 25", "sampleSize.xml");
}
END_TEST

START_TEST (test_sampleSize)
{
  compareFileTranslation("sampleSize");
}
END_TEST


START_TEST (test_skewness_txt)
{
  compareStringTranslation("a.skewness = 25", "skewness.xml");
}
END_TEST

START_TEST (test_skewness)
{
  compareFileTranslation("skewness");
}
END_TEST


START_TEST (test_standardError_txt)
{
  compareStringTranslation("a.standardError = 25", "standardError.xml");
}
END_TEST

START_TEST (test_standardError)
{
  compareFileTranslation("standardError");
}
END_TEST


START_TEST (test_variance_txt)
{
  compareStringTranslation("a.variance = 25", "variance.xml");
}
END_TEST

START_TEST (test_variance)
{
  compareFileTranslation("variance");
}
END_TEST


START_TEST (test_confidenceInterval_txt)
{
  compareStringTranslation("a.confidenceInterval = {0, 25}", "confidenceInterval.xml");
}
END_TEST

START_TEST (test_confidenceInterval)
{
  compareFileTranslation("confidenceInterval");
}
END_TEST


START_TEST (test_credibleInterval_txt)
{
  compareStringTranslation("a.credibleInterval = {0, x}", "credibleInterval.xml");
}
END_TEST

START_TEST (test_credibleInterval)
{
  compareFileTranslation("credibleInterval");
}
END_TEST


START_TEST (test_interquartileRange_txt)
{
  compareStringTranslation("a.interquartileRange = {x, y}", "interquartileRange.xml");
}
END_TEST

START_TEST (test_interquartileRange)
{
  compareFileTranslation("interquartileRange");
}
END_TEST


START_TEST (test_range_txt)
{
  compareStringTranslation("a.range = {-25, 25}", "range.xml");
}
END_TEST

START_TEST (test_range)
{
  compareFileTranslationExtraRoundtrips("range");
}
END_TEST


START_TEST (test_externalParameter1_txt)
{
  compareStringTranslation("a.externalParameter = {-20, -15}; a.externalParameter is \"http://my.url/\"", "externalParameter1.xml");
}
END_TEST

START_TEST (test_externalParameter1)
{
  compareFileTranslationExtraRoundtrips("externalParameter1");
}
END_TEST


START_TEST (test_externalParameter2_txt)
{
  compareStringTranslation("a.externalParameter = x; a.externalParameter is \"http://my.url/\"", "externalParameter2.xml");
}
END_TEST

START_TEST (test_externalParameter2)
{
  compareFileTranslation("externalParameter2");
}
END_TEST


START_TEST (test_externalParameter3_txt)
{
  compareStringTranslation("a.externalParameter = -x; a.externalParameter is \"http://my.url/\"", "externalParameter3.xml");
}
END_TEST

START_TEST (test_externalParameter3)
{
  compareFileTranslation("externalParameter3");
}
END_TEST


START_TEST (test_distribution_txt)
{
  compareStringTranslation("a.distribution = normal(3, x)", "distribution.xml");
}
END_TEST

START_TEST (test_distribution)
{
  compareFileTranslation("distribution");
}
END_TEST



Suite *
create_suite_Uncert (void)
{
  Suite *suite = suite_create("Antimony Uncert Terms");
  TCase *tcase = tcase_create("Antimony Uncert Terms");

  tcase_add_test( tcase, test_mean_txt);
  tcase_add_test( tcase, test_mean);
  tcase_add_test( tcase, test_standardDeviation_txt);
  tcase_add_test( tcase, test_standardDeviation);
  tcase_add_test( tcase, test_coefficientOfVariation_txt);
  tcase_add_test( tcase, test_coefficientOfVariation);
  tcase_add_test( tcase, test_kurtosis_txt);
  tcase_add_test( tcase, test_kurtosis);
  tcase_add_test( tcase, test_median_txt);
  tcase_add_test( tcase, test_median);
  tcase_add_test( tcase, test_mode_txt);
  tcase_add_test( tcase, test_mode);
  tcase_add_test( tcase, test_sampleSize_txt);
  tcase_add_test( tcase, test_sampleSize);
  tcase_add_test( tcase, test_skewness_txt);
  tcase_add_test( tcase, test_skewness);
  tcase_add_test( tcase, test_standardError_txt);
  tcase_add_test( tcase, test_standardError);
  tcase_add_test( tcase, test_variance_txt);
  tcase_add_test( tcase, test_variance);
  tcase_add_test( tcase, test_confidenceInterval_txt);
  tcase_add_test( tcase, test_confidenceInterval);
  tcase_add_test( tcase, test_credibleInterval_txt);
  tcase_add_test( tcase, test_credibleInterval);
  tcase_add_test( tcase, test_interquartileRange_txt);
  tcase_add_test( tcase, test_interquartileRange);
  tcase_add_test( tcase, test_range_txt);
  tcase_add_test( tcase, test_range);
  tcase_add_test( tcase, test_externalParameter1_txt);
  tcase_add_test( tcase, test_externalParameter1);
  tcase_add_test( tcase, test_externalParameter2_txt);
  tcase_add_test( tcase, test_externalParameter2);
  tcase_add_test( tcase, test_externalParameter3_txt);
  tcase_add_test( tcase, test_externalParameter3);
  tcase_add_test( tcase, test_distribution_txt);
  tcase_add_test( tcase, test_distribution);


  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



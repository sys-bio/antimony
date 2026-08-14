/**
 * \file    TestAntimonyFlattening.c
 * \brief   Compare Antimony's flattening to libsbml's internal tests of the same.
 * \author  Lucian Smith
 * 
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include "stringx.h" // NormalizeLineEndings
#include <sbml/SBMLTypes.h>
#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/packages/comp/common/CompExtensionTypes.h>

#include <string>
#include "gtest/gtest.h"
#include <fstream>
#include <cerrno>

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

void compareFileFlattening(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  string dir(TestDataDirectory);
  string filename = dir + "from-libsbml/" + base + ".xml";

  //Get the Antimony-flattened version
  long ret = loadSBMLFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* atosbml = getSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);
  SBMLDocument* doc = readSBMLFromString(atosbml);
  Model* model = doc->getModel();
  model->getListOfCompartments()->sort();
  model->getListOfSpecies()->sort();
  model->getListOfParameters()->sort();
  model->getListOfFunctionDefinitions()->sort();
  model->getListOfReactions()->sort();
  for (unsigned int rxn=0; rxn<model->getNumReactions(); rxn++) {
    model->getReaction(rxn)->getListOfModifiers()->sort();
  }
  string atosbml_libs = writeSBMLToStdString(doc);
  delete doc;

  //Get the SBML-flattened version
  doc = readSBMLFromFile(filename.c_str());
  model = doc->getModel();
  EXPECT_TRUE(model != NULL);
  ConversionProperties props;
  props.addOption("flatten comp");
  props.addOption("performValidation", true);
  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(props);
  converter->setDocument(doc);
  int result = converter->convert();
  EXPECT_TRUE(result == LIBSBML_OPERATION_SUCCESS);
  string sbmlFlat = writeSBMLToStdString(doc);
  ret = loadSBMLString(sbmlFlat.c_str());
  EXPECT_TRUE(ret != -1);
  char* newSbmlFlat = getSBMLString(NULL);
  delete doc;
  doc = readSBMLFromString(newSbmlFlat);
  model = doc->getModel();
  EXPECT_TRUE(model != NULL);
  model->setName(model->getId()); //Because Antimony does this.
  model->getListOfCompartments()->sort();
  model->getListOfSpecies()->sort();
  model->getListOfParameters()->sort();
  model->getListOfFunctionDefinitions()->sort();
  model->getListOfReactions()->sort();
  for (unsigned int rxn=0; rxn<model->getNumReactions(); rxn++) {
    model->getReaction(rxn)->getListOfModifiers()->sort();
  }

  //Compare them!
  if (base=="test41" || base=="replace_rule") {
    // can't get these to use the supplied metaid
    elideMetaIds(doc);
    sbmlFlat = writeSBMLToStdString(doc);
    EXPECT_STREQ(elideMetaIdsFromSBMLstring(atosbml_libs).c_str(), sbmlFlat.c_str());
  } else {
    sbmlFlat = writeSBMLToStdString(doc);
    EXPECT_STREQ(atosbml_libs.c_str(), sbmlFlat.c_str());
  }

  delete converter;
  delete doc;
  freeAll();
}

//This version of the function is used when Antimony flattening and SBML flattening are functionally
// equivalent, but differ in the specifics.  'subdir' is the test-data subdirectory the files live in
// (with a trailing slash, or blank for test-data itself), and 'cc' is the component-connector string
// used when flattening still-qualified submodel variables into flat SBML ids.
void compareFileFlatteningWithDifferences(const string& base, const string& subdir = "from-libsbml/", const string& cc = "__")
{
  clearPreviousLoads();
  g_registry.SetCC(cc);
  string dir(TestDataDirectory);
  string filename = dir + subdir + base + ".xml";
  string antfile = dir + subdir + base + ".txt";
  string flatfile = dir + subdir + base + "_flat.xml";

  //Get the Antimony-flattened version
  long ret = loadSBMLFile(filename.c_str());
  EXPECT_TRUE(ret != -1);
  char* sbml2ant = getAntimonyString(NULL);
  EXPECT_TRUE(sbml2ant != NULL);
  char* sbmlflat = getSBMLString(NULL);

  std::ifstream t(antfile.c_str());
  std::stringstream sbml2ant_ref;
  sbml2ant_ref << t.rdbuf();
  EXPECT_STREQ(NormalizeLineEndings(sbml2ant_ref.str()).c_str(), NormalizeLineEndings(string(sbml2ant)).c_str());

  ret = loadSBMLString(sbmlflat);
  sbmlflat = getSBMLString(NULL);

  std::ifstream t2(flatfile.c_str());
  std::stringstream sbmlflat_ref;
  sbmlflat_ref << t2.rdbuf();

  //string sf_r = sbmlflat_ref.str();
  EXPECT_STREQ(elideMetaIdsFromSBMLstring(NormalizeLineEndings(sbmlflat_ref.str())).c_str(), elideMetaIdsFromSBMLstring(NormalizeLineEndings(string(sbmlflat))).c_str());

  freeAll();
}

TEST(AntimonyFlattening, test_aggregate)
{
  compareFileFlattening("aggregate");
}

TEST(AntimonyFlattening, test_complexified)
{
  compareFileFlattening("complexified");
}

TEST(AntimonyFlattening, test_complexified2)
{
  compareFileFlattening("complexified2");
}

TEST(AntimonyFlattening, test_CompTest)
{
  compareFileFlatteningWithDifferences("CompTest");
}

TEST(AntimonyFlattening, test_doubleext)
{
  compareFileFlattening("doubleext");
}

TEST(AntimonyFlattening, test_doubleext2)
{
  compareFileFlattening("doubleext2");
}

TEST(AntimonyFlattening, test_dropports)
{
  compareFileFlattening("dropports");
}

TEST(AntimonyFlattening, test_eg_import_external)
{
  compareFileFlattening("eg-import-external");
}

TEST(AntimonyFlattening, test_eg_ports)
{
  compareFileFlattening("eg-ports");
}

TEST(AntimonyFlattening, test_eg_replacement)
{
  compareFileFlattening("eg-replacement");
}

TEST(AntimonyFlattening, test_eg_simple_aggregate)
{
  compareFileFlattening("eg-simple-aggregate");
}

TEST(AntimonyFlattening, test_enzyme_identical)
{
  compareFileFlattening("enzyme_identical");
}

TEST(AntimonyFlattening, test_enzyme_model)
{
  compareFileFlattening("enzyme_model");
}

TEST(AntimonyFlattening, test_exchangetest)
{
  compareFileFlatteningWithDifferences("exchangetest");
}

TEST(AntimonyFlattening, test_QTPop)
{
  compareFileFlatteningWithDifferences("QTPop");
}

TEST(AntimonyFlattening, test_replace_implied_deletion)
{
  compareFileFlattening("replace_implied_deletion");
}

TEST(AntimonyFlattening, test_replace_implied_deletion2)
{
  compareFileFlattening("replace_implied_deletion2");
}

TEST(AntimonyFlattening, test_replace_rule)
{
  compareFileFlattening("replace_rule");
}

TEST(AntimonyFlattening, test_replace_rules_and_constraints)
{
  compareFileFlatteningWithDifferences("replace_rules_and_constraints");
}

TEST(AntimonyFlattening, test_test1)
{
  compareFileFlattening("test1");
}

TEST(AntimonyFlattening, test_test2)
{
  compareFileFlattening("test2");
}

TEST(AntimonyFlattening, test_test3)
{
  compareFileFlattening("test3");
}

TEST(AntimonyFlattening, test_test4)
{
  compareFileFlattening("test4");
}

TEST(AntimonyFlattening, test_test5)
{
  compareFileFlattening("test5");
}

TEST(AntimonyFlattening, test_test6)
{
  compareFileFlattening("test6");
}

TEST(AntimonyFlattening, test_test7)
{
  compareFileFlattening("test7");
}

TEST(AntimonyFlattening, test_test8)
{
  compareFileFlattening("test8");
}

TEST(AntimonyFlattening, test_test9)
{
  compareFileFlattening("test9");
}

TEST(AntimonyFlattening, test_test10)
{
  compareFileFlattening("test10");
}

TEST(AntimonyFlattening, test_test11)
{
  compareFileFlattening("test11");
}

TEST(AntimonyFlattening, test_test12)
{
  compareFileFlattening("test12");
}

TEST(AntimonyFlattening, test_test13)
{
  compareFileFlattening("test13");
}

TEST(AntimonyFlattening, test_test14)
{
  compareFileFlattening("test14");
}

TEST(AntimonyFlattening, test_test15)
{
  compareFileFlattening("test15");
}

TEST(AntimonyFlattening, test_test16)
{
  compareFileFlattening("test16");
}

TEST(AntimonyFlattening, test_test17)
{
  compareFileFlattening("test17");
}

TEST(AntimonyFlattening, test_test18)
{
  compareFileFlattening("test18");
}

TEST(AntimonyFlattening, test_test19)
{
  compareFileFlattening("test19");
}

TEST(AntimonyFlattening, test_test20)
{
  compareFileFlattening("test20");
}

TEST(AntimonyFlattening, test_test21)
{
  compareFileFlattening("test21");
}

TEST(AntimonyFlattening, test_test22)
{
  compareFileFlatteningWithDifferences("test22");
}

TEST(AntimonyFlattening, test_test23)
{
  compareFileFlatteningWithDifferences("test23");
}

TEST(AntimonyFlattening, test_test24)
{
  compareFileFlatteningWithDifferences("test24");
}

TEST(AntimonyFlattening, test_test25)
{
  compareFileFlatteningWithDifferences("test25");
}

TEST(AntimonyFlattening, test_test26)
{
  compareFileFlattening("test26");
}

TEST(AntimonyFlattening, test_test27)
{
  compareFileFlatteningWithDifferences("test27");
}

TEST(AntimonyFlattening, test_test28)
{
  compareFileFlatteningWithDifferences("test28");
}

TEST(AntimonyFlattening, test_test29)
{
  compareFileFlattening("test29");
}

TEST(AntimonyFlattening, test_test30)
{
  compareFileFlattening("test30");
}

TEST(AntimonyFlattening, test_test31)
{
  compareFileFlattening("test31");
}

TEST(AntimonyFlattening, test_test32)
{
  compareFileFlattening("test32");
}

TEST(AntimonyFlattening, test_test33)
{
  compareFileFlattening("test33");
}

TEST(AntimonyFlattening, test_test34)
{
  compareFileFlattening("test34");
}

TEST(AntimonyFlattening, test_test35)
{
  compareFileFlatteningWithDifferences("test35");
}

TEST(AntimonyFlattening, test_test36)
{
  compareFileFlatteningWithDifferences("test36");
}

TEST(AntimonyFlattening, test_test37)
{
  compareFileFlatteningWithDifferences("test37");
}

TEST(AntimonyFlattening, test_test38)
{
  compareFileFlatteningWithDifferences("test38");
}

TEST(AntimonyFlattening, test_deleted_kinetic_law)
{
  compareFileFlatteningWithDifferences("deleted_kinetic_law", "", "_");
}

TEST(AntimonyFlattening, test_deleted_species_reference)
{
  compareFileFlatteningWithDifferences("deleted_species_reference", "", "_");
}

TEST(AntimonyFlattening, test_test39)
{
  compareFileFlatteningWithDifferences("test39");
}

TEST(AntimonyFlattening, test_test40)
{
  compareFileFlattening("test40");
}

TEST(AntimonyFlattening, test_test41)
{
  compareFileFlattening("test41");
}

TEST(AntimonyFlattening, test_test42)
{
  compareFileFlattening("test42");
}

TEST(AntimonyFlattening, test_test43)
{
  compareFileFlattening("test43");
}

TEST(AntimonyFlattening, test_test44)
{
  compareFileFlatteningWithDifferences("test44");
}

TEST(AntimonyFlattening, test_test45)
{
  compareFileFlatteningWithDifferences("test45");
}

TEST(AntimonyFlattening, test_test46)
{
  compareFileFlatteningWithDifferences("test46");
}

TEST(AntimonyFlattening, test_test47)
{
  compareFileFlatteningWithDifferences("test47");
}

TEST(AntimonyFlattening, test_test48)
{
  compareFileFlatteningWithDifferences("test48");
}

TEST(AntimonyFlattening, test_test49)
{
  compareFileFlattening("test49");
}

TEST(AntimonyFlattening, test_test50)
{
  compareFileFlattening("test50");
}

TEST(AntimonyFlattening, test_test51)
{
  compareFileFlattening("test51");
}

TEST(AntimonyFlattening, test_test52)
{
  compareFileFlattening("test52");
}

TEST(AntimonyFlattening, test_test53)
{
  compareFileFlatteningWithDifferences("test53", "from-libsbml/", "_");
}

TEST(AntimonyFlattening, test_test54)
{
  //This actually doesn't delete the deletion, as it should, but it should tell the user that in the Antimony version.
  compareFileFlatteningWithDifferences("test54");
}

TEST(AntimonyFlattening, test_test55)
{
  compareFileFlattening("test55");
}

TEST(AntimonyFlattening, test_test56)
{
  compareFileFlattening("test56");
}

TEST(AntimonyFlattening, test_test57)
{
  compareFileFlattening("test57");
}

//TEST(AntimonyFlattening, test_test58)
//{
//  compareFileFlatteningWithDifferences("test58");
//}
//END_TEST

//TEST(AntimonyFlattening, test_test59)
//{
//  compareFileFlatteningWithDifferences("test59");
//}
//END_TEST

TEST(AntimonyFlattening, test_test60)
{
  compareFileFlattening("test60");
}

//TEST(AntimonyFlattening, test_test61)
//{
//  compareFileFlatteningWithDifferences("test61");
//}
//END_TEST

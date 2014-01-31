/**
 * \file    TestAntimonyFlattening.c
 * \brief   Compare Antimony's flattening to libsbml's internal tests of the same.
 * \author  Lucian Smith
 * 
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include <sbml/SBMLTypes.h>
#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/packages/comp/common/CompExtensionTypes.h>

#include <string>
#include <check.h>
#include <fstream>
#include <cerrno>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareFileFlattening(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  string dir(TestDataDirectory);
  string filename = dir + "from-libsbml/" + base + ".xml";

  //Get the Antimony-flattened version
  long ret = loadSBMLFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getSBMLString(NULL);
  fail_unless(atosbml != NULL);
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
  delete atosbml;
  atosbml = writeSBMLToString(doc);
  delete doc;

  //Get the SBML-flattened version
  doc = readSBMLFromFile(filename.c_str());
  model = doc->getModel();
  fail_unless(model != NULL);
  ConversionProperties* props = new ConversionProperties();
  props->addOption("flatten comp");
  props->addOption("performValidation", true);
  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  converter->setDocument(doc);
  int result = converter->convert();
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);
  char* sbmlFlat = writeSBMLToString(doc);
  ret = loadSBMLString(sbmlFlat);
  fail_unless(ret != -1);
  delete sbmlFlat;
  sbmlFlat = getSBMLString(NULL);
  delete doc;
  doc = readSBMLFromString(sbmlFlat);
  model = doc->getModel();
  fail_unless(model != NULL);
  model->setName(model->getId()); //Because Antimony does this.
  model->getListOfCompartments()->sort();
  model->getListOfSpecies()->sort();
  model->getListOfParameters()->sort();
  model->getListOfFunctionDefinitions()->sort();
  model->getListOfReactions()->sort();
  for (unsigned int rxn=0; rxn<model->getNumReactions(); rxn++) {
    model->getReaction(rxn)->getListOfModifiers()->sort();
  }
  model->unsetMetaId();
  delete sbmlFlat;
  sbmlFlat = writeSBMLToString(doc);

  //Compare them!
  fail_unless(string(atosbml) == string(sbmlFlat));

  delete doc;
  delete atosbml;
  delete sbmlFlat;
}

//This version of the function is used when Antimony flattening and SBML flattening are functionally 
// equivalent, but differ in the specifics.
void compareFileFlatteningWithDifferences(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  string dir(TestDataDirectory);
  string filename = dir + "from-libsbml/" + base + ".xml";
  string antfile = dir + "from-libsbml/" + base + ".txt";
  string flatfile = dir + "from-libsbml/" + base + "_flat.xml";

  //Get the Antimony-flattened version
  long ret = loadSBMLFile(filename.c_str());
  fail_unless(ret != -1);
  char* sbml2ant = getAntimonyString(NULL);
  fail_unless(sbml2ant != NULL);
  char* sbmlflat = getSBMLString(NULL);

  ret = loadAntimonyFile(antfile.c_str());
  fail_unless(ret != -1);
  char* sbml2ant_ref = getAntimonyString(NULL);
  fail_unless(string(sbml2ant_ref) == string(sbml2ant));

  ret = loadSBMLFile(flatfile.c_str());
  fail_unless(ret != -1);
  char* sbmlflat_ref = getSBMLString(NULL);

  ret = loadSBMLString(sbmlflat);
  delete sbmlflat;
  sbmlflat = getSBMLString(NULL);

  fail_unless(string(sbmlflat) == string(sbmlflat_ref));

  delete sbml2ant;
  delete sbml2ant_ref;
  delete sbmlflat;
  delete sbmlflat_ref;
}

START_TEST (test_aggregate)
{
  compareFileFlattening("aggregate");
}
END_TEST

START_TEST (test_complexified)
{
  compareFileFlattening("complexified");
}
END_TEST

START_TEST (test_complexified2)
{
  compareFileFlattening("complexified2");
}
END_TEST

START_TEST (test_CompTest)
{
  compareFileFlattening("CompTest");
}
END_TEST

START_TEST (test_doubleext)
{
  compareFileFlattening("doubleext");
}
END_TEST

START_TEST (test_doubleext2)
{
  compareFileFlattening("doubleext2");
}
END_TEST

START_TEST (test_dropports)
{
  compareFileFlattening("dropports");
}
END_TEST

START_TEST (test_eg_import_external)
{
  compareFileFlattening("eg-import-external");
}
END_TEST

START_TEST (test_eg_ports)
{
  compareFileFlattening("eg-ports");
}
END_TEST

START_TEST (test_eg_replacement)
{
  compareFileFlattening("eg-replacement");
}
END_TEST

START_TEST (test_eg_simple_aggregate)
{
  compareFileFlattening("eg-simple-aggregate");
}
END_TEST

START_TEST (test_enzyme_identical)
{
  compareFileFlattening("enzyme_identical");
}
END_TEST

START_TEST (test_enzyme_model)
{
  compareFileFlattening("enzyme_model");
}
END_TEST

START_TEST (test_exchangetest)
{
  compareFileFlattening("exchangetest");
}
END_TEST

START_TEST (test_exchangetest2)
{
  compareFileFlattening("exchangetest2");
}
END_TEST

START_TEST (test_QTPop)
{
  compareFileFlattening("QTPop");
}
END_TEST

START_TEST (test_replace_implied_deletion)
{
  compareFileFlattening("replace_implied_deletion");
}
END_TEST

START_TEST (test_replace_implied_deletion2)
{
  compareFileFlattening("replace_implied_deletion2");
}
END_TEST

START_TEST (test_replace_rule)
{
  compareFileFlattening("replace_rule");
}
END_TEST

START_TEST (test_replace_rules_and_constraints)
{
  compareFileFlattening("replace_rules_and_constraints");
}
END_TEST

START_TEST (test_test1)
{
  compareFileFlattening("test1");
}
END_TEST

START_TEST (test_test2)
{
  compareFileFlattening("test2");
}
END_TEST

START_TEST (test_test3)
{
  compareFileFlattening("test3");
}
END_TEST

START_TEST (test_test4)
{
  compareFileFlattening("test4");
}
END_TEST

START_TEST (test_test5)
{
  compareFileFlattening("test5");
}
END_TEST

START_TEST (test_test6)
{
  compareFileFlattening("test6");
}
END_TEST

START_TEST (test_test7)
{
  compareFileFlattening("test7");
}
END_TEST

START_TEST (test_test8)
{
  compareFileFlattening("test8");
}
END_TEST

START_TEST (test_test9)
{
  compareFileFlattening("test9");
}
END_TEST

START_TEST (test_test10)
{
  compareFileFlattening("test10");
}
END_TEST

START_TEST (test_test11)
{
  compareFileFlattening("test11");
}
END_TEST

START_TEST (test_test12)
{
  compareFileFlattening("test12");
}
END_TEST

START_TEST (test_test13)
{
  compareFileFlattening("test13");
}
END_TEST

START_TEST (test_test14)
{
  compareFileFlattening("test14");
}
END_TEST

START_TEST (test_test15)
{
  compareFileFlattening("test15");
}
END_TEST

START_TEST (test_test16)
{
  compareFileFlattening("test16");
}
END_TEST

START_TEST (test_test17)
{
  compareFileFlattening("test17");
}
END_TEST

START_TEST (test_test18)
{
  compareFileFlattening("test18");
}
END_TEST

START_TEST (test_test19)
{
  compareFileFlattening("test19");
}
END_TEST

START_TEST (test_test20)
{
  compareFileFlattening("test20");
}
END_TEST

START_TEST (test_test21)
{
  compareFileFlattening("test21");
}
END_TEST

START_TEST (test_test22)
{
  compareFileFlatteningWithDifferences("test22");
}
END_TEST

START_TEST (test_test23)
{
  compareFileFlatteningWithDifferences("test23");
}
END_TEST

START_TEST (test_test24)
{
  compareFileFlatteningWithDifferences("test24");
}
END_TEST

START_TEST (test_test25)
{
  compareFileFlatteningWithDifferences("test25");
}
END_TEST

START_TEST (test_test26)
{
  compareFileFlattening("test26");
}
END_TEST

START_TEST (test_test27)
{
  compareFileFlatteningWithDifferences("test27");
}
END_TEST

START_TEST (test_test28)
{
  compareFileFlatteningWithDifferences("test28");
}
END_TEST

START_TEST (test_test29)
{
  compareFileFlattening("test29");
}
END_TEST

START_TEST (test_test30)
{
  compareFileFlattening("test30");
}
END_TEST

START_TEST (test_test31)
{
  compareFileFlattening("test31");
}
END_TEST

START_TEST (test_test32)
{
  compareFileFlattening("test32");
}
END_TEST

START_TEST (test_test33)
{
  compareFileFlattening("test33");
}
END_TEST

START_TEST (test_test34)
{
  compareFileFlattening("test34");
}
END_TEST

START_TEST (test_test35)
{
  compareFileFlattening("test35");
}
END_TEST

START_TEST (test_test36)
{
  compareFileFlattening("test36");
}
END_TEST

START_TEST (test_test37)
{
  compareFileFlattening("test37");
}
END_TEST

START_TEST (test_test38)
{
  compareFileFlattening("test38");
}
END_TEST

START_TEST (test_test39)
{
  compareFileFlattening("test39");
}
END_TEST

START_TEST (test_test40)
{
  compareFileFlattening("test40");
}
END_TEST

START_TEST (test_test41)
{
  compareFileFlattening("test41");
}
END_TEST

START_TEST (test_test42)
{
  compareFileFlattening("test42");
}
END_TEST

START_TEST (test_test43)
{
  compareFileFlattening("test43");
}
END_TEST

START_TEST (test_test44)
{
  compareFileFlatteningWithDifferences("test44");
}
END_TEST

START_TEST (test_test45)
{
  compareFileFlatteningWithDifferences("test45");
}
END_TEST

START_TEST (test_test46)
{
  compareFileFlatteningWithDifferences("test46");
}
END_TEST

START_TEST (test_test47)
{
  compareFileFlatteningWithDifferences("test47");
}
END_TEST

START_TEST (test_test48)
{
  compareFileFlatteningWithDifferences("test48");
}
END_TEST

START_TEST (test_test49)
{
  compareFileFlattening("test49");
}
END_TEST

START_TEST (test_test50)
{
  compareFileFlattening("test50");
}
END_TEST

START_TEST (test_test51)
{
  compareFileFlattening("test51");
}
END_TEST

START_TEST (test_test52)
{
  compareFileFlattening("test52");
}
END_TEST

START_TEST (test_test53)
{
  compareFileFlattening("test53");
}
END_TEST

START_TEST (test_test54)
{
  //This actually doesn't delete the deletion, as it should, but it should tell the user that in the Antimony version.
  compareFileFlatteningWithDifferences("test54");
}
END_TEST

START_TEST (test_test55)
{
  compareFileFlattening("test55");
}
END_TEST

START_TEST (test_test56)
{
  compareFileFlattening("test56");
}
END_TEST

START_TEST (test_test57)
{
  compareFileFlattening("test57");
}
END_TEST

START_TEST (test_test58)
{
  compareFileFlatteningWithDifferences("test58");
}
END_TEST

START_TEST (test_test59)
{
  compareFileFlatteningWithDifferences("test59");
}
END_TEST

START_TEST (test_test60)
{
  compareFileFlattening("test60");
}
END_TEST

START_TEST (test_test61)
{
  compareFileFlatteningWithDifferences("test61");
}
END_TEST


Suite *
create_suite_Flattening(void)
{
  Suite *suite = suite_create("Antimony Flattening");
  TCase *tcase = tcase_create("Antimony Flattening");

  tcase_add_test( tcase, test_aggregate);
  tcase_add_test( tcase, test_complexified);
  tcase_add_test( tcase, test_complexified2);
  tcase_add_test( tcase, test_CompTest);
  tcase_add_test( tcase, test_doubleext);
  tcase_add_test( tcase, test_doubleext2);
  tcase_add_test( tcase, test_dropports);
  tcase_add_test( tcase, test_eg_import_external);
  tcase_add_test( tcase, test_eg_ports);
  tcase_add_test( tcase, test_eg_replacement);
  tcase_add_test( tcase, test_eg_simple_aggregate);
  tcase_add_test( tcase, test_enzyme_identical);
  tcase_add_test( tcase, test_enzyme_model);
  tcase_add_test( tcase, test_exchangetest);
  //tcase_add_test( tcase, test_QTPop); //Fails because of libsbml :(
  tcase_add_test( tcase, test_replace_implied_deletion);
  tcase_add_test( tcase, test_replace_implied_deletion2);
  tcase_add_test( tcase, test_replace_rule);
  tcase_add_test( tcase, test_replace_rules_and_constraints);
  tcase_add_test( tcase, test_test1);
  tcase_add_test( tcase, test_test2);
  tcase_add_test( tcase, test_test3);
  tcase_add_test( tcase, test_test4);
  tcase_add_test( tcase, test_test5);
  tcase_add_test( tcase, test_test6);
  tcase_add_test( tcase, test_test7);
  tcase_add_test( tcase, test_test8);
  tcase_add_test( tcase, test_test9);
  tcase_add_test( tcase, test_test10);
  tcase_add_test( tcase, test_test11);
  tcase_add_test( tcase, test_test12);
  tcase_add_test( tcase, test_test13);
  tcase_add_test( tcase, test_test14);
  tcase_add_test( tcase, test_test15);
  tcase_add_test( tcase, test_test16);
  tcase_add_test( tcase, test_test17);
  tcase_add_test( tcase, test_test18);
  tcase_add_test( tcase, test_test19);
  tcase_add_test( tcase, test_test20);
  tcase_add_test( tcase, test_test21);
  tcase_add_test( tcase, test_test22);
  tcase_add_test( tcase, test_test23);
  tcase_add_test( tcase, test_test24);
  tcase_add_test( tcase, test_test25);
  tcase_add_test( tcase, test_test26);
  tcase_add_test( tcase, test_test27);
  tcase_add_test( tcase, test_test28);
  tcase_add_test( tcase, test_test29);
  tcase_add_test( tcase, test_test30);
  tcase_add_test( tcase, test_test31);
  tcase_add_test( tcase, test_test32);
  tcase_add_test( tcase, test_test33);
  tcase_add_test( tcase, test_test34);
  tcase_add_test( tcase, test_test35);
  tcase_add_test( tcase, test_test36);
  tcase_add_test( tcase, test_test37);
  tcase_add_test( tcase, test_test38);
  tcase_add_test( tcase, test_test39);
  tcase_add_test( tcase, test_test40);
  tcase_add_test( tcase, test_test41);
  tcase_add_test( tcase, test_test42);
  tcase_add_test( tcase, test_test43);
  tcase_add_test( tcase, test_test44);
  tcase_add_test( tcase, test_test45);
  tcase_add_test( tcase, test_test46);
  tcase_add_test( tcase, test_test47);
  tcase_add_test( tcase, test_test48);
  tcase_add_test( tcase, test_test49);
  tcase_add_test( tcase, test_test50);
  tcase_add_test( tcase, test_test51);
  tcase_add_test( tcase, test_test52);
  tcase_add_test( tcase, test_test53);
  tcase_add_test( tcase, test_test54);
  tcase_add_test( tcase, test_test55);
  tcase_add_test( tcase, test_test56);
  tcase_add_test( tcase, test_test57);
  tcase_add_test( tcase, test_test58);
  tcase_add_test( tcase, test_test59);
  tcase_add_test( tcase, test_test60);
  tcase_add_test( tcase, test_test61);
  
  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



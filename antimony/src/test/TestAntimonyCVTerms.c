/**
 * \file    TestAntimonyCVTerms.c
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
//{
//  clearPreviousLoads();
//  // load document
//  string dir(TestDataDirectory);
//  string filename = dir + base + ".txt";
//  long ret = loadAntimonyFile(filename.c_str());
//  fail_unless(ret != -1);
//  char* atosbml = getCompSBMLString(NULL);
//  fail_unless(atosbml != NULL);
//
//  string sbmlfile = dir + base + ".xml";
//  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
//  string matching = writeSBMLToStdString(doc);
//  fail_unless(string(atosbml) == matching);
//
//  //Now check the roundtripped version:
//  ret = loadSBMLString(matching.c_str());
//  char* roundtrip = getAntimonyString(NULL);
//  fail_unless(roundtrip != NULL);
//  string rtfilename = dir + base + "_rt.txt";
//  ret = loadAntimonyFile(rtfilename.c_str());
//  fail_unless(ret != -1);
//  matching = getAntimonyString(NULL);
//  fail_unless(string(roundtrip) == string(matching));
//
//  delete doc;
//  freeAll();
//}

extern void compareFileTranslationWithRenaming(const string& base);
//{
//  clearPreviousLoads();
//  // load document
//  string dir(TestDataDirectory);
//  string filename = dir + base + ".xml";
//  long ret = loadSBMLFile(filename.c_str());
//  fail_unless(ret != -1);
//  char* sbmltoa = getAntimonyString(NULL);
//  fail_unless(sbmltoa != NULL);
//  char* sbmlrt = getSBMLString(NULL);
//  fail_unless(sbmlrt != NULL);
//
//
//  filename = dir + base + ".txt";
//  ret = loadAntimonyFile(filename.c_str());
//  fail_unless(ret != -1);
//  char* matching = getAntimonyString(NULL);
//  fail_unless(string(sbmltoa) == string(matching));
//
//  //Now check the roundtripped version:
//  char* roundtrip = getSBMLString(NULL);
//  fail_unless(roundtrip != NULL);
//  fail_unless(string(roundtrip) == string(sbmlrt));
//
//  freeAll();
//}

extern void compareStringTranslation(const string& antimony, const string& sbml);
//{
//  clearPreviousLoads();
//  long ret = loadAntimonyString(antimony.c_str());
//  fail_unless(ret != -1);
//  char* atosbml = getCompSBMLString(NULL);
//  fail_unless(atosbml != NULL);
//
//  string dir(TestDataDirectory);
//  string sbmlfile = dir + sbml;
//  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
//  string matchingdoc = writeSBMLToStdString(doc);
//
//  fail_unless(string(atosbml) == matchingdoc);
//  delete doc;
//  freeAll();
//}

//if(qual == "is" || qual == "identity" || qual == "biological_entity_is")
//return BQB_IS;
//else if(qual == "hasPart" || qual == "part")
//return BQB_HAS_PART;
//else if(qual == "isPartOf" || qual == "parthood")
//return BQB_IS_PART_OF;
//else if(qual == "isVersionOf" || qual == "hypernym")
//return BQB_IS_VERSION_OF;
//else if(qual == "hasVersion" || qual == "version")
//return BQB_HAS_VERSION;
//else if(qual == "isHomologTo" || qual == "homolog")
//return BQB_IS_HOMOLOG_TO;
//else if(qual == "isDescribedBy" || qual == "description")
//return BQB_IS_DESCRIBED_BY;
//else if(qual == "isEncodedBy" || qual == "encoder")
//return BQB_IS_ENCODED_BY;
//else if(qual == "encodes" || qual == "encodement")
//return BQB_ENCODES;
//else if(qual == "occursIn" || qual == "container")
//return BQB_OCCURS_IN;
//else if(qual == "hasProperty" || qual == "property")
//return BQB_HAS_PROPERTY;
//else if(qual == "isPropertyOf" || qual == "propertyBearer")
//return BQB_IS_PROPERTY_OF;
//else if(qual == "hasTaxon" || qual == "taxon")
//return BQB_HAS_TAXON;

START_TEST (test_identity)
{
  compareFileTranslation("identity");
}
END_TEST

START_TEST (test_identity_txt)
{
  compareStringTranslation("a=3; a identity \"BQB_thing\"", "identity.xml");
}
END_TEST

START_TEST (test_identity_txt2)
{
  compareStringTranslation("a=3; a biological_entity_is \"BQB_thing\"", "identity.xml");
}
END_TEST


START_TEST (test_hasPart)
{
  compareFileTranslation("hasPart");
}
END_TEST

START_TEST (test_hasPart_txt)
{
  compareStringTranslation("a=3; a hasPart \"BQB_thing\"", "hasPart.xml");
}
END_TEST


START_TEST (test_hasPart_txt2)
{
  compareStringTranslation("a=3; a part \"BQB_thing\"", "hasPart.xml");
}
END_TEST

START_TEST (test_isPartOf)
{
  compareFileTranslation("isPartOf");
}
END_TEST

START_TEST (test_isPartOf_txt)
{
  compareStringTranslation("a=3; a isPartOf \"BQB_thing\"", "isPartOf.xml");
}
END_TEST


START_TEST (test_isPartOf_txt2)
{
  compareStringTranslation("a=3; a parthood \"BQB_thing\"", "isPartOf.xml");
}
END_TEST

START_TEST (test_isVersionOf)
{
  compareFileTranslation("isVersionOf");
}
END_TEST

START_TEST (test_isVersionOf_txt)
{
  compareStringTranslation("a=3; a isVersionOf \"BQB_thing\"", "isVersionOf.xml");
}
END_TEST


START_TEST (test_isVersionOf_txt2)
{
  compareStringTranslation("a=3; a hypernym \"BQB_thing\"", "isVersionOf.xml");
}
END_TEST

START_TEST (test_hasVersion)
{
  compareFileTranslation("hasVersion");
}
END_TEST

START_TEST (test_hasVersion_txt)
{
  compareStringTranslation("a=3; a hasVersion \"BQB_thing\"", "hasVersion.xml");
}
END_TEST


START_TEST (test_hasVersion_txt2)
{
  compareStringTranslation("a=3; a version \"BQB_thing\"", "hasVersion.xml");
}
END_TEST

START_TEST (test_isHomologTo)
{
  compareFileTranslation("isHomologTo");
}
END_TEST

START_TEST (test_isHomologTo_txt)
{
  compareStringTranslation("a=3; a isHomologTo \"BQB_thing\"", "isHomologTo.xml");
}
END_TEST


START_TEST (test_isHomologTo_txt2)
{
  compareStringTranslation("a=3; a homolog \"BQB_thing\"", "isHomologTo.xml");
}
END_TEST

START_TEST (test_isDescribedBy)
{
  compareFileTranslation("isDescribedBy");
}
END_TEST

START_TEST (test_isDescribedBy_txt)
{
  compareStringTranslation("a=3; a isDescribedBy \"BQB_thing\"", "isDescribedBy.xml");
}
END_TEST


START_TEST (test_isDescribedBy_txt2)
{
  compareStringTranslation("a=3; a description \"BQB_thing\"", "isDescribedBy.xml");
}
END_TEST

START_TEST (test_isEncodedBy)
{
  compareFileTranslation("isEncodedBy");
}
END_TEST

START_TEST (test_isEncodedBy_txt)
{
  compareStringTranslation("a=3; a isEncodedBy \"BQB_thing\"", "isEncodedBy.xml");
}
END_TEST


START_TEST (test_isEncodedBy_txt2)
{
  compareStringTranslation("a=3; a encoder \"BQB_thing\"", "isEncodedBy.xml");
}
END_TEST

START_TEST (test_encodes)
{
  compareFileTranslation("encodes");
}
END_TEST

START_TEST (test_encodes_txt)
{
  compareStringTranslation("a=3; a encodes \"BQB_thing\"", "encodes.xml");
}
END_TEST


START_TEST (test_encodes_txt2)
{
  compareStringTranslation("a=3; a encodement \"BQB_thing\"", "encodes.xml");
}
END_TEST

START_TEST (test_occursIn)
{
  compareFileTranslation("occursIn");
}
END_TEST

START_TEST (test_occursIn_txt)
{
  compareStringTranslation("a=3; a occursIn \"BQB_thing\"", "occursIn.xml");
}
END_TEST


START_TEST (test_occursIn_txt2)
{
  compareStringTranslation("a=3; a container \"BQB_thing\"", "occursIn.xml");
}
END_TEST

START_TEST (test_hasProperty)
{
  compareFileTranslation("hasProperty");
}
END_TEST

START_TEST (test_hasProperty_txt)
{
  compareStringTranslation("a=3; a hasProperty \"BQB_thing\"", "hasProperty.xml");
}
END_TEST


START_TEST (test_hasProperty_txt2)
{
  compareStringTranslation("a=3; a property \"BQB_thing\"", "hasProperty.xml");
}
END_TEST

START_TEST (test_isPropertyOf)
{
  compareFileTranslation("isPropertyOf");
}
END_TEST

START_TEST (test_isPropertyOf_txt)
{
  compareStringTranslation("a=3; a isPropertyOf \"BQB_thing\"", "isPropertyOf.xml");
}
END_TEST


START_TEST (test_isPropertyOf_txt2)
{
  compareStringTranslation("a=3; a propertyBearer \"BQB_thing\"", "isPropertyOf.xml");
}
END_TEST

START_TEST (test_hasTaxon)
{
  compareFileTranslation("hasTaxon");
}
END_TEST

START_TEST (test_hasTaxon_txt)
{
  compareStringTranslation("a=3; a hasTaxon \"BQB_thing\"", "hasTaxon.xml");
}
END_TEST


START_TEST (test_hasTaxon_txt2)
{
  compareStringTranslation("a=3; a taxon \"BQB_thing\"", "hasTaxon.xml");
}
END_TEST




Suite *
create_suite_CVTerms (void)
{
  Suite *suite = suite_create("Antimony CV Terms");
  TCase *tcase = tcase_create("Antimony CV Terms");

  tcase_add_test( tcase, test_identity);
  tcase_add_test( tcase, test_identity_txt);
  tcase_add_test( tcase, test_identity_txt2);
  tcase_add_test( tcase, test_hasPart);
  tcase_add_test( tcase, test_hasPart_txt);
  tcase_add_test( tcase, test_hasPart_txt2);
  tcase_add_test( tcase, test_isPartOf);
  tcase_add_test( tcase, test_isPartOf_txt);
  tcase_add_test( tcase, test_isPartOf_txt2);
  tcase_add_test( tcase, test_isVersionOf);
  tcase_add_test( tcase, test_isVersionOf_txt);
  tcase_add_test( tcase, test_isVersionOf_txt2);
  tcase_add_test( tcase, test_hasVersion);
  tcase_add_test( tcase, test_hasVersion_txt);
  tcase_add_test( tcase, test_hasVersion_txt2);
  tcase_add_test( tcase, test_isHomologTo);
  tcase_add_test( tcase, test_isHomologTo_txt);
  tcase_add_test( tcase, test_isHomologTo_txt2);
  tcase_add_test( tcase, test_isDescribedBy);
  tcase_add_test( tcase, test_isDescribedBy_txt);
  tcase_add_test( tcase, test_isDescribedBy_txt2);
  tcase_add_test( tcase, test_isEncodedBy);
  tcase_add_test( tcase, test_isEncodedBy_txt);
  tcase_add_test( tcase, test_isEncodedBy_txt2);
  tcase_add_test( tcase, test_encodes);
  tcase_add_test( tcase, test_encodes_txt);
  tcase_add_test( tcase, test_encodes_txt2);
  tcase_add_test( tcase, test_occursIn);
  tcase_add_test( tcase, test_occursIn_txt);
  tcase_add_test( tcase, test_occursIn_txt2);
  tcase_add_test( tcase, test_hasProperty);
  tcase_add_test( tcase, test_hasProperty_txt);
  tcase_add_test( tcase, test_hasProperty_txt2);
  tcase_add_test( tcase, test_isPropertyOf);
  tcase_add_test( tcase, test_isPropertyOf_txt);
  tcase_add_test( tcase, test_isPropertyOf_txt2);
  tcase_add_test( tcase, test_hasTaxon);
  tcase_add_test( tcase, test_hasTaxon_txt);
  tcase_add_test( tcase, test_hasTaxon_txt2);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



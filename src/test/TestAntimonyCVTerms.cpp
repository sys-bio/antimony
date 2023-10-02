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
extern void compareFileTranslationWithRenaming(const string& base);
extern void compareStringTranslation(const string& antimony, const string& sbml);

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

START_TEST(test_created_model)
{
    compareFileTranslation("created_model");
    compareStringTranslation("model foo(); a=3; end; foo created \"2019-07-29T10:53:09Z\"", "created_model.xml");
}
END_TEST

START_TEST(test_created_model_internal)
{
    compareStringTranslation("model foo(); a=3; model created \"2019-07-29T10:53:09Z\"; end", "created_model.xml");
}
END_TEST

START_TEST(test_created_element)
{
    compareFileTranslation("created_element");
    compareStringTranslation("a=3; a created \"2019-07-29T10:53:09Z\"", "created_element.xml");
}
END_TEST

START_TEST(test_notes_model_noxml)
{
    compareFileTranslation("notes_model_noxml");
    compareStringTranslation("model foo(); a=3; end; foo notes \"Just text, no XML\"", "notes_model_noxml.xml");
}
END_TEST

START_TEST(test_notes_model_noxml_internal)
{
    compareStringTranslation("model foo(); a=3; model notes \"Just text, no XML\"; end", "notes_model_noxml.xml");
}
END_TEST

START_TEST(test_notes_element_noxml)
{
    compareFileTranslation("notes_element_noxml");
    compareStringTranslation("a notes \"Just text, no XML\"", "notes_element_noxml.xml");
}
END_TEST

START_TEST(test_notes_model_xml)
{
    compareFileTranslation("notes_model_xml");
}
END_TEST

START_TEST(test_notes_model_xml_internal)
{
    compareFileTranslation("notes_model_xml_internal");
}
END_TEST

START_TEST(test_notes_element_xml)
{
    compareFileTranslation("notes_element_xml");
}
END_TEST

START_TEST(test_modified_model)
{
    compareFileTranslation("modified_model");
    compareStringTranslation("model foo(); a=3; end; foo modified \"2019-07-29T10:53:09Z\"", "modified_model.xml");
}
END_TEST

START_TEST(test_modified_model_internal)
{
    compareStringTranslation("model foo(); a=3; model modified \"2019-07-29T10:53:09Z\"; end", "modified_model.xml");
}
END_TEST

START_TEST(test_modified_element)
{
    compareFileTranslation("modified_element");
    compareStringTranslation("a=3; a modified \"2019-07-29T10:53:09Z\"", "modified_element.xml");
}
END_TEST

START_TEST(test_creator_one_model)
{
    compareFileTranslation("creator_one_model");
    compareStringTranslation("model foo(); a=3; end; foo creator1.givenName \"Lucian\"; foo creator1.familyName \"Smith\"; foo creator1.organization \"UW\"; foo creator1.email \"lpsmith@uw.edu\"", "creator_one_model.xml");
}
END_TEST

START_TEST(test_creator_one_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator1.givenName \"Lucian\"; model creator1.familyName \"Smith\"; model creator1.organization \"UW\"; model creator1.email \"lpsmith@uw.edu\"; end", "creator_one_model.xml");
}
END_TEST

START_TEST(test_creator_one_element)
{
    compareFileTranslation("creator_one_element");
    compareStringTranslation("a=3; a creator1.givenName \"Lucian\"; a creator1.familyName \"Smith\"; a creator1.organization \"UW\"; a creator1.email \"lpsmith@uw.edu\"", "creator_one_element.xml");
}
END_TEST

START_TEST(test_creator_blank_model)
{
    compareFileTranslation("creator_blank_model");
    compareStringTranslation("model foo(); a=3; end; foo creator.givenName \"Lucian\"; foo creator.familyName \"Smith\"; foo creator.organization \"UW\"; foo creator.email \"lpsmith@uw.edu\"", "creator_blank_model.xml");
}
END_TEST

START_TEST(test_creator_blank_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator.givenName \"Lucian\"; model creator.familyName \"Smith\"; model creator.organization \"UW\"; model creator.email \"lpsmith@uw.edu\"; end", "creator_blank_model.xml");
}
END_TEST

START_TEST(test_creator_two_model)
{
    compareFileTranslation("creator_two_model");
    compareStringTranslation("model foo(); a=3; end; foo creator.givenName \"Lucian\"; foo creator.familyName \"Smith\"; foo creator.organization \"UW\"; foo creator.email \"lpsmith@uw.edu\";foo creator2.name \"George Holtzour\"; foo creator2.organization \"Family lore\"; foo creator2.email \"george@theholtz.net\"", "creator_two_model.xml");
}
END_TEST

START_TEST(test_creator_two_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator.givenName \"Lucian\"; model creator.familyName \"Smith\"; model creator.organization \"UW\"; model creator.email \"lpsmith@uw.edu\";model creator2.name \"George Holtzour\"; model creator2.organization \"Family lore\"; model creator2.email \"george@theholtz.net\"; end", "creator_two_model.xml");
}
END_TEST




Suite *
create_suite_CVTerms (void)
{
  Suite *suite = suite_create("Antimony CV Terms");
  TCase *tcase = tcase_create("Antimony CV Terms");

  tcase_add_test(tcase, test_created_model);
  tcase_add_test(tcase, test_created_model_internal);
  tcase_add_test(tcase, test_created_element);
  tcase_add_test(tcase, test_notes_model_noxml);
  tcase_add_test(tcase, test_notes_model_noxml_internal);
  tcase_add_test(tcase, test_notes_element_noxml);
  tcase_add_test(tcase, test_notes_model_xml);
  tcase_add_test(tcase, test_notes_model_xml_internal);
  tcase_add_test(tcase, test_notes_element_xml);
  tcase_add_test(tcase, test_modified_model);
  tcase_add_test(tcase, test_modified_model_internal);
  tcase_add_test(tcase, test_modified_element);
  tcase_add_test(tcase, test_creator_one_model);
  tcase_add_test(tcase, test_creator_one_model_internal);
  tcase_add_test(tcase, test_creator_one_element);

  tcase_add_test(tcase, test_identity);
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



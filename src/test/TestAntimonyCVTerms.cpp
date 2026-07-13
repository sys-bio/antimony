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
#include "gtest/gtest.h"

using namespace std;

extern string TestDataDirectory;

#include "TestAntimonyUtil.h"

TEST(AntimonyCVTerms, test_identity)
{
  compareFileTranslation("identity");
}

TEST(AntimonyCVTerms, test_identity_txt)
{
  compareStringTranslation("a=3; a identity \"BQB_thing\"", "identity.xml");
}

TEST(AntimonyCVTerms, test_identity_txt2)
{
  compareStringTranslation("a=3; a biological_entity_is \"BQB_thing\"", "identity.xml");
}

TEST(AntimonyCVTerms, test_hasPart)
{
  compareFileTranslation("hasPart");
}

TEST(AntimonyCVTerms, test_hasPart_txt)
{
  compareStringTranslation("a=3; a hasPart \"BQB_thing\"", "hasPart.xml");
}

TEST(AntimonyCVTerms, test_hasPart_txt2)
{
  compareStringTranslation("a=3; a part \"BQB_thing\"", "hasPart.xml");
}

TEST(AntimonyCVTerms, test_isPartOf)
{
  compareFileTranslation("isPartOf");
}

TEST(AntimonyCVTerms, test_isPartOf_txt)
{
  compareStringTranslation("a=3; a isPartOf \"BQB_thing\"", "isPartOf.xml");
}

TEST(AntimonyCVTerms, test_isPartOf_txt2)
{
  compareStringTranslation("a=3; a parthood \"BQB_thing\"", "isPartOf.xml");
}

TEST(AntimonyCVTerms, test_isVersionOf)
{
  compareFileTranslation("isVersionOf");
}

TEST(AntimonyCVTerms, test_isVersionOf_txt)
{
  compareStringTranslation("a=3; a isVersionOf \"BQB_thing\"", "isVersionOf.xml");
}

TEST(AntimonyCVTerms, test_isVersionOf_txt2)
{
  compareStringTranslation("a=3; a hypernym \"BQB_thing\"", "isVersionOf.xml");
}

TEST(AntimonyCVTerms, test_hasVersion)
{
  compareFileTranslation("hasVersion");
}

TEST(AntimonyCVTerms, test_hasVersion_txt)
{
  compareStringTranslation("a=3; a hasVersion \"BQB_thing\"", "hasVersion.xml");
}

TEST(AntimonyCVTerms, test_hasVersion_txt2)
{
  compareStringTranslation("a=3; a version \"BQB_thing\"", "hasVersion.xml");
}

TEST(AntimonyCVTerms, test_isHomologTo)
{
  compareFileTranslation("isHomologTo");
}

TEST(AntimonyCVTerms, test_isHomologTo_txt)
{
  compareStringTranslation("a=3; a isHomologTo \"BQB_thing\"", "isHomologTo.xml");
}

TEST(AntimonyCVTerms, test_isHomologTo_txt2)
{
  compareStringTranslation("a=3; a homolog \"BQB_thing\"", "isHomologTo.xml");
}

TEST(AntimonyCVTerms, test_isDescribedBy)
{
  compareFileTranslation("isDescribedBy");
}

TEST(AntimonyCVTerms, test_isDescribedBy_txt)
{
  compareStringTranslation("a=3; a isDescribedBy \"BQB_thing\"", "isDescribedBy.xml");
}

TEST(AntimonyCVTerms, test_isDescribedBy_txt2)
{
  compareStringTranslation("a=3; a description \"BQB_thing\"", "isDescribedBy.xml");
}

TEST(AntimonyCVTerms, test_isEncodedBy)
{
  compareFileTranslation("isEncodedBy");
}

TEST(AntimonyCVTerms, test_isEncodedBy_txt)
{
  compareStringTranslation("a=3; a isEncodedBy \"BQB_thing\"", "isEncodedBy.xml");
}

TEST(AntimonyCVTerms, test_isEncodedBy_txt2)
{
  compareStringTranslation("a=3; a encoder \"BQB_thing\"", "isEncodedBy.xml");
}

TEST(AntimonyCVTerms, test_encodes)
{
  compareFileTranslation("encodes");
}

TEST(AntimonyCVTerms, test_encodes_txt)
{
  compareStringTranslation("a=3; a encodes \"BQB_thing\"", "encodes.xml");
}

TEST(AntimonyCVTerms, test_encodes_txt2)
{
  compareStringTranslation("a=3; a encodement \"BQB_thing\"", "encodes.xml");
}

TEST(AntimonyCVTerms, test_occursIn)
{
  compareFileTranslation("occursIn");
}

TEST(AntimonyCVTerms, test_occursIn_txt)
{
  compareStringTranslation("a=3; a occursIn \"BQB_thing\"", "occursIn.xml");
}

TEST(AntimonyCVTerms, test_occursIn_txt2)
{
  compareStringTranslation("a=3; a container \"BQB_thing\"", "occursIn.xml");
}

TEST(AntimonyCVTerms, test_hasProperty)
{
  compareFileTranslation("hasProperty");
}

TEST(AntimonyCVTerms, test_hasProperty_txt)
{
  compareStringTranslation("a=3; a hasProperty \"BQB_thing\"", "hasProperty.xml");
}

TEST(AntimonyCVTerms, test_hasProperty_txt2)
{
  compareStringTranslation("a=3; a property \"BQB_thing\"", "hasProperty.xml");
}

TEST(AntimonyCVTerms, test_isPropertyOf)
{
  compareFileTranslation("isPropertyOf");
}

TEST(AntimonyCVTerms, test_isPropertyOf_txt)
{
  compareStringTranslation("a=3; a isPropertyOf \"BQB_thing\"", "isPropertyOf.xml");
}

TEST(AntimonyCVTerms, test_isPropertyOf_txt2)
{
  compareStringTranslation("a=3; a propertyBearer \"BQB_thing\"", "isPropertyOf.xml");
}

TEST(AntimonyCVTerms, test_hasTaxon)
{
  compareFileTranslation("hasTaxon");
}

TEST(AntimonyCVTerms, test_hasTaxon_txt)
{
  compareStringTranslation("a=3; a hasTaxon \"BQB_thing\"", "hasTaxon.xml");
}

TEST(AntimonyCVTerms, test_hasTaxon_txt2)
{
  compareStringTranslation("a=3; a taxon \"BQB_thing\"", "hasTaxon.xml");
}

TEST(AntimonyCVTerms, test_created_model)
{
    compareFileTranslation("created_model");
    compareStringTranslation("model foo(); a=3; end; foo created \"2019-07-29T10:53:09Z\"", "created_model.xml");
}

TEST(AntimonyCVTerms, test_created_model_parts)
{
    compareFileTranslation("created_model_parts");
    compareStringTranslation("model foo(); a=3; end; foo created.year 2019; foo created.month 07; foo created.day 29; foo created.hour 10; foo created.minute 53; foo created.second 09", "created_model_parts.xml");
}

TEST(AntimonyCVTerms, test_created_model_internal)
{
    compareStringTranslation("model foo(); a=3; model created \"2019-07-29T10:53:09Z\"; end", "created_model.xml");
}

TEST(AntimonyCVTerms, test_created_model_internal_parts)
{
    compareStringTranslation("model foo(); a=3; model created.year 2019; model created.month 07; model created.day 29; model created.hour 10; model created.minute 53; model created.second 09; end", "created_model.xml");
}

TEST(AntimonyCVTerms, test_created_element)
{
    compareFileTranslation("created_element");
    compareStringTranslation("a=3; a created \"2019-07-29T10:53:09Z\"", "created_element.xml");
}

TEST(AntimonyCVTerms, test_notes_model_noxml)
{
    compareFileTranslation("notes_model_noxml");
    compareStringTranslation("model foo(); a=3; end; foo notes \"Just text, no XML\"", "notes_model_noxml.xml");
}

TEST(AntimonyCVTerms, test_notes_model_noxml_internal)
{
    compareStringTranslation("model foo(); a=3; model notes \"Just text, no XML\"; end", "notes_model_noxml.xml");
}

TEST(AntimonyCVTerms, test_notes_element_noxml)
{
    compareFileTranslation("notes_element_noxml");
    compareStringTranslation("a notes \"Just text, no XML\"", "notes_element_noxml.xml");
}

TEST(AntimonyCVTerms, test_notes_model_xml)
{
    compareFileTranslation("notes_model_xml");
}

TEST(AntimonyCVTerms, test_notes_model_xml_internal)
{
    compareFileTranslation("notes_model_xml_internal");
}

TEST(AntimonyCVTerms, test_notes_element_xml)
{
    compareFileTranslation("notes_element_xml");
}

TEST(AntimonyCVTerms, test_notes_model_markdown)
{
    compareFileTranslation("notes_model_markdown");
    compareStringTranslation("model foo(); a=3; end; foo notes ```# Header\n\nHere is a list:\n\n- First\n- Second```", "notes_model_markdown.xml");
}

TEST(AntimonyCVTerms, test_notes_model_markdown_link)
{
    compareFileTranslation("notes_model_markdown_link");
    compareStringTranslation("model foo(); a=3; end; foo notes ```Please refer to [CC0  Public Domain Dedication](http://creativecommons.org/publicdomain/zero/1.0/ \"Access to: CC0 1.0 Universal (CC0 1.0), Public Domain Dedication\") for more information.```", "notes_model_markdown_link.xml");
}

TEST(AntimonyCVTerms, test_modified_model)
{
    compareFileTranslation("modified_model");
    compareStringTranslation("model foo(); a=3; end; foo modified \"2019-07-29T10:53:09Z\"", "modified_model.xml");
}

TEST(AntimonyCVTerms, test_modified_model_parts)
{
    compareFileTranslation("modified_model_parts");
    compareStringTranslation("model foo(); a=3; end; foo modified.year 2019; foo modified.month 07; foo modified.day 29; foo modified.hour 10; foo modified.minute 53; foo modified.second 09", "modified_model_parts.xml");
}

TEST(AntimonyCVTerms, test_modified_model_internal)
{
    compareStringTranslation("model foo(); a=3; model modified \"2019-07-29T10:53:09Z\"; end", "modified_model.xml");
}

TEST(AntimonyCVTerms, test_modified_model_internal_parts)
{
    compareStringTranslation("model foo(); a=3; model modified.year 2019; model modified.month 07; model modified.day 29; model modified.hour 10; model modified.minute 53; model modified.second 09; end", "modified_model.xml");
}

TEST(AntimonyCVTerms, test_modified_element)
{
    compareFileTranslation("modified_element");
    compareStringTranslation("a=3; a modified \"2019-07-29T10:53:09Z\"", "modified_element.xml");
}

TEST(AntimonyCVTerms, test_creator_one_model)
{
    compareFileTranslation("creator_one_model");
    compareStringTranslation("model foo(); a=3; end; foo creator1.givenName \"Lucian\"; foo creator1.familyName \"Smith\"; foo creator1.organization \"UW\"; foo creator1.email \"lpsmith@uw.edu\"", "creator_one_model.xml");
}

TEST(AntimonyCVTerms, test_creator_one_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator1.givenName \"Lucian\"; model creator1.familyName \"Smith\"; model creator1.organization \"UW\"; model creator1.email \"lpsmith@uw.edu\"; end", "creator_one_model.xml");
}

TEST(AntimonyCVTerms, test_creator_one_element)
{
    compareFileTranslation("creator_one_element");
    compareStringTranslation("a=3; a creator1.givenName \"Lucian\"; a creator1.familyName \"Smith\"; a creator1.organization \"UW\"; a creator1.email \"lpsmith@uw.edu\"", "creator_one_element.xml");
}

TEST(AntimonyCVTerms, test_creator_blank_model)
{
    compareFileTranslation("creator_blank_model");
    compareStringTranslation("model foo(); a=3; end; foo creator.givenName \"Lucian\"; foo creator.familyName \"Smith\"; foo creator.organization \"UW\"; foo creator.email \"lpsmith@uw.edu\"", "creator_blank_model.xml");
}

TEST(AntimonyCVTerms, test_creator_blank_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator.givenName \"Lucian\"; model creator.familyName \"Smith\"; model creator.organization \"UW\"; model creator.email \"lpsmith@uw.edu\"; end", "creator_blank_model.xml");
}

TEST(AntimonyCVTerms, test_creator_two_model)
{
    compareFileTranslation("creator_two_model");
    compareStringTranslation("model foo(); a=3; end; foo creator.givenName \"Lucian\"; foo creator.familyName \"Smith\"; foo creator.organization \"UW\"; foo creator.email \"lpsmith@uw.edu\";foo creator2.name \"George Holtzour\"; foo creator2.organization \"Family lore\"; foo creator2.email \"george@theholtz.net\"", "creator_two_model.xml");
}

TEST(AntimonyCVTerms, test_creator_two_model_internal)
{
    compareStringTranslation("model foo(); a=3; model creator.givenName \"Lucian\"; model creator.familyName \"Smith\"; model creator.organization \"UW\"; model creator.email \"lpsmith@uw.edu\";model creator2.name \"George Holtzour\"; model creator2.organization \"Family lore\"; model creator2.email \"george@theholtz.net\"; end", "creator_two_model.xml");
}

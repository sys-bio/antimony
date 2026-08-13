/**
 * \file    TestAntimonyHierarchy.c
 * \brief   Test Antimony's hierarchy constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "registry.h"
#include <sbml/SBMLTypes.h>
#include <sbml/conversion/SBMLConverterRegistry.h>
#include <sbml/packages/comp/common/CompExtensionTypes.h>

#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "gtest/gtest.h"
#include "stringx.h" // NormalizeLineEndings, SizeTToString

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

// True when the character at 'pos' is part of an SId, so that replacing an id
// does not also replace it where it appears inside a longer name.
static bool IsIdChar(char c)
{
  return isalnum(static_cast<unsigned char>(c)) || c == '_';
}

// Replace every id in an SBML string with its position in the document.
// libSBML's flattener and Antimony's flattener can choose different names for
// the same element -- libSBML bumps a submodel's id prefix when Antimony has
// already used that prefix for an element promoted out of that submodel -- so
// two documents can be structurally identical and still differ in names.
static string CanonicalizeIds(const string& sbmlstring)
{
  SBMLDocument* doc = readSBMLFromString(sbmlstring.c_str());
  if (doc == NULL || doc->getModel() == NULL) {
    delete doc;
    return sbmlstring;
  }
  vector<string> ids;
  ids.push_back(doc->getModel()->getId());
  List* elements = doc->getModel()->getAllElements();
  for (unsigned int e = 0; e < elements->getSize(); e++) {
    SBase* element = static_cast<SBase*>(elements->get(e));
    if (element->isSetId() && !element->getId().empty()) {
      ids.push_back(element->getId());
    }
  }
  delete elements;
  delete doc;

  // Longest first, so that no id is replaced inside a longer one.
  vector<size_t> order;
  for (size_t i = 0; i < ids.size(); i++) {
    order.push_back(i);
  }
  for (size_t a = 0; a < order.size(); a++) {
    for (size_t b = a + 1; b < order.size(); b++) {
      if (ids[order[b]].size() > ids[order[a]].size()) {
        size_t tmp = order[a];
        order[a] = order[b];
        order[b] = tmp;
      }
    }
  }

  string ret = sbmlstring;
  for (size_t o = 0; o < order.size(); o++) {
    const string& id = ids[order[o]];
    if (id.empty()) continue;
    // '%' cannot appear in an SId, so a token built from it is never itself
    // matched by a later, shorter id.
    string token = "%" + SizeTToString(order[o]) + "%";
    size_t pos = ret.find(id);
    while (pos != string::npos) {
      size_t after = pos + id.size();
      bool leftok = (pos == 0) || !IsIdChar(ret[pos - 1]);
      bool rightok = (after >= ret.size()) || !IsIdChar(ret[after]);
      if (leftok && rightok) {
        ret.replace(pos, id.size(), token);
        pos = ret.find(id, pos + token.size());
      }
      else {
        pos = ret.find(id, pos + 1);
      }
    }
  }
  return ret;
}

static string ReadFileText(const string& filename)
{
  ifstream infile(filename.c_str());
  stringstream contents;
  contents << infile.rdbuf();
  return NormalizeLineEndings(contents.str());
}

// When 'lax', two comparisons are allowed to succeed in a weaker form.  See
// compareFileHierarchyLax for when that is appropriate.
void compareFileHierarchyImpl(const string& base, bool lax)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
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

  //Now compare libAntimony's flattening with libSBML's flattening
  atosbml = getSBMLString(NULL);
  EXPECT_TRUE(atosbml != NULL);

  ConversionProperties props;
  props.addOption("flatten comp");
  props.addOption("performValidation", true);
  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(props);
  converter->setDocument(doc);
  int result = converter->convert();
  // fail if conversion was not valid
  EXPECT_TRUE(result == LIBSBML_OPERATION_SUCCESS);
  elideMetaIds(doc);
  string sbmlFlat = writeSBMLToStdString(doc);
  string atosbml_nometa = elideMetaIdsFromSBMLstring(atosbml);
  if (lax) {
    //Structure has to match; the names the two flatteners chose need not.
    EXPECT_STREQ(CanonicalizeIds(atosbml_nometa).c_str(), CanonicalizeIds(sbmlFlat).c_str());
  }
  else {
    EXPECT_STREQ(atosbml_nometa.c_str(), sbmlFlat.c_str());
  }

  ret = loadSBMLString(matching.c_str());
  EXPECT_TRUE(ret != -1);
  char* roundtrip = getAntimonyString(NULL);
  EXPECT_TRUE(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  if (lax) {
    //Compare against the reference file itself rather than against a reload of
    //it:  a reload cannot reproduce translation warnings, and re-emits
    //declarations in Antimony's parse order.
    EXPECT_STREQ(ReadFileText(rtfilename).c_str(), NormalizeLineEndings(string(roundtrip)).c_str());
  }
  else {
    ret = loadAntimonyFile(rtfilename.c_str());
    EXPECT_TRUE(ret != -1);
    matching = getAntimonyString(NULL);
    EXPECT_STREQ(roundtrip, matching.c_str());
  }

  delete doc;
  delete converter;
  freeAll();
}

void compareFileHierarchy(const string& base)
{
  compareFileHierarchyImpl(base, false);
}

// For models where two things Antimony cannot control get in the way of exact
// string comparison, but the content is still right:
//
//  * libSBML's flattener bumps a submodel's id prefix when Antimony has already
//    used that prefix for an element promoted out of that submodel, so the two
//    flattenings agree on structure but not on every name.
//  * The Antimony round-trip is compared against the reference file directly,
//    because reloading that file cannot reproduce translation warnings, and
//    because a named stoichiometry reaches Antimony from a <speciesReference>
//    but reaches the parser from the reaction line, so the two orders differ.
void compareFileHierarchyLax(const string& base)
{
  compareFileHierarchyImpl(base, true);
}

TEST(AntimonyHierarchy, test_deleted_rate_rule)
{
  compareFileHierarchy("deleted_rate_rule");
}

TEST(AntimonyHierarchy, test_implied_reaction)
{
  compareFileHierarchyLax("implied_reaction");
}

TEST(AntimonyHierarchy, test_implied_reaction_override)
{
  compareFileHierarchyLax("implied_reaction_override");
}

TEST(AntimonyHierarchy, test_implied_nested_reaction)
{
  compareFileHierarchy("implied_nested_reaction");
}

TEST(AntimonyHierarchy, test_implied_event)
{
  compareFileHierarchy("implied_event");
}

TEST(AntimonyHierarchy, test_implied_event_override)
{
  compareFileHierarchy("implied_event_override");
}

TEST(AntimonyHierarchy, test_hierarchy)
{
  compareFileHierarchy("hierarchy");
}

TEST(AntimonyHierarchy, test_defaultSubCompartment)
{
  compareFileHierarchy("defaultSubCompartment");
}

TEST(AntimonyHierarchy, test_defaultSubSubCompartment)
{
  compareFileHierarchy("defaultSubSubCompartment");
}

TEST(AntimonyHierarchy, test_defaultOrNotCompartment)
{
  compareFileHierarchy("defaultOrNotCompartment");
}

TEST(AntimonyHierarchy, test_deletion)
{
  compareFileHierarchy("deletion");
}

TEST(AntimonyHierarchy, test_deletePriority)
{
  compareFileHierarchy("deletePriority");
}

TEST(AntimonyHierarchy, test_deletePriority2)
{
  compareFileHierarchy("deletePriority2");
}

TEST(AntimonyHierarchy, test_deleteDelay)
{
  compareFileHierarchy("deleteDelay");
}

TEST(AntimonyHierarchy, test_deleteDelay2)
{
  compareFileHierarchy("deleteDelay2");
}

TEST(AntimonyHierarchy, test_deleteEventAssignment)
{
  compareFileHierarchy("deleteEventAssignment");
}

TEST(AntimonyHierarchy, test_deleteEventAssignment2)
{
  compareFileHierarchy("deleteEventAssignment2");
}

TEST(AntimonyHierarchy, test_deleteEventAssignment3)
{
  compareFileHierarchy("deleteEventAssignment3");
}

TEST(AntimonyHierarchy, test_deleteEventAssignment4)
{
  compareFileHierarchy("deleteEventAssignment4");
}

TEST(AntimonyHierarchy, test_deleteEventAssignment5)
{
  compareFileHierarchy("deleteEventAssignment5");
}

TEST(AntimonyHierarchy, test_deleteTrigger)
{
  compareFileHierarchy("deleteTrigger");
}

TEST(AntimonyHierarchy, test_deleteReaction)
{
  compareFileHierarchy("deleteReaction");
}

TEST(AntimonyHierarchy, test_deleteReactant)
{
  compareFileHierarchy("deleteReactant");
}

TEST(AntimonyHierarchy, test_deleteProduct)
{
  compareFileHierarchy("deleteProduct");
}

TEST(AntimonyHierarchy, test_deleteModifier)
{
  compareFileHierarchy("deleteModifier");
}

TEST(AntimonyHierarchy, test_deleteKineticLaw)
{
  compareFileHierarchy("deleteKineticLaw");
}

TEST(AntimonyHierarchy, test_deleteModifierKineticLaw)
{
  compareFileHierarchy("deleteModifierKineticLaw");
}

TEST(AntimonyHierarchy, test_deleteSpecies)
{
  compareFileHierarchy("deleteSpecies");
}

TEST(AntimonyHierarchy, test_deleteSpeciesInDefaultCompartment)
{
  compareFileHierarchy("deleteSpeciesInDefaultCompartment");
}

TEST(AntimonyHierarchy, test_deleteSpeciesInDefaultCompartment2)
{
  compareFileHierarchy("deleteSpeciesInDefaultCompartment2");
}

TEST(AntimonyHierarchy, test_deleteSpeciesPort)
{
  compareFileHierarchy("deleteSpeciesPort");
}

TEST(AntimonyHierarchy, test_deleteSpeciesPortDefaultCompartment)
{
  compareFileHierarchy("deleteSpeciesPortDefaultCompartment");
}

TEST(AntimonyHierarchy, test_deleteRateRuleDirect)
{
  compareFileHierarchy("deleteRateRuleDirect");
}

TEST(AntimonyHierarchy, test_deleteRateRuleIndirect)
{
  compareFileHierarchy("deleteRateRuleIndirect");
}

TEST(AntimonyHierarchy, test_deleteRateRuleOfAnother)
{
  compareFileHierarchy("deleteRateRuleOfAnother");
}

TEST(AntimonyHierarchy, test_deleteAssignmentRuleDirect)
{
  compareFileHierarchy("deleteAssignmentRuleDirect");
}

TEST(AntimonyHierarchy, test_deleteAssignmentRuleIndirect)
{
  compareFileHierarchy("deleteAssignmentRuleIndirect");
}

TEST(AntimonyHierarchy, test_deleteAssignmentRuleOfAnother)
{
  compareFileHierarchy("deleteAssignmentRuleOfAnother");
}

TEST(AntimonyHierarchy, test_deleteInitialAssignmentDirect)
{
  compareFileHierarchy("deleteInitialAssignmentDirect");
}

TEST(AntimonyHierarchy, test_deleteInitialAssignmentIndirect)
{
  compareFileHierarchy("deleteInitialAssignmentIndirect");
}

TEST(AntimonyHierarchy, test_deleteInitialAssignmentOfAnother)
{
  compareFileHierarchy("deleteInitialAssignmentOfAnother");
}

TEST(AntimonyHierarchy, test_replaceAssignmentRule)
{
  compareFileHierarchy("replaceAssignmentRule");
}

TEST(AntimonyHierarchy, test_replaceRateRule)
{
  compareFileHierarchy("replaceRateRule");
}

TEST(AntimonyHierarchy, test_replaceInitialAssignment)
{
  compareFileHierarchy("replaceInitialAssignment");
}

TEST(AntimonyHierarchy, test_replaceCompartment)
{
  compareFileHierarchy("replaceCompartment");
}

TEST(AntimonyHierarchy, test_replaceSpecies)
{
  compareFileHierarchy("replaceSpecies");
}

TEST(AntimonyHierarchy, test_replaceSpeciesDefaultCompartment)
{
  compareFileHierarchy("replaceSpeciesDefaultCompartment");
}

TEST(AntimonyHierarchy, test_replaceParameter)
{
  compareFileHierarchy("replaceParameter");
}

TEST(AntimonyHierarchy, test_replaceReactionOnly)
{
  compareFileHierarchy("replaceReactionOnly");
}

TEST(AntimonyHierarchy, test_replaceReactionOnly2)
{
  compareFileHierarchy("replaceReactionOnly2");
}

TEST(AntimonyHierarchy, test_replaceReactionWithCompartments1)
{
  compareFileHierarchy("replaceReactionWithCompartments1");
}

TEST(AntimonyHierarchy, test_replaceReactionWithCompartments2)
{
  compareFileHierarchy("replaceReactionWithCompartments2");
}

TEST(AntimonyHierarchy, test_replaceReactionWithKineticLaw)
{
  compareFileHierarchy("replaceReactionWithKineticLaw");
}

TEST(AntimonyHierarchy, test_replaceReactionWithKineticLawRxnRef)
{
  compareFileHierarchy("replaceReactionWithKineticLawRxnRef");
}

TEST(AntimonyHierarchy, test_replaceInteraction)
{
  compareFileHierarchy("replaceInteraction");
}

TEST(AntimonyHierarchy, test_submodelInteraction)
{
  compareFileHierarchy("submodelInteraction");
}

TEST(AntimonyHierarchy, test_port)
{
  compareFileHierarchy("port");
}

TEST(AntimonyHierarchy, test_subport)
{
  compareFileHierarchy("subport");
}

TEST(AntimonyHierarchy, test_subport2)
{
  compareFileHierarchy("subport2");
}

TEST(AntimonyHierarchy, test_subsubport)
{
  compareFileHierarchy("subsubport");
}

TEST(AntimonyHierarchy, test_conversionFactor)
{
  compareFileHierarchy("paramconv_hierarchy");
}

TEST(AntimonyHierarchy, test_timeconv_raterule)
{
  compareFileHierarchy("timeconv_raterule");
}

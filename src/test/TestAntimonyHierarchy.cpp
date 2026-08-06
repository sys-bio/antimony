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

#include <string>
#include "gtest/gtest.h"

using namespace std;
using namespace libsbml;

extern string TestDataDirectory;

void compareFileHierarchy(const string& base)
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
  EXPECT_STREQ(atosbml_nometa.c_str(), sbmlFlat.c_str());

  ret = loadSBMLString(matching.c_str());
  EXPECT_TRUE(ret != -1);
  char* roundtrip = getAntimonyString(NULL);
  EXPECT_TRUE(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  EXPECT_TRUE(ret != -1);
  matching = getAntimonyString(NULL);
  EXPECT_STREQ(roundtrip, matching.c_str());

  delete doc;
  delete converter;
  freeAll();
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

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
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

void compareFileHierarchy(const string& base)
{
  clearPreviousLoads();
  g_registry.SetCC("__");
  // load document
  string dir(TestDataDirectory);
  string filename = dir + base + ".txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string sbmlfile = dir + base + ".xml";
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  char* matching = writeSBMLToString(doc);
  fail_unless(string(atosbml) == string(matching));
  delete atosbml;

  //Now compare libAntimony's flattening with libSBML's flattening
  atosbml = getSBMLString(NULL);
  fail_unless(atosbml != NULL);

  ConversionProperties* props = new ConversionProperties();
  props->addOption("flatten comp");
  props->addOption("performValidation", true);
  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(*props);
  converter->setDocument(doc);
  int result = converter->convert();
  // fail if conversion was not valid
  fail_unless(result == LIBSBML_OPERATION_SUCCESS);
  char* sbmlFlat = writeSBMLToString(doc);
  fail_unless(string(atosbml) == string(sbmlFlat));

  ret = loadSBMLString(matching);
  char* roundtrip = getAntimonyString(NULL);
  fail_unless(roundtrip != NULL);
  string rtfilename = dir + base + "_rt.txt";
  ret = loadAntimonyFile(rtfilename.c_str());
  fail_unless(ret != -1);
  matching = getAntimonyString(NULL);
  fail_unless(string(roundtrip) == string(matching));

  delete doc;
  delete atosbml;
  delete sbmlFlat;
  delete roundtrip;
  delete matching;
}

START_TEST (test_hierarchy)
{
  compareFileHierarchy("hierarchy");
}
END_TEST

START_TEST (test_defaultSubCompartment)
{
  compareFileHierarchy("defaultSubCompartment");
}
END_TEST

START_TEST (test_defaultSubSubCompartment)
{
  compareFileHierarchy("defaultSubSubCompartment");
}
END_TEST

START_TEST (test_defaultOrNotCompartment)
{
  compareFileHierarchy("defaultOrNotCompartment");
}
END_TEST

START_TEST (test_deletion)
{
  compareFileHierarchy("deletion");
}
END_TEST

START_TEST (test_deletePriority)
{
  compareFileHierarchy("deletePriority");
}
END_TEST

START_TEST (test_deletePriority2)
{
  compareFileHierarchy("deletePriority2");
}
END_TEST

START_TEST (test_deleteDelay)
{
  compareFileHierarchy("deleteDelay");
}
END_TEST

START_TEST (test_deleteDelay2)
{
  compareFileHierarchy("deleteDelay2");
}
END_TEST

START_TEST (test_deleteEventAssignment)
{
  compareFileHierarchy("deleteEventAssignment");
}
END_TEST

START_TEST (test_deleteEventAssignment2)
{
  compareFileHierarchy("deleteEventAssignment2");
}
END_TEST

START_TEST (test_deleteEventAssignment3)
{
  compareFileHierarchy("deleteEventAssignment3");
}
END_TEST

START_TEST (test_deleteEventAssignment4)
{
  compareFileHierarchy("deleteEventAssignment4");
}
END_TEST

START_TEST (test_deleteEventAssignment5)
{
  compareFileHierarchy("deleteEventAssignment5");
}
END_TEST

START_TEST (test_deleteTrigger)
{
  compareFileHierarchy("deleteTrigger");
}
END_TEST

START_TEST (test_deleteReaction)
{
  compareFileHierarchy("deleteReaction");
}
END_TEST

START_TEST (test_deleteReactant)
{
  compareFileHierarchy("deleteReactant");
}
END_TEST

START_TEST (test_deleteProduct)
{
  compareFileHierarchy("deleteProduct");
}
END_TEST

START_TEST (test_deleteModifier)
{
  compareFileHierarchy("deleteModifier");
}
END_TEST

START_TEST (test_deleteKineticLaw)
{
  compareFileHierarchy("deleteKineticLaw");
}
END_TEST

START_TEST (test_deleteModifierKineticLaw)
{
  compareFileHierarchy("deleteModifierKineticLaw");
}
END_TEST

START_TEST (test_deleteSpecies)
{
  compareFileHierarchy("deleteSpecies");
}
END_TEST

START_TEST (test_deleteSpeciesInDefaultCompartment)
{
  compareFileHierarchy("deleteSpeciesInDefaultCompartment");
}
END_TEST

START_TEST (test_deleteSpeciesInDefaultCompartment2)
{
  compareFileHierarchy("deleteSpeciesInDefaultCompartment2");
}
END_TEST

START_TEST (test_deleteSpeciesPort)
{
  compareFileHierarchy("deleteSpeciesPort");
}
END_TEST

START_TEST (test_deleteSpeciesPortDefaultCompartment)
{
  compareFileHierarchy("deleteSpeciesPortDefaultCompartment");
}
END_TEST

START_TEST (test_deleteRateRuleDirect)
{
  compareFileHierarchy("deleteRateRuleDirect");
}
END_TEST

START_TEST (test_deleteRateRuleIndirect)
{
  compareFileHierarchy("deleteRateRuleIndirect");
}
END_TEST

START_TEST (test_deleteRateRuleOfAnother)
{
  compareFileHierarchy("deleteRateRuleOfAnother");
}
END_TEST

START_TEST (test_deleteAssignmentRuleDirect)
{
  compareFileHierarchy("deleteAssignmentRuleDirect");
}
END_TEST

START_TEST (test_deleteAssignmentRuleIndirect)
{
  compareFileHierarchy("deleteAssignmentRuleIndirect");
}
END_TEST

START_TEST (test_deleteAssignmentRuleOfAnother)
{
  compareFileHierarchy("deleteAssignmentRuleOfAnother");
}
END_TEST

START_TEST (test_deleteInitialAssignmentDirect)
{
  compareFileHierarchy("deleteInitialAssignmentDirect");
}
END_TEST

START_TEST (test_deleteInitialAssignmentIndirect)
{
  compareFileHierarchy("deleteInitialAssignmentIndirect");
}
END_TEST

START_TEST (test_deleteInitialAssignmentOfAnother)
{
  compareFileHierarchy("deleteInitialAssignmentOfAnother");
}
END_TEST

START_TEST (test_replaceAssignmentRule)
{
  compareFileHierarchy("replaceAssignmentRule");
}
END_TEST

START_TEST (test_replaceRateRule)
{
  compareFileHierarchy("replaceRateRule");
}
END_TEST

START_TEST (test_replaceInitialAssignment)
{
  compareFileHierarchy("replaceInitialAssignment");
}
END_TEST

START_TEST (test_replaceCompartment)
{
  compareFileHierarchy("replaceCompartment");
}
END_TEST

START_TEST (test_replaceSpecies)
{
  compareFileHierarchy("replaceSpecies");
}
END_TEST

START_TEST (test_replaceSpeciesDefaultCompartment)
{
  compareFileHierarchy("replaceSpeciesDefaultCompartment");
}
END_TEST

START_TEST (test_replaceParameter)
{
  compareFileHierarchy("replaceParameter");
}
END_TEST

START_TEST (test_replaceReactionOnly)
{
  compareFileHierarchy("replaceReactionOnly");
}
END_TEST

START_TEST (test_replaceReactionOnly2)
{
  compareFileHierarchy("replaceReactionOnly2");
}
END_TEST

START_TEST (test_replaceReactionWithCompartments1)
{
  compareFileHierarchy("replaceReactionWithCompartments1");
}
END_TEST

START_TEST (test_replaceReactionWithCompartments2)
{
  compareFileHierarchy("replaceReactionWithCompartments2");
}
END_TEST

START_TEST (test_replaceReactionWithKineticLaw)
{
  compareFileHierarchy("replaceReactionWithKineticLaw");
}
END_TEST

START_TEST (test_replaceReactionWithKineticLawRxnRef)
{
  compareFileHierarchy("replaceReactionWithKineticLawRxnRef");
}
END_TEST

START_TEST (test_replaceInteraction)
{
  compareFileHierarchy("replaceInteraction");
}
END_TEST

START_TEST (test_submodelInteraction)
{
  compareFileHierarchy("submodelInteraction");
}
END_TEST

START_TEST (test_port)
{
  compareFileHierarchy("port");
}
END_TEST

START_TEST (test_subport)
{
  compareFileHierarchy("subport");
}
END_TEST

START_TEST (test_subport2)
{
  compareFileHierarchy("subport2");
}
END_TEST

START_TEST (test_subsubport)
{
  compareFileHierarchy("subsubport");
}
END_TEST


Suite *
create_suite_Hierarchy(void)
{
  Suite *suite = suite_create("Antimony Hierarchy");
  TCase *tcase = tcase_create("Antimony Hierarchy");

  //tcase_add_test( tcase, test_replace);
  //tcase_add_test( tcase, test_replace);

  tcase_add_test( tcase, test_hierarchy);
  tcase_add_test( tcase, test_defaultSubCompartment);
  tcase_add_test( tcase, test_defaultSubSubCompartment);
  tcase_add_test( tcase, test_defaultOrNotCompartment);
  tcase_add_test( tcase, test_deletion);
  tcase_add_test( tcase, test_deletePriority);
  tcase_add_test( tcase, test_deletePriority2);
  tcase_add_test( tcase, test_deleteDelay);
  tcase_add_test( tcase, test_deleteDelay2);
  tcase_add_test( tcase, test_deleteEventAssignment);
  tcase_add_test( tcase, test_deleteEventAssignment2);
  tcase_add_test( tcase, test_deleteEventAssignment3);
  tcase_add_test( tcase, test_deleteEventAssignment4);
  tcase_add_test( tcase, test_deleteEventAssignment5);
  tcase_add_test( tcase, test_deleteTrigger);
  tcase_add_test( tcase, test_deleteReaction);
  tcase_add_test( tcase, test_deleteReactant);
  tcase_add_test( tcase, test_deleteProduct);
  tcase_add_test( tcase, test_deleteModifier);
  tcase_add_test( tcase, test_deleteKineticLaw);
  tcase_add_test( tcase, test_deleteModifierKineticLaw);
  tcase_add_test( tcase, test_deleteSpecies);
  tcase_add_test( tcase, test_deleteSpeciesInDefaultCompartment);
  tcase_add_test( tcase, test_deleteSpeciesInDefaultCompartment2);
  tcase_add_test( tcase, test_deleteSpeciesPort);
  tcase_add_test( tcase, test_deleteSpeciesPortDefaultCompartment);
  tcase_add_test( tcase, test_deleteRateRuleDirect);
  tcase_add_test( tcase, test_deleteRateRuleIndirect);
  tcase_add_test( tcase, test_deleteRateRuleOfAnother);
  tcase_add_test( tcase, test_deleteAssignmentRuleDirect);
  tcase_add_test( tcase, test_deleteAssignmentRuleIndirect);
  tcase_add_test( tcase, test_deleteAssignmentRuleOfAnother);
  tcase_add_test( tcase, test_deleteInitialAssignmentDirect);
  tcase_add_test( tcase, test_deleteInitialAssignmentIndirect);
  tcase_add_test( tcase, test_deleteInitialAssignmentOfAnother);
  tcase_add_test( tcase, test_replaceAssignmentRule);
  tcase_add_test( tcase, test_replaceRateRule);
  tcase_add_test( tcase, test_replaceInitialAssignment);
  tcase_add_test( tcase, test_replaceCompartment);
  tcase_add_test( tcase, test_replaceParameter);
  tcase_add_test( tcase, test_replaceSpecies);
  tcase_add_test( tcase, test_replaceSpeciesDefaultCompartment);
  tcase_add_test( tcase, test_replaceReactionOnly);
  tcase_add_test( tcase, test_replaceReactionOnly2);
  tcase_add_test( tcase, test_replaceReactionWithCompartments1);
  tcase_add_test( tcase, test_replaceReactionWithCompartments2);
  tcase_add_test( tcase, test_replaceReactionWithKineticLaw);
  tcase_add_test( tcase, test_replaceReactionWithKineticLawRxnRef);
  tcase_add_test( tcase, test_replaceInteraction);
  tcase_add_test( tcase, test_submodelInteraction);
  tcase_add_test( tcase, test_port);
  tcase_add_test( tcase, test_subport);
  tcase_add_test( tcase, test_subport2);
  tcase_add_test( tcase, test_subsubport);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



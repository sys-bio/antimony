/**
 * \file    TestAlgebraicRule.c
 * \brief   AlgebraicRule unit tests
 * \author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include "libutil.h"
#include "antimony_api.h"
#include "sbml/SBMLTypes.h"

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

START_TEST (unknown_file1)
{
  string filename = "nosuchfile.txt";
  long ret = loadAntimonyFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  delete err;
}
END_TEST


START_TEST (unknown_file2)
{
  string filename = "nosuchfile.xml";
  long ret = loadSBMLFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Unable to read SBML file 'nosuchfile.xml' due to errors encountered when parsing the file.  Error(s) from libSBML:\nline 1: (00002 [Error]) File unreadable.\n");
  fail_unless(error == expected);
  delete err;
}
END_TEST


START_TEST (unknown_file3)
{
#ifndef NCELLML
  string filename = "nosuchfile.cellml";
  long ret = loadCellMLFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Unable to read CellML file 'nosuchfile.cellml' due to errors encountered when parsing the file.  Error(s) from the CellML API:\nservererror\n");
  fail_unless(error == expected);
  delete err;
#endif
}
END_TEST


START_TEST (unknown_file4)
{
  string filename = "nosuchfile.txt";
  long ret = loadFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  delete err;
}
END_TEST


START_TEST (unknown_file5)
{
  string filename = "nosuchdir/nosuchfile.txt";
  long ret = loadFile(filename.c_str());
  fail_unless(ret==-1);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("Could not open 'nosuchdir/nosuchfile.txt', and could not find that file in any known directory.  Please check that this file:\n	1) exists in directory that antimony is being run from or knows about\n	2) is read enabled, and\n	3) is not in use by another program.\n");
  fail_unless(error == expected);
  delete err;
}
END_TEST


START_TEST (unknown_models)
{
  char* nomod = getSBMLString("");
  fail_unless(nomod == NULL);
  char* err = getLastError();
  fail_unless(err != NULL);
  string error(err);
  string expected("No such module: ''.  Existing modules: '__main'");
  fail_unless(error == expected);
  delete err;
  nomod = getAntimonyString("");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
  delete err;
#ifndef NCELLML
  nomod = getCellMLString("");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
  delete err;
#endif

  nomod = getSBMLString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  expected = "No such module: 'nosuchmodel'.  Existing modules: '__main'";
  fail_unless(error == expected);
  delete err;
  nomod = getAntimonyString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
  delete err;
#ifndef NCELLML
  nomod = getCellMLString("nosuchmodel");
  fail_unless(nomod == NULL);
  err = getLastError();
  fail_unless(err != NULL);
  error = err;
  fail_unless(error == expected);
  delete err;
#endif
}
END_TEST

void compareFileTranslation(const string& base)
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
  char* matching = writeSBMLToString(doc);
  fail_unless(string(atosbml) == string(matching));

  //Now check the roundtripped version:
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
  delete roundtrip;
  delete matching;
}

void compareStringTranslation(const string& antimony, const string& sbml)
{
  clearPreviousLoads();
  long ret = loadAntimonyString(antimony.c_str());
  fail_unless(ret != -1);
  char* atosbml = getCompSBMLString(NULL);
  fail_unless(atosbml != NULL);

  string dir(TestDataDirectory);
  string sbmlfile = dir + sbml;
  SBMLDocument* doc = readSBMLFromFile(sbmlfile.c_str());
  string matchingdoc = writeSBMLToString(doc);

  fail_unless(atosbml == matchingdoc);
  delete doc;
  delete atosbml;
}

START_TEST (test_parameter)
{
  compareFileTranslation("parameter");
}
END_TEST

START_TEST (test_parameter_txt)
{
  compareStringTranslation("a=3", "parameter.xml");
}
END_TEST


START_TEST (test_reaction)
{
  compareFileTranslation("reaction");
}
END_TEST

START_TEST (test_reaction_txt)
{
  compareStringTranslation("J0: a->; k1", "reaction.xml");
}
END_TEST


START_TEST (test_compartment)
{
  compareFileTranslation("compartment");
}
END_TEST

START_TEST (test_compartment_txt)
{
  compareStringTranslation("x in y", "compartment.xml");
}
END_TEST


START_TEST (test_species)
{
  compareFileTranslation("species");
}
END_TEST

START_TEST (test_species_txt)
{
  compareStringTranslation("species x in y", "species.xml");
}
END_TEST


START_TEST (test_reactionIn)
{
  compareFileTranslation("reactionIn");
}
END_TEST

START_TEST (test_reactionIn_txt)
{
  compareStringTranslation("J0 in C: ->a; k1", "reactionIn.xml");
}
END_TEST


START_TEST (test_event)
{
  compareFileTranslation("event");
}
END_TEST

START_TEST (test_event_txt)
{
  compareStringTranslation("at(time>3): x=3", "event.xml");
}
END_TEST


START_TEST (test_eventPriority)
{
  compareFileTranslation("eventPriority");
}
END_TEST

START_TEST (test_eventPriority_txt)
{
  compareStringTranslation("at(time>3), priority=2: x=3", "eventPriority.xml");
}
END_TEST


START_TEST (test_eventDelay)
{
  compareFileTranslation("eventDelay");
}
END_TEST

START_TEST (test_eventDelay_txt)
{
  compareStringTranslation("at 2 after (time>3): x=3", "eventDelay.xml");
}
END_TEST


START_TEST (test_eventT0)
{
  compareFileTranslation("eventT0");
}
END_TEST

START_TEST (test_eventT0_txt)
{
  compareStringTranslation("at(time>3), t0=false: x=3", "eventT0.xml");
}
END_TEST


START_TEST (test_eventFromTrigger)
{
  compareFileTranslation("eventFromTrigger");
}
END_TEST

START_TEST (test_eventFromTrigger_txt)
{
  compareStringTranslation("at(time>3), fromTrigger=false: x=3", "eventFromTrigger.xml");
}
END_TEST


START_TEST (test_eventPersistent)
{
  compareFileTranslation("eventPersistent");
}
END_TEST

START_TEST (test_eventPersistent_txt)
{
  compareStringTranslation("at(time>3), persistent=false: x=3", "eventPersistent.xml");
}
END_TEST


START_TEST (test_initialValue)
{
  compareFileTranslation("initialValue");
}
END_TEST

START_TEST (test_initialValue_txt)
{
  compareStringTranslation("x=3", "initialValue.xml");
}
END_TEST


START_TEST (test_initialConcentration)
{
  compareFileTranslation("initialConcentration");
}
END_TEST

START_TEST (test_initialConcentration_txt)
{
  compareStringTranslation("species x=3", "initialConcentration.xml");
}
END_TEST


START_TEST (test_initialAmount)
{
  compareFileTranslation("initialAmount");
}
END_TEST

START_TEST (test_initialAmount_txt)
{
  compareStringTranslation("species x in C=3/C", "initialAmount.xml");
}
END_TEST


START_TEST (test_initialAssignment)
{
  compareFileTranslation("initialAssignment");
}
END_TEST

START_TEST (test_initialAssignment_txt)
{
  compareStringTranslation("x=4/6", "initialAssignment.xml");
}
END_TEST


START_TEST (test_interactionGeneric)
{
  compareFileTranslation("interactionGeneric");
}
END_TEST

START_TEST (test_interactionGeneric_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -( J0;", "interactionGeneric.xml");
}
END_TEST


START_TEST (test_interactionActivation)
{
  compareFileTranslation("interactionActivation");
}
END_TEST

START_TEST (test_interactionActivation_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -o J0;", "interactionActivation.xml");
}
END_TEST


START_TEST (test_interactionInhibition)
{
  compareFileTranslation("interactionInhibition");
}
END_TEST

START_TEST (test_interactionInhibition_txt)
{
  compareStringTranslation("J0: S1->;;Ji: S2 -| J0;", "interactionInhibition.xml");
}
END_TEST


START_TEST (test_rateRule)
{
  compareFileTranslation("rateRule");
}
END_TEST

START_TEST (test_rateRule_txt)
{
  compareStringTranslation("x'=4.4", "rateRule.xml");
}
END_TEST


START_TEST (test_assignmentRule)
{
  compareFileTranslation("assignmentRule");
}
END_TEST

START_TEST (test_assignmentRule_txt)
{
  compareStringTranslation("x:=4.8", "assignmentRule.xml");
}
END_TEST


START_TEST (test_units)
{
  compareFileTranslation("units");
}
END_TEST

START_TEST (test_units_txt)
{
  compareStringTranslation("unit mL = .001*liters", "units.xml");
}
END_TEST


START_TEST (test_names)
{
  compareFileTranslation("names");
}
END_TEST

START_TEST (test_names_txt)
{
  compareStringTranslation("x is \"This Name!\"", "names.xml");
}
END_TEST


Suite *
create_suite_Basic (void)
{
  Suite *suite = suite_create("Antimony Basic");
  TCase *tcase = tcase_create("Antimony Basic");

  tcase_add_test( tcase, unknown_file1);
  tcase_add_test( tcase, unknown_file2);
  tcase_add_test( tcase, unknown_file3);
  tcase_add_test( tcase, unknown_file4);
  tcase_add_test( tcase, unknown_file5);
  tcase_add_test( tcase, unknown_models);
  tcase_add_test( tcase, test_parameter);
  tcase_add_test( tcase, test_parameter_txt);
  tcase_add_test( tcase, test_reaction);
  tcase_add_test( tcase, test_reaction_txt);
  tcase_add_test( tcase, test_compartment);
  tcase_add_test( tcase, test_compartment_txt);
  tcase_add_test( tcase, test_species);
  tcase_add_test( tcase, test_species_txt);
  tcase_add_test( tcase, test_reactionIn);
  tcase_add_test( tcase, test_reactionIn_txt);
  tcase_add_test( tcase, test_event);
  tcase_add_test( tcase, test_event_txt);
  tcase_add_test( tcase, test_eventPriority);
  tcase_add_test( tcase, test_eventPriority_txt);
  tcase_add_test( tcase, test_eventDelay);
  tcase_add_test( tcase, test_eventDelay_txt);
  tcase_add_test( tcase, test_eventT0);
  tcase_add_test( tcase, test_eventT0_txt);
  tcase_add_test( tcase, test_eventFromTrigger);
  tcase_add_test( tcase, test_eventFromTrigger_txt);
  tcase_add_test( tcase, test_eventPersistent);
  tcase_add_test( tcase, test_eventPersistent_txt);
  tcase_add_test( tcase, test_initialValue);
  tcase_add_test( tcase, test_initialValue_txt);
  tcase_add_test( tcase, test_initialConcentration);
  tcase_add_test( tcase, test_initialConcentration_txt);
  tcase_add_test( tcase, test_initialAmount);
  tcase_add_test( tcase, test_initialAmount_txt);
  tcase_add_test( tcase, test_initialAssignment);
  tcase_add_test( tcase, test_initialAssignment_txt);
  tcase_add_test( tcase, test_interactionGeneric);
  tcase_add_test( tcase, test_interactionGeneric_txt);
  tcase_add_test( tcase, test_interactionActivation);
  tcase_add_test( tcase, test_interactionActivation_txt);
  tcase_add_test( tcase, test_interactionInhibition);
  tcase_add_test( tcase, test_interactionInhibition_txt);
  tcase_add_test( tcase, test_rateRule);
  tcase_add_test( tcase, test_rateRule_txt);
  tcase_add_test( tcase, test_assignmentRule);
  tcase_add_test( tcase, test_assignmentRule_txt);
  tcase_add_test( tcase, test_units);
  tcase_add_test( tcase, test_units_txt);
  tcase_add_test( tcase, test_names);
  tcase_add_test( tcase, test_names_txt);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



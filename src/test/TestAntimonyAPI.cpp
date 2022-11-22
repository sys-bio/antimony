/**
 * \file    TestAntimonyAPI.c
 * \brief   Test Antimony's API constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <iostream>

#include <string>
#include <check.h>

using namespace std;

BEGIN_C_DECLS

extern char *TestDataDirectory;

START_TEST (test_getAntimonyString)
{
  loadString("a=3");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  freeAll();
}
END_TEST

START_TEST (test_whatIsMainModel1)
{
  loadString("a=3\nmodel foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "__main");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_whatIsMainModel2)
{
  loadString("a=3\nmodel *foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_whatIsMainModel3)
{
  loadString("model foo()\nb=10\nend\na=3");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "__main");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_whatIsMainModel4)
{
  loadString("model foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_whatIsMainModel5)
{
  loadString("model foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "bar");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_whatIsMainModel6)
{
  loadString("model *foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n");
  char* mainname = getMainModuleName();
  fail_unless(string(mainname) == "foo");


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadAntimonyFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyFileErrNotAntimony)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.xml";

  long ret = loadAntimonyFile(filename.c_str());
  fail_unless (ret == -1);
  string err = "The file '" + filename + "' is actually an SBML file, and is not in the Antimony format.  Use 'loadFile' or 'loadSBMLFile' to correctly parse it.";
  fail_unless (string(getLastError()) == err);

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyFileErrNoFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/does_not_exist.txt";

  long ret = loadAntimonyFile(filename.c_str());
  fail_unless (ret == -1);
  string err = "Could not open '" + filename + "', and could not find that file in any known directory.  Please check that this file:\n\t1) exists in directory that antimony is being run from or knows about\n\t2) is read enabled, and\n\t3) is not in use by another program.\n";
  fail_unless (string(getLastError()) == err);

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_getStrings)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");
  char* sbml = getSBMLString(NULL);
  fail_unless(string(sbml) == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  sbml = getCompSBMLString(NULL);
  fail_unless(string(sbml) == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" xmlns:comp=\"http://www.sbml.org/sbml/level3/version1/comp/version1\" level=\"3\" version=\"1\" comp:required=\"true\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  sbml = getSBMLString(NULL);
  fail_unless(string(sbml) == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_getCellML)
{
  clearPreviousLoads();
  loadString("model *foo()\nb=10\nend\nmodel bar()\nc=10\nend");

#ifndef NCELLML
  //This function crashes for NO REASON.  I use exactly the same 
  char* cellml = getCellMLString(NULL);
  fail_unless(string(cellml) == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
#endif
  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyString)
{
  loadAntimonyString("a=3");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyStringErrNotAntimony)
{
  long ret = loadAntimonyString("^SLFJNNN___ slk");
  fail_unless (ret == -1);
  string err = "Error in model string, line 1:  syntax error, unexpected '^'";
  fail_unless (string(getLastError()) == err);


  freeAll();
  clearPreviousLoads();
}
END_TEST

START_TEST (test_loadAntimonyStringErrSBML)
{
  long ret = loadAntimonyString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  fail_unless (ret == -1);
  string err = "The provided string is actually an SBML model, and is not in the Antimony format.  Use 'loadString' or 'loadSBMLString' to correctly parse it.";
  fail_unless (string(getLastError()) == err);


  freeAll();
}
END_TEST

START_TEST (test_loadSBMLFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.xml";

  loadSBMLFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\n// Other declarations:\nconst a;\n");

  freeAll();
}
END_TEST

START_TEST (test_loadSBMLFileErrNotSBML)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  long ret = loadSBMLFile(filename.c_str());
  fail_unless (ret == -1);
  string err_libxml = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (01035 [Error]) Main XML content is empty.\n\n";
  string err_libexpat = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (01006 [Error]) XML content is not well-formed.\n\n";
  char* lasterr = getLastError();
  fail_unless (string(lasterr) == err_libxml || string(lasterr) == err_libexpat);

  freeAll();
}
END_TEST

START_TEST (test_loadSBMLFileErrNoFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/doesNotExist.xml";

  loadSBMLFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  string err = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (00002 [Error]) File unreadable.\n";


  freeAll();
}
END_TEST

START_TEST (test_loadSBMLString)
{
  long ret = loadSBMLString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\n// Other declarations:\nconst a;\n");

  freeAll();
}
END_TEST

START_TEST (test_loadSBMLStringErrNotSBML)
{
  long ret = loadSBMLString("^SLFJNNN___ slk");
  fail_unless (ret == -1);
  string err_libxml = "Unable to read SBML string due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 2: (01035 [Error]) Main XML content is empty.\n\n";
  string err_libexpat = "Unable to read SBML string due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 2: (01006 [Error]) XML content is not well-formed.\n\n";
  char* lasterr = getLastError();
  fail_unless (string(lasterr) == err_libxml || string(lasterr) == err_libexpat);


  freeAll();
}
END_TEST

START_TEST (test_loadSBMLFileWithLocationAuto)
{
  string dir(TestDataDirectory);
  string filename = dir + "from-libsbml/ext_in_subdir.xml";

  int ret = loadSBMLFile(filename.c_str());
  fail_unless(getNumModules() == 3);

  freeAll();
}
END_TEST

START_TEST (test_loadSBMLStringWithLocation)
{
  string dir = TestDataDirectory;
  dir += "from-libsbml/";
  long ret = loadSBMLStringWithLocation("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
"<!-- The file 'new_aggregate.xml' is actually in the subdirectory 'subdir', so you have to tell the converter to look there, or this model cannot be flattened.-->"
"<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" xmlns:comp=\"http://www.sbml.org/sbml/level3/version1/comp/version1\" level=\"3\" version=\"1\" comp:required=\"true\">"
"  <model>"
"    <comp:listOfSubmodels>"
"      <comp:submodel comp:id=\"A\" comp:modelRef=\"EM1\"/>"
"    </comp:listOfSubmodels>"
"  </model>"
"  <comp:listOfExternalModelDefinitions>"
"    <comp:externalModelDefinition comp:id=\"EM1\" comp:source=\"subdir/new_aggregate.xml\" comp:modelRef=\"enzyme\"/>"
"  </comp:listOfExternalModelDefinitions>"
"</sbml>"
, dir.c_str());
  fail_unless (ret != -1);

  fail_unless(getNumModules() == 3);

  freeAll();
}
END_TEST

START_TEST (test_previousLoads)
{
  clearPreviousLoads();
  fail_unless(getNumFiles() == 0);

  loadString("a=3");
  loadString("b=3");
  fail_unless(getNumFiles() == 2);

  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\nb = 3;\n");

  revertTo(1);
  model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  revertTo(2);
  model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\nb = 3;\n");

  clearPreviousLoads();
  freeAll();
}
END_TEST

START_TEST (test_directories)
{
  addDirectory(TestDataDirectory);
  int ret = loadFile("parameter.txt");
  fail_unless(ret != -1);
  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n");

  clearDirectories();
  ret = loadFile("parameter.txt");
  fail_unless(ret == -1);

  freeAll();
}
END_TEST
  
//LIB_EXTERN int   writeAntimonyFile(const char* filename, const char* moduleName);
//LIB_EXTERN int   writeSBMLFile(const char* filename, const char* moduleName);
//LIB_EXTERN int   writeCompSBMLFile(const char* filename, const char* moduleName);

START_TEST (test_checkModule)
{
  int ret = loadString("model foo()\na=3\nend");
  fail_unless(ret != -1);
  fail_unless(checkModule("foo") == true);
  fail_unless(checkModule("bar") == false);
  fail_unless(checkModule("__main") == true);

  freeAll();
}
END_TEST

//LIB_EXTERN char*  getWarnings();

START_TEST (test_SBMLWarnings)
{
  int ret = loadString("const S1");
  fail_unless(ret != -1);

  fail_unless(string(getSBMLWarnings(NULL)) == "As a principle of best modeling practice, the <parameter> should set an initial value rather than be left undefined. Doing so improves the portability of models between different simulation and analysis systems, and helps make it easier to detect potential errors in models.\n The <parameter> with the id 'S1' does not have 'value' attribute, nor is its initial value set by an <initialAssignment> or <assignmentRule>.\n\nDue to the need to instantiate models, modelDefinitions, submodels etc. for the purposes of validation it is problematic to reliably report line numbers when performing validation on models using the Hierarchical Model Composition package.\n\nAs a principle of best modeling practice, the <parameter> should set an initial value rather than be left undefined. Doing so improves the portability of models between different simulation and analysis systems, and helps make it easier to detect potential errors in models.\n The <parameter> with the id 'S1' does not have 'value' attribute, nor is its initial value set by an <initialAssignment> or <assignmentRule>.\n");

  freeAll();
}
END_TEST
  
START_TEST (test_SBMLInfo)
{
  //As far as I can tell, there are currently zero messages that libsbml classifies as 'info'
  int ret = loadString("a=3");
  fail_unless(ret != -1);
  char* sbml = getSBMLString(NULL);

  fail_unless(string(getSBMLInfoMessages(NULL)) == "");

  freeAll();
}
END_TEST
  
START_TEST (test_moduleNames)
{
  int ret = loadString("model foo()\na=3\nend\nmodel bar()\nb=4\nend\n");
  fail_unless(ret != -1);

  fail_unless(getNumModules() == 3);
  char** modname = getModuleNames();
  fail_unless(string(modname[0]) == "__main");
  fail_unless(string(modname[1]) == "foo");
  fail_unless(string(modname[2]) == "bar");
  fail_unless(string(getNthModuleName(0)) == "__main");
  fail_unless(string(getNthModuleName(1)) == "foo");
  fail_unless(string(getNthModuleName(2)) == "bar");
  fail_unless(string(getMainModuleName()) == "bar");

  freeAll();
}
END_TEST
  
START_TEST (test_moduleInterfaceNames)
{
  int ret = loadString("model foo(a, b, c)\na=3\nend");
  fail_unless(ret != -1);

  fail_unless(getNumSymbolsInInterfaceOf("foo") == 3);
  char** inames = getSymbolNamesInInterfaceOf("foo");
  fail_unless(string(inames[0]) == "a");
  fail_unless(string(inames[1]) == "b");
  fail_unless(string(inames[2]) == "c");
  fail_unless(string(getNthSymbolNameInInterfaceOf("foo", 0)) == "a");
  fail_unless(string(getNthSymbolNameInInterfaceOf("foo", 1)) == "b");
  fail_unless(string(getNthSymbolNameInInterfaceOf("foo", 2)) == "c");
  fail_unless(string(getNthSymbolNameInInterfaceOf("foo", 3)) == "");

  freeAll();
}
END_TEST
  
START_TEST (test_replacedSymbols)
{
  int ret = loadString("model foo(a, b, c)\na=3\nend\nmodel bar()\nmod1: foo(A,B,C)\nend\n");
  fail_unless(ret != -1);

  fail_unless(getNumReplacedSymbolNames("bar") == 3);
  char*** replacedPairs = getAllReplacementSymbolPairs("bar");
  fail_unless(string(replacedPairs[0][0]) == "mod1_a");
  fail_unless(string(replacedPairs[0][1]) == "A");
  fail_unless(string(replacedPairs[1][0]) == "mod1_b");
  fail_unless(string(replacedPairs[1][1]) == "B");
  fail_unless(string(replacedPairs[2][0]) == "mod1_c");
  fail_unless(string(replacedPairs[2][1]) == "C");

  char** replacedPair = getNthReplacementSymbolPair("bar", 0);
  fail_unless(string(replacedPair[0]) == "mod1_a");
  fail_unless(string(replacedPair[1]) == "A");

  char* formersymb = getNthFormerSymbolName("bar", 0);
  fail_unless(string(formersymb) == "mod1_a");

  char* newsymb = getNthReplacementSymbolName("bar", 0);
  fail_unless(string(newsymb) == "A");

  fail_unless(getNumReplacedSymbolNamesBetween("bar", "mod1", "") == 3);
  
  replacedPairs = getAllReplacementSymbolPairsBetween("bar", "mod1", "");
  fail_unless(string(replacedPairs[0][0]) == "a");
  fail_unless(string(replacedPairs[0][1]) == "A");
  fail_unless(string(replacedPairs[1][0]) == "b");
  fail_unless(string(replacedPairs[1][1]) == "B");
  fail_unless(string(replacedPairs[2][0]) == "c");
  fail_unless(string(replacedPairs[2][1]) == "C");

  replacedPair = getNthReplacementSymbolPairBetween("bar", "mod1", "", 0);
  fail_unless(string(replacedPair[0]) == "a");
  fail_unless(string(replacedPair[1]) == "A");

  formersymb = getNthFormerSymbolNameBetween("bar", "mod1", "", 0);
  fail_unless(string(formersymb) == "a");

  newsymb = getNthReplacementSymbolNameBetween("bar", "mod1", "", 0);
  fail_unless(string(newsymb) == "A");


  freeAll();
}
END_TEST
  
//The 'printAllDataFor' function tests a lot of other functions implicitly, which is nice.
START_TEST (test_printAll)
{
  int ret = loadString(
    "model foo(a, b, c)\n"
    "  a=3\n"
    "  a' = 1\n"
    "  b := a+2\n"
    "  S1 -> S2; k1*S1\n"
    "  J1: S2 -> ; k2*S2*S3\n"
    "  E0: at(time>2): a = 0\n"
    "  S2 in C1\n"
    "  C1 = 1.5\n"
    "  DNA1: P--Q--R\n"
    "  DNA2: DNA1--S\n"
    "  S3 -o J1;\n"
    "end"
    );
  fail_unless(ret != -1);

  char* out = printAllDataFor("foo");
  fail_unless(string(out) ==
    "All variables for module foo:\n"
"a	Type:  variable formula or equation\n"
"	Initialization: 3\n"
"	Rate rule: 1\n"
"b	Type:  variable formula or equation\n"
"	Assignment rule: a+2\n"
"c	Type:  constant formula or equation\n"
"S1	Type:  variable species (generic)\n"
"S2	Type:  variable species (generic)\n"
"	In compartment: C1\n"
"k1	Type:  Unknown type\n"
"_J0	Type:  Reaction (generic)\n"
"	Kinetic Law: k1*S1\n"
"J1	Type:  Reaction (generic)\n"
"	Kinetic Law: k2*S2*S3\n"
"k2	Type:  Unknown type\n"
"S3	Type:  variable species (generic)\n"
"E0	Type:  Event\n"
"	Event Trigger: (time>2)\n"
"C1	Type:  constant-sized compartment\n"
"	Initialization or basic equation : 1.5\n"
"DNA1	Type:  modular DNA strand\n"
"	Assignment rule: 0\n"
"P	Type:  all DNA (genes and operators)\n"
"	Assignment rule: 0\n"
"Q	Type:  all DNA (genes and operators)\n"
"	Assignment rule: (0)\n"
"R	Type:  all DNA (genes and operators)\n"
"	Assignment rule: ((0))\n"
"DNA2	Type:  modular DNA strand\n"
"	Assignment rule: 0\n"
"S	Type:  all DNA (genes and operators)\n"
"	Assignment rule: (((0)))\n"
"_J1	Type:  Interaction (generic)\n"
"\n"
"DNA strands:\n"
"DNA2: P--Q--R--S\n"
"\n"
"Modular DNA strands:\n"
"DNA1: P--Q--R\n"
"DNA2: DNA1--S\n"
"\n"
"Reactions:\n"
"_J0: S1 -> S2 ; k1*S1\n"
"J1: S2 ->  ; k2*S2*S3\n"
"Stoichiometry matrix\n"
"		_J0	J1\n"
"S1		-1	0\n"
"S2		1	-1\n"
"S3		0	0\n"
"\n"
"Reaction rates\n"
"k1*S1\n"
"k2*S2*S3\n"
"\n"
"Interactions:\n"
"_J1: S3 -( J1 ; \n"
"\n"
"Events\n"
"E0: at (time > 2): a=0\n"
"\n");
  freeAll();
}
END_TEST
  

START_TEST (test_names)
{
  int ret = loadString("a = 3\na is \"name\"\nspecies b = 2\nb is \"species B\"");

  fail_unless(getNumSymbolsOfType("__main", allSymbols) == 2);
  char** names = getSymbolDisplayNamesOfType("__main", allSymbols);
  fail_unless(string(names[0]) == "name");
  fail_unless(string(names[1]) == "species B");
  names = getSymbolDisplayNamesOfType("__main", allSpecies);
  fail_unless(string(names[0]) == "species B");
  freeAll();
}
END_TEST

START_TEST (test_event_modifications)
{
  int ret = loadString("E0: at(x==3): y=2\nE1: at 5 after n==2, priority=10, persistent=false, t0=false, fromTrigger=false: z=3");

  fail_unless(string(getDelayForEvent("__main", 0)) == "");
  fail_unless(string(getDelayForEvent("__main", 1)) == "5");
  fail_unless(getEventHasDelay("__main", 0) == false);
  fail_unless(getEventHasDelay("__main", 1) == true);

  fail_unless(string(getPriorityForEvent("__main", 0)) == "");
  fail_unless(string(getPriorityForEvent("__main", 1)) == "10");
  fail_unless(getEventHasPriority("__main", 0) == false);
  fail_unless(getEventHasPriority("__main", 1) == true);

  fail_unless(getPersistenceForEvent("__main", 0) == true);
  fail_unless(getPersistenceForEvent("__main", 1) == false);

  fail_unless(getT0ForEvent("__main", 0) == true);
  fail_unless(getT0ForEvent("__main", 1) == false);

  fail_unless(getFromTriggerForEvent("__main", 0) == true);
  fail_unless(getFromTriggerForEvent("__main", 1) == false);

  freeAll();
}
END_TEST

START_TEST (test_addDefaults)
{
  int ret = loadString("model foo(a)\nconst z\nspecies x in C1\nx ->;\nend");
  fail_unless(ret != -1);

  char* model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Compartments and Species:\n  compartment C1;\n  species x in C1;\n\n  // Reactions:\n  _J0: x -> ; ;\n\n  // Species initializations:\n  x = ;\n\n  // Compartment initializations:\n  C1 = ;\n\n  // Variable initializations:\n  a = ;\n  z = ;\n\n  // Other declarations:\n  const z;\nend\n");
  fail_unless(addDefaultInitialValues(NULL) == false);
  model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Compartments and Species:\n  compartment C1;\n  species x in C1;\n\n  // Reactions:\n  _J0: x -> ; 0;\n\n  // Species initializations:\n  x = 0;\n\n  // Compartment initializations:\n  C1 = 1;\n\n  // Variable initializations:\n  a = 1;\n  z = 1;\n\n  // Other declarations:\n  const z;\nend\n");

  ret = loadString("model foo(a)\nend\nA: foo(x)");
  fail_unless(ret != -1);

  model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Variable initializations:\n  a = ;\nend\n\n\n// Sub-modules, and any changes to those submodules:\nA: foo(x);\n\n");
  fail_unless(addDefaultInitialValues(NULL) == false);
  model = getAntimonyString(NULL);
  fail_unless(string(model) == (string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Variable initializations:\n  a = ;\nend\n\n\n// Sub-modules, and any changes to those submodules:\nA: foo(x);\n\n// Variable initializations:\nx = 1;\n\n");



  freeAll();
}
END_TEST


START_TEST (test_dimensionless)
{
  int ret = loadString("a=3+2");
  fail_unless(ret != -1);
  setBareNumbersAreDimensionless(true);

  char* sbml = getSBMLString(NULL);
  fail_unless(string(sbml) == "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version1/core\" level=\"3\" version=\"1\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" constant=\"true\"/>\n    </listOfParameters>\n    <listOfInitialAssignments>\n      <initialAssignment symbol=\"a\">\n        <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:sbml=\"http://www.sbml.org/sbml/level3/version1/core\">\n          <apply>\n            <plus/>\n            <cn sbml:units=\"dimensionless\" type=\"integer\"> 3 </cn>\n            <cn sbml:units=\"dimensionless\" type=\"integer\"> 2 </cn>\n          </apply>\n        </math>\n      </initialAssignment>\n    </listOfInitialAssignments>\n  </model>\n</sbml>\n");
  setBareNumbersAreDimensionless(false);

  freeAll();
}
END_TEST

 
  
START_TEST (test_rxns)
{
    clearPreviousLoads();
    string mod =
        "s1 = 1\n"
        "s2 = 2\n"
        "s3 = 3\n"
        "s4 = 4\n"
        "k1 = 0.5\n"
        "k2 = 0.3\n"
        "k3 = 0.1\n"
        "k4 = 0.05\n"
        "->s1; k1 / s1\n"
        "s1->s2;k2* s1 / s2\n"
        "s2->s3;k3* s2 / s3\n"
        "s3->s4;k4* s3 / s4\n";
  int ret = loadString(mod.c_str());
  fail_unless(ret != -1);
  fail_unless(getNumReactions("__main") == 4);


  freeAll();
}
END_TEST

 
  
  //LIB_EXTERN void setBareNumbersAreDimensionless(bool dimensionless);



Suite *
create_suite_API (void)
{
  Suite *suite = suite_create("Antimony API");
  TCase *tcase = tcase_create("Antimony API");

  tcase_add_test( tcase, test_getAntimonyString);
  tcase_add_test( tcase, test_whatIsMainModel1);
  tcase_add_test( tcase, test_whatIsMainModel2);
  tcase_add_test( tcase, test_whatIsMainModel3);
  tcase_add_test( tcase, test_whatIsMainModel4);
  tcase_add_test( tcase, test_whatIsMainModel5);
  tcase_add_test( tcase, test_whatIsMainModel6);
  tcase_add_test( tcase, test_loadFile);
  //tcase_add_test( tcase, test_getCellML);
  tcase_add_test( tcase, test_loadAntimonyFile);
  tcase_add_test( tcase, test_loadAntimonyFileErrNotAntimony);
  tcase_add_test( tcase, test_loadAntimonyFileErrNoFile);
  tcase_add_test( tcase, test_getStrings);
  tcase_add_test( tcase, test_loadAntimonyString);
  tcase_add_test( tcase, test_loadAntimonyStringErrNotAntimony);
  tcase_add_test( tcase, test_loadAntimonyStringErrSBML);
  tcase_add_test( tcase, test_loadSBMLFile);
  tcase_add_test( tcase, test_loadSBMLFileErrNotSBML);
  tcase_add_test( tcase, test_loadSBMLFileErrNoFile);
  tcase_add_test( tcase, test_loadSBMLString);
  tcase_add_test( tcase, test_loadSBMLStringErrNotSBML);
  tcase_add_test( tcase, test_loadSBMLFileWithLocationAuto);
  tcase_add_test( tcase, test_loadSBMLStringWithLocation);
  tcase_add_test( tcase, test_previousLoads);
  tcase_add_test( tcase, test_directories);
  tcase_add_test( tcase, test_checkModule);
  tcase_add_test( tcase, test_SBMLWarnings);
  tcase_add_test( tcase, test_SBMLInfo);
  tcase_add_test( tcase, test_moduleNames);
  tcase_add_test( tcase, test_moduleInterfaceNames);
  tcase_add_test( tcase, test_replacedSymbols);
  tcase_add_test( tcase, test_printAll);
  tcase_add_test( tcase, test_names);
  tcase_add_test( tcase, test_event_modifications);
  tcase_add_test( tcase, test_addDefaults);
  tcase_add_test( tcase, test_dimensionless);
  tcase_add_test( tcase, test_rxns);

  suite_add_tcase(suite, tcase);

  return suite;
}

END_C_DECLS



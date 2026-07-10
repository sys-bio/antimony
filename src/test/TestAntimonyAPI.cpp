/**
 * \file    TestAntimonyAPI.c
 * \brief   Test Antimony's API constructs.
 * \author  Lucian Smith
 * ---------------------------------------------------------------------- -->*/

#include "antimony_api.h"
#include <iostream>

#include <string>
#include "gtest/gtest.h"

using namespace std;

extern char *TestDataDirectory;

TEST(AntimonyAPI, test_getAntimonyString)
{
  loadString("a=3");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  freeAll();
}

TEST(AntimonyAPI, test_getAntimonyVersionString)
{
  char* version = getVersionStr();
  EXPECT_STREQ(version, LIBANTIMONY_VERSION_STRING);

  freeAll();
}

TEST(AntimonyAPI, test_whatIsMainModel1)
{
  loadString("a=3\nmodel foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "__main");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_whatIsMainModel2)
{
  loadString("a=3\nmodel *foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "foo");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_whatIsMainModel3)
{
  loadString("model foo()\nb=10\nend\na=3");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "__main");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_whatIsMainModel4)
{
  loadString("model foo()\nb=10\nend");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "foo");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_whatIsMainModel5)
{
  loadString("model foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "bar");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_whatIsMainModel6)
{
  loadString("model *foo()\nb=10\nend\nmodel bar()\nc=10\nend");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel *foo()\n\n  // Variable initializations:\n  b = 10;\nend\n\nmodel bar()\n\n  // Variable initializations:\n  c = 10;\nend\n").c_str());
  char* mainname = getMainModuleName();
  EXPECT_STREQ(mainname, "foo");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadAntimonyFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyFileErrNotAntimony)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.xml";

  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret == -1);
  string err = "The file '" + filename + "' is actually an SBML file, and is not in the Antimony format.  Use 'loadFile' or 'loadSBMLFile' to correctly parse it.";
  EXPECT_STREQ(getLastError(), err.c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyFileErrNoFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/does_not_exist.txt";

  long ret = loadAntimonyFile(filename.c_str());
  EXPECT_TRUE(ret == -1);
  string err = "Could not open '" + filename + "', and could not find that file in any known directory.  Please check that this file:\n\t1) exists in directory that antimony is being run from or knows about\n\t2) is read enabled, and\n\t3) is not in use by another program.\n";
  EXPECT_STREQ(getLastError(), err.c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_getStrings)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  loadFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());
  char* sbml = getSBMLString(NULL);
  EXPECT_STREQ(sbml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  sbml = getCompSBMLString(NULL);
  EXPECT_STREQ(sbml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" xmlns:comp=\"http://www.sbml.org/sbml/level3/version1/comp/version1\" level=\"3\" version=\"2\" comp:required=\"true\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  sbml = getSBMLString(NULL);
  EXPECT_STREQ(sbml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_getCellML)
{
  clearPreviousLoads();
  loadString("model *foo()\nb=10\nend\nmodel bar()\nc=10\nend");

#ifndef NCELLML
  //This function crashes for NO REASON.  I use exactly the same 
  char* cellml = getCellMLString(NULL);
  EXPECT_STREQ(cellml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
#endif
  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyString)
{
  loadAntimonyString("a=3");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyStringErrNotAntimony)
{
  long ret = loadAntimonyString("^SLFJNNN___ slk");
  EXPECT_TRUE(ret == -1);
  string err = "Error in model string, line 1:  syntax error, unexpected '^'";
  EXPECT_STREQ(getLastError(), err.c_str());

  freeAll();
  clearPreviousLoads();
}

TEST(AntimonyAPI, test_loadAntimonyStringErrSBML)
{
  long ret = loadAntimonyString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  EXPECT_TRUE(ret == -1);
  string err = "The provided string is actually an SBML model, and is not in the Antimony format.  Use 'loadString' or 'loadSBMLString' to correctly parse it.";
  EXPECT_STREQ(getLastError(), err.c_str());

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.xml";

  loadSBMLFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\n// Other declarations:\nconst a;\n").c_str());

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLFileErrNotSBML)
{
  string dir(TestDataDirectory);
  string filename = dir + "/parameter.txt";

  long ret = loadSBMLFile(filename.c_str());
  EXPECT_TRUE(ret == -1);
  string err_libxml = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (01035 [Error]) Main XML content is empty.\n\n";
  string err_libexpat = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (01006 [Error]) XML content is not well-formed.\n\n";
  char* lasterr = getLastError();
  EXPECT_TRUE(string(lasterr) == err_libxml || string(lasterr) == err_libexpat)
      << "Got: " << lasterr;

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLFileErrNoFile)
{
  string dir(TestDataDirectory);
  string filename = dir + "/doesNotExist.xml";

  loadSBMLFile(filename.c_str());
  char* model = getAntimonyString(NULL);
  string err = "Unable to read SBML file '" + filename + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 1: (00002 [Error]) File unreadable.\n";

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLString)
{
  long ret = loadSBMLString("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model id=\"__main\" name=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" value=\"3\" constant=\"true\"/>\n    </listOfParameters>\n  </model>\n</sbml>\n");
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n\n// Other declarations:\nconst a;\n").c_str());

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLStringErrNotSBML)
{
  long ret = loadSBMLString("^SLFJNNN___ slk");
  EXPECT_TRUE(ret == -1);
  string err_libxml = "Unable to read SBML string due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 2: (01035 [Error]) Main XML content is empty.\n\n";
  string err_libexpat = "Unable to read SBML string due to errors encountered when parsing the file.  Error(s) from libSBML:\n\nline 2: (01006 [Error]) XML content is not well-formed.\n\n";
  char* lasterr = getLastError();
  EXPECT_TRUE(string(lasterr) == err_libxml || string(lasterr) == err_libexpat)
      << "Got: " << lasterr;

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLFileWithLocationAuto)
{
  string dir(TestDataDirectory);
  string filename = dir + "from-libsbml/ext_in_subdir.xml";

  int ret = loadSBMLFile(filename.c_str());
  EXPECT_TRUE(getNumModules() == 3);

  freeAll();
}

TEST(AntimonyAPI, test_loadSBMLStringWithLocation)
{
  string dir = TestDataDirectory;
  dir += "from-libsbml/";
  long ret = loadSBMLStringWithLocation("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
"<!-- The file 'new_aggregate.xml' is actually in the subdirectory 'subdir', so you have to tell the converter to look there, or this model cannot be flattened.-->"
"<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" xmlns:comp=\"http://www.sbml.org/sbml/level3/version1/comp/version1\" level=\"3\" version=\"2\" comp:required=\"true\">"
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
  EXPECT_TRUE(ret != -1);

  EXPECT_TRUE(getNumModules() == 3);

  freeAll();
}

TEST(AntimonyAPI, test_previousLoads)
{
  clearPreviousLoads();
  EXPECT_TRUE(getNumFiles() == 0);

  loadString("a=3");
  loadString("b=3");
  EXPECT_TRUE(getNumFiles() == 2);

  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\nb = 3;\n").c_str());

  revertTo(1);
  model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  revertTo(2);
  model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\nb = 3;\n").c_str());

  clearPreviousLoads();
  freeAll();
}

TEST(AntimonyAPI, test_directories)
{
  addDirectory(TestDataDirectory);
  int ret = loadFile("parameter.txt");
  EXPECT_TRUE(ret != -1);
  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\n// Variable initializations:\na = 3;\n").c_str());

  clearDirectories();
  ret = loadFile("parameter.txt");
  EXPECT_TRUE(ret == -1);

  freeAll();
}
  
//LIB_EXTERN int   writeAntimonyFile(const char* filename, const char* moduleName);
//LIB_EXTERN int   writeSBMLFile(const char* filename, const char* moduleName);
//LIB_EXTERN int   writeCompSBMLFile(const char* filename, const char* moduleName);

TEST(AntimonyAPI, test_checkModule)
{
  int ret = loadString("model foo()\na=3\nend");
  EXPECT_TRUE(ret != -1);
  EXPECT_TRUE(checkModule("foo") == true);
  EXPECT_TRUE(checkModule("bar") == false);
  EXPECT_TRUE(checkModule("__main") == true);

  freeAll();
}

//LIB_EXTERN char*  getWarnings();

TEST(AntimonyAPI, test_SBMLWarnings)
{
  int ret = loadString("const S1");
  EXPECT_TRUE(ret != -1);

  EXPECT_STREQ(getSBMLWarnings(NULL), "As a principle of best modeling practice, the <parameter> should set an initial value rather than be left undefined. Doing so improves the portability of models between different simulation and analysis systems, and helps make it easier to detect potential errors in models.\n The <parameter> with the id 'S1' does not have 'value' attribute, nor is its initial value set by an <initialAssignment> or <assignmentRule>.\n\nDue to the need to instantiate models, modelDefinitions, submodels etc. for the purposes of validation it is problematic to reliably report line numbers when performing validation on models using the Hierarchical Model Composition package.\n\nAs a principle of best modeling practice, the <parameter> should set an initial value rather than be left undefined. Doing so improves the portability of models between different simulation and analysis systems, and helps make it easier to detect potential errors in models.\n The <parameter> with the id 'S1' does not have 'value' attribute, nor is its initial value set by an <initialAssignment> or <assignmentRule>.\n");

  freeAll();
}
  
TEST(AntimonyAPI, test_SBMLInfo)
{
  //As far as I can tell, there are currently zero messages that libsbml classifies as 'info'
  int ret = loadString("a=3");
  EXPECT_TRUE(ret != -1);
  char* sbml = getSBMLString(NULL);

  EXPECT_STREQ(getSBMLInfoMessages(NULL), "");

  freeAll();
}
  
TEST(AntimonyAPI, test_moduleNames)
{
  int ret = loadString("model foo()\na=3\nend\nmodel bar()\nb=4\nend\n");
  EXPECT_TRUE(ret != -1);

  EXPECT_TRUE(getNumModules() == 3);
  char** modname = getModuleNames();
  EXPECT_STREQ(modname[0], "__main");
  EXPECT_STREQ(modname[1], "foo");
  EXPECT_STREQ(modname[2], "bar");
  EXPECT_STREQ(getNthModuleName(0), "__main");
  EXPECT_STREQ(getNthModuleName(1), "foo");
  EXPECT_STREQ(getNthModuleName(2), "bar");
  EXPECT_STREQ(getMainModuleName(), "bar");

  freeAll();
}
  
TEST(AntimonyAPI, test_moduleInterfaceNames)
{
  int ret = loadString("model foo(a, b, c)\na=3\nend");
  EXPECT_TRUE(ret != -1);

  EXPECT_TRUE(getNumSymbolsInInterfaceOf("foo") == 3);
  char** inames = getSymbolNamesInInterfaceOf("foo");
  EXPECT_STREQ(inames[0], "a");
  EXPECT_STREQ(inames[1], "b");
  EXPECT_STREQ(inames[2], "c");
  EXPECT_STREQ(getNthSymbolNameInInterfaceOf("foo", 0), "a");
  EXPECT_STREQ(getNthSymbolNameInInterfaceOf("foo", 1), "b");
  EXPECT_STREQ(getNthSymbolNameInInterfaceOf("foo", 2), "c");
  EXPECT_STREQ(getNthSymbolNameInInterfaceOf("foo", 3), "");

  freeAll();
}
  
TEST(AntimonyAPI, test_replacedSymbols)
{
  int ret = loadString("model foo(a, b, c)\na=3\nend\nmodel bar()\nmod1: foo(A,B,C)\nend\n");
  EXPECT_TRUE(ret != -1);

  EXPECT_TRUE(getNumReplacedSymbolNames("bar") == 3);
  char*** replacedPairs = getAllReplacementSymbolPairs("bar");
  EXPECT_STREQ(replacedPairs[0][0], "mod1_a");
  EXPECT_STREQ(replacedPairs[0][1], "A");
  EXPECT_STREQ(replacedPairs[1][0], "mod1_b");
  EXPECT_STREQ(replacedPairs[1][1], "B");
  EXPECT_STREQ(replacedPairs[2][0], "mod1_c");
  EXPECT_STREQ(replacedPairs[2][1], "C");

  char** replacedPair = getNthReplacementSymbolPair("bar", 0);
  EXPECT_STREQ(replacedPair[0], "mod1_a");
  EXPECT_STREQ(replacedPair[1], "A");

  char* formersymb = getNthFormerSymbolName("bar", 0);
  EXPECT_STREQ(formersymb, "mod1_a");

  char* newsymb = getNthReplacementSymbolName("bar", 0);
  EXPECT_STREQ(newsymb, "A");

  EXPECT_TRUE(getNumReplacedSymbolNamesBetween("bar", "mod1", "") == 3);
  
  replacedPairs = getAllReplacementSymbolPairsBetween("bar", "mod1", "");
  EXPECT_STREQ(replacedPairs[0][0], "a");
  EXPECT_STREQ(replacedPairs[0][1], "A");
  EXPECT_STREQ(replacedPairs[1][0], "b");
  EXPECT_STREQ(replacedPairs[1][1], "B");
  EXPECT_STREQ(replacedPairs[2][0], "c");
  EXPECT_STREQ(replacedPairs[2][1], "C");

  replacedPair = getNthReplacementSymbolPairBetween("bar", "mod1", "", 0);
  EXPECT_STREQ(replacedPair[0], "a");
  EXPECT_STREQ(replacedPair[1], "A");

  formersymb = getNthFormerSymbolNameBetween("bar", "mod1", "", 0);
  EXPECT_STREQ(formersymb, "a");

  newsymb = getNthReplacementSymbolNameBetween("bar", "mod1", "", 0);
  EXPECT_STREQ(newsymb, "A");

  freeAll();
}
  
//The 'printAllDataFor' function tests a lot of other functions implicitly, which is nice.
TEST(AntimonyAPI, test_printAll)
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
  EXPECT_TRUE(ret != -1);

  char* out = printAllDataFor("foo");
  EXPECT_STREQ(out, "All variables for module foo:\n"
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
"_J1: S3 -o J1 ; \n"
"\n"
"Events\n"
"E0: at (time > 2): a=0\n"
"\n");
  freeAll();
}
  

TEST(AntimonyAPI, test_names)
{
  int ret = loadString("a = 3\na is \"name\"\nspecies b = 2\nb is \"species B\"");

  EXPECT_TRUE(getNumSymbolsOfType("__main", allSymbols) == 2);
  char** names = getSymbolDisplayNamesOfType("__main", allSymbols);
  EXPECT_STREQ(names[0], "name");
  EXPECT_STREQ(names[1], "species B");
  names = getSymbolDisplayNamesOfType("__main", allSpecies);
  EXPECT_STREQ(names[0], "species B");
  freeAll();
}

TEST(AntimonyAPI, test_event_modifications)
{
  int ret = loadString("E0: at(x==3): y=2\nE1: at 5 after n==2, priority=10, persistent=false, t0=false, fromTrigger=false: z=3");

  EXPECT_STREQ(getDelayForEvent("__main", 0), "");
  EXPECT_STREQ(getDelayForEvent("__main", 1), "5");
  EXPECT_TRUE(getEventHasDelay("__main", 0) == false);
  EXPECT_TRUE(getEventHasDelay("__main", 1) == true);

  EXPECT_STREQ(getPriorityForEvent("__main", 0), "");
  EXPECT_STREQ(getPriorityForEvent("__main", 1), "10");
  EXPECT_TRUE(getEventHasPriority("__main", 0) == false);
  EXPECT_TRUE(getEventHasPriority("__main", 1) == true);

  EXPECT_TRUE(getPersistenceForEvent("__main", 0) == true);
  EXPECT_TRUE(getPersistenceForEvent("__main", 1) == false);

  EXPECT_TRUE(getT0ForEvent("__main", 0) == true);
  EXPECT_TRUE(getT0ForEvent("__main", 1) == false);

  EXPECT_TRUE(getFromTriggerForEvent("__main", 0) == true);
  EXPECT_TRUE(getFromTriggerForEvent("__main", 1) == false);

  freeAll();
}

TEST(AntimonyAPI, test_addDefaults)
{
  int ret = loadString("model foo(a)\nconst z\nspecies x in C1\nx ->;\nend");
  EXPECT_TRUE(ret != -1);

  char* model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Compartments and Species:\n  compartment C1;\n  species x in C1;\n\n  // Reactions:\n  _J0: x -> ; ;\n\n  // Species initializations:\n  x = ;\n\n  // Compartment initializations:\n  C1 = ;\n\n  // Variable initializations:\n  a = ;\n  z = ;\n\n  // Other declarations:\n  const z;\nend\n").c_str());
  EXPECT_TRUE(addDefaultInitialValues(NULL) == false);
  model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Compartments and Species:\n  compartment C1;\n  species x in C1;\n\n  // Reactions:\n  _J0: x -> ; 0;\n\n  // Species initializations:\n  x = 0;\n\n  // Compartment initializations:\n  C1 = 1;\n\n  // Variable initializations:\n  a = 1;\n  z = 1;\n\n  // Other declarations:\n  const z;\nend\n").c_str());

  ret = loadString("model foo(a)\nend\nA: foo(x)");
  EXPECT_TRUE(ret != -1);

  model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Variable initializations:\n  a = ;\nend\n\n\n// Sub-modules, and any changes to those submodules:\nA: foo(x);\n\n").c_str());
  EXPECT_TRUE(addDefaultInitialValues(NULL) == false);
  model = getAntimonyString(NULL);
  EXPECT_STREQ(model, ((string)"// Created by libAntimony " + LIBANTIMONY_VERSION_STRING + "\nmodel foo(a)\n\n  // Variable initializations:\n  a = ;\nend\n\n\n// Sub-modules, and any changes to those submodules:\nA: foo(x);\n\n// Variable initializations:\nx = 1;\n\n").c_str());

  freeAll();
}

TEST(AntimonyAPI, test_dimensionless)
{
  int ret = loadString("a=3+2");
  EXPECT_TRUE(ret != -1);
  setBareNumbersAreDimensionless(true);

  char* sbml = getSBMLString(NULL);
  EXPECT_STREQ(sbml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<sbml xmlns=\"http://www.sbml.org/sbml/level3/version2/core\" level=\"3\" version=\"2\">\n  <model metaid=\"__main\" id=\"__main\">\n    <listOfParameters>\n      <parameter id=\"a\" constant=\"true\"/>\n    </listOfParameters>\n    <listOfInitialAssignments>\n      <initialAssignment symbol=\"a\">\n        <math xmlns=\"http://www.w3.org/1998/Math/MathML\" xmlns:sbml=\"http://www.sbml.org/sbml/level3/version2/core\">\n          <apply>\n            <plus/>\n            <cn sbml:units=\"dimensionless\" type=\"integer\"> 3 </cn>\n            <cn sbml:units=\"dimensionless\" type=\"integer\"> 2 </cn>\n          </apply>\n        </math>\n      </initialAssignment>\n    </listOfInitialAssignments>\n  </model>\n</sbml>\n");
  setBareNumbersAreDimensionless(false);

  freeAll();
}

 
  
TEST(AntimonyAPI, test_rxns)
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
  EXPECT_TRUE(ret != -1);
  EXPECT_TRUE(getNumReactions("__main") == 4);

  freeAll();
}

 
  
  //LIB_EXTERN void setBareNumbersAreDimensionless(bool dimensionless);

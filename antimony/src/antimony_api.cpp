#include <cassert>
#include <clocale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <string.h>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifndef NCELLML
#include "cellmlx.h"
#endif

#include "antimony_api.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "typex.h"

#define DEFAULTCOMP "default_compartment" //Also defined in module.cpp

using namespace std;
extern int antimony_yyparse();
extern int antimony_yylloc_first_line;

wstring makeUTF16(const string& aStr)
{
  wchar_t* buf = new wchar_t[aStr.size() + 1];
  mbstowcs(buf, aStr.c_str(), aStr.size() + 1);
  wstring s = buf;
  delete [] buf;
  return s;
}

string makeUTF8(const wstring& aStr)
{
  char* buf = new char[aStr.length() * 2 + 1];
  wcstombs(buf, aStr.c_str(), aStr.length() * 2 + 1);
  string s = buf;
  delete [] buf;
  return s;
}

//Useful functions for later routines:
char* getCharStar(const char* orig)
{
  char* ret = strdup(orig);
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstars.push_back(ret);
  return ret;
}

char** getCharStarStar(unsigned long size)
{
  char** ret = (char**) malloc(size*sizeof(char*));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstarstars.push_back(ret);
  return ret;
}

char*** getCharStarStarStar(unsigned long size)
{
  char*** ret = (char***) malloc(size*sizeof(char**));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstarstarstars.push_back(ret);
  return ret;
}

double* getDoubleStar(unsigned long size)
{
  double* ret = (double*) malloc(size*sizeof(double));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_doublestars.push_back(ret);
  return ret;
}

double** getDoubleStarStar(unsigned long size)
{
  double** ret = (double**) malloc(size*sizeof(double*));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_doublestarstars.push_back(ret);
  return ret;
}

rd_type* getRDTypeStar(unsigned long size)
{
  rd_type* ret = (rd_type*) malloc(size*sizeof(rd_type));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_rd_typestars.push_back(ret);
  return ret;
}

unsigned long* getSizeTStar(unsigned long size)
{
  unsigned long* ret = (unsigned long*) malloc(size*sizeof(unsigned long));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_ulongstars.push_back(ret);
  return ret;
}

void reportReactionIndexProblem(unsigned long n, unsigned long actualsize, const char* moduleName, bool reaction=true)
{
  string name = "reaction";
  if (!reaction) {
    name = "interaction";
  }
    
  string error = "There is no " + name + "with index " + SizeTToString(n) + " in module ";
  error += moduleName;
  error += ".";
  if (actualsize == 0) {
    error += "  In fact, there are no " + name + "s at all in that module.";
  }
  else if (actualsize == 1) {
    error += "  There is a single " + name + " with index 0.";
  }
  else if (actualsize > 1) {
    error += "  Valid "+ name + " index values are 0 through " + SizeTToString(actualsize-1) + ".";
  }
  g_registry.SetError(error);
}

void reportReactionSubIndexProblem(unsigned long n, unsigned long actualsize, unsigned long rxnnum, const char* moduleName, bool reaction, bool reactant)
{
  string rxnname = "reaction";
  string reactantname = "reactant";
  if (!reactant) {
    reactantname = "product";
  }
  if (!reaction) {
    rxnname = "interaction";
    reactantname = "interactor";
    if (!reactant) {
      reactantname = "interactee";
    }
  }
  string error = "There is no " + reactantname + "with index " + SizeTToString(n) + " in " + rxnname + SizeTToString(rxnnum) + " in module ";
  error += moduleName;
  error += ".";
  if (actualsize == 0) {
    error += "  In fact, there are no " + reactantname + "s at all in that " + rxnname + ".";
  }
  else if (actualsize == 1) {
    error += "  There is a single " + reactantname + " with index 0.";
  }
  else if (actualsize > 1) {
    error += "  Valid "+ reactantname + " index values are 0 through " + SizeTToString(actualsize-1) + ".";
  }
  g_registry.SetError(error);
}

void reportVariableTypeIndexProblem(unsigned long n, return_type rtype, unsigned long actualsize, const char* moduleName)
{
  if (rtype == allReactions) {
    return reportReactionIndexProblem(n, actualsize, moduleName);
  }
  string error = "There is no variable of type " + ReturnTypeToString(rtype);
  if (actualsize > 0) {
    error += " with index " + SizeTToString(n);
  }
  error += " in module ";
  error +=  moduleName;
  error +=  ".";
  if (actualsize == 1) {
    error += "  There is a single variable of this type with index 0.";
  }
  else if (actualsize > 1) {
    error += "  Valid index values are 0 through " + SizeTToString(actualsize-1) + ".";
  }
  g_registry.SetError(error);
}


//Helper function for below.
long ParseFile(string oldlocale)
{
  int antimony_yyreturn = antimony_yyparse();
  setlocale(LC_ALL, oldlocale.c_str());
  if (antimony_yyreturn != 0) {
    if (g_registry.GetError().size() == 0) {
      assert(false); //Need to fill in the reason why we failed explicitly, if possible.
      if (antimony_yyreturn == 1) {
        g_registry.SetError("Parsing failed because of invalid input.");
      }
      else if (antimony_yyreturn == 2) {
        g_registry.SetError("Parsing failed due to memory exhaution.");
      }
      else {
        g_registry.SetError("Unknown parsing error.");
      }
    }
    string errorp = "Error in ";
    string fname = g_registry.GetLastFile();
    if (fname == "") {
      errorp += "model string";
    }
    else {
      errorp += "file '" + fname + "'";
    }
    errorp += ", line " + SizeTToString(antimony_yylloc_first_line) + ":  ";
    g_registry.AddErrorPrefix(errorp);
    return -1;
  }
  //if (g_registry.FinalizeModules()) return -1;
  return g_registry.SaveModules();
}


//Exported routines:

LIB_EXTERN long loadString(const char* model)
{
  long retval = -1;
#ifndef NSBML
  retval = loadSBMLString(model);
  if (retval != -1) return retval;
#endif
#ifndef NCELLML
  retval = loadCellMLString(model);
  //xmlSetStructuredErrorFunc(NULL, NULL);
  if (retval != -1) return retval;
#endif
  return loadAntimonyString(model);
}

LIB_EXTERN long loadFile(const char* filename)
{
  long retval = -1;
#ifndef NSBML
  retval = loadSBMLFile(filename);
  if (retval != -1) return retval;
#endif
#ifndef NCELLML
  retval = loadCellMLFile(filename);
  if (retval != -1) return retval;
#endif
  return loadAntimonyFile(filename);
}

LIB_EXTERN long loadAntimonyString(const char* model)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  g_registry.ClearModules();
  int ofreturn = g_registry.OpenString(model);
  if (ofreturn==0) return -1; //file read failure
  if (ofreturn==2) {
    //SBML model
    g_registry.SetError("The provided string is actually an SBML model, and is not in the Antimony format.  Use 'loadString' or 'loadSBMLString' to correctly parse it.");
    setlocale(LC_ALL, oldlocale.c_str());
    g_registry.ClearModules();
    return -1;
  }
  assert(ofreturn==1); //antimony file
  return ParseFile(oldlocale);
}

LIB_EXTERN long loadAntimonyFile(const char* filename)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  g_registry.ClearModules();
  int ofreturn = g_registry.OpenFile(filename);
  if (ofreturn==0) return -1; //file read failure
  if (ofreturn==2) {
    //SBML file
    string file(filename);
    g_registry.SetError("The file '" + file + "' is actually an SBML file, and is not in the Antimony format.  Use 'loadFile' or 'loadSBMLFile' to correctly parse it.");
    setlocale(LC_ALL, oldlocale.c_str());
    g_registry.ClearModules();
    return -1;
  }
  assert(ofreturn==1); //antimony file
  return ParseFile(oldlocale);
}

#ifndef NSBML
void LoadSBML(const SBMLDocument* doc)
{
#ifdef USE_COMP
  string mainsbmlname = getNameFromSBMLObject(doc->getModel(), "doc");
  const CompSBMLDocumentPlugin* compdoc = static_cast<const CompSBMLDocumentPlugin*>(doc->getPlugin("comp"));
  if (compdoc!=NULL) {
    int numext = compdoc->getNumExternalModelDefinitions();
    for (int emd=0; emd<numext; emd++) {
      const ExternalModelDefinition* extmoddef = compdoc->getExternalModelDefinition(emd);
      string extid = extmoddef->getId();
      Model* extmod = getModelFromExternalModelDefinition(extmoddef);
      if (extmod == NULL) {
        g_registry.AddWarning("Unable to find model " + extmoddef->getModelRef() + " from the document " + extmoddef->getSource() + ".  The model " + extid + " will be blank.");  
      }
      else {
        g_registry.LoadSubmodelsFrom(extmod);
        if (g_registry.GetModule(extid)==NULL) {
          g_registry.NewCurrentModule(&extid);
          g_registry.CurrentModule()->LoadSBML(extmod);
          g_registry.RevertToPreviousModule();
        }
      }
    }
    int nummodels = compdoc->getNumModelDefinitions();
    for (int md=0; md<nummodels; md++) {
      const ModelDefinition* modeldef = compdoc->getModelDefinition(md);
      g_registry.LoadSubmodelsFrom(modeldef);
      string sbmlname = getNameFromSBMLObject(modeldef, "model");
      if (g_registry.GetModule(sbmlname)==NULL) {
        g_registry.NewCurrentModule(&sbmlname);
        g_registry.CurrentModule()->LoadSBML(modeldef);
        g_registry.RevertToPreviousModule();
      }
    }
  }
  Module* mainmod = g_registry.GetModule(MAINMODULE);
  if (mainsbmlname != MAINMODULE) {
    g_registry.NewCurrentModule(&mainsbmlname);
    mainmod = g_registry.CurrentModule();
  }
  mainmod->LoadSBML(doc->getModel());
  mainmod->SetIsMain(true);
  return;

#else
  string sbmlname = getNameFromSBMLObject(doc->getModel(), "file");
  if (sbmlname != MAINMODULE) {
    g_registry.NewCurrentModule(&sbmlname);
  }
  g_registry.CurrentModule()->LoadSBML(doc->getModel());
#endif
}


long CheckAndAddSBMLDoc(SBMLDocument* document)
{
  g_registry.ClearWarnings();
  document->setConsistencyChecks(LIBSBML_CAT_UNITS_CONSISTENCY, false);
  document->checkConsistency();
  if (document->getErrorLog()->getNumFailsWithSeverity(2) > 0 || document->getErrorLog()->getNumFailsWithSeverity(3) > 0 ) {
    return -1;
  }
  LoadSBML(document);

  g_registry.FinalizeModules();
  return g_registry.SaveModules();
}

LIB_EXTERN long loadSBMLFile(const char* filename)
{
  g_registry.ClearModules();
  SBMLDocument* document = readSBML(filename);
  long retval = CheckAndAddSBMLDoc(document);
  if (retval == -1) {
    stringstream errorstream;
    document->printErrors(errorstream);
    string file(filename);
    g_registry.SetError("Unable to read SBML file '" + file + "' due to errors encountered when parsing the file.  Error(s) from libSBML:\n" +  errorstream.str());
  }
  delete document;
  return retval;
}

LIB_EXTERN long loadSBMLString(const char* model)
{
  return loadSBMLStringWithLocation(model, NULL);
}

LIB_EXTERN long loadSBMLStringWithLocation(const char* model, const char* location)
{
  g_registry.ClearModules();
  SBMLDocument* document = readSBMLFromString(model);
  if (location != NULL) {
    string locURI = "file:";
    locURI += location;
    document->setLocationURI(locURI);
  }
  long retval = CheckAndAddSBMLDoc(document);
  if (retval == -1) {
    stringstream errorstream;
    document->printErrors(errorstream);
    g_registry.SetError("Unable to read SBML string due to errors encountered when parsing the file.  Error(s) from libSBML:\n" +  errorstream.str());
  }
  delete document;
  return retval;
}
#endif

#ifndef NCELLML

long CheckAndAddCellMLDoc(iface::cellml_api::Model* model)
{
  g_registry.ClearWarnings();
  if (g_registry.LoadCellML(model)) return -1;
  g_registry.FinalizeModules();
  return g_registry.SaveModules();
}

LIB_EXTERN long loadCellMLFile(const char* filename)
{
  RETURN_INTO_OBJREF(boot, iface::cellml_api::CellMLBootstrap, CreateCellMLBootstrap());
  RETURN_INTO_OBJREF(ml, iface::cellml_api::DOMModelLoader, boot->modelLoader());
  wstring wideFilename(makeUTF16(filename));

  ObjRef<iface::cellml_api::Model> model;
  try
  {
    model = already_AddRefd<iface::cellml_api::Model>(ml->loadFromURL(wideFilename.c_str()));
  }
  catch (...)
  {
    string file(filename);
    RETURN_INTO_WSTRING(error, ml->lastErrorMessage());
    string emsg(makeUTF8(error));
    g_registry.SetError("Unable to read CellML file '" + file + "' due to errors encountered when parsing the file.  Error(s) from libCellML:\n" +  emsg);
    return -1;
  }
  return CheckAndAddCellMLDoc(model);
}

LIB_EXTERN long loadCellMLString(const char* modelstring)
{
  RETURN_INTO_OBJREF(boot, iface::cellml_api::CellMLBootstrap, CreateCellMLBootstrap());
  RETURN_INTO_OBJREF(ml, iface::cellml_api::DOMModelLoader, boot->modelLoader());
  wstring wideString(makeUTF16(modelstring));

  ObjRef<iface::cellml_api::Model> model;
  try
  {
    model = already_AddRefd<iface::cellml_api::Model>(ml->createFromText(wideString.c_str()));
  }
  catch (...)
  {
    wstring error = ml->lastErrorMessage();
    string emsg(makeUTF8(error));
    g_registry.SetError("Unable to read CellML string due to errors encountered when parsing the file.  Error(s) from libCellML:\n" +  emsg);
  }
  return CheckAndAddCellMLDoc(model);
}

string getCellMLText(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  ObjRef<iface::cellml_api::Model> model = g_registry.GetModule(moduleName)->GetCellMLModel();
  RETURN_INTO_WSTRING(cellmltext, model->serialisedText());
  string cellmlstring = makeUTF8(cellmltext);
  size_t gtpos;
  // XXX - I'd strongly recommend replacing this with code to go through the
  // DOM representation and add text nodes containing newlines instead
  //   -- Andrew Miller.
  // Nah, this is simply for visualization purposes.  If the API ever provides a way to make it look nice, I'll use that.  --LS
  while ((gtpos = cellmlstring.find("><")) != string::npos) {
    cellmlstring.insert(gtpos+1, "\n");
  }
  //LS DEBUG Hack number units!
  gtpos = cellmlstring.find("<model");
  cellmlstring.insert(gtpos+6, " xmlns:cellml=\"http://www.cellml.org/cellml/1.1#\"");
  while ((gtpos = cellmlstring.find("<cn>")) != string::npos) {
    cellmlstring.insert(gtpos+3, " cellml:units=\"dimensionless\"");
  }
  return cellmlstring;
}

LIB_EXTERN int writeCellMLFile(const char* filename, const char* moduleName)
{
  string cellmlstring;
  if (moduleName == NULL) {
    cellmlstring = getCellMLText(g_registry.GetMainModule()->GetModuleName().c_str());
  }
  else if (!checkModule(moduleName)) {
    return 0;
  }
  else {
    cellmlstring = getCellMLText(moduleName);
  }
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  ofstream afile(filename);
  if (!afile.good()) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
    setlocale(LC_ALL, oldlocale.c_str());
    return 0;
  }
  afile << cellmlstring;
  afile.close();
  setlocale(LC_ALL, oldlocale.c_str());
  return 1;
}

LIB_EXTERN char* getCellMLString(const char* moduleName)
{
  string cellmlstring;
  if (moduleName == NULL) {
    cellmlstring = getCellMLText(g_registry.GetMainModule()->GetModuleName().c_str());
  }
  else if (!checkModule(moduleName)) {
    return NULL;
  }
  else {
    cellmlstring = getCellMLText(moduleName);
  }
  return getCharStar(cellmlstring.c_str());
}

#endif

LIB_EXTERN unsigned long getNumFiles()
{
  return g_registry.GetNumFiles();
}

LIB_EXTERN bool revertTo(long index)
{
  return !g_registry.RevertToModuleSet(index);
}

LIB_EXTERN void clearPreviousLoads()
{
  g_registry.ClearAll();
}

LIB_EXTERN void   addDirectory(const char* directory)
{
  g_registry.AddDirectory(directory);
}

LIB_EXTERN void   clearDirectories()
{
  g_registry.ClearDirectories();
}

LIB_EXTERN char* getLastError()
{
  return getCharStar((g_registry.GetError()).c_str());
}

LIB_EXTERN char* getWarnings()
{
  string ret;
  vector<string> warnings = g_registry.GetWarnings();
  if (warnings.size() == 0) return NULL;
  for (size_t warn=0; warn<warnings.size(); warn++) {
    if (warn > 0) {
      ret += "\n";
    }
    ret += warnings[warn];
  }
  return getCharStar(ret.c_str());
}

LIB_EXTERN char** getModuleNames()
{
  unsigned long nummods = getNumModules();
  char** retval = getCharStarStar(nummods);
  if (retval == NULL) return NULL;
  for (unsigned long mod=0; mod<nummods; mod++) {
    retval[mod] = getNthModuleName(mod);
    if (retval[mod] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char*  getNthModuleName(unsigned long n)
{
  unsigned long nummods = g_registry.GetNumModules();
  if (n >= nummods) {
    string error = "There is no module with index " + SizeTToString(n) + ".";
    if (nummods == 1) {
      error += "  There is a single module with index 0.";
    }
    else if (nummods > 1) {
      error += "  Valid module index values are 0 through " + SizeTToString(nummods-1) + ".";
    }
    if (nummods == 0) {
      error += "  In fact, there are no modules at all.  Try running loadModule(filename).";
    }
    g_registry.SetError(error);
    return NULL;
  }
  char* retval = getCharStar(g_registry.GetNthModuleName(n).c_str());
  return retval;
}

LIB_EXTERN char* getMainModuleName()
{
  const Module* mainmod = g_registry.GetMainModule();
  if (mainmod==NULL) return NULL;
  char* retval = getCharStar(mainmod->GetModuleName().c_str());
  return retval;
}

LIB_EXTERN bool checkModule(const char* moduleName)
{
  if (moduleName==NULL) return false;
  if (g_registry.GetModule(moduleName) == NULL) {
    string error = "No such module: '";
    error += moduleName;
    error += "'.  Existing modules: ";
    if (g_registry.GetNumModules()==0) {
      error += "[none]";
    }
    else {
      error += "'" + g_registry.GetNthModuleName(0) + "'";
      for (unsigned long mod=1; mod<g_registry.GetNumModules(); mod++) {
        error += ", '" + g_registry.GetNthModuleName(mod) + "'";
      }
    }
    g_registry.SetError(error);
    return false;
  }
  return true;
}


LIB_EXTERN unsigned long getNumSymbolsInInterfaceOf(const char* moduleName)
{
  if (!checkModule(moduleName)) return 0;
  return g_registry.GetModule(moduleName)->GetNumExportVariables();
}

LIB_EXTERN char** getSymbolNamesInInterfaceOf(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  Module* mod = g_registry.GetModule(moduleName);
  unsigned long intnum = mod->GetNumExportVariables();
  char** names = getCharStarStar(intnum);
  if (names==NULL) return NULL;
  for (unsigned long var=0; var<intnum; var++) {
    names[var] = getNthSymbolNameInInterfaceOf(moduleName, var);
    if (names[var]==NULL) return NULL;
  }
  return names;
}

LIB_EXTERN char* getNthSymbolNameInInterfaceOf(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  return getCharStar(g_registry.GetModule(moduleName)->GetNthExportVariable(n)[0].c_str());
}


LIB_EXTERN unsigned long getNumReplacedSymbolNames(const char* moduleName)
{
  if (!checkModule(moduleName)) return 0;
  return g_registry.GetModule(moduleName)->GetNumSynchronizedVariables();
}

LIB_EXTERN char*** getAllReplacementSymbolPairs(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  vector<pair<string, string> > replacements = g_registry.GetModule(moduleName)->GetAllSynchronizedVariablePairs();
  char*** ret = getCharStarStarStar(replacements.size());
  if (ret==NULL) return NULL;
  for (size_t n=0; n<replacements.size(); n++) {
    char** two = getCharStarStar(2);
    if (two==NULL) return NULL;
    char* former = getCharStar(replacements[n].first.c_str());
    if (former==NULL) return NULL;
    char* latter = getCharStar(replacements[n].second.c_str());
    if (latter==NULL) return NULL;
    two[0] = former;
    two[1] = latter;
    ret[n] = two;
  }
  return ret;
}

LIB_EXTERN char** getNthReplacementSymbolPair(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablePair(n);
  char** ret = getCharStarStar(2);
  if (ret==NULL) return NULL;
  char* former = getCharStar(replacement.first.c_str());
  if (former==NULL) return NULL;
  char* latter = getCharStar(replacement.second.c_str());
  if (latter==NULL) return NULL;
  ret[0] = former;
  ret[1] = latter;
  return ret;
}

LIB_EXTERN char* getNthFormerSymbolName(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablePair(n);
  return getCharStar(replacement.first.c_str());
}

LIB_EXTERN char* getNthReplacementSymbolName(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablePair(n);
  return getCharStar(replacement.second.c_str());
}


LIB_EXTERN unsigned long getNumReplacedSymbolNamesBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName)
{
  if (!checkModule(moduleName)) return 0;
  return g_registry.GetModule(moduleName)->GetSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName).size();
}

LIB_EXTERN char*** getAllReplacementSymbolPairsBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  vector<pair<string, string> > replacements = g_registry.GetModule(moduleName)->GetSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName);
  char*** ret = getCharStarStarStar(replacements.size());
  if (ret==NULL) return NULL;
  for (size_t n=0; n<replacements.size(); n++) {
    char** two = getCharStarStar(2);
    if (two==NULL) return NULL;
    char* former = getCharStar(replacements[n].first.c_str());
    if (former==NULL) return NULL;
    char* latter = getCharStar(replacements[n].second.c_str());
    if (latter==NULL) return NULL;
    two[0] = former;
    two[1] = latter;
    ret[n] = two;
  }
  return ret;
}

LIB_EXTERN char** getNthReplacementSymbolPairBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName, n);
  char** ret = getCharStarStar(2);
  if (ret==NULL) return NULL;
  char* former = getCharStar(replacement.first.c_str());
  if (former==NULL) return NULL;
  char* latter = getCharStar(replacement.second.c_str());
  if (latter==NULL) return NULL;
  ret[0] = former;
  ret[1] = latter;
  return ret;
}

LIB_EXTERN char* getNthFormerSymbolNameBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName, n);
  return getCharStar(replacement.first.c_str());
}

LIB_EXTERN char* getNthReplacementSymbolNameBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName, n);
  return getCharStar(replacement.second.c_str());
}

LIB_EXTERN unsigned long getNumModules()
{
  return g_registry.GetNumModules();
}

LIB_EXTERN unsigned long getNumSymbolsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return 0;
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
}

LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** names = getCharStarStar(vnum);
  if (names == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    names[var] = getNthSymbolNameOfType(moduleName, rtype, var);
    if (names[var] == NULL) return NULL;
  }
  return names;
}

LIB_EXTERN char** getSymbolDisplayNamesOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** names = getCharStarStar(vnum);
  if (names == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    names[var] = getNthSymbolDisplayNameOfType(moduleName, rtype, var);
    if (names[var] == NULL) return NULL;
  }
  return names;
}

LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = getCharStarStar(vnum);
  if (equations == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    equations[var] = getNthSymbolEquationOfType(moduleName, rtype, var);
    if (equations[var]==NULL) return NULL;
  }
  return equations;
}

LIB_EXTERN char** getSymbolInitialAssignmentsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = getCharStarStar(vnum);
  if (equations == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    equations[var] = getNthSymbolInitialAssignmentOfType(moduleName, rtype, var);
    if (equations[var]==NULL) return NULL;
  }
  return equations;
}

LIB_EXTERN char** getSymbolAssignmentRulesOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = getCharStarStar(vnum);
  if (equations == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    equations[var] = getNthSymbolAssignmentRuleOfType(moduleName, rtype, var);
    if (equations[var]==NULL) return NULL;
  }
  return equations;
}

LIB_EXTERN char** getSymbolRateRulesOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = getCharStarStar(vnum);
  if (equations == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    equations[var] = getNthSymbolRateRuleOfType(moduleName, rtype, var);
    if (equations[var]==NULL) return NULL;
  }
  return equations;
}

LIB_EXTERN char** getSymbolCompartmentsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  char** compartments = getCharStarStar(vnum);
  if (compartments == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    compartments[var] = getNthSymbolCompartmentOfType(moduleName, rtype, var);
    if (compartments[var]==NULL) return NULL;
  }
  return compartments;
}

LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
}

LIB_EXTERN char*  getNthSymbolDisplayNameOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetDisplayName().c_str());
}

LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetFormula()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()).c_str());
}

LIB_EXTERN char*  getNthSymbolInitialAssignmentOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetInitialAssignment()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()).c_str());
}

LIB_EXTERN char*  getNthSymbolAssignmentRuleOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetAssignmentRuleOrKineticLaw()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()).c_str());
}

LIB_EXTERN char*  getNthSymbolRateRuleOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetRateRule()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()).c_str());
  //Rate rules don't have ellipses, so the strands don't matter.
}

LIB_EXTERN char*  getNthSymbolCompartmentOfType(const char* moduleName, return_type rtype, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
  if (var==NULL) {
    unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  const Variable* compartment = var->GetCompartment();
  if (compartment == NULL) {
    return getCharStar(DEFAULTCOMP);
  }
  return getCharStar(compartment->GetNameDelimitedBy(g_registry.GetCC()).c_str());
}




LIB_EXTERN unsigned long getNumReactions(const char* moduleName)
{
  if (!checkModule(moduleName)) return 0;
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN unsigned long getNumInteractions(const char* moduleName)
{ 
  if (!checkModule(moduleName)) return 0;
  return getNumSymbolsOfType(moduleName, allInteractions);
}

unsigned long getNumReactOrProdForRxnOrInt(const char* moduleName, unsigned long n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return 0;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  if (n >= getNumSymbolsOfType(moduleName, rtype)) {
    reportReactionIndexProblem(n, getNumSymbolsOfType(moduleName, rtype), moduleName, reaction);    
  }
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
  if (rxn->GetReaction() == NULL) {
    return 0;
  }
  if (reactant) {
    return rxn->GetReaction()->GetLeft()->Size();
  }
  else {
    return rxn->GetReaction()->GetRight()->Size();
  }
}

LIB_EXTERN unsigned long getNumReactants(const char* moduleName, unsigned long n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, true, true);
}

LIB_EXTERN unsigned long getNumProducts(const char* moduleName, unsigned long n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, true, false);
}

LIB_EXTERN unsigned long getNumInteractors(const char* moduleName, unsigned long n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, false, true);
}

LIB_EXTERN unsigned long getNumInteractees(const char* moduleName, unsigned long n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, false, false);
}

char* getNthRxnorIntMthReactantOrProductName(const char* moduleName, unsigned long n, unsigned long m, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return NULL;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
  if (rxn->GetReaction() == NULL) {
    return NULL;
  }
  vector<string> names;
  if (reactant) {
    names = rxn->GetReaction()->GetLeft()->ToStringVecDelimitedBy(g_registry.GetCC());
  }
  else {
    names = rxn->GetReaction()->GetRight()->ToStringVecDelimitedBy(g_registry.GetCC());
  }
  if (m >= names.size()) {
    reportReactionSubIndexProblem(m, names.size(), n, moduleName, reaction, reactant);
    return NULL;
  }
  char* retname = getCharStar(names[m].c_str());
  return retname;
}

char** getNthRxnOrIntReactantOrProductNames(const char* moduleName, unsigned long n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long vnum = getNumReactOrProdForRxnOrInt(moduleName, n, reaction, reactant);
  char** names = getCharStarStar(vnum);
  if (names == NULL) return NULL;
  for (unsigned long var=0; var<vnum; var++) {
    names[var] = getNthRxnorIntMthReactantOrProductName(moduleName, n, var, reaction, reactant);
    if (names[var]==NULL) return NULL;
  }
  return names;
}

char*** getReactantOrProductNamesForRxnOrInt(const char* moduleName, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  char*** allnames = getCharStarStarStar(numlines);
  if (allnames == NULL) return NULL;
  for (unsigned long rxn=0; rxn<numlines; rxn++) {
    char** rxnnames = getNthRxnOrIntReactantOrProductNames(moduleName, rxn, reaction, reactant);
    if (rxnnames == NULL) return NULL;
    allnames[rxn] = rxnnames;
  }
  return allnames;
}

LIB_EXTERN char*** getReactantNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, true, true);
}

LIB_EXTERN char** getNthReactionReactantNames(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, true, true);
}

LIB_EXTERN char*  getNthReactionMthReactantName(const char* moduleName, unsigned long rxn, unsigned long reactant)
{
  return getNthRxnorIntMthReactantOrProductName(moduleName, rxn, reactant, true, true);
}

LIB_EXTERN char*** getProductNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, true, false);
}

LIB_EXTERN char** getNthReactionProductNames(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, true, false);
}

LIB_EXTERN char*  getNthReactionMthProductName(const char* moduleName, unsigned long rxn, unsigned long product)
{
  return getNthRxnorIntMthReactantOrProductName(moduleName, rxn, product, true, false);
}


LIB_EXTERN char*** getInteractorNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, false, true);
}

LIB_EXTERN char** getNthReactionInteractorNames(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, false, true);
}

LIB_EXTERN char* getNthReactionMthInteractorName(const char* moduleName, unsigned long interaction, unsigned long interactor)
{
  return getNthRxnorIntMthReactantOrProductName(moduleName, interaction, interactor, false, true);
}

LIB_EXTERN char*** getInteracteeNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, false, false);
}

LIB_EXTERN char** getNthReactionInteracteeNames(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, false, false);
}

LIB_EXTERN char* getNthReactioniMthInteracteeName(const char* moduleName, unsigned long interaction, unsigned long interactee)
{
  return getNthRxnorIntMthReactantOrProductName(moduleName, interaction, interactee, false, false);
}

double getNthRxnOrIntMthReactantOrProductStoichiometries(const char* moduleName, unsigned long n, unsigned long m, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return 0.0;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return 0.0;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
  if (rxn->GetReaction() == NULL) {
    return 0.0;
  }
  vector<double> stoichiometries;
  if (reactant) {
    stoichiometries = rxn->GetReaction()->GetLeft()->GetStoichiometries();
  }
  else {
    stoichiometries = rxn->GetReaction()->GetRight()->GetStoichiometries();
  }
  if (m >= stoichiometries.size()) {
    reportReactionSubIndexProblem(m, stoichiometries.size(), n, moduleName, reaction, reactant);
    return 0.0;
  }
  return stoichiometries[m];
}

double* getNthRxnOrIntReactantOrProductStoichiometries(const char* moduleName, unsigned long n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return NULL;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
  if (rxn->GetReaction() == NULL) {
    return NULL;
  }
  vector<double> stoichiometries;
  if (reactant) {
    stoichiometries = rxn->GetReaction()->GetLeft()->GetStoichiometries();
  }
  else {
    stoichiometries = rxn->GetReaction()->GetRight()->GetStoichiometries();
  }
  double* retstoichiometries = getDoubleStar(stoichiometries.size());
  for (unsigned long stoichiometry=0; stoichiometry<stoichiometries.size(); stoichiometry++) {
    retstoichiometries[stoichiometry] = stoichiometries[stoichiometry];
  }
  return retstoichiometries;
}

double** getReactantOrProductStoichiometriesForRxnOrInt(const char* moduleName, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  double** allstoichiometries = getDoubleStarStar(numlines);
  if (allstoichiometries == NULL) return NULL;
  for (unsigned long rxn=0; rxn<numlines; rxn++) {
    double* rxnstoichiometries = getNthRxnOrIntReactantOrProductStoichiometries(moduleName, rxn, reaction, reactant);
    if (rxnstoichiometries == NULL) return NULL;
    allstoichiometries[rxn] = rxnstoichiometries;
  }
  return allstoichiometries;
}

LIB_EXTERN double** getReactantStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, true, true);
}

LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, unsigned long rxn)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, rxn, true, true);
}

LIB_EXTERN double getNthReactionMthReactantStoichiometries(const char* moduleName, unsigned long rxn, unsigned long reactant)
{
  return getNthRxnOrIntMthReactantOrProductStoichiometries(moduleName, rxn, reactant, true, true);
}

LIB_EXTERN double** getProductStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, true, false);
}

LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, unsigned long rxn)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, rxn, true, false);
}

LIB_EXTERN double getNthReactionProductStoichiometries(const char* moduleName, unsigned long rxn, unsigned long product)
{
  return getNthRxnOrIntMthReactantOrProductStoichiometries(moduleName, rxn, product, true, false);
}

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long nspecies   = getNumSymbolsOfType(moduleName, varSpecies);
  unsigned long nreactions = getNumSymbolsOfType(moduleName, allReactions);
  double** matrix = getDoubleStarStar(nspecies);
  if (matrix == NULL) return NULL;
  for (unsigned long i=0; i<nspecies; i++) {
    matrix[i] = getDoubleStar(nreactions);
    if (matrix[i] == NULL) return NULL;
  }
  for (unsigned long rxn=0; rxn<nreactions; rxn++) {
    const AntimonyReaction* reaction = g_registry.GetModule(moduleName)->GetNthVariableOfType(allReactions, rxn, false)->GetReaction();
    for (unsigned long sp=0; sp<nspecies; sp++) {
      const Variable* species = g_registry.GetModule(moduleName)->GetNthVariableOfType(varSpecies, sp, false);
      matrix[sp][rxn] = reaction->GetStoichiometryFor(species);
    }
  }
  return matrix;
}

LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, varSpecies);
}

LIB_EXTERN unsigned long   getStoichiometryMatrixNumRows(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, varSpecies);
}

LIB_EXTERN unsigned long   getStoichiometryMatrixNumColumns(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN char** getReactionRates(const char* moduleName)
{
  return getSymbolEquationsOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionRate(const char* moduleName, unsigned long n)
{
  return getNthSymbolEquationOfType(moduleName, allReactions, n);
}

LIB_EXTERN unsigned long getNumReactionRates(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN char** getReactionNames(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionName(const char* moduleName, unsigned long n)
{
  return getNthSymbolNameOfType(moduleName, allReactions, n);
}

LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long numints = g_registry.GetModule(moduleName)->GetNumVariablesOfType(allInteractions, false);
  rd_type* typelist = getRDTypeStar(numints);
  if (typelist == NULL) return NULL;
  for (unsigned long i=0; i<numints; i++) {
    typelist[i] = getNthInteractionDivider(moduleName, i);
  }
  return typelist;
}

LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return rdBecomes;
  unsigned long numlines = getNumSymbolsOfType(moduleName, allInteractions);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, false);
    return rdBecomes;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(allInteractions, n, false)->GetReaction()->GetType();
}

LIB_EXTERN unsigned long getNumEvents(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allEvents);
}

LIB_EXTERN char** getEventNames(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allEvents);
}

LIB_EXTERN char* getNthEventName(const char* moduleName, unsigned long eventno)
{
  return getNthSymbolNameOfType(moduleName, allEvents, eventno);
}

LIB_EXTERN unsigned long getNumAssignmentsForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return 0;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return 0;
  return var->GetEvent()->GetNumAssignments();
}

LIB_EXTERN char* getTriggerForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return NULL;
  string trig = var->GetEvent()->GetTrigger()->ToDelimitedStringWithEllipses(g_registry.GetCC());
  return getCharStar(trig.c_str());
}

LIB_EXTERN char* getDelayForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return NULL;
  string trig = var->GetEvent()->GetDelay()->ToDelimitedStringWithEllipses(g_registry.GetCC());
  return getCharStar(trig.c_str());
}

LIB_EXTERN bool getEventHasDelay(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return false;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return false;
  return (!var->GetEvent()->GetDelay()->IsEmpty());
}

LIB_EXTERN char*   getPriorityForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return NULL;
  string trig = var->GetEvent()->GetPriority()->ToDelimitedStringWithEllipses(g_registry.GetCC());
  return getCharStar(trig.c_str());
}

LIB_EXTERN bool    getEventHasPriority(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return false;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return false;
  return (!var->GetEvent()->GetPriority()->IsEmpty());
}

LIB_EXTERN bool   getPersistenceForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return false;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return false;
  return var->GetEvent()->GetPersistent();
}

LIB_EXTERN bool   getT0ForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return false;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return false;
  return var->GetEvent()->GetInitialValue();
}

LIB_EXTERN bool   getFromTriggerForEvent(const char* moduleName, unsigned long eventno)
{
  if (!checkModule(moduleName)) return false;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return false;
  return var->GetEvent()->GetUseValuesFromTriggerTime();
}

LIB_EXTERN char* getNthAssignmentVariableForEvent(const char* moduleName, unsigned long eventno, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return NULL;
  string asnt = var->GetEvent()->GetNthAssignmentVariableName(n, g_registry.GetCC());
  if (asnt=="") return NULL;
  return getCharStar(asnt.c_str());
}

LIB_EXTERN char* getNthAssignmentEquationForEvent(const char* moduleName, unsigned long eventno, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno, false);
  if (var==NULL) return NULL;
  string formula = var->GetEvent()->GetNthAssignmentFormulaString(n, g_registry.GetCC(), false);
  if (formula=="") return NULL;
  return getCharStar(formula.c_str());
}

LIB_EXTERN unsigned long getNumDNAStrands(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, expandedStrands);
}

LIB_EXTERN unsigned long* getDNAStrandSizes(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long numDNA = getNumDNAStrands(moduleName);
  unsigned long* retval = getSizeTStar(numDNA);
  if (retval == NULL) return NULL;
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, strand, false)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC()).size();
  }
  return retval;
}

LIB_EXTERN unsigned long getSizeOfNthDNAStrand(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return 0;
  unsigned long actualsize = getNumDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no DNA strand with index " + SizeTToString(n);
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid DNA strand index values are 0 through ";
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return 0;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n, false)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC()).size();
}


LIB_EXTERN char*** getDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long numDNA = getNumDNAStrands(moduleName);
  char*** retval = getCharStarStarStar(numDNA);
  if (retval == NULL) return NULL;
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthDNAStrand(moduleName, strand);
    if (retval[strand]==NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char** getNthDNAStrand(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long actualsize = getNumDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no DNA strand with index " + SizeTToString(n);
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid DNA strand index values are 0 through ";
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  vector<string> strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n, false)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC());
  unsigned long dna_length = strand.size();
  char** retval = getCharStarStar(dna_length);
  if (retval == NULL) return NULL;
  for (unsigned long dnabit=0; dnabit<dna_length; dnabit++) {
    retval[dnabit] = getCharStar(strand[dnabit].c_str());;
    if (retval[dnabit] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN bool getIsNthDNAStrandOpen(const char* moduleName, unsigned long n, bool upstream)
{
  const DNAStrand* strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n, false)->GetDNAStrand();
  if (upstream) {
    return strand->GetUpstreamOpen();
  }
  else {
    return strand->GetDownstreamOpen();
  }
}




LIB_EXTERN unsigned long getNumModularDNAStrands(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, modularStrands);
}

LIB_EXTERN unsigned long* getModularDNAStrandSizes(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long numModularDNA = getNumModularDNAStrands(moduleName);
  unsigned long* retval = getSizeTStar(numModularDNA);
  if (retval == NULL) return NULL;
  for (unsigned long strand=0; strand<numModularDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, strand, false)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC()).size();
  }
  return retval;
}

LIB_EXTERN unsigned long getSizeOfNthModularDNAStrand(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return 0;
  unsigned long actualsize = getNumModularDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no Modular DNA strand with index " + SizeTToString(n);
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no Modular DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single Modular DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid Modular DNA strand index values are 0 through ";
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return 0;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n, false)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC()).size();
}

LIB_EXTERN char*** getModularDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long numDNA = getNumModularDNAStrands(moduleName);
  char*** retval = getCharStarStarStar(numDNA);
  if (retval == NULL) return NULL;
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthModularDNAStrand(moduleName, strand);
    if (retval[strand]==NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char** getNthModularDNAStrand(const char* moduleName, unsigned long n)
{
  if (!checkModule(moduleName)) return NULL;
  unsigned long actualsize = getNumModularDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no Modular DNA strand with index " + SizeTToString(n);
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no Modular DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single Modular DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid Modular DNA strand index values are 0 through ";
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  vector<string> strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n, false)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC());
  unsigned long dna_length = strand.size();
  char** retval = getCharStarStar(dna_length);
  if (retval == NULL) return NULL;
  for (unsigned long dnabit=0; dnabit<dna_length; dnabit++) {
    retval[dnabit] = getCharStar(strand[dnabit].c_str());;
    if (retval[dnabit] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN bool getIsNthModularDNAStrandOpen(const char* moduleName, unsigned long n, bool upstream)
{
  const DNAStrand* strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n, false)->GetDNAStrand();
  if (upstream) {
    return strand->GetUpstreamOpen();
  }
  else {
    return strand->GetDownstreamOpen();
  }
}


LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return allUnknown;
  const Variable* var = g_registry.GetModule(moduleName)->GetVariableFromSymbol(symbolName);
  if (var == NULL) {
    return allUnknown;
  }
  var_type vtype = var->GetType();
  bool isconst = var->GetIsConst();
  switch(vtype) {
  case varSpeciesUndef:
    if (isconst) return constSpecies;
    return varSpecies;
  case varFormulaUndef:
    if (isconst) return constFormulas;
    return varFormulas;
  case varDNA:
    return allDNA;
  case varFormulaOperator:
    if (isconst) return constOperators;
    return varOperators;
  case varReactionGene:
    return allGenes;
  case varReactionUndef:
    return allReactions;
  case varInteraction:
    return allInteractions;
  case varUndefined:
    return allUnknown;
  case varModule:
    return subModules;
  case varEvent:
    return allEvents;
  case varCompartment:
    if (isconst) return constCompartments;
    return varCompartments;
  case varStrand:
    return modularStrands;
  case varUnitDefinition:
    return allUnits;
  }
  assert(false); //uncaught var_type
  g_registry.SetError("Coding error:  Didn't include a return type for variable type " + VarTypeToString(vtype) + " in getTypeOfSymbol; antimony_api.cpp.  Email the author to fix.");
  return allUnknown;
}

LIB_EXTERN formula_type getTypeOfEquationForSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return formulaINITIAL;
  const Variable* var = g_registry.GetModule(moduleName)->GetVariableFromSymbol(symbolName);
  if (var == NULL) {
    string error = "No such variable: '";
    error += *symbolName + "'.";
    g_registry.SetError(error);
    return formulaINITIAL;
  }
  return var->GetFormulaType();
}

LIB_EXTERN char* getCompartmentForSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetVariableFromSymbol(symbolName);
  if (var == NULL) return NULL;
  const Variable* varcomp = var->GetCompartment();
  string retval;
  if (varcomp == NULL) {
    retval = DEFAULTCOMP;
  }
  else {
    retval = varcomp->GetNameDelimitedBy(g_registry.GetCC());
  }
  return getCharStar(retval.c_str());
}

LIB_EXTERN int writeAntimonyFile(const char* filename, const char* moduleName)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  string antimony;
  if (moduleName != NULL) {
    if (!checkModule(moduleName)) return 0;
    antimony = g_registry.GetAntimony(moduleName);
  }
  else {
    antimony = g_registry.GetAntimony();
  }
  ofstream afile(filename);
  if (!afile.good()) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
    setlocale(LC_ALL, oldlocale.c_str());
    return 0;
  }
  while (antimony.size()>1 && antimony[0] == '\n') {
    antimony.erase(0, 1);
  }
  string top = "//Created by libAntimony " LIBANTIMONY_VERSION_STRING "\n";
  vector<string> warnings = g_registry.GetWarnings();
  for (size_t warn=0; warn<warnings.size(); warn++) {
    if (warn == 0) {
      top += "\n// Warnings from automatic translation:\n";
    }
    top += "//    " + warnings[warn] + "\n";
  }
  if (warnings.size() > 0) {
    top += "\n";
  }
  afile << top << antimony;
  afile.close();
  setlocale(LC_ALL, oldlocale.c_str());
  return 1;
}

LIB_EXTERN char* getAntimonyString(const char* moduleName)
{
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  string antimony;
  if (moduleName != NULL) {
    if (!checkModule(moduleName)) return 0;
    antimony = g_registry.GetAntimony(moduleName);
  }
  else {
    antimony = g_registry.GetAntimony();
  }
  setlocale(LC_ALL, oldlocale.c_str());
  while (antimony.size()>1 && antimony[0] == '\n') {
    antimony.erase(0, 1);
  }
  string top = "//Created by libAntimony " LIBANTIMONY_VERSION_STRING "\n";
  vector<string> warnings = g_registry.GetWarnings();
  for (size_t warn=0; warn<warnings.size(); warn++) {
    if (warn == 0) {
      top += "\n// Warnings from automatic translation:\n";
    }
    top += "//    " + warnings[warn] + "\n";
  }
  if (warnings.size() > 0) {
    top += "\n";
  }
  return getCharStar(string(top + antimony).c_str());
}

/*
  LIB_EXTERN int writeJarnacFile(const char* filename, const char* moduleName)
  {
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  if (!checkModule(moduleName)) return 0;
  string jarnac = g_registry.GetJarnac(moduleName);
  ofstream jfile(filename);
  if (!jfile.good()) {
  string error = "Unable to open file ";
  error += filename;
  error += " for writing.";
  g_registry.SetError(error);
  setlocale(LC_ALL, oldlocale.c_str());
  return 0;
  }
  jfile << jarnac;
  jfile.close();
  setlocale(LC_ALL, oldlocale.c_str());
  return 1;
  }

  LIB_EXTERN char* getJarnacString(const char* moduleName)
  {
  string oldlocale = setlocale(LC_ALL, NULL);
  setlocale(LC_ALL, "C");
  if (!checkModule(moduleName)) return NULL;
  char* jarnac = getCharStar(g_registry.GetJarnac(moduleName).c_str());
  setlocale(LC_ALL, oldlocale.c_str());
  return jarnac;
  }
*/
#ifndef NSBML
int writeSBMLFileInternal(const char* filename, const char* moduleName, bool comp)
{
  const SBMLDocument* sbmldoc;
  if (moduleName != NULL) {
    if (!checkModule(moduleName)) return 0;
    sbmldoc = g_registry.GetModule(moduleName)->GetSBML(comp);
  }
  else {
    sbmldoc = g_registry.GetMainModule()->GetSBML(comp);
  }
  SBMLWriter sbmlw;
  sbmlw.setProgramName("libAntimony");
  sbmlw.setProgramVersion(LIBANTIMONY_VERSION_STRING);
  int sbmlret = sbmlw.writeSBML(sbmldoc, filename);
  if (sbmlret == 0) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
  }
  return sbmlret;
}

LIB_EXTERN int writeSBMLFile(const char* filename, const char* moduleName)
{
  return writeSBMLFileInternal(filename, moduleName, false);
}

LIB_EXTERN int writeCompSBMLFile(const char* filename, const char* moduleName)
{
  return writeSBMLFileInternal(filename, moduleName, true);
}


char* getSBMLStringInternal(const char* moduleName, bool comp)
{
  const SBMLDocument* sbmldoc;
  if (moduleName != NULL) {
    if (!checkModule(moduleName)) return 0;
    sbmldoc = g_registry.GetModule(moduleName)->GetSBML(comp);
  }
  else {
    sbmldoc = g_registry.GetMainModule()->GetSBML(comp);
  }
  SBMLWriter sbmlw;
  sbmlw.setProgramName("libAntimony");
  sbmlw.setProgramVersion(LIBANTIMONY_VERSION_STRING);
  char* sbmlstring = sbmlw.writeSBMLToString(sbmldoc);
  if (sbmlstring == NULL) {
    string error = "An underlying parser component in libSBML has failed when writing ";
    error += moduleName;
    error += ".";
    g_registry.SetError(error);
    return NULL;
  }
  g_registry.m_charstars.push_back(sbmlstring);
  return sbmlstring;
}

LIB_EXTERN char* getSBMLString(const char* moduleName)
{
  return getSBMLStringInternal(moduleName, false);
}

LIB_EXTERN char* getCompSBMLString(const char* moduleName)
{
  return getSBMLStringInternal(moduleName, true);
}

LIB_EXTERN char* getSBMLInfoMessages(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getCharStar(g_registry.GetModule(moduleName)->GetSBMLInfo().c_str());
}

LIB_EXTERN char* getSBMLWarnings(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getCharStar(g_registry.GetModule(moduleName)->GetSBMLWarnings().c_str());
}
#endif

LIB_EXTERN void freeAll()
{
  g_registry.FreeAll();
}


LIB_EXTERN void printAllDataFor(const char* moduleName)
{
  if (!checkModule(moduleName)) {
    cout << "Couldn't find module: '" << moduleName << "'" << endl;
    return;
  }

  cout << "All variables for module " << moduleName << ":" << endl;
  char **symbolnames = getSymbolNamesOfType(moduleName, allSymbols);
  char **symbolequations = getSymbolEquationsOfType(moduleName, allSymbols);
  char **symbolcompartments = getSymbolCompartmentsOfType(moduleName, allSymbols);
  char **symbolraterules = getSymbolRateRulesOfType(moduleName, allSymbols);
  unsigned long numvars = getNumSymbolsOfType(moduleName, allSymbols);
  for (unsigned long var=0; var<numvars; var++) {
    return_type rtype = getTypeOfSymbol(moduleName, symbolnames[var]);
    formula_type ftype = getTypeOfEquationForSymbol(moduleName, symbolnames[var]);
    cout << symbolnames[var] << "\tType:  " << ReturnTypeToString(rtype) << endl;
    string compartmentname(symbolcompartments[var]);
    if (compartmentname != DEFAULTCOMP) {
      cout << "\tIn compartment: " << compartmentname.c_str() << endl;
    }
    switch(ftype) {
    case formulaINITIAL:
      if (string(symbolequations[var]) != "") {
        cout << "\tInitialization or basic equation : " << symbolequations[var] << endl;
      }
      break;
    case formulaASSIGNMENT:
      if (string(symbolequations[var]) != "" ) {
        cout << "\tAssignment rule: " << symbolequations[var] << endl;
      }
      break;
    case formulaRATE:
      if (string(symbolequations[var]) != "") {
        cout << "\tInitialization: " << symbolequations[var] << endl;
      }
      if (string(symbolraterules[var]) != "") {
        cout << "\tRate rule: " << symbolraterules[var] << endl;
      }
      break;
    case formulaKINETIC:
      if (string(symbolequations[var]) != "") {
        cout << "\tKinetic Law: " << symbolequations[var] << endl;
      }
      break;
    case formulaTRIGGER:
      if (string(symbolequations[var]) != "") {
        cout << "\tEvent Trigger: " << symbolequations[var] << endl;
      }
      break;
    }
  }
  if (getNumDNAStrands(moduleName) > 0) {
    char ***dnanames = getDNAStrands(moduleName);
    const unsigned long *dnanums = getDNAStrandSizes(moduleName);
    cout << endl << "DNA strands:" << endl;
    for (unsigned long strand=0; strand<getNumDNAStrands(moduleName); strand++) {
      cout << getNthSymbolNameOfType(moduleName, expandedStrands, strand) << ": ";
      for (unsigned long element=0; element<dnanums[strand]; element++) {
        if (element != 0 || getIsNthDNAStrandOpen(moduleName, strand, true)) {
          cout << "--";
        }
        cout << dnanames[strand][element];
      }
      if (getIsNthDNAStrandOpen(moduleName, strand, false)) {
        cout << "--";
      }
      cout << endl;
    }
  }

  if (getNumModularDNAStrands(moduleName) > getNumDNAStrands(moduleName))  {
    char ***dnanames = getModularDNAStrands(moduleName);
    const unsigned long *dnanums = getModularDNAStrandSizes(moduleName);
    cout << endl << "Modular DNA strands:" << endl;
    for (unsigned long strand=0; strand<getNumModularDNAStrands(moduleName); strand++) {
      cout << getNthSymbolNameOfType(moduleName, modularStrands, strand) << ": ";
      for (unsigned long element=0; element<dnanums[strand]; element++) {
        if (element != 0 || getIsNthModularDNAStrandOpen(moduleName, strand, true)) {
          cout << "--";
        }
        cout << dnanames[strand][element];
      }
      if (getIsNthModularDNAStrandOpen(moduleName, strand, false)) {
        cout << "--";
      }
      cout << endl;
    }
  }

  cout << endl << "Reactions:" << endl;
  char ***leftrxnnames = getReactantNames(moduleName);
  char ***rightrxnnames = getProductNames(moduleName);
  char **rxnnames = getReactionNames(moduleName);
  char **rxnrates = getReactionRates(moduleName);
  
  double **leftrxnstoichs = getReactantStoichiometries(moduleName);
  double **rightrxnstoichs = getProductStoichiometries(moduleName);

  for (unsigned long rxn=0; rxn<getNumReactions(moduleName); rxn++) {
    cout << rxnnames[rxn] << ": ";
    for (unsigned long var=0; var<getNumReactants(moduleName,rxn); var++) {
      if (var > 0) {
        cout << " + ";
      }
      if (leftrxnstoichs[rxn][var] > 1) {
        char lnum[50];
        sprintf(lnum, "%g", leftrxnstoichs[rxn][var]);
        cout << lnum;
      }
      cout << leftrxnnames[rxn][var];
    }
    cout << " -> ";
    for (unsigned long var=0; var<getNumProducts(moduleName,rxn); var++) {
      if (var > 0) {
        cout << " + ";
      }
      if (rightrxnstoichs[rxn][var] > 1) {
        char rnum[50];
        sprintf(rnum, "%g", rightrxnstoichs[rxn][var]);
        cout << rnum;
      }
      cout << rightrxnnames[rxn][var];
    }
    cout << " ; " << rxnrates[rxn];
    cout << endl;
  }

  cout << "Stoichiometry matrix" << endl;
  double** matrix = getStoichiometryMatrix(moduleName);
  char** columns  = getStoichiometryMatrixColumnLabels(moduleName);
  char** rows     = getStoichiometryMatrixRowLabels(moduleName);
  cout << "\t";
  for (unsigned long col=0; col<getStoichiometryMatrixNumColumns(moduleName); col++) {
    cout << "\t" << columns[col];
  }
  cout << endl;
  for (unsigned long row=0; row<getStoichiometryMatrixNumRows(moduleName); row++) {
    cout << rows[row] << "\t";
    for (unsigned long col=0; col<getStoichiometryMatrixNumColumns(moduleName); col++) {
      cout << "\t" << matrix[row][col];
    }
    cout << endl;
  }
  cout << endl;

  cout << "Reaction rates" << endl;
  for (unsigned long rate=0; rate<getNumReactionRates(moduleName); rate++) {
    cout << rxnrates[rate] << endl;
  }

  if (getNumSymbolsOfType(moduleName, allInteractions) > 0) {
    cout << endl << "Interactions:" << endl;
    char ***leftrxnnames = getInteractorNames(moduleName);
    char ***rightrxnnames = getInteracteeNames(moduleName);
    char **rxnnames = getSymbolNamesOfType(moduleName, allInteractions);
    rd_type *rxndividers = getInteractionDividers(moduleName);  
  
    for (unsigned long rxn=0; rxn<getNumInteractions(moduleName); rxn++) {
      cout << rxnnames[rxn] << ": ";
      for (unsigned long var=0; var<getNumInteractors(moduleName,rxn); var++) {
        if (var > 0) {
          cout << " + ";
        }
        cout << leftrxnnames[rxn][var];
      }
      cout << " " << RDToString(rxndividers[rxn]).c_str() << " ";
      for (unsigned long var=0; var<getNumInteractees(moduleName,rxn); var++) {
        if (var > 0) {
          assert(false); //Should be only one 'interactee' per interaction.
          cout << " + ";
        }
        cout << rightrxnnames[rxn][var];
      }
      cout << " ; " << endl;
    }
  }
  if (getNumEvents(moduleName) > 0) {
    char** eventnames = getEventNames(moduleName);
    
    cout << endl << "Events" << endl;
    for (unsigned long event=0; event<getNumEvents(moduleName); event++) {
      cout << eventnames[event] << ": at ";
      if (getEventHasDelay(moduleName, event)) {
        cout << getDelayForEvent(moduleName, event) << " after ";
      }
      cout << getTriggerForEvent(moduleName, event) << ": ";
      for (unsigned long asnt=0; asnt<getNumAssignmentsForEvent(moduleName, event); asnt++) {
        if (asnt > 0) {
          cout << ", ";
        }
        cout << getNthAssignmentVariableForEvent(moduleName, event, asnt);
        cout << "=";
        cout << getNthAssignmentEquationForEvent(moduleName, event, asnt);
      }
      cout << endl;
    }
  }
  cout << endl;
}

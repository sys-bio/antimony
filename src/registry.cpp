#include <cassert>
#include <vector>
#include <string>
#include <cstdlib>
#include <sys/stat.h>
#include <regex>

#include "formula.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "registry.h"
#include "sbmlx.h"

#include "stringx.h"
#include "variable.h"
#include <sbml/conversion/SBMLConverterRegistry.h>

extern int antimony_yylloc_first_line;
extern int antimony_yylloc_last_line;
extern std::vector<int> antimony_yylloc_last_lines;
#define CONFIGFILE ".antimony";

using namespace std;
using namespace libsbml;

Registry::Registry()
  : m_oldinputs(),
    m_files(),
    m_directories(),
    m_variablenames(),
    m_functions(),
    m_constants(),
    m_storedvars(),
    m_storedformulas(),
    m_modules(),
    m_modulemap(),
    m_currentModules(),
    m_currentReactantLists(),
    m_currentImportedModule(),
    m_workingstrand(),
    m_currentEvent(),
    m_cc("_"),
    m_constness(constDEFAULT),
    m_substonly(false),
    m_error(),
    m_oldmodules(),
    m_olduserfunctions(),
    m_oldmodulemaps(),
    m_sbindex(),
    m_writeNameToSBML(true),
    m_writeTimestampToSBML(false),
    m_bareNumbersAreDimensionless(false),
    m_eof(false),
    m_removeFunctionDefinitions(true),
    input(NULL)
{
  string main = MAINMODULE;
  NewCurrentModule(&main);
  SetupFunctions();
  SetupConstants();
}

Registry::~Registry()
{
  FreeVariables();
  FreeFormulas();
}

void Registry::ClearModules()
{
  while (!SwitchToPreviousFile()) {}
  if (input) {
    //input->close(); //LS DEBUG
    input->clear();
    delete input;
  }
  m_files.clear();
  m_modules.clear();
  m_modulemap.clear();
  m_currentModules.clear();
  m_currentReactantLists.clear();
  m_currentImportedModule.clear();
  m_workingstrand.Clear();
  m_currentEvent.clear();
  m_error.clear();
  m_userfunctions.clear();
  m_userfunctionnames.clear();
  m_sbindex.clear();
  m_isfunction = false;
  string main = MAINMODULE;
  NewCurrentModule(&main);
}

void Registry::FreeVariables()
{
  for (set<Variable*>::iterator var=m_storedvars.begin(); var!=m_storedvars.end(); var++) {
    delete *var;
  }
  m_storedvars.clear();
}

void Registry::FreeFormulas()
{
  for (set<Formula*>::iterator form=m_storedformulas.begin(); form!=m_storedformulas.end(); form++) {
    delete *form;
  }
  m_storedformulas.clear();
}

void Registry::ClearAll()
{
  m_oldmodules.clear();
  m_oldmodulemaps.clear();
  m_olduserfunctions.clear();
  m_warnings.clear();
  FreeVariables();
  FreeFormulas();
  ClearModules();
}

void Registry::AddDirectory(string directory)
{
  if (directory.empty()) return;
  if (directory[directory.size()-1] != '/') {
    directory = directory + "/";
  }
  m_directories.push_back(directory);
  if (m_sbindex.size() > 0) {
    string sbi = directory + "/" + CONFIGFILE;
    if (file_exists(sbi)) {
      AddSBIndex(sbi);
    }
  }
}


vector<string> Registry::GetDirectories()
{
  return m_directories;
}


void Registry::ClearDirectories()
{
  m_directories.clear();
}


//Return values:  1: antimony, unread 2: SBML, read
int Registry::OpenString(string model)
{
  //Try opening as SBML:
  SBMLDocument* document = readSBMLFromString(model.c_str());
  int sbmlcheck = CheckAndAddSBMLIfGood(document);
  delete document;
  if (sbmlcheck==2) return 2;
  if (model.size()==0 || model[model.size()-1] != '\n') {
    model.push_back('\n');
  }
  m_files.push_back("");
  if (input != NULL) {
    m_oldinputs.push_back(input);
  }
  istringstream* inputstring = new istringstream(model);
  antimony_yylloc_last_lines.push_back(antimony_yylloc_last_line);
  antimony_yylloc_last_line = 1;
  antimony_yylloc_first_line = 1;
  input = inputstring;
  return 1;
}

//Return values:  0: failure, 1: antimony, unread 2: SBML, read
int Registry::OpenFile(const string& filename, bool antOnly)
{
  //Find a filename that can be passed to a file input stream that exists.
  ParseSBIndex();
  string thisfilename = "";
  if (m_files.size() > 0) {
    thisfilename = m_files[m_files.size()-1];
  }
  string newname = GetFilenameFrom(thisfilename, filename);
  //If we can't find the file at all, return 0.
  if (newname=="") {
    string error = "Could not open '";
    error += filename;
    error += "', and could not find that file in any known directory.  "
      "Please check that this file:\n" 
      "	1) exists in directory that antimony is being run from or knows about\n"
      "	2) is read enabled, and\n"
      "	3) is not in use by another program.\n";
    SetError(error);
    return 0;
  }

  //Add the directory of this file to our list of known directories, so we
  // can look for other files there, especially .antimony files:
  size_t lastslash = newname.rfind('/');
  if (lastslash != string::npos) {
    string dir = newname;
    dir = dir.replace(lastslash, dir.size()-lastslash, "");
    AddDirectory(dir);
  }

  //Try opening as SBML:
  //if (!antOnly) {
    SBMLDocument* document = readSBML(newname.c_str());
    if (CheckAndAddSBMLIfGood(document)==2) {
      delete document;
      return 2;
    }
    delete document;
  //}

  //If that failed, set up the 'input' member variable so we can parse it as Antimony.
  ifstream* inputfile = new ifstream;
  inputfile->open(newname.c_str(), ios::in);
  if (!inputfile->is_open() || !inputfile->good()) {
    string error = "Input file ";
    error += filename;
    if (newname != filename) {
      error += " was found to map to " + newname + ", which";
    }
    error += " exists, but seemingly cannot be read from.  Check the permissions on the file and try again.  If this still does not work, contact us letting us know how you got this error.";
    SetError(error);
    delete inputfile;
    return 0;
  }
  m_files.push_back(newname);
  if (input != NULL) {
    m_oldinputs.push_back(input);
  }
  input = inputfile;
  antimony_yylloc_last_lines.push_back(antimony_yylloc_last_line);
  antimony_yylloc_last_line = 1;
  antimony_yylloc_first_line = 1;
  return 1;
}

string Registry::GetFilenameFrom(string thisfile, string import)
{
  if (import.empty()) return "";
  string ret = "";
  //First check to see if we've been told about this import from this file in an .antimony file
  ParseSBIndex();
  map<pair<string, string>, string>::iterator result;
  result = m_sbindex.find(make_pair(thisfile, import));
  if (result != m_sbindex.end()) {
    ret = result->second;
    assert(file_exists(ret)); //should have already been checked in ParseSBIndex
    return ret;
  }

  //If it wasn't there, look for it normally.  First, if it's an absolute link, look for it that way.
  // Otherwise, prepend the local directory.
  string reldirectory = thisfile;
  size_t lastslash = reldirectory.rfind('/');
  if (lastslash != string::npos) {
    reldirectory = reldirectory.replace(lastslash, reldirectory.size()-lastslash, "");
  }
  ret = import;
  if (import[0] == '/') {
    ret = reldirectory + import;
  }
  if (file_exists(ret)) return ret;

  //Apparantly that didn't work either.  Try looking in the directories that have been provided:
  for (size_t d=0; d<m_directories.size(); d++) {
    ret = m_directories[d] + "/" + import;
    if (file_exists(ret)) return ret;
  }

  //As a last-ditch effort, try looking for only the file part of 'import' by calling this function again:
  string nodir = import;
  lastslash = nodir.rfind('/');
  if (lastslash != string::npos) {
    nodir = nodir.replace(0, lastslash+1, "");
    return GetFilenameFrom(thisfile, nodir);
  }

  //Nope, 'import' was already only a filename.  Time to give up:
  return "";
}

void Registry::ParseSBIndex()
{
  string sbi = CONFIGFILE;
  if (m_sbindex.size() > 0) return; //Already parsed any sbindexes.
  if (file_exists(sbi)) {
    AddSBIndex(sbi);
  }
  for (size_t d=0; d<m_directories.size(); d++) {
    string dsbi = m_directories[d] + "/" + sbi;
    if (file_exists(dsbi)) {
      AddSBIndex(dsbi);
    }
  }
}

void Registry::AddSBIndex(string sbi)
{
  ifstream inputfile;
  inputfile.open(sbi.c_str(), ios::in);
  if (!inputfile.is_open() || !inputfile.good()) {
    //Can't open/read the file.
    AddWarning("Unable to open and/or read the sbindex file '" + sbi +"', even though it was seen to exist.");
    return;
  }
  string sbidir = sbi;
  size_t lastslash = sbidir.rfind('/');
  if (lastslash != string::npos) {
    sbidir = sbidir.replace(lastslash, sbidir.size()-lastslash, ""); 
  }
  else {
    sbidir = "";
  }
  const int buffsize = 99999;
  char charline[buffsize];
  while (inputfile.good() && !inputfile.eof()) {
    inputfile.getline(charline, buffsize);
    string oneline(charline);
    size_t tabchar = oneline.find('\t');
    vector<string> entries;
    while (tabchar != string::npos) {
      entries.push_back(oneline.substr(0, tabchar));
      oneline = oneline.replace(0, tabchar+1, "");
      tabchar = oneline.find('\t');
    }
    entries.push_back(oneline);
    if (entries.size()==3) {
      //cout << "Found three entries." << endl;
      string requester = entries[0];
      string request   = entries[1];
      string filename  = entries[2];
      if (requester == "<MAIN>") {
        requester = "";
      }
      if (requester.size() > 0 && requester[0] != '/') {
        requester = sbidir + requester;
      }
      if (filename.size() > 0 && filename[0] != '/') {
        filename = sbidir + filename;
      }
      if (file_exists(filename)) {
        m_sbindex.insert(make_pair(make_pair(requester, request), filename));
      }
      //cout << "'" << requester << "', '" << request << "', '" << filename << "'" << endl;
    }
    else if (oneline != ""){
      AddWarning("Incorrectly formatted line in sbindex file '" + sbi + "':  each line is supposed to be three-column tab-delimited");
    }
  }
  //LS DEBUG:
  /*
  cout << "Entries from " << sbi << endl;
  for (map<pair<string, string>, string>::iterator entry=m_sbindex.begin(); entry != m_sbindex.end(); entry++) {
    cout << (*entry).first.first << ", " << (*entry).first.second << ":  " << (*entry).second << endl;
  }
  */
}

bool Registry::file_exists (const string& filename)
{
#ifdef _MSC_VER
#  define stat _stat
#endif

  if (filename.empty()) return 0;
  struct stat buf;
  return stat(filename.c_str(), &buf) == 0;
}

int Registry::CheckAndAddSBMLIfGood(SBMLDocument* document)
{
  //First convert any distrib function definitions from annotation to distrib-style MathML.
  ConvertDistribAnnotation(document);
  document->setConsistencyChecks(LIBSBML_CAT_UNITS_CONSISTENCY, false);
  document->checkConsistency();
  removeBooleanErrors(document);
  SBMLErrorLog* log = document->getErrorLog();
  if (log->getNumFailsWithSeverity(2) == 0 && log->getNumFailsWithSeverity(3) == 0) {
    //It's a valid SBML file. 
    Model* sbml = document->getModel();
    LoadSubmodelsFrom(sbml);
    string sbmlname = getNameFromSBMLObject(sbml, "file");
    if (sbmlname != MAINMODULE) {
      while (NewCurrentModule(&sbmlname)) {
        //Duplicated module name
        sbmlname += "_";
      }
    }
    CurrentModule()->LoadSBML(document->getModel());
    if (sbmlname != MAINMODULE) {
      RevertToPreviousModule();
    }
    return 2;
  }
  return 0;
}

void Registry::LoadSubmodelsFrom(Model* model)
{
  const CompModelPlugin* cmp = static_cast<const CompModelPlugin*>(model->getPlugin("comp"));
  if (cmp==NULL) return;
  //Load any submodels that external model might need.
  for (unsigned int s=0; s<cmp->getNumSubmodels(); s++) {
    const Submodel* submodel = cmp->getSubmodel(s);
    if (LoadModelFrom(submodel->getModelRef(), model->getSBMLDocument())) {
      AddWarning("Unable to load submodel " + submodel->getModelRef() + ".");
    }
  }
}

bool Registry::LoadModelFrom(string modelname, SBMLDocument* document)
{
  if (modelname.empty()) return true;
  if (GetModule(modelname) != NULL) return false; //Already loaded.
  if (document==NULL) return true;
  CompSBMLDocumentPlugin* docplug = static_cast<CompSBMLDocumentPlugin*>(document->getPlugin("comp"));
  if (docplug==NULL) return true;
  SBase* model = docplug->getModel(modelname);
  if (model==NULL) {
    AddWarning("Unable to find model " + modelname + " in the SBML Document.");
    return true;
  }
  Model* mod = NULL;
  const SBMLDocument* modeldoc = document;
  if (model->getTypeCode()==SBML_COMP_EXTERNALMODELDEFINITION) {
    const ExternalModelDefinition* emd = static_cast<const ExternalModelDefinition*>(model);
    mod = getModelFromExternalModelDefinition(emd);
    if (mod==NULL) {
      AddWarning("Unable to load external model " + modelname + ".");
      return true;
    }
  }
  else {
    mod = static_cast<Model*>(model);
  }
  LoadSubmodelsFrom(mod);
  NewCurrentModule(&modelname);
  CurrentModule()->LoadSBML(mod);
  return false;
}

#ifndef NCELLML

#include "cellmlx.h"
#include "libcellml/component.h"
#include "libcellml/model.h"
#include "libcellml/variable.h"

namespace {

//Depth-first walk collecting 'component' and all of its (nested,
//encapsulated) descendants.
void CollectCellMLComponents(const libcellml::ComponentPtr& component, vector<libcellml::ComponentPtr>& all)
{
  all.push_back(component);
  for (size_t i = 0; i < component->componentCount(); i++) {
    CollectCellMLComponents(component->component(i), all);
  }
}

//CellML 'connections' are just variable equivalences in libCellML--unlike
//the old CellML-API code, there's no <connection>/<map_variables> XML
//structure to walk by hand; we just look each equivalent variable up by
//name in the module its owning component became.
void SynchronizeCellMLVariableEquivalences(const libcellml::ComponentPtr& component)
{
  if (component->isImport()) return;
  Module* mod = g_registry.GetModule(CellMLModuleNameFor(component));
  if (mod != NULL) {
    for (size_t v = 0; v < component->variableCount(); v++) {
      libcellml::VariablePtr cmlvar = component->variable(v);
      string varname = cmlvar->name();
      FixName(varname);
      Variable* antvar1 = mod->GetVariable(vector<string>(1, varname));
      if (antvar1 == NULL) continue;

      for (size_t e = 0; e < cmlvar->equivalentVariableCount(); e++) {
        libcellml::VariablePtr othervar = cmlvar->equivalentVariable(e);
        libcellml::ComponentPtr othercomp = std::dynamic_pointer_cast<libcellml::Component>(othervar->parent());
        if (othercomp == nullptr || othercomp->isImport()) continue;
        Module* othermod = g_registry.GetModule(CellMLModuleNameFor(othercomp));
        if (othermod == NULL) continue;
        string othername = othervar->name();
        FixName(othername);
        Variable* antvar2 = othermod->GetVariable(vector<string>(1, othername));
        if (antvar2 == NULL || antvar1 == antvar2) continue;
        if (antvar1->GetIsEquivalentTo(antvar2)) continue;

        if (antvar1->Synchronize(antvar2, NULL)) {
          g_registry.AddWarning("Unable to synchronize the CellML-equivalent variables '" + antvar1->GetNameDelimitedBy(".") + "' and '" + antvar2->GetNameDelimitedBy(".") + "':  " + g_registry.GetError());
        }
      }
    }
  }
  for (size_t c = 0; c < component->componentCount(); c++) {
    SynchronizeCellMLVariableEquivalences(component->component(c));
  }
}

}  // namespace

bool Registry::LoadCellML(const libcellml::ModelPtr& model)
{
  if (model == nullptr) return true;

  size_t numtop = model->componentCount();
  if (numtop == 0) {
    SetError("No components found in this CellML model.");
    return true;
  }

  vector<libcellml::ComponentPtr> top_components;
  vector<libcellml::ComponentPtr> all_components;
  for (size_t i = 0; i < numtop; i++) {
    libcellml::ComponentPtr top = model->component(i);
    top_components.push_back(top);
    CollectCellMLComponents(top, all_components);
  }

  bool anyimports = false;
  for (size_t i = 0; i < all_components.size(); i++) {
    if (all_components[i]->isImport()) anyimports = true;
  }
  if (anyimports) {
    AddWarning("This CellML model uses <import> elements to pull in components from other files.  Antimony does not yet resolve CellML imports, so those components (and anything that depends on them) will be missing from the translation.");
  }

  //First pass:  each (non-imported) component becomes its own Antimony module.
  for (size_t i = 0; i < all_components.size(); i++) {
    libcellml::ComponentPtr component = all_components[i];
    if (component->isImport()) continue;
    string cellmlname = CellMLModuleNameFor(component);
    Module* mod = GetModule(cellmlname);
    if (mod == NULL) {
      while (NewCurrentModule(&cellmlname)) {
        cellmlname += "_";
      }
      CurrentModule()->LoadCellMLComponent(component);
      RevertToPreviousModule();
    }
    //else:  a component with an identical (model, local) name already
    //became a module--treat this as the same component.
  }

  //Second pass:  mirror the encapsulation hierarchy as Antimony submodules.
  for (size_t topnum = 0; topnum < top_components.size(); topnum++) {
    if (top_components[topnum]->isImport()) continue;
    Module* mod = GetModule(CellMLModuleNameFor(top_components[topnum]));
    assert(mod != NULL);
    mod->SetCellMLChildrenAsSubmodules(top_components[topnum]);
  }

  //Now create a master module that contains only the top-level components.
  string modname = model->name();
  if (modname.empty()) modname = "cellml_model";
  FixName(modname);
  modname += "__" MAINMODULE;
  while (NewCurrentModule(&modname, &modname, true)) {
    //Failure - duplicated name
    modname += "_";
  }
  CurrentModule()->LoadCellMLModel(top_components);

  //Finally, synchronize CellML's variable equivalences ('connections').
  for (size_t topnum = 0; topnum < top_components.size(); topnum++) {
    if (top_components[topnum]->isImport()) continue;
    SynchronizeCellMLVariableEquivalences(top_components[topnum]);
  }

  CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  CurrentModule()->SetIsMain(true);

  return false; //success
}

#endif

void Registry::CreateLocalVariablesForSubmodelInterfaceIfNeeded()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    m_modules[mod].CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  }
}


void Registry::SetEOFFlag() {
  m_eof=true;
}


void Registry::ClearEOFFlag() {
  m_eof=false;
}


bool Registry::GetEOFFlag() const {
  return m_eof;
}


bool Registry::SwitchToPreviousFile()
{
  if (!input) return true;
  //input->close(); //LS DEBUG
  input->clear();
  delete input;
  if (m_oldinputs.size() == 0) {
    input = NULL;
    return true;
  }
  input = m_oldinputs.back();
  m_oldinputs.pop_back();
  m_files.pop_back();
  return false;
}

void Registry::SetupFunctions()
{
  //This list straight from sbml's L3Parser (which I also wrote).
  const char* functions[] = {
  "abs"
  , "acos"
  , "arccos"
  , "acosh"
  , "arccosh"
  , "acot"
  , "arccot"
  , "acoth"
  , "arccoth"
  , "acsc"
  , "arccsc"
  , "acsch"
  , "arccsch"
  , "asec"
  , "arcsec"
  , "asech"
  , "arcsech"
  , "asin"
  , "arcsin"
  , "arcsinh"
  , "atan"
  , "arctan"
  , "atanh"
  , "arctanh"
  , "ceil"
  , "ceiling"
  , "cos"
  , "cosh"
  , "cot"
  , "coth"
  , "csc"
  , "csch"
  , "delay"
  , "exp"
  , "factorial"
  , "floor"
  , "log"
  , "ln"
  , "log10"
  , "piecewise"
  , "power"
  , "pow"
  , "sqr"
  , "sqrt"
  , "rateOf"
  , "root"
  , "sec"
  , "sech"
  , "sin"
  , "sinh"
  , "tan"
  , "tanh"
  , "and"
  , "not"
  , "or"
  , "xor"
  , "eq"
  , "equals"
  , "geq"
  , "gt"
  , "leq"
  , "lt"
  , "neq"
  , "divide"
  , "minus"
  , "plus"
  , "times"
  , "quotient"
  , "max"
  , "min"
  , "rem"
  , "implies"
  , "normal"
  , "truncatedNormal"
  , "uniform"
  , "exponential"
  , "truncatedExponential"
  , "gamma"
  , "truncatedGamma"
  , "poisson"
  , "truncatedPoisson"
  , "bernoulli"
  , "binomial"
  , "cauchy"
  , "chisquare"
  , "laplace"
  , "lognormal"
  , "rayleigh"
  };
  for (size_t func=0; func<88; func++) {
    m_functions.push_back(functions[func]);
  }
}

void Registry::SetupConstants()
{
  //This list straight from sbml's L3Parser (which I also wrote).
  const char* constants[] = {
  "true"
  , "True"
  , "TRUE"
  , "false"
  , "False"
  , "FALSE"
  , "pi"
  , "exponentiale"
  , "avogadro"
  , "time"
  , "inf"
  , "INF"
  , "infinity"
  , "NaN"
  , "nan"
  , "NAN"
  , "notanumber"
  };
  for (size_t c=0; c<17; c++) {
    m_constants.push_back(constants[c]);
  }
}

bool Registry::NewCurrentModule(const string* name, const string* displayname, bool ismain)
{
  string localname(*name);
  m_currentModules.push_back(localname);
  //Check to make sure no existing module exist with this name
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetModuleName() == localname) {
      //assert(false); //Parsing disallows this condition, but translation allows it (though it's still an Antimony error).
      //cout << "duplicated name: " << localname << endl;
      SetError("Programming error:  Unable to create new module with the same name as an existing module (\"" + localname + "\").");
      m_currentModules.pop_back();
      return true;
    }
    if (ismain && m_modules[mod].GetIsMain()) {
      string warn = "Warning: changing main module for this file to be " + *name + " instead of '" + m_modules[mod].GetModuleName() + "'.";
      AddWarning(warn);
      m_modules[mod].SetIsMain(false);
    }
  }
  //Otherwise, create a new module with that name
  m_modules.push_back(Module(localname));
  m_modules[m_modules.size()-1].SetIsMain(ismain);
  if (displayname)
    m_modules[m_modules.size()-1].SetDisplayName(*displayname);
  m_modulemap.insert(make_pair(*name, m_modules.size()-1));
  return false;
}

Module* Registry::CurrentModule()
{
  assert (m_currentModules.size() > 0);
  return GetModule(m_currentModules.back());
}

string Registry::CurrentModuleName()
{
    assert(m_currentModules.size() > 0);
    return m_currentModules.back();
}

bool Registry::SetCurrentModuleIf(const string* modname, const string* annotation)
{
    if (*annotation != "annotate") {
        g_registry.SetError("Invalid syntax: '" + *annotation + " " + *modname + "'.  If you are trying to annotate a model, try 'annotate " + *modname + "'.");
        return true;
    }
    m_currentModules.push_back(*modname);
    return false;
}

void Registry::RevertToPreviousModule()
{
  m_currentModules.pop_back();
  assert(m_currentModules.size() > 0);
}

bool Registry::AddVariableToCurrentExportList(Variable* export_var)
{
  if (m_isfunction) {
    return m_userfunctions.back().AddVariableToExportList(export_var);
  }
  return CurrentModule()->AddVariableToExportList(export_var);
}

void Registry::NewUserFunction(const string* name)
{
  m_isfunction = true;
  UserFunction newfunc(*name);
  m_userfunctionnames.push_back(*name);
  m_userfunctions.push_back(newfunc);
}

bool Registry::SetUserFunction(Formula* formula)
{
  m_isfunction = false;
  return m_userfunctions.back().SetFormula(*formula);
}

bool Registry::AddVariableToCurrentImportList(Variable* import_var)
{
  Module* submod = CurrentModule()->GetVariable(m_currentImportedModule)->GetModule();
  Variable* var = submod->GetNextExportVariable();
  if (var == NULL) {
    string error = "Unable to add variable '" + import_var->GetNameDelimitedBy(GetCC()) + "' when creating an instance of the module '" + submod->GetModuleName() + "' because this module is defined to have only " + SizeTToString(submod->GetNumExportVariables()) + " variable(s) definable by default in its construction.";
    SetError(error);
    return true;
  }
  var->Synchronize(import_var, NULL);
  return false;
}

bool Registry::AddNumberToCurrentImportList(double val)
{
  Module* submod = CurrentModule()->GetVariable(m_currentImportedModule)->GetModule();
  Variable* var = submod->GetNextExportVariable();
  if (var == NULL) {
    string error = "Unable to add the number '" + DoubleToString(val) + "' + to the argument list when creating an instance of the module '" + submod->GetModuleName() + "' because this module is defined to have only " + SizeTToString(submod->GetNumExportVariables()) + " variable(s) definable by default in its construction.";
    SetError(error);
    return true;
  }
  Variable* import_var = CurrentModule()->AddNewNumberedVariable("_ant");
  Formula form;
  form.AddNum(val);
  import_var->SetFormula(&form);
  var->Synchronize(import_var, NULL);
  return false;
}

Variable* Registry::AddVariableToCurrent(const string* name)
{
  //if (name && *name == "sboTerm") {
  //  // JKM setting the sboTerm for the enclosing module or function
  //  return CurrentModule()->GetSBOTermWrapper();
  //}
  if (m_isfunction) {
    return m_userfunctions.back().AddOrFindVariable(name);
  }
  return CurrentModule()->AddOrFindVariable(name);
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula, int type)
{
  ReactantList blank;
  Variable* retval = NULL;
  if (type == 0)
  {
    retval = CurrentModule()->AddNewReaction(m_currentReactantLists[0], divider, m_currentReactantLists[1], formula);
  }
  else if (type == 1)
  {
    retval = CurrentModule()->AddNewReaction(m_currentReactantLists[0], divider, blank, formula);
  }
  else if (type == 2)
  {
    retval = CurrentModule()->AddNewReaction(blank, divider, m_currentReactantLists[0], formula);
  }
  m_currentReactantLists.clear();
  return retval;
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula, Variable* var, int type)
{
  ReactantList blank;
  Variable* retval = NULL;
  if (type == 0)
  {
    retval = CurrentModule()->AddNewReaction( m_currentReactantLists[0], divider,  m_currentReactantLists[1], formula, var);
  }
  else if (type == 1)
  {
    retval = CurrentModule()->AddNewReaction( m_currentReactantLists[0], divider,  blank, formula, var);
  }
  else if (type == 2)
  {
    retval = CurrentModule()->AddNewReaction( blank, divider,  m_currentReactantLists[0], formula, var);
  }
  else
  {
    assert(false); //Should only be three options.
  }
  m_currentReactantLists.clear();
  return retval;
}

ReactantList* Registry::NewBlankReactantList()
{
  ReactantList rlist;
  m_currentReactantLists.push_back(rlist);
  return &(m_currentReactantLists.back());
}

bool Registry::SetStrandAs(Variable* var)
{
  if (var->SetDNAStrand(m_workingstrand)) return true;
  vector<Variable*> vars = m_workingstrand.GetVariables();
  for (size_t vnum=0; vnum<vars.size(); vnum++) {
    if (vars[vnum]->SetIsInStrand(var)) return true;
  }
  m_workingstrand.Clear();
  return false;
}

bool Registry::SaveWorkingStrand()
{
  Variable* var = CurrentModule()->AddNewNumberedVariable("_dna");
  return SetStrandAs(var);
}

bool Registry::SetNewUpstreamOpen(Variable* var)
{
  m_workingstrand.Clear();
  m_workingstrand.SetUpstream(true);
  return m_workingstrand.SetUpstream(var);
}

void Registry::SetOpenUpstream()
{
  m_workingstrand.SetUpstream(true);
}

bool Registry::SetDownstreamEnd(Variable* var)
{
  m_workingstrand.SetDownstream(false);
  return m_workingstrand.SetDownstream(var);
}

bool Registry::SetNewDownstreamOpen(Variable* var)
{
  m_workingstrand.Clear();
  m_workingstrand.SetDownstream(true);
  return m_workingstrand.SetUpstream(var);
}

bool Registry::SetDownstreamOpen(Variable* var)
{
  m_workingstrand.SetDownstream(true);
  return m_workingstrand.SetDownstream(var);
}


bool Registry::SetNewCurrentEvent(Formula* trigger)
{
  Variable* evar = CurrentModule()->AddNewNumberedVariable("_E");
  return SetNewCurrentEvent(trigger, evar);
}

bool Registry::SetNewCurrentEvent(Formula* delay, Formula* trigger)
{
  Variable* evar = CurrentModule()->AddNewNumberedVariable("_E");
  return SetNewCurrentEvent(delay, trigger, evar);
}

bool Registry::SetNewCurrentEvent(Formula* trigger, Variable* var)
{
  m_currentEvent = var->GetName();
  string formstring = trigger->ToSBMLString();
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      char* l3err = SBML_getLastParseL3Error();
      g_registry.SetError("In event trigger \"" + trigger->ToDelimitedStringWithEllipses(".") + "\":  " + l3err);
      free(l3err);
      return true;
    }
    //else if (!ASTform->isBoolean() && !ASTform->isFunction()) {
    //  g_registry.SetError("The formula \"" + trigger->ToDelimitedStringWithEllipses(".") + "\" cannot be parsed in a boolean context, and it is therefore illegal to use it as the trigger for an event.  (Perhaps try adding parentheses?)");
    //  delete ASTform;
    //  return true;
    //}
    delete ASTform;
  }
  Formula delay;
  AntimonyEvent event(delay, *trigger, var);
  return var->SetEvent(&event);
}

bool Registry::SetNewCurrentEvent(Formula* delay, Formula* trigger, Variable* var)
{
  m_currentEvent = var->GetName();
  AntimonyEvent event(*delay, *trigger, var);
  return var->SetEvent(&event);
}

AntimonyEvent* Registry::GetCurrentEvent() {
  return CurrentModule()->GetVariable(m_currentEvent)->GetEvent();
}

bool Registry::AddNewAlgebraicRuleToCurrent(double val, Formula* formula)
{
    return CurrentModule()->AddNewAlgebraicRule(val, formula);
}

Variable* Registry::GetCurrentSubmodel()
{
  return CurrentModule()->GetVariable(m_currentImportedModule);
}

void Registry::AddWarning(std::string warning)
{
    for (size_t w = 0; w < m_warnings.size(); w++) {
        if (m_warnings[w] == warning) {
            return;
        }
    }
    m_warnings.push_back(warning);
}

Formula* Registry::NewBlankFormula()
{
  Formula* form = new Formula();
  m_storedformulas.insert(form);
  return form;
}

string Registry::GetLastFile()
{
  if (m_files.size()) return m_files.back();
  assert(false); //Should only be called when parsing.
  return "";
}

Module* Registry::GetModule(string modulename)
{
  map<string, size_t>::iterator found = m_modulemap.find(modulename);
  if (found != m_modulemap.end()) {
    return &(m_modules[found->second]);
  }
  //We don't store the user functions in a hash because there usually aren't that many of them.
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
      return &(m_userfunctions[uf]);
    }
  }
  //In case we missed adding it to the hash:
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      //assert(false);
      m_modulemap.insert(make_pair(modulename, mod));
      return &(m_modules[mod]);
    }
  }
  return NULL;
}

const Module* Registry::GetMainModule() const
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetIsMain()) {
      return &(m_modules[mod]);
    }
  }
  //If there's no 'main' module, return "__main" if there's anything in it, or the last one in the list.
  if (m_modules.size() == 0) return NULL;
  if (m_modules[0].GetNumVariablesOfType(allSymbols, true) > 0) {
    return &(m_modules[0]);
  }
  return &(m_modules[m_modules.size()-1]);
}

Module* Registry::GetMainModule()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetIsMain()) {
      return &(m_modules[mod]);
    }
  }
  //If there's no 'main' module, return "__main" if there's anything in it, or the last one in the list.
  if (m_modules.size() == 0) return NULL;
  if (m_modules[0].GetNumVariablesOfType(allSymbols, true) > 0) {
    return &(m_modules[0]);
  }
  return &(m_modules[m_modules.size()-1]);
}

const Module* Registry::GetModule(string modulename) const
{
  map<string, size_t>::const_iterator found = m_modulemap.find(modulename);
  if (found != m_modulemap.end()) {
    return &(m_modules[found->second]);
  }
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      assert(false);
      return &(m_modules[mod]);
    }
  }
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
      assert(false);
      return &(m_userfunctions[uf]);
    }
  }
  return NULL;
}

bool Registry::IsModuleName(string word)
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (word == m_modules[mod].GetModuleName()) {
      return true;
    }
  }
  return false;
}

const string*  Registry::AddWord(string word)
{
  pair<set<string>::iterator,bool> ret;

  ret = m_variablenames.insert(word);
  set<string>::iterator wordit = ret.first;
  return &(*wordit);
}

void Registry::StoreVariable(Variable* var)
{
  m_storedvars.insert(var);
}

const string* Registry::IsFunction(string word)
{
  for (size_t func=0; func<m_functions.size(); func++) {
    if (word == m_functions[func]) {
      return &(m_functions[func]);
    }
  }
  for (size_t uf=0; uf<m_userfunctionnames.size(); uf++) {
    if (word == m_userfunctionnames[uf]) {
      return &(m_userfunctionnames[uf]);
    }
  }
  return NULL;
}

const string* Registry::IsConstant(string word)
{
  for (size_t c=0; c<m_constants.size(); c++) {
    if (CaselessStrCmp(false, word, m_constants[c])) {
      return &(m_constants[c]);
    }
  }
  return NULL;
}

string Registry::GetAntimony(bool enableAnnotations) const
{
  string retval;
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    retval += m_userfunctions[uf].GetAntimony(enableAnnotations) + "\n";
  }
  set<const Module*> mods;
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if ((mods.insert(&m_modules[mod])).second) {
      //New module; add it.
      retval += m_modules[mod].GetAntimony(mods, true, enableAnnotations);
      if (mod <m_modules.size()-1) {
        retval += "\n";
      }
    }
  }
  return retval;
}

string Registry::GetAntimony(string modulename, bool enableAnnotations) const
{
  const Module* amod = GetModule(modulename);
  if (amod == NULL) return "";
  set<const Module*> nomods;
  return amod->GetAntimony(nomods, false, enableAnnotations);
}

string Registry::GetJarnac(string modulename) const
{
  const Module* jmod = GetModule(modulename);
  if (jmod == NULL) return "";
  string jarnac = modulename + " = define model\n";
  jarnac += jmod->GetJarnacReactions();
  jarnac += "\n";
  jarnac += jmod->GetJarnacVarFormulas();
  jarnac += "\nend\n\n";
  jarnac += jmod->GetJarnacConstFormulas(modulename);
  return jarnac;
}

bool Registry::FinalizeModules()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].Finalize()) return true;
  }
  return false;
}


size_t Registry::GetNumModules()
{
  return m_modules.size();
}

string Registry::GetNthModuleName(size_t n)
{
  if (n>=m_modules.size()) {
    assert(false); //Shouldn't get here; wrong user calls caught earlier.
    g_registry.SetError("Programming error:  no such module " + SizeTToString(n) + ".");
    return NULL;
  }
  return m_modules[n].GetModuleName();
}

size_t Registry::SaveModules()
{
  m_oldmodules.push_back(m_modules);
  m_olduserfunctions.push_back(m_userfunctions);
  m_oldmodulemaps.push_back(m_modulemap);
  m_isfunction = false;
  return m_oldmodules.size();
}

bool Registry::RevertToModuleSet(long n)
{
  assert(m_oldmodules.size() == m_olduserfunctions.size());
  if (n == -1) {
    g_registry.SetError("An error occurred when reading that file.  Any modules in it are unavailable.");
    return true;
  }
  if (n<=0 || n>static_cast<long>(m_oldmodules.size())) {
    string error = "No such file handle.  ";
    if (m_oldmodules.size()==0) {
      error += "No files have been successfully read.";
    }
    else if (m_oldmodules.size()==1) {
      error += "Exactly one file has been successfully read, with file handle 1.";
    }
    else {
      error += "Valid file handles are 1 through " + SizeTToString(m_oldmodules.size());
    }
    g_registry.SetError(error);
    return true;
  }
  m_modules.clear(); //LS NOTE:  needed because otherwise we leak models!  Yes, this is weird.
  m_userfunctions.clear();
  m_modules = m_oldmodules[n-1];
  m_modulemap = m_oldmodulemaps[n-1];
  m_userfunctions = m_olduserfunctions[n-1];
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].Finalize()) return true;
  }
  m_userfunctionnames.clear();
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    m_userfunctionnames.push_back(m_userfunctions[uf].GetModuleName());
  }
  m_isfunction = false;
  return false;
}

const UserFunction* Registry::GetNthUserFunction(size_t n) const
{
  if (m_userfunctions.size() <= n) return NULL;
  return &(m_userfunctions[n]);
}

UserFunction* Registry::GetNthUserFunction(size_t n)
{
  if (m_userfunctions.size() <= n) return NULL;
  return &(m_userfunctions[n]);
}

UserFunction* Registry::GetUserFunction(string word)
{
  for (size_t func=0; func<m_userfunctionnames.size(); func++) {
    if (word == m_userfunctionnames[func]) {
      return &(m_userfunctions[func]);
    }
  }
  return NULL;
}

void Registry::FixTimeInFunctions()
{
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (m_userfunctions[uf].ChangeTimeToRef()) {
      for (size_t mod=0; mod<m_modules.size(); mod++) {
        m_modules[mod].AddTimeToUserFunction(m_userfunctions[uf].GetModuleName());
      }
    }
  }
}

void Registry::SetRemoveFunctionDefinitions(bool removeFunctionDefinitions)
{
    m_removeFunctionDefinitions = removeFunctionDefinitions;
}

bool Registry::GetRemoveFunctionDefinitions()
{
    return m_removeFunctionDefinitions;
}

bool Registry::ProcessGlobalCVTerm(const string* name, const string* qual, const vector<string>& resources)
{
  if (name && qual) {
    Module* module = GetModule(*name);
    if (!module) {
      stringstream ss;
      ss << "Cannot find module for \"" << *name << "\"";
      SetError(ss.str());
      return true;
    }
    // get element for name
    // qual can be a model or biology qualifier
    // is/identity is used by both - give priority to biology
    // to eliminate guesswork explicitly use one of:
    //   var_name model_entity_is     "resource"
    //   var_name biologcal_entity_is "resource"
    BiolQualifierType_t bq = module->DecodeBiolQualifier(*qual);
    ModelQualifierType_t mq = module->DecodeModelQualifier(*qual);
    int creator_number = 0;
    string creator_substr = "";
    if (bq != BQB_UNKNOWN) {
        module->AppendBiolQualifiers(bq, resources);
    }
    else if (mq != BQM_UNKNOWN) {
        module->AppendModelQualifiers(mq, resources);
    }
    else if (CaselessStrCmp(true, *qual, "notes")) {
        module->AppendNotes(resources);
    }
    else if (CaselessStrCmp(true, *qual, "created")) {
        if (resources.size() > 1) {
            g_registry.SetError("Cannot set multiple 'created' dates.");
            return true;
        }
        bool ret = module->SetCreated(resources[0]);
        if (ret) {
            g_registry.SetError("Invalid date format '" + resources[0] + "': the format must match 'YYYY-MM-DDThh:mm:ssTZD' where TZD is either Z or +/ -HH:MM");
            return true;
        }
    }
    else if (CaselessStrCmp(true, *qual, "modified")) {
        module->AppendModified(resources);
    }
    else {
        stringstream ss;
        ss << "Unrecognized qualifier \"" << *qual << "\"";
        g_registry.SetError(ss.str());
        return true;
    }
    module->TransferAnnotationToModel(module->GetModelIfCreated());
    return false;
  } 
  else {
    SetError("Global CV qualifier encountered but not enough arguments - pass qualifier and at least one resource");
    return true;
  }
}

bool Registry::ProcessCreatorTerm(Annotated* a, const string* creator, const string* cterm, double resource)
{
    if (abs(resource - round(resource)) > 0.000001) {
        stringstream err;
        err << "Unable to use " << resource << " as a creator term resource; only non-decimal numbers are allowed.";
        g_registry.SetError(err.str());
        return true;
    }
    string val = to_string(round(resource));
    vector<string> vals;
    vals.push_back(val);
    return ProcessCreatorTerm(a, creator, cterm, vals);
}

bool Registry::ProcessCreatorTerm(Annotated* a, const string* creator, const string* cterm, const vector<string>& resources)
{
    unsigned int creator_number = 0;

    if (*creator == "created") {
        if (resources.size() > 1) {
            SetError("Unable to set multiple date elements at once.");
            return true;
        }
        a->SetCreated(*cterm, resources[0]);
        return false;
    }
    if (*creator == "modified") {
        if (resources.size() > 1) {
            SetError("Unable to set multiple date elements at once.");
            return true;
        }
        a->ResetLastModified(*cterm, resources[0]);
        return false;
    }
    if (CheckCreatorString(*creator, creator_number)) {
        return true;
    }
    if (a->addCreatorInfo(creator_number, *cterm, resources)) {
        return true;
    }
    return false;
}

bool Registry::ProcessGlobalCreatorTerm(const string* name, const string* creator, const string* cterm, double resource)
{
    if (abs(resource - round(resource)) > 0.000001) {
        stringstream err;
        err << "Unable to use " << resource << " as a creator term resource; only non-decimal numbers are allowed.";
        g_registry.SetError(err.str());
        return true;
    }
    string val = to_string(round(resource));
    vector<string> vals;
    vals.push_back(val);
    return ProcessGlobalCreatorTerm(name, creator, cterm, vals);
}

bool Registry::ProcessGlobalCreatorTerm(const string* name, const string* creator, const string* cterm, const vector<string>& resources)
{
    if (name) {
        Module* module = GetModule(*name);
        if (!module) {
            stringstream ss;
            ss << "Cannot find module for \"" << *name << "\"";
            SetError(ss.str());
            return true;
        }
        unsigned int creator_number = 0;
        if (*creator == "created") {
            if (resources.size() > 1) {
                SetError("Unable to set multiple date elements at once.");
                return true;
            }
            module->SetCreated(*cterm, resources[0]);
        }
        else if (*creator == "modified") {
            if (resources.size() > 1) {
                SetError("Unable to set multiple date elements at once.");
                return true;
            }
            module->ResetLastModified(*cterm, resources[0]);
        }
        else if (CheckCreatorString(*creator, creator_number)) {
            return true;
        }
        else if (module->addCreatorInfo(creator_number, *cterm, resources)) {
            return true;
        }
        module->TransferAnnotationToModel(module->GetModelIfCreated());
        return false;
    }
    else {
        SetError("Global CV qualifier encountered but not enough arguments - pass qualifier and at least one resource");
        return true;
    }
}

bool Registry::CheckCreatorString(const string& qualifier, unsigned int& creator_number)
{
    if (qualifier == "creator") {
        creator_number = 1;
        return false;
    }
    regex creatorNum("^creator([0-9]+)$");
    std::smatch m;
    if (regex_search(qualifier, m, creatorNum)) {
        creator_number = stoi(m[1].str());
        return false;
    }
    g_registry.SetError("Unknown qualifier string '" + qualifier + "'.  The only legal qualifiers of the form 'x.y' start with 'creator#' where '#' is an optional number (for when there are multiple creators).");
    return true;
}

void Registry::FreeAll()
{
  for (size_t i=0; i<m_charstars.size(); i++) {
    free(m_charstars[i]);
  }
  m_charstars.clear();
  for (size_t i=0; i<m_charstarstars.size(); i++) {
    free(m_charstarstars[i]);
  }
  m_charstarstars.clear();
  for (size_t i=0; i<m_charstarstarstars.size(); i++) {
    free(m_charstarstarstars[i]);
  }
  m_charstarstarstars.clear();

  for (size_t i=0; i<m_doublestars.size(); i++) {
    free(m_doublestars[i]);
  }
  m_doublestars.clear();
  for (size_t i=0; i<m_doublestarstars.size(); i++) {
    free(m_doublestarstars[i]);
  }
  m_doublestarstars.clear();

  for (size_t i=0; i<m_ulongstars.size(); i++) {
    free(m_ulongstars[i]);
  }
  m_ulongstars.clear();
  for (size_t i=0; i<m_rd_typestars.size(); i++) {
    free(m_rd_typestars[i]);
  }
  m_rd_typestars.clear();
}

void Registry::SetWriteNameToSBML(bool set)
{
  m_writeNameToSBML = set;
}

bool Registry::GetWriteNameToSBML()
{
  return m_writeNameToSBML;
}

void Registry::SetWriteTimestampToSBML(bool set)
{
  m_writeTimestampToSBML = set;
}

bool Registry::GetWriteTimestampToSBML()
{
  return m_writeTimestampToSBML;
}

void Registry::SetBareNumbersAreDimensionless(bool dimensionless)
{
  m_bareNumbersAreDimensionless = dimensionless;
}

bool Registry::GetBareNumbersAreDimensionless()
{
  return m_bareNumbersAreDimensionless;
}

int Registry::ConvertDistribAnnotation(SBMLDocument * document)
{
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  ConversionProperties props;
  props.addOption("convert distrib annotations");

  SBMLConverter* converter = SBMLConverterRegistry::getInstance().getConverterFor(props);
  // load document
  converter->setDocument(document);
  int ret = converter->convert();
  delete converter;
  return ret;
#else
  return 0;
#endif
}

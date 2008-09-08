#include <vector>
#include <string>

#include "formula.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"
#include "variable.h"

using namespace std;

Registry::Registry()
  : m_oldinputs(),
    m_files(),
    m_variablenames(),
    m_functions(),
    m_modules(),
    m_currentModules(),
    m_currentReactantLists(),
    m_currentImportedModule(),
    m_scratchFormula(),
    m_cc('_'),
    input(NULL)
{
  //A user can't use []'s in a name, so this is guaranteed to be unique
  string main = "[main]";
  NewCurrentModule(&main);
  SetupFunctions();
}

void Registry::ClearModules()
{
  while (!SwitchToPreviousFile());
  if (input) {
    input->close();
    input->clear();
    delete(input);
  }
  m_files.clear();
  m_modules.clear();
  m_currentModules.clear();
  m_currentReactantLists.clear();
  m_currentImportedModule.clear();
  m_scratchFormula.Clear();
  string main = "[main]";
  NewCurrentModule(&main);
}

//Return values:  0: failure, 1: antimony, unread 2: SBML, read
int Registry::OpenFile(const string filename)
{
  //Try opening as SBML:
  SBMLDocument* document = readSBML(filename.c_str());
  if (document->getNumErrors() == 0) {
    //It's a valid SBML file.
    const Model* sbml = document->getModel();
    string sbmlname = getNameFromSBMLObject(sbml, "file");
    NewCurrentModule(&sbmlname);
    CurrentModule()->LoadSBML(sbml);
    RevertToPreviousModule();
    delete(document);
    return 2;
  }
  delete(document);
  
  m_files.push_back(filename);
  if (input != NULL) {
    m_oldinputs.push_back(input);
  }
  input = new(ifstream);
  input->open(filename.c_str(), ios::in);
  if (!input->is_open()) {
    m_files.pop_back();
    string error = "Could not open \"";
    error += filename;
    error += "\".  "
      "Please check that this file:\n" 
      "	1) exists in directory that antimony is being run from,\n"
      "	2) is read enabled, and\n"
      "	3) is not in use by another program.\n";
    SetError(error);	
    return 0;
  }

  if (!input->good())
  {
    m_files.pop_back();
    string error = "Input file ";
    error += filename;
    error += " is open, but not able to be read from.  This should not happen, and is probably a programming error on our part, but just in case, check the permissions on the file and try again.  If that still does not work, contact us letting us know how you got this error.";
    SetError(error);
    return 0;
  }
  return 1;
}

bool Registry::SwitchToPreviousFile()
{
  if (!input) return true;
  input->close();
  input->clear();
  delete(input);
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
  //This list courtesy libSBML, MathML.cpp, MATHML_ELEMENTS, plus "pow", in honor of Batman.
  // (Ok, other extras (post-xor) from ASTNode.cpp)
  const char* functions[] = {
  "abs"
  , "and"
  , "annotation"
  , "annotation-xml"
  , "apply"
  , "arccos"
  , "arccosh"
  , "arccot"
  , "arccoth"
  , "arccsc"
  , "arccsch"
  , "arcsec"
  , "arcsech"
  , "arcsin"
  , "arcsinh"
  , "arctan"
  , "arctanh"
  , "bvar"
  , "ceiling"
  , "ci"
  , "cn"
  , "cos"
  , "cosh"
  , "cot"
  , "coth"
  , "csc"
  , "csch"
  , "csymbol"
  , "degree"
  , "divide"
  , "eq"
  , "exp"
  , "exponentiale"
  , "factorial"
  , "false"
  , "floor"
  , "geq"
  , "gt"
  , "infinity"
  , "lambda"
  , "leq"
  , "ln"
  , "log"
  , "logbase"
  , "lt"
  , "math"
  , "minus"
  , "neq"
  , "not"
  , "notanumber"
  , "or"
  , "otherwise"
  , "pi"
  , "piece"
  , "piecewise"
  , "plus"
  , "power"
  , "root"
  , "sec"
  , "sech"
  , "semantics"
  , "sep"
  , "sin"
  , "sinh"
  , "tan"
  , "tanh"
  , "times"
  , "true"
  , "xor"
  , "acos"
  , "asin"
  , "atan"
  , "ceil"
  , "delay"
  , "log10"
  , "pow"
  , "sqr"
  , "sqrt"
  };
  for (size_t func=0; func<78; func++) {
    m_functions.push_back(functions[func]);
  }
}

void Registry::NewCurrentModule(const string* name)
{
  string localname(*name);
  m_currentModules.push_back(localname);
  //Check to make sure no existing module exist with this name
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetModuleName() == localname) {
      assert(false); //Parsing disallows this condition
      g_registry.SetError("Programming error:  Unable to create new module with the same name as an existing module.");
      return;
    }
  }
  //Otherwise, create a new module with that name
  m_modules.push_back(localname);
}

Module* Registry::CurrentModule()
{
  assert (m_currentModules.size() > 0);
  return GetModule(m_currentModules.back());
}

void Registry::RevertToPreviousModule()
{
  m_currentModules.pop_back();
  assert(m_currentModules.size() > 0);
}

void Registry::AddVariableToCurrentExportList(Variable* export_var)
{
  CurrentModule()->AddVariableToExportList(export_var);
}

bool Registry::AddVariableToCurrentImportList(Variable* import_var)
{
  Module* submod = CurrentModule()->GetVariable(m_currentImportedModule)->GetModule();
  Variable* var = submod->GetNextExportVariable();
  if (var == NULL) {
    string error = "Unable to add variable '" + import_var->GetNameDelimitedBy(GetCC()) + "' when creating an instance of the module '" + submod->GetModuleName() + "' because this module is defined to have only " + ToString(submod->GetNumExportVariables()) + " variable(s) definable by default in its construction.";
    SetError(error);
    return true; //abort!  Nothing to do.
  }
  import_var->Synchronize(var);
  return false;
}

Variable* Registry::AddVariableToCurrent(const string* name)
{
  return CurrentModule()->AddOrFindVariable(name);
}

AntimonyReaction* Registry::AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula)
{
  AntimonyReaction* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula);
  m_currentReactantLists.clear();
  return retval;
}

AntimonyReaction* Registry::AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula, Variable* var)
{
  AntimonyReaction* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula, var);
  m_currentReactantLists.clear();
  return retval;
}

ReactantList* Registry::NewBlankReactantList()
{
  ReactantList rlist;
  m_currentReactantLists.push_back(rlist);
  return &(m_currentReactantLists.back());
}

Variable* Registry::NewVariableIfNeeded(Variable* var, bool up)
{
  if (var->GetType() == varModule) {
    if (up) {
      return var->GetModule()->GetUpstreamDNA();
    }
    else {
      return var->GetModule()->GetDownstreamDNA();
    }
  }
  if (var->IsUnlinked(up)) {
    Variable* working = GetWorkingStrand();
    if (working == NULL) return var;
    if (working->DoesNotLinkTo(var)) {
      return var;
    }
  }
  vector<string> varname = var->GetName();
  Variable* newvar=CurrentModule()->AddNewNumberedVariable("_dna");
  var = CurrentModule()->GetVariable(varname); //Since the pointer is now stale.
  var->Synchronize(newvar);
  newvar->SetListSeparately(true);
  return newvar;
}

bool Registry::SetNewUpstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  if (var==NULL) return true;
  if (var->SetType(varDNA)) return true;
  SetWorkingStrand(var);
  var->SetOpenUpstream();
  return false;
}

bool Registry::SetDownstreamEnd(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  if (var==NULL) return true;
  if (var->SetType(varDNA)) return true;
  GetWorkingStrand()->SetDownstream(var);
  SetWorkingStrand(var);
  return false;
}

bool Registry::SetNewDownstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, false);
  if (var==NULL) return true;
  if (var->SetType(varDNA)) return true;
  var->SetOpenDownstream();
  SetWorkingStrand(var);
  return false;
}

bool Registry::SetDownstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  if (var==NULL) return true;
  if (var->SetType(varDNA)) return true;
  GetWorkingStrand()->SetDownstream(var);
  var->SetOpenDownstream();
  SetWorkingStrand(var);
  return false;
}


void Registry::SetWorkingStrand(Variable* var)
{
  m_workingstrand = var->GetName();
}

void Registry::SetAssignmentVariable(Variable* var)
{
  m_assignmentvar = var->GetName();
}

Formula* Registry::NewBlankFormula()
{
  m_scratchFormula.Clear();
  return &(m_scratchFormula);
}

string Registry::GetLastFile()
{
  if (m_files.size()) return m_files.back();
  return "";
}

Module* Registry::GetModule(string modulename)
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      return &(m_modules[mod]);
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

Variable* Registry::GetImportedModuleSubVariable(const std::string* name)
{
  vector<string> varname = m_currentImportedModule;
  varname.push_back(*name);
  return CurrentModule()->GetVariable(varname);
}

Variable* Registry::GetWorkingStrand()
{
  return CurrentModule()->GetVariable(m_workingstrand);
}

Variable* Registry::GetAssignmentVariable()
{
  return CurrentModule()->GetVariable(m_assignmentvar);
}

const string*  Registry::AddWord(string word)
{
  pair<set<string>::iterator,bool> ret;

  ret = m_variablenames.insert(word);
  set<string>::iterator wordit = ret.first;
  return &(*wordit);
}

const string* Registry::IsFunction(string word)
{
  for (size_t func=0; func<m_functions.size(); func++) {
    if (word == m_functions[func]) {
      return &(m_functions[func]);
    }
  }
  return NULL;
}

string Registry::GetJarnac(string modulename)
{
  string jarnac = modulename + " = define model\n";
  jarnac += GetModule(modulename)->GetJarnacReactions();
  jarnac += "\n";
  jarnac += GetModule(modulename)->GetJarnacVarFormulas();
  jarnac += "\nend\n\n";
  jarnac += GetModule(modulename)->GetJarnacConstFormulas(modulename);
  return jarnac;
}

void Registry::CompileAllExportLists()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    m_modules[mod].CompileExportLists();
  }
}


size_t Registry::GetNumModules()
{
  return m_modules.size();
}

string Registry::GetNthModuleName(size_t n)
{
  if (n>=m_modules.size()) {
    assert(false); //Shouldn't get here; wrong user calls caught earlier.
    g_registry.SetError("Programming error:  no such module " + ToString(n) + ".");
    return NULL;
  }
  return m_modules[n].GetModuleName();
}

long Registry::SaveModules()
{
  m_oldmodules.push_back(m_modules);
  return m_oldmodules.size();
}

bool Registry::RevertToModuleSet(long n)
{
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
      error += "Valid file handles are 1 through " + ToString(m_oldmodules.size());
    }
    g_registry.SetError(error);
    return true;
  }
  m_modules.clear(); //LS NOTE:  needed because otherwise we leak models!  Yes, this is weird.
  m_modules = m_oldmodules[n-1];
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    m_modules[mod].CompileExportLists();
  }
  return false;
}

void Registry::ClearOldModules()
{
  m_oldmodules.clear();
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

  for (size_t i=0; i<m_size_tstars.size(); i++) {
    free(m_size_tstars[i]);
  }
  m_size_tstars.clear();
  for (size_t i=0; i<m_rd_typestars.size(); i++) {
    free(m_rd_typestars[i]);
  }
  m_rd_typestars.clear();
}

#include <vector>
#include <string>
#include <cstdlib>

#include "formula.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "registry.h"
#include "sbmlx.h"

#include "stringx.h"
#include "variable.h"

extern int yylloc_first_line;
extern int yylloc_last_line;
extern std::vector<int> yylloc_last_lines;

using namespace std;
    
Registry::Registry()
  : m_oldinputs(),
    m_files(),
    m_variablenames(),
    m_functions(),
    m_storedvars(),
    m_modules(),
    m_currentModules(),
    m_currentReactantLists(),
    m_currentImportedModule(),
    m_scratchFormula(),
    m_scratchFormulas(),
    m_workingstrand(),
    m_currentEvent(),
    m_cc('_'),
    m_error(),
    m_oldmodules(),
    input(NULL)
{
  string main = MAINMODULE;
  NewCurrentModule(&main);
  SetupFunctions();
}

Registry::~Registry()
{
  FreeVariables();
}

void Registry::ClearModules()
{
  while (!SwitchToPreviousFile()) {}
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
  m_scratchFormulas.clear();
  m_workingstrand.Clear();
  m_currentEvent.clear();
  m_error.clear();
  m_userfunctions.clear();
  m_userfunctionnames.clear();
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

void Registry::ClearAll()
{
  m_oldmodules.clear();
  FreeVariables();
  ClearModules();
}

//Return values:  0: failure, 1: antimony, unread 2: SBML, read
int Registry::OpenFile(const string filename)
{
#ifndef NSBML
  //Try opening as SBML:
  SBMLDocument* document = readSBML(filename.c_str());
  document->setConsistencyChecks(LIBSBML_CAT_UNITS_CONSISTENCY, false);
  document->checkConsistency();
  SBMLErrorLog* log = document->getErrorLog();
  if (log->getNumFailsWithSeverity(2) == 0 && log->getNumFailsWithSeverity(3) == 0) {
    //It's a valid SBML file.
    const Model* sbml = document->getModel();
    string sbmlname = getNameFromSBMLObject(sbml, "file");
    if (sbmlname != MAINMODULE) {
      NewCurrentModule(&sbmlname);
    }
    CurrentModule()->LoadSBML(sbml);
    if (sbmlname != MAINMODULE) {
      RevertToPreviousModule();
    }
    delete(document);
    return 2;
  }
  delete(document);
#endif  
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
  yylloc_last_lines.push_back(yylloc_last_line);
  yylloc_last_line = 1;
  yylloc_first_line = 1;
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
  if (m_isfunction) {
    m_userfunctions.back().AddVariableToExportList(export_var);
    return;
  }
  CurrentModule()->AddVariableToExportList(export_var);
}

void Registry::NewUserFunction(const std::string* name)
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
  var->Synchronize(import_var);
  return false;
}

Variable* Registry::AddVariableToCurrent(const string* name)
{
  if (m_isfunction) {
    return m_userfunctions.back().AddOrFindVariable(name);
  }
  return CurrentModule()->AddOrFindVariable(name);
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula)
{
  Variable* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula);
  m_currentReactantLists.clear();
  return retval;
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula, Variable* var)
{
  Variable* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula, var);
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

bool Registry::SetNewCurrentEvent(Formula* trigger, Variable* var)
{
  m_currentEvent = var->GetName();
#ifndef NSBML
  string formstring = trigger->ToSBMLString();
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The event trigger \"" + trigger->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else if (!ASTform->isBoolean()) {
      g_registry.SetError("The formula \"" + trigger->ToDelimitedStringWithEllipses('.') + "\" cannot be parsed in a boolean context, and it is therefore illegal to use it as the trigger for an event.");
      delete ASTform;
      return true;
    }      
    else {
      delete ASTform;
    }
  }
#endif
  AntimonyEvent event(*trigger,var);
  return var->SetEvent(&event);
}

bool Registry::AddResultToCurrentEvent(Variable* var, Formula* form)
{
  //return
  CurrentModule()->GetVariable(m_currentEvent)->GetEvent()->AddResult(var, form);
  m_scratchFormula = m_scratchFormulas.back();
  m_scratchFormulas.pop_back();
  return false;
}

bool Registry::SetCompartmentOfCurrentSubmod(Variable* var)
{
  return CurrentModule()->GetVariable(m_currentImportedModule)->SetCompartment(var);
}

Formula* Registry::NewBlankFormula()
{
  m_scratchFormulas.push_back(m_scratchFormula);
  m_scratchFormula.Clear();
  return &(m_scratchFormula);
}

string Registry::GetLastFile()
{
  if (m_files.size()) return m_files.back();
  assert(false); //Should only be called when parsing.
  return "";
}

Module* Registry::GetModule(string modulename)
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      return &(m_modules[mod]);
    }
  }
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
      return &(m_userfunctions[uf]);
    }
  }
  return NULL;
}

const Module* Registry::GetModule(string modulename) const
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      return &(m_modules[mod]);
    }
  }
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
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

string Registry::GetAntimony(string modulename) const
{
  const Module* amod = GetModule(modulename);
  if (amod == NULL) return NULL;
  set<const Module*> nomods;
  return amod->GetAntimony(nomods, false);
}

string Registry::GetJarnac(string modulename) const
{
  const Module* jmod = GetModule(modulename);
  if (jmod == NULL) return NULL;
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

long Registry::SaveModules()
{
  m_oldmodules.push_back(m_modules);
  m_olduserfunctions.push_back(m_userfunctions);
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

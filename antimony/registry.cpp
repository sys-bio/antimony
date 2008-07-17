#include <vector>
#include <string>

#include "registry.h"
#include "module.h"
#include "reaction.h"
#include "reactantlist.h"
#include "formula.h"
#include "variable.h"

using namespace std;

Registry::Registry()
  : m_modules(),
    m_currentModules(),
    m_currentReactantLists(),
    m_currentImportedModule(),
    m_scratchFormula(),
    m_mainmodulename(),
    m_jarnac(),
    m_cc('_'),
    input(),
    variablenames()
{
  //A user can't use []'s in a name, so this is guaranteed to be unique
  string main = "[main]";
  NewCurrentModule(&main);
}

void Registry::ClearModels()
{
  m_modules.clear();
  m_currentModules.clear();
  m_currentReactantLists.clear();
  m_currentImportedModule.clear();
  m_scratchFormula.Clear();
  m_mainmodulename.clear();
  m_jarnac.clear();
  g_registry.input.clear();
  string main = "[main]";
  NewCurrentModule(&main);
}

void Registry::NewCurrentModule(const string* name)
{
  string localname(*name);
  m_currentModules.push_back(localname);
  //Check to make sure no existing module exist with this name
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetModuleName() == localname) {
      //LS DEBUG:  throw an error?  Assume they're continuing a definition?
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

void Registry::AddVariableToCurrentImportList(Variable* import_var)
{
  Variable* var = CurrentModule()->GetVariable(m_currentImportedModule)->GetModule()->GetNextExportVariable();
  assert(var != NULL); //LS DEBUG:  throw error
  import_var->Synchronize(var);
}

Variable* Registry::AddVariableToCurrent(const string* name)
{
  return CurrentModule()->AddOrFindVariable(name);
}

Reaction* Registry::AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula)
{
  Reaction* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula);
  m_currentReactantLists.clear();
  return retval;
}

Reaction* Registry::AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula, Variable* var)
{
  Reaction* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula, var);
  m_currentReactantLists.clear();
  return retval;
}

ReactantList* Registry::NewBlankReactantList()
{
  ReactantList rlist;
  m_currentReactantLists.push_back(rlist);
  return &(m_currentReactantLists.back());
}

void Registry::SetMainModuleName(const char* filename)
{
  string modname = filename;
  size_t txt = modname.find(".txt");
  if (txt != string::npos) {
    modname.erase(txt, 4);
  }
  m_mainmodulename = modname;
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
  if (var->IsUnlinked()) {
    return var;
  }
  vector<string> varname = var->GetName();
  Variable* newvar=CurrentModule()->AddNewNumberedVariable("_dna");
  var = CurrentModule()->GetVariable(varname); //Since the pointer is now stale.
  var->Synchronize(newvar);
  newvar->SetListSeparately(true);
  return newvar;
}

  void Registry::SetNewUpstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  var->SetType(varDNA);
  SetWorkingStrand(var);
  var->SetOpenUpstream();
}

void Registry::SetDownstreamEnd(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  var->SetType(varDNA);
  GetWorkingStrand()->SetDownstream(var);
  SetWorkingStrand(var);
}

void Registry::SetNewDownstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, false);
  var->SetType(varDNA);
  var->SetOpenDownstream();
  SetWorkingStrand(var);
}

void Registry::SetDownstreamOpen(Variable* var)
{
  var = NewVariableIfNeeded(var, true);
  var->SetType(varDNA);
  GetWorkingStrand()->SetDownstream(var);
  var->SetOpenDownstream();
  SetWorkingStrand(var);
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

Module* Registry::GetModule(std::string modulename)
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      return &(m_modules[mod]);
    }
  }
  //LS DEBUG:  throw error
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

  ret = variablenames.insert(word);
  set<string>::iterator wordit = ret.first;
  return &(*wordit);
}

string Registry::GetJarnac(string modulename)
{
  string name = modulename;
  if (name=="[main]") {
    name = m_mainmodulename;
  }
  if (GetModule(modulename)== NULL && modulename == m_mainmodulename) {
    modulename = "[main]";
  }
  string jarnac = name + " = define model\n";
  jarnac += GetModule(modulename)->GetJarnacReactions();
  jarnac += "\n";
  jarnac += GetModule(modulename)->GetJarnacVarFormulas();
  jarnac += "\nend\n\n";
  jarnac += GetModule(modulename)->GetJarnacConstFormulas(name);
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
    //LS DEBUG throw error
    assert(false);
  }
  return m_modules[n].GetModuleName();
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

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
  g_registry.input.clear();
  string main = "[main]";
  NewCurrentModule(&main);
}

void Registry::NewCurrentModule(const string* name)
{
  string localname(*name);
  m_modules.push_back(localname);
  m_currentModules.push_back(localname);
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

const string* Registry::GetJarnac(string modulename)
{
  string name = modulename;
  if (name=="[main]") {
    name = m_mainmodulename;
  }
  if (modulename == m_mainmodulename) {
    modulename = "[main]";
  }
  m_jarnac = name + " = define model\n";
  m_jarnac += GetModule(modulename)->GetJarnacReactions();
  m_jarnac += "\n";
  m_jarnac += GetModule(modulename)->GetJarnacVarFormulas();
  m_jarnac += "\nend\n\n";
  m_jarnac += GetModule(modulename)->GetJarnacConstFormulas(name);
  return &m_jarnac;
}

size_t Registry::GetNumModules()
{
  return m_modules.size();
}


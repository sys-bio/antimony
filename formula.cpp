#include <iostream>

#include "formula.h"
#include "module.h"
#include "registry.h"
#include "variable.h"

using namespace std;

void Formula::AddVariable(Variable* var)
{
  pair<string, vector<string> > newvar;
  newvar = make_pair(var->GetNamespace(), var->GetName());
  m_components.push_back(newvar);
}

void Formula::AddNum(double num)
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  char charnum[50];
  sprintf(charnum, "%g", num);
  string strnum(charnum);
  newvar = make_pair(strnum, novar);
  m_components.push_back(newvar);
}

void Formula::AddMathThing(char maththing)
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  string math = " "; // Make this "   " and the subsequent 0 a 1 for spacing.
  math[0] = maththing;
  newvar = make_pair(math, novar);
  m_components.push_back(newvar);
}

void Formula::AddEllipses()
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  string ellipses = "...";
  newvar = make_pair(ellipses, novar);
  assert(m_components.size()==0);
  m_components.push_back(newvar);
}

void Formula::SetNewTopName(string newmodname, string newtopname)
{
  for (size_t component=0; component<m_components.size(); component++) {
    if (m_components[component].second.size() > 0) {
      m_components[component].first = newmodname;
      m_components[component].second.insert(m_components[component].second.begin(), newtopname);
    }
  }
}

bool Formula::IsEmpty() const
{
  return m_components.size() == 0;
}

bool Formula::IsSimpleVariable() const
{
  if (m_components.size() == 1) {
    if (m_components[0].second.size() > 0) {
      return true;
    }
  }
  return false;
}

bool Formula::GetIsConst() const
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0 ) {
      vector<string> varname = m_components[comp].second;
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL); //LS DEBUG THROW ERROR
      const Variable* actualvar = module->GetVariable(varname);
      if (actualvar == NULL) {
        return false; //Can't find the variable in question, so assume.
      }
      else if (!actualvar->GetIsConst()) {
        return false;
      }
    }
  }
  return true;
}

void Formula::CheckIncludes(string modname, ReactantList* rlist) const
{
  vector<vector<string> > varlist = rlist->GetVariableList();
  for (size_t var=0; var<varlist.size(); var++) {
    assert(!ContainsVar(modname, varlist[var])); //LS DEBUG:  throw an error
  }
}

bool Formula::ContainsVar(string modname, vector<string> vname) const
{
  for (size_t var=0; var<m_components.size(); var++) {
    if (m_components[var].second == vname) {
      return true;
    }
    if (modname == m_components[var].first) {
      Module* module = g_registry.GetModule(m_components[var].first);
      Variable* subvar = NULL;
      if (module != NULL) {
        subvar = module->GetVariable(m_components[var].second);
      }
      else {
        assert(false); //come on, they're both part of the same nonexistant module?
      }
      if (subvar != NULL) {
        Formula* subform = subvar->GetFormula();
        if (subform != NULL) {
          if (subform->ContainsVar(modname, vname)) {
            return true;
          }
        }
      }
    }
  }
  return false;
}
    
void Formula::Clear()
{
  m_components.clear();
}

vector<string> Formula::GetSimpleVariable() const
{
  assert(IsSimpleVariable());
  return m_components[0].second;
}

string Formula::ToDelimitedStringWithUpvar(char cc, Variable* upvar) const
{
  string retval;
  for (size_t comp=0; comp < m_components.size(); comp++) {
    vector<string> varname = m_components[comp].second;
    Module* module = g_registry.GetModule(m_components[comp].first);
    Variable* actualvar = NULL;
    if (module != NULL) {
      actualvar = module->GetVariable(varname);
    }
    if (m_components[comp].first == "...") {
      actualvar = upvar;
    }
    if (actualvar != NULL) {
      retval += actualvar->GetNameDelimitedBy(cc);
    }
    else if (varname.size() > 0) {
      assert(false); //Can't find the variable!
      //LS DEBUG THROW ERROR
    }
    else {
      if (m_components[comp].first != "...") {
        retval += m_components[comp].first;
      }
      else {
        retval += "0";
      }
    }
  }
  return retval;
}

#include <iostream>

#include "formula.h"
#include "module.h"
#include "registry.h"
#include "variable.h"

using namespace std;

void Formula::AddVariable(Variable* var)
{
  pair<string, vector<string> > newvar;
  newvar = make_pair(var->GetNameDelimitedBy('.'), var->GetName());
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

void Formula::SetNewTopName(string newtopname)
{
  for (size_t component=0; component<m_components.size(); component++) {
    if (m_components[component].second.size() > 0) {
      m_components[component].first = newtopname + "." + m_components[component].first;
      m_components[component].second.insert(m_components[component].second.begin(), newtopname);
    }
  }
}

void Formula::SetEllipses(Variable* var)
{
  if (m_components.size() > 0 && m_components[0].first == "...") {
    if (var != NULL) {
      m_components[0].second = var->GetName();
    }
    else {
      m_components[0].second.clear();
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
      Variable* actualvar = g_registry.CurrentModule()->GetVariable(varname);
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

void Formula::CheckIncludes(ReactantList* rlist) const
{
  vector<vector<string> > varlist = rlist->GetVariableList();
  for (size_t var=0; var<varlist.size(); var++) {
    assert(!ContainsVar(varlist[var])); //LS DEBUG:  throw an error
  }
}

bool Formula::ContainsVar(vector<string> vname) const
{
  for (size_t var=0; var<m_components.size(); var++) {
    if (m_components[var].second == vname) {
      return true;
    }
    Variable* subvar = g_registry.CurrentModule()->GetVariable(m_components[var].second);
    if (subvar != NULL) {
      Formula* subform = subvar->GetFormula();
      if (subform != NULL) {
        if (subform->ContainsVar(vname)) {
          return true;
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
  for (size_t piece=0; piece < m_components.size(); piece++) {
    vector<string> varname = m_components[piece].second;
    Variable* actualvar = g_registry.CurrentModule()->GetVariable(varname);
    if (m_components[piece].first == "...") {
      actualvar = upvar;
    }
    if (actualvar != NULL) {
      retval += actualvar->GetNameDelimitedBy(cc);
    }
    else {
      if (m_components[piece].first != "...") {
        retval += m_components[piece].first;
      }
      else {
        retval += "0";
      }
    }
  }
  return retval;
}

#include "reactantlist.h"
#include "registry.h"
#include "module.h"
#include "variable.h"
#include <iostream>

using namespace std;

void ReactantList::AddReactant(Variable* var, double stoichiometry)
{
  m_components.push_back(make_pair(stoichiometry, var->GetName()));
  m_module = var->GetNamespace();
  //var->SetType(varSpeciesUndef); //<-might actually be a formula for -o things
  //cout << "New version: " << ToString() << endl;
}

void ReactantList::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  for (size_t component=0; component<m_components.size(); component++) {
    m_components[component].second.insert(m_components[component].second.begin(), newtopname);
  }
}

void ReactantList::SetVarsTo(var_type vtype)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL); //LS DEBUG throw error
    Variable* var = module->GetVariable(m_components[component].second);
    if (var != NULL) {
      var->SetType(vtype);
    }
  }
}

void ReactantList::CheckIsSingleDNAVar()
{
  //LS DEBUG:  throw errors instead of asserting
  assert(m_components.size()==1);
  assert(m_components[0].first==1);
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL); //LS DEBUG throw error
  Variable* var = module->GetVariable(m_components[0].second);
  assert(var != NULL);
  var_type vtype = var->GetType();
  assert(IsDNA(vtype) || vtype==varUndefined);
}

Variable* ReactantList::GetSingleVar()
{
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL); //LS DEBUG throw error
  return module->GetVariable(m_components[0].second);
}

vector<vector<string> > ReactantList::GetVariableList()
{
  vector<vector<string> > vlist;
  for (size_t var=0; var<m_components.size(); var++) {
    vlist.push_back(m_components[var].second);
  }
  return vlist;
}

string ReactantList::ToStringDelimitedBy(char cc) const
{
  string retval;
  for (size_t component=0; component<m_components.size(); component++) {
    if (m_components[component].first != 1) {
      char charnum[50];
      sprintf(charnum, "%g", m_components[component].first);
      retval += charnum;
    }
    vector<string> varname = m_components[component].second; 
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL); //LS DEBUG throw error
    Variable* actualvar = module->GetVariable(m_components[component].second);
    if (actualvar != NULL) {
      retval += actualvar->GetNameDelimitedBy(cc);
    }
    else {
      assert(false); //LS DEBUG:  I don't think we should get this.
      for (size_t i=0; i<varname.size(); i++) {
        retval += varname[i];
        if (i<varname.size()-1) {
          retval.push_back(cc);
        }
      }
    }
    if (component < m_components.size() - 1) {
      retval += " + ";
    }
  }
  return retval;
}

vector<string> ReactantList::ToStringVecDelimitedBy(char cc) const
{
  vector<string> retval;
  for (size_t component=0; component<m_components.size(); component++) {
    vector<string> varname = m_components[component].second;
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL); //LS DEBUG throw error
    Variable* actualvar = module->GetVariable(varname);
    if (actualvar != NULL) {
      retval.push_back(actualvar->GetNameDelimitedBy(cc));
    }
    else {
      assert(false); //LS DEBUG:  I don't think we should get this.
      string var;
      for (size_t i=0; i<varname.size(); i++) {
        var += varname[i];
        if (i<varname.size()-1) {
          var.push_back(cc);
        }
      }
      retval.push_back(var);
    }
  }
  return retval;
}

vector<double> ReactantList::GetStoichiometries() const
{
  vector<double> retval;
  for (size_t component=0; component<m_components.size(); component++) {
    retval.push_back(m_components[component].first);
  }
  return retval;
}

double ReactantList::GetStoichiometryFor(const Variable* var) const
{
  double stoich = 0;
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL); //LS DEBUG throw error
    Variable* compvar = module->GetVariable(m_components[component].second);
    assert(compvar != NULL); //LS DEBUG throw error
    if (compvar->GetIsEquivalentTo(var)) {
      stoich += m_components[component].first;
    }
  }
  return stoich;
}

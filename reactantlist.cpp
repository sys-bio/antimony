#include "reactantlist.h"
#include "registry.h"
#include "stringx.h"
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

bool ReactantList::SetVarsTo(var_type vtype)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(m_components[component].second);
    if (var != NULL) {
      if (var->SetType(vtype)) return true;
    }
  }
  return false;
}

void ReactantList::SetComponentCompartments(Variable* var)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(m_components[component].second);
    if (var != NULL) {
      var->SetCompartment(var);
    }
  }
}

bool ReactantList::SetTypesOfComponentsTo(var_type vtype)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(m_components[component].second);
    if (var != NULL) {
      if (var->SetType(vtype)) return true;
    }
  }
  return false;
}    

bool ReactantList::CheckIsSingleDNAOrReaction()
{
  if (m_components.size() == 0) {
    g_registry.SetError("An interaction must be defined to influence DNA or a reaction, but here is defined to influence nothing at all.");
    return true;
  }
  if (m_components.size() > 1) {
    g_registry.SetError("An interaction may not influence two or more things at once.");
    return true;
  }
  if (m_components[0].first != 1) {
    g_registry.SetError("An interaction has no stoichiometry:  '" + ToString(m_components[0].first) + "' is illegal in this context.");
    return true;
  }
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* var = module->GetVariable(m_components[0].second);
  assert(var != NULL);
  var_type vtype = var->GetType();
  if (IsDNA(vtype) || vtype==varUndefined || IsReaction(vtype)) {
    return false;
  }
  g_registry.SetError("An interaction may not influence a symbol previously defined to be a " + VarTypeToString(vtype) + ".  It must influence a reaction, DNA, or a previously unused symbol.");
  return true;
}

Variable* ReactantList::GetSingleVar()
{
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
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
    assert(module != NULL);
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
    assert(module != NULL);
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
    assert(module != NULL);
    Variable* compvar = module->GetVariable(m_components[component].second);
    assert(compvar != NULL);
    if (compvar->GetIsEquivalentTo(var)) {
      stoich += m_components[component].first;
    }
  }
  return stoich;
}

double ReactantList::GetStoichiometryFor(size_t n) const
{
  if (n>=m_components.size()) return NULL;
  return m_components[n].first;
}

const Variable* ReactantList::GetNthReactant(size_t n) const
{
  if (n>=m_components.size()) return NULL;
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  return module->GetVariable(m_components[n].second);
}

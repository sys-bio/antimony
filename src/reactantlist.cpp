#include <cassert>
#include "formula.h"
#include "reactantlist.h"
#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"
#include "module.h"
#include "variable.h"
#include <iostream>

using namespace std;

bool ReactantList::AddReactant(Variable* var, double stoichiometry)
{
  var_type vartype = var->GetType();
  if (!CanBeInReaction(vartype)) {
    g_registry.SetError("The variable '" + var->GetNameDelimitedBy(".") + "' cannot be used in a reaction or interaction, as it is the wrong type ('" + VarTypeToString(var->GetType()) + "').");
    return true;
  }
  //if (var->SetType(varSpeciesUndef)) //<-might actually be a formula for -o things
  vector<string> noname;
  m_components.push_back(make_tuple(stoichiometry, noname, var->GetName()));
  m_module = var->GetNamespace();
  //cout << "New version: " << ToString() << endl;
  return false;
}

bool ReactantList::AddReactant(Variable* var, Variable* stoichiometry)
{
    var_type vartype = var->GetType();
    if (!CanBeInReaction(vartype)) {
        g_registry.SetError("The variable '" + var->GetNameDelimitedBy(".") + "' cannot be used in a reaction or interaction, as it is the wrong type ('" + VarTypeToString(vartype) + "').");
        return true;
    }
    vartype = stoichiometry->GetType();
    if (!CanBeStoichiometry(vartype)) {
        g_registry.SetError("The variable '" + stoichiometry->GetNameDelimitedBy(".") + "' cannot be used as a stoichiometry, as it is the wrong type ('" + VarTypeToString(vartype) + "').");
        return true;
    }
    stoichiometry->SetType(varStoichiometry);
    //if (var->SetType(varSpeciesUndef)) //<-might actually be a formula for -o things
    m_components.push_back(make_tuple(std::numeric_limits<double>::quiet_NaN(), stoichiometry->GetName(), var->GetName()));
    m_module = var->GetNamespace();
    //cout << "New version: " << ToString() << endl;
    return false;
}

void ReactantList::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  for (size_t component=0; component<m_components.size(); component++) {
    get<2>(m_components[component]).insert(get<2>(m_components[component]).begin(), newtopname);
    if (get<1>(m_components[component]).size() > 0) {
        get<1>(m_components[component]).insert(get<1>(m_components[component]).begin(), newtopname);
    }
  }
}

void ReactantList::SetComponentCompartments(Variable* compartment, var_type supercomp)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(get<2>(m_components[component]));
    if (var != NULL) {
      var->SetSuperCompartment(compartment, supercomp);
    }
  }
}

bool ReactantList::SetComponentTypesTo(var_type vtype)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(get<2>(m_components[component]));
    if (var != NULL) {
      if (var->SetType(vtype)) return true;
    }
  }
  return false;
}

bool ReactantList::SetComponentFormulasTo(Formula form)
{
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* var = module->GetVariable(get<2>(m_components[component]));
    if (var != NULL) {
      if (var->SetFormula(&form)) return true;
    }
  }
  return false;
}

bool ReactantList::ClearReferencesTo(Variable* deletedvar)
{
  if (m_module.empty()) {
    //There are no reactants in this list, so we don't need to clear it.
    return false;
  }
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);

  bool ret = false;
  for (auto component = m_components.begin(); component != m_components.end(); ) {
    Variable* var = module->GetVariable(get<2>(*component));
    if (var->GetIsEquivalentTo(deletedvar)) {
      component = m_components.erase(component);
      ret = true;
    }
    else {
      component++;
    }
  }
  return ret;
}

vector<vector<string> > ReactantList::GetVariableList() const
{
  vector<vector<string> > vlist;
  for (size_t var=0; var<m_components.size(); var++) {
    vlist.push_back(get<2>(m_components[var]));
  }
  return vlist;
}

string ReactantList::ToStringDelimitedBy(std::string cc) const
{
  string retval;
  for (size_t component=0; component<m_components.size(); component++) {
    if (component > 0) {
      retval += " + ";
    }
    //Stoichiometry:
    if (get<1>(m_components[component]).size() > 0) {
        vector<string> varname = get<1>(m_components[component]);
        Variable* var = g_registry.GetModule(m_module)->GetVariable(varname);
        retval += (var->GetNameDelimitedBy(cc));
        retval += " ";
    }
    else if (get<0>(m_components[component]) != 1) {
      char charnum[50];
      sprintf(charnum, "%g", get<0>(m_components[component]));
      retval += charnum;
      retval += ' ';
    }
    //Species reference:
    vector<string> varname = get<2>(m_components[component]);
    Variable* var = g_registry.GetModule(m_module)->GetVariable(varname);
    if (var->GetIsConst()) {
      retval += "$";
    }
    retval += (var->GetNameDelimitedBy(cc));
  }
  return retval;
}

vector<string> ReactantList::ToStringVecDelimitedBy(string cc) const
{
  vector<string> retval;
  for (size_t component=0; component<m_components.size(); component++) {
    vector<string> varname = get<2>(m_components[component]);
    retval.push_back(g_registry.GetModule(m_module)->GetVariable(varname)->GetNameDelimitedBy(cc));
  }
  return retval;
}

vector<double> ReactantList::GetStoichiometries() const
{
  vector<double> retval;
  for (size_t component=0; component<m_components.size(); component++) {
    retval.push_back(get<0>(m_components[component]));
  }
  return retval;
}

double ReactantList::GetStoichiometryFor(const Variable* var) const
{
  double stoich = 0;
  for (size_t component=0; component<m_components.size(); component++) {
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    Variable* compvar = module->GetVariable(get<2>(m_components[component]));
    assert(compvar != NULL);
    if (compvar->GetIsEquivalentTo(var)) {
      stoich += get<0>(m_components[component]);
    }
  }
  return stoich;
}

double ReactantList::GetStoichiometryFor(size_t n) const
{
  if (n>=m_components.size()) return 0.0;
  if (get<1>(m_components[n]).size() > 0) {
      Module* module = g_registry.GetModule(m_module);
      assert(module != NULL);
      Variable* stoichvar = module->GetVariable(get<1>(m_components[n]));
      Formula* stoichform = stoichvar->GetFormula();
      if (stoichform->IsDouble()) {
          return stoichform->GetDouble();
      }
      return std::numeric_limits<double>::quiet_NaN();
  }
  return get<0>(m_components[n]);
}

const Variable* ReactantList::GetNthReactant(size_t n) const
{
  if (n>=m_components.size()) return NULL;
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  return module->GetVariable(get<2>(m_components[n]));
}

const Variable* ReactantList::GetNthStoichiometryVar(size_t n) const
{
    if (n >= m_components.size()) return NULL;
    if (get<1>(m_components[n]).size() > 0) {
        Module* module = g_registry.GetModule(m_module);
        assert(module != NULL);
        Variable* stoichvar = module->GetVariable(get<1>(m_components[n]));
        return stoichvar;
    }
    return NULL;
}

void ReactantList::FixNames()
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    FixName(get<2>(m_components[comp]));
  }
  FixName(m_module);
}

bool ReactantList::Matches(const ReactantList* newrl) const
{
  vector<vector<string> > newvariables = newrl->GetVariableList();
  vector<vector<string> > oldvariables = GetVariableList();
  if (newvariables.size() > oldvariables.size()) return false;
  //Make a copy of the components that we can mess with:
  auto components = m_components;
  if (newvariables.size() < oldvariables.size()) {
    set<vector<string> > newvarset(newvariables.begin(), newvariables.end());
    set<vector<string> > oldvarset(oldvariables.begin(), oldvariables.end());
    for (set<vector<string> >::iterator ov = oldvarset.begin(); ov != oldvarset.end(); ov++) {
      if (newvarset.find(*ov) == newvarset.end()) {
        //The missing element might have been deleted automatically.
        size_t match = 0;
        for (size_t ovnum=0; ovnum<oldvariables.size(); ovnum++) {
          if (oldvariables[ovnum] == *ov) {
            match = ovnum;
            break;
          }
        }
        Module* module = g_registry.GetModule(m_module);
        assert(module != NULL);
        Variable* ov_var = module->GetVariable(*ov);
        if (ov_var->GetType() == varDeleted) {
          components.erase(components.begin()+match);
        }
        else {
          return false;
        }
      }
    }
  }
  if (components.size() != newvariables.size()) return false;
  for (size_t component=0; component<components.size(); component++) {
    //Check stoichiometry value
    if (get<0>(components[component]) != get<0>(newrl->m_components[component])) return false;
    Module* module = g_registry.GetModule(m_module);
    assert(module != NULL);
    //Check stoichiometry variable (if any)
    Variable* origvar = module->GetVariable(get<1>(components[component]));
    Variable* newvar = module->GetVariable(get<1>(newrl->m_components[component]));
    if (origvar && newvar)
    {
        if (origvar->GetSameVariable() != newvar->GetSameVariable()) return false;
    }
    else if (origvar && !newvar)
    {
        return false;
    }
    else if (newvar && !origvar)
    {
        return false;
    }
    //Check species reference
    origvar = module->GetVariable(get<2>(components[component]));
    assert(origvar != NULL);
    newvar = module->GetVariable(newvariables[component]);
    assert(newvar != NULL);
    if (origvar->GetSameVariable() != newvar->GetSameVariable()) return false;
  }
  return true;
}

bool ReactantList::HasReactantFor(const Variable* species) const
{
    vector<string> specid = species->GetName();
    for (size_t component = 0; component < m_components.size(); component++) {
        //Check stoichiometry value
        if (get<2>(m_components[component]) == specid) {
            return true;
        }
    }
    return false;
}

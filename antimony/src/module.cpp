#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <sstream>
#include <ostream>
#include <set>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "typex.h"
#include "unitdef.h"
#ifndef NCELLML
#include <wchar.h>
#include <CellMLBootstrap.hpp>
#endif

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include "sbml/packages/distrib/common/DistribExtensionTypes.h"
#endif

extern Registry g_registry;
using namespace std;

#define DEFAULTCOMP "default_compartment" //Also defined in antimony_api.cpp

Module::Module(string name)
  : m_modulename(name),
    m_exportlist(),
    m_variablename(),
    m_variables(),
    m_defaultVariables(),
    m_synchronized(),
    m_conversionFactors(),
    m_returnvalue(),
    m_rateNames(),
    m_usedDistributions(),
    m_currentexportvar(0),
    m_ismain(false),
    m_sbmllevel(3),
    m_sbmlversion(1),
    m_varmap(),
#ifndef NSBML
#ifdef USE_COMP
    m_sbmlnamespaces(m_sbmllevel, m_sbmlversion, "comp", 1),
#else
    m_sbmlnamespaces(m_sbmllevel, m_sbmlversion),
#endif
    m_sbml(&m_sbmlnamespaces),
    m_libsbml_info(""),
    m_libsbml_warnings(""),
#endif
#ifndef NCELLML
    m_cellmlmodel(NULL),
    m_cellmlcomponent(NULL),
    m_childrenadded(false),
#endif
    m_uniquevars()
{
#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  compdoc->setRequired(true);
  SBMLDocument* doctest = compdoc->getSBMLDocument();
  SBase* parenttest = compdoc->getParentSBMLObject();
  assert(doctest != NULL);
  assert(parenttest != NULL);
  /*
  if (doctest == NULL) {
    cout << "SBML document not set, for unknown reason.";
  }
  if (parenttest == NULL) {
    cout << "Parent of 'splugin' not found, for unknown reason.";
  }
  */
#endif //USE_COMP
  AddDefaultVariables();
}

Module::Module(const Module& src, string newtopname, string modulename)
  : m_modulename(src.m_modulename),
    m_exportlist(src.m_exportlist),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_defaultVariables(src.m_defaultVariables),
    m_synchronized(src.m_synchronized),
    m_conversionFactors(src.m_conversionFactors),
    m_returnvalue(src.m_returnvalue),
    m_rateNames(src.m_rateNames),
    m_usedDistributions(src.m_usedDistributions),
    m_currentexportvar(0),
    m_ismain(src.m_ismain),
    m_sbmllevel(src.m_sbmllevel),
    m_sbmlversion(src.m_sbmlversion),
    m_varmap(), // useless--will reset with SetNewTopName, below.
#ifndef NSBML
    m_sbmlnamespaces(src.m_sbmlnamespaces),
    m_sbml(&m_sbmlnamespaces), //New because we're renaming everything.
    m_libsbml_info(), //don't need this info for submodules--might be wrong anyway.
    m_libsbml_warnings(),
#endif
#ifndef NCELLML
    m_cellmlmodel(NULL),
    m_cellmlcomponent(NULL),
    m_childrenadded(src.m_childrenadded),
#endif
    m_uniquevars()
{
  SetNewTopName(modulename, newtopname);
  /*
#ifndef NSBML
  CreateSBMLModel(false); //It's either this or go through and rename every blasted thing in it, and libSBML doesn't provide an easy way to go through all elements at once.
#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  SBMLDocument* doctest = compdoc->getSBMLDocument();
  SBase* parenttest = compdoc->getParentSBMLObject();
  if (doctest == NULL) {
    cout << "SBML document not set, for unknown reason.";
  }
  if (parenttest == NULL) {
    cout << "Parent of 'splugin' not found, for unknown reason.";
  }
#endif //USE_COMP
#endif
  */
#ifndef NCELLML
  //CreateCellMLModel(); //ditto
#endif
}

Module::Module(const Module& src)
  : m_modulename(src.m_modulename),
    m_exportlist(src.m_exportlist),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_defaultVariables(src.m_defaultVariables),
    m_synchronized(src.m_synchronized),
    m_conversionFactors(src.m_conversionFactors),
    m_returnvalue(src.m_returnvalue),
    m_rateNames(src.m_rateNames),
    m_usedDistributions(src.m_usedDistributions),
    m_currentexportvar(src.m_currentexportvar),
    m_ismain(src.m_ismain),
    m_sbmllevel(src.m_sbmllevel),
    m_sbmlversion(src.m_sbmlversion),
    m_varmap(src.m_varmap),
#ifndef NSBML
    m_sbmlnamespaces(src.m_sbmlnamespaces),
    m_sbml(src.m_sbml),
    m_libsbml_info(src.m_libsbml_info),
    m_libsbml_warnings(src.m_libsbml_warnings),
#endif
#ifndef NCELLML
    m_cellmlmodel(src.m_cellmlmodel),
    m_cellmlcomponent(src.m_cellmlcomponent),
    m_childrenadded(src.m_childrenadded),
#endif
    m_uniquevars(src.m_uniquevars)
{
#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  SBMLDocument* doctest = compdoc->getSBMLDocument();
  SBase* parenttest = compdoc->getParentSBMLObject();
  if (doctest == NULL) {
    cout << "SBML document not set, for unknown reason.";
  }
  if (parenttest == NULL) {
    cout << "Parent of 'splugin' not found, for unknown reason.";
  }
#endif //USE_COMP
}

Module& Module::operator=(const Module& src)
{
  m_modulename = src.m_modulename;
  m_exportlist = src.m_exportlist;
  m_variablename = src.m_variablename;
  m_variables = src.m_variables;
  m_synchronized = src.m_synchronized;
  m_conversionFactors = src.m_conversionFactors;
  m_returnvalue = src.m_returnvalue;
  m_rateNames = src.m_rateNames;
  m_usedDistributions = src.m_usedDistributions;
  m_currentexportvar = src.m_currentexportvar;
  m_ismain = src.m_ismain;
  m_sbmllevel = src.m_sbmllevel;
  m_sbmlversion = src.m_sbmlversion;
  m_varmap = src.m_varmap;
#ifndef NSBML
  m_sbmlnamespaces = src.m_sbmlnamespaces;
  m_sbml = src.m_sbml;
  m_libsbml_info = src.m_libsbml_info;
  m_libsbml_warnings = src.m_libsbml_warnings;
#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  compdoc->setRequired(true);
  SBMLDocument* doctest = compdoc->getSBMLDocument();
  SBase* parenttest = compdoc->getParentSBMLObject();
  if (doctest == NULL) {
    cout << "SBML document not set, for unknown reason.";
  }
  if (parenttest == NULL) {
    cout << "Parent of 'splugin' not found, for unknown reason.";
  }
#endif //USE_COMP
#endif
#ifndef NCELLML
  m_cellmlmodel = src.m_cellmlmodel;
  m_cellmlcomponent = src.m_cellmlcomponent;
  m_childrenadded = src.m_childrenadded;
#endif
  m_uniquevars = src.m_uniquevars;
  return *this;
}


Module::~Module()
{
}
  
Variable* Module::AddOrFindVariable(const string* name)
{
  vector<string> fullname;
  fullname.push_back(*name);
  Variable* foundvar = GetVariable(fullname);
  if (foundvar==NULL) {
    //Pull out the default of that name if it exists.
    foundvar = GetDefaultVariable(fullname);
    if (foundvar != NULL) {
      m_variables.push_back(foundvar);
      StoreVariable(foundvar);
      if (foundvar->GetType()==varUnitDefinition) {
        AddUnitVariables(foundvar->GetUnitDef());
      }
    }
  }
  if (foundvar == NULL) {
    //Didn't find one--need to create a new one.
    Variable* newvar = new Variable(*name, this);
    m_variables.push_back(newvar);
    StoreVariable(newvar);
    foundvar = newvar;
  }
  return foundvar;
}

Variable* Module::AddNewNumberedVariable(const string name)
{
  long num=0;
  string newvarname;
  Variable* foundvar = NULL;
  do {
    char charnum[50];
    sprintf(charnum, "%li", num);
    num++;
    newvarname = name;
    newvarname += charnum;
    vector<string> fullname;
    fullname.push_back(newvarname);
    foundvar = GetVariable(fullname);
  } while (foundvar != NULL);
  Variable* newvar = new Variable(newvarname, this);
  m_variables.push_back(newvar);
  StoreVariable(newvar);
  return newvar;
}

void Module::StoreVariable(Variable* var)
{
  g_registry.StoreVariable(var);
  m_varmap.insert(make_pair(var->GetName(), var));
}

bool Module::AddVariableToExportList(Variable* var)
{
  vector<string> varname = var->GetName();
  for (size_t exp=0; exp<m_exportlist.size(); exp++) {
    if (m_exportlist[exp] == varname) {
      g_registry.SetError("Unable to add '" + ToStringFromVecDelimitedBy(varname, ".") + "' to the interface to module " + m_modulename + " because that variable is already in the interface.");
      return true;
    }
  }
  m_exportlist.push_back(var->GetName());
  return false;
}

Variable* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula)
{
  Variable* newrxn = AddNewNumberedVariable("_J");
  return AddNewReaction(left, divider, right, formula, newrxn);
}

Variable* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var)
{
  AntimonyReaction newrxn(*left, divider, *right, *formula, var);
  if (formula->ContainsVar(var)) {
    g_registry.SetError("The definition of reaction '" + var->GetNameDelimitedBy(".") + "' contains a reference to itself directly or indirectly in its reaction rate (" + formula->ToDelimitedStringWithEllipses(".") + ").");
    return NULL;
  }
  if (var->SetReaction(&newrxn)) return NULL;
  return var;
}

bool Module::SetFormula(Formula* formula)
{
  Variable* retvar = GetVariable(m_returnvalue);
  if (retvar == NULL) {
    g_registry.SetError(GetVariableNameDelimitedBy(".") + " is a submodule, not a variable you can set to be equal to something.");
    return true;
  }
  return GetVariable(m_returnvalue)->SetFormula(formula);
}

void Module::SetNewTopName(string newmodname, string newtopname)
{
  //Need new variables, not just pointers to the old variables.
  m_varmap.clear(); //Refilled with StoreVariable, below.
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* newvar = new Variable(*m_variables[var]);
    newvar->SetNewTopName(newmodname, newtopname);
    if (newvar->GetType() == varModule) {
      const Module* submod = newvar->GetModule();
      m_varmap.insert(submod->m_varmap.begin(), submod->m_varmap.end());
    }
    m_variables[var] = newvar;
    StoreVariable(newvar);
  }
  for (size_t var=0; var<m_defaultVariables.size(); var++) {
    Variable* newvar = new Variable(*m_defaultVariables[var]);
    newvar->SetNewTopName(newmodname, newtopname);
    m_defaultVariables[var] = newvar;
  }
  m_variablename.insert(m_variablename.begin(), newtopname);
  for (size_t var=0; var<m_exportlist.size(); var++) {
    m_exportlist[var].insert(m_exportlist[var].begin(), newtopname);
  }
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    m_synchronized[pair].first.insert(m_synchronized[pair].first.begin(), newtopname);
    m_synchronized[pair].second.insert(m_synchronized[pair].second.begin(), newtopname);
    if (!m_conversionFactors[pair].empty()) {
      m_conversionFactors[pair].insert(m_conversionFactors[pair].begin(), newtopname);
    }
  }
}

bool Module::SetModule(const string* modname)
{
  Variable* newmod = AddNewNumberedVariable("_sys");
  return newmod->SetModule(modname);
}

void Module::SetComponentCompartments(Variable* compartment)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->SetSuperCompartment(compartment, varModule)) {
      m_variables[var]->SetComponentCompartments(true);
    }
  }
}

void Module::AddSynchronizedPair(const Variable* oldvar, const Variable* newvar, const Variable* conversionFactor)
{
  m_synchronized.push_back(make_pair(oldvar->GetName(), newvar->GetName()));
  if (conversionFactor==NULL) {
    vector<string> empty;
    m_conversionFactors.push_back(empty);
  }
  else {
    m_conversionFactors.push_back(conversionFactor->GetName());
  }
}

void Module::AddTimeToUserFunction(string function)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Formula* form = m_variables[var]->GetFormula();
    if (form != NULL && form->ContainsFunction(function)) {
      form->InsertTimeInFunction(function);
    }
    Formula* form2 = m_variables[var]->GetRateRule();
    if (form2 != NULL && form2 != form && form2->ContainsFunction(function)) {
      form2->InsertTimeInFunction(function);
    }
  }
}

void Module::CreateLocalVariablesForSubmodelInterfaceIfNeeded()
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      Module* submod = m_variables[var]->GetModule();
      for (size_t exv=0; exv<submod->m_exportlist.size(); exv++) {
        Variable* var = GetVariable(submod->m_exportlist[exv])->GetSameVariable();
        if (var->GetName().size() > 1) {
          //we need a local variable for this!
          string localname = (submod->m_exportlist[exv])[submod->m_exportlist[exv].size()-1];
          vector<string> fullname;
          fullname.push_back(localname);
          Variable* newvar;
          if (GetVariable(fullname) == NULL) {
            newvar = AddOrFindVariable(&localname);
          }
          else {
            newvar = AddNewNumberedVariable(localname);
          }
          if (newvar->Synchronize(var, NULL)) {
            assert(false);
          }
        }
      }
    }
  }
}

bool Module::AddDeletion(Variable* deletedvar)
{
  deletedvar = deletedvar->GetSameVariable();
  //Make sure the deleted variable has not been synchronized with anything at this level:
  for (size_t sync=0; sync<m_synchronized.size(); sync++) {
    Variable* var = GetVariable(m_synchronized[sync].first);
    if (var->GetSameVariable() == deletedvar) {
      g_registry.SetError("Unable to delete variable " + deletedvar->GetNameDelimitedBy(".") + " because it is already synchronized to the variable " + ToStringFromVecDelimitedBy(m_synchronized[sync].second, ".") + ".");
      return true;
    }
    var = GetVariable(m_synchronized[sync].second);
    if (var->GetSameVariable() == deletedvar) {
      g_registry.SetError("Unable to delete variable " + deletedvar->GetNameDelimitedBy(".") + " because it is already synchronized to the variable " + ToStringFromVecDelimitedBy(m_synchronized[sync].first, ".") + ".");
      return true;
    }
  }
  vector<string> delname = deletedvar->GetName();
  if (delname.size() == 1) {
    //Can't delete top-level elements (why?)
    g_registry.SetError("It is illegal to delete variable " + delname[0] + " because deletions are constructs for elements in submodels only.  If you don't want an element in the model you are manipulating, don't put it in in the first place.");
    return true;
  }
  //At this point, we know we should be able to delete the variable--it's in a submodel, and not connected to anything outside that submodel.
  vector<string> submodname;
  submodname.push_back(delname[0]);
  Variable* subvar = GetVariable(submodname);
  if (subvar==NULL) {
    assert(false); //Should be impossible to find a variable whose submodel does not exist.
    g_registry.SetError("Unable to find submodel " + submodname[0] + " to delete variable " + deletedvar->GetNameDelimitedBy(".") + " from it.");
    return true;
  }
  if (deletedvar->GetType()==varModule) {
    if (DeleteFromSynchronized(deletedvar)) return true;
  }
  return subvar->DeleteFromSubmodel(deletedvar);
}

void Module::ClearReferencesTo(Variable* deletedvar, set<pair<vector<string>, deletion_type> >* ret)
{
  set<pair<vector<string>, deletion_type> > temp;
  for (size_t v=0; v<m_variables.size(); v++) {
    temp = m_variables[v]->ClearReferencesTo(deletedvar);
    ret->insert(temp.begin(), temp.end());
  }
  if (deletedvar->GetIsEquivalentTo(GetVariable(m_returnvalue))) {
    m_returnvalue.clear();
  }
  for (size_t sync=0; sync<m_conversionFactors.size(); sync++) {
    Variable* convvar = GetVariable(m_conversionFactors[sync]);
    if (convvar->GetSameVariable() == deletedvar) {
      m_conversionFactors[sync].clear();
    }
  }
  return;
}

//Used when 'deletedvar' is a submodel itself.
bool Module::DeleteFromSynchronized(Variable* deletedvar)
{
  assert(deletedvar->GetType()==varModule);
  vector<string> delname = deletedvar->GetName();
  
  vector<vector<string> >::iterator cf = m_conversionFactors.begin();
  for (vector<pair<vector<string>, vector<string> > >::iterator sync = m_synchronized.begin(); sync != m_synchronized.end();) {
    vector<pair<vector<string>, vector<string> > >::iterator nextsync = sync;
    vector<vector<string> >::iterator nextcf = cf;
    nextsync++;
    nextcf++;
    vector<string> firstname = sync->first;
    vector<string> secondname = sync->second;
    if (firstname.size() > delname.size()) {
      bool matches = true;
      for (size_t n=0; n<delname.size(); n++) {
        if (firstname[n] != delname[n]) {
          matches = false;
        }
      }
      if (matches) {
        m_synchronized.erase(sync);
        m_conversionFactors.erase(cf);
        sync = nextsync;
        cf = nextcf;
        continue;
      }
    }
    if (secondname.size() > delname.size()) {
      for (size_t n=0; n<delname.size(); n++) {
        if (secondname[n] != delname[n]) {
          g_registry.SetError("Unable to delete model " + deletedvar->GetNameDelimitedBy(".") + " because a variable in that model (" + ToStringFromVecDelimitedBy(secondname, ".") + ") was already synchronized with " + ToStringFromVecDelimitedBy(firstname, ".") + ".  Either delete that variable first, or do not try to delete the entire submodel, and instead delete unused elements from it.");
          return true;
        }
      }
    }
    sync = nextsync;
    cf = nextcf;
  }
  return false;
}

Variable* Module::AddOrFindUnitDef(UnitDef* unitdef)
{
  for (size_t v=0; v<m_variables.size(); v++) {
    Variable* var = m_variables[v];
    if (var->GetType() != varUnitDefinition) continue;
    UnitDef* match = var->GetUnitDef();
    if (unitdef->Matches(match)) {
      delete unitdef;
      return var;
    }
    if (!match->GetNameAutoGenerated() && unitdef->GetNameAutoGenerated() && unitdef->ComponentsMatch(match)) {
      delete unitdef;
      return var;
    }
  }
  for (size_t dv=0; dv<m_defaultVariables.size(); dv++) {
    Variable* var = m_defaultVariables[dv];
    if (var->GetType() != varUnitDefinition) continue;
    UnitDef* match = var->GetUnitDef();
    if (unitdef->Matches(match)) {
      delete unitdef;
      m_variables.push_back(var);
      StoreVariable(var);
      return var;
    }
    if (!match->GetNameAutoGenerated() && unitdef->GetNameAutoGenerated() && unitdef->ComponentsMatch(match)) {
      delete unitdef;
      m_variables.push_back(var);
      StoreVariable(var);
      return var;
    }
  }
  //Need a new variable;
  string udname = unitdef->GetNameDelimitedBy(".");
  Variable* var = AddOrFindVariable(&udname); //Since this unitdef was never a part of a variable, it will always have a simple name.
  if (var->SetUnitDef(unitdef)) return NULL;
  return var;
}


bool Module::AddUnitVariables(UnitDef* unitdef)
{
  for (unsigned long u=0; u<unitdef->GetNumUnitElements(); u++) {
    UnitElement* ue = unitdef->GetUnitElement(u);
    string uekind = ue->GetKind();
    Variable* var = AddOrFindVariable(&uekind);
    if (var->SetType(varUnitDefinition)) return true;
  }
  return false; //success
}

void Module::AddDefaultVariables()
{
  string name = "substance";
  Variable* newvar = new Variable(name, this);
  UnitDef* ud = new UnitDef("mole", m_modulename);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

  name = "volume";
  newvar = new Variable(name, this);
  ud = new UnitDef("litre", m_modulename);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

  name = "area";
  newvar = new Variable(name, this);
  ud = new UnitDef("metre", m_modulename);
  ud->RaiseTo(2);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

  name = "length";
  newvar = new Variable(name, this);
  ud = new UnitDef("metre", m_modulename);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

  name = "time_unit";
  newvar = new Variable(name, this);
  ud = new UnitDef("second", m_modulename);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

  name = "extent";
  newvar = new Variable(name, this);
  ud = new UnitDef("item", m_modulename);
  newvar->SetUnitDef(ud);
  m_defaultVariables.push_back(newvar);
  delete ud;

}

void PrintVarMap(map<vector<string>, Variable* > varmap)
{
  cout << "variables in map:" << endl;
  for (map<vector<string>, Variable* >::iterator var=varmap.begin(); var != varmap.end(); var++) {
    cout << ToStringFromVecDelimitedBy(var->first, ".") << endl;
  }
}

Variable* Module::GetVariable(const vector<string>& name)
{
  map<vector<string>, Variable*>::iterator found = m_varmap.find(name);
  if (found != m_varmap.end()) {
    return found->second;
  }
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetName() == name) {
      //PrintVarMap(m_varmap);
      m_varmap.insert(make_pair(name, m_variables[var]));
      //assert(false); //already got?
      return m_variables[var];
    }
    if (m_variables[var]->GetType() == varModule) {
      Variable* subvar = m_variables[var]->GetModule()->GetVariable(name);
      if (subvar != NULL) {
        //PrintVarMap(m_varmap);
        //cout << "and from subvar:" << endl;
        //PrintVarMap(m_variables[var]->GetModule()->m_varmap);
        m_varmap.insert(make_pair(name, subvar));
        //assert(false); //already got?
        return subvar;
      }
    }
  }
  return NULL;
}

Variable* Module::GetDefaultVariable(const vector<string>& name)
{
  for (size_t var=0; var<m_defaultVariables.size(); var++) {
    if (m_defaultVariables[var]->GetName() == name) {
      return m_defaultVariables[var];
    }
  }
  return NULL;
}

void Module::AddToVarMapFrom(const Module& submod)
{
  m_varmap.insert(submod.m_varmap.begin(), submod.m_varmap.end());
}

const Variable* Module::GetVariable(const vector<string>& name) const
{
  map<vector<string>, Variable*>::const_iterator found = m_varmap.find(name);
  if (found != m_varmap.end()) {
    return found->second;
  }
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetName() == name) {
      return m_variables[var];
    }
    if (m_variables[var]->GetType() == varModule) {
      const Variable* subvar = m_variables[var]->GetModule()->GetVariable(name);
      if (subvar != NULL) {
        return subvar;
      }
    }
  }
  return NULL;
}

const Variable* Module::GetVariableFromSymbol(string varname) const
{
  for (size_t v=0; v<m_uniquevars.size(); v++) {
    if (varname == m_uniquevars[v]->GetNameDelimitedBy(g_registry.GetCC())) {
      return m_uniquevars[v];
    }
  }
  g_registry.SetError("Unknown variable " + varname + " in module " + m_modulename + ".");
  return NULL;
}

Variable* Module::GetSubVariable(const string* name)
{
  vector<string> subvarname = m_variablename;
  subvarname.push_back(*name);
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetName() == subvarname) {
      return m_variables[var];
    }
  }
  return NULL;
}

const Formula* Module::GetFormula() const
{
  const Variable* retvar = GetVariable(m_returnvalue);
  if (retvar != NULL) {
    return retvar->GetFormula();
  }
  //Often, there will be no return value.  In fact, this might always be the case, since as
  // of this comment, there is no way to actually set this.
  return &(g_registry.m_blankform);
}

Formula* Module::GetFormula()
{
  Variable* retvar = GetVariable(m_returnvalue);
  if (retvar != NULL) {
    return GetVariable(m_returnvalue)->GetFormula();
  }
  //Often, there will be no return value.  In fact, this might always be the case, since as
  // of this comment, there is no way to actually set this.
  return &(g_registry.m_blankform);
}

Variable* Module::GetNextExportVariable()
{
  if (m_currentexportvar >= m_exportlist.size()) {
    return NULL;
  }
  size_t exp = m_currentexportvar;
  m_currentexportvar++;
  return GetVariable(m_exportlist[exp]);
}

vector<string> Module::GetNthExportVariable(size_t n) const
{
  if (n>=m_exportlist.size()) {
    g_registry.SetError("Unable to retrieve variable " + SizeTToString(n) + " in the interface of module " + GetModuleName() + " because there are only " + SizeTToString(m_exportlist.size()) + " symbol(s) in that module's interface.");
    vector<string> empty;
    empty.push_back("");
    return empty;
  }
  return m_exportlist[n];
}

size_t Module::GetNumSynchronizedVariables() const
{
  return m_synchronized.size();
}

pair<string, string> Module::GetNthSynchronizedVariablePair(size_t n) const
{
  if (n >= m_synchronized.size()) {
    g_registry.SetError("Unable to retrieve synchronized variable pair " + SizeTToString(n) + " in the module " + GetModuleName() + " because there are only " + SizeTToString(m_synchronized.size()) + " synchronized variables defined within that module.");
    pair<string, string> blank;
    return blank;
  }
  return make_pair(ToStringFromVecDelimitedBy(m_synchronized[n].first, g_registry.GetCC()),
                   ToStringFromVecDelimitedBy(m_synchronized[n].second, g_registry.GetCC()) );
}

vector<pair<string, string> > Module::GetAllSynchronizedVariablePairs() const
{
  vector<pair<string, string> > ret;
  for (size_t n=0; n<m_synchronized.size(); n++) {
    ret.push_back(make_pair(ToStringFromVecDelimitedBy(m_synchronized[n].first, g_registry.GetCC()),
                            ToStringFromVecDelimitedBy(m_synchronized[n].second, g_registry.GetCC()) ));
  }
  return ret;
}

vector<pair<string, string> > Module::GetSynchronizedVariablesBetween(string mod1, string mod2) const
{
  vector<pair<string, string> > ret;
  for (size_t pr=0; pr<m_synchronized.size(); pr++) {
    pair<vector<string>, vector<string> > prn = m_synchronized[pr];
    if ((prn.first[0]  == mod1 || (prn.first.size()==1  && mod1=="")) &&
        (prn.second[0] == mod2 || (prn.second.size()==1 && mod2=="")) ) {
      vector<string> shortername = prn.first;
      string name1, name2;
      if (shortername.size() > 1) {
        shortername.erase(shortername.begin());
      }
      name1 = ToStringFromVecDelimitedBy(shortername, g_registry.GetCC());
      shortername = prn.second;
      if (shortername.size() > 1) {
        shortername.erase(shortername.begin());
      }
      name2 = ToStringFromVecDelimitedBy(shortername, g_registry.GetCC());
      ret.push_back(make_pair(name1, name2));
    }
  }
  return ret;
}

pair<string, string> Module::GetNthSynchronizedVariablesBetween(string mod1, string mod2, size_t n) const
{
  vector<pair<string, string> >  fullvec = GetSynchronizedVariablesBetween(mod1, mod2);
  if (n>=fullvec.size()) {
    g_registry.SetError("Unable to retrieve synchronized variable pair " + SizeTToString(n) + " between submodules '" + mod1 + "' and '" + mod2 + "' in the module '" + GetModuleName() + "' because there are only " + SizeTToString(m_synchronized.size()) + " synchronized variables between those submodules defined within the full module.");
    pair<string, string> blank;
    return blank;
  }
  return fullvec[n];
}

Variable* Module::GetUpstreamDNA()
{
  Variable* retvar = NULL;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    Variable* var = m_variables[vnum];
    if (var->GetType() == varStrand && var->GetDNAStrand()->GetUpstreamOpen()) {
      if (retvar != NULL) {
        g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy(".") + "', because this module has multiple sites at which to attach upstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in 'NEWDNA--" + var->GetNameDelimitedBy(".") + "'.");
        return NULL;
      }
      retvar = var;
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy(".") + "', because this module has no 'open ends' at which to attach DNA.");
    return NULL;
  }
  return retvar;
}

Variable* Module::GetDownstreamDNA()
{
  Variable* retvar = NULL;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    Variable* var = m_variables[vnum];
    if (var->GetType() == varStrand && var->GetDNAStrand()->GetDownstreamOpen()) {
      if (retvar != NULL) {
        g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy(".") + "', because this module has multiple sites at which to attach downstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in '" + var->GetNameDelimitedBy(".") + "--NEWDNA'.");
        return NULL;
      }
      retvar = var;
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy(".") + "', because this module has no 'open ends' at which to attach DNA.");
    return NULL;
  }
  return retvar;
}

formula_type Module::GetFormulaType() const
{
  const Variable* retvar = GetVariable(m_returnvalue);
  if (retvar == NULL) {
    return formulaINITIAL;
  }
  return retvar->GetFormulaType();
}

bool Module::IsRateOfSymbol(const std::string& name) const
{
  return m_rateNames.find(name) != m_rateNames.end();
}

const string& Module::GetModuleName() const
{
  return m_modulename;
}

string Module::GetVariableNameDelimitedBy(string cc) const
{
  if (m_variablename.size() == 0) return "";
  string retval = m_variablename[0];
  for (size_t v=1; v<m_variablename.size(); v++) {
    retval += cc + m_variablename[v];
  }
  return retval;
}

bool Module::Finalize()
{
  m_uniquevars.clear();
  string cc = g_registry.GetCC();

  //Phase 1:  Error checking for loops
  for (size_t var=0; var<m_variables.size(); var++) {
    //If this is a submodule, we'll be calling the error checking bit soon,
    // so don't worry about it.
    if (m_variables[var]->IncludesSelf()) return true;
    //LS NOTE: loops should be detected at assignment time, but it's possible I missed something.
    if (m_variables[var]->GetType() == varCompartment){
      if (m_variables[var]->AnyCompartmentLoops()) return true;
    }
    else if (m_variables[var]->GetType() == varInteraction) {
      vector<vector<string> > rxns = m_variables[var]->GetReaction()->GetRight()->GetVariableList();
      for (size_t rxn=0; rxn<rxns.size(); rxn++) {
        Variable* rightvar = GetVariable(rxns[rxn]);
        const Formula* form = rightvar->GetFormula();
        if (!form->IsEmpty() &&
            form->CheckIncludes(m_variables[var]->GetNamespace(), m_variables[var]->GetReaction()->GetLeft())) {
          g_registry.AddErrorPrefix("According to the interaction '" + m_variables[var]->GetNameDelimitedBy(cc) + "', the formula for '" + rightvar->GetNameDelimitedBy(cc) + "' ('" + form->ToDelimitedStringWithEllipses(cc) + "') ");
          return true;
        }
      }
    }
  }

#ifndef NSBML
  //Phase 2:  Check for undefined functions
  for (size_t var=0; var<m_variables.size(); var++) {
    Formula* form = m_variables[var]->GetFormula();
    if (form) {
      string formstr = form->ToSBMLString();
      ASTNode* root = parseStringToASTNode(formstr);
      set<string> allfns;
      GetFunctionNames(root, allfns);
      delete root;
      for (set<string>::iterator name=allfns.begin(); name != allfns.end(); name++) {
        if (g_registry.IsFunction(*name) == NULL) {
          //Someone used a function they didn't define, which means it ended up as a variable.
          vector<string> varname;
          varname.push_back(*name);
          Variable* var = GetVariable(varname);
          bool isPredefined = false;
          if (*name == "rate" || *name == "rateOf") {
            isPredefined = true;
            m_rateNames.insert(*name);
            //We need to check the 'rate'/'rateOf' variable:
            if (var != NULL) {
              if (var->GetType() != varUndefined) {
                g_registry.SetError("Unable to use '" + *name + "' as a function, as it is used elsewhere as a " + VarTypeToString(var->GetType()) + ".");
                return true;
              }
            }
          }
          else {
            distribution_type dtype = StringToDistributionType(*name);
            if (dtype != distUNKNOWN) {
              isPredefined = true;
              m_usedDistributions.insert(dtype);
              if (var != NULL && var->GetType() != varUndefined) {
                g_registry.SetError("Unable to use '" + *name + "' as a function, as it is used elsewhere as a " + VarTypeToString(var->GetType()) + ".");
                return true;
              }
            }
          }
          if (!isPredefined) {
            g_registry.SetError("'" + *name + "' was used as a function, but no such function was defined.  Please define the function using 'function " + *name + "([arguments]) [function definition] end'.");
            return true;
          }
        }
      }
    }
  }
  //Now check if the functions themselves use distributions
  for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
    set<distribution_type> functypes = g_registry.GetNthUserFunction(uf)->GetUsedDistributionTypes();
    m_usedDistributions.insert(functypes.begin(), functypes.end());
  }

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  if (m_usedDistributions.size() > 0) {
    m_sbmlnamespaces.addPackageNamespace("distrib", 1);
  }
#endif
#endif
  
  //Phase 3:  Set compartments
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var]->SetComponentCompartments(false);
  }

#ifndef NSBML
  //Phase 4:  Create substance units for SBML species.
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* species = m_variables[var];
    if (!IsSpecies(species->GetType())) continue;
    Variable* unitvar = species->GetUnitVariable();
    Variable* compartment = species->GetCompartment();
    if (unitvar != NULL) {
      //We need to find or create a substance unit for this species.
      UnitDef* ud = new UnitDef(*unitvar->GetUnitDef());
      UnitDef volume("liter", m_modulename);
      if (compartment != NULL) {
        Variable* compunit = compartment->GetUnitVariable();
        if (compunit != NULL) {
          ud->MultiplyUnitDef(compunit->GetUnitDef());
        }
      }
      else {
        ud->MultiplyUnitDef(&volume);
      }
      ud->Reduce();
      Variable* newunit = AddOrFindUnitDef(ud);
    }
  }
#endif

  //Phase 5: Store a list of unique variable names.
  set<Variable*> uniquevarset;  //Can't have m_uniquevars be a set because order matters (bah).
  pair<set<Variable*>::iterator, bool> setret;
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* basevar = m_variables[var]->GetSameVariable();
    setret = uniquevarset.insert(basevar);
    if (setret.second) {
      m_uniquevars.push_back(basevar);
      if (basevar->GetType() == varModule) {
        Module* submod = basevar->GetModule();
        if (submod->Finalize()) return true;
        //Copy over what we've just created:
        vector<Variable*> subvars = submod->m_uniquevars;
        //And put them in our own vectors, if we don't have them already.
        for (size_t nsubvar=0; nsubvar<subvars.size(); nsubvar++) {
          Variable* subvar = subvars[nsubvar];
          setret = uniquevarset.insert(subvar);
          if (setret.second) {
            m_uniquevars.push_back(subvar);
          }
        }
      }
    }
  }

  //Phase 6:  convert conversion factors.
  //First, undo the time and extent conversion of any submodel reaction whose formula was replaced:
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* submod = m_variables[var];
    if (submod->GetType() != varModule) {
      continue;
    }
    submod->GetModule()->UndoTimeExtentConversions(submod->GetTimeConversionFactor(), submod->GetExtentConversionFactor());
  }

  if (m_conversionFactors.size() != m_synchronized.size()) {
    //assert(false);
  }
  for (size_t cf=0; cf < m_conversionFactors.size(); cf++) {
    vector<string> toconvert = m_synchronized[cf].first;
    if (toconvert.empty()) continue;
    vector<string> convmodel = toconvert;
    convmodel.pop_back();
    if (convmodel.empty()) {
      assert(false);
      return true;
    }
    Variable* conversionFactor = GetVariable(m_conversionFactors[cf]);
    if (conversionFactor==NULL) continue;
    Variable* converted = GetVariable(toconvert);
    if (converted==NULL) {
      return true;
    }
    Variable* modulevar = GetVariable(convmodel);
    modulevar->GetModule()->Convert(converted, conversionFactor, m_modulename);
  }

#ifndef NSBML
  //Phase 7:  Check SBML compatibility, and create sbml model object.
  //LS DEBUG:  The need for two SBMLDocuments is a hack; fix when libSBML is updated.
  if (m_variablename.empty()) {
    //Only test SBML on top-level modules.
#ifdef USE_COMP
    const SBMLDocument* sbmldoc = GetSBML(true); //Use the comp version if possible.
#else
    const SBMLDocument* sbmldoc = GetSBML(false); //Trying to get the comp version would result in an added warning.
#endif
    stringstream stream;

    SBMLWriter writer;
    writer.writeSBML(sbmldoc, stream);
    string newSBML = stream.str();
    SBMLReader reader;
    SBMLDocument* testdoc = reader.readSBMLFromString(newSBML);
    testdoc->setConsistencyChecks(LIBSBML_CAT_UNITS_CONSISTENCY, false);
    testdoc->checkConsistency();
    SBMLErrorLog* log = testdoc->getErrorLog();
    string trueerrors = "";
    for (unsigned int err=0; err<log->getNumErrors(); err++) {
      const SBMLError* error = log->getError(err);
      unsigned int errtype = error->getSeverity();
      switch(errtype) {
      case 0: //LIBSBML_SEV_INFO:
        if (m_libsbml_info != "") m_libsbml_info += "\n";
        m_libsbml_info += error->getMessage();
        break;
      case 1: //LIBSBML_SEV_WARNING:
        if (m_libsbml_warnings != "") m_libsbml_warnings += "\n";
        m_libsbml_warnings += error->getMessage();
        break;
      case 2: //LIBSBML_SEV_ERROR:
#ifndef NDEBUG
        if (trueerrors != "") trueerrors += "\n";
        trueerrors += error->getMessage();
#else
        m_libsbml_warnings += error->getMessage();
#endif
        break;
      case 3: //LIBSBML_SEV_FATAL:
        g_registry.SetError("Fatal error when creating an SBML document; unable to continue.  Error from libSBML:  " + error->getMessage());
        delete testdoc;
        return true;
      default:
        g_registry.SetError("Unknown error when creating an SBML document--there should have only been four types, but we found a fifth?  libSBML may have been updated; try using an older version, perhaps.  Error from libSBML:  " + error->getMessage());
        delete testdoc;
        return true;
      }
    }
    if (trueerrors != "") {
      g_registry.SetError(SizeTToString(log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR)) + " SBML error(s) when creating module '" + m_modulename + "'.  libAntimony tries to catch these errors before libSBML complains, but sometimes cannot.  Error message(s) from libSBML:\n" + trueerrors);
      delete testdoc;
      return true;
    }
    delete testdoc;
  }
#endif
  return false;
}

size_t Module::GetNumVariablesOfType(return_type rtype, bool comp) const
{
  size_t total = 0;
  vector<Variable*> vars = m_uniquevars;
  if (comp) {
    vars = m_variables;
    //These aren't necessarily unique--remove any that aren't.
    vector<Variable*>::iterator varit = vars.begin();
    while (varit != vars.end()) {
      if ((*varit)->IsPointer()) {
        varit = vars.erase(varit);
      }
      else {
        varit++;
      }
    }
  }
  if (rtype == allSymbols) return vars.size();
  for (size_t nvar=0; nvar<vars.size(); nvar++) {
    const Variable* var = vars[nvar];
    if (AreEquivalent(rtype, var->GetType()) &&
      AreEquivalent(rtype, var->GetIsConst())) {
        if (!(rtype == expandedStrands && !var->IsExpandedStrand())) {
          total++;
        }
    }
  }
  return total;
}

const Variable* Module::GetNthConstVariableOfType(return_type rtype, size_t n, bool comp) const
{
  vector<Variable*> vars = m_uniquevars;
  if (comp) {
    vars = m_variables;
    //These aren't necessarily unique--remove any that aren't.
    vector<Variable*>::iterator varit = vars.begin();
    while (varit != vars.end()) {
      if ((*varit)->IsPointer()) {
        varit = vars.erase(varit);
      }
      else {
        varit++;
      }
    }
  }
  if (rtype == allSymbols) {
    assert(n < vars.size());
    return vars[n];
  }

  size_t total = 0;
  for (size_t nvar=0; nvar<vars.size(); nvar++) {
    const Variable* var = vars[nvar];
    if (AreEquivalent(rtype, var->GetType()) &&
        AreEquivalent(rtype, var->GetIsConst())) {
      if (!(rtype == expandedStrands && !var->IsExpandedStrand())) {
        if (total == n) {
          return var;
        }
        total++;
      }
    }
  }
  return NULL;
}


const Variable* Module::GetNthVariableOfType(return_type rtype, size_t n, bool comp) const
{
  return GetNthConstVariableOfType(rtype, n, comp);
}

Variable* Module::GetNthVariableOfType(return_type rtype, size_t n, bool comp) 
{ 
  const Variable* ret = GetNthConstVariableOfType(rtype, n, comp);
  return const_cast<Variable*>(ret);
}



bool Module::AreEquivalent(return_type rtype, var_type vtype) const
{
  switch (rtype) {
  case allSpecies:
  case varSpecies:
  case constSpecies:
    if (vtype == varSpeciesUndef) {
      return true;
    }
    return false;
  case allFormulas:
  case varFormulas:
  case constFormulas:
    if (vtype == varFormulaUndef ||
        vtype == varDNA ||
        vtype == varFormulaOperator) {
      return true;
    }
    return false;
  case allDNA:
    if (vtype == varDNA ||
        vtype == varFormulaOperator ||
        vtype == varReactionGene) {
      return true;
    }
    return false;
  case allOperators:
  case varOperators:
  case constOperators:
    if (vtype == varFormulaOperator) {
      return true;
    }
    return false;
  case allGenes:
    if (vtype == varReactionGene) {
      return true;
    }
    return false;
  case allReactions:
    if (vtype == varReactionGene ||
        vtype == varReactionUndef) {
      return true;
    }
    return false;
  case allInteractions:
    if (vtype == varInteraction) {
      return true;
    }
    return false;
  case allUnknown:
    if (vtype == varUndefined) {
      return true;
    }
    return false;
  case subModules:
    if (vtype == varModule) {
      return true;
    }
    return false;
  case allSymbols:
    return true;
  case allEvents:
    if (vtype == varEvent) {
      return true;
    }
    return false;
  case expandedStrands:
  case modularStrands:
    if (vtype == varStrand) {
      return true;
    }
    return false;
  case allCompartments:
  case varCompartments:
  case constCompartments:
    if (vtype == varCompartment) {
      return true;
    }
    return false;
  case allUnits:
    if (vtype==varUnitDefinition) {
      return true;
    }
    return false;
  case allDeleted:
    if (vtype==varDeleted) {
      return true;
    }
    return false;
  }
  //This is just to to get compiler warnings if we switch vtype later, so
  // we remember to change the rest of this function:
  switch(vtype) {
  case varSpeciesUndef:
  case varFormulaUndef:
  case varDNA:
  case varFormulaOperator:
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
  case varUndefined:
  case varModule:
  case varEvent:
  case varCompartment:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
    break;
  }
  assert(false); //uncaught return type
  return false;
}

bool Module::AreEquivalent(return_type rtype, bool isconst) const
{
  switch (rtype) {
  case varSpecies:
  case varFormulas:
  case varOperators:
  case varCompartments:
    return (!isconst);
  case constSpecies:
  case constFormulas:
  case constOperators:
  case constCompartments:
    return (isconst);
  case allDNA:
  case allGenes:
  case allOperators:
  case allSymbols:
  case allSpecies:
  case allFormulas:
  case allUnknown:
  case allReactions:
  case allInteractions:
  case allEvents:
  case allCompartments:
  case allUnits:
  case expandedStrands:
  case modularStrands:
  case subModules:
  case allDeleted:
    return true;
  }
  assert(false); //uncaught return_type
  return false;
}

string Module::OutputOnly(vector<var_type> types, string name, string indent, string cc, map<const Variable*, Variable > origmap) const
{
  string retval = "";
  bool firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    var_type type = var->GetType();
    bool matches = false;
    for (size_t t=0; t<types.size(); t++) {
      if (type==types[t]) {
        matches = true;
        break;
      }
    }
    if (matches) {
      const Formula* form = var->GetFormula();
      formula_type ftype = var->GetFormulaType();
      if (form != NULL && !form->IsEllipsesOnly() && (ftype==formulaINITIAL || ftype==formulaRATE)) {
        if (OrigFormulaIsAlready(var, origmap, form)) continue;
        if (firstone) {
          retval += "\n" + indent + "// " + name + ":\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " = " + form->ToDelimitedStringWithEllipses(cc) + ";\n";
      }
      Variable* unit = var->GetUnitVariable();
      if (unit != NULL) {
        retval += indent + var->GetNameDelimitedBy(cc) + " has " + unit->GetNameDelimitedBy(cc) + ";\n";
      }
    }
  }
  return retval;
}

string Module::ListIn80Cols(string type, vector<string> names, string indent) const
{
  if (names.size()==0) return "";
  string retval = "";
  string oneline = indent + type;
  if (type != "") {
    oneline += " ";
  }
  oneline += names[0];
  for (size_t n=1; n<names.size(); n++) {
    if (oneline.size() > 71) {
      retval += oneline + ";\n";
      oneline = indent + type;
      if (type != "") {
        oneline += " ";
      }
      oneline += names[n];
    }
    else {
      oneline += ", " + names[n];
    }
  }
  retval += oneline + ";\n";
  return retval;
}


string Module::ToString() const
{
  string retval = "Module name:  ";
  retval += m_modulename + "\n" + "Variables: ";
  if (m_variables.size() > 0) {
    retval += m_variables[0]->ToString();
  }
  for (size_t var=1; var<m_variables.size(); var++) {
    retval += ",  " + m_variables[var]->ToString();
  }
  retval += "\nReactions:  ";
  for (size_t var=0; var<m_variables.size(); var++) {
    if (IsReaction(m_variables[var]->GetType())) {
      retval += m_variables[var]->GetReaction()->ToDelimitedStringWithEllipses(".");
    }
  }
  
  if (m_exportlist.size() > 0) {
    retval += "\nExported variables: ";
    for (size_t var=0; var<m_exportlist.size(); var++) {
      if (var>0) retval += ", ";
      for (size_t subnum=0; subnum<m_exportlist[var].size(); subnum++) {
        if (subnum>0) retval += ".";
        retval += m_exportlist[var][subnum];
      }
    }
    retval += "\n";
  }

  retval += "\nSubmodules:  ";
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->ToString();
    }
  }

  return retval;
}

string Module::GetAntimony(set<const Module*>& usedmods, bool funcsincluded) const
{
  assert(m_uniquevars.size() > 0 || m_variables.size() == 0); //The api usually calls Finalize--it didn't!
  string retval;
  string cc = ".";
  //First, we need any user-defined functions if we don't have them already.  Eventually we'll want to only write out the used ones, but for now, we'll just write them all out LS DEBUG

  if (!funcsincluded) {
    for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
      retval += g_registry.GetNthUserFunction(uf)->GetAntimony() + "\n";
    }
  }
  //Now, we need the definitions of any submodules
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      const Module* mod = g_registry.GetModule(m_variables[var]->GetModule()->GetModuleName());
      if (mod==NULL) {
        g_registry.SetError("Unable to find base module " + m_variables[var]->GetModule()->GetModuleName() + ".");
        return "";
      }
      if ((usedmods.insert(mod)).second) {
        //New module; add it.
        retval += mod->GetAntimony(usedmods, true) + "\n";
      }
    }
  }
  string indent = "";
  //Module definition
  if (m_modulename != MAINMODULE) {
    retval += "model ";
    if (GetIsMain()) retval += "*";
    retval += m_modulename + "(";
    for (size_t exp=0; exp<m_exportlist.size(); exp++) {
      if (exp > 0) {
        retval += ", ";
      }
      for (size_t nbit=0; nbit<m_exportlist[exp].size(); nbit++) {
        if (nbit > 0) retval += ".";
        retval += m_exportlist[exp][nbit];
      }
    }
    retval += ")\n";
    indent = "  ";
  }

  //Definitions of all modules first:
  bool firstone = true;
  set<size_t> already_synchronized;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      vector<string> mname = m_variables[var]->GetName();
      assert(mname.size() == 1);
      const Module* submod = m_variables[var]->GetModule();
      if (firstone) {
        retval += "\n" + indent + "// Sub-modules, and any changes to those submodules:\n";
        firstone = false;
      }
      retval += indent + mname[0] + ": " + submod->GetModuleName() + "(";
      string varimportlist;
      set<size_t> added_syncs;
      //cout << "Current number of synchronizaztions in " << m_modulename << ": " << m_synchronized.size() << endl;
      //cout << "Current number of variables: " << m_variables.size() << endl;
      for (size_t exp=0; exp<submod->GetNumExportVariables(); exp++) {
        vector<string> exportname = submod->GetNthExportVariable(exp);
        for (size_t sync=0; sync<m_synchronized.size(); sync++) {
          if (m_synchronized[sync].first == exportname &&
              m_synchronized[sync].second.size() == 1 &&
              m_conversionFactors[sync].empty()) {
            if (added_syncs.size() > 0) {
              varimportlist += ", ";
            }
            varimportlist += m_synchronized[sync].second[0];
            added_syncs.insert(sync);
            break;
          }
        }
      }
      if (added_syncs.size() == submod->GetNumExportVariables()) {
        retval += varimportlist;
        already_synchronized.insert(added_syncs.begin(), added_syncs.end());
      }

      retval += ")";
      Variable* extentconv = m_variables[var]->GetExtentConversionFactor();
      Variable* timeconv = m_variables[var]->GetTimeConversionFactor();
      if (timeconv !=NULL) {
        retval += ", timeconv = " + timeconv->GetNameDelimitedBy(cc);
      }
      if (extentconv != NULL) {
        retval += ", extentconv = " + extentconv->GetNameDelimitedBy(cc);
      }
      retval += ";\n";
    }
  }
  retval += ListSynchronizedVariables(indent, already_synchronized);

  //Now get the mapping of unique variables to original module variables--the latter will be the variables that are still hanging around in the ur-version of the module, not the ones we copied into the SubModule variable in this model.
  map<const Variable*, Variable > origmap;
  FillInOrigmap(origmap);

  //List the compartments and the species (but don't define them yet) so that the order is preserved:
  vector<string> compartmentnames;
  vector<string> speciesnames;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    string name = m_uniquevars[var]->GetNameDelimitedBy(cc);
    Variable* comp = m_uniquevars[var]->GetCompartment();
    if (comp != NULL) {
      name += " in " + comp->GetNameDelimitedBy(cc);
    }
    if (m_uniquevars[var]->GetType() == varCompartment) {
      if (!OrigIsAlreadyCompartment(m_uniquevars[var], origmap)) {
        compartmentnames.push_back(name);
      }
    }
    else if (IsSpecies(m_uniquevars[var]->GetType())) {
      if (m_uniquevars[var]->GetIsConst()) {
        name = "$" + name;
      }
      if (!OrigIsAlreadyConstSpecies(m_uniquevars[var], origmap, m_uniquevars[var]->GetIsConst())) {
        speciesnames.push_back(name);
      }
    }
  }
  if (compartmentnames.size() > 0 || speciesnames.size() > 0) {
    retval += "\n" + indent + "// Compartments and Species:\n";
  }
  retval += ListIn80Cols("compartment", compartmentnames, indent);
  retval += ListIn80Cols("species", speciesnames, indent);

  //Now list DNA strands:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    if (var->GetType() == varStrand) {
      string strand = var->GetDNAStrand()->ToStringDelimitedBy(cc);
      if (OrigIsAlreadyDNAStrand(var, origmap, strand)) continue;
      if (firstone) {
        retval += "\n" + indent + "// DNA strands:\n";
        firstone = false;
      }
      retval += indent + var->GetNameDelimitedBy(cc) + ": " + strand + ";\n";
    }
  }

  //Now any assignment rules:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    if (var->GetType() == varStrand) continue;
    if (var->GetFormulaType() == formulaASSIGNMENT) {
      const Formula* asntrule = var->GetFormula();
      if (!asntrule->IsEllipsesOnly()) {
        if (OrigAssignmentRuleIsAlready(var, origmap, asntrule)) continue;
        if (firstone) {
          retval += "\n" + indent + "// Assignment Rules:\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " := " + asntrule->ToDelimitedStringWithEllipses(cc) + ";\n";
      }
    }
  }

  //Any rate rules:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    if (var->GetFormulaType() == formulaRATE) {
      const Formula* raterule = var->GetRateRule();
      if (OrigRateRuleIsAlready(var, origmap, raterule)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Rate Rules:\n";
        firstone = false;
      }
      retval += indent + var->GetNameDelimitedBy(cc) + "' = " + raterule->ToDelimitedStringWithEllipses(cc) + ";\n";
    }
  }

  //Then reactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    var_type type = var->GetType();
    if (IsReaction(type)) {
      const AntimonyReaction* rxn = var->GetReaction();
      if (OrigReactionIsAlready(var, origmap, rxn)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Reactions:\n";
        firstone = false;
      }
      retval += indent + rxn->ToDelimitedStringWithEllipses(cc) + "\n";
    }
  }

  //Then interactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    //if (var->IsPointer()) continue;
    var_type type = var->GetType();
    if (type == varInteraction) {
      const AntimonyReaction* rxn = var->GetReaction();
      if (OrigReactionIsAlready(var, origmap, rxn)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Interactions:\n";
        firstone = false;
      }
      retval += indent + rxn->ToDelimitedStringWithEllipses(cc) + "\n";
    }
  }

  //Then events:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    var_type type = var->GetType();
    if (type == varEvent) {
      const AntimonyEvent* event = var->GetEvent();
      if (OrigEventIsAlready(var, origmap, event)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Events:\n";
        firstone = false;
      }
      retval += indent + event->ToStringDelimitedBy(cc) + "\n";
    }
  }

  //Then species:
  vector<var_type> types;
  types.push_back(varSpeciesUndef);
  retval += OutputOnly(types, "Species initializations", indent, cc, origmap);
  
  //Compartments:
  types.clear();
  types.push_back(varCompartment);
  retval += OutputOnly(types, "Compartment initializations", indent, cc, origmap);

  //Other random formulas:
  types.clear();
  types.push_back(varFormulaUndef);
  types.push_back(varFormulaOperator);
  types.push_back(varUndefined);
  types.push_back(varDNA);
  retval += OutputOnly(types, "Variable initializations", indent, cc, origmap);

  //Whether things are variable or constant (if not already declared)
  vector<string> delnames;
  vector<string> varnames;
  vector<string> constnames;
  vector<string> DNAnames;
  vector<string> operatornames;
  vector<string> genenames;
  vector<string> innames;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    var_type type = m_uniquevars[var]->GetType();
    if (IsSpecies(type)) continue; //already named them and know if they're const.
    if (IsReaction(type)) continue; //Also know if reactions are constant ('no') and if they're in a compartment.
    const_type isconst = m_uniquevars[var]->GetConstType();
    string name = m_uniquevars[var]->GetNameDelimitedBy(cc);
    Variable* comp = m_uniquevars[var]->GetCompartment();
    if (OrigMatches(m_uniquevars[var], origmap, type, isconst, comp)) continue;
    if (comp != NULL) {
      name += " in " + comp->GetNameDelimitedBy(cc);
      innames.push_back(name);
    }
    switch(isconst) {
    case constVAR:
      varnames.push_back(name);
      break;
    case constCONST:
      constnames.push_back(name);
      break;
    case constDEFAULT:
      break;
    }
    switch(type) {
    case varDNA:
      DNAnames.push_back(name);
      if (comp != NULL && IsSpecies(type)==false && innames.back() == name) {
        innames.pop_back();
      }
      break;
    case varFormulaOperator:
      if (comp != NULL && IsSpecies(type)==false && innames.back() == name) {
        innames.pop_back();
      }
      operatornames.push_back(name);
      break;
    case varReactionGene:
      if (comp != NULL && IsSpecies(type)==false && innames.back() == name) {
        innames.pop_back();
      }
      genenames.push_back(name);
      break;
    case varDeleted:
      if (constnames.size() && constnames.back() == name) {
        constnames.pop_back();
      }
      if (varnames.size() && varnames.back() == name) {
        varnames.pop_back();
      }
      if (innames.size() && innames.back() == name) {
        innames.pop_back();
      }
      delnames.push_back(m_uniquevars[var]->GetNameDelimitedBy(cc));
      break;
    case varSpeciesUndef: //already taken care of at top
    case varFormulaUndef: //
    case varReactionUndef: 
    case varInteraction: 
    case varUndefined: 
    case varModule: 
    case varEvent: 
    case varCompartment: 
    case varStrand:
    case varUnitDefinition:
      break;
    }
  }

  //Deleted elements:
  if (delnames.size()) {
    retval += "\n" + indent + "// Deleted elements from submodels:\n";
    retval += ListIn80Cols("delete", delnames, indent);
  }

  if (DNAnames.size() || operatornames.size() || genenames.size() || varnames.size() || constnames.size() || innames.size()) {
    retval += "\n" + indent + "// Other declarations:\n";
    retval += ListIn80Cols("DNA", DNAnames, indent);
    retval += ListIn80Cols("operator", operatornames, indent);
    retval += ListIn80Cols("gene", genenames, indent);
    retval += ListIn80Cols("var", varnames, indent);
    retval += ListIn80Cols("const", constnames, indent);
    retval += ListIn80Cols("", innames, indent);
  }

  //Units
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    if (var->GetType()==varUnitDefinition) {
      const UnitDef* ud = var->GetUnitDef();
      string unitdef = ud->ToStringDelimitedBy(cc);
      if (OrigIsAlreadyUnitDef(var, origmap, unitdef)) continue;
      UnitDef* canonical = ud->GetCanonical();
      if (canonical!=NULL && canonical->IsOnlyCanonicalKind()) {
        delete canonical;
        continue;
      }
      delete canonical;
      if (firstone) {
        retval += "\n" + indent + "// Unit definitions:\n";
        firstone = false;
      }
      retval += indent + "unit " + var->GetNameDelimitedBy(cc) + " = " + unitdef + ";\n";
    }
  }

  //Display names
  bool anydisplay = false;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    if (OrigDisplayNameIsAlready(m_uniquevars[var], origmap)) continue;
    if (anydisplay == false) {
      retval += "\n" + indent + "// Display Names:\n";
      anydisplay = true;
    }
    retval += indent + m_uniquevars[var]->GetNameDelimitedBy(cc) + " is \"" + m_uniquevars[var]->GetDisplayName() + "\";\n";
  }

  //end model definition
  if (m_modulename != MAINMODULE) {
    retval += "end\n";
  }
  return retval;
}

string Module::GetJarnacReactions() const
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (IsReaction(m_variables[var]->GetType()) &&
        !m_variables[var]->IsPointer()) {
      retval += "  " + m_variables[var]->GetReaction()->ToDelimitedStringWithStrands(g_registry.GetCC(), m_variables[var]->GetStrandVars()) + "\n";
    }
    else if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->GetJarnacReactions();
    }
  }
  return retval;
}

string Module::GetJarnacVarFormulas() const
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    var_type type = m_variables[var]->GetType();
    if (!m_variables[var]->IsPointer() &&
        (HasOrIsFormula(type) && m_variables[var]->HasFormula() && !m_variables[var]->GetIsConst())) {
      retval += "  ";
      retval += m_variables[var]->GetNameDelimitedBy(g_registry.GetCC()) + " = ";
      retval += m_variables[var]->GetFormula()->ToSBMLString() + "\n";
    }
    else if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->GetJarnacVarFormulas();
    }
  }
  return retval;
}

string Module::GetJarnacConstFormulas(string modulename) const
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    var_type type = m_variables[var]->GetType();
    if (!m_variables[var]->IsPointer() &&
        (HasOrIsFormula(type) && m_variables[var]->HasFormula() && m_variables[var]->GetIsConst())) {
      retval += modulename + ".";
      retval += m_variables[var]->GetNameDelimitedBy(g_registry.GetCC()) + " = ";
      retval += m_variables[var]->GetFormula()->ToSBMLString() + "\n";
    }
    else if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->GetJarnacConstFormulas(modulename);
    }
  }
  return retval;
}

bool Module::GetNeedDefaultCompartment() const
{
  size_t numsp= GetNumVariablesOfType(allSpecies, false);
  for (size_t sp=0; sp<numsp; sp++) {
    const Variable* species = GetNthVariableOfType(allSpecies, sp, false);
    if (species->GetCompartment() == NULL) {
      return true;
    }
  }
  return false;
}

string Module::ListSynchronizedVariables(string indent, set<size_t> alreadysynchronized) const
{
  string cc = ".";
  string list = "";
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    if (alreadysynchronized.find(pair) == alreadysynchronized.end()) {
      list += indent + ToStringFromVecDelimitedBy(m_synchronized[pair].first, cc);
      if (!m_conversionFactors[pair].empty()) {
        list += " * " + ToStringFromVecDelimitedBy(m_conversionFactors[pair], cc);
      }
      list += " is ";
      list += ToStringFromVecDelimitedBy(m_synchronized[pair].second, cc);
      list += ";\n";
    }
  }
  return list;
}

string Module::ListAssignmentDifferencesFrom(const Module* origmod, string mname, string indent) const
{
  std::string cc = ".";
  string list = "";
  assert(GetNumVariablesOfType(allSymbols, false) == origmod->GetNumVariablesOfType(allSymbols, false));
  set<const Variable*> renamed;
  for (size_t var=0; var<GetNumVariablesOfType(allSymbols, false); var++) {
    const Variable* thisvar = GetNthVariableOfType(allSymbols, var, false);
    const Variable* origvar = origmod->GetNthVariableOfType(allSymbols, var, false);
    string thisform = thisvar->GetFormula()->ToDelimitedStringWithEllipses(cc);
    string origform = origvar->GetFormula()->ToDelimitedStringWithEllipses(cc);
    while (thisform.find(mname + ".") != string::npos) {
      thisform.erase(thisform.find(mname + "."), mname.size()+1);
    }
    if (thisform != origform) {
      list += indent + thisvar->GetNameDelimitedBy(cc) + " = " + thisvar->GetFormula()->ToDelimitedStringWithEllipses(cc) + ";\n";
    }
  }
  return list;
}

#ifndef NSBML
#include "module-sbml.cpp"
#endif
  

#ifndef NCELLML
#include "module-cellml.cpp"
#endif


void Module::FixNames()
{
  FixName(m_modulename);
  FixName(m_exportlist);
  FixName(m_variablename);
  FixName(m_returnvalue);
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var]->FixNames();
  }
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    FixName(m_synchronized[pair].first);
    FixName(m_synchronized[pair].second);
  }
  FixName(m_varmap);
}

void Module::FillInOrigmap(map<const Variable*, Variable >& origmap) const
{
  map<const Variable*, Variable >::iterator origmapiter;
  
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      vector<string> mname = m_variables[var]->GetName();
      assert(mname.size() == 1);
      //cout << "Module " << mname[0] << endl;
      const Module* submod = m_variables[var]->GetModule();
      const Module* origmod = g_registry.GetModule(submod->GetModuleName());
      for (size_t uniq=0; uniq<origmod->m_uniquevars.size(); uniq++) {
        const Variable* origmodvar = origmod->m_uniquevars[uniq];
        //cout << "Original: " << origmodvar->GetNameDelimitedBy(".") << ": " << FormulaTypeToString(origmodvar->GetFormulaType());
        //if (origmodvar->GetFormula() != NULL) cout << ": " << origmodvar->GetFormula()->ToDelimitedStringWithEllipses(".");
        //cout << endl;
        assert(!origmodvar->IsPointer());
        Variable copied(*(origmod->m_uniquevars[uniq]));
        copied.ClearSameName();
        copied.SetNewTopName(m_modulename, mname[0]);
        const Variable* origvar = GetVariable(copied.GetName());
        if (origvar == NULL) {
          assert(false);
          continue;
        }
        origvar = origvar->GetSameVariable();
        assert(find(m_uniquevars.begin(), m_uniquevars.end(), origvar) != m_uniquevars.end());
        origmapiter = origmap.find(origvar);
        if (origmapiter == origmap.end()) {
          origmap.insert(make_pair(origvar, copied));
        }
        else {
          //Find out how the two variables were synchronized
          bool synched = false;
          for (size_t sync=0; sync<m_synchronized.size(); sync++) {
            const Variable* conversionFactor = GetVariable(m_conversionFactors[sync]);
            if ((m_synchronized[sync].first == copied.GetName()) &&
                (m_synchronized[sync].second == origmapiter->second.GetName())) {
              copied.Synchronize(&origmapiter->second, conversionFactor);
              if (origmapiter->second.IsPointer()) {
                assert(!copied.IsPointer());
                origmapiter->second = copied;
              }
              synched = true;
              break;
            }
            if ((m_synchronized[sync].first == origmapiter->second.GetName()) &&
                (m_synchronized[sync].second == copied.GetName())) {
              origmapiter->second.Synchronize(&copied, conversionFactor);
              if (origmapiter->second.IsPointer()) {
                assert(!copied.IsPointer());
                origmapiter->second = copied;
              }
              synched = true;
              break;
            }
          }
          if (!synched) {
            //Sync them randomly  LS DEBUG
            //assert(false);
            origmapiter->second.Synchronize(&copied, NULL);
            //copied.Synchronize(&origmapiter->second);
            if (!copied.IsPointer()) {
              //The synchronization worked backwards from what we tried.
              origmapiter->second = copied;
            }
          }
          //cout << "Final: " << origmapiter->second.ToString() << endl;
        }
      }
    }
  }
}

bool Module::OrigFormulaIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, const Formula* formula) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << var->GetNameDelimitedBy(".") << " not found" << endl;
    return false;
  }
  const Formula* origform = origmapiter->second.GetFormula();

  formula_type ftype = origmapiter->second.GetFormulaType();
  if (origform != NULL && !origform->IsEllipsesOnly() && (ftype==formulaINITIAL || ftype==formulaRATE)) {
    return origform->Matches(formula);
  }
  /*
  cout << var->GetNameDelimitedBy(".") << " original is blank or wrong type: ";
  if (form != NULL) {
    cout << form->ToDelimitedStringWithEllipses(cc);
  }
  cout << endl;
  */
  return false;
}

bool Module::OrigRateRuleIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, const Formula* formula) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << var->GetNameDelimitedBy(".") << " not found" << endl;
    return false;
  }
  const Formula* origform = origmapiter->second.GetRateRule();

  formula_type ftype = origmapiter->second.GetFormulaType();
  if (origform != NULL && !origform->IsEllipsesOnly() && ftype==formulaRATE) {
    return origform->Matches(formula);
  }
  return false;
}

bool Module::OrigIsAlreadyCompartment(const Variable* var, const map<const Variable*, Variable>& origmap) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  return (origmapiter->second.GetType() == varCompartment);
}

bool Module::OrigIsAlreadyConstSpecies(const Variable* var, const map<const Variable*, Variable>& origmap, bool isconst) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  if (!IsSpecies(origmapiter->second.GetType())) return false;
  return (origmapiter->second.GetIsConst() == isconst);
}

bool Module::OrigIsAlreadyDNAStrand(const Variable* var, const map<const Variable*, Variable>& origmap, string strand) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  std::string cc = ".";
  if (origmapiter->second.GetType() != varStrand) return false;
  return (origmapiter->second.GetDNAStrand()->ToStringDelimitedBy(cc) == strand);
}

bool Module::OrigAssignmentRuleIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, const Formula* formula) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << var->GetNameDelimitedBy(".") << " not found" << endl;
    return false;
  }
  const Formula* origform = origmapiter->second.GetFormula();

  formula_type ftype = origmapiter->second.GetFormulaType();
  if (origform != NULL && !origform->IsEllipsesOnly() && ftype==formulaASSIGNMENT) {
    return origform->Matches(formula);
  }
  /*
  cout << var->GetNameDelimitedBy(".") << " original is blank or wrong type: ";
  if (form != NULL) {
    cout << form->ToDelimitedStringWithEllipses(cc);
  }
  cout << endl;
  */
  return false;
}

bool Module::OrigReactionIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, const AntimonyReaction* rxn) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  std::string cc = ".";
  var_type type = origmapiter->second.GetType();
  if (!(IsReaction(type) || type==varInteraction)) return false;
  return (origmapiter->second.GetReaction()->Matches(rxn));
}

bool Module::OrigEventIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, const AntimonyEvent* event) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  if (origmapiter->second.GetType() != varEvent) return false;
  return (origmapiter->second.GetEvent()->Matches(event));
}

bool Module::OrigIsAlreadyUnitDef(const Variable* var, const map<const Variable*, Variable>& origmap, string unitdef) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  std::string cc = ".";
  if (origmapiter->second.GetType() != varUnitDefinition) return false;
  return (origmapiter->second.GetUnitDef()->ToStringDelimitedBy(cc) == unitdef);
}

bool Module::OrigDisplayNameIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap) const
{
  if (var->GetDisplayName() == "") return true;
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  return (origmapiter->second.GetDisplayName() == var->GetDisplayName());
}

bool Module::OrigMatches(const Variable* var, const map<const Variable*, Variable>& origmap, var_type type, const_type isconst, const Variable* comp) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  if (origmapiter->second.GetType() != type) return false;
  if (origmapiter->second.GetConstType() != isconst) return false;
  return (origmapiter->second.GetCompartment() == comp);
}

vector<const Variable*> Module::GetSynchronizedVariablesFor(const Variable* var)
{
  vector<const Variable*> ret;
  if (var==NULL) {
    assert(false);
    return ret;
  }
  for (size_t s=0; s<m_synchronized.size(); s++) {
    if (m_synchronized[s].first == var->GetName()) {
      const Variable* sync = GetVariable(m_synchronized[s].second);
      ret.push_back(sync);
    }
    if (m_synchronized[s].second == var->GetName()) {
      const Variable* sync = GetVariable(m_synchronized[s].first);
      ret.push_back(sync);
    }
  }
  return ret;
}

void Module::FillInSyncmap(map<const Variable*, Variable >& syncmap) const
{
  for (size_t s=0; s<m_synchronized.size(); s++) {
    const Variable* var = NULL;
    if (m_synchronized[s].first.size() > 1) {
      var = GetVariable(m_synchronized[s].first);
      AddVarToSyncMap(var, syncmap);
    }
    if (m_synchronized[s].second.size() > 1) {
      var = GetVariable(m_synchronized[s].second);
      AddVarToSyncMap(var, syncmap);
    }
  }
}

void Module::AddVarToSyncMap(const Variable* var, map<const Variable*, Variable >& syncmap) const
{
  vector<string> origname = var->GetName();
  if (origname.size() <=1) {
    assert(false);
    return;
  }
  vector<string> submodname;
  submodname.push_back(origname[0]);
  origname.erase(origname.begin());
  const Variable* submod = GetVariable(submodname);
  assert(submod != NULL);
  Module* origmod = g_registry.GetModule(submod->GetModule()->GetModuleName());
  Variable* origvar = origmod->GetVariable(origname)->GetSameVariable();
  Variable copied = *origvar;
  copied.ClearSameName();
  copied.SetNewTopName(m_modulename, submodname[0]);
  syncmap.insert(make_pair(var, copied));
}

void Module::Convert(Variable* conv, Variable* cf, string modulename)
{
  Module* origmod = g_registry.GetModule(m_modulename);
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* subvar = m_variables[var];
    Variable* origsubvar = origmod->m_variables[var];
    Formula* form = NULL;
    Formula origform;
    AntimonyEvent origevent;
    AntimonyEvent* newevent;
    switch (subvar->GetType()) {
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varSpeciesUndef:
    case varCompartment:
    case varUndefined:
    case varUnitDefinition:
    case varReactionUndef:
    case varReactionGene:
    case varInteraction:
      form = subvar->GetFormula();
      origform = *origsubvar->GetFormula();
      for (size_t vn=m_variablename.size() - origsubvar->GetName().size() + 1; vn > 0; vn--) {
        origform.SetNewTopName(modulename, m_variablename[vn-1]);
      }
      if (origform.Matches(form)) {
        form->Convert(conv, cf);
      }
      if (subvar->GetFormulaType() == formulaRATE) {
        form = subvar->GetRateRule();
        origform = *origsubvar->GetRateRule();
        origform.SetNewTopName(modulename, m_variablename[0]);
        if (origform.Matches(form)) {
          form->Convert(conv, cf);
        }
      }
      break;
    case varModule:
      subvar->GetModule()->Convert(conv, cf, modulename);
      break;
    case varEvent:
      newevent = subvar->GetEvent();
      origevent = *origsubvar->GetEvent();
      origevent.SetNewTopName(modulename, m_variablename[0]);
      if (origevent.Matches(newevent)) {
        newevent->Convert(conv, cf);
      }
      break;
    case varStrand:
    case varDeleted:
      break;
    }
  }
}

void Module::ConvertTime(Variable* tcf)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* subvar = m_variables[var];
    Formula* form = NULL;
    switch (subvar->GetType()) {
    case varReactionUndef:
    case varReactionGene:
      subvar->GetFormula()->AddInvTimeConversionFactor(tcf);
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varSpeciesUndef:
    case varCompartment:
    case varUndefined:
    case varInteraction:
      subvar->GetFormula()->ConvertTime(tcf);
      if (subvar->GetFormulaType() == formulaRATE) {
        subvar->GetRateRule()->AddInvTimeConversionFactor(tcf);
        subvar->GetRateRule()->ConvertTime(tcf);
      }
      break;
    case varModule:
      subvar->GetModule()->ConvertTime(tcf);
      break;
    case varEvent:
      subvar->GetEvent()->ConvertTime(tcf);
      break;
    case varUnitDefinition:
    case varStrand:
    case varDeleted:
      break;
    }
  }
}

void Module::ConvertExtent(Variable* xcf)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* subvar = m_variables[var];
    Formula* form = NULL;
    switch (subvar->GetType()) {
    case varReactionUndef:
    case varReactionGene:
      subvar->GetFormula()->AddConversionFactor(xcf);
      Convert(subvar, xcf, subvar->GetNamespace());
      break;
    case varModule:
      subvar->GetModule()->ConvertExtent(xcf);
      break;
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varSpeciesUndef:
    case varCompartment:
    case varUndefined:
    case varInteraction:
    case varEvent:
    case varUnitDefinition:
    case varStrand:
    case varDeleted:
      break;
    }
  }
}

void Module::UndoTimeExtentConversions(Variable* tcf, Variable* xcf)
{
  if (xcf == NULL && tcf == NULL) return;
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* subvar = m_variables[var];
    switch (subvar->GetType()) {
    case varReactionUndef:
    case varReactionGene:
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varSpeciesUndef:
    case varCompartment:
    case varUndefined:
    case varInteraction:
      subvar->GetFormula()->UnConvertTimeExtent(tcf, xcf);
      if (subvar->GetFormulaType() == formulaRATE) {
        subvar->GetRateRule()->UnConvertTimeExtent(tcf, xcf);
      }
      break;
    case varModule:
      subvar->GetModule()->UndoTimeExtentConversions(tcf, xcf);
      break;
    case varEvent:
      subvar->GetEvent()->UnConvertTimeExtent(tcf, xcf);
      break;
    case varUnitDefinition:
    case varStrand:
    case varDeleted:
      break;
    }
  }
}

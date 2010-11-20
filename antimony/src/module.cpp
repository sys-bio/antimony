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
#ifndef NCELLML
#include <wchar.h>
#include <CellMLBootstrap.hpp>
#endif

#define LEVELANDVERSION 3, 1

extern Registry g_registry;
using namespace std;

#define DEFAULTCOMP "default_compartment" //Also defined in antimony_api.cpp

Module::Module(string name)
  : m_modulename(name),
    m_exportlist(),
    m_variablename(),
    m_variables(),
    m_synchronized(),
    m_returnvalue(),
    m_currentexportvar(0),
    m_ismain(false),
    m_varmap(),
#ifndef NSBML
    m_sbml(LEVELANDVERSION),
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
#ifndef NSBML
  m_sbml.setLevelAndVersion(LEVELANDVERSION); //LS DEBUG:  bug in libsbml requires this (9/23/09)
#endif
}

Module::Module(const Module& src, string newtopname, string modulename)
  : m_modulename(src.m_modulename),
    m_exportlist(src.m_exportlist),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_synchronized(src.m_synchronized),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(0),
    m_varmap(), // useless--will reset with SetNewTopName, below.
#ifndef NSBML
    m_sbml(),
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
#ifndef NSBML
  m_sbml.setLevelAndVersion(LEVELANDVERSION); //LS DEBUG:  bug in libsbml requires this (9/23/09)
#endif
  SetNewTopName(modulename, newtopname);
#ifndef NSBML
  CreateSBMLModel(); //It's either this or go through and rename every blasted thing in it, and libSBML doesn't provide an easy way to go through all elements at once.
#endif
#ifndef NCELLML
  //CreateCellMLModel(); //ditto
#endif
}

Module::Module(const Module& src)
  : m_modulename(src.m_modulename),
    m_exportlist(src.m_exportlist),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_synchronized(src.m_synchronized),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(src.m_currentexportvar),
    m_varmap(src.m_varmap),
#ifndef NSBML
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
}

Module& Module::operator=(const Module& src)
{
  m_modulename = src.m_modulename;
  m_exportlist = src.m_exportlist;
  m_variablename = src.m_variablename;
  m_variables = src.m_variables;
  m_synchronized = src.m_synchronized;
  m_returnvalue = src.m_returnvalue;
  m_currentexportvar = src.m_currentexportvar;
  m_varmap = src.m_varmap;
#ifndef NSBML
  m_sbml = src.m_sbml;
  m_libsbml_info = src.m_libsbml_info;
  m_libsbml_warnings = src.m_libsbml_warnings;
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
      g_registry.SetError("Unable to add '" + ToStringFromVecDelimitedBy(varname, '.') + "' to the interface to module " + m_modulename + " because that variable is already in the interface.");
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
    g_registry.SetError("The definition of reaction '" + var->GetNameDelimitedBy('.') + "' contains a reference to itself directly or indirectly in its reaction rate (" + formula->ToDelimitedStringWithEllipses('.') + ").");
    return NULL;
  }
  if (var->SetReaction(&newrxn)) return NULL;
  return var;
}

bool Module::SetFormula(Formula* formula)
{
  Variable* retvar = GetVariable(m_returnvalue);
  if (retvar == NULL) {
    g_registry.SetError(GetVariableNameDelimitedBy('.') + " is a submodule, not a variable you can set to be equal to something.");
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
  m_variablename.insert(m_variablename.begin(), newtopname);
  for (size_t var=0; var<m_exportlist.size(); var++) {
    m_exportlist[var].insert(m_exportlist[var].begin(), newtopname);
  }
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    m_synchronized[pair].first.insert(m_synchronized[pair].first.begin(), newtopname);
    m_synchronized[pair].second.insert(m_synchronized[pair].second.begin(), newtopname);
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

void Module::AddSynchronizedPair(Variable* oldvar, Variable* newvar)
{
  m_synchronized.push_back(make_pair(oldvar->GetName(), newvar->GetName()));
}

void Module::AddTimeToUserFunction(std::string function)
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
          if (newvar->Synchronize(var)) {
            assert(false);
          }
        }
      }
    }
  }
}

void PrintVarMap(map<vector<string>, Variable* > varmap)
{
  cout << "variables in map:" << endl;
  for (map<vector<string>, Variable* >::iterator var=varmap.begin(); var != varmap.end(); var++) {
    cout << ToStringFromVecDelimitedBy(var->first, '.') << endl;
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

const Variable* Module::GetVariableFromSymbol(std::string varname) const
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
        g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has multiple sites at which to attach upstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in 'NEWDNA--" + var->GetNameDelimitedBy('.') + "'.");
        return NULL;
      }
      retvar = var;
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has no 'open ends' at which to attach DNA.");
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
        g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has multiple sites at which to attach downstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in '" + var->GetNameDelimitedBy('.') + "--NEWDNA'.");
        return NULL;
      }
      retvar = var;
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has no 'open ends' at which to attach DNA.");
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

const string& Module::GetModuleName() const
{
  return m_modulename;
}

string Module::GetVariableNameDelimitedBy(char cc) const
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

  //Phase 1:  Error checking for loops
  for (size_t var=0; var<m_variables.size(); var++) {
    //If this is a submodule, we'll be calling the error checking bit soon,
    // so don't worry about it.
    if (m_variables[var]->IncludesSelf()) return true;
    //LS NOTE: loops should be detected at assignment time, but it's possible I missed something.
    if (m_variables[var]->GetType() == varCompartment){
      if (m_variables[var]->AnyCompartmentLoops()) return true;
    }
  }

  //Phase 2:  Error checking for interactions
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varInteraction) {
      vector<vector<string> > rxns = m_variables[var]->GetReaction()->GetRight()->GetVariableList();
      for (size_t rxn=0; rxn<rxns.size(); rxn++) {
        Variable* rightvar = GetVariable(rxns[rxn]);
        const Formula* form = rightvar->GetFormula();
        if (!form->IsEmpty() &&
            form->CheckIncludes(m_variables[var]->GetNamespace(), m_variables[var]->GetReaction()->GetLeft())) {
          g_registry.AddErrorPrefix("According to the interaction '" + m_variables[var]->GetNameDelimitedBy('_') + "', the formula for '" + rightvar->GetNameDelimitedBy('_') + "' (=" + form->ToDelimitedStringWithEllipses('_') + ") ");
          return true;
        }
      }
    }
  }
  
  //Phase 3:  Set compartments
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var]->SetComponentCompartments(false);
  }

  //Phase 4: Store a list of unique variable names.
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

#ifndef NSBML
  //Phase 5:  Check SBML compatibility, and create sbml model object.
  //LS DEBUG:  The need for two SBMLDocuments is a hack; fix when libSBML is updated.
  const SBMLDocument* sbmldoc = GetSBML();
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
      if (trueerrors != "") trueerrors += "\n";
      trueerrors += error->getMessage();
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
    g_registry.SetError(SizeTToString(log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR)) + " SBML error(s) when creating module '" + m_modulename + "'.  libAntimony tries to catch these errors before libSBML complains, but this one slipped through--please let us know what happened and we'll try to fix it.  Error message(s) from libSBML:\n" + trueerrors);
    //delete testdoc;
    //return true;
  }
  delete testdoc;
#endif
  return false;
}

size_t Module::GetNumVariablesOfType(return_type rtype) const
{
  if (rtype == allSymbols) return m_uniquevars.size();
  size_t total = 0;
  for (size_t nvar=0; nvar<m_uniquevars.size(); nvar++) {
    const Variable* var = m_uniquevars[nvar];
    if (AreEquivalent(rtype, var->GetType()) &&
        AreEquivalent(rtype, var->GetIsConst())) {
      if (!(rtype == expandedStrands && !var->IsExpandedStrand())) {
        total++;
      }
    }
  }
  return total;
}

const Variable* Module::GetNthVariableOfType(return_type rtype, size_t n) const
{
  if (rtype == allSymbols) {
    assert(n < m_uniquevars.size());
    return m_uniquevars[n];
  }

  size_t total = 0;
  for (size_t nvar=0; nvar<m_uniquevars.size(); nvar++) {
    const Variable* var = m_uniquevars[nvar];
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
  case expandedStrands:
  case modularStrands:
  case subModules:
    return true;
  }
  assert(false); //uncaught return_type
  return false;
}

string Module::OutputOnly(vector<var_type> types, string name, string indent, char cc, map<const Variable*, Variable > origmap) const
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
      if (form != NULL && !form->IsEmpty() && !form->IsEllipsesOnly() && (ftype==formulaINITIAL || ftype==formulaRATE)) {
        string formula = form->ToDelimitedStringWithEllipses(cc);
        if (OrigFormulaIsAlready(var, origmap, formula)) continue;
        if (firstone) {
          retval += "\n" + indent + "// " + name + ":\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " = " + formula + ";\n";
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
      retval += m_variables[var]->GetReaction()->ToDelimitedStringWithEllipses('.');
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
  char cc = '.';
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
    retval += "model " + m_modulename + "(";
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
              m_synchronized[sync].second.size() == 1) {
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

      retval += ");\n";
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
      if (!asntrule->IsEmpty() && !asntrule->IsEllipsesOnly()) {
        string rule = asntrule->ToDelimitedStringWithEllipses(cc);
        if (OrigIsAlreadyAssignmentRule(var, origmap, rule)) continue;
        if (firstone) {
          retval += "\n" + indent + "// Assignment Rules:\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " := " + rule + ";\n";
      }
    }
  }

  //Any rate rules:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    if (var->GetFormulaType() == formulaRATE) {
      const Formula* raterule = var->GetRateRule();
      string rule =  raterule->ToDelimitedStringWithEllipses(cc);
      if (OrigIsAlreadyRateRule(var, origmap, rule)) continue;
      if (!raterule->IsEmpty()) {
        if (firstone) {
          retval += "\n" + indent + "// Rate Rules:\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + "' = " + rule + ";\n";
      }
    }
  }

  //Then reactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    var_type type = var->GetType();
    if (IsReaction(type)) {
      string rxn = var->GetReaction()->ToDelimitedStringWithEllipses(cc);
      if (OrigIsAlreadyReaction(var, origmap, rxn)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Reactions:\n";
        firstone = false;
      }
      retval += indent + rxn + "\n";
    }
  }

  //Then interactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    //if (var->IsPointer()) continue;
    var_type type = var->GetType();
    if (type == varInteraction) {
      string rxn = var->GetReaction()->ToDelimitedStringWithEllipses(cc);
      if (OrigIsAlreadyReaction(var, origmap, rxn)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Interactions:\n";
        firstone = false;
      }
      retval += indent + rxn + "\n";
    }
  }

  //Then events:
  firstone = true;
  for (size_t vnum=0; vnum<m_uniquevars.size(); vnum++) {
    const Variable* var = m_uniquevars[vnum];
    var_type type = var->GetType();
    if (type == varEvent) {
      string event = var->GetEvent()->ToStringDelimitedBy(cc);
      if (OrigIsAlreadyEvent(var, origmap, event)) continue;
      if (firstone) {
        retval += "\n" + indent + "// Events:\n";
        firstone = false;
      }
      retval += indent + event + "\n";
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

  //And finally, other random formulas.
  types.clear();
  types.push_back(varFormulaUndef);
  types.push_back(varFormulaOperator);
  types.push_back(varUndefined);
  types.push_back(varDNA);
  retval += OutputOnly(types, "Variable initializations", indent, cc, origmap);

  //Variables
  vector<string> varnames;
  vector<string> constnames;
  vector<string> DNAnames;
  vector<string> operatornames;
  vector<string> genenames;
  vector<string> innames;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    var_type type = m_uniquevars[var]->GetType();
    if (IsSpecies(type)) continue; //already named them and know if they're const.
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
    case varSpeciesUndef: //already taken care of at top
    case varFormulaUndef: //
    case varReactionUndef: 
    case varInteraction: 
    case varUndefined: 
    case varModule: 
    case varEvent: 
    case varCompartment: 
    case varStrand:
      break;
    }
  }

  if (DNAnames.size() || operatornames.size() || genenames.size() || varnames.size() || constnames.size() || innames.size()) {
    retval += "\n" + indent + "//Other declarations:\n";
    retval += ListIn80Cols("DNA", DNAnames, indent);
    retval += ListIn80Cols("operator", operatornames, indent);
    retval += ListIn80Cols("gene", genenames, indent);
    retval += ListIn80Cols("var", varnames, indent);
    retval += ListIn80Cols("const", constnames, indent);
    retval += ListIn80Cols("", innames, indent);
  }

  //Display names
  bool anydisplay = false;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    //if (m_uniquevars[var]->IsPointer()) continue;
    if (m_uniquevars[var]->GetDisplayName() != "") {
      if (anydisplay == false) {
        retval += "\n" + indent + "//Display Names:\n";
        anydisplay = true;
      }
      retval += indent + m_uniquevars[var]->GetNameDelimitedBy(cc) + " is \"" + m_uniquevars[var]->GetDisplayName() + "\";\n";
    }
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
      retval += "  " + m_variables[var]->GetReaction()->ToDelimitedStringWithStrands('_', m_variables[var]->GetStrandVars()) + "\n";
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
      retval += m_variables[var]->GetNameDelimitedBy('_') + " = ";
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
      retval += m_variables[var]->GetNameDelimitedBy('_') + " = ";
      retval += m_variables[var]->GetFormula()->ToSBMLString() + "\n";
    }
    else if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->GetJarnacConstFormulas(modulename);
    }
  }
  return retval;
}

string Module::ListSynchronizedVariables(string indent, set<size_t> alreadysynchronized) const
{
  char cc = '.';
  string list = "";
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    if (alreadysynchronized.find(pair) == alreadysynchronized.end()) {
      list += indent + ToStringFromVecDelimitedBy(m_synchronized[pair].first, cc) + " is " + ToStringFromVecDelimitedBy(m_synchronized[pair].second, cc) + ";\n";
    }
  }
  return list;
}

string Module::ListAssignmentDifferencesFrom(const Module* origmod, string mname, string indent) const
{
  char cc = '.';
  string list = "";
  assert(GetNumVariablesOfType(allSymbols) == origmod->GetNumVariablesOfType(allSymbols));
  set<const Variable*> renamed;
  for (size_t var=0; var<GetNumVariablesOfType(allSymbols); var++) {
    const Variable* thisvar = GetNthVariableOfType(allSymbols, var);
    const Variable* origvar = origmod->GetNthVariableOfType(allSymbols, var);
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
        //cout << "Original: " << origmodvar->GetNameDelimitedBy('.') << ": " << FormulaTypeToString(origmodvar->GetFormulaType());
        //if (origmodvar->GetFormula() != NULL) cout << ": " << origmodvar->GetFormula()->ToDelimitedStringWithEllipses('.');
        //cout << endl;
        assert(!origmodvar->IsPointer());
        Variable copied(*(origmod->m_uniquevars[uniq]));
        copied.ClearSameName();
        copied.SetNewTopName(m_modulename, mname[0]);
        const Variable* origvar = GetVariable(copied.GetName())->GetSameVariable();
        assert(find(m_uniquevars.begin(), m_uniquevars.end(), origvar) != m_uniquevars.end());
        origmapiter = origmap.find(origvar);
        if (origmapiter == origmap.end()) {
          origmap.insert(make_pair(origvar, copied));
        }
        else {
          //Find out how the two variables were synchronized
          bool synched = false;
          for (size_t sync=0; sync<m_synchronized.size(); sync++) {
            if ((m_synchronized[sync].first == copied.GetName()) &&
                (m_synchronized[sync].second == origmapiter->second.GetName())) {
              copied.Synchronize(&origmapiter->second);
              if (origmapiter->second.IsPointer()) {
                assert(!copied.IsPointer());
                origmapiter->second = copied;
              }
              synched = true;
              break;
            }
            if ((m_synchronized[sync].first == origmapiter->second.GetName()) &&
                (m_synchronized[sync].second == copied.GetName())) {
              origmapiter->second.Synchronize(&copied);
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
            origmapiter->second.Synchronize(&copied);
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

bool Module::OrigFormulaIsAlready(const Variable* var, const map<const Variable*, Variable>& origmap, string formula) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << var->GetNameDelimitedBy('.') << " not found" << endl;
    return false;
  }
  char cc = '.';
  const Formula* form = origmapiter->second.GetFormula();
  formula_type ftype = origmapiter->second.GetFormulaType();
  if (form != NULL && !form->IsEmpty() && !form->IsEllipsesOnly() && (ftype==formulaINITIAL || ftype==formulaRATE)) {
    return (form->ToDelimitedStringWithEllipses(cc) == formula);
  }
  /*
  cout << var->GetNameDelimitedBy('.') << " original is blank or wrong type: ";
  if (form != NULL) {
    cout << form->ToDelimitedStringWithEllipses(cc);
  }
  cout << endl;
  */
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
  char cc = '.';
  if (origmapiter->second.GetType() != varStrand) return false;
  return (origmapiter->second.GetDNAStrand()->ToStringDelimitedBy(cc) == strand);
}

bool Module::OrigIsAlreadyAssignmentRule(const Variable* var, const map<const Variable*, Variable>& origmap, string rule) const
{
  //cout << "Old: " << rule << endl;
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << "not found" << endl;
    return false;
  }
  char cc = '.';
  
  if (origmapiter->second.GetFormulaType() != formulaASSIGNMENT) {
    //cout << var->GetNameDelimitedBy('.') << " is not assignment:" << FormulaTypeToString(origmapiter->second.GetFormulaType()) << endl;
    //cout << "New: " <<  origmapiter->second.GetFormula()->ToDelimitedStringWithEllipses(cc) << endl;
    return false;
  }
  string newrule = origmapiter->second.GetFormula()->ToDelimitedStringWithEllipses(cc);
  //cout << "New: " << newrule << endl;
  return (origmapiter->second.GetFormula()->ToDelimitedStringWithEllipses(cc) == rule);
}

bool Module::OrigIsAlreadyRateRule(const Variable* var, const map<const Variable*, Variable>& origmap, string rule) const
{
  //cout << "Old: " << rule << endl;
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) {
    //cout << "not found" << endl;
    return false;
  }
  char cc = '.';
  if (origmapiter->second.GetFormulaType() != formulaRATE) {
    //cout << var->GetNameDelimitedBy('.') << " is not a rate rule:" << FormulaTypeToString(origmapiter->second.GetFormulaType()) << endl;
    //cout << "New: " <<  origmapiter->second.GetFormula()->ToDelimitedStringWithEllipses(cc) << endl;
    return false;
  }
  return (origmapiter->second.GetRateRule()->ToDelimitedStringWithEllipses(cc) == rule);
}

bool Module::OrigIsAlreadyReaction(const Variable* var, const map<const Variable*, Variable>& origmap, string rxn) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  char cc = '.';
  var_type type = origmapiter->second.GetType();
  if (!(IsReaction(type) || type==varInteraction)) return false;
  return (origmapiter->second.GetReaction()->ToDelimitedStringWithEllipses(cc) == rxn);
}

bool Module::OrigIsAlreadyEvent(const Variable* var, const map<const Variable*, Variable>& origmap, string event) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  char cc = '.';
  if (origmapiter->second.GetType() != varEvent) return false;
  return (origmapiter->second.GetEvent()->ToStringDelimitedBy(cc) == event);
}

bool Module::OrigMatches(const Variable* var, const map<const Variable*, Variable>& origmap, var_type type, const_type isconst, const Variable* comp) const
{
  map<const Variable*, Variable >::const_iterator origmapiter = origmap.find(var);
  if (origmapiter == origmap.end()) return false;
  if (origmapiter->second.GetType() != type) return false;
  if (origmapiter->second.GetConstType() != isconst) return false;
  return (origmapiter->second.GetCompartment() == comp);
}

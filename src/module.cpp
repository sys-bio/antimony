#include <algorithm>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "typex.h"

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
#ifndef NSBML
    m_sbml(name + "-unset"),
    m_libsbml_info(""),
    m_libsbml_warnings(""),
#endif
    m_uniquevars()
{
}

Module::Module(const Module& src, string newtopname, string modulename)
  : m_modulename(src.m_modulename),
    m_exportlist(src.m_exportlist),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_synchronized(src.m_synchronized),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(0),
#ifndef NSBML
    m_sbml(src.m_sbml),
    m_libsbml_info(), //don't need this info for submodules--might be wrong anyway.
    m_libsbml_warnings(),
#endif
    m_uniquevars()
{
  SetNewTopName(modulename, newtopname);
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
    g_registry.StoreVariable(newvar);
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
  g_registry.StoreVariable(newvar);
  return newvar;
}

void Module::AddVariableToExportList(Variable* var)
{
  m_exportlist.push_back(var->GetName());
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
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* newvar = new Variable(*m_variables[var]);
    g_registry.StoreVariable(newvar);
    m_variables[var] = newvar;
  }
  m_variablename.insert(m_variablename.begin(), newtopname);
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var]->SetNewTopName(newmodname, newtopname);
  }
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

Variable* Module::GetVariable(vector<string> name)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetName() == name) {
      return m_variables[var];
    }
    if (m_variables[var]->GetType() == varModule) {
      Variable* subvar = m_variables[var]->GetModule()->GetVariable(name);
      if (subvar != NULL) {
        return subvar;
      }
    }
  }
  /*
  cout << "No variable found for ";
  for (size_t nname=0; nname<name.size(); nname++) {
    if (nname > 0) cout << ".";
    cout << name[nname];
  }
  cout << endl;
  */
  return NULL;
}

const Variable* Module::GetVariable(vector<string> name) const
{
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
    const Variable* var = GetVariable(m_uniquevars[v]);
    if (varname == var->GetNameDelimitedBy(g_registry.GetCC())) {
      return var;
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
  return NULL;
}

Formula* Module::GetFormula()
{
  Variable* retvar = GetVariable(m_returnvalue);
  if (retvar != NULL) {
    return GetVariable(m_returnvalue)->GetFormula();
  }
  //Often, there will be no return value.  In fact, this might always be the case, since as
  // of this comment, there is no way to actually set this.
  return NULL;
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
        if (form->CheckIncludes(m_variables[var]->GetNamespace(), m_variables[var]->GetReaction()->GetLeft())) {
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
  set<string> varnames;
  char cc = '_';
  pair<set<string>::iterator, bool> nameret;
  for (size_t var=0; var<m_variables.size(); var++) {
    //if (m_variables[var]->IsPointer()) continue;
    nameret = varnames.insert(m_variables[var]->GetNameDelimitedBy(cc));
    if (nameret.second) {
      m_uniquevars.push_back(m_variables[var]->GetName());
      if (m_variables[var]->GetType() == varModule) {
        Module* submod = m_variables[var]->GetModule();
        if (submod->Finalize()) return true;
        //Copy over what we've just created:
        vector<vector<string> > subvars = submod->m_uniquevars;
        //And put them in our own vectors, if we don't have them already.
        for (size_t nsubvar=0; nsubvar<subvars.size(); nsubvar++) {
          Variable* subvar = GetVariable(subvars[nsubvar]);
          nameret = varnames.insert(subvar->GetNameDelimitedBy(cc));
          if (nameret.second) {
            m_uniquevars.push_back(submod->m_uniquevars[nsubvar]);
          }
        }
      }
    }
  }

#ifndef NSBML
  //Phase 5:  Check SBML compatibility, and create sbml model object.
  //LS DEBUG:  The need for two SBMLDocuments is a hack; fix when libSBML is updated.
  SBMLDocument sbmldoc;
  Model sbml = GetSBMLModel();
  sbmldoc.setModel(&sbml);
  SBMLDocument* testdoc = readSBMLFromString(writeSBMLToString(&sbmldoc));
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
      delete(testdoc);
      return true;
    default:
      g_registry.SetError("Unknown error when creating an SBML document--there should have only been four types, but we found a fifth?  libSBML may have been updated; try using an older version, perhaps.  Error from libSBML:  " + error->getMessage());
      delete(testdoc);
      return true;
    }
  }
  if (trueerrors != "") {
    g_registry.SetError(SizeTToString(log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR)) + " SBML error(s) when creating module '" + m_modulename + "'.  libAntimony tries to catch these errors before libSBML complains, but this one slipped through--please let us know what happened and we'll try to fix it.  Error message(s) from libSBML:\n" + trueerrors);
    delete(testdoc);
    return true;
  }
  delete(testdoc);
#endif
  return false;
}

size_t Module::GetNumVariablesOfType(return_type rtype) const
{
  size_t total = 0;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    if (AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetType()) &&
        AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetIsConst())) {
      if (!(rtype == expandedStrands && !GetVariable(m_uniquevars[var])->IsExpandedStrand())) {
        total++;
      }
    }
  }
  return total;
}

const Variable* Module::GetNthVariableOfType(return_type rtype, size_t n) const
{
  size_t total = 0;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    if (AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetType()) &&
        AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetIsConst())) {
      if (!(rtype == expandedStrands && !GetVariable(m_uniquevars[var])->IsExpandedStrand())) {
        if (total == n) {
          return GetVariable(m_uniquevars[var]);
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

string Module::GetAntimony(set<const Module*> usedmods, bool funcsincluded) const
{
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
        return NULL;
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

  //Modules next:
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      vector<string> mname = m_variables[var]->GetName();
      assert(mname.size() == 1);
      const Module* submod = m_variables[var]->GetModule();
      retval += indent + mname[0] + ": " + submod->GetModuleName() + "()\n";
    }
  }
  retval += ListSynchronizedVariables(indent);
  //And now subvariables that have changed names or values in submods.
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      vector<string> mname = m_variables[var]->GetName();
      assert(mname.size() == 1);
      const Module* submod = m_variables[var]->GetModule();
      const Module* origmod = g_registry.GetModule(submod->GetModuleName());
      retval += submod->ListAssignmentDifferencesFrom(origmod, mname[0], indent);
    }
  }

  //And now the definitions of all local variables:
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    var_type type = var->GetType();
    if (var->IsPointer()) continue;
    else if (IsReaction(type) || type == varInteraction) {
      retval += indent + var->GetReaction()->ToDelimitedStringWithEllipses(cc) + "\n";
    }
    else if (type == varEvent) {
      retval += indent + var->GetEvent()->ToStringDelimitedBy(cc) + "\n";
    }
    else if (type == varStrand) {
      retval += indent + var->GetNameDelimitedBy(cc) + ": " + var->GetDNAStrand()->ToStringDelimitedBy(cc) + "\n";
    }
    else if (type != varModule) {
      const Formula* form = var->GetFormula();
      if (form != NULL && !form->IsEmpty() && !form->IsEllipsesOnly()) {
        retval += indent + var->GetNameDelimitedBy(cc) + " = " + form->ToDelimitedStringWithEllipses(cc) + ";\n";
      }
    }
  }

  //Variables
  for (size_t var=0; var<m_variables.size(); var++) {
    if ((m_variables[var]->GetType() != varModule) &&
        (m_variables[var]->GetType() != varUndefined) &&
        (m_variables[var]->GetType() != varStrand) &&
        (m_variables[var]->GetType() != varEvent) &&
        (m_variables[var]->GetType() != varFormulaUndef) &&
        (m_variables[var]->GetType() != varReactionUndef) &&
        (m_variables[var]->GetType() != varInteraction) &&
        (!m_variables[var]->IsPointer())) {
      retval += indent;
      switch(m_variables[var]->GetConstType()) {
      case constVAR:
        retval += "var ";
        break;
      case constCONST:
        retval += "const ";
        break;
      case constDEFAULT:
        break;
      }
      retval += VarTypeToAntimony(m_variables[var]->GetType());
      retval += m_variables[var]->GetNameDelimitedBy(cc);
      Variable* compartment = m_variables[var]->GetCompartment();
      if (compartment != NULL) {
        if (m_variables[var]->GetIsSetCompartment()) {
          retval += " in " + compartment->GetNameDelimitedBy(cc);
        }
      }
      retval += ";\n";
    }
  }

  //Const vs. var
  string conststring = "";
  string varstring = "";
  for (size_t var=0; var<m_variables.size(); var++) {
    switch(m_variables[var]->GetConstType()) {
    case constVAR:
      if (varstring != "") {
        varstring += ", ";
      }
      varstring += m_variables[var]->GetNameDelimitedBy(cc);
      break;
    case constCONST:
      if (conststring != "") {
        conststring += ", ";
      }
      conststring += m_variables[var]->GetNameDelimitedBy(cc);
      break;
    case constDEFAULT:
      break;
    }
  }
  if (conststring != "") {
    retval += indent + "const " + conststring + ";\n";
  }
  if (varstring != "") {
    retval += indent + "var " + varstring + ";\n";
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
      retval += m_variables[var]->GetFormulaStringDelimitedBy('_') + "\n";
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
      retval += m_variables[var]->GetFormulaStringDelimitedBy('_') + "\n";
    }
    else if (m_variables[var]->GetType() == varModule) {
      retval += m_variables[var]->GetModule()->GetJarnacConstFormulas(modulename);
    }
  }
  return retval;
}

string Module::ListSynchronizedVariables(string indent) const
{
  char cc = '.';
  string list = "";
  for (size_t pair=0; pair<m_synchronized.size(); pair++) {
    list += indent + ToStringFromVecDelimitedBy(m_synchronized[pair].first, cc) + " is " + ToStringFromVecDelimitedBy(m_synchronized[pair].second, cc) + ";\n";
  }
  return list;
}

string Module::ListAssignmentDifferencesFrom(const Module* origmod, string mname, string indent) const
{
  //LS DEBUG:  Get this to work for sub-sub-modules, i.e. 'X is foo.bar.y'
  char cc = '.';
  string list = "";
  assert(GetNumVariablesOfType(allSymbols) == origmod->GetNumVariablesOfType(allSymbols));
  set<const Variable*> renamed;
  for (size_t var=0; var<GetNumVariablesOfType(allSymbols); var++) {
    const Variable* thisvar = GetNthVariableOfType(allSymbols, var);
    const Variable* origvar = origmod->GetNthVariableOfType(allSymbols, var);
    string thisform = thisvar->GetFormulaStringWithEllipses(cc);
    string origform = origvar->GetFormulaStringWithEllipses(cc);
    while (thisform.find(mname + ".") != string::npos) {
      thisform.erase(thisform.find(mname + "."), mname.size()+1);
    }
    if (thisform != origform) {
      list += indent + thisvar->GetNameDelimitedBy(cc) + " = " + thisvar->GetFormulaStringWithEllipses(cc) + ";\n";
    }
  }
  return list;
}

#ifndef NSBML
void Module::LoadSBML(const Model* sbml)
{
  string sbmlname = "";

  //Function Definitions
  //This is a bit weird, since functions exist outside of modules, since they can be used in any model.  So we have to go to the registry to save them.
  for (unsigned int func=0; func<sbml->getNumFunctionDefinitions(); func++) {
    const FunctionDefinition* function = sbml->getFunctionDefinition(func);
    sbmlname = getNameFromSBMLObject(function, "_F");
    g_registry.NewUserFunction(&sbmlname);
    string formulastring(SBML_formulaToString(function->getMath()));
    size_t charbit = formulastring.find("lambda(");
    if (charbit != string::npos) {
      formulastring.erase(charbit, 7);
      charbit = formulastring.find(",");
      while (charbit != string::npos) {
        string varstring = formulastring;
        varstring.erase(charbit, varstring.size()-charbit+1);
        Variable* expvar = g_registry.AddVariableToCurrent(&varstring);
        g_registry.AddVariableToCurrentExportList(expvar);
        formulastring.erase(0, charbit+1);
        charbit = formulastring.find(",");
      }
      formulastring.erase(formulastring.size()-1, 1); //erase the final ')'
    }
    Formula* formula = g_registry.NewBlankFormula();
    setFormulaWithString(formulastring, formula);
    g_registry.SetUserFunction(formula);
  }

  //Compartments
  for (unsigned int comp=0; comp<sbml->getNumCompartments(); comp++) {
    const Compartment* compartment = sbml->getCompartment(comp);
    sbmlname = getNameFromSBMLObject(compartment, "_C");
    if (sbmlname == DEFAULTCOMP && compartment->getConstant() && compartment->isSetSize() && compartment->getSize() == 1.0) {
      break;
      //LS NOTE: we assume this was created with Antimony, and ignore the auto-generated 'default compartment'
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    var->SetType(varCompartment);
    Formula* formula = g_registry.NewBlankFormula();
    if (compartment->isSetSize()) {
      formula->AddNum(compartment->getSize());
      var->SetFormula(formula);
    }
  }

  //Species
  for (unsigned int spec=0; spec<sbml->getNumSpecies(); spec++) {
    const Species* species = sbml->getSpecies(spec);
    sbmlname = getNameFromSBMLObject(species, "_S");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (species->getConstant()==false || species->getBoundaryCondition()==true) {
      //Antimony does not have the concept of boundary species that are not constant.  They can be pretty well modeled simply as parameters, however, so we'll do that instead.
      var->SetType(varFormulaUndef);
    }
    else {
      var->SetType(varSpeciesUndef);
    }

    //Setting the formula
    Formula* formula = g_registry.NewBlankFormula();
    if (species->isSetInitialAmount()) {
      formula->AddNum(species->getInitialAmount());
      var->SetFormula(formula);
    }
    else if (species->isSetInitialConcentration()) {
      formula->AddNum(species->getInitialConcentration());
      var->SetFormula(formula);
    }
    //Anything more complicated is set in a Rule, which we'll get to later.

    if (species->getConstant()) {
      //Since all species are variable by default, we only set this explicitly if true.
      var->SetIsConst(true);
    }
    if (species->getCompartment() != DEFAULTCOMP) {
      Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
      compartment->SetType(varCompartment);
      var->SetCompartment(compartment);
    }
  }

  //Events:
  for (unsigned int ev=0; ev<sbml->getNumEvents(); ev++) {
    const Event* event = sbml->getEvent(ev);
    sbmlname = getNameFromSBMLObject(event, "_E");
    Variable* var = AddOrFindVariable(&sbmlname);
    var->SetType(varEvent);

    //Set the trigger:
    string triggerstring(SBML_formulaToString(event->getTrigger()->getMath()));
    Formula* trigger = g_registry.NewBlankFormula();
    setFormulaWithString(triggerstring, trigger);
    AntimonyEvent antevent(*trigger,var);
    var->SetEvent(&antevent);

    //Set the assignments:
    for (unsigned int asnt=0; asnt<event->getNumEventAssignments(); asnt++) {
      const EventAssignment* assignment = event->getEventAssignment(asnt);
      Variable* asntvar = AddOrFindVariable(&(assignment->getVariable()));
      Formula*  asntform = g_registry.NewBlankFormula();
      setFormulaWithString(SBML_formulaToString(assignment->getMath()), asntform);
      var->GetEvent()->AddResult(asntvar, asntform);
    }
  }

  //LS DEBUG:  Add constraints?

  //Parameters
  for (unsigned int param=0; param<sbml->getNumParameters(); param++) {
    const Parameter* parameter = sbml->getParameter(param);
    sbmlname = getNameFromSBMLObject(parameter, "_P");
    Variable* var = AddOrFindVariable(&sbmlname);
    Formula* formula = g_registry.NewBlankFormula();
    formula->AddNum(parameter->getValue());
    var->SetFormula(formula);
    //LS DEBUG:  Some 'parameters' can vary from Rules, below, and in those cases, the value is
    // supposed to be an 'initial value'.  But I have no idea what that might mean, so we'll just
    // overwrite the formula with the rule if it happens.
  }

  //Initial Assignments:  can override 'getValue' values.
  for (unsigned int ia=0; ia<sbml->getNumInitialAssignments(); ia++) {
    const InitialAssignment* initasnt = sbml->getInitialAssignment(ia);
    if (initasnt->isSetSymbol()) {
      sbmlname = initasnt->getSymbol();
      Variable* var = AddOrFindVariable(&sbmlname);
      Formula* formula = g_registry.NewBlankFormula();
      string formulastring(SBML_formulaToString(initasnt->getMath()));
      setFormulaWithString(formulastring, formula);
      var->SetFormula(formula);
      if (var->GetType() != varSpeciesUndef) {
        //Initial assignments for non-species variables are only used when the variable is supposed to be constant, so we're going to set the constness explicitly here.  This can be overridden by an assignment rule, but that comes next.
        var->SetIsConst(true);
      }
    }
    else {
      //LS DEBUG:  error?  The 'symbol' is supposed to be required.
    }
  }
    
  //Rules:  can override 'getValue' values and 'Initial Assignment' formulas.
  for (unsigned int rulen=0; rulen<sbml->getNumRules(); rulen++) {
    const Rule* rule = sbml->getRule(rulen);
    if (rule->isAssignment()) {
      sbmlname = rule->getVariable();
      if (sbmlname == "") {
        sbmlname = getNameFromSBMLObject(rule, "_R");
      }
      Variable* var = AddOrFindVariable(&sbmlname);
      Formula* formula = g_registry.NewBlankFormula();
      string formulastring(SBML_formulaToString(rule->getMath()));
      setFormulaWithString(formulastring, formula);
      var->SetFormula(formula);
      if (var->GetType() != varSpeciesUndef) {
        //Assignment rules always mean the variable in question is not constant
        var->SetIsConst(false);
      }
    }
    else {
      //LS DEBUG:  error message?  Unable to process algebraic or rate rules
    }
  }

  //Reactions
  for (unsigned int rxn=0; rxn<sbml->getNumReactions(); rxn++) {
    const Reaction* reaction = sbml->getReaction(rxn);
    sbmlname = getNameFromSBMLObject(reaction, "_J");
    Variable* var = AddOrFindVariable(&sbmlname);
    //reactants
    ReactantList reactants;
    for (unsigned int react=0; react<reaction->getNumReactants(); react++) {
      const SpeciesReference* reactant = reaction->getReactant(react);
      double stoichiometry = 1;
      if (reactant->isSetStoichiometryMath()) {
        //LS DEBUG:  error message?
      }
      else {
        stoichiometry = reactant->getStoichiometry();
      }
      sbmlname = reactant->getSpecies();
      if (sbmlname == "") {
        sbmlname = getNameFromSBMLObject(reactant, "_S");
      }
      Variable* rvar = AddOrFindVariable(&sbmlname);
      reactants.AddReactant(rvar, stoichiometry);
    }
    //products
    ReactantList products;
    for (unsigned int react=0; react<reaction->getNumProducts(); react++) {
      const SpeciesReference* product = reaction->getProduct(react);
      double stoichiometry = 1;
      if (product->isSetStoichiometryMath()) {
        //LS DEBUG:  error message?
      }
      else {
        stoichiometry = product->getStoichiometry();
      }
      sbmlname = product->getSpecies();
      if (sbmlname == "") {
        sbmlname = getNameFromSBMLObject(product, "_S");
      }
      Variable* rvar = AddOrFindVariable(&sbmlname);
      products.AddReactant(rvar, stoichiometry);
    }
    //formula
    Formula* formula = g_registry.NewBlankFormula();
    if (reaction->isSetKineticLaw()) {
      char* formulastring = SBML_formulaToString(reaction->getKineticLaw()->getMath());
      setFormulaWithString(formulastring, formula);
      free(formulastring);
    }
    //Put all three together:
    AddNewReaction(&reactants, rdBecomes, &products, formula, var);
  }
  m_sbml = *sbml;
  FixNames();
}

Model Module::GetSBMLModel()
{
  if (m_sbml.getId() == m_modulename) {
    return m_sbml;
  }
  CreateSBMLModel();
  return m_sbml;
}

void Module::CreateSBMLModel()
{
  Model newmod(m_modulename);
  m_sbml = newmod; //clear the old one, just in case.
  char cc = g_registry.GetCC();
  //User-defined functions
  for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
    const UserFunction* userfunction = g_registry.GetNthUserFunction(uf);
    assert(userfunction != NULL);
    //FunctionDefinition* fd = m_sbml.createFunctionDefinition();
    //fd->setId(userfunction->GetModuleName());
    //fd->setMath(SBML_parseFormula(userfunction->GetFormula().ToDelimitedStringWithEllipses('.').c_str()));
    FunctionDefinition fd(userfunction->GetModuleName(), userfunction->ToSBMLString());
    m_sbml.addFunctionDefinition(&fd);
  }
  //Compartments
  Compartment* defaultCompartment = m_sbml.createCompartment();
  defaultCompartment->setId(DEFAULTCOMP);
  defaultCompartment->setConstant(true);
  defaultCompartment->setSize(1);
  for (size_t comp=0; comp<GetNumVariablesOfType(allCompartments); comp++) {
    const Variable* compartment = GetNthVariableOfType(allCompartments, comp);
    Compartment* sbmlcomp = m_sbml.createCompartment();
    sbmlcomp->setId(compartment->GetNameDelimitedBy(cc));
    sbmlcomp->setConstant(compartment->GetIsConst());
    const Formula* formula = compartment->GetFormula();
    if (formula->IsDouble()) {
      sbmlcomp->setSize(atof(formula->ToDelimitedStringWithEllipses(cc).c_str()));
    }
    else if (!formula->IsEmpty()) {
      AssignmentRule rule(compartment->GetNameDelimitedBy(cc), formula->ToDelimitedStringWithEllipses(cc));
      sbmlcomp->setConstant(false); //Requirement of SBML
      m_sbml.addRule(&rule);
    }
  }

  //Species
  for (size_t spec=0; spec < GetNumVariablesOfType(allSpecies); spec++) {
    const Variable* species = GetNthVariableOfType(allSpecies, spec);
    Species* sbmlspecies = m_sbml.createSpecies();
    sbmlspecies->setId(species->GetNameDelimitedBy(cc));
    if (species->GetIsConst()) {
      sbmlspecies->setBoundaryCondition(true);
      sbmlspecies->setConstant(true);
    }
    const Formula* formula = species->GetFormula();
    if (formula->IsDouble()) {
      sbmlspecies->setInitialConcentration(atof(formula->ToDelimitedStringWithEllipses(cc).c_str()));
    }
    else if (!formula->IsEmpty()) {
      //create a rule
      InitialAssignment rule;
      rule.setSymbol(species->GetNameDelimitedBy(cc));
      rule.setMath(SBML_parseFormula(formula->ToDelimitedStringWithEllipses(cc).c_str()));
      m_sbml.addInitialAssignment(&rule);
    }
    const Variable* compartment = species->GetCompartment();
    if (compartment == NULL) {
      sbmlspecies->setCompartment(defaultCompartment->getId());
    }
    else {
      sbmlspecies->setCompartment(compartment->GetNameDelimitedBy(cc));
    }
  }

  //Formulas
  for (size_t form=0; form < GetNumVariablesOfType(allFormulas); form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form);
    const Formula*  formula = formvar->GetFormula();
    Parameter* param = m_sbml.createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    param->setConstant(formvar->GetIsConst());
    if (formula->IsDouble()) {
      param->setValue(atof(formula->ToDelimitedStringWithEllipses(cc).c_str()));
    }
    else if (!formula->IsEmpty()) {
      if (formvar->GetIsConst()) {
        InitialAssignment ia(formvar->GetNameDelimitedBy(cc));
        ia.setMath(SBML_parseFormula(formula->ToDelimitedStringWithStrands(cc, formvar->GetStrandVars()).c_str()));
        m_sbml.addInitialAssignment(&ia);
      }
      else {
        //create a rule
        AssignmentRule rule(formvar->GetNameDelimitedBy(cc), formula->ToDelimitedStringWithStrands(cc, formvar->GetStrandVars()));
        m_sbml.addRule(&rule);
      }
    }
  }

  //Reactions
  for (size_t rxn=0; rxn < GetNumVariablesOfType(allReactions); rxn++) {
    const Variable* rxnvar = GetNthVariableOfType(allReactions, rxn);
    const AntimonyReaction* reaction = rxnvar->GetReaction();
    if (reaction->IsEmpty()) {
      continue; //Reactions that involve no species are illegal in SBML.
    }
    Reaction sbmlrxn(rxnvar->GetNameDelimitedBy(cc), "", NULL, false);
    const Formula* formula = reaction->GetFormula();
    string formstring = formula->ToDelimitedStringWithStrands(cc, rxnvar->GetStrandVars());
    if (!formula->IsEmpty()) {
      KineticLaw kl(formstring);
      sbmlrxn.setKineticLaw(&kl);
    }
    const ReactantList* left = reaction->GetLeft();
    for (size_t lnum=0; lnum<left->Size(); lnum++) {
      const Variable* nthleft = left->GetNthReactant(lnum);
      double nthstoich = left->GetStoichiometryFor(lnum);
      SpeciesReference sr(nthleft->GetNameDelimitedBy(cc), nthstoich);
      sbmlrxn.addReactant(&sr);
    }
    const ReactantList* right = reaction->GetRight();
    for (size_t rnum=0; rnum<right->Size(); rnum++) {
      const Variable* nthright = right->GetNthReactant(rnum);
      double nthstoich = right->GetStoichiometryFor(rnum);
      SpeciesReference sr(nthright->GetNameDelimitedBy(cc), nthstoich);
      sbmlrxn.addProduct(&sr);
    }
    //Find 'modifiers' and add them.
    vector<const Variable*> subvars = formula->GetVariablesFrom(formstring, m_modulename);
    for (size_t v=0; v<subvars.size(); v++) {
      if (subvars[v] != NULL && subvars[v]->GetType() == varSpeciesUndef) {
        if (left->GetStoichiometryFor(subvars[v]) == 0 &&
            right->GetStoichiometryFor(subvars[v]) == 0) {
          ModifierSpeciesReference msr(subvars[v]->GetNameDelimitedBy(cc));
          sbmlrxn.addModifier(&msr);
        }
      }
    }
    m_sbml.addReaction(&sbmlrxn);
  }

  //Events
  for (size_t ev=0; ev < GetNumVariablesOfType(allEvents); ev++) {
    const AntimonyEvent* event = GetNthVariableOfType(allEvents, ev)->GetEvent();
    Event* sbmlevent = m_sbml.createEvent();
    ASTNode_t* ASTtrig = SBML_parseFormula(event->GetTrigger()->ToSBMLString().c_str());
    Trigger trigger(ASTtrig);
    delete ASTtrig;
    sbmlevent->setTrigger(&trigger);
    for (size_t asnt=0; asnt<event->GetNumAssignments(); asnt++) {
      EventAssignment* sbmlasnt = m_sbml.createEventAssignment();
      sbmlasnt->setVariable(event->GetNthAssignmentVariableName(asnt, cc));
      ASTNode_t* ASTasnt = SBML_parseFormula(event->GetNthAssignmentFormulaString(asnt, '_', true).c_str());
      sbmlasnt->setMath(ASTasnt);
      delete ASTasnt;
    }
  }

  //Unknown variables (turn into parameters)
  for (size_t form=0; form < GetNumVariablesOfType(allUnknown); form++) {
    const Variable* formvar = GetNthVariableOfType(allUnknown, form);
    Parameter* param = m_sbml.createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
  }
}
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
  
}

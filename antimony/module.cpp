#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

#include "module.h"
#include "variable.h"
#include "registry.h"

extern Registry g_registry;

using namespace std;

Module::Module(string name)
  : m_modulename(name),
    m_variablename(),
    m_variables(),
    m_exportlist(),
    m_returnvalue(),
    m_currentexportvar(0),
    m_uniquevars(),
    m_rxnleftvarnames(),
    m_rxnrightvarnames(),
    m_rxnleftstoichiometries(),
    m_rxnrightstoichiometries()
{
}

Module::Module(const Module& src, string newtopname, string modulename)
  : m_modulename(src.m_modulename),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_exportlist(src.m_exportlist),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(0),
    m_uniquevars(),
    m_rxnleftvarnames(),
    m_rxnrightvarnames(),
    m_rxnleftstoichiometries(),
    m_rxnrightstoichiometries()
{
  SetNewTopName(modulename, newtopname);
  //CompileExportLists();
}

Module::Module(const Module& src)
  : m_modulename(src.m_modulename),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_exportlist(src.m_exportlist),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(src.m_currentexportvar),
    m_uniquevars(),
    m_rxnleftvarnames(),
    m_rxnrightvarnames(),
    m_rxnleftstoichiometries(),
    m_rxnrightstoichiometries()
{
  //CompileExportLists();
}


Variable* Module::AddOrFindVariable(const string* name)
{
  vector<string> fullname;
  fullname.push_back(*name);
  Variable* foundvar = GetVariable(fullname);
  if (foundvar == NULL) {
    //Didn't find one--need to create a new one.
    Variable newvar(*name, this);
    m_variables.push_back(newvar);
    foundvar = &(m_variables.back());
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
  Variable newvar(newvarname, this);
  m_variables.push_back(newvar);
  return &(m_variables.back());
}

void Module::AddVariableToExportList(Variable* var)
{
  m_exportlist.push_back(var->GetName());
}

Reaction* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula)
{
  Variable* newrxn = AddNewNumberedVariable("_J");
  return AddNewReaction(left, divider, right, formula, newrxn);
}

Reaction* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var)
{
  left->SetVarsTo(varSpeciesUndef);
  switch(divider) {
  case rdBecomes:
    right->SetVarsTo(varSpeciesUndef);
    break;
  case rdActivates:
  case rdInhibits:
  case rdInfluences:
    right->SetVarsTo(varDNA);
    right ->CheckIsSingleDNAVar();
    formula->CheckIncludes(m_modulename, left);
    right->GetSingleVar()->SetFormula(formula);
    break;
  }
  Reaction newrxn(*left, divider, *right, *formula, var);
  return var->SetReaction(&newrxn);
}

void Module::SetFormula(Formula* formula)
{
  GetVariable(m_returnvalue)->SetFormula(formula);
}

Variable* Module::GetVariable(vector<string> name)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].GetName() == name) {
      return (&(m_variables[var]));
    }
    if (m_variables[var].GetType() == varModule) {
      Variable* subvar = m_variables[var].GetModule()->GetVariable(name);
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
    if (m_variables[var].GetName() == name) {
      return (&(m_variables[var]));
    }
    if (m_variables[var].GetType() == varModule) {
      const Variable* subvar = m_variables[var].GetModule()->GetVariable(name);
      if (subvar != NULL) {
        return subvar;
      }
    }
  }
  return NULL;
}

Variable* Module::GetSubVariable(const string* name)
{
  vector<string> subvarname = m_variablename;
  subvarname.push_back(*name);
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].GetName() == subvarname) {
      return (&(m_variables[var]));
    }
  }
  return NULL;
}

Variable* Module::GetReactionVariable()
{
  return GetVariable(m_currentrxnvar);
}

const Formula* Module::GetFormula() const
{
  const Variable* retvar = GetVariable(m_returnvalue);
  if (retvar != NULL) {
    return GetVariable(m_returnvalue)->GetFormula();
  }
  //otherwise throw an error  LS DEBUG
  return NULL;
}

Formula* Module::GetFormula()
{
  Variable* retvar = GetVariable(m_returnvalue);
  if (retvar != NULL) {
    return GetVariable(m_returnvalue)->GetFormula();
  }
  //otherwise throw an error  LS DEBUG
  return NULL;
}

Variable* Module::GetNextExportVariable()
{
  if (m_currentexportvar > m_exportlist.size() - 1) {
    //LS DEBUG:  User error
    assert(false);
  }
  size_t exp = m_currentexportvar;
  m_currentexportvar++;
  return GetVariable(m_exportlist[exp]);
}

Variable* Module::GetUpstreamDNA()
{
  Variable* retvar = NULL;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].HasOpenUpstream()) {
      if (retvar != NULL) {
        assert(false); //throw an error:  LS DEBUG
      }
      retvar = &(m_variables[var]);
    }
  }
  if (retvar==NULL) {
    assert(false); //throw an error:  LS DEBUG
  }
  return retvar;
}

Variable* Module::GetDownstreamDNA()
{
  Variable* retvar = NULL;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].HasOpenDownstream()) {
      if (retvar != NULL) {
        assert(false); //throw an error:  LS DEBUG
      }
      retvar = &(m_variables[var]);
    }
  }
  if (retvar==NULL) {
    assert(false); //throw an error:  LS DEBUG
  }
  return retvar;
}

const string& Module::GetModuleName() const
{
  return m_modulename;
}

vector<string> Module::GetVariableName() const
{
  return m_variablename;
}

void Module::SetNewTopName(string newmodname, string newtopname)
{
  m_variablename.insert(m_variablename.begin(), newtopname);
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var].SetNewTopName(newmodname, newtopname);
  }
  for (size_t var=0; var<m_exportlist.size(); var++) {
    m_exportlist[var].insert(m_exportlist[var].begin(), newtopname);
  }
}

void Module::SetReactionVariable(Variable* var)
{
  m_currentrxnvar = var->GetName();
}

void Module::ImportModule(const string* modname)
{
  Variable* newmod = AddNewNumberedVariable("_sys");
  newmod->ImportModule(modname);
}

string Module::ToString() const
{
  string retval = "Module name:  ";
  retval += m_modulename + "\n" + "Variables: ";
  if (m_variables.size() > 0) {
    retval += m_variables[0].ToString();
  }
  for (size_t var=1; var<m_variables.size(); var++) {
    retval += ",  " + m_variables[var].ToString();
  }
  retval += "\nReactions:  ";
  for (size_t var=0; var<m_variables.size(); var++) {
    if (IsReaction(m_variables[var].GetType())) {
      retval += m_variables[var].GetReaction()->ToStringDelimitedBy('.');
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
    if (m_variables[var].GetType() == varModule) {
      retval += m_variables[var].GetModule()->ToString();
    }
  }

  return retval;
}

string Module::GetJarnacReactions() const
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (IsReaction(m_variables[var].GetType()) &&
        !m_variables[var].IsPointer()) {
      retval += "  " + m_variables[var].GetReaction()->ToStringDelimitedBy('_') + "\n";
    }
    else if (m_variables[var].GetType() == varModule) {
      retval += m_variables[var].GetModule()->GetJarnacReactions();
    }
  }
  return retval;
}

string Module::GetJarnacVarFormulas()
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    var_type type = m_variables[var].GetType();
    if (!m_variables[var].IsPointer() &&
        (HasOrIsFormula(type) && m_variables[var].HasFormula() && !m_variables[var].GetIsConst())) {
      retval += "  ";
      retval += m_variables[var].GetNameDelimitedBy('_') + " = ";
      retval += m_variables[var].GetFormulaStringDelimitedBy('_') + "\n";
    }
    else if (m_variables[var].GetType() == varModule) {
      retval += m_variables[var].GetModule()->GetJarnacVarFormulas();
    }
  }
  return retval;
}

string Module::GetJarnacConstFormulas(string modulename)
{
  string retval;
  for (size_t var=0; var<m_variables.size(); var++) {
    var_type type = m_variables[var].GetType();
    if (!m_variables[var].IsPointer() &&
        (HasOrIsFormula(type) && m_variables[var].HasFormula() && m_variables[var].GetIsConst())) {
      retval += modulename + ".";
      retval += m_variables[var].GetNameDelimitedBy('_') + " = ";
      retval += m_variables[var].GetFormulaStringDelimitedBy('_') + "\n";
    }
    else if (m_variables[var].GetType() == varModule) {
      retval += m_variables[var].GetModule()->GetJarnacConstFormulas(modulename);
    }
  }
  return retval;
}

void Module::CompileExportLists()
{
  m_uniquevars.clear();
  m_rxnleftvarnames.clear();
  m_rxnrightvarnames.clear();
  m_rxnleftstoichiometries.clear();
  m_rxnrightstoichiometries.clear();
  m_dna.clear();

  //Phase 0:  Error checking for loops
  for (size_t var=0; var<m_variables.size(); var++) {
    //If this is a submodule, we'll be calling the error checking bit soon,
    // so don't worry about it.
    //LS DEBUG:  This doesn't actually work.
    //assert(m_variables[var].CheckDoesNotIncludeSelf()); //LS DEBUG: throw error
  }
  //Store the data locally so we don't have to search sub-modules every time
  // we want to hand out information
  set<string> varnames;
  char cc = '_';
  pair<set<string>::iterator, bool> nameret;
  for (size_t var=0; var<m_variables.size(); var++) {
    pair<pair<string,string>, pair<string,string> > newvar;
    newvar.first.first = m_variables[var].GetNameDelimitedBy(cc);
    newvar.first.second = "";
    if (m_variables[var].GetFormula() != NULL) {
      newvar.first.second = m_variables[var].GetFormulaStringDelimitedBy(cc);
    }
    newvar.second.first = VarTypeToString(m_variables[var].GetType());
    if (m_variables[var].GetIsConst()) {
      newvar.second.second = "const";
    }
    else {
      newvar.second.second = "var";
    }
    nameret = varnames.insert(newvar.first.first);
    if (nameret.second || m_variables[var].GetListSeparately()) {
      m_uniquevars.push_back(m_variables[var].GetName());
      if (IsReaction(m_variables[var].GetType())) {
        const Reaction* rxn = m_variables[var].GetReaction();
        if (rxn->GetType() == rdBecomes) {
          m_rxnleftvarnames.push_back(rxn->LeftToStringVecDelimitedBy(cc));
          m_rxnrightvarnames.push_back(rxn->RightToStringVecDelimitedBy(cc));
          m_rxnleftstoichiometries.push_back(rxn->GetLeftStoichiometries());
          m_rxnrightstoichiometries.push_back(rxn->GetRightStoichiometries());
        }
      }
      if (m_variables[var].IsDNAStart()) {
        m_dna.push_back(m_variables[var].GetDNAStringDelimitedBy(cc));
      }
      if (m_variables[var].GetType() == varModule) {
        Module* submod = m_variables[var].GetModule();
        submod->CompileExportLists();
        //Copy over what we've just created:
        vector<vector<string> > subvars = submod->m_uniquevars;
        //And put them in our own vectors, if we don't have them already.
        for (size_t nsubvar=0; nsubvar<subvars.size(); nsubvar++) {
          Variable* subvar = GetVariable(subvars[nsubvar]);
          nameret = varnames.insert(subvar->GetNameDelimitedBy(cc));
          if (nameret.second) { //Or GetListSeparately()?  LS DEBUG
            m_uniquevars.push_back(submod->m_uniquevars[nsubvar]);
            if (IsReaction(subvar->GetType())) {
              //Find the reaction and add it.
              const Reaction* rxn = subvar->GetReaction();
              if (rxn->GetType() == rdBecomes) {
                //but only if it's a stoichiometry matrix reaction
                m_rxnleftvarnames.push_back(rxn->LeftToStringVecDelimitedBy(cc));
                m_rxnrightvarnames.push_back(rxn->RightToStringVecDelimitedBy(cc));
                m_rxnleftstoichiometries.push_back(rxn->GetLeftStoichiometries());
                m_rxnrightstoichiometries.push_back(rxn->GetRightStoichiometries());
              }
            }
          }
        }
        //vector<vector<string> > dna = submod->m_dna;
        m_dna.insert(m_dna.end(), submod->m_dna.begin(), submod->m_dna.end());
      }
    }
  }
}

size_t Module::GetNumVariablesOfType(return_type rtype)
{
  size_t total = 0;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    if (AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetType()) &&
        AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetIsConst())) {
      total++;
    }
  }
  return total;
}

const Variable* Module::GetNthVariableOfType(return_type rtype, size_t n)
{
  size_t total = 0;
  for (size_t var=0; var<m_uniquevars.size(); var++) {
    if (AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetType()) &&
        AreEquivalent(rtype, GetVariable(m_uniquevars[var])->GetIsConst())) {
      if (total == n) {
        return GetVariable(m_uniquevars[var]);
      }
      total++;
    }
  }
  //LS DEBUG:  THROW AN ERROR
  assert(false);
  return NULL;
}



bool Module::AreEquivalent(return_type rtype, var_type vtype)
{
  switch (rtype) {
  case varSpecies:
  case constSpecies:
    if (vtype == varSpeciesUndef ||
        vtype == varSpeciesProtein) {
      return true;
    }
    return false;
  case varProteins:
  case constProteins:
    if (vtype == varSpeciesProtein) {
      return true;
    }
    return false;
  case varFormulas:
  case constFormulas:
    if (vtype == varFormulaUndef ||
        vtype == varDNA ||
        vtype == varFormulaPromoter ||
        vtype == varFormulaOperator) {
      return true;
    }
    return false;
  case varAnyDNA:
  case constAnyDNA:
    if (vtype == varDNA ||
        vtype == varFormulaPromoter ||
        vtype == varFormulaOperator ||
        vtype == varReactionGene) {
      return true;
    }
    return false;
  case varPromoters:
  case constPromoters:
    if (vtype == varFormulaPromoter) {
      return true;
    }
    return false;
  case varOperators:
  case constOperators:
    if (vtype == varFormulaOperator) {
      return true;
    }
    return false;
  case varGenes:
  case constGenes:
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
  }
  //This is just to to get compiler warnings if we switch vtype later, so
  // we remember to change the rest of this function:
  switch(vtype) {
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varFormulaUndef:
  case varDNA:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
  case varUndefined:
  case varModule:
    break;
  }
  assert(false); //uncaught return type
  return false;
}

bool Module::AreEquivalent(return_type rtype, bool isconst)
{
  switch (rtype) {
  case varSpecies:
  case varProteins:
  case varFormulas:
  case varAnyDNA:
  case varPromoters:
  case varOperators:
  case varGenes:
    return (!isconst);
  case constSpecies:
  case constProteins:
  case constFormulas:
  case constAnyDNA:
  case constPromoters:
  case constOperators:
  case constGenes:
    return (isconst);
  case allSymbols:
  case allUnknown:
  case allReactions:
  case allInteractions:
  case subModules:
    return true;
  }
  assert(false); //uncaught return_type
  return false;
}

var_type Module::GetTypeFor(std::string varname)
{
  for (size_t v=0; v<m_uniquevars.size(); v++) {
    Variable* var = GetVariable(m_uniquevars[v]);
    if (varname == var->GetNameDelimitedBy(g_registry.GetCC())) {
      return var->GetType();
    }
  }
  assert(false); //unknown variable
  return varUndefined;
}

bool Module::IsConst(std::string varname)
{
  for (size_t v=0; v<m_uniquevars.size(); v++) {
    Variable* var = GetVariable(m_uniquevars[v]);
    if (varname == var->GetNameDelimitedBy(g_registry.GetCC())) {
      return var->GetIsConst();
    }
  }
  assert(false); //unknown variable
  return false;
}

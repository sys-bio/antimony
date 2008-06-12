#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

#include "module.h"
#include "variable.h"

using namespace std;

Module::Module(string name)
  : m_modulename(name),
    m_variablename(),
    m_variables(),
    m_exportlist(),
    m_returnvalue(),
    m_currentexportvar(0),
    m_varsntypes(),
    m_variablenames(),
    m_variabletypes()
{
}

Module::Module(const Module& src, string newtopname, string modulename)
  : m_modulename(src.m_modulename),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_exportlist(src.m_exportlist),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(0),
    m_varsntypes(),
    m_variablenames(),
    m_variabletypes()
{
  SetNewTopName(newtopname);
  SetNamespace(modulename);
  //CompileExportLists();
}

Module::Module(const Module& src)
  : m_modulename(src.m_modulename),
    m_variablename(src.m_variablename),
    m_variables(src.m_variables),
    m_exportlist(src.m_exportlist),
    m_returnvalue(src.m_returnvalue),
    m_currentexportvar(src.m_currentexportvar),
    m_varsntypes(),
    m_variablenames(),
    m_variabletypes()
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
    formula->CheckIncludes(left);
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

void Module::SetNewTopName(string newtopname)
{
  m_variablename.insert(m_variablename.begin(), newtopname);
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var].SetNewTopName(newtopname);
  }
  for (size_t var=0; var<m_exportlist.size(); var++) {
    m_exportlist[var].insert(m_exportlist[var].begin(), newtopname);
  }
}

void Module::SetNamespace(string modulename)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    m_variables[var].SetNamespace(modulename);
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
  //Phase 0:  Error checking for loops
  for (size_t var=0; var<m_variables.size(); var++) {
    //If this is a submodule, we'll be calling the error checking bit soon,
    // so don't worry about it.
    //LS DEBUG:  This doesn't actually work.
    //assert(m_variables[var].CheckDoesNotIncludeSelf()); //LS DEBUG: throw error
  }
  //Phase 1:  Store the data locally (mostly so we can have consistent pointers for strings)
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
      m_varsntypes.push_back(newvar);
      if (IsReaction(m_variables[var].GetType())) {
        vector<string> rxn = m_variables[var].GetReaction()->ToStringVecDelimitedBy(cc);
        rxn.insert(rxn.begin(),newvar.first.first);
        m_reactionvarnames.push_back(rxn);
        m_leftstoichiometries.push_back(m_variables[var].GetReaction()->GetLeftStoichiometries());
        m_rightstoichiometries.push_back(m_variables[var].GetReaction()->GetRightStoichiometries());
      }
      else if (m_variables[var].IsDNAStart()) {
        m_dna.push_back(m_variables[var].GetDNAStringDelimitedBy(cc));
      }
      else if (m_variables[var].GetType() == varModule) {
        Module* submod = m_variables[var].GetModule();
        submod->CompileExportLists();
        //Copy over what we've just created:
        vector<pair<pair<string,string>, pair<string,string> > > subvarsntypes = submod->m_varsntypes;
        vector<vector<string> > rxnvarnames = submod->m_reactionvarnames;
        vector<vector<double> > lstoichs = submod->m_leftstoichiometries;
        vector<vector<double> > rstoichs = submod->m_rightstoichiometries;
        //And put it in our own vectors, if we don't have them already.
        for (size_t subvar=0; subvar<subvarsntypes.size(); subvar++) {
          nameret = varnames.insert(subvarsntypes[subvar].first.first);
          if (nameret.second) {
            m_varsntypes.push_back(subvarsntypes[subvar]);
            if (IsReaction(subvarsntypes[subvar].second.first)) {
              //Find the reaction and add it.
              for (size_t subrxn=0; subrxn<rxnvarnames.size(); subrxn++) {
                if (rxnvarnames[subrxn][0] == subvarsntypes[subvar].first.first) {
                  m_reactionvarnames.push_back(rxnvarnames[subrxn]);
                  m_leftstoichiometries.push_back(lstoichs[subrxn]);
                  m_rightstoichiometries.push_back(rstoichs[subrxn]);
                  break;
                }
              }
            }
          }
        }
        vector<vector<string> > dna = submod->m_dna;
        m_dna.insert(m_dna.end(), dna.begin(), dna.end());
      }
    }
  }
  
  //Phase 2:  Store the data for export (vectorize the char* pointers to strings)

  //Sorting lets us hand out sub-vectors without duplicating storage.
  std::sort(m_varsntypes.begin(), m_varsntypes.end(), VarsNTypesSort);
  
  for (size_t var=0; var<m_varsntypes.size(); var++) {
    m_variablenames.push_back(m_varsntypes[var].first.first.c_str());
    m_variableformulas.push_back(m_varsntypes[var].first.second.c_str());
    m_variabletypes.push_back(m_varsntypes[var].second.first.c_str());
    m_variableconsts.push_back(m_varsntypes[var].second.second.c_str());
  }
  for (size_t rxn=0; rxn<m_reactionvarnames.size(); rxn++) {
    vector<const char*> leftnames;
    vector<const char*> rightnames;
    bool left=true;
    for (size_t var=1; var<m_reactionvarnames[rxn].size()-2; var++) {
      if (m_reactionvarnames[rxn][var] == "->" ||
          m_reactionvarnames[rxn][var] == "-|" ||
          m_reactionvarnames[rxn][var] == "-o" ||
          m_reactionvarnames[rxn][var] == "-(") {
        left = false;
        m_rxndividers.push_back(m_reactionvarnames[rxn][var].c_str());
      }
      else if (left) {
        leftnames.push_back(m_reactionvarnames[rxn][var].c_str());
      }
      else {
        rightnames.push_back(m_reactionvarnames[rxn][var].c_str());
      }
    }
    m_rxnnames.push_back(m_reactionvarnames[rxn][0].c_str());
    m_rxnrates.push_back(m_reactionvarnames[rxn][m_reactionvarnames[rxn].size()-1].c_str());
    m_leftnames.push_back(leftnames);
    m_rightnames.push_back(rightnames);
    m_leftstoichpointers.push_back(&(m_leftstoichiometries[rxn][0]));
    m_rightstoichpointers.push_back(&(m_rightstoichiometries[rxn][0]));
    m_leftsizes.push_back(leftnames.size());
    m_rightsizes.push_back(rightnames.size());
  }
  assert(m_leftnames.size() == m_rightnames.size());
  for (size_t rxn=0; rxn<m_leftnames.size(); rxn++) {
    m_leftnamepointers.push_back(&m_leftnames[rxn][0]);
    m_rightnamepointers.push_back(&m_rightnames[rxn][0]);
  }

  for (size_t strand=0; strand<m_dna.size(); strand++) {
    vector<const char*> strandvec;
    for (size_t element=0; element<m_dna[strand].size(); element++) {
      strandvec.push_back(m_dna[strand][element].c_str());
    }
    m_dnapointers.push_back(strandvec);
  }
  for(size_t strand=0; strand<m_dnapointers.size(); strand++) {
    m_dnalengths.push_back(m_dna[strand].size());
    m_dnanames.push_back(&(m_dnapointers[strand][0]));
  }
    
}

size_t Module::GetFirstVariableIndexForType(return_type rtype)
{
  for (size_t var=0; var<m_variabletypes.size(); var++) {
    if (AreEquivalent(rtype, StringToVarType(m_variabletypes[var])) &&
        AreEquivalent(rtype, m_variableconsts[var]==string("const"))) {
      return var;
    }
  }
  return 0; //I think this is the safest
}

size_t Module::GetNumVariablesOfType(return_type rtype)
{
  size_t total = 0;
  for (size_t var=0; var<m_variabletypes.size(); var++) {
    if (AreEquivalent(rtype, StringToVarType(m_variabletypes[var])) &&
        AreEquivalent(rtype, m_variableconsts[var]==string("const"))) {
      total++;
    }
  }
  return total;
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
  case varReactions:
  case constReactions:
    if (vtype == varReactionGene ||
        vtype == varReactionUndef) {
      return true;
    }
    return false;
  case varUnknown:
  case constUnknown:
    if (vtype == varUndefined) {
      return true;
    }
    return false;
  case subModules:
    if (vtype == varModule) {
      return true;
    }
    return false;
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
  case varReactions:
  case varUnknown:
    return (!isconst);
  case constSpecies:
  case constProteins:
  case constFormulas:
  case constAnyDNA:
  case constPromoters:
  case constOperators:
  case constGenes:
  case constReactions:
  case constUnknown:
    return (isconst);
  case subModules:
    return true;
  }
  assert(false); //uncaught return_type
  return false;
}

bool VarsNTypesSort(pair<pair<string,string>, pair<string,string> > v1, pair<pair<string,string>, pair<string,string> > v2)
{
  if (v1.second.second == "var" && v2.second.second=="const") {
    return true;
  }
  if (v2.second.second == "var" && v1.second.second=="const") {
    return false;
  }
  
  if (v1.second.first == v2.second.first) {
    return (v1.first.first < v2.first.first);
  }
  var_type v1type = StringToVarType(v1.second.first);
  var_type v2type = StringToVarType(v2.second.first);
  return (v1type < v2type);
}

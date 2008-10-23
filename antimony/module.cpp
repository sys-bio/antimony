#include <algorithm>
#include <functional>
#include <iostream>
#include <set>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"

extern Registry g_registry;

using namespace std;

Module::Module(string name)
  : m_modulename(name),
    m_variablename(),
    m_variables(),
    m_exportlist(),
    m_returnvalue(),
    m_currentexportvar(0),
    m_sbml(name + "-unset"),
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
    m_sbml(src.m_sbml),
    m_uniquevars(),
    m_rxnleftvarnames(),
    m_rxnrightvarnames(),
    m_rxnleftstoichiometries(),
    m_rxnrightstoichiometries()
{
  SetNewTopName(modulename, newtopname);
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

AntimonyReaction* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula)
{
  Variable* newrxn = AddNewNumberedVariable("_J");
  return AddNewReaction(left, divider, right, formula, newrxn);
}

AntimonyReaction* Module::AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var)
{
  string err = "When defining reaction '" + var->GetNameDelimitedBy('.') + "':  ";
  if (left->SetVarsTo(varSpeciesUndef)) {
    g_registry.SetError(err + g_registry.GetError());
    return NULL;
  }
  switch(divider) {
  case rdBecomes:
    if (right->SetVarsTo(varSpeciesUndef)) {
      g_registry.SetError(err + g_registry.GetError());
      return NULL;
    }
    break;
  case rdActivates:
  case rdInhibits:
  case rdInfluences:
    if (right ->CheckIsSingleDNAOrReaction()) {
      g_registry.SetError(err + g_registry.GetError());
      return NULL;
    }
    if (right->GetSingleVar()->SetFormula(formula)) return NULL;
    break;
  }
  AntimonyReaction newrxn(*left, divider, *right, *formula, var);
  if (formula->ContainsVar(var)) {
    g_registry.SetError("The definition of reaction '" + var->GetNameDelimitedBy('.') + "' contains a reference to itself directly or indirectly in its reaction rate (" + formula->ToStringDelimitedBy('.') + ").");
    return NULL;
  }
  return var->SetReaction(&newrxn);
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
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].HasOpenUpstream()) {
      if (retvar != NULL) {
        g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has multiple sites at which to attach upstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in 'NEWDNA--" + m_variables[var].GetNameDelimitedBy('.') + "'.");
        return NULL;
      }
      retvar = &(m_variables[var]);
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has no 'open ends' at which to attach DNA.");
    return NULL;
  }
  return retvar;
}

const Variable* Module::GetUpstreamDNA() const
{
  const Variable* retvar = NULL;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].HasOpenUpstream()) {
      if (retvar != NULL) {
        g_registry.SetError("Unable to attach DNA upstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has multiple sites at which to attach upstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in 'NEWDNA--" + m_variables[var].GetNameDelimitedBy('.') + "'.");
        return NULL;
      }
      retvar = &(m_variables[var]);
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
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].HasOpenDownstream()) {
      if (retvar != NULL) {
        g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has multiple sites at which to attach downstream DNA.  To attach DNA to a particular strand of DNA within this module, mention it explicitly, as in '" + m_variables[var].GetNameDelimitedBy('.') + "--NEWDNA'.");
        return NULL;
      }
      retvar = &(m_variables[var]);
    }
  }
  if (retvar==NULL) {
    g_registry.SetError("Unable to attach DNA downstream of module '" + GetVariableNameDelimitedBy('.') + "', because this module has no 'open ends' at which to attach DNA.");
    return NULL;
  }
  return retvar;
}

vector<string> Module::GetNewCrossModuleDNALinks() const
{
  vector<string> newlinks;
  for (size_t var=0; var<m_variables.size(); var++) {
    const Variable* downvar = m_variables[var].GetDownstreamDNA();
    if (downvar != NULL && downvar->GetName().size() > 1) {
      vector<string> origname = m_variables[var].GetName();
      origname.erase(origname.begin());
      const Variable* origvar = g_registry.GetModule(m_modulename)->GetVariable(origname);
      const Variable* origdown = origvar->GetDownstreamDNA();
      if (!(downvar->IsSameVarInNewModule(origdown))) {
        string upname = m_variables[var].GetNameDelimitedBy('.');
        string downname = downvar->GetNameDelimitedBy('.');
        if (&m_variables[var] == g_registry.GetModule(m_variables[var].GetNamespace())->GetDownstreamDNA()) {
          upname = ToStringFromVecDelimitedBy(m_variablename, '.');
        }
        const Module* downmod = g_registry.GetModule(downvar->GetNamespace());
        if (downvar == downmod->GetUpstreamDNA()) {
          downname = downmod->GetVariableNameDelimitedBy('.');
        }
        newlinks.push_back(m_variables[var].GetNameDelimitedBy('.') + "--" + downvar->GetNameDelimitedBy('.'));
      }
    }
  }
  return newlinks;
}

const string& Module::GetModuleName() const
{
  return m_modulename;
}

vector<string> Module::GetVariableName() const
{
  return m_variablename;
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

bool Module::SetModule(const string* modname)
{
  Variable* newmod = AddNewNumberedVariable("_sys");
  return newmod->SetModule(modname);
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

string Module::GetAntimony(set<const Module*> usedmods) const
{
  string retval;
  //First, we need any submodules
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].GetType() == varModule) {
      const Module* mod = g_registry.GetModule(m_variables[var].GetModule()->GetModuleName());
      if (mod==NULL) {
        g_registry.SetError("Unable to find base module " + m_variables[var].GetModule()->GetModuleName() + ".");
        return NULL;
      }
      if ((usedmods.insert(mod)).second) {
        //New module; add it.
        retval += mod->GetAntimony(usedmods) + "\n";
      }
    }
  }
  string indent = "";
  //Module definition
  if (m_modulename != "[main]") {
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

  //Variables
  for (size_t var=0; var<m_variables.size(); var++) {
    if ((m_variables[var].GetType() != varModule) &&
        (m_variables[var].GetType() != varUndefined)) {
      retval += indent;
      if (m_variables[var].GetIsConst()) {
        retval += "const ";
      }
      switch(m_variables[var].GetType()) {
      case varSpeciesUndef:
        retval += "species ";
        break;
      case varFormulaUndef:
        retval += "formula ";
        break;
      case varReactionUndef:
        retval += "reaction ";
        break;
      case varReactionGene:
        retval += "gene ";
        break;
      case varInteraction:
        retval += "reaction ";
        break;
      case varFormulaOperator:
        retval += "operator ";
        break;
      case varDNA:
        retval += "DNA ";
        break;
      case varEvent:
        retval += "event ";
      case varModule:
      case varUndefined:
        //handled earlier
        break;
      }
      vector<string> vname = m_variables[var].GetName();
      assert(vname.size()==1);
      retval += vname[0] + ";\n";
    }
  }

  //Modules next:
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].GetType() == varModule) {
      vector<string> mname = m_variables[var].GetName();
      assert(mname.size() == 1);
      const Module* submod = m_variables[var].GetModule();
      const Module* origmod = g_registry.GetModule(submod->GetModuleName());
      retval += indent + mname[0] + ": " + submod->GetModuleName() + "(";
      retval += submod->ListIdentityDifferencesFrom(origmod, mname[0]);
      retval += ")\n";
      retval += submod->ListAssignmentDifferencesFrom(origmod, mname[0], indent);
    }
  }

  //Any linked DNA:
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].IsDNAStartForModule()) {
      retval += indent + m_variables[var].GetDNAStringForThisNamespace() + "\n";
    }
  }

  //Any linked DNA cross-module!  Yarr.
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var].GetType() == varModule) {
      vector<string> links = m_variables[var].GetModule()->GetNewCrossModuleDNALinks();
      for (size_t link = 0; link<links.size(); link++) {
        retval += indent + links[link] + "\n";
      }
    }
  }

  //And now the definitions of all local variables:
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = &m_variables[vnum];
    var_type type = var->GetType();
    if (IsReaction(type)) {
      retval += indent + var->GetReaction()->ToDelimitedStringWithEllipses('.') + "\n";
    }
    else if (type != varModule) {
      const Formula* form = var->GetFormula();
      if (form != NULL && !form->IsEmpty()) {
        retval += indent + var->GetNameDelimitedBy('.') + " = " + form->ToDelimitedStringWithEllipses('.') + ";\n";
      }
    }
  }
      

  
  //end model definition
  if (m_modulename != "[main]") {
    retval += "end\n";
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

string Module::GetJarnacVarFormulas() const
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

string Module::GetJarnacConstFormulas(string modulename) const
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
    assert(m_variables[var].CheckDoesNotIncludeSelf());
    //LS NOTE: loops should be detected at assignment time, but it's possible I missed something.
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
        const AntimonyReaction* rxn = m_variables[var].GetReaction();
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
              const AntimonyReaction* rxn = subvar->GetReaction();
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

size_t Module::GetNumVariablesOfType(return_type rtype) const
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

const Variable* Module::GetNthVariableOfType(return_type rtype, size_t n) const
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
  case varAnyDNA:
  case constAnyDNA:
    if (vtype == varDNA ||
        vtype == varFormulaOperator ||
        vtype == varReactionGene) {
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
  case allEvents:
    if (vtype == varEvent) {
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
  case varAnyDNA:
  case varOperators:
  case varGenes:
    return (!isconst);
  case constSpecies:
  case constFormulas:
  case constAnyDNA:
  case constOperators:
  case constGenes:
    return (isconst);
  case allSymbols:
  case allSpecies:
  case allFormulas:
  case allUnknown:
  case allReactions:
  case allInteractions:
  case allEvents:
  case subModules:
    return true;
  }
  assert(false); //uncaught return_type
  return false;
}

var_type Module::GetTypeFor(std::string varname) const
{
  for (size_t v=0; v<m_uniquevars.size(); v++) {
    const Variable* var = GetVariable(m_uniquevars[v]);
    if (varname == var->GetNameDelimitedBy(g_registry.GetCC())) {
      return var->GetType();
    }
  }
  g_registry.SetError("Unknown variable " + varname + " in module " + m_modulename + ".");
  return varUndefined;
}

bool Module::IsConst(std::string varname) const
{
  for (size_t v=0; v<m_uniquevars.size(); v++) {
    const Variable* var = GetVariable(m_uniquevars[v]);
    if (varname == var->GetNameDelimitedBy(g_registry.GetCC())) {
      return var->GetIsConst();
    }
  }
  g_registry.SetError("Unknown variable " + varname + " in module " + m_modulename + ".");
  return false;
}

string Module::ListIdentityDifferencesFrom(const Module* origmod, string mname) const
{
  string list = "";
  assert(GetNumVariablesOfType(allSymbols) == origmod->GetNumVariablesOfType(allSymbols));
  set<const Variable*> renamed;
  for (size_t var=0; var<m_variables.size(); var++) {
    const Variable* origvar = origmod->GetNthVariableOfType(allSymbols, var);
    const Variable* thisvar = GetNthVariableOfType(allSymbols, var);
    vector<string> thispoint = thisvar->GetPrintedName();
    if (thispoint.size() > 1 && thispoint[0] == mname) {
      thispoint.erase(thispoint.begin());
    }
    vector<string> origpoint = origvar->GetPrintedName();
    if (origpoint != thispoint) {
      renamed.insert(thisvar);
    }
  }
  for (size_t exportv=0; exportv<m_exportlist.size(); exportv++) {
    const Variable* expvar = GetVariable(m_exportlist[exportv]);
    if (exportv > 0) {
      list += ", ";
    }
    if (renamed.find(expvar) != renamed.end()) {
      list += ToStringFromVecDelimitedBy(expvar->GetPrintedName(), '.');
      renamed.erase(expvar);
    }
  }

  for (set<const Variable*>::iterator newname= renamed.begin(); newname != renamed.end(); newname++) {
    if (newname != renamed.begin() || m_exportlist.size() > 0) {
      list += ", ";
    }
    vector<string> subname = (*newname)->GetName();
    subname.erase(subname.begin());
    list += ToStringFromVecDelimitedBy((*newname)->GetPrintedName(), '.') + "=" + ToStringFromVecDelimitedBy(subname, '.');
  }    

  return list;
}

string Module::ListAssignmentDifferencesFrom(const Module* origmod, string mname, string indent) const
{
  string list = "";
  assert(GetNumVariablesOfType(allSymbols) == origmod->GetNumVariablesOfType(allSymbols));
  set<const Variable*> renamed;
  for (size_t var=0; var<GetNumVariablesOfType(allSymbols); var++) {
    const Variable* thisvar = GetNthVariableOfType(allSymbols, var);
    const Variable* origvar = origmod->GetNthVariableOfType(allSymbols, var);
    string thisform = thisvar->GetFormulaStringWithEllipses('.');
    string origform = origvar->GetFormulaStringWithEllipses('.');
    while (thisform.find(mname + ".") != string::npos) {
      thisform.erase(thisform.find(mname + "."), mname.size()+1);
    }
    if (thisform != origform) {
      list += indent + thisvar->GetNameDelimitedBy('.') + " = " + thisvar->GetFormulaStringWithEllipses('.') + ";\n";
    }
  }
  return list;
}

void Module::LoadSBML(const Model* sbml)
{
  string sbmlname = "";
  //Species
  for (unsigned int spec=0; spec<sbml->getNumSpecies(); spec++) {
    const Species* species = sbml->getSpecies(spec);
    sbmlname = getNameFromSBMLObject(species, "_S");
    Variable* var = AddOrFindVariable(&sbmlname);
    var->SetType(varSpeciesUndef);

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

    //Now we check whether to set it constant or not.  For now, our 'constness' is set
    // if the species is either 'constant' or a 'boundary condition'
    if (species->getConstant() || species->getBoundaryCondition()) {
      var->SetIsConst(true);
    }

    //LS DEBUG:  add compartment assignment here when they're implemented
  }
  //LS DEBUG:  Add compartments, constraints, events

  //Function Definitions
  for (unsigned int func=0; func<sbml->getNumFunctionDefinitions(); func++) {
    const FunctionDefinition* function = sbml->getFunctionDefinition(func);
    sbmlname = getNameFromSBMLObject(function, "_F");
    Variable* var = AddOrFindVariable(&sbmlname);
    string formulastring(SBML_formulaToString(function->getBody()));
    Formula* formula = g_registry.NewBlankFormula();
    setFormulaWithString(formulastring, formula);
    var->SetFormula(formula);
  }

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

  //Rules
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
    char* formulastring = SBML_formulaToString(reaction->getKineticLaw()->getMath());
    setFormulaWithString(formulastring, formula);
    free(formulastring);
    //Put all three together:
    AddNewReaction(&reactants, rdBecomes, &products, formula, var);
  }
  m_sbml = *sbml;
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
      sbmlspecies->setInitialConcentration(atoi(formula->ToStringDelimitedBy(cc).c_str()));
    }
    else {
      //create a rule
      AssignmentRule rule(species->GetNameDelimitedBy(cc), formula->ToStringDelimitedBy(cc));
      m_sbml.addRule(&rule);
    }
  }

  //Formulas
  for (size_t form=0; form < GetNumVariablesOfType(allFormulas); form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form);
    const Formula*  formula = formvar->GetFormula();
    Parameter* param = m_sbml.createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formula->IsDouble()) {
      param->setValue(atoi(formula->ToStringDelimitedBy(cc).c_str()));
    }
    else {
      //create a rule
      AssignmentRule rule(formvar->GetNameDelimitedBy(cc), formula->ToStringDelimitedBy(cc));
      m_sbml.addRule(&rule);
    }
  }

  //Reactions
  for (size_t rxn=0; rxn < GetNumVariablesOfType(allReactions); rxn++) {
    const Variable* rxnvar = GetNthVariableOfType(allReactions, rxn);
    const AntimonyReaction* reaction = rxnvar->GetReaction();
    const Formula* formula = reaction->GetFormula();
    KineticLaw kl(formula->ToStringDelimitedBy(cc));
    Reaction sbmlrxn(rxnvar->GetNameDelimitedBy(cc), "", &kl, false);
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
    for (size_t v=0; v<formula->GetNumVariables(); v++) {
      const Variable* formvar = formula->GetNthVariable(v);
      if (formvar != NULL) {
        if (left->GetStoichiometryFor(formvar) == 0 &&
            right->GetStoichiometryFor(formvar) == 0) {
          ModifierSpeciesReference msr(formvar->GetNameDelimitedBy(cc));
          sbmlrxn.addModifier(&msr);
        }
      }
    }
    m_sbml.addReaction(&sbmlrxn);
  }
}

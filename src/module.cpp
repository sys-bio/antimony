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
using namespace iface;
#endif

#define LEVELANDVERSION 2, 4

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
    m_sbml(),
    m_libsbml_info(""),
    m_libsbml_warnings(""),
#endif
#ifndef NCELLML
    m_cellmlmodel(NULL),
    m_cellmlcomponent(NULL),
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
#ifndef NSBML
    m_sbml(),
    m_libsbml_info(), //don't need this info for submodules--might be wrong anyway.
    m_libsbml_warnings(),
#endif
#ifndef NCELLML
    m_cellmlmodel(NULL),
    m_cellmlcomponent(NULL),
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
  CreateCellMLModel(); //ditto
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
#ifndef NSBML
    m_sbml(src.m_sbml),
    m_libsbml_info(src.m_libsbml_info),
    m_libsbml_warnings(src.m_libsbml_warnings),
#endif
#ifndef NCELLML
    m_cellmlmodel(src.m_cellmlmodel),
    m_cellmlcomponent(src.m_cellmlcomponent),
#endif
    m_uniquevars(src.m_uniquevars)
{
#ifndef NCELLML
  if (m_cellmlmodel != NULL) {
    m_cellmlmodel->add_ref();
  }
  if (m_cellmlcomponent != NULL) {
    m_cellmlcomponent->add_ref();
  }
#endif
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
  m_uniquevars = src.m_uniquevars;
#ifndef NSBML
  m_sbml = src.m_sbml;
  m_libsbml_info = src.m_libsbml_info;
  m_libsbml_warnings = src.m_libsbml_warnings;
#endif
#ifndef NCELLML
  m_cellmlmodel = src.m_cellmlmodel;
  m_cellmlcomponent = src.m_cellmlcomponent;
  if (m_cellmlmodel != NULL) {
    m_cellmlmodel->add_ref();
  }
  if (m_cellmlcomponent != NULL) {
    m_cellmlcomponent->add_ref();
  }
#endif
  return *this;
}


Module::~Module()
{
#ifndef NCELLML
  if (m_cellmlmodel != NULL) {
    m_cellmlmodel->release_ref();
  }
  if (m_cellmlcomponent != NULL) {
    m_cellmlcomponent->release_ref();
  }
#endif
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
    delete testdoc;
    return true;
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
    const Variable* var = GetVariable(m_uniquevars[nvar]);
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
    return GetVariable(m_uniquevars[n]);
  }

  size_t total = 0;
  for (size_t nvar=0; nvar<m_uniquevars.size(); nvar++) {
    const Variable* var = GetVariable(m_uniquevars[nvar]);
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

string Module::OutputOnly(vector<var_type> types, string name, string indent, char cc) const
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
        if (firstone) {
          retval += "\n" + indent + "// " + name + ":\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " = " + form->ToDelimitedStringWithEllipses(cc) + ";\n";
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

  //Definitions of all variables; Modules first:
  bool firstone = true;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      vector<string> mname = m_variables[var]->GetName();
      assert(mname.size() == 1);
      const Module* submod = m_variables[var]->GetModule();
      if (firstone) {
        retval += "\n" + indent + "// Sub-modules, and any changes to those submodules:\n";
        firstone = false;
      }
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

  //List the compartments and the species (but don't define them yet) so that the order is preserved:
  vector<string> compartmentnames;
  vector<string> speciesnames;
  for (size_t var=0; var<m_variables.size(); var++) {
    string name = m_variables[var]->GetNameDelimitedBy(cc);
    Variable* comp = m_variables[var]->GetCompartment();
    if (comp != NULL) {
      name += " in " + comp->GetNameDelimitedBy(cc);
    }
    if (m_variables[var]->GetType() == varCompartment) {
      compartmentnames.push_back(name);
    }
    else if (IsSpecies(m_variables[var]->GetType())) {
      if (m_variables[var]->GetIsConst()) {
        name = "$" + name;
      }
      speciesnames.push_back(name);
    }
  }
  if (compartmentnames.size() > 0 || speciesnames.size() > 0) {
    retval += "\n" + indent + "// Compartments and Species:\n";
  }
  retval += ListIn80Cols("compartment", compartmentnames, indent);
  retval += ListIn80Cols("species", speciesnames, indent);

  //Now list DNA strands:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    var_type type = var->GetType();
    if (var->IsPointer()) continue;
    else if (type == varStrand) {
      if (firstone) {
        retval += "\n" + indent + "// DNA strands:\n";
        firstone = false;
      }
      retval += indent + var->GetNameDelimitedBy(cc) + ": " + var->GetDNAStrand()->ToStringDelimitedBy(cc) + "\n";
    }
  }

  //Now any assignment rules:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    if (var->GetType() == varStrand) continue;
    if (var->GetFormulaType() == formulaASSIGNMENT) {
      const Formula* asntrule = var->GetFormula();
      if (!asntrule->IsEmpty() && !asntrule->IsEllipsesOnly()) {
        if (firstone) {
          retval += "\n" + indent + "// Assignment Rules:\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + " := " + asntrule->ToDelimitedStringWithEllipses(cc) + "\n";
      }
    }
  }

  //Any rate rules:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    if (var->GetFormulaType() == formulaRATE) {
      const Formula* raterule = var->GetRateRule();
      if (!raterule->IsEmpty()) {
        if (firstone) {
          retval += "\n" + indent + "// Rate Rules:\n";
          firstone = false;
        }
        retval += indent + var->GetNameDelimitedBy(cc) + "' = " + raterule->ToDelimitedStringWithEllipses(cc) + "\n";
      }
    }
  }

  //Then reactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    var_type type = var->GetType();
    if (var->IsPointer()) continue;
    else if (IsReaction(type)) {
      if (firstone) {
        retval += "\n" + indent + "// Reactions:\n";
        firstone = false;
      }
      retval += indent + var->GetReaction()->ToDelimitedStringWithEllipses(cc) + "\n";
    }
  }

  //Then interactions:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    var_type type = var->GetType();
    if (type == varInteraction) {
      if (firstone) {
        retval += "\n" + indent + "// Interactions:\n";
        firstone = false;
      }
      retval += indent + var->GetReaction()->ToDelimitedStringWithEllipses(cc) + "\n";
    }
  }

  //Then events:
  firstone = true;
  for (size_t vnum=0; vnum<m_variables.size(); vnum++) {
    const Variable* var = m_variables[vnum];
    if (var->IsPointer()) continue;
    var_type type = var->GetType();
    if (type == varEvent) {
      if (firstone) {
        retval += "\n" + indent + "// Events:\n";
        firstone = false;
      }
      retval += indent + var->GetEvent()->ToStringDelimitedBy(cc) + "\n";
    }
  }

  //Then species:
  vector<var_type> types;
  types.push_back(varSpeciesUndef);
  retval += OutputOnly(types, "Species initializations", indent, cc);
  
  //Compartments:
  types.clear();
  types.push_back(varCompartment);
  retval += OutputOnly(types, "Compartment initializations", indent, cc);

  //And finally, other random formulas.
  types.clear();
  types.push_back(varFormulaUndef);
  types.push_back(varFormulaOperator);
  types.push_back(varUndefined);
  types.push_back(varDNA);
  retval += OutputOnly(types, "Variable initializations", indent, cc);

  //Variables
  vector<string> varnames;
  vector<string> constnames;
  vector<string> DNAnames;
  vector<string> operatornames;
  vector<string> genenames;
  vector<string> innames;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->IsPointer()) continue;
    var_type type = m_variables[var]->GetType();
    if (IsSpecies(type)) continue; //already named them and know if they're const.
    const_type isconst = m_variables[var]->GetConstType();
    string name = m_variables[var]->GetNameDelimitedBy(cc);
    Variable* comp = m_variables[var]->GetCompartment();
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
    retval += indent + "\n//Other declarations:\n";
    retval += ListIn80Cols("DNA", DNAnames, indent);
    retval += ListIn80Cols("operator", operatornames, indent);
    retval += ListIn80Cols("gene", genenames, indent);
    retval += ListIn80Cols("var", varnames, indent);
    retval += ListIn80Cols("const", constnames, indent);
    retval += ListIn80Cols("", innames, indent);
  }

  //Display names
  bool anydisplay = false;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->IsPointer()) continue;
    if (m_variables[var]->GetDisplayName() != "") {
      if (anydisplay == false) {
        retval += "\n" + indent + "//Display Names:\n";
        anydisplay = true;
      }
      retval += indent + m_variables[var]->GetNameDelimitedBy(cc) + " is \"" + m_variables[var]->GetDisplayName() + "\";\n";
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
void Module::LoadSBML(const SBMLDocument* sbmldoc)
{
  //m_sbml = *sbmldoc;
  const Model* sbml = sbmldoc->getModel();
  string sbmlname = "";

  //Function Definitions
  //This is a bit weird, since functions exist outside of modules, since they can be used in any model.  So we have to go to the registry to save them.
  for (unsigned int func=0; func<sbml->getNumFunctionDefinitions(); func++) {
    const FunctionDefinition* function = sbml->getFunctionDefinition(func);
    sbmlname = getNameFromSBMLObject(function, "_F");
    g_registry.NewUserFunction(&sbmlname);
    for (unsigned int arg=0; arg<function->getNumArguments(); arg++) {
      string argument(parseASTNodeToString(function->getArgument(arg)));
      Variable* expvar = g_registry.AddVariableToCurrent(&argument);
      g_registry.AddVariableToCurrentExportList(expvar);
    }
    string formulastring(parseASTNodeToString(function->getBody()));
    Formula* formula = g_registry.NewBlankFormula();
    setFormulaWithString(formulastring, formula);
    g_registry.SetUserFunction(formula);
    g_registry.GetNthUserFunction(g_registry.GetNumUserFunctions()-1)->FixNames();
  }

  set<string> defaultcompartments;
  //Compartments
  for (unsigned int comp=0; comp<sbml->getNumCompartments(); comp++) {
    const Compartment* compartment = sbml->getCompartment(comp);
    sbmlname = getNameFromSBMLObject(compartment, "_C");
    if (compartment->getSBOTerm() == 410) {
      //The 'implicit compartment'
      defaultcompartments.insert(sbmlname);
      continue;
    }
    if (sbmlname == DEFAULTCOMP && compartment->getConstant() && compartment->isSetSize() && compartment->getSize() == 1.0) {
      defaultcompartments.insert(sbmlname);
      continue;
      //LS NOTE: we assume this was created with Antimony, and ignore the auto-generated 'default compartment'
      // Later versions of antimony now set the SBO terms to 410, so we might not need this code very long.
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    if (compartment->isSetName()) {
      var->SetDisplayName(compartment->getName());
    }
    var->SetType(varCompartment);
    Formula* formula = g_registry.NewBlankFormula();
    if (compartment->isSetSize()) {
      formula->AddNum(compartment->getSize());
      var->SetFormula(formula);
    }
    if (compartment->isSetUnits()) {
      var->SetUnits(compartment->getUnits());
    }
  }

  //Species
  for (unsigned int spec=0; spec<sbml->getNumSpecies(); spec++) {
    const Species* species = sbml->getSpecies(spec);
    sbmlname = getNameFromSBMLObject(species, "_S");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (species->isSetName()) {
      var->SetDisplayName(species->getName());
    }
    var->SetType(varSpeciesUndef);

    //Setting the formula
    Formula* formula = g_registry.NewBlankFormula();
    if (species->isSetInitialAmount()) {
      double amount = species->getInitialAmount();
      formula->AddNum(amount);
      if (amount != 0 && defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
        Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
        Formula* compform = compartment->GetFormula();
        if (!compform->IsOne()) {
          formula->AddMathThing('/');
          formula->AddVariable(compartment);
        }
      }
      var->SetFormula(formula);
    }
    else if (species->isSetInitialConcentration()) {
      formula->AddNum(species->getInitialConcentration());
      var->SetFormula(formula);
    }
    //Anything more complicated is set in a Rule, which we'll get to later.

    if (species->getConstant() || species->getBoundaryCondition()) {
      //Since all species are variable by default, we only set this explicitly if true.
      var->SetIsConst(true);
    }
    if (defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
      Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
      compartment->SetType(varCompartment);
      var->SetCompartment(compartment);
    }
    if (species->isSetUnits()) {
      var->SetUnits(species->getUnits());
    }
  }
  
  //Events:
  for (unsigned int ev=0; ev<sbml->getNumEvents(); ev++) {
    const Event* event = sbml->getEvent(ev);
    sbmlname = getNameFromSBMLObject(event, "_E");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (event->isSetName()) {
      var->SetDisplayName(event->getName());
    }
    var->SetType(varEvent);

    //Set the trigger:
    string triggerstring(parseASTNodeToString(event->getTrigger()->getMath()));
    Formula trigger;
    setFormulaWithString(triggerstring, &trigger);
    Formula delay;
    const Delay* sbmldelay = event->getDelay();
    if (sbmldelay != NULL) {
      string delaystring(parseASTNodeToString(sbmldelay->getMath()));
      setFormulaWithString(delaystring, &delay);
    }
    AntimonyEvent antevent(delay, trigger,var);
    var->SetEvent(&antevent);

    //Set the assignments:
    for (unsigned int asnt=0; asnt<event->getNumEventAssignments(); asnt++) {
      const EventAssignment* assignment = event->getEventAssignment(asnt);
      string name = assignment->getVariable();
      Variable* asntvar = AddOrFindVariable(&name);
      Formula*  asntform = g_registry.NewBlankFormula();
      setFormulaWithString(parseASTNodeToString(assignment->getMath()), asntform);
      var->GetEvent()->AddResult(asntvar, asntform);
    }
  }

  //LS DEBUG:  Add constraints?

  //Parameters
  for (unsigned int param=0; param<sbml->getNumParameters(); param++) {
    const Parameter* parameter = sbml->getParameter(param);
    sbmlname = getNameFromSBMLObject(parameter, "_P");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (parameter->isSetName()) {
      var->SetDisplayName(parameter->getName());
    }
    if (parameter->isSetValue()) {
      Formula* formula = g_registry.NewBlankFormula();
      formula->AddNum(parameter->getValue());
      var->SetFormula(formula);
      //LS NOTE:  If a parameter has both a value and an 'initial assignment', the initial assignment will override the value.
    }
    if (parameter->isSetUnits()) {
      var->SetUnits(parameter->getUnits());
    }
  }

  //Initial Assignments:  can override 'getValue' values.
  for (unsigned int ia=0; ia<sbml->getNumInitialAssignments(); ia++) {
    const InitialAssignment* initasnt = sbml->getInitialAssignment(ia);
    if (initasnt->isSetSymbol()) {
      sbmlname = initasnt->getSymbol();
      Variable* var = AddOrFindVariable(&sbmlname);
      if (initasnt->isSetName()) {
        var->SetDisplayName(initasnt->getName());
      }
      Formula* formula = g_registry.NewBlankFormula();
      string formulastring(parseASTNodeToString(initasnt->getMath()));
      setFormulaWithString(formulastring, formula);
      var->SetFormula(formula);
    }
    else {
      //LS DEBUG:  error?  The 'symbol' is supposed to be required.
    }
  }
    
  //Rules:
  for (unsigned int rulen=0; rulen<sbml->getNumRules(); rulen++) {
    const Rule* rule = sbml->getRule(rulen);
    if (rule->isAlgebraic()) {
      //LS DEBUG:  error message?  Unable to process algebraic rules
      continue;
    }
    sbmlname = rule->getVariable();
    assert(sbmlname != "");
    if (sbmlname == "") {
      sbmlname = getNameFromSBMLObject(rule, "_R");
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    if (rule->isSetName()) {
      var->SetDisplayName(rule->getName());
    }
    Formula* formula = g_registry.NewBlankFormula();
    string formulastring(parseASTNodeToString(rule->getMath()));
    setFormulaWithString(formulastring, formula);
    if (IsSpecies(var->GetType())) {
      //Any species in any rule must be 'const' (in Antimony), because this means it's a 'boundary species'
      var->SetIsConst(true);
    }
    else {
      //For other parameters, assignment and rate rules always mean the variable in question is not constant.
      var->SetIsConst(false);
    }

    if (rule->isAssignment()) {
      var->SetAssignmentRule(formula);
    }
    else if (rule->isRate()) {
      var->SetRateRule(formula);
    }
    else {
      assert(false); //should be caught above
    }
  }

  //Reactions
  for (unsigned int rxn=0; rxn<sbml->getNumReactions(); rxn++) {
    const Reaction* reaction = sbml->getReaction(rxn);
    sbmlname = getNameFromSBMLObject(reaction, "_J");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (reaction->isSetName()) {
      var->SetDisplayName(reaction->getName());
    }
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
    string formulastring = "";
    Formula formula;
    if (reaction->isSetKineticLaw()) {
      const KineticLaw* kl = reaction->getKineticLaw();
      var->SetUnits(kl->getSubstanceUnits() + "/(" + kl->getTimeUnits() + ")");
      formulastring = parseASTNodeToString(kl->getMath());
      setFormulaWithString(formulastring, &formula);
      for (unsigned int localp=0; localp<kl->getNumParameters(); localp++) {
        const Parameter* localparam = kl->getParameter(localp);
        vector<string> fullname;
        //Find the variable with the original name:
        string origname = getNameFromSBMLObject(localparam, "_P");
        fullname.push_back(origname);
        Variable* origvar = GetVariable(fullname);

        //Create a new variable with a new name:
        fullname.clear();
        sbmlname = var->GetNameDelimitedBy('_') + "_" + origname;
        fullname.push_back(sbmlname);
        Variable* foundvar = GetVariable(fullname);
        while (foundvar != NULL) {
           //Just in case something weird happened and there was another one of *this* name, too.
          sbmlname = var->GetNameDelimitedBy('_') + "_" + sbmlname;
          fullname.clear();
          fullname.push_back(sbmlname);
          foundvar = GetVariable(fullname);
        }
        Variable* localvar = AddOrFindVariable(&sbmlname);

        //Replace the variable in the formula:
        if(origvar != NULL) {
          formula.ReplaceWith(origvar, localvar);
        }
        else {
          //If origvar is NULL, nothing needs to be replaced: if the original formula had included the parameter, the earlier setFormulaWithString would have created one.  But since there wasn't one, this means the original formula didn't include the parameter at all!  Meaning this local parameter has no use whatsoever!  What the heck, dude.  Oh, well.
          //cout << "Unused local variable for reaction " << var->GetNameDelimitedBy('.') << ":  " << origname << endl;
        }

        //Set the value for the new variable:
        Formula localformula;
        localformula.AddNum(localparam->getValue());
        localvar->SetFormula(&localformula);
      }
	}
	else if (reaction->getNumModifiers() > 0) {
		//If the kinetic law is empty, we can set some interactions, if there are any Modifiers.
    ReactantList right;
    right.AddReactant(var);
    ReactantList left;
		for (unsigned int mod=0; mod<reaction->getNumModifiers(); mod++) {
			const ModifierSpeciesReference* msr = reaction->getModifier(mod);
      string species = msr->getSpecies();
      Variable* specvar = AddOrFindVariable(&species);
      left.AddReactant(specvar);
      sbmlname = getNameFromSBMLObject(msr, "_I");
    }
    Variable* interaction = AddOrFindVariable(&sbmlname);
    Formula blankform;
    AddNewReaction(&left, rdInfluences, &right, &blankform, interaction);
	}
    //Put reactants, products, and the formula together:
    AddNewReaction(&reactants, rdBecomes, &products, &formula, var);
  }
  //Finally, fix the fact that 'time' used to be OK in functions (l2v1), but is no longer (l2v2).
  g_registry.FixTimeInFunctions();
  //And that some SBML-OK names are not OK in Antimony
  FixNames();
}

const SBMLDocument* Module::GetSBML()
{
  const Model* mod = m_sbml.getModel();
  if (mod != NULL && mod->getId() == m_modulename) {
    return &m_sbml;
  }
  CreateSBMLModel();
  return &m_sbml;
}

void Module::CreateSBMLModel()
{
  Model* sbmlmod = m_sbml.createModel();
  sbmlmod->setId(m_modulename);
  sbmlmod->setName(m_modulename);
  sbmlmod->setNotes("<body xmlns=\"http://www.w3.org/1999/xhtml\"><p> Originally created by libAntimony " VERSION_STRING " (using libSBML " LIBSBML_DOTTED_VERSION ") </p></body>");
  char cc = g_registry.GetCC();
  //User-defined functions
  for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
    const UserFunction* userfunction = g_registry.GetNthUserFunction(uf);
    assert(userfunction != NULL);
    FunctionDefinition* fd = sbmlmod->createFunctionDefinition();
    fd->setId(userfunction->GetModuleName());
    ASTNode* math = parseStringToASTNode(userfunction->ToSBMLString());
    fd->setMath(math);
    delete math;
  }
  //Compartments
  Compartment* defaultCompartment = sbmlmod->createCompartment();
  defaultCompartment->setId(DEFAULTCOMP);
  defaultCompartment->setConstant(true);
  defaultCompartment->setSize(1);
  defaultCompartment->setSBOTerm(410); //The 'implicit compartment'
  size_t numcomps = GetNumVariablesOfType(allCompartments);
  for (size_t comp=0; comp<numcomps; comp++) {
    const Variable* compartment = GetNthVariableOfType(allCompartments, comp);
    Compartment* sbmlcomp = sbmlmod->createCompartment();
    sbmlcomp->setId(compartment->GetNameDelimitedBy(cc));
    if (compartment->GetDisplayName() != "") {
      sbmlcomp->setName(compartment->GetDisplayName());
    }
    sbmlcomp->setConstant(compartment->GetIsConst());
    formula_type ftype = compartment->GetFormulaType();
    assert (ftype == formulaINITIAL || ftype==formulaASSIGNMENT || ftype==formulaRATE);
    if (ftype != formulaINITIAL) {
      sbmlcomp->setConstant(false);
    }
    const Formula* formula = compartment->GetFormula();
    if (formula->IsDouble()) {
      sbmlcomp->setSize(atof(formula->ToSBMLString().c_str()));
    }
    SetAssignmentFor(sbmlmod, compartment);
  }

  //Species
  size_t numspecies = GetNumVariablesOfType(allSpecies);
  for (size_t spec=0; spec < numspecies; spec++) {
    const Variable* species = GetNthVariableOfType(allSpecies, spec);
    Species* sbmlspecies = sbmlmod->createSpecies();
    sbmlspecies->setId(species->GetNameDelimitedBy(cc));
    if (species->GetDisplayName() != "") {
      sbmlspecies->setName(species->GetDisplayName());
    }
    sbmlspecies->setConstant(false); //There's no need to try to distinguish between const and var for species.
    if (species->GetIsConst()) {
      sbmlspecies->setBoundaryCondition(true);
    }
    else {
      sbmlspecies->setBoundaryCondition(false);
    }
    const Variable* compartment = species->GetCompartment();
    if (compartment == NULL) {
      sbmlspecies->setCompartment(defaultCompartment->getId());
    }
    else {
      sbmlspecies->setCompartment(compartment->GetNameDelimitedBy(cc));
    }
    const Formula* formula = species->GetFormula();
    if (formula->IsDouble()) {
      sbmlspecies->setInitialConcentration(atof(formula->ToSBMLString().c_str()));
    }
    SetAssignmentFor(sbmlmod, species);
  }

  //Formulas
  size_t numforms = GetNumVariablesOfType(allFormulas);
  for (size_t form=0; form < numforms; form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form);
    const Formula*  formula = formvar->GetFormula();
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    param->setConstant(formvar->GetIsConst());
    if (formula->IsDouble()) {
      param->setValue(atof(formula->ToSBMLString().c_str()));
    }
    SetAssignmentFor(sbmlmod, formvar);
    formula_type ftype = formvar->GetFormulaType();
    assert (ftype == formulaINITIAL || ftype==formulaASSIGNMENT || ftype==formulaRATE);
    if (ftype != formulaINITIAL) {
      param->setConstant(false);
    }
  }

  //Reactions
  size_t numrxns = GetNumVariablesOfType(allReactions);
  for (size_t rxn=0; rxn < numrxns; rxn++) {
    const Variable* rxnvar = GetNthVariableOfType(allReactions, rxn);
    const AntimonyReaction* reaction = rxnvar->GetReaction();
    if (reaction->IsEmpty()) {
      continue; //Reactions that involve no species are illegal in SBML.
    }
    Reaction* sbmlrxn = sbmlmod->createReaction();
    sbmlrxn->setId(rxnvar->GetNameDelimitedBy(cc));
    if (rxnvar->GetDisplayName() != "") {
      sbmlrxn->setName(rxnvar->GetDisplayName());
    }
    const Formula* formula = reaction->GetFormula();
    string formstring = formula->ToSBMLString(rxnvar->GetStrandVars());
    if (!formula->IsEmpty()) {
      KineticLaw* kl = sbmlmod->createKineticLaw();
      ASTNode* math = parseStringToASTNode(formstring);
      kl->setMath(math);
      delete math;
    }
    const ReactantList* left = reaction->GetLeft();
    for (size_t lnum=0; lnum<left->Size(); lnum++) {
      const Variable* nthleft = left->GetNthReactant(lnum);
      double nthstoich = left->GetStoichiometryFor(lnum);
      SpeciesReference* sr = sbmlmod->createReactant();
      sr->setSpecies(nthleft->GetNameDelimitedBy(cc));
      sr->setStoichiometry(nthstoich);
    }
    const ReactantList* right = reaction->GetRight();
    for (size_t rnum=0; rnum<right->Size(); rnum++) {
      const Variable* nthright = right->GetNthReactant(rnum);
      double nthstoich = right->GetStoichiometryFor(rnum);
      SpeciesReference* sr = sbmlmod->createProduct();
      sr->setSpecies(nthright->GetNameDelimitedBy(cc));
      sr->setStoichiometry(nthstoich);
    }
    //Find 'modifiers' and add them.
    vector<const Variable*> subvars = formula->GetVariablesFrom(formstring, m_modulename);
    for (size_t v=0; v<subvars.size(); v++) {
      if (subvars[v] != NULL && subvars[v]->GetType() == varSpeciesUndef) {
        if (left->GetStoichiometryFor(subvars[v]) == 0 &&
            right->GetStoichiometryFor(subvars[v]) == 0) {
          ModifierSpeciesReference* msr = sbmlmod->createModifier();
          msr->setSpecies(subvars[v]->GetNameDelimitedBy(cc));
        }
      }
    }
  }

  //Events
  size_t numevents = GetNumVariablesOfType(allEvents);
  for (size_t ev=0; ev < numevents; ev++) {
    const Variable* eventvar = GetNthVariableOfType(allEvents, ev);
    const AntimonyEvent* event = eventvar->GetEvent();
    Event* sbmlevent = sbmlmod->createEvent();
    sbmlevent->setId(eventvar->GetNameDelimitedBy(cc));
    if (eventvar->GetDisplayName() != "") {
      sbmlevent->setName(eventvar->GetDisplayName());
    }
    Trigger* trig = sbmlevent->createTrigger();
    ASTNode* ASTtrig = parseStringToASTNode(event->GetTrigger()->ToSBMLString());
    trig->setMath(ASTtrig);
    delete ASTtrig;
    const Formula* delay = event->GetDelay();
    if (!delay->IsEmpty()) {
      ASTtrig = parseStringToASTNode(delay->ToSBMLString());
      Delay* sbmldelay = sbmlevent->createDelay();
      sbmldelay->setMath(ASTtrig);
      delete ASTtrig;
    }
      
    long numasnts = static_cast<long>(event->GetNumAssignments());
    for (long asnt=numasnts-1; asnt>=0; asnt--) {
      //events are stored in reverse order.  Don't ask...
      EventAssignment* sbmlasnt = sbmlmod->createEventAssignment();
      sbmlasnt->setVariable(event->GetNthAssignmentVariableName(asnt, cc));
      ASTNode* ASTasnt = parseStringToASTNode(event->GetNthAssignmentFormulaString(asnt, '_', true));
      sbmlasnt->setMath(ASTasnt);
      delete ASTasnt;
    }
  }

  //Interactions
  size_t numinteractions = GetNumVariablesOfType(allInteractions);
  for (size_t irxn=0; irxn<numinteractions; irxn++) {
    const Variable* arxnvar = GetNthVariableOfType(allInteractions, irxn);
	  const AntimonyReaction* arxn = arxnvar->GetReaction();
	  Reaction* rxn = sbmlmod->getReaction(arxn->GetRight()->GetNthReactant(0)->GetNameDelimitedBy(cc));
    if (rxn != NULL) {
	    for (size_t interactor=0; interactor<arxn->GetLeft()->Size(); interactor++) {
		    ModifierSpeciesReference* msr = rxn->createModifier();
		    msr->setSpecies(arxn->GetLeft()->GetNthReactant(interactor)->GetNameDelimitedBy(cc));
        msr->setName(arxnvar->GetNameDelimitedBy(cc));
	    }
    }
  }

  //Unknown variables (turn into parameters)
  size_t numunknown = GetNumVariablesOfType(allUnknown);
  for (size_t form=0; form < numunknown; form++) {
    const Variable* formvar = GetNthVariableOfType(allUnknown, form);
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
  }
}

void Module::SetAssignmentFor(Model* sbmlmod, const Variable* var)
{
  char cc = g_registry.GetCC();
  formula_type ftype = var->GetFormulaType();
  const Formula* formula = var->GetFormula();
  if (!formula->IsEmpty()) {
    ASTNode* math = parseStringToASTNode(formula->ToSBMLString());
    if (ftype == formulaASSIGNMENT) {
      AssignmentRule* ar = sbmlmod->createAssignmentRule();
      ar->setVariable(var->GetNameDelimitedBy(cc));
      ar->setMath(math);
    }
    else if (!formula->IsDouble()) { //if it was a double, we already dealt with it.
      InitialAssignment* ia = sbmlmod->createInitialAssignment();
      ia->setSymbol(var->GetNameDelimitedBy(cc));
      ia->setMath(math);
    }
    delete math;
  }
  if (ftype == formulaRATE) {
    formula = var->GetRateRule();
    if (!formula->IsEmpty()) {
      ASTNode* math = parseStringToASTNode(var->GetRateRule()->ToSBMLString());
      RateRule* rr = sbmlmod->createRateRule();
      rr->setVariable(var->GetNameDelimitedBy(cc));
      rr->setMath(math);
      delete math;
    }
  }
}
#endif
  

#ifndef NCELLML
void Module::LoadCellMLModel(cellml_api::Model* model)
{
  assert(m_cellmlcomponent==NULL);
  if (m_cellmlmodel != NULL) {
    m_cellmlmodel->release_ref();
    assert(false);
  }
  m_cellmlmodel = model;
  m_cellmlmodel->add_ref();

  //Translate
  wchar_t* cellmltext;
  string cellmlname;

  //Components become sub-modules
  cellml_api::CellMLComponentSet* components = m_cellmlmodel->localComponents();
  cellml_api::CellMLComponentIterator* cmpi = components->iterateComponents();
  components->release_ref();
  cellml_api::CellMLComponent* component;
  while ((component = cmpi->nextComponent()) != NULL) {
    //Load the component as a submodule (which should already have been loaded by the registry in LoadCellML)
    cellmltext = component->name();
    component->release_ref();
    cellmlname = ToThinString(cellmltext);
    string cellmlmodname = "cellmlmod_" + cellmlname;
    free(cellmltext);
    Variable* var = AddOrFindVariable(&cellmlname);
    if(var->SetModule(&cellmlmodname)) {
      assert(false);
      return;
    }
  }

  //Imports also become sub-modules
  cellml_api::CellMLImportSet* imports = m_cellmlmodel->imports();
  cellml_api::CellMLImportIterator* impi = imports->iterateImports();
  cellml_api::CellMLImport* import;
  while ((import = impi->nextImport()) != NULL) {
    cellml_api::ImportComponentSet* impcomponents = import->components();
    cellml_api::ImportComponentIterator* icmpi = impcomponents->iterateImportComponents();
    impcomponents->release_ref();
    cellml_api::ImportComponent* impcomponent;
    while ((impcomponent = icmpi->nextImportComponent()) != NULL) {
      //Load the imported component as a submodules, too.
      cellmltext = impcomponent->name();
      impcomponent->release_ref();
      cellmlname = ToThinString(cellmltext);
      free(cellmltext);
      cellmltext = impcomponent->componentRef();
      string cellmlmodname = ToThinString(cellmltext);
      free(cellmltext);
      Variable* var = AddOrFindVariable(&cellmlname);
      if(var->SetModule(&cellmlmodname)) {
        assert(false);
        return;
      }
    }
    import->release_ref();
  }
  impi->release_ref();
  //Now go through them again to get the connections.  I know, right?
  impi = imports->iterateImports();
  imports->release_ref();
  while ((import = impi->nextImport()) != NULL) {
    cellml_api::ConnectionSet* impconnections = import->importedConnections();
    LoadConnections(impconnections);
    impconnections->release_ref();
    import->release_ref();
  }
  impi->release_ref();
  //And then get the main model's connections
  cellml_api::ConnectionSet* connections = model->connections();
  LoadConnections(connections);
  connections->release_ref();
}

void Module::LoadConnections(cellml_api::ConnectionSet* connections)
{
  wchar_t* cellmlstring;
  string cellmlname;
  cellml_api::ConnectionIterator* coni = connections->iterateConnections();
  cellml_api::Connection* connection;
  while ((connection = coni->nextConnection()) != NULL) {
    cellml_api::MapComponents* compmap = connection->componentMapping();
    cellmlstring = compmap->firstComponentName();
    cellmlname = ToThinString(cellmlstring);
    free(cellmlstring);
    vector<string> varname;
    varname.push_back(cellmlname);
    Variable* firstmod = GetVariable(varname);
    assert(firstmod!=NULL);
    cellmlstring = compmap->secondComponentName();
    cellmlname = ToThinString(cellmlstring);
    free(cellmlstring);
    varname.clear();
    varname.push_back(cellmlname);
    Variable* secondmod = GetVariable(varname);
    //LS DEBUG:  The above code will fail if there is more than one module with the same name.
    cellml_api::MapVariablesSet* mvs = connection->variableMappings();
    cellml_api::MapVariablesIterator* mvsi = mvs->iterateMapVariables();
    mvs->release_ref();
    cellml_api::MapVariables* mapvars;
    while ((mapvars = mvsi->nextMapVariable()) != NULL) {
      cellmlstring = mapvars->firstVariableName();
      cellmlname = ToThinString(cellmlstring);
      free(cellmlstring);
      Variable* firstvar = firstmod->GetSubVariable(&cellmlname);
      assert(firstvar != NULL);
      cellmlstring = mapvars->secondVariableName();
      cellmlname = ToThinString(cellmlstring);
      free(cellmlstring);
      Variable* secondvar = secondmod->GetSubVariable(&cellmlname);
      firstvar->Synchronize(secondvar);
      //LS NOTE: Unlike the above code, this should work regardless of namespace if we get the module right in the first place.
      mapvars->release_ref();
    }
    connection->release_ref();
  }
  coni->release_ref();
}

void Module::LoadCellMLComponent(cellml_api::CellMLComponent* component)
{
  wchar_t* cellmlstring;
  string cellmlname;
  assert(m_cellmlmodel==NULL);
  if (m_cellmlcomponent != NULL) {
    m_cellmlcomponent->release_ref();
    assert(false);
  }
  //Variables
  cellml_api::CellMLVariableSet* varset = component->variables();
  cellml_api::CellMLVariableIterator* vsi = varset->iterateVariables();
  varset->release_ref();
  cellml_api::CellMLVariable* cmlvar;
  while ((cmlvar = vsi->nextVariable()) != NULL) {
    cellmlstring = cmlvar->name();
    cellmlname = ToThinString(cellmlstring);
    free(cellmlstring);
    Variable* antvar = AddOrFindVariable(&cellmlname);
    cellmlstring = cmlvar->initialValue();
    cellmlname = ToThinString(cellmlstring);
    if (cellmlname != "") {
      Formula* formula = g_registry.NewBlankFormula();
      setFormulaWithString(cellmlname, formula);
      antvar->SetFormula(formula);
    }
    free(cellmlstring);
    cmlvar->release_ref();
  }
  vsi->release_ref();

  //Reactions
  cellml_api::ReactionSet* rxnset = component->reactions();
  cellml_api::ReactionIterator* rxni = rxnset->iterateReactions();
  rxnset->release_ref();
  cellml_api::Reaction* rxn;
  while ((rxn = rxni->nextReaction()) != NULL) {
    //parse the reaction;
    //reactions don't have names, so make up a new one for Antimony
    //LS DEBUG:  stopped coding here for now...
    //Variable* rxnvar = AddOrFindVariable(&cellmlname);
    rxn->release_ref();
  }
  rxni->release_ref();
  
  //Math
  cellml_api::MathList* mathlist; //LS DEBUG what?  // = cmlvar->math();
  cellml_api::MathMLElementIterator* mli = mathlist->iterate();
  mathlist->release_ref();
  mathml_dom::MathMLElement* mathel;
  while((mathel = mli->next()) != NULL) {
    //Er, here's where you'd translate the MathML to Infix and figure out whether it was
    // and assignment rule or a rate rule.
    mathel->release_ref();
  }
  mli->release_ref();

  //Containers (?)
}

const cellml_api::Model* Module::GetCellMLModel()
{
  if (m_cellmlmodel==NULL || (m_cellmlmodel->name() != ToWString(m_modulename))) {
    CreateCellMLModel();
  }
  return m_cellmlmodel;
}

void Module::CreateCellMLModel()
{
  if (m_cellmlmodel != NULL) {
    m_cellmlmodel->release_ref();
    if (m_cellmlcomponent != NULL) {
      m_cellmlcomponent->release_ref();
      m_cellmlcomponent = NULL;
    }
  }
  cellml_api::CellMLBootstrap* boot = CreateCellMLBootstrap();;
  m_cellmlmodel = boot->createModel(L"1.1");
  boot->release_ref();

  m_cellmlmodel->name(ToWString(m_modulename).c_str());
  //Create units

  //Create a component for all local variables
  m_cellmlcomponent = CreateCellMLComponentFor(m_cellmlmodel);
  m_cellmlmodel->addElement(m_cellmlcomponent);

  //Create all connections

  //Create groups (?)
}

cellml_api::CellMLComponent* Module::CreateCellMLComponentFor(cellml_api::Model* model)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* variable = m_variables[var];
    switch(variable->GetType()) {
    case varModule:
      model->addElement(variable->GetModule()->CreateCellMLComponentFor(model));
    }
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

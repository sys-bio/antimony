#include <assert.h>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "stringx.h"

using namespace std;

Variable::Variable(const string name, const Module* module)
  : m_name(),
    m_module(module->GetModuleName()),
    m_sameVariable(),
    m_valFormula(),
    m_valReaction(),
    m_valModule(),
    m_valEvent(),
    m_valStrand(),
    m_compartment(),
    m_strands(),
    m_type(varUndefined),
    m_const(constDEFAULT)

{
  m_name.push_back(name);
}

vector<string> Variable::GetName() const
{
  return m_name;
}

vector<string> Variable::GetPrintedName() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetPrintedName();
  }
  return m_name;
}

string Variable::GetNameDelimitedBy(char cc) const
{
  if (IsPointer()) {
    return GetSameVariable()->GetNameDelimitedBy(cc);
  }
  //  if (m_sameVariable.size()
  string retval;
  for (size_t i=0; i<m_name.size(); i++) {
    if (i>0) {
      retval += cc;
    }
    retval += m_name[i];
  }
  return retval;
}

string Variable::GetFormulaStringDelimitedBy(char cc) const
{
  if (GetFormula() == NULL) return "";
  return GetFormula()->ToDelimitedStringWithStrands(cc, GetStrandVars());
}

string Variable::GetFormulaStringWithEllipses(char cc) const
{
  if (GetFormula() == NULL) return "";
  return GetFormula()->ToDelimitedStringWithEllipses(cc);
}

var_type Variable::GetType() const
{
  //LS NOTE:  don't get the type of the equivalent variable--that can lead to infinite loops.
  return m_type;
}


const Formula* Variable::GetFormula() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetFormula();
  }
  switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return m_valEvent.GetTrigger();
  case varStrand:
    return m_valStrand.GetFinalFormula();
  }
  assert(false); //Uncaught variable type
  g_registry.SetError("Programming error:  uncaught variable type.  Must rewrite to fix.");
  return NULL;
}

Formula* Variable::GetFormula()
{
  if (IsPointer()) {
    return GetSameVariable()->GetFormula();
  }
  else switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return m_valEvent.GetTrigger();
  case varStrand:
    return m_valStrand.GetFinalFormula();
  }
  assert(false); //Uncaught variable type
  g_registry.SetError("Programming error:  uncaught variable type.  Must rewrite to fix.");
  return NULL;
}

const AntimonyReaction* Variable::GetReaction() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetReaction();
  }
  assert(IsReaction(m_type) || m_type == varInteraction);
  return &(m_valReaction);
}

Module* Variable::GetModule()
{
  if (IsPointer()) {
    return GetSameVariable()->GetModule();
  }
  assert(m_type == varModule);
  return &(m_valModule[0]);
}

const AntimonyEvent* Variable::GetEvent() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetEvent();
  }
  assert(m_type == varEvent);
  return &(m_valEvent);
}

AntimonyEvent* Variable::GetEvent()
{
  if (IsPointer()) {
    return GetSameVariable()->GetEvent();
  }
  assert(m_type == varEvent);
  return &(m_valEvent);
}

Variable* Variable::GetSubVariable(const std::string* name)
{
  if (IsPointer()) {
    return GetSameVariable()->GetSubVariable(name);
  }
  if (m_type != varModule) {
    return NULL;
  }
  assert(m_valModule.size() == 1);
  return m_valModule[0].GetSubVariable(name);
}

Variable* Variable::GetSameVariable() const
{
  Variable* var = g_registry.GetModule(m_module)->GetVariable(m_name);
  Variable* subvar = g_registry.GetModule(m_module)->GetVariable(m_sameVariable);
  if (subvar == NULL) return var;
  while (var != subvar) {
    var = subvar;
    subvar = subvar->GetSameVariable();
  }
  return var;
}

const DNAStrand* Variable::GetDNAStrand() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetDNAStrand();
  }
  if (m_type != varStrand) {
    return NULL;
  }
  return &(m_valStrand);
}

Variable* Variable::GetCompartment() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetCompartment();
  }
  return g_registry.GetModule(m_module)->GetVariable(m_compartment);
}


bool Variable::GetIsConst() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetIsConst();
  }
  const_type formconst = constDEFAULT;
  if (GetFormula() != NULL) {
    if (GetFormula()->GetIsConst()) {
      formconst = constCONST;
    }
    else {
      formconst = constVAR;
    }
  }
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varCompartment:
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    if (m_const == constDEFAULT) {
      if (formconst==constDEFAULT || formconst==constCONST) return true;
      if (formconst==constVAR) return false;
    }
    if (m_const == constCONST && formconst == constVAR) return false;
    break;
  case varSpeciesUndef:
    if (m_const == constDEFAULT) return false;
    break;
  case varModule:
  case varEvent:
  case varStrand:
    return false;
  case varUndefined:
    return true;
  }
  switch(m_const) {
  case constCONST:
    return true;
  case constVAR:
    return false;
  case constDEFAULT:
    assert(false); //should be caught above.
    return false;
  }
  assert(false); //uncaught const type
  return false;
}

bool Variable::GetIsEquivalentTo(const Variable* var) const
{
  if (IsPointer()) {
    return GetSameVariable()->GetIsEquivalentTo(var);
  }
  const Variable* othervar = var->GetSameVariable();
  if (othervar->GetName() == m_name) return true;
  return false;
}

vector<pair<Variable*, size_t> > Variable::GetStrandVars() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetStrandVars();
  }
  vector<pair<Variable*, size_t> > retval;
  for (set<vector<string> >::iterator strand = m_strands.begin(); strand != m_strands.end(); strand++) {
    Variable* var = g_registry.GetModule(m_module)->GetVariable(*strand);
    assert(var != NULL);
    vector<size_t> occurrences = var->GetDNAStrand()->GetOccurrencesOf(m_name);
    for (size_t occurrence=0; occurrence<occurrences.size(); occurrence++) {
      retval.push_back(make_pair(var, occurrences[occurrence]));
    }
  }
  return retval;
}

bool Variable::IsExpandedStrand() const
{
  if (IsPointer()) {
    return GetSameVariable()->IsExpandedStrand();
  }
  if (GetType() != varStrand) return false;
  return (m_strands.size()==0);
}

string Variable::GetFormulaForNthEntryInStrand(char cc, size_t n)
{
  if (IsPointer()) {
    return GetSameVariable()->GetFormulaForNthEntryInStrand(cc, n);
  }
  assert(GetType() == varStrand);
  vector<Variable*> vars = m_valStrand.GetVariables();
  assert(n < vars.size());
  vector<pair<Variable*, size_t> > onestrandvar;
  if (vars[n]->GetType() == varStrand) {
    vector<Variable*> subvars = vars[n]->GetDNAStrand()->GetVariables();
    onestrandvar.push_back(make_pair(vars[n], subvars.size()-1));
  }
  else {
    onestrandvar.push_back(make_pair(this, n));
  }
  Formula* form = vars[n]->GetFormula();
  assert(form != NULL);
  string retval = form->ToDelimitedStringWithStrands(cc, onestrandvar);
  if (retval == "") {
    retval = "0";
  }
  return retval;
}

bool Variable::SetType(var_type newtype)
{
  if (newtype == varUndefined) return false;
  if (newtype == m_type) return false;
  if (IsPointer()) {
    if (GetSameVariable()->SetType(newtype)) return true;
    m_type = GetSameVariable()->GetType();
    return false;
  }
  if (IsDNA(newtype) && !m_valReaction.LeftIsEmpty()) {
    g_registry.SetError("For now, we disallow DNA reactions (i.e. genes) to consume anything in the reaction they define:  the left side of the reaction must be empty (i.e  ' -> S1' and not 'G1 -> S1').");
    return true;
  }
  if (IsDNA(newtype) && GetFormula()->IsEmpty()) {
    //Default formula for DNA is "..."
    Formula formula;
    formula.AddEllipses();
    SetFormula(&formula);
  }
  if (IsDNA(m_type) && newtype == varStrand) {
    if (m_valReaction.IsEmpty() && (m_valFormula.IsEmpty() || m_valFormula.ToDelimitedStringWithEllipses('.')=="...")) {
      m_type = newtype;
      m_valFormula.Clear();
      return false;
    }
    else {
      g_registry.SetError("Unable to use the variable '" + GetNameDelimitedBy('.') + "' as a DNA strand because it is already set to be a particular piece of DNA, with an associated reaction or a formula.");
      return true;
    }
  }
  string error = "Unable to set the type of variable '" + GetNameDelimitedBy('.') + "' to " + VarTypeToString(newtype) + " because it is already set to be the incompatible type " + VarTypeToString(m_type) + ".  This situation can occur either with explicit type declaration or by using the variable in different, incompatible contexts.";
  switch(m_type) {
  case varSpeciesUndef:
    switch(newtype) {
    case varSpeciesUndef:
      //If they were both SpeciesUndef, we already returned.
      return false;
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
      g_registry.SetError(error); return true;
    }
  case varFormulaUndef:
    switch(newtype) {
    case varSpeciesUndef:
    case varFormulaUndef:
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
    case varCompartment:
      m_type = newtype;
      return false;
    case varModule:
    case varEvent:
    case varStrand:
      g_registry.SetError(error); return true;
    case varUndefined:
      return false;
    }
  case varDNA:
    switch(newtype) {
    case varFormulaUndef:
    case varUndefined:
      return false;
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
      m_type = newtype;
      return false;
    case varReactionUndef:
      m_type = varReactionGene;
      return false;
    case varSpeciesUndef:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
      g_registry.SetError(error); return true;
    }
  case varFormulaOperator:
    switch(newtype) {
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varUndefined:
      return false;
    case varSpeciesUndef:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
      g_registry.SetError(error); return true;
    }
  case varReactionGene:
    switch(newtype) {
    case varFormulaUndef:
    case varDNA:
    case varReactionGene:
    case varReactionUndef:
    case varUndefined:
      return false;
    case varSpeciesUndef:
    case varFormulaOperator:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
      g_registry.SetError(error); return true;
    }
  case varReactionUndef:
    switch(newtype) {
    case varReactionUndef:
    case varUndefined:
    case varFormulaUndef:
      return false;
    case varDNA:
    case varReactionGene:
      m_type = varReactionGene;
      return false;
    case varSpeciesUndef:
    case varFormulaOperator:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
      g_registry.SetError(error); return true;
    }
  case varInteraction:
    switch(newtype) {
    case varUndefined:
    case varFormulaUndef:
    case varInteraction:
      return false;
    case varReactionUndef:
    case varDNA:
    case varReactionGene:
    case varSpeciesUndef:
    case varFormulaOperator:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
      g_registry.SetError(error); return true;
    }
  case varUndefined:
    m_type = newtype;
    return false;
  case varModule:
  case varEvent:
  case varCompartment:
  case varStrand:
    g_registry.SetError(error); return true; //the already-identical cases handled above.
  }

  assert(false); //uncaught vtype
  return false;
}

bool Variable::SetFormula(Formula* formula)
{
  if (IsPointer()) {
    return GetSameVariable()->SetFormula(formula);
  }
  string formstring = formula->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
  if (formula->ContainsVar(this)) {
    g_registry.SetError("Loop detected:  " + GetNameDelimitedBy('.') + "'s definition either includes itself directly (i.e. 's5 = 6 + s5') or by proxy (i.e. 's5 = 8*d3' and 'd3 = 9*s5').");
    return true;
  }
  switch (m_type) {
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    m_valReaction.SetFormula(formula);
    break;
  case varModule:
    return m_valModule[0].SetFormula(formula);
  case varUndefined:
    m_type = varFormulaUndef;
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varCompartment:
  case varSpeciesUndef:
    m_valFormula = *formula;
    break;
  case varEvent:
    if (m_valEvent.SetTrigger(*formula)) return true;
    break;
  case varStrand:
    g_registry.SetError("Cannot set '" + GetNameDelimitedBy('.') + "' to be " + formula->ToDelimitedStringWithEllipses('.') + " because DNA strands are only defined by their components, and do not have any equations associated with them.");
    return true;
  }
  return false;
}

bool Variable::SetReaction(AntimonyReaction* rxn)
{
  if (IsPointer()) {
    return GetSameVariable()->SetReaction(rxn);
  }
  string formstring = rxn->GetFormula()->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The reaction rate \"" + rxn->GetFormula()->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
  string err = "When defining reaction '" + GetNameDelimitedBy('.') + "':  ";
  if (rxn->GetLeft()->SetComponentTypesTo(varSpeciesUndef)) {
    g_registry.AddErrorPrefix(err);
    return true;
  }
  if (IsInteraction(rxn->GetType())) {
    if (SetType(varInteraction) || rxn->GetRight()->SetComponentTypesTo(varReactionUndef)) {
      g_registry.AddErrorPrefix(err);
      return true;
    }
  }
  else {
    if (SetType(varReactionUndef)) return true;
    if (rxn->GetRight()->SetComponentTypesTo(varSpeciesUndef)){
      g_registry.AddErrorPrefix(err);
      return true;
    }
  }
  m_valReaction = *rxn;
  if (!m_valFormula.IsEmpty() && rxn->GetFormula()->IsEmpty()) {
    m_valReaction.SetFormula(&m_valFormula);
    Formula blankform;
    m_valFormula = blankform;
  }
  if (IsInteraction(m_valReaction.GetType())) {
    if (m_valReaction.SetFormulaOfInteracteesAndClear()) {
      g_registry.AddErrorPrefix(err);
      return true;
    }
  }
  return false;
}

bool Variable::SetModule(const string* modname)
{
  if (IsPointer()) {
    return GetSameVariable()->SetModule(modname);
  }
  assert(m_name.size() == 1);
  if (m_type != varUndefined) {
    g_registry.SetError("Cannot define '" + GetNameDelimitedBy('.') + "' to be model '" + *modname + "', because it is already a " + VarTypeToString(m_type) + ".");
    return true; //error
  }
  Module newmod(*g_registry.GetModule(*modname), m_name[0], m_module);
  m_valModule.push_back(newmod);
  m_type = varModule;
  g_registry.SetCurrentImportedModule(m_name);
  return false;
}

bool Variable::SetEvent(const AntimonyEvent* event)
{
  if (IsPointer()) {
    return GetSameVariable()->SetEvent(event);
  }
  m_valEvent = *event;
  return SetType(varEvent);
}

void Variable::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  m_name.insert(m_name.begin(), newtopname);
  if (m_sameVariable.size() > 0) {
    m_sameVariable.insert(m_sameVariable.begin(), newtopname);
    return;
  }
  if (!m_valFormula.IsEmpty()) {
    m_valFormula.SetNewTopName(m_module, newtopname);
  }
  if (!m_valReaction.IsEmpty()) {
    m_valReaction.SetNewTopName(m_module, newtopname);
  }
  if (m_valModule.size() > 0) {
    assert(m_valModule.size() == 1);
    m_valModule[0].SetNewTopName(m_module, newtopname);
  }
  if (!m_valStrand.IsEmpty()) {
    m_valStrand.SetNewTopName(m_module, newtopname);
  }
  if (!m_valEvent.IsEmpty()) {
    m_valEvent.SetNewTopName(m_module, newtopname);
  }
  if (m_compartment.size() > 0) {
    m_compartment.insert(m_compartment.begin(), newtopname);
  }
  set<vector<string> > newstrands;
  for (set<vector<string> >::iterator strand = m_strands.begin(); strand != m_strands.end(); strand++) {
    vector<string> newname = *strand;
    newname.insert(newname.begin(), newtopname);
    newstrands.insert(newname);
  }
  m_strands = newstrands;
}

bool Variable::SetIsConst(bool constant)
{
  if (IsPointer()) {
    return GetSameVariable()->SetIsConst(constant);
  }
  string error = "Cannot set '" + GetNameDelimitedBy('.') + "' to be constant";
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varUndefined:
  case varCompartment:
    if (!m_valFormula.GetIsConst() && constant) {
      g_registry.SetError(error + " because its rate constant or initial value contains something that is or cannot be constant (such as a floating species concentration).");
      return true;
    }
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    if (constant) {
      g_registry.SetError(error + ".  Reactions and interactions are non-constant by definition.");
      return true;
    }
    break;
  case varModule:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for submodules.");
      return true;
    }
    break;
  case varEvent:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for events.");
      return true;
    }
    break;
  case varStrand:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for DNA strands.");
      return true;
    }
    break;
  }
  if (constant) {
    m_const = constCONST;
  }
  else {
    m_const = constVAR;
  }
  return false;
}

void Variable::SetRegConst()
{
  const_type regconst = g_registry.GetConstness();
  if (regconst != constDEFAULT) {
    m_const = g_registry.GetConstness();
  }
}

bool Variable::SetCompartment(Variable* var)
{
  if (IsPointer()) {
    return GetSameVariable()->SetCompartment(var);
  }
  if (var->SetType(varCompartment)) return true;
  if (m_compartment.size() > 0) {
    g_registry.SetError("Cannot set '" + GetNameDelimitedBy('.') + "' to be in compartment '" + var->GetNameDelimitedBy('.') + "', because it is already in a different compartment (" + ToStringFromVecDelimitedBy(m_compartment, '.') + ").");
    return true;
  }
  m_compartment = var->GetName();
  return false;
}

void Variable::SetComponentCompartments()
{
  if (IsPointer()) {
    return GetSameVariable()->SetComponentCompartments();
  }
  Variable* compartment = g_registry.GetModule(m_module)->GetVariable(m_compartment);
  if (compartment == NULL) return;
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varCompartment:
  case varSpeciesUndef:
  case varEvent:
  case varUndefined:
    return; //No components to set
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.SetComponentCompartments(compartment);
  case varModule:
    return m_valModule[0].SetComponentCompartments(compartment);
  case varStrand:
    return m_valStrand.SetComponentCompartments(compartment);
  }
}

bool Variable::SetDNAStrand(DNAStrand& strand)
{
  if (IsPointer()) {
    return GetSameVariable()->SetDNAStrand(strand);
  }
  if (SetType(varStrand)) return true;
  m_valStrand = strand;
  return false;
}

bool Variable::SetIsInStrand(Variable* var)
{
  if (IsPointer()) {
    return GetSameVariable()->SetIsInStrand(var);
  }
  if (GetType() == varStrand) {
    if (m_strands.size() > 0) {
      g_registry.SetError("Cannot put the DNA strand '" + GetNameDelimitedBy('.') + "' into the strand '" + var->GetNameDelimitedBy('.') + "' because it is already in the strand '" + g_registry.GetModule(m_module)->GetVariable(*m_strands.begin())->GetNameDelimitedBy('.') + "', and can only be in one strand at a time.  If you want a copy in the new strand, you must copy the DNA itself.");
      return true;
    }
    if (m_valStrand.CheckContains(var)) {
      g_registry.SetError("Cannot put the DNA strand " + GetNameDelimitedBy('.') + " into the strand " + var->GetNameDelimitedBy('.') + " because the first already contains the second, either directly or indirectly.");
      return true;
    }
  }
  m_strands.insert(var->GetName());
  return false;
}

//Set this variable to be a shell pointing to the clone, transferring any data we may already have.
bool Variable::Synchronize(Variable* clone)
{
  if (IsPointer()) {
    if(GetSameVariable()->Synchronize(clone)) return true;
    m_type = clone->GetType();
    return false;
  }
  if (clone == NULL) {
    g_registry.SetError("No such variable in this module.");
    return true;
  }
  clone = clone->GetSameVariable();
  if (GetIsEquivalentTo(clone)) {
    //already equivalent--don't do anything
    return false;
  }
  
  //Check for error conditions
  assert(m_module == clone->GetNamespace());

  if (m_type == varModule) {
    g_registry.SetError("Cannot set the modules '" + GetNameDelimitedBy('.') + "' and '" + clone->GetNameDelimitedBy('.') + "' to be the same thing--modules must be unique by definition.");
    return false;
  }

  //Check to make sure we don't synchronize variables that are already in each other's formulas.
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(clone)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy('.') + "' may not be set to be equal to '" + clone->GetNameDelimitedBy('.') + " because " + GetNameDelimitedBy('.') + "'s definition already includes " + clone->GetNameDelimitedBy('.') + " either directly or by proxy .");
      return true;
    }
  }
  form = clone->GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(this)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy('.') + "' may not be set to be equal to '" + clone->GetNameDelimitedBy('.') + " because " + clone->GetNameDelimitedBy('.') + "'s definition already includes " + GetNameDelimitedBy('.') + " either directly or by proxy .");
      return true;
    }
  }

  //Now, actually synchronize the data.
  if ((m_type == varUndefined) ||
      (m_type == varReactionUndef && IsReaction(clone->GetType())) ||
      (m_type == varSpeciesUndef && IsSpecies(clone->GetType())) ){
    m_type = clone->GetType();
  }
  else {
    if (clone->SetType(m_type)) {
      g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy('.') + " with " + clone->GetNameDelimitedBy('.') + " because they are set to be " + VarTypeToString(m_type) + " and " + VarTypeToString(clone->GetType()) + " types, respectively, which are incompatible:  ");
      return true;
    }
    m_type = clone->GetType();
  }

  if (m_const==constCONST) {
    clone->SetIsConst(true);
  }
  if (m_const==constVAR) {
    clone->SetIsConst(false);
  }
  //and leave it alone if it's constDEFAULT;

  if (!m_valFormula.IsEmpty()) {
    Formula* cloneform = clone->GetFormula();
    if (cloneform->IsEmpty()) {
      if (clone->SetFormula(&m_valFormula)) return true;
    }
    //else stay with the clone version--it supercedes our own.
    m_valFormula.Clear();
  }
  if (!m_valReaction.IsEmpty()) {
    const AntimonyReaction* clonerxn = clone->GetReaction();
    if (clonerxn->IsEmpty()) {
      if (clone->SetReaction(&m_valReaction)) return true;
    }
    m_valReaction.Clear();
  }
  assert(m_valModule.size()==0);
  if (!m_valStrand.IsEmpty()) {
    const DNAStrand* clonestrand = clone->GetDNAStrand();
    if (clonestrand->IsEmpty()) {
      if (clone->SetDNAStrand(m_valStrand)) return true;
    }
    m_valStrand.Clear();
  }
  
  if (m_compartment.size() > 0) {
    Variable* compartment =  g_registry.GetModule(m_module)->GetVariable(m_compartment);
    Variable* clonecompartment = clone->GetCompartment();
    if (clonecompartment == NULL) {
      clone->SetCompartment(compartment);
    }
  }

  m_sameVariable = clone->GetName();

  //And save this pair in the module as having been syncronized
  g_registry.GetModule(m_module)->AddSynchronizedPair(this, clone);

  return false;
}

bool Variable::IncludesSelf()
{
  if (IsPointer()) {
    return GetSameVariable()->IncludesSelf();
  }
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(this)) {
      g_registry.SetError("Error in model " + m_module + ":  loop detected.  The formula for '" + GetNameDelimitedBy('.') + "' ('" + GetFormula()->ToDelimitedStringWithEllipses('.') + "') contains itself, either directly or indirectly.");
      return true;
    }
  }
  return false;
}

bool Variable::AnyCompartmentLoops() const
{
  vector<const Variable*> novars;
  return AnyCompartmentLoops(novars);
}

bool Variable::AnyCompartmentLoops(vector<const Variable*> lowercomps) const
{
  if (IsPointer()) {
    return GetSameVariable()->AnyCompartmentLoops(lowercomps);
  }
  assert(m_type == varCompartment);
  lowercomps.push_back(this);
  if (m_compartment.size() == 0) return false;
  const Variable* compartment = g_registry.GetModule(m_module)->GetVariable(m_compartment);
  compartment = compartment->GetSameVariable();
  for (size_t lnum=0; lnum<lowercomps.size(); lnum++) {
    if (compartment == lowercomps[lnum]) {
      g_registry.SetError("Error in model " + m_module + ":  loop detected.  Compartments '" + GetNameDelimitedBy('.') + "' and '" + compartment->GetNameDelimitedBy('.') + "' are contained within each other.");
      return true;
    }
  }
  return compartment->AnyCompartmentLoops(lowercomps);
}

string Variable::ToString() const
{
  return GetNameDelimitedBy('.') + " (" + VarTypeToString(m_type) + ")";
}

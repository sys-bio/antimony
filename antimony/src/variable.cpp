#include <assert.h>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"
#include "typex.h"

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
    m_valRateRule(),
    m_formulatype(formulaINITIAL),
    m_compartment(),
    m_supercompartment(),
    m_supercomptype(varUndefined),
    m_strands(),
    m_type(varUndefined),
    m_const(constDEFAULT),
    m_units("")
{
  m_name.push_back(name);
}

vector<string> Variable::GetName() const
{
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

var_type Variable::GetType() const
{
  //LS NOTE:  don't get the type of the equivalent variable--that can lead to infinite loops.
  return m_type;
}

formula_type Variable::GetFormulaType() const
{
  switch(GetType()) {
  case varFormulaUndef:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    return m_formulatype;
  case varFormulaOperator:
  case varDNA:
    return formulaASSIGNMENT;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return formulaKINETIC;
  case varModule:
    return m_valModule[0].GetFormulaType();
  case varEvent:
    return formulaTRIGGER;
  case varStrand:
    return formulaASSIGNMENT; //or kinetic, but we treat them the same in this case.
  }
  assert(false); //uncaught variable type;
  return m_formulatype;
}

const Formula* Variable::GetFormula() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetFormula();
  }
  switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
  case varDNA:
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

const Formula* Variable::GetInitialAssignment() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetInitialAssignment();
  }
  switch (m_type) {
  case varFormulaUndef:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    if (m_formulatype == formulaINITIAL || m_formulatype==formulaRATE) {
      return &(m_valFormula);
    }
    else {
      return &(g_registry.m_blankform);
    }
  case varModule:
    return m_valModule[0].GetFormula();
  case varFormulaOperator:
  case varDNA:
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
  case varEvent:
  case varStrand:
    return &(g_registry.m_blankform);
  }
  assert(false); //uncaught type
  return &(g_registry.m_blankform);
}    

const Formula* Variable::GetAssignmentRuleOrKineticLaw() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetAssignmentRuleOrKineticLaw();
  }
  switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    if (m_formulatype == formulaASSIGNMENT) {
      return &(m_valFormula);
    }
    else {
      return &(g_registry.m_blankform);
    }
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return &(g_registry.m_blankform);
  case varStrand:
    return m_valStrand.GetFinalFormula();
  }
  assert(false); //uncaught type
  return &(g_registry.m_blankform);
}    

Formula* Variable::GetAssignmentRuleOrKineticLaw()
{
  if (IsPointer()) {
    return GetSameVariable()->GetAssignmentRuleOrKineticLaw();
  }
  switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    if (GetFormulaType() == formulaASSIGNMENT) {
      return &(m_valFormula);
    }
    else {
      return &(g_registry.m_blankform);
    }
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return &(g_registry.m_blankform);
  case varStrand:
    return m_valStrand.GetFinalFormula();
  }
  assert(false); //uncaught type
  return &(g_registry.m_blankform);
}

const Formula* Variable::GetRateRule() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetRateRule();
  }
  if (GetFormulaType() == formulaRATE) {
    return &(m_valRateRule);
  }
  else {
    return &(g_registry.m_blankform);
  }
}    

Formula* Variable::GetRateRule()
{
  if (IsPointer()) {
    return GetSameVariable()->GetRateRule();
  }
  if (GetFormulaType() == formulaRATE) {
    return &(m_valRateRule);
  }
  else {
    return &(g_registry.m_blankform);
  }
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
  if (m_compartment.size() > 0) {
    return g_registry.GetModule(m_module)->GetVariable(m_compartment);
  }
  return g_registry.GetModule(m_module)->GetVariable(m_supercompartment);
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
  for (set<vector<string> >::const_iterator strand = m_strands.begin(); strand != m_strands.end(); strand++) {
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
  Formula* form = vars[n]->GetAssignmentRuleOrKineticLaw();
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
  if (IsDNA(newtype)) {
    //Default formula for DNA is "...", and it must be an assignment rule.
    m_formulatype = formulaASSIGNMENT; //If it's a gene, the GetFormulaType will figure it out automatically.
    Formula formula;
    formula.AddEllipses();
    if (GetFormula()->IsEmpty()) {
      SetAssignmentRule(&formula);
    }
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
  if (!CanHaveRateRule(newtype) && !m_valRateRule.IsEmpty()) {
    g_registry.SetError("Variables with rate rules may not be set to be type " + VarTypeToString(newtype) + " because these variables do not change during the course of the model.");
    return true;
  }
  if (!CanHaveAssignmentRule(newtype) && m_formulatype == formulaASSIGNMENT) {
    g_registry.SetError("Variables with assignment rules may not be set to be type " + VarTypeToString(newtype) + " because these variables do not change during the course of the model.");
    return true;
  }

  //If we're setting this to be a species and we have a rate rule or assignment rule, we need to be 'const' (aka a boundary species):
  if (IsSpecies(newtype) && (m_formulatype == formulaASSIGNMENT || m_formulatype == formulaRATE)) {
    m_const = constCONST;
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
    case varEvent:
      m_type = newtype;
      return false;
    case varModule:
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
  case varEvent:
  case varCompartment:
    if (newtype == varFormulaUndef || newtype == varUndefined) return false;
    g_registry.SetError(error); return true; //the already-identical cases handled above.
  case varUndefined:
    m_type = newtype;
    return false;
  case varModule:
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
#ifndef NSBML
  string formstring = formula->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
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
  case varDNA:
  case varFormulaOperator:
    m_formulatype = formulaASSIGNMENT;
    m_valFormula = *formula;
    break;
  case varUndefined:
    m_type = varFormulaUndef;
    //and fall through to:
  case varFormulaUndef:
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

bool Variable::SetAssignmentRule(Formula* formula)
{
  if (IsPointer()) {
    return GetSameVariable()->SetAssignmentRule(formula);
  }
#ifndef NSBML
  string formstring = formula->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" for '" + GetNameDelimitedBy('.') + "' seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  if (formula->ContainsVar(this)) {
    g_registry.SetError("Loop detected:  " + GetNameDelimitedBy('.') + "'s definition either includes itself directly (i.e. 's5 = 6 + s5') or by proxy (i.e. 's5 = 8*d3' and 'd3 = 9*s5').");
    return true;
  }
  if (IsReaction(m_type)) {
    m_valReaction.SetFormula(formula);
    return false;
  }
  if (!CanHaveAssignmentRule(m_type)) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy('.') + "' is the type " + VarTypeToString(m_type) + ", and may not have an assignment rule associated with it.");
    return true;
  }
  if (GetFormulaType() == formulaRATE) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy('.') + "' is associated with a rate rule, and may not additionally have an assignment rule.");
    return true;
  }
  if (m_type == varUndefined) {
    m_type = varFormulaUndef;
  }
  m_formulatype = formulaASSIGNMENT;
  m_valFormula = *formula;
  return false;
}

bool Variable::SetRateRule(Formula* formula)
{
  if (IsPointer()) {
    return GetSameVariable()->SetRateRule(formula);
  }
#ifndef NSBML
  string formstring = formula->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" for '" + GetNameDelimitedBy('.') + "' seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  //if (formula->ContainsVar(this));  //Rate rules may indeed contain references to themselves!
  if (!CanHaveRateRule(m_type)) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy('.') + "' is the type " + VarTypeToString(m_type) + ", and may not have a rate rule associated with it.");
    return true;
  }
  if (GetFormulaType() == formulaASSIGNMENT) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy('.') + "' is associated with an assignment rule, and may not additionally have a rate rule.");
    return true;
  }
  if (m_type == varUndefined) {
    m_type = varFormulaUndef;
  }
  m_valRateRule = *formula;
  m_formulatype = formulaRATE;
  return false;
}

bool Variable::SetReaction(AntimonyReaction* rxn)
{
  if (IsPointer()) {
    return GetSameVariable()->SetReaction(rxn);
  }
#ifndef NSBML
  string formstring = rxn->GetFormula()->ToSBMLString(GetStrandVars());
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The reaction rate \"" + rxn->GetFormula()->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
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
  if (!m_valRateRule.IsEmpty()) {
    m_valRateRule.SetNewTopName(m_module, newtopname);
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
  if (m_supercompartment.size() > 0) {
    m_supercompartment.insert(m_supercompartment.begin(), newtopname);
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
    //These types can always be set const or non-const, even if they have assignment rules.
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
    m_const = regconst;
  }
}

bool Variable::SetCompartment(Variable* var)
{
  if (IsPointer()) {
    return GetSameVariable()->SetCompartment(var);
  }
  if (var->SetType(varCompartment)) return true;
  if (m_compartment.size() > 0) {
    if (m_compartment == var->GetName()) return false; //resetting
    g_registry.SetError("Cannot set '" + GetNameDelimitedBy('.') + "' to be in compartment '" + var->GetNameDelimitedBy('.') + "', because it is already in a different compartment (" + ToStringFromVecDelimitedBy(m_compartment, '.') + ").");
    return true;
  }
  m_compartment = var->GetName();
  return false;
}

bool Variable::SetSuperCompartment(Variable* var, var_type supertype)
{
  if (IsPointer()) {
    return GetSameVariable()->SetSuperCompartment(var, supertype);
  }
  if (m_compartment.size() > 0) return false; //Already set; no need to do anything.
  bool change = false;
  if (m_supercompartment.size() == 0) {
    change = true;
  }
  else switch (m_supercomptype) {
  case varSpeciesUndef:
  case varFormulaUndef:
  case varDNA:
  case varFormulaOperator:
  case varEvent:
  case varCompartment:
  case varUndefined:
    assert(false); // Those things don't have components
    return false;
  case varStrand:
    //Strands take precedence over everything else
    if (supertype == varStrand) {
      change = true;
    }
    break;
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
    if (supertype != varModule) {
      change = true;
    }
    break;
  case varModule:
    change = true;
    break;
  }
  if (change) {
    m_supercompartment = var->GetName();
    m_supercomptype = supertype;
    return true;
  }
  return false;
}

void Variable::SetComponentCompartments(bool frommodule)
{
  if (IsPointer()) {
    return GetSameVariable()->SetComponentCompartments(frommodule);
  }
  Variable* compartment = GetCompartment();
  if (compartment == NULL) return;
  switch(m_type) {
  case varSpeciesUndef:
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varCompartment:
  case varEvent:
  case varUndefined:
    return; //No components to set
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.SetComponentCompartments(compartment, frommodule);
  case varModule:
    return m_valModule[0].SetComponentCompartments(compartment);
  case varStrand:
    return m_valStrand.SetComponentCompartments(compartment, frommodule);
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

  //If the variables came from SBML, we can check to see if the units are the same:
  string myunits = GetUnits();
  string cloneunits = clone->GetUnits();
  if (myunits != "" && cloneunits != "" && myunits != cloneunits) {
    g_registry.SetError("The symbols " + GetNameDelimitedBy('.') + " and " + clone->GetNameDelimitedBy('.') + " may not be set to be equal to one another because the units of the first (" + myunits + ") are incompatible with the units of the second (" + cloneunits + ").");
    return true;
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

  if (clone->m_const == constDEFAULT) {
    clone->m_const = m_const;
  }

  if (!m_valFormula.IsEmpty()) {
    Formula* cloneform = clone->GetFormula();
    if (cloneform->IsEmpty() || cloneform->IsEllipsesOnly()) {
      switch (GetFormulaType()) {
      case formulaINITIAL:
      case formulaRATE: //We'll deal with the actual rate rule next.
        if (clone->SetFormula(&m_valFormula)) {
          g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy('.') + " with " + clone->GetNameDelimitedBy('.') + ":  ");
          return true;
        }
        break;
      case formulaASSIGNMENT:
        if (clone->SetAssignmentRule(&m_valFormula)) {
          g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy('.') + " with " + clone->GetNameDelimitedBy('.')+ ":  ");
          return true;
        }
        break;
      case formulaKINETIC:
      case formulaTRIGGER:
        assert(false); //How did a reaction or trigger have a m_valFormula?
        break;
      }
    }
    //else stay with the clone version--it supercedes our own.
    m_valFormula.Clear();
  }
  if (!m_valRateRule.IsEmpty()) {
    Formula* cloneform = clone->GetRateRule();
    if (cloneform->IsEmpty()) {
      if (clone->SetRateRule(&m_valRateRule))  {
        g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy('.') + " with " + clone->GetNameDelimitedBy('.') + ":  ");
        return true;
      }
    }
    //else stay with the clone version--it supercedes our own.
    m_valRateRule.Clear();
  }
  m_formulatype = clone->GetFormulaType();
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
  
  if (clone->m_compartment.size() == 0) {
    clone->m_compartment = m_compartment;
  }
  m_compartment.clear();
  if (clone->m_supercompartment.size() == 0) {
    clone->m_supercompartment = m_supercompartment;
    clone->m_supercomptype = m_supercomptype;
  }
  m_supercompartment.clear();


  

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

void Variable::FixNames()
{
  FixName(m_name);
  FixName(m_module);
  FixName(m_sameVariable);
  FixName(m_compartment);
  FixName(m_supercompartment);
  set<vector<string> > fixedstrands;
  for (set<vector<string> >::iterator strand=m_strands.begin(); strand != m_strands.end(); strand++) {
    vector<string> strandcopy = *strand;
    FixName(strandcopy);
    fixedstrands.insert(strandcopy);
  }
  m_strands = fixedstrands;

  m_valFormula.FixNames(m_module);
  m_valRateRule.FixNames(m_module);
  m_valReaction.FixNames();
  for (size_t mod=0; mod<m_valModule.size(); mod++) {
    m_valModule[mod].FixNames();
  }
  m_valEvent.FixNames();
  m_valStrand.FixNames();
}

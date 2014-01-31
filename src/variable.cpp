#include <assert.h>

#include "module.h"
#include "variable.h"
#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"
#include "typex.h"
#include "unitdef.h"

using namespace std;

Variable::Variable(const string name, const Module* module)
  : Annotated(),
    m_name(),
    m_module(module->GetModuleName()),
    m_displayname(""),
    m_sameVariable(),
    m_valFormula(),
    m_valReaction(),
    m_valModule(),
    m_valEvent(),
    m_valStrand(),
    m_valRateRule(),
    m_valUnitDef(name, module->GetModuleName()),
    m_formulatype(formulaINITIAL),
    m_extentConversionFactor(),
    m_timeConversionFactor(),
    m_compartment(),
    m_supercompartment(),
    m_supercomptype(varUndefined),
    m_strands(),
    m_type(varUndefined),
    m_deletedunit(false),
    m_replacedformrxn(false),
    m_const(constDEFAULT),
    m_unitVariable()
{
  m_name.push_back(name);
}

const vector<string>& Variable::GetName() const
{
  return m_name;
}

string Variable::GetNameDelimitedBy(string cc) const
{
  if (IsPointer()) {
    return GetSameVariable()->GetNameDelimitedBy(cc);
  }
  string retval;
  for (size_t i=0; i<m_name.size(); i++) {
    if (i>0) {
      retval += cc;
    }
    retval += m_name[i];
  }
  if (GetType()==varUnitDefinition) {
    FixUnitName(retval);
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
  if (IsPointer()) {
    return GetSameVariable()->GetFormulaType();
  }
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
  case varUnitDefinition:
  case varDeleted:
    return formulaINITIAL; //For lack of any other default.
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
  case varUnitDefinition:
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
  case varDeleted:
    return &(g_registry.m_blankform);
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
  case varUnitDefinition:
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
  case varDeleted:
    return &(g_registry.m_blankform);
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
  case varUnitDefinition:
    return &(m_valFormula);
  case varFormulaOperator:
  case varDNA:
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
  case varEvent:
  case varStrand:
  case varDeleted:
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
  case varStrand:
    return m_valStrand.GetFinalFormula();
  case varEvent:
  case varUnitDefinition:
  case varDeleted:
    return &(g_registry.m_blankform);
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
  case varStrand:
    return m_valStrand.GetFinalFormula();
  case varEvent:
  case varUnitDefinition:
  case varDeleted:
    return &(g_registry.m_blankform);
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

AntimonyReaction* Variable::GetReaction()
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

const Module* Variable::GetModule() const
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

UnitDef* Variable::GetUnitDef()
{
  if (IsPointer()) {
    return GetSameVariable()->GetUnitDef();
  }
  assert(m_type==varUnitDefinition);
  return &(m_valUnitDef);
}

const UnitDef* Variable::GetUnitDef() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetUnitDef();
  }
  assert(m_type==varUnitDefinition);
  return &(m_valUnitDef);
}

Variable* Variable::GetSubVariable(const string* name)
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

Variable* Variable::GetSameVariable()
{
  if (m_sameVariable.size() == 0) return this; //LS NOTE: speed
  Variable* var = g_registry.GetModule(m_module)->GetVariable(m_name);
  Variable* subvar = g_registry.GetModule(m_module)->GetVariable(m_sameVariable);
  if (subvar == NULL) return var;
  while (var != subvar) {
    var = subvar;
    subvar = subvar->GetSameVariable();
  }
  return var;
}

const Variable* Variable::GetSameVariable() const
{
  if (m_sameVariable.size() == 0) return this; //LS NOTE:  speed
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
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varCompartment:
    if (m_const == constDEFAULT) {
      if (GetFormula() != NULL) {
        if (GetFormula()->GetIsConst()) {
          formconst = constCONST;
        }
        else {
          formconst = constVAR;
        }
      }
      if (formconst==constDEFAULT || formconst==constCONST) return true;
      if (formconst==constVAR) return false;
    }
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return false;
  case varSpeciesUndef:
    if (m_const == constDEFAULT) return false;
    break;
  case varModule:
  case varEvent:
  case varStrand:
    return false;
  case varUndefined:
    if (m_const==constDEFAULT) return true;
    break;
  case varUnitDefinition:
  case varDeleted:
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
  if (var==NULL) return false;
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

string Variable::GetFormulaForNthEntryInStrand(string cc, size_t n)
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

string Variable::GetDisplayName() const
{
  if (IsPointer()) {
    return GetSameVariable()->GetDisplayName();
  }
  return m_displayname;
}

Variable* Variable::GetUnitVariable() const
{
  return g_registry.GetModule(m_module)->GetVariable(m_unitVariable);
}

bool Variable::SetUnitVariable(string name)
{
  FixUnitName(name);
  Variable* var = g_registry.GetModule(m_module)->AddOrFindVariable(&name);
  return SetUnitVariable(var);
}

bool Variable::SetUnitVariable(Variable* unitvar)
{
  if (unitvar==NULL) return true;
  if (unitvar->SetType(varUnitDefinition)) return true;
  m_unitVariable = unitvar->GetName();
  return false;
}

bool Variable::SetType(var_type newtype)
{
  if (newtype == varUndefined) return false;
  if (newtype == m_type) return false;
  if (newtype == varDeleted) {
    //You can delete anything
    m_type = varDeleted;
    return false;
  }
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
    if (m_valReaction.IsEmpty() && (m_valFormula.IsEmpty() || m_valFormula.ToDelimitedStringWithEllipses(".")=="...")) {
      m_type = newtype;
      m_valFormula.Clear();
      return false;
    }
    else {
      g_registry.SetError("Unable to use the variable '" + GetNameDelimitedBy(".") + "' as a DNA strand because it is already set to be a particular piece of DNA, with an associated reaction or a formula.");
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
  if (newtype == varDeleted) {
    //You can delete any type of variable.
    if (m_type == varUnitDefinition) {
      m_deletedunit = true; 
    }
    m_type = newtype;
    m_const = constDEFAULT;
    m_valFormula.Clear();
    m_valRateRule.Clear();
    m_valReaction.Clear();
    m_valUnitDef.ClearComponents();
    return false;
  }

  string error = "Unable to set the type of variable '" + GetNameDelimitedBy(".") + "' to " + VarTypeToString(newtype) + " because it is already set to be the incompatible type " + VarTypeToString(m_type) + ".  This situation can occur either with explicit type declaration or by using the variable in different, incompatible contexts.";
  switch(m_type) {
  case varSpeciesUndef:
    switch(newtype) {
    case varSpeciesUndef:
    case varDeleted:
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
    case varUnitDefinition:
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
    case varDeleted:
      m_type = newtype;
      return false;
    case varUnitDefinition:
      m_type = newtype;
      if (m_valFormula.MakeAllVariablesUnits()) return true;
      if (m_valFormula.IsDouble() && m_unitVariable.size()>0) {
        m_valFormula.AddVariable(GetUnitVariable());
      }
      if (m_valUnitDef.SetFromFormula(&m_valFormula)) return true;
      m_valFormula.Clear();
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
    case varDeleted:
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
    case varUnitDefinition:
      g_registry.SetError(error); return true;
    }
  case varFormulaOperator:
    switch(newtype) {
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varUndefined:
    case varDeleted:
      return false;
    case varSpeciesUndef:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
    case varUnitDefinition:
      g_registry.SetError(error); return true;
    }
  case varReactionGene:
    switch(newtype) {
    case varFormulaUndef:
    case varDNA:
    case varReactionGene:
    case varReactionUndef:
    case varUndefined:
    case varDeleted:
      return false;
    case varSpeciesUndef:
    case varFormulaOperator:
    case varInteraction:
    case varModule:
    case varEvent:
    case varCompartment:
    case varStrand:
    case varUnitDefinition:
      g_registry.SetError(error); return true;
    }
  case varReactionUndef:
    switch(newtype) {
    case varReactionUndef:
    case varUndefined:
    case varFormulaUndef:
    case varDeleted:
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
    case varUnitDefinition:
      g_registry.SetError(error); return true;
    }
  case varInteraction:
  case varEvent:
  case varCompartment:
  case varUnitDefinition:
    if (newtype == varFormulaUndef || newtype == varUndefined) return false;
    g_registry.SetError(error); return true; //the already-identical cases handled above.
  case varUndefined:
    m_type = newtype;
    return false;
  case varModule:
  case varStrand:
    g_registry.SetError(error); return true; //the already-identical cases handled above.
  case varDeleted:
    g_registry.SetError("Unable to set the type of variable '" + GetNameDelimitedBy(".") + "' to " + VarTypeToString(newtype) + " because it has already been deleted from the containing model.");
    return true;
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
    string errstring = SBML_getLastParseL3Error();
    if (ASTform == NULL && !errstring.empty()) {
      g_registry.SetError("In the formula \"" + formula->ToDelimitedStringWithEllipses(".") + "\":  " + errstring);
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  if (formula->ContainsVar(this)) {
    g_registry.SetError("Loop detected:  " + GetNameDelimitedBy(".") + "'s definition (" + formula->ToDelimitedStringWithEllipses(".") + ") either includes itself directly (i.e. 's5 = 6 + s5') or by proxy (i.e. 's5 = 8*d3' and 'd3 = 9*s5').");
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
  case varUnitDefinition:
    if (formula->MakeAllVariablesUnits()) return true;
    if (m_valUnitDef.SetFromFormula(formula)) return true;
    break;
  case varEvent:
    if (m_valEvent.SetTrigger(*formula)) return true;
    break;
  case varStrand:
    g_registry.SetError("Cannot set '" + GetNameDelimitedBy(".") + "' to be " + formula->ToDelimitedStringWithEllipses(".") + " because DNA strands are only defined by their components, and do not have any equations associated with them.");
    return true;
  case varDeleted:
    g_registry.SetError("Cannot set '" + GetNameDelimitedBy(".") + "' to be " + formula->ToDelimitedStringWithEllipses(".") + " because this variable was already deleted.");
  }
#ifndef NSBML
  if (m_valFormula.MakeUnitVariablesUnits()) return true;
  ASTNode* root = parseStringToASTNode(m_valFormula.ToSBMLString());
  if (root != NULL && root->isSetUnits() && root->getNumChildren()==0) {
    string unit = root->getUnits();
    if (SetUnitVariable(unit)) return true;
    //Now remove the units from the formula string, since we already stored that information.
    double val = GetValueFrom(root);
    m_valFormula.Clear();
    m_valFormula.AddNum(val);
  }
#endif
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
      g_registry.SetError("In the formula \"" + formstring + "\" for '" + GetNameDelimitedBy(".") + "':  " + SBML_getLastParseL3Error());
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  if (formula->ContainsVar(this)) {
    g_registry.SetError("Loop detected:  " + GetNameDelimitedBy(".") + "'s definition (" + formula->ToDelimitedStringWithEllipses(".") + ") either includes itself directly (i.e. 's5 := 6 + s5') or by proxy (i.e. 's5 := 8*d3' and 'd3 := 9*s5').");
    return true;
  }
  if (IsReaction(m_type)) {
    m_valReaction.SetFormula(formula);
    if (formula->MakeUnitVariablesUnits()) return true;
    return false;
  }
  if (!CanHaveAssignmentRule(m_type)) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy(".") + "' is the type " + VarTypeToString(m_type) + ", and may not have an assignment rule associated with it.");
    return true;
  }
  if (GetFormulaType() == formulaRATE && !m_valRateRule.IsEmpty()) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy(".") + "' is associated with a rate rule, and may not additionally have an assignment rule.");
    return true;
  }
  if (m_type == varUndefined) {
    m_type = varFormulaUndef;
  }
  if (formula->MakeUnitVariablesUnits()) return true;
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
      g_registry.SetError("In the formula \"" + formula->ToDelimitedStringWithEllipses(".") + "\" for '" + GetNameDelimitedBy(".") + "':  " + SBML_getLastParseL3Error());
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  //if (formula->ContainsVar(this));  //Rate rules may indeed contain references to themselves!
  if (!CanHaveRateRule(m_type)) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy(".") + "' is the type " + VarTypeToString(m_type) + ", and may not have a rate rule associated with it.");
    return true;
  }
  if (GetFormulaType() == formulaASSIGNMENT && !m_valFormula.IsEmpty()) {
    g_registry.SetError("The variable '" + GetNameDelimitedBy(".") + "' is associated with an assignment rule, and may not additionally have a rate rule.");
    return true;
  }
  if (m_type == varUndefined) {
    m_type = varFormulaUndef;
  }
  if (formula->MakeUnitVariablesUnits()) return true;
  m_valRateRule = *formula;
  m_formulatype = formulaRATE;
  //If the rate rule is being cleared, set up a deletion.

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
      g_registry.SetError("In the reaction rate \"" + rxn->GetFormula()->ToDelimitedStringWithEllipses(".") + "\":  " + SBML_getLastParseL3Error());
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  string err = "When defining reaction '" + GetNameDelimitedBy(".") + "':  ";
  if (rxn->GetLeft()->SetComponentTypesTo(varSpeciesUndef)) {
    g_registry.AddErrorPrefix(err);
    return true;
  }
  if (IsInteraction(rxn->GetType())) {
    if (SetType(varInteraction) || rxn->GetRight()->SetComponentTypesTo(varFormulaUndef)) {
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
  Module newmod(*g_registry.GetModule(*modname), m_name[0], m_module);
  m_valModule.push_back(newmod);
  m_type = varModule;
  g_registry.SetCurrentImportedModule(m_name);
  g_registry.GetModule(m_module)->AddToVarMapFrom(newmod);
  return SetType(varModule);
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
  if (m_valUnitDef.GetName().size() != 0) {
    m_valUnitDef.SetName(m_name);
  }
  if (m_compartment.size() > 0) {
    m_compartment.insert(m_compartment.begin(), newtopname);
  }
  if (m_supercompartment.size() > 0) {
    m_supercompartment.insert(m_supercompartment.begin(), newtopname);
  }
  if (m_unitVariable.size() > 0) {
    m_unitVariable.insert(m_unitVariable.begin(), newtopname);
  }
  if (m_extentConversionFactor.size() > 0) {
    m_extentConversionFactor.insert(m_extentConversionFactor.begin(), newtopname);
  }
  if (m_timeConversionFactor.size() > 0) {
    m_timeConversionFactor.insert(m_timeConversionFactor.begin(), newtopname);
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
  string error = "Cannot set '" + GetNameDelimitedBy(".") + "' to be constant";
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
  case varUnitDefinition:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for unit definitions.");
      return true;
    }
    break;
  case varDeleted:
    g_registry.SetError(error + ", as the variable was already deleted.");
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
  m_compartment = var->GetSameVariable()->GetName();
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
  case varUnitDefinition:
  case varDeleted:
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
  case varUnitDefinition:
  case varDeleted:
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
      g_registry.SetError("Cannot put the DNA strand '" + GetNameDelimitedBy(".") + "' into the strand '" + var->GetNameDelimitedBy(".") + "' because it is already in the strand '" + g_registry.GetModule(m_module)->GetVariable(*m_strands.begin())->GetNameDelimitedBy(".") + "', and can only be in one strand at a time.  If you want a copy in the new strand, you must copy the DNA itself.");
      return true;
    }
    if (m_valStrand.CheckContains(var)) {
      g_registry.SetError("Cannot put the DNA strand " + GetNameDelimitedBy(".") + " into the strand " + var->GetNameDelimitedBy(".") + " because the first already contains the second, either directly or indirectly.");
      return true;
    }
  }
  m_strands.insert(var->GetName());
  return false;
}

bool Variable::SetDisplayName(string name)
{
  if (IsPointer()) {
    return GetSameVariable()->SetDisplayName(name);
  }
  if (name == GetNameDelimitedBy(g_registry.GetCC())) return false; //Don't bother with names that are identical to id's
  size_t quote = name.find('"');
  while (quote != string::npos) {
    name.replace(quote, 1, "&quot;");
    quote = name.find('"');
  }
  m_displayname = name;
  return false;
}

//Sets this variable to be a unit definition.
bool Variable::SetUnitDef(UnitDef* unitdef)
{
  if (SetType(varUnitDefinition)) return true;
  unitdef->SetName(m_name);
  m_valUnitDef = *unitdef;
  Module* mod = g_registry.GetModule(m_module);
  if (mod != NULL && mod->AddUnitVariables(unitdef)) return true;
  return false; //success
}

//Sets this variable to *have* the given unit.
bool Variable::SetUnit(Variable* var)
{
  if (var->SetType(varUnitDefinition)) return true;
  m_unitVariable = var->GetName();
  return false; //success
}

bool Variable::SetExtentConversionFactor(Variable* var)
{
  if (var->SetType(varFormulaUndef)) return true;
  if (var->GetType() != varFormulaUndef) {
    g_registry.SetError("Unable to use " + var->GetNameDelimitedBy(".") + " as the extent conversion factor for submodel " + GetNameDelimitedBy(".") + " because that variable is of type " + VarTypeToString(var->GetType()) + " and only variables of type Formula may be used as conversion factors.");
    return true;
  }
  if (var->SetIsConst(true)) return true;
  m_extentConversionFactor = var->GetName();
  GetModule()->ConvertExtent(var);
  return false;
}

bool Variable::SetTimeConversionFactor(Variable* var)
{
  if (var->SetType(varFormulaUndef)) return true;
  if (var->GetType() != varFormulaUndef) {
    g_registry.SetError("Unable to use " + var->GetNameDelimitedBy(".") + " as the time conversion factor for submodel " + GetNameDelimitedBy(".") + " because that variable is of type " + VarTypeToString(var->GetType()) + " and only variables of type Formula may be used as conversion factors.");
    return true;
  }
  if (var->SetIsConst(true)) return true;
  m_timeConversionFactor = var->GetName();
  GetModule()->ConvertTime(var);
  return false;
}

bool Variable::SetExtentConversionFactor(double val)
{
  string convname = "extentconv";
  Variable* conversionFactor = g_registry.GetModule(m_module)->AddOrFindVariable(&convname);
  Formula* formula = new Formula();
  formula->AddNum(val);
  if (conversionFactor->SetFormula(formula)) return true;
  return SetExtentConversionFactor(conversionFactor);
}

bool Variable::SetTimeConversionFactor(double val)
{
  string convname = "timeconv";
  Variable* conversionFactor = g_registry.GetModule(m_module)->AddOrFindVariable(&convname);
  Formula* formula = new Formula();
  formula->AddNum(val);
  if (conversionFactor->SetFormula(formula)) return true;
  return SetTimeConversionFactor(conversionFactor);
}

Variable* Variable::GetExtentConversionFactor()
{
  return g_registry.GetModule(m_module)->GetVariable(m_extentConversionFactor);
}

Variable* Variable::GetTimeConversionFactor()
{
  return g_registry.GetModule(m_module)->GetVariable(m_timeConversionFactor);
}

set<pair<vector<string>, deletion_type> > Variable::GetDeletions() const
{
  return m_deletions;
}

bool Variable::DeleteFromSubmodel(Variable* deletedvar)
{
  if (GetType() != varModule) {
    assert(false);
    g_registry.SetError("Cannot delete variable " + deletedvar->GetNameDelimitedBy(".") + " because " + GetNameDelimitedBy(".") + " is not a submodel.");
    return true;
  }

  //Find and delete references to deletedvar:
  Module* submod = GetModule();
  submod->ClearReferencesTo(deletedvar, &m_deletions);

  //Now delete the deleted variable's own rate rule, assignment rule, and/or initial assignment
 Formula* form = deletedvar->GetFormula();
 Formula* rform = deletedvar->GetRateRule();
 switch(deletedvar->GetType()) {
 case varSpeciesUndef:
 case varFormulaUndef:
 case varUndefined:
 case varCompartment:
   switch (deletedvar->GetFormulaType()) {
   case formulaRATE:
     if (!rform->IsEmpty()) {
       m_deletions.insert(make_pair(deletedvar->GetName(), delRateRule));
     }
     //Fall through to:
   case formulaINITIAL:
     if (!(form->IsEmpty() || form->IsDouble())) {
       if (!(IsSpecies(deletedvar->GetType()) && form->IsAmountIn(deletedvar->GetCompartment()))) {
         m_deletions.insert(make_pair(deletedvar->GetName(), delInitialAssignment));
       }
     }
     break;
   case formulaASSIGNMENT: 
     if (!form->IsEmpty()) {
       m_deletions.insert(make_pair(deletedvar->GetName(), delAssignmentRule));
     }
     break;
   case formulaKINETIC:
   case formulaTRIGGER:
     //Nothing extra needed.
     break;
   }
   break;
  case varDNA:
  case varFormulaOperator:
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
  case varModule:
  case varEvent:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
    //These types can't have rules to them.
    break;
  }

  //Save the fact that you deleted the variable:
  if (deletedvar->GetType() == varInteraction) {
    m_deletions.insert(make_pair(deletedvar->GetName(), delInteraction));
  }
  else {
    m_deletions.insert(make_pair(deletedvar->GetName(), delFull));
  }
  //And set deletedvar to 'deleted'!  Like Strong Bad!
  deletedvar->SetType(varDeleted);
  return false;
}

void Variable::AddDeletion(Variable* var, deletion_type deltype)
{
  assert(var != NULL);
  if (var==NULL) return;
  m_deletions.insert(make_pair(var->GetName(), deltype));
}

set<pair<vector<string>, deletion_type> > Variable::ClearReferencesTo(Variable* deletedvar)
{
  set<pair<vector<string>, deletion_type> > ret;
  set<pair<vector<string>, deletion_type> > temp;
  Module* parentmod = g_registry.GetModule(m_module);
  if (m_valFormula.ClearReferencesTo(deletedvar)) {
    if (m_formulatype == formulaINITIAL) {
      ret.insert(make_pair(m_name, delInitialAssignment));
    }
    else if (m_formulatype == formulaASSIGNMENT) {
      ret.insert(make_pair(m_name, delAssignmentRule));
    }
    else {
      assert(false);
    }
  }
  m_valReaction.ClearReferencesTo(deletedvar, &ret);
  if (!m_valModule.empty()) {
    m_valModule[0].ClearReferencesTo(deletedvar, &ret);
  }
  if (m_valEvent.ClearReferencesTo(deletedvar, &ret)) {
    //The event is no longer viable, and must be cleared and deleted.
    AntimonyEvent ae;
    m_valEvent = ae;
    Module* module = g_registry.GetModule(m_module);
    Variable* deleteme = module->GetVariable(m_name);
    module->AddDeletion(deleteme);
    return ret;
  }
  if (m_valStrand.ClearReferencesTo(deletedvar)) {
    //LS DEBUG:  do something?
  }
  if (m_type==varUnitDefinition && m_valUnitDef.ClearReferencesTo(deletedvar)) {
    ret.insert(make_pair(m_name, delFull));
    m_deletedunit = true;
  }
  if (m_valRateRule.ClearReferencesTo(deletedvar)) {
    ret.insert(make_pair(m_name, delRateRule));
  }
  if (deletedvar->GetIsEquivalentTo(parentmod->GetVariable(m_extentConversionFactor))) {
    //NOTE:  untranslateable to SBML, since you can't delete an attribute, nor effectively replace a submodel.
    m_extentConversionFactor.clear();
  }
  if (deletedvar->GetIsEquivalentTo(parentmod->GetVariable(m_timeConversionFactor))) {
    //NOTE:  untranslateable to SBML, since you can't delete an attribute, nor effectively replace a submodel.
    m_timeConversionFactor.clear();
  }
  if (deletedvar->GetIsEquivalentTo(parentmod->GetVariable(m_compartment))) {
    //NOTE:  untranslateable to SBML, since you can't delete an attribute, nor effectively replace a submodel.
    m_compartment.clear();
  }
  if (deletedvar->GetIsEquivalentTo(parentmod->GetVariable(m_supercompartment))) {
    //Untranslateable to SBML, but so are supercompartments, so it's OK.
    m_supercompartment.clear();
  }
  set<vector<string> >::iterator strand=m_strands.begin();
  while (strand != m_strands.end()) {
    //LS DEBUG:  I don't think it's worth worrying about translating these deletions yet, until there's an actual corresponding element in SBML or CellML or something.
    if (parentmod->GetVariable(*strand)->GetSameVariable() == deletedvar) {
      m_strands.erase(strand);
      strand = m_strands.begin();
    }
    else {
      strand++;
    }
  }
  if (deletedvar->GetIsEquivalentTo(parentmod->GetVariable(m_unitVariable))) {
    //NOTE:  untranslateable to SBML, since you can't delete an attribute.
    m_unitVariable.clear();
  }
  return ret;
}

//Set this variable to be a shell pointing to the clone, transferring any data we may already have.
bool Variable::Synchronize(Variable* clone, const Variable* conversionFactor)
{
  if (IsPointer()) {
    if(GetSameVariable()->Synchronize(clone, conversionFactor)) return true;
    m_type = clone->GetType();
    return false;
  }
  if (clone == NULL) {
    g_registry.SetError("No such variable in this module.");
    return true;
  }
  if ((m_type == varModule) || (clone->m_type == varModule)) {
    g_registry.SetError("Modules may not be synchronized directly.  Instead, synchronize elements of the modules individually.");
    return true;
  }
  if (clone->IsPointer()) {
    //We have to wrap this in this check because sometimes we're synchronizing variables that are not actually in the model (to check if they've been written out already when outputting Antimony script).
    clone = clone->GetSameVariable();
  }
  if (GetIsEquivalentTo(clone)) {
    //already equivalent--don't do anything
    return false;
  }

  //Check for error conditions
  assert(m_module == clone->GetNamespace());

  if (m_type == varModule) {
    g_registry.SetError("Cannot set the modules '" + GetNameDelimitedBy(".") + "' and '" + clone->GetNameDelimitedBy(".") + "' to be the same thing--modules must be unique by definition.");
    return true;
  }

  //Check to make sure we don't synchronize variables that are already in each other's formulas.
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(clone)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy(".") + "' may not be set to be equal to '" + clone->GetNameDelimitedBy(".") + "' because " + GetNameDelimitedBy(".") + "'s definition already includes " + clone->GetNameDelimitedBy(".") + " either directly or by proxy.");
      return true;
    }
  }
  form = clone->GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(this)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy(".") + "' may not be set to be equal to '" + clone->GetNameDelimitedBy(".") + "' because " + clone->GetNameDelimitedBy(".") + "'s definition already includes " + GetNameDelimitedBy(".") + " either directly or by proxy.");
      return true;
    }
  }

  if ((m_type == varUndefined) ||
      (m_type == varReactionUndef && IsReaction(clone->GetType())) ||
      (m_type == varSpeciesUndef && IsSpecies(clone->GetType())) ){
    m_type = clone->GetType();
  }
  else {
    if (clone->SetType(m_type)) {
      g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy(".") + " with " + clone->GetNameDelimitedBy(".") + " because they are set to be " + VarTypeToString(m_type) + " and " + VarTypeToString(clone->GetType()) + " types, respectively, which are incompatible:  ");
      return true;
    }
    m_type = clone->GetType();
  }

  //Now, actually synchronize the data.

  //Synchronize the units:
  Variable* unitvar = GetUnitVariable();
  Variable* cloneuv = clone->GetUnitVariable();
  if (unitvar!=NULL) {
    if (cloneuv==NULL) {
      clone->SetUnitVariable(unitvar);
    }
    else if (conversionFactor==NULL) {
      UnitDef* ud = unitvar->GetUnitDef();
      UnitDef* cloneud = cloneuv->GetUnitDef();
      if (ud != NULL && cloneud != NULL && !ud->Matches(cloneud)) {
        g_registry.SetError("The symbols " + GetNameDelimitedBy(".") + " and " + clone->GetNameDelimitedBy(".") + " may not be set to be equal to one another because the units of the first (" + ud->GetNameDelimitedBy(".") + ") are incompatible with the units of the second (" + cloneud->GetNameDelimitedBy(".") + ").");
        return true;
      }
    }
    m_unitVariable.clear();
  }
  
  //Synchronize the const-ness
  if (clone->m_const == constDEFAULT) {
    clone->m_const = m_const;
  }
  m_const = clone->m_const;

  if (m_displayname != "") {
    if (clone->GetDisplayName() == "") {
      clone->SetDisplayName(m_displayname);
    }
    m_displayname = "";
  }

  //Synchronize the formulas.
  if (!m_valFormula.IsEmpty()) {
    Formula* cloneform = clone->GetFormula();
    if (cloneform->IsEmpty() || cloneform->IsEllipsesOnly()) {
      m_valFormula.AddConversionFactor(conversionFactor);
      switch (GetFormulaType()) {
      case formulaINITIAL:
      case formulaRATE: //We'll deal with the actual rate rule next.
        if (clone->SetFormula(&m_valFormula)) {
          g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy(".") + " with " + clone->GetNameDelimitedBy(".") + ":  ");
          return true;
        }
        break;
      case formulaASSIGNMENT:
        if (clone->SetAssignmentRule(&m_valFormula)) {
          g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy(".") + " with " + clone->GetNameDelimitedBy(".")+ ":  ");
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
      m_valRateRule.AddConversionFactor(conversionFactor);
      if (clone->SetRateRule(&m_valRateRule))  {
        g_registry.AddErrorPrefix("Cannot synchronize " + GetNameDelimitedBy(".") + " with " + clone->GetNameDelimitedBy(".") + ":  ");
        return true;
      }
    }
    //else stay with the clone version--it supercedes our own.
    m_valRateRule.Clear();
  }
  m_formulatype = clone->GetFormulaType();

  //Synchronize the Reactions.
  if (!m_valReaction.IsEmpty()) {
    const AntimonyReaction* clonerxn = clone->GetReaction();
    if (clonerxn->IsEmpty()) {
      m_valReaction.GetFormula()->AddConversionFactor(conversionFactor);
      if (clone->SetReaction(&m_valReaction)) return true;
    }
    m_replacedformrxn = true;
    m_valReaction.Clear();
  }

  //Don't synchronize modules (should be accounted for above)
  assert(m_valModule.size()==0);

  //Synchronize DNA strands
  if (!m_valStrand.IsEmpty()) {
    const DNAStrand* clonestrand = clone->GetDNAStrand();
    if (clonestrand->IsEmpty()) {
      if (clone->SetDNAStrand(m_valStrand)) return true;
    }
    m_valStrand.Clear();
  }
  
  //Synchronize the compartments.
  if (clone->m_compartment.size() == 0) {
    clone->m_compartment = m_compartment;
  }
  m_compartment.clear();
  if (clone->m_supercompartment.size() == 0) {
    clone->m_supercompartment = m_supercompartment;
    clone->m_supercomptype = m_supercomptype;
  }
  m_supercompartment.clear();

  //We always synchronize the data above first, but where we store it can change based on which version is the top-level.
  if (clone->m_name.size() > 1 && m_name.size() == 1) {
    //When synchronizing a local variable to a submodule's variable, always have the local trump the submodule.
    return (clone->Synchronize(this, NULL));
  }
  
  m_sameVariable = clone->GetName();

  //And save this pair in the module as having been syncronized
  g_registry.GetModule(m_module)->AddSynchronizedPair(this, clone, conversionFactor);

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
      g_registry.SetError("Error in model " + m_module + ":  loop detected.  The formula for '" + GetNameDelimitedBy(".") + "' ('" + GetFormula()->ToDelimitedStringWithEllipses(".") + "') contains itself, either directly or indirectly.");
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
      g_registry.SetError("Error in model " + m_module + ":  loop detected.  Compartments '" + GetNameDelimitedBy(".") + "' and '" + compartment->GetNameDelimitedBy(".") + "' are contained within each other.");
      return true;
    }
  }
  return compartment->AnyCompartmentLoops(lowercomps);
}

string Variable::ToString() const
{
  string ret = GetNameDelimitedBy(".") + " (" + VarTypeToString(m_type) + ")";
  if (GetFormula() != NULL) {
    ret += ": " + GetFormula()->ToDelimitedStringWithEllipses(".");
  }
  return ret;
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

bool Variable::StillMatchesOriginal(formula_type ftype) const
{
  const Formula* formnow = GetFormula();
  if (ftype==formulaRATE) {
    formnow = GetRateRule();
  }
  if (m_name.size() == 1) return true; //It still is the original!
  const Variable* origvar = GetOriginal();
  const Formula* formthen = origvar->GetFormula();
  if (ftype==formulaRATE) {
    formthen = origvar->GetRateRule();
  }
  return formnow->Matches(formthen);
}

const Variable* Variable::GetOriginal() const
{
  if (m_name.size()==1) return this;
  vector<string> modname = m_name;
  modname.pop_back();
  Variable* modvar = g_registry.GetModule(m_module)->GetVariable(modname);
  Module* origmod = g_registry.GetModule(modvar->GetModule()->GetModuleName());
  vector<string> origname;
  origname.push_back(m_name[m_name.size()-1]);
  return origmod->GetVariable(origname);
}

Variable* Variable::GetParentVariable()
{
  vector<string> parentname = m_name;
  parentname.pop_back();
  if (parentname.size()==0) {
    return NULL;
  }
  return g_registry.GetModule(m_module)->GetVariable(parentname);  
}

#ifndef NSBML
void Variable::SetWithRule(const Rule* rule)
{
  Formula formula;
  string formulastring(parseASTNodeToString(rule->getMath()));
  setFormulaWithString(formulastring, &formula, g_registry.GetModule(m_module));
  formula.SetNewTopNameWith(rule, m_module);
  formula.SetAnnotation(rule);
  if (IsSpecies(GetType())) {
    //Any species in any rule must be 'const' (in Antimony), because this means it's a 'boundary species'
    SetIsConst(true);
  }
  else {
    //For other parameters, assignment and rate rules always mean the variable in question is not constant.
    SetIsConst(false);
  }

  if (rule->isAssignment()) {
    SetAssignmentRule(&formula);
  }
  else if (rule->isRate()) {
    SetRateRule(&formula);
  }
  else {
    assert(false); //Algebraic rules should be caught in calling function
  }
}

#endif

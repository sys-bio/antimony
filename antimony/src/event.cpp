#include <assert.h>

#include "event.h"
#include "typex.h"
#include "variable.h"
#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"

using namespace std;

AntimonyEvent::AntimonyEvent(const Formula& delay, const Formula& trigger, Variable* var)
  : m_trigger(trigger),
    m_delay(delay),
    m_priority(),
    m_useValuesFromTriggerTime(true),
    m_persistent(true),
    m_initialValue(true),
    m_varresults(),
    m_formresults(),
    m_name(var->GetName()),
    m_module(var->GetNamespace())
{
}

AntimonyEvent::AntimonyEvent()
  : m_trigger(),
    m_delay(),
    m_priority(),
    m_useValuesFromTriggerTime(true),
    m_persistent(true),
    m_initialValue(true),
    m_varresults(),
    m_formresults(),
    m_name(),
    m_module()
{
}

bool AntimonyEvent::SetTrigger(const Formula& form)
{
  string formstring = form.ToSBMLString();
#ifndef NSBML
  if (formstring.size() > 0) {
    ASTNode* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + form.ToDelimitedStringWithEllipses(".") + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else if (!ASTform->isBoolean()) {
      g_registry.SetError("The formula \"" + form.ToDelimitedStringWithEllipses(".") + "\" cannot be parsed in a boolean context, and it is therefore illegal to use it as the trigger for an event.  (Perhaps try adding parentheses?)");
      delete ASTform;
      return true;
    }
    delete ASTform;
  }
#endif
  m_trigger = form;
  return false;
}

bool AntimonyEvent::SetPriority(const Formula& priority)
{
  string prioritystring = priority.ToSBMLString();
#ifndef NSBML
  if (prioritystring.size() > 0) {
    ASTNode* ASTpriority = parseStringToASTNode(prioritystring);
    if (ASTpriority == NULL) {
      g_registry.SetError("The priority \"" + priority.ToDelimitedStringWithEllipses(".") + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else if (ASTpriority->isBoolean()) {
      g_registry.SetError("The priority \"" + priority.ToDelimitedStringWithEllipses(".") + "\" is boolean, and it is therefore illegal to use it as the priority for an event.  Perhaps this was meant as the trigger?  If the line is being misparsed, try adding parentheses.");
      delete ASTpriority;
      return true;
    }
    delete ASTpriority;
  }
#endif
  m_priority = priority;
  return false;
}

bool AntimonyEvent::SetUseValuesFromTriggerTime(const Formula& form)
{
  if (!form.IsBoolean()) {
    g_registry.SetError("Unable to use '" + form.ToDelimitedStringWithEllipses(".") + "': only 'true' or 'false' may be used to set the value of 'fromTrigger' on an event.");
    return true;
  }
  m_useValuesFromTriggerTime = form.GetBoolean();
  return false;
}

bool AntimonyEvent::SetPersistent(const Formula& form)
{
  if (!form.IsBoolean()) {
    g_registry.SetError("Unable to use '" + form.ToDelimitedStringWithEllipses(".") + "': only 'true' or 'false' may be used to set the value of 'persistent' on an event.");
    return true;
  }
  m_persistent = form.GetBoolean();
  return false;
}

bool AntimonyEvent::SetInitialValue(const Formula& form)
{
  if (!form.IsBoolean()) {
    g_registry.SetError("Unable to use '" + form.ToDelimitedStringWithEllipses(".") + "': only 'true' or 'false' may be used to set the value of 't0' (the initial value) of an event.");
    return true;
  }
  m_initialValue = form.GetBoolean();
  return false;
}

bool AntimonyEvent::AddResult(Variable* var, Formula* form)
{
  m_varresults.insert(m_varresults.begin(), var->GetName());
  m_formresults.insert(m_formresults.begin(), *form);
  var->SetType(varFormulaUndef);
  if (!IsSpecies(var->GetType())) {
    var->SetIsConst(false);//It might be a straight value, but the event changes it.
  }
  return false;
}

void AntimonyEvent::SetNewTopName(string modname, string newtopname)
{
  //Ourself:
  m_name.insert(m_name.begin(), newtopname);
  m_module = modname;
  //Our dependents:
  m_trigger.SetNewTopName(modname, newtopname);
  m_delay.SetNewTopName(modname, newtopname);
  m_priority.SetNewTopName(modname, newtopname);
  assert(m_varresults.size() == m_formresults.size());
  for (size_t result=0; result<m_varresults.size(); result++) {
    m_varresults[result].insert(m_varresults[result].begin(), newtopname);
    m_formresults[result].SetNewTopName(modname, newtopname);
  }
}

bool AntimonyEvent::IsEmpty() const
{
  if (m_trigger.IsEmpty()) {
    return true;
  }
  return false;
}

bool AntimonyEvent::CheckFormulas() const
{
  if (m_trigger.ContainsCurlyBrackets()) {
    g_registry.SetError("Curly brackets detected in the event trigger: '" + m_trigger.ToDelimitedStringWithEllipses(".") + "': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
    return true;
  }
  if (m_delay.ContainsCurlyBrackets()) {
    g_registry.SetError("Curly brackets detected in the event delay: '" + m_trigger.ToDelimitedStringWithEllipses(".") + "': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
    return true;
  }
  if (m_priority.ContainsCurlyBrackets()) {
    g_registry.SetError("Curly brackets detected in the event priority: '" + m_trigger.ToDelimitedStringWithEllipses(".") + "': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
    return true;
  }
  for (size_t fr = 0; fr < m_formresults.size(); fr++) {
    if (m_formresults[fr].ContainsCurlyBrackets()) {
      g_registry.SetError("Curly brackets detected in the event assignment: '" + m_formresults[fr].ToDelimitedStringWithEllipses(".") + "': vectors are not supported in the current version of Antimony apart from their use in setting certain uncertainty parameters.");
      return true;
    }

  }
  return false;
}

void AntimonyEvent::Convert(Variable* converted, Variable* cf)
{
  m_trigger.Convert(converted, cf);
  m_delay.Convert(converted, cf);
  m_priority.Convert(converted, cf);
  for (size_t fr=0; fr<m_formresults.size(); fr++) {
    Variable* asntvar = g_registry.GetModule(m_module)->GetVariable(m_varresults[fr]);
    if (converted->GetSameVariable() == asntvar->GetSameVariable()) {
      m_formresults[fr].AddConversionFactor(cf);
    }
    m_formresults[fr].Convert(converted, cf);
  }
}

void AntimonyEvent::ConvertTime(Variable* tcf)
{
  m_trigger.ConvertTime(tcf);
  m_delay.ConvertTime(tcf);
  m_delay.AddConversionFactor(tcf);
  m_priority.ConvertTime(tcf);
  for (size_t fr=0; fr<m_formresults.size(); fr++) {
    m_formresults[fr].ConvertTime(tcf);
  }
}

void AntimonyEvent::UnConvertTimeExtent(Variable* tcf, Variable* xcf)
{
  m_trigger.UnConvertTimeExtent(tcf, xcf);
  m_delay.UnConvertTimeExtent(tcf, xcf);
  m_delay.UnConvertTimeExtent(tcf, xcf);
  m_priority.UnConvertTimeExtent(tcf, xcf);
  for (size_t fr=0; fr<m_formresults.size(); fr++) {
    m_formresults[fr].UnConvertTimeExtent(tcf, xcf);
  }
}

bool AntimonyEvent::ClearReferencesTo(Variable* deletedvar, set<pair<vector<string>, deletion_type> >* ret)
{
  if (IsEmpty()) return false;
  if (m_trigger.ClearReferencesTo(deletedvar)) {
    //Can't (yet?) have an event with no trigger: delete the event
    return true;
  }
  if (m_delay.ClearReferencesTo(deletedvar)) {
    ret->insert(make_pair(m_name, delEventDelay));
  }
  if (m_priority.ClearReferencesTo(deletedvar)) {
    ret->insert(make_pair(m_name, delEventPriority));
  }
  vector<Formula>::iterator form = m_formresults.begin();
  vector<vector<string> >::iterator varresult = m_varresults.begin();
  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  while (form != m_formresults.end()) {
    if (form->ClearReferencesTo(deletedvar) ||
        module->GetVariable(*varresult)->GetIsEquivalentTo(deletedvar)) {
          vector<string> longername = m_name;
          longername.push_back((*varresult)[varresult->size()-1]);
          ret->insert(make_pair(longername,  delEventAssignment));
          form = m_formresults.erase(form);
          varresult = m_varresults.erase(varresult);
    }
    else {
      form++;
      varresult++;
    }
  }
  if (m_formresults.size() == 0) {
    //Can't (yet?) have an event with no event assignments: delete the event
    return true;
  }
  return false; //Didn't have to delete ourselves.
}

string AntimonyEvent::GetNthAssignmentVariableName(size_t n, string cc) const
{
  if (n >= m_varresults.size()) {
    string error = "Unable to retrieve assignment '" + SizeTToString(n) + "' from event " + ToStringFromVecDelimitedBy(m_name, cc) + ":  ";
    if (m_varresults.size() == 0) {
      error += "No assignments are present for this event at all.";
    }
    else if (m_varresults.size() == 1) {
      error += "A single event assignment is present for this event with index 0.";
    }
    else {
      error += "Valid assignment indices for this event are 0 through " + SizeTToString(m_varresults.size());
    }
    g_registry.SetError(error);
    return "";
  }
  Variable* resultvar = g_registry.GetModule(m_module)->GetVariable(m_varresults[n]);
  if (resultvar == NULL) {
    assert(false);
    return "";
  }
  return resultvar->GetNameDelimitedBy(cc);
}

string AntimonyEvent::GetNthAssignmentFormulaString(size_t n, string cc, bool SBML) const
{
  if (n >= m_formresults.size()) {
    string error = "Unable to retrieve assignment '" + SizeTToString(n) + "' from event " + ToStringFromVecDelimitedBy(m_name, cc) + ":  ";
    if (m_formresults.size() == 0) {
      error += "No assignments are present for this event at all.";
    }
    else if (m_formresults.size() == 1) {
      error += "A single event assignment is present for this event with index 0.";
    }
    else {
      error += "Valid assignment indices for this event are 0 through " + SizeTToString(m_formresults.size()) + ".";
    }
    g_registry.SetError(error);
    return "";
  }
  Variable* resultvar = g_registry.GetModule(m_module)->GetVariable(m_varresults[n]);
  if (SBML) {
    return m_formresults[n].ToSBMLString(resultvar->GetStrandVars());
  }
  return m_formresults[n].ToDelimitedStringWithStrands(cc, resultvar->GetStrandVars());
}

string AntimonyEvent::ToStringDelimitedBy(string cc) const
{
  if (IsEmpty()) return "";
  string retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* actualvar = module->GetVariable(m_name);
  if (actualvar == NULL) {
    //um what?
    assert(false);
    return "";
  }
  retval += actualvar->GetNameDelimitedBy(cc) + ": at ";
  if (!m_delay.IsEmpty()) {
    retval += m_delay.ToDelimitedStringWithEllipses(cc) + " after ";
  }
  retval += m_trigger.ToDelimitedStringWithEllipses(cc);
  if (!m_priority.IsEmpty()) {
    retval += ", priority = " + m_priority.ToDelimitedStringWithEllipses(cc);
  }
  if (m_initialValue == false) {
    retval += ", t0=false";
  }
  if (m_persistent == false) {
    retval += ", persistent=false";
  }
  if (m_useValuesFromTriggerTime == false) {
    retval += ", fromTrigger=false";
  }
  retval += ": ";
  for (size_t result=0; result<m_varresults.size(); result++) {
    if (result>0) {
      retval += ", ";
    }
    Variable* resultvar = g_registry.GetModule(m_module)->GetVariable(m_varresults[result]);
    if (resultvar == NULL) {
      assert(false);
      return "";
    }
    retval += resultvar->GetNameDelimitedBy(cc);
    retval += " = ";
    retval += m_formresults[result].ToDelimitedStringWithEllipses(cc);
  }
  retval += ";";
  
  return retval;
}

void AntimonyEvent::FixNames()
{
  m_trigger.FixNames(m_module);
  FixName(m_varresults);
  for (size_t formr=0; formr<m_formresults.size(); formr++) {
    m_formresults[formr].FixNames(m_module);
  }
  FixName(m_name);
  FixName(m_module);
}

bool AntimonyEvent::Matches(const AntimonyEvent* newevent) const
{
  if (m_useValuesFromTriggerTime != newevent->m_useValuesFromTriggerTime) return false;
  if (m_persistent != newevent->m_persistent) return false;
  if (m_initialValue != newevent->m_initialValue) return false;
  if (!m_trigger.Matches(newevent->GetTrigger())) return false;
  if (!m_delay.Matches(newevent->GetDelay())) {
    if (!(newevent->GetDelay()->IsEmpty() && 
           m_delay.ContainsDeletedVar())) {
      return false;
    }
  }
  if (!m_priority.Matches(newevent->GetPriority())) {
    if (!(newevent->GetPriority()->IsEmpty() && 
           m_priority.ContainsDeletedVar())) {
      return false;
    }
  }
  if (m_formresults.size() < newevent->GetNumAssignments()) return false;
  //Create copies we can mess with:
  vector<vector<string> > varresults = m_varresults;
  vector<Formula> formresults = m_formresults;
  if (m_formresults.size() > newevent->m_formresults.size()) {
    //Some of the event assignments might have been deleted automatically.
    set<vector<string> > oldvars(m_varresults.begin(), m_varresults.end());
    set<vector<string> > newvars(newevent->m_varresults.begin(), newevent->m_varresults.end());
    for (set<vector<string> >::iterator ov=oldvars.begin(); ov != oldvars.end(); ov++) {
      if (newvars.find(*ov) == newvars.end()) {
        size_t match = 0;
        for (size_t ovnum=0; ovnum<varresults.size(); ovnum++) {
          if (varresults[ovnum] == *ov) {
            match = ovnum;
            break;
          }
        }
        Module* module = g_registry.GetModule(m_module);
        assert(module != NULL);
        Variable* ov_var = module->GetVariable(*ov);
        if (ov_var->GetType() == varDeleted || formresults[match].ContainsDeletedVar()) {
          formresults.erase(formresults.begin()+match);
          varresults.erase(varresults.begin()+match);
        }
        else {
          return false;
        }
      }
    }
  }

  if (formresults.size() != newevent->m_formresults.size()) return false;
  for (size_t fr=0; fr<formresults.size(); fr++) {
    if (!formresults[fr].Matches(newevent->GetAssignmentFormula(fr))) return false;
    if (varresults[fr] != newevent->m_varresults[fr]) return false;
  }
  return true;
}

const Formula* AntimonyEvent::GetAssignmentFormula(size_t n) const
{
  if (n >= m_formresults.size()) return NULL;
  return &m_formresults[n];
}

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
    m_varresults(),
    m_formresults(),
    m_name(var->GetName()),
    m_module(var->GetNamespace())
{
}

AntimonyEvent::AntimonyEvent()
  : m_trigger(),
    m_delay(),
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
      g_registry.SetError("The formula \"" + form.ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else if (!ASTform->isBoolean()) {
      g_registry.SetError("The formula \"" + form.ToDelimitedStringWithEllipses('.') + "\" cannot be parsed in a boolean context, and it is therefore illegal to use it as the trigger for an event.  (Perhaps try adding parentheses?)");
      delete ASTform;
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  m_trigger = form;
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

string AntimonyEvent::GetNthAssignmentVariableName(size_t n, char cc) const
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

string AntimonyEvent::GetNthAssignmentFormulaString(size_t n, char cc, bool SBML) const
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

string AntimonyEvent::ToStringDelimitedBy(char cc) const
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
  retval += m_trigger.ToDelimitedStringWithEllipses(cc) + ": ";
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
    retval += m_formresults[result].ToDelimitedStringWithStrands(cc, resultvar->GetStrandVars());
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

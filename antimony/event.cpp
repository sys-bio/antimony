#include <assert.h>

#include "event.h"
#include "variable.h"
#include "registry.h"
#include "stringx.h"

using namespace std;

AntimonyEvent::AntimonyEvent(const Formula& trigger, Variable* var)
  : m_trigger(trigger),
    m_varresults(),
    m_formresults(),
    m_name(var->GetName()),
    m_module(var->GetNamespace())
{
}

AntimonyEvent::AntimonyEvent()
  : m_trigger(),
    m_varresults(),
    m_formresults(),
    m_name(),
    m_module()
{
}

void AntimonyEvent::SetTrigger(const Formula& form)
{
  m_trigger = form;
}

bool AntimonyEvent::AddResult(Variable* var, Formula* form)
{
  m_varresults.insert(m_varresults.begin(), var->GetName());
  m_formresults.insert(m_formresults.begin(), *form);
  return false;
}

void AntimonyEvent::SetNewTopName(string modname, string newtopname)
{
  //Ourself:
  m_name.insert(m_name.begin(), newtopname);
  m_module = modname;
  //Our dependents
  m_trigger.SetNewTopName(modname, newtopname);
  assert(m_varresults.size() == m_formresults.size());
  for (size_t result=0; result<m_varresults.size(); result++) {
    m_varresults[result].insert(m_varresults[result].begin(), newtopname);
    m_formresults[result].SetNewTopName(modname, newtopname);
  }
}

string AntimonyEvent::GetNthAssignmentVariableName(size_t n, char cc) const
{
  if (n >= m_varresults.size()) {
    string error = "Unable to retrieve assignment '" + ToString(n) + "' from event " + ToStringFromVecDelimitedBy(m_name, cc) + ":  ";
    if (m_varresults.size() == 0) {
      error += "No assignments are present for this event at all.";
    }
    else if (m_varresults.size() == 1) {
      error += "A single event assignment is present for this event with index 0.";
    }
    else {
      error += "Valid assignment indices for this event are 0 through " + ToString(m_varresults.size());
    }
    g_registry.SetError(error);
    return "";
  }
  return ToStringFromVecDelimitedBy(m_varresults[n], cc);
}

string AntimonyEvent::GetNthAssignmentFormulaString(size_t n, char cc) const
{
  if (n >= m_formresults.size()) {
    string error = "Unable to retrieve assignment '" + ToString(n) + "' from event " + ToStringFromVecDelimitedBy(m_name, cc) + ":  ";
    if (m_formresults.size() == 0) {
      error += "No assignments are present for this event at all.";
    }
    else if (m_formresults.size() == 1) {
      error += "A single event assignment is present for this event with index 0.";
    }
    else {
      error += "Valid assignment indices for this event are 0 through " + ToString(m_formresults.size()) + ".";
    }
    g_registry.SetError(error);
    return "";
  }
  return m_formresults[n].ToStringDelimitedBy(cc);
}

string AntimonyEvent::ToStringDelimitedBy(char cc) const
{
  string retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* actualvar = module->GetVariable(m_name);
  if (actualvar == NULL) {
    //um what?
    assert(false);
    return retval;
  }
  retval += actualvar->GetNameDelimitedBy(cc) + ": @(";
  retval += m_trigger.ToStringDelimitedBy(cc) + "): ";
  for (size_t result=0; result<m_varresults.size(); result++) {
    if (result>0) {
      retval += ", ";
    }
    retval += ToStringFromVecDelimitedBy(m_varresults[result], cc);
    retval += " = ";
    retval += m_formresults[result].ToStringDelimitedBy(cc);
  }
  retval += ";";
  
  return retval;
}

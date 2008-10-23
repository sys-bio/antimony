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
  m_varresults.push_back(var->GetName());
  m_formresults.push_back(*form);
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

string AntimonyEvent::ToStringDelimitedBy(char cc) const
{
  string retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* actualvar = module->GetVariable(m_name);
  if (actualvar == NULL) {
    //um what?
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
  retval += ";\n";
  
  return retval;
}

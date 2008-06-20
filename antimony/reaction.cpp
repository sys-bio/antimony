#include <assert.h>

#include "reaction.h"
#include "registry.h"
#include "rd_type.h"
#include "module.h"
#include "variable.h"

using namespace std;

Reaction::Reaction(ReactantList left, rd_type divider, ReactantList right, Formula formula, Variable* var)
  : m_empty(false),
    m_left(left),
    m_right(right),
    m_divider(divider),
    m_name(var->GetName()),
    m_formula(formula)
{
  //The reactantlists have pointers to variables in them, so they need to be
  // set properly before using this constructor.
}


Reaction::Reaction()
  : m_empty(true),
    m_left(),
    m_right(),
    m_divider(rdBecomes),
    m_name(),
    m_formula()
{
}

void Reaction::SetFormula(Formula* formula)
{
  assert(!m_empty);
  m_formula = *formula;
}

void Reaction::SetNewTopName(string newtopname)
{
  m_left.SetNewTopName(newtopname);
  m_right.SetNewTopName(newtopname);
  m_name.insert(m_name.begin(), newtopname);
  m_formula.SetNewTopName(newtopname);
}

void Reaction::Clear()
{
  m_empty = true;
  ReactantList blanklist;
  m_left = blanklist;
  m_right = blanklist;
  m_name.clear();
  m_formula.Clear();
}

const Formula* Reaction::GetFormula() const
{
  return &(m_formula);
}

Formula* Reaction::GetFormula()
{
  return &(m_formula);
}

bool Reaction::IsEmpty() const
{
  return m_empty;
}

bool Reaction::LeftIsEmpty() const
{
  if (m_empty) return true;
  return (m_left.Size() == 0);
}

string Reaction::ToStringDelimitedBy(char cc) const
{
  string retval;
  Variable* actualvar = g_registry.CurrentModule()->GetVariable(m_name);
  if (actualvar != NULL) {
    retval += actualvar->GetNameDelimitedBy(cc);
  }
  else {
    for (size_t i=0; i<m_name.size(); i++) {
      if (i>0) retval += ".";
      retval += m_name[i];
    }
  }
  retval += ": " + m_left.ToStringDelimitedBy(cc) + " " + RDToString(m_divider) + " " + m_right.ToStringDelimitedBy(cc) + "; " + m_formula.ToStringDelimitedBy(cc) + ";";
  return retval;
}

vector<string> Reaction::LeftToStringVecDelimitedBy(char cc) const
{
  return m_left.ToStringVecDelimitedBy(cc);
}

vector<string> Reaction::RightToStringVecDelimitedBy(char cc) const
{
  return m_right.ToStringVecDelimitedBy(cc);
}

vector<double> Reaction::GetLeftStoichiometries() const
{
  return m_left.GetStoichiometries();
}

vector<double> Reaction::GetRightStoichiometries() const
{
  return m_right.GetStoichiometries();
}

bool Reaction::GetIsConst() const
{
  return m_formula.GetIsConst();
}

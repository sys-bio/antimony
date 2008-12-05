#include <assert.h>

#include "reaction.h"
#include "registry.h"
#include "rd_type.h"
#include "module.h"
#include "variable.h"

using namespace std;

AntimonyReaction::AntimonyReaction(ReactantList left, rd_type divider, ReactantList right, Formula formula, Variable* var)
  : m_empty(false),
    m_left(left),
    m_right(right),
    m_divider(divider),
    m_name(var->GetName()),
    m_module(var->GetNamespace()),
    m_formula(formula)
{
  //The reactantlists have pointers to variables in them, so they need to be
  // set properly before using this constructor.
}


AntimonyReaction::AntimonyReaction()
  : m_empty(true),
    m_left(),
    m_right(),
    m_divider(rdBecomes),
    m_name(),
    m_formula()
{
}

void AntimonyReaction::SetFormula(Formula* formula)
{
  m_formula = *formula;
}

void AntimonyReaction::SetNewTopName(string modname, string newtopname)
{
  //Ourself:
  m_name.insert(m_name.begin(), newtopname);
  m_module = modname;
  //Our dependents
  m_left.SetNewTopName(modname, newtopname);
  m_right.SetNewTopName(modname, newtopname);
  m_formula.SetNewTopName(modname, newtopname);
}

void AntimonyReaction::SetComponentCompartments(Variable* var)
{
  m_left.SetComponentCompartments(var);
  m_right.SetComponentCompartments(var);
}

bool AntimonyReaction::SetFormulaOfInteracteesAndClear()
{
  if (m_formula.IsEmpty()) return false;
  if (m_right.SetComponentFormulasTo(m_formula)) return true;
  m_formula.Clear();
  return false;
}

void AntimonyReaction::Clear()
{
  m_empty = true;
  ReactantList blanklist;
  m_left = blanklist;
  m_right = blanklist;
  m_name.clear();
  m_formula.Clear();
}

const Formula* AntimonyReaction::GetFormula() const
{
  return &(m_formula);
}

Formula* AntimonyReaction::GetFormula()
{
  return &(m_formula);
}

bool AntimonyReaction::IsEmpty() const
{
  return m_empty;
}

bool AntimonyReaction::LeftIsEmpty() const
{
  if (m_empty) return true;
  return (m_left.Size() == 0);
}

string AntimonyReaction::ToDelimitedStringWithStrands(char cc, vector<pair<Variable*, size_t> > strands) const
{
  if (IsEmpty()) return "";
  string retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* actualvar = module->GetVariable(m_name);
  if (actualvar != NULL) {
    retval += actualvar->GetNameDelimitedBy(cc);
  }
  else {
    assert(false); //Should be clean...
    for (size_t i=0; i<m_name.size(); i++) {
      if (i>0) retval += cc;
      retval += m_name[i];
    }
  }
  retval += ": " + m_left.ToStringDelimitedBy(cc) + " " + RDToString(m_divider) + " " + m_right.ToStringDelimitedBy(cc) + "; " + m_formula.ToDelimitedStringWithStrands(cc, strands) + ";";
  return retval;
}

string AntimonyReaction::ToDelimitedStringWithEllipses(char cc) const
{
  if (IsEmpty()) return "";
  string retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* actualvar = module->GetVariable(m_name);
  if (actualvar != NULL) {
    retval += actualvar->GetNameDelimitedBy(cc);
  }
  else {
    assert(false); //Should be clean...
    for (size_t i=0; i<m_name.size(); i++) {
      if (i>0) retval += cc;
      retval += m_name[i];
    }
  }
  retval += ": " + m_left.ToStringDelimitedBy(cc) + " " + RDToString(m_divider) + " " + m_right.ToStringDelimitedBy(cc) + "; " + m_formula.ToDelimitedStringWithEllipses(cc) + ";";
  return retval;
}

vector<string> AntimonyReaction::LeftToStringVecDelimitedBy(char cc) const
{
  return m_left.ToStringVecDelimitedBy(cc);
}

vector<string> AntimonyReaction::RightToStringVecDelimitedBy(char cc) const
{
  return m_right.ToStringVecDelimitedBy(cc);
}

vector<double> AntimonyReaction::GetLeftStoichiometries() const
{
  return m_left.GetStoichiometries();
}

vector<double> AntimonyReaction::GetRightStoichiometries() const
{
  return m_right.GetStoichiometries();
}

double AntimonyReaction::GetStoichiometryFor(const Variable* var) const
{
  double stoich = 0;
  stoich -= m_left.GetStoichiometryFor(var);
  stoich += m_right.GetStoichiometryFor(var);
  return stoich;
}


bool AntimonyReaction::GetIsConst() const
{
  return m_formula.GetIsConst();
}

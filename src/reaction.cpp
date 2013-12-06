#include <assert.h>

#include "reaction.h"
#include "registry.h"
#include "enums.h"
#include "sbmlx.h"
#include "stringx.h"
#include "typex.h"
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

void AntimonyReaction::SetComponentCompartments(Variable* var, bool frommodule)
{
  var_type supercomp = varReactionUndef;
  if (frommodule) supercomp = varModule;
  m_left.SetComponentCompartments(var, supercomp);
  m_right.SetComponentCompartments(var, supercomp);
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

void AntimonyReaction::ClearReferencesTo(Variable* deletedvar, set<pair<vector<string>, deletion_type> >* ret)
{
  vector<string> delname = deletedvar->GetName();
  bool isinrxn = false;
  if (m_empty) return;
  vector<string> longername = m_name;
  if (m_divider == rdBecomes || m_divider == rdBecomesIrreversibly) {
    longername.push_back(delname[delname.size()-1]);
    if (m_left.ClearReferencesTo(deletedvar)) {
      ret->insert(make_pair(longername,  delReactant));
      isinrxn = true;
    }
    if (m_right.ClearReferencesTo(deletedvar)) {
      ret->insert(make_pair(longername, delProduct));
      isinrxn = true;
    }
    if (m_formula.ClearReferencesTo(deletedvar)) {
      ret->insert(make_pair(m_name, delKineticLaw));
      //Also remove any modifier species references:
      if (!isinrxn && IsSpecies(deletedvar->GetType())) {
        ret->insert(make_pair(longername, delModifier));
      }
    }
  }
  else {
    //This is an interaction, not a reaction
    if (m_left.ClearReferencesTo(deletedvar)) {
      longername = m_right.GetNthReactant(0)->GetName();
      longername.push_back(delname[delname.size()-1]);
      ret->insert(make_pair(longername, delModifier));
    }
    m_right.ClearReferencesTo(deletedvar);
    if (m_left.GetVariableList().size()==0 ||
      m_right.GetVariableList().size()==0) {
      //The interaction itself has to be removed for Antimony purposes.
      ret->insert(make_pair(m_name, delInteraction));
    }
    //We don't have to worry about the right-hand side, since that's the reaction itself--if it is the deleted var, we're good.  Also, we don't have to worry about the 'kinetic law', since that just gets set as the KL of the reaction itself, too.
  }
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
  if (m_empty) return true;
  if (m_left.Size() == 0 && m_right.Size() == 0) return true;
  return false;
}

bool AntimonyReaction::LeftIsEmpty() const
{
  if (m_empty) return true;
  return (m_left.Size() == 0);
}

string AntimonyReaction::ToDelimitedStringWithStrands(std::string cc, vector<pair<Variable*, size_t> > strands) const
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

string AntimonyReaction::ToDelimitedStringWithEllipses(std::string cc) const
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
  if (actualvar->GetCompartment() != NULL) {
    retval += " in " + actualvar->GetCompartment()->GetNameDelimitedBy(cc);
  }
  retval += ": " + m_left.ToStringDelimitedBy(cc) + " " + RDToString(m_divider) + " " + m_right.ToStringDelimitedBy(cc) + "; " + m_formula.ToDelimitedStringWithEllipses(cc) + ";";
  return retval;
}

double AntimonyReaction::GetStoichiometryFor(const Variable* var) const
{
  double stoich = 0;
  stoich -= m_left.GetStoichiometryFor(var);
  stoich += m_right.GetStoichiometryFor(var);
  return stoich;
}

void AntimonyReaction::FixNames()
{
  FixName(m_name);
  FixName(m_module);
  m_left.FixNames();
  m_right.FixNames();
  m_formula.FixNames(m_module);
}

bool AntimonyReaction::Matches(const AntimonyReaction* newreaction) const
{
  if (GetType() != newreaction->GetType()) return false;
  if (!m_left.Matches(newreaction->GetLeft())) return false;
  if (!m_right.Matches(newreaction->GetRight())) return false;
  return m_formula.Matches(newreaction->GetFormula());
}


#ifndef REACTION_H
#define REACTION_H

#include <string>
#include <utility>
#include <vector>
#include <set>

#include "enums.h"
#include "reactantlist.h"
#include "formula.h"
#include "enums.h"

//Note:  'AntimonyReaction' instead of just 'Reaction' because libSBML defines a 'Reaction' class.
class AntimonyReaction
{
private:
  //AntimonyReaction(const AntimonyReaction& src); //Undefined
  //AntimonyReaction& operator=(const AntimonyReaction& src); //Undefined

  bool m_empty;
  ReactantList m_left;
  ReactantList m_right;
  rd_type m_divider;
  std::vector<std::string> m_name;
  std::string m_module;
  Formula m_formula;

public:
  AntimonyReaction(const ReactantList& left, rd_type divider, const ReactantList& right, Formula formula, Variable* var);
  AntimonyReaction(); //Make a blank one, but don't use it.
  ~AntimonyReaction() {};

  void SetFormula(Formula* formula);
  void SetNewTopName(std::string modname, std::string newtopname);
  void SetComponentCompartments(Variable* var, bool frommodule);
  bool SetFormulaOfInteracteesAndClear();
  void Clear();
  void ClearReferencesTo(Variable* deletedvar, std::set<std::pair<std::vector<std::string>, deletion_type> >* ret);

  const Formula* GetFormula() const;
  const ReactantList* GetLeft()  const {return &m_left;};
  const ReactantList* GetRight() const {return &m_right;};
        ReactantList* GetLeft()        {return &m_left;};
        ReactantList* GetRight()       {return &m_right;};
  Formula* GetFormula();
  rd_type GetType() const {return m_divider;};
  bool IsEmpty() const;
  bool LeftIsEmpty() const;

  bool Matches(const AntimonyReaction* newrxn) const;
  bool HasReactantFor(const Variable* species) const;
  std::string ToDelimitedStringWithStrands(std::string cc, std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string ToDelimitedStringWithEllipses(std::string cc) const;
  double GetStoichiometryFor(const Variable* var) const;
  void FixNames();
};


#endif //REACTION_H

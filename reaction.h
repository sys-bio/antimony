#ifndef REACTION_H
#define REACTION_H

#include <string>
#include <utility>
#include <vector>

#include "rd_type.h"
#include "reactantlist.h"
#include "formula.h"

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
  AntimonyReaction(ReactantList left, rd_type divider, ReactantList right, Formula formula, Variable* var);
  AntimonyReaction(); //Make a blank one, but don't use it.
  ~AntimonyReaction() {};

  void SetFormula(Formula* formula);
  void SetNewTopName(std::string modname, std::string newtopname);
  void SetComponentCompartments(Variable* var);
  bool SetFormulaOfInteracteesAndClear();
  void Clear();

  const Formula* GetFormula() const;
  const ReactantList* GetLeft()  const {return &m_left;};
  const ReactantList* GetRight() const {return &m_right;};
        ReactantList* GetLeft()        {return &m_left;};
        ReactantList* GetRight()       {return &m_right;};
  Formula* GetFormula();
  rd_type GetType() const {return m_divider;};
  bool IsEmpty() const;
  bool LeftIsEmpty() const;

  std::string ToDelimitedStringWithStrands(char cc, std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string ToDelimitedStringWithEllipses(char cc) const;
  double GetStoichiometryFor(const Variable* var) const;
  bool GetIsConst() const;
};


#endif //REACTION_H

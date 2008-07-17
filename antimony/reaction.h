#ifndef REACTION_H
#define REACTION_H

#include <string>
#include <utility>
#include <vector>

#include "rd_type.h"
#include "reactantlist.h"
#include "formula.h"

class Reaction
{
private:
  //Reaction(const Reaction& src); //Undefined
  //Reaction& operator=(const Reaction& src); //Undefined

  bool m_empty;
  ReactantList m_left;
  ReactantList m_right;
  rd_type m_divider;
  std::vector<std::string> m_name;
  std::string m_module;
  Formula m_formula;

public:
  Reaction(ReactantList left, rd_type divider, ReactantList right, Formula formula, Variable* var);
  Reaction(); //Make a blank one, but don't use it.
  ~Reaction() {};

  void SetFormula(Formula* formula);
  void SetNewTopName(std::string modname, std::string newtopname);
  void Clear();

  const Formula* GetFormula() const;
  Formula* GetFormula();
  rd_type GetType() const {return m_divider;};
  bool IsEmpty() const;
  bool LeftIsEmpty() const;

  std::string ToStringDelimitedBy(char cc) const;
  std::vector<std::string> LeftToStringVecDelimitedBy(char cc) const;
  std::vector<std::string> RightToStringVecDelimitedBy(char cc) const;
  std::vector<double> GetLeftStoichiometries() const;
  std::vector<double> GetRightStoichiometries() const;
  double GetStoichiometryFor(const Variable* var) const;
  bool GetIsConst() const;
};


#endif //REACTION_H

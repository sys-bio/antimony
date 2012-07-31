#ifndef REACTANTLIST_H
#define REACTANTLIST_H

#include <string>
#include <utility>
#include <vector>
#include "enums.h"

class Variable;
class Formula;

class ReactantList
{
private:
  //ReactantList(const ReactantList& src); //Undefined
  //ReactantList& operator=(const ReactantList& src); //Undefined

  std::vector<std::pair<double, std::vector<std::string> > > m_components;
  std::string m_module;

public:
  ReactantList() {};
  ~ReactantList() {};

  void AddReactant(Variable* var, double stoichiometry=1);
  void SetNewTopName(std::string newmodname, std::string newtopname);
  void SetComponentCompartments(Variable* var, var_type supertype);
  bool SetComponentTypesTo(var_type vtype);
  bool SetComponentFormulasTo(Formula form);

  std::vector<std::vector<std::string> > GetVariableList() const;
  size_t Size() const {return m_components.size();};

  bool Matches(const ReactantList* newrl) const;
  std::string ToStringDelimitedBy(char cc) const;
  std::vector<std::string> ToStringVecDelimitedBy(char cc) const;
  std::vector<double> GetStoichiometries() const;
  double GetStoichiometryFor(const Variable* var) const;
  double GetStoichiometryFor(size_t n) const;
  const Variable* GetNthReactant(size_t n) const;
  void FixNames();
};


#endif //REACTANTLIST_H

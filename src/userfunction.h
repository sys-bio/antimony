#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

class UserFunction : public Module
{
private:
  Formula m_formula;

public:
  UserFunction(std::string name);
  ~UserFunction() {};

  bool SetFormula(const Formula& formula);
  Formula GetFormula() const {return m_formula;};
  std::string ToSBMLString() const;
  std::string GetAntimony() const;
  void FixNames();
  bool ChangeTimeToRef();
  //bool GetFormulaUsing(std::vector<std::vector<std::string> > newvars, Formula& setform) const;

};


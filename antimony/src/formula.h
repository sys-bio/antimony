#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <utility>
#include <vector>

#ifndef NSBML
#include <sbml/math/ASTNode.h>
#endif

class ReactantList;
class Variable;

class Formula
{
private:
  //Formula(const Formula& src); //Undefined
  //Formula& operator=(const Formula& src); //Undefined

  std::vector<std::pair<std::string, std::vector<std::string> > > m_components;
  std::vector<std::pair<std::string, std::vector<std::string> > > m_conversionFactors;
  std::vector<std::pair<std::string, std::vector<std::string> > > m_timeConversionFactors;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > m_convertedVariables;
  std::string m_module;

public:
  Formula() {};
  ~Formula() {};

  void AddVariable(const Variable* var);
  void AddNum(double num);
  void AddMathThing(char maththing);
  void AddText(const std::string* function);
  void AddFormula(const Formula* form2);
  void AddEllipses();
  void AddParentheses();
  void AddConversionFactor(const Variable* cf);
  void AddInvTimeConversionFactor(const Variable* tcf);

  void SetNewTopName(std::string newmodname, std::string newtopname);

  bool IsEmpty() const;
  bool IsDouble() const;
  bool IsBoolean() const;
  bool GetBoolean() const;
  bool IsAmountIn(const Variable* compartment) const;
  bool IsOne() const;
  bool IsEllipsesOnly() const;
  bool IsSingleVariable() const;
  bool GetIsConst() const;
  bool CheckIncludes(std::string modname, const ReactantList* rlist) const;
  bool ContainsVar(std::string modname, std::vector<std::string> vname) const;
  bool ContainsVar(const Variable* outervar) const;
  bool ContainsFunction(const std::string& function) const;

  void Clear();

  std::string ToDelimitedStringWithStrands(char cc, std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string ToDelimitedStringWithEllipses(char cc) const;
  std::string ToSBMLString() const;
  std::string ToSBMLString(std::vector<std::pair<Variable*, size_t> > strands) const;
  double      ToAmount() const;
  std::string ConvertOneSymbolToFunction(std::string formula) const;
  std::vector<const Variable*> GetVariablesFrom(std::string formula, std::string module) const;
  std::vector<std::vector<std::string> > GetVariables() const;

  void FixNames(std::string modname);
  void ChangeTimeTo(const Variable* timeref);
  void InsertTimeInFunction(std::string function);
  void ReplaceWith(const Variable* origvar, const Variable* newvar);

  bool Matches(const Formula* newform) const;
  void Convert(Variable* converted, Variable* cf);
  void ConvertTime(Variable* tcf);

  bool MakeAllVariablesUnits();
  bool MakeUnitVariablesUnits();
#ifndef NSBML
  bool MakeUnitVariablesUnits(ASTNode* astn);
  void SetNewTopNameWith(const SBase* from, const std::string& modname);
#endif

  bool ClearReferencesTo(Variable* deletedvar);

  //For CellMLStuff:
  void UseInstead(std::string newname, const Variable* oldvar);
  std::string ToCellML() const;
  std::string ToCellMLString(std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string CellMLify(std::string formula) const;
};


#endif //FORMULA_H

#ifndef FORMULA_H
#define FORMULA_H

#include <string>
#include <utility>
#include <vector>
#include <set>
#include "annotated.h"

#ifndef NSBML
#include <sbml/math/ASTNode.h>
class Model;
#endif

class ReactantList;
class Variable;

class Formula : public Annotated
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

  bool AddVariable(const Variable* var);
  void AddNum(double num);
  void AddMathThing(char maththing);
  void AddInequality(constraint_type ineq);
  void AddText(const std::string* function);
  void AddFormula(const Formula* form2);
  void AddEllipses();
  void AddParentheses();
  void AddCurlyBrackets();
  void AddConversionFactor(const Variable* cf);
  void AddInvTimeConversionFactor(const Variable* tcf);

  void SetNewTopName(std::string newmodname, std::string newtopname);

  bool IsEmpty() const;
  bool IsDouble() const;
  double GetDouble() const;
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
  bool ContainsDeletedVar() const;
  bool ContainsFunction(const std::string& function) const;
  bool ContainsName(const std::string& name) const;
  bool ContainsCurlyBrackets() const;

  void Clear();

  std::string ToDelimitedStringWithStrands(std::string cc, std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string ToDelimitedStringWithEllipses(std::string cc) const;
  std::string ToSBMLString() const;
  std::string ToSBMLString(std::vector<std::pair<Variable*, size_t> > strands) const;
  double      ToAmount() const;
  std::string ConvertOneSymbolToFunction(std::string formula) const;
  std::vector<const Variable*> GetVariablesFrom(std::string formula, std::string module) const;
  std::vector<std::vector<std::string> > GetVariables() const;

  void FixNames(std::string modname);
  void ChangeTimeTo(const Variable* timeref);
  void InsertTimeInFunction(std::string function);
  void ReplaceWith(std::vector<std::string> origname, std::vector<std::string> newname);

  bool Matches(const Formula* newform) const;
  void Convert(Variable* converted, Variable* cf);
  void ConvertTime(Variable* tcf);
  void UnConvertTimeExtent(Variable* tcf, Variable* xcf);

  bool MakeAllVariablesUnits();
  bool MakeUnitVariablesUnits();
#ifndef NSBML
  bool MakeUnitVariablesUnits(ASTNode* astn);
  void SetNewTopNameWith(const SBase* from, const std::string& modname);
  void AddFluxObjective(Model* sbmlmod, bool maximize, const Variable* var) const;
  bool IsValidObjectiveFunction() const;
  bool IsValidObjectiveFunction(const ASTNode* astn) const;
  void GetObjectivesFromAST(const ASTNode* astn, std::vector<std::pair<std::string, double> >& objectives) const;
#endif

  bool ClearReferencesTo(Variable* deletedvar);
  void AddReferencedVariablesTo(std::set<std::pair<std::string, const Variable*> >& referencedVars) const;

  //For CellMLStuff:
  void UseInstead(std::string newname, const Variable* oldvar);
  std::string ToCellML() const;
  std::string ToCellMLString(std::vector<std::pair<Variable*, size_t> > strands) const;
  std::string CellMLify(std::string formula) const;
};


#endif //FORMULA_H

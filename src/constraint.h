#ifndef ANTIMONYCONSTRAINT_H
#define ANTIMONYCONSTRAINT_H

#include <string>
#include <utility>
#include <vector>
#include "enums.h"
#include "formula.h"

class Variable;

class AntimonyConstraint
{
private:
  Formula m_formula;
  bool m_isSetInitialValue;
  double m_initialValue;
  std::vector<std::string> m_initialVariable;
  constraint_type m_type;
  std::vector<std::string> m_name;
  std::string m_module;
#ifndef NSBML
  libsbml::ASTNode* m_astnode;
#endif
#ifdef LIBSBML_HAS_PACKAGE_FBC
  std::string m_rxnId;
  Formula m_fbUpper;
  Formula m_fbLower;
#endif

public:
  AntimonyConstraint(); //Undefined
  AntimonyConstraint(const AntimonyConstraint& constraint);
  AntimonyConstraint(Variable* var);
  ~AntimonyConstraint();

  void SetFormula(Formula* formula, bool onlyformula);
  void SetInitialValue(double val);
  void SetInitialVariable(Variable* var);
  void SetType(constraint_type type);
  void SetName(std::vector<std::string> name);
  void SetModulename(std::string modulename);
  void Clear();

  bool IsEmpty() const;
  bool IsSetInitialValue() const;
  bool IsSetInitialVariable() const;
  const Formula* GetFormula() const;
  Formula* GetFormula();
  double GetInitialValue() const;
  Variable* GetInitialVariable() const;
  constraint_type GetConstraintType() const;

  void SetNewTopName(std::string newmodname, std::string newtopname);
  std::string ToStringDelimitedBy(std::string cc) const;
  bool Matches(const AntimonyConstraint* newconstraint) const;

  void FixNames();

#ifndef NSBML
  void SetWithASTNode(const libsbml::ASTNode* astnode);
  void calculateASTNode();
  const libsbml::ASTNode* getASTNode() const;
#ifdef LIBSBML_HAS_PACKAGE_FBC
  bool calculateFluxBounds();
  bool isFluxBound() const;
  void addFluxBounds(libsbml::Model* model) const;
  bool IsReactionID(const std::string& rxnid) const;
  void SetLowerFBFormula(Variable* var);
  void SetUpperFBFormula(Variable* var);
  void setReactionId(const std::string& rxnid);
#endif
#endif
};


#endif //ANTIMONYCONSTRAINT_H

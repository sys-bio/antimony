#ifndef UNCERTWRAPPER_H
#define UNCERTWRAPPER_H

#include "variable.h"

class Variable;
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
class Uncertainty;
#endif
// A proxy class returned by the parser for setting SBO terms
class UncertWrapper : public Variable
{
protected:
  Variable* m_parent;
  uncert_type m_uncert_type;
public:
  UncertWrapper(Variable* parent, uncert_type type);
  ~UncertWrapper();

  bool IsPointer() const;
  virtual Variable* GetSameVariable();
  virtual const Variable* GetSameVariable() const;
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  //virtual bool SetUncertType(uncert_type newtype);
  virtual uncert_type GetUncertType();
  Variable* GetParent();
  virtual std::string GetNameDelimitedBy(std::string cc) const;
  virtual bool Synchronize(Variable* clone, const Variable* conversionFactor);
  virtual std::string CreateUncertParamsAntimonySyntax(const std::string& indent) const;
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  virtual Uncertainty * GetOrCreateUncertainty(SBase * sbmlobj) const;
#endif
  virtual bool TransferAnnotationTo(SBase* sbmlobj, std::string metaid) const;
  void ReadAnnotationFrom(const SBase* sbmlobj);
};


#endif //UNCERTWRAPPER_H

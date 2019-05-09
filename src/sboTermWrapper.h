#ifndef SBOTERMWRAPPER_H
#define SBOTERMWRAPPER_H

#include "variable.h"

class Variable;
// A proxy class returned by the parser for setting SBO terms
class SboTermWrapper : public Variable
{
protected:
  Variable* m_parent;
public:
  SboTermWrapper(Variable* parent);
  ~SboTermWrapper();

  bool IsPointer() const;
  virtual Variable* GetSameVariable();
  virtual const Variable* GetSameVariable() const;
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  Variable* GetParent();
  virtual std::string GetNameDelimitedBy(std::string cc) const;
  virtual bool Synchronize(Variable* clone, const Variable* conversionFactor);
};


#endif //SBOTERMWRAPPER_H

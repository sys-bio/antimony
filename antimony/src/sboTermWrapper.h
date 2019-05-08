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

  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  Variable* GetParent();
};


#endif //SBOTERMWRAPPER_H

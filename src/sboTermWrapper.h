#ifndef SBOTERMWRAPPER_H
#define SBOTERMWRAPPER_H

#include "variable.h"

class Annotated;
// A proxy class returned by the parser for setting SBO terms
class SboTermWrapper : public Variable
{
protected:
  Annotated* m_parent;
public:
  SboTermWrapper(Annotated* parent);
  ~SboTermWrapper();

  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  Annotated* GetParent();
};


#endif //SBOTERMWRAPPER_H

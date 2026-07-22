#ifndef KINETICLAWWRAPPER_H
#define KINETICLAWWRAPPER_H

#include "variable.h"

class Variable;
// A proxy class returned by the parser for annotating a reaction's kinetic
// law (sboTerm, CV terms, notes, etc.) separately from the reaction itself.
class KineticLawWrapper : public Variable
{
protected:
  Variable* m_parent;
public:
  KineticLawWrapper(Variable* parent);
  ~KineticLawWrapper();

  bool IsPointer() const;
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  Variable* GetParent();
  virtual std::string GetNameDelimitedBy(std::string cc) const;
  virtual bool Synchronize(Variable* clone, const Variable* conversionFactor);
};


#endif //KINETICLAWWRAPPER_H

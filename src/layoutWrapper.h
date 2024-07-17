#ifndef LAYOUTWRAPPER_H
#define LAYOUTWRAPPER_H

#include "variable.h"
#include <sbml/packages/layout/sbml/Layout.h>

class Variable;
// A proxy class returned by the parser for setting layout terms
class LayoutWrapper : public Variable
{
protected:
  Variable* m_parent;
  layout_type m_layout_type;
public:
  LayoutWrapper(Variable* parent, layout_type type);
  LayoutWrapper(layout_type type, const std::string& group);
  ~LayoutWrapper();

  bool IsPointer() const;
  virtual Variable* GetSameVariable();
  virtual const Variable* GetSameVariable() const;
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  //virtual bool SetlayoutType(layout_type newtype);
  virtual layout_type GetLayoutType();
  Variable* GetParent();
  virtual std::string GetNameDelimitedBy(std::string cc) const;
  virtual bool Synchronize(Variable* clone, const Variable* conversionFactor);
  virtual std::string CreatelayoutParamsAntimonySyntax(const std::string& indent) const;
  virtual bool TransferLayoutInformationTo(libsbml::SBMLDocument* sbml) const;
  bool TransferLayoutInformationTo(libsbml::SBMLDocument* sbml, const std::string& group) const;
  virtual bool HasLayoutPositionInfo() const;
};


#endif //LAYOUTWRAPPER_H

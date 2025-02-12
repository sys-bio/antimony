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
  std::string m_speciesId;
  int m_speciesIndex;
  int m_segmentIndex;
  arc_type m_arctype;
public:
  LayoutWrapper(Variable* parent, layout_type type, std::string name, const Module* module);
  LayoutWrapper(Variable* parent, layout_type type);
  LayoutWrapper(layout_type type, const std::string& group);
  ~LayoutWrapper();

  bool IsPointer() const;
  //virtual Variable* GetSameVariable();
  //virtual const Variable* GetSameVariable() const;
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  virtual bool SetType(var_type newtype);
  //virtual bool SetlayoutType(layout_type newtype);
  virtual layout_type GetLayoutType();
  Variable* GetParent();
  virtual std::string GetNameDelimitedBy(std::string cc) const;
  virtual bool Synchronize(Variable* clone, const Variable* conversionFactor);
  virtual std::string CreateLayoutParamsAntimonySyntax(const std::string& indent) const;
  virtual bool TransferLayoutInformationTo(libsbml::SBMLDocument* sbml);
  virtual bool TransferLayoutInformationTo(libsbml::SBMLDocument* sbml, const std::string& group);
  virtual bool HasLayoutPositionInfo() const;
  virtual bool setSpeciesId(const std::string* name);
  virtual void setSpeciesIndex(int index);
  virtual void setSegmentIndex(int index);
  virtual bool setArcType(const std::string* type);
  virtual bool setArcNumber(const std::string* type);
  virtual bool setSegmentNumber(const std::string* type);
  virtual bool setArcType(arc_type type);
  virtual Variable* GetSubVariable(const std::string* name);
};


#endif //LAYOUTWRAPPER_H

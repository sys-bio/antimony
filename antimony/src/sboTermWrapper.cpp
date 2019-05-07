#include "sboTermWrapper.h"
#include "module.h"
#include "registry.h"

using namespace std;

SboTermWrapper::SboTermWrapper(Annotated* parent)
  : Variable()
  , m_parent(parent)
{
  m_sboTermWrapper = NULL;
  m_type = varSboTermWrapper;
}

SboTermWrapper::~SboTermWrapper() 
{
}

bool SboTermWrapper::SetFormula(Formula* formula, bool isObjective)
{
  if (!formula->IsDouble()) {
    g_registry.SetError("Expected sboTerm to be set to a number or SBO:NUMBER");
    return true;
  }
  double val = formula->GetDouble();
  if (val < 0 || val > 9999999) {
    stringstream istr;
    istr << val;
    g_registry.SetError("SBO value out of range: " + istr.str());
    return true;
  }

  m_parent->SetSBOTerm(val);
  return false;
}

bool SboTermWrapper::SetType(var_type newtype)
{
  Variable* varparent = dynamic_cast<Variable*> (m_parent);
  if (varparent) {
    return varparent->SetType(newtype);
  }
  return true;
}

Annotated* SboTermWrapper::GetParent() 
{ 
  return m_parent; 
}

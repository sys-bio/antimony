#include "sboTermWrapper.h"
#include "module.h"
#include "registry.h"

using namespace std;

SboTermWrapper::SboTermWrapper(Variable* parent)
  : Variable()
  , m_parent(parent)
{
  m_sboTermWrapper = NULL;
  m_type = varSboTermWrapper;
}

SboTermWrapper::~SboTermWrapper() 
{
}

bool SboTermWrapper::IsPointer() const
{
  return true;
}

Variable * SboTermWrapper::GetSameVariable()
{
  return m_parent;
}

const Variable * SboTermWrapper::GetSameVariable() const
{
  return m_parent;
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
  return m_parent->SetType(newtype);
}

Variable* SboTermWrapper::GetParent() 
{ 
  return m_parent; 
}

string SboTermWrapper::GetNameDelimitedBy(string cc) const
{
  string base = m_parent->GetNameDelimitedBy(cc);
  return base + cc + "sboTerm";
}

bool SboTermWrapper::Synchronize(Variable* clone, const Variable* conversionFactor)
{
  g_registry.SetError("Unable to synchronize two symbols when one of them ('" + GetNameDelimitedBy(".") + "') is an SBO term.");
  return true;
}

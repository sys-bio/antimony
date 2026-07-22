#include "kineticLawWrapper.h"
#include "module.h"
#include "registry.h"

using namespace std;

KineticLawWrapper::KineticLawWrapper(Variable* parent)
  : Variable()
  , m_parent(parent)
{
  m_module = parent->GetNamespace();
  m_displayname = "";
  m_formulatype = formulaINITIAL;
  m_supercomptype = varUndefined;
  m_deletedunit = false;
  m_replacedformrxn = false;
  m_const = constDEFAULT;
  m_substOnly = false;
  m_sboTermWrapper = NULL;
  m_type = varKineticLawWrapper;
  SetNamespace(parent->GetNamespace());
}

KineticLawWrapper::~KineticLawWrapper()
{
}

bool KineticLawWrapper::IsPointer() const
{
  return false;
}

bool KineticLawWrapper::SetFormula(Formula* formula, bool isObjective)
{
  return m_parent->SetFormula(formula, isObjective);
}

bool KineticLawWrapper::SetType(var_type newtype)
{
  if (newtype == m_type) {
    return false;
  }
  g_registry.SetError("Unable to use the symbol '" + GetNameDelimitedBy(".") + "' in any context other than setting properties of a kinetic law.");
  return true;
}

Variable* KineticLawWrapper::GetParent()
{
  return m_parent;
}

string KineticLawWrapper::GetNameDelimitedBy(string cc) const
{
  return m_parent->GetNameDelimitedBy(cc) + cc + "kineticLaw";
}

bool KineticLawWrapper::Synchronize(Variable* clone, const Variable* conversionFactor)
{
  g_registry.SetError("Unable to synchronize two symbols when one of them ('" + GetNameDelimitedBy(".") + "') is a kinetic law.");
  return true;
}

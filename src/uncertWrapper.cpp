#include "uncertWrapper.h"
#include "module.h"
#include "registry.h"
#include "stringx.h"
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include <sbml/packages/distrib/sbml/Uncertainty.h>
#include <sbml/packages/distrib/extension/DistribSBasePlugin.h>
#endif

using namespace std;

UncertWrapper::UncertWrapper(Variable* parent, uncert_type type)
  : Variable()
  , m_parent(parent)
  , m_uncert_type(type)
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
  m_type = varUncertWrapper;
  SetNamespace(parent->GetNamespace());
}

UncertWrapper::~UncertWrapper() 
{
}

bool UncertWrapper::IsPointer() const
{
  return false;
}

Variable * UncertWrapper::GetSameVariable()
{
  return m_parent;
}

const Variable * UncertWrapper::GetSameVariable() const
{
  return m_parent;
}

bool UncertWrapper::SetFormula(Formula* formula, bool isObjective)
{
  if (Variable::SetFormula(formula, isObjective)) {
    return true;
  }

  if (m_uncert_type == unExternalParameter || m_uncert_type == unDistribution) {
    //Anything is allowed for these types
    return false;
  }
  if (IsSpan(m_uncert_type)) {
    //Only Vectors of length 2 are allowed for these types
    //We're only going to be able to check this in SBML mode
#ifndef NSBML
    ASTNode* astn = parseStringToASTNode(formula->ToSBMLString());
    if (astn->getType() != AST_LINEAR_ALGEBRA_VECTOR || astn->getNumChildren() != 2) {
      g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  an uncertainty parameter of type " + UncertTypeToString(m_uncert_type) + " must be a vector of length two, marked with curly brackets (i.e. '{3, 8}').");
      delete astn;
      return true;
    }
    for (unsigned int c = 0; c < 2; c++) {
      ASTNodeType_t ctype = astn->getChild(c)->getType();
      if (ctype != AST_NAME && !astn->getChild(c)->isNumber()) {
        g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  an uncertainty parameter of type " + UncertTypeToString(m_uncert_type) + " must be a vector of length two, and each element of the vector may only be a value or a single variable (i.e. '{x, 5.4}' or '{p, q}').");
        delete astn;
        return true;
      }
    }
    if (astn->getChild(0)->isSetUnits() && astn->getChild(1)->isSetUnits()) {
      if (astn->getChild(0)->getUnits() != astn->getChild(1)->getUnits()) {
        g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  the units of both elements in the vector must be the same.");
        delete astn;
        return true;
      }
    }
    delete astn;
#endif
    return false;
  }
  else {
    if (formula->IsDouble() || formula->IsSingleVariable()) {
      return false;
    }
    g_registry.SetError("Unable to set the value of '" + GetNameDelimitedBy(".") + "' to be '" + formula->ToDelimitedStringWithEllipses(".") + "':  this uncertainty parameter must only be a single value or a single variable.");
    return true;
  }
  return false;
}

bool UncertWrapper::SetType(var_type newtype)
{
  if (newtype == m_type) {
    return false;
  }
  g_registry.SetError("Unable to use the symbol '" + GetNameDelimitedBy(".") + "' in any context other than setting its value.");
  return true;
}

//bool UncertWrapper::SetUncertType(uncert_type newtype)
//{
//  m_uncert_type = newtype;
//}

uncert_type UncertWrapper::GetUncertType()
{
  return m_uncert_type;
}

Variable* UncertWrapper::GetParent()
{ 
  return m_parent; 
}

string UncertWrapper::GetNameDelimitedBy(string cc) const
{
  return m_parent->GetNameDelimitedBy(cc) + cc + UncertTypeToString(m_uncert_type);
}

bool UncertWrapper::Synchronize(Variable* clone, const Variable* conversionFactor)
{
  g_registry.SetError("Unable to synchronize two symbols when one of them ('" + GetNameDelimitedBy(".") + "') is an uncertainty term.");
  return true;
}

string UncertWrapper::CreateUncertParamsAntimonySyntax(const string & indent) const
{
  string ret = "";
  if (!m_valFormula.IsEmpty()) {
    ret = indent + GetNameDelimitedBy(".") + " = " + m_valFormula.ToDelimitedStringWithEllipses(".") + "\n";
  }
  if (!m_displayname.empty()) {
    ret += indent + GetNameDelimitedBy(".") + " is \"" + m_displayname + "\"\n";
  }
  return ret;
}

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
Uncertainty* UncertWrapper::GetOrCreateUncertainty(SBase* sbmlobj) const
{
  DistribSBasePlugin* dsbp = static_cast<DistribSBasePlugin*>(sbmlobj->getPlugin("distrib"));
  if (dsbp == NULL) {
    assert(false); //Should have enabled package already.
    return NULL;
  }
  if (dsbp->getNumUncertainties() == 0) {
    return dsbp->createUncertainty();
  }
  return dsbp->getUncertainty(0);
}
#endif


bool UncertWrapper::TransferAnnotationTo(SBase * sbmlobj, std::string metaid) const
{
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  Uncertainty* uncert = GetOrCreateUncertainty(sbmlobj);
  UncertType_t sbmltype = UncertTypeToSBML(m_uncert_type);
  if (sbmltype == DISTRIB_UNCERTTYPE_INVALID) {
    return true;
  }

  //Get the uncertainty parameter, ensuring there's only one of any one type.
#if LIBSBML_VERSION <= 51800
  UncertParameter* uparam = NULL;
  for (size_t up = 0; up < uncert->getNumUncertParameters(); up++) {
    if (uncert->getUncertParameter(up)->getType() == sbmltype) {
      uparam = uncert->getUncertParameter(up);
    }
  }
#else
  UncertParameter* uparam = uncert->getUncertParameterByType(sbmltype);
#endif
  UncertSpan* uspan = NULL;
  if (uparam == NULL) {
    switch (sbmltype) {
    case DISTRIB_UNCERTTYPE_DISTRIBUTION:
    case DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION:
    case DISTRIB_UNCERTTYPE_KURTOSIS:
    case DISTRIB_UNCERTTYPE_MEAN:
    case DISTRIB_UNCERTTYPE_MEDIAN:
    case DISTRIB_UNCERTTYPE_MODE:
    case DISTRIB_UNCERTTYPE_SAMPLESIZE:
    case DISTRIB_UNCERTTYPE_SKEWNESS:
    case DISTRIB_UNCERTTYPE_STANDARDDEVIATION:
    case DISTRIB_UNCERTTYPE_STANDARDERROR:
    case DISTRIB_UNCERTTYPE_VARIANCE:
      uparam = uncert->createUncertParameter();
      break;
    case DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL:
    case DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL:
    case DISTRIB_UNCERTTYPE_INTERQUARTILERANGE:
    case DISTRIB_UNCERTTYPE_RANGE:
    case DISTRIB_UNCERTTYPE_EXTERNALPARAMETER:
      uparam = uncert->createUncertSpan();
      uspan = static_cast<UncertSpan*>(uparam);
      break;
    case DISTRIB_UNCERTTYPE_INVALID:
      assert(false); //Should be caught above.
      return true;
    }
    uparam->setType(sbmltype);
  }

  //Set the definitionURL for external parameters or distributions.
  if (!m_displayname.empty()) {
    switch (sbmltype) {
    case DISTRIB_UNCERTTYPE_DISTRIBUTION:
    case DISTRIB_UNCERTTYPE_EXTERNALPARAMETER:
      uparam->setDefinitionURL(m_displayname);
      break;
    case DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION:
    case DISTRIB_UNCERTTYPE_KURTOSIS:
    case DISTRIB_UNCERTTYPE_MEAN:
    case DISTRIB_UNCERTTYPE_MEDIAN:
    case DISTRIB_UNCERTTYPE_MODE:
    case DISTRIB_UNCERTTYPE_SAMPLESIZE:
    case DISTRIB_UNCERTTYPE_SKEWNESS:
    case DISTRIB_UNCERTTYPE_STANDARDDEVIATION:
    case DISTRIB_UNCERTTYPE_STANDARDERROR:
    case DISTRIB_UNCERTTYPE_VARIANCE:
    case DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL:
    case DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL:
    case DISTRIB_UNCERTTYPE_INTERQUARTILERANGE:
    case DISTRIB_UNCERTTYPE_RANGE:
      uparam->setName(m_displayname);
      break;
    case DISTRIB_UNCERTTYPE_INVALID:
      assert(false); //Should be caught above.
      return true;
    }
  }

  //Set the value/values.
  if (!m_valFormula.IsEmpty()) {
    bool extParamAssigned = false;
    if (sbmltype == DISTRIB_UNCERTTYPE_DISTRIBUTION) {
      //Always set the math, not the value.
      ASTNode* astn = parseStringToASTNode(m_valFormula.ToSBMLString());
      uparam->setMath(astn);
      delete astn;
    }
    else if (m_valFormula.IsDouble()) {
      switch (sbmltype) {
      case DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION:
      case DISTRIB_UNCERTTYPE_KURTOSIS:
      case DISTRIB_UNCERTTYPE_MEAN:
      case DISTRIB_UNCERTTYPE_MEDIAN:
      case DISTRIB_UNCERTTYPE_MODE:
      case DISTRIB_UNCERTTYPE_SAMPLESIZE:
      case DISTRIB_UNCERTTYPE_SKEWNESS:
      case DISTRIB_UNCERTTYPE_STANDARDDEVIATION:
      case DISTRIB_UNCERTTYPE_STANDARDERROR:
      case DISTRIB_UNCERTTYPE_VARIANCE:
      case DISTRIB_UNCERTTYPE_EXTERNALPARAMETER:
        uparam->setValue(m_valFormula.GetDouble());
        if (m_unitVariable.size() > 0) {
          uparam->setUnits(ToStringFromVecDelimitedBy(m_unitVariable, "_"));
        }
        break;
      case DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL:
      case DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL:
      case DISTRIB_UNCERTTYPE_INTERQUARTILERANGE:
      case DISTRIB_UNCERTTYPE_RANGE:
        assert(false); //Should have been caught earlier.
        break;
      case DISTRIB_UNCERTTYPE_DISTRIBUTION:
      case DISTRIB_UNCERTTYPE_INVALID:
        assert(false); //Should be caught above.
        return true;
      }
    }
    else if (m_valFormula.IsSingleVariable()) {
      switch (sbmltype) {
      case DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION:
      case DISTRIB_UNCERTTYPE_KURTOSIS:
      case DISTRIB_UNCERTTYPE_MEAN:
      case DISTRIB_UNCERTTYPE_MEDIAN:
      case DISTRIB_UNCERTTYPE_MODE:
      case DISTRIB_UNCERTTYPE_SAMPLESIZE:
      case DISTRIB_UNCERTTYPE_SKEWNESS:
      case DISTRIB_UNCERTTYPE_STANDARDDEVIATION:
      case DISTRIB_UNCERTTYPE_STANDARDERROR:
      case DISTRIB_UNCERTTYPE_VARIANCE:
      case DISTRIB_UNCERTTYPE_EXTERNALPARAMETER:
        uparam->setVar(m_valFormula.ToSBMLString());
        break;
      case DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL:
      case DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL:
      case DISTRIB_UNCERTTYPE_INTERQUARTILERANGE:
      case DISTRIB_UNCERTTYPE_RANGE:
        assert(false); //Should have been caught earlier.
        break;
      case DISTRIB_UNCERTTYPE_DISTRIBUTION:
      case DISTRIB_UNCERTTYPE_INVALID:
        assert(false); //Should be caught above.
        return true;
      }
    }
    else {
      assert(sbmltype == DISTRIB_UNCERTTYPE_EXTERNALPARAMETER || uspan != NULL); //should be only remaining category.
      ASTNode* astn = parseStringToASTNode(m_valFormula.ToSBMLString());
      if (astn && astn->getType() == AST_LINEAR_ALGEBRA_VECTOR && astn->getNumChildren() == 2) {
        extParamAssigned = true;
        for (int c = 0; c < 2; c++) {
          ASTNode* ch = astn->getChild(c);
          if (ch->isNumber()) {
            if (ch->isSetUnits()) {
              uspan->setUnits(ch->getUnits());
            }
            if (c == 0) {
              uspan->setValueLower(ch->getValue());
            }
            else {
              uspan->setValueUpper(ch->getValue());
            }
          }
          else if (ch->isName()) {
            if (c == 0) {
              uspan->setVarLower(ch->getName());
            }
            else {
              uspan->setVarUpper(ch->getName());
            }
          }
          else {
            assert(sbmltype == DISTRIB_UNCERTTYPE_EXTERNALPARAMETER);
            extParamAssigned = false;
          }
        }
      }
      if (!extParamAssigned) {
        uspan->setMath(astn);
      }
      delete astn;
    }
  }
#endif
  return false;
}

void UncertWrapper::ReadAnnotationFrom(const SBase * sbmlobj)
{
}


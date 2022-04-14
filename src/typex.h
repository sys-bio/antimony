#ifndef ANTIMONY_TYPEX_H
#define ANTIMONY_TYPEX_H

#include "enums.h"
#include <string>
#include <sbml/common/libsbml-config-common.h>
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include <sbml/packages/distrib/extension/DistribExtension.h>
#endif
bool IsReaction(const var_type vtype);
bool IsInteraction(const rd_type rdtype);
bool IsSpecies(const var_type vtype);
bool IsDNA(const var_type vtype);
bool CanHaveRateRule(const var_type vtype);
bool CanHaveAssignmentRule(const var_type vtype);
bool CanBeInReaction(const var_type vtype);
bool CanBeStoichiometry(const var_type vtype);
bool HasOrIsFormula(const var_type vtype);
bool IsSpan(const uncert_type utype);
std::string RDToString(rd_type type);
std::string VarTypeToString(const var_type vtype);
std::string VarTypeToAntimony(const var_type vtype);
std::string ReturnTypeToString(const return_type rtype);
std::string FormulaTypeToString(const formula_type ftype);
std::string UncertTypeToString(const uncert_type utype);
uncert_type UncertStringToType(const std::string& uncert);
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
UncertType_t UncertTypeToSBML(const uncert_type utype);
uncert_type SBMLToUncertType(const UncertType_t utype);
#endif

#endif

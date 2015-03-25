#ifndef ANTIMONY_TYPEX_H
#define ANTIMONY_TYPEX_H

#include "enums.h"
#include <string>
bool IsReaction(const var_type vtype);
bool IsInteraction(const rd_type rdtype);
bool IsSpecies(const var_type vtype);
bool IsDNA(const var_type vtype);
bool CanHaveRateRule(const var_type vtype);
bool CanHaveAssignmentRule(const var_type vtype);
bool HasOrIsFormula(const var_type vtype);
std::string RDToString(rd_type type);
std::string VarTypeToString(const var_type vtype);
std::string VarTypeToAntimony(const var_type vtype);
std::string ReturnTypeToString(const return_type rtype);
std::string FormulaTypeToString(const formula_type ftype);
std::string DistributionTypeToString(const distribution_type dtype);
distribution_type StringToDistributionType(const std::string& name);
std::string GetArgumentStringForDistribution(const distribution_type dtype);
std::string GetURIForDistribution(const distribution_type dtype);
std::string GetWikipediaURIForDistribution(const distribution_type dtype);
#endif

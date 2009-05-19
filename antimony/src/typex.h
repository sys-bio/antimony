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
std::string ReturnTypeToString(return_type rtype);

#endif

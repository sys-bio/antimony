#ifndef RD_TYPE_H
#define RD_TYPE_H

#include <string>
#include <assert.h>

enum rd_type {rdBecomes, rdActivates, rdInhibits, rdInfluences};
std::string RDToString(rd_type type);

enum var_type {varSpeciesUndef, varSpeciesProtein, varFormulaUndef, varDNA, varFormulaPromoter, varFormulaOperator, varReactionGene, varReactionUndef, varUndefined, varModule};

std::string VarTypeToString(const var_type vtype);
var_type StringToVarType(const std::string& name);
bool IsReaction(const var_type var);
bool IsSpecies(const var_type var);
bool IsDNA(const var_type var);
bool HasOrIsFormula(const var_type var);
bool IsReaction(const std::string& name);
bool IsSpecies(const std::string& name);

#endif // RD_TYPE_H

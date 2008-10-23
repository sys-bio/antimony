#ifndef RD_TYPE_H
#define RD_TYPE_H

#include <string>
#include <assert.h>

enum rd_type {rdBecomes, rdActivates, rdInhibits, rdInfluences};
std::string RDToString(rd_type type);

enum var_type {varSpeciesUndef, varFormulaUndef, varDNA, varFormulaOperator, varReactionGene, varReactionUndef, varInteraction, varUndefined, varModule, varEvent};

std::string VarTypeToString(const var_type vtype);
var_type StringToVarType(const std::string& name);
bool IsReaction(const var_type var);
bool IsInteraction(const rd_type rdtype);
bool IsSpecies(const var_type var);
bool IsDNA(const var_type var);
bool HasOrIsFormula(const var_type var);
bool IsReaction(const std::string& name);
bool IsSpecies(const std::string& name);

enum return_type {allSymbols, allSpecies, allFormulas, allReactions, allInteractions, allEvents, allUnknown, varSpecies, varFormulas, varAnyDNA, varOperators, varGenes, constSpecies, constFormulas, constAnyDNA, constOperators, constGenes, subModules};
std::string ReturnTypeToString(return_type rtype);


#endif // RD_TYPE_H

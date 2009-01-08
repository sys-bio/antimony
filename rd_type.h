#ifndef RD_TYPE_H
#define RD_TYPE_H

#include <string>
#include <assert.h>

enum rd_type {rdBecomes, rdActivates, rdInhibits, rdInfluences};
std::string RDToString(rd_type type);

enum var_type {varSpeciesUndef,
               varFormulaUndef,
               varDNA,
               varFormulaOperator,
               varReactionGene,
               varReactionUndef,
               varInteraction,
               varUndefined,
               varModule,
               varEvent,
               varCompartment,
               varStrand};

enum return_type {allSymbols,
                  allSpecies,
                  allFormulas,
                  allDNA,
                  allOperators,
                  allGenes,
                  allReactions,
                  allInteractions,
                  allEvents,
                  allCompartments,
                  allUnknown,
                  varSpecies,
                  varFormulas,
                  varOperators,
                  varCompartments,
                  constSpecies,
                  constFormulas,
                  constOperators,
                  constCompartments,
                  subModules,
                  expandedStrands,
                  modularStrands};

enum const_type {constDEFAULT, constVAR, constCONST};

std::string VarTypeToString(const var_type vtype);
std::string VarTypeToAntimony(const var_type vtype);
bool IsReaction(const var_type var);
bool IsInteraction(const rd_type rdtype);
bool IsSpecies(const var_type var);
bool IsDNA(const var_type var);
bool HasOrIsFormula(const var_type var);

std::string ReturnTypeToString(return_type rtype);


#endif // RD_TYPE_H

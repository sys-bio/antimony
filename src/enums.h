#ifndef ENUMS_H
#define ENUMS_H

enum rd_type {rdBecomes, rdActivates, rdInhibits, rdInfluences};

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

#endif // ENUMS_H

#ifndef ENUMS_H
#define ENUMS_H

 /**
  * @file    enums.h
  * @brief   Various enums used both in the API and internally in libAntimony.
  * @author  Lucian Smith
  *
  */
/**
 * rd_types are the different types of reactions and interactions.
 * - rdBecomes: A reaction: ->
 * - rdActivates: An activation interaction: -o
 * - rdInhibits: An inhibition interaction: -|
 * - rdInfluences: A generic interaction: -(
 */
enum rd_type {rdBecomes = 0, rdActivates, rdInhibits, rdInfluences};

/**
 * var_types define internally what a symbol is; they are not used in the API anywhere.  But for the curious, they are:
 * - varSpeciesUndef: Generic species
 * - varFormulaUndef: Generic formula (reaction rate, constant, etc.)
 * - varDNA: A DNA element
 * - varFormulaOperator: A DNA element that only has a formula associated with it (an operator)
 * - varReactionGene: A DNA element that has a reaction associated with it (a gene)
 * - varReactionUndef: A generic reaction
 * - varInteraction: A generic interaction
 * - varUndefined: A symbol that was used somewhere (like in a formula) that has no other definition.
 * - varModule: A submodule
 * - varEvent: An event
 * - varCompartment: A compartment
 * - varStrand: A DNA strand (an ordered list of DNA elements)
 */

enum var_type {varSpeciesUndef = 0,
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
/**
 * return_types are used in the API when requesting information about different symbols.  Each return_type refers to a different group of symbols, and are overlapping--i.e. a single symbol can be included in 'allGenes' and 'allReactions'. 
  * - allSymbols:        Every symbol of every type in Antimony
  * - allSpecies:        All species, both const (border) and variable.
  * - allFormulas:       All formulas (values defined by an equation), both const and variable.
  * - allDNA:            All symbols defined to be DNA (operators and genes, but not strands).
  * - allOperators:      All symbols defined to be operators (formulas embeddable in a DNA strand).
  * - allGenes:          All symbols defined to be genes (reactions embeddable in a DNA strand).
  * - allReactions:      All reactions (species being converted or created).
  * - allInteractions:   All interactions (species involved in reaction rates).
  * - allEvents:         All events.
  * - allCompartments:   All compartments, both const and variable.
  * - allUnknown:        All symbols whose type has never been defined or used.
  * - varSpecies:        Variable species.
  * - varFormulas:       Formulas (equations) that can change (including as a result of events).
  * - varOperators:      Operators with variable values.
  * - varCompartments:   Compartments with variable sizes.
  * - constSpecies:      Constant species (aka 'border species').
  * - constFormulas:     Formulas with constant values.
  * - constOperators:    Operators with constant values.
  * - constCompartments: Compartments with constant sizes.
  * - subModules:        Submodules used within the current module.
  * - expandedStrands:   DNA strands containing nothing but operators and genes--any sub-strands have been expanded to their component DNA objects, and those sub-strands are not included in any lists.
  * - modularStrands:    All defined DNA strands, with some being subparts of the others.
  */
enum return_type {allSymbols = 0,
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

/**
 * const_type values are not used in the API, but are used internally in libAntimony.  Every symbol starts off being constDEFAULT, which means that the model never stated explicitly whether the symbol was to be constant or variable, so the program will use a heuristic to determine which is the case.  Once set, the heuristic is ignored, and the type (constVAR for variable symbols, constCONST for constant ones) is permanent.  Not all symbols can actually be variable or constant (for example, submodules and reactions), so attempts to set this value for those symbols will fail.
 */
enum const_type {constDEFAULT = 0, constVAR, constCONST};

/**
 * rule_type values are not used in the API, but are used internally in libAntimony.  Every symbol starts off with a default type based on its type (most things are formINITIAL; reactions are formKINETIC, and events are formTRIGGER), and those symbols that aren't reactions, events, or modules may be formASSIGNMENT (for those symbols that have assignment rules) or formRATE (for those symbols that have rate rules).  formASSIGNMENT symbols have only one formula, but formRATE have two: one for their initial condition, and one for how it changes with time.
 */
enum formula_type {formulaINITIAL = 0, formulaASSIGNMENT, formulaRATE, formulaKINETIC, formulaTRIGGER};
#endif // ENUMS_H

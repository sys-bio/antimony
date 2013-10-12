/**
  * @file    antimony_api_cpp.h
  * @brief   An API for the Antimony parser using C++ objects
  * @author  Lucian Smith
  *
  * When creating Python bindings for antimony_api.h, we ran into the problem that some return values were arrays, and did not contain information about their length, making them impossible to wrap in some languages.  This file therefore converts any function from the C API and converts it to use C++ vectors (and strings) instead.
  */


#ifndef ANTIMONY_API_CPP_H
#define ANTIMONY_API_CPP_H

#include "libutil.h"
#include "enums.h"

/**
  * @name Modules
  */
/** \{ */
/**
 * Returns an array of all the current module names.
 */
LIB_EXTERN std::vector<std::string> getModuleNamesAsVector();

/** \} */

/**
  * @name Module Interface
  */
/** \{ */
/**
 * Returns the names of the symbols defined to be in the interface of the given module.  In other words, if a module is defined 'module M(x, y, z)', this returns the list 'x, y, z'.  A module with no symbols defined in its interface would return a pointer to an empty string. 
 */
LIB_EXTERN std::vector<std::string> getSymbolNamesInInterfaceOfAsVector(const char* moduleName);

/** \} */



/**
  * @name Replacements
  */
/** \{ */

/**
 * Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 * @see getNthReplacementSymbolPair
 */
LIB_EXTERN std::vector<std::vector<std::string> > getAllReplacementSymbolPairsAsVector(const char* moduleName);

/**
 * Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN std::vector<std::string> getNthReplacementSymbolPairAsVector(const char* moduleName, unsigned long n);

/**
 * Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 * @see getNthReplacementSymbolPair
 */
LIB_EXTERN std::vector<std::vector<std::string> > getAllReplacementSymbolPairsBetweenAsVector(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);

/**
 * Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN std::vector<std::string> getNthReplacementSymbolPairBetweenAsVector(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);
/** \} */



/**
  * @name Symbols and symbol information
  */
/** \{ */

/**
 * Returns the names of the symbols of the given return type.  (In SBML, these are the 'id's.)
 */
LIB_EXTERN std::vector<std::string> getSymbolNamesOfTypeAsVector(const char* moduleName, return_type rtype);

/**
 * Returns the 'display names' of the symbols of the given return type.  (In SBML, these are the 'name's.)
 */
LIB_EXTERN std::vector<std::string> getSymbolDisplayNamesOfTypeAsVector(const char* moduleName, return_type rtype);

/**
 * Returns the equations associated with the symbols of the given return type.
 * - Species:                 The initial assignment or assignment rule for the species in question
 * - Formulas and operators:  The initial assignment or assignment rule for the formula in question
 * - Compartments:            The initial assignment or assignment rule for the compartment in question
 * - DNA elements:            The assignment rule or reaction rate of the element in question (no DNA element is defined by an initial assignment or by a rate rule with an initial assignment)
 * - DNA Strands:             The assignment rule or reaction rate for the last element of the strand
 * - Reactions and genes:     The reaction rate
 * - Events:                  The trigger condition
 * - Interactions:            Nothing
 * - Modules:                 Nothing
 *
 * For elements that could have either initial assignments or assignment rules, use getTypeOfEquationForSymbol, or just use getSymbolInitialAssignmentsOfType and getSymbolAssignmentRulesOfType explicitly.
 */
LIB_EXTERN std::vector<std::string> getSymbolEquationsOfTypeAsVector(const char* moduleName, return_type rtype);


/**
 * Returns the equations associated with the initial assignment for symbols of the given return type.
 * - Species:                 The initial assignment for the species in question
 * - Formulas and operators:  The initial assignment of the formula in question
 * - Compartments:            The initial assignment for the compartment
 *
 * - DNA Strands:             Nothing
 * - Reactions and genes:     Nothing
 * - Events:                  Nothing
 * - Interactions:            Nothing
 * - Modules:                 Nothing
 */
LIB_EXTERN std::vector<std::string> getSymbolInitialAssignmentsOfTypeAsVector(const char* moduleName, return_type rtype);

/**
 * Returns the equations associated with the assignment rule for symbols of the given return type.
 * - Species:                 The assignment rule for the species in question
 * - Formulas and operators:  The assignment rule of the formula in question
 * - Compartments:            The assignment rule for the compartment
 * - DNA Strands:             The assignment rule or reaction rate at the end of the strand.
 * - Reactions and genes:     The reaction rate (for consistency with DNA strands)
 *
 * - Events:                  Nothing
 * - Interactions:            Nothing
 * - Modules:                 Nothing
 */
LIB_EXTERN std::vector<std::string> getSymbolAssignmentRulesOfTypeAsVector(const char* moduleName, return_type rtype);

/**
 * Returns the equations associated with the rate rule for symbols of the given return type.
 * - Species:                 The rate rule for the species in question
 * - Formulas and operators:  The rate rule of the formula in question
 * - Compartments:            The rate rule for the compartment
 * - DNA Strands:             The rate rule or reaction rate at the end of the strand.
 * - Reactions and genes:     Nothing
 * - Events:                  Nothing
 * - Interactions:            Nothing
 * - Modules:                 Nothing
 */
LIB_EXTERN std::vector<std::string> getSymbolRateRulesOfTypeAsVector(const char* moduleName, return_type rtype);

/**
 * Returns the compartments associated with the symbols of the given return type.  Note that unlike in SBML, any symbol of any type may have an associated compartment, including compartments themselves.  Rules about compartments in Antimony can be found in the <A class="el" target="_top" HREF="Tutorial.pdf">Tutorial.pdf</a> document included with this documentation.
 */
LIB_EXTERN std::vector<std::string> getSymbolCompartmentsOfTypeAsVector(const char* moduleName, return_type rtype);
/** \} */

/**
  * @name Reactions
  */
/** \{ */
/**
 * Returns all the reactant names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumReactants' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN std::vector<std::vector<std::string> > getReactantNamesAsVector(const char* moduleName);

/**
 * Returns an array of all the reactant names for the given reaction.  The length of the array can be obtained with 'getNumReactants'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN std::vector<std::string>  getNthReactionReactantNamesAsVector(const char* modulename, unsigned long rxn);

/**
 * Returns all the product names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumProducts' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN std::vector<std::vector<std::string> > getProductNamesAsVector(const char* moduleName);

/**
 * Returns an array of all the product names for the given reaction.  The length of the array can be obtained with 'getNumProducts'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN std::vector<std::string>  getNthReactionProductNamesAsVector(const char* modulename, unsigned long rxn);

/**
 * Returns a two-dimensional array of the stoichiometries for all reactants in all reactions in the given module.
 */
LIB_EXTERN std::vector<std::vector<double> > getReactantStoichiometriesAsVector(const char* moduleName);

/**
 * Returns a two-dimensional array of the stoichiometries for all products in all reactions in the given module.
 */
LIB_EXTERN std::vector<std::vector<double> > getProductStoichiometriesAsVector(const char* moduleName);

/** \} */

/**
  * @name Interactions
  */
/** \{ */
/**
 * Returns all the interactor names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractors' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN std::vector<std::vector<std::string> > getInteractorNamesAsVector(const char* moduleName);

/**
 * Returns an array of all the interactor names for the given interaction.  The length of the array can be obtained with 'getNumInteractors'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN std::vector<std::string>  getNthInteractionInteractorNamesAsVector(const char* modulename, unsigned long rxn);

/**
 * Returns all the interactee names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractees' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN std::vector<std::vector<std::string> > getInteracteeNamesAsVector(const char* moduleName);

/**
 * Returns an array of all the interactee names for the given interaction.  The length of the array can be obtained with 'getNumInteractees'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN std::vector<std::string>  getNthInteractionInteracteeNamesAsVector(const char* modulename, unsigned long rxn);

/**
 * Returns an array of all the interaction dividers in the given module.  The length of the array can be obtained with 'getNumInteractions'.
 */
LIB_EXTERN std::vector<rd_type> getInteractionDividersAsVector(const char* moduleName);

/** \} */

/**
  * @name Stoichiometry matrix information
  */
/** \{ */

/**
 * Returns an N x M stoichiometry matrix where N is the number of reactions in the model, and M is the number of variable species (or 'floating species').
 */
LIB_EXTERN std::vector<std::vector<double> > getStoichiometryMatrixAsVector(const char* moduleName);

/**
 * The row labels for the stoichiometry matrix.  Is exactly the same as calling 'getSymbolNamesOfType(moduleName, varSpecies)', but provided here so you don't have to think about it.
 */
LIB_EXTERN std::vector<std::string>   getStoichiometryMatrixRowLabelsAsVector(const char* moduleName);

/**
 * The column labels for the stoichiometry matrix.  Is exactly the same as calling 'getSymbolNamesOfType(moduleName, allReactions)' but provided here so you don't have to think about it.
 */
LIB_EXTERN std::vector<std::string>   getStoichiometryMatrixColumnLabelsAsVector(const char* moduleName);

/**
 * Returns an array of the reaction rates for the given module.  Is the same as 'getSymbolEquationsOfType(moduleName, allReactions)', but is provided for convenience.
 */
LIB_EXTERN std::vector<std::string>   getReactionRatesAsVector(const char* moduleName);

/** \} */

/**
  * @name Events
  */
/** \{ */

/**
 * Returns the names of the events in the module.  Is the same as 'getSymbolNamesOfType(moduleName, allEvents)', but is provided for convenience.
 */
LIB_EXTERN std::vector<std::string>  getEventNamesAsVector(const char* moduleName);
/** \} */

/**
  * @name DNA strands
  */
/** \{ */

/**
 * Returns an array of DNA strand sizes for all strands in the module.  Useful for looping over the arrays returned by 'getDNAStrands'
 */
LIB_EXTERN std::vector<unsigned long> getDNAStrandSizesAsVector(const char* moduleName);

/**
 * Returns an array of all DNA strands in the given module as lists of their components.  All components are either Operator objects or Gene objects, depending on whether they have an associated reaction.
 */
LIB_EXTERN std::vector<std::vector<std::string> > getDNAStrandsAsVector(const char* moduleName);

/**
 * Returns an array of names of the components in the nth DNA strand in the given module.  If no such strand exists, sets an error and returns NULL.
 */
LIB_EXTERN std::vector<std::string>  getNthDNAStrandAsVector(const char* moduleName, unsigned long n);

/**
 * Returns an array of Modular DNA strand sizes for the given module.  Useful for looping over the components in the sub-arrays returned by getModularDNAStrands.
 */
LIB_EXTERN std::vector<unsigned long> getModularDNAStrandSizesAsVector(const char* moduleName);

/**
 * Returns an array of strands, each of which has an array of the names of the components of that strand.  The components may be operators, genes, and other modular DNA strands. 
 */
LIB_EXTERN std::vector<std::vector<std::string> > getModularDNAStrandsAsVector(const char* moduleName);

/**
 * Returns an array of names of the components in the nth modular DNA strand in the given module.  If no such strand exists, an error is set, and NULL is returned.
 */
LIB_EXTERN std::vector<std::string>  getNthModularDNAStrandAsVector(const char* moduleName, unsigned long n);

/** \} */

#endif //ANTIMONY_API_CPP_H

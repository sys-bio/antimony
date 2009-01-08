 /**
  * @file    antimony_api.h
  * @brief   The API for libAntimony
  * @author  Lucian Smith
  *
  * libAntimony uses a bison parser, libSBML, and internal C++ objects to read, convert, store, and output abstracted models of biological systems.  Information about creating antimony-formatted input files is available from http://sys-bio.org/.  The functions described in this document are a plain C API (application programming interface) to be used in programs that want to convert Antimony models to their own internal formats, and/or to convert Antimony models to and from SBML models.
  *
  * Note:  It is not currently possible to convert an internally-formatted model into an Antimony model (the API has several 'get' functions, but no 'set' functions).  This restriction will be relaxed in future versions of the library.
  *
  * Antimony models are modular; that is, one model may be defined and then used as a subset of a larger model.  As such, a single Antimony file may contain a number of different models, each referred to as a 'module'.  SBML files are (as of January 2009) not modular, and only contain a single model per file.  When writing SBML files, therefore, only one module may be written per file.  (A proposed aspect of SBML Level 3 is to introduce modularity in a similar way to how Antimony works; once libSBML implements this modularity, libAntimony will be extended to allow writing and reading of modular SBML files as well.)
  *
  * Converting files may be accomplished fairly straightforwardly using 'loadFile' to read in a file (of either Antimony or SBML format), 'getNumModules' and 'getModuleNames' to obtain a list of the modules in that file, and finally the 'writeAntimonyFile' or 'writeSBMLFile' routines to write them out again.
  *
  * Converting the models inside Antimony or SBML files to your own internal format for your software is a bit more involved.  An example program is provided that will read in a list of files, write out all the included modules to individual Antimony and SBML files, and write out a list of the components to the screen in a few different formats which will hopefully prove useful as an example.  The 'printAllDataFor' routine in the file antimony_api.cpp may also be used as an example, as it only uses routines provided in the API, and is thus fully exportable and modifiable in other C or C++ programs.
  *
  * In general, Antimony models may contain:
  *   * Species
  *   * Reactions
  *   * Reaction rates and other formulas
  *   * Compartments
  *   * Events
  *   * Interactions (not modelled explicitly in SBML, only implied)
  *   * DNA strands (not modelled explicitly in SBML)
  *
  * Note that there are many concepts modelled in SBML that are not modelled in libAntimony--as such, libAntimony is not the ideal tool to use to convert SBML models with those concepts included; the excellent libSBML (http://sbml.org/Software/libSBML) should be used instead.  Similarly, the concepts in Antimony not in SBML (the main ones being modularity, interactions, and DNA strands) will be lost when converting to an SBML file, so converting an Antimony file to SBML and back again may be lossy.
  *
  * Return Types
  * Many of the functions listed below ask for an enum value to determine what kind of symbol you are asking about.  This list is declared in rd_type.h, and is as follows:
         0: allSymbols:        Every symbol of every type in Antimony
         1: allSpecies:        All species, both const (border) and variable.
         2: allFormulas:       All formulas (values defined by an equation), both const and variable.
         3: allDNA:            All symbols defined to be DNA (operators and genes, but not strands).
         4: allOperators:      All symbols defined to be operators (formulas embeddable in a DNA strand).
         5: allGenes:          All symbols defined to be genes (reactions embeddable in a DNA strand).
         6: allReactions:      All reactions (species being converted or created).
         7: allInteractions:   All interactions (species involved in reaction rates).
         8: allEvents:         All events.
         9: allCompartments:   All compartments, both const and variable.
        10: allUnknown:        All symbols whose type has never been defined or used.
        11: varSpecies:        Variable species.
        12: varFormulas:       Formulas (equations) that can change (including as a result of events).
        13: varOperators:      Operators with variable values.
        14: varCompartments:   Compartments with variable sizes.
        15: constSpecies:      Constant species (aka 'border species').
        16: constFormulas:     Formulas with constant values.
        17: constOperators:    Operators with constant values.
        18: constCompartments: Compartments with constant sizes.
        19: subModules:        Submodules used within the current module.
        20: expandedStrands:   DNA strands containing nothing but operators and genes--any sub-strands have been expanded to their component DNA objects, and those sub-strands are not included in any lists.
        21: modularStrands:    All defined DNA strands, with some being subparts of the others.
  *
  * Returned Pointers
  * The majority of the functions described below return pointers to arrays and/or strings.  These pointers pointers you then own, created with 'malloc':  you must 'free' them yourself to release the allocated memory.  Some programming environments will handle this automatically for you, and others will not.  If you want to not bother with it, the function 'freeAll' is provided, which will free every pointer created by this library.  In order for this to work, however, you must have not freed a single provided pointer yourself, and you must not subsequently try to reference any data provided by the library (your own copies of the data will be fine, of course).
  *
  * If the library runs out of memory when trying to return a pointer, it will return NULL instead and attempt to set an error message, retrievable with 'getLastError()'.
 */


#ifndef ANTIMONY_API_H
#define ANTIMONY_API_H

#include "libutil.h"
#include "rd_type.h"

BEGIN_C_DECLS;

/**
 * @brief Load a file of either SBML or Antimony format.
 *
 * Loads a file of either SBML or Antimony format.  It first attempts to read the document as SBML, and if this results in an error, then reads it as Antimony.  If this, too, results in an error, the second error is saved, and a '-1' is returned.
 *
 * @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 *
 * @param The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadFile(const char* filename);

/**
 * @brief Load a file known to be SBML.
 *
 * Loads a file and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 * @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 *
 * @param The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadSBMLFile(const char* filename);

/**
 * @brief Returns the number of files loaded into memory so far.
 *
 * Every time 'loadFile' or 'loadSBMLFile' is called successfully, the module(s) in those files are saved.  This function will tell you how many sets of modules from successful reads are resident in memory.
 * @return The number of files currently stored in memory.
 */
LIB_EXTERN size_t getNumFiles();

/**
 * Change the 'active' set of modules to the ones from the given index (as received from 'loadFile' or 'loadSBMLFile').  Attempting to revert to a negative or nonexistent index returns 'true' and the previous active set of modules is retained.
 *
 */
LIB_EXTERN bool   revertTo(long index);

/**
 * Clears memory of all files loaded.  The next successful call to 'loadFile' or 'loadSBMLFile' will return 0 as the first valid index.
 */
LIB_EXTERN void   clearPreviousLoads();

/**
 * When any function returns an error condition, a longer description of the problem is stored in memory, and obtainable with this function.  In most cases, this means that a call that returns a pointer returned 'NULL' (or 0).
 */
LIB_EXTERN char*  getLastError();

/**
 * Returns the number of modules in the current active set (i.e. the last file successfully loaded, or whichever file was returned to with 'revertTo'
 */
LIB_EXTERN size_t getNumModules();

/**
 * Returns an array of all the current module names
 */
LIB_EXTERN char** getModuleNames();

/**
 * Returns just the nth module name.  Returns NULL and sets an error if there is no such module n.
 */
LIB_EXTERN char*  getNthModuleName(size_t n);

/**
 * Returns 'true' if the submitted module name exists in the current active set, 'false' if not.
 */
LIB_EXTERN bool   checkModule(const char* moduleName);

/**
 * Returns the number of symbols of the given return type (see above).  Useful when looping over the arrays in the subsequent functions.
 */
LIB_EXTERN size_t getNumSymbolsOfType(const char* moduleName, return_type rtype);

/**
 * Returns the names of the symbols of the given return type.
 */
LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype);

/**
 * Returns the equations associated with the symbols of the given return type.
 *   Reactions and genes:     The reaction rate
 *   Formulas and operators:  The formula in question
 *   Species:                 Initial concentration
 *   Events:                  The trigger condition
 *   Compartments:            The initial size
 *   DNA Strands:             The reaction rate at the end of the strand
 *   Interactions:            Nothing
 *   Modules:                 Nothing
 */
LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype);

/**
 * Returns the compartments associated with the symbols of the given return type.  Note that unlike in SBML, any symbol of any type may have an associated compartment, including compartments themselves.  Rules about compartments in Antimony can be found at [sys-bio.org]
 */ //LS DEBUG:  documentation
LIB_EXTERN char** getSymbolCompartmentsOfType(const char* moduleName, return_type rtype);

/**
 * Returns the name of the Nth symbol of the given type.  If no such symbol exists, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n);

/**
 * Returns the equation associated with the Nth symbol of the given type.  If no equation is set for the symbol in question, an empty string is returned.  If no symbol can be found, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n);

/**
 * Returns the name of the compartment associated with the nth symbol of the given type.  If no compartment is explicitly set in the file, the string "default_compartment" is returned.  If no symbol can be found, NULL is returned and an error is set.
*/
LIB_EXTERN char*  getNthSymbolCompartmentOfType(const char* moduleName, return_type rtype, size_t n);

/**
 * Returns the number of reactions (including genes) in the named module.  Useful when looping over all reactions in the arrays returned by subsequent functions.
 */
LIB_EXTERN size_t getNumReactions(const char* moduleName);

/**
 * Returns the number of reactants (species on the left side of the reaction) for the given reaction.  If no such reaction is present, '0' is returned and an error is set.  Sadly, if there are no reactants, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, most likely.
*/
LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t rxn);

/**
 * Returns the number of products (species on the right side of the reaction) for the given reaction.  If no such reaction is present, '0' is returned and an error is set.  Sadly, if there are no products, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, too.
 */
LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t rxn);

/**
 * Returns all the reactant names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumReactants' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getReactantNames(const char* moduleName);

/**
 * Returns an array of all the reactant names for the given reaction.  The length of the array can be obtained with 'getNumReactants'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthReactionReactantNames(const char* modulename, size_t rxn);

/**
 * Returns all the product names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumProducts' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getProductNames(const char* moduleName);

/**
 * Returns an array of all the product names for the given reaction.  The length of the array can be obtained with 'getNumProducts'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthReactionProductNames(const char* modulename, size_t rxn);

/**
 * Returns a two-dimensional array of the stoichiometries for all reactants in all reactions in the given module.
 */
LIB_EXTERN double** getReactantStoichiometries(const char* moduleName);

/**
 * Returns a two-dimensional array of the stoichiometries for all products in all reactions in the given module.
 */
LIB_EXTERN double** getProductStoichiometries(const char* moduleName);

/**
 * Returns an array of the stoichiometries for the reactants of the Nth reaction in the module.  If no such reaction exists, an error is set and NULL is returned.
 */
LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n);

/**
 * Returns an array of the stoichiometries for the reactants of the Nth reaction in the module.  If no such reaction exists, an error is set and NULL is returned.
 */
LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, size_t n);



/**
 * Returns the number of interactions in the named module.  Useful when looping over all interactions in the arrays returned by subsequent functions.
 */
LIB_EXTERN size_t getNumInteractions(const char* moduleName);

/**
 * Returns the number of interactors (species on the left side of the interaction) for the given interaction.  If no such interaction is present, '0' is returned and an error is set.  Sadly, if there are no interactors, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, most likely.
*/
LIB_EXTERN size_t getNumInteractors(const char* moduleName, size_t rxn);

/**
 * Returns the number of interactees (reactions on the right side of the interaction) for the given interaction.  If no such interaction is present, '0' is returned and an error is set.  Sadly, if there are no interactees, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, too.
 */
LIB_EXTERN size_t getNumInteractees(const char* moduleName, size_t rxn);

/**
 * Returns all the interactor names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractors' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getInteractorNames(const char* moduleName);

/**
 * Returns an array of all the interactor names for the given interaction.  The length of the array can be obtained with 'getNumInteractors'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionInteractorNames(const char* modulename, size_t rxn);

/**
 * Returns all the interactee names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractees' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getInteracteeNames(const char* moduleName);

/**
 * Returns an array of all the interactee names for the given interaction.  The length of the array can be obtained with 'getNumInteractees'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionInteracteeNames(const char* modulename, size_t rxn);

/**
 * Returns a two-dimensional array of the stoichiometries for all interactors in all interactions in the given module.
 */
LIB_EXTERN double** getInteractorStoichiometries(const char* moduleName);

/**
 * Returns a two-dimensional array of the stoichiometries for all interactees in all interactions in the given module.
 */
LIB_EXTERN double** getInteracteeStoichiometries(const char* moduleName);

/**
 * Returns an array of the stoichiometries for the interactors of the Nth interaction in the module.  If no such interaction exists, an error is set and NULL is returned.
 */
LIB_EXTERN double* getNthInteractionInteractorStoichiometries(const char* moduleName, size_t n);

/**
 * Returns an array of the stoichiometries for the interactors of the Nth interaction in the module.  If no such interaction exists, an error is set and NULL is returned.
 */
LIB_EXTERN double* getNthInteractionInteracteeStoichiometries(const char* moduleName, size_t n);
LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName);
LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, size_t n);

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName);
LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName);
LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName);

LIB_EXTERN char**   getReactionRates(const char* moduleName);
LIB_EXTERN char*    getNthReactionRate(const char* moduleName, size_t n);
LIB_EXTERN size_t   getNumReactionRates(const char* moduleName);


LIB_EXTERN size_t  getNumEvents(const char* moduleName);
LIB_EXTERN char**  getEventNames(const char* moduleName);
LIB_EXTERN char*   getNthEventName(const char* moduleName, size_t event);
LIB_EXTERN size_t  getNumAssignmentsForEvent(const char* moduleName, size_t event);
LIB_EXTERN char*   getTriggerForEvent(const char* moduleName, size_t event);
LIB_EXTERN char*   getNthAssignmentVariableForEvent(const char* moduleName, size_t event, size_t n);
LIB_EXTERN char*   getNthAssignmentEquationForEvent(const char* moduleName, size_t event, size_t n);

LIB_EXTERN char*** getDNAStrands(const char* moduleName);
LIB_EXTERN char**  getNthDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN bool    getIsNthDNAStrandOpen(const char* moduleName, size_t n, bool upstream);
LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName);
LIB_EXTERN size_t  getNumDNAStrands(const char* moduleName);

LIB_EXTERN char*** getModularDNAStrands(const char* moduleName);
LIB_EXTERN char**  getNthModularDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN bool    getIsNthModularDNAStrandOpen(const char* moduleName, size_t n, bool upstream);
LIB_EXTERN size_t* getModularDNAStrandSizes(const char* moduleName);
LIB_EXTERN size_t  getNumModularDNAStrands(const char* moduleName);

LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName);
LIB_EXTERN char*   getCompartmentForSymbol(const char* moduleName, const char* symbolName);

//Output
LIB_EXTERN int   writeAntimonyFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getAntimonyString(const char* moduleName);

LIB_EXTERN int   writeJarnacFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getJarnacString(const char* moduleName);

LIB_EXTERN int   writeSBMLFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getSBMLString(const char* moduleName);

//Warnings and extra information
LIB_EXTERN char* getSBMLInfoMessages(const char* moduleName);
LIB_EXTERN char* getSBMLWarnings(const char* moduleName);

LIB_EXTERN void freeAll();

LIB_EXTERN void printAllDataFor(const char* moduleName);


END_C_DECLS;

#endif //ANTIMONY_API_H

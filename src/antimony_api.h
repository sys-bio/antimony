 /**
  * @file    antimony_api.h
  * @brief   The API for the Antimony parser
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
  * - Species
  * - Reactions
  * - Reaction rates and other formulas
  * - Compartments
  * - Events
  * - Interactions (not modelled explicitly in SBML, only implied)
  * - DNA strands (not modelled explicitly in SBML)
  *
  * Note that there are many concepts modelled in SBML that are not modelled in libAntimony--as such, libAntimony is not the ideal tool to use to convert SBML models with those concepts included; the excellent libSBML (http://sbml.org/Software/libSBML) should be used instead.  Similarly, the concepts in Antimony not in SBML (the main ones being modularity, interactions, and DNA strands) will be lost when converting to an SBML file, so converting an Antimony file to SBML and back again may be lossy.
  *
  * Return Types
  * Many of the functions listed below ask for an enum value to determine what kind of symbol you are asking about.  This list is declared in enums.h, and is as follows:
  * - 0: allSymbols:        Every symbol of every type in Antimony
  * - 1: allSpecies:        All species, both const (border) and variable.
  * - 2: allFormulas:       All formulas (values defined by an equation), both const and variable.
  * - 3: allDNA:            All symbols defined to be DNA (operators and genes, but not strands).
  * - 4: allOperators:      All symbols defined to be operators (formulas embeddable in a DNA strand).
  * - 5: allGenes:          All symbols defined to be genes (reactions embeddable in a DNA strand).
  * - 6: allReactions:      All reactions (species being converted or created).
  * - 7: allInteractions:   All interactions (species involved in reaction rates).
  * - 8: allEvents:         All events.
  * - 9: allCompartments:   All compartments, both const and variable.
  * - 10: allUnknown:        All symbols whose type has never been defined or used.
  * - 11: varSpecies:        Variable species.
  * - 12: varFormulas:       Formulas (equations) that can change (including as a result of events).
  * - 13: varOperators:      Operators with variable values.
  * - 14: varCompartments:   Compartments with variable sizes.
  * - 15: constSpecies:      Constant species (aka 'border species').
  * - 16: constFormulas:     Formulas with constant values.
  * - 17: constOperators:    Operators with constant values.
  * - 18: constCompartments: Compartments with constant sizes.
  * - 19: subModules:        Submodules used within the current module.
  * - 20: expandedStrands:   DNA strands containing nothing but operators and genes--any sub-strands have been expanded to their component DNA objects, and those sub-strands are not included in any lists.
  * - 21: modularStrands:    All defined DNA strands, with some being subparts of the others.
  *
  * Returned Pointers
  * The majority of the functions described below return pointers to arrays and/or strings.  These pointers you then own, and are created with 'malloc':  you must 'free' them yourself to release the allocated memory.  Some programming environments will handle this automatically for you, and others will not.  If you want to not bother with it, the function 'freeAll' is provided, which will free every pointer created by this library.  In order for this to work, however, you must have not freed a single provided pointer yourself, and you must not subsequently try to reference any data provided by the library (your own copies of the data will be fine, of course).
  *
  * If the library runs out of memory when trying to return a pointer, it will return NULL instead and attempt to set an error message, retrievable with 'getLastError()'.
  *
 */


#ifndef ANTIMONY_API_H
#define ANTIMONY_API_H

#ifndef VERSION_STRING //So we can define it in the makefile if need be.
#define VERSION_STRING "v1.3"
#endif


#include "libutil.h"
#include "enums.h"

BEGIN_C_DECLS
/**
  * @name Input Functions
  */
/** \{ */
/**
 * Load a file of either SBML or Antimony format.  The first attempts to read the document as SBML, and if this results in an error, then reads it as Antimony.  If this, too, results in an error, the second error is saved, and a '-1' is returned.
 *
 * @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 *
 * @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadFile(const char* filename);

/**
 * Load a string of either SBML or Antimony format.  The first attempts to read the string as SBML, and if this results in an error, then reads it as Antimony.  If this, too, results in an error, the second error is saved, and a '-1' is returned.
 *
 * @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 *
 * @param model The model, in either Antimony or SBML format.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadString(const char* model);

#ifndef NSBML
/**
 * @brief Load a file known to be SBML.
 *
 * Loads a file and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 * @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 *
 * @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadSBMLFile(const char* filename);

/**
 * @brief Load a string known to be SBML.
 *
 * Loads a string and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 * @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 *
 * @param model The model, in SBML format.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadSBMLString(const char* model);
#endif

#ifndef NCELLML
/**
 * @brief Load a file known to be CellML.
 *
 * Loads a file and parses it (using libCellML) as a CellML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 * @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NCELLML' flag.
 *
 * @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadCellMLFile(const char* filename);

/**
 * @brief Load a string known to be CellML.
 *
 * Loads a string and parses it (using libCellML) as a CellML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 * @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NCELLML' flag.
 *
 * @param model The model, in CellML format.
 *
 * @see getLastError()
 */
LIB_EXTERN long   loadCellMLString(const char* model);
#endif


/**
 * @brief Returns the number of files loaded into memory so far.
 *
 * Every time 'load<file/string>' is called successfully, the module(s) in those files are saved.  This function will tell you how many sets of modules from successful reads are resident in memory.
 * @return The number of files currently stored in memory.
 */

LIB_EXTERN unsigned long getNumFiles();

/**
 * Change the 'active' set of modules to the ones from the given index (as received from 'load<file/string>').  Attempting to revert to a negative or nonexistent index returns 'false' and the previous active set of modules is retained.  A successful change return 'true'.
 *
 */
LIB_EXTERN bool   revertTo(long index);

/**
 * Clears memory of all files loaded.  The next successful call to 'load<file/string>' will return 0 as the first valid index.
 */
LIB_EXTERN void   clearPreviousLoads();
/** \} */

/**
  * @name Output
  */
/** \{ */

/**
 * Writes out an antimony-formatted file containing the given module.  If no module name is given, all modules in the current set are returned.  If the module depends on any sub-modules, those modules are written out as well, also in the antimony format.  Returns 0 on failure (and sets an error), 1 on success.
 */
LIB_EXTERN int   writeAntimonyFile(const char* filename, const char* moduleName);

/**
 * Returns the same output as writeAntimonyFile, but to a char* array instead of to a file.  Returns NULL on failure, and sets an error.
 */
LIB_EXTERN char* getAntimonyString(const char* moduleName);

#ifndef NSBML
/**
 * Writes out a SBML-formatted XML file to the file indicated.  For now, the output is 'flattened', that is, all components of sub-modules are re-named and placed in a single model.  Returns the output of libSBML's 'writeSBML', which "Returns non-zero on success and zero if the filename could not be opened for writing."  An error indicating this is set on returning zero.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 *
 *@see getSBMLString
 */
LIB_EXTERN int   writeSBMLFile(const char* filename, const char* moduleName);
/**
 * Returns the same output as writeSBMLFile, but to a char* array instead of to a file.  Returns the output of libSBML's 'writeSBMLToString", which "Returns the string on success and NULL if one of the underlying parser components fail (rare)."
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 *
 *@see writeSBMLFile
 */
LIB_EXTERN char* getSBMLString(const char* moduleName);
#endif

#ifndef NCELLML
/**
 * Writes out a CellML-formatted XML file to the file indicated.  For now, the output is 'flattened', that is, all components of sub-modules are re-named and placed in a single model.  Returns one on success and zero on failure.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NCELLML' flag.
 *
 *@see getCellMLString
 */
LIB_EXTERN int   writeCellMLFile(const char* filename, const char* moduleName);
/**
 * Returns the same output as writeCellMLFile, but to a char* array instead of to a file.  Returns the string on success (as translated to 'char' from CellML's native 'wchar') and NULL on failure."
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NCELLML' flag.
 *
 *@see writeCellMLToString
 */
LIB_EXTERN char* getCellMLString(const char* moduleName);
#endif

/**
 * Writes out a jarnac-formatted file containing a 'flattened' version of the current module (one where all the species and reactions are listed in the same model).  This has *not* been very extensively tested, and many aspects of the model may be dropped.  But the basics should be there.  Returns 1 on success, 0 on failure (and sets an error).
 */
LIB_EXTERN int   writeJarnacFile(const char* filename, const char* moduleName);

/**
 * Returns the same output as writeJarnacFile, but to a char* array instead of to a file.
 */
LIB_EXTERN char* getJarnacString(const char* moduleName);


/**
 * An example function that will print to stdout all the information in the given module.  This function probably isn't as useful to call as it is to examine and copy for your own purposes:  it only calls functions defined here in antimony_api.h.
 */
LIB_EXTERN void printAllDataFor(const char* moduleName);
/** \} */

/**
  * @name Errors and Warnings
  */
/** \{ */

/**
 * Returns 'true' if the submitted module name exists in the current active set, 'false' if not.
 */
LIB_EXTERN bool   checkModule(const char* moduleName);

/**
 * When any function returns an error condition, a longer description of the problem is stored in memory, and is obtainable with this function.  In most cases, this means that a call that returns a pointer returned 'NULL' (or 0).
 */
LIB_EXTERN char*  getLastError();

/**
 * When translating some other format to Antimony, elements that are unable to be translated are saved as warnings, retrievable with this function (returns NULL if no warnings present).
 */
LIB_EXTERN char*  getWarnings();

#ifndef NSBML
/**
 *  Returns the 'info' messages from libSBML. libAntimony always translates its modules into SBML to check for errors.  If SBML finds errors, libAntimony gives up, passes on the error message, and does not save the model.  However, libSBML may discover other things about your model it wants to tell you about, in 'info' and 'warning' messages.  Info messages are just things it found it thinks you might want to know; warning messages are things it found which it feels violates 'best practices' in biological modelling, but not to the extent that it feels you did something actually wrong.  Since Antimony is unitless, for example, you will always find warnings about how you didn't set any units.  This function returns the 'info' messages from libSBML.  If there are no info messages, returns an empty string.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 * @see getSBMLWarnings
 */
LIB_EXTERN char* getSBMLInfoMessages(const char* moduleName);

/**
 * Returns the 'warning' messages from libSBML.  If there are no warning messages (an unlikely occurrence), returns an empty string.
 * NOTE:  This function is unavailable when libAntimony is compiled with the '-NSBML' flag.
 * @see getSBMLInfoMessages
 */
LIB_EXTERN char* getSBMLWarnings(const char* moduleName);
#endif

/** \} */

/**
  * @name Modules
  */
/** \{ */
/**
 * Returns the number of modules in the current active set (the last file successfully loaded, or whichever file was returned to with 'revertTo').
 */
LIB_EXTERN unsigned long getNumModules();

/**
 * Returns an array of all the current module names.
 */
LIB_EXTERN char** getModuleNames();

/**
 * Returns the nth module name.  Returns NULL and sets an error if there is no such module n.
 */
LIB_EXTERN char*  getNthModuleName(unsigned long n);
/** \} */

/**
 * Returns the number of symbols defined to be in the interface of the given module.  In other words, if a module is defined 'module M(x, y, z)', this returns '3'.  (Modules with no interface symbols return '0'.)
 */
LIB_EXTERN unsigned long getNumSymbolsInInterfaceOf(const char* moduleName);

/**
 * Returns the names of the symbols defined to be in the interface of the given module.  In other words, if a module is defined 'module M(x, y, z)', this returns the list 'x, y, z'.  A module with no symbols defined in its interface would return a pointer to an empty string. 
 */
LIB_EXTERN char** getSymbolNamesInInterfaceOf(const char* moduleName);

/**
 * Returns the Nth symbol name defined to be in the interface of the given module.  If a module is defined 'module M(x, y, z)', calling this with n=0 returns "x".  If no such symbol is found, NULL is returned and an error is set.
 */
LIB_EXTERN char* getNthSymbolNameInInterfaceOf(const char* moduleName, unsigned long n);



/**
 * Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an 'is' construct, or through the use of a module's interface.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN unsigned long getNumReplacedSymbolNames(const char* moduleName);

/**
 * Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 * @see getNthReplacementSymbolPair
 */
LIB_EXTERN char*** getAllReplacementSymbolPairs(const char* moduleName);

/**
 * Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN char** getNthReplacementSymbolPair(const char* moduleName, unsigned long n);

/**
 * Returns the Nth symbol name that has been replaced by a new symbol name in the given module, through the use of an 'is' construct, or through the use of a module's interface.
 * @see getNthReplacementSymbolName
 * @see GetNumReplacedSymbolNames
 */
LIB_EXTERN char* getNthFormerSymbolName(const char* moduleName, unsigned long n);

/**
 * Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an 'is' construct, or through the use of a module's interface.
 * @see getNthFormerSymbolName
 * @see GetNumReplacedSymbolNames
 */
LIB_EXTERN char* getNthReplacementSymbolName(const char* moduleName, unsigned long n);



/**
 * Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an 'is' construct, or through the use of a module's interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  If an empty string is used as one of the submodule names, those synchronized variables that are not part of any submodule are searched for.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN unsigned long getNumReplacedSymbolNamesBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName);

/**
 * Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 * @see getNthReplacementSymbolPair
 */
LIB_EXTERN char*** getAllReplacementSymbolPairsBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);

/**
 * Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when 'is' is used, and when a module's 'interface' (the symbols listed in parentheses) is used.
 * @see getNthFormerSymbolName
 * @see getNthReplacementSymbolName
 */
LIB_EXTERN char** getNthReplacementSymbolPairBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);

/**
 * Returns the Nth symbol name that has been replaced by a new symbol name in the given module, through the use of an 'is' construct, or through the use of a module's interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.
 * @see getNthReplacementSymbolName
 * @see GetNumReplacedSymbolNames
 */
LIB_EXTERN char* getNthFormerSymbolNameBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);

/**
 * Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an 'is' construct, or through the use of a module's interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.
 * @see getNthFormerSymbolName
 * @see GetNumReplacedSymbolNames
 */
LIB_EXTERN char* getNthReplacementSymbolNameBetween(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n);




/**
  * @name Symbols and symbol information
  */
/** \{ */

/**
 * Returns the number of symbols of the given return type.  Useful when looping over the arrays in the subsequent functions.
 * @see get()
 */
LIB_EXTERN unsigned long getNumSymbolsOfType(const char* moduleName, return_type rtype);

/**
 * Returns the names of the symbols of the given return type.  (In SBML, these are the 'id's.)
 */
LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype);

/**
 * Returns the 'display names' of the symbols of the given return type.  (In SBML, these are the 'name's.)
 */
LIB_EXTERN char** getSymbolDisplayNamesOfType(const char* moduleName, return_type rtype);

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
LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype);


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
LIB_EXTERN char** getSymbolInitialAssignmentsOfType(const char* moduleName, return_type rtype);

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
LIB_EXTERN char** getSymbolAssignmentRulesOfType(const char* moduleName, return_type rtype);

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
LIB_EXTERN char** getSymbolRateRulesOfType(const char* moduleName, return_type rtype);

/**
 * Returns the compartments associated with the symbols of the given return type.  Note that unlike in SBML, any symbol of any type may have an associated compartment, including compartments themselves.  Rules about compartments in Antimony can be found in the <A class="el" target="_top" HREF="Tutorial.pdf">Tutorial.pdf</a> document included with this documentation.
 */
LIB_EXTERN char** getSymbolCompartmentsOfType(const char* moduleName, return_type rtype);

/**
 * Returns the name of the Nth symbol of the given type.  If no such symbol exists, NULL is returned and an error is set.  (In SBML, this is the 'id' of the element.)
 */
LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the 'display name' of the Nth symbol of the given type.  If no such symbol exists, NULL is returned and an error is set.  (In SBML, this is the 'name' of the element.)
 */
LIB_EXTERN char*  getNthSymbolDisplayNameOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the equation associated with the Nth symbol of the given type.  If no equation is set for the symbol in question, an empty string is returned.  If no symbol can be found, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the initial assignment associated with the Nth symbol of the given type.  If no initial assignment is set for the symbol in question, an empty string is returned.  If no symbol can be found, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolInitialAssignmentOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the assignment rule associated with the Nth symbol of the given type.  If no assignment rule is set for the symbol in question, an empty string is returned.  If no symbol can be found, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolAssignmentRuleOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the rate rule associated with the Nth symbol of the given type.  If no rate rule is set for the symbol in question, an empty string is returned.  If no symbol can be found, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthSymbolRateRuleOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the name of the compartment associated with the nth symbol of the given type.  If no compartment is explicitly set in the file, the string "default_compartment" is returned.  If no symbol can be found, NULL is returned and an error is set.
*/
LIB_EXTERN char*  getNthSymbolCompartmentOfType(const char* moduleName, return_type rtype, unsigned long n);

/**
 * Returns the most specific return type available for the given symbolName.  A symbol defined to be a gene, for example, will return 'allGenes' and not 'allReactions', though the symbol does indeed qualify as a reaction.
 */
LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName);

/**
 * Returns the type of the 'main' equation associated with the given symbolName.  All reactions will return 'formulaKINETIC', and all events will return 'formulaTRIGGER'.  All DNA elements that are not genes will return 'formulaASSIGNMENT', as DNA elements are defined by assignment rules and kinetic laws.  All other symbols will return 'formulaINITIAL' by default (i.e. in the case where no equation at all is associated with the symbol in question), and otherwise will return formulaINITIAL for symbols defined by initial assignments only, formulaASSIGNMENT for symbols defined by assignment rules, and formulaRATE for symbols defined by both initial assignments and rate rules (or just rate rules; it is valid though not simulatable to have a symbol with a rate rule but no initial assignment).  In the case of rate rules, the initial assignment is found in the 'Equation' associated with the symbol, and the rate rule is found in the 'RateRule' associated with the symbol.
 */
LIB_EXTERN formula_type getTypeOfEquationForSymbol(const char* moduleName, const char* symbolName);

/**
 * Returns the name of the compartment the given symbol is a member of.  In antimony, all symbols may have compartments, not just species.  If a symbol has no set compartment, and is not a member of a symbol with a set compartment, this will return "default_compartment"
 */
LIB_EXTERN char*   getCompartmentForSymbol(const char* moduleName, const char* symbolName);
/** \} */

/**
  * @name Reactions
  */
/** \{ */

/**
 * Returns the number of reactions (including genes) in the named module.  Useful when looping over all reactions in the arrays returned by subsequent functions.
 */
LIB_EXTERN unsigned long getNumReactions(const char* moduleName);

/**
 * Returns the number of reactants (species on the left side of the reaction) for the given reaction.  If no such reaction is present, '0' is returned and an error is set.  Sadly, if there are no reactants, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, most likely.
*/
LIB_EXTERN unsigned long getNumReactants(const char* moduleName, unsigned long rxn);

/**
 * Returns the number of products (species on the right side of the reaction) for the given reaction.  If no such reaction is present, '0' is returned and an error is set.  Sadly, if there are no products, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, too.
 */
LIB_EXTERN unsigned long getNumProducts(const char* moduleName, unsigned long rxn);

/**
 * Returns all the reactant names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumReactants' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getReactantNames(const char* moduleName);

/**
 * Returns an array of all the reactant names for the given reaction.  The length of the array can be obtained with 'getNumReactants'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthReactionReactantNames(const char* modulename, unsigned long rxn);

/**
 * Returns the mth reactant name of the mth reaction.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthReactionMthReactantName(const char* modulename, unsigned long rxn, unsigned long reactant);

/**
 * Returns all the product names for all reactions in the given module.  The dimensions of the included arrays can be found with 'getNumReactions' and 'getNumProducts' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getProductNames(const char* moduleName);

/**
 * Returns an array of all the product names for the given reaction.  The length of the array can be obtained with 'getNumProducts'.  If no such reaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthReactionProductNames(const char* modulename, unsigned long rxn);

/**
 * Returns the mth product name of the given reaction.  If no such reaction or product is present, NULL is returned and an error is set.
 */
LIB_EXTERN char*  getNthReactionMthProductName(const char* modulename, unsigned long rxn, unsigned long product);

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
LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, unsigned long rxn);

/**
 * Returns an array of the stoichiometries for the products of the Nth reaction in the module.  If no such reaction exists, an error is set and NULL is returned.
 */
LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, unsigned long rxn);

/**
 * Returns the stoichiometry for the Mth reactant of the Nth reaction in the module.  If no such reactant or reaction exists, an error is set and 0 is returned.
 */
LIB_EXTERN double getNthReactionMthReactantStoichiometries(const char* moduleName, unsigned long rxn, unsigned long reactant);

/**
 * Returns the stoichiometries for the Mth product of the Nth reaction in the module.  If no such product or reaction exists, an error is set and 0 is returned.
 */
LIB_EXTERN double getNthReactionMthProductStoichiometries(const char* moduleName, unsigned long rxn, unsigned long product);

/** \} */

/**
  * @name Interactions
  */
/** \{ */


/**
 * Returns the number of interactions in the named module.  Useful when looping over all interactions in the arrays returned by subsequent functions.
 */
LIB_EXTERN unsigned long getNumInteractions(const char* moduleName);

/**
 * Returns the number of interactors (species on the left side of the interaction) for the given interaction.  If no such interaction is present, '0' is returned and an error is set.  Sadly, if there are no interactors, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, most likely.
*/
LIB_EXTERN unsigned long getNumInteractors(const char* moduleName, unsigned long rxn);

/**
 * Returns the number of interactees (reactions on the right side of the interaction) for the given interaction.  If no such interaction is present, '0' is returned and an error is set.  Sadly, if there are no interactees, '0' is also returned, though no error is set.  So you'll have to keep track of this one on your own, too.
 */
LIB_EXTERN unsigned long getNumInteractees(const char* moduleName, unsigned long rxn);

/**
 * Returns all the interactor names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractors' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getInteractorNames(const char* moduleName);

/**
 * Returns an array of all the interactor names for the given interaction.  The length of the array can be obtained with 'getNumInteractors'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionInteractorNames(const char* modulename, unsigned long rxn);

/**
 * Returns the Mth interactor names for the given interaction.  If no such interactor or interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionMthInteractorNames(const char* modulename, unsigned long interaction, unsigned long interactor);

/**
 * Returns all the interactee names for all interactions in the given module.  The dimensions of the included arrays can be found with 'getNumInteractions' and 'getNumInteractees' (the array is not 'square'--each sub array may have a different length).
 */
LIB_EXTERN char*** getInteracteeNames(const char* moduleName);

/**
 * Returns an array of all the interactee names for the given interaction.  The length of the array can be obtained with 'getNumInteractees'.  If no such interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionInteracteeNames(const char* modulename, unsigned long rxn);

/**
 * Returns the Mth interactee name for the given interaction.  If no such interactee or interaction is present, NULL is returned and an error is set.
 */
LIB_EXTERN char**  getNthInteractionMthInteracteeName(const char* modulename, unsigned long interaction, unsigned long interactee);

/**
 * Returns an array of all the interaction dividers in the given module.  The length of the array can be obtained with 'getNumInteractions'.
 */
LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName);

/**
 * Returns the Nth interaction divider in the module.  If no such interaction is present, 0 is returned, which is 'rdBecomes, which is an invalid Interaction divider (since it's used for reactions instead).
 */
LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, unsigned long n);

/** \} */

/**
  * @name Stoichiometry matrix information
  */
/** \{ */

/**
 * Returns an N x M stoichiometry matrix where N is the number of reactions in the model, and M is the number of variable species (or 'floating species').
 */
LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName);

/**
 * The row labels for the stoichiometry matrix.  Is exactly the same as calling 'getSymbolNamesOfType(moduleName, varSpecies)', but provided here so you don't have to think about it.
 */
LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName);

/**
 * The column labels for the stoichiometry matrix.  Is exactly the same as calling 'getSymbolNamesOfType(moduleName, allReactions)' but provided here so you don't have to think about it.
 */
LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName);

/**
 * The number of rows in the stoichiometry matrix (or, the number of 'varSpecies').
 */
LIB_EXTERN unsigned long   getStoichiometryMatrixNumRows(const char* moduleName);

/**
 * The number of columns in the stoichiometry matrix (or, the number of 'allReactions').
 */
LIB_EXTERN unsigned long   getStoichiometryMatrixNumColumns(const char* moduleName);


/**
 * Returns the number of reactions (and hence reaction rates) in the module.  Useful for looping over all reaction rates in the following function.
 */
LIB_EXTERN unsigned long   getNumReactionRates(const char* moduleName);

/**
 * Returns an array of the reaction rates for the given module.  Is the same as 'getSymbolEquationsOfType(moduleName, allReactions)', but is provided for convenience.
 */
LIB_EXTERN char**   getReactionRates(const char* moduleName);

/**
 * Returns the reaction rate for the Nth reaction in the module.  If the reaction exists, but its reaction rate has not been set, returns an empty string.  If the reaction does not exist, an error is set, and NULL is returned.
 */
LIB_EXTERN char*    getNthReactionRate(const char* moduleName, unsigned long rxn);

/** \} */

/**
  * @name Events
  */
/** \{ */

/**
 * Returns the number of events in the given module.  Useful for subsequent functions that return arrays of information for all events.
 */
LIB_EXTERN unsigned long  getNumEvents(const char* moduleName);

/**
 * Returns the names of the events in the module.  Is the same as 'getSymbolNamesOfType(moduleName, allEvents)', but is provided for convenience.
 */
LIB_EXTERN char**  getEventNames(const char* moduleName);

/**
 * Returns the name of the nth event in the module.
 */
LIB_EXTERN char*   getNthEventName(const char* moduleName, unsigned long event);

/**
 * Returns the number of assignments stored in the given event.  Useful when looping through those assignements in functions below.
 */
LIB_EXTERN unsigned long  getNumAssignmentsForEvent(const char* moduleName, unsigned long event);

/**
 * Returns the trigger for the given event, as an equation that can be interpreted in a boolean context.
 */
LIB_EXTERN char*   getTriggerForEvent(const char* moduleName, unsigned long event);

/**
 * Returns the delay for the given event, as an equation (if present; if the event has no delay, "" is returned).
 */
LIB_EXTERN char*   getDelayForEvent(const char* moduleName, unsigned long event);

/**
 * Returns 'true' if the given event has a delay; 'false' otherwise.
 */
LIB_EXTERN bool    getEventHasDelay(const char* moduleName, unsigned long event);

/**
 * Each assignment for an event assigns a formula to a variable.  This function returns the variable in question for the given event and assignment.
 */
LIB_EXTERN char*   getNthAssignmentVariableForEvent(const char* moduleName, unsigned long event, unsigned long n);

/**
 * Each assignment for an event assigns a formula to a variable.  This function returns the in question in question for the given event and assignment.
 */
LIB_EXTERN char*   getNthAssignmentEquationForEvent(const char* moduleName, unsigned long event, unsigned long n);
/** \} */

/**
  * @name DNA strands
  */
/** \{ */


/**
 * Returns the number of unique DNA strands in the module, as defined in the Antimony documentation (or, the number of physical cassettes of DNA present in the module).  Useful in looping over the arrays returned by functions below.
 */
LIB_EXTERN unsigned long  getNumDNAStrands(const char* moduleName);

/**
 * Returns an array of DNA strand sizes for all strands in the module.  Useful for looping over the arrays returned by 'getDNAStrands'
 */
LIB_EXTERN unsigned long* getDNAStrandSizes(const char* moduleName);

/**
 * Returns just the size (in number of components) of the nth DNA strand in the given module.  If no such strand exists, sets an error and returns 0.  This is actually useful here, since all DNA strands otherwise have a size of at least 1.
 */
LIB_EXTERN unsigned long getSizeOfNthDNAStrand(const char* moduleName, unsigned long n);

/**
 * Returns an array of all DNA strands in the given module as lists of their components.  All components are either Operator objects or Gene objects, depending on whether they have an associated reaction.
 */
LIB_EXTERN char*** getDNAStrands(const char* moduleName);

/**
 * Returns an array of names of the components in the nth DNA strand in the given module.  If no such strand exists, sets an error and returns NULL.
 */
LIB_EXTERN char**  getNthDNAStrand(const char* moduleName, unsigned long n);

/**
 * Returns whether the given DNA strand was defined to be 'open' (that is, have an attachable end) at the upstream end (if 'upstream' is true) or at the downstream end (if 'upstream' is false).  This allows reproduction of a strand defined by "--X--Y--" vs. "X--Y", etc.
 */
LIB_EXTERN bool    getIsNthDNAStrandOpen(const char* moduleName, unsigned long n, bool upstream);

/**
 * Returns the sizes (in number of components) of all modular (separately-defined) DNA strands.  Modular strands may contain genes, operators, and other DNA strands.  Useful for looping over the strands in the array returned by getModularDNAStrands.
 */
LIB_EXTERN unsigned long  getNumModularDNAStrands(const char* moduleName);

/**
 * Returns an array of Modular DNA strand sizes for the given module.  Useful for looping over the components in the sub-arrays returned by getModularDNAStrands.
 */
LIB_EXTERN unsigned long* getModularDNAStrandSizes(const char* moduleName);

/**
 * Returns an array of strands, each of which has an array of the names of the components of that strand.  The components may be operators, genes, and other modular DNA strands. 
 */
LIB_EXTERN char*** getModularDNAStrands(const char* moduleName);

/**
 * Returns an array of names of the components in the nth modular DNA strand in the given module.  If no such strand exists, an error is set, and NULL is returned.
 */
LIB_EXTERN char**  getNthModularDNAStrand(const char* moduleName, unsigned long n);

/**
 * Returns whether the given modular DNA strand was defined to be 'open' (that is, have an attachable end) at the upstream end (if 'upstream' is true) or at the downstream end (if 'upstream' is false).  This allows reproduction of a strand defined by "--X--Y--" vs. "X--Y", etc.
 */
LIB_EXTERN bool    getIsNthModularDNAStrandOpen(const char* moduleName, unsigned long n, bool upstream);

/** \} */

/**
  * @name Memory management
  */
/** \{ */

/**
 * Frees all pointers handed to you by libAntimony.
 * All libAntimony functions above that return pointers return malloc'ed pointers that you now own.  If you wish, you can ignore this and never free anything, as long as you call 'freeAll' at the very end of your program.  If you free *anything* yourself, however, calling this function will cause the program to crash!  It won't know that you already freed that pointer, and will attempt to free it again.  So either keep track of all memory management yourself, or use this function after you're completely done.
 *
 * Note that this function only frees pointers handed to you by other antimony_api functions.  The models themselves are still in memory and are available.  (To clear that memory, use clearPreviousLoads() )
 */
LIB_EXTERN void freeAll();

/** \} */



END_C_DECLS

#endif //ANTIMONY_API_H

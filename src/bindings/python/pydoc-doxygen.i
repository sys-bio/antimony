%feature("docstring") loadFile "
 Load a file of any format libAntimony knows about (potentially Antimony, SBML, or CellML).  If all attempts fail, the errors from the attempt to read the file in the Antimony format are saved, so if the file is actually SBML or CellML, the error is likely to be \'but contains errors, the reported errors will be from the attempt to read it as Antimony, and a \'-1\' is returned.

 NOTE:  This function will not attempt to parse the file as SBML if libAntimony is compiled with the \'-NSBML\' flag, and will not attempt to parse the file as CellML if compiled with the \'-NCELLML\' flag.

 @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.

 @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.

 @see getLastError()
";


%feature("docstring") loadString "
 Load a string of any format libAntimony knows about (potentially Antimony, SBML, or CellML).  The first attempts to read the string as SBML, and if this results in an error, then reads it as Antimony.  If this, too, results in an error, the second error is saved, and a \'-1\' is returned.

 NOTE:  This function will not attempt to parse the string as SBML if libAntimony is compiled with the \'-NSBML\' flag, and will not attempt to parse the string as CellML if compiled with the \'-NCELLML\' flag.

 @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.

 @param model The model, in (potentially) Antimony, SBML, or CellML format.

 @see getLastError()
";


%feature("docstring") loadAntimonyFile "
 Loads a file and parses it as an Antimony file.  On an error, the error is saved, -1 is returned, and no information is stored.

 @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.

 @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.

 @see getLastError()
";


%feature("docstring") loadAntimonyString "
 Loads a string and parses it as an Antimony set of modules.  On an error, the error is saved, -1 is returned, and no information is stored.

 @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.

 @param model The model in Antimony format.

 @see getLastError()
";


%feature("docstring") loadSBMLFile "
 @brief Load a file known to be SBML.

 Loads a file and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.

 @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.

 @see getLastError()
";


%feature("docstring") loadSBMLString "
 @brief Load a string known to be SBML.

 Loads a string and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.

 @param model The model, in SBML format.

 @see getLastError()
";


%feature("docstring") loadSBMLStringWithLocation "
 @brief Load a string known to be SBML with its file location.

 Loads a string and parses it (using libSBML) as an SBML file.  On an error, the error is saved, -1 is returned, and no information is stored.  This function additionally allows you to set the location of the string, in case there are relative file references in the file (as there can be in some hierarchical models).
 @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.

 @param model The model, in SBML format.
 @param location The location of the file (i.e. \'file1.xml\' or \'/home/user/sbml/models/file.xml\')

 @see getLastError()
";


%feature("docstring") loadCellMLFile "
 @brief Load a file known to be CellML.

 Loads a file and parses it (using libCellML) as a CellML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 @return a long integer indicating the index of the file read and stored.  On an error, returns -1 and no information is stored.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NCELLML\' flag.

 @param filename The filename as a character string.  May be either absolute or relative to the directory the executable is being run from.

 @see getLastError()
";


%feature("docstring") loadCellMLString "
 @brief Load a string known to be CellML.

 Loads a string and parses it (using libCellML) as a CellML file.  On an error, the error is saved, -1 is returned, and no information is stored.
 @return a long integer indicating the index of the string read and stored.  On an error, returns -1 and no information is stored.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NCELLML\' flag.

 @param model The model, in CellML format.

 @see getLastError()
";


%feature("docstring") getNumFiles "
 @brief Returns the number of files loaded into memory so far.

 Every time \'load<file/string>\' is called successfully, the module(s) in those files are saved.  This function will tell you how many sets of modules from successful reads are resident in memory.
 @return The number of files currently stored in memory.
";


%feature("docstring") revertTo "
 Change the \'active\' set of modules to the ones from the given index (as received from \'load<file/string>\').  Attempting to revert to a negative or nonexistent index returns \'false\' and the previous active set of modules is retained.  A successful change return \'true\'.
";


%feature("docstring") clearPreviousLoads "
 Clears memory of all files loaded.  The next successful call to \'load<file/string>\' will return 0 as the first valid index.
";


%feature("docstring") addDirectory "
 Add a directory in which imported files may be found, and in which to look for a \'.antimony\' file (which contains rules about where to look locally for imported antimony and sbml files).
";


%feature("docstring") clearDirectories "
 Clears the list of directories added with the \'addDirectory\' function.
";


%feature("docstring") writeAntimonyFile "
 Writes out an antimony-formatted file containing the given module.  If no module name is given, all modules in the current set are returned.  If the module depends on any sub-modules, those modules are written out as well, also in the antimony format.  Returns 0 on failure (and sets an error), 1 on success.
";


%feature("docstring") getAntimonyString "
 Returns the same output as writeAntimonyFile, but to a char array instead of to a file.  Returns None on failure, and sets an error.
";


%feature("docstring") writeSBMLFile "
 Writes out a SBML-formatted XML file to the file indicated.  The output is \'flattened\', that is, all components of sub-modules are re-named and placed in a single model.  Returns the output of libSBML\'s \'writeSBML\', which \'Returns non-zero on success and zero if the filename could not be opened for writing.\'  An error indicating this is set on returning zero.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.

@see getSBMLString
";


%feature("docstring") getSBMLString "
 Returns the same output as writeSBMLFile, but to a char array instead of to a file.  The output is \'flattened\', that is, all components of sub-modules are re-named and placed in a single model.  Returns the output of libSBML\'s \'writeSBMLToString\', which \'Returns the string on success and None if one of the underlying parser components fail (rare).\'
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.

@see writeSBMLFile
";


%feature("docstring") writeCompSBMLFile "
 Writes out a SBML-formatted XML file to the file indicated, using the \'Hierarchichal Model Composition\' package.  This retains Antimony\'s modularity in the SBML format.  Returns the output of libSBML\'s \'writeSBML\', which \'Returns non-zero on success and zero if the filename could not be opened for writing.\'  An error indicating this is set on returning zero.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag, or if compiled without the USE_COMP flag.

@see getSBMLString
";


%feature("docstring") getCompSBMLString "
 Returns the same output as writeSBMLFile, but to a char array instead of to a file, using the \'Hierarchichal Model Composition\' package.  This retains Antimony\'s modularity in the SBML format.  Returns the output of libSBML\'s \'writeSBMLToString\', which \'Returns the string on success and None if one of the underlying parser components fail (rare).\'
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag, or if compiled without the USE_COMP flag.

@see writeSBMLFile
";


%feature("docstring") writeCellMLFile "
 Writes out a CellML-formatted XML file to the file indicated, retaining the same Antimony hierarchy using the CellML \'component\' hieararchy.  Returns one on success and zero on failure.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NCELLML\' flag.

@see getCellMLString
";


%feature("docstring") getCellMLString "
 Returns the same output as writeCellMLFile, but to a char array instead of to a file.  Returns the string on success (as translated to \'char\' from CellML\'s native \'wchar\') and None on failure.\'
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NCELLML\' flag.

@see writeCellMLToString
";


%feature("docstring") printAllDataFor "
 An example function that will print to stdout all the information in the given module.  This function probably isn\'t as useful to call as it is to examine and copy for your own purposes:  it only calls functions defined here in antimony_api.h.
";


%feature("docstring") checkModule "
 Returns \'true\' if the submitted module name exists in the current active set, \'false\' if not.
";


%feature("docstring") getLastError "
 When any function returns an error condition, a longer description of the problem is stored in memory, and is obtainable with this function.  In most cases, this means that a call that returns a pointer returned \'None\' (or 0).
";


%feature("docstring") getWarnings "
 When translating some other format to Antimony, elements that are unable to be translated are saved as warnings, retrievable with this function (returns None if no warnings present).  Warnings may also be generated by problems discovered in \'.antimony\' files.
";


%feature("docstring") getSBMLInfoMessages "
 Returns the \'info\' messages from libSBML. libAntimony always translates its modules into SBML to check for errors.  If SBML finds errors, libAntimony gives up, passes on the error message, and does not save the model.  However, libSBML may discover other things about your model it wants to tell you about, in \'info\' and \'warning\' messages.  Info messages are just things it found it thinks you might want to know; warning messages are things it found which it feels violates \'best practices\' in biological modelling, but not to the extent that it feels you did something actually wrong.  Since Antimony is unitless, for example, you will always find warnings about how you didn\'t set any units.  This function returns the \'info\' messages from libSBML.  If there are no info messages, returns an empty string.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.
 @see getSBMLWarnings
";


%feature("docstring") getSBMLWarnings "
 Returns the \'warning\' messages from libSBML.  If there are no warning messages (an unlikely occurrence), returns an empty string.
 NOTE:  This function is unavailable when libAntimony is compiled with the \'-NSBML\' flag.
 @see getSBMLInfoMessages
";


%feature("docstring") getNumModules "
 Returns the number of modules in the current active set (the last file successfully loaded, or whichever file was returned to with \'revertTo\').
";


%feature("docstring") getModuleNames "
 Returns an array of all the current module names.
";


%feature("docstring") getNthModuleName "
 Returns the nth module name.  Returns None and sets an error if there is no such module n.
";


%feature("docstring") getMainModuleName "
 Returns the \'main\' module name.  In Antimony, this is either the module marked by an asterisk (\'modelmainModel()\')  or the last module defined in the file.  In translated SBML models, this is the model child of thelt;sbmlgt; object.  In translated CellML models, this is the \'containing\' model that the translator creates to hold all the CellML components.  Returns None only if there are no modules at all.
";


%feature("docstring") getNumSymbolsInInterfaceOf "
 Returns the number of symbols defined to be in the interface of the given module.  In other words, if a module is defined \'module M(x, y, z)\', this returns \'3\'.  (Modules with no interface symbols return \'0\'.)
";


%feature("docstring") getSymbolNamesInInterfaceOf "
 Returns the names of the symbols defined to be in the interface of the given module.  In other words, if a module is defined \'module M(x, y, z)\', this returns the list \'x, y, z\'.  A module with no symbols defined in its interface would return a pointer to an empty string.
";


%feature("docstring") getNthSymbolNameInInterfaceOf "
 Returns the Nth symbol name defined to be in the interface of the given module.  If a module is defined \'module M(x, y, z)\', calling this with n=0 returns \'x\'.  If no such symbol is found, None is returned and an error is set.
";


%feature("docstring") getNumReplacedSymbolNames "
 Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
";


%feature("docstring") getAllReplacementSymbolPairs "
 Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when \'is\' is used, and when a module\'s \'interface\' (the symbols listed in parentheses) is used.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
 @see getNthReplacementSymbolPair
";


%feature("docstring") getNthReplacementSymbolPair "
 Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement.  These replacements are created when \'is\' is used, and when a module\'s \'interface\' (the symbols listed in parentheses) is used.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
";


%feature("docstring") getNthFormerSymbolName "
 Returns the Nth symbol name that has been replaced by a new symbol name in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface.
 @see getNthReplacementSymbolName
 @see GetNumReplacedSymbolNames
";


%feature("docstring") getNthReplacementSymbolName "
 Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface.
 @see getNthFormerSymbolName
 @see GetNumReplacedSymbolNames
";


%feature("docstring") getNumReplacedSymbolNamesBetween "
 Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  If an empty string is used as one of the submodule names, those synchronized variables that are not part of any submodule are searched for.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
";


%feature("docstring") getAllReplacementSymbolPairsBetween "
 Returns a list of pairs of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when \'is\' is used, and when a module\'s \'interface\' (the symbols listed in parentheses) is used.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
 @see getNthReplacementSymbolPair
";


%feature("docstring") getNthReplacementSymbolPairBetween "
 Returns the Nth pair of symbol names that have been synchronized with each other--the first the symbol that was replaced, and the second the symbol used as the replacement, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.  These replacements are created when \'is\' is used, and when a module\'s \'interface\' (the symbols listed in parentheses) is used.
 @see getNthFormerSymbolName
 @see getNthReplacementSymbolName
";


%feature("docstring") getNthFormerSymbolNameBetween "
 Returns the Nth symbol name that has been replaced by a new symbol name in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.
 @see getNthReplacementSymbolName
 @see GetNumReplacedSymbolNames
";


%feature("docstring") getNthReplacementSymbolNameBetween "
 Returns the Nth replacement symbol name of a symbol that has replaced a different symbol in the given module, through the use of an \'is\' construct, or through the use of a module\'s interface, between the given submodules, with the variable in the first submodule being the former variable name, and the variable in the second being the replacement variable name.
 @see getNthFormerSymbolName
 @see GetNumReplacedSymbolNames
";


%feature("docstring") getNumSymbolsOfType "
 Returns the number of symbols of the given return type.  Useful when looping over the arrays in the subsequent functions.
 @see get()
";


%feature("docstring") getSymbolNamesOfType "
 Returns the names of the symbols of the given return type.  (In SBML, these are the \'id\'s.)
";


%feature("docstring") getSymbolDisplayNamesOfType "
 Returns the \'display names\' of the symbols of the given return type.  (In SBML, these are the \'name\'s.)
";


%feature("docstring") getSymbolEquationsOfType "
 Returns the equations associated with the symbols of the given return type.
 - Species:                 The initial assignment or assignment rule for the species in question
 - Formulas and operators:  The initial assignment or assignment rule for the formula in question
 - Compartments:            The initial assignment or assignment rule for the compartment in question
 - DNA elements:            The assignment rule or reaction rate of the element in question (no DNA element is defined by an initial assignment or by a rate rule with an initial assignment)
 - DNA Strands:             The assignment rule or reaction rate for the last element of the strand
 - Reactions and genes:     The reaction rate
 - Events:                  The trigger condition
 - Interactions:            Nothing
 - Modules:                 Nothing

 For elements that could have either initial assignments or assignment rules, use getTypeOfEquationForSymbol, or just use getSymbolInitialAssignmentsOfType and getSymbolAssignmentRulesOfType explicitly.
";


%feature("docstring") getSymbolInitialAssignmentsOfType "
 Returns the equations associated with the initial assignment for symbols of the given return type.
 - Species:                 The initial assignment for the species in question
 - Formulas and operators:  The initial assignment of the formula in question
 - Compartments:            The initial assignment for the compartment

 - DNA Strands:             Nothing
 - Reactions and genes:     Nothing
 - Events:                  Nothing
 - Interactions:            Nothing
 - Modules:                 Nothing
";


%feature("docstring") getSymbolAssignmentRulesOfType "
 Returns the equations associated with the assignment rule for symbols of the given return type.
 - Species:                 The assignment rule for the species in question
 - Formulas and operators:  The assignment rule of the formula in question
 - Compartments:            The assignment rule for the compartment
 - DNA Strands:             The assignment rule or reaction rate at the end of the strand.
 - Reactions and genes:     The reaction rate (for consistency with DNA strands)

 - Events:                  Nothing
 - Interactions:            Nothing
 - Modules:                 Nothing
";


%feature("docstring") getSymbolRateRulesOfType "
 Returns the equations associated with the rate rule for symbols of the given return type.
 - Species:                 The rate rule for the species in question
 - Formulas and operators:  The rate rule of the formula in question
 - Compartments:            The rate rule for the compartment
 - DNA Strands:             The rate rule or reaction rate at the end of the strand.
 - Reactions and genes:     Nothing
 - Events:                  Nothing
 - Interactions:            Nothing
 - Modules:                 Nothing
";


%feature("docstring") getSymbolCompartmentsOfType "
 Returns the compartments associated with the symbols of the given return type.  Note that unlike in SBML, any symbol of any type may have an associated compartment, including compartments themselves.  Rules about compartments in Antimony can be found in the <A class=\'el\' target=\'_top\' HREF=\'Tutorial.pdf\'>Tutorial.pdf</a> document included with this documentation.
";


%feature("docstring") getNthSymbolNameOfType "
 Returns the name of the Nth symbol of the given type.  If no such symbol exists, None is returned and an error is set.  (In SBML, this is the \'id\' of the element.)
";


%feature("docstring") getNthSymbolDisplayNameOfType "
 Returns the \'display name\' of the Nth symbol of the given type.  If no such symbol exists, None is returned and an error is set.  (In SBML, this is the \'name\' of the element.)
";


%feature("docstring") getNthSymbolEquationOfType "
 Returns the equation associated with the Nth symbol of the given type.  If no equation is set for the symbol in question, an empty string is returned.  If no symbol can be found, None is returned and an error is set.
";


%feature("docstring") getNthSymbolInitialAssignmentOfType "
 Returns the initial assignment associated with the Nth symbol of the given type.  If no initial assignment is set for the symbol in question, an empty string is returned.  If no symbol can be found, None is returned and an error is set.
";


%feature("docstring") getNthSymbolAssignmentRuleOfType "
 Returns the assignment rule associated with the Nth symbol of the given type.  If no assignment rule is set for the symbol in question, an empty string is returned.  If no symbol can be found, None is returned and an error is set.
";


%feature("docstring") getNthSymbolRateRuleOfType "
 Returns the rate rule associated with the Nth symbol of the given type.  If no rate rule is set for the symbol in question, an empty string is returned.  If no symbol can be found, None is returned and an error is set.
";


%feature("docstring") getNthSymbolCompartmentOfType "
 Returns the name of the compartment associated with the nth symbol of the given type.  If no compartment is explicitly set in the file, the string \'default_compartment\' is returned.  If no symbol can be found, None is returned and an error is set.
";


%feature("docstring") getTypeOfSymbol "
 Returns the most specific return type available for the given symbolName.  A symbol defined to be a gene, for example, will return \'allGenes\' and not \'allReactions\', though the symbol does indeed qualify as a reaction.
";


%feature("docstring") getTypeOfEquationForSymbol "
 Returns the type of the \'main\' equation associated with the given symbolName.  All reactions will return \'formulaKINETIC\', and all events will return \'formulaTRIGGER\'.  All DNA elements that are not genes will return \'formulaASSIGNMENT\', as DNA elements are defined by assignment rules and kinetic laws.  All other symbols will return \'formulaINITIAL\' by default (i.e. in the case where no equation at all is associated with the symbol in question), and otherwise will return formulaINITIAL for symbols defined by initial assignments only, formulaASSIGNMENT for symbols defined by assignment rules, and formulaRATE for symbols defined by both initial assignments and rate rules (or just rate rules; it is valid though not simulatable to have a symbol with a rate rule but no initial assignment).  In the case of rate rules, the initial assignment is found in the \'Equation\' associated with the symbol, and the rate rule is found in the \'RateRule\' associated with the symbol.
";


%feature("docstring") getCompartmentForSymbol "
 Returns the name of the compartment the given symbol is a member of.  In antimony, all symbols may have compartments, not just species.  If a symbol has no set compartment, and is not a member of a symbol with a set compartment, this will return \'default_compartment\'
";


%feature("docstring") getNumReactions "
 Returns the number of reactions (including genes) in the named module.  Useful when looping over all reactions in the arrays returned by subsequent functions.
";


%feature("docstring") getNumReactants "
 Returns the number of reactants (species on the left side of the reaction) for the given reaction.  If no such reaction is present, \'0\' is returned and an error is set.  Sadly, if there are no reactants, \'0\' is also returned, though no error is set.  So you\'ll have to keep track of this one on your own, most likely.
";


%feature("docstring") getNumProducts "
 Returns the number of products (species on the right side of the reaction) for the given reaction.  If no such reaction is present, \'0\' is returned and an error is set.  Sadly, if there are no products, \'0\' is also returned, though no error is set.  So you\'ll have to keep track of this one on your own, too.
";


%feature("docstring") getReactantNames "
 Returns all the reactant names for all reactions in the given module.  The dimensions of the included arrays can be found with \'getNumReactions\' and \'getNumReactants\' (the array is not \'square\'--each sub array may have a different length).
";


%feature("docstring") getNthReactionReactantNames "
 Returns an array of all the reactant names for the given reaction.  The length of the array can be obtained with \'getNumReactants\'.  If no such reaction is present, None is returned and an error is set.
";


%feature("docstring") getNthReactionMthReactantName "
 Returns the mth reactant name of the mth reaction.  If no such reaction is present, None is returned and an error is set.
";


%feature("docstring") getProductNames "
 Returns all the product names for all reactions in the given module.  The dimensions of the included arrays can be found with \'getNumReactions\' and \'getNumProducts\' (the array is not \'square\'--each sub array may have a different length).
";


%feature("docstring") getNthReactionProductNames "
 Returns an array of all the product names for the given reaction.  The length of the array can be obtained with \'getNumProducts\'.  If no such reaction is present, None is returned and an error is set.
";


%feature("docstring") getNthReactionMthProductName "
 Returns the mth product name of the given reaction.  If no such reaction or product is present, None is returned and an error is set.
";


%feature("docstring") getReactantStoichiometries "
 Returns a two-dimensional array of the stoichiometries for all reactants in all reactions in the given module.
";


%feature("docstring") getProductStoichiometries "
 Returns a two-dimensional array of the stoichiometries for all products in all reactions in the given module.
";


%feature("docstring") getNthReactionReactantStoichiometries "
 Returns an array of the stoichiometries for the reactants of the Nth reaction in the module.  If no such reaction exists, an error is set and None is returned.
";


%feature("docstring") getNthReactionProductStoichiometries "
 Returns an array of the stoichiometries for the products of the Nth reaction in the module.  If no such reaction exists, an error is set and None is returned.
";


%feature("docstring") getNthReactionMthReactantStoichiometries "
 Returns the stoichiometry for the Mth reactant of the Nth reaction in the module.  If no such reactant or reaction exists, an error is set and 0 is returned.
";


%feature("docstring") getNthReactionMthProductStoichiometries "
 Returns the stoichiometries for the Mth product of the Nth reaction in the module.  If no such product or reaction exists, an error is set and 0 is returned.
";


%feature("docstring") getNumInteractions "
 Returns the number of interactions in the named module.  Useful when looping over all interactions in the arrays returned by subsequent functions.
";


%feature("docstring") getNumInteractors "
 Returns the number of interactors (species on the left side of the interaction) for the given interaction.  If no such interaction is present, \'0\' is returned and an error is set.  Sadly, if there are no interactors, \'0\' is also returned, though no error is set.  So you\'ll have to keep track of this one on your own, most likely.
";


%feature("docstring") getNumInteractees "
 Returns the number of interactees (reactions on the right side of the interaction) for the given interaction.  If no such interaction is present, \'0\' is returned and an error is set.  Sadly, if there are no interactees, \'0\' is also returned, though no error is set.  So you\'ll have to keep track of this one on your own, too.
";


%feature("docstring") getInteractorNames "
 Returns all the interactor names for all interactions in the given module.  The dimensions of the included arrays can be found with \'getNumInteractions\' and \'getNumInteractors\' (the array is not \'square\'--each sub array may have a different length).
";


%feature("docstring") getNthInteractionInteractorNames "
 Returns an array of all the interactor names for the given interaction.  The length of the array can be obtained with \'getNumInteractors\'.  If no such interaction is present, None is returned and an error is set.
";


%feature("docstring") getNthInteractionMthInteractorName "
 Returns the Mth interactor names for the given interaction.  If no such interactor or interaction is present, None is returned and an error is set.
";


%feature("docstring") getInteracteeNames "
 Returns all the interactee names for all interactions in the given module.  The dimensions of the included arrays can be found with \'getNumInteractions\' and \'getNumInteractees\' (the array is not \'square\'--each sub array may have a different length).
";


%feature("docstring") getNthInteractionInteracteeNames "
 Returns an array of all the interactee names for the given interaction.  The length of the array can be obtained with \'getNumInteractees\'.  If no such interaction is present, None is returned and an error is set.
";


%feature("docstring") getNthInteractionMthInteracteeName "
 Returns the Mth interactee name for the given interaction.  If no such interactee or interaction is present, None is returned and an error is set.
";


%feature("docstring") getInteractionDividers "
 Returns an array of all the interaction dividers in the given module.  The length of the array can be obtained with \'getNumInteractions\'.
";


%feature("docstring") getNthInteractionDivider "
 Returns the Nth interaction divider in the module.  If no such interaction is present, 0 is returned, which is \'rdBecomes, which is an invalid Interaction divider (since it\'s used for reactions instead).
";


%feature("docstring") getStoichiometryMatrix "
 Returns an N x M stoichiometry matrix where N is the number of reactions in the model, and M is the number of variable species (or \'floating species\').
";


%feature("docstring") getStoichiometryMatrixRowLabels "
 The row labels for the stoichiometry matrix.  Is exactly the same as calling \'getSymbolNamesOfType(moduleName, varSpecies)\', but provided here so you don\'t have to think about it.
";


%feature("docstring") getStoichiometryMatrixColumnLabels "
 The column labels for the stoichiometry matrix.  Is exactly the same as calling \'getSymbolNamesOfType(moduleName, allReactions)\' but provided here so you don\'t have to think about it.
";


%feature("docstring") getStoichiometryMatrixNumRows "
 The number of rows in the stoichiometry matrix (or, the number of \'varSpecies\').
";


%feature("docstring") getStoichiometryMatrixNumColumns "
 The number of columns in the stoichiometry matrix (or, the number of \'allReactions\').
";


%feature("docstring") getNumReactionRates "
 Returns the number of reactions (and hence reaction rates) in the module.  Useful for looping over all reaction rates in the following function.
";


%feature("docstring") getReactionRates "
 Returns an array of the reaction rates for the given module.  Is the same as \'getSymbolEquationsOfType(moduleName, allReactions)\', but is provided for convenience.
";


%feature("docstring") getNthReactionRate "
 Returns the reaction rate for the Nth reaction in the module.  If the reaction exists, but its reaction rate has not been set, returns an empty string.  If the reaction does not exist, an error is set, and None is returned.
";


%feature("docstring") getNumEvents "
 Returns the number of events in the given module.  Useful for subsequent functions that return arrays of information for all events.
";


%feature("docstring") getEventNames "
 Returns the names of the events in the module.  Is the same as \'getSymbolNamesOfType(moduleName, allEvents)\', but is provided for convenience.
";


%feature("docstring") getNthEventName "
 Returns the name of the nth event in the module.
";


%feature("docstring") getNumAssignmentsForEvent "
 Returns the number of assignments stored in the given event.  Useful when looping through those assignements in functions below.
";


%feature("docstring") getTriggerForEvent "
 Returns the trigger for the given event, as an equation that can be interpreted in a boolean context.
";


%feature("docstring") getDelayForEvent "
 Returns the delay for the given event, as an equation (if present; if the event has no delay, \'\' is returned.  If no such module or event is present, None is returned and an error is set.).
";


%feature("docstring") getEventHasDelay "
 Returns \'true\' if the given event has a delay; \'false\' otherwise.
";


%feature("docstring") getPriorityForEvent "
 Returns the priority for the given event, as an equation (if present; if the event has no priority, \'\' is returned.  If no such module or event is present, None is returned and an error is set.).
";


%feature("docstring") getEventHasPriority "
 Returns \'true\' if the given event has a priority; \'false\' otherwise.
";


%feature("docstring") getPersistenceForEvent "
 Returns the value of the persistence flag for the given event (default is \'false\').  Unable to return an error if there is no such event or module, so will simply return \'false\' in those situations, as well.
";


%feature("docstring") getT0ForEvent "
 Returns the value at time 0 for the given event trigger (default is \'true\').  Unable to return an error if there is no such event or module, so will simply return \'true\' in those situations, as well.
";


%feature("docstring") getFromTriggerForEvent "
 Returns the value of the \'fromTrigger\' flag for the given event trigger (default is \'true\').  Unable to return an error if there is no such event or module, so will simply return \'true\' in those situations, as well.
";


%feature("docstring") getNthAssignmentVariableForEvent "
 Each assignment for an event assigns a formula to a variable.  This function returns the variable in question for the given event and assignment.
";


%feature("docstring") getNthAssignmentEquationForEvent "
 Each assignment for an event assigns a formula to a variable.  This function returns the in question in question for the given event and assignment.
";


%feature("docstring") getNumDNAStrands "
 Returns the number of unique DNA strands in the module, as defined in the Antimony documentation (or, the number of physical cassettes of DNA present in the module).  Useful in looping over the arrays returned by functions below.
";


%feature("docstring") getDNAStrandSizes "
 Returns an array of DNA strand sizes for all strands in the module.  Useful for looping over the arrays returned by \'getDNAStrands\'
";


%feature("docstring") getSizeOfNthDNAStrand "
 Returns just the size (in number of components) of the nth DNA strand in the given module.  If no such strand exists, sets an error and returns 0.  This is actually useful here, since all DNA strands otherwise have a size of at least 1.
";


%feature("docstring") getDNAStrands "
 Returns an array of all DNA strands in the given module as lists of their components.  All components are either Operator objects or Gene objects, depending on whether they have an associated reaction.
";


%feature("docstring") getNthDNAStrand "
 Returns an array of names of the components in the nth DNA strand in the given module.  If no such strand exists, sets an error and returns None.
";


%feature("docstring") getIsNthDNAStrandOpen "
 Returns whether the given DNA strand was defined to be \'open\' (that is, have an attachable end) at the upstream end (if \'upstream\' is true) or at the downstream end (if \'upstream\' is false).  This allows reproduction of a strand defined by \'--X--Y--\' vs. \'X--Y\', etc.
";


%feature("docstring") getNumModularDNAStrands "
 Returns the sizes (in number of components) of all modular (separately-defined) DNA strands.  Modular strands may contain genes, operators, and other DNA strands.  Useful for looping over the strands in the array returned by getModularDNAStrands.
";


%feature("docstring") getModularDNAStrandSizes "
 Returns an array of Modular DNA strand sizes for the given module.  Useful for looping over the components in the sub-arrays returned by getModularDNAStrands.
";


%feature("docstring") getModularDNAStrands "
 Returns an array of strands, each of which has an array of the names of the components of that strand.  The components may be operators, genes, and other modular DNA strands.
";


%feature("docstring") getNthModularDNAStrand "
 Returns an array of names of the components in the nth modular DNA strand in the given module.  If no such strand exists, an error is set, and None is returned.
";


%feature("docstring") getIsNthModularDNAStrandOpen "
 Returns whether the given modular DNA strand was defined to be \'open\' (that is, have an attachable end) at the upstream end (if \'upstream\' is true) or at the downstream end (if \'upstream\' is false).  This allows reproduction of a strand defined by \'--X--Y--\' vs. \'X--Y\', etc.
";


%feature("docstring") freeAll "
 Frees all pointers handed to you by libAntimony.
 All libAntimony functions above that return pointers return malloc\'ed pointers that you now own.  If you wish, you can ignore this and never free anything, as long as you call \'freeAll\' at the very end of your program.  If you freeanything yourself, however, calling this function will cause the program to crash!  It won\'t know that you already freed that pointer, and will attempt to free it again.  So either keep track of all memory management yourself, or use this function after you\'re completely done.

 Note that this function only frees pointers handed to you by other antimony_api functions.  The models themselves are still in memory and are available.  (To clear that memory, use clearPreviousLoads() )
";


%feature("docstring") OStream "
 Wrapper class for the C++ standard streams <code>cout</code>,
 <code>cerr</code>, and <code>clog</code>.

 A few libSBML methods accept an argument for indicating where to send
 text string output.  An example is the SBMLDocument.printErrors() method. However, the methods use C++ style streams and not Java
 stream objects.  The OStream object exists to bridge the Java and
 underlying native implementation.  It is a simple wrapper around the
 underlying stream object and provides a few basic methods for
 manipulating it.
";


%feature("docstring") OFStream "
 Wrapper class for the C++ standard file stream <code>ofstream</code>.

 The C++ <code>ofstream</code> (\'output file stream\') provides an
 interface for writing data to files as output streams.  This class,
 OFStream, wraps the C++ <code>ofstream</code> and provides an OStream
 interface to it.  The file to be associated with the stream can be
 specified as a parameter to the constructors in this class.

 This class may be useful because some libSBML methods accept an argument
 for indicating where to send text string output.  An example is the
 SBMLDocument.printErrors() method.  The methods use C++ style streams
 and not Java stream objects.  The OStream object exists to bridge the
 Java and underlying native implementation.  It is a simple wrapper
 around the underlying stream object and provides a few basic methods for
 manipulating it.
";


%feature("docstring") OStringStream "
 Wrapper class for the C++ standard stream <code>ostringstream</code>.
 
 The C++ <code>ostringstream</code> (\'output string stream class\')
 provides an interface to manipulating strings as if they were output
 streams.  This class class, OStringStream, wraps the
 <code>ostringstream</code> and provides an OStream interface to it.
 
 This class may be useful because some libSBML methods accept an argument
 for indicating where to send text string output.  An example is the 
 SBMLDocument.printErrors() method.  The methods use
 C++ style streams and not Java stream objects.  The OStream object
 exists to bridge the Java and underlying native implementation.  It is a
 simple wrapper around the underlying stream object and provides a few
 basic methods for manipulating it.
";


%feature("docstring") OStream::OStream "
 Creates a new OStream object with one of standard output stream objects.
 
 @param sot a value from the StdOSType enumeration(COUT, CERR, or CLOG) 
 indicating the type of stream to create.
";


%feature("docstring") OStream::get_ostream "
 Returns the stream object.
 <p>
 @return the stream object
";


%feature("docstring") OStream::endl "
 Writes an end-of-line character on this tream.
";


%feature("docstring") OFStream::OFStream "
 Creates a new OFStream object for a file.
 <p>
 This opens the given file @p filename with the @p is_append flag
 (default is <code>false</code>), and creates an OFStream object
 instance that associates the file\'s content with an OStream object.
 <p>
 @param filename the name of the file to open
 @param is_append whether to open the file for appending (default:
 <code>false</code>, meaning overwrite the content instead)
 
 @if notcpp @htmlinclude warn-default-args-in-docs.html @endif
";


%feature("docstring") OFStream::open "
 Opens a file and associates this stream object with it.
 <p>
 This method opens a given file @p filename with the given
 @p is_append flag (whose default value is <code>false</code>),
 and associates <i>this</i> stream object with the file\'s content.
 <p>
 @param filename the name of the file to open
 @param is_append whether to open the file for appending (default:
 <code>false</code>, meaning overwrite the content instead)
 
 @if notcpp @htmlinclude warn-default-args-in-docs.html @endif
";


%feature("docstring") OFStream::close "
 Closes the file currently associated with this stream object.
";


%feature("docstring") OFStream::is_open "
 Returns <code>true</code> if this stream object is currently
 associated with a file.
 <p>
 @return <code>true</code> if the stream object is currently
 associated with a file, <code>false</code> otherwise
";


%feature("docstring") OStringStream::OStringStream "
 Creates a new OStringStream object
";


%feature("docstring") OStringStream::str "
 This method has multiple variants that differ in the arguments
 they accept.  Each is described separately below.

 <hr>
 Method variant with the following signature:
 <pre class='signature'>str()</pre>

 Returns the copy of the string object currently assosiated 
 with this <code>ostringstream</code> buffer.
 <p>
 @return a copy of the string object for this stream
     

 <hr>
 Method variant with the following signature:
 <pre class='signature'>str(string s)</pre>

 Sets string @p s to the string object currently assosiated with
 this stream buffer.
 <p>
 @param s the string to write to this stream
";



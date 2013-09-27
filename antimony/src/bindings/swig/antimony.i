/**
 * \file    antimony.i
 * \brief   Language-independent SWIG directives for wrapping libantimony
 * \author  Lucian Smith, based on libsbml code from Ben Bornstein and Ben Kovitz
 * 
 */

%module(directors="1") libantimony

#pragma SWIG nowarn=473,401,844

%pragma(java) moduleclassmodifiers="
/**
  * Wrapper class for global methods and constants defined by libSBML.
  * <p>
  * <em style='color: #555'>
  * This class of objects is defined by libantimony only and has no direct
  * equivalent in terms of Antimony components.
  * </em>
  * <p>
  * In the C++ version of libantimony, models are parsed and stored in a 
  * global object, which can then be queried by subsequent calls to
  * antimony API functions.  However, all returned elements become the
  * property of the caller.
  */
public class"


%{
#include "../../antimony_api.h"
%}

/**
 *
 * Includes a language specific interface file.
 *
 */

%include local.i

/**
 * Disable warnings about const/non-const versions of functions.
 */
#pragma SWIG nowarn=516


/**
 * The following methods will create new objects.  To prevent memory
 * leaks we must inform SWIG of this.
 */

%typemap(newfree) char * "free($1);";

%newobject getAntimonyString;
%newobject getSBMLString;
%newobject getCompSBMLString;
%newobject getCellMLString;
%newobject getLastError;
%newobject getWarnings;
%newobject getSBMLInfoMessages;
%newobject getSBMLWarnings;
%newobject getModuleNames;
%newobject getNthModuleName;
%newobject getMainModuleName;
%newobject getSymbolNamesInInterfaceOf;
%newobject getNthSymbolNameInInterfaceOf;
%newobject getAllReplacementSymbolPairs;
%newobject getNthReplacementSymbolPair;
%newobject getNthFormerSymbolName;
%newobject getNthReplacementSymbolName;
%newobject getAllReplacementSymbolPairsBetween;
%newobject getNthReplacementSymbolPairBetween;
%newobject getNthFormerSymbolNameBetween;
%newobject getNthReplacementSymbolNameBetween;
%newobject getSymbolNamesOfType;
%newobject getSymbolDisplayNamesOfType;
%newobject getSymbolEquationsOfType;
%newobject getSymbolInitialAssignmentsOfType;
%newobject getSymbolAssignmentRulesOfType;
%newobject getSymbolRateRulesOfType;
%newobject getSymbolCompartmentsOfType;
%newobject getNthSymbolDisplayNameOfType;
%newobject getNthSymbolEquationOfType;
%newobject getNthSymbolInitialAssignmentOfType;
%newobject getNthSymbolAssignmentRuleOfType;
%newobject getNthSymbolRateRuleOfType;
%newobject getNthSymbolCompartmentOfType;
%newobject getCompartmentForSymbol;
%newobject getReactantNames;
%newobject getNthReactionReactantNames;
%newobject getNthReactionMthReactantName;
%newobject getProductNames;
%newobject getNthReactionProductNames;
%newobject getNthReactionMthProductName;
%newobject getReactantStoichiometries;
%newobject getProductStoichiometries;
%newobject getNthReactionReactantStoichiometries;
%newobject getNthReactionProductStoichiometries;
%newobject getInteractorNames;
%newobject getNthInteractionInteractorNames;
%newobject getNthInteractionMthInteractorName;
%newobject getInteracteeNames;
%newobject getNthInteractionInteracteeNames;
%newobject getNthInteractionMthInteracteeName;
%newobject getInteractionDividers;
%newobject getStoichiometryMatrix;
%newobject getStoichiometryMatrixRowLabels;
%newobject getStoichiometryMatrixColumnLabels;
%newobject getReactionRates;
%newobject getNthReactionRate;
%newobject getEventNames;
%newobject getNthEventName;
%newobject getTriggerForEvent;
%newobject getDelayForEvent;
%newobject getPriorityForEvent;
%newobject getNthAssignmentVariableForEvent;
%newobject getNthAssignmentEquationForEvent;
%newobject getDNAStrandSizes;
%newobject getDNAStrands;
%newobject getNthDNAStrand;
%newobject getModularDNAStrandSizes;
%newobject getModularDNAStrands;
%newobject getNthModularDNAStrand;

/**
 * Ignore the 'freeAll' function, as SWIG handles the new returned objects above
 */

%ignore freeAll;


/**
 * Wrap these files.
 */

%include antimony_api.h
%include enums.h

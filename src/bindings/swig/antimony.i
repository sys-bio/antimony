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
#include "../../antimony_api_cpp.h"
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

#ifndef NSBML
%newobject getSBMLString;
%newobject getSBMLInfoMessages;
%newobject getSBMLWarnings;
#endif

#ifndef USE_COMP
%newobject getCompSBMLString;
#endif

#ifndef NCELLML
%newobject getCellMLString;
#endif

%newobject getAntimonyString;
%newobject getLastError;
%newobject getWarnings;
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
 * Ignore 'freeAll', and all functions that return vectors, as SWIG cannot convert them properly.
 */

%ignore freeAll;
%ignore getModuleNames;
%ignore getSymbolNamesInInterfaceOf;
%ignore getAllReplacementSymbolPairs;
%ignore getNthReplacementSymbolPair;
%ignore getAllReplacementSymbolPairsBetween;
%ignore getNthReplacementSymbolPairBetween;
%ignore getSymbolNamesOfType;
%ignore getSymbolDisplayNamesOfType;
%ignore getSymbolEquationsOfType;
%ignore getSymbolInitialAssignmentsOfType;
%ignore getSymbolAssignmentRulesOfType;
%ignore getSymbolRateRulesOfType;
%ignore getSymbolCompartmentsOfType;
%ignore getReactantNames;
%ignore getNthReactionReactantNames;
%ignore getProductNames;
%ignore getNthReactionProductNames;
%ignore getReactantStoichiometries;
%ignore getProductStoichiometries;
%ignore getInteractorNames;
%ignore getNthInteractionInteractorNames;
%ignore getInteracteeNames;
%ignore getNthInteractionInteracteeNames;
%ignore getInteractionDividers;
%ignore getStoichiometryMatrix;
%ignore getStoichiometryMatrixRowLabels;
%ignore getStoichiometryMatrixColumnLabels;
%ignore getReactionRates;
%ignore getEventNames;
%ignore getDNAStrandSizes;
%ignore getDNAStrands;
%ignore getNthDNAStrand;
%ignore getModularDNAStrandSizes;
%ignore getModularDNAStrands;
%ignore getNthModularDNAStrand;

%rename(getModuleNames) getModuleNamesAsVector;
%rename(getSymbolNamesInInterfaceOf) getSymbolNamesInInterfaceOfAsVector;
%rename(getAllReplacementSymbolPairs) getAllReplacementSymbolPairsAsVector;
%rename(getNthReplacementSymbolPair) getNthReplacementSymbolPairAsVector;
%rename(getAllReplacementSymbolPairsBetween) getAllReplacementSymbolPairsBetweenAsVector;
%rename(getNthReplacementSymbolPairBetween) getNthReplacementSymbolPairBetweenAsVector;
%rename(getSymbolNamesOfType) getSymbolNamesOfTypeAsVector;
%rename(getSymbolDisplayNamesOfType) getSymbolDisplayNamesOfTypeAsVector;
%rename(getSymbolEquationsOfType) getSymbolEquationsOfTypeAsVector;
%rename(getSymbolInitialAssignmentsOfType) getSymbolInitialAssignmentsOfTypeAsVector;
%rename(getSymbolAssignmentRulesOfType) getSymbolAssignmentRulesOfTypeAsVector;
%rename(getSymbolRateRulesOfType) getSymbolRateRulesOfTypeAsVector;
%rename(getSymbolCompartmentsOfType) getSymbolCompartmentsOfTypeAsVector;
%rename(getReactantNames) getReactantNamesAsVector;
%rename(getNthReactionReactantNames) getNthReactionReactantNamesAsVector;
%rename(getProductNames) getProductNamesAsVector;
%rename(getNthReactionProductNames) getNthReactionProductNamesAsVector;
%rename(getReactantStoichiometries) getReactantStoichiometriesAsVector;
%rename(getProductStoichiometries) getProductStoichiometriesAsVector;
%rename(getInteractorNames) getInteractorNamesAsVector;
%rename(getNthInteractionInteractorNames) getNthInteractionInteractorNamesAsVector;
%rename(getInteracteeNames) getInteracteeNamesAsVector;
%rename(getNthInteractionInteracteeNames) getNthInteractionInteracteeNamesAsVector;
#%rename(getInteractionDividers) getInteractionDividersAsVector;
%ignore getInteractionDividersAsVector;
%rename(getStoichiometryMatrix) getStoichiometryMatrixAsVector;
%rename(getStoichiometryMatrixRowLabels) getStoichiometryMatrixRowLabelsAsVector;
%rename(getStoichiometryMatrixColumnLabels) getStoichiometryMatrixColumnLabelsAsVector;
%rename(getReactionRates) getReactionRatesAsVector;
%rename(getEventNames) getEventNamesAsVector;
%rename(getDNAStrandSizes) getDNAStrandSizesAsVector;
%rename(getDNAStrands) getDNAStrandsAsVector;
%rename(getNthDNAStrand) getNthDNAStrandAsVector;
%rename(getModularDNAStrandSizes) getModularDNAStrandSizesAsVector;
%rename(getModularDNAStrands) getModularDNAStrandsAsVector;
%rename(getNthModularDNAStrand) getNthModularDNAStrandAsVector;

%include "std_vector.i"
%include "std_string.i"
#%include "std_exception.i"

// Instantiate templates used by example
namespace std {
   %template(UnsignedLongVector) vector<unsigned long>;
   %template(DoubleVector) vector<double>;
   %template(DoubleVectorVector) vector<vector<double> >;
   %template(StringVector) vector<string>;
   %template(StringVectorVector) vector<vector<string> >;
#   %template(RDTypeVector) vector<rd_type>;
}

/**
 * Wrap these files.
 */

%include antimony_api.h
%include antimony_api_cpp.h
%include enums.h

#include <assert.h>

#include "enums.h"
#include "typex.h"
#include "stringx.h"

using namespace std;
using namespace libsbml;

extern bool CaselessStrCmp(bool caseless, const string& lhs, const string& rhs);

bool IsReaction(const var_type vtype)
{
  switch(vtype) {
  case varReactionUndef:
  case varReactionGene:
    return true;
  case varInteraction:
  case varSpeciesUndef:
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varModule:
  case varEvent:
  case varCompartment:
  case varStrand:
  case varUndefined:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsInteraction(const rd_type rdtype)
{
  switch(rdtype) {
  case rdBecomes:
  case rdBecomesIrreversibly:
    return false;
  case rdActivates:
  case rdInhibits:
  case rdInfluences:
    return true;
  }
  assert(false); //uncaught type
  return false;
}

bool IsSpecies(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
    return true;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
  case varFormulaOperator:
  case varFormulaUndef:
  case varDNA:
  case varModule:
  case varEvent:
  case varCompartment:
  case varStrand:
  case varUndefined:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsDNA(const var_type vtype)
{
  switch(vtype) {
  case varReactionGene:
  case varFormulaOperator:
  case varDNA:
    return true;
  case varSpeciesUndef:
  case varReactionUndef:
  case varInteraction:
  case varFormulaUndef:
  case varModule:
  case varEvent:
  case varCompartment:
  case varStrand:
  case varUndefined:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool CanHaveRateRule(const var_type vtype)
{
  switch(vtype) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
    return true;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
  case varModule:
  case varEvent:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught type
  return false;
}

bool CanHaveAssignmentRule(const var_type vtype)
{
  switch(vtype) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varCompartment:
  case varUndefined:
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return true;
  case varModule:
  case varEvent:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught type
  return false;
}

bool CanBeInReaction(const var_type vtype)
{
  switch(vtype) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varUndefined:
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return true;
  case varCompartment:
  case varModule:
  case varEvent:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught type
  return false;
}

bool HasOrIsFormula(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
  case varFormulaOperator:
  case varFormulaUndef:
  case varDNA:
  case varCompartment:
  case varUnitDefinition:
  case varConstraint:
    return true;
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
  case varModule:
  case varEvent: //Not for the purposes of Jarnac, at any rate.
  case varStrand:
  case varUndefined:
  case varDeleted:
  case varSboTermWrapper:
  case varUncertWrapper:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsSpan(const uncert_type utype)
{
  switch (utype) {
  case unCoefficientOfVariation:
  case unKurtosis:
  case unMean:
  case unMedian:
  case unMode:
  case unSampleSize:
  case unSkewness:
  case unStandardDeviation:
  case unStandardError:
  case unVariance:
  case unDistribution:
  case unExternalParameter:
  case unUnknown:
    return false;
  case unConfidenceInterval:
  case unCredibleInterval:
  case unInterquartileRange:
  case unRange:
    return true;
  }
  assert(false);
  return false;
}

string RDToString(rd_type type)
{
  switch(type) {
  case rdBecomes:    return "->";
  case rdBecomesIrreversibly:  return "=>";
  case rdActivates:  return "-o";
  case rdInhibits:   return "-|";
  case rdInfluences: return "-(";
  }
  assert(false); //Forgot to add reaction type;
  return "";
}

string VarTypeToString(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
    return "Species";
  case varFormulaUndef:
    return "Formula";
  case varReactionUndef:
    return "Reaction";
  case varReactionGene:
    return "Gene";
  case varInteraction:
    return "Interaction";
  case varFormulaOperator:
    return "Operator";
  case varDNA:
    return "DNA";
  case varModule:
    return "Module";
  case varEvent:
    return "Event";
  case varCompartment:
    return "Compartment";
  case varStrand:
    return "Strand";
  case varUnitDefinition:
    return "Unit Definition";
  case varDeleted:
    return "Deleted element";
  case varUndefined:
    return "Undefined";
  case varConstraint:
    return "Constraint";
  case varSboTermWrapper:
    return "SBO Term";
  case varUncertWrapper:
    return "Uncertainty parameter";
  }
  assert(false);
  return "";
}

string VarTypeToAntimony(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
    return "species ";
  case varFormulaUndef:
    return "formula ";
  case varReactionUndef:
    return "reaction ";
  case varReactionGene:
    return "gene ";
  case varInteraction:
    return "reaction ";
  case varFormulaOperator:
    return "operator ";
  case varDNA:
    return "DNA ";
  case varEvent:
    return "event ";
  case varCompartment:
    return "compartment ";
  case varUnitDefinition:
    return "unit ";
  case varDeleted:
    return "delete ";
  case varConstraint:
    return "constraint ";
  case varStrand:
  case varModule:
  case varUndefined:
  case varSboTermWrapper:
  case varUncertWrapper:
    assert(false);
    return "undefinable_type";
    break;
  }
  assert(false); //uncaught type
  return "undeclared_type";
}

string ReturnTypeToString(const return_type rtype)
{
  switch(rtype) {
  case allSymbols:
    return "all symbols";
  case allSpecies:
    return "all species (boundary and not)";
  case allFormulas:
    return "all formulas (generic, constant or not)";
  case varSpecies:
    return "variable species (generic)";
  case varFormulas:
    return "variable formula or equation";
  case allDNA:
    return "all DNA (genes and operators)";
  case allGenes:
    return "all genes (DNA that has an associated reaction)";
  case allOperators:
    return "all operators (DNA with no associated reaction)";
  case allReactions:
    return "Reaction (generic)";
  case allInteractions:
    return "Interaction (generic)";
  case allEvents:
    return "Event";
  case allCompartments:
    return "all compartments (constant and variable)";
  case varOperators:
    return "variable DNA (operator)";
  case varCompartments:
    return "variable-sized compartment";
  case allUnknown:
    return "Unknown type";
  case constSpecies:
    return "constant/boundary species (generic)";
  case constFormulas:
    return "constant formula or equation";
  case constOperators:
    return "constant DNA (operator)";
  case constCompartments:
    return "constant-sized compartment";
  case subModules:
    return "a submodule";
  case expandedStrands:
    return "expanded DNA strand";
  case modularStrands:
    return "modular DNA strand";
  case allUnits:
    return "units";
  case allDeleted:
    return "deleted submodel elements";
  case allConstraints:
    return "constraints";
  }
  assert(false); //uncaught type
  return "Uncaught type";
}

string FormulaTypeToString(const formula_type ftype)
{
  switch(ftype) {
  case formulaINITIAL:
    return "Initial";
  case formulaASSIGNMENT:
    return "Assignment rule";
  case formulaRATE:
    return "Rate rule";
  case formulaKINETIC:
    return "Kinetic law";
  case formulaTRIGGER:
    return "Trigger";
  }
  assert(false); //uncaught type
  return "uncaught type";
}

string UncertTypeToString(const uncert_type utype)
{
  switch(utype) {
  case unCoefficientOfVariation:
    return "coefficientOfVariation";
  case unKurtosis:
    return "kurtosis";
  case unMean:
    return "mean";
  case unMedian:
    return "median";
  case unMode:
    return "mode";
  case unSampleSize:
    return "sampleSize";
  case unSkewness:
    return "skewness";
  case unStandardDeviation:
    return "standardDeviation";
  case unStandardError:
    return "standardError";
  case unVariance:
    return "variance";
  case unConfidenceInterval:
    return "confidenceInterval";
  case unCredibleInterval:
    return "credibleInterval";
  case unInterquartileRange:
    return "interquartileRange";
  case unRange:
    return "range";
  case unDistribution:
    return "distribution";
  case unExternalParameter:
    return "externalParameter";
  case unUnknown:
    return "unknown";
  }
  assert(false); //uncaught type
  return "uncaught type";
}

uncert_type UncertStringToType(const string& uncert)
{
  if (CaselessStrCmp(false, uncert, "coefficientOfVariation")) {
    return unCoefficientOfVariation;
  }
  if (CaselessStrCmp(false, uncert, "kurtosis")) {
    return unKurtosis;
  }
  if (CaselessStrCmp(false, uncert, "mean")) {
    return unMean;
  }
  if (CaselessStrCmp(false, uncert, "median")) {
    return unMedian;
  }
  if (CaselessStrCmp(false, uncert, "mode")) {
    return unMode;
  }
  if (CaselessStrCmp(false, uncert, "sampleSize")) {
    return unSampleSize;
  }
  if (CaselessStrCmp(false, uncert, "skewness")) {
    return unSkewness;
  }
  if (CaselessStrCmp(false, uncert, "standardDeviation")) {
    return unStandardDeviation;
  }
  if (CaselessStrCmp(false, uncert, "stdev")) {
    return unStandardDeviation;
  }
  if (CaselessStrCmp(false, uncert, "standardError")) {
    return unStandardError;
  }
  if (CaselessStrCmp(false, uncert, "variance")) {
    return unVariance;
  }
  if (CaselessStrCmp(false, uncert, "confidenceInterval")) {
    return unConfidenceInterval;
  }
  if (CaselessStrCmp(false, uncert, "credibleInterval")) {
    return unCredibleInterval;
  }
  if (CaselessStrCmp(false, uncert, "interquartileRange")) {
    return unInterquartileRange;
  }
  if (CaselessStrCmp(false, uncert, "range")) {
    return unRange;
  }
  if (CaselessStrCmp(false, uncert, "distribution")) {
    return unDistribution;
  }
  if (CaselessStrCmp(false, uncert, "externalParameter")) {
    return unExternalParameter;
  }
  return unUnknown;
}

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
UncertType_t UncertTypeToSBML(const uncert_type utype)
{
  switch (utype) {
  case unDistribution:
    return DISTRIB_UNCERTTYPE_DISTRIBUTION;
  case unExternalParameter:
      return DISTRIB_UNCERTTYPE_EXTERNALPARAMETER;
  case unCoefficientOfVariation:
      return DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION;
  case unKurtosis:
      return DISTRIB_UNCERTTYPE_KURTOSIS;
  case unMean:
    return DISTRIB_UNCERTTYPE_MEAN;
  case unMedian:
    return DISTRIB_UNCERTTYPE_MEDIAN;
  case unMode:
    return DISTRIB_UNCERTTYPE_MODE;
  case unSampleSize:
    return DISTRIB_UNCERTTYPE_SAMPLESIZE;
  case unSkewness:
    return DISTRIB_UNCERTTYPE_SKEWNESS;
  case unStandardDeviation:
    return DISTRIB_UNCERTTYPE_STANDARDDEVIATION;
  case unStandardError:
    return DISTRIB_UNCERTTYPE_STANDARDERROR;
  case unVariance:
    return DISTRIB_UNCERTTYPE_VARIANCE;
  case unConfidenceInterval:
    return DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL;
  case unCredibleInterval:
    return DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL;
  case unInterquartileRange:
    return DISTRIB_UNCERTTYPE_INTERQUARTILERANGE;
  case unRange:
    return DISTRIB_UNCERTTYPE_RANGE;
  case unUnknown:
    return DISTRIB_UNCERTTYPE_INVALID;
  }
  assert(false);
  return DISTRIB_UNCERTTYPE_INVALID;
}

uncert_type SBMLToUncertType(const UncertType_t utype)
{
  switch (utype) {
  case DISTRIB_UNCERTTYPE_DISTRIBUTION:
    return unDistribution;
  case DISTRIB_UNCERTTYPE_EXTERNALPARAMETER:
    return unExternalParameter;
  case DISTRIB_UNCERTTYPE_COEFFIENTOFVARIATION:
    return unCoefficientOfVariation;
  case DISTRIB_UNCERTTYPE_KURTOSIS:
    return unKurtosis;
  case DISTRIB_UNCERTTYPE_MEAN:
    return unMean;
  case DISTRIB_UNCERTTYPE_MEDIAN:
    return unMedian;
  case DISTRIB_UNCERTTYPE_MODE:
    return unMode;
  case DISTRIB_UNCERTTYPE_SAMPLESIZE:
    return unSampleSize;
  case DISTRIB_UNCERTTYPE_SKEWNESS:
    return unSkewness;
  case DISTRIB_UNCERTTYPE_STANDARDDEVIATION:
    return unStandardDeviation;
  case DISTRIB_UNCERTTYPE_STANDARDERROR:
    return unStandardError;
  case DISTRIB_UNCERTTYPE_VARIANCE:
    return unVariance;
  case DISTRIB_UNCERTTYPE_CONFIDENCEINTERVAL:
    return unConfidenceInterval;
  case DISTRIB_UNCERTTYPE_CREDIBLEINTERVAL:
    return unCredibleInterval;
  case DISTRIB_UNCERTTYPE_INTERQUARTILERANGE:
    return unInterquartileRange;
  case DISTRIB_UNCERTTYPE_RANGE:
    return unRange;
  case DISTRIB_UNCERTTYPE_INVALID:
    return unUnknown;
  }
  assert(false);
  return unUnknown;
}
#endif

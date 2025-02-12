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
  case varLayoutWrapper:
  case varStoichiometry:
  case varAlgebraicRule:
  case varLayoutColorEtc:
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
  case varLayoutWrapper:
  case varStoichiometry:
  case varAlgebraicRule:
  case varLayoutColorEtc:
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
  case varLayoutWrapper:
  case varStoichiometry:
  case varAlgebraicRule:
  case varLayoutColorEtc:
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
  case varStoichiometry:
  case varLayoutColorEtc:
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
  case varLayoutWrapper:
  case varAlgebraicRule:
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
  case varStoichiometry:
  case varLayoutColorEtc:
      return true;
  case varModule:
  case varEvent:
  case varStrand:
  case varUnitDefinition:
  case varDeleted:
  case varConstraint:
  case varSboTermWrapper:
  case varUncertWrapper:
  case varLayoutWrapper:
  case varAlgebraicRule:
    return false;
  }
  assert(false); //uncaught type
  return false;
}

bool CanHaveAlgebraicRule(const var_type vtype)
{
    switch (vtype) {
    case varAlgebraicRule:
    case varUndefined:
    case varLayoutColorEtc:
        return true;
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varSpeciesUndef:
    case varCompartment:
    case varStoichiometry:
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
    case varLayoutWrapper:
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
  case varLayoutColorEtc:
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
  case varLayoutWrapper:
  case varStoichiometry:
  case varAlgebraicRule:
      return false;
  }
  assert(false); //uncaught type
  return false;
}

bool CanBeStoichiometry(const var_type vtype)
{
    switch (vtype) {
    case varFormulaUndef:
    case varFormulaOperator:
    case varUndefined:
    case varStoichiometry:
    case varLayoutColorEtc:
        return true;
    case varReactionUndef:
    case varReactionGene:
    case varInteraction:
    case varSpeciesUndef:
    case varDNA:
    case varCompartment:
    case varModule:
    case varEvent:
    case varStrand:
    case varUnitDefinition:
    case varDeleted:
    case varConstraint:
    case varSboTermWrapper:
    case varUncertWrapper:
    case varLayoutWrapper:
    case varAlgebraicRule:
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
  case varStoichiometry:
  case varLayoutColorEtc:
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
  case varLayoutWrapper:
  case varAlgebraicRule: //Again, not for Jarnac, which doesn't do algebraic rules.
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

bool IsPair(const layout_type ltype)
{
    switch (ltype) {
    case lt_x:
    case lt_y:
    case lt_height:
    case lt_width:
    case lt_color:
    case lt_font:
    case lt_fontsize:
    case lt_fontcolor:
    case lt_fontstyle:
    case lt_fontweight:
    case lt_linewidth:
    case lt_linecolor:
    case lt_shape:
    case lt_unknown:
        return false;
    case lt_position:
    case lt_size:
    case lt_reactionArc:
    case lt_sourceSink:
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
  case varLayoutWrapper:
      return "Layout or render parameter";
  case varStoichiometry:
      return "Stoichiometry";
  case varAlgebraicRule:
      return "Algebraic Rule";
  case varLayoutColorEtc:
      return "Color or shape name";
  }
  assert(false);
  return "";
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
  case allStoichiometries:
    return "stoichiometries";
  case allAlgebraicRules:
      return "algebraic rules";
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
  case formulaALGEBRAIC:
    return "Algebraic rule";
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

string LayoutTypeToString(const layout_type ltype)
{
    switch (ltype) {
    case lt_position:
        return "position";
    case lt_x:
        return "x";
    case lt_y:
        return "y";
    case lt_size:
        return "size";
    case lt_height:
        return "height";
    case lt_width:
        return "width";
    case lt_color:
        return "color";
    case lt_font:
        return "font";
    case lt_fontsize:
        return "fontSize";
    case lt_fontcolor:
        return "fontColor";
    case lt_fontstyle:
        return "fontStyle";
    case lt_fontweight:
        return "fontWeight";
    case lt_linewidth:
        return "lineWidth";
    case lt_linecolor:
        return "lineColor";
    case lt_shape:
        return "shape";
    case lt_reactionArc:
        return "reaction arc";
    case lt_sourceSink:
        return "--";
    case lt_unknown:
        return "unknown";
    }
    assert(false); //uncaught type
    return "uncaught type";
}

layout_type LayoutStringToType(const string& ltype)
{
    if (CaselessStrCmp(true, ltype, "position") ||
        CaselessStrCmp(true, ltype, "pos")) {
        return lt_position;
    }
    if (CaselessStrCmp(true, ltype, "x")) {
        return lt_x;
    }
    if (CaselessStrCmp(true, ltype, "y")) {
        return lt_y;
    }
    if (CaselessStrCmp(true, ltype, "size")) {
        return lt_size;
    }
    if (CaselessStrCmp(true, ltype, "height")) {
        return lt_height;
    }
    if (CaselessStrCmp(true, ltype, "width")) {
        return lt_width;
    }
    if (CaselessStrCmp(true, ltype, "color")) {
        return lt_color;
    }
    if (CaselessStrCmp(true, ltype, "fillcolor")) {
        return lt_color;
    }
    if (CaselessStrCmp(true, ltype, "font")) {
        return lt_font;
    }
    if (CaselessStrCmp(true, ltype, "fontsize")) {
        return lt_fontsize;
    }
    if (CaselessStrCmp(true, ltype, "fontcolor")) {
        return lt_fontcolor;
    }
    if (CaselessStrCmp(true, ltype, "fontweight")) {
        return lt_fontweight;
    }
    if (CaselessStrCmp(true, ltype, "fontstyle")) {
        return lt_fontstyle;
    }
    if (CaselessStrCmp(true, ltype, "linethickness")) {
        return lt_linewidth;
    }
    if (CaselessStrCmp(true, ltype, "linewidth")) {
        return lt_linewidth;
    }
    if (CaselessStrCmp(true, ltype, "strokewidth")) {
        return lt_linewidth;
    }
    if (CaselessStrCmp(true, ltype, "borderwidth")) {
        return lt_linewidth;
    }
    if (CaselessStrCmp(true, ltype, "linecolor")) {
        return lt_linecolor;
    }
    if (CaselessStrCmp(true, ltype, "shape")) {
        return lt_shape;
    }
    //NOTE:  no way to convert any string to 'reaction arc'; that's defined by RXNID.SPECID
    return lt_unknown;
}

bool isValidFontStyle(const std::string& ftype)
{
    if (CaselessStrCmp(true, ftype, "bold")) {
        return true;
    }
    if (CaselessStrCmp(true, ftype, "italic")) {
        return true;
    }
    if (CaselessStrCmp(true, ftype, "normal")) {
        return true;
    }
    if (CaselessStrCmp(true, ftype, "bold_italic")) {
        return true;
    }
    return false;
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

string ArcTypeToString(const arc_type type)
{
    switch (type) {
    case at_spec:
        return "species_pos";
    case at_rxn:
        return "rxn_pos";
    case at_b1:
        return "b1";
    case at_b2:
        return "b2";
    case at_none:
        return "position";
    }
    assert(false); //uncaught type
    return "unknown_type";
}


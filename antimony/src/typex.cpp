#include <assert.h>

#include "enums.h"
#include "typex.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

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
    return false;
  }
  assert(false); //uncaught vtype
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

string DistributionTypeToString(const distribution_type dtype)
{
  switch(dtype) {
  case distUNKNOWN:
    return "Unknown";
  case distNORMAL:
    return "normal";
  case distTRUNCNORMAL:
    return "truncatedNormal";
  case distUNIFORM:
    return "uniform";
  case distEXPONENTIAL:
    return "exponential";
  case distTRUNCEXPONENTIAL:
    return "truncatedExponential";
  case distGAMMA:
    return "gamma";
  case distTRUNCGAMMA:
    return "truncatedGamma";
  case distPOISSON:
    return "poisson";
  case distTRUNCPOISSON:
    return "truncatedPoisson";
  }
  assert(false); //uncaught type
  return "uncaught type";
}

distribution_type StringToDistributionType(const string& name)
{
  if (CaselessStrCmp(name, "normal"))
    return distNORMAL;
  if (CaselessStrCmp(name, "truncatedNormal"))
    return distTRUNCNORMAL;
  if (CaselessStrCmp(name, "uniform"))
    return distUNIFORM;
  if (CaselessStrCmp(name, "exponential"))
    return distEXPONENTIAL;
  if (CaselessStrCmp(name, "truncatedExponential"))
    return distTRUNCEXPONENTIAL;
  if (CaselessStrCmp(name, "gamma"))
    return distGAMMA;
  if (CaselessStrCmp(name, "truncatedGamma"))
    return distTRUNCGAMMA;
  if (CaselessStrCmp(name, "poisson"))
    return distPOISSON;
  if (CaselessStrCmp(name, "truncatedPoisson"))
    return distTRUNCPOISSON;
  return distUNKNOWN;
}

string GetArgumentStringForDistribution(const distribution_type dtype)
{
  switch(dtype) {
  case distUNKNOWN:
    return "";
  case distNORMAL:
    return "mean, stddev,";
  case distTRUNCNORMAL:
    return "mean, stddev, lowlimit, uplimit,";
  case distUNIFORM:
    return "minimum, maximum,";
  case distEXPONENTIAL:
    return "rate,";
  case distTRUNCEXPONENTIAL:
    return "rate, lowlimit, uplimit,";
  case distGAMMA:
    return "mean, stddev,";
  case distTRUNCGAMMA:
    return "mean, stddev, lowlimit, uplimit,";
  case distPOISSON:
    return "rate,";
  case distTRUNCPOISSON:
    return "rate, lowlimit, uplimit,";
  }
  assert(false); //Uncaught type
  return "";
}

std::string GetURIForDistribution(const distribution_type dtype)
{
  switch(dtype) {
  case distUNKNOWN:
    return "http://uncertml.org/distributions/";
  case distNORMAL:
  case distTRUNCNORMAL:
    return "http://uncertml.org/distributions/normal";
  case distUNIFORM:
    return "http://uncertml.org/distributions/uniform";
  case distEXPONENTIAL:
  case distTRUNCEXPONENTIAL:
    return "http://uncertml.org/distributions/exponential";
  case distGAMMA:
  case distTRUNCGAMMA:
    return "http://uncertml.org/distributions/gamma";
  case distPOISSON:
  case distTRUNCPOISSON:
    return "http://uncertml.org/distributions/poisson";
  }
  assert(false); //Uncaught type
  return "http://uncertml.org/distributions/";
}

std::string GetWikipediaURIForDistribution(const distribution_type dtype)
{
  switch(dtype) {
  case distUNKNOWN:
    return "http://en.wikipedia.org/wiki/Distribution_(mathematics)";
  case distNORMAL:
    return "http://en.wikipedia.org/wiki/Normal_distribution";
  case distTRUNCNORMAL:
    return "http://en.wikipedia.org/wiki/Truncated_normal_distribution";
  case distUNIFORM:
    return "http://en.wikipedia.org/wiki/Uniform_distribution";
  case distEXPONENTIAL:
  case distTRUNCEXPONENTIAL:
    return "http://en.wikipedia.org/wiki/Exponential_distribution";
  case distGAMMA:
  case distTRUNCGAMMA:
    return "http://en.wikipedia.org/wiki/Gamma_distribution";
  case distPOISSON:
  case distTRUNCPOISSON:
    return "http://en.wikipedia.org/wiki/Poisson_distribution";
  }
  assert(false); //Uncaught type
  return "http://en.wikipedia.org/wiki/Distribution_(mathematics)";
}

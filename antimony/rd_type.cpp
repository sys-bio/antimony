#include "rd_type.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

std::string RDToString(rd_type type)
{
  switch(type) {
  case rdBecomes:    return "->";
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
  case varSpeciesProtein:
    return "Protein";
  case varFormulaUndef:
    return "Formula";
  case varReactionUndef:
    return "Reaction";
  case varReactionGene:
    return "Gene";
  case varInteraction:
    return "Interaction";
  case varFormulaPromoter:
    return "Promoter";
  case varFormulaOperator:
    return "Operator";
  case varDNA:
    return "DNA";
  case varModule:
    return "Module";
  case varUndefined:
    return "Undefined";
  }
  assert(false);
  return "";
}

var_type StringToVarType(const string& name)
{
  if (CaselessStrCmp(name,"Species")) {
    return varSpeciesUndef;
  }
  if (CaselessStrCmp(name,"Protein")) {
    return varSpeciesProtein;
  }
  if (CaselessStrCmp(name,"Formula")) {
    return varFormulaUndef;
  }
  if (CaselessStrCmp(name,"Promoter")) {
    return varFormulaPromoter;
  }
  if (CaselessStrCmp(name,"Operator")) {
    return varFormulaOperator;
  }
  if (CaselessStrCmp(name,"DNA")) {
    return varDNA;
  }
  if (CaselessStrCmp(name,"Reaction")) {
    return varReactionUndef;
  }
  if (CaselessStrCmp(name,"Gene")) {
    return varReactionGene;
  }
  if (CaselessStrCmp(name,"Interaction")) {
    return varInteraction;
  }
  if (CaselessStrCmp(name,"Module")) {
    return varModule;
  }
  if (CaselessStrCmp(name,"Undefined")) {
    return varUndefined;
  }
  assert(false); //uncaught var type
  return varUndefined;
}

bool IsReaction(const var_type vtype)
{
  switch(vtype) {
  case varReactionUndef:
  case varReactionGene:
    return true;
  case varInteraction:
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
  case varModule:
  case varUndefined:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsInteraction(const rd_type rdtype)
{
  switch(rdtype) {
  case rdBecomes:
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
  case varSpeciesProtein:
    return true;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varFormulaUndef:
  case varDNA:
  case varModule:
  case varUndefined:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsDNA(const var_type vtype)
{
  switch(vtype) {
  case varReactionGene:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
    return true;
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varReactionUndef:
  case varInteraction:
  case varFormulaUndef:
  case varModule:
  case varUndefined:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool HasOrIsFormula(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varFormulaUndef:
  case varDNA:
    return true;
  case varReactionGene:
  case varReactionUndef:
  case varInteraction:
  case varModule:
  case varUndefined:
    return false;
  }
  assert(false); //uncaught vtype
  return false;
}

bool IsReaction(const string& name)
{
  return IsReaction(StringToVarType(name));
}

bool IsSpecies(const string& name)
{
  return IsSpecies(StringToVarType(name));
}

string ReturnTypeToString(return_type rtype)
{
  switch(rtype) {
  case allSymbols:
    return "all symbols";
  case allSpecies:
    return "all species (generic, boundary and not)";
  case allFormulas:
    return "all formulas (generic, constant or not)";
  case varSpecies:
    return "variable species (generic)";
  case varProteins:
    return "variable species (protein)";
  case varFormulas:
    return "variable formula or equation";
  case varAnyDNA:
    return "variable DNA (generic)";
  case varPromoters:
    return "variable DNA (promoter)";
  case varOperators:
    return "variable DNA (operator)";
  case varGenes:
    return "variable DNA (gene; also a reaction)";
  case allReactions:
    return "Reaction (generic)";
  case allInteractions:
    return "Interaction (generic)";
  case allUnknown:
    return "Unknown type";
  case constSpecies:
    return "constant/boundary species (generic)";
  case constProteins:
    return "constant/boundary species (protein)";
  case constFormulas:
    return "constant formula or equation";
  case constAnyDNA:
    return "constant DNA (generic)";
  case constPromoters:
    return "constant DNA (promoter)";
  case constOperators:
    return "constant DNA (operator)";
  case constGenes:
    return "constant DNA (gene; also a reaction)";
  case subModules:
    return "a submodule";
  }
  assert(false); //uncaught type
  return "Uncaught type";
}


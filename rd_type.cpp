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

bool IsSpecies(const var_type vtype)
{
  switch(vtype) {
  case varSpeciesUndef:
  case varSpeciesProtein:
    return true;
  case varReactionUndef:
  case varReactionGene:
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


#include <cassert>
#include <string>
#include <vector>
#include <map>
#include "variable.h"
#include "formula.h"
#include "registry.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

#ifndef NSBML
#include "sbmlx.h"
#include "sbml/math/FormulaFormatter.h"
#if LIBSBML_VERSION >= 50900
#include "sbml/math/L3FormulaFormatter.h"
#endif

string getNameFromSBMLObject(const SBase* sbml, string basename)
{
  string name = sbml->getId();
  if (name == "") {
    name = sbml->getName();
    //Names can have spaces, so...
    while (name.find(" ") != string::npos) {
      name.replace(name.find(" "), 1, "_");
    }
  }
  if (name=="") {
    long num=0;
    Variable* foundvar = NULL;
    do {
      char charnum[50];
      sprintf(charnum, "%li", num);
      num++;
      name = basename;
      name += charnum;
      vector<string> fullname;
      fullname.push_back(name);
      foundvar = g_registry.CurrentModule()->GetVariable(fullname);
    } while (foundvar != NULL);
  }
  assert(name != "");
  if (name != sbml->getId()) {
    SBase* varsbml = const_cast<SBase*>(sbml);
    varsbml->setId(name);
  }
  return name;
}

void matchNamesToTypes(ASTNode *node)  
{
  if (node->getType() == AST_NAME_TIME) {
    node->setName("time");
  }
  if (node->getType() == AST_NAME_AVOGADRO) {
    node->setName("avogadro");
  }
  if (node->getType() == AST_FUNCTION_DELAY) {
    node->setName("delay");
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    matchNamesToTypes(node->getChild(c));
  }
}


string parseASTNodeToString(const ASTNode* ASTform, bool carat) {
  if (ASTform==NULL) return "";
  ASTNode clone(*ASTform);
  matchNamesToTypes(&clone);
  if (carat) {
    powerToCarat(&clone);
  }

#if LIBSBML_VERSION >= 50900
  char* formula = SBML_formulaToL3String(&clone);
#else
  char* formula = SBML_formulaToString(&clone);
#endif
  string ret = formula;
#ifndef WIN32
  free(formula);
#endif
  return ret;
}


void matchTypesToNames(ASTNode_t* node)  
{
  if (node->isOperator() == false && node->isNumber() == false) {
    if (string(node->getName()) == "time") {
      node->setType(AST_NAME_TIME);
    }
    if (string(node->getName()) == "avogadro") {
      node->setType(AST_NAME_AVOGADRO);
    }
    if (string(node->getName()) == "delay") {
      node->setType(AST_FUNCTION_DELAY);
    }
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    matchTypesToNames(node->getChild(c));
  }
}

ASTNode* parseStringToASTNode(const string& formula)
{
  L3ParserSettings l3ps;
  l3ps.setParseCollapseMinus(true);
  l3ps.setParseLog(L3P_PARSE_LOG_AS_LN);
  ASTNode* rootnode = SBML_parseL3FormulaWithSettings(formula.c_str(), &l3ps);
  if (rootnode == NULL) {
    g_registry.SetError(SBML_getLastParseL3Error());
    return NULL;
  }
  if (formula.find("time") != string::npos ||
      formula.find("avogadro") != string::npos ||
      formula.find("delay") != string::npos) {
    matchTypesToNames(rootnode);
  }
  return rootnode;
}

void caratToPower(ASTNode* node)
{
  if (node->getType() == AST_POWER) {
    node->setType(AST_FUNCTION_POWER);
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    caratToPower(node->getChild(c));
  }
}

void powerToCarat(ASTNode* node)
{
  if (node->getType() == AST_FUNCTION_POWER) {
    node->setType(AST_POWER);
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    powerToCarat(node->getChild(c));
  }
}

void GetUnitNames(ASTNode* astn, set<string>& names)
{
  if (astn==NULL) return;
  if (astn->isSetUnits()) {
    names.insert(astn->getUnits());
  }
  for (unsigned int c=0; c<astn->getNumChildren(); c++) {
    GetUnitNames(astn->getChild(c), names);
  }
  return;
}

void GetFunctionNames(ASTNode* astn, set<string>& names)
{
  if (astn==NULL) return;
  if (astn->getType() == AST_FUNCTION) {
    names.insert(astn->getName());
  }
  for (unsigned int c=0; c<astn->getNumChildren(); c++) {
    GetFunctionNames(astn->getChild(c), names);
  }
  return;
}

double GetValueFrom(ASTNode* astn)
{
  switch (astn->getType()) {
  case AST_RATIONAL:
  case AST_REAL:
  case AST_REAL_E:
    return astn->getReal();
  case AST_INTEGER:
    return astn->getInteger();
  default:
    assert(false);
    return 0; 
  }
}
UnitDef GetUnitDefFrom(const UnitDefinition* unitdefinition, string modulename)
{
  UnitDef ret(unitdefinition->getId(), modulename);
  ret.ClearComponents();
  for (unsigned int ue=0; ue<unitdefinition->getNumUnits(); ue++) {
    const Unit* unit = unitdefinition->getUnit(ue);
    ret.AddUnitElement(unit);
  }
  return ret;
}

#endif


//SBML models might have variable names in them that are reserved keywords in Antimony (like 'compartment', to take a huge example).  FixName fixes this so that you can output readable Antimony again.
bool FixName(string& name)
{
  while (name.size() && name[0] == ' ') {
    name.erase(0, 1);
  }
  while (name.size() && name[name.size()-1] == ' ') {
    name.erase(name.size()-1, 1);
  }
  const char* keywords[] = {
  "DNA",
  "at",
  "compartment",
  "const",
  "delete",
  "end",
  "event",
  "ext",
  "formula",
  "function",
  "gene",
  "has",
  "import",
  "in",
  "is",
  "model",
  "module",
  "operator",
  "reaction",
  "species",
  "var",

  "abs"
  , "acos"
  , "arccos"
  , "acosh"
  , "arccosh"
  , "acot"
  , "arccot"
  , "acoth"
  , "arccoth"
  , "acsc"
  , "arccsc"
  , "acsch"
  , "arccsch"
  , "asec"
  , "arcsec"
  , "asech"
  , "arcsech"
  , "asin"
  , "arcsin"
  , "arcsinh"
  , "atan"
  , "arctan"
  , "atanh"
  , "arctanh"
  , "ceil"
  , "ceiling"
  , "cos"
  , "cosh"
  , "cot"
  , "coth"
  , "csc"
  , "csch"
  , "delay"
  , "exp"
  , "factorial"
  , "floor"
  , "log"
  , "ln"
  , "log10"
  , "piecewise"
  , "power"
  , "pow"
  , "sqr"
  , "sqrt"
  , "root"
  , "sec"
  , "sech"
  , "sin"
  , "sinh"
  , "tan"
  , "tanh"
  , "and"
  , "not"
  , "or"
  , "xor"
  , "eq"
  , "equals"
  , "geq"
  , "gt"
  , "leq"
  , "lt"
  , "neq"
  , "divide"
  , "minus"
  , "plus"
  , "times"

  , "true"  
  , "false"  
  , "pi"  
  , "exponentiale" 
  , "avogadro"  
  , "time"
  , "inf"  
  , "infinity"  
  , "nan"  
  , "notanumber"
  };
  for (size_t kw=0; kw<96; kw++) {
    if (CaselessStrCmp(name, keywords[kw])) {
      name += "_";
      return true;
    }
  }
  for (size_t pos=0; pos<name.size(); pos++) {
    if (!(isalpha(name[pos]) || isdigit(name[pos]) || name[pos]=='_')) {
      name[pos] = '_';
    }
  }
  return false;
}

bool FixName(vector<string>& names)
{
  bool ret = false;
  for (size_t n=0; n<names.size(); n++) {
    if (FixName(names[n])) {
      ret = true;
    }
  }
  return ret;
}

void FixName(vector<vector<string> >& allnames) 
{
  for (size_t n=0; n<allnames.size(); n++) {
    FixName(allnames[n]);
  }
}


void FixName(map<vector<string>, Variable*>& varmap)
{
  for (map<vector<string>, Variable*>::iterator vm=varmap.begin(); vm != varmap.end();)
  {
    vector<string> name = vm->first;
    if (FixName(name)) {
      map<vector<string>, Variable*>::iterator vm2 = vm;
      vm++;
      varmap.insert(make_pair(name, vm2->second));
      varmap.erase(vm2);
    }
    else {
      vm++;
    }
  }
  
}

#ifdef USE_COMP
Model* getModelFromExternalModelDefinition(const ExternalModelDefinition* cextmoddef)
{
  ExternalModelDefinition* extmoddef = const_cast<ExternalModelDefinition*>(cextmoddef);
  Model* extmod = extmoddef->getReferencedModel();
  if (extmod == NULL) {
    string error = "Unable to open ";
    if (extmoddef->isSetModelRef()) {
      error += "the model " + extmoddef->getModelRef() + " from ";
    }
    if (extmoddef->isSetSource()) {
      error += "the URI " + extmoddef->getSource() + ".";
    }
    else {
      error += "the external model definition, because it did not have the required 'source' attribute.";
    }
    g_registry.AddWarning(error);
  }
  return extmod;
}

#endif

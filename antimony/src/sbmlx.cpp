#include <cassert>
#include <string>
#include <vector>
#include <map>
#include "variable.h"
#include "formula.h"
#include "registry.h"

extern bool CaselessStrCmp(const std::string& lhs, const std::string& rhs);

using namespace std;

#ifndef NSBML
#include "sbmlx.h"

// SBase objects no longer have IDs :( //update: now they do again!
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

/*
  string getNameFromSBMLObject(string ID, string name, string basename)
  {
  if (ID != "") return ID;
  if (name != "") return name;
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
  assert(name != "");
  return name;
  }
*/
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
  char* formula = SBML_formulaToString(&clone);
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
  l3ps.setParseLog(L3P_PARSE_LOG_AS_LOG10);
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

set<string> GetUnitNames(ASTNode* astn)
{
  set<string> ret;
  if (astn==NULL) return ret;
  if (astn->isSetUnits()) {
    ret.insert(astn->getUnits());
  }
  for (unsigned int c=0; c<astn->getNumChildren(); c++) {
    set<string> addme = GetUnitNames(astn->getChild(c));
    ret.insert(addme.begin(), addme.end());
  }
  return ret;
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
bool FixName(std::string& name)
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
  for (size_t kw=0; kw<93; kw++) {
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

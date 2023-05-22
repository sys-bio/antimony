#include <cassert>
#include <string>
#include <vector>
#include <map>
#include "variable.h"
#include "formula.h"
#include "registry.h"
#include "typex.h"

using namespace std;
using namespace libsbml;

extern bool CaselessStrCmp(bool caseless, const string& lhs, const string& rhs);

#ifndef NSBML
#include "sbmlx.h"
#include "sbml/math/FormulaFormatter.h"
#if LIBSBML_VERSION >= 50900
#include "sbml/math/L3FormulaFormatter.h"
#endif
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
#include "sbml/packages/distrib/common/DistribExtensionTypes.h"
#endif

string getNameFromSBMLObject(const SBase* sbml, string basename)
{
  if (sbml == NULL) {
    return "";
  }
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


void removeGlobalFunctionIDs(ASTNode_t* node)
{
  if (node==NULL) return;
  unsigned int nc = node->getNumChildren();
  if (node->getType() == AST_FUNCTION) {
    string id = node->getName();
    const UserFunction* uf = g_registry.GetUserFunction(id);
    if (uf) {
      //Fill in the missing children with the IDs of the missing variables.
      for (unsigned int c=nc; c > 0; c--) {
        vector<string> vecname = uf->GetNthExportVariable(c-1);
        const ASTNode* n = node->getChild(c-1);
        const char* cc = n->getName();
        if (cc != NULL && (string)(cc) == vecname[vecname.size()-1].c_str()) {
          node->removeChild(c-1);
          nc--;
        }
        else {
          break;
        }
      }
    }
  }
  for (unsigned int c = 0; c < nc ; c++) {
    removeGlobalFunctionIDs(node->getChild(c));
  }
}

string parseASTNodeToString(const ASTNode* ASTform, bool carat) {
  if (ASTform==NULL) return "";
  ASTNode clone(*ASTform);
  matchNamesToTypes(&clone);
  //removeGlobalFunctionIDs(&clone);
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
    if (string(node->getName()) == "True" || string(node->getName()) == "TRUE") {
        node->setType(AST_CONSTANT_TRUE);
    }
    if (string(node->getName()) == "False" || string(node->getName()) == "FALSE") {
        node->setType(AST_CONSTANT_FALSE);
    }
    if (string(node->getName()) == "NAN" || string(node->getName()) == "nan") {
        node->setType(AST_REAL);
        node->setValue(numeric_limits<double>::quiet_NaN());
    }
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    matchTypesToNames(node->getChild(c));
  }
}

void expandGlobalFunctionIDs(ASTNode_t* node)  
{
  if (node==NULL) return;
  unsigned int nc = node->getNumChildren();
  if (node->getType() == AST_FUNCTION) {
    string id = node->getName();
    const UserFunction* uf = g_registry.GetUserFunction(id);
    if (uf && uf->GetNumExportVariables() > nc) {
      //Fill in the missig children with the IDs of the missing variables.
      for (unsigned int c=nc; c<uf->GetNumExportVariables(); c++) {
        vector<string> vecname = uf->GetNthExportVariable(c);
        ASTNode* child = new ASTNode(AST_NAME);
        child->setName(vecname[vecname.size()-1].c_str());
        node->addChild(child);
      }
    }
  }
  for (unsigned int c = 0; c < nc ; c++) {
    expandGlobalFunctionIDs(node->getChild(c));
  }
}

bool isAlphaNumeric(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z') ||
      (c >= '0' && c <= '9')) {
        return true;
  }
  return false;
}

const string pythonToCBooleans(const string& formula)
{
  string newform = formula;
  size_t foundb = newform.find(" and ");
  while (foundb != string::npos) {
    newform.replace(foundb, 5, " && ");
    foundb = newform.find(" and ");
  }
  foundb = newform.find(" AND ");
  while (foundb != string::npos) {
    newform.replace(foundb, 5, " && ");
    foundb = newform.find(" AND ");
  }
  foundb = newform.find(" or ");
  while (foundb != string::npos) {
    newform.replace(foundb, 4, " || ");
    foundb = newform.find(" or ");
  }
  foundb = newform.find(" OR ");
  while (foundb != string::npos) {
    newform.replace(foundb, 4, " || ");
    foundb = newform.find(" OR ");
  }
  foundb = newform.find("not ");
  while (foundb != string::npos) {
    if (foundb == 0 || !isAlphaNumeric(newform[foundb-1])) {
      newform.replace(foundb, 4, " ! ");
    }
    foundb = newform.find("not ", foundb);
  }
  return newform;
}

const string truncatedDistribToSBML(const string& formula)
{
  string newform = formula;
  size_t foundd = newform.find("truncatedNormal");
  while (foundd != string::npos) {
    newform.replace(foundd, 10, "n");
    foundd = newform.find("truncatedNormal");
  }
  foundd = newform.find("truncatedPoisson");
  while (foundd != string::npos) {
    newform.replace(foundd, 10, "p");
    foundd = newform.find("truncatedPoisson");
  }
  foundd = newform.find("truncatedExponential");
  while (foundd != string::npos) {
    newform.replace(foundd, 10, "e");
    foundd = newform.find("truncatedExponential");
  }
  foundd = newform.find("truncatedGamma");
  while (foundd != string::npos) {
    newform.replace(foundd, 10, "g");
    foundd = newform.find("truncatedGamma");
  }
  return newform;
}

ASTNode* parseStringToASTNode(const string& formula)
{
  string newform = pythonToCBooleans(formula);
  newform = truncatedDistribToSBML(newform);
  L3ParserSettings l3ps;
  l3ps.setParseCollapseMinus(true);
  l3ps.setParseLog(L3P_PARSE_LOG_AS_LN);
  l3ps.setParsePackageMath(EM_ARRAYS, true);
  l3ps.setComparisonCaseSensitivity(L3P_COMPARE_BUILTINS_CASE_SENSITIVE);
  ASTNode* rootnode = SBML_parseL3FormulaWithSettings(newform.c_str(), &l3ps);
  if (rootnode == NULL) {
    char* l3err = SBML_getLastParseL3Error();
    g_registry.SetError(l3err);
    free(l3err);
    return NULL;
  }
  matchTypesToNames(rootnode);
  expandGlobalFunctionIDs(rootnode);
  if (g_registry.GetBareNumbersAreDimensionless()) {
    makeUnitlessNumbersDimensionless(rootnode);
  }
  return rootnode;
}

void makeUnitlessNumbersDimensionless(ASTNode* node)
{
  if (node->isNumber() && node->getUnits().empty()) {
    node->setUnits("dimensionless");
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    makeUnitlessNumbersDimensionless(node->getChild(c));
  }
}

void caratToPower(ASTNode* node)
{
  if (node == NULL) {
    return;
  }
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

bool UsesDistrib(const ASTNode* astn)
{
  if (astn==NULL) return false;
  ASTNodeType_t type = astn->getType();
  if (type >= AST_DISTRIB_FUNCTION_NORMAL && type <= AST_DISTRIB_FUNCTION_RAYLEIGH) {
    return true;
  }
  for (unsigned int c=0; c<astn->getNumChildren(); c++) {
    if (UsesDistrib(astn->getChild(c))) {
      return true;
    }
  }
  return false;
}

double GetValueFrom(const ASTNode* astn)
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

ASTNodeType_t ConstraintTypeToASTType(constraint_type type)
{
  switch(type) {
  case constNONE:
    return AST_UNKNOWN;
  case constGT:
    return AST_RELATIONAL_GT;
  case constLT:
    return AST_RELATIONAL_LT;
  case constEQ:
    return AST_RELATIONAL_EQ;
  case constGEQ:
    return AST_RELATIONAL_GEQ;
  case constLEQ:
    return AST_RELATIONAL_LEQ;
  case constNEQ:
    return AST_RELATIONAL_NEQ;
  }
  assert(false);
  return AST_UNKNOWN;
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
  , "True"
  , "False"
  , "TRUE"
  , "FALSE"
  , "pi"
  , "exponentiale" 
  , "avogadro"  
  , "time"
  , "inf"  
  , "INF"
  , "infinity"
  , "NaN"
  , "NAN"
  , "nan"
  , "notanumber"

  , "rateOf"
  , "quotient"
  , "max"
  , "min"
  , "rem"
  , "implies"

  , "normal"
  , "truncatedNormal"
  , "uniform"
  , "exponential"
  , "truncatedExponential"
  , "gamma"
  , "truncatedGamma"
  , "poisson"
  , "truncatedPoisson"
  , "bernoulli"
  , "binomial"
  , "cauchy"
  , "chisquare"
  , "laplace"
  , "lognormal"
  , "rayleigh"

  , "length"
  , "area"
  , "volume"
  , "substance"
  , "extent"
  , "time_unit"
  };
  for (size_t kw=0; kw<126; kw++) {
    if (CaselessStrCmp(false, name, keywords[kw])) {
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

void removeBooleanErrors(SBMLDocument* doc)
{
  SBMLErrorLog* log = doc->getErrorLog();
#if LIBSBML_VERSION >= 51103
  log->removeAll(10209);
  log->removeAll(10210);
  log->removeAll(10211);
  log->removeAll(10212);
  log->removeAll(10213);
  log->removeAll(10217);
  log->removeAll(21202);
  log->removeAll(21001);
  log->removeAll(98006);
#else
  log->remove(10209);
  log->remove(10210);
  log->remove(10211);
  log->remove(10212);
  log->remove(10213);
  log->remove(10217);
  log->remove(21202);
  log->remove(21001);
  log->remove(98006);
#endif
  if (log->contains(1090105) && log->getNumFailsWithSeverity(LIBSBML_SEV_ERROR)==1) {
    log->remove(1090105);
  }
  if (log->contains(1090106) && log->getNumFailsWithSeverity(LIBSBML_SEV_WARNING)==1) {
    log->remove(1090106);
  }
}

void elideMetaIds(SBMLDocument* doc)
{
  List* elts = doc->getAllElements();
  for(unsigned int k=0; k<elts->getSize(); ++k) {
    ((SBase*)elts->get(k))->unsetMetaId();
  }
  delete elts;
}

std::string elideMetaIdsFromSBMLstring(std::string sbml)
{
  SBMLReader reader;
  SBMLDocument* d = reader.readSBMLFromString(sbml);
  if (d->getNumErrors()) {
    g_registry.SetError("elideMetaIdsFromSBMLstring: Could not read sbml from string");
    return sbml;
  }
  elideMetaIds(d);
  SBMLWriter writer;
  string ret = writer.writeSBMLToStdString(d);
  delete d;
  return ret;
}

constraint_type getConstraintTypeFrom(ASTNodeType_t asttype)
{
  switch(asttype) {
  case AST_RELATIONAL_LEQ:
    return constLEQ;
  case AST_RELATIONAL_GEQ:
    return constGEQ;
  case AST_RELATIONAL_LT:
    return constLT;
  case AST_RELATIONAL_GT:
    return constGT;
  case AST_RELATIONAL_EQ:
    return constEQ;
  case AST_RELATIONAL_NEQ:
    return constNEQ;
  default:
    return constNONE;
  }
  assert(false); //uncaught type
  return constNONE;
}

#ifdef LIBSBML_HAS_PACKAGE_FBC
FluxBoundOperation_t getFBOperationFrom(constraint_type ctype)
{
  switch(ctype) {
  case constEQ:
    return FLUXBOUND_OPERATION_EQUAL;
  case constNEQ:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  case constLEQ:
  case constLT:
    return FLUXBOUND_OPERATION_LESS_EQUAL;
  case constGEQ:
  case constGT:
    return FLUXBOUND_OPERATION_GREATER_EQUAL;
  case constNONE:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  }
  assert(false);
  return FLUXBOUND_OPERATION_UNKNOWN;
}

FluxBoundOperation_t getReverseFBOperationFrom(constraint_type ctype)
{
  switch(ctype) {
  case constEQ:
    return FLUXBOUND_OPERATION_EQUAL;
  case constNEQ:
  case constNONE:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  case constLEQ:
  case constLT:
    return FLUXBOUND_OPERATION_GREATER_EQUAL;
  case constGEQ:
  case constGT:
    return FLUXBOUND_OPERATION_LESS_EQUAL;
  }
  assert(false);
  return FLUXBOUND_OPERATION_UNKNOWN;
}

constraint_type getConstraintTypeFrom(FluxBoundOperation_t fbtype)
{
  switch(fbtype) {
  case FLUXBOUND_OPERATION_LESS_EQUAL:
    return constLEQ;
  case FLUXBOUND_OPERATION_GREATER_EQUAL:
    return constGEQ;
  case FLUXBOUND_OPERATION_LESS:
    return constLT;
  case FLUXBOUND_OPERATION_GREATER:
    return constGT;
  case FLUXBOUND_OPERATION_EQUAL:
    return constEQ;
  case FLUXBOUND_OPERATION_UNKNOWN:
    return constNONE;
  }
  assert(false); //uncaught type
  return constNONE;
}

FluxBoundOperation_t getFBOperationFrom(ASTNodeType_t asttype)
{
  switch(asttype) {
  case AST_RELATIONAL_EQ:
    return FLUXBOUND_OPERATION_EQUAL;
  case AST_RELATIONAL_NEQ:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  case AST_RELATIONAL_LEQ:
  case AST_RELATIONAL_LT:
    return FLUXBOUND_OPERATION_LESS_EQUAL;
  case AST_RELATIONAL_GEQ:
  case AST_RELATIONAL_GT:
    return FLUXBOUND_OPERATION_GREATER_EQUAL;
  default:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  }
  assert(false);
  return FLUXBOUND_OPERATION_UNKNOWN;
}

FluxBoundOperation_t getReverseFBOperationFrom(ASTNodeType_t asttype)
{
  switch(asttype) {
  case AST_RELATIONAL_EQ:
    return FLUXBOUND_OPERATION_EQUAL;
  case AST_RELATIONAL_NEQ:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  case AST_RELATIONAL_LEQ:
  case AST_RELATIONAL_LT:
    return FLUXBOUND_OPERATION_GREATER_EQUAL;
  case AST_RELATIONAL_GEQ:
  case AST_RELATIONAL_GT:
    return FLUXBOUND_OPERATION_LESS_EQUAL;
  default:
    assert(false);
    return FLUXBOUND_OPERATION_UNKNOWN;
  }
  assert(false);
  return FLUXBOUND_OPERATION_UNKNOWN;
}

bool FluxesMatch(const FluxBound* fb1, const FluxBound* fb2)
{
  if (fb1->getFluxBoundOperation() != fb2->getFluxBoundOperation()) return false;
  if (fb1->getReaction() != fb2->getReaction()) return false;
  if (fb1->getValue() != fb2->getValue()) return false;
  return true;
}

#endif
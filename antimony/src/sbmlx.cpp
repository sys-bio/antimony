#include <cassert>
#include <string>
#include <vector>
#include <map>
#include "variable.h"
#include "formula.h"
#include "registry.h"
#include "typex.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

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

ASTNode* parseStringToASTNode(const string& formula)
{
  const string newform = pythonToCBooleans(formula);
  L3ParserSettings l3ps;
  l3ps.setParseCollapseMinus(true);
  l3ps.setParseLog(L3P_PARSE_LOG_AS_LN);
  ASTNode* rootnode = SBML_parseL3FormulaWithSettings(newform.c_str(), &l3ps);
  if (rootnode == NULL) {
    g_registry.SetError(SBML_getLastParseL3Error());
    return NULL;
  }
  if (formula.find("time") != string::npos ||
      formula.find("avogadro") != string::npos ||
      formula.find("delay") != string::npos) {
    matchTypesToNames(rootnode);
  }
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
  , "pi"  
  , "exponentiale" 
  , "avogadro"  
  , "time"
  , "inf"  
  , "infinity"  
  , "NaN"  
  , "notanumber"

  , "rateOf"
  , "quotient"
  , "max"
  , "min"
  , "rem"
  , "implies"
  };
  for (size_t kw=0; kw<102; kw++) {
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

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
void makeNormal(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("mean");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("stddev");
  di->setIndex(1);
  DistribNormalDistribution* normal = dfd->createDistribNormalDistribution();
  DistribUncertValue* mean = normal->createMean();
  mean->setVar("mean");
  DistribUncertValue* stddev = normal->createStddev();
  stddev->setVar("stddev");
}

void makeTruncNormal(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("mean");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("stddev");
  di->setIndex(1);
  di = dfd->createDistribInput();
  di->setId("lowlimit");
  di->setIndex(2);
  di = dfd->createDistribInput();
  di->setId("uplimit");
  di->setIndex(3);
  DistribNormalDistribution* normal = dfd->createDistribNormalDistribution();
  DistribUncertValue* mean = normal->createMean();
  mean->setVar("mean");
  DistribUncertValue* stddev = normal->createStddev();
  stddev->setVar("stddev");
  DistribUncertBound* bound = normal->createTruncationLowerBound();
  bound->setVar("lowlimit");
  bound->setInclusive(true);
  bound = normal->createTruncationUpperBound();
  bound->setVar("uplimit");
  bound->setInclusive(true);
}

void makeUniform(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("minimum");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("maximum");
  di->setIndex(1);
  DistribUniformDistribution* uniform = dfd->createDistribUniformDistribution();
  DistribUncertValue* min = uniform->createMinimum();
  DistribUncertValue* max = uniform->createMaximum();
  min->setVar("minimum");
  max->setVar("maximum");
}

void makeExponential(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  DistribExponentialDistribution* exp = dfd->createDistribExponentialDistribution();
  DistribUncertValue* rate = exp->createRate();
  rate->setVar("rate");
}

void makeTruncExponential(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("lowlimit");
  di->setIndex(1);
  di = dfd->createDistribInput();
  di->setId("uplimit");
  di->setIndex(2);
  DistribExponentialDistribution* exp = dfd->createDistribExponentialDistribution();
  DistribUncertValue* rate = exp->createRate();
  rate->setVar("rate");
  DistribUncertBound* bound = exp->createTruncationLowerBound();
  bound->setVar("lowlimit");
  bound->setInclusive(true);
  bound = exp->createTruncationUpperBound();
  bound->setVar("uplimit");
  bound->setInclusive(true);
}

void makeGamma(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("shape");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("scale");
  di->setIndex(1);
  DistribGammaDistribution* gamma = dfd->createDistribGammaDistribution();
  DistribUncertValue* shape = gamma->createShape();
  DistribUncertValue* scale = gamma->createScale();
  shape->setVar("shape");
  scale->setVar("scale");
}

void makeTruncGamma(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("shape");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("scale");
  di->setIndex(1);
  di = dfd->createDistribInput();
  di->setId("lowlimit");
  di->setIndex(2);
  di = dfd->createDistribInput();
  di->setId("uplimit");
  di->setIndex(3);
  DistribGammaDistribution* gamma = dfd->createDistribGammaDistribution();
  DistribUncertValue* shape = gamma->createShape();
  DistribUncertValue* scale = gamma->createScale();
  shape->setVar("shape");
  scale->setVar("scale");
  DistribUncertBound* bound = gamma->createTruncationLowerBound();
  bound->setVar("lowlimit");
  bound->setInclusive(true);
  bound = gamma->createTruncationUpperBound();
  bound->setVar("uplimit");
  bound->setInclusive(true);
}

void makePoisson(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  DistribPoissonDistribution* poisson = dfd->createDistribPoissonDistribution();
  DistribUncertValue* rate = poisson->createRate();
  rate->setVar("rate");
}

void makeTruncPoisson(DistribDrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("lowlimit");
  di->setIndex(1);
  di = dfd->createDistribInput();
  di->setId("uplimit");
  di->setIndex(2);
  DistribPoissonDistribution* poisson = dfd->createDistribPoissonDistribution();
  DistribUncertValue* rate = poisson->createRate();
  rate->setVar("rate");
  DistribUncertBound* bound = poisson->createTruncationLowerBound();
  bound->setVar("lowlimit");
  bound->setInclusive(true);
  bound = poisson->createTruncationUpperBound();
  bound->setVar("uplimit");
  bound->setInclusive(true);
}

#endif

void addDistributionToModel(Model* model, distribution_type dtype)
{
  FunctionDefinition* fd = model->createFunctionDefinition();
  string function = "lambda(" + GetArgumentStringForDistribution(dtype) + " NaN)";
  ASTNode* math = parseStringToASTNode(function.c_str());
  fd->setMath(math);
  delete math;
  string annotation = "<annotation> <distribution xmlns=\"http://sbml.org/annotations/distribution\" definition=\"" + GetWikipediaURIForDistribution(dtype) + "\"/> </annotation>";
  fd->setAnnotation(annotation.c_str());
  fd->setId(DistributionTypeToString(dtype));
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  DistribFunctionDefinitionPlugin* dfdp = static_cast<DistribFunctionDefinitionPlugin*>(fd->getPlugin("distrib"));
  DistribDrawFromDistribution* dfd = dfdp->createDistribDrawFromDistribution();
  switch(dtype) {
  case distNORMAL:
    makeNormal(dfd);
    break;
  case distTRUNCNORMAL:
    makeTruncNormal(dfd);
    break;
  case distUNIFORM:
    makeUniform(dfd);
    break;
  case distEXPONENTIAL:
    makeExponential(dfd);
    break;
  case distTRUNCEXPONENTIAL:
    makeTruncExponential(dfd);
    break;
  case distGAMMA:
    makeGamma(dfd);
    break;
  case distTRUNCGAMMA:
    makeTruncGamma(dfd);
    break;
  case distPOISSON:
    makePoisson(dfd);
    break;
  case distTRUNCPOISSON:
    makeTruncPoisson(dfd);
    break;
  }
#endif
}

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
distribution_type checkNormal(const DistribDistribution* distrib, const DistribDrawFromDistribution* dfd)
{
  unsigned int numinputs = dfd->getNumDistribInputs();
  if (numinputs != 2 && numinputs != 4) {
    return distUNKNOWN;
  }
  const DistribNormalDistribution* normal = static_cast<const DistribNormalDistribution*>(distrib);
  if (!normal->isSetMean()) {
    return distUNKNOWN;
  }
  if (!normal->isSetStddev()) {
    return distUNKNOWN;
  }
  if (normal->isSetTruncationLowerBound() != normal->isSetTruncationUpperBound()) {
    return distUNKNOWN;
  }
  const DistribUncertValue* value = normal->getMean();
  if (value->getVar() != dfd->getDistribInputByIndex(0)->getId()) {
    return distUNKNOWN;
  }
  value = normal->getStddev();
  if (value->getVar() != dfd->getDistribInputByIndex(1)->getId()) {
    return distUNKNOWN;
  }
  if (!normal->isSetTruncationLowerBound()) {
    return distNORMAL;
  }
  value = normal->getTruncationLowerBound();
  if (value->getVar() != dfd->getDistribInputByIndex(2)->getId()) {
    return distUNKNOWN;
  }
  value = normal->getTruncationUpperBound();
  if (value->getVar() != dfd->getDistribInputByIndex(3)->getId()) {
    return distUNKNOWN;
  }
  return distTRUNCNORMAL;
}


distribution_type checkUniform(const DistribDistribution* distrib, const DistribDrawFromDistribution* dfd)
{
  unsigned int numinputs = dfd->getNumDistribInputs();
  if (numinputs != 2) {
    return distUNKNOWN;
  }
  const DistribUniformDistribution* uniform = static_cast<const DistribUniformDistribution*>(distrib);
  if (!uniform->isSetMaximum()) {
    return distUNKNOWN;
  }
  if (!uniform->isSetMinimum()) {
    return distUNKNOWN;
  }
  const DistribUncertValue* value = uniform->getMinimum();
  if (value->getVar() != dfd->getDistribInputByIndex(0)->getId()) {
    return distUNKNOWN;
  }
  value = uniform->getMaximum();
  if (value->getVar() != dfd->getDistribInputByIndex(1)->getId()) {
    return distUNKNOWN;
  }
  return distUNIFORM;
}


distribution_type checkExponential(const DistribDistribution* distrib, const DistribDrawFromDistribution* dfd)
{
  unsigned int numinputs = dfd->getNumDistribInputs();
  if (numinputs != 1 && numinputs != 3) {
    return distUNKNOWN;
  }
  const DistribExponentialDistribution* exp = static_cast<const DistribExponentialDistribution*>(distrib);
  if (!exp->isSetRate()) {
    return distUNKNOWN;
  }
  if (exp->isSetTruncationLowerBound() != exp->isSetTruncationUpperBound()) {
    return distUNKNOWN;
  }
  const DistribUncertValue* value = exp->getRate();
  if (value->getVar() != dfd->getDistribInputByIndex(0)->getId()) {
    return distUNKNOWN;
  }
  if (!exp->isSetTruncationLowerBound()) {
    return distEXPONENTIAL;
  }
  value = exp->getTruncationLowerBound();
  if (value->getVar() != dfd->getDistribInputByIndex(1)->getId()) {
    return distUNKNOWN;
  }
  value = exp->getTruncationUpperBound();
  if (value->getVar() != dfd->getDistribInputByIndex(2)->getId()) {
    return distUNKNOWN;
  }
  return distTRUNCEXPONENTIAL;
}


distribution_type checkGamma(const DistribDistribution* distrib, const DistribDrawFromDistribution* dfd)
{
  unsigned int numinputs = dfd->getNumDistribInputs();
  if (numinputs != 2 && numinputs != 4) {
    return distUNKNOWN;
  }
  const DistribGammaDistribution* gamma = static_cast<const DistribGammaDistribution*>(distrib);
  if (!gamma->isSetShape()) {
    return distUNKNOWN;
  }
  if (!gamma->isSetScale()) {
    return distUNKNOWN;
  }
  if (gamma->isSetTruncationLowerBound() != gamma->isSetTruncationUpperBound()) {
    return distUNKNOWN;
  }
  const DistribUncertValue* value = gamma->getShape();
  if (value->getVar() != dfd->getDistribInputByIndex(0)->getId()) {
    return distUNKNOWN;
  }
  value = gamma->getScale();
  if (value->getVar() != dfd->getDistribInputByIndex(1)->getId()) {
    return distUNKNOWN;
  }
  if (!gamma->isSetTruncationLowerBound()) {
    return distGAMMA;
  }
  value = gamma->getTruncationLowerBound();
  if (value->getVar() != dfd->getDistribInputByIndex(2)->getId()) {
    return distUNKNOWN;
  }
  value = gamma->getTruncationUpperBound();
  if (value->getVar() != dfd->getDistribInputByIndex(3)->getId()) {
    return distUNKNOWN;
  }
  return distTRUNCGAMMA;
}


distribution_type checkPoisson(const DistribDistribution* distrib, const DistribDrawFromDistribution* dfd)
{
  unsigned int numinputs = dfd->getNumDistribInputs();
  if (numinputs != 1 && numinputs != 3) {
    return distUNKNOWN;
  }
  const DistribPoissonDistribution* poisson = static_cast<const DistribPoissonDistribution*>(distrib);
  if (!poisson->isSetRate()) {
    return distUNKNOWN;
  }
  if (poisson->isSetTruncationLowerBound() != poisson->isSetTruncationUpperBound()) {
    return distUNKNOWN;
  }
  const DistribUncertValue* value = poisson->getRate();
  if (value->getVar() != dfd->getDistribInputByIndex(0)->getId()) {
    return distUNKNOWN;
  }
  if (!poisson->isSetTruncationLowerBound()) {
    return distPOISSON;
  }
  value = poisson->getTruncationLowerBound();
  if (value->getVar() != dfd->getDistribInputByIndex(1)->getId()) {
    return distUNKNOWN;
  }
  value = poisson->getTruncationUpperBound();
  if (value->getVar() != dfd->getDistribInputByIndex(2)->getId()) {
    return distUNKNOWN;
  }
  return distTRUNCPOISSON;
}


distribution_type GetExactTypeOf(const DistribFunctionDefinitionPlugin* dfdp)
{
  if (dfdp == NULL) {
    return distUNKNOWN;
  }
  const DistribDrawFromDistribution* dfd = dfdp->getDistribDrawFromDistribution();
  if (dfd == NULL) {
    return distUNKNOWN;
  }
  const DistribDistribution* distribution = dfd->getDistribution();
  if (distribution == NULL) {
    return distUNKNOWN;
  }
  switch (distribution->getTypeCode()) {
    case SBML_DISTRIB_NORMALDISTRIBUTION:
      return checkNormal(distribution, dfd);
    case SBML_DISTRIB_UNIFORMDISTRIBUTION:
      return checkUniform(distribution, dfd);
    case SBML_DISTRIB_EXPONENTIALDISTRIBUTION:
      return checkExponential(distribution, dfd);
    case SBML_DISTRIB_GAMMADISTRIBUTION:
      return checkGamma(distribution, dfd);
    case SBML_DISTRIB_POISSONDISTRIBUTION:
      return checkPoisson(distribution, dfd);
    default:
      return distUNKNOWN;
  }
  return distUNKNOWN;
}

string GetArgumentFor(const DistribUncertValue* value)
{
  if (value == NULL) {
    return "";
  }
  if (value->isSetVar()) {
    return value->getVar();
  }
  if (value->isSetValue()) {
    stringstream s;
    s << value->getValue();
    return s.str();
  }
  return "";
}

//string GetArgumentFor(const string& arg, const DistribDistribution* value)
//{
//  return arg;
//}
//

string GetAntimonyFromNormal(const DistribDistribution* dist)
{
  const DistribNormalDistribution* normal = static_cast<const DistribNormalDistribution*>(dist);
  string mean = GetArgumentFor(normal->getMean());
  string stddev = GetArgumentFor(normal->getStddev());
  string variance = GetArgumentFor(normal->getVariance());
  string function = "normal";
  //Convert variance to stddev:
  if (!variance.empty() && stddev.empty()) {
    stddev = "sqrt(" + variance + ")";
    variance = "";
  }
  if (mean.empty() || stddev.empty()) return "";
  string arglist = "(" + mean + ", " + stddev;
  //If this is a truncated normal, adjust accordingly.
  if (normal->isSetTruncationLowerBound() || normal->isSetTruncationUpperBound()) {
    string lowlimit = GetArgumentFor(normal->getTruncationLowerBound());
    string uplimit = GetArgumentFor(normal->getTruncationUpperBound());
    if (lowlimit.empty()) {
      lowlimit = "-inf";
    }
    if (uplimit.empty()) {
      uplimit = "inf";
    }
    function = "truncatedNormal";
    arglist += ", " + lowlimit + ", " + uplimit;
  }
  return function + arglist + ")";
}

string GetAntimonyFromUniform(const DistribDistribution* dist)
{
  const DistribUniformDistribution* uniform= static_cast<const DistribUniformDistribution*>(dist);
  string minimum = GetArgumentFor(uniform->getMinimum());
  string maximum = GetArgumentFor(uniform->getMaximum());
  if (minimum.empty() || maximum.empty()) return "";
  return "uniform(" + minimum + ", " + maximum + ")";
}

string GetAntimonyFromExponential(const DistribDistribution* dist)
{
  const DistribExponentialDistribution* exp = static_cast<const DistribExponentialDistribution*>(dist);
  string rate = GetArgumentFor(exp->getRate());
  string function = "exponential";
  if (rate.empty()) return "";
  string arglist = "(" + rate;
  //If this is a truncated function, adjust accordingly.
  if (exp->isSetTruncationLowerBound() || exp->isSetTruncationUpperBound()) {
    string lowlimit = GetArgumentFor(exp->getTruncationLowerBound());
    string uplimit = GetArgumentFor(exp->getTruncationUpperBound());
    if (lowlimit.empty()) {
      lowlimit = "-inf";
    }
    if (uplimit.empty()) {
      uplimit = "inf";
    }
    function = "truncatedExponential";
    arglist += ", " + lowlimit + ", " + uplimit;
  }
  return function + arglist + ")";
}

string GetAntimonyFromGamma(const DistribDistribution* dist)
{
  const DistribGammaDistribution* gamma = static_cast<const DistribGammaDistribution*>(dist);
  string shape = GetArgumentFor(gamma->getShape());
  if (shape.empty()) return "";
  string scale = GetArgumentFor(gamma->getScale());
  if (scale.empty()) return "";
  string function = "gamma";
  string arglist = "(" + shape + ", " + scale;
  //If this is a truncated function, adjust accordingly.
  if (gamma->isSetTruncationLowerBound() || gamma->isSetTruncationUpperBound()) {
    string lowlimit = GetArgumentFor(gamma->getTruncationLowerBound());
    string uplimit = GetArgumentFor(gamma->getTruncationUpperBound());
    if (lowlimit.empty()) {
      lowlimit = "-inf";
    }
    if (uplimit.empty()) {
      uplimit = "inf";
    }
    function = "truncatedGamma";
    arglist += ", " + lowlimit + ", " + uplimit;
  }
  return function + arglist + ")";
}

string GetAntimonyFromPoisson(const DistribDistribution* dist)
{
  const DistribPoissonDistribution* poisson = static_cast<const DistribPoissonDistribution*>(dist);
  string rate = GetArgumentFor(poisson->getRate());
  string function = "poisson";
  if (rate.empty()) return "";
  string arglist = "(" + rate;
  //If this is a truncated function, adjust accordingly.
  if (poisson->isSetTruncationLowerBound() || poisson->isSetTruncationUpperBound()) {
    string lowlimit = GetArgumentFor(poisson->getTruncationLowerBound());
    string uplimit = GetArgumentFor(poisson->getTruncationUpperBound());
    if (lowlimit.empty()) {
      lowlimit = "-inf";
    }
    if (uplimit.empty()) {
      uplimit = "inf";
    }
    function = "truncatedPoisson";
    arglist += ", " + lowlimit + ", " + uplimit;
  }
  return function + arglist + ")";
}

ASTNode* GetAntimonyFormOf(const DistribFunctionDefinitionPlugin* dfdp)
{
  const DistribDrawFromDistribution* dfd = dfdp->getDistribDrawFromDistribution();
  if (dfd==NULL) return NULL;
  const DistribDistribution* dist = dfd->getDistribution();
  if (dist==NULL) return NULL;
  string antimony = "lambda(";
  for (unsigned long di=0; di<dfd->getNumDistribInputs(); di++) {
    const DistribInput* distinp = dfd->getListOfDistribInputs()->get(di);
    if (distinp == NULL) return NULL;
    antimony += distinp->getId() + ", ";
  }
  string distrib = "";
  switch (dist->getTypeCode()) {
  case SBML_DISTRIB_NORMALDISTRIBUTION:
    distrib = GetAntimonyFromNormal(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
    break;
  case SBML_DISTRIB_UNIFORMDISTRIBUTION:
    distrib = GetAntimonyFromUniform(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
    break;
  case SBML_DISTRIB_EXPONENTIALDISTRIBUTION:
    distrib = GetAntimonyFromExponential(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
    break;
  case SBML_DISTRIB_GAMMADISTRIBUTION:
    distrib = GetAntimonyFromGamma(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
    break;
  case SBML_DISTRIB_POISSONDISTRIBUTION:
    distrib = GetAntimonyFromPoisson(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  return parseStringToASTNode(antimony + ")");
}
#endif
distribution_type GetDistributionFromAnnotation(const std::string& annot, unsigned int numargs)
{
 if (annot.find("http://sbml.org/annotations/distribution") != string::npos) {
   //It might be a distribution we know about!
   if (annot.find(GetURIForDistribution(distNORMAL)) != string::npos ) {
     if (numargs == 2) return distNORMAL;
     if (numargs == 4) return distTRUNCNORMAL;
     return distUNKNOWN;
   }
   if (annot.find(GetURIForDistribution(distUNIFORM)) != string::npos ) {
     if (numargs == 2) return distUNIFORM;
     return distUNKNOWN;
   }
   if (annot.find(GetURIForDistribution(distEXPONENTIAL)) != string::npos ) {
     if (numargs == 1) return distEXPONENTIAL;
     if (numargs == 3) return distTRUNCEXPONENTIAL;
     return distUNKNOWN;
   }
   if (annot.find(GetURIForDistribution(distGAMMA)) != string::npos ) {
     if (numargs == 2) return distGAMMA;
     if (numargs == 4) return distTRUNCGAMMA;
     return distUNKNOWN;
   }
   if (annot.find(GetURIForDistribution(distPOISSON)) != string::npos ) {
     if (numargs == 1) return distPOISSON;
     if (numargs == 3) return distTRUNCPOISSON;
     return distUNKNOWN;
   }
 }
 return distUNKNOWN;
}

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
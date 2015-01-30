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
  removeGlobalFunctionIDs(&clone);
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

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
void makeNormal(DrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("mean");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("stddev");
  di->setIndex(1);
  UncertMLNode* dist = UncertMLNode::createDistributionNode("NormalDistribution", "mean, stddev", "mean, stddev");
  dfd->setUncertML(dist);
}

void makeTruncNormal(DrawFromDistribution* dfd)
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
  UncertMLNode* dist = UncertMLNode::createDistributionNode("NormalDistribution", "mean, stddev, truncationLowerInclusiveBound, truncationUpperInclusiveBound", "mean, stddev, lowlimit, uplimit");
  dfd->setUncertML(dist);
}

void makeUniform(DrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("minimum");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("maximum");
  di->setIndex(1);
  UncertMLNode* dist = UncertMLNode::createDistributionNode("UniformDistribution", "minimum, maximum", "minimum, maximum");
  dfd->setUncertML(dist);
}

void makeExponential(DrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  UncertMLNode* dist = UncertMLNode::createDistributionNode("ExponentialDistribution", "rate", "rate");
  dfd->setUncertML(dist);
}

void makeTruncExponential(DrawFromDistribution* dfd)
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
  UncertMLNode* dist = UncertMLNode::createDistributionNode("ExponentialDistribution", "rate, truncationLowerInclusiveBound, truncationUpperInclusiveBound", "rate, lowlimit, uplimit");
  dfd->setUncertML(dist);
}

void makeGamma(DrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("shape");
  di->setIndex(0);
  di = dfd->createDistribInput();
  di->setId("scale");
  di->setIndex(1);
  UncertMLNode* dist = UncertMLNode::createDistributionNode("GammaDistribution", "shape, scale", "shape, scale");
  dfd->setUncertML(dist);
}

void makeTruncGamma(DrawFromDistribution* dfd)
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
  UncertMLNode* dist = UncertMLNode::createDistributionNode("GammaDistribution", "shape, scale, truncationLowerInclusiveBound, truncationUpperInclusiveBound", "shape, scale, lowlimit, uplimit");
  dfd->setUncertML(dist);
}

void makePoisson(DrawFromDistribution* dfd)
{
  DistribInput* di = dfd->createDistribInput();
  di->setId("rate");
  di->setIndex(0);
  UncertMLNode* dist = UncertMLNode::createDistributionNode("PoissonDistribution", "rate", "rate");
  dfd->setUncertML(dist);
}

void makeTruncPoisson(DrawFromDistribution* dfd)
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
  UncertMLNode* dist = UncertMLNode::createDistributionNode("PoissonDistribution", "rate, truncationLowerInclusiveBound, truncationUpperInclusiveBound", "rate, lowlimit, uplimit");
  dfd->setUncertML(dist);
}

#endif

void addDistributionToModel(Model* model, distribution_type dtype)
{
  FunctionDefinition* fd = model->createFunctionDefinition();
  string function = "lambda(" + GetArgumentStringForDistribution(dtype) + " NaN)";
  ASTNode* math = parseStringToASTNode(function.c_str());
  fd->setMath(math);
  string annotation = "<annotation> <symbols xmlns=\"http://sbml.org/annotations/symbols\" definition=\"" + GetURIForDistribution(dtype) + "\"/> </annotation>";
  fd->setAnnotation(annotation.c_str());
  fd->setId(DistributionTypeToString(dtype));
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  DistribFunctionDefinitionPlugin* dfdp = static_cast<DistribFunctionDefinitionPlugin*>(fd->getPlugin("distrib"));
  DrawFromDistribution* dfd = dfdp->createDrawFromDistribution();
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
bool isExactOneChildDistribution(const DrawFromDistribution* dfd, string distname, string ch1)
{
  if (dfd->getNumDistribInputs() != 1) return false;
  const UncertMLNode* dist = dfd->getUncertML();
  if (dist->getElementName() != distname) return false;
  if (dist->getNumChildren() != 1) return false;
  UncertMLNode* child1 = dist->getChild(0);
  if (child1->getElementName() != ch1) return false;

  if (child1->getNumChildren() != 1) return false;
  child1 = child1->getChild(0);
  
  if (child1->getElementName() != "var") return false;
  if (child1->getNumAttributes() != 1) return false;
  const XMLAttributes atts1 = child1->getAttributes();
  if (!atts1.hasAttribute("varId")) return false;

  const DistribInput* di = dfd->getDistribInput(atts1.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 0) return false;
  return true;
}

bool isExactTwoChildDistribution(const DrawFromDistribution* dfd, string distname, string ch1, string ch2)
{
  if (dfd->getNumDistribInputs() != 2) return false;
  const UncertMLNode* dist = dfd->getUncertML();
  if (dist->getElementName() != distname) return false;
  if (dist->getNumChildren() != 2) return false;
  UncertMLNode* child1 = dist->getChild(0);
  UncertMLNode* child2 = dist->getChild(1);
  if (child1->getElementName() != ch1) {
    if (child2->getElementName() != ch1) return false;
    child2 = dist->getChild(0);
    child1 = dist->getChild(1);
  }
  if (child2->getElementName() != ch2) return false;

  if (child1->getNumChildren() != 1) return false;
  if (child2->getNumChildren() != 1) return false;
  child1 = child1->getChild(0);
  child2 = child2->getChild(0);
  
  if (child1->getElementName() != "var") return false;
  if (child2->getElementName() != "var") return false;
  if (child1->getNumAttributes() != 1) return false;
  if (child2->getNumAttributes() != 1) return false;
  const XMLAttributes atts1 = child1->getAttributes();
  if (!atts1.hasAttribute("varId")) return false;
  const XMLAttributes atts2 = child2->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;

  const DistribInput* di = dfd->getDistribInput(atts1.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 0) return false;
  di = dfd->getDistribInput(atts2.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 1) return false;
  return true;
}

bool isExactThreeChildDistribution(const DrawFromDistribution* dfd, string distname, string ch1, string ch2, string ch3)
{
  if (dfd->getNumDistribInputs() != 3) return false;
  const UncertMLNode* dist = dfd->getUncertML();
  if (dist->getElementName() != distname) return false;
  if (dist->getNumChildren() != 3) return false;
  UncertMLNode* child1 = dist->getChild(0);
  UncertMLNode* child2 = dist->getChild(1);
  UncertMLNode* child3 = dist->getChild(2);
  if (child1->getElementName() != ch1) {
    if (child2->getElementName() == ch1) {
      child2 = dist->getChild(0);
      child1 = dist->getChild(1);
    }
    else if (child3->getElementName() == ch1){
      child3 = dist->getChild(0);
      child1 = dist->getChild(2);
    }
    else return false;
  }
  if (child2->getElementName() != ch2) {
    if (child3->getElementName() == ch2){
      child3 = dist->getChild(1);
      child2 = dist->getChild(2);
    }
    else return false;
  }
  if (child3->getElementName() != ch3) return false;

  if (child1->getNumChildren() != 1) return false;
  if (child2->getNumChildren() != 1) return false;
  if (child3->getNumChildren() != 1) return false;
  child1 = child1->getChild(0);
  child2 = child2->getChild(0);
  child3 = child3->getChild(0);
  
  if (child1->getElementName() != "var") return false;
  if (child2->getElementName() != "var") return false;
  if (child3->getElementName() != "var") return false;
  if (child1->getNumAttributes() != 1) return false;
  if (child2->getNumAttributes() != 1) return false;
  if (child3->getNumAttributes() != 1) return false;
  const XMLAttributes atts1 = child1->getAttributes();
  if (!atts1.hasAttribute("varId")) return false;
  const XMLAttributes atts2 = child2->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;
  const XMLAttributes atts3 = child3->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;

  const DistribInput* di = dfd->getDistribInput(atts1.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 0) return false;
  di = dfd->getDistribInput(atts2.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 1) return false;
  di = dfd->getDistribInput(atts3.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 2) return false;

  return true;
}

bool isExactFourChildDistribution(const DrawFromDistribution* dfd, string distname, string ch1, string ch2, string ch3, string ch4)
{
  if (dfd->getNumDistribInputs() != 4) return false;
  const UncertMLNode* dist = dfd->getUncertML();
  if (dist->getElementName() != distname) return false;
  if (dist->getNumChildren() != 4) return false;
  UncertMLNode* child1 = dist->getChild(0);
  UncertMLNode* child2 = dist->getChild(1);
  UncertMLNode* child3 = dist->getChild(2);
  UncertMLNode* child4 = dist->getChild(3);
  if (child1->getElementName() != ch1) {
    if (child2->getElementName() == ch1) {
      child2 = dist->getChild(0);
      child1 = dist->getChild(1);
    }
    else if (child3->getElementName() == ch1){
      child3 = dist->getChild(0);
      child1 = dist->getChild(2);
    }
    else if (child4->getElementName() == ch1){
      child4 = dist->getChild(0);
      child1 = dist->getChild(3);
    }
    else return false;
  }
  if (child2->getElementName() != ch2) {
    if (child3->getElementName() == ch2){
      child3 = dist->getChild(1);
      child2 = dist->getChild(2);
    }
    else if (child4->getElementName() == ch2){
      child4 = dist->getChild(1);
      child2 = dist->getChild(3);
    }
    else return false;
  }
  if (child3->getElementName() != ch3) {
    if (child4->getElementName() != ch3) return false;
    child4 = dist->getChild(2);
    child3 = dist->getChild(3);
  }
  if (child4->getElementName() != ch4) return false;

  if (child1->getNumChildren() != 1) return false;
  if (child2->getNumChildren() != 1) return false;
  if (child3->getNumChildren() != 1) return false;
  if (child4->getNumChildren() != 1) return false;
  child1 = child1->getChild(0);
  child2 = child2->getChild(0);
  child3 = child3->getChild(0);
  child4 = child4->getChild(0);
  
  if (child1->getElementName() != "var") return false;
  if (child2->getElementName() != "var") return false;
  if (child3->getElementName() != "var") return false;
  if (child4->getElementName() != "var") return false;
  if (child1->getNumAttributes() != 1) return false;
  if (child2->getNumAttributes() != 1) return false;
  if (child3->getNumAttributes() != 1) return false;
  if (child4->getNumAttributes() != 1) return false;
  const XMLAttributes atts1 = child1->getAttributes();
  if (!atts1.hasAttribute("varId")) return false;
  const XMLAttributes atts2 = child2->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;
  const XMLAttributes atts3 = child3->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;
  const XMLAttributes atts4 = child4->getAttributes();
  if (!atts2.hasAttribute("varId")) return false;

  const DistribInput* di = dfd->getDistribInput(atts1.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 0) return false;
  di = dfd->getDistribInput(atts2.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 1) return false;
  di = dfd->getDistribInput(atts3.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 2) return false;
  di = dfd->getDistribInput(atts4.getValue("varId"));
  if (di == NULL) return false;
  if (di->getIndex() != 3) return false;

  return true;
}


distribution_type GetExactTypeOf(const DistribFunctionDefinitionPlugin* dfdp)
{
  const DrawFromDistribution* dfd = dfdp->getDrawFromDistribution();
  if (isExactTwoChildDistribution(dfd, "NormalDistribution", "mean", "stddev")) 
    return distNORMAL;
  if (isExactFourChildDistribution(dfd, "NormalDistribution", "mean", "stddev", "truncationLowerInclusiveBound", "truncationUpperInclusiveBound")) 
    return distTRUNCNORMAL;
  if (isExactTwoChildDistribution(dfd, "UniformDistribution", "minimum", "maximum")) 
    return distUNIFORM;
  if (isExactOneChildDistribution(dfd, "ExponentialDistribution", "rate")) 
    return distEXPONENTIAL;
  if (isExactThreeChildDistribution(dfd, "ExponentialDistribution", "rate", "truncationLowerInclusiveBound", "truncationUpperInclusiveBound")) 
    return distTRUNCEXPONENTIAL;
  if (isExactTwoChildDistribution(dfd, "GammaDistribution", "shape", "scale")) 
    return distGAMMA;
  if (isExactFourChildDistribution(dfd, "GammaDistribution", "shape", "scale", "truncationLowerInclusiveBound", "truncationUpperInclusiveBound")) 
    return distTRUNCGAMMA;
  if (isExactOneChildDistribution(dfd, "PoissonDistribution", "rate")) 
    return distPOISSON;
  if (isExactThreeChildDistribution(dfd, "PoissonDistribution", "rate", "truncationLowerInclusiveBound", "truncationUpperInclusiveBound")) 
    return distTRUNCPOISSON;
  return distUNKNOWN;
}

string GetArgumentFor(string element, const UncertMLNode* dist)
{
  UncertMLNode* child = NULL;
  unsigned int n=0;
  while (n < dist->getNumChildren() && child==NULL) {
    child = dist->getChild(n);
    if (child->getElementName() != element) {
      child = NULL;
    }
    n++;
  }
  if (child == NULL) return "";
  if (child->getNumChildren() != 1) return "";
  child = child->getChild(0);
  if (child->getElementName() == "var") {
    //It's a string reference
    if (child->getNumAttributes() != 1) return "";
    return child->getAttributes().getValue("varId");
  }
  if (child->getElementName() == "iVal" ||
      child->getElementName() == "kVal" ||
      child->getElementName() == "ndVal" ||
      child->getElementName() == "nnVal" ||
      child->getElementName() == "nnrVal" ||
      child->getElementName() == "pVal" ||
      child->getElementName() == "pnnVal" ||
      child->getElementName() == "prVal" ||
      child->getElementName() == "rVal" ||
      child->getElementName() == "sVal"
      ) {
    //It's a numerical value
    child = child->getChild(0);
    if (child != NULL) return child->getText();
  }
  return "";
}

string GetAntimonyFromNormal(const UncertMLNode* dist)
{
  string mean = GetArgumentFor("mean", dist);
  string stddev = GetArgumentFor("stddev", dist);
  string variance = GetArgumentFor("variance", dist);
  string lowlimit = GetArgumentFor("truncationLowerInclusiveBound", dist);
  string uplimit = GetArgumentFor("truncationUpperInclusiveBound", dist);
  string function = "normal";
  //Convert variance to stddev:
  if (!variance.empty() && stddev.empty()) {
    stddev = "sqrt(" + variance + ")";
    variance = "";
  }
  if (mean.empty() || stddev.empty()) return "";
  string arglist = "(" + mean + ", " + stddev;
  //If this is a truncated normal, adjust accordingly.
  if (!lowlimit.empty() || !uplimit.empty()) {
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

string GetAntimonyFromUniform(const UncertMLNode* dist)
{
  string minimum = GetArgumentFor("minimum", dist);
  string maximum = GetArgumentFor("maximum", dist);
  if (minimum.empty() || maximum.empty()) return "";
  return "uniform(" + minimum + ", " + maximum + ")";
}

string GetAntimonyFromTruncated(const UncertMLNode* dist, string function, string truncfunction, string arg1, string arg2, string min, string max)
{
  string first = GetArgumentFor(arg1, dist);
  string second = GetArgumentFor(arg2, dist);
  string lowlimit = GetArgumentFor("truncationLowerInclusiveBound", dist);
  string uplimit = GetArgumentFor("truncationUpperInclusiveBound", dist);
  if (first.empty()) return "";
  string arglist = "(";
  if (!arg1.empty()) {
    if (first.empty()) return "";
    arglist += first;
  }
  if (!arg2.empty()) {
    if (second.empty()) return "";
    arglist += ", " + second;
  }
  //If this is a truncated exponential, adjust accordingly.
  if (!lowlimit.empty() || !uplimit.empty()) {
    if (lowlimit.empty()) {
      lowlimit = min;
    }
    if (uplimit.empty()) {
      uplimit = max;
    }
    function = truncfunction;
    arglist += ", " + lowlimit + ", " + uplimit;
  }
  return function + arglist + ")";
}

ASTNode* GetAntimonyFormOf(const DistribFunctionDefinitionPlugin* dfdp)
{
  const DrawFromDistribution* dfd = dfdp->getDrawFromDistribution();
  if (dfd==NULL) return NULL;
  const UncertMLNode* dist = dfd->getUncertML();
  if (dist==NULL) return NULL;
  string antimony = "lambda(";
  for (unsigned long di=0; di<dfd->getNumDistribInputs(); di++) {
    const DistribInput* distinp = dfd->getListOfDistribInputs()->getByIndex(di);
    if (distinp == NULL) return NULL;
    antimony += distinp->getId() + ", ";
  }
  string elname = dist->getElementName();
  if (elname == "NormalDistribution") {
    string distrib = GetAntimonyFromNormal(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  else if (elname == "UniformDistribution") {
    string distrib = GetAntimonyFromUniform(dist);
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  else if (elname == "ExponentialDistribution") {
    string distrib = GetAntimonyFromTruncated(dist, "exponential", "truncatedExponential", "rate", "", "0", "inf");
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  else if (elname == "GammaDistribution") {
    string distrib = GetAntimonyFromTruncated(dist, "gamma", "truncatedGamma", "shape", "scale", "0", "inf");
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  else if (elname == "PoissonDistribution") {
    string distrib = GetAntimonyFromTruncated(dist, "poisson", "truncatedPoisson", "rate", "", "0", "inf");
    if (distrib.empty()) return NULL;
    antimony += distrib;
  }
  return parseStringToASTNode(antimony + ")");
}
#endif
distribution_type GetDistributionFromAnnotation(const std::string& annot, unsigned int numargs)
{
 if (annot.find("http://sbml.org/annotations/symbols") != string::npos) {
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

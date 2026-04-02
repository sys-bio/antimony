#include <cassert>
#include "constraint.h"
#include "variable.h"
#include "sbmlx.h"
#include "registry.h"
#include "stringx.h"

using namespace std;
using namespace libsbml;

AntimonyConstraint::AntimonyConstraint()
  : m_formula()
  , m_isSetInitialValue(false)
  , m_initialValue(0.0)
  , m_initialVariable()
  , m_type(constNONE)
  , m_name()
  , m_module()
  , m_astnode(NULL)
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_rxnId()
  , m_fbLower()
  , m_fbUpper()
#endif
{
}

AntimonyConstraint::AntimonyConstraint(const AntimonyConstraint& constraint)
  : m_formula(constraint.m_formula)
  , m_isSetInitialValue(constraint.m_isSetInitialValue)
  , m_initialValue(constraint.m_initialValue)
  , m_initialVariable(constraint.m_initialVariable)
  , m_type(constraint.m_type)
  , m_name(constraint.m_name)
  , m_module(constraint.m_module)
  , m_astnode(constraint.m_astnode)
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_rxnId(constraint.m_rxnId)
  , m_fbLower(constraint.m_fbLower)
  , m_fbUpper(constraint.m_fbUpper)
#endif
{
  if (m_astnode != NULL) {
    m_astnode = m_astnode->deepCopy();
  }
}

AntimonyConstraint::AntimonyConstraint(Variable* var)
  : m_formula()
  , m_isSetInitialValue(false)
  , m_initialValue(0.0)
  , m_initialVariable()
  , m_type(constNONE)
  , m_name(var->GetName())
  , m_module(var->GetNamespace())
  , m_astnode(NULL)
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_rxnId()
  , m_fbLower()
  , m_fbUpper()
#endif
{
}

AntimonyConstraint::~AntimonyConstraint()
{
  delete m_astnode;
}

void AntimonyConstraint::SetFormula(Formula* formula, bool onlyformula)
{
  m_formula = *formula;
  if (onlyformula) return;
  ASTNode* astnode = parseStringToASTNode(formula->ToSBMLString());
  SetWithASTNode(astnode);
  delete astnode;
}

void AntimonyConstraint::SetWithASTNode(const ASTNode* constnode)
{
  if (constnode == NULL) {
    return;
  }
  string formulastring;
  ASTNode astnode = *constnode;
  unsigned int numchildren = astnode.getNumChildren();
  if (numchildren < 2) {
      formulastring = parseASTNodeToString(&astnode);
      setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
    return;
  }
  ASTNodeType_t roottype = astnode.getType();
  ASTNode* c1 = astnode.getChild(0);
  ASTNode* c2 = astnode.getChild(1);
  string c1name = (c1->getType() == AST_NAME ? c1->getName() : "");
  string c2name = (c2->getType() == AST_NAME ? c2->getName() : "");
  Variable* var;
  bool reverse = false;
  switch(roottype) {
  case AST_RELATIONAL_EQ:
  case AST_RELATIONAL_GEQ:
  case AST_RELATIONAL_GT:
  case AST_RELATIONAL_LEQ:
  case AST_RELATIONAL_LT:
  case AST_RELATIONAL_NEQ:
    if (c1->getType()==AST_NAME && !g_registry.IsConstant(c1name)) {
      var = g_registry.GetModule(m_module)->AddOrFindVariable(&c1name);
      SetInitialVariable(var);
      astnode.removeChild(0);
      delete c1;
    }
    else if (c1->isNumber()) {
      SetInitialValue(GetValueFrom(c1));
      astnode.removeChild(0);
      delete c1;
    }
    else if (c2->getType()==AST_NAME && !g_registry.IsConstant(c2name) && numchildren == 2) {
      var = g_registry.GetModule(m_module)->AddOrFindVariable(&c2name);
      SetInitialVariable(var);
      astnode.removeChild(1);
      reverse = true;
      delete c2;
    }
    else if (c2->isNumber() && numchildren == 2) {
      SetInitialValue(GetValueFrom(c2));
      astnode.removeChild(1);
      reverse = true;
      delete c2;
    }
    else {
      formulastring = parseASTNodeToString(&astnode);
      setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
      return;
    }
    if (numchildren==2) {
      formulastring = parseASTNodeToString(astnode.getChild(0));
      setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
    }
    else {
      formulastring = parseASTNodeToString(&astnode);
      setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
    }
    switch(roottype) {
    case AST_RELATIONAL_EQ:
      SetType(constEQ);
      break;
    case AST_RELATIONAL_GEQ:
      if (reverse) {
        SetType(constLEQ);
      }
      else {
        SetType(constGEQ);
      }
      break;
    case AST_RELATIONAL_GT:
      if (reverse) {
        SetType(constLT);
      }
      else {
        SetType(constGT);
      }
      break;
    case AST_RELATIONAL_LEQ:
      if (reverse) {
        SetType(constGEQ);
      }
      else {
        SetType(constLEQ);
      }
      break;
    case AST_RELATIONAL_LT:
      if (reverse) {
        SetType(constGT);
      }
      else {
        SetType(constLT);
      }
      break;
    case AST_RELATIONAL_NEQ:
      SetType(constNEQ);
      break;
    default:
        assert(false); //Should be impossible, given above switch statement.
        break;
    }
    break;
  case AST_LOGICAL_AND:
    if (astnode.getNumChildren() == 2 && c1->isRelational() && c2->isRelational() &&
      c1->getNumChildren()==2 && c2->getNumChildren()==2) {
        c1 = c1->getChild(1);
        c2 = c2->getChild(0);
        if (c1->getType() == AST_NAME && c2->getType() == AST_NAME &&
            (string)c1->getName() == (string)c2->getName()) 
        {
          m_type = getConstraintTypeFrom(astnode.getChild(0)->getType());
          formulastring = parseASTNodeToString(astnode.getChild(1));
          setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
          c1 = astnode.getChild(0)->getChild(0);
          c1name = (c1->getType() == AST_NAME ? c1->getName() : "");
          if (c1->getType() == AST_NAME && !g_registry.IsConstant(c1name)) {
            var = g_registry.GetModule(m_module)->AddOrFindVariable(&c1name);
            SetInitialVariable(var);
            return;
          }
          else if (c1->isNumber()) {
            SetInitialValue(GetValueFrom(c1));
            return;
          }
          else {
            //It doesn't actually work; unset and fall through to default:
            m_type = constNONE;
          }
        }
    }
  default:
    formulastring = parseASTNodeToString(&astnode);
    setFormulaWithString(formulastring, &m_formula, g_registry.GetModule(m_module));
    return;
  }
}

void AntimonyConstraint::SetInitialValue(double val)
{
  m_isSetInitialValue = true;
  m_initialValue = val;
}

void AntimonyConstraint::SetInitialVariable(Variable* var)
{
  m_initialVariable = var->GetName();
  m_module = var->GetNamespace();
}

void AntimonyConstraint::SetType(constraint_type type)
{
  m_type = type;
}

void AntimonyConstraint::SetName(std::vector<std::string> name)
{
  m_name = name;
}

void AntimonyConstraint::SetModulename(std::string modulename)
{
  m_module = modulename;
}

void AntimonyConstraint::Clear()
{
  m_formula.Clear();
  m_isSetInitialValue = false;
  m_initialValue = 0.0;
  m_initialVariable.clear();
  m_type = constNONE;
}

bool AntimonyConstraint::IsEmpty() const
{
  return m_formula.IsEmpty();
}

bool AntimonyConstraint::IsSetInitialValue() const
{
  return m_isSetInitialValue;
}

bool AntimonyConstraint::IsSetInitialVariable() const
{
  return !m_initialVariable.empty();
}

void AntimonyConstraint::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  if (!m_initialVariable.empty()) {
    m_initialVariable.insert(m_initialVariable.begin(), newtopname);
  }
  m_formula.SetNewTopName(newmodname, newtopname);
  m_name.insert(m_name.begin(), newtopname);
  delete m_astnode;
  m_astnode = NULL;
#ifdef LIBSBML_HAS_PACKAGE_FBC
  m_fbLower.SetNewTopName(newmodname, newtopname);
  m_fbUpper.SetNewTopName(newmodname, newtopname);
#endif
}

bool AntimonyConstraint::Matches(const AntimonyConstraint* newconstraint) const
{
  if (m_type != newconstraint->m_type) return false;
  if (m_initialValue != newconstraint->m_initialValue) return false;
  if (m_initialVariable != newconstraint->m_initialVariable) return false;
  return m_formula.Matches(&newconstraint->m_formula);
}

const Formula* AntimonyConstraint::GetFormula() const
{
  return &m_formula;
}

Formula* AntimonyConstraint::GetFormula()
{
  return &m_formula;
}

double AntimonyConstraint::GetInitialValue() const
{
  return m_initialValue;
}

Variable* AntimonyConstraint::GetInitialVariable() const
{
  Module* mod = g_registry.GetModule(m_module);
  if (mod==NULL) return NULL;
  return mod->GetVariable(m_initialVariable);
}

constraint_type AntimonyConstraint::GetConstraintType() const
{
  return m_type;
}

string AntimonyConstraint::ToStringDelimitedBy(std::string cc) const
{
  stringstream retval;

  Module* module = g_registry.GetModule(m_module);
  assert(module != NULL);
  Variable* var = module->GetVariable(m_name);
  var = var->GetSameVariable();
  size_t con_ = m_name[m_name.size()-1].find("_con");
  if (m_type == constEQ ||
    m_name[m_name.size()-1].find("_con") != 0 ||
    var->GetDisplayName() != "" ||
    (!m_isSetInitialValue && m_initialVariable.empty()) )
  {
    //We need to use the 'constraint' syntax
    retval << "constraint " << var->GetNameDelimitedBy(cc) << ": ";
  }

  if (m_isSetInitialValue) {
    retval << m_initialValue;
  }
  else if (!m_initialVariable.empty()) {
    retval << ToStringFromVecDelimitedBy(m_initialVariable, cc);
  }
  switch (m_type) {
  case constNONE:
    break;
  case constGT:
    retval << " > ";
    break;
  case constLT:
    retval << " < ";
    break;
  case constEQ:
    retval << " == ";
    break;
  case constGEQ:
    retval << " >= ";
    break;
  case constLEQ:
    retval << " <= ";
    break;
  case constNEQ:
    retval << " != ";
  }
  retval << m_formula.ToDelimitedStringWithEllipses(cc);
  return retval.str();
}

void AntimonyConstraint::FixNames()
{
  m_formula.FixNames(m_module);
  FixName(m_initialVariable);
}

const ASTNode* AntimonyConstraint::getASTNode() const
{
  return m_astnode;
}

void AntimonyConstraint::calculateASTNode()
{
  if (m_astnode != NULL) return;

  ASTNode* rhs = parseStringToASTNode(m_formula.ToSBMLString());
  if (rhs == NULL) {
      //A problem here hopefully will be caught earlier, but just in case.
      return;
  }
  if (m_type != constNONE) {
    if (rhs->getType() == ConstraintTypeToASTType(m_type) && rhs->getType() != AST_RELATIONAL_NEQ) {
      if (IsSetInitialValue()) {
        stringstream valstr;
        valstr << GetInitialValue();
        ASTNode* val = parseStringToASTNode(valstr.str());
        rhs->insertChild(0, val);
      }
      else if (IsSetInitialVariable()) {
        ASTNode* var = new ASTNode(AST_NAME);
        var->setName(GetInitialVariable()->GetNameDelimitedBy(g_registry.GetCC()).c_str());
        rhs->insertChild(0, var);
      }
      else {
        assert(false);
      }
      m_astnode = rhs;
    }
    else if (rhs->isRelational()) {
      m_astnode = new ASTNode(AST_LOGICAL_AND);
      ASTNode* newfirst = new ASTNode(ConstraintTypeToASTType(m_type));
      if (IsSetInitialValue()) {
        stringstream valstr;
        valstr << GetInitialValue();
        ASTNode* val = parseStringToASTNode(valstr.str());
        newfirst->addChild(val);
      }
      else if (IsSetInitialVariable()) {
        ASTNode* var = new ASTNode(AST_NAME);
        var->setName(GetInitialVariable()->GetNameDelimitedBy(g_registry.GetCC()).c_str());
        newfirst->addChild(var);
      }
      else {
        assert(false);
      }
      newfirst->addChild(rhs->getChild(0)->deepCopy());
      m_astnode->addChild(newfirst);
      m_astnode->addChild(rhs);
    }
    else {
      m_astnode = new ASTNode(ConstraintTypeToASTType(m_type));
      if (IsSetInitialValue()) {
        stringstream valstr;
        valstr << GetInitialValue();
        ASTNode* val = parseStringToASTNode(valstr.str());
        m_astnode->addChild(val);
      }
      else if (IsSetInitialVariable()) {
        ASTNode* var = new ASTNode(AST_NAME);
        var->setName(GetInitialVariable()->GetNameDelimitedBy(g_registry.GetCC()).c_str());
        m_astnode->addChild(var);
      }
      else {
        assert(false);
      }
      m_astnode->addChild(rhs);
    }
  }
  else {
    m_astnode = rhs;
  }
}

#ifdef LIBSBML_HAS_PACKAGE_FBC
void setBound(const string& id, bool isLower, FbcReactionPlugin* fbrxn)
{
    if (isLower) {
        fbrxn->setLowerFluxBound(id);
    }
    else {
        fbrxn->setUpperFluxBound(id);
    }
}

void setOneHalf(const Formula& formula, bool isLower, FbcReactionPlugin* fbrxn, Model* model)
{
    if (formula.IsEmpty()) {
        return;
    }
    //If it's a single variable, just set the flux bound to that.
    if (formula.IsSingleVariable()) {
        setBound(formula.ToSBMLString(), isLower, fbrxn);
        return;
    }
    //Otherwise, if it's a value, create a parameter and set the flux bound.  Assume that any parameter with the same ID will be something we created earlier, so that we don't flood the model with a bunch of variables that are all '0' or whatever.
    if (formula.IsDouble()) {
        stringstream ss;
        ss << formula.GetDouble();
        string id = "fb_" + ss.str();
        replace(id.begin(), id.end(), '.', '_');
        size_t neg = id.find('-');
        if (neg != string::npos) {
            id.replace(neg, 1, "neg_");
        }
        Parameter* param = model->getParameter(id);
        if (param == NULL) {
            param = model->createParameter();
            param->setId(id);
            param->setConstant(true);
            param->setValue(formula.GetDouble());
        }
        setBound(id, isLower, fbrxn);
        return;
    }
    //Finally, it's some formula.  Set up a parameter with this formula as its assignment rule.
    stringstream id("fb0");
    int index = 0;
    Parameter* param = model->getParameter(id.str());
    while (param != NULL) {
        index++;
        id.clear();
        id << "fb_" << index;
        param = model->getParameter(id.str());
    }
    param = model->createParameter();
    param->setId(id.str());
    param->setConstant(false);
    AssignmentRule* ar = model->createAssignmentRule();
    ar->setVariable(id.str());
    ASTNode* astn = parseStringToASTNode(formula.ToSBMLString());
    ar->setMath(astn);
    delete astn;
}

void AntimonyConstraint::addFluxBounds(Model* model) const
{
    if (!isFluxBound()) {
        return;
    }
    Reaction* rxn = model->getReaction(m_rxnId);
    FbcReactionPlugin* fbrxn = static_cast<FbcReactionPlugin*>(rxn->getPlugin("fbc"));
    setOneHalf(m_fbLower, true, fbrxn, model);
    setOneHalf(m_fbUpper, false, fbrxn, model);
}

bool areCompatible(ASTNodeType_t first, ASTNodeType_t second)
{
    if (first == AST_RELATIONAL_GT || first == AST_RELATIONAL_GEQ) {
        if (second == AST_RELATIONAL_GT || second == AST_RELATIONAL_GEQ) {
            return true;
        }
        return false;
    }
    if (first==AST_RELATIONAL_LT || first == AST_RELATIONAL_LEQ) {
        if (second == AST_RELATIONAL_LT || second == AST_RELATIONAL_LEQ) {
            return true;
        }
        return false;
    }
    return false;
}

bool AntimonyConstraint::calculateFluxBounds()
{
  if (!m_rxnId.empty()) {
    //Already calculated
    return m_rxnId != "--";
  }
  if (m_type == constNEQ) {
    m_rxnId = "--";
    return false;
  }
  if (m_astnode == NULL) {
    calculateASTNode();
  }
  if (m_astnode == NULL) {
    assert(false);
    m_rxnId = "--";
    return false;
  }
  unsigned int numchildren = m_astnode->getNumChildren();
  ASTNodeType_t asttype = m_astnode->getType();
  Module* mod = g_registry.GetModule(m_module);
  if (m_astnode->isRelational()
      && asttype != AST_RELATIONAL_NEQ
      && numchildren >= 2 && numchildren <= 3) {
      const ASTNode* c1 = m_astnode->getChild(0);
      const ASTNode* c2 = m_astnode->getChild(1);
      if (mod == NULL) {
          assert(false);
          m_rxnId = "--";
          return false;
      }
      if (numchildren == 3) {
          //c2 must be a reaction ID.
          if (c2->getType() != AST_NAME) {
              m_rxnId = "--";
              return false;
          }
          string id = c2->getName();
          if (!IsReactionID(id)) {
              m_rxnId = "--";
              return false;
          }
          //c2 is a reaction id!  Store, and set c1 and c2 as lower/upper bounds
          m_rxnId = id;
          const ASTNode* c3 = m_astnode->getChild(2);
          std::string c1str = parseASTNodeToString(c1);
          std::string c3str = parseASTNodeToString(c3);
          if (asttype == AST_RELATIONAL_GEQ || asttype == AST_RELATIONAL_GT) {
              setFormulaWithString(c1str, &m_fbUpper, mod);
              setFormulaWithString(c3str, &m_fbLower, mod);
          }
          else if (asttype == AST_RELATIONAL_LEQ || asttype == AST_RELATIONAL_LT) {
              setFormulaWithString(c1str, &m_fbLower, mod);
              setFormulaWithString(c3str, &m_fbUpper, mod);
          }
          else if (asttype == AST_RELATIONAL_EQ) {
              setFormulaWithString(c1str, &m_fbLower, mod);
              setFormulaWithString(c3str, &m_fbUpper, mod);
          }
          return true;
      }
      //Otherwise there's just two children:
      assert(c1 != NULL);
      assert(c2 != NULL);
      bool correct = false;
      std::string c_str;
      if (c2->getType() == AST_NAME && IsReactionID(c2->getName())) {
          m_rxnId = c2->getName();
          c_str = parseASTNodeToString(c1);
          correct = true;
      }
      else if (c1->getType() == AST_NAME && IsReactionID(c1->getName())) {
          m_rxnId = c1->getName();
          c_str = parseASTNodeToString(c2);
          correct = true;
          if (asttype == AST_RELATIONAL_GEQ || asttype == AST_RELATIONAL_GT) {
              asttype = AST_RELATIONAL_LT;
          }
          else if (asttype == AST_RELATIONAL_LEQ || asttype == AST_RELATIONAL_LT) {
              asttype = AST_RELATIONAL_GT;
          }
      }
      if (!correct) {
          m_rxnId = "--";
          return false;
      }
      if (asttype == AST_RELATIONAL_GEQ || asttype == AST_RELATIONAL_GT) {
          setFormulaWithString(c_str, &m_fbUpper, mod);
      }
      else if (asttype == AST_RELATIONAL_LEQ || asttype == AST_RELATIONAL_LT) {
          setFormulaWithString(c_str, &m_fbLower, mod);
      }
      else if (asttype == AST_RELATIONAL_EQ) {
          setFormulaWithString(c_str, &m_fbUpper, mod);
          setFormulaWithString(c_str, &m_fbLower, mod);
      }
      else {
          //Not a flux bound.  I think.
          m_rxnId = "--";
          return false;
      }
      return true;
  }
  if (m_astnode->getType() == AST_LOGICAL_AND && m_astnode->getNumChildren()==2) {
    const ASTNode* c1 = m_astnode->getChild(0);
    const ASTNode* c2 = m_astnode->getChild(1);
    if (!c1->isRelational() || !c2->isRelational()) {
        m_rxnId = "--";
        return false;
    }
    ASTNodeType_t c1type = c1->getType();
    ASTNodeType_t c2type = c2->getType();
    if (c1type == AST_RELATIONAL_NEQ || c2type == AST_RELATIONAL_NEQ) {
        m_rxnId = "--";
        return false;
    }
    if (!areCompatible(c1type, c2type)) {
        m_rxnId = "--";
        return false;
    }
    if (c1->getNumChildren() != 2 || c2->getNumChildren() != 2) {
        m_rxnId = "--";
        return false;
    }
    if (c1->getChild(1)->getType() != AST_NAME || c2->getChild(0)->getType() != AST_NAME) {
        m_rxnId = "--";
        return false;
    }
    string id = c1->getChild(1)->getName();
    if (id != c2->getChild(0)->getName()) {
        m_rxnId = "--";
        return false;
    }
    if (!IsReactionID(id)) {
        m_rxnId = "--";
        return false;
    }
    //It's what we hoped it was:
    m_rxnId = id;
    string c1str = parseASTNodeToString(c1->getChild(0));
    string c2str = parseASTNodeToString(c2->getChild(1));
    if (c1type == AST_RELATIONAL_LT || c1type == AST_RELATIONAL_LEQ) {
        setFormulaWithString(c1str, &m_fbLower, mod);
        setFormulaWithString(c2str, &m_fbUpper, mod);
    }
    else {
        setFormulaWithString(c1str, &m_fbUpper, mod);
        setFormulaWithString(c2str, &m_fbLower, mod);
    }
    return true;
  }
  return false;
}

bool AntimonyConstraint::isFluxBound() const
{
    return !(m_rxnId == "--");
}

bool AntimonyConstraint::IsReactionID(const string& rxnid) const
{
  Module* mod = g_registry.GetModule(m_module);
  vector<string> rxname;
  rxname.push_back(rxnid);
  const Variable* idvar = mod->GetVariable(rxname);
  if (idvar == NULL) {
    //Try splitting up the rxnid;
    string item = rxnid;
    size_t doubleunders = item.find("__");
    while (doubleunders != string::npos) {
      item.replace(doubleunders,1,"");
      doubleunders = item.find("__");
    }
    stringstream ss(rxnid);
    rxname.clear();
    while (getline(ss, item, '_')) {
      rxname.push_back(item);
    }
    idvar = mod->GetVariable(rxname);
  }
  if (idvar==NULL || !IsReaction(idvar->GetType())) {
    return false;
  }
  return true;
}

void AntimonyConstraint::SetLowerFBFormula(Variable* var)
{
    m_fbLower.Clear();
    m_fbLower.AddVariable(var);
}

void AntimonyConstraint::SetUpperFBFormula(Variable* var)
{
    m_fbUpper.Clear();
    m_fbUpper.AddVariable(var);
}

void AntimonyConstraint::setReactionId(const std::string& rxnid)
{
    m_rxnId = rxnid;
}

#endif

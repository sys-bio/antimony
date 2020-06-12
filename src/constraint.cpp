#include <cassert>
#include "constraint.h"
#include "variable.h"
#include "sbmlx.h"
#include "registry.h"
#include "stringx.h"

using namespace std;

AntimonyConstraint::AntimonyConstraint()
  : m_formula()
  , m_isSetInitialValue(false)
  , m_initialValue(0.0)
  , m_initialVariable()
  , m_type(constNONE)
  , m_name()
  , m_module()
#ifndef NSBML
  , m_astnode(NULL)
#endif
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_isSetFB(false)
  , m_fbLeft(3,1)
  , m_fbRight(3,1)
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
#ifndef NSBML
  , m_astnode(constraint.m_astnode)
#endif
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_isSetFB(constraint.m_isSetFB)
  , m_fbLeft(constraint.m_fbLeft)
  , m_fbRight(constraint.m_fbRight)
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
#ifndef NSBML
  , m_astnode(NULL)
#endif
#ifdef LIBSBML_HAS_PACKAGE_FBC
  , m_isSetFB(false)
  , m_fbLeft(3,1)
  , m_fbRight(3,1)
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
#ifndef NSBML
  if (onlyformula) return;
  ASTNode* astnode = parseStringToASTNode(formula->ToSBMLString());
  SetWithASTNode(astnode);
  delete astnode;
#endif
}

#ifndef NSBML
void AntimonyConstraint::SetWithASTNode(const ASTNode* constnode)
{
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
#endif

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
#ifndef NSBML
  delete m_astnode;
  m_astnode = NULL;
#ifdef LIBSBML_HAS_PACKAGE_FBC
  m_fbLeft.unsetOperation();
  m_fbRight.unsetOperation();
#endif
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

#ifndef NSBML
const ASTNode* AntimonyConstraint::getASTNode() const
{
  return m_astnode;
}

void AntimonyConstraint::calculateASTNode()
{
  if (m_astnode != NULL) return;

  ASTNode* rhs = parseStringToASTNode(m_formula.ToSBMLString());
  if (m_type != constNONE) {
    if (rhs->getType() == ConstraintTypeToASTType(m_type) && rhs->getType() != AST_RELATIONAL_NEQ) {
      if (IsSetInitialValue()) {
        ASTNode* val = new ASTNode(AST_REAL);
        val->setValue(GetInitialValue());
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
        ASTNode* val = new ASTNode(AST_REAL);
        val->setValue(GetInitialValue());
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
        ASTNode* val = new ASTNode(AST_REAL);
        val->setValue(GetInitialValue());
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
#endif

#ifdef LIBSBML_HAS_PACKAGE_FBC
void AntimonyConstraint::addFluxBounds(Model* sbml) const
{
  if (m_fbLeft.isSetOperation()) {
    FbcModelPlugin* fbcmp = static_cast<FbcModelPlugin*>(sbml->getPlugin("fbc"));
    fbcmp->addFluxBound(&m_fbLeft);
    if (m_fbRight.isSetOperation()) {
      fbcmp->addFluxBound(&m_fbRight);
    }
  }
}

bool AntimonyConstraint::calculateFluxBounds()
{
  m_isSetFB = true;
  if (m_type == constNEQ) {
    return false;
  }
  if (m_astnode == NULL) {
    calculateASTNode();
  }
  if (m_astnode == NULL) {
    assert(false);
    return false;
  }
  m_fbLeft.setId(ToStringFromVecDelimitedBy(m_name, "__"));
  m_fbRight.setId(ToStringFromVecDelimitedBy(m_name, "__") + "_b");
  unsigned int numchildren = m_astnode->getNumChildren();
  if (m_astnode->isRelational() 
    && m_astnode->getType() != AST_RELATIONAL_NEQ
    && numchildren >= 2 && numchildren <= 3) {
    const ASTNode* c1 = m_astnode->getChild(0);
    const ASTNode* c2 = m_astnode->getChild(1);
    Module* mod = g_registry.GetModule(m_module);
    if (mod==NULL) {
      assert(false);
      return false;
    }
    if (numchildren == 3) {
      //c2 must be a reaction ID.
      if (c2->getType() != AST_NAME){
        return false;
      }
      string id = c2->getName();
      if (!IsReactionID(id)) {
        return false;
      }
      //c2 is a reaction id!  Now, c1 and c3 have to be numbers or variables.
      const ASTNode* c3 = m_astnode->getChild(2);
      if (c1->isNumber() && c3->isNumber()) {
        //We can handle this in FBC l1
        m_fbLeft.setReaction(id);
        m_fbLeft.setValue(GetValueFrom(c1));
        m_fbLeft.setOperation(getReverseFBOperationFrom(m_astnode->getType()));

        m_fbRight.setReaction(id);
        m_fbRight.setValue(GetValueFrom(c3));
        m_fbRight.setOperation(getFBOperationFrom(m_astnode->getType()));
        return true;
      }
      else {
        //In FBC v2 it'll be OK if it's a parameter, but not until then.
        return false;
      }
    }
    //Otherwise there's just two children:
    assert(c1 != NULL);
    assert(c2 != NULL);
    FluxBoundOperation_t fb_op = getFBOperationFrom(m_astnode->getType());
    if (c1->isNumber() && c2->getType() == AST_NAME) {
      //Reverse everything.
      const ASTNode* temp = c2;
      c2 = c1;
      c1 = temp;
      fb_op = getReverseFBOperationFrom(m_type);
    }
    if (c1->getType() == AST_NAME && c2->isNumber()) {
      string id = c1->getName();
      if (!IsReactionID(id)) {
        return false;
      }
      m_fbLeft.setReaction(id);
      m_fbLeft.setValue(GetValueFrom(c2));
      m_fbLeft.setOperation(fb_op);
      return true;
    }
    else {
      //Can't (yet) handle this situation.
      return false;
    }
  }
  if (m_astnode->getType() == AST_LOGICAL_AND && m_astnode->getNumChildren()==2) {
    const ASTNode* c1 = m_astnode->getChild(0);
    const ASTNode* c2 = m_astnode->getChild(1);
    if (!c1->isRelational() || !c2->isRelational()) {
      return false;
    }
    if (c1->getType() == AST_RELATIONAL_NEQ || c2->getType() == AST_RELATIONAL_NEQ) {
      return false;
    }
    m_fbLeft = GetFluxBoundFrom(c1);
    m_fbRight = GetFluxBoundFrom(c2);
    if (m_fbLeft.isSetOperation() || m_fbRight.isSetOperation()) {
      m_fbLeft.setId(ToStringFromVecDelimitedBy(m_name, "__"));
      m_fbRight.setId(ToStringFromVecDelimitedBy(m_name, "__") + "_b");
      return true;
    }
  }
  return false;
}

FluxBound AntimonyConstraint::GetFluxBoundFrom(const ASTNode* node) const
{
  FluxBound fb(3,1);
  if (node->getNumChildren() != 2) {
    return fb;
  }
  const ASTNode* c1 = node->getChild(0);
  const ASTNode* c2 = node->getChild(1);
  if (c1->getType() == AST_NAME && IsReactionID(c1->getName()) && c2->isNumber()) {
    fb.setReaction(c1->getName());
    fb.setValue(GetValueFrom(c2));
    fb.setOperation(getFBOperationFrom(node->getType()));
  }
  else if (c2->getType() == AST_NAME && IsReactionID(c2->getName()) && c1->isNumber()) {
    fb.setReaction(c2->getName());
    fb.setValue(GetValueFrom(c1));
    fb.setOperation(getReverseFBOperationFrom(node->getType()));
  }
  return fb;
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


bool AntimonyConstraint::ContainsFlux(const FluxBound* fb) const
{
  if (!m_isSetFB) {
    AntimonyConstraint copy = *this;
    copy.calculateFluxBounds();
    if (FluxesMatch(fb, &copy.m_fbLeft)) return true;
    if (FluxesMatch(fb, &copy.m_fbRight)) return true;
    return false;
  }
  if (FluxesMatch(fb, &m_fbLeft)) return true;
  if (FluxesMatch(fb, &m_fbRight)) return true;
  return false;
}

void AntimonyConstraint::SetFromFluxBound(const FluxBound* fb)
{
  m_initialVariable.clear();
  m_initialVariable.push_back(fb->getReaction());
  m_type = getConstraintTypeFrom(fb->getFluxBoundOperation());
  m_formula.Clear();
  m_formula.AddNum(fb->getValue());
}

#endif

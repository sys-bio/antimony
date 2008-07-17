#include <assert.h>

#include "module.h"
#include "variable.h"
#include "registry.h"

using namespace std;

Variable::Variable(const string name, const Module* module)
  : m_name(),
    m_namespace(module->GetModuleName()),
    m_sameVariable(),
    m_listseparately(false),
    m_valFormula(),
    m_valReaction(),
    m_valModule(),
    m_upstream(),
    m_downstream(),
    m_type(varUndefined),
    m_const(false)

{
  m_name.push_back(name);
}

vector<string> Variable::GetName() const
{
  return m_name;
}

string Variable::GetNameDelimitedBy(char cc) const
{
  string retval;
  vector<string> name = m_name;
  if (m_printedname.size() > 0) {
    name = m_printedname;
  }
  assert(name.size() > 0);
  if (name.size()) {
    retval += name[0];
  }
  for (size_t i=1; i<name.size(); i++) {
    retval += cc + name[i];
  }
  return retval;
}

string Variable::GetFormulaStringDelimitedBy(char cc) const
{
  Variable* upvar = NULL;
  if (m_upstream.size() > 0) {
    upvar=g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
  }
  if (GetFormula() == NULL) return "";
  return GetFormula()->ToDelimitedStringWithUpvar(cc, upvar);
}

var_type Variable::GetType() const
{
  /*
  if (m_sameVariable.size() > 0) {
    Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    assert(samevar != this);
    return samevar->GetType();
  }
  else
  */
  return m_type;
}


const Formula* Variable::GetFormula() const
{
  if (m_sameVariable.size() > 0) {
    const Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    if (samevar != NULL) {
      return samevar->GetFormula();
    }
    return NULL;
  }
  else switch (m_type) {
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varUndefined:
    assert(m_valReaction.IsEmpty());
    assert(m_valModule.size()==0);
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    assert(m_valModule.size() == 0);
    //assert(m_valFormula.IsEmpty());
    return m_valReaction.GetFormula();
  case varModule:
    assert(m_valReaction.IsEmpty());
    assert(m_valFormula.IsEmpty());
    assert(m_valModule.size()==1);
    return m_valModule[0].GetFormula();
  }
  assert(false); //Uncaught variable type
  return &(m_valFormula);
}

Formula* Variable::GetFormula()
{
  if (m_sameVariable.size() > 0) {
    Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    if (samevar != NULL) {
      return samevar->GetFormula();
    }
    return NULL;
  }
  else switch (m_type) {
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varUndefined:
    assert(m_valReaction.IsEmpty());
    assert(m_valModule.size()==0);
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    assert(m_valModule.size() == 0);
    //assert(m_valFormula.IsEmpty());
    return m_valReaction.GetFormula();
  case varModule:
    assert(m_valReaction.IsEmpty());
    assert(m_valFormula.IsEmpty());
    assert(m_valModule.size()==1);
    return m_valModule[0].GetFormula();
  }
  assert(false); //Uncaught variable type
  return &(m_valFormula);
}

const Reaction* Variable::GetReaction() const
{
  assert(IsReaction(m_type));
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetReaction();
  }
  //assert(!m_valReaction.IsEmpty());
  //assert(m_valFormula.IsEmpty());
  assert(m_valModule.size() == 0);
  return &(m_valReaction);
}

const Module* Variable::GetModule() const
{
  assert(m_type == varModule);
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetModule();
  }
  assert(m_valModule.size() == 1);
  assert(m_valFormula.IsEmpty());
  assert(m_valReaction.IsEmpty());
  return &(m_valModule[0]);
}

Module* Variable::GetModule()
{
  assert(m_type == varModule);
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetModule();
  }
  assert(m_valModule.size() == 1);
  assert(m_valFormula.IsEmpty());
  assert(m_valReaction.IsEmpty());
  return &(m_valModule[0]);
}

Variable* Variable::GetSubVariable(const std::string* name)
{
  if (m_type != varModule) {
    assert(false);
    //Throw an error  LS DEBUG
  }
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetSubVariable(name);
  }
  assert(m_valModule.size() == 1);
  return m_valModule[0].GetSubVariable(name);
}

bool Variable::GetIsConst() const
{
  if (m_sameVariable.size() > 0) {
    const Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    if ((samevar != NULL) && (samevar != this)) {
      return samevar->GetIsConst();
    }
  }
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
    return m_valFormula.GetIsConst();
  case varSpeciesUndef:
  case varSpeciesProtein:
    if (!m_valFormula.GetIsConst()) {
      return false;
    }
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    if (!m_valReaction.GetIsConst()) {
      return false;
    }
    break;
  case varModule:
    return false;
  case varUndefined:
    return true;
  }
  return m_const;
}

bool Variable::GetIsEquivalentTo(const Variable* var) const
{
  if (var->GetName() == m_name) return true;
  Module* mod = g_registry.GetModule(m_namespace);
  assert(mod != NULL);
  if (IsPointer()) {
    Variable* otherme = mod->GetVariable(GetPointerName());
    assert(otherme != NULL);
    if (otherme->GetIsEquivalentTo(var)) return true;
  }
  if (var->IsPointer()) {
    Variable* otheryou = mod->GetVariable(var->GetPointerName());
    assert(otheryou != NULL);
    if (GetIsEquivalentTo(otheryou)) return true;
  }
  return false;
}

bool Variable::IsDNAStart() const
{
  if (!IsDNA(m_type)) {
    return false;
  }
  if (m_upstream.size() == 1 && m_upstream[0] == "[open]") {
    return true;
  }
  if (m_downstream.size() > 0 && m_upstream.size() == 0) {
    return true;
  }
  return false;
}

bool Variable::IsUnlinked() const
{
  return (m_upstream.size()==0 && m_downstream.size()==0);
}

bool Variable::HasOpenUpstream() const
{
  return (m_upstream.size()==1 && m_upstream[0]=="[open]");
}

bool Variable::HasOpenDownstream() const
{
  return (m_downstream.size()==1 && m_downstream[0]=="[open]");
}

vector<string> Variable::GetDNAStringDelimitedBy(char cc) const
{
  vector<string> dna;
  if (m_upstream.size() == 1 && m_upstream[0] == "[open]") {
    dna.push_back("--");
  }
  dna.push_back(GetNameDelimitedBy(cc));
  if (m_downstream.size() == 1 && m_downstream[0] == "[open]") {
    dna.push_back("--");
    return dna;
  }
  if (m_downstream.size() == 0) {
    return dna;
  }
  dna.push_back("--");
  vector<string> moredna = g_registry.GetModule(m_namespace)->GetVariable(m_downstream)->GetDNAStringDelimitedBy(cc);
  dna.insert(dna.end(), moredna.begin(), moredna.end());
  return dna;
}  

void Variable::SetType(var_type newtype)
{
  assert(m_type == varUndefined ||
         m_type == newtype ||
         (IsReaction(m_type) && IsReaction(newtype)) ||
         (IsSpecies(m_type)  && IsSpecies(newtype)) ||
         (IsDNA(m_type)      && IsDNA(newtype)) ||
         (IsSpecies(newtype) && m_type == varFormulaUndef)
         );
  if ((newtype == varSpeciesUndef ||
       newtype == varReactionUndef) &&
      m_type != varUndefined) {
    return;
  }
  if (IsDNA(m_type) && newtype == varDNA) {
    return;
  }
  m_type = newtype;
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetType(newtype);
  }
  if (IsDNA(m_type) && !m_valReaction.LeftIsEmpty()) {
    assert(false);
    //throw an error --LS DEBUG
  }
}

void Variable::SetFormula(Formula* formula)
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetFormula(formula);
  }
  if (formula->IsSimpleVariable()) {
    Variable* newvar = g_registry.GetModule(m_namespace)->GetVariable(formula->GetSimpleVariable());
    if (newvar == this) {
      //Setting something equal to itself--do nothing.
      //LS DEBUG:  emit a warning?
      return;
    }
    if (newvar->GetName().size() < GetName().size()) {
      //Synchronize the longer name (and therefore the subvariable) to the
      // shorter name
      newvar->Synchronize(this);
    }
    else {
      bool dosync = false;
      if (newvar->GetName().size() < GetName().size()) {
        dosync = true;
      }
      else for (size_t nname=0; nname<GetName().size()-1; nname++) {
        if (newvar->GetName()[nname] != GetName()[nname]) {
          //The variables come from different modules--sync them.
          dosync = true;
        }
      }
      if (dosync) {
        Synchronize(newvar);
        return;
      }
    }
  }
  if (formula->ContainsVar(m_namespace, m_name)) {
    cout << "Loop detected:  " << GetNameDelimitedBy('.').c_str() << "'s definition either includes itself directly ('s5 = 6 + s5') or by proxy ('s5 = 8*d3' and 'd3 = 9*s5')." << endl; 
    //LS DEBUG:  throw an error
    assert(false);
  }
  switch (m_type) {
  case varSpeciesUndef:
  case varSpeciesProtein:
    assert(m_valReaction.IsEmpty());
    assert(m_valModule.size() == 0);
    m_valFormula = *formula;
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    assert(m_valModule.size() == 0);
    assert(m_valFormula.IsEmpty());
    //assert(!m_valReaction.IsEmpty());
    m_valReaction.SetFormula(formula);
    break;
  case varModule:
    assert(m_valReaction.IsEmpty());
    assert(m_valFormula.IsEmpty());
    assert(m_valModule.size() == 1);
    m_valModule[0].SetFormula(formula);
    break;
  case varUndefined:
    assert(m_valFormula.IsEmpty());
    m_type = varFormulaUndef;
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
    assert(m_valReaction.IsEmpty());
    assert(m_valModule.size() == 0);
    m_valFormula = *formula;
    break;
  }

}

Reaction* Variable::SetReaction(Reaction* rxn)
{
  //LS DEBUG:  calling something a reaction that used to be a formula is OK
  assert(m_type==varUndefined || m_type==varDNA || IsReaction(m_type));
  m_valReaction = *rxn;
  if (m_type==varUndefined) {
    if (IsInteraction(rxn->GetType())) {
      m_type = varInteraction;
    }
    else {
      m_type = varReactionUndef;
    }
  }
  else if (m_type==varDNA) {
    m_type = varReactionGene;
    if (!m_valFormula.IsEmpty()) {
      m_valReaction.SetFormula(&m_valFormula);
      Formula blankform;
      m_valFormula = blankform;
    }
  }
  else if (!IsReaction(m_type)) {
    assert(false);
    //Throw an error
  }
  return &m_valReaction;
}

void Variable::SetNewTopName(string newmodname, string newtopname)
{
  m_namespace = newmodname;
  m_name.insert(m_name.begin(), newtopname);
  if (m_sameVariable.size() > 0) {
    m_sameVariable.insert(m_sameVariable.begin(), newtopname);
  }
  if (m_printedname.size() > 0) {
    m_printedname.insert(m_printedname.begin(), newtopname);
  }
  if (!m_valFormula.IsEmpty()) {
    m_valFormula.SetNewTopName(m_namespace, newtopname);
  }
  if (!m_valReaction.IsEmpty()) {
    m_valReaction.SetNewTopName(m_namespace, newtopname);
  }
  if (m_valModule.size() > 0) {
    assert(m_valModule.size() == 1);
    m_valModule[0].SetNewTopName(m_namespace, newtopname);
  }
  if (m_upstream.size() > 0 &&
      m_upstream[0] != "[open]") {
    m_upstream.insert(m_upstream.begin(), newtopname);
  }
  if (m_downstream.size() > 0 &&
      m_downstream[0] != "[open]") {
    m_downstream.insert(m_downstream.begin(), newtopname);
  }
}

void Variable::SetPrintedName(std::vector<std::string> printedname)
{
  m_printedname = printedname;
}

void Variable::SetIsConst(bool constant)
{
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaPromoter:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varSpeciesProtein:
  case varUndefined:
    if (!m_valFormula.GetIsConst() && constant) {
      assert(false);
      //Throw an error--LS DEBUG
    }
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    if (!m_valReaction.GetIsConst() && constant) {
      assert(false);
      //Throw an error--LS DEBUG
    }
    break;
  case varModule:
    assert(!constant);
    if (!constant) {
      //Throw an error--LS DEBUG
    }
    break;
  }
  m_const = constant;
}

void Variable::SetOpenUpstream()
{
  if (m_upstream.size()>0) {
    Variable* upvar=g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
    if (upvar != NULL) {
      return upvar->SetOpenUpstream();
    }
    else {
      assert(m_upstream[0] == "[open]");
      return;
    }
  }
  string open = "[open]";
  m_upstream.push_back(open);
}

void Variable::SetOpenDownstream()
{
  if (m_downstream.size()>0) {
    Variable* downvar=g_registry.GetModule(m_namespace)->GetVariable(m_downstream);
    if (downvar != NULL) {
      return downvar->SetOpenDownstream();
    }
  }
  string open = "[open]";
  m_downstream.clear();
  m_downstream.push_back(open);
}

void Variable::SetUpstream(Variable* var)
{
  Variable* upvar = g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
  if (upvar == NULL) {
    m_upstream = var->GetName();
  }
  else {
    //assert(false); //Should this ever happen?
    return upvar->SetUpstream(var);
  }
  Formula* form = GetFormula();
  if (form->IsEmpty()) {
    form->AddEllipses();
  }
}

void Variable::SetDownstream(Variable* var) {
  Variable* downvar = g_registry.GetModule(m_namespace)->GetVariable(m_downstream);
  if (downvar == NULL) {
    assert(m_downstream.size() == 1);
    assert(m_downstream[0] == "[open]");
    m_downstream = var->GetName();
  }
  else {
    //assert(false); //Should this ever happen?
    return downvar->SetDownstream(var);
  }
  var->SetUpstream(this);
}

void Variable::Synchronize(Variable* clone)
{
  if (m_sameVariable.size() != 0) {
    Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    samevar->Synchronize(clone);
  }

  assert(m_namespace == clone->GetNamespace());
  m_sameVariable = clone->GetName();
  if (m_printedname.size() > 0) {
    clone->SetPrintedName(m_printedname);
  }
  else {
    clone->SetPrintedName(m_name);
  }
  if (m_name == m_sameVariable) {
    //Don't set a variable to be equal to itself!
    m_sameVariable.clear();
    return;
  }
  if ((m_type == varUndefined) ||
      (m_type == varReactionUndef && IsReaction(clone->GetType())) ||
      (m_type == varSpeciesUndef && IsSpecies(clone->GetType())) ){
    m_type = clone->GetType();
  }
  else {
    clone->SetType(m_type);
  }

  if (!m_valFormula.IsEmpty()) {
    clone->SetFormula(&m_valFormula);
    m_valFormula.Clear();
  }
  if (!m_valReaction.IsEmpty()) {
    clone->SetReaction(&m_valReaction);
    m_valReaction.Clear();
  }
  if (m_valModule.size() > 0) {
    assert(false); //I want to know what someone wants when they try this,
    // because I'm not convinced I'm doing the right thing below.  LS DEBUG
    string modname = m_valModule[0].GetModuleName();
    clone->ImportModule(&modname);
    m_valModule.clear();
  }

  clone->SetIsConst(GetIsConst());
}

void Variable::ImportModule(const string* modname)
{
  assert(m_name.size() == 1);
  assert(m_type == varUndefined);
  Module newmod(*g_registry.GetModule(*modname), m_name[0], m_namespace);
  m_valModule.push_back(newmod);
  m_type = varModule;
  g_registry.SetCurrentImportedModule(m_name);
}

bool Variable::CheckDoesNotIncludeSelf()
{
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(m_namespace, m_name)) {
      return true;
    }
  }
  return false;
}

string Variable::ToString() const
{
  return GetNameDelimitedBy('.') + " (" + VarTypeToString(m_type) + ")";
}

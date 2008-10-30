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
    m_valEvent(),
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

string Variable::GetFormulaStringWithEllipses(char cc) const
{
  if (GetFormula() == NULL) return "";
  return GetFormula()->ToDelimitedStringWithEllipses(cc);
}

var_type Variable::GetType() const
{
  //LS NOTE:  don't get the type of the equivalent variable--that can lead to infinite loops.
  return m_type;
}


const Formula* Variable::GetFormula() const
{
  if (m_sameVariable.size() > 0) {
    const Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    if (samevar != NULL) {
      return samevar->GetFormula();
    }
    assert(false);
    return NULL;
  }
  else switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varUndefined:
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return m_valEvent.GetTrigger();
  }
  assert(false); //Uncaught variable type
  g_registry.SetError("Programming error:  uncaught variable type.  Must rewrite to fix.");
  return NULL;
}

Formula* Variable::GetFormula()
{
  if (m_sameVariable.size() > 0) {
    Module* mod = g_registry.GetModule(m_namespace);
    Variable* samevar = mod->GetVariable(m_sameVariable);
    if (samevar != NULL) {
      return samevar->GetFormula();
    }
    samevar = mod->GetVariable(m_sameVariable);
    assert(false);
    return NULL;
  }
  else switch (m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varUndefined:
    return &(m_valFormula);
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    return m_valReaction.GetFormula();
  case varModule:
    return m_valModule[0].GetFormula();
  case varEvent:
    return m_valEvent.GetTrigger();
  }
  assert(false); //Uncaught variable type
  g_registry.SetError("Programming error:  uncaught variable type.  Must rewrite to fix.");
  return NULL;
}

const AntimonyReaction* Variable::GetReaction() const
{
  assert(IsReaction(m_type));
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetReaction();
  }
  return &(m_valReaction);
}

const Module* Variable::GetModule() const
{
  assert(m_type == varModule);
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetModule();
  }
  return &(m_valModule[0]);
}

Module* Variable::GetModule()
{
  assert(m_type == varModule);
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetModule();
  }
  return &(m_valModule[0]);
}

const AntimonyEvent* Variable::GetEvent() const
{
  assert(m_type == varEvent);
  return &(m_valEvent);
}

AntimonyEvent* Variable::GetEvent()
{
  assert(m_type == varEvent);
  return &(m_valEvent);
}

Variable* Variable::GetSubVariable(const std::string* name)
{
  if (m_type != varModule) {
    return NULL;
  }
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetSubVariable(name);
  }
  assert(m_valModule.size() == 1);
  return m_valModule[0].GetSubVariable(name);
}

Variable* Variable::GetSameVariable()
{
  Variable* var = this;
  Variable* subvar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
  if (subvar == NULL) return var;
  while (var != subvar) {
    var = subvar;
    subvar = subvar->GetSameVariable();
  }
  return var;
}

Variable* Variable::GetUpstreamDNA() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetUpstreamDNA();
  }
  return g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
}

Variable* Variable::GetDownstreamDNA() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetDownstreamDNA();
  }
  return g_registry.GetModule(m_namespace)->GetVariable(m_downstream);
}




bool Variable::GetIsConst() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetIsConst();
  }
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
    return m_valFormula.GetIsConst();
  case varSpeciesUndef:
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
  case varEvent:
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

bool Variable::IsSameVarInNewModule(const Variable* origvar) const
{
  if (origvar==NULL) {
    return false;
  }
  vector<string> origname = origvar->GetName();
  vector<string> myname = m_name;
  if (origname.size() > myname.size()) {
    return false;
  }
  while (myname.size() > origname.size()) {
    myname.erase(myname.begin());
  }
  for (size_t nn=0; nn < myname.size(); nn++) {
    if (myname[nn] != origname[nn]) {
      return false;
    }
  }
  return true;
}

bool Variable::IsDNAStart() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->IsDNAStart();
  }
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

bool Variable::IsDNAStartForModule() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->IsDNAStartForModule();
  }
  if (IsDNAStart()) return true;
  if (m_upstream.size()==0) return false;
  size_t modlevel = m_name.size();
  if (m_printedname.size() > 0) {
    modlevel = m_printedname.size();
  }
  size_t uplevel = g_registry.GetModule(m_namespace)->GetVariable(m_upstream)->GetPrintedName().size();
  if (uplevel <= modlevel) return false;
  return true;
}

bool Variable::IsUnlinked(bool up) const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->IsUnlinked(up);
  }
  if (up) {
    if (m_upstream.size()==0 ||
        (m_upstream.size()==1 && m_upstream[0] == "[open]")) {
      return true;
    }
    return false;
  }
  else {
    if (m_downstream.size()==0 ||
        (m_downstream.size()==1 && m_downstream[0] == "[open]")) {
      return true;
    }
    return false;
  }
}

bool Variable::DoesNotLinkTo(Variable* var) const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->DoesNotLinkTo(var);
  }
  if (GetUpstreamDNA() != NULL) {
    return GetUpstreamDNA()->DoesNotLinkTo(var);
  }
  if (m_upstream.size() > 0 && m_upstream[0] != "[open]") {
    Variable* upvar = g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
    assert(upvar != NULL);
    return upvar->DoesNotLinkTo(var);
  }
  const Variable* nextvar = this;
  while (nextvar != NULL) {
    if (var == nextvar) {
      return false;
    }
    nextvar = nextvar->GetDownstreamDNA();
  }
  return true;
}
    

bool Variable::HasOpenUpstream() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->HasOpenUpstream();
  }
  return (m_upstream.size()==1 && m_upstream[0]=="[open]");
}

bool Variable::HasOpenDownstream() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->HasOpenDownstream();
  }
  return (m_downstream.size()==1 && m_downstream[0]=="[open]");
}

vector<string> Variable::GetDNAStringDelimitedBy(char cc) const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetDNAStringDelimitedBy(cc);
  }
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

string Variable::GetDNAStringForThisNamespace() const
{
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->GetDNAStringForThisNamespace();
  }
  string dna = "";
  if (IsDNAStart() == false && IsDNAStartForModule() == true) {
    //upstream is in another module
    dna = g_registry.GetModule(m_namespace)->GetVariable(m_upstream)->GetNameDelimitedBy('.');
    dna += "--";
  }
  else if (IsDNAStart() && IsDNAStartForModule() ) {
    if (m_upstream.size() == 1 && m_upstream[0] == "[open]") {
      dna = "--";
    }
  }
  dna += GetNameDelimitedBy('.');
  if (m_downstream.size() == 0) {
    return dna;
  }
  dna += "--";
  if (m_downstream.size() == 1 && m_downstream[0] == "[open]") {
    return dna;
  }
  if (m_downstream.size() > 1) {
    dna += g_registry.GetModule(m_namespace)->GetVariable(m_downstream)->GetNameDelimitedBy('.');
    return dna;
  }
  dna += g_registry.GetModule(m_namespace)->GetVariable(m_downstream)->GetDNAStringForThisNamespace();
  return dna;
}


bool Variable::SetType(var_type newtype)
{
  if (newtype == varUndefined) return false;
  if (newtype == m_type) return false;
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetType(newtype);
  }
  if (IsDNA(newtype) && !m_valReaction.LeftIsEmpty()) {
    g_registry.SetError("For now, we disallow DNA reactions (i.e. genes) to consume anything in the reaction they define:  the left side of the reaction must be empty (i.e  ' -> S1' and not 'G1 -> S1').");
    return true;
  }
  string error = "Unable to set the type of variable '" + GetNameDelimitedBy('.') + "' to " + VarTypeToString(newtype) + " because it is already set to be the incompatible type " + VarTypeToString(m_type) + ".  This situation can occur either with explicit type declaration or by using the variable in different, incompatible contexts.";
  switch(m_type) {
  case varSpeciesUndef:
    switch(newtype) {
    case varSpeciesUndef:
      //If they were both SpeciesUndef, we already returned.
      return false;
    case varFormulaUndef:
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
    case varUndefined:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varFormulaUndef:
    switch(newtype) {
    case varSpeciesUndef:
    case varFormulaUndef:
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
      m_type = newtype;
      return false;
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    case varUndefined:
      return false;
    }
  case varDNA:
    switch(newtype) {
    case varFormulaUndef:
    case varUndefined:
      return false;
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
      m_type = newtype;
      return false;
    case varReactionUndef:
      m_type = varReactionGene;
      return false;
    case varSpeciesUndef:
    case varInteraction:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varFormulaOperator:
    switch(newtype) {
    case varFormulaUndef:
    case varFormulaOperator:
    case varDNA:
    case varUndefined:
      return false;
    case varSpeciesUndef:
    case varReactionGene:
    case varReactionUndef:
    case varInteraction:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varReactionGene:
    switch(newtype) {
    case varFormulaUndef:
    case varDNA:
    case varReactionGene:
    case varReactionUndef:
    case varUndefined:
      return false;
    case varSpeciesUndef:
    case varFormulaOperator:
    case varInteraction:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varReactionUndef:
    switch(newtype) {
    case varReactionUndef:
    case varUndefined:
    case varFormulaUndef:
      return false;
    case varDNA:
    case varReactionGene:
      m_type = varReactionGene;
      return false;
    case varSpeciesUndef:
    case varFormulaOperator:
    case varInteraction:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varInteraction:
    switch(newtype) {
    case varUndefined:
    case varFormulaUndef:
    case varInteraction:
      return false;
    case varReactionUndef:
    case varDNA:
    case varReactionGene:
    case varSpeciesUndef:
    case varFormulaOperator:
    case varModule:
    case varEvent:
      g_registry.SetError(error); return true;
    }
  case varUndefined:
    m_type = newtype;
    return false;
  case varModule:
  case varEvent:
    g_registry.SetError(error); return true; //the already-a-module/event cases handled above.
  }

  assert(false); //uncaught vtype
  return false;
}

bool Variable::SetFormula(Formula* formula)
{
  string formstring = formula->ToStringDelimitedBy('.');
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetFormula(formula);
  }
  if (formula->IsSimpleVariable()) {
    Variable* newvar = g_registry.GetModule(m_namespace)->GetVariable(formula->GetSimpleVariable());
    if (GetIsEquivalentTo(newvar)) {
      //Setting something equal to itself--do nothing.
      //cout << "Already equivalent." << endl;
      return false;
    }
    if (newvar->GetName().size() < GetName().size()) {
      //Synchronize the longer name (and therefore the subvariable) to the
      // shorter name
      if (newvar->Synchronize(this)) return true;
      return false;
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
        if (Synchronize(newvar)) return true;
        return false;
      }
    }
  }
  if (formula->ContainsVar(this)) {
    g_registry.SetError("Loop detected:  " + GetNameDelimitedBy('.') + "'s definition either includes itself directly (i.e. 's5 = 6 + s5') or by proxy (i.e. 's5 = 8*d3' and 'd3 = 9*s5').");
    return true;
  }
  switch (m_type) {
  case varSpeciesUndef:
    m_valFormula = *formula;
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    m_valReaction.SetFormula(formula);
    break;
  case varModule:
    return m_valModule[0].SetFormula(formula);
  case varUndefined:
    m_type = varFormulaUndef;
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
    m_valFormula = *formula;
    break;
  case varEvent:
    m_valEvent.SetTrigger(*formula);
    break;
  }
  return false;
}

AntimonyReaction* Variable::SetReaction(AntimonyReaction* rxn)
{
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetReaction(rxn);
  }
  string formstring = rxn->GetFormula()->ToStringDelimitedBy('.');
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The reaction rate \"" + rxn->GetFormula()->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return NULL;
    }
    else {
      delete ASTform;
    }
  }
  assert(m_type==varUndefined || m_type==varDNA || m_type==varFormulaUndef || IsReaction(m_type));
  m_valReaction = *rxn;
  if (m_type==varUndefined) {
    if (IsInteraction(rxn->GetType())) {
      m_type = varInteraction;
    }
    else {
      m_type = varReactionUndef;
    }
  }
  if (m_type==varDNA) {
    m_type = varReactionGene;
  }
  if (!m_valFormula.IsEmpty()) {
    m_valReaction.SetFormula(&m_valFormula);
    Formula blankform;
    m_valFormula = blankform;
  }
  SetType(varReactionUndef);
  return &m_valReaction;
}

bool Variable::SetModule(const string* modname)
{
  assert(m_name.size() == 1);
  if (m_type != varUndefined) {
    g_registry.SetError("Cannot define '" + GetNameDelimitedBy('.') + "' to be model '" + *modname + "', because it is already a " + VarTypeToString(m_type) + ".");
    return true; //error
  }
  Module newmod(*g_registry.GetModule(*modname), m_name[0], m_namespace);
  m_valModule.push_back(newmod);
  m_type = varModule;
  g_registry.SetCurrentImportedModule(m_name);
  return false;
}

bool Variable::SetEvent(const AntimonyEvent* event)
{
  m_valEvent = *event;
  return SetType(varEvent);
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

bool Variable::SetIsConst(bool constant)
{
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetIsConst(constant);
  }
  string error = "Cannot set '" + GetNameDelimitedBy('.') + "' to be constant";
  switch(m_type) {
  case varFormulaUndef:
  case varFormulaOperator:
  case varDNA:
  case varSpeciesUndef:
  case varUndefined:
    if (!m_valFormula.GetIsConst() && constant) {
      g_registry.SetError(error + " because its rate constant or initial value contains something that is or cannot be constant (such as a floating species concentration).");
      return true;
    }
    break;
  case varReactionUndef:
  case varReactionGene:
  case varInteraction:
    if (constant) {
      g_registry.SetError(error + ".  Reactions and interactions are non-constant by definition.");
      return true;
    }
    break;
  case varModule:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for submodules.");
      return true;
    }
    break;
  case varEvent:
    if (!constant) {
      g_registry.SetError(error + ", as 'constantness' is undefined for events.");
      return true;
    }
    break;
  }
  m_const = constant;
  return false;
}

void Variable::SetOpenUpstream()
{
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetOpenUpstream();
  }
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
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetOpenDownstream();
  }
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
  if (m_sameVariable.size() > 0) {
    return g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetUpstream(var);
  }
  Variable* upvar = g_registry.GetModule(m_namespace)->GetVariable(m_upstream);
  if (upvar == NULL) {
    var = var->GetSameVariable();
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

void Variable::SetDownstream(Variable* var)
{
  if (m_sameVariable.size() > 0) {
    g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable)->SetDownstream(var);
  }
  Variable* downvar = g_registry.GetModule(m_namespace)->GetVariable(m_downstream);
  if (downvar == NULL) {
    assert(m_downstream.size() == 1);
    assert(m_downstream[0] == "[open]");
    var = var->GetSameVariable();
    m_downstream = var->GetName();
  }
  else {
    //assert(false); //Should this ever happen?
    return downvar->SetDownstream(var);
  }
  var->SetUpstream(this);
}

bool Variable::Synchronize(Variable* clone)
{
  //Check for error conditions
  assert(m_namespace == clone->GetNamespace());
  if (clone == NULL) {
    g_registry.SetError("No such variable in this module.");
    return true;
  }
  if (GetIsEquivalentTo(clone)) {
    //already equivalent--don't do anything
    // (Shouldn't be necessary from Variable:: calls, but this also gets called from the
    //  registry during parsing.) 
    //cout << "Already equivalent" << endl;
    return false;
  }

  //Check to make sure we don't synchronize variables that are already in each other's formulas.
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(clone)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy('.') + "' may not be set to be equal to '" + clone->GetNameDelimitedBy('.') + " because " + GetNameDelimitedBy('.') + "'s definition already includes " + clone->GetNameDelimitedBy('.') + " either directly or by proxy .");
      return true;
    }
  }
  form = clone->GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(this)) {
      g_registry.SetError("Loop detected:  '" + GetNameDelimitedBy('.') + "' may not be set to be equal to '" + clone->GetNameDelimitedBy('.') + " because " + clone->GetNameDelimitedBy('.') + "'s definition already includes " + GetNameDelimitedBy('.') + " either directly or by proxy .");
      return true;
    }
  }

  //If we already point to someone, let them point to the new thing instead.
  if (m_sameVariable.size() != 0) {
    Variable* samevar = g_registry.GetModule(m_namespace)->GetVariable(m_sameVariable);
    if (samevar->Synchronize(clone)) return true;
  }
  else {
    m_sameVariable = clone->GetName();
  }

  //Now, actually synchronize the data.
  if (m_printedname.size() > 0) {
    clone->SetPrintedName(m_printedname);
  }
  else {
    clone->SetPrintedName(m_name);
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
    clone->SetModule(&modname); //If we do, check the return value here.
    m_valModule.clear();
  }

  //DNA strands information.
  if (m_upstream.size() > 0) {
    Variable* upvar = GetUpstreamDNA();
    Variable* cloneupvar = clone->GetUpstreamDNA();
    if (upvar == NULL) {
      if (cloneupvar == NULL) {
        clone->SetOpenUpstream();
      }
    }
    else {
      if (cloneupvar == NULL) {
        clone->SetUpstream(upvar);
      }
      else {
        upvar = upvar->GetSameVariable();
        cloneupvar = cloneupvar->GetSameVariable();
        if (upvar != cloneupvar) {
          g_registry.SetError("Cannot set '" + GetNameDelimitedBy('.') + "' and '" + clone->GetNameDelimitedBy('.') + "' to be the same, since they seem to be already assigned to different DNA strands.");
          return true;
        }
      }
    }
  }
  m_upstream.clear();

  if (m_downstream.size() > 0) {
    Variable* downvar = GetDownstreamDNA();
    Variable* clonedownvar = clone->GetDownstreamDNA();
    if (downvar == NULL) {
      if (clonedownvar == NULL) {
        clonedownvar->SetOpenDownstream();
      }
      //else do nothing;
    }
    else {
      if (clonedownvar == NULL) {
        clonedownvar->SetDownstream(downvar);
      }
      else {
        downvar = downvar->GetSameVariable();
        clonedownvar = clonedownvar->GetSameVariable();
        if (downvar != clonedownvar) {
          g_registry.SetError("Cannot set '" + GetNameDelimitedBy('.') + "' and '" + clone->GetNameDelimitedBy('.') + "' to be the same, since they seem to be already assigned to different DNA strands.");
          return true;
        }
      }
    }
  }
  m_downstream.clear();
  
    

  if (clone->SetIsConst(GetIsConst())) {
    return true; //(error condition)
  }
  return false;
}

bool Variable::CheckDoesNotIncludeSelf()
{
  Formula* form = GetFormula();
  if (form != NULL) {
    if (form->ContainsVar(this)) {
      return false;
    }
  }
  return true;
}

string Variable::ToString() const
{
  return GetNameDelimitedBy('.') + " (" + VarTypeToString(m_type) + ")";
}

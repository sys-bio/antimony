#ifndef NCELLML

#include <memory>

#include "cellmlx.h"

#include "libcellml/component.h"
#include "libcellml/model.h"
#include "libcellml/variable.h"

using namespace std;

namespace {

// A variable's CellML InterfaceType has two independent facets (PUBLIC,
// visible to sibling/parent components, and PRIVATE, visible to child
// components) folded into one enum.  A pass-through variable may need both
// facets set across two separate calls (once for its 'upward' link, once
// for its 'downward' one), so this upgrades rather than overwrites.
void EnsureInterfaceType(const libcellml::VariablePtr& var, libcellml::Variable::InterfaceType type)
{
  using libcellml::Variable;
  if (var->hasInterfaceType(type) || var->hasInterfaceType(Variable::InterfaceType::PUBLIC_AND_PRIVATE)) {
    return;
  }
  if (var->hasInterfaceType(Variable::InterfaceType::NONE)) {
    var->setInterfaceType(type);
    return;
  }
  //Already has the other single interface type set; combine the two.
  var->setInterfaceType(Variable::InterfaceType::PUBLIC_AND_PRIVATE);
}

}  // namespace

//
//----------Reading CellML models---------------
//
// CellML import doesn't need TeLICeM or CeVAS the way the old CellML-API
// code did: libCellML exposes the encapsulation hierarchy directly as the
// Component tree, and variable equivalences ('connections') directly on
// each Variable, so there's no XML structure to walk by hand for either.
// Math is read back via the mirror image of the export path: MathML ->
// libsbml ASTNode -> Antimony infix string -> setFormulaWithString (see
// cellmlx.cpp's ParseCellMLMath).

void Module::LoadCellMLModel(const vector<libcellml::ComponentPtr>& top_components)
{
  assert(m_cellmlcomponent==NULL);

  //Each top-level CellML component becomes a submodule of this wrapper module.
  for (size_t comp=0; comp<top_components.size(); comp++) {
    if (top_components[comp]->isImport()) continue; //Unresolved; already warned about.
    string compname = top_components[comp]->name();
    FixName(compname);
    string cellmlmodname = CellMLModuleNameFor(top_components[comp]);
    Variable* var = AddOrFindVariable(&compname);
    if (var->SetModule(&cellmlmodname)) {
      assert(false);
      return;
    }
  }
  SetIsMain(true);

  FixNames();  //In case the name of one of the modules is something like 'time'.
}

void Module::LoadCellMLComponent(const libcellml::ComponentPtr& component)
{
  assert(m_cellmlmodel==NULL);

  //Variables
  for (size_t v=0; v<component->variableCount(); v++) {
    libcellml::VariablePtr cmlvar = component->variable(v);
    string varName = cmlvar->name();
    FixName(varName);
    Variable* antvar = AddOrFindVariable(&varName);
    antvar->SetCellMLVariable(cmlvar);

    string ivStr = cmlvar->initialValue();
    if (ivStr != "") {
      Formula* formula = g_registry.NewBlankFormula();
      setFormulaWithString(ivStr, formula, this);
      antvar->SetFormula(formula);
    }

    //Put it in the module interface if it has one:
    if (!cmlvar->hasInterfaceType(libcellml::Variable::InterfaceType::NONE)) {
      AddVariableToExportList(antvar);
    }
  }

  //Math
  vector<CellMLMathEquation> equations = ParseCellMLMath(component->math());
  for (size_t e=0; e<equations.size(); e++) {
    const CellMLMathEquation& equation = equations[e];
    Formula* formula = g_registry.NewBlankFormula();
    setFormulaWithString(equation.rhsFormula, formula, this);

    if (equation.kind == CellMLMathEquation::ALGEBRAIC_RULE) {
      if (AddNewAlgebraicRule(0, formula)) {
        string warning = "Unable to use the formula \"" + formula->ToDelimitedStringWithEllipses(".") + "\" to set an algebraic rule:  " + getLastError();
        g_registry.AddWarning(warning);
      }
      continue;
    }

    string varname = equation.targetVariable;
    FixName(varname);
    Variable* var = AddOrFindVariable(&varname);

    if (equation.kind == CellMLMathEquation::RATE_RULE) {
      if (var->SetRateRule(formula)) {
        string warning = "Unable to use the formula \"" + formula->ToDelimitedStringWithEllipses(".") + "\" to set the rate rule for " + var->GetNameDelimitedBy(".") + ":  " + getLastError();
        g_registry.AddWarning(warning);
      }
    }
    else {
      if (var->SetAssignmentRule(formula)) {
        string warning = "Unable to use the formula \"" + formula->ToDelimitedStringWithEllipses(".") + "\" to set the assignment rule for " + var->GetNameDelimitedBy(".") + ":  " + getLastError();
        g_registry.AddWarning(warning);
      }
    }
  }

  //And finally, fix names.
  FixNames();
}

void Module::SetCellMLChildrenAsSubmodules(const libcellml::ComponentPtr& component)
{
  for (size_t i=0; i<component->componentCount(); i++) {
    libcellml::ComponentPtr child = component->component(i);
    if (child->isImport()) continue; //Unresolved; already warned about.

    Module* submod = g_registry.GetModule(CellMLModuleNameFor(child));
    if (submod == NULL) continue; //Shouldn't happen for a non-import component, but be defensive.
    submod->SetCellMLChildrenAsSubmodules(child); //Recursive, so the submodels are all set up before we copy them.

    string cellmlname = child->name();
    FixName(cellmlname);
    vector<string> fullname;
    fullname.push_back(cellmlname);
    Variable* foundvar = GetVariable(fullname);
    if (foundvar != NULL && foundvar->GetType() != varModule) {
      cellmlname = cellmlname + "_mod";
    }

    string cellmlmodname = CellMLModuleNameFor(child);
    Variable* var = AddOrFindVariable(&cellmlname);
    if (var->SetModule(&cellmlmodname)) {
      assert(false);
      return;
    }
  }
}

libcellml::ModelPtr Module::GetCellMLModel()
{
  if (m_cellmlmodel == nullptr || m_cellmlmodel->name() != m_modulename) {
    CreateCellMLModel();
  }
  return m_cellmlmodel;
}

//
//----------Creating CellML Models---------------
//

void Module::CreateCellMLModel()
{
  m_cellmlmodel = nullptr;
  m_cellmlcomponent = nullptr;

  m_cellmlmodel = libcellml::Model::create(m_modulename);

  //Create a component for all local variables, nesting them (via
  //addComponent) exactly the way Antimony's modules are nested--this *is*
  //CellML's encapsulation hierarchy, so no separate encapsulation pass is
  //needed the way the old CellML-API-based code required.
  AddCellMLComponentsTo(nullptr, this);

  //Figure out which variable in each set of synced variables needs to be the 'canonical' one
  SetCanonicalVars(); //(uses m_syncedvars)

  //Create all connections
  AddConnections();

  //Add in the Math
  for (map<Variable*, vector<Variable*> >::iterator mapiter = m_syncedvars.begin();
       mapiter != m_syncedvars.end(); mapiter++) {
    AssignMathOnceFor(mapiter->second);
  }

  //Add in the ODEs
  AddODEsTo(this);
}

void Module::AddCellMLComponentsTo(const libcellml::ComponentPtr& parent, Module* topmod)
{
  libcellml::ComponentPtr comp = GetCellMLComponent(topmod);
  if (parent != nullptr) {
    parent->addComponent(comp);
  }
  else {
    topmod->m_cellmlmodel->addComponent(comp);
  }
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* variable = m_variables[var];
    if (variable->GetType() == varModule) {
      variable->GetModule()->AddCellMLComponentsTo(comp, topmod);
    }
  }
}

libcellml::ComponentPtr Module::GetCellMLComponent(Module* topmod)
{
  if (m_cellmlcomponent == nullptr) {
    CreateCellMLComponent(topmod);
  }
  return m_cellmlcomponent;
}

void Module::CreateCellMLComponent(Module* topmod)
{
  //Establish a unique name in CellML, which is a different namespace than Antimony (which can distinguish X.y from Z.y--in CellML, we can no longer call both 'y', and it's awkward to call everything 'X_y', etc.)
  int nindex = static_cast<int>(m_variablename.size())-1;
  string name = m_modulename; //The top component needs a name here, too.
  if (nindex >= 0) {
    name = m_variablename[nindex];
    while (topmod->InUnique(name)) {
      assert(nindex>0);
      if (nindex==0) {
        //error  LS DEBUG
      }
      nindex--;
      name = m_variablename[nindex] + "_" + name;
    }
  }
  topmod->AddUnique(name);
  m_cellmlcomponent = libcellml::Component::create(name);
  m_cellmlmodel = topmod->m_cellmlmodel;

  map<Variable*, vector<Variable*> >::iterator mapiter;

  //Create into m_cellmlcomponent.
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* variable = m_variables[var];
    bool used = false;
    switch(variable->GetType()) {
    case varSpeciesUndef:
    case varFormulaUndef:
    case varDNA:
    case varFormulaOperator:
    case varReactionGene:
    case varInteraction:
    case varReactionUndef:
    case varCompartment:
    case varUndefined:
    case varAlgebraicRule:
      //The above all become CellML variables:
      AddNewVariableToCellML(variable);
      used = true;
      break;
    case varEvent:
    case varModule:
    case varStrand:
    case varUncertWrapper:
    case varLayoutWrapper:
    case varSboTermWrapper:
    case varStoichiometry:
    case varLayoutColorEtc:
    case varKineticLawWrapper:
    case varUnitDefinition:
    case varDeleted:
    case varConstraint:
        //These all have no CellML equivalent (except Module, which is taken care of separately).
      break;
    case varGeneProduct:
    case varGeneProductAssociation:
    case varSpeciesCharge:
    case varSpeciesChemicalFormula:
      //Need to figure out what to do with these.
        assert(false);
        break;
    }
    if (used) {
      //Create a list of synchronized variables
      Variable* samevar = variable->GetSameVariable();
      mapiter = topmod->m_syncedvars.find(samevar);
      if (mapiter == topmod->m_syncedvars.end()) {
        vector<Variable*> varlist;
        varlist.push_back(variable);
        topmod->m_syncedvars.insert(make_pair(samevar, varlist));
      }
      else {
        mapiter->second.push_back(variable);
      }
    }
  }
}

void Module::AddNewVariableToCellML(Variable* variable)
{
  vector<string> varname = variable->GetName();
  assert(varname.size()>0);
  libcellml::VariablePtr cmlvar = AddNewVariableToCellML(varname[varname.size()-1]);
  variable->SetCellMLVariable(cmlvar);
}

libcellml::VariablePtr Module::AddNewVariableToCellML(const string& varname)
{
  assert(m_cellmlcomponent != nullptr);
  return AddNewVariableToCellML(varname, m_cellmlcomponent);
}

libcellml::VariablePtr Module::AddNewVariableToCellML(const string& varname, const libcellml::ComponentPtr& component)
{
  string uniquename = varname;
  size_t varnum = 1;
  while (component->variable(uniquename) != nullptr) {
    //A variable with that name already exists; create a new one instead.
    uniquename = varname + "_" + SizeTToString(varnum);
    varnum++;
  }

  libcellml::VariablePtr cmlvar = libcellml::Variable::create(uniquename);
  cmlvar->setUnits("dimensionless");
  component->addVariable(cmlvar);
  return cmlvar;
}

Variable* Module::WhichFirstDefined(vector<Variable*> varlist, formula_type ftype)
{
  assert(varlist.size()>0);
  Variable* candidate = NULL;
  for (size_t var=0; var<varlist.size(); var++) {
    if (varlist[var]->StillMatchesOriginal(ftype)) {
      if (candidate == NULL || candidate->GetName().size() < varlist[var]->GetName().size()) {
        candidate = varlist[var];
      }
    }
  }
  if (candidate == NULL) {
    //The top module changed a variable's definition without giving it a local name.
    //Um, help? LS DEBUG
    //At least point to the version that everyone is synced to:
    candidate = varlist[0]->GetSameVariable();
    //cout << "Help!  Nothing found for the variables synced to " << candidate->GetNameDelimitedBy(".");
  }
  return candidate;
}

bool Module::InUnique(string name)
{
  return (m_uniquenames.find(name) != m_uniquenames.end());
}

void Module::AddUnique(string name)
{
  m_uniquenames.insert(name);
}

void Module::SetCanonicalVars()
{
  for (map<Variable*, vector<Variable*> >::iterator mapiter = m_syncedvars.begin();
       mapiter != m_syncedvars.end(); mapiter++) {
    FindAndSetCanonical(mapiter->second);
  }
}

void Module::FindAndSetCanonical(vector<Variable*> varlist)
{
  formula_type ftype = varlist[0]->GetFormulaType();
  Variable* canonvar = WhichFirstDefined(varlist, ftype);
  for (size_t var=0; var<varlist.size(); var++) {
    varlist[var]->SetCanonicalVariable(canonvar);
  }
}

void Module::AddConnections()
{
  map<Variable*, Variable*> tree;
  SetupTree(tree, NULL);
  for (map<Variable*, vector<Variable*> >::iterator mapiter = m_syncedvars.begin();
       mapiter != m_syncedvars.end(); mapiter++) {
    if (mapiter->second.size() > 1) {
      AddConnectionsTo(mapiter->second, tree);
    }
  }
}

void Module::SetupTree(map<Variable*, Variable*>& tree, Variable* thisvar)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      tree.insert(make_pair(m_variables[var], thisvar));
      m_variables[var]->GetModule()->SetupTree(tree, m_variables[var]);
    }
  }
}

Variable* Module::GetParent(Variable* child, const map<Variable*, Variable*>& tree)
{
  if (child==NULL) return NULL;
  map<Variable*, Variable*>::const_iterator branch = tree.find(child);
  if (branch==tree.end()) {
    assert(false); //We should put NULL in the tree specifically for top-level children
    return NULL;
  }
  else {
    return branch->second;
  }
}

Variable* Module::GetSyncedVariable(Variable* mod, const map<Variable*, Variable*>& mod2var)
{
  map<Variable*, Variable*>::const_iterator branch = mod2var.find(mod);
  if (branch==mod2var.end()) {
    return NULL;
  }
  else {
    return branch->second;
  }
}

libcellml::VariablePtr Module::GetLinkedCMLVar(Variable* mod, const map<Variable*, libcellml::VariablePtr>& mod2linkedcellml)
{
  map<Variable*, libcellml::VariablePtr>::const_iterator branch = mod2linkedcellml.find(mod);
  if (branch==mod2linkedcellml.end()) {
    return nullptr;
  }
  else {
    return branch->second;
  }
}

void Module::Connect(Variable* modin, Variable* canonmod, map<Variable*, libcellml::VariablePtr>& mod2linkedcellml, const map<Variable*, Variable*>& mod2var, const set<Variable*>& canonparents, const map<Variable*, Variable*>& tree)
{
  libcellml::VariablePtr cmlin = GetLinkedCMLVar(modin, mod2linkedcellml);
  if (cmlin != nullptr) {
    //We already connected this, so we're done!
    return;
  }
  Variable* canonvar = GetSyncedVariable(canonmod, mod2var);
  Variable* syncedvar = GetSyncedVariable(modin, mod2var);
  if (syncedvar == NULL) {
    vector<string> canonname = canonvar->GetName();
    cmlin = modin->GetModule()->AddNewVariableToCellML(canonname[canonname.size()-1]);
  }
  else {
    cmlin = syncedvar->GetCellMLVariable();
  }

  //So, there are three options:
  //  One, the modin is a direct parent of canonmod, so we link downwards towards it.
  //  Two, the modin is a direct child of a direct parent of canonmod, so we link sidways into the parent tree or to canonmod directly.
  //  Three, we link to the variable in modin's parent.  All other cases reduce to this.
  Variable* inparent = GetParent(modin, tree);
  if (canonparents.find(modin) != canonparents.end()) {
    //Option 1!
    Variable* potential_child = canonmod;
    Variable* parent = GetParent(potential_child, tree);
    while (parent != modin) {
      potential_child = parent;
      parent = GetParent(potential_child, tree);
    }
    Connect(potential_child, canonmod, mod2linkedcellml, mod2var, canonparents, tree);
    libcellml::VariablePtr cmlchild = GetLinkedCMLVar(potential_child, mod2linkedcellml);
    assert(cmlchild != nullptr);
    AddOneConnection(cmlin, cmlchild, td_DOWN);
  }
  else if (canonparents.find(inparent) != canonparents.end()) {
    //Option 2!
    Variable* potential_sibling = canonmod;
    Variable* parent = GetParent(potential_sibling, tree);
    while (parent != inparent) {
      potential_sibling = parent;
      parent = GetParent(potential_sibling, tree);
    }
    Connect(potential_sibling, canonmod, mod2linkedcellml, mod2var, canonparents, tree);
    libcellml::VariablePtr cmlsib = GetLinkedCMLVar(potential_sibling, mod2linkedcellml);
    assert(cmlsib != nullptr);
    AddOneConnection(cmlin, cmlsib, td_SIDEWAYS);
  }
  else {
    //Option 3!
    Connect(inparent, canonmod, mod2linkedcellml, mod2var, canonparents, tree);
    libcellml::VariablePtr cmlparent = GetLinkedCMLVar(inparent, mod2linkedcellml);
    assert(cmlparent != nullptr);
    AddOneConnection(cmlin, cmlparent, td_UP);
  }

  //Finally, put the new cmlin variable into the sync list so we only do this once:
  mod2linkedcellml.insert(make_pair(modin, cmlin));
}

void Module::AddOneConnection(const libcellml::VariablePtr& varin, const libcellml::VariablePtr& varout, tree_direction td)
{
  using libcellml::Variable;
  switch(td) {
  case td_UP:
    EnsureInterfaceType(varin, Variable::InterfaceType::PUBLIC);
    EnsureInterfaceType(varout, Variable::InterfaceType::PRIVATE);
    break;
  case td_DOWN:
    EnsureInterfaceType(varin, Variable::InterfaceType::PRIVATE);
    EnsureInterfaceType(varout, Variable::InterfaceType::PUBLIC);
    break;
  case td_SIDEWAYS:
    EnsureInterfaceType(varin, Variable::InterfaceType::PUBLIC);
    EnsureInterfaceType(varout, Variable::InterfaceType::PUBLIC);
    break;
  }
  //Unlike the old CellML API, libCellML variable equivalence isn't grouped
  //into explicit <connection> elements by hand--the Printer works out the
  //correct <connection>/<map_variables> grouping from the component
  //hierarchy and this equivalence graph at serialisation time.
  Variable::addEquivalence(varin, varout);
}

void Module::AssignMathOnceFor(vector<Variable*> varlist)
{
  Variable* finalvar = varlist[0];
  const Formula* ia = finalvar->GetInitialAssignment();
  const Formula* ar = finalvar->GetAssignmentRuleOrKineticLaw();
  const Formula* rr = finalvar->GetRateRule();
  //'ia' and 'rr' may both exist and have been initially defined in different modules.  But that doesn't matter, since we need to define all three in the same CellML module, since that's the way they roll.
  Variable* targetvar = varlist[0]->GetCanonicalVariable();
  libcellml::VariablePtr cmlvar = targetvar->GetCellMLVariable();
  const Variable* origtarget = targetvar->GetOriginal();
  vector<string> varname = origtarget->GetName();
  assert(varname.size()==1);
  string cc = g_registry.GetCC();
  if (!ia->IsEmpty()) {
    if (ia->IsDouble()) {
      cmlvar->setInitialValue(ia->ToDelimitedStringWithEllipses(cc));
      //cout << "Successfully set initial value for " << targetvar->GetNameDelimitedBy(".") << endl;
    }
    else {
      //Have to create a new variable.
      string newvarname = varname[varname.size()-1] + "_init";
      Variable* tvarparent = targetvar->GetParentVariable();
      Module* tvarmod = this;
      if (tvarparent != NULL) {
        tvarmod = tvarparent->GetModule();
      }
      libcellml::VariablePtr initvar = tvarmod->AddNewVariableToCellML(newvarname);
      cmlvar->setInitialValue(initvar);
      string rhs = origtarget->GetInitialAssignment()->ToSBMLString(origtarget->GetStrandVars());
      string math = WrapAssignmentMath(newvarname, FormulaStringToMathML(rhs));
      if (!SetCellMLMathFor(math, targetvar)) {
        string warning = "Unable to initialize " + targetvar->GetNameDelimitedBy(".") + " through "+ newvarname + " (" + newvarname + " = " + rhs + ")";
        g_registry.AddWarning(warning);
      }
    }
  }
  if (!ar->IsEmpty()) {
    string rhs = origtarget->GetAssignmentRuleOrKineticLaw()->ToSBMLString(origtarget->GetStrandVars());
    string math = WrapAssignmentMath(varname[varname.size()-1], FormulaStringToMathML(rhs));
    if (!SetCellMLMathFor(math, targetvar)) {
      string warning = "Unable to translate \"" + varname[varname.size()-1] + " = " + rhs + "\" to CellML's MathML for the assignment rule.";
      g_registry.AddWarning(warning);
    }
  }
  if (!rr->IsEmpty()) {
    AddTimeFor(targetvar->GetCellMLVariable());
    const Variable* rrorigtarget = targetvar->GetOriginal();
    vector<string> rrvarname = rrorigtarget->GetName();
    assert(rrvarname.size()==1);
    string rhs = rrorigtarget->GetRateRule()->ToSBMLString(rrorigtarget->GetStrandVars());
    string math = WrapRateMath(rrvarname[rrvarname.size()-1], "time", FormulaStringToMathML(rhs));
    if (!SetCellMLMathFor(math, targetvar)) {
      string warning = "Unable to translate \"d(" + rrvarname[rrvarname.size()-1] + ")/d(time) = " + rhs + "\" to CellML's MathML for the rate rule.";
      g_registry.AddWarning(warning);
    }
  }
  if (origtarget->GetFormulaType() == formulaALGEBRAIC) {
    string rhs = origtarget->GetFormula()->ToSBMLString(origtarget->GetStrandVars());
    string math = WrapAlgebraicMath(FormulaStringToMathML(rhs));
    if (!SetCellMLMathFor(math, targetvar)) {
      string warning = "Unable to translate the algebraic rule \"" + rhs + " = 0\" to CellML's MathML.";
      g_registry.AddWarning(warning);
    }
  }
}

bool Module::SetCellMLMathFor(const string& mathml, Variable* targetvar)
{
  libcellml::VariablePtr cmlvar = targetvar->GetCellMLVariable();
  libcellml::ComponentPtr cmlcomp = std::dynamic_pointer_cast<libcellml::Component>(cmlvar->parent());
  return SetCellMLMathFor(mathml, cmlcomp);
}

bool Module::SetCellMLMathFor(const string& mathml, const libcellml::ComponentPtr& cmlcomp)
{
  if (mathml.empty() || cmlcomp == nullptr) {
    return false;
  }
  cmlcomp->appendMath(mathml);
  return true;
}

void Module::AddTimeFor(const libcellml::VariablePtr& cmlvar)
{
  libcellml::ComponentPtr cmlcomp = std::dynamic_pointer_cast<libcellml::Component>(cmlvar->parent());
  AddTimeTo(cmlcomp);
}

libcellml::VariablePtr Module::AddTimeTo(const libcellml::ComponentPtr& cmlcomp)
{
  libcellml::VariablePtr time = cmlcomp->variable("time");
  if (time != nullptr) {
    //Already exists.
    return time;
  }
  assert(m_cellmlmodel != nullptr);

  time = libcellml::Variable::create("time");
  time->setUnits("dimensionless");
  cmlcomp->addVariable(time);

  libcellml::ComponentPtr parent = std::dynamic_pointer_cast<libcellml::Component>(cmlcomp->parent());
  if (parent != nullptr) {
    libcellml::VariablePtr ptime = AddTimeTo(parent);
    AddOneConnection(time, ptime, td_UP);
  }

  return time;
}

void Module::AddODEsTo(Module* topmod)
{
  set<Variable*> species;
  set<Variable*> reactions;
  GetAllSpeciesAndReactions(species, reactions);
  set<Variable*>::iterator speciter, rxniter;
  for (speciter=species.begin(); speciter != species.end(); speciter++) {
    vector<string> commonmod;
    Formula form;
    set<Variable*> involvedrxns;
    for (rxniter=reactions.begin(); rxniter != reactions.end(); rxniter++) {
      double stoich = (*rxniter)->GetReaction()->GetStoichiometryFor(*speciter);
      if (stoich != 0) {
        if (stoich < 0) {
          form.AddMathThing('-');
        }
        else if (!form.IsEmpty()) {
          form.AddMathThing('+');
        }
        if (stoich != 1.0 && stoich != -1.0) {
          form.AddNum(stoich);
          form.AddMathThing('*');
        }
        form.AddVariable(*rxniter);
        involvedrxns.insert(*rxniter);
      }
    }
    if (involvedrxns.size()==0) continue; //The species was in no reactions.
    set<Variable*> contains;
    Module* ratemod = topmod->BestModuleToAdd(involvedrxns, contains);
    ratemod->AddRateRuleInvolving(*speciter, form, involvedrxns);
  }
}

void Module::GetAllSpeciesAndReactions(set<Variable*>& species, set<Variable*>& reactions)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    if (IsSpecies(m_variables[var]->GetType()) && !(m_variables[var]->GetIsConst())) {
      species.insert(m_variables[var]->GetSameVariable());
    }
    else if (IsReaction(m_variables[var]->GetType())) {
      reactions.insert(m_variables[var]->GetSameVariable());
    }
    else if (m_variables[var]->GetType()==varModule) {
      m_variables[var]->GetModule()->GetAllSpeciesAndReactions(species, reactions);
    }
  }
}

Module* Module::BestModuleToAdd(set<Variable*> involvedrxns, set<Variable*>& contains )
{
  for (size_t var=0; var<m_variables.size(); var++) {
    var_type vtype = m_variables[var]->GetType();
    if (vtype==varModule) {
      set<Variable*> partcontains;
      Module* testmod = m_variables[var]->GetModule()->BestModuleToAdd(involvedrxns, partcontains);
      assert(testmod == NULL || (partcontains.size() == involvedrxns.size()));
        set<Variable*>::iterator contit;
      for (contit = partcontains.begin(); contit != partcontains.end(); contit++) {
        contains.insert(*contit);
      }
      if (testmod != NULL) {
        return testmod; //Might be some parallel sub-module that *also* contains all rxns, but who cares.
      }
    }
    else if (IsReaction(vtype)) {
      Variable* sourcerxn = m_variables[var]->GetSameVariable();
      if (involvedrxns.find(sourcerxn) != involvedrxns.end()) {
        contains.insert(sourcerxn);
      }
    }
  }
  if (involvedrxns.size() == contains.size()) return this;
  return NULL;
}

void Module::AddConnectionsTo(vector<Variable*> varlist, const map<Variable*, Variable*>& tree)
{
  Variable* canonmod = varlist[0]->GetCanonicalVariable()->GetParentVariable();
  map<Variable*, libcellml::VariablePtr> mod2linkedcellml;
  map<Variable*, Variable*> mod2var;
  set<Variable*> canonparents;

  //This sets up the linkage between modules and the pre-existing Antimony variables, all of which have corresponding CellML variables
  for (size_t var=0; var<varlist.size(); var++) {
    Variable* modvar = varlist[var]->GetParentVariable();
    mod2var.insert(make_pair(modvar, varlist[var]));
  }

  //This sets up the list of direct parents of the 'canon' module.  This is used when connecting to know how to connect (up, down, or sideways)
  Variable* cp = GetParent(canonmod, tree);
  while (cp != NULL) {
    canonparents.insert(cp);
    cp = GetParent(cp, tree);
  }
  if (canonmod != NULL) {
    canonparents.insert(cp); //The top-level module may have a linked variable too
  }

  //The first linked CellML variable we have is the canonical one:
  libcellml::VariablePtr canoncml = GetSyncedVariable(canonmod, mod2var)->GetCellMLVariable();
  mod2linkedcellml.insert(make_pair(canonmod, canoncml));

  //Now go through the list and connect everything.  As things are linked, mod2linkedcellml is updated so we don't duplicate effort.
  for (size_t var=0; var<varlist.size(); var++) {
    Connect(varlist[var]->GetParentVariable(), canonmod, mod2linkedcellml, mod2var, canonparents, tree);
  }
}

void Module::AddRateRuleInvolving(Variable* species, Formula form, set<Variable*> involvedrxns)
{
  libcellml::VariablePtr subvar = nullptr;
  string localname = "";
  FindOrCreateLocalVersionOf(species, localname, subvar);

  for (set<Variable*>::iterator involvedit=involvedrxns.begin(); involvedit != involvedrxns.end(); involvedit++) {
    string localrxn;
    FindOrCreateLocalVersionOf(*involvedit, localrxn, subvar);
    form.UseInstead(localrxn, *involvedit);
  }
  string rhs = form.ToSBMLString();
  AddTimeTo(m_cellmlcomponent);
  string math = WrapRateMath(localname, "time", FormulaStringToMathML(rhs));
  if (!SetCellMLMathFor(math, m_cellmlcomponent)) {
    string warning = "Unable to translate \"d(" + localname + ")/d(time) = " + rhs + "\" to CellML's MathML for the rate rule.";
    g_registry.AddWarning(warning);
  }
}

void Module::FindOrCreateLocalVersionOf(Variable* variable, string& newvarname, libcellml::VariablePtr& newlocalvar)
{
  //Find...
  for (size_t var=0; var<m_variables.size(); var++) {
    if (variable->GetSameVariable() == m_variables[var]->GetSameVariable()) {
      vector<string> varname = m_variables[var]->GetName();
      newlocalvar = m_variables[var]->GetCellMLVariable();
      newvarname  = varname[varname.size()-1];
      return;
    }
  }
  //...or create
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType()==varModule) {
      libcellml::VariablePtr subvar = nullptr;
      string foundvarname = "";
      m_variables[var]->GetModule()->FindOrCreateLocalVersionOf(variable, foundvarname, subvar);
      if (foundvarname != "") {
        //The variable was indeed in this list.  Create a local copy (in CellML) and sync it.
        vector<string> varname;
        varname.push_back(foundvarname);
        while (GetVariable(varname) != NULL) {
          foundvarname = m_variables[var]->GetModule()->GetModuleName() + "_" + foundvarname;
          varname[0] = foundvarname;
        }
        newlocalvar = AddNewVariableToCellML(foundvarname);
        AddOneConnection(newlocalvar, subvar, td_DOWN);
        newvarname = foundvarname;
        return;
      }
    }
  }
  newvarname = "";
  return;
}

#endif

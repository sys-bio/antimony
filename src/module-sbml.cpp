#include "module.h"
#include "sbml/Model.h"

using namespace libsbml;

#ifndef NSBML
void SetVarWithEvent(Variable* var, const Event* event, Module* module, vector<string> submodname)
{
  if (event->isSetName()) {
    var->SetDisplayName(event->getName());
  }
  var->SetType(varEvent);

  //Set the trigger:
  const Trigger* sbmltrigger = event->getTrigger();
  Formula trigger;
  if (sbmltrigger != NULL && sbmltrigger->isSetMath()) {
    string triggerstring(parseASTNodeToString(sbmltrigger->getMath()));
    setFormulaWithString(triggerstring, &trigger, module);
    trigger.ReadAnnotationFrom(sbmltrigger);
  }
  Formula delay;
  const Delay* sbmldelay = event->getDelay();
  if (sbmldelay != NULL) {
    string delaystring(parseASTNodeToString(sbmldelay->getMath()));
    setFormulaWithString(delaystring, &delay, module);
    delay.ReadAnnotationFrom(sbmldelay);
  }

  //Set the priority:
  Formula priority;
  if (event->isSetPriority()) {
    const Priority* sbmlpriority = event->getPriority();
    if (sbmlpriority != NULL) {
      string prioritystring(parseASTNodeToString(sbmlpriority->getMath()));
      setFormulaWithString(prioritystring, &priority, module);
      priority.ReadAnnotationFrom(sbmlpriority);
    }
  }

  //Set the new top names for everything
  string modname = module->GetModuleName();
  for (size_t n=submodname.size(); n>0; n--) {
    string name = submodname[n-1];
    trigger.SetNewTopName(modname, name);
    priority.SetNewTopName(modname, name);
    delay.SetNewTopName(modname, name);
  }
  AntimonyEvent antevent(delay, trigger, var);
  antevent.SetPriority(priority);
  //And set the other optional booleans:
  if (event->isSetUseValuesFromTriggerTime()) {
    antevent.SetUseValuesFromTriggerTime(event->getUseValuesFromTriggerTime());
  }
  if (sbmltrigger && sbmltrigger->isSetPersistent()) {
    antevent.SetPersistent(event->getTrigger()->getPersistent());
  }
  if (sbmltrigger && sbmltrigger->isSetInitialValue()) {
    antevent.SetInitialValue(event->getTrigger()->getInitialValue());
  }
  //All done--give it to the variable.
  var->SetEvent(&antevent);

  //Set the assignments:
  for (unsigned int asnt=0; asnt<event->getNumEventAssignments(); asnt++) {
    const EventAssignment* assignment = event->getEventAssignment(asnt);
    vector<string> name = submodname;
    name.push_back(assignment->getVariable());
    Variable* asntvar = module->GetVariable(name);
    if (asntvar == NULL && name.size()==1) {
      asntvar = module->AddOrFindVariable(&name[0]);
    }
    assert(asntvar != NULL);
    Formula*  asntform = g_registry.NewBlankFormula();
    setFormulaWithString(parseASTNodeToString(assignment->getMath()), asntform, module);
    asntform->ReadAnnotationFrom(assignment);
    for (size_t n=submodname.size(); n>0; n--) {
      string name = submodname[n-1];
      asntform->SetNewTopName(modname, name);
    }
    var->GetEvent()->AddResult(asntvar, asntform);
  }
  module->TranslateRulesAndAssignmentsTo(event, var);
}

string GetNewIDForLocalParameter(const SBase* lp)
{
  if (lp==NULL) {
    assert(false);
    return "";
  }
  const Reaction* rxnparent = static_cast<const Reaction*>(lp->getAncestorOfType(SBML_REACTION));
  if (rxnparent==NULL) return "";
#ifdef USE_COMP
  const Model* model = static_cast<const Model*>(rxnparent->getAncestorOfType(SBML_COMP_MODELDEFINITION, "comp"));
  if (model==NULL) {
    model = static_cast<const Model*>(rxnparent->getAncestorOfType(SBML_MODEL));
  }
#else
  const Model* model = static_cast<const Model*>(rxnparent->getAncestorOfType(SBML_MODEL));
#endif
  if (model==NULL) return "";
  string rxnname;
  if (rxnparent->isSetId()) {
    rxnname = rxnparent->getId();
  }
  else {
    unsigned long rxnnum;
    for (rxnnum=0; rxnnum<model->getNumReactions(); rxnnum++) {
      if (rxnparent == model->getReaction(rxnnum)) break;
    }
    rxnname = "_J" + SizeTToString(rxnnum);
  }
  string lpid = rxnname + "_" + lp->getId();
  SBase* shadow = const_cast<Model*>(model)->getElementBySId(lpid);
  size_t snum = 0;
  while (shadow != NULL) {
    lpid = rxnname + "_" + lp->getId() + SizeTToString(snum);
    snum++;
    shadow = const_cast<Model*>(model)->getElementBySId(lpid);
  }
  return lpid;
}

#ifdef USE_COMP

void  SetSBaseReference(SBaseRef* sbr, SBase* target, Model* targetmodel, string baseid)
{
  //We'll re-set any of these that happened to be correct:
  sbr->unsetIdRef();
  sbr->unsetMetaIdRef();
  sbr->unsetUnitRef();
  sbr->unsetPortRef();
  int type = target->getTypeCode();
  string id = target->getId();
  string metaid = target->getMetaId();
  CompModelPlugin* cmp = static_cast<CompModelPlugin*>(targetmodel->getPlugin("comp"));
  for (unsigned long p=0; p<cmp->getNumPorts(); p++) {
    Port* port = cmp->getPort(p);
    SBase* porttarget = port->getReferencedElement();
    if (porttarget == target) {
      sbr->setPortRef(port->getId());
      return;
    }
  }
  if (!id.empty() && type != SBML_RATE_RULE && type != SBML_INITIAL_ASSIGNMENT
    && type != SBML_EVENT_ASSIGNMENT && type != SBML_ASSIGNMENT_RULE) {
      sbr->setIdRef(id);
      return;
  }
  if (metaid.empty()) {
    SBMLDocument* sbml = sbr->getSBMLDocument();
    assert(sbml != NULL);
    size_t num = 1;
    metaid = baseid;
    while (sbml->getElementByMetaId(metaid) != NULL) {
      metaid = baseid + SizeTToString(num);
      num++;
    }
//     std::cerr << "set sbase reference meta id " << metaid << "\n";
    target->setMetaId(metaid);
  }
  sbr->setMetaIdRef(metaid);
  return;
}

void Module::FindOrCreateLocalVersionOf(const Variable* var, libsbml::Model* sbmlmod)
{
  if(var->GetName().size() == 1) {
    //We'll create this variable normally.
    return;
  }
  string cc = g_registry.GetCC();
  string flatname = var->GetNameDelimitedBy(cc);
  SBase* topvar = sbmlmod->getElementBySId(flatname);
  if (topvar != NULL) {
    //We already created this variable with a previous call to this function.
    return;
  }
  Species* species;
  Compartment* compartment;
  Parameter* parameter;
  UnitDefinition* unitdefinition;
  bool isunit = false;
  Variable* varcompartment = var->GetCompartment();
  switch(var->GetType()) {
  case varCompartment:
    compartment = sbmlmod->createCompartment();
    compartment->setId(flatname);
    compartment->setConstant(var->GetConstType() == constVAR);
    topvar = compartment;
    break;
  case varSpeciesUndef:
    species = sbmlmod->createSpecies();
    species->setId(flatname);
    species->setConstant(false);
    species->setBoundaryCondition(var->GetIsConst());
    species->setHasOnlySubstanceUnits(false);
    species->setCompartment(DEFAULTCOMP);
    if (varcompartment != NULL) {
      species->setCompartment(varcompartment->GetNameDelimitedBy(cc));
      if (varcompartment->GetName().size() > 1) {
        FindOrCreateLocalVersionOf(varcompartment, sbmlmod);
      }
    }
    topvar = species;
    break;
  case varUnitDefinition:
    unitdefinition=sbmlmod->createUnitDefinition();
    unitdefinition->setId(flatname);
    isunit = true;
    topvar=unitdefinition;
    break;
  case varFormulaOperator:
  case varFormulaUndef:
  case varUndefined:
  case varReactionGene:
  case varReactionUndef:
  case varDNA:
    //LS NOTE:  Currently, the only things that can reference reactions are formulas, for which a Parameter is a perfectly acceptable substitute.  However, in the future, there may be other things that can reference Reactions that will require them to be replaced by an actual local Reaction.
    parameter = sbmlmod->createParameter();
    parameter->setId(flatname);
    parameter->setConstant(false);
    topvar = parameter;
    break;
  case varInteraction:
  case varModule:
  case varEvent:
  case varStrand:
  case varDeleted:
  case varSboTermWrapper:
  case varUncertWrapper:
  case varConstraint:
  case varStoichiometry:
    assert(false); //Unhandled type
    break;
  }
  vector<string> varname = var->GetName();
  CompSBasePlugin* csbp = static_cast<CompSBasePlugin*>(topvar->getPlugin("comp"));
  ReplacedBy* rb = csbp->createReplacedBy();
  rb->setSubmodelRef(varname[0]);
  rb->setIdRef(varname[1]);
  SBaseRef* sbr = rb;
  for (size_t sub=2; sub<varname.size(); sub++) {
    sbr = rb->createSBaseRef();
    sbr->setIdRef(varname[sub]);
  }
  if (isunit) {
    sbr->unsetIdRef();
    sbr->setUnitRef(varname[varname.size()-1]);
  }
}

void Module::GetReplacingAndRules(const Replacing* replacing, string re_string, const SBase* orig, Variable*& reference, const InitialAssignment*& ia, const Rule*& rule)
{
  reference = NULL;
  string submod = replacing->getSubmodelRef();
  vector<string> smname;
  smname.push_back(submod);
  Variable* smvar = GetVariable(smname);
  if (smvar == NULL) {
    g_registry.AddWarning("Unable to find submodule " + submod + " in model " + GetModuleName() + " which would have contained the " + re_string  + " for " + orig->getElementName() + " " + orig->getId() + ".");
    return;
  }
  if (smvar->GetType() != varModule) {
    g_registry.AddWarning("Unable to connect a " + re_string + " for " + orig->getElementName() + " " + orig->getId() + " in model " + GetModuleName() + ": the variable " + submod + " is not a submodel.");
    return;
  }
  reference = GetSBaseRef(replacing, submod, re_string, orig);
  const SBase* sb = orig->getParentSBMLObject();
  while (sb != NULL && !(sb->getTypeCode() == SBML_MODEL || sb->getTypeCode() == SBML_COMP_MODELDEFINITION)) {
    sb = sb->getParentSBMLObject();
  }
  if (sb==NULL) return;
  const Model* origmodel = static_cast<const Model*>(sb);
  if (origmodel==NULL) return;
  Replacing* sbr = const_cast<Replacing*>(replacing);
  SBase* ref = sbr->getReferencedElement();
  sb = ref;
  while (sb != NULL && !(sb->getTypeCode() == SBML_MODEL || sb->getTypeCode() == SBML_COMP_MODELDEFINITION)) {
    sb = sb->getParentSBMLObject();
  }
  if (sb==NULL) return;
  const Model* refmodel = static_cast<const Model*>(sb);
  if (refmodel==NULL) return;

  //Initial assignment:
  const InitialAssignment* newia = origmodel->getInitialAssignment(orig->getId());
  if (IsReplaced(newia, origmodel)) {
    newia = NULL;
  }
  if (newia==NULL) {
    newia = refmodel->getInitialAssignment(ref->getId());
    if (IsReplaced(newia, refmodel)) {
      newia = NULL;
    }
  }
  if (newia != NULL) {
    ia = newia;
  }

  //Rules
  const Rule* newrule = origmodel->getRule(orig->getId());
  if (IsReplaced(newrule, origmodel)) {
    newrule = NULL;
  }
  if (newrule == NULL) {
    newrule = refmodel->getRule(ref->getId());
    if (IsReplaced(newrule, origmodel)) {
      newrule = NULL;
    }
  }
  if (newrule != NULL) {
    rule = newrule;
  }

  return;
}

Variable* Module::GetSBaseRef(const SBaseRef* csbr, string modname, string re_string, const SBase* orig)
{
  SBaseRef* sbr = const_cast<SBaseRef*>(csbr);
  SBase* referenced = sbr->getReferencedElement();
  if (referenced==NULL) {
    g_registry.AddWarning("Unable to find a " + re_string + " for " + orig->getElementName() + " " + orig->getId() + " in model " + GetModuleName() + ".");
    return NULL;
  }
  vector<string> refname;
  string refid = referenced->getId();
  if (refid.empty()) {
    //LS DEBUG:  We might be able to handle some of these even if they don't have IDs at some point
    g_registry.AddWarning("Unable to connect a " + re_string + " for " + orig->getElementName() + " " + orig->getId() + " in model " + GetModuleName() + ": the referenced element has no ID, which is required in Antimony.");
    return NULL;
  }
  if (referenced->getTypeCode() == SBML_LOCAL_PARAMETER) {
    //We renamed it when we translated it to Antimony
    refid = GetNewIDForLocalParameter(referenced);
  }
  FixName(refid);
  refname.push_back(refid);
  //Now move back up the stack of submodels until we get to modname:
  const SBase* parent = referenced->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
  while (parent != NULL) {
    string submodelid = parent->getId();
    refname.insert(refname.begin(), submodelid);
    parent = parent->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
  }
  Variable* ret = GetVariable(refname);
  if (ret==NULL) {
      g_registry.AddWarning("Unable to connect a " + re_string + " for " + orig->getElementName() + " " + orig->getId() + " in model " + GetModuleName() + ": the variable " + ToStringFromVecDelimitedBy(refname, ".") + " could not be found.");
  }
  return ret;
}

bool Module::IsReplaced(const InitialAssignment* ia, const Model* parent)
{
  //This routine assumes that the passed-in initial assignment is either the top-level object or is already copied into a Submodel object.
  if (ia==NULL) return false;
  const CompSBasePlugin* iaplug = static_cast<const CompSBasePlugin*>(ia->getPlugin("comp"));
  if (iaplug != NULL) {
    if (iaplug->isSetReplacedBy()) return true;
  }
  if (parent==NULL) return false;
  const SBase* parentchain = parent->getParentSBMLObject();
  while (parentchain != NULL) {
    if (parentchain->getTypeCode()==SBML_MODEL || parentchain->getTypeCode()==SBML_COMP_MODELDEFINITION) {
      parent = static_cast<const Model*>(parentchain);
      if (parent==NULL) {
        assert(false);
        continue;
      }
      for (unsigned int i=0; i<parent->getNumInitialAssignments(); i++) {
        const InitialAssignment* upperia = parent->getInitialAssignment(i);
        iaplug = static_cast<const CompSBasePlugin*>(upperia->getPlugin("comp"));
        if (iaplug==NULL) continue;
        for (unsigned int r=0; r<iaplug->getNumReplacedElements(); r++) {
          const ReplacedElement* cre = iaplug->getReplacedElement(r);
          ReplacedElement* re = const_cast<ReplacedElement*>(cre);
          if (re->getReferencedElement() == ia) return true;
        }
      }
    }
    else if (parentchain->getTypeCode()==SBML_COMP_SUBMODEL) {
      //check to see if it was deleted!
      const Submodel* submodel = static_cast<const Submodel*>(parentchain);
      for (unsigned int del=0; del<submodel->getNumDeletions(); del++) {
        const Deletion* cdeletion = submodel->getDeletion(del);
        Deletion* deletion = const_cast<Deletion*>(cdeletion);
        if (deletion->getReferencedElement() == ia) return true;
      }
    }
    parentchain = parentchain->getParentSBMLObject();
  }
  return false;
}

bool Module::IsReplaced(const Rule* rule, const Model* parent)
{
  //This routine assumes that the passed-in rule is either the top-level object or is already copied into a Submodel object.
  if (rule==NULL) return false;
  const CompSBasePlugin* ruleplug = static_cast<const CompSBasePlugin*>(rule->getPlugin("comp"));
  if (ruleplug != NULL) {
    if (ruleplug->isSetReplacedBy()) return true;
  }
  if (parent==NULL) return false;
  const SBase* parentchain = rule->getParentSBMLObject();
  while (parentchain != NULL) {
    if (parentchain->getTypeCode()==SBML_MODEL || parentchain->getTypeCode()==SBML_COMP_MODELDEFINITION) {
      parent = static_cast<const Model*>(parentchain);
      if (parent==NULL) {
        assert(false);
        continue;
      }
      for (unsigned int i=0; i<parent->getNumRules(); i++) {
        const Rule* upperrule = parent->getRule(i);
        ruleplug = static_cast<const CompSBasePlugin*>(upperrule->getPlugin("comp"));
        if (ruleplug==NULL) continue;
        for (unsigned int r=0; r<ruleplug->getNumReplacedElements(); r++) {
          const ReplacedElement* cre = ruleplug->getReplacedElement(r);
          ReplacedElement* re = const_cast<ReplacedElement*>(cre);
          if (re->getReferencedElement() == rule) return true;
        }
      }
    }
    else if (parentchain->getTypeCode()==SBML_COMP_SUBMODEL) {
      //check to see if it was deleted!
      const Submodel* submodel = static_cast<const Submodel*>(parentchain);
      for (unsigned int del=0; del<submodel->getNumDeletions(); del++) {
        const Deletion* cdeletion = submodel->getDeletion(del);
        Deletion* deletion = const_cast<Deletion*>(cdeletion);
        if (deletion->getReferencedElement() == rule) return true;
      }
    }
    parentchain = parentchain->getParentSBMLObject();
  }
  return false;
}

void Module::AddSubmodelsToDocument(SBMLDocument* sbml)
{
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(sbml->getPlugin("comp"));

  size_t numsubmods = GetNumVariablesOfType(subModules, true);
  for (size_t sm=0; sm<numsubmods; sm++) {
    Module* submod = GetNthVariableOfType(subModules, sm, true)->GetModule();
    Module* origmod = g_registry.GetModule(submod->GetModuleName());
    submod->AddSubmodelsToDocument(sbml);
    SBase* therealready = compdoc->getModel(origmod->GetModuleName());
    if (therealready == NULL) {
      const SBMLDocument* subdoc = origmod->GetSBML(true);
      const ModelDefinition md(*(subdoc->getModel()));
      int rv = compdoc->addModelDefinition(&md);
    }
  }
}

void Module::ReturnSubmodelsFromDocument(SBMLDocument* sbml)
{
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(sbml->getPlugin("comp"));

  for (unsigned int md=0; md<compdoc->getNumModelDefinitions(); md++) {
    ModelDefinition* modeldef = compdoc->getModelDefinition(md);
    string id = modeldef->getId();
    Module* module = g_registry.GetModule(id);
    module->m_sbml.setModel(modeldef);
  }
}

Port* GetPortFor(SBase* referent, Model* topmodel)
{
  Port* port = NULL;
  SBase* parent = referent->getParentSBMLObject();
  while (parent != NULL && parent != topmodel) {
    if (parent->getTypeCode() == SBML_MODEL ||
        parent->getTypeCode() == SBML_COMP_MODELDEFINITION) {
          Model* modparent = static_cast<Model*>(parent);
          CompModelPlugin* cmp = static_cast<CompModelPlugin*>(modparent->getPlugin("comp"));
          for (unsigned long p=0; p<cmp->getNumPorts(); p++) {
            Port* modport = cmp->getPort(p);
            if (modport->getReferencedElement() == referent) {
              port = modport;
              //However, don't stop the loop, because we want the topmost reference.
            }
          }
    }
    parent = parent->getParentSBMLObject();
  }
  return port;
}


//When we create an SBML model, we never use ports.  Now we need to go through the model and use them if possible.
void FixPortReferencesIn(Model* sbmlmod)
{
  CompModelPlugin* cmp = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
  for (size_t sm=0; sm<cmp->getNumSubmodels(); sm++) {
    Submodel* submod = cmp->getSubmodel(static_cast<unsigned int>(sm));
    submod->clearInstantiation();
    set<SBase*> referents;
    set<Deletion*> extradels;
    for (size_t d=0; d<submod->getNumDeletions(); d++) {
      Deletion* deletion = submod->getDeletion(static_cast<unsigned int>(d));
      deletion->saveReferencedElement();
      SBase* referent = deletion->getReferencedElement();
      if (referent == NULL) {
        assert(false); //??
        extradels.insert(deletion);
      }
      if (referents.insert(referent).second == false) {
        extradels.insert(deletion);
      }
    }
    for (set<Deletion*>::iterator d=extradels.begin(); d!=extradels.end(); d++) {
      (*d)->removeFromParentAndDelete();
    }
  }
  List* elements = sbmlmod->getAllElements();
  vector<SBaseRef*> sBaseRefs;
  for (unsigned int el=0; el<elements->getSize(); el++) {
    SBase* element = static_cast<SBase*>(elements->get(el));
    SBaseRef* sbr = static_cast<SBaseRef*>(element);
    switch (element->getTypeCode()) {
    case SBML_COMP_DELETION:
    case SBML_COMP_REPLACEDBY:
    case SBML_COMP_REPLACEDELEMENT:
    case SBML_COMP_PORT:
      //We only want the top-level SBaseRefs, not any instances of the SBaseRef class itself.
      sBaseRefs.push_back(sbr);
      break;
    default:
      break;
    }
  }
  delete elements;
  for (size_t s=0; s<sBaseRefs.size(); s++) {
    SBaseRef* sbr = sBaseRefs[s];
    sbr->saveReferencedElement();
    SBase* referent = sbr->getReferencedElement();
    Port* port = GetPortFor(referent, sbmlmod);
    if (port != NULL) {
      //We need to remap sbr to point to the Port instead.
      vector<SBase*> portchain;
      portchain.push_back(port);
      SBase* parent = port->getParentSBMLObject();
      while (parent != NULL && parent->getTypeCode() != SBML_DOCUMENT) {
        if (parent->getTypeCode() == SBML_COMP_SUBMODEL) {
          portchain.push_back(parent);
        }
        parent = parent->getParentSBMLObject();
      }
      //Remove the top-level submodel, which will already be referenced
      portchain.pop_back();
      assert(portchain.size() > 0);
      sbr->unsetSBaseRef();
      sbr->unsetIdRef();
      sbr->unsetMetaIdRef();
      sbr->unsetUnitRef();
      //Antimony doesn't create any DeletionRefs, so we're OK there.
      for (size_t pc=portchain.size()-1; pc>0; pc--) {
        SBase* submodel = portchain[pc];
        sbr->setIdRef(submodel->getId());
        sbr = sbr->createSBaseRef();
      }
      sbr->setPortRef(port->getId());
    }
  }
}

#endif  //USE_COMP

void Module::TranslateRulesAndAssignmentsTo(const SBase* obj, Variable* var)
{
  const InitialAssignment* ia = NULL;
  const Rule* rule = NULL;
  bool noreplace = true;
  bool origformisblank = var->GetFormula()->IsEmpty();

#ifdef USE_COMP
  const CompSBasePlugin* cplugin = static_cast<const CompSBasePlugin*>(obj->getPlugin("comp"));
  //While we are searching for replaced elements, etc., find the single canonical version of these things, if they exist.
  if (cplugin != NULL) {
    for (unsigned int re=0; re<cplugin->getNumReplacedElements(); re++) {
      const ReplacedElement* replaced = cplugin->getReplacedElement(re);
      Variable* conversionFactor = NULL;
      if (replaced->isSetConversionFactor()) {
        conversionFactor = AddOrFindVariable(&replaced->getConversionFactor());
      }
      Variable* smvar = NULL;
      GetReplacingAndRules(replaced, "replaced element", obj, smvar, ia, rule);
      noreplace = false;
      if (smvar!=NULL) {
        if (ia != NULL || 
            (rule != NULL && rule->isAssignment())) {
          //If 'var' was set with an initialValue (or equivalent) it should be overridden by the initial assignment.  But when we call 'synchronize', that routine doesn't know the difference, so we need to clear it first.  The same is true of assignment rules.
          Formula form;
          var->SetFormula(&form);
        }
        smvar->Synchronize(var, conversionFactor);
        //If it is NULL, we've already added an appropriate warning.
      }
    }
    if (cplugin->isSetReplacedBy()) {
      const ReplacedBy* replacedby = cplugin->getReplacedBy();
      Variable* smvar;
      GetReplacingAndRules(replacedby, "replacement element", obj, smvar, ia, rule);
      noreplace = false;
      if (smvar!=NULL) {
        var->Synchronize(smvar, NULL);
        //If it is NULL, we've already added an appropriate warning.
        //Also, replacedBy elements don't have conversion factors.
      }
    }
  }
#endif
  if (noreplace) {
    const SBase* parentmod = obj;
    while (parentmod != NULL && parentmod->getTypeCode() != SBML_MODEL 
#ifdef USE_COMP
      && parentmod->getTypeCode() != SBML_COMP_MODELDEFINITION
#endif
      ) {
      parentmod = parentmod->getParentSBMLObject();
    }
    const Model* pm = static_cast<const Model*>(parentmod);
    ia = pm->getInitialAssignment(obj->getId());
    rule = pm->getRule(obj->getId());
  }
  if (ia != NULL) {
    bool localparent = true;
#ifdef USE_COMP
    //We need to check to see if the initial assignment replaced anything
    CompSBasePlugin* iaplugin = const_cast<CompSBasePlugin*>(static_cast<const CompSBasePlugin*>(ia->getPlugin("comp")));
    if (iaplugin != NULL) {
      if (iaplugin->isSetReplacedBy()) {
        //Ignore this rule
        localparent = false;
      }
      for (unsigned int re = 0; re<iaplugin->getNumReplacedElements(); re++) {
        ReplacedElement* replacedelement = iaplugin->getReplacedElement(re);
        const SBase* target = replacedelement->getReferencedElement();
        assert(target != NULL);
        if (target != NULL) {
          const InitialAssignment* targetia = static_cast<const InitialAssignment*>(target);
          vector<string> tia_name;
          const SBaseRef* sbr = replacedelement->getSBaseRef();
          tia_name.push_back(targetia->getSymbol());
          const SBase* parentsub = targetia->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
          while (parentsub != NULL) {
            const Submodel* submod = static_cast<const Submodel*>(parentsub);
            tia_name.insert(tia_name.begin(), submod->getId());
            parentsub = parentsub->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
          }
          Variable* target = GetVariable(tia_name);
          vector<string> submodname;
          submodname.push_back(replacedelement->getSubmodelRef());
          Variable* submodel = GetVariable(submodname);
          submodel->AddDeletion(target, delInitialAssignment);
          Formula blankform;
          target->SetFormula(&blankform);
        }
      }
    }
    const SBase* parent = ia->getParentSBMLObject();
    while (parent != NULL) {
      if (parent->getTypeCode() == SBML_COMP_SUBMODEL) {
        localparent = false;
      }
      parent = parent->getParentSBMLObject();
    }
#endif
    if (localparent) {
      Formula formula;
      string formulastring(parseASTNodeToString(ia->getMath()));
      setFormulaWithString(formulastring, &formula, this);
      formula.SetNewTopNameWith(ia, GetModuleName());
      formula.ReadAnnotationFrom(ia);
      var->SetFormula(&formula);
    }
  }
#ifdef USE_COMP
  else if (ia == NULL && (rule == NULL || !rule->isAssignment()) && cplugin != NULL && !cplugin->isSetReplacedBy() && origformisblank && !var->GetFormula()->IsEmpty()) {
    //We need to ensure that synchronization didn't overwrite the original blank.
    Formula form;
    var->SetFormula(&form);
  }
#endif
  if (rule != NULL) {
    bool localparent = true;
#ifdef USE_COMP
    //We need to check to see if the rule replaced anything
    CompSBasePlugin* ruleplugin = const_cast<CompSBasePlugin*>(static_cast<const CompSBasePlugin*>(rule->getPlugin("comp")));
    if (ruleplugin != NULL) {
      if (ruleplugin->isSetReplacedBy()) {
        //Ignore this rule
        localparent = false;
      }
      for (unsigned int re = 0; re<ruleplugin->getNumReplacedElements(); re++) {
        ReplacedElement* replacedelement = ruleplugin->getReplacedElement(re);
        SBase* target = replacedelement->getReferencedElement();
        assert(target != NULL);
        if (target != NULL) {
          const Rule* targetrule = static_cast<Rule*>(target);
          vector<string> trule_name;
          trule_name.push_back(targetrule->getVariable());
          const SBase* parentsub = targetrule->getParentSBMLObject();
          while (parentsub != NULL) {
            if (parentsub->getTypeCode() == SBML_COMP_SUBMODEL) {
              const Submodel* submod = static_cast<const Submodel*>(parentsub);
              trule_name.insert(trule_name.begin(), submod->getId());
            }
            parentsub = parentsub->getParentSBMLObject();
          }
          Variable* target = GetVariable(trule_name);
          vector<string> submodname;
          submodname.push_back(replacedelement->getSubmodelRef());
          Variable* submodel = GetVariable(submodname);
          deletion_type deltype = delRateRule;
          Formula blankform;
          if (targetrule->getTypeCode() == SBML_ASSIGNMENT_RULE) {
            deltype = delAssignmentRule;
            target->SetFormula(&blankform);
          }
          else {
            target->SetRateRule(&blankform);
          }
          submodel->AddDeletion(target, deltype);

        }
      }
    }
    const SBase* parent = rule->getParentSBMLObject();
    while (parent != NULL) {
      if (parent->getTypeCode() == SBML_COMP_SUBMODEL) {
        localparent = false;
      }
      parent = parent->getParentSBMLObject();
    }
#endif
    if (localparent) {
      var->SetWithRule(rule);
    }
  }
  else if (!var->GetRateRule()->IsEmpty()) {
    //The old rate rule must have been deleted.
    Formula form;
    var->SetRateRule(&form);
  }
}

void SynchronizeLocalAndGlobal(const vector<string>& paramname, const vector<string>& targetname, Module* mod)
{
  vector<string> localname;
  localname.push_back(paramname[paramname.size()-1]);
  Variable* paramvar = mod->GetVariable(paramname);
  Variable* targetvar = mod->GetVariable(targetname);
  Variable* localvar = mod->GetVariable(localname);
  if (localvar == NULL) {
    localvar = mod->AddOrFindVariable(&localname[0]);
  }
  else {
    localvar = mod->AddNewNumberedVariable(localname[0]);
  }
  paramvar->Synchronize(localvar, NULL);
  targetvar->Synchronize(localvar, NULL);
}

void Module::LoadSBML(Model* sbml)
{
  if (sbml == NULL) {
    return;
  }
  //Some models use an old 'rateOf' function, which we can update to the l3v2 version.
  UpdateRateOf(sbml);

  //Some SBML-OK names are not OK in Antimony
  FixNames(sbml);
  if(sbml->isSetName())
    SetDisplayName(sbml->getName());
  PopulateCVTerms((SBase*)sbml);
  ReadAnnotationFrom(sbml);
#ifdef USE_COMP
  //Load submodels
  const CompModelPlugin* mplugin = static_cast<const CompModelPlugin*>(sbml->getPlugin("comp"));
  if (mplugin != NULL) {
    for (unsigned int sm=0; sm<mplugin->getNumSubmodels(); sm++) {
      const Submodel* submodel = mplugin->getSubmodel(sm);
      string submodname = getNameFromSBMLObject(submodel, "submod");
      Variable* var = AddOrFindVariable(&submodname);
      Formula blankform;
      if (submodel->isSetName()) {
        var->SetDisplayName(submodel->getName());
      }
      var->ReadAnnotationFrom(submodel);
      string refname = submodel->getModelRef();
      if (g_registry.GetModule(refname)==NULL) {
        g_registry.LoadModelFrom(refname, sbml->getSBMLDocument());
      }
      if (var->SetModule(&refname)) {
        g_registry.AddWarning("Unable to find submodel " + refname + ".");
      }
      var->ReadAnnotationFrom(submodel);
      for (unsigned int d=0; d<submodel->getNumDeletions(); d++) {
        Deletion* deletion = const_cast<Deletion*>(submodel->getDeletion(d));
        string delname = deletion->getId();
        if (!delname.empty()) {
          delname += " ";
          }
        SBase* target = deletion->getReferencedElement();
        if (target != NULL) {
          SBase* submodparent = target->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
          vector<string> targetname;
          while (submodparent != NULL) {
            targetname.insert(targetname.begin(), submodparent->getId());
            submodparent = submodparent->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
          }
          vector<string> delparentname = targetname;
          vector<string> paramname = targetname;
          SBase* typeparent = target->getAncestorOfType(SBML_EVENT);
          Event* event = static_cast<Event*>(typeparent);
          typeparent = target->getAncestorOfType(SBML_REACTION);
          Reaction* reaction = static_cast<Reaction*>(typeparent);
          SpeciesReference* sr = static_cast<SpeciesReference*>(target);
          Variable* deletedvar = NULL;
          Variable* origparam = NULL;
          Variable* newparam = NULL;
          set<pair<vector<string>, deletion_type> > noret;
          size_t numvars = m_variables.size();
          switch (target->getTypeCode()) {
          case SBML_INITIAL_ASSIGNMENT:
            paramname.push_back(target->getId());
            var->AddDeletion(paramname, delInitialAssignment);
            deletedvar = GetVariable(paramname);
            deletedvar->SetFormula(&blankform);
            break; 
          case SBML_RATE_RULE:
            paramname.push_back(target->getId());
            var->AddDeletion(paramname, delRateRule);
            deletedvar = GetVariable(paramname);
            deletedvar->SetRateRule(&blankform);
            break; 
          case SBML_ASSIGNMENT_RULE:
            paramname.push_back(target->getId());
            var->AddDeletion(paramname, delAssignmentRule);
            deletedvar = GetVariable(paramname);
            deletedvar->SetAssignmentRule(&blankform);
            break; 
          case SBML_SPECIES:
          case SBML_COMPARTMENT:
          case SBML_PARAMETER:
          case SBML_REACTION:
          case SBML_EVENT:
          case SBML_UNIT_DEFINITION:
          case SBML_COMP_SUBMODEL:
            if (!target->isSetId()) {
              g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because the target " + SBMLTypeCode_toString(target->getTypeCode(), target->getPackageName().c_str()) + " element did not have an ID.");
              continue;
            }
            targetname.push_back(target->getId());
            deletedvar = GetVariable(targetname);
            if (deletedvar == NULL) {
              assert(targetname[targetname.size()-1] == DEFAULTCOMP);
              break;
            }
            AddDeletion(deletedvar);
            deletedvar->ReadAnnotationFrom(deletion);
            if (target->getTypeCode() == SBML_UNIT_DEFINITION) {
              deletedvar->SetIsDeletedUnit(true);
            }
            break;
          case SBML_PRIORITY:
          case SBML_DELAY:
          case SBML_EVENT_ASSIGNMENT:
          case SBML_TRIGGER:
            //Delete the target, then re-calculate the event:
            assert(event != NULL);
            if (!event->isSetId()) {
              g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because the Event parent of the deleted " + SBMLTypeCode_toString(target->getTypeCode(), "core") + " element did not have an ID, making it impossible for Antimony to determine which event was being modified.");
              continue;
            }
            targetname.push_back(event->getId());
            deletedvar = GetVariable(targetname);
            assert(deletedvar != NULL);
            switch(target->getTypeCode()) {
            case SBML_PRIORITY:
              var->AddDeletion(targetname, delEventPriority);
              break;
            case SBML_DELAY:
              var->AddDeletion(targetname, delEventDelay);
              break;
            case SBML_EVENT_ASSIGNMENT:
              targetname.push_back(target->getId());
              var->AddDeletion(targetname, delEventAssignment);
              break;
            case SBML_TRIGGER:
              break;
            default:
              break;
            }
            target->removeFromParentAndDelete();
            SetVarWithEvent(deletedvar, event, this, delparentname);
            while (m_variables.size() > numvars) {
              //We added variables from the strings in the event, but they are superfluous; take them back out.
              m_variables.pop_back();
            }
            break;
          case SBML_ALGEBRAIC_RULE:
            g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ".  " + SBMLTypeCode_toString(target->getTypeCode(), "core") + " elements cannot be expressed in Antimony at all.  (Deleting them is therefore safe, because they are automatically dropped anyway.)");
          case SBML_CONSTRAINT:
            g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because Constraints do not have IDs in SBML.");
            break;
          case SBML_FUNCTION_DEFINITION:
            g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ".  Function definitions are global in Antimony, not local, and therefore cannot be deleted from submodels.");
            break;
          case SBML_LOCAL_PARAMETER:
            assert(reaction != NULL);
            if (!reaction->isSetId()) {
              g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because the Reaction parent of the deleted Local Parameter did not have an ID, making it impossible for Antimony to determine which event was being modified.");
              continue;
            }
            paramname.push_back(reaction->getId());
            deletedvar = GetVariable(paramname);
            assert(deletedvar != NULL);
            paramname = targetname;
            paramname.push_back(target->getId());
            targetname.push_back(GetNewIDForLocalParameter(target));
            SynchronizeLocalAndGlobal(paramname, targetname, this);
            break;
          case SBML_SPECIES_REFERENCE:
            assert(reaction != NULL);
            if (!reaction->isSetId()) {
              g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because the Reaction parent of the deleted species reference did not have an ID, making it impossible for Antimony to determine which event was being modified.");
              continue;
            }
            paramname.push_back(reaction->getId());
            deletedvar = GetVariable(paramname);
            assert(deletedvar != NULL);
            paramname = targetname;
            paramname.push_back(sr->getSpecies());
            origparam = GetVariable(paramname);
            if (deletedvar->GetType() == varDeleted) {
              //Don't need to delete a child of a deleted thing
              break;
            }
            deletedvar->GetReaction()->ClearReferencesTo(origparam, &(var->m_deletions));
            break;
          case SBML_KINETIC_LAW:
            assert(reaction != NULL);
            if (!reaction->isSetId()) {
              g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ", because the Reaction parent of the deleted Local Parameter did not have an ID, making it impossible for Antimony to determine which event was being modified.");
              continue;
            }
            paramname.push_back(reaction->getId());
            deletedvar = GetVariable(paramname);
            assert(deletedvar != NULL);
            deletedvar->GetReaction()->GetFormula()->Clear();
            var->AddDeletion(paramname, delKineticLaw);
            break;
          case SBML_MODIFIER_SPECIES_REFERENCE:
            assert(reaction != NULL);
            paramname.push_back(reaction->getId());
            paramname.push_back(sr->getSpecies());
            var->AddDeletion(paramname, delModifier);
            paramname.pop_back();
            paramname.pop_back();
            if (reaction->isSetKineticLaw()) {
              //Antimony is going to re-create the modifier species references, so we don't need to do anything.
              break;
            }
            //Otherwise, we tried to create an interaction for it based on the name.
            if (target->isSetName()) {
              paramname.push_back(target->getName());
              deletedvar = GetVariable(paramname);
              if (deletedvar != NULL) {
                if (deletedvar->GetType() == varInteraction) {
                  AddDeletion(deletedvar);
                  deletedvar->ReadAnnotationFrom(deletion);
                  break;
                }
                if (deletedvar->GetType() == varDeleted) break;
                g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ".  Modifier species references are translated as 'interactions' in Antimony, but this reference was not able to be discovered.  If this problem persists, try setting the 'name' attribute on the modifier, which Antimony can then use to name the interaction.");
              }
            }
          default:
            //From core:
            /*
              SBML_UNIT 	
              SBML_LISTOF
            */
            //var = AddOrFindVariable(&delname);
            g_registry.AddWarning("Unable to process deletion " + delname + "from submodel " + submodname + " in model " + GetModuleName() + ".  Deletions of " + SBMLTypeCode_toString(target->getTypeCode(), target->getPackageName().c_str()) + " elements have not been added as a concept in Antimony.");
            break;
          }
        }
      }
      if (submodel->isSetTimeConversionFactor()) {
        string tcf = submodel->getTimeConversionFactor();
        Variable* tcfvar = AddOrFindVariable(&tcf);
        var->SetTimeConversionFactor(tcfvar);
      }
      if (submodel->isSetExtentConversionFactor()) {
        string xcf = submodel->getExtentConversionFactor();
        Variable* xcfvar = AddOrFindVariable(&xcf);
        var->SetExtentConversionFactor(xcfvar);
      }
    }
  }
#endif //USE_COMP
  //m_sbml = *sbmldoc;
  string sbmlname = "";

  //Function Definitions
  //This is a bit weird, since functions exist outside of modules, since they can be used in any model.  So we have to go to the registry to save them.
  for (unsigned int func=0; func<sbml->getNumFunctionDefinitions(); func++) {
    const FunctionDefinition* function = sbml->getFunctionDefinition(func);
    sbmlname = getNameFromSBMLObject(function, "_F");
    string annot = function->getAnnotationString();
    //List* allElements = const_cast<Model*>(sbml)->getAllElements();
    if (annot.find("http://sbml.org/annotations/symbols") != string::npos &&
        annot.find("http://en.wikipedia.org/wiki/Derivative") != string::npos )
    {
      //It's the special 'rateOf' function.  However, if the name is not 'rateOf' or 'rate', we need to change it to be one of those two.
      //if (sbmlname != "rateOf" && sbmlname != "rate") {
      //  for (unsigned int e=0; e<allElements->getSize(); e++) {
      //    SBase* element = static_cast<SBase*>(allElements->get(e));
      //    element->renameSIdRefs(sbmlname, "rateOf");
      //  }
      //  sbmlname = "rateOf";
      //}
      m_rateNames.insert(sbmlname);
      continue;
    }
    
    UserFunction* uf = g_registry.GetUserFunction(sbmlname);
    bool duplicate = false;
    while (uf != NULL && !duplicate) {
      if (parseASTNodeToString(function->getMath()) == uf->ToSBMLString()) {
        duplicate = true;
      }
      else {
        sbmlname = getNameFromSBMLObject(sbml, "fd") + "_" + sbmlname;
        uf = g_registry.GetUserFunction(sbmlname);
      }
    }
    if (duplicate) {
      uf->ReadAnnotationFrom(function);
      uf->SetDisplayName(function->getName());
      continue;
    }
    g_registry.NewUserFunction(&sbmlname);
    uf = g_registry.GetUserFunction(sbmlname);
    uf->PopulateCVTerms((SBase*)function);
    uf->ReadAnnotationFrom(function);
    uf->SetDisplayName(function->getName());
    for (unsigned int arg=0; arg<function->getNumArguments(); arg++) {
      string argument(parseASTNodeToString(function->getArgument(arg)));
      Variable* expvar = g_registry.AddVariableToCurrent(&argument);
      g_registry.AddVariableToCurrentExportList(expvar);
    }
    const ASTNode* astn = function->getBody();
    if (!m_usedDistributions && UsesDistrib(astn)) {
        m_usedDistributions = true;
    }
    string formulastring(parseASTNodeToString(astn));
    Formula formula;
    setFormulaWithString(formulastring, &formula, uf);
    g_registry.SetUserFunction(&formula);
    g_registry.GetNthUserFunction(g_registry.GetNumUserFunctions()-1)->FixNames();
  }

  //Units
  for (unsigned int ud=0; ud<sbml->getNumUnitDefinitions(); ud++) {
    const UnitDefinition* unitdefinition = sbml->getUnitDefinition(ud);
    sbmlname = getNameFromSBMLObject(unitdefinition, "_UD");
    FixUnitName(sbmlname);
    Variable* var = AddOrFindVariable(&sbmlname);
    var->ReadAnnotationFrom(unitdefinition);
    if (unitdefinition->isSetName()) {
      var->SetDisplayName(unitdefinition->getName());
    }
    UnitDef unitdef = GetUnitDefFrom(unitdefinition, m_modulename);
    var->SetUnitDef(&unitdef);
  }

  //Model-wide units:
  string unitname;
  if (sbml->isSetLengthUnits()) {
    string lunits = sbml->getLengthUnits();
    unitname = "length";
    if (lunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(lunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
  if (sbml->isSetAreaUnits()) {
    string aunits = sbml->getAreaUnits();
    unitname = "area";
    if (aunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(aunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
  if (sbml->isSetVolumeUnits()) {
    string vunits = sbml->getVolumeUnits();
    unitname = "volume";
    if (vunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(vunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
  if (sbml->isSetSubstanceUnits()) {
    string sunits = sbml->getSubstanceUnits();
    unitname = "substance";
    if (sunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(sunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
  if (sbml->isSetExtentUnits()) {
    string xunits = sbml->getExtentUnits();
    unitname = "extent";
    if (xunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(xunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
  if (sbml->isSetTimeUnits()) {
    string tunits = sbml->getTimeUnits();
    unitname = "time_unit";
    if (tunits != unitname) {
      Variable* var = AddOrFindVariable(&unitname);
      UnitDef unitdef = UnitDef(tunits, m_modulename);
      var->SetUnitDef(&unitdef);
    }
  }
 
  //Compartments
  set<string> defaultcompartments;
  for (unsigned int comp=0; comp<sbml->getNumCompartments(); comp++) {
    const Compartment* compartment = sbml->getCompartment(comp);
    sbmlname = getNameFromSBMLObject(compartment, "_C");
    if (compartment->getSBOTerm() == 410) {
      //The 'implicit compartment'
      defaultcompartments.insert(sbmlname);
      continue;
    }
    if (sbmlname == DEFAULTCOMP && compartment->getConstant() && compartment->isSetSize() && compartment->getSize() == 1.0) {
      defaultcompartments.insert(sbmlname);
      continue;
      //LS NOTE: we assume this was created with Antimony, and ignore the auto-generated 'default compartment'
      // Later versions of antimony now set the SBO terms to 410, so we might not need this code very long.
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    var->PopulateCVTerms((SBase*)compartment);
    var->ReadAnnotationFrom(compartment);
    if (compartment->isSetName()) {
      var->SetDisplayName(compartment->getName());
    }
    var->SetType(varCompartment);
    Formula formula;
    if (compartment->isSetSize()) {
      formula.AddNum(compartment->getSize());
      var->SetFormula(&formula);
    }
    if (compartment->isSetUnits()) {
      var->SetUnitVariable(compartment->getUnits());
    }
    if (compartment->isSetConstant()) {
      var->SetIsConst(compartment->getConstant());
    }
    TranslateRulesAndAssignmentsTo(compartment, var);
  }

  //Species
  for (unsigned int spec=0; spec<sbml->getNumSpecies(); spec++) {
    const Species* species = sbml->getSpecies(spec);
    sbmlname = getNameFromSBMLObject(species, "_S");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (species->isSetName()) {
      var->SetDisplayName(species->getName());
    }
    var->SetType(varSpeciesUndef);
    var->PopulateCVTerms((SBase*)species);
    var->ReadAnnotationFrom(species);
    var->SetSubstOnly(species->getHasOnlySubstanceUnits());

    //Setting the formula
    Formula formula;
    if (species->isSetInitialAmount()) {
      double amount = species->getInitialAmount();
      formula.AddNum(amount);
      if (amount != 0 && defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
        Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
        Formula* compform = compartment->GetFormula();
        formula.AddMathThing('/');
        formula.AddVariable(compartment);
      }
      var->SetFormula(&formula);
    }
    else if (species->isSetInitialConcentration()) {
      formula.AddNum(species->getInitialConcentration());
      var->SetFormula(&formula);
    }
    //Anything more complicated is set in a Rule, which we'll get to later.

    if (species->getConstant() || species->getBoundaryCondition()) {
      //Since all species are variable by default, we only set this explicitly if true.
      var->SetIsConst(true);
    }
    Variable* compartment = NULL;
    if (defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
      compartment = AddOrFindVariable(&(species->getCompartment()));
      compartment->SetType(varCompartment);
      var->SetCompartment(compartment);
    }
    if (species->isSetUnits()) {
      string unitname = species->getUnits();
      FixUnitName(unitname);
      Variable* spunits = AddOrFindVariable(&unitname);
      spunits->SetType(varUnitDefinition);
      UnitDef ud(*spunits->GetUnitDef());
      UnitDef* compud = NULL;
      if (compartment==NULL) {
        string volume = "volume";
        compud = AddOrFindVariable(&volume)->GetUnitDef();
      }
      else {
        Variable* compunits = compartment->GetUnitVariable();
        if (compunits == NULL) {
          vector<string> volname;
          volname.push_back("volume");
          compunits = GetVariable(volname);
          if (compunits == NULL) {
            compunits = GetDefaultVariable(volname);
          }
          assert(compunits != NULL);
        }
        compud = compunits->GetUnitDef();
      }
      ud.DivideUnitDef(compud);
      ud.Reduce();
      Variable* concentrationUnits = AddOrFindUnitDef(ud);
      var->SetUnitVariable(concentrationUnits);
    }
    TranslateRulesAndAssignmentsTo(species, var);
  }

  //Events:
  for (unsigned int ev=0; ev<sbml->getNumEvents(); ev++) {
    const Event* event = sbml->getEvent(ev);
    sbmlname = getNameFromSBMLObject(event, "_E");
    if (!event->isSetId()) {
      Event* ncevent = const_cast<Event*>(event);
      ncevent->setId(sbmlname);
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    vector<string> nosub;
    SetVarWithEvent(var, event, this, nosub);
    var->ReadAnnotationFrom(event);
  }

  //Constraints:
  vector<AntimonyConstraint> constraints;
  for (unsigned int c=0; c<sbml->getNumConstraints(); c++) {
    const Constraint* constraint = sbml->getConstraint(c);
    sbmlname = getNameFromSBMLObject(constraint, "_con");
    Variable* var = AddOrFindVariable(&sbmlname);
    var->ReadAnnotationFrom(constraint);
    if (constraint->isSetMessage()) {
      string msg = constraint->getMessageString();
      msg = StripMsgXML(msg);
      var->SetDisplayName(msg);
    }
    if (constraint->isSetMath()) {
      AntimonyConstraint acon(var);
      const ASTNode* astn = constraint->getMath();
      if (!m_usedDistributions && UsesDistrib(astn)) {
          m_usedDistributions = true;
      }
      acon.SetWithASTNode(astn);
      var->SetConstraint(&acon);
      constraints.push_back(acon);
    }
  }

  //Parameters
  for (unsigned int param=0; param<sbml->getNumParameters(); param++) {
    const Parameter* parameter = sbml->getParameter(param);
    sbmlname = getNameFromSBMLObject(parameter, "_P");
    Variable* var = AddOrFindVariable(&sbmlname);
    var->PopulateCVTerms((SBase*)parameter);
    var->ReadAnnotationFrom(parameter);
    if (parameter->isSetName()) {
      var->SetDisplayName(parameter->getName());
    }
    if (parameter->isSetValue()) {
      Formula* formula = g_registry.NewBlankFormula();
      formula->AddNum(parameter->getValue());
      var->SetFormula(formula);
      //LS NOTE:  If a parameter has both a value and an 'initial assignment', the initial assignment will override the value.
    }
    if (parameter->isSetUnits()) {
      var->SetUnitVariable(parameter->getUnits());
    }
    if (parameter->isSetConstant()) {
      var->SetIsConst(parameter->getConstant());
    }
    TranslateRulesAndAssignmentsTo(parameter, var);
  }

  //If we ever get algebraic rules, we will need to set them up here, for both comp and non-comp (and check their replacements).

  //Reactions
  for (unsigned int rxn=0; rxn<sbml->getNumReactions(); rxn++) {
    const Reaction* reaction = sbml->getReaction(rxn);
    sbmlname = getNameFromSBMLObject(reaction, "_J");
    Variable* var = AddOrFindVariable(&sbmlname);
    var->PopulateCVTerms((SBase*)reaction);
    var->ReadAnnotationFrom(reaction);
    if (reaction->isSetName()) {
      var->SetDisplayName(reaction->getName());
    }

    //reactants and products
    ReactantList reactants;
    ReactantList products;
    for (int lr = 0; lr < 2; lr++) {
        const ListOfSpeciesReferences* losr = reaction->getListOfReactants();
        ReactantList* rl = &reactants;
        if (lr == 1) {
            losr = reaction->getListOfProducts();
            rl = &products;
        }
        for (unsigned int react = 0; react < losr->size(); react++) {
            const SpeciesReference* specref = static_cast<const SpeciesReference*>(losr->get(react));
            Variable* stoichvar = NULL;
            double stoichiometry = 1;
            if (specref->isSetStoichiometryMath()) {
                string reactantId = specref->getId();
                if (reactantId.empty()) {
                    reactantId = sbmlname + "_" + specref->getSpecies() + "_stoichiometry";
                }
                stoichvar = AddOrFindVariable(&reactantId);
                assert(!stoichvar->SetType(varStoichiometry)); //Since the SBML file is valid.
                Formula formula;
                string formulastring(parseASTNodeToString(specref->getStoichiometryMath()->getMath()));
                setFormulaWithString(formulastring, &formula, this);
                formula.SetNewTopNameWith(specref, GetModuleName());
                formula.ReadAnnotationFrom(specref);
                stoichvar->SetAssignmentRule(&formula);
            }
            else if (specref->isSetIdAttribute()) {
                stoichvar = AddOrFindVariable(&(specref->getIdAttribute()));
                bool setret = stoichvar->SetType(varStoichiometry); //Since the SBML file is valid.
                assert(!setret);
                if (specref->isSetStoichiometry() && !stoichvar->HasFormula()) {
                    Formula formula;
                    formula.AddNum(specref->getStoichiometry());
                    stoichvar->SetFormula(&formula);
                }
                TranslateRulesAndAssignmentsTo(specref, stoichvar);
            }
            else {
                if (specref->isSetStoichiometry()) {
                    stoichiometry = specref->getStoichiometry();
                }
            }
            sbmlname = specref->getSpecies();
            if (sbmlname == "") {
                sbmlname = getNameFromSBMLObject(specref, "_S");
            }
            Variable* rvar = AddOrFindVariable(&sbmlname);
            if (stoichvar) {
                rl->AddReactant(rvar, stoichvar);
            }
            else {
                rl->AddReactant(rvar, stoichiometry);
            }
#ifdef USE_COMP
            const CompSBasePlugin* csbp = static_cast<const CompSBasePlugin*>(specref->getPlugin("comp"));
            if (csbp != NULL && (csbp->getNumReplacedElements() != 0 || csbp->isSetReplacedBy())) {
                g_registry.AddWarning("Cannot replace stoichiometries in Antimony:  all replacedElements and replacedBy children of " + specref->getSpecies() + " in reaction " + reaction->getId() + " will be ignored.");
            }
#endif
        }
    }

    //formula
    string formulastring = "";
    Formula formula;
    if (reaction->isSetKineticLaw()) {
      const KineticLaw* kl = reaction->getKineticLaw();
      formula.ReadAnnotationFrom(kl);
      ASTNode* astn = NULL;
      if (kl->isSetMath()) {
        astn = kl->getMath()->deepCopy();
      }
      for (unsigned int localp=0; localp<kl->getNumParameters(); localp++) {
        const Parameter* localparam = kl->getParameter(localp);
        string origname = localparam->getId();

        //Create a new variable with a new name:
        vector<string> fullname;
        sbmlname = GetNewIDForLocalParameter(localparam);
        fullname.push_back(sbmlname);
        Variable* localvar = AddOrFindVariable(&sbmlname);
        localvar->ReadAnnotationFrom(localparam);
        //Change the ASTNode so that old idrefs point to the new name.
        if (astn) {
          astn->renameSIdRefs(localparam->getId(), sbmlname);
        }
        //Set the value for the new variable:
        if (localparam->isSetValue()) {
          Formula localformula;
          localformula.AddNum(localparam->getValue());
          localvar->SetFormula(&localformula);
        }
        if (localparam->isSetUnits()) {
          localvar->SetUnitVariable(localparam->getUnits());
        }
      }
      if (astn) {
        formulastring = parseASTNodeToString(astn);
        setFormulaWithString(formulastring, &formula, this);
        if (!m_usedDistributions && UsesDistrib(astn)) {
            m_usedDistributions = true;
        }
        delete astn;
      }
    }
    else if (reaction->getNumModifiers() > 0) {
      //If the kinetic law is empty, we can set some interactions, if there are any Modifiers.
      ReactantList right;
      right.AddReactant(var);
      for (unsigned int mod=0; mod<reaction->getNumModifiers(); mod++) {
        ReactantList left;
        const ModifierSpeciesReference* msr = reaction->getModifier(mod);
        string species = msr->getSpecies();
        Variable* specvar = AddOrFindVariable(&species);
        left.AddReactant(specvar);
        sbmlname = getNameFromSBMLObject(msr, "_I");
        rd_type itype = rdInfluences;
        if (msr->isSetSBOTerm()) {
          if (msr->getSBOTerm() == 20) {
            itype = rdInhibits;
          }
          else if (msr->getSBOTerm() == 459) {
            itype = rdActivates;
          }
        }
        Variable* interaction = AddOrFindVariable(&sbmlname);
        Formula blankform;
        AddNewReaction(left, itype, right, &blankform, interaction);
      }
    }
    rd_type rxntype = rdBecomes;
    if (!reaction->getReversible()) {
      rxntype = rdBecomesIrreversibly;
    }
    //Put reactants, products, and the formula together:
    Variable* arxn = AddNewReaction(reactants, rxntype, products, &formula, var);
      if (reaction->isSetCompartment()) {
        if (defaultcompartments.find(reaction->getCompartment()) == defaultcompartments.end()) {
          Variable* compartment = AddOrFindVariable(&(reaction->getCompartment()));
          compartment->SetType(varCompartment);
          arxn->SetCompartment(compartment);
        }

      }
    TranslateRulesAndAssignmentsTo(reaction, var);
  }

  //FBC Constraints:
#ifdef LIBSBML_HAS_PACKAGE_FBC
  const FbcModelPlugin* fmp = static_cast<const FbcModelPlugin*>(sbml->getPlugin("fbc"));
  if (fmp != NULL) {
    for (unsigned int fb=0; fb<fmp->getNumFluxBounds(); fb++) {
      const FluxBound* fluxbound = fmp->getFluxBound(fb);
      bool haveAlready = false;
      for (size_t ac=0; ac<constraints.size(); ac++) {
        if (constraints[ac].ContainsFlux(fluxbound)) {
          haveAlready = true;
        }
      }
      if (!haveAlready) {
        sbmlname = getNameFromSBMLObject(fluxbound, "_con");
        Variable* var = AddOrFindVariable(&sbmlname);
        var->ReadAnnotationFrom(fluxbound);
        if (fluxbound->isSetName()) {
          var->SetDisplayName(fluxbound->getName());
        }
        AntimonyConstraint acon(var);
        acon.SetFromFluxBound(fluxbound);
        var->SetConstraint(&acon);
      }
    }
    const Objective* objective = fmp->getActiveObjective();
    if (objective != NULL) {
      sbmlname = getNameFromSBMLObject(objective, "_objective");
      Variable* varobj = AddOrFindVariable(&sbmlname);
      varobj->ReadAnnotationFrom(objective);
      if (objective->isSetName()) {
        varobj->SetDisplayName(objective->getName());
      }
      m_maximize = (objective->getObjectiveType() == OBJECTIVE_TYPE_MAXIMIZE);
      m_objective = varobj->GetName();
      Formula form;
      for (unsigned int fo=0; fo<objective->getNumFluxObjectives(); fo++) {
        if (fo > 0) {
          form.AddMathThing('+');
        }
        const FluxObjective* fluxobj = objective->getFluxObjective(fo);
        double stoich = fluxobj->getCoefficient();
        if (stoich != 1) {
          form.AddNum(stoich);
          form.AddMathThing('*');
        }
        vector<string> rxnname;
        rxnname.push_back(fluxobj->getReaction());
        Variable* rxn = GetVariable(rxnname);
        if (rxn==NULL || !IsReaction(rxn->GetType())) {
          assert(false); //should be possible?
          continue;
        }
        form.AddVariable(rxn);
      }
      varobj->SetFormula(&form, true);
    }
  }
#endif

#ifdef USE_COMP
  if(mplugin != NULL) {
    //Ports!
    for (unsigned int p=0; p<mplugin->getNumPorts(); p++) {
      const Port* port = mplugin->getPort(p);
      if (port->isSetSBaseRef()) {
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because the object the port referenced is in a submodel, and these objects cannot be declared ports in Antimony.");
        continue;
      }
      SBase* ref = const_cast<Port*>(port)->getReferencedElement();
      if (ref==NULL) {
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because the object the port referenced could not be found.");
        continue;
      }
      switch(ref->getTypeCode()) {
      case SBML_CONSTRAINT:
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because Constraint elements do not have IDs in SBML, and therefore cannot be made into ports in Antimony.");
        continue;
      case SBML_ALGEBRAIC_RULE:
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because " + SBMLTypeCode_toString(ref->getTypeCode(), "core") + " elements do not exist in Antimony, and are therefore untranslateable.");
        continue;
      case SBML_INITIAL_ASSIGNMENT:
      case SBML_RATE_RULE:
      case SBML_ASSIGNMENT_RULE:
      case SBML_PRIORITY:
      case SBML_DELAY:
      case SBML_EVENT_ASSIGNMENT:
      case SBML_TRIGGER:
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because " + SBMLTypeCode_toString(ref->getTypeCode(), "core") + " elements only exist as part of other Antimony elements, and do not function as their own separate entities which may be flagged as a port.");
        continue;
      case SBML_FUNCTION_DEFINITION:
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because function defintions are global in Antimony, not local.");
        continue;
      default:
        break;
      }
      if (!ref->isSetId()) {
        g_registry.AddWarning("Unable to create port " + port->getId() + " in model " + GetModuleName() + " because the referenced element has no ID.");
      }
      string refid = ref->getId();
      if (ref->getTypeCode()==SBML_LOCAL_PARAMETER) {
        refid = GetNewIDForLocalParameter(ref);
      }
      Variable* portvar = AddOrFindVariable(&refid);
      AddVariableToExportList(portvar);
    }
    /*
    //Time and extent for reaction references only:
    for (unsigned int sm=0; sm<mplugin->getNumSubmodels(); sm++) {
      const Submodel* submodel = mplugin->getSubmodel(sm);
      string submodname = getNameFromSBMLObject(submodel, "submod");
      Variable* var = AddOrFindVariable(&submodname);
      Module* submod = var->GetModule();
      if (submodel->isSetTimeConversionFactor()) {
        string tcf = submodel->getTimeConversionFactor();
        Variable* tcfvar = AddOrFindVariable(&tcf);
        submod->SetTimeConversionFactorForRxnRefs(tcfvar);
      }
      if (submodel->isSetExtentConversionFactor()) {
        string xcf = submodel->getExtentConversionFactor();
        Variable* xcfvar = AddOrFindVariable(&xcf);
        submod->SetExtentConversionFactorForRxnRefs(xcfvar);
      }
    }
    */
  }
#endif //USE_COMP

  //Finally, fix the fact that 'time' used to be OK in functions (l2v1), but is no longer (l2v2).
  g_registry.FixTimeInFunctions();
}

const SBMLDocument* Module::GetSBML(bool comp)
{
  const Model* mod = m_sbml.getModel();
  if (mod != NULL && mod->getId() == m_modulename && m_sbml.getPackageRequired("comp") == comp) {
    return &m_sbml;
  }
  CreateSBMLModel(comp);
  return &m_sbml;
}

Model* Module::GetModelIfCreated()
{
    return m_sbml.getModel();
}

void Module::CreateSBMLModel(bool comp)
{
#ifndef USE_COMP
  if (comp) {
    comp = false;
    g_registry.AddWarning("Unable to create hierarchical version of SBML model:  libAntimony was not compiled with the USE_COMP flag set.  libSBML may need to be recompiled with USE_COMP as well.  Exporting flattened version of SBML file instead.");
  }
#endif
  if (comp) {
    SBMLDocument newdoc(&m_sbmlnamespaces);
    m_sbml = newdoc;
#ifdef USE_COMP
    m_sbml.setPackageRequired("comp", true);
#endif
  }
  else {
    SBMLNamespaces plainnamespaces(m_sbmlnamespaces);
    plainnamespaces.removePackageNamespace(3, 1, "comp", 1);
    SBMLDocument newdoc(&plainnamespaces);
    m_sbml = newdoc;
  }

  size_t numsubmods = GetNumVariablesOfType(subModules, true);
#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
  for (size_t sm = 0; sm < numsubmods; sm++) {
    Variable* submod = GetNthVariableOfType(subModules, sm, true);
    Module* module = submod->GetModule();
    if (module->m_usedDistributions) {
      m_usedDistributions = true;
    }
  }
  if (m_usedDistributions) {
    DistribExtension de;
    string uri = de.getURI(m_sbml.getLevel(), m_sbml.getVersion(), 1);
    m_sbml.enablePackage(uri, "distrib", true);
    m_sbml.setPackageRequired("distrib", true);
  }
#endif
#ifdef LIBSBML_HAS_PACKAGE_FBC
  if (m_hasFBC) {
    m_sbml.setPackageRequired("fbc", false);
  }
#endif
  Model* sbmlmod = m_sbml.createModel();

  sbmlmod->setId(m_modulename);
  sbmlmod->setName(GetDisplayName());
  sbmlmod->setMetaId(GetModuleName());
  TransferAnnotationTo(sbmlmod, GetModuleName());

  string cc = g_registry.GetCC();
  map<const Variable*, Variable > syncmap;
  if (comp) {
    FillInSyncmap(syncmap); //Only need this if we're hierarchical
  }

  set<pair<string, const Variable*> > referencedVars;
#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  CompModelPlugin* mplugin = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));

  //Set of referenced variables, so that we can create replacedBy's to them if they are actually submodel variables.
  //Submodels!
  if (comp) {
    AddSubmodelsToDocument(&m_sbml);
    for (size_t sm=0; sm<numsubmods; sm++) {
      Variable* submod = GetNthVariableOfType(subModules, sm, true);
      Module* module = submod->GetModule();
      Submodel* sbmlsubmod = mplugin->createSubmodel();
      sbmlsubmod->setId(submod->GetNameDelimitedBy(cc));
      sbmlsubmod->setName(submod->GetDisplayName());
      sbmlsubmod->setModelRef(module->GetModuleName());
      if (submod->GetSBOTerm() != 0) {
        sbmlsubmod->setSBOTerm(submod->GetSBOTerm());
      }
      submod->TransferAnnotationTo(sbmlsubmod, GetModuleName()+"."+submod->GetNameDelimitedBy(cc));
      Variable* conv = submod->GetTimeConversionFactor();
      if (conv != NULL) {
        sbmlsubmod->setTimeConversionFactor(conv->GetNameDelimitedBy(cc));
      }
      conv = submod->GetExtentConversionFactor();
      if (conv != NULL) {
        sbmlsubmod->setExtentConversionFactor(conv->GetNameDelimitedBy(cc));
      }
      //Delete the submodel's default compartment, if it is no longer needed
      if (!GetNeedDefaultCompartment() && g_registry.GetModule(module->GetModuleName())->GetNeedDefaultCompartment()) {
        Deletion* deletion = sbmlsubmod->createDeletion();
        deletion->setIdRef(DEFAULTCOMP);
      }

      //Delete the things explicitly deleted.
      set<pair<vector<string>, deletion_type> > deletedvars = submod->GetDeletions();
      for (set<pair<vector<string>, deletion_type> >::iterator d = deletedvars.begin(); d!= deletedvars.end(); d++) {
        vector<string> fullname= (*d).first;
        vector<string> delname = fullname;
        deletion_type type = (*d).second;
        //These four deletion types have an extra name on the end:
        switch(type) {
        case delEventAssignment:
        case delReactant:
        case delProduct:
        case delModifier:
          delname.pop_back();
          break;
        case delInteraction:
          //Interactions have no direct SBML equivalent; just ignore it.
          continue;
        default:
          break;
        }
        Deletion* deletion = sbmlsubmod->createDeletion();
        assert(delname.size() > 1);
        deletion->setIdRef(delname[1]);
        SBaseRef* sbr = deletion;
        for (size_t n=2; n<delname.size(); n++) {
          SBaseRef* subsbr = sbr->createSBaseRef();
          subsbr->setIdRef(delname[n]);
          sbr = subsbr;
        }
        Variable* deletedvar = GetVariable(delname);
        if (deletedvar->IsDeletedUnit()) {
          sbr->unsetIdRef();
          sbr->setUnitRef(delname[delname.size()-1]);
        }
        //deletedvar->TransferAnnotationTo(deletion);
        //Find the actual bit we're deleting:
        SBase* referenced = deletion->getReferencedElement();
        assert(referenced != NULL);
        SBase* parentModelsb = referenced->getAncestorOfType(SBML_COMP_MODELDEFINITION, "comp");
        if (parentModelsb==NULL) {
          assert(false); //They should all be in model definitions, as far as I can work out.
          parentModelsb = referenced->getAncestorOfType(SBML_MODEL);
        }
        assert(parentModelsb != NULL);
        string parentId = parentModelsb->getId();
        parentModelsb = compdoc->getModel(parentId);
        assert(parentModelsb != NULL);
        Model* parentModel = static_cast<Model*>(parentModelsb);
        SBase* target = parentModel->getElementBySId(delname[delname.size()-1]);
        if (target == NULL) {
          target = parentModel->getUnitDefinition(delname[delname.size()-1]);
        }
        assert(target != NULL);
        Event* event = static_cast<Event*>(target);
        Priority* priority = NULL;
        Delay* delay = NULL;
        EventAssignment* eventAssignment = NULL;
        Reaction* rxn = static_cast<Reaction*>(target);
        SimpleSpeciesReference* ssr = NULL;
        KineticLaw* kl = NULL;
        RateRule* rr = NULL;
        InitialAssignment* ia = NULL;
        AssignmentRule* ar = NULL;
        string metaid = "";
        switch(type) {
        case delFull:
          //Don't need to do anything else.
          SetSBaseReference(sbr, target, parentModel, "meta");
          break;
        case delEventPriority:
          priority = event->getPriority();
          assert(priority != NULL);
          metaid = parentId + "__" + event->getId() + "__priority";
          SetSBaseReference(sbr, priority, parentModel, metaid);
          break;
        case delEventDelay:
          delay = event->getDelay();
          assert(delay != NULL);
          metaid = parentId + "__" + event->getId() + "__delay";
          SetSBaseReference(sbr, delay, parentModel, metaid);
          break;
        case delEventAssignment:
          eventAssignment = event->getEventAssignment(fullname[fullname.size()-1].c_str());
          assert(eventAssignment != NULL);
          metaid = parentId + "__" + event->getId() + "__eventAssignment__" + eventAssignment->getVariable();
          SetSBaseReference(sbr, eventAssignment, parentModel, metaid);
          break;
        case delReactant:
          ssr = rxn->getReactant(fullname[fullname.size()-1].c_str());
          assert(ssr != NULL);
          metaid = rxn->getId() + "__reactant__" + ssr->getSpecies();
          SetSBaseReference(sbr, ssr, parentModel, metaid);
          break;
        case delProduct:
          ssr = rxn->getProduct(fullname[fullname.size()-1].c_str());
          assert(ssr != NULL);
          metaid = rxn->getId() + "__product__" + ssr->getSpecies();
          SetSBaseReference(sbr, ssr, parentModel, metaid);
          break;
        case delModifier:
          ssr = rxn->getModifier(fullname[fullname.size()-1].c_str());
          assert(ssr != NULL);
          metaid = parentId + "__" + rxn->getId() + "__modifier__" + ssr->getSpecies();
          SetSBaseReference(sbr, ssr, parentModel, metaid);
          break;
        case delKineticLaw:
          kl = rxn->getKineticLaw();
          if(kl == NULL) {
            deletion->removeFromParentAndDelete();
            continue;
          }
          metaid = parentId + "__" + rxn->getId() + "__kineticLaw";
          SetSBaseReference(sbr, kl, parentModel, metaid);
          break;
        case delRateRule:
          rr = parentModel->getRateRule(delname[delname.size()-1]);
          if(rr == NULL) {
            deletion->removeFromParentAndDelete();
            continue;
          }
          metaid = parentId + "__" + rr->getVariable() + "__rateRule";
          SetSBaseReference(sbr, rr, parentModel, metaid);
          break;
        case delInitialAssignment:
          ia = parentModel->getInitialAssignment(delname[delname.size()-1]);
          if(ia == NULL) {
            deletion->removeFromParentAndDelete();
            continue;
          }
          metaid = parentId + "__" + ia->getSymbol() + "__initialAssignment";
          SetSBaseReference(sbr, ia, parentModel, metaid);
          break;
        case delAssignmentRule:
          ar = parentModel->getAssignmentRule(delname[delname.size()-1]);
          if(ar == NULL) {
            deletion->removeFromParentAndDelete();
            continue;
          }
          metaid = parentId + "__" + ar->getVariable() + "__assignmentRule";
          SetSBaseReference(sbr, ar, parentModel, metaid);
          break;
        case delInteraction:
          //Don't need to do anything.  I think.
          break;
        }
      }
    }
    ReturnSubmodelsFromDocument(&m_sbml);
  }
#endif //USE_COMP

  //User-defined functions
  for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
    const UserFunction* userfunction = g_registry.GetNthUserFunction(uf);
    assert(userfunction != NULL);
    FunctionDefinition* fd = sbmlmod->createFunctionDefinition();
    fd->setId(userfunction->GetModuleName());
    fd->setName(userfunction->GetDisplayName());
    userfunction->TransferAnnotationTo(fd, GetModuleName()+"."+userfunction->GetModuleName());
    ASTNode* math = parseStringToASTNode(userfunction->ToSBMLString());
    fd->setMath(math);
    delete math;
  }

  //The 'rateOf' function:
  //for (set<string>::iterator rname=m_rateNames.begin(); rname != m_rateNames.end(); rname++) {
  //  FunctionDefinition* fd = sbmlmod->createFunctionDefinition();
  //  fd->setId(*rname);
  //  ASTNode* math = parseStringToASTNode("lambda(x, NaN)");
  //  fd->setMath(math);
  //  fd->setAnnotation("<annotation> <symbols xmlns=\"http://sbml.org/annotations/symbols\" definition=\"http://en.wikipedia.org/wiki/Derivative\"/> </annotation>");
  //  delete math;
  //}


  //Species
  size_t numspecies = GetNumVariablesOfType(allSpecies, comp);
  for (size_t spec=0; spec < numspecies; spec++) {
    Variable* species = GetNthVariableOfType(allSpecies, spec, comp);
    Species* sbmlspecies = sbmlmod->createSpecies();
    sbmlspecies->setId(species->GetNameDelimitedBy(cc));
    if (species->GetDisplayName() != "") {
      sbmlspecies->setName(species->GetDisplayName());
    }

    // JKM set the meta id to module_name.species_id; this should be globally unique
    species->TransferAnnotationTo(sbmlspecies, GetModuleName()+"."+species->GetNameDelimitedBy(cc));

    sbmlspecies->setConstant(false); //There's no need to try to distinguish between const and var for species.
    if (species->GetIsConst()) {
      sbmlspecies->setBoundaryCondition(true);
    }
    else {
      sbmlspecies->setBoundaryCondition(false);
    }
    sbmlspecies->setHasOnlySubstanceUnits(species->GetSubstOnly());
    const Variable* compartment = species->GetCompartment();
    if (compartment == NULL) {
      sbmlspecies->setCompartment(DEFAULTCOMP);
    }
    else {
      string cname = compartment->GetNameDelimitedBy(cc);
#ifdef USE_COMP
      if (comp) {
        //If the compartment is from a submodel, we might need to create a local compartment for it.
        referencedVars.insert(make_pair(cname, compartment));
      }
#endif
      sbmlspecies->setCompartment(cname);
    }
    Variable* unitvar = species->GetUnitVariable();
    Formula* formula = species->GetFormula();
    if (formula->IsDouble()) {
      sbmlspecies->setInitialConcentration(formula->GetDouble());
    }
    else if (formula->IsAmountIn(compartment)) {
      sbmlspecies->setInitialAmount(formula->ToAmount());
    }
    if (unitvar != NULL) {
      //We need to convert concentration to substance.
      UnitDef ud(*unitvar->GetUnitDef());
      UnitDef volume("liter", m_modulename);
      if (compartment != NULL) {
        Variable* compunit = compartment->GetUnitVariable();
        if (compunit == NULL) {
          vector<string> volname;
          volname.push_back("volume");
          compunit = GetVariable(volname);
          if (compunit == NULL) {
            compunit = GetDefaultVariable(volname);
          }
          assert(compunit != NULL); //'volume' should always exist at least as a default unit.
        }
        ud.MultiplyUnitDef(compunit->GetUnitDef());
      }
      else {
        ud.MultiplyUnitDef(&volume);
      }
      ud.Reduce();
      Variable* newunit = AddOrFindUnitDef(ud);
      sbmlspecies->setSubstanceUnits(newunit->GetNameDelimitedBy(cc));
    }
    SetAssignmentFor(sbmlmod, species, syncmap, comp, referencedVars);
  }

  //Units
  size_t numunits = GetNumVariablesOfType(allUnits, comp);
  for (size_t ud=0; ud<numunits; ud++) {
    Variable* unit = GetNthVariableOfType(allUnits, ud, comp);
    UnitDef* unitdef = unit->GetUnitDef();
    if (!unit->IsBuiltin()) {
      UnitDefinition* sbmlunitdef = unitdef->AddToSBML(sbmlmod, unit->GetNameDelimitedBy(cc), unit->GetDisplayName());
      if (sbmlunitdef != NULL) {
        unit->TransferAnnotationTo(sbmlunitdef, GetModuleName()+"."+unit->GetNameDelimitedBy(cc));
      }
      vector<string> name = unit->GetName();
      assert(!name.empty());
      string unitname = unit->GetNameDelimitedBy(cc);
      if (unit->IsBuiltin())
        unitname = unit->GetName().back();
      string finalname = name[name.size()-1];
      if (finalname=="substance") {
        sbmlmod->setSubstanceUnits(unitname);
      }
      if (finalname=="volume") {
        sbmlmod->setVolumeUnits(unitname);
      }
      if (finalname=="area") {
        sbmlmod->setAreaUnits(unitname);
      }
      if (finalname=="length") {
        sbmlmod->setLengthUnits(unitname);
      }
      if (finalname=="time_unit") {
        sbmlmod->setTimeUnits(unitname);
      }
      if (finalname=="extent") {
        sbmlmod->setExtentUnits(unitname);
      }
    }
  }

  //Compartments
  bool need_default = GetNeedDefaultCompartment();
  unsigned int dim=3;
  if (need_default) {
    Compartment* defaultCompartment = sbmlmod->createCompartment();
    defaultCompartment->setId(DEFAULTCOMP);
    defaultCompartment->setConstant(true);
    defaultCompartment->setSize(1);
    defaultCompartment->setSBOTerm(410); //The 'implicit compartment'
    defaultCompartment->setSpatialDimensions(dim);
#ifdef USE_COMP
    if (comp) {
      CompSBasePlugin* plugcompartment = static_cast<CompSBasePlugin*>(defaultCompartment->getPlugin("comp"));
      for (size_t sm=0; sm<numsubmods; sm++) {
        Variable* submod = GetNthVariableOfType(subModules, sm, true);
        string modname = submod->GetModule()->GetModuleName();
        Module* origmod = g_registry.GetModule(modname);
        if (origmod->GetNeedDefaultCompartment()) {
          ReplacedElement* re = plugcompartment->createReplacedElement();
          re->setSubmodelRef(submod->GetNameDelimitedBy(cc));
          re->setIdRef(DEFAULTCOMP);
        }
      }
    }
#endif //USE_COMP
  }
  size_t numcomps = GetNumVariablesOfType(allCompartments, comp);
  for (size_t cmpt=0; cmpt<numcomps; cmpt++) {
    const Variable* compartment = GetNthVariableOfType(allCompartments, cmpt, comp);
    Compartment* sbmlcomp = sbmlmod->createCompartment();
    sbmlcomp->setId(compartment->GetNameDelimitedBy(cc));
    compartment->TransferAnnotationTo(sbmlcomp, GetModuleName()+"."+compartment->GetNameDelimitedBy(cc));
    if (compartment->GetDisplayName() != "") {
      sbmlcomp->setName(compartment->GetDisplayName());
    }
    sbmlcomp->setConstant(compartment->GetIsConst());
    formula_type ftype = compartment->GetFormulaType();
    assert (ftype == formulaINITIAL || ftype==formulaASSIGNMENT || ftype==formulaRATE);
    if (ftype != formulaINITIAL) {
      sbmlcomp->setConstant(false);
    }
    const Formula* formula = compartment->GetFormula();
    if (formula->IsDouble()) {
      sbmlcomp->setSize(formula->GetDouble());
    }
    Variable* unitvar = compartment->GetUnitVariable();
    if (unitvar != NULL) {
      sbmlcomp->setUnits(unitvar->GetNameOrBuiltin(cc));
    }
    SetAssignmentFor(sbmlmod, compartment, syncmap, comp, referencedVars);
    sbmlcomp->setSpatialDimensions(dim);
  }

  //Formulas
  size_t numforms = GetNumVariablesOfType(allFormulas, comp);
  for (size_t form=0; form < numforms; form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form, comp);
    const Formula*  formula = formvar->GetFormula();
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    formvar->TransferAnnotationTo(param, GetModuleName()+"."+formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    param->setConstant(formvar->GetIsConst());
    if (formula->IsDouble()) {
      param->setValue(formula->GetDouble());
    }
    Variable* unitvar = formvar->GetUnitVariable();
    if (unitvar != NULL) {
      param->setUnits(unitvar->GetNameOrBuiltin(cc));
    }
    SetAssignmentFor(sbmlmod, formvar, syncmap, comp, referencedVars);
    formula_type ftype = formvar->GetFormulaType();
    assert (ftype == formulaINITIAL || ftype==formulaASSIGNMENT || ftype==formulaRATE);
    if (ftype != formulaINITIAL) {
      param->setConstant(false);
    }
  }

  //Reactions
  size_t numrxns = GetNumVariablesOfType(allReactions, comp);
  for (size_t rxn=0; rxn < numrxns; rxn++) {
    const Variable* rxnvar = GetNthVariableOfType(allReactions, rxn, comp);
    const AntimonyReaction* reaction = rxnvar->GetReaction();
    Reaction* sbmlrxn = sbmlmod->createReaction();
    sbmlrxn->setFast(false);
    sbmlrxn->setId(rxnvar->GetNameDelimitedBy(cc));
    rxnvar->TransferAnnotationTo(sbmlrxn, GetModuleName()+"."+rxnvar->GetNameDelimitedBy(cc));
    if (rxnvar->GetDisplayName() != "") {
      sbmlrxn->setName(rxnvar->GetDisplayName());
    }
    if (reaction->GetType() == rdBecomes) {
      sbmlrxn->setReversible(true);
    }
    else {
      assert(reaction->GetType() == rdBecomesIrreversibly);
      sbmlrxn->setReversible(false);
    }
    const Variable* rxncompartment = rxnvar->GetCompartment();
    if (rxncompartment != NULL) {
      sbmlrxn->setCompartment(rxncompartment->GetNameDelimitedBy(cc));
#ifdef USE_COMP
      if (comp) {
        //If the compartment is from a submodel, we might need to create a local compartment for it.
        referencedVars.insert(make_pair(rxncompartment->GetNameDelimitedBy(cc), rxncompartment));
      }
#endif
    }
    const Formula* formula = reaction->GetFormula();
    string formstring = formula->ToSBMLString(rxnvar->GetStrandVars());
    if (!formula->IsEmpty()) {
      KineticLaw* kl = sbmlmod->createKineticLaw();
      ASTNode* math = parseStringToASTNode(formstring);
      kl->setMath(math);
      delete math;
#ifdef USE_COMP
      if (comp) {
        formula->AddReferencedVariablesTo(referencedVars);
      }
#endif
    }
    for (int lr = 0; lr < 2; lr++) {
        const ReactantList* rl = reaction->GetLeft();
        if (lr == 1) {
            rl = reaction->GetRight();
        }
        for (size_t lnum = 0; lnum < rl->Size(); lnum++) {
            const Variable* nthr = rl->GetNthReactant(lnum);
            referencedVars.insert(make_pair(nthr->GetNameDelimitedBy(cc), nthr));
            SpeciesReference* sr = NULL;
            if (lr == 1) {
                sr = sbmlmod->createProduct();
            }
            else {
                sr = sbmlmod->createReactant();
            }
            sr->setSpecies(nthr->GetNameDelimitedBy(cc));
            double nthstoich = rl->GetStoichiometryFor(lnum);
            const Variable* namedstoich = rl->GetNthStoichiometryVar(lnum);
            if (namedstoich == NULL) {
                sr->setConstant(true);
                sr->setStoichiometry(nthstoich);
            }
            else {
                sr->setIdAttribute(namedstoich->GetNameDelimitedBy(cc));
                if (namedstoich->GetFormulaType() != formulaINITIAL) {
                    sr->setConstant(false);
                }
                else {
                    sr->setConstant(namedstoich->GetIsConst());
                }
                if (namedstoich->GetFormula()->IsDouble()) {
                    sr->setStoichiometry(nthstoich);
                }
                SetAssignmentFor(sbmlmod, namedstoich, syncmap, comp, referencedVars);
            }
        }
    }
    //Find 'modifiers' and add them.
    vector<const Variable*> subvars = formula->GetVariablesFrom(formstring, m_modulename);
    for (size_t v=0; v<subvars.size(); v++) {
      if (subvars[v] != NULL && subvars[v]->GetType() == varSpeciesUndef) {
        if (!reaction->HasReactantFor(subvars[v])) {
          ModifierSpeciesReference* msr = sbmlmod->createModifier();
          msr->setSpecies(subvars[v]->GetNameDelimitedBy(cc));
        }
      }
    }
  }

  //Events
  size_t numevents = GetNumVariablesOfType(allEvents, comp);
  for (size_t ev=0; ev < numevents; ev++) {
    const Variable* eventvar = GetNthVariableOfType(allEvents, ev, comp);
    const AntimonyEvent* event = eventvar->GetEvent();
    Event* sbmlevent = sbmlmod->createEvent();
    sbmlevent->setId(eventvar->GetNameDelimitedBy(cc));
    if (eventvar->GetDisplayName() != "") {
      sbmlevent->setName(eventvar->GetDisplayName());
    }
    eventvar->TransferAnnotationTo(sbmlevent, GetModuleName()+"."+eventvar->GetNameDelimitedBy(cc));
    Trigger* trig = sbmlevent->createTrigger();
    ASTNode* ASTtrig = parseStringToASTNode(event->GetTrigger()->ToSBMLString());
    if (ASTtrig==NULL) {
      ASTtrig = parseStringToASTNode("true");
    }
    trig->setMath(ASTtrig);

    delete ASTtrig;
    const Formula* delay = event->GetDelay();
    if (!delay->IsEmpty()) {
      ASTtrig = parseStringToASTNode(delay->ToSBMLString());
      Delay* sbmldelay = sbmlevent->createDelay();
      if (sbmldelay != NULL) {
        sbmldelay->setMath(ASTtrig);
      }
      delete ASTtrig;
    }
    const Formula* priority = event->GetPriority();
    if (!priority->IsEmpty()) {
      ASTtrig = parseStringToASTNode(priority->ToSBMLString());
      Priority* sbmlpriority = sbmlevent->createPriority();
      if (sbmlpriority != NULL) {
        sbmlpriority->setMath(ASTtrig);
      }
      delete ASTtrig;
    }
    sbmlevent->setUseValuesFromTriggerTime(event->GetUseValuesFromTriggerTime());
    sbmlevent->getTrigger()->setInitialValue(event->GetInitialValue());
    sbmlevent->getTrigger()->setPersistent(event->GetPersistent());
      
    long numasnts = static_cast<long>(event->GetNumAssignments());
    for (long asnt=numasnts-1; asnt>=0; asnt--) {
      //events are stored in reverse order.  Don't ask...
      EventAssignment* sbmlasnt = sbmlmod->createEventAssignment();
      sbmlasnt->setVariable(event->GetNthAssignmentVariableName(asnt, cc));
      ASTNode* ASTasnt = parseStringToASTNode(event->GetNthAssignmentFormulaString(asnt, cc, true));
      sbmlasnt->setMath(ASTasnt);
      delete ASTasnt;
    }
  }

  //Interactions
  //Because interactions aren't their own thing in SBML, we want all of the interactions from the entire model, in case one of them interacts with a reaction at this level.  Hence, instead of using the 'comp' boolean, we use 'false', to get everything.
  size_t numinteractions = GetNumVariablesOfType(allInteractions, false);
  for (size_t irxn=0; irxn<numinteractions; irxn++) {
    const Variable* arxnvar = GetNthVariableOfType(allInteractions, irxn, false);
    const AntimonyReaction* arxn = arxnvar->GetReaction();
    Reaction* rxn = sbmlmod->getReaction(arxn->GetRight()->GetNthReactant(0)->GetNameDelimitedBy(cc));
    if (rxn != NULL) {
      for (size_t interactor=0; interactor<arxn->GetLeft()->Size(); interactor++) {
        ModifierSpeciesReference* msr = rxn->createModifier();
        msr->setSpecies(arxn->GetLeft()->GetNthReactant(interactor)->GetNameDelimitedBy(cc));
        msr->setName(arxnvar->GetName()[arxnvar->GetName().size()-1]);
        switch(arxn->GetType()) {
        case rdBecomes:
        case rdBecomesIrreversibly:
          assert(false); //should be interaction, not reaction
          break;
        case rdActivates:
          msr->setSBOTerm(459);
          break;
        case rdInhibits:
          msr->setSBOTerm(20);
          break;
        case rdInfluences:
          msr->setSBOTerm(19);
          break;
        }
        const Variable* intvar = arxn->GetLeft()->GetNthReactant(interactor);
        referencedVars.insert(make_pair(intvar->GetNameDelimitedBy(cc), intvar));
      }
    }
  }

  //Constraints (could be FBC constraints)
  size_t numconstraints = GetNumVariablesOfType(allConstraints, comp);
  for (size_t con=0; con < numconstraints; con++) {
    const Variable* convar = GetNthVariableOfType(allConstraints, con, comp);
    const AntimonyConstraint* antconstraint = convar->GetConstraint();
    const Formula*  formula = convar->GetFormula();
    Constraint* constraint = sbmlmod->createConstraint();

    if (convar->GetDisplayName() != "") {
#if LIBSBML_VERSION >= 51103
      constraint->setMessage(convar->GetDisplayName(), true); // <- have to update libsbml for this to work.
#endif
    }
    convar->TransferAnnotationTo(constraint, GetModuleName() + "." + convar->GetNameDelimitedBy(cc));
    constraint->setMath(antconstraint->getASTNode());
#ifdef LIBSBML_HAS_PACKAGE_FBC
    //We need to check to see if the constraint can be translated to an FBC constraint.
    antconstraint->addFluxBounds(sbmlmod);
#endif
  }

  //Unknown variables (turn into parameters)
  size_t numunknown = GetNumVariablesOfType(allUnknown, comp);
  for (size_t form=0; form < numunknown; form++) {
    const Variable* formvar = GetNthVariableOfType(allUnknown, form, comp);
    vector<string> fvname = formvar->GetName();
    //if (fvname[fvname.size()-1] == "rateOf" ||
    //    fvname[fvname.size()-1] == "rate" ||
    //    StringToDistributionType(fvname[fvname.size()-1]) != distUNKNOWN) 
    //if (StringToDistributionType(fvname[fvname.size() - 1]) != distUNKNOWN)
    //{
    //  continue;
    //}
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    formvar->TransferAnnotationTo(param, GetModuleName()+"."+formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    param->setConstant(formvar->GetIsConst());
    Variable* unitvar = formvar->GetUnitVariable();
    if (unitvar != NULL) {
      param->setUnits(unitvar->GetNameOrBuiltin(cc));
    }
  }

  //The objective function (if present)
  if (m_objective.size() > 0) {
    Variable* objective = GetVariable(m_objective)->GetSameVariable();
    string objname = objective->GetNameDelimitedBy(cc);
    //First remove the 'objective' parameter:
    SBase* obj = sbmlmod->getElementBySId(objname);
    if (obj) {
      obj->removeFromParentAndDelete();
    }
    else {
      obj = NULL; //What?
    }
    obj = sbmlmod->getInitialAssignmentBySymbol(objname);
    if (obj) {
      obj->removeFromParentAndDelete();
    }
    obj = sbmlmod->getAssignmentRuleByVariable(objname);
    if (obj) {
      obj->removeFromParentAndDelete();
    }
    objective->GetFormula()->AddFluxObjective(sbmlmod, m_maximize, objective);
  }


#ifdef USE_COMP
  //Ports
  if (comp) {
    set<string> portnames;
    pair<set<string>::iterator, bool> setret;
    for (size_t ex=0; ex<m_exportlist.size(); ex++) {
      Port* port = mplugin->createPort();
      //assert(m_exportlist[ex].size()==1);
      const Variable* exported = GetVariable(m_exportlist[ex]);
      string portname = m_exportlist[ex][m_exportlist[ex].size()-1];
      if (exported != NULL && exported->GetType()==varUnitDefinition) {
        port->setUnitRef(m_exportlist[ex][0]);
        portname = "unit_" + portname;
      }
      else {
        port->setIdRef(m_exportlist[ex][0]);
      }
      size_t digit = 0;
      setret = portnames.insert(portname);
      while (setret.second == false) {
        portname = m_exportlist[ex][m_exportlist[ex].size()-1] + "_" + SizeTToString(digit);
        setret = portnames.insert(portname);
      }
      port->setId(portname);
    }
    //Synchronized variables
    for (size_t sync=0; sync<m_synchronized.size(); sync++) {
      vector<string> name1 = m_synchronized[sync].first;
      vector<string> name2 = m_synchronized[sync].second;
      const Variable* conversionFactor = GetVariable(m_conversionFactors[sync]);
      if (name1.size() == 1 && name2.size() != 1) {
        //Switch the order if the first is a local variable and the second is not.
        name1 = name2;
        name2 = m_synchronized[sync].first;
        //Also, the conversion factor is no longer valid (and also already applied to the local model)
        conversionFactor = NULL;
      }
      if (name1.size() == 1 && name2.size() == 1) {
        //Don't worry about it--we already removed it in the GetNthWhatever functions.
      }
      else if (name2.size()==1) {
        SBase* sbmlvar1 = sbmlmod->getElementBySId(name2[0]);
        bool isunit = false;
        if (sbmlvar1 == NULL) {
          sbmlvar1 = sbmlmod->getUnitDefinition(name2[0]);
          isunit = true;
        }
        assert(sbmlvar1 != NULL);
        CompSBasePlugin* svarplug1 = static_cast<CompSBasePlugin*>(sbmlvar1->getPlugin("comp"));
        ReplacedElement* re = svarplug1->createReplacedElement();
        re->setSubmodelRef(name1[0]);
        if (conversionFactor != NULL) {
          re->setConversionFactor(conversionFactor->GetNameDelimitedBy(cc));
        }
        size_t svn=1;
        SBaseRef* sbr = re;
        while (svn+1 < name1.size()) {
          sbr->setIdRef(name1[svn]);
          sbr = sbr->createSBaseRef();
          svn++;
        }
        if (isunit) {
          sbr->setUnitRef(name1[svn]);
        }
        else {
          sbr->setIdRef(name1[svn]);
        }
        //Need to create a metaid on the parent if the child has one:
        SBase* referenced = re->getReferencedElement();
        if (referenced && referenced->isSetMetaId()) {
          sbmlvar1->setMetaId(GetModuleName() + "." + name2[0]);
        }
      }
      else {
        //assert(false);
        //We do need to create a local variable, but there's no point in asserting; that will only confuse people.  This is the situation where you synchronize elements that are only in submodels:  A.S is B.S
        //LS DEBUG
      }
    }
    for (set<pair<string, const Variable*> >::iterator ref = referencedVars.begin(); ref != referencedVars.end(); ref++) {
      FindOrCreateLocalVersionOf((*ref).second, sbmlmod);
    }
    FixPortReferencesIn(sbmlmod);
  }
#endif //USE_COMP
}

void Module::SetAssignmentFor(Model* sbmlmod, const Variable* var, const map<const Variable*, Variable>& syncmap, bool comp, set<pair<string, const Variable*> > referencedVars)
{
  bool useinitial = true;
  bool useassignment = true;
  bool userate = true;
#ifdef USE_COMP
  if (comp) {
    //The comp version is a lot more complicated than the flat version, because we need to:
    // * Delete all rules/assignments that no longer apply to this variable
    // * Leave any rule/assignment that still applies
    // * Create a new rule/assignment if none of the old ones apply.
    vector<const Variable*> synchronized = GetSynchronizedVariablesFor(var);
    useassignment = SynchronizeAssignments(sbmlmod, var, synchronized, syncmap);
    userate = SynchronizeRates(sbmlmod, var, synchronized, syncmap);
  }
#endif
  string cc = g_registry.GetCC();
  formula_type ftype = var->GetFormulaType();
  const Formula* formula = var->GetFormula();
  if (!formula->IsEmpty()) {
    ASTNode* math = parseStringToASTNode(formula->ToSBMLString());
    if (ftype == formulaASSIGNMENT) {
      if (useassignment) {
        AssignmentRule* ar = sbmlmod->createAssignmentRule();
        ar->setVariable(var->GetNameDelimitedBy(cc));
        ar->setMath(math);
      }
    }
    else if (!formula->IsDouble() &&
      !(IsSpecies(var->GetType()) && formula->IsAmountIn(var->GetCompartment()))) {
        //if it was a double or a species with an amount, we already dealt with it.  Otherwise:
        if (useassignment) {
          InitialAssignment* ia = sbmlmod->createInitialAssignment();
          ia->setSymbol(var->GetNameDelimitedBy(cc));
          ia->setMath(math);
        }
    }
    if (comp) {
      formula->AddReferencedVariablesTo(referencedVars);
    }
    delete math;
  }
  if (ftype == formulaRATE) {
    formula = var->GetRateRule();
    if (!formula->IsEmpty()) {
      if (userate) {
        ASTNode* math = parseStringToASTNode(var->GetRateRule()->ToSBMLString());
        RateRule* rr = sbmlmod->createRateRule();
        rr->setVariable(var->GetNameDelimitedBy(cc));
        rr->setMath(math);
        delete math;
        if (comp) {
          formula->AddReferencedVariablesTo(referencedVars);
        }
      }
    }
  }
}

#ifdef USE_COMP
vector<string> GetSubmodNameFor(SBase* sbase)
{
  vector<string> ret;
  SBase* parent = sbase->getParentSBMLObject();
  while (parent != NULL && parent->getTypeCode() != SBML_DOCUMENT) {
    if (parent->getTypeCode() == SBML_COMP_SUBMODEL) {
      ret.insert(ret.begin(), parent->getId());
    }
    parent = parent->getParentSBMLObject();
  }
  return ret;
}

void CreateImpliedDeletion(Submodel* submodel, SBase* sbase, SBMLDocument& sbml, string basemetaid)
{
  //First check if there already is a deletion
  for (size_t d=0; d<submodel->getNumDeletions(); d++) {
    Deletion* del=submodel->getDeletion(static_cast<unsigned int>(d));
    if (del->getReferencedElement() == sbase) return;
  }
  vector<string> submodname = GetSubmodNameFor(sbase);
  submodname.insert(submodname.begin(), submodel->getId());
  Deletion* deletion = submodel->createDeletion();
  string metaid = sbase->getMetaId();
  if (metaid.empty()) {
    //Need to set one.
    size_t num = 1;
    metaid = basemetaid;
    while (sbml.getElementByMetaId(metaid) != NULL) {
      metaid = basemetaid + SizeTToString(num);
      num++;
    }
    //However, sbase might just be a copy of the real thing we need to find:
    SBase* parent = sbase->getAncestorOfType(SBML_COMP_SUBMODEL, "comp");
    Submodel* submod = static_cast<Submodel*>(parent);
    if (submod != NULL) {
      //Yup, it was a copy.
      CompSBMLDocumentPlugin* sbmlp = static_cast<CompSBMLDocumentPlugin*>(sbml.getPlugin("comp"));
      ModelDefinition* md = sbmlp->getModelDefinition(submod->getModelRef());
      InitialAssignment* ia = NULL;
      Rule* rule = NULL;
      switch(sbase->getTypeCode()) {
      case SBML_INITIAL_ASSIGNMENT:
        ia = static_cast<InitialAssignment*>(sbase);
        ia = md->getInitialAssignment(ia->getSymbol());
        if (ia->isSetMetaId()) {
          metaid = ia->getMetaId();
        }
        else {
          ia->setMetaId(metaid);
        }
        break;
      case SBML_RATE_RULE:
      case SBML_ASSIGNMENT_RULE:
        rule = static_cast<Rule*>(sbase);
        rule = md->getRule(rule->getVariable());
        if (rule->isSetMetaId()) {
          metaid = rule->getMetaId();
        }
        else {
          rule->setMetaId(metaid);
        }
        break;
      default:
        assert(false);
        break;
      }
    }
//     std::cerr << "implied deletion meta id " << metaid << "\n";
    sbase->setMetaId(metaid);
    SBaseRef* subsbr = new SBaseRef();
    subsbr->setMetaIdRef(metaid);
    while (submod != NULL && submod != submodel) {
      SBaseRef* newsbr = new SBaseRef();
      newsbr->setIdRef(submod->getId());
      newsbr->setSBaseRef(subsbr);
      subsbr = newsbr;
      submod = static_cast<Submodel*>(submod->getAncestorOfType(SBML_COMP_SUBMODEL, "comp"));
    }
    deletion->setIdRef(subsbr->getIdRef());
    deletion->setMetaIdRef(subsbr->getMetaIdRef());
    deletion->setSBaseRef(subsbr->getSBaseRef());
    delete subsbr;
    return;
  }
  SBaseRef* sbr = deletion;
  for (size_t i=1; i<submodname.size(); i++) {
    sbr->setIdRef(submodname[i]);
    sbr = sbr->createSBaseRef();
  }
  sbr->setMetaIdRef(metaid);
}

InitialAssignment* Module::FindInitialAssignment(Model* md, vector<string> syncname)
{
  InitialAssignment* ia = md->getInitialAssignment(syncname[syncname.size()-1]);
  if (ia != NULL) return ia;
  SBase* object = md->getElementBySId(syncname[syncname.size()-1]);
  if (object==NULL) return NULL;
  CompSBasePlugin* objp = static_cast<CompSBasePlugin*>(object->getPlugin("comp"));
  for (unsigned long re=0; re<objp->getNumReplacedElements(); re++) {
    SBase* referenced = objp->getReplacedElement(re)->getReferencedElement();
    syncname[1] = referenced->getId();
    SBase* parent = referenced->getParentSBMLObject();
    while (parent != NULL && parent->getTypeCode() != SBML_MODEL && parent->getTypeCode() != SBML_COMP_MODELDEFINITION) {
      parent = parent->getParentSBMLObject();
    }
    if (parent != NULL) {
      Model* parentmod = static_cast<Model*>(parent);
      InitialAssignment* ia = FindInitialAssignment(parentmod, syncname);
      if (ia != NULL) {
        return ia;
      }
    }
  }

  return NULL;
}

Rule* Module::FindRule(Model* md, vector<string> syncname)
{
  Rule* rule = md->getRule(syncname[syncname.size()-1]);
  if (rule != NULL) return rule;
  SBase* object = md->getElementBySId(syncname[syncname.size()-1]);
  if (object==NULL) return NULL;
  CompSBasePlugin* objp = static_cast<CompSBasePlugin*>(object->getPlugin("comp"));
  for (unsigned long re=0; re<objp->getNumReplacedElements(); re++) {
    SBase* referenced = objp->getReplacedElement(re)->getReferencedElement();
    syncname[1] = referenced->getId();
    SBase* parent = referenced->getParentSBMLObject();
    while (parent != NULL && parent->getTypeCode() != SBML_MODEL && parent->getTypeCode() != SBML_COMP_MODELDEFINITION) {
      parent = parent->getParentSBMLObject();
    }
    if (parent != NULL) {
      Model* parentmod = static_cast<Model*>(parent);
      Rule* rule = FindRule(parentmod, syncname);
      if (rule != NULL) {
        return rule;
      }
    }
  }

  return NULL;
}

bool Module::SynchronizeAssignments(Model* sbmlmod, const Variable* var, const vector<const Variable*>& synchronized, const map<const Variable*, Variable>& syncmap)
{
  bool ret = true;
  const Formula* currentform = var->GetFormula();
  bool notblank = !currentform->IsEmpty();
  for (size_t v=0; v<synchronized.size(); v++) {
    map<const Variable*, Variable >::const_iterator syncmapiter = syncmap.find(synchronized[v]);
    if (syncmapiter == syncmap.end()) {
      assert(false);
      continue;
    }
    const Variable* orig = &syncmapiter->second;
    if (ret && notblank && var->GetFormulaType() == orig->GetFormulaType() &&
        orig->GetFormula()->Matches(currentform)) {
          ret = false; //We can leave the original definition there.
          continue;
    }
    if (orig->GetFormula()->IsEmpty()) continue; //There won't be any ia's or ar's in the original.
    //Otherwise, delete any initial assignments or assignment rules in the submodel.
    vector<string> syncname = synchronized[v]->GetName();
    vector<string> submodname = syncname;
    submodname.pop_back();
    Variable* submod = GetVariable(submodname);
    if (submod==NULL) {
      assert(false);
      continue;
    }
    if (orig->GetFormulaType() == formulaASSIGNMENT) {
      if (submod->HasDeletion(syncname, delAssignmentRule)) continue;
    }
    else if (orig->GetFormulaType() == formulaINITIAL) {
      if (submod->HasDeletion(syncname, delInitialAssignment)) continue;
    }
    Model* md = sbmlmod;
    for (size_t sm=0; sm<submodname.size(); sm++) {
      CompModelPlugin* cmp = static_cast<CompModelPlugin*>(md->getPlugin("comp"));
      Submodel* instantiatedsubmod = cmp->getSubmodel(submodname[sm]);
      md = instantiatedsubmod->getInstantiation();
    }
    CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
    md = static_cast<Model*>(compdoc->getModel(md->getId()));
    vector<string> iasyncname = syncname;
    InitialAssignment* ia = FindInitialAssignment(md, iasyncname);
    if (iasyncname != syncname) {
      iasyncname.insert(iasyncname.begin(), submodname[0]);
    }
    vector<string> rulesyncname = syncname;
    Rule* ar = FindRule(md, syncname);
    if (iasyncname != syncname) {
      rulesyncname.insert(rulesyncname.begin(), submodname[0]);
    }
    CompModelPlugin* cmp = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
    Submodel* submodel = cmp->getSubmodel(submodname[0]);
    if (submod==NULL) {
      assert(false);
      return ret;
    }
    if (ia != NULL) {
      string basemetaid = ia->getParentSBMLObject()->getParentSBMLObject()->getId() + "__" + ia->getId() + "__initialAssignment";
      CreateImpliedDeletion(submodel, ia, m_sbml, basemetaid);
    }
    if (ar != NULL && ar->isAssignment()) {
      string basemetaid = ar->getParentSBMLObject()->getParentSBMLObject()->getId() + "__" + ar->getId() + "__assignmentRule";
      CreateImpliedDeletion(submodel, ar, m_sbml, basemetaid);
    }
  }
  return ret;
}

bool Module::SynchronizeRates(Model* sbmlmod, const Variable* var, const vector<const Variable*>& synchronized, const map<const Variable*, Variable>& syncmap)
{
  bool ret = true;
  const Formula* currentform = var->GetRateRule();
  bool notblank = !currentform->IsEmpty();
  for (size_t v=0; v<synchronized.size(); v++) {
    map<const Variable*, Variable >::const_iterator syncmapiter = syncmap.find(synchronized[v]);
    if (syncmapiter == syncmap.end()) {
      assert(false);
      continue;
    }
    const Variable* orig = &syncmapiter->second;
    if (ret && notblank && var->GetFormulaType() == orig->GetFormulaType() &&
        orig->GetRateRule()->Matches(currentform)) {
          ret = false; //We can leave the original definition there.
          continue;
    }
    if (orig->GetRateRule()->IsEmpty()) continue; //There won't be any rr's in the original.
    //Otherwise, delete any rate rules in the submodel.
    vector<string> syncname = synchronized[v]->GetName();
    vector<string> submodname = syncname;
    submodname.pop_back();
    Variable* submod = GetVariable(submodname);
    if (submod==NULL) {
      assert(false);
      continue;
    }
    if (submod->HasDeletion(syncname, delRateRule)) continue;
    Model* md = sbmlmod;
    for (size_t sm=0; sm<submodname.size(); sm++) {
      CompModelPlugin* cmp = static_cast<CompModelPlugin*>(md->getPlugin("comp"));
      Submodel* instantiatedsubmod = cmp->getSubmodel(submodname[sm]);
      md = instantiatedsubmod->getInstantiation();
    }
    Rule* rr = FindRule(md, syncname);
    if (rr != NULL && rr->isRate()) {
      CompModelPlugin* cmp = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
      Submodel* submodel = cmp->getSubmodel(submodname[0]);
      if (submod==NULL) {
        assert(false);
        return ret;
      }
      string basemetaid = rr->getParentSBMLObject()->getParentSBMLObject()->getId() + "__" + rr->getId() + "__rateRule";
      CreateImpliedDeletion(submodel, rr, m_sbml, basemetaid);
    }
  }
  return ret;
}
#endif //USE_COMP

void Module::FixNames(Model* model)
{
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
    "var"
    };

    const char* functions[] = {
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
    };

    const char* constants[] = {
    "true"
    , "True"
    , "TRUE"
    , "false"
    , "False"
    , "FALSE"
    , "pi"
    , "exponentiale"
    , "exponentialE"
    , "avogadro"
    , "time"
    , "inf"
    , "INF"
    , "infinity"
    , "NaN"
    , "nan"
    , "NAN"
    , "notanumber"
    };

    const char* units[] = {
    "length"
    , "area"
    , "volume"
    , "substance"
    , "extent"
    , "time_unit"
    };

    //At some point, it would be nice to allow keywords that are functions as 
    // variable names, and visa versa.  But today is not that day.
    for (size_t kw = 0; kw < 21; kw++) {
        FixConstants(keywords[kw], model);
        FixFunctions(keywords[kw], model);
    }

    for (size_t fn = 0; fn < 88; fn++) {
        FixConstants(functions[fn], model);
        FixFunctions(functions[fn], model);
    }

    for (size_t c = 0; c < 18; c++) {
        FixConstants(constants[c], model);
        FixFunctions(constants[c], model);
    }

    for (size_t u = 0; u < 6; u++) {
        FixConstants(units[u], model);
        FixFunctions(units[u], model);
    }

    FixUnitNames(model);
}

void Module::FixConstants(const string& name, Model* model)
{
    SBase* obj = model->getElementBySId(name);
    if (obj != NULL && obj->getTypeCode() != SBML_FUNCTION_DEFINITION) {
        string newname = name + "_";
        obj->setId(newname);
        List* elements = model->getAllElements();
        for (unsigned int el = 0; el < elements->getSize(); el++) {
            SBase* element = static_cast<SBase*>(elements->get(el));
            element->renameSIdRefs(name, newname);
        }
    }
}

void Module::FixFunctions(const string& name, Model* model)
{
    SBase* obj = model->getElementBySId(name);
    if (obj != NULL && obj->getTypeCode() == SBML_FUNCTION_DEFINITION) {
        string newname = name + "_";
        obj->setId(newname);
        model->renameSIdRefs(name, newname);
        List* elements = model->getAllElements();
        for (unsigned int el = 0; el < elements->getSize(); el++) {
            SBase* element = static_cast<SBase*>(elements->get(el));
            element->renameSIdRefs(name, newname);
        }
        for (unsigned int fd = 0; fd < model->getNumFunctionDefinitions(); fd++) {
            ASTNode* astn = const_cast<ASTNode*>(model->getFunctionDefinition(fd)->getMath());
            if (astn) {
                astn->renameSIdRefs(name, newname);
            }
        }
    }
    else {

    }
}

void Module::FixUnitNames(Model* model)
{
    for (unsigned int un = 0; un < model->getNumUnitDefinitions(); un++) {
        UnitDefinition* ud = model->getUnitDefinition(un);
        if (!ud->isSetId()) {
            continue;
        }
        string unitid = ud->getId();
        bool shadowed_unit_name = false;
        SBase* shadow = model->getListOfCompartments()->getElementBySId(unitid);
        if (shadow == NULL) {
            shadow = model->getListOfConstraints()->getElementBySId(unitid);
        }
        if (shadow == NULL) {
            shadow = model->getListOfEvents()->getElementBySId(unitid);
        }
        if (shadow == NULL) {
            shadow = model->getListOfFunctionDefinitions()->getElementBySId(unitid);
        }
        if (shadow == NULL) {
            shadow = model->getListOfParameters()->getElementBySId(unitid);
        }
        if (shadow == NULL) {
            shadow = model->getListOfReactions()->getElementBySId(unitid);
        }
        if (shadow == NULL) {
            shadow = model->getListOfSpecies()->getElementBySId(unitid);
        }
        if (shadow != NULL) {
            //It was shadowed:  rename the unit.
            string newunitid = unitid + "_unit";
            ud->setId(newunitid);
            List* elements = model->getAllElements();
            for (unsigned int el = 0; el < elements->getSize(); el++) {
                SBase* element = static_cast<SBase*>(elements->get(el));
                element->renameUnitSIdRefs(unitid, newunitid);
            }
        }
    }
}

void changeRateOf(ASTNode* astn)
{
    if (astn == NULL) {
        return;
    }
    if (astn->getType() == AST_FUNCTION && astn->getName() == (string)"rateOf") {
        astn->setType(AST_FUNCTION_RATE_OF);
    }
    for (unsigned int c = 0; c < astn->getNumChildren(); c++) {
        changeRateOf(astn->getChild(c));
    }
}

void Module::UpdateRateOf(Model* model)
{
    FunctionDefinition* rateOf = NULL;
    for (unsigned int fd = 0; fd < model->getNumFunctionDefinitions(); fd++) {
        FunctionDefinition* function = model->getFunctionDefinition(fd);
        if (function->getId() == (string)"rateOf" && function->getNumArguments() == 1) {
            rateOf = function;
        }
    }
    if (rateOf != NULL) {
        model->getSBMLDocument()->setLevelAndVersion(3, 2, false);
        model->removeFunctionDefinition("rateOf");
        List* elements = model->getAllElements();
        for (unsigned int el = 0; el < elements->getSize(); el++) {
            SBase* element = static_cast<SBase*>(elements->get(el));
            ASTNode* astn = const_cast<ASTNode*>(element->getMath());
            changeRateOf(astn);
        }
    }
}

#endif //NSBML

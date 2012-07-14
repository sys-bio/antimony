#ifndef NSBML
#ifdef USE_COMP

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

Variable* Module::GetSBaseRef(const SBaseRef* csbr, std::string modname, std::string re_string, const SBase* orig)
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
  refname.push_back(refid);
  //Now move back up the stack of submodels until we get to modname:
  const SBase* parent = referenced->getParentSBMLObject();
  while (parent != NULL) {
    if (parent->getTypeCode()==SBML_COMP_SUBMODEL) {
      string submodelid = parent->getId();
      refname.insert(refname.begin(), submodelid);
    }
    parent = parent->getParentSBMLObject();
  }
  Variable* ret = GetVariable(refname);
  if (ret==NULL) {
      g_registry.AddWarning("Unable to connect a " + re_string + " for " + orig->getElementName() + " " + orig->getId() + " in model " + GetModuleName() + ": the variable " + ToStringFromVecDelimitedBy(refname, '.') + " could not be found.");
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
  const SBase* parentchain = parent->getParentSBMLObject();
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

void Module::TranslateReplacedElementsFor(const CompSBasePlugin* cplugin, Variable* var)
{
  if (cplugin == NULL) return;
  const SBase* psbmlo = cplugin->getParentSBMLObject();
  //While we are searching for replaced elements, etc., find the single canonical version of these things, if they exist.
  const InitialAssignment* ia = NULL;
  const Rule* rule = NULL;
  bool noreplace = true;
  bool origformisblank = var->GetFormula()->IsEmpty();

  for (unsigned int re=0; re<cplugin->getNumReplacedElements(); re++) {
    const ReplacedElement* replaced = cplugin->getReplacedElement(re);
    if (replaced->isSetConversionFactor()) {
      g_registry.AddWarning("Unable to translate the conversion factor for the replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": individual conversion factors are not yet added as a concept in Antimony.");
    }
    Variable* smvar = NULL;
    GetReplacingAndRules(replaced, "replaced element", psbmlo, smvar, ia, rule);
    noreplace = false;
    if (smvar!=NULL) {
      smvar->Synchronize(var);
      //If it is NULL, we've already added an appropriate warning.
    }
  }
  if (cplugin->isSetReplacedBy()) {
    const ReplacedBy* replacedby = cplugin->getReplacedBy();
    Variable* smvar;
    GetReplacingAndRules(replacedby, "replacement element", psbmlo, smvar, ia, rule);
    noreplace = false;
    if (smvar!=NULL) {
      var->Synchronize(smvar);
      //If it is NULL, we've already added an appropriate warning.
    }
  }
  if (noreplace) {
    const SBase* parentmod = psbmlo;
    while (parentmod != NULL && parentmod->getTypeCode() != SBML_MODEL && parentmod->getTypeCode() != SBML_COMP_MODELDEFINITION) {
      parentmod = parentmod->getParentSBMLObject();
    }
    const Model* pm = static_cast<const Model*>(parentmod);
    ia = pm->getInitialAssignment(psbmlo->getId());
    rule = pm->getRule(psbmlo->getId());
  }
  if (ia != NULL) {
    Formula* formula = g_registry.NewBlankFormula();
    string formulastring(parseASTNodeToString(ia->getMath()));
    setFormulaWithString(formulastring, formula, this);
    formula->SetNewTopNameWith(ia, GetModuleName());
    var->SetFormula(formula);
  }
  else if (!cplugin->isSetReplacedBy() && origformisblank && !var->GetFormula()->IsEmpty()) {
    //We need to ensure that synchronization didn't overwrite the original blank.
    Formula* form = g_registry.NewBlankFormula();
    string space = " ";
    form->AddText(&space);
    var->SetFormula(form);
  }
  if (rule != NULL) {
    var->SetWithRule(rule);
  }
  else if (!var->GetRateRule()->IsEmpty()) {
    //The old rate rule must have been deleted.
    Formula* form = g_registry.NewBlankFormula();
    string space = " ";
    form->AddText(&space);
    var->SetRateRule(form);
  }
}

void Module::AddSubmodelsToDocument(SBMLDocument* sbml)
{
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(sbml->getPlugin("comp"));

  size_t numsubmods = GetNumVariablesOfType(subModules, true);
  if (numsubmods > 0) compdoc->setRequired(true);
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

#endif  //USE_COMP

void Module::LoadSBML(const Model* sbml)
{
#ifdef USE_COMP
  //Load submodels
  const CompModelPlugin* mplugin = static_cast<const CompModelPlugin*>(sbml->getPlugin("comp"));
  if (mplugin != NULL) {
    for (unsigned int sm=0; sm<mplugin->getNumSubmodels(); sm++) {
      const Submodel* submodel = mplugin->getSubmodel(sm);
      string submodname = getNameFromSBMLObject(submodel, "submod");
      Variable* var = AddOrFindVariable(&submodname);
      if (submodel->isSetName()) {
        var->SetDisplayName(submodel->getName());
      }
      string refname = submodel->getModelRef();
      if (g_registry.GetModule(refname)==NULL) {
        g_registry.LoadModelFrom(refname, sbml->getSBMLDocument());
      }
      if (var->SetModule(&refname)) {
        g_registry.AddWarning("Unable to find submodel " + refname + ".");
      }
      for (unsigned int d=0; d<submodel->getNumDeletions(); d++) {
        const Deletion* deletion = submodel->getDeletion(d);
        string delname = getNameFromSBMLObject(deletion, "del");
        //var = AddOrFindVariable(&delname);
        g_registry.AddWarning("Unable to process the deletion " + delname + " from submodel " + submodname + " in model " + GetModuleName() + ".  Deletions have not yet been added as a concept in Antimony.");
        //LS DEBUG:  when we have deletions, add them here.
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
    g_registry.NewUserFunction(&sbmlname);
    for (unsigned int arg=0; arg<function->getNumArguments(); arg++) {
      string argument(parseASTNodeToString(function->getArgument(arg)));
      Variable* expvar = g_registry.AddVariableToCurrent(&argument);
      g_registry.AddVariableToCurrentExportList(expvar);
    }
    string formulastring(parseASTNodeToString(function->getBody()));
    Formula* formula = g_registry.NewBlankFormula();
    setFormulaWithString(formulastring, formula, this);
    g_registry.SetUserFunction(formula);
    g_registry.GetNthUserFunction(g_registry.GetNumUserFunctions()-1)->FixNames();
  }

  //Units
  for (unsigned int ud=0; ud<sbml->getNumUnitDefinitions(); ud++) {
    const UnitDefinition* unitdefinition = sbml->getUnitDefinition(ud);
    sbmlname = getNameFromSBMLObject(unitdefinition, "_UD");
    FixUnitName(sbmlname);
    Variable* var = AddOrFindVariable(&sbmlname);
    if (unitdefinition->isSetName()) {
      var->SetDisplayName(unitdefinition->getName());
    }
    var->SetUnitDef(&GetUnitDefFrom(unitdefinition, m_modulename));
#ifdef USE_COMP
    const CompSBasePlugin* udplugin = static_cast<const CompSBasePlugin*>(unitdefinition->getPlugin("comp"));
    TranslateReplacedElementsFor(udplugin, var);
#endif
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
    if (compartment->isSetName()) {
      var->SetDisplayName(compartment->getName());
    }
    var->SetType(varCompartment);
    Formula* formula = g_registry.NewBlankFormula();
    if (compartment->isSetSize()) {
      formula->AddNum(compartment->getSize());
      var->SetFormula(formula);
    }
    if (compartment->isSetUnits()) {
      var->SetUnitVariable(compartment->getUnits());
    }
    if (compartment->isSetConstant()) {
      var->SetIsConst(compartment->getConstant());
    }
#ifdef USE_COMP
    const CompSBasePlugin* cplugin = static_cast<const CompSBasePlugin*>(compartment->getPlugin("comp"));
    TranslateReplacedElementsFor(cplugin, var);
#endif
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

    //Setting the formula
    Formula* formula = g_registry.NewBlankFormula();
    if (species->isSetInitialAmount()) {
      double amount = species->getInitialAmount();
      formula->AddNum(amount);
      if (amount != 0 && defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
        Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
        Formula* compform = compartment->GetFormula();
        if (!compform->IsOne()) {
          formula->AddMathThing('/');
          formula->AddVariable(compartment);
        }
      }
      var->SetFormula(formula);
    }
    else if (species->isSetInitialConcentration()) {
      formula->AddNum(species->getInitialConcentration());
      var->SetFormula(formula);
    }
    //Anything more complicated is set in a Rule, which we'll get to later.

    if (species->getConstant() || species->getBoundaryCondition()) {
      //Since all species are variable by default, we only set this explicitly if true.
      var->SetIsConst(true);
    }
    Variable* compartment = NULL;
    if (defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
      Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
      compartment->SetType(varCompartment);
      var->SetCompartment(compartment);
    }
    if (species->isSetUnits()) {
      Variable* spunits = AddOrFindVariable(&(species->getUnits()));
      spunits->SetType(varUnitDefinition);
      UnitDef* ud = new UnitDef(*spunits->GetUnitDef());
      UnitDef* compud = NULL;
      if (compartment==NULL) {
        string volume = "volume";
        compud = AddOrFindVariable(&volume)->GetUnitDef();
      }
      else {
        Variable* compunits = compartment->GetUnitVariable();
        compud = compunits->GetUnitDef();
      }
      ud->DivideUnitDef(compud);
      ud->Reduce();
      Variable* concentrationUnits = AddOrFindUnitDef(ud);
      var->SetUnitVariable(concentrationUnits);
    }
#ifdef USE_COMP
    const CompSBasePlugin* splugin = static_cast<const CompSBasePlugin*>(species->getPlugin("comp"));
    TranslateReplacedElementsFor(splugin, var);
#endif
  }

  //Events:
  for (unsigned int ev=0; ev<sbml->getNumEvents(); ev++) {
    const Event* event = sbml->getEvent(ev);
    sbmlname = getNameFromSBMLObject(event, "_E");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (event->isSetName()) {
      var->SetDisplayName(event->getName());
    }
    var->SetType(varEvent);

    //Set the trigger:
    string triggerstring(parseASTNodeToString(event->getTrigger()->getMath()));
    Formula trigger;
    setFormulaWithString(triggerstring, &trigger, this);
    Formula delay;
    const Delay* sbmldelay = event->getDelay();
    if (sbmldelay != NULL) {
      string delaystring(parseASTNodeToString(sbmldelay->getMath()));
      setFormulaWithString(delaystring, &delay, this);
    }
    AntimonyEvent antevent(delay, trigger, var);

    //Set the priority:
    if (event->isSetPriority()) {
      const Priority* sbmlpriority = event->getPriority();
      Formula priority;
      if (sbmlpriority != NULL) {
        string prioritystring(parseASTNodeToString(sbmlpriority->getMath()));
        setFormulaWithString(prioritystring, &priority, this);
      }
      antevent.SetPriority(priority);
    }
    //And set the other optional booleans:
    if (event->isSetUseValuesFromTriggerTime()) {
      antevent.SetUseValuesFromTriggerTime(event->getUseValuesFromTriggerTime());
    }
    if (event->getTrigger()->isSetPersistent()) {
      antevent.SetPersistent(event->getTrigger()->getPersistent());
    }
    if (event->getTrigger()->isSetInitialValue()) {
      antevent.SetInitialValue(event->getTrigger()->getInitialValue());
    }
    //All done--give it to the variable.
    var->SetEvent(&antevent);

    //Set the assignments:
    for (unsigned int asnt=0; asnt<event->getNumEventAssignments(); asnt++) {
      const EventAssignment* assignment = event->getEventAssignment(asnt);
      string name = assignment->getVariable();
      Variable* asntvar = AddOrFindVariable(&name);
      Formula*  asntform = g_registry.NewBlankFormula();
      setFormulaWithString(parseASTNodeToString(assignment->getMath()), asntform, this);
      var->GetEvent()->AddResult(asntvar, asntform);
    }
#ifdef USE_COMP
    const CompSBasePlugin* eplugin = static_cast<const CompSBasePlugin*>(event->getPlugin("comp"));
    TranslateReplacedElementsFor(eplugin, var);
#endif
  }

  //LS DEBUG:  Add constraints?

  //Parameters
  for (unsigned int param=0; param<sbml->getNumParameters(); param++) {
    const Parameter* parameter = sbml->getParameter(param);
    sbmlname = getNameFromSBMLObject(parameter, "_P");
    Variable* var = AddOrFindVariable(&sbmlname);
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
#ifdef USE_COMP
    const CompSBasePlugin* pplugin = static_cast<const CompSBasePlugin*>(parameter->getPlugin("comp"));
    TranslateReplacedElementsFor(pplugin, var);
#endif
  }

#ifndef USE_COMP
  //Initial Assignments:  can override 'getValue' values.
  for (unsigned int ia=0; ia<sbml->getNumInitialAssignments(); ia++) {
    const InitialAssignment* initasnt = sbml->getInitialAssignment(ia);
    if (!initasnt->isSetSymbol()) {
      assert(false); //Should have been caught in SBML validity check.
      continue;
    }
    sbmlname = initasnt->getSymbol();
    Variable* var = AddOrFindVariable(&sbmlname);
    Formula* formula = g_registry.NewBlankFormula();
    string formulastring(parseASTNodeToString(initasnt->getMath()));
    setFormulaWithString(formulastring, formula, this);
    var->SetFormula(formula);
  }
    
  //Rules:
  for (unsigned int rulen=0; rulen<sbml->getNumRules(); rulen++) {
    const Rule* rule = sbml->getRule(rulen);
    if (rule->isAlgebraic()) {
      //LS DEBUG:  error message?  Unable to process algebraic rules
      continue;
    }
    sbmlname = rule->getVariable();
    assert(sbmlname != "");
    if (sbmlname == "") {
      sbmlname = getNameFromSBMLObject(rule, "_R");
    }
    Variable* var = AddOrFindVariable(&sbmlname);
    var->SetWithRule(rule);
  }
#endif
  //If we ever get algebraic rules, we will need to set them up here, for both comp and non-comp (and check their replacements).

  //Reactions
  for (unsigned int rxn=0; rxn<sbml->getNumReactions(); rxn++) {
    const Reaction* reaction = sbml->getReaction(rxn);
    sbmlname = getNameFromSBMLObject(reaction, "_J");
    Variable* var = AddOrFindVariable(&sbmlname);
    if (reaction->isSetName()) {
      var->SetDisplayName(reaction->getName());
    }
    //reactants
    ReactantList reactants;
    for (unsigned int react=0; react<reaction->getNumReactants(); react++) {
      const SpeciesReference* reactant = reaction->getReactant(react);
      double stoichiometry = 1;
      if (reactant->isSetStoichiometryMath()) {
        //LS DEBUG:  error message?
      }
      else {
        if (reactant->isSetStoichiometry()) {
          stoichiometry = reactant->getStoichiometry();
        }
        //LS DEBUG:  else error?
      }
      sbmlname = reactant->getSpecies();
      if (sbmlname == "") {
        sbmlname = getNameFromSBMLObject(reactant, "_S");
      }
      Variable* rvar = AddOrFindVariable(&sbmlname);
      reactants.AddReactant(rvar, stoichiometry);
    }
    //products
    ReactantList products;
    for (unsigned int react=0; react<reaction->getNumProducts(); react++) {
      const SpeciesReference* product = reaction->getProduct(react);
      double stoichiometry = 1;
      if (product->isSetStoichiometryMath()) {
        //LS DEBUG:  error message?
      }
      else {
        if (product->isSetStoichiometry()) {
          stoichiometry = product->getStoichiometry();
        }
      }
      sbmlname = product->getSpecies();
      if (sbmlname == "") {
        sbmlname = getNameFromSBMLObject(product, "_S");
      }
      Variable* rvar = AddOrFindVariable(&sbmlname);
      products.AddReactant(rvar, stoichiometry);
    }
    //formula
    string formulastring = "";
    Formula formula;
    if (reaction->isSetKineticLaw()) {
      const KineticLaw* kl = reaction->getKineticLaw();
      formulastring = parseASTNodeToString(kl->getMath());
      setFormulaWithString(formulastring, &formula, this);
      for (unsigned int localp=0; localp<kl->getNumParameters(); localp++) {
        const Parameter* localparam = kl->getParameter(localp);
        vector<string> fullname;
        //Find the variable with the original name:
        string origname = getNameFromSBMLObject(localparam, "_P");
        fullname.push_back(origname);
        Variable* origvar = GetVariable(fullname);

        //Create a new variable with a new name:
        fullname.clear();
        sbmlname = var->GetNameDelimitedBy('_') + "_" + origname;
        fullname.push_back(sbmlname);
        Variable* foundvar = GetVariable(fullname);
        while (foundvar != NULL) {
          //Just in case something weird happened and there was another one of *this* name, too.
          sbmlname = var->GetNameDelimitedBy('_') + "_" + sbmlname;
          fullname.clear();
          fullname.push_back(sbmlname);
          foundvar = GetVariable(fullname);
        }
        Variable* localvar = AddOrFindVariable(&sbmlname);

        //Replace the variable in the formula:
        if(origvar != NULL) {
          formula.ReplaceWith(origvar, localvar);
        }
        else {
          //If origvar is NULL, nothing needs to be replaced: if the original formula had included the parameter, the earlier setFormulaWithString would have created one.  But since there wasn't one, this means the original formula didn't include the parameter at all!  Meaning this local parameter has no use whatsoever!  What the heck, dude.  Oh, well.
          //cout << "Unused local variable for reaction " << var->GetNameDelimitedBy('.') << ":  " << origname << endl;
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
    }
    else if (reaction->getNumModifiers() > 0) {
      //If the kinetic law is empty, we can set some interactions, if there are any Modifiers.
      ReactantList right;
      right.AddReactant(var);
      ReactantList left;
      for (unsigned int mod=0; mod<reaction->getNumModifiers(); mod++) {
        const ModifierSpeciesReference* msr = reaction->getModifier(mod);
        string species = msr->getSpecies();
        Variable* specvar = AddOrFindVariable(&species);
        left.AddReactant(specvar);
        sbmlname = getNameFromSBMLObject(msr, "_I");
      }
      Variable* interaction = AddOrFindVariable(&sbmlname);
      Formula blankform;
      AddNewReaction(&left, rdInfluences, &right, &blankform, interaction);
    }
    rd_type rxntype = rdBecomes;
    if (!reaction->getReversible()) {
      rxntype = rdBecomesIrreversibly;
    }
    //Put reactants, products, and the formula together:
    AddNewReaction(&reactants, rxntype, &products, &formula, var);
#ifdef USE_COMP
    const CompSBasePlugin* rplugin = static_cast<const CompSBasePlugin*>(reaction->getPlugin("comp"));
    TranslateReplacedElementsFor(rplugin, var);
#endif
  }

#ifdef USE_COMP
  if(mplugin != NULL) {
    //Ports!
    for (unsigned int p=0; p<mplugin->getNumPorts(); p++) {
      const Port* port = mplugin->getPort(p);
      if (port->isSetIdRef()) {
        string idref = port->getIdRef();
        Variable* portvar = AddOrFindVariable(&idref);
        AddVariableToExportList(portvar);
      }
      else {
        g_registry.AddWarning("Unable to add port " + port->getId() + " to model " + GetModuleName() + ":  ports created without idrefs are currently untranslatable to antimony.");
      }
    }
  }
#endif //USE_COMP

  //Finally, fix the fact that 'time' used to be OK in functions (l2v1), but is no longer (l2v2).
  g_registry.FixTimeInFunctions();
  //And that some SBML-OK names are not OK in Antimony
  FixNames();
}

const SBMLDocument* Module::GetSBML(bool comp)
{
  const Model* mod = m_sbml.getModel();
  if (comp && mod != NULL && mod->getId() == m_modulename) {
    return &m_sbml;
  }
  CreateSBMLModel(comp);
  return &m_sbml;
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
    CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
    if (compdoc != NULL) compdoc->setRequired(false);
#endif
  }
  else {
    SBMLNamespaces plainnamespaces(m_sbmllevel, m_sbmlversion);
    SBMLDocument newdoc(&plainnamespaces);
    m_sbml = newdoc;
  }

  Model* sbmlmod = m_sbml.createModel();
  sbmlmod->setId(m_modulename);
  sbmlmod->setName(m_modulename);
  char cc = g_registry.GetCC();
  map<const Variable*, Variable > syncmap;
  if (comp) {
    FillInSyncmap(syncmap); //Only need this if we're hierarchical
  }

#ifdef USE_COMP
  CompSBMLDocumentPlugin* compdoc = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
  CompModelPlugin* mplugin = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
  size_t numsubmods = GetNumVariablesOfType(subModules, true);

  //Submodels!
  if (comp) {
    AddSubmodelsToDocument(&m_sbml);
    for (size_t sm=0; sm<numsubmods; sm++) {
      Variable* submod = GetNthVariableOfType(subModules, sm, true);
      Module* module = submod->GetModule();
      Submodel* sbmlsubmod = mplugin->createSubmodel();
      sbmlsubmod->setId(submod->GetNameDelimitedBy(cc));
      sbmlsubmod->setModelRef(module->GetModuleName());
      Variable* conv = submod->GetExtentConversionFactor();
      if (conv != NULL) {
        sbmlsubmod->setExtentConversionFactor(conv->GetNameDelimitedBy(cc));
      }
      conv = submod->GetTimeConversionFactor();
      if (conv != NULL) {
        sbmlsubmod->setTimeConversionFactor(conv->GetNameDelimitedBy(cc));
      }
    }
  }
#endif //USE_COMP

  //User-defined functions
  for (size_t uf=0; uf<g_registry.GetNumUserFunctions(); uf++) {
    const UserFunction* userfunction = g_registry.GetNthUserFunction(uf);
    assert(userfunction != NULL);
    FunctionDefinition* fd = sbmlmod->createFunctionDefinition();
    fd->setId(userfunction->GetModuleName());
    ASTNode* math = parseStringToASTNode(userfunction->ToSBMLString());
    fd->setMath(math);
    delete math;
  }

  //Species
  bool need_default = false;
  size_t numspecies = GetNumVariablesOfType(allSpecies, comp);
  for (size_t spec=0; spec < numspecies; spec++) {
    Variable* species = GetNthVariableOfType(allSpecies, spec, comp);
    Species* sbmlspecies = sbmlmod->createSpecies();
    sbmlspecies->setId(species->GetNameDelimitedBy(cc));
    if (species->GetDisplayName() != "") {
      sbmlspecies->setName(species->GetDisplayName());
    }
    sbmlspecies->setConstant(false); //There's no need to try to distinguish between const and var for species.
    if (species->GetIsConst()) {
      sbmlspecies->setBoundaryCondition(true);
    }
    else {
      sbmlspecies->setBoundaryCondition(false);
    }
    const Variable* compartment = species->GetCompartment();
    if (compartment == NULL) {
      sbmlspecies->setCompartment(DEFAULTCOMP);
      need_default = true;
    }
    else {
      sbmlspecies->setCompartment(compartment->GetNameDelimitedBy(cc));
    }
    Variable* unitvar = species->GetUnitVariable();
    Formula* formula = species->GetFormula();
    if (formula->IsDouble()) {
      sbmlspecies->setInitialConcentration(atof(formula->ToSBMLString().c_str()));
    }
    else if (formula->IsAmountIn(compartment)) {
      sbmlspecies->setInitialAmount(formula->ToAmount());
    }
    if (unitvar != NULL) {
      //We need to convert concentration to substance.
      UnitDef* ud = new UnitDef(*unitvar->GetUnitDef());
      UnitDef volume("liter", m_modulename);
      if (compartment != NULL) {
        Variable* compunit = compartment->GetUnitVariable();
        if (compunit != NULL) {
          ud->MultiplyUnitDef(compunit->GetUnitDef());
        }
      }
      else {
        ud->MultiplyUnitDef(&volume);
      }
      ud->Reduce();
      Variable* newunit = AddOrFindUnitDef(ud);
      sbmlspecies->setSubstanceUnits(newunit->GetNameDelimitedBy(cc));
    }
    sbmlspecies->setHasOnlySubstanceUnits(false);
    SetAssignmentFor(sbmlmod, species, syncmap, comp);
  }

  //Units
  size_t numunits = GetNumVariablesOfType(allUnits, comp);
  for (size_t ud=0; ud<numunits; ud++) {
    Variable* unit = GetNthVariableOfType(allUnits, ud, comp);
    UnitDef* unitdef = unit->GetUnitDef();
    unitdef->AddToSBML(sbmlmod, unit->GetNameDelimitedBy(cc), unit->GetDisplayName());
    vector<string> name = unit->GetName();
    assert(!name.empty());
    string unitname = unit->GetNameDelimitedBy(cc);
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

  //Compartments
  size_t numsp= GetNumVariablesOfType(allSpecies, comp);
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
        ReplacedElement* re = plugcompartment->createReplacedElement();
        re->setSubmodelRef(submod->GetNameDelimitedBy(cc));
        re->setIdRef(DEFAULTCOMP);
      }
    }
#endif //USE_COMP
  }
  size_t numcomps = GetNumVariablesOfType(allCompartments, comp);
  for (size_t cmpt=0; cmpt<numcomps; cmpt++) {
    const Variable* compartment = GetNthVariableOfType(allCompartments, cmpt, comp);
    Compartment* sbmlcomp = sbmlmod->createCompartment();
    sbmlcomp->setId(compartment->GetNameDelimitedBy(cc));
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
      sbmlcomp->setSize(atof(formula->ToSBMLString().c_str()));
    }
    Variable* unitvar = compartment->GetUnitVariable();
    if (unitvar != NULL) {
      sbmlcomp->setUnits(unitvar->GetNameDelimitedBy('_'));
    }
    SetAssignmentFor(sbmlmod, compartment, syncmap, comp);
    sbmlcomp->setSpatialDimensions(dim);
  }

  //Formulas
  size_t numforms = GetNumVariablesOfType(allFormulas, comp);
  for (size_t form=0; form < numforms; form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form, comp);
    const Formula*  formula = formvar->GetFormula();
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    param->setConstant(formvar->GetIsConst());
    if (formula->IsDouble()) {
      param->setValue(atof(formula->ToSBMLString().c_str()));
    }
    Variable* unitvar = formvar->GetUnitVariable();
    if (unitvar != NULL) {
      param->setUnits(unitvar->GetNameDelimitedBy('_'));
    }
    SetAssignmentFor(sbmlmod, formvar, syncmap, comp);
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
    if (reaction->IsEmpty()) {
      continue; //Reactions that involve no species are illegal in SBML.
    }
    Reaction* sbmlrxn = sbmlmod->createReaction();
    sbmlrxn->setFast(false);
    sbmlrxn->setId(rxnvar->GetNameDelimitedBy(cc));
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
    const Formula* formula = reaction->GetFormula();
    string formstring = formula->ToSBMLString(rxnvar->GetStrandVars());
    if (!formula->IsEmpty()) {
      KineticLaw* kl = sbmlmod->createKineticLaw();
      ASTNode* math = parseStringToASTNode(formstring);
      kl->setMath(math);
      delete math;
    }
    const ReactantList* left = reaction->GetLeft();
    for (size_t lnum=0; lnum<left->Size(); lnum++) {
      const Variable* nthleft = left->GetNthReactant(lnum);
      double nthstoich = left->GetStoichiometryFor(lnum);
      SpeciesReference* sr = sbmlmod->createReactant();
      sr->setSpecies(nthleft->GetNameDelimitedBy(cc));
      sr->setStoichiometry(nthstoich);
      sr->setConstant(true);
    }
    const ReactantList* right = reaction->GetRight();
    for (size_t rnum=0; rnum<right->Size(); rnum++) {
      const Variable* nthright = right->GetNthReactant(rnum);
      double nthstoich = right->GetStoichiometryFor(rnum);
      SpeciesReference* sr = sbmlmod->createProduct();
      sr->setSpecies(nthright->GetNameDelimitedBy(cc));
      sr->setStoichiometry(nthstoich);
      sr->setConstant(true);
    }
    //Find 'modifiers' and add them.
    vector<const Variable*> subvars = formula->GetVariablesFrom(formstring, m_modulename);
    for (size_t v=0; v<subvars.size(); v++) {
      if (subvars[v] != NULL && subvars[v]->GetType() == varSpeciesUndef) {
        if (left->GetStoichiometryFor(subvars[v]) == 0 &&
            right->GetStoichiometryFor(subvars[v]) == 0) {
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
    Trigger* trig = sbmlevent->createTrigger();
    ASTNode* ASTtrig = parseStringToASTNode(event->GetTrigger()->ToSBMLString());
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
      ASTNode* ASTasnt = parseStringToASTNode(event->GetNthAssignmentFormulaString(asnt, '_', true));
      sbmlasnt->setMath(ASTasnt);
      delete ASTasnt;
    }
  }

  //Interactions
  size_t numinteractions = GetNumVariablesOfType(allInteractions, comp);
  for (size_t irxn=0; irxn<numinteractions; irxn++) {
    const Variable* arxnvar = GetNthVariableOfType(allInteractions, irxn, comp);
    const AntimonyReaction* arxn = arxnvar->GetReaction();
    Reaction* rxn = sbmlmod->getReaction(arxn->GetRight()->GetNthReactant(0)->GetNameDelimitedBy(cc));
    if (rxn != NULL) {
      for (size_t interactor=0; interactor<arxn->GetLeft()->Size(); interactor++) {
        ModifierSpeciesReference* msr = rxn->createModifier();
        msr->setSpecies(arxn->GetLeft()->GetNthReactant(interactor)->GetNameDelimitedBy(cc));
        msr->setName(arxnvar->GetNameDelimitedBy(cc));
      }
    }
  }

  //Unknown variables (turn into parameters)
  size_t numunknown = GetNumVariablesOfType(allUnknown, comp);
  for (size_t form=0; form < numunknown; form++) {
    const Variable* formvar = GetNthVariableOfType(allUnknown, form, comp);
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    param->setConstant(formvar->GetIsConst());
    Variable* unitvar = formvar->GetUnitVariable();
    if (unitvar != NULL) {
      param->setUnits(unitvar->GetNameDelimitedBy('_'));
    }
  }

#ifdef USE_COMP
  //Ports
  if (comp) {
    set<string> portnames;
    pair<set<string>::iterator, bool> setret;
    for (size_t ex=0; ex<m_exportlist.size(); ex++) {
      Port* port = mplugin->createPort();
      size_t test = m_exportlist[ex].size();
      if (test > 1) {
        test = test;
      }
      //assert(m_exportlist[ex].size()==1);
      port->setIdRef(m_exportlist[ex][0]);
      string portname = m_exportlist[ex][m_exportlist[ex].size()-1];
      size_t digit = 0;
      setret = portnames.insert(portname);
      while (setret.second = false) {
        portname = m_exportlist[ex][m_exportlist[ex].size()-1] + "_" + SizeTToString(digit);
        setret = portnames.insert(portname);
      }
      port->setId(portname);
    }
    //Synchronized variables
    for (size_t sync=0; sync<m_synchronized.size(); sync++) {
      vector<string> name1 = m_synchronized[sync].first;
      vector<string> name2 = m_synchronized[sync].second;
      if (name2.size() == 1 && name1.size() != 1) {
        //Switch the order if the second is a local variable and the first is not.
        name1 = name2;
        name2 = m_synchronized[sync].first;
      }
      const Variable* var1 = GetVariable(name1);
      const Variable* var2 = GetVariable(name2);
      if (name1.size() == 1 && name2.size() == 1) {
        //Don't worry about it--we already removed it in the GetNthWhatever functions.
      }
      else if (name1.size()==1) {
        SBase* sbmlvar1 = sbmlmod->getElementBySId(name1[0]);
        CompSBasePlugin* svarplug1 = static_cast<CompSBasePlugin*>(sbmlvar1->getPlugin("comp"));
        ReplacedElement* re = svarplug1->createReplacedElement();
        re->setSubmodelRef(name2[0]);
        size_t svn=1;
        SBaseRef* sbr = re;
        while (svn+1 < name2.size()) {
          sbr->setIdRef(name2[svn]);
          sbr = sbr->createSBaseRef();
          svn++;
        }
        sbr->setIdRef(name2[svn]);
      }
      else {
        assert(false);
        //Need to create a local variable.
        //LS DEBUG
      }
    }
  }
#endif //USE_COMP
}

void Module::SetAssignmentFor(Model* sbmlmod, const Variable* var, const map<const Variable*, Variable>& syncmap, bool comp)
{
  bool useinitial = true;
  bool useassignment = true;
  bool userate = true;
  if (comp) {
    //The comp version is a lot more complicated than the flat version, because we need to:
    // * Delete all rules/assignments that no longer apply to this variable
    // * Leave any rule/assignment that still applies
    // * Create a new rule/assignment if none of the old ones apply.
    vector<const Variable*> synchronized = GetSynchronizedVariablesFor(var);
    useassignment = SynchronizeAssignments(sbmlmod, var, synchronized, syncmap);
    userate = SynchronizeRates(sbmlmod, var, synchronized, syncmap);
  }
  char cc = g_registry.GetCC();
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
      }
    }
  }
}


void CreateDeletion(Submodel* submodel, SBase* sbase, SBMLDocument& sbml, vector<string> submodname, string basemetaid)
{
  Deletion* deletion = submodel->createDeletion();
  SBaseRef* sbr = deletion;
  for (size_t i=1; i<submodname.size(); i++) {
    sbr->setIdRef(submodname[i]);
    sbr = sbr->createSBaseRef();
  }
  string metaid = sbase->getMetaId();
  if (metaid.empty()) {
    //Need to set one.
    size_t num = 1;
    metaid = basemetaid;
    while (sbml.getElementByMetaId(metaid) != NULL) {
      metaid = basemetaid + SizeTToString(num);
      num++;
    }
    sbase->setMetaId(metaid);
  }
  sbr->setMetaIdRef(metaid);
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
        currentform->ToSBMLString() == orig->GetFormula()->ToSBMLString()) {
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
    CompSBMLDocumentPlugin* csdp = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
    ModelDefinition* md = csdp->getModelDefinition(submod->GetModule()->GetModuleName());
    InitialAssignment* ia = md->getInitialAssignment(syncname[syncname.size()-1]);
    Rule* ar = md->getRule(syncname[syncname.size()-1]);
    Deletion* deletion = NULL;
    SBaseRef* sbr = NULL;
    CompModelPlugin* cmp = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
    Submodel* submodel = cmp->getSubmodel(submodname[0]);
    if (submod==NULL) {
      assert(false);
      return ret;
    }
    if (ia != NULL) {
      string basemetaid = submod->GetModule()->GetModuleName() + "_" + ia->getId() + "_initialassignment";
      CreateDeletion(submodel, ia, m_sbml, submodname, basemetaid);
    }
    if (ar != NULL && ar->isAssignment()) {
      string basemetaid = submod->GetModule()->GetModuleName() + "_" + ar->getId() + "_assignmentrule";
      CreateDeletion(submodel, ar, m_sbml, submodname, basemetaid);
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
        currentform->ToSBMLString() == orig->GetRateRule()->ToSBMLString()) {
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
    CompSBMLDocumentPlugin* csdp = static_cast<CompSBMLDocumentPlugin*>(m_sbml.getPlugin("comp"));
    ModelDefinition* md = csdp->getModelDefinition(submod->GetModule()->GetModuleName());
    Rule* rr = md->getRule(syncname[syncname.size()-1]);
    if (rr != NULL && rr->isRate()) {
      CompModelPlugin* cmp = static_cast<CompModelPlugin*>(sbmlmod->getPlugin("comp"));
      Submodel* submodel = cmp->getSubmodel(submodname[0]);
      if (submod==NULL) {
        assert(false);
        return ret;
      }
      string basemetaid = submod->GetModule()->GetModuleName() + "_" + rr->getId() + "_raterule";
      CreateDeletion(submodel, rr, m_sbml, submodname, basemetaid);
    }
  }
  return ret;
}

#endif

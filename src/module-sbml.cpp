#ifndef NSBML
#ifdef USE_COMP
void Module::TranslateReplacedElementsFor(const CompSBasePlugin* cplugin, Variable* var)
{
  if (cplugin == NULL) return;
  const SBase* psbmlo = cplugin->getParentSBMLObject();
  const SBase* parentmod = psbmlo->getAncestorOfType(SBML_MODEL);
  if (parentmod == NULL) {
    parentmod = cplugin->getParentSBMLObject()->getAncestorOfType(SBML_COMP_MODELDEFINITION, "comp");
  }
  const CompModelPlugin* parentmodplug = NULL;
  if (parentmod != NULL) {
    parentmodplug = static_cast<const CompModelPlugin*>(parentmod->getPlugin("comp"));
  }
  assert(parentmodplug != NULL);
  for (unsigned int re=0; re<cplugin->getNumReplacedElements(); re++) {
    const ReplacedElement* replacement = cplugin->getReplacedElement(re);
    string submod = replacement->getSubmodelRef();
    vector<string> smname;
    smname.push_back(submod);
    Variable* smvar = GetVariable(smname);
    if (smvar == NULL) {
      g_registry.AddWarning("Unable to find submodule " + submod + " in model " + GetModuleName() + " which would have contained a replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + ".");
    }
    else {
      if (smvar->GetType() != varModule) {
        g_registry.AddWarning("Unable to connect a replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": the variable " + submod + " is not a submodel.");
      }
      else {
        if (replacement->isSetIdRef()) {
          smname.push_back(replacement->getIdRef());
          smvar = GetVariable(smname);
          if (smvar == NULL) {
            g_registry.AddWarning("Unable to connect a replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": the variable " + ToStringFromVecDelimitedBy(smname, '.') + " could not be found.");
          }
          else {
            AddSynchronizedPair(smvar, var);
          }
        }
        else if (parentmodplug == NULL) {
          //This seems unlikely?  But anyway.
          g_registry.AddWarning("Unable to find parent model of " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ".");
        }
        else if (replacement->isSetPortRef()) {
          string pid = replacement->getPortRef();
          const Submodel* submodel = parentmodplug->getSubmodel(submod);
          const SBMLDocument* doc = replacement->getSBMLDocument();
          const CompSBMLDocumentPlugin* docplug = static_cast<const CompSBMLDocumentPlugin*>(doc->getPlugin("comp"));
          const SBase* mod = docplug->getModel(submodel->getModelRef());
          if (mod == NULL) {
            g_registry.AddWarning("Unable to find the model " + submodel->getModelRef() + " in the SBML document referenced in the replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ".");
          }
          else {
            int modtc = mod->getTypeCode();
            if (modtc == SBML_COMP_EXTERNALMODELDEFINITION) {
              const ExternalModelDefinition* extmoddef = static_cast<const ExternalModelDefinition*>(mod);
              SBMLDocument* extdoc = NULL;
              Model* extmod = NULL;
              getDocumentFromExternalModelDefinition(extmoddef, extdoc, extmod);
              if (extdoc->getModel() == NULL) {
                g_registry.AddWarning("Unable to connect to a port for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": the externally-defined model could not be read.");
                //LS DEBUG:  Get this working with relative pathnames in QTAntimony (which, as of now, it does not.)
              }
              else {
                //LS DEBUG:  get this working, too.
              }
            }
            else {
              const Model* sm = static_cast<const Model*>(mod);
              const CompModelPlugin* mplugin = static_cast<const CompModelPlugin*>(sm->getPlugin("comp"));
              const Port* smport = mplugin->getPort(pid);
              if (smport == NULL) {
                g_registry.AddWarning("Unable to find the port " + pid + " in model " + submodel->getModelRef() + ".  The port does not seem to exist.  (Referenced in a replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ".)");
              }
              else {
                if (smport->isSetIdRef()) {
                  smname.push_back(smport->getIdRef());
                  smvar = GetVariable(smname);
                  if (smvar == NULL) {
                    g_registry.AddWarning("Unable to connect a replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": the variable " + ToStringFromVecDelimitedBy(smname, '.') + " could not be found.");
                  }
                  else {
                    AddSynchronizedPair(smvar, var);
                  }
                }
                else {
                  g_registry.AddWarning("Unable to connect to the port " + pid + " in model " + submod + ".  Antimony does not yet support for SBaseRef objects that do not use SIdRefs.");
                }
              }
            }
          }
        }
        else {
          g_registry.AddWarning("Unable to translate replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": translation of replacements defined with elements other than idrefs is not yet implemented.");
        }
      }
    }
    if (replacement->isSetConversionFactor()) {
      g_registry.AddWarning("Unable to translate the conversion factor for the replaced element for " + VarTypeToString(var->GetType()) + " " + var->GetNameDelimitedBy('.') + " in model " + GetModuleName() + ": conversion factors are not yet added as a concept in Antimony.");
    }
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
      if (var->SetModule(&refname)) {
        g_registry.AddWarning("Unable to find submodel " + refname + ".");
      }
      for (unsigned int d=0; d<submodel->getNumDeletions(); d++) {
        const Deletion* deletion = submodel->getDeletion(d);
        string delname = getNameFromSBMLObject(deletion, "del");
        var = AddOrFindVariable(&delname);
        g_registry.AddWarning("Unable to process the deletion " + delname + " from submodel " + submodname + " in model " + GetModuleName() + ".  Deletions have not yet been added as a concept in Antimony.");
        //LS DEBUG:  when we have deletions, add them here.
      }
      if (submodel->isSetSubstanceConversionFactor() ||
          submodel->isSetTimeConversionFactor() ||
          submodel->isSetExtentConversionFactor()) {
        g_registry.AddWarning("Unable to process the conversion factor(s) from submodel " + submodname + " in model " + GetModuleName() + ".  Conversion factors have not yet been added as a concept in Antimony.");
        //LS DEBUG:  when we have conversion factors, add them here.
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

  set<string> defaultcompartments;
  //Compartments
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
      var->SetUnits(compartment->getUnits());
    }
#ifdef USE_COMP
    if (comp) {
      const CompSBasePlugin* cplugin = static_cast<const CompSBasePlugin*>(compartment->getPlugin("comp"));
      TranslateReplacedElementsFor(cplugin, var);
    }
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
    if (defaultcompartments.find(species->getCompartment()) == defaultcompartments.end()) {
      Variable* compartment = AddOrFindVariable(&(species->getCompartment()));
      compartment->SetType(varCompartment);
      var->SetCompartment(compartment);
    }
    if (species->isSetUnits()) {
      var->SetUnits(species->getUnits());
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
      var->SetUnits(parameter->getUnits());
    }
#ifdef USE_COMP
    const CompSBasePlugin* pplugin = static_cast<const CompSBasePlugin*>(parameter->getPlugin("comp"));
    TranslateReplacedElementsFor(pplugin, var);
#endif
  }

  //Initial Assignments:  can override 'getValue' values.
  for (unsigned int ia=0; ia<sbml->getNumInitialAssignments(); ia++) {
    const InitialAssignment* initasnt = sbml->getInitialAssignment(ia);
    if (initasnt->isSetSymbol()) {
      sbmlname = initasnt->getSymbol();
      Variable* var = AddOrFindVariable(&sbmlname);
      if (initasnt->isSetName()) {
        var->SetDisplayName(initasnt->getName());
      }
      Formula* formula = g_registry.NewBlankFormula();
      string formulastring(parseASTNodeToString(initasnt->getMath()));
      setFormulaWithString(formulastring, formula, this);
      var->SetFormula(formula);
    }
    else {
      //LS DEBUG:  error?  The 'symbol' is supposed to be required.
    }
    //Don't need to check replacements--that'll all work out automatically.
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
    if (rule->isSetName()) {
      var->SetDisplayName(rule->getName());
    }
    Formula* formula = g_registry.NewBlankFormula();
    string formulastring(parseASTNodeToString(rule->getMath()));
    setFormulaWithString(formulastring, formula, this);
    if (IsSpecies(var->GetType())) {
      //Any species in any rule must be 'const' (in Antimony), because this means it's a 'boundary species'
      var->SetIsConst(true);
    }
    else {
      //For other parameters, assignment and rate rules always mean the variable in question is not constant.
      var->SetIsConst(false);
    }

    if (rule->isAssignment()) {
      var->SetAssignmentRule(formula);
    }
    else if (rule->isRate()) {
      var->SetRateRule(formula);
    }
    else {
      assert(false); //should be caught above
    }
    //Don't need to check replacements for normal rules, but if we ever get algebraic rules, we will.
  }

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
      var->SetUnits(kl->getSubstanceUnits() + "/(" + kl->getTimeUnits() + ")");
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
        Formula localformula;
        localformula.AddNum(localparam->getValue());
        localvar->SetFormula(&localformula);
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
    const Variable* species = GetNthVariableOfType(allSpecies, spec, comp);
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
    const Formula* formula = species->GetFormula();
    if (formula->IsDouble()) {
      sbmlspecies->setInitialConcentration(atof(formula->ToSBMLString().c_str()));
    }
    else if (formula->IsAmountIn(species->GetCompartment())) {
      sbmlspecies->setInitialAmount(formula->ToAmount());
    }
    sbmlspecies->setHasOnlySubstanceUnits(false);
    SetAssignmentFor(sbmlmod, species);
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
    SetAssignmentFor(sbmlmod, compartment);
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
    SetAssignmentFor(sbmlmod, formvar);
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
        //Need to create a local variable.

      }
    }
  }
#endif //USE_COMP
}

void Module::SetAssignmentFor(Model* sbmlmod, const Variable* var)
{
  char cc = g_registry.GetCC();
  formula_type ftype = var->GetFormulaType();
  const Formula* formula = var->GetFormula();
  if (!formula->IsEmpty()) {
    ASTNode* math = parseStringToASTNode(formula->ToSBMLString());
    if (ftype == formulaASSIGNMENT) {
      AssignmentRule* ar = sbmlmod->createAssignmentRule();
      ar->setVariable(var->GetNameDelimitedBy(cc));
      ar->setMath(math);
    }
    else if (!formula->IsDouble() &&
             !(IsSpecies(var->GetType()) && formula->IsAmountIn(var->GetCompartment()))) {
      //if it was a double or a species with an amount, we already dealt with it.  Otherwise:
      InitialAssignment* ia = sbmlmod->createInitialAssignment();
      ia->setSymbol(var->GetNameDelimitedBy(cc));
      ia->setMath(math);
    }
    delete math;
  }
  if (ftype == formulaRATE) {
    formula = var->GetRateRule();
    if (!formula->IsEmpty()) {
      ASTNode* math = parseStringToASTNode(var->GetRateRule()->ToSBMLString());
      RateRule* rr = sbmlmod->createRateRule();
      rr->setVariable(var->GetNameDelimitedBy(cc));
      rr->setMath(math);
      delete math;
    }
  }
}
#endif

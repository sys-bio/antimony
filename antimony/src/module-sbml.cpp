#ifndef NSBML
void Module::LoadSBML(const SBMLDocument* sbmldoc)
{
  //m_sbml = *sbmldoc;
  const Model* sbml = sbmldoc->getModel();
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
    AntimonyEvent antevent(delay, trigger,var);
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
        stoichiometry = reactant->getStoichiometry();
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
        stoichiometry = product->getStoichiometry();
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
    //Put reactants, products, and the formula together:
    AddNewReaction(&reactants, rdBecomes, &products, &formula, var);
  }
  //Finally, fix the fact that 'time' used to be OK in functions (l2v1), but is no longer (l2v2).
  g_registry.FixTimeInFunctions();
  //And that some SBML-OK names are not OK in Antimony
  FixNames();
}

const SBMLDocument* Module::GetSBML()
{
  const Model* mod = m_sbml.getModel();
  if (mod != NULL && mod->getId() == m_modulename) {
    return &m_sbml;
  }
  CreateSBMLModel();
  return &m_sbml;
}

void Module::CreateSBMLModel()
{
  Model* sbmlmod = m_sbml.createModel();
  sbmlmod->setId(m_modulename);
  sbmlmod->setName(m_modulename);
  sbmlmod->setNotes("<body xmlns=\"http://www.w3.org/1999/xhtml\"><p> Originally created by libAntimony " VERSION_STRING " (using libSBML " LIBSBML_DOTTED_VERSION ") </p></body>");
  char cc = g_registry.GetCC();
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
  //Compartments
  Compartment* defaultCompartment = sbmlmod->createCompartment();
  defaultCompartment->setId(DEFAULTCOMP);
  defaultCompartment->setConstant(true);
  defaultCompartment->setSize(1);
  defaultCompartment->setSBOTerm(410); //The 'implicit compartment'
  size_t numcomps = GetNumVariablesOfType(allCompartments);
  for (size_t comp=0; comp<numcomps; comp++) {
    const Variable* compartment = GetNthVariableOfType(allCompartments, comp);
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
  }

  //Species
  size_t numspecies = GetNumVariablesOfType(allSpecies);
  for (size_t spec=0; spec < numspecies; spec++) {
    const Variable* species = GetNthVariableOfType(allSpecies, spec);
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
      sbmlspecies->setCompartment(defaultCompartment->getId());
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
    SetAssignmentFor(sbmlmod, species);
  }

  //Formulas
  size_t numforms = GetNumVariablesOfType(allFormulas);
  for (size_t form=0; form < numforms; form++) {
    const Variable* formvar = GetNthVariableOfType(allFormulas, form);
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
  size_t numrxns = GetNumVariablesOfType(allReactions);
  for (size_t rxn=0; rxn < numrxns; rxn++) {
    const Variable* rxnvar = GetNthVariableOfType(allReactions, rxn);
    const AntimonyReaction* reaction = rxnvar->GetReaction();
    if (reaction->IsEmpty()) {
      continue; //Reactions that involve no species are illegal in SBML.
    }
    Reaction* sbmlrxn = sbmlmod->createReaction();
    sbmlrxn->setId(rxnvar->GetNameDelimitedBy(cc));
    if (rxnvar->GetDisplayName() != "") {
      sbmlrxn->setName(rxnvar->GetDisplayName());
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
    }
    const ReactantList* right = reaction->GetRight();
    for (size_t rnum=0; rnum<right->Size(); rnum++) {
      const Variable* nthright = right->GetNthReactant(rnum);
      double nthstoich = right->GetStoichiometryFor(rnum);
      SpeciesReference* sr = sbmlmod->createProduct();
      sr->setSpecies(nthright->GetNameDelimitedBy(cc));
      sr->setStoichiometry(nthstoich);
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
  size_t numevents = GetNumVariablesOfType(allEvents);
  for (size_t ev=0; ev < numevents; ev++) {
    const Variable* eventvar = GetNthVariableOfType(allEvents, ev);
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
      sbmldelay->setMath(ASTtrig);
      delete ASTtrig;
    }
      
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
  size_t numinteractions = GetNumVariablesOfType(allInteractions);
  for (size_t irxn=0; irxn<numinteractions; irxn++) {
    const Variable* arxnvar = GetNthVariableOfType(allInteractions, irxn);
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
  size_t numunknown = GetNumVariablesOfType(allUnknown);
  for (size_t form=0; form < numunknown; form++) {
    const Variable* formvar = GetNthVariableOfType(allUnknown, form);
    Parameter* param = sbmlmod->createParameter();
    param->setId(formvar->GetNameDelimitedBy(cc));
    if (formvar->GetDisplayName() != "") {
      param->setName(formvar->GetDisplayName());
    }
    switch(formvar->GetConstType()) {
    case constVAR:
      param->setConstant(true);
      break;
    case constCONST:
      param->setConstant(false);
      break;
    case constDEFAULT:
      break;
    }
  }
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

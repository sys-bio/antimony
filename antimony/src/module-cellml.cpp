#ifndef NCELLML

#include "cellmlx.h"
#include <TeLICeMService.hpp>
#include <IfaceAnnoTools.hxx>
#include <IfaceCUSES.hxx>
#include <CUSESBootstrap.hpp>

void Module::LoadCellMLModel(iface::cellml_api::Model* model, std::vector<iface::cellml_api::CellMLComponent*> top_components)
{
  assert(m_cellmlcomponent==NULL);
  if (m_cellmlmodel != NULL) {
    assert(false);
  }
  m_cellmlmodel = model;

  //Translate

  //Components become sub-modules
  for (size_t comp=0; comp<top_components.size(); comp++) {
    //Load the component as a submodule (which should already have been loaded by the registry in LoadCellML)
    string compname = GetNameAccordingToEncapsulationParent(top_components[comp], model);
    string cellmlmodname = GetModuleNameFrom(top_components[comp]);
    Variable* var = AddOrFindVariable(&compname);
    if(var->SetModule(&cellmlmodname)) {
      assert(false);
      return;
    }
  }
  SetIsMain(true);

  FixNames();  //In case the name of one of the modules is something like 'time'.
}

bool HasTimeUnits(iface::cellml_api::CellMLVariable* cmlvar) {
  RETURN_INTO_WSTRING(unitsName, cmlvar->unitsName());

  // Shortcut for a common case...
  if (unitsName == L"second")
    return true;

  // Otherwise, use CUSES to resolve the units. Optimisation note: It would be
  // better to make the CUSES once, and cache it against the model.
  RETURN_INTO_OBJREF(cb, iface::cellml_services::CUSESBootstrap, CreateCUSESBootstrap());
  RETURN_INTO_OBJREF(mod, iface::cellml_api::Model, cmlvar->modelElement());
  RETURN_INTO_OBJREF(cuses, iface::cellml_services::CUSES, cb->createCUSESForModel(mod, false));

  RETURN_INTO_OBJREF(cur, iface::cellml_services::CanonicalUnitRepresentation,
                     cuses->getUnitsByName(cmlvar, unitsName.c_str()));
  if (cur->length() != 1)
    return false;
  RETURN_INTO_OBJREF(bui, iface::cellml_services::BaseUnitInstance, cur->fetchBaseUnit(0));
  RETURN_INTO_OBJREF(bu, iface::cellml_services::BaseUnit, bui->unit());
  RETURN_INTO_WSTRING(uname, bu->name());
  return (uname == L"second");
}

void Module::LoadCellMLComponent(iface::cellml_api::CellMLComponent* component)
{
  assert(m_cellmlmodel==NULL);
 // assert(m_cellmlcomponent != NULL);

  //Variables
  RETURN_INTO_OBJREF(varset, iface::cellml_api::CellMLVariableSet, component->variables());
  RETURN_INTO_OBJREF(vsi, iface::cellml_api::CellMLVariableIterator, varset->iterateVariables());

  while (true) {
    RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable, vsi->nextVariable());
    if (cmlvar == NULL)
      break;

    RETURN_INTO_WSTRING(wvarName, cmlvar->name());
    std::string varName(makeUTF8(wvarName));
    Variable* antvar = AddOrFindVariable(&varName);

    //antvar->SetIsConst(false); //This forces it to be output in the Antimony script even if it's not otherwise used.
    RETURN_INTO_WSTRING(ivStr, cmlvar->initialValue());
    if (ivStr != L"") {
      Formula* formula = g_registry.NewBlankFormula();
      std::string ivStr8(makeUTF8(ivStr));
      setFormulaWithString(ivStr8, formula, this);
      antvar->SetFormula(formula);
    }

    //Put it in the module interface if it has one:
    if (cmlvar->publicInterface() != iface::cellml_api::INTERFACE_NONE ||
        cmlvar->privateInterface() != iface::cellml_api::INTERFACE_NONE) {
      AddVariableToExportList(antvar);
    }
  }

  //Reactions
  RETURN_INTO_OBJREF(rxnset, iface::cellml_api::ReactionSet, component->reactions());
  RETURN_INTO_OBJREF(rxni, iface::cellml_api::ReactionIterator, rxnset->iterateReactions());
  while (true) {
    RETURN_INTO_OBJREF(rxn, iface::cellml_api::Reaction, rxni->nextReaction());
    if (rxn == NULL)
      break;

    //parse the reaction;
    //reactions don't have names, so make up a new one for Antimony
    //LS DEBUG:  stopped coding here for now...
    //Variable* rxnvar = AddOrFindVariable(&cellmlname);
  }
  
  //Math
  RETURN_INTO_OBJREF(mathlist, iface::cellml_api::MathList, component->math());
  RETURN_INTO_OBJREF(mli, iface::cellml_api::MathMLElementIterator, mathlist->iterate());

  RETURN_INTO_OBJREF(ts, iface::cellml_services::TeLICeMService, CreateTeLICeMService());

  while (true)
  {
    RETURN_INTO_OBJREF(mathel, iface::mathml_dom::MathMLElement, mli->next());
    if (mathel == NULL)
      break;

    RETURN_INTO_OBJREF(nodes, iface::dom::NodeList, mathel->childNodes());
    uint32_t length = nodes->length();
    for (uint32_t i=0; i<length; i++) {
      RETURN_INTO_OBJREF(node, iface::dom::Node, nodes->item(i));
      DECLARE_QUERY_INTERFACE_OBJREF(input, node, mathml_dom::MathMLApplyElement);
      if (input != NULL) {
        RETURN_INTO_WSTRING(wmath, ts->showMaths(input));
        std::string infix(makeUTF8(wmath));

        cout << infix << endl;

        string variable, equation;
        variable.assign(infix, 0, infix.find('='));
        equation.assign(infix, infix.find('=')+1, infix.size());
        variable = Trim(variable);
        equation = Trim(equation);
        string origeq = equation;

        //Remove all the '{id: ...}' bits
        size_t idpos;
        while ((idpos = equation.find("{id:")) != string::npos) {
          equation.erase(idpos, equation.find("}", idpos)-idpos+1);
        }
        //Remove '{unit: ...}' bits (for now)
        while ((idpos = equation.find("{unit:")) != string::npos) {
          equation.erase(idpos, equation.find("}", idpos)-idpos+1);
        }
        //Remove '{base: ...}' bits
        while ((idpos = equation.find("{base:")) != string::npos) {
          equation.erase(idpos, equation.find("}", idpos)-idpos+1);
        }
        //Remove '$'--it's apparantly the way that TeLICeM notes variables that are also function names.
        // (We'll fix the name later ourselves with 'FixNames')
        while ((idpos = equation.find("$")) != string::npos) {
          equation.erase(idpos, 1);
        }
        while ((idpos = variable.find("$")) != string::npos) {
          variable.erase(idpos, 1);
        }

        //Handle piecewise equations
        if ((idpos = equation.find("piecewise")) != string::npos) {
          equation = CellMLPiecewiseToSBML(equation);
        }
        //Claim we can't handle definite integrals:
        if ((idpos = equation.find("definite_integral")) != string::npos) {
          g_registry.AddWarning("Unable to use the formula \"" + equation + "\" to define '" + variable + "' because Antimony does not handle definite integrals.");
          continue;
        }
        Formula* formula = g_registry.NewBlankFormula();
        setFormulaWithString(Trim(equation), formula, this);

        //Find out what variable we're assigning to, and how we're assigning to it.
        //Remove '{unit: ...}' bits (for now)
        while ((idpos = variable.find("{unit:")) != string::npos) {
          variable.erase(idpos, variable.find("}", idpos)-idpos+1);
        }
        vector<string> fullname;
        fullname.push_back(variable);
        Variable* var = GetVariable(fullname);
        if (var != NULL) {
          //Math is simple assignent rule
          if (var->SetAssignmentRule(formula)) {
            //Something went wrong
            //cout << "Unable to use the formula \"" << formula->ToDelimitedStringWithEllipses('.') << "\" (originally \"" << origeq << "\") to set the assignment rule for " << var->GetNameDelimitedBy('.') << ":  " << getLastError() << endl;
            string warning = "Unable to use the formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" to set the assignment rule for " + var->GetNameDelimitedBy('.') + ":  " + getLastError();
            g_registry.AddWarning(warning);
          }
        }
        else if (variable.find("d(") == 0 && variable.find(")/d(") != string::npos) {
          //Math is of the form dx/dy--if y is time, we can make this a rate rule.
          size_t timepos = variable.find(")/d(")+4;
          string maybetime;
          maybetime.assign(variable, timepos, variable.find(')', timepos)-timepos);
          std::wstring wtimevar(makeUTF16(maybetime));
          RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable,
                             varset->getVariable(wtimevar.c_str()));
          if (cmlvar && !HasTimeUnits(cmlvar)) {
            RETURN_INTO_WSTRING(wuname, cmlvar->unitsName());
            std::string uname(makeUTF8(wuname));
            string warning = "The units of \"" + maybetime + "\" ('" + uname + "') do not have 'seconds' as their base unit, so assuming this CellML model is trying to take the derivative of something with respect to some not-time element, we are not translating this derivative.";
            g_registry.AddWarning(warning);
            continue;
          }
          variable.assign(variable, 2, timepos-6);
          variable = Trim(variable);
          var = AddOrFindVariable(&variable);
          if (var->SetRateRule(formula)) {
            string warning = "Unable to use the formula \"" + formula->ToDelimitedStringWithEllipses('.') + "\" to set the rate rule for " + var->GetNameDelimitedBy('.') + ":  " + getLastError();
            g_registry.AddWarning(warning);
          }
        }
        else if (variable.find("del(") != string::npos) {
          //It's a partial differential equation.
          string warning = "Unable to translate an assignment to \"" + variable + "\" in the Antimony format because Antimony does not handle partial differential equations (though neither do existing CellML tools).";
          g_registry.AddWarning(warning);
        }
        else if (variable.find("selector(") != string::npos) {
          //It's vector or matrix math of some sort.
          string warning = "Unable to translate an assignment to \"" + variable + "\" in the Antimony format because Antimony does not handle vector or matrix algebra.";
          g_registry.AddWarning(warning);
        }
        else if (IsReal(variable)) {
          //It's some sort of algebraic rule.
          string warning = "Unable to translate the equation \"" + variable + " = " + equation + "\" because Antimony does not handle algebraic rules.";
          g_registry.AddWarning(warning);
        }
        else {
          //Unable to determine what kind of math we're talking about.
          string warning = "Unable to figure out how to translate an assignment to \"" + variable + "\" in the Antimony format.  This variable may have been left undefined in that component.";
          g_registry.AddWarning(warning);
        }

      }
      else {
        //string warning = "Child node " +  i + " of 'math' element not an 'apply' element";
      }
    }
  }

  //Containers (?)

  //And finally, fix names.
  FixNames();
}

void Module::SetCellMLChildrenAsSubmodules(iface::cellml_api::CellMLComponent* component) {
  //Iterate over 'encapsulation' children and make them submodules.
  RETURN_INTO_OBJREF(children, iface::cellml_api::CellMLComponentSet, component->encapsulationChildren());
  RETURN_INTO_OBJREF(childi, iface::cellml_api::CellMLComponentIterator, children->iterateComponents());

  while (true) {
    RETURN_INTO_OBJREF(child, iface::cellml_api::CellMLComponent,
                       childi->nextComponent());
    if (child != NULL)
      break;

    std::string cellmlname = GetNameAccordingToEncapsulationParent(child, m_cellmlmodel);
    //rv = child->GetName(cellmltext);
    //cellmlname = ToThinString(cellmltext.get());
    //FixName(cellmlname);

    string cellmlmodname = GetModuleNameFrom(child);
    Module* submod = g_registry.GetModule(cellmlmodname);

    submod->SetCellMLChildrenAsSubmodules(child); //Recursive!  This is so the submodels are all set up before we copy them.
    vector<string> fullname;
    fullname.push_back(cellmlname);
    Variable* foundvar = GetVariable(fullname);
    if (foundvar != NULL && !(foundvar->GetType()==varModule && m_childrenadded)) {
      cellmlname = cellmlname + "_mod";
    }

    //Save the name, since it's not obvious whether the "_mod" was added or not.
    char* id_s = child->objid();
    std::string compmodid(id_s);
    free(id_s);

    g_registry.m_cellmlnames.insert(make_pair(compmodid, cellmlname)); //Even if we've already added this submodule, each time it's imported, the submodule gets its own component ID, and they all need to go in here.
    if (!m_childrenadded) {
      Variable* var = AddOrFindVariable(&cellmlname);
      if(var->SetModule(&cellmlmodname)) {
        assert(false);
        return;
      }
    }
  }
  m_childrenadded = true; //Since this is recursive, we may call some multiply-imported submodules multiple times otherwise.
}


iface::cellml_api::Model* Module::GetCellMLModel()
{
  if (m_cellmlmodel==NULL) {
    CreateCellMLModel();
  }
  else {
    RETURN_INTO_WSTRING(wcellmltext, m_cellmlmodel->name());
    std::string cellmltext(makeUTF8(wcellmltext));
    if (cellmltext != m_modulename) {
      CreateCellMLModel();
    }
  }
  return m_cellmlmodel;
}

void Module::ReloadSubmodelVariables(const string& modulename)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* variable = m_variables[var];
    if (variable->GetType() == varModule) {
      Module* modcopy = variable->GetModule();
      Module* submod = g_registry.GetModule(modcopy->GetModuleName());
      submod->ReloadSubmodelVariables(submod->GetModuleName());
      modcopy->ReloadSubmodelVariables(modulename);
      modcopy->ResyncVariablesWith(submod, modulename, variable->GetName());
    }
  }
}

void Module::ResyncVariablesWith(const Module* twin, string modulename, vector<string> varname)
{
  assert (m_variables.size() <= twin->m_variables.size());
  for (size_t var = m_variables.size(); var<twin->m_variables.size(); var++) {
    //New variables
    Variable* newsubvar = twin->m_variables[var];
    Variable* newvar = new Variable(*newsubvar);
    for (size_t name=varname.size(); name>0; name--) {
      newvar->SetNewTopName(modulename, varname[name-1]);
    }
    //cout << "new subvar: " << ToStringFromVecDelimitedBy(newvar->GetName(), '.') << " for module " << ToStringFromVecDelimitedBy(m_variablename, '.') << endl;
    assert(newvar->GetType() != varModule);
    m_variables.push_back(newvar);
    StoreVariable(newvar);
  }
}

void Module::ReloadSubmodelConnections(Module* syncmod)
{
  for (size_t var=0; var<m_variables.size(); var++) {
    Variable* variable = m_variables[var];
    if (variable->GetType() == varModule) {
      Module* modcopy = variable->GetModule();
      Module* submod = g_registry.GetModule(modcopy->GetModuleName());
      assert(modcopy != submod);
      submod->ReloadSubmodelConnections(submod);
      modcopy->ReloadSubmodelConnections(syncmod);
      //cout << "reloading connections from " << submod->m_modulename << " to sync with " << variable->GetNameDelimitedBy('.') << endl;
      m_varmap.insert(submod->m_varmap.begin(), submod->m_varmap.end());
      for (size_t sync = modcopy->m_synchronized.size(); sync<submod->m_synchronized.size(); sync++) {
        //There are synchronizations in the ur-module that we didn't get when we copied it.
        vector<string> var1name = submod->m_synchronized[sync].first;
        vector<string> var2name = submod->m_synchronized[sync].second;
        for (size_t vn=variable->GetName().size(); vn>0; vn--) {
          var1name.insert(var1name.begin(), variable->GetName()[vn-1]);
          var2name.insert(var2name.begin(), variable->GetName()[vn-1]);
        }
        Variable* var1 = syncmod->GetVariable(var1name);
        Variable* var2 = syncmod->GetVariable(var2name);
        size_t numsynced = syncmod->m_synchronized.size();
        assert(var1 != NULL && var2 != NULL);
        if (var1->GetIsEquivalentTo(var2)) {
          //Already synchronized.
          continue;
        }
        if (!var1->Synchronize(var2)) {
          //This adds the synchronization to the local list instead of the submodel's list.  So, move it!
          assert(g_registry.GetModule(var1->GetNamespace()) == syncmod);
          assert(numsynced == syncmod->m_synchronized.size()-1);
          assert(syncmod->m_synchronized.size() > 0);
          pair<vector<string>, vector<string> > newsync = syncmod->m_synchronized[syncmod->m_synchronized.size()-1];
          syncmod->m_synchronized.pop_back();
          modcopy->m_synchronized.push_back(newsync);
          /*
          cout << ToStringFromVecDelimitedBy(var1name, '.') << " to "
               << ToStringFromVecDelimitedBy(var2name, '.') << ": " << endl;
          cout << ToStringFromVecDelimitedBy(var1->GetName(), '.') << " and "
               << ToStringFromVecDelimitedBy(var2->GetName(), '.') << " now synchronized";
          if (!var1->GetFormula()->IsEmpty()) {
            cout << ": " << var1->GetFormula()->ToDelimitedStringWithEllipses('.') << endl;
          }
          else {
            cout << "." << endl;
          }
          */
        }
        else {
          g_registry.AddWarning("In module '" + m_modulename + "', the variables " + var1->GetNameDelimitedBy('.') + " and " + var2->GetNameDelimitedBy('.') + " were unable to be set as equivalent:  " + g_registry.GetError());
          //This is tricky, because now we have to remove the main module's synchronization that set this up in the first place.
          vector<string> sync1name, sync2name;
          bool foundorig = false;
          if (var1->IsPointer()) {
            //cout << "var1 is pointer: " << var1->GetNameDelimitedBy('.') << endl;
            sync1name = var1->GetName();
            sync2name = var1->GetPointerName();
            //cout << "Looking for sync for " << ToStringFromVecDelimitedBy(sync1name, '.') << " and " << ToStringFromVecDelimitedBy(sync2name, '.') << endl;
            for (vector<pair<vector<string>, vector<string> > >::iterator sync = m_synchronized.begin();
                 sync != m_synchronized.end(); sync++) {
              //cout << "Found " << ToStringFromVecDelimitedBy(sync->first, '.') << " and " << ToStringFromVecDelimitedBy(sync->second, '.') << endl;
              if ((sync1name == sync->first && sync2name == sync->second) ||
                  (sync2name == sync->first && sync1name == sync->second)) {
                //cout << "Removing sync from " << m_modulename << ": " << ToStringFromVecDelimitedBy(sync1name, '.') << " with " << ToStringFromVecDelimitedBy(sync2name, '.') << endl;
                m_synchronized.erase(sync);
                foundorig = true;
                //cout << "Found original!" << endl;
                break;
              }
            }
          }
          if (!foundorig && var2->IsPointer()) {
            //cout << "var2 is pointer: " << var2->GetNameDelimitedBy('.') << endl;
            sync1name = var2->GetName();
            sync2name = var2->GetPointerName();
            for (vector<pair<vector<string>, vector<string> > >::iterator sync = m_synchronized.begin();
                 sync != m_synchronized.end(); sync++) {
              if ((sync1name == sync->first && sync2name == sync->second) ||
                  (sync2name == sync->first && sync1name == sync->second)) {
                //cout << "Removing sync from " << m_modulename << ": " << ToStringFromVecDelimitedBy(sync1name, '.') << " with " << ToStringFromVecDelimitedBy(sync2name, '.') << endl;
                m_synchronized.erase(sync);
                foundorig = true;
                //cout << "Found original!" << endl;
                break;
              }
            }
          }
          
          assert(foundorig);
        }
      }
    }
  }
  //Finalize(); //Re-finalize to update m_origvars.
}

//
//----------Creating CellML Models---------------
//

void Module::CreateCellMLModel()
{
  if (m_cellmlmodel != NULL) {
    if (m_cellmlcomponent != NULL) {
      m_cellmlcomponent = NULL;
    }
  }

  RETURN_INTO_OBJREF(boot, iface::cellml_api::CellMLBootstrap, CreateCellMLBootstrap());
  m_cellmlmodel =
    already_AddRefd<iface::cellml_api::Model>(boot->createModel(L"1.1"));

  DECLARE_QUERY_INTERFACE_OBJREF(cde, m_cellmlmodel, cellml_api::CellMLDOMElement);
  RETURN_INTO_OBJREF(de, iface::dom::Element, cde->domElement());
  RETURN_INTO_OBJREF(doc, iface::dom::Document, de->ownerDocument());

  std::wstring wname(makeUTF16(m_modulename));
  m_cellmlmodel->name(wname.c_str());

  //Create units

  //Create a component for all local variables
  AddCellMLComponentsTo(m_cellmlmodel, this);

  //Create encapsulation relationships
  AddEncapsulationTo(m_cellmlmodel);

  //Figure out which variable in each set of synced variables needs to be the 'canonical' one
  SetCanonicalVars(); //(uses m_syncedvars)

  //Create all connections
  AddConnections();

  //Add in the Math
  for (map<Variable*, vector<Variable*> >::iterator mapiter = m_syncedvars.begin();
       mapiter != m_syncedvars.end(); mapiter++) {
    AssignMathOnceFor(mapiter->second, doc);
  }

  //Add in the ODEs
  AddODEsTo(m_cellmlmodel, this, doc);
}

void Module::AddCellMLComponentsTo(iface::cellml_api::Model* model, Module* topmod)
{
  model->addElement(GetCellMLComponent(topmod));
  for (size_t var=0; var<m_variables.size(); var++) { 
    Variable* variable = m_variables[var];
    if (variable->GetType() == varModule) {
      variable->GetModule()->AddCellMLComponentsTo(model, topmod);
    }
  }
}

// Note: doesn't AddRef.
iface::cellml_api::CellMLComponent* Module::GetCellMLComponent(Module* topmod)
{
  if (m_cellmlcomponent == NULL) {
    CreateCellMLComponent(topmod);
  }
  return m_cellmlcomponent;
}

void Module::CreateCellMLComponent(Module* topmod)
{
  //Establish a unique name in CellML, which is a different namespace than Antimony (which can distinguish X.y from Z.y--in CelML, we can no longer call both 'y', and it's awkward to call everything 'X_y', etc.)
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
  topmod->AddUnique(m_variablename, name);
  m_cellmlcomponent =
    already_AddRefd<iface::cellml_api::CellMLComponent>(topmod->m_cellmlmodel->createComponent());
  std::wstring wname(makeUTF16(name));
  m_cellmlcomponent->name(wname.c_str());
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
      //The above all become CellML variables:
      AddNewVariableToCellML(variable, topmod->m_cellmlmodel);
      used = true;
      break;
    case varEvent:
    case varModule:
    case varStrand:
      //These all have no CellML equivalent (except Module, which is taken care of separately).
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

void Module::AddNewVariableToCellML(Variable* variable, iface::cellml_api::Model* model)
{
  vector<string> varname = variable->GetName();
  assert(varname.size()>0);
  RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable,
                     AddNewVariableToCellML(varname[varname.size()-1], model));
  variable->SetCellMLVariable(cmlvar);
}


iface::cellml_api::CellMLVariable* Module::AddNewVariableToCellML(string varname, iface::cellml_api::Model* model)
{
  assert(m_cellmlcomponent != NULL);
  return AddNewVariableToCellML(varname, m_cellmlcomponent, model);
}

iface::cellml_api::CellMLVariable* Module::AddNewVariableToCellML(string varname, iface::cellml_api::CellMLComponent* component, iface::cellml_api::Model* model)
{
  RETURN_INTO_OBJREF(cmlvarset, iface::cellml_api::CellMLVariableSet,
                     component->variables());

  std::wstring cmlvarst(makeUTF16(varname));

  RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable,
                     cmlvarset->getVariable(cmlvarst.c_str()));
  size_t varnum = 1;
  while (cmlvar != NULL) {
    //A variable with that name already exists; create a new one instead.
    cmlvarst = makeUTF16(varname + "_" + SizeTToString(varnum));
    RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable,
                       cmlvarset->getVariable(cmlvarst.c_str()));
    varnum++;
  }

  cmlvar = already_AddRefd<iface::cellml_api::CellMLVariable>
    (model->createCellMLVariable());
  component->addElement(cmlvar);
  cmlvar->name(cmlvarst.c_str());
  string nodim = "dimensionless";
  cmlvar->unitsName(makeUTF16(nodim).c_str());
  //cmlvar->publicInterface(iface::cellml_api::INTERFACE_OUT);
  //cmlvar->privateInterface(iface::cellml_api::INTERFACE_IN); //LS DEBUG: make sure the new version of this code survives somewhere.
  cmlvar->add_ref();
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
    //cout << "Help!  Nothing found for the variables synced to " << candidate->GetNameDelimitedBy('.');
  }
  return candidate;
}

bool Module::InUnique(string name)
{
  return (m_uniquenames.find(name) != m_uniquenames.end());
}

void Module::AddUnique(vector<string> fullname, string name)
{
  m_uniquenames.insert(name);
  m_cellmlnames.insert(make_pair(fullname, name));
}

string Module::GetCellMLNameOf(vector<string> fullname)
{
  assert(m_cellmlnames.find(fullname) != m_cellmlnames.end());
  return m_cellmlnames.find(fullname)->second;
}

void Module::AddEncapsulationTo(iface::cellml_api::Model* model)
{
  RETURN_INTO_OBJREF(group, iface::cellml_api::Group, model->createGroup());
  model->addElement(group);
  RETURN_INTO_OBJREF(relref, iface::cellml_api::RelationshipRef, model->createRelationshipRef());
  group->addElement(relref);
  relref->setRelationshipName(L"", L"encapsulation");
  /* LS DEBUG CELLML:  actually do this!
  vector<string> blank;
  RETURN_INTO_OBJREF(cr, iface::cellml_api::ComponentRef, GetComponentRef(m_cellmlmodel, GetCellMLNameOf(blank), this));
  group->addElement(cr);
  */
}

iface::cellml_api::ComponentRef* Module::GetComponentRef(iface::cellml_api::Model* model, std::string cmlname, Module* topmod)
{
  RETURN_INTO_OBJREF(cr, iface::cellml_api::ComponentRef, model->createComponentRef());
  cr->componentName(makeUTF16(cmlname).c_str());
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType() == varModule) {
      string subvarcmlname = topmod->GetCellMLNameOf(m_variables[var]->GetName());
      iface::cellml_api::ComponentRef* subcr = m_variables[var]->GetModule()->GetComponentRef(model, subvarcmlname, topmod);
      cr->addElement(subcr);
    }
  }
  return cr;
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

iface::cellml_api::CellMLVariable* Module::GetLinkedCMLVar(Variable* mod, const std::map<Variable*, iface::cellml_api::CellMLVariable* >& mod2linkedcellml)
{
  map<Variable*, iface::cellml_api::CellMLVariable* >::const_iterator branch = mod2linkedcellml.find(mod);
  if (branch==mod2linkedcellml.end()) {
    return NULL;
  }
  else {
    return branch->second;
  }
}

void Module::Connect(Variable* modin, Variable* canonmod, std::map<Variable*, iface::cellml_api::CellMLVariable*>& mod2linkedcellml, const std::map<Variable*, Variable*>& mod2var, const std::set<Variable*>& canonparents, const std::map<Variable*, Variable*>& tree)
{
  iface::cellml_api::CellMLVariable* cmlin = GetLinkedCMLVar(modin, mod2linkedcellml);
  if ( cmlin != NULL) {
    //We already connected this, so we're done!
    return;
  }
  Variable* canonvar = GetSyncedVariable(canonmod, mod2var);
  Variable* syncedvar = GetSyncedVariable(modin, mod2var);
  if (syncedvar == NULL) {
    vector<string> canonname = canonvar->GetName();
    cmlin = modin->GetModule()->AddNewVariableToCellML(canonname[canonname.size()-1], m_cellmlmodel);
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
    iface::cellml_api::CellMLVariable* cmlchild = GetLinkedCMLVar(potential_child, mod2linkedcellml);
    assert(cmlchild != NULL);
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
    iface::cellml_api::CellMLVariable* cmlsib = GetLinkedCMLVar(potential_sibling, mod2linkedcellml);
    assert(cmlsib != NULL);
    AddOneConnection(cmlin, cmlsib, td_SIDEWAYS);
  }
  else {
    //Option 3!
    Connect(inparent, canonmod, mod2linkedcellml, mod2var, canonparents, tree);
    iface::cellml_api::CellMLVariable* cmlparent = GetLinkedCMLVar(inparent, mod2linkedcellml);
    assert(cmlparent != NULL);
    AddOneConnection(cmlin, cmlparent, td_UP);
  }

  //Finally, put the new cmlin variable into the sync list so we only do this once:
  mod2linkedcellml.insert(make_pair(modin, cmlin));
}

void  Module::AddOneConnection(iface::cellml_api::CellMLVariable* varin, iface::cellml_api::CellMLVariable* varout, tree_direction td)
{
  switch(td) {
  case td_UP:
    varin->publicInterface(iface::cellml_api::INTERFACE_OUT);
    varout->privateInterface(iface::cellml_api::INTERFACE_IN);
    break;
  case td_DOWN:
    varin->privateInterface(iface::cellml_api::INTERFACE_OUT);
    varout->publicInterface(iface::cellml_api::INTERFACE_IN);
    break;
  case td_SIDEWAYS:
    varin->publicInterface(iface::cellml_api::INTERFACE_OUT);
    varout->publicInterface(iface::cellml_api::INTERFACE_IN);
    break;
  }
  iface::cellml_api::CellMLComponent* compin  = GetCellMLComponentOf(varin);
  iface::cellml_api::CellMLComponent* compout = GetCellMLComponentOf(varout);
  iface::cellml_api::Connection* connection = GetOrCreateConnectionFor(compin, compout, m_cellmlmodel);
  RETURN_INTO_OBJREF(mapvars, iface::cellml_api::MapVariables, m_cellmlmodel->createMapVariables());
  connection->addElement(mapvars);
  try
  {
    mapvars->firstVariable(varin);
    mapvars->secondVariable(varout);
  }
  catch (...)
  {
    mapvars->firstVariable(varout);
    mapvars->secondVariable(varin);
  }
}

void Module::AssignMathOnceFor(vector<Variable*> varlist, iface::dom::Document* doc)
{
  Variable* finalvar = varlist[0];
  const Formula* ia = finalvar->GetInitialAssignment();
  const Formula* ar = finalvar->GetAssignmentRuleOrKineticLaw();
  const Formula* rr = finalvar->GetRateRule();
  //'ia' and 'rr' may both exist and have been initially defined in different modules.  But that doesn't matter, since we need to define all three in the same CellML module, since that's the way they roll.
  Variable* targetvar = varlist[0]->GetCanonicalVariable();
  RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable, targetvar->GetCellMLVariable());
  const Variable* origtarget = targetvar->GetOriginal();
  vector<string> varname = origtarget->GetName();
  assert(varname.size()==1);
  if (!ia->IsEmpty()) {
    if (ia->IsDouble()) {
      std::wstring wiv(makeUTF16(ia->ToDelimitedStringWithEllipses('_')));
      cmlvar->initialValue(wiv.c_str());
      cout << "Successfully set initial value for " << targetvar->GetNameDelimitedBy('.') << endl;
    }
    else {
      //Have to create a new variable.
      string newvarname = varname[varname.size()-1] + "_init";
      std::wstring wiv(makeUTF16(newvarname));
      cmlvar->initialValue(wiv.c_str());
      Variable* tvarparent = targetvar->GetParentVariable();
      Module* tvarmod = this;
      if (tvarparent != NULL) {
        tvarmod = tvarparent->GetModule();
      }
      RETURN_INTO_OBJREF(initvar, iface::cellml_api::CellMLVariable, tvarmod->AddNewVariableToCellML(newvarname, m_cellmlmodel));
      //LS DEBUG:  didn't check to see if we renamed 'newvarname'
      string formula = newvarname + " = " + origtarget->GetInitialAssignment()->ToCellMLString(origtarget->GetStrandVars());
      if (!AddCellMLMathTo(formula, targetvar, doc)) {
        string warning = "Unable to initialize " + targetvar->GetNameDelimitedBy('.') + " through "+ newvarname + " (" + formula + ")";
        g_registry.AddWarning(warning);
      }
    }
  }
  if (!ar->IsEmpty()) {
    string formula = origtarget->GetAssignmentRuleOrKineticLaw()->ToCellMLString(origtarget->GetStrandVars());
    formula = varname[varname.size()-1] + " = " + formula;
    if (!AddCellMLMathTo(formula, targetvar, doc)) {
      string warning = "Unable to translate \"" + formula + "\" to CellML's MathML for the assignment rule.";
      g_registry.AddWarning(warning);
    }
  }
  if (!rr->IsEmpty()) {
    AddTimeFor(targetvar->GetCellMLVariable());
    const Variable* origtarget = targetvar->GetOriginal();
    vector<string> varname = origtarget->GetName();
    assert(varname.size()==1);
    string formula = origtarget->GetRateRule()->ToCellMLString(origtarget->GetStrandVars());
    formula = "d(" + varname[varname.size()-1] + ")/d(time) = " + formula;
    if (!AddCellMLMathTo(formula, targetvar, doc)) {
      string warning = "Unable to translate \"" + formula + "\" to CellML's MathML for the rate rule.";
      g_registry.AddWarning(warning);
    }
  }
}

bool Module::AddCellMLMathTo(string formula, Variable* targetvar, iface::dom::Document* doc)
{
  RETURN_INTO_OBJREF(cmlvar, iface::cellml_api::CellMLVariable, targetvar->GetCellMLVariable());
  RETURN_INTO_OBJREF(cmlcomp, iface::cellml_api::CellMLComponent, GetCellMLComponentOf(cmlvar));
  return AddCellMLMathTo(formula, cmlcomp, doc);
}

bool Module::AddCellMLMathTo(std::string formula, iface::cellml_api::CellMLComponent* cmlcomp, iface::dom::Document* doc)
{
  RETURN_INTO_OBJREF(ts, iface::cellml_services::TeLICeMService, CreateTeLICeMService());
  std::wstring wform(makeUTF16(formula));
  RETURN_INTO_OBJREF(tmr, iface::cellml_services::TeLICeMMathResult,
                     ts->parseMaths(doc, wform.c_str()));
  // XXX it would be good to check tmr->errorMessage() and log the error - Andrew Miller
  RETURN_INTO_OBJREF(math, iface::mathml_dom::MathMLElement,
                      tmr->mathResult());
  if (math == NULL)
    return false;

  cmlcomp->addMath(math);
  return true;
}

void Module::AddTimeFor(iface::cellml_api::CellMLVariable* cmlvar)
{
  RETURN_INTO_OBJREF(cmlcomp, iface::cellml_api::CellMLComponent, GetCellMLComponentOf(cmlvar));
  AddTimeTo(cmlcomp);
}

iface::cellml_api::CellMLVariable* Module::AddTimeTo(iface::cellml_api::CellMLComponent* cmlcomp)
{
  RETURN_INTO_OBJREF(cmlvarset, iface::cellml_api::CellMLVariableSet, cmlcomp->variables());
  RETURN_INTO_OBJREF(time, iface::cellml_api::CellMLVariable, cmlvarset->getVariable(L"time"));

  if (time != NULL) {
    //Already exists!
    return time;
  }
  assert(m_cellmlmodel != NULL);

  time = already_AddRefd<iface::cellml_api::CellMLVariable>
    (m_cellmlmodel->createCellMLVariable());
  cmlcomp->addElement(time);
  time->name(L"time");
  string nodim = "dimensionless";
  time->unitsName(makeUTF16(nodim).c_str());

  RETURN_INTO_OBJREF(parent, iface::cellml_api::CellMLComponent, cmlcomp->encapsulationParent());
  if (parent != NULL) {
    RETURN_INTO_OBJREF(ptime, iface::cellml_api::CellMLVariable, AddTimeTo(parent));
    AddOneConnection(time, ptime, td_UP);
  }

  time->add_ref();
  return time;
}

void Module::AddODEsTo(iface::cellml_api::Model* model, Module* topmod, iface::dom::Document* doc)
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
    ratemod->AddRateRuleInvolving(*speciter, form, involvedrxns, doc);
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
  map<Variable*, iface::cellml_api::CellMLVariable*> mod2linkedcellml;
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
  iface::cellml_api::CellMLVariable* canoncml = GetSyncedVariable(canonmod, mod2var)->GetCellMLVariable();
  mod2linkedcellml.insert(make_pair(canonmod, canoncml));

  //Now go through the list and connect everything.  As things are linked, mod2linkedcellml is updated so we don't duplicate effort.
  for (size_t var=0; var<varlist.size(); var++) {
    Connect(varlist[var]->GetParentVariable(), canonmod, mod2linkedcellml, mod2var, canonparents, tree);
  }
}

void Module::AddRateRuleInvolving(Variable* species, Formula form, set<Variable*> involvedrxns, iface::dom::Document* doc)
{
  string localname = FindOrCreateLocalVersionOf(species);

  for (set<Variable*>::iterator involvedit=involvedrxns.begin(); involvedit != involvedrxns.end(); involvedit++) {
    string localrxn = FindOrCreateLocalVersionOf(*involvedit);

    form.UseInstead(localrxn, *involvedit);
  }
  string infix = "d(" + localname + ")/d(time) = " + form.ToCellML();
  AddTimeTo(m_cellmlcomponent);
  if (!AddCellMLMathTo(infix, m_cellmlcomponent, doc)) {
    string warning = "Unable to translate \"" + infix + "\" to CellML's MathML for the rate rule.";
    g_registry.AddWarning(warning);
  }
}

string Module::FindOrCreateLocalVersionOf(Variable* variable)
{
  iface::cellml_api::CellMLVariable* localvar;
  for (size_t var=0; var<m_variables.size(); var++) {
    if (variable->GetSameVariable() == m_variables[var]->GetSameVariable()) {
      vector<string> varname = m_variables[var]->GetName();
      //assert(varname.size()==1); //Not true!  Names have *this* module's name in the front.
      localvar = m_variables[var]->GetCellMLVariable();
      return (varname[varname.size()-1]);
    }
  }
  for (size_t var=0; var<m_variables.size(); var++) {
    if (m_variables[var]->GetType()==varModule) {
      iface::cellml_api::CellMLVariable* subvar = NULL;
      string foundvar = m_variables[var]->GetModule()->FindOrCreateLocalVersionOf(variable);
      if (foundvar != "") {
        //The variable was indeed in this list.  Create a local copy (in CellML) and sync it.
        vector<string> varname;
        varname.push_back(foundvar);
        while (GetVariable(varname) != NULL) {
          foundvar = m_variables[var]->GetModule()->GetModuleName() + "_" + foundvar;
          varname[0] = foundvar;
        }
        localvar = AddNewVariableToCellML(foundvar, m_cellmlmodel);
        AddOneConnection(localvar, subvar, td_DOWN);
        return foundvar;
      }
    }
  }
  return "";
}

#endif

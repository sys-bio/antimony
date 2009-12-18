#ifndef NCELLML

#include "cellml-opencell/MathMLInputServices.h"
#include "ICellMLInputServices.h"
#include <nsStringAPI.h>
#include <nsDebug.h>
#include <nsCOMPtr.h>
#include <nsServiceManagerUtils.h>

#define CELLML_BOOTSTRAP_CONTRACTID "@cellml.org/cellml-bootstrap;1"

void Module::LoadCellMLModel(nsCOMPtr<cellml_apiIModel> model)
{
  assert(m_cellmlcomponent==NULL);
  if (m_cellmlmodel != NULL) {
    assert(false); 
  }
  m_cellmlmodel = model;

  //Translate
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  //Components become sub-modules
  nsCOMPtr<cellml_apiICellMLComponentSet> components;
  rv = m_cellmlmodel->GetLocalComponents(getter_AddRefs(components));
  nsCOMPtr<cellml_apiICellMLComponentIterator> cmpi;
  rv = components->IterateComponents(getter_AddRefs(cmpi));
  nsCOMPtr<cellml_apiICellMLComponent> component;
  rv = cmpi->NextComponent(getter_AddRefs(component));
  while (component != NULL) {
    //Load the component as a submodule (which should already have been loaded by the registry in LoadCellML)
    rv = component->GetName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    string cellmlmodname = "cellmlmod_" + cellmlname;
    Variable* var = AddOrFindVariable(&cellmlname);
    if(var->SetModule(&cellmlmodname)) {
      assert(false);
      return;
    }
    rv = cmpi->NextComponent(getter_AddRefs(component));
  }

  //Imports also become sub-modules
  nsCOMPtr<cellml_apiICellMLImportSet> imports;
  rv = m_cellmlmodel->GetImports(getter_AddRefs(imports));
  nsCOMPtr<cellml_apiICellMLImportIterator> impi;
  rv = imports->IterateImports(getter_AddRefs(impi));
  nsCOMPtr<cellml_apiICellMLImport> import;
  rv = impi->NextImport(getter_AddRefs(import));
  while (import != NULL) {
    nsCOMPtr<cellml_apiIImportComponentSet> impcomponents;
    rv = import->GetComponents(getter_AddRefs(impcomponents));
    nsCOMPtr<cellml_apiIImportComponentIterator> icmpi;
    rv = impcomponents->IterateImportComponents(getter_AddRefs(icmpi));
    nsCOMPtr<cellml_apiIImportComponent> impcomponent;
    rv = icmpi->NextImportComponent(getter_AddRefs(impcomponent));
    while (impcomponent != NULL) {
      //Load the imported component as a submodules, too.
      rv = impcomponent->GetName(cellmltext);
      cellmlname = ToThinString(cellmltext.get());
      rv = impcomponent->GetComponentRef(cellmltext);
      string cellmlmodname = ToThinString(cellmltext.get());
      Variable* var = AddOrFindVariable(&cellmlname);
      if(var->SetModule(&cellmlmodname)) {
        assert(false);
        return;
      }
      rv = icmpi->NextImportComponent(getter_AddRefs(impcomponent));
    }
    rv = impi->NextImport(getter_AddRefs(import));
  }
  //Now go through them again to get the connections.  I know, right?
  rv = imports->IterateImports(getter_AddRefs(impi));
  rv = impi->NextImport(getter_AddRefs(import));
  while (import != NULL) {
    nsCOMPtr<cellml_apiIConnectionSet> impconnections;
    rv = import->GetImportedConnections(getter_AddRefs(impconnections));
    LoadConnections(impconnections);
    rv = impi->NextImport(getter_AddRefs(import));
  }
  //And then get the main model's connections
  nsCOMPtr<cellml_apiIConnectionSet> connections;
  rv = model->GetConnections(getter_AddRefs(connections));
  LoadConnections(connections);
}

void Module::LoadConnections(nsCOMPtr<cellml_apiIConnectionSet> connections)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  nsCOMPtr<cellml_apiIConnectionIterator> coni;
  rv = connections->IterateConnections(getter_AddRefs(coni));
  nsCOMPtr<cellml_apiIConnection> connection;
  rv = coni->NextConnection(getter_AddRefs(connection));
  while (connection != NULL) {
    nsCOMPtr<cellml_apiIMapComponents> compmap;
    rv = connection->GetComponentMapping(getter_AddRefs(compmap));
    rv = compmap->GetFirstComponentName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    vector<string> varname;
    varname.push_back(cellmlname);
    Variable* firstmod = GetVariable(varname);
    assert(firstmod!=NULL);
    rv = compmap->GetSecondComponentName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    varname.clear();
    varname.push_back(cellmlname);
    Variable* secondmod = GetVariable(varname);
    //LS DEBUG:  The above code will fail if there is more than one module with the same name.
    nsCOMPtr<cellml_apiIMapVariablesSet> mvs;
    rv = connection->GetVariableMappings(getter_AddRefs(mvs));
    nsCOMPtr<cellml_apiIMapVariablesIterator> mvsi;
    rv = mvs->IterateMapVariables(getter_AddRefs(mvsi));
    nsCOMPtr<cellml_apiIMapVariables> mapvars;
    rv = mvsi->NextMapVariable(getter_AddRefs(mapvars));
    while (mapvars != NULL) {
      rv = mapvars->GetFirstVariableName(cellmltext);
      cellmlname = ToThinString(cellmltext.get());
      Variable* firstvar = firstmod->GetSubVariable(&cellmlname);
      assert(firstvar != NULL);
      rv = mapvars->GetSecondVariableName(cellmltext);
      cellmlname = ToThinString(cellmltext.get());
      Variable* secondvar = secondmod->GetSubVariable(&cellmlname);
      firstvar->Synchronize(secondvar);
      //LS NOTE: Unlike the above code, this should work regardless of namespace if we get the module right in the first place.
      rv = mvsi->NextMapVariable(getter_AddRefs(mapvars));
    }
    rv = coni->NextConnection(getter_AddRefs(connection));
  }
}

bool HasTimeUnits(nsCOMPtr<cellml_apiICellMLVariable> cmlvar) {
  nsresult rv;
  nsString cellmltext;
  rv = cmlvar->GetUnitsName(cellmltext);
  if (cellmltext == ToNSString("second")) return true;
  nsCOMPtr<cellml_apiIUnits> units;
  rv = cmlvar->GetUnitsElement(getter_AddRefs(units));
  if (units==NULL) return false;
  nsCOMPtr<cellml_apiIUnitSet> unitset;
  rv = units->GetUnitCollection(getter_AddRefs(unitset));
  nsCOMPtr<cellml_apiIUnitIterator> uniti;
  rv = unitset->IterateUnits(getter_AddRefs(uniti));
  nsCOMPtr<cellml_apiIUnit> unit;
  rv = uniti->NextUnit(getter_AddRefs(unit));
  while (unit != NULL) {
    rv = unit->GetUnits(cellmltext);
    if (cellmltext == ToNSString("second")) return true;
    rv = uniti->NextUnit(getter_AddRefs(unit));
  }
  return false;
}

void Module::LoadCellMLComponent(nsCOMPtr<cellml_apiICellMLComponent> component)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  assert(m_cellmlmodel==NULL);
  if (m_cellmlcomponent != NULL) {
    assert(false);
  }
  //Variables
  nsCOMPtr<cellml_apiICellMLVariableSet> varset;
  rv = component->GetVariables(getter_AddRefs(varset));
  nsCOMPtr<cellml_apiICellMLVariableIterator> vsi;
  rv = varset->IterateVariables(getter_AddRefs(vsi));
  nsCOMPtr<cellml_apiICellMLVariable> cmlvar;
  rv = vsi->NextVariable(getter_AddRefs(cmlvar));
  while (cmlvar != NULL) {
    rv = cmlvar->GetName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    Variable* antvar = AddOrFindVariable(&cellmlname);
    antvar->SetIsConst(false); //This forces it to be output in the Antimony script even if it's not otherwise used.
    rv = cmlvar->GetInitialValue(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    if (cellmlname != "") {
      Formula* formula = g_registry.NewBlankFormula();
      setFormulaWithString(cellmlname, formula);
      antvar->SetFormula(formula);
    }
    rv = vsi->NextVariable(getter_AddRefs(cmlvar));
  }

  //Reactions
  nsCOMPtr<cellml_apiIReactionSet> rxnset;
  rv = component->GetReactions(getter_AddRefs(rxnset));
  nsCOMPtr<cellml_apiIReactionIterator> rxni;
  rv = rxnset->IterateReactions(getter_AddRefs(rxni));
  nsCOMPtr<cellml_apiIReaction> rxn;
  rv = rxni->NextReaction(getter_AddRefs(rxn));
  while (rxn != NULL) {
    //parse the reaction;
    //reactions don't have names, so make up a new one for Antimony
    //LS DEBUG:  stopped coding here for now...
    //Variable* rxnvar = AddOrFindVariable(&cellmlname);
    rv = rxni->NextReaction(getter_AddRefs(rxn));
  }
  
  //Math
  nsCOMPtr<cellml_apiIMathContainer> mc(do_QueryInterface(component));
  nsCOMPtr<cellml_apiIMathList> mathlist;
  rv = mc->GetMath(getter_AddRefs(mathlist));
  nsCOMPtr<cellml_apiIMathMLElementIterator> mli;
  rv = mathlist->Iterate(getter_AddRefs(mli));
  nsCOMPtr<mathml_domIMathMLElement> mathel;
  rv = mli->Next(getter_AddRefs(mathel));
  while(mathel != NULL) {
    nsCOMPtr<domINodeList> nodes;
    rv = mathel->GetChildNodes(getter_AddRefs(nodes));
    PRUint32 length;
    rv = nodes->GetLength(&length);
    for (PRUint32 i=0; i<length; i++) {
      nsCOMPtr<domINode> node;
      rv = nodes->Item(i, getter_AddRefs(node));
      nsCOMPtr<mathml_domIMathMLApplyElement> input(do_QueryInterface(node, &rv));
      if (input != NULL) {
        nsCString indent;
        indent = "";
        nsCString cinfix;
        MathMLInputServices mmlis;
        rv = mmlis.MathMLToInputFormat(input, NULL, indent, cinfix);
        string infix;
        infix = cinfix.get();
        string variable, equation;
        variable.assign(infix, 0, infix.find('='));
        equation.assign(infix, infix.find('=')+1, infix.size());

        //Remove all the '{id: ...}' bits
        size_t idpos;
        while ((idpos = equation.find("{id:")) != string::npos) {
          equation.erase(idpos, equation.find("}", idpos)-idpos+1);
        }
        //Remove '{unit: ...}' bits (for now)
        while ((idpos = equation.find("{unit:")) != string::npos) {
          equation.erase(idpos, equation.find("}", idpos)-idpos+1);
        }
        Formula* formula = g_registry.NewBlankFormula();
        setFormulaWithString(Trim(equation), formula);

        //Find out what variable we're assigning to, and how we're assigning to it.
        variable = Trim(variable);
        vector<string> fullname;
        fullname.push_back(variable);
        Variable* var = GetVariable(fullname);
        if (var != NULL) {
          //Math is simple assignent rule
          if (var->SetAssignmentRule(formula)) {
            //Something went wrong
            cout << "Unable to use the formula \"" << formula->ToDelimitedStringWithEllipses('.') << "\" to set the assignment rule for " << var->GetNameDelimitedBy('.') << endl;
          }
        }
        else if (variable.find("d(") == 0 && variable.find(")/d(") != string::npos) {
          //Math is of the form dx/dy--if y is time, we can make this a rate rule.
          size_t timepos = variable.find(")/d(")+4;
          string maybetime;
          maybetime.assign(variable, timepos, variable.find(')', timepos)-timepos);
          cellmltext = ToNSString(maybetime);
          rv = varset->GetVariable(cellmltext, getter_AddRefs(cmlvar));
          if (cmlvar && !HasTimeUnits(cmlvar)) {
            cout << "Units of \"" << maybetime << "\" are not time units, so CellML is trying to take the derivative of something with respect to some not-time element.  Which we don't know how to deal with, so we're punting." << endl;
            continue;
          }
          variable.assign(variable, 2, timepos-6);
          var = AddOrFindVariable(&variable);
          if (var->SetRateRule(formula)) {
            cout << "Unable to use the formula \"" << formula->ToDelimitedStringWithEllipses('.') << "\" to set the rate rule for " << var->GetNameDelimitedBy('.') << endl;
          }
        }
        else {
          //Unable to determine what kind of math we're talking about.
          cout << "Unable to figure out how to translate an assignment to \"" << variable << "\" in the Antimony format." << endl;
          
        }

        /*
        cout << "original:  " << cinfix.get() << endl;
        if (var != NULL) {
          cout << "antimony:  " << var->GetNameDelimitedBy('.');
          formula_type ftype = var->GetFormulaType();
          switch(ftype) {
          case formulaASSIGNMENT:
            cout << " := ";
            break;
          case formulaRATE:
            cout << "' = " << var->GetRateRule()->ToDelimitedStringWithEllipses('.') << endl;
            if (!var->GetFormula()->IsEmpty()) {
              cout << "           " << var->GetNameDelimitedBy('.') << "  = ";
            }
            break;
          case formulaINITIAL:
            cout << " = ";
            break;
          case formulaKINETIC:
          case formulaTRIGGER:
            assert(false); //These don't exist in CellML
            break;
          }
          cout << var->GetFormula()->ToDelimitedStringWithEllipses('.') << endl;
        }
        else {
          cout << "(No Antimony version available)" << endl;
        }
        */
      }
      else {
        //cout << "Child node " <<  i << " of 'math' element not an 'apply' element" << endl;
      }
    }
    rv = mli->Next(getter_AddRefs(mathel));
  }

  //Containers (?)
}

const nsCOMPtr<cellml_apiIModel> Module::GetCellMLModel()
{
  if (m_cellmlmodel==NULL) {
    CreateCellMLModel();
  }
  else {
    nsString cellmltext;
    m_cellmlmodel->GetName(cellmltext);
    if (ToThinString(cellmltext.get()) != m_modulename) {
      CreateCellMLModel();
    }
  }
  return m_cellmlmodel;
}

void Module::CreateCellMLModel()
{
  nsresult rv;
  nsString cellmltext;
  wstring cellmlwstring;

  if (m_cellmlmodel != NULL) {
    if (m_cellmlcomponent != NULL) {
      m_cellmlcomponent = NULL;
    }
  }

  nsCOMPtr<cellml_apiICellMLBootstrap> boot(do_GetService(CELLML_BOOTSTRAP_CONTRACTID, &rv));
  NS_ENSURE_SUCCESS(rv, );
  rv = boot->CreateModel(NS_LITERAL_STRING("1.1"), getter_AddRefs(m_cellmlmodel));
  NS_ENSURE_SUCCESS(rv, );
  nsCOMPtr<cellml_apiICellMLComponentSet> components;
  rv = m_cellmlmodel->GetLocalComponents(getter_AddRefs(components));

  cellmltext = ToNSString(m_modulename);
  m_cellmlmodel->SetName(cellmltext);
  //Create units

  //Create a component for all local variables
  m_cellmlcomponent = CreateCellMLComponentFor(m_cellmlmodel);
  m_cellmlmodel->AddElement(m_cellmlcomponent);

  //Create all connections

  //Create groups (?)
}

nsCOMPtr<cellml_apiICellMLComponent> Module::CreateCellMLComponentFor(nsCOMPtr<cellml_apiIModel> model)
{
  nsCOMPtr<cellml_apiICellMLComponent> newc;
  for (size_t var=0; var<m_variables.size(); var++) { 
    Variable* variable = m_variables[var];
    switch(variable->GetType()) {
    case varModule:
      model->AddElement(variable->GetModule()->CreateCellMLComponentFor(model));
      break;
    default:
      break;
      //LS DEBUG:  add stuff here
    }
  }
  return newc;
}

#endif

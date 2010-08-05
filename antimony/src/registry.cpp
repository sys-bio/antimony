#include <cassert>
#include <vector>
#include <string>
#include <cassert>
#include <cstdlib>

#include "formula.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "registry.h"
#include "sbmlx.h"

#include "stringx.h"
#include "variable.h"

extern int yylloc_first_line;
extern int yylloc_last_line;
extern std::vector<int> yylloc_last_lines;

using namespace std;

#ifndef NCELLML
#include "cellmlx.h"
#include <nsXPCOM.h>
#include <nsIComponentManager.h>
#include <nsComponentManagerUtils.h>
#endif

Registry::Registry()
  : m_oldinputs(),
    m_files(),
    m_variablenames(),
    m_functions(),
    m_storedvars(),
    m_storedformulas(),
    m_modules(),
    m_modulemap(),
    m_currentModules(),
    m_currentReactantLists(),
    m_currentImportedModule(),
    m_workingstrand(),
    m_currentEvent(),
    m_cc('_'),
    m_error(),
    m_oldmodules(),
    m_olduserfunctions(),
    m_oldmodulemaps(),
    input(NULL)
{
  string main = MAINMODULE;
  NewCurrentModule(&main);
  SetupFunctions();

#ifndef NCELLML
  nsresult rv;
  // Initialize XPCOM and check for failure ...
  rv = NS_InitXPCOM2(nsnull, nsnull, nsnull);
  if ( NS_FAILED(rv) )
  {
    printf("Calling NS_InitXPCOM returns [%x].\n", rv);
    return;
  }

  nsCOMPtr<cellml_apiICellMLBootstrap> foo = do_CreateInstance(CELLML_BOOTSTRAP_CONTRACTID, &rv);
  if ( NS_FAILED(rv) )
  {
    ostringstream warning;
    warning << "Creating a cellml bootstrap instance returns " << rv << ":  your working directory must be the one with the 'components/' subdirectory.  I know, right?  Sigh.";
    g_registry.AddWarning(warning.str());
    return;
  }

#endif
}

Registry::~Registry()
{
  FreeVariables();
  FreeFormulas();

#ifndef NCELLML
  NS_ShutdownXPCOM(nsnull);
#endif
}

void Registry::ClearModules()
{
  while (!SwitchToPreviousFile()) {}
  if (input) {
    //input->close(); //LS DEBUG
    input->clear();
    delete input;
  }
  m_files.clear();
  m_modules.clear();
  m_modulemap.clear();
  m_currentModules.clear();
  m_currentReactantLists.clear();
  m_currentImportedModule.clear();
  m_workingstrand.Clear();
  m_currentEvent.clear();
  m_error.clear();
  m_userfunctions.clear();
  m_userfunctionnames.clear();
  m_isfunction = false;
  string main = MAINMODULE;
  NewCurrentModule(&main);
}

void Registry::FreeVariables()
{
  for (set<Variable*>::iterator var=m_storedvars.begin(); var!=m_storedvars.end(); var++) {
    delete *var;
  }
  m_storedvars.clear();
}

void Registry::FreeFormulas()
{
  for (set<Formula*>::iterator form=m_storedformulas.begin(); form!=m_storedformulas.end(); form++) {
    delete *form;
  }
  m_storedformulas.clear();
}

void Registry::ClearAll()
{
  m_oldmodules.clear();
  m_oldmodulemaps.clear();
  m_olduserfunctions.clear();
  FreeVariables();
  FreeFormulas();
  ClearModules();
}

//Return values:  1: antimony, unread 2: SBML, read
int Registry::OpenString(string model)
{
#ifndef NSBML
  //Try opening as SBML:
  SBMLDocument* document = readSBMLFromString(model.c_str());
  int sbmlcheck = CheckAndAddSBMLIfGood(document);
  delete document;
  if (sbmlcheck==2) return 2;
#endif
  if (model[model.size()-1] != '\n') {
    model.push_back('\n');
  }
  m_files.push_back("");
  if (input != NULL) {
    m_oldinputs.push_back(input);
  }
  istringstream* inputstring = new istringstream(model);
  yylloc_last_lines.push_back(yylloc_last_line);
  yylloc_last_line = 1;
  yylloc_first_line = 1;
  input = inputstring;
  return 1;
}

//Return values:  0: failure, 1: antimony, unread 2: SBML, read
int Registry::OpenFile(const string& filename)
{
#ifndef NSBML
  //Try opening as SBML:
  SBMLDocument* document = readSBML(filename.c_str());
  int sbmlcheck = CheckAndAddSBMLIfGood(document);
  delete document;
  if (sbmlcheck==2) return 2;
#endif
  m_files.push_back(filename);
  if (input != NULL) {
    m_oldinputs.push_back(input);
  }
  ifstream* inputfile = new ifstream;
  input = inputfile;
  inputfile->open(filename.c_str(), ios::in);
  if (!inputfile->is_open()) {
    m_files.pop_back();
    string error = "Could not open \"";
    error += filename;
    error += "\".  "
      "Please check that this file:\n" 
      "	1) exists in directory that antimony is being run from,\n"
      "	2) is read enabled, and\n"
      "	3) is not in use by another program.\n";
    SetError(error);
    return 0;
  }

  if (!inputfile->good())
  {
    m_files.pop_back();
    string error = "Input file ";
    error += filename;
    error += " is open, but not able to be read from.  This should not happen, and is probably a programming error on our part, but just in case, check the permissions on the file and try again.  If that still does not work, contact us letting us know how you got this error.";
    SetError(error);
    return 0;
  }
  yylloc_last_lines.push_back(yylloc_last_line);
  yylloc_last_line = 1;
  yylloc_first_line = 1;
  return 1;
}

#ifndef NSBML
int Registry::CheckAndAddSBMLIfGood(SBMLDocument* document)
{
  document->setConsistencyChecks(LIBSBML_CAT_UNITS_CONSISTENCY, false);
  document->checkConsistency();
  SBMLErrorLog* log = document->getErrorLog();
  if (log->getNumFailsWithSeverity(2) == 0 && log->getNumFailsWithSeverity(3) == 0) {
    //It's a valid SBML file.
    const Model* sbml = document->getModel();
    string sbmlname = getNameFromSBMLObject(sbml, "file");
    if (sbmlname != MAINMODULE) {
      while (NewCurrentModule(&sbmlname)) {
        //Duplicated module name
        sbmlname += "_";
      }
    }
    CurrentModule()->LoadSBML(document);
    if (sbmlname != MAINMODULE) {
      RevertToPreviousModule();
    }
    return 2;
  }
  return 0;
}
#endif  

#ifndef NCELLML

#include "cellmlx.h"

#define CEVAS_BOOTSTRAP_CONTRACTID "@cellml.org/cevas-bootstrap;1"

bool Registry::LoadCellML(nsCOMPtr<cellml_apiIModel> model)
{
  if (model == NULL) return true;
  nsresult rv;
  nsString cellmltext;
  string cellmlname;
  nsCOMPtr<cellml_servicesICeVASBootstrap> cevasboot(do_GetService(CEVAS_BOOTSTRAP_CONTRACTID, &rv));
  NS_ENSURE_SUCCESS(rv, true);

  nsCOMPtr<cellml_servicesICeVAS> cevas;
  rv = cevasboot->CreateCeVASForModel(model, getter_AddRefs(cevas));
  if (NS_FAILED(rv)) {
    nsString error;
    cevas->GetModelError(error);
    SetError("Error reading CellML model:  " + ToThinString(error.get()));
    return true;
  }
  nsCOMPtr<cellml_apiICellMLComponentIterator> cmpi;
  rv = cevas->IterateRelevantComponents(getter_AddRefs(cmpi));
  nsCOMPtr<cellml_apiICellMLComponent> component;
  rv = cmpi->NextComponent(getter_AddRefs(component));
  int numcomps=0;
  vector<nsCOMPtr<cellml_apiICellMLComponent> > top_components;
  while (component != NULL) {
    numcomps++;
    //Each CellML 'component' becomes its own Antimony 'module'
    cellmlname = GetModuleNameFrom(component);
    FixName(cellmlname);
    Module* mod = GetModule(cellmlname);
    if (mod == NULL) {
      while (NewCurrentModule(&cellmlname)) {
        cellmlname += "_";
      }
      CurrentModule()->LoadCellMLComponent(component);
      RevertToPreviousModule();
    }
    else {
      //It's either a multiply-imported component, or a component with an identical name.
    }
    nsCOMPtr<cellml_apiICellMLComponent> parent;
    rv = component->GetEncapsulationParent(getter_AddRefs(parent));
    if (parent == NULL) {
      top_components.push_back(component);
    }
    rv = cmpi->NextComponent(getter_AddRefs(component));
  }
  if (numcomps == 0) {
    SetError("No components found in this CellML model.");
    return true;
  }

  //Now loop through all the components again, this time setting up 'encapsulation' for the submodules
  for (size_t topnum = 0; topnum<top_components.size(); topnum++) {
    component = top_components[topnum];
    rv = component->GetName(cellmltext);
    cellmlname = GetModuleNameFrom(component);
    Module* mod = GetModule(cellmlname);
    assert(mod != NULL);
    mod->SetCellMLChildrenAsSubmodules(component); // <- Here's where the work happens
  }

  //Now create a master model that contains only contain the top_components.
  rv = model->GetName(cellmltext);
  cellmlname = ToThinString(cellmltext.get());
  FixName(cellmlname);
  cellmlname += "__" MAINMODULE;
  while (NewCurrentModule(&cellmlname)) {
    //Failure - duplicated name
    cellmlname += "_";
  }
  CurrentModule()->LoadCellMLModel(model, top_components);

  //Now intercolate the connections into the modules.  First, get the connections from the imports:
  nsCOMPtr<cellml_apiICellMLImportSet> imports;
  rv = model->GetImports(getter_AddRefs(imports));
  nsCOMPtr<cellml_apiICellMLImportIterator> impi;
  rv = imports->IterateImports(getter_AddRefs(impi));
  nsCOMPtr<cellml_apiICellMLImport> import;
  rv = impi->NextImport(getter_AddRefs(import));
  while (import != NULL) {
    nsCOMPtr<cellml_apiIConnectionSet> impconnections;
    rv = import->GetImportedConnections(getter_AddRefs(impconnections));
    nsCOMPtr<cellml_apiIModel> impmodel;
    rv = import->GetImportedModel(getter_AddRefs(impmodel));
    LoadConnections(impconnections);
    rv = impi->NextImport(getter_AddRefs(import));
  }
  //And then get the main model's connections
  nsCOMPtr<cellml_apiIConnectionSet> connections;
  rv = model->GetConnections(getter_AddRefs(connections));
  LoadConnections(connections);

  CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  //We've pulled a fast one here by inserting connections into models that were already copied into other models.  So, we need to go back through and pull those connections into the copied models.  We'll do this recursively by calling the routine on the top model.
  CurrentModule()->ReloadSubmodelVariables(CurrentModule()->GetModuleName());
  CurrentModule()->ReloadSubmodelConnections(CurrentModule());
  
  return false; //success
}

bool Registry::LoadConnections(nsCOMPtr<cellml_apiIConnectionSet> connections)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  nsCOMPtr<cellml_apiIConnectionIterator> coni;
  rv = connections->IterateConnections(getter_AddRefs(coni));
  nsCOMPtr<cellml_apiIConnection> connection;
  rv = coni->NextConnection(getter_AddRefs(connection));
  bool somewrong = false;
  while (connection != NULL) {
    if (SynchronizeCellMLConnection(connection)) {
      somewrong = true;
    }
    rv = coni->NextConnection(getter_AddRefs(connection));
  }
  return somewrong;
}

bool Registry::SynchronizeCellMLConnection(nsCOMPtr<cellml_apiIConnection> connection)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  nsCOMPtr<cellml_apiIModel> topmodel; //used when the encapsulation parent is null (in GetNameAccordingToEncapsulationParent)
  rv = connection->GetModelElement(getter_AddRefs(topmodel));
  nsCOMPtr<cellml_apiICellMLElement> parentel;
  rv = topmodel->GetParentElement(getter_AddRefs(parentel));
  while (parentel != NULL) {
    rv = parentel->GetModelElement(getter_AddRefs(topmodel));
    rv = topmodel->GetParentElement(getter_AddRefs(parentel));
  }
  //rv = topmodel->GetName(cellmltext);
  //cout << "Top model: " << ToThinString(cellmltext.get()) << endl;
  
  //First we get the list of the component and any/all encapsulation parents
  vector<string> comp1moduleparents, comp2moduleparents;
  vector<string> comp1modulenames, comp2modulenames;
  nsCOMPtr<cellml_apiIMapComponents> compmap;
  rv = connection->GetComponentMapping(getter_AddRefs(compmap));
  nsCOMPtr<cellml_apiICellMLComponent> component;

  //First
  rv = compmap->GetFirstComponent(getter_AddRefs(component));
  while (component != NULL) {
    string modname = GetModuleNameFrom(component);
    comp1moduleparents.insert(comp1moduleparents.begin(), modname);
    modname = GetNameAccordingToEncapsulationParent(component, topmodel);
    FixName(modname);
    comp1modulenames.insert(comp1modulenames.begin(), modname);
    rv = component->GetEncapsulationParent(getter_AddRefs(component));
  }
  comp1moduleparents.insert(comp1moduleparents.begin(), CurrentModule()->GetModuleName());

  //Second
  rv = compmap->GetSecondComponent(getter_AddRefs(component));
  while (component != NULL) {
    string modname = GetModuleNameFrom(component);
    comp2moduleparents.insert(comp2moduleparents.begin(), modname);
    modname = GetNameAccordingToEncapsulationParent(component, topmodel);
    FixName(modname);
    comp2modulenames.insert(comp2modulenames.begin(), modname);
    rv = component->GetEncapsulationParent(getter_AddRefs(component));
  }
  comp2moduleparents.insert(comp2moduleparents.begin(), CurrentModule()->GetModuleName());

  //cout << "First component's parents: " << ToStringFromVecDelimitedBy(comp1moduleparents, '.') << endl << "Second component's parents: " << ToStringFromVecDelimitedBy(comp2moduleparents, '.') << endl;
  //cout << "First component's names: " << ToStringFromVecDelimitedBy(comp1modulenames, '.') << endl << "Second component's names: " << ToStringFromVecDelimitedBy(comp2modulenames, '.') << endl;
  //Now figure out the 'lowest' common parent in the encapsulation tree:
  string commonparent = "";
  assert(comp1moduleparents.size() > 0 && comp2moduleparents.size() > 0 && comp1moduleparents[0] == comp2moduleparents[0]);
  size_t pnum = 0;
  while (comp1modulenames.size() > 0 && comp2modulenames.size() > 0 &&
         comp1modulenames[0] == comp2modulenames[0]) {
    comp1modulenames.erase(comp1modulenames.begin());
    comp2modulenames.erase(comp2modulenames.begin());
    pnum++;
  }
  commonparent = comp1moduleparents[pnum];

  //At this point, we have the name of the module where the encapsulation happens:
  Module* topmod = CurrentModule();
  if (commonparent != "") {
    topmod = GetModule(commonparent);
  }
  assert(topmod != NULL);

  // cout << "Top module: " << commonparent << endl;
  // cout << "first compartment submodule name: " << ToStringFromVecDelimitedBy(comp1modulenames, '.') << endl;
  // cout << "second compartment submodule name: " << ToStringFromVecDelimitedBy(comp2modulenames, '.') << endl;

  //And we have the full names of the submodules whose variables need to be synchronized.  But there might be multiple variables, so we go through them all:
  nsCOMPtr<cellml_apiIMapVariablesSet> mvs;
  rv = connection->GetVariableMappings(getter_AddRefs(mvs));
  nsCOMPtr<cellml_apiIMapVariablesIterator> mvsi;
  rv = mvs->IterateMapVariables(getter_AddRefs(mvsi));
  nsCOMPtr<cellml_apiIMapVariables> mapvars;
  rv = mvsi->NextMapVariable(getter_AddRefs(mapvars));
  bool somefalse = false;
  while (mapvars != NULL) {
    rv = mapvars->GetFirstVariableName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    FixName(cellmlname);
    vector<string> fullvarname = comp1modulenames;
    fullvarname.push_back(cellmlname);
    Variable* firstvar = topmod->GetVariable(fullvarname);
    assert(firstvar != NULL);
    firstvar = firstvar->GetSameVariable();
    rv = mapvars->GetSecondVariableName(cellmltext);
    cellmlname = ToThinString(cellmltext.get());
    FixName(cellmlname);
    fullvarname = comp2modulenames;
    fullvarname.push_back(cellmlname);
    Variable* secondvar = topmod->GetVariable(fullvarname);
    assert(secondvar != NULL);
    secondvar = secondvar->GetSameVariable();
    //Now we create a local name for the variables to be synchronized if one doesn't already exist.
    vector<string> firstvarname = firstvar->GetName();
    vector<string> secondvarname = secondvar->GetName();
    if (firstvarname.size() > 1 && secondvarname.size() > 1) {
      //Create a local variable
      vector<string> newvarname;
      newvarname.push_back(secondvarname[secondvarname.size()-1]);
      Variable* newvar = topmod->GetVariable(newvarname);
      if (newvar == NULL) {
        newvar = topmod->AddOrFindVariable(&newvarname[0]);
      }
      else {
        newvar = topmod->AddNewNumberedVariable(newvarname[0]);
      }
      if (firstvar->Synchronize(newvar)) {
        g_registry.AddWarning("In module '" + topmod->GetModuleName() + "', the variables " + firstvar->GetNameDelimitedBy('.') + " and " + newvar->GetNameDelimitedBy('.') + " were unable to be set as equivalent:  " + g_registry.GetError());
        somefalse = true;
      }
      if (secondvar->Synchronize(newvar)) {
        g_registry.AddWarning("In module '" + topmod->GetModuleName() + "', the variables " + secondvar->GetNameDelimitedBy('.') + " and " + newvar->GetNameDelimitedBy('.') + " were unable to be set as equivalent:  " + g_registry.GetError());
        somefalse = true;
      }
    }
    else {
      if (firstvar->Synchronize(secondvar)) {
        g_registry.AddWarning("In module '" + topmod->GetModuleName() + "', the variables " + firstvar->GetNameDelimitedBy('.') + " and " + secondvar->GetNameDelimitedBy('.') + " were unable to be set as equivalent:  " + g_registry.GetError());
        somefalse = true;
      }
    }
    rv = mvsi->NextMapVariable(getter_AddRefs(mapvars));
  }
  return somefalse;
}  

#endif

void Registry::CreateLocalVariablesForSubmodelInterfaceIfNeeded()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    m_modules[mod].CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  }
}


bool Registry::SwitchToPreviousFile()
{
  if (!input) return true;
  //input->close(); //LS DEBUG
  input->clear();
  delete input;
  if (m_oldinputs.size() == 0) {
    input = NULL;
    return true;
  }
  input = m_oldinputs.back();
  m_oldinputs.pop_back();
  m_files.pop_back();
  return false;
}

void Registry::SetupFunctions()
{
  //This list courtesy libSBML, MathML.cpp, MATHML_ELEMENTS, plus "pow", in honor of Batman.
  // (Ok, other extras (post-xor) from ASTNode.cpp)
  const char* functions[] = {
  "abs"
  , "and"
  , "annotation"
  , "annotation-xml"
  , "apply"
  , "arccos"
  , "arccosh"
  , "arccot"
  , "arccoth"
  , "arccsc"
  , "arccsch"
  , "arcsec"
  , "arcsech"
  , "arcsin"
  , "arcsinh"
  , "arctan"
  , "arctanh"
  , "bvar"
  , "ceiling"
  //  , "ci"
  , "cn"
  , "cos"
  , "cosh"
  , "cot"
  , "coth"
  , "csc"
  , "csch"
  , "csymbol"
  , "degree"
  , "divide"
  , "eq"
  , "exp"
  , "exponentiale"
  , "factorial"
  , "false"
  , "floor"
  , "geq"
  , "gt"
  , "infinity"
  , "lambda"
  , "leq"
  , "ln"
  , "log"
  , "logbase"
  , "lt"
  , "math"
  , "minus"
  , "neq"
  , "not"
  , "notanumber"
  , "or"
  , "otherwise"
  , "pi"
  , "piece"
  , "piecewise"
  , "plus"
  , "power"
  , "root"
  , "sec"
  , "sech"
  , "semantics"
  , "sep"
  , "sin"
  , "sinh"
  , "tan"
  , "tanh"
  , "times"
  , "true"
  , "xor"
  , "acos"
  , "asin"
  , "atan"
  , "ceil"
  , "delay"
  , "log10"
  , "pow"
  , "sqr"
  , "sqrt"
  , "time"
  };
  for (size_t func=0; func<78; func++) {
    m_functions.push_back(functions[func]);
  }
}

bool Registry::NewCurrentModule(const string* name)
{
  string localname(*name);
  m_currentModules.push_back(localname);
  //Check to make sure no existing module exist with this name
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].GetModuleName() == localname) {
      //assert(false); //Parsing disallows this condition, but translation allows it (though it's still an Antimony error).
      //cout << "duplicated name: " << localname << endl;
      SetError("Programming error:  Unable to create new module with the same name as an existing module (\"" + localname + "\").");
      return true;
    }
  }
  //Otherwise, create a new module with that name
  m_modules.push_back(Module(localname));
  m_modulemap.insert(make_pair(*name, m_modules.size()-1));
  return false;
}

Module* Registry::CurrentModule()
{
  assert (m_currentModules.size() > 0);
  return GetModule(m_currentModules.back());
}

void Registry::RevertToPreviousModule()
{
  m_currentModules.pop_back();
  assert(m_currentModules.size() > 0);
}

bool Registry::AddVariableToCurrentExportList(Variable* export_var)
{
  if (m_isfunction) {
    return m_userfunctions.back().AddVariableToExportList(export_var);
  }
  return CurrentModule()->AddVariableToExportList(export_var);
}

void Registry::NewUserFunction(const std::string* name)
{
  m_isfunction = true;
  UserFunction newfunc(*name);
  m_userfunctionnames.push_back(*name);
  m_userfunctions.push_back(newfunc);
}

bool Registry::SetUserFunction(Formula* formula)
{
  m_isfunction = false;
  return m_userfunctions.back().SetFormula(*formula);
}

bool Registry::AddVariableToCurrentImportList(Variable* import_var)
{
  Module* submod = CurrentModule()->GetVariable(m_currentImportedModule)->GetModule();
  Variable* var = submod->GetNextExportVariable();
  if (var == NULL) {
    string error = "Unable to add variable '" + import_var->GetNameDelimitedBy(GetCC()) + "' when creating an instance of the module '" + submod->GetModuleName() + "' because this module is defined to have only " + SizeTToString(submod->GetNumExportVariables()) + " variable(s) definable by default in its construction.";
    SetError(error);
    return true;
  }
  var->Synchronize(import_var);
  return false;
}

Variable* Registry::AddVariableToCurrent(const string* name)
{
  if (m_isfunction) {
    return m_userfunctions.back().AddOrFindVariable(name);
  }
  return CurrentModule()->AddOrFindVariable(name);
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula)
{
  Variable* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula);
  m_currentReactantLists.clear();
  return retval;
}

Variable* Registry::AddNewReactionToCurrent(rd_type divider, Formula* formula, Variable* var)
{
  Variable* retval = CurrentModule()->AddNewReaction(&(m_currentReactantLists[0]), divider, &(m_currentReactantLists[1]), formula, var);
  m_currentReactantLists.clear();
  return retval;
}

ReactantList* Registry::NewBlankReactantList()
{
  ReactantList rlist;
  m_currentReactantLists.push_back(rlist);
  return &(m_currentReactantLists.back());
}

bool Registry::SetStrandAs(Variable* var)
{
  if (var->SetDNAStrand(m_workingstrand)) return true;
  vector<Variable*> vars = m_workingstrand.GetVariables();
  for (size_t vnum=0; vnum<vars.size(); vnum++) {
    if (vars[vnum]->SetIsInStrand(var)) return true;
  }
  m_workingstrand.Clear();
  return false;
}

bool Registry::SaveWorkingStrand()
{
  Variable* var = CurrentModule()->AddNewNumberedVariable("_dna");
  return SetStrandAs(var);
}

bool Registry::SetNewUpstreamOpen(Variable* var)
{
  m_workingstrand.Clear();
  m_workingstrand.SetUpstream(true);
  return m_workingstrand.SetUpstream(var);
}

void Registry::SetOpenUpstream()
{
  m_workingstrand.SetUpstream(true);
}

bool Registry::SetDownstreamEnd(Variable* var)
{
  m_workingstrand.SetDownstream(false);
  return m_workingstrand.SetDownstream(var);
}

bool Registry::SetNewDownstreamOpen(Variable* var)
{
  m_workingstrand.Clear();
  m_workingstrand.SetDownstream(true);
  return m_workingstrand.SetUpstream(var);
}

bool Registry::SetDownstreamOpen(Variable* var)
{
  m_workingstrand.SetDownstream(true);
  return m_workingstrand.SetDownstream(var);
}


bool Registry::SetNewCurrentEvent(Formula* trigger)
{
  Variable* evar = CurrentModule()->AddNewNumberedVariable("_E");
  return SetNewCurrentEvent(trigger, evar);
}

bool Registry::SetNewCurrentEvent(Formula* delay, Formula* trigger)
{
  Variable* evar = CurrentModule()->AddNewNumberedVariable("_E");
  return SetNewCurrentEvent(delay, trigger, evar);
}

bool Registry::SetNewCurrentEvent(Formula* trigger, Variable* var)
{
  m_currentEvent = var->GetName();
#ifndef NSBML
  string formstring = trigger->ToSBMLString();
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      g_registry.SetError("The event trigger \"" + trigger->ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else if (!ASTform->isBoolean()) {
      g_registry.SetError("The formula \"" + trigger->ToDelimitedStringWithEllipses('.') + "\" cannot be parsed in a boolean context, and it is therefore illegal to use it as the trigger for an event.  (Perhaps try adding parentheses?)");
      delete ASTform;
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  Formula delay;
  AntimonyEvent event(delay, *trigger,var);
  return var->SetEvent(&event);
}

bool Registry::SetNewCurrentEvent(Formula* delay, Formula* trigger, Variable* var)
{
  m_currentEvent = var->GetName();
  AntimonyEvent event(*delay, *trigger, var);
  return var->SetEvent(&event);
}

bool Registry::AddResultToCurrentEvent(Variable* var, Formula* form)
{
  //return
  CurrentModule()->GetVariable(m_currentEvent)->GetEvent()->AddResult(var, form);
  return false;
}

bool Registry::SetCompartmentOfCurrentSubmod(Variable* var)
{
  return CurrentModule()->GetVariable(m_currentImportedModule)->SetCompartment(var);
}

Formula* Registry::NewBlankFormula()
{
  Formula* form = new Formula();
  m_storedformulas.insert(form);
  return form;
}

string Registry::GetLastFile()
{
  if (m_files.size()) return m_files.back();
  assert(false); //Should only be called when parsing.
  return "";
}

Module* Registry::GetModule(string modulename)
{
  map<string, size_t>::iterator found = m_modulemap.find(modulename);
  if (found != m_modulemap.end()) {
    return &(m_modules[found->second]);
  }
  //We don't store the user functions in a hash because there usually aren't that many of them.
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
      return &(m_userfunctions[uf]);
    }
  }
  //In case we missed adding it to the hash:
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      assert(false);
      m_modulemap.insert(make_pair(modulename, mod));
      return &(m_modules[mod]);
    }
  }
  return NULL;
}

const Module* Registry::GetModule(string modulename) const
{
  map<string, size_t>::const_iterator found = m_modulemap.find(modulename);
  if (found != m_modulemap.end()) {
    return &(m_modules[found->second]);
  }
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (modulename == m_modules[mod].GetModuleName()) {
      assert(false);
      return &(m_modules[mod]);
    }
  }
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (modulename == m_userfunctions[uf].GetModuleName()) {
      assert(false);
      return &(m_userfunctions[uf]);
    }
  }
  return NULL;
}

bool Registry::IsModuleName(string word)
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (word == m_modules[mod].GetModuleName()) {
      return true;
    }
  }
  return false;
}

const string*  Registry::AddWord(string word)
{
  pair<set<string>::iterator,bool> ret;

  ret = m_variablenames.insert(word);
  set<string>::iterator wordit = ret.first;
  return &(*wordit);
}

void Registry::StoreVariable(Variable* var)
{
  m_storedvars.insert(var);
}

const string* Registry::IsFunction(string word)
{
  for (size_t func=0; func<m_functions.size(); func++) {
    if (word == m_functions[func]) {
      return &(m_functions[func]);
    }
  }
  for (size_t uf=0; uf<m_userfunctionnames.size(); uf++) {
    if (word == m_userfunctionnames[uf]) {
      return &(m_userfunctionnames[uf]);
    }
  }
  return NULL;
}

string Registry::GetAntimony() const
{
  string retval;
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    retval += m_userfunctions[uf].GetAntimony() + "\n";
  }
  set<const Module*> mods;
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    retval += m_modules[mod].GetAntimony(mods, true) + "\n";
    mods.insert(&m_modules[mod]);
  }
  return retval;
}

string Registry::GetAntimony(string modulename) const
{
  const Module* amod = GetModule(modulename);
  if (amod == NULL) return "";
  set<const Module*> nomods;
  return amod->GetAntimony(nomods, false);
}

string Registry::GetJarnac(string modulename) const
{
  const Module* jmod = GetModule(modulename);
  if (jmod == NULL) return "";
  string jarnac = modulename + " = define model\n";
  jarnac += jmod->GetJarnacReactions();
  jarnac += "\n";
  jarnac += jmod->GetJarnacVarFormulas();
  jarnac += "\nend\n\n";
  jarnac += jmod->GetJarnacConstFormulas(modulename);
  return jarnac;
}

bool Registry::FinalizeModules()
{
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].Finalize()) return true;
  }
  return false;
}


size_t Registry::GetNumModules()
{
  return m_modules.size();
}

string Registry::GetNthModuleName(size_t n)
{
  if (n>=m_modules.size()) {
    assert(false); //Shouldn't get here; wrong user calls caught earlier.
    g_registry.SetError("Programming error:  no such module " + SizeTToString(n) + ".");
    return NULL;
  }
  return m_modules[n].GetModuleName();
}

long Registry::SaveModules()
{
  m_oldmodules.push_back(m_modules);
  m_olduserfunctions.push_back(m_userfunctions);
  m_oldmodulemaps.push_back(m_modulemap);
  m_isfunction = false;
  return m_oldmodules.size();
}

bool Registry::RevertToModuleSet(long n)
{
  assert(m_oldmodules.size() == m_olduserfunctions.size());
  if (n == -1) {
    g_registry.SetError("An error occurred when reading that file.  Any modules in it are unavailable.");
    return true;
  }
  if (n<=0 || n>static_cast<long>(m_oldmodules.size())) {
    string error = "No such file handle.  ";
    if (m_oldmodules.size()==0) {
      error += "No files have been successfully read.";
    }
    else if (m_oldmodules.size()==1) {
      error += "Exactly one file has been successfully read, with file handle 1.";
    }
    else {
      error += "Valid file handles are 1 through " + SizeTToString(m_oldmodules.size());
    }
    g_registry.SetError(error);
    return true;
  }
  m_modules.clear(); //LS NOTE:  needed because otherwise we leak models!  Yes, this is weird.
  m_userfunctions.clear();
  m_modules = m_oldmodules[n-1];
  m_modulemap = m_oldmodulemaps[n-1];
  m_userfunctions = m_olduserfunctions[n-1];
  for (size_t mod=0; mod<m_modules.size(); mod++) {
    if (m_modules[mod].Finalize()) return true;
  }
  m_userfunctionnames.clear();
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    m_userfunctionnames.push_back(m_userfunctions[uf].GetModuleName());
  }
  m_isfunction = false;
  return false;
}

const UserFunction* Registry::GetNthUserFunction(size_t n) const
{
  if (m_userfunctions.size() <= n) return NULL;
  return &(m_userfunctions[n]);
}

UserFunction* Registry::GetNthUserFunction(size_t n)
{
  if (m_userfunctions.size() <= n) return NULL;
  return &(m_userfunctions[n]);
}

void Registry::FixTimeInFunctions()
{
  for (size_t uf=0; uf<m_userfunctions.size(); uf++) {
    if (m_userfunctions[uf].ChangeTimeToRef()) {
      for (size_t mod=0; mod<m_modules.size(); mod++) {
        m_modules[mod].AddTimeToUserFunction(m_userfunctions[uf].GetModuleName());
      }
    }
  }
}

void Registry::FreeAll()
{
  for (size_t i=0; i<m_charstars.size(); i++) {
    free(m_charstars[i]);
  }
  m_charstars.clear();
  for (size_t i=0; i<m_charstarstars.size(); i++) {
    free(m_charstarstars[i]);
  }
  m_charstarstars.clear();
  for (size_t i=0; i<m_charstarstarstars.size(); i++) {
    free(m_charstarstarstars[i]);
  }
  m_charstarstarstars.clear();

  for (size_t i=0; i<m_doublestars.size(); i++) {
    free(m_doublestars[i]);
  }
  m_doublestars.clear();
  for (size_t i=0; i<m_doublestarstars.size(); i++) {
    free(m_doublestarstars[i]);
  }
  m_doublestarstars.clear();

  for (size_t i=0; i<m_ulongstars.size(); i++) {
    free(m_ulongstars[i]);
  }
  m_ulongstars.clear();
  for (size_t i=0; i<m_rd_typestars.size(); i++) {
    free(m_rd_typestars[i]);
  }
  m_rd_typestars.clear();
}

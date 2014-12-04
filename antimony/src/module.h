#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <set>
#include <map>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifdef USE_COMP
#include <sbml/packages/comp/common/CompExtensionTypes.h>
#endif

#ifndef NCELLML
//#include "ICellMLInputServices.h"
//#include <nsCOMPtr.h>
enum tree_direction {td_UP, td_DOWN, td_SIDEWAYS};
#endif

#include "annotated.h"
#include "antimony_api.h"
#include "variable.h"
#include "reaction.h"

class ReactionList;

class Module  : public Annotated
{
protected:
  std::string m_modulename;
  std::vector<std::vector<std::string> > m_exportlist;

private:
  Module(); //undefined

  std::vector<std::string> m_variablename;

  std::vector<Variable*> m_variables;
  std::vector<Variable*> m_defaultVariables;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > m_synchronized;
  std::vector<std::vector<std::string> > m_conversionFactors;
  std::vector<std::string> m_returnvalue;
  std::set<std::string> m_rateNames;
  std::set<distribution_type> m_usedDistributions;

  size_t m_currentexportvar;
  bool m_ismain;
  int m_sbmllevel;
  int m_sbmlversion;

  //Caching for speed:
  std::map<std::vector<std::string>, Variable*> m_varmap;

#ifndef NSBML
  SBMLNamespaces m_sbmlnamespaces;
  SBMLDocument m_sbml;
  std::string m_libsbml_info;
  std::string m_libsbml_warnings;
#endif

#ifndef NCELLML
  ObjRef<iface::cellml_api::Model> m_cellmlmodel;
  ObjRef<iface::cellml_api::CellMLComponent> m_cellmlcomponent;
  std::map<std::vector<std::string>, std::string > m_cellmlnames;
  std::set<std::string> m_uniquenames;
  std::map<Variable*, std::vector<Variable*> > m_syncedvars;
  bool m_childrenadded;
#endif

public:

  //Storage vectors for output:
  std::vector<Variable*> m_uniquevars;

  Module(std::string name);
  Module(const Module& src); //Can't accept default with CellML, since it reference counts.
  Module& operator=(const Module& src); //(same as above)
  Module(const Module& src, std::string newtopname, std::string modulename);
  ~Module();

  Variable* AddOrFindVariable(const std::string* name);
  Variable* AddNewNumberedVariable(const std::string name);
  void StoreVariable(Variable* var);
  bool AddVariableToExportList(Variable* var);
  Variable* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula);
  Variable* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var);
  bool SetFormula(Formula* formula);
  void SetNewTopName(std::string newmodname, std::string newtopname);
  bool SetModule(const std::string* modname);
  void SetComponentCompartments(Variable* compartment);
  void AddSynchronizedPair(const Variable* oldvar, const Variable* newvar, const Variable* conversionFactor);
  void AddTimeToUserFunction(std::string function);
  void CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  void SetIsMain(bool ismain) {m_ismain=ismain;};
  bool AddDeletion(Variable* deletedvar);
  bool DeleteFromSynchronized(Variable* deletedvar);
  void ClearReferencesTo(Variable* deletedvar, std::set<std::pair<std::vector<std::string>, deletion_type> >* ret);
  Variable* AddOrFindUnitDef(UnitDef* unitdef);
  bool AddUnitVariables(UnitDef* unitdef);
  void AddDefaultVariables();

  Variable* GetVariable(const std::vector<std::string>& name);
  Variable* GetDefaultVariable(const std::vector<std::string>& name);
  void AddToVarMapFrom(const Module& submod);
  const Variable* GetVariable(const std::vector<std::string>& name) const;
  const Variable* GetVariableFromSymbol(std::string varname) const;
  Variable* GetSubVariable(const std::string* name);
  const Formula* GetFormula() const;
  Formula* GetFormula();
  Variable* GetNextExportVariable();
  size_t GetNumExportVariables() const {return m_exportlist.size();};
  std::vector<std::string> GetNthExportVariable(size_t n) const;
  size_t GetNumSynchronizedVariables() const;
  std::pair<std::string, std::string> GetNthSynchronizedVariablePair(size_t n) const;
  std::vector<std::pair<std::string, std::string> > GetAllSynchronizedVariablePairs() const;
  std::vector<std::pair<std::string, std::string> > GetSynchronizedVariablesBetween(std::string mod1, std::string mod2) const;
  std::pair<std::string, std::string> GetNthSynchronizedVariablesBetween(std::string mod1, std::string mod2, size_t n) const;
  Variable* GetUpstreamDNA();
  Variable* GetDownstreamDNA();
  formula_type GetFormulaType() const; //If we have a return value
  bool GetIsMain() const {return m_ismain;};
  bool IsRateOfSymbol(const std::string& name) const;


  const std::string& GetModuleName() const;
  std::string GetVariableNameDelimitedBy(std::string cc) const;
  std::string ToString() const;
  std::string OutputOnly(std::vector<var_type> types, std::string name, std::string indent, std::string cc, std::map<const Variable*, Variable > origmap) const;
  std::string ListIn80Cols(std::string type, std::vector<std::string> names, std::string indent) const;
  std::string GetAntimony(std::set<const Module*>& usedmods, bool funcsincluded) const;
  std::string GetJarnacReactions() const;
  std::string GetJarnacVarFormulas() const;
  std::string GetJarnacConstFormulas(std::string modulename) const;

  bool GetNeedDefaultCompartment() const;


  //Output for the API
  bool Finalize();
#ifndef NSBML
  std::string GetSBMLInfo() const {return m_libsbml_info;};
  std::string GetSBMLWarnings() const {return m_libsbml_warnings;};
  bool CheckUndefined(const Formula* form);
#endif
  size_t GetNumVariablesOfType(return_type rtype, bool comp) const;
  const Variable* GetNthVariableOfType(return_type rtype, size_t n, bool comp) const;
        Variable* GetNthVariableOfType(return_type rtype, size_t n, bool comp);
  bool   AreEquivalent(return_type rtype, var_type vtype) const;
  bool   AreEquivalent(return_type rtype, bool isconst) const;

  std::string ListSynchronizedVariables(std::string indent, std::set<size_t> alreadysynchronized) const;
  std::string ListAssignmentDifferencesFrom(const Module* origmod, std::string mname, std::string indent) const;
#ifndef NSBML
#ifdef USE_COMP
  void  AddSubmodelsToDocument(SBMLDocument* sbml);
  void  ReturnSubmodelsFromDocument(SBMLDocument* sbml);
  bool  SynchronizeAssignments(Model* sbmlmod, const Variable* var, const std::vector<const Variable*>& synchronized, const std::map<const Variable*, Variable>& syncmap);
  bool  SynchronizeRates(Model* sbmlmod, const Variable* var, const std::vector<const Variable*>& synchronized, const std::map<const Variable*, Variable>& syncmap);
#endif //USE_COMP
  void TranslateRulesAndAssignmentsTo(const SBase* obj, Variable* var);
  void  LoadSBML(const SBMLDocument* sbmldoc);
  void  LoadSBML(const Model* sbml);
  const SBMLDocument* GetSBML(bool comp);
  void  CreateSBMLModel(bool comp);
  void  SetAssignmentFor(Model* sbmlmod, const Variable* var, const std::map<const Variable*, Variable>& syncmap, bool comp, std::set<std::pair<std::string, const Variable*> > referencedVars);
  void  FindOrCreateLocalVersionOf(const Variable* var, Model* sbmlmod);
#endif //NSBML
  std::vector<const Variable*> GetSynchronizedVariablesFor(const Variable* var);
  void FillInSyncmap(std::map<const Variable*, Variable >& syncmap) const;
  void AddVarToSyncMap(const Variable* var, std::map<const Variable*, Variable >& syncmap) const;

#ifndef NCELLML
  //Reading:
  void  LoadCellMLModel(iface::cellml_api::Model* model,
                        std::vector<iface::cellml_api::CellMLComponent*> top_components);
  void  LoadCellMLComponent(iface::cellml_api::CellMLComponent* component);
  void  SetCellMLChildrenAsSubmodules(iface::cellml_api::CellMLComponent* component);
  iface::cellml_api::Model* GetCellMLModel();
  void  ResyncVariablesWith(const Module* twin, std::string modulename, std::vector<std::string> varname);
  void  ReloadSubmodelVariables(const std::string& modname);
  void  ReloadSubmodelConnections(Module* syncmod);

  //Creating:
  void  CreateCellMLModel();
  void  AddCellMLComponentsTo(iface::cellml_api::Model* model, Module* topmod);
  iface::cellml_api::CellMLComponent* GetCellMLComponent(Module* topmod);
  void  CreateCellMLComponent(Module* topmod);
  void  AddNewVariableToCellML(Variable* variable, iface::cellml_api::Model* model);
  iface::cellml_api::CellMLVariable* AddNewVariableToCellML(std::string varname, iface::cellml_api::Model* model);
  iface::cellml_api::CellMLVariable* AddNewVariableToCellML(std::string varname, iface::cellml_api::CellMLComponent* component, iface::cellml_api::Model* model);
  void  AssignMathOnceFor(std::vector<Variable*> varlist, iface::dom::Document* doc);
  bool  AddCellMLMathTo(std::string formula, Variable* targetvar, iface::dom::Document* doc);
  bool  AddCellMLMathTo(std::string formula, iface::cellml_api::CellMLComponent* cmlcomp, iface::dom::Document* doc);
  void  AddTimeFor(iface::cellml_api::CellMLVariable* cmlvar);
  iface::cellml_api::CellMLVariable* AddTimeTo(iface::cellml_api::CellMLComponent* cmlcomp);

  Variable* WhichFirstDefined(std::vector<Variable*> varlist, formula_type ftype);
  bool  InUnique(std::string name);
  void  AddUnique(std::vector<std::string> fullname, std::string name);
  std::string GetCellMLNameOf(std::vector<std::string> name);
  void  AddEncapsulationTo(iface::cellml_api::Model* model);
  void  AddConnectionsTo(iface::cellml_api::Model* model, Module* topmod);
  void  AddODEsTo(iface::cellml_api::Model* model, Module* topmod, iface::dom::Document* doc);

  iface::cellml_api::ComponentRef* GetComponentRef(iface::cellml_api::Model* model, std::string cmlname, Module* topmod);
  void  SetCanonicalVars();
  void  FindAndSetCanonical(std::vector<Variable*> varlist);
  void  AddConnections();
  void  SetupTree(std::map<Variable*, Variable*>& tree, Variable* thisvar);
  void  AddConnectionsTo(std::vector<Variable*> varlist, const std::map<Variable*, Variable*>& tree);
  Variable*  GetParent(Variable* child, const std::map<Variable*, Variable*>& tree);
  Variable* GetSyncedVariable(Variable* mod, const std::map<Variable*, Variable*>& mod2var);
  iface::cellml_api::CellMLVariable* GetLinkedCMLVar(Variable* mod, const std::map<Variable*, iface::cellml_api::CellMLVariable* >& mod2linkedcellml);
  void Connect(Variable* modin, Variable* canonmod, std::map<Variable*, iface::cellml_api::CellMLVariable*>& mod2linkedcellml, const std::map<Variable*, Variable*>& mod2var, const std::set<Variable*>& canonparents, const std::map<Variable*, Variable*>& tree);
  void  AddOneConnection(iface::cellml_api::CellMLVariable* varin, iface::cellml_api::CellMLVariable* varout, tree_direction td);
  void  GetAllSpeciesAndReactions(std::set<Variable*>& species, std::set<Variable*>& reactions);
  Module* BestModuleToAdd(std::set<Variable*> involvedrxns, std::set<Variable*>& contains );
  void  AddRateRuleInvolving(Variable* species, Formula form, std::set<Variable*> involvedrxns, iface::dom::Document* doc);
  void  FindOrCreateLocalVersionOf(Variable* variable, std::string& newvarname, iface::cellml_api::CellMLVariable*& newlocalvar);
#endif

  void FixNames();
  void ConvertTime(Variable* tcf);
  void ConvertExtent(Variable* xcf);
  void UndoTimeExtentConversions(Variable* tcf, Variable* xcf);

private:
  void FillInOrigmap(std::map<const Variable*, Variable >& origmap) const;
  bool OrigFormulaIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, const Formula* formula) const;
  bool OrigRateRuleIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, const Formula* formula) const;
  bool OrigAssignmentRuleIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, const Formula* formula) const;
  bool OrigIsAlreadyCompartment(const Variable* var, const std::map<const Variable*, Variable>& origmap) const;
  bool OrigIsAlreadyConstSpecies(const Variable* var, const std::map<const Variable*, Variable>& origmap, bool isconst) const;
  bool OrigIsAlreadyDNAStrand(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string strand) const;
  bool OrigReactionIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, const AntimonyReaction* rxn) const;
  bool OrigEventIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, const AntimonyEvent* event) const;
  bool OrigIsAlreadyUnitDef(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string unitdef) const;
  bool OrigDisplayNameIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap) const;
  bool OrigMatches(const Variable* var, const std::map<const Variable*, Variable>& origmap, var_type type, const_type isconst, const Variable* comp) const;
  const Variable* GetNthConstVariableOfType(return_type rtype, size_t n, bool comp) const;
  void Convert(Variable* converted, Variable* cf, std::string modulename);
#ifndef NSBML
  bool IsReplaced(const InitialAssignment* ia, const Model* parent);
  bool IsReplaced(const Rule* rule, const Model* parent);
#ifdef USE_COMP
  void GetReplacingAndRules(const Replacing* replacing, std::string re_string, const SBase* orig, Variable*& reference, const InitialAssignment*& ia, const Rule*& rule);
  Variable* GetSBaseRef(const SBaseRef* sbr, std::string modname, std::string re_string, const SBase* orig);
  InitialAssignment* FindInitialAssignment(Model* md, std::vector<std::string> syncname);
  Rule* FindRule(Model* md, std::vector<std::string> syncname);
#endif
#endif
};

#include "userfunction.h"


#endif //MODULE_H

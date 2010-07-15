#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <set>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifndef NCELLML
#include "ICellMLInputServices.h"
#include <nsCOMPtr.h>
#endif

#include "antimony_api.h"
#include "variable.h"
#include "reaction.h"

class ReactionList;

class Module{
protected:
  std::string m_modulename;
  std::vector<std::vector<std::string> > m_exportlist;

private:
  Module(); //undefined

  std::vector<std::string> m_variablename;

  std::vector<Variable*> m_variables;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > m_synchronized;
  std::vector<std::vector<std::string> > m_changed;
  std::vector<std::string> m_returnvalue;

  size_t m_currentexportvar;

  //Caching for speed:
  std::map<std::vector<std::string>, Variable*> m_varmap;

#ifndef NSBML
  SBMLDocument m_sbml;
  std::string m_libsbml_info;
  std::string m_libsbml_warnings;
#endif

#ifndef NCELLML
  nsCOMPtr<cellml_apiIModel> m_cellmlmodel;
  nsCOMPtr<cellml_apiICellMLComponent> m_cellmlcomponent;
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
  void AddSynchronizedPair(Variable* oldvar, Variable* newvar);
  void AddTimeToUserFunction(std::string function);
  void CreateLocalVariablesForSubmodelInterfaceIfNeeded();

  Variable* GetVariable(const std::vector<std::string>& name);
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

  const std::string& GetModuleName() const;
  std::string GetVariableNameDelimitedBy(char cc) const;
  std::string ToString() const;
  std::string OutputOnly(std::vector<var_type> types, std::string name, std::string indent, char cc, std::map<const Variable*, Variable > origmap) const;
  std::string ListIn80Cols(std::string type, std::vector<std::string> names, std::string indent) const;
  std::string GetAntimony(std::set<const Module*>& usedmods, bool funcsincluded) const;
  std::string GetJarnacReactions() const;
  std::string GetJarnacVarFormulas() const;
  std::string GetJarnacConstFormulas(std::string modulename) const;


  //Output for the API
  bool Finalize();
#ifndef NSBML
  std::string GetSBMLInfo() const {return m_libsbml_info;};
  std::string GetSBMLWarnings() const {return m_libsbml_warnings;};
#endif
  size_t GetNumVariablesOfType(return_type rtype) const;
  const Variable* GetNthVariableOfType(return_type rtype, size_t n) const;
  bool   AreEquivalent(return_type rtype, var_type vtype) const;
  bool   AreEquivalent(return_type rtype, bool isconst) const;

  std::string ListSynchronizedVariables(std::string indent, std::set<size_t> alreadysynchronized) const;
  std::string ListAssignmentDifferencesFrom(const Module* origmod, std::string mname, std::string indent) const;
#ifndef NSBML
  void  LoadSBML(const SBMLDocument* sbmldoc);
  const SBMLDocument* GetSBML();
  void  CreateSBMLModel();
  void  SetAssignmentFor(Model* sbmlmod, const Variable* var);
#endif

#ifndef NCELLML
  //Reading:
  void  LoadCellMLModel(nsCOMPtr<cellml_apiIModel> model, std::vector<nsCOMPtr<cellml_apiICellMLComponent> > top_components);
  void  LoadCellMLComponent(nsCOMPtr<cellml_apiICellMLComponent> component);
  void  SetCellMLChildrenAsSubmodules(nsCOMPtr<cellml_apiICellMLComponent> component);
  const nsCOMPtr<cellml_apiIModel> GetCellMLModel();
  void  ResyncVariablesWith(const Module* twin, std::string modulename, std::vector<std::string> varname);
  void  ReloadSubmodelVariables(const std::string& modname);
  void  ReloadSubmodelConnections(Module* syncmod);

  //Creating:
  void  CreateCellMLModel();
  void  AddCellMLComponentsTo(nsCOMPtr<cellml_apiIModel> model, std::string topmod);
  nsCOMPtr<cellml_apiICellMLComponent> GetCellMLComponent(std::string topmod);
  void  CreateCellMLComponent(std::string topmod);
  void  AddVariableToCellML(Variable* variable, nsCOMPtr<cellml_apiIModel> model);
  void  AssignMathOnceFor(std::vector<Variable*> varlist);
  Variable* WhichFirstDefined(std::vector<Variable*> varlist, formula_type ftype);
  bool  InUnique(std::string name);
  void  AddUnique(std::vector<std::string> fullname, std::string name);
  void  AddConnectionsTo(nsCOMPtr<cellml_apiIModel> model, std::string topmodname);
  void  AddOneConnection(nsCOMPtr<cellml_apiIModel> model, Variable* var, Module* topmod);
  std::string GetCellMLNameOf(std::vector<std::string> name);
#endif

  void  FixNames();

private:
  void FillInOrigmap(std::map<const Variable*, Variable >& origmap) const;
  bool OrigFormulaIsAlready(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string formula) const;
  bool OrigIsAlreadyCompartment(const Variable* var, const std::map<const Variable*, Variable>& origmap) const;
  bool OrigIsAlreadyConstSpecies(const Variable* var, const std::map<const Variable*, Variable>& origmap, bool isconst) const;
  bool OrigIsAlreadyDNAStrand(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string strand) const;
  bool OrigIsAlreadyAssignmentRule(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string rule) const;
  bool OrigIsAlreadyRateRule(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string rule) const;
  bool OrigIsAlreadyReaction(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string rxn) const;
  bool OrigIsAlreadyEvent(const Variable* var, const std::map<const Variable*, Variable>& origmap, std::string event) const;
  bool OrigMatches(const Variable* var, const std::map<const Variable*, Variable>& origmap, var_type type, const_type isconst, const Variable* comp) const;
};

#include "userfunction.h"


#endif //MODULE_H

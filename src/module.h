#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <set>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifndef NCELLML
#include <IfaceCellML_APISPEC.hxx>
using namespace iface;
#endif

#include "antimony_api.h"
#include "variable.h"
#include "reaction.h"

class ReactionList;

class Module
{
protected:
  std::string m_modulename;
  std::vector<std::vector<std::string> > m_exportlist;

private:
  Module(); //undefined

  std::vector<std::string> m_variablename;

  std::vector<Variable*> m_variables;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > m_synchronized;
  std::vector<std::string> m_returnvalue;

  size_t m_currentexportvar;

#ifndef NSBML
  SBMLDocument m_sbml;
  std::string m_libsbml_info;
  std::string m_libsbml_warnings;
#endif

#ifndef NCELLML
  cellml_api::Model* m_cellmlmodel;
  cellml_api::CellMLComponent* m_cellmlcomponent;
#endif

public:

  //Storage vectors for output:
  std::vector<std::vector<std::string> > m_uniquevars;

  Module(std::string name);
  Module(const Module& src); //Can't accept default with CellML, since it reference counts.
  Module& operator=(const Module& src); //(same as above)
  Module(const Module& src, std::string newtopname, std::string modulename);
  ~Module();

  Variable* AddOrFindVariable(const std::string* name);
  Variable* AddNewNumberedVariable(const std::string name);
  void AddVariableToExportList(Variable* var);
  Variable* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula);
  Variable* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var);
  bool SetFormula(Formula* formula);
  void SetNewTopName(std::string newmodname, std::string newtopname);
  bool SetModule(const std::string* modname);
  void SetComponentCompartments(Variable* compartment);
  void AddSynchronizedPair(Variable* oldvar, Variable* newvar);
  void AddTimeToUserFunction(std::string function);

  Variable* GetVariable(std::vector<std::string> name);
  const Variable* GetVariable(std::vector<std::string> name) const;
  const Variable* GetVariableFromSymbol(std::string varname) const;
  Variable* GetSubVariable(const std::string* name);
  const Formula* GetFormula() const;
  Formula* GetFormula();
  Variable* GetNextExportVariable();
  size_t GetNumExportVariables() const {return m_exportlist.size();};
  Variable* GetUpstreamDNA();
  Variable* GetDownstreamDNA();
  formula_type GetFormulaType() const; //If we have a return value

  const std::string& GetModuleName() const;
  std::string GetVariableNameDelimitedBy(char cc) const;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > GetSyncronized() const {return m_synchronized;};
  std::string ToString() const;
  std::string OutputOnly(std::vector<var_type> types, std::string name, std::string indent, char cc) const;
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

  std::string ListSynchronizedVariables(std::string indent) const;
  std::string ListAssignmentDifferencesFrom(const Module* origmod, std::string mname, std::string indent) const;
#ifndef NSBML
  void  LoadSBML(const SBMLDocument* sbmldoc);
  const SBMLDocument* GetSBML();
  void  CreateSBMLModel();
  void  SetAssignmentFor(Model* sbmlmod, const Variable* var);
#endif

#ifndef NCELLML
  void  LoadCellMLModel(cellml_api::Model* model);
  void  LoadConnections(cellml_api::ConnectionSet* connections);
  void  LoadCellMLComponent(cellml_api::CellMLComponent* component);
  const cellml_api::Model* GetCellMLModel();
  void  CreateCellMLModel();
  cellml_api::CellMLComponent* CreateCellMLComponentFor(cellml_api::Model* model);
#endif

  void  FixNames();
};

#include "userfunction.h"


#endif //MODULE_H
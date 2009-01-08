#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <set>

#include <sbml/SBMLTypes.h>

#include "antimony_api.h"
#include "variable.h"
#include "reaction.h"

class ReactionList;

class Module
{
private:
  Module() {}; //undefined

  //Module(const Module& src); //Use default, but have to re-run CompileExportLists
  //Module& operator=(const Module& src); //(same as above)

  std::string m_modulename;
  std::vector<std::string> m_variablename;

  std::vector<Variable*> m_variables;
  std::vector<std::vector<std::string> > m_exportlist;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > m_synchronized;
  std::vector<std::string> m_returnvalue;

  size_t m_currentexportvar;

  Model m_sbml;
  std::string m_libsbml_info;
  std::string m_libsbml_warnings;
  
public:

  //Storage vectors for output:
  std::vector<std::vector<std::string> > m_uniquevars;

  Module(std::string name);
  //Module(const Module& src); //accept default
  Module(const Module& src, std::string newtopname, std::string modulename);
  ~Module() {};

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

  const std::string& GetModuleName() const;
  std::string GetVariableNameDelimitedBy(char cc) const;
  std::vector<std::pair<std::vector<std::string>, std::vector<std::string> > > GetSyncronized() const {return m_synchronized;};
  std::string ToString() const;
  std::string GetAntimony(set<const Module*> usedmods) const;
  std::string GetJarnacReactions() const;
  std::string GetJarnacVarFormulas() const;
  std::string GetJarnacConstFormulas(std::string modulename) const;


  //Output for the API
  bool Finalize();
  std::string GetSBMLInfo() const {return m_libsbml_info;};
  std::string GetSBMLWarnings() const {return m_libsbml_warnings;};
  size_t GetNumVariablesOfType(return_type rtype) const;
  const Variable* GetNthVariableOfType(return_type rtype, size_t n) const;
  bool   AreEquivalent(return_type rtype, var_type vtype) const;
  bool   AreEquivalent(return_type rtype, bool isconst) const;

  std::string ListSynchronizedVariables(std::string indent) const;
  std::string ListAssignmentDifferencesFrom(const Module* origmod, std::string mname, std::string indent) const;
  void  LoadSBML(const Model* sbml);
  Model GetSBMLModel();
  void  CreateSBMLModel();
};

#endif //MODULE_H

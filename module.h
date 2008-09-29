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

  std::vector<Variable> m_variables;
  std::vector< std::vector<std::string> > m_exportlist;
  std::vector<std::string> m_returnvalue;

  std::vector<std::string> m_currentrxnvar;

  size_t m_currentexportvar;

  Model m_sbml;
  
public:

  //Storage vectors for output:
  std::vector<std::vector<std::string> > m_uniquevars;
  std::vector<std::vector<std::string> > m_rxnleftvarnames;
  std::vector<std::vector<std::string> > m_rxnrightvarnames;
  std::vector<std::vector<double> >      m_rxnleftstoichiometries;
  std::vector<std::vector<double> >      m_rxnrightstoichiometries;

  std::vector<std::vector<std::string> > m_dna;

  Module(std::string name);
  //Module(const Module& src); //accept default
  Module(const Module& src, std::string newtopname, std::string modulename);
  ~Module() {};

  Variable* AddOrFindVariable(const std::string* name);
  Variable* AddNewNumberedVariable(const std::string name);
  void AddVariableToExportList(Variable* var);
  AntimonyReaction* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula);
  AntimonyReaction* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var);
  bool SetFormula(Formula* formula);

  Variable* GetVariable(std::vector<std::string> name);
  const Variable* GetVariable(std::vector<std::string> name) const;
  Variable* GetSubVariable(const std::string* name);
  Variable* GetReactionVariable();
  const Formula* GetFormula() const;
  Formula* GetFormula();
  Variable* GetNextExportVariable();
  size_t GetNumExportVariables() const {return m_exportlist.size();};
  Variable* GetUpstreamDNA();
  const Variable* GetUpstreamDNA() const;
  Variable* GetDownstreamDNA();
  std::vector<std::string> GetNewCrossModuleDNALinks() const;

  const std::string& GetModuleName() const;
  std::vector<std::string> GetVariableName() const;
  std::string GetVariableNameDelimitedBy(char cc) const;

  void SetNewTopName(std::string newmodname, std::string newtopname);
  void SetReactionVariable(Variable* var);
  bool ImportModule(const std::string* modname);
  
  std::string ToString() const;
  std::string GetAntimony(set<const Module*> usedmods) const;
  std::string GetJarnacReactions() const;
  std::string GetJarnacVarFormulas() const;
  std::string GetJarnacConstFormulas(std::string modulename) const;


  //Output for the API
  void CompileExportLists();
  size_t GetNumVariablesOfType(return_type rtype) const;
  const Variable* GetNthVariableOfType(return_type rtype, size_t n) const;
  bool   AreEquivalent(return_type rtype, var_type vtype) const;
  bool   AreEquivalent(return_type rtype, bool isconst) const;
  var_type GetTypeFor(std::string varname) const;
  bool     IsConst(std::string varname) const;

  std::string ListIdentityDifferencesFrom(const Module* origmod, std::string mname) const;
  std::string ListAssignmentDifferencesFrom(const Module* origmod, std::string mname, std::string indent) const;
  void  LoadSBML(const Model* sbml);
  Model GetSBMLModel();
  void  CreateSBMLModel();
};

#endif //MODULE_H

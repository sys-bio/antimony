#ifndef MODULE_H
#define MODULE_H

#include <string>
#include <vector>
#include <set>

#include "antimony_api.h"
#include "variable.h"
#include "reaction.h"

class ReactionList;

class Module
{
private:
  Module() {}; //undefined
  //Module(const Module& src); //Must define!  Lots of pointers must change!
  //Module& operator=(const Module& src); //(uses the above)

  std::string m_modulename;
  std::vector<std::string> m_variablename;

  std::vector<Variable> m_variables;
  std::vector< std::vector<std::string> > m_exportlist;
  std::vector<std::string> m_returnvalue;

  std::vector<std::string> m_currentrxnvar;

  size_t m_currentexportvar;

public:

  //Storage vectors for output:
  std::vector<std::vector<std::string> > m_uniquevars;
  std::vector<std::vector<std::string> > m_rxnleftvarnames;
  std::vector<std::vector<std::string> > m_rxnrightvarnames;
  std::vector<rd_type>                   m_rxntypes;
  std::vector<std::vector<double> >      m_rxnleftstoichiometries;
  std::vector<std::vector<double> >      m_rxnrightstoichiometries;

  std::vector<std::vector<std::string> > m_dna;

  Module(std::string name);
  Module(const Module& src);
  Module(const Module& src, std::string newtopname, std::string modulename);
  ~Module() {};

  Variable* AddOrFindVariable(const std::string* name);
  Variable* AddNewNumberedVariable(const std::string name);
  void AddVariableToExportList(Variable* var);
  Reaction* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula);
  Reaction* AddNewReaction(ReactantList* left, rd_type divider, ReactantList* right, Formula* formula, Variable* var);
  void SetFormula(Formula* formula);

  Variable* GetVariable(std::vector<std::string> name);
  const Variable* GetVariable(std::vector<std::string> name) const;
  Variable* GetSubVariable(const std::string* name);
  Variable* GetReactionVariable();
  const Formula* GetFormula() const;
  Formula* GetFormula();
  Variable* GetNextExportVariable();
  Variable* GetUpstreamDNA();
  Variable* GetDownstreamDNA();

  const std::string& GetModuleName() const;
  std::vector<std::string> GetVariableName() const;

  void SetNewTopName(std::string newtopname);
  void SetNamespace(std::string modulename);
  void SetReactionVariable(Variable* var);
  void ImportModule(const std::string* modname);
  
  std::string ToString() const;
  std::string GetJarnacReactions() const;
  std::string GetJarnacVarFormulas();
  std::string GetJarnacConstFormulas(std::string modulename);

  //Output for the API
  void CompileExportLists();
  size_t GetFirstVariableIndexForType(return_type rtype);
  size_t GetNumVariablesOfType(return_type rtype);
  const Variable* GetNthVariableOfType(return_type rtype, size_t n);
  bool   AreEquivalent(return_type rtype, var_type vtype);
  bool   AreEquivalent(return_type rtype, bool isconst);
};

#endif //MODULE_H

#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include "formula.h"
#include "reaction.h"

class Module;

class Variable
{
private:
  Variable(); //Undefined
  //Variable(const Variable& src); //Accept the default (?)
  //Variable& operator=(const Variable& src); //Undefined

  std::vector<std::string> m_name;
  std::vector<std::string> m_printedname;
  std::string m_namespace; //The name of the high-level module we're in.

  //The variable's value is either a different Variable object (with a different name):
  std::vector<std::string> m_sameVariable;
  bool m_listseparately;

  //Or, one (and only one!) of the following:
  Formula m_valFormula;
  AntimonyReaction m_valReaction;
  std::vector<Module> m_valModule;

  //If the variable is in a strand of DNA, this tells us how they are related
  std::vector<std::string> m_upstream;
  std::vector<std::string> m_downstream;

  //This tells us what kind of variable we're dealing with.
  var_type m_type;

  //Additionally, the variable might be set constant
  bool m_const;

public:
  Variable(const std::string name, const Module* module);
  ~Variable() {};


  bool IsPointer() const {return m_sameVariable.size() != 0;};
  std::vector<std::string> GetName() const;
  std::vector<std::string> GetPointerName() const {return m_sameVariable;};
  std::string GetNameDelimitedBy(char cc) const;
  std::string GetFormulaStringDelimitedBy(char cc) const;
  var_type GetType() const;
  bool HasFormula() const {return (!m_valFormula.IsEmpty());};
  const Formula* GetFormula() const;
  Formula* GetFormula();
  const AntimonyReaction* GetReaction() const;
  const Module* GetModule() const;
  Module* GetModule();
  Variable* GetSubVariable(const std::string* name);
  Variable* GetUpstreamDNA() const;
  Variable* GetDownstreamDNA() const;
  std::string GetNamespace() const {return m_namespace;};
  bool GetIsConst() const;
  bool GetListSeparately() const {return m_listseparately;};
  bool GetIsEquivalentTo(const Variable* var) const;

  bool IsDNAStart() const;
  bool IsUnlinked(bool up) const;
  bool DoesNotLinkTo(Variable* var) const;
  bool HasOpenUpstream() const;
  bool HasOpenDownstream() const;
  std::vector<std::string> GetDNAStringDelimitedBy(char cc) const;

  bool SetType(var_type newtype);
  bool SetFormula(Formula* formula);
  AntimonyReaction* SetReaction(AntimonyReaction* rxn);
  void SetNewTopName(std::string newmodname, std::string newtopname);
  void SetPrintedName(std::vector<std::string> printedname);
  bool SetIsConst(bool constant);
  void SetListSeparately(bool ls) {m_listseparately = ls;};

  void SetOpenUpstream();
  void SetOpenDownstream();
  void SetDownstream(Variable* var);
  void SetUpstream(Variable* var);

  bool Synchronize(Variable* clone);
  bool ImportModule(const std::string* modname);

  bool CheckDoesNotIncludeSelf();
  std::string ToString() const;
};


#endif //VARIABLE_H

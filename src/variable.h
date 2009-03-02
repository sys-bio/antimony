#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <set>
#include "dnastrand.h"
#include "event.h"
#include "formula.h"
#include "reaction.h"
#include "enums.h"

class Module;

class Variable
{
private:
  Variable(); //Undefined
  //Variable(const Variable& src); //Accept the default (?)
  //Variable& operator=(const Variable& src); //Undefined

  std::vector<std::string> m_name;
  std::string m_module; //The name of the high-level module we're in.

  //The variable's value is either a different Variable object (with a different name):
  std::vector<std::string> m_sameVariable;

  //Or, one (and only one!) of the following:
  Formula m_valFormula;
  AntimonyReaction m_valReaction;
  std::vector<Module> m_valModule;
  AntimonyEvent m_valEvent;
  DNAStrand m_valStrand;

  //If we've set the compartment we're in, this tells us where we are.
  std::vector<std::string> m_compartment;
  std::vector<std::string> m_supercompartment;
  var_type m_supercomptype;
  std::set<std::vector<std::string> > m_strands;

  //This tells us what kind of variable we're dealing with.
  var_type m_type;

  //Additionally, the variable might be set constant
  const_type m_const;

public:
  Variable(const std::string name, const Module* module);
  ~Variable() {};


  bool IsPointer() const {return m_sameVariable.size() != 0;};
  std::vector<std::string> GetName() const;
  std::vector<std::string> GetPointerName() const {return m_sameVariable;};
  std::string GetNameDelimitedBy(char cc) const;
  std::string GetFormulaStringDelimitedBy(char cc) const;
  std::string GetFormulaStringWithEllipses(char cc) const;
  var_type GetType() const;
  bool HasFormula() const {return (!m_valFormula.IsEmpty());};
  const Formula* GetFormula() const;
  Formula* GetFormula();
  const AntimonyReaction* GetReaction() const;
  Module* GetModule();
  const AntimonyEvent* GetEvent() const;
  AntimonyEvent* GetEvent();
  Variable* GetSubVariable(const std::string* name);
  Variable* GetSameVariable() const;
  const DNAStrand* GetDNAStrand() const;
  Variable* GetCompartment() const;
  bool GetIsSetCompartment() const {return (m_compartment.size() != 0);};
  std::string GetNamespace() const {return m_module;};
  bool GetIsConst() const;
  const_type GetConstType() const {return m_const;};
  bool GetIsEquivalentTo(const Variable* var) const;
  std::vector<std::pair<Variable*, size_t> > GetStrandVars() const;
  bool IsExpandedStrand() const;
  std::string GetFormulaForNthEntryInStrand(char cc, size_t n);

  bool SetType(var_type newtype);
  bool SetFormula(Formula* formula);
  bool SetReaction(AntimonyReaction* rxn);
  bool SetModule(const std::string* modname);
  bool SetEvent(const AntimonyEvent* event);
  void SetNewTopName(std::string newmodname, std::string newtopname);
  bool SetIsConst(bool constant);
  void SetRegConst();

  bool SetCompartment(Variable* var);
  void SetComponentCompartments(bool from_module);
  bool SetSuperCompartment(Variable* var, var_type supertype);
  bool SetDNAStrand(DNAStrand& strand);
  bool SetIsInStrand(Variable* var);

  bool Synchronize(Variable* clone);

  bool IncludesSelf();
  bool AnyCompartmentLoops() const;
  bool AnyCompartmentLoops(std::vector<const Variable*> lowercomps) const;
  std::string ToString() const;
  void FixNames();
};


#endif //VARIABLE_H

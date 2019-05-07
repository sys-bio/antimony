#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include <vector>
#include <set>
#include "annotated.h"
#include "constraint.h"
#include "dnastrand.h"
#include "event.h"
#include "formula.h"
#include "reaction.h"
#include "unitdef.h"
#include "enums.h"

#ifndef NCELLML
#include "cellmlx.h"
#endif

#ifndef NSBML
#include "sbml/SBMLTypes.h"
#endif

class Module;
class UnitDef;
class SboTermWrapper;

class Variable : public Annotated
{
private:
  //Variable(const Variable& src); //Accept the default (?)
  //Variable& operator=(const Variable& src); //Undefined

  std::vector<std::string> m_name;
  std::string m_module; //The name of the high-level module we're in.
  std::string m_displayname;

  //The variable's value is either a different Variable object (with a different name):
  std::vector<std::string> m_sameVariable;

  //Or, one (and only one!) of the following:
  Formula m_valFormula;
  AntimonyReaction m_valReaction;
  std::vector<Module> m_valModule;
  AntimonyEvent m_valEvent;
  DNAStrand m_valStrand;
  UnitDef m_valUnitDef;
  AntimonyConstraint m_valConstraint;

  //Some parameters and species can have rate rules in addition to initial assignments:
  Formula m_valRateRule;
  formula_type m_formulatype;

  //If the variable is a submodule, it can have conversion factors and deletions.
  std::vector<std::string> m_extentConversionFactor;
  std::vector<std::string> m_timeConversionFactor;
protected:
  std::set<std::pair<std::vector<std::string>, deletion_type> > m_deletions;
  friend class Module;

  //This tells us what kind of variable we're dealing with.
  var_type m_type;

  Variable() : m_valUnitDef("nounit", "nomodule") {}

  // Subclass which is used as a wrapper for setting SBO terms
  SboTermWrapper* m_sboTermWrapper;
private:
  //If we've set the compartment we're in, this tells us where we are.
  std::vector<std::string> m_compartment;
  std::vector<std::string> m_supercompartment;
  var_type m_supercomptype;
  std::set<std::vector<std::string> > m_strands;

  //When we are a deleted variable, it makes a difference to SBML whether or not we used to be a unit
  bool m_deletedunit;

  //If we are a submodel reaction that has been replaced, we need to know this because of time and extent conversion factors.
  bool m_replacedformrxn;

  //Additionally, the variable might be set constant
  const_type m_const;

  //Also, a species might be set hasOnlySubstanceUnits
  bool m_substOnly;

  //Also, the variable might have a unit associated with it.
  std::vector<std::string> m_unitVariable;

#ifndef NCELLML
  //If we are using CellML, this is a link to the corresponding variable in that document.
  ObjRef<iface::cellml_api::CellMLVariable> m_cellmlvariable;
  Variable* m_canonvar;
#endif

public:
  Variable(const std::string name, const Module* module);
  Variable(const Variable& other);
  ~Variable();


  bool IsPointer() const {return m_sameVariable.size() != 0;};
  const std::vector<std::string>& GetName() const;
  std::vector<std::string> GetPointerName() const {return m_sameVariable;};
  std::string GetNameDelimitedBy(std::string cc) const;
  var_type GetType() const;
  bool HasFormula() const {return (!m_valFormula.IsEmpty());};
  formula_type GetFormulaType() const;
  const Formula* GetFormula() const;
  Formula* GetFormula();
  const Formula* GetInitialAssignment() const;
  const Formula* GetAssignmentRuleOrKineticLaw() const;
  Formula* GetAssignmentRuleOrKineticLaw();
  const Formula* GetRateRule() const;
  Formula* GetRateRule();
  const AntimonyReaction* GetReaction() const;
  AntimonyReaction* GetReaction();
  Module* GetModule();
  const Module* GetModule() const;
  AntimonyEvent* GetEvent();
  const AntimonyEvent* GetEvent() const;
  UnitDef* GetUnitDef();
  const UnitDef* GetUnitDef() const;
  AntimonyConstraint* GetConstraint();
  const AntimonyConstraint* GetConstraint() const;

  Variable* GetSubVariable(const std::string* name);
  Variable* GetSameVariable();
  const Variable* GetSameVariable() const;
  const DNAStrand* GetDNAStrand() const;
  Variable* GetCompartment() const;
  bool GetIsSetCompartment() const {return (m_compartment.size() != 0);};
  std::string GetNamespace() const {return m_module;};
  void SetNamespace(const std::string& modname) {m_module = modname;};
  bool GetIsConst() const;
  const_type GetConstType() const {return m_const;};
  bool GetSubstOnly() const {return m_substOnly;};
  bool GetIsEquivalentTo(const Variable* var) const;
  std::vector<std::pair<Variable*, size_t> > GetStrandVars() const;
  bool IsExpandedStrand() const;
  std::string GetFormulaForNthEntryInStrand(std::string cc, size_t n);
  std::string GetDisplayName() const;
  bool IsDeletedUnit() const {return m_deletedunit;}
  void SetIsDeletedUnit(bool del) {m_deletedunit = del;}

  Variable* GetUnitVariable() const;
  bool SetUnitVariable(std::string);
  bool SetUnitVariable(Variable* unitvar);

  virtual bool SetType(var_type newtype);
  virtual bool SetFormula(Formula* formula, bool isObjective=false);
  bool SetAssignmentRule(Formula* formula);
  bool SetRateRule(Formula* formula);
  bool SetReaction(AntimonyReaction* rxn);
  bool SetModule(const std::string* modname);
  bool SetEvent(const AntimonyEvent* event);
  bool SetConstraint(const AntimonyConstraint* constraint);

  void SetNewTopName(std::string newmodname, std::string newtopname);
  bool SetIsConst(bool constant);
  bool SetSubstOnly(bool substonly);
  void SetRegConst();
  void SetRegSpecVals();

  bool SetCompartment(Variable* var);
  void SetComponentCompartments(bool from_module);
  bool SetSuperCompartment(Variable* var, var_type supertype);
  bool SetDNAStrand(DNAStrand& strand);
  bool SetIsInStrand(Variable* var);
  bool SetDisplayName(std::string name);
  bool SetUnitDef(const UnitDef* unitdef);
  bool SetUnit(Variable* var);
  /// Takes care of edge cases with built-in units in submodules
  std::string GetNameOrBuiltin(std::string cc) const;
  // JKM: kind of a hack right now
  /// Returns true if is an SBML built-in unit, false otherwise
  bool IsBuiltin() const;

  void AddDeletion(Variable* var, deletion_type deltype);
  void AddDeletion(std::vector<std::string> varname, deletion_type deltype);
  bool HasDeletion(std::vector<std::string> varname, deletion_type deltype);

  //Submodule conversion factors:
  bool SetExtentConversionFactor(Variable* var);
  bool SetTimeConversionFactor(Variable* var);
  bool SetExtentConversionFactor(double val);
  bool SetTimeConversionFactor(double val);
  Variable* GetExtentConversionFactor();
  Variable* GetTimeConversionFactor();
  std::set<std::pair<std::vector<std::string>, deletion_type> > GetDeletions() const;

  //Submodule deletions:
  bool DeleteFromSubmodel(Variable* deletedvar);
  std::set<std::pair<std::vector<std::string>, deletion_type> > ClearReferencesTo(Variable* deletedvar);

  bool Synchronize(Variable* clone, const Variable* conversionFactor);
#ifndef NSBML
  //bool Synchronize(Variable* clone, SBase* foo);
  void SetWithRule(const Rule* rule);
#endif

  bool IncludesSelf();
  bool AnyCompartmentLoops() const;
  bool AnyCompartmentLoops(std::vector<const Variable*> lowercomps) const;
  std::string ToString() const;
  void FixNames();
  void ClearSameName() {m_sameVariable.clear();};
  bool StillMatchesOriginal(formula_type ftype) const;
  const Variable* GetOriginal() const;
  Variable* GetParentVariable();

  bool IsReplacedFormRxn() const {return m_replacedformrxn;};


#ifndef NCELLML
  Variable* GetCanonicalVariable() {return m_canonvar;};
  void SetCanonicalVariable(Variable* cvar) {m_canonvar = cvar;};
  iface::cellml_api::CellMLVariable* GetCellMLVariable() {m_cellmlvariable->add_ref(); return m_cellmlvariable;};
  void SetCellMLVariable(iface::cellml_api::CellMLVariable* cmlvar) {m_cellmlvariable = cmlvar;};
#endif
};

#endif //VARIABLE_H

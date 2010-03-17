#ifndef REGISTRY_H
#define REGISTRY_H

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>
#include <sstream>

#include "dnastrand.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "enums.h"


#ifndef NCELLML
#include <IfaceCellML_APISPEC.hxx>
#include <CellMLBootstrap.hpp>

#define CELLML_BOOTSTRAP_CONTRACTID "@cellml.org/cellml-bootstrap;1"

#endif

#define MAINMODULE "__main"
#ifndef VERSION_STRING //So we can define it in the makefile if need be.
#define VERSION_STRING "v1.3"
#endif

class Registry
{
private:
  std::vector<std::istream*> m_oldinputs;
  std::vector<std::string>   m_files;
  std::set<std::string>      m_variablenames;
  std::vector<std::string>   m_functions;

  std::set<Variable*>      m_storedvars;
  std::set<Formula*>       m_storedformulas;

  std::vector<Module> m_modules;
  std::vector<std::string> m_currentModules;
  std::vector<ReactantList> m_currentReactantLists;
  std::vector<std::string> m_currentImportedModule;
  DNAStrand m_workingstrand;

  std::vector<UserFunction> m_userfunctions;
  std::vector<std::string>  m_userfunctionnames;
  bool m_isfunction;

  std::vector<std::string> m_currentEvent;
  
  char m_cc;
  const_type m_constness;
  std::string m_error;
  std::vector<std::vector<Module> > m_oldmodules;
  std::vector<std::vector<UserFunction> > m_olduserfunctions;

public:
  Registry();
  ~Registry();

  //Sometimes we need to pass a blank formula instead of a NULL pointer
  Formula m_blankform;

  std::istream* input;

  void ClearModules();
  void FreeVariables();
  void FreeFormulas();
  void ClearAll();

  int    OpenFile(const std::string& filename);
  int    OpenString(std::string model);
#ifndef NSBML
  int    CheckAndAddSBMLIfGood(SBMLDocument* document);
#endif
#ifndef NCELLML
  bool   LoadCellML(nsCOMPtr<cellml_apiIModel> model);
  bool   LoadConnections(nsCOMPtr<cellml_apiIConnectionSet> connections, nsCOMPtr<cellml_apiIModel> topmodel);
  bool   SynchronizeCellMLConnection(nsCOMPtr<cellml_apiIConnection> connection, nsCOMPtr<cellml_apiIModel> topmodel);
#endif
  bool   SwitchToPreviousFile();
  size_t GetNumFiles() {return m_oldmodules.size();};
  void   SetupFunctions();

  //Modules
  void NewCurrentModule(const std::string* name);
  Module* CurrentModule();
  void RevertToPreviousModule();

  //Functions
  void NewUserFunction(const std::string* name);
  bool SetUserFunction(Formula* formula);

  //Variables
  void SetConstness(const_type isconst) {m_constness = isconst;};
  void AddVariableToCurrentExportList(Variable* export_var);
  bool AddVariableToCurrentImportList(Variable* import_var);
  Variable* AddVariableToCurrent(const std::string* name);
  Variable* AddNewReactionToCurrent(rd_type divider, Formula* formula);
  Variable* AddNewReactionToCurrent(rd_type divider, Formula* formula, Variable* var);
  ReactantList* NewBlankReactantList();
  Formula* NewBlankFormula();
  void SetCurrentImportedModule(std::vector<std::string> imod) {m_currentImportedModule = imod;}
  Variable* NewVariableIfNeeded(Variable* var, bool up);

  //DNA strands:
  bool SetStrandAs(Variable* var);
  bool SaveWorkingStrand();
  bool SetNewUpstreamOpen(Variable* var);
  void SetOpenUpstream();
  bool SetDownstreamEnd(Variable* var);
  bool SetNewDownstreamOpen(Variable* var);
  bool SetDownstreamOpen(Variable* var);

  //Events
  bool SetNewCurrentEvent(Formula* trigger);
  bool SetNewCurrentEvent(Formula* delay, Formula* trigger);
  bool SetNewCurrentEvent(Formula* trigger, Variable* var);
  bool SetNewCurrentEvent(Formula* delay, Formula* trigger, Variable* var);
  bool AddResultToCurrentEvent(Variable* var, Formula* form);
  bool SetCompartmentOfCurrentSubmod(Variable* var);

  void SetError(std::string error) {m_error = error;};
  void AddErrorPrefix(std::string error) {m_error = error + m_error;};

  std::string GetLastFile();
  Module* GetModule(std::string modulename);
  const Module* GetModule(std::string modulename) const;
  bool IsModuleName(std::string word);

  const_type GetConstness() const {return m_constness;};
  const std::string* AddWord(std::string word);
  void StoreVariable(Variable* var);
  const std::string* IsFunction(std::string word);

  std::string GetAntimony() const;
  std::string GetAntimony(std::string modulename) const;
  std::string GetJarnac(std::string modulename) const;

  bool FinalizeModules();

  size_t GetNumModules();
  std::string GetNthModuleName(size_t n);
  char GetCC() {return m_cc;};
  std::string GetError() {return m_error;};
  long SaveModules();
  bool RevertToModuleSet(long n);

  size_t GetNumUserFunctions() const {return m_userfunctions.size();};
  const UserFunction* GetNthUserFunction(size_t n) const;
  UserFunction* GetNthUserFunction(size_t n);
  void FixTimeInFunctions();

  //Keeping track of malloc'd stuff so we can free it ourselves if need be.
  std::vector<char*>    m_charstars;
  std::vector<char**>   m_charstarstars;
  std::vector<char***>  m_charstarstarstars;
  std::vector<double*>  m_doublestars;
  std::vector<double**> m_doublestarstars;
  std::vector<unsigned long*> m_ulongstars;
  std::vector<rd_type*> m_rd_typestars;
  void FreeAll();
};

extern Registry g_registry;


#endif //REGISTRY_H

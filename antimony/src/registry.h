#ifndef REGISTRY_H
#define REGISTRY_H

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <set>
#include <stdio.h>
#include <string>

#include "dnastrand.h"
#include "module.h"
#include "reactantlist.h"
#include "reaction.h"
#include "rd_type.h"

#define MAINMODULE "__main"

class Registry
{
private:
  std::vector<std::ifstream*> m_oldinputs;
  std::vector<std::string>    m_files;
  std::set<std::string>       m_variablenames;
  std::vector<std::string>    m_functions;

  std::set<Variable*>      m_storedvars;

  std::vector<Module> m_modules;
  std::vector<std::string> m_currentModules;
  std::vector<ReactantList> m_currentReactantLists;
  std::vector<std::string> m_currentImportedModule;
  Formula m_scratchFormula;
  std::vector<Formula> m_scratchFormulas;
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

  std::ifstream* input;

  void ClearModules();
  void FreeVariables();
  void ClearAll();

  int    OpenFile(const std::string filename);
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
  Variable* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula);
  Variable* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula, Variable* var);
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
  bool SetNewCurrentEvent(Formula* trigger, Variable* var);
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

  //Keeping track of malloc'd stuff so we can free it ourselves if need be.
  std::vector<char*>    m_charstars;
  std::vector<char**>   m_charstarstars;
  std::vector<char***>  m_charstarstarstars;
  std::vector<double*>  m_doublestars;
  std::vector<double**> m_doublestarstars;
  std::vector<size_t*>  m_size_tstars;
  std::vector<rd_type*> m_rd_typestars;
  void FreeAll();
};

extern Registry g_registry;


#endif //REGISTRY_H

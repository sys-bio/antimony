#ifndef REGISTRY_H
#define REGISTRY_H

#include <ctype.h>
#include <fstream>
#include <iostream>
#include <math.h>
#include <sbml/SBMLTypes.h>
#include <set>
#include <stdio.h>
#include <string>

#include "module.h"
#include "reactantlist.h"
#include "reaction.h"


class Registry
{
private:
  std::vector<std::ifstream*> m_oldinputs;
  std::vector<std::string>    m_files;
  std::set<std::string>       m_variablenames;
  std::vector<std::string>    m_functions;

  std::vector<Module> m_modules;
  std::vector<std::string> m_currentModules;
  std::vector<ReactantList> m_currentReactantLists;
  std::vector<std::string> m_currentImportedModule;
  Formula m_scratchFormula;
  std::vector<std::string> m_workingstrand;
  std::vector<std::string> m_assignmentvar;
  
  char m_cc;
  std::string m_error;
  std::vector<std::vector<Module> > m_oldmodules;

public:
  Registry();
  ~Registry() {};

  std::ifstream* input;

  void ClearModules();

  bool OpenFile(const std::string filename);
  bool SwitchToPreviousFile();
  size_t GetNumFiles() {return m_oldmodules.size();};
  void SetupFunctions();

  void NewCurrentModule(const std::string* name);
  Module* CurrentModule();
  void RevertToPreviousModule();
  void AddVariableToCurrentExportList(Variable* export_var);
  bool AddVariableToCurrentImportList(Variable* import_var);
  Variable* AddVariableToCurrent(const std::string* name);
  AntimonyReaction* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula);
  AntimonyReaction* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula, Variable* var);
  ReactantList* NewBlankReactantList();
  Formula* NewBlankFormula();
  void SetCurrentImportedModule(std::vector<std::string> imod) {m_currentImportedModule = imod;}
  void SetAssignmentVariable(Variable* var);
  Variable* NewVariableIfNeeded(Variable* var, bool up);
  bool SetNewUpstreamOpen(Variable* var);
  bool SetDownstreamEnd(Variable* var);
  bool SetNewDownstreamOpen(Variable* var);
  bool SetDownstreamOpen(Variable* var);
  void SetWorkingStrand(Variable* var);
  void SetError(std::string error) {m_error = error;};
  void AddErrorPrefix(std::string error) {m_error = error + m_error;};

  std::string GetLastFile();
  Module* GetModule(std::string modulename);
  //const Module* GetModule(std::string modulename) const;
  bool IsModuleName(std::string word);
  Variable* GetImportedModuleSubVariable(const std::string* name);
  Variable* GetWorkingStrand();
  Variable* GetAssignmentVariable();

  const std::string* AddWord(std::string word);
  const std::string* IsFunction(std::string word);

  std::string GetJarnac(std::string modulename);

  void CompileAllExportLists();

  size_t GetNumModules();
  std::string GetNthModuleName(size_t n);
  char GetCC() {return m_cc;};
  std::string GetError() {return m_error;};
  long SaveModules();
  bool RevertToModuleSet(long n);
  void ClearOldModules();

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

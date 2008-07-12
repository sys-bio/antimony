#ifndef REGISTRY_H
#define REGISTRY_H

#include <math.h>
#include <stdio.h>
#include <string>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <set>
#include "module.h"
#include "reaction.h"
#include "reactantlist.h"
//#include "calculator.h"

class Registry
{
private:
  std::vector<Module> m_modules;
  std::vector<std::string> m_currentModules;
  std::vector<ReactantList> m_currentReactantLists;
  std::vector<std::string> m_currentImportedModule;
  Formula m_scratchFormula;
  std::vector<std::string> m_workingstrand;
  std::vector<std::string> m_assignmentvar;
  std::string m_mainmodulename;
  std::string m_jarnac;
  char m_cc;

public:
  Registry();
  ~Registry() {};

  std::ifstream input;
  std::set<std::string> variablenames;

  void ClearModels();

  void NewCurrentModule(const std::string* name);
  Module* CurrentModule();
  void RevertToPreviousModule();
  void AddVariableToCurrentExportList(Variable* export_var);
  void AddVariableToCurrentImportList(Variable* import_var);
  Variable* AddVariableToCurrent(const std::string* name);
  Reaction* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula);
  Reaction* AddNewReactionToCurrent(ReactantList* left_react, rd_type divider, ReactantList* right_react, Formula* formula, Variable* var);
  ReactantList* NewBlankReactantList();
  Formula* NewBlankFormula();
  void SetMainModuleName(const char* filename);
  void SetCurrentImportedModule(std::vector<std::string> imod) {m_currentImportedModule = imod;}
  void SetAssignmentVariable(Variable* var);
  Variable* NewVariableIfNeeded(Variable* var, bool up);
  void SetNewUpstreamOpen(Variable* var);
  void SetDownstreamEnd(Variable* var);
  void SetNewDownstreamOpen(Variable* var);
  void SetDownstreamOpen(Variable* var);
  void SetWorkingStrand(Variable* var);

  Module* GetModule(std::string modulename);
  //const Module* GetModule(std::string modulename) const;
  bool IsModuleName(std::string word);
  Variable* GetImportedModuleSubVariable(const std::string* name);
  Variable* GetWorkingStrand();
  Variable* GetAssignmentVariable();

  const std::string* AddWord(std::string word);

  const std::string* GetJarnac(std::string modulename);

  size_t GetNumModules();
  std::string GetNthModuleName(size_t n);
  char GetCC() {return m_cc;};

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

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
#include "cellmlx.h"
#endif

#define MAINMODULE "__main"
#ifndef LIBANTIMONY_VERSION_STRING //Should be created in the makefile (CMakeLists.txt)
#define LIBANTIMONY_VERSION_STRING "v2.12.0"
#endif

class Registry
{
private:
  std::vector<std::istream*> m_oldinputs;
  std::vector<std::string>   m_files;
  std::vector<std::string>   m_directories;
  std::set<std::string>      m_variablenames;
  std::vector<std::string>   m_functions;
  std::vector<std::string>   m_constants;

  std::set<Variable*>      m_storedvars;
  std::set<Formula*>       m_storedformulas;

  std::vector<Module> m_modules;
  std::map<std::string, size_t> m_modulemap;
  std::vector<std::string> m_currentModules;
  std::vector<ReactantList> m_currentReactantLists;
  std::vector<std::string> m_currentImportedModule;
  DNAStrand m_workingstrand;

  std::vector<UserFunction> m_userfunctions;
  std::vector<std::string>  m_userfunctionnames;
  bool m_isfunction;

  std::vector<std::string> m_currentEvent;
  
  std::string m_cc;
  const_type m_constness;
  bool m_substonly;
  std::string m_error;
  std::vector<std::string> m_warnings;
  std::vector<std::vector<Module> > m_oldmodules;
  std::vector<std::vector<UserFunction> > m_olduserfunctions;
  std::vector<std::map<std::string, size_t> > m_oldmodulemaps;

  std::map<std::pair<std::string, std::string>, std::string> m_sbindex;

  bool m_writeNameToSBML;
  bool m_writeTimestampToSBML;
  bool m_bareNumbersAreDimensionless;
  bool m_eof;

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

  void   AddDirectory(std::string directory);
  std::vector<std::string> GetDirectories();
  void   ClearDirectories();

  int    OpenFile(const std::string& filename, bool antOnly=false);
  int    OpenString(std::string model);
#ifndef NSBML
  int    CheckAndAddSBMLIfGood(libsbml::SBMLDocument* document);
  void   LoadSubmodelsFrom(libsbml::Model* model);
  bool   LoadModelFrom(std::string modelname, libsbml::SBMLDocument* document);
#endif
#ifndef NCELLML
  bool   LoadCellML(iface::cellml_api::Model* model);
  bool   LoadConnections(iface::cellml_api::ConnectionSet* connections);
  bool   SynchronizeCellMLConnection(iface::cellml_api::Connection* connection);
  std::map<std::string, std::string> m_cellmlnames;
#endif
  void   CreateLocalVariablesForSubmodelInterfaceIfNeeded();
  void   SetEOFFlag(); // adds a newline to the end of the file
  void   ClearEOFFlag();
  bool   GetEOFFlag() const; // returns the status of the eof flag
  bool   SwitchToPreviousFile();
  size_t GetNumFiles() {return m_oldmodules.size();};
  void   SetupFunctions();
  void   SetupConstants();
  std::string GetFilenameFrom(std::string thisfile, std::string import);
  void   ParseSBIndex();
  void   AddSBIndex(std::string sbi);
  bool   file_exists (const std::string& filename);

  //Modules
  bool NewCurrentModule(const std::string* name, const std::string* displayname=NULL, bool ismain=false);
  Module* CurrentModule();
  std::string CurrentModuleName();
  bool SetCurrentModuleIf(const std::string* modname, const std::string* annotation);
  void RevertToPreviousModule();

  //Functions
  void NewUserFunction(const std::string* name);
  bool SetUserFunction(Formula* formula);

  //Variables
  void SetConstness(const_type isconst) {m_constness = isconst;};
  void SetSubstOnly(bool substOnly) {m_substonly = substOnly;};
  bool AddVariableToCurrentExportList(Variable* export_var);
  bool AddVariableToCurrentImportList(Variable* import_var);
  bool AddNumberToCurrentImportList(double val);
  Variable* AddVariableToCurrent(const std::string* name);
  Variable* AddNewReactionToCurrent(rd_type divider, Formula* formula, int type);
  Variable* AddNewReactionToCurrent(rd_type divider, Formula* formula, Variable* var, int type);
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
  AntimonyEvent* GetCurrentEvent();
  Variable* GetCurrentSubmodel();

  void SetError(std::string error) {m_error = error;};
  void AddErrorPrefix(std::string error) {m_error = error + m_error;};
  void AddWarning(std::string warning) {m_warnings.push_back(warning);};
  void ClearWarnings() {m_warnings.clear();};

  std::string GetLastFile();
  Module* GetModule(std::string modulename);
  const Module* GetModule(std::string modulename) const;
  const Module* GetMainModule() const;
  Module* GetMainModule();
  bool IsModuleName(std::string word);

  const_type GetConstness() const {return m_constness;};
  bool GetSubstOnly() const {return m_substonly;};
  const std::string* AddWord(std::string word);
  void StoreVariable(Variable* var);
  const std::string* IsFunction(std::string word);
  const std::string* IsConstant(std::string word);

  std::string GetAntimony(bool enableAnnotations=true) const;
  std::string GetAntimony(std::string modulename, bool enableAnnotations=true) const;
  std::string GetJarnac(std::string modulename) const;

  bool FinalizeModules();

  size_t GetNumModules();
  std::string GetNthModuleName(size_t n);
  std::string GetCC() {return m_cc;};
  void        SetCC(std::string cc) {m_cc = cc;};
  std::string GetError() {return m_error;};
  std::vector<std::string> GetWarnings() {return m_warnings;};
  size_t SaveModules();
  bool RevertToModuleSet(long n);

  size_t GetNumUserFunctions() const {return m_userfunctions.size();};
  const UserFunction* GetNthUserFunction(size_t n) const;
  UserFunction* GetNthUserFunction(size_t n);
  UserFunction* GetUserFunction(std::string name);
  void FixTimeInFunctions();

  // CV terms
  bool ProcessGlobalCVTerm(const std::string* name, const std::string* qual, std::vector<std::string>* resources);

  bool ProcessCreatorTerm(Annotated* a, const std::string* creator, const std::string* cterm, std::vector<std::string>* resources);

  bool ProcessGlobalCreatorTerm(const std::string* name, const std::string* creator, const std::string* cterm, std::vector<std::string>* resources);

  bool CheckCreatorString(const std::string& qualifier, int& creator_number);

  //Keeping track of malloc'd stuff so we can free it ourselves if need be.
  std::vector<char*>    m_charstars;
  std::vector<char**>   m_charstarstars;
  std::vector<char***>  m_charstarstarstars;
  std::vector<double*>  m_doublestars;
  std::vector<double**> m_doublestarstars;
  std::vector<unsigned long*> m_ulongstars;
  std::vector<rd_type*> m_rd_typestars;
  void FreeAll();

  //For testing, we don't want to write our name/version to SBML files so that we can more easily compare the outputs to the expected outputs.
  void SetWriteNameToSBML(bool set);
  bool GetWriteNameToSBML();

  //Some people might not want to write the Timestamp to SBML files.
  void SetWriteTimestampToSBML(bool set);
  bool GetWriteTimestampToSBML();

  //Defaults
  void SetBareNumbersAreDimensionless(bool dimensionless);
  bool GetBareNumbersAreDimensionless();

  int  ConvertDistribAnnotation(libsbml::SBMLDocument* document);
};

extern Registry g_registry;


#endif //REGISTRY_H

#include <string>

#include "antimony_api.h"
#include "registry.h"


using namespace std;
extern int yyparse();

LIB_EXTERN const int loadModel(const char* filename)
{
  g_registry.ClearModels();  
  g_registry.input.open(filename, ios::in);
  if (!g_registry.input.is_open()) {
    string err_string = "Could not open \"";
    err_string += filename;
    err_string += "\".  "
      "Please check that this file:\n" 
      "	1) exists in directory that antimony is being run from,\n"
      "	2) is read enabled, and\n"
      "	3) is not in use by another program.\n";
    cerr << err_string << endl;	
    return 0;
  }

  if (!g_registry.input.good())
  {
	  cerr << "trouble" << endl;
  }

  g_registry.SetMainModuleName(filename);
  int retval = yyparse();
  g_registry.input.close();
  g_registry.GetModule("[main]")->CompileExportLists();
  cout << "Return value: " << retval << endl;
  return retval;
}

LIB_EXTERN const char* getJarnac(const char* moduleName)
{
  return g_registry.GetJarnac(moduleName)->c_str();
}

LIB_EXTERN const char** getModuleNames()
{
  g_registry.CompileModuleNames();
   return &(g_registry.m_modulenames[0]);
}

LIB_EXTERN const char*  getNthModuleName(size_t n)
{
  g_registry.CompileModuleNames();
  return g_registry.m_modulenames[n];
}

LIB_EXTERN const size_t getNumModuleNames()
{
  return g_registry.GetNumModules();
}

LIB_EXTERN const char** getSymbolNamesOfType(const char* moduleName, return_type rtype)
{
  size_t n = g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(rtype);
  return &(g_registry.GetModule(moduleName)->m_variablenames[n]);
}

LIB_EXTERN const char** getSymbolEquationsOfType(const char* moduleName, return_type rtype)
{
  size_t n = g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(rtype);
  return &(g_registry.GetModule(moduleName)->m_variableformulas[n]);
}

LIB_EXTERN const char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n)
{
  n += g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(rtype);
  return g_registry.GetModule(moduleName)->m_variablenames[n];
}

LIB_EXTERN const char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n)
{
  n += g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(rtype);
  return g_registry.GetModule(moduleName)->m_variableformulas[n];
}

LIB_EXTERN const size_t getNumSymbolsOfType(const char* moduleName, return_type rtype)
{
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
}


LIB_EXTERN const char** getAllSymbolNames(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_variablenames[0]);
}

LIB_EXTERN const char*  getNthSymbolName(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_variablenames[n];
}

LIB_EXTERN const char** getSymbolTypes(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_variabletypes[0]);
}

LIB_EXTERN const char*  getNthSymbolType(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_variabletypes[n];
}

LIB_EXTERN const char** getSymbolEquations(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_variableformulas[0]);
}

LIB_EXTERN const char*  getNthSymbolEquation(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_variableformulas[n];
}

LIB_EXTERN const char** getSymbolConsts(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_variableconsts[0]);
}

LIB_EXTERN const char*  getNthSymbolConst(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_variableconsts[n];
}

LIB_EXTERN const char** getConstSymbolNames(const char* moduleName)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return &(g_registry.GetModule(moduleName)->m_variablenames[var]);
    }
  }
  return NULL;
}

LIB_EXTERN const char*  getNthConstSymbolName(const char* moduleName, size_t n)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return g_registry.GetModule(moduleName)->m_variablenames[var+n];
    }
  }
  return NULL;
}

LIB_EXTERN const char** getConstSymbolTypes(const char* moduleName)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return &(g_registry.GetModule(moduleName)->m_variabletypes[var]);
    }
  }
  return NULL;
}

LIB_EXTERN const char*  getNthConstSymbolType(const char* moduleName, size_t n)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return g_registry.GetModule(moduleName)->m_variabletypes[var+n];
    }
  }
  return NULL;
}

LIB_EXTERN const char** getConstSymbolEquations(const char* moduleName)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return &(g_registry.GetModule(moduleName)->m_variableformulas[var]);
    }
  }
  return NULL;
}

LIB_EXTERN const char*  getNthConstSymbolEquation(const char* moduleName, size_t n)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return g_registry.GetModule(moduleName)->m_variableformulas[var+n];
    }
  }
  return NULL;
}

LIB_EXTERN const size_t getNumConstSymbols(const char* moduleName)
{
  vector<const char*> vconsts = g_registry.GetModule(moduleName)->m_variableconsts;
  for (size_t var=0; var<vconsts.size(); var++) {
    string varorconst(vconsts[var]);
    if (varorconst == "const") {
      return vconsts.size()-var;
    }
  }
  return 0;
}

LIB_EXTERN const size_t getNumSymbols(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_variablenames.size();
}

LIB_EXTERN const char*** getReactantNames(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_leftnamepointers[0]);
}

LIB_EXTERN const char*   getNthReactionMthReactantName(const char* moduleName, size_t n, size_t m)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers[n][m];
}

LIB_EXTERN const char*** getProductNames(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rightnamepointers[0]);
}

LIB_EXTERN const char*   getNthReactionMthProductName(const char* moduleName, size_t n, size_t m)
{
  return g_registry.GetModule(moduleName)->m_rightnamepointers[n][m];
}

LIB_EXTERN const double** getReactantStoichiometries(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_leftstoichpointers[0]);
}

LIB_EXTERN const double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_leftstoichpointers[n];
}

LIB_EXTERN const double** getProductStoichiometries(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rightstoichpointers[0]);
}

LIB_EXTERN const double* getNthReactionProductStoichiometries(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rightstoichpointers[n];
}

LIB_EXTERN const size_t getNumReactions(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers.size();
}

LIB_EXTERN const size_t* getNumReactants(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_leftsizes[0]);
}

LIB_EXTERN const size_t* getNumProducts(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rightsizes[0]);
}

LIB_EXTERN const double** getStoichiometryMatrix(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN const double*  getStoichiometryMatrixNthRow(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN const char**   getStoichiometryMatrixColumnLabels(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN const char**   getStoichiometryMatrixRowLabels(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN const char*    getStoichiometryMatrixNthColumnLabel(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN const char*    getStoichiometryMatrixNthRowLabel(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN const char**   getStoichiometryMatrixColumnFormulas(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN const char*    getStoichiometryMatrixNthColumnFormula(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN const size_t   getStoichiometryMatrixNumRows(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN const size_t   getStoichiometryMatrixNumColumns(const char* moduleName)
{
	return NULL;
}


LIB_EXTERN const char** getReactionRates(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxnrates[0]);
}

LIB_EXTERN const char*  getNthReactionRate(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnrates[n];
}

LIB_EXTERN const char** getReactionDividers(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxndividers[0]);
}

LIB_EXTERN const char*  getNthReactionDivider(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxndividers[n];
}

LIB_EXTERN const char** getReactionNames(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxnnames[0]);
}

LIB_EXTERN const char*  getNthReactionName(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnnames[n];
}

LIB_EXTERN const char*** getDNAStrands(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_dnanames[0]);
}

LIB_EXTERN const size_t* getDNAStrandSizes(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_dnalengths[0]);
}

LIB_EXTERN const size_t getNumDNAStrands(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_dnanames.size();
}

LIB_EXTERN bool checkModule(const char* moduleName)
{
  return (g_registry.GetModule(moduleName) != NULL);
}

LIB_EXTERN void printAllDataFor(const char* moduleName)
{
  if (!checkModule(moduleName)) {
    cout << "Couldn't find module: '" << moduleName << "'" << endl;
    return;
  }
  cout << "All variables and types for module " << moduleName << ":" << endl;
  const char **variablenames = getAllSymbolNames(moduleName);
  const char **variabletypes = getSymbolTypes(moduleName);
  const char **variableconsts = getSymbolConsts(moduleName);
  const char **variableequations = getSymbolEquations(moduleName);
  for (size_t var=0; var<getNumSymbols(moduleName); var++) {
    cout << variablenames[var] << " (" << variabletypes[var] << ", " << variableconsts[var] << ") : " << variableequations[var] << endl;
  }

  cout << endl << "Just the constant values and their formulas:" << endl;
  const char **cvarnames = getConstSymbolNames(moduleName);
  const char **cvartypes = getConstSymbolTypes(moduleName);
  const char **cvarequations = getConstSymbolEquations(moduleName);
  for (size_t cvar=0; cvar<getNumConstSymbols(moduleName); cvar++) {
    cout << cvarnames[cvar] << ": " << cvarequations[cvar] << " (" << cvartypes[cvar] << ")" << endl;
  }

  if (getNumDNAStrands(moduleName) > 0) {
    const char ***dnanames = getDNAStrands(moduleName);
    const size_t *dnanums = getDNAStrandSizes(moduleName);
    cout << endl << "DNA strands:" << endl;
    for (size_t strand=0; strand<getNumDNAStrands(moduleName); strand++) {
      for (size_t element=0; element<dnanums[strand]; element++) {
        cout << dnanames[strand][element];
      }
      cout << endl;
    }
  }

  cout << endl << "Reactions:" << endl;
  const char ***leftrxnnames = getReactantNames(moduleName);
  const char ***rightrxnnames = getProductNames(moduleName);
  const char **rxnnames = getReactionNames(moduleName);
  const char **rxnrates = getReactionRates(moduleName);
  const char **rxndividers = getReactionDividers(moduleName);

  const double **leftrxnstoichs = getReactantStoichiometries(moduleName);
  const double **rightrxnstoichs = getProductStoichiometries(moduleName);

  const size_t *leftnums = getNumReactants(moduleName);
  const size_t *rightnums = getNumProducts(moduleName);

  for (size_t rxn=0; rxn<getNumReactions(moduleName); rxn++) {
    cout << rxnnames[rxn] << ": ";
    for (size_t var=0; var<leftnums[rxn]; var++) {
      if (var > 0) {
        cout << " + ";
      }
      if (leftrxnstoichs[rxn][var] > 1) {
        char lnum[50];
        sprintf(lnum, "%g", leftrxnstoichs[rxn][var]);
        cout << lnum;
      }
      cout << leftrxnnames[rxn][var];
    }
    cout << " " << rxndividers[rxn] << " ";
    for (size_t var=0; var<rightnums[rxn]; var++) {
      if (var > 0) {
        cout << " + ";
      }
      if (rightrxnstoichs[rxn][var] > 1) {
        char rnum[50];
        sprintf(rnum, "%g", rightrxnstoichs[rxn][var]);
        cout << rnum;
      }
      cout << rightrxnnames[rxn][var];
    }
    cout << " ; " << rxnrates[rxn];
    cout << endl;
  }
  cout << endl;
}

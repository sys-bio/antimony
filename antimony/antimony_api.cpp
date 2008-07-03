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
  //cout << "Return value: " << retval << endl;
  return retval;
}

LIB_EXTERN const char* getJarnac(const char* moduleName)
{
  return g_registry.GetJarnac(moduleName)->c_str();
}

LIB_EXTERN char** getModuleNames()
{
  size_t nummods = getNumModules();
  char** retval = (char**) malloc(nummods*sizeof(char*));
  for (size_t mod=0; mod<nummods; mod++) {
    retval[mod] = getNthModuleName(mod);
  }
  return retval;
}

LIB_EXTERN char*  getNthModuleName(size_t n)
{
  return strdup(g_registry.GetNthModuleName(n).c_str());
}

LIB_EXTERN size_t getNumModules()
{
  return g_registry.GetNumModules();
}

LIB_EXTERN bool checkModule(const char* moduleName)
{
  return (g_registry.GetModule(moduleName) != NULL);
}


LIB_EXTERN size_t getNumSymbolsOfType(const char* moduleName, return_type rtype)
{
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
}

LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype)
{
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** names = (char**) malloc(vnum*sizeof(char*));
  for (size_t var=0; var<vnum; var++) {
    names[var] = getNthSymbolNameOfType(moduleName, rtype, var);
  }
  return names;
}

LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype)
{
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = (char**) malloc(vnum*sizeof(char*));
  for (size_t var=0; var<vnum; var++) {
    equations[var] = getNthSymbolEquationOfType(moduleName, rtype, var);
  }
  return equations;
}

LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n)
{
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  return strdup(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
}

LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n)
{
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  return strdup(var->GetFormulaStringDelimitedBy(g_registry.GetCC()).c_str());
}




LIB_EXTERN size_t getNumReactions(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_rxntypes.size();
}

LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t rxn)
{
  if (g_registry.GetModule(moduleName)->m_rxnleftvarnames.size() >= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return g_registry.GetModule(moduleName)->m_rxnleftvarnames[rxn].size();
}

LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t rxn)
{
  if (g_registry.GetModule(moduleName)->m_rxnrightvarnames.size() >= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return g_registry.GetModule(moduleName)->m_rxnrightvarnames[rxn].size();
}

LIB_EXTERN char*** getReactantNames(const char* moduleName)
{
  vector<vector<string> >* lnames = &g_registry.GetModule(moduleName)->m_rxnleftvarnames;
  char*** allnames = (char***) malloc(lnames->size()*sizeof(char**));
  for (size_t reaction=0; reaction<lnames->size(); reaction++) {
    allnames[reaction] = (char**) malloc((*lnames)[reaction].size()*sizeof(char*));
    for (size_t reactant=0; reactant<(*lnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = strdup((*lnames)[reaction][reactant].c_str());
    }
  }
  return allnames;
}

LIB_EXTERN char*** getProductNames(const char* moduleName)
{
  vector<vector<string> >* rnames = &g_registry.GetModule(moduleName)->m_rxnrightvarnames;
  char*** allnames = (char***) malloc(rnames->size()*sizeof(char**));
  for (size_t reaction=0; reaction<rnames->size(); reaction++) {
    allnames[reaction] = (char**) malloc((*rnames)[reaction].size()*sizeof(char*));
    for (size_t reactant=0; reactant<(*rnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = strdup((*rnames)[reaction][reactant].c_str());
    }
  }
  return allnames;
}

LIB_EXTERN char*   getNthReactionMthReactantName(const char* moduleName, size_t n, size_t m)
{
  //LS DEBUG error checking bounds
  return strdup(g_registry.GetModule(moduleName)->m_rxnleftvarnames[n][m].c_str());
}

LIB_EXTERN char*   getNthReactionMthProductName(const char* moduleName, size_t n, size_t m)
{
  //LS DEBUG error checking bounds
  return strdup(g_registry.GetModule(moduleName)->m_rxnrightvarnames[n][m].c_str());
}

LIB_EXTERN double** getReactantStoichiometries(const char* moduleName)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnleftstoichiometries;
  double** alllstoichs = (double**) malloc(lsrs->size()*sizeof(double*));
  for (size_t rxn=0; rxn<lsrs->size(); rxn++) {
    alllstoichs[rxn] = getNthReactionReactantStoichiometries(moduleName, rxn);
  }
  return alllstoichs;
}

LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnleftstoichiometries;
  if (n >= lsrs->size()) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  double* lstoichs = (double*) malloc((*lsrs)[n].size()*sizeof(double));
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    lstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return lstoichs;
}

LIB_EXTERN double** getProductStoichiometries(const char* moduleName)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnrightstoichiometries;
  double** allrstoichs = (double**) malloc(lsrs->size()*sizeof(double*));
  for (size_t rxn=0; rxn<lsrs->size(); rxn++) {
    allrstoichs[rxn] = getNthReactionReactantStoichiometries(moduleName, rxn);
  }
  return allrstoichs;
}

LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, size_t n)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnrightstoichiometries;
  if (n >= lsrs->size()) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  double* rstoichs = (double*) malloc((*lsrs)[n].size()*sizeof(double));
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    rstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return rstoichs;
}

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN double*  getStoichiometryMatrixNthRow(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN char*    getStoichiometryMatrixNthColumnLabel(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN char*    getStoichiometryMatrixNthRowLabel(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN char**   getStoichiometryMatrixColumnFormulas(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN char*    getStoichiometryMatrixNthColumnFormula(const char* moduleName, size_t n)
{
	return NULL;
}

LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName)
{
	return NULL;
}

LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName)
{
	return NULL;
}


LIB_EXTERN char** getReactionRates(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxnrates[0]);
}

LIB_EXTERN char*  getNthReactionRate(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnrates[n];
}

LIB_EXTERN char** getReactionDividers(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxndividers[0]);
}

LIB_EXTERN char*  getNthReactionDivider(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxndividers[n];
}

LIB_EXTERN char** getReactionNames(const char* moduleName)
{
  return &(g_registry.GetModule(moduleName)->m_rxnnames[0]);
}

LIB_EXTERN char*  getNthReactionName(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnnames[n];
}

LIB_EXTERN char*** getDNAStrands(const char* moduleName)
{
  size_t numDNA = getNumDNAStrands(moduleName);
  char*** retval = (char***) malloc(numDNA*sizeof(char**));
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthDNAStrand(moduleName, strand);
  }
  return retval;
}

LIB_EXTERN char** getNthDNAStrand(const char* moduleName, size_t n)
{
  if (g_registry.GetModule(moduleName)->m_dna.size() < n) {
    //LS DEBUG:  THROW AN ERROR
    assert(false);
  }
  size_t dna_length = g_registry.GetModule(moduleName)->m_dna[n].size();
  char** retval = (char**) malloc (dna_length*sizeof (char *));
  for (size_t dnabit=0; dnabit<g_registry.GetModule(moduleName)->m_dna[n].size(); dnabit++) {
    retval[dnabit] = strdup(m_dna[n][dnabit].c_str());;
  }
  return retval;
}

LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName)
{
  size_t numDNA = getNumDNAStrands(moduleName);
  size_t* retval = (size_t*) malloc(numDNA*sizeof(size_t));
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->m_dna[strand].size();
  }
}

LIB_EXTERN size_t getNumDNAStrands(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_dna.size();
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

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
  g_registry.CompileAllExportLists();
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
  g_registry.m_charstarstars.push_back(retval);
  for (size_t mod=0; mod<nummods; mod++) {
    retval[mod] = getNthModuleName(mod);
  }
  return retval;
}

LIB_EXTERN char*  getNthModuleName(size_t n)
{
  char* retval = strdup(g_registry.GetNthModuleName(n).c_str());
  g_registry.m_charstars.push_back(retval);
  return retval;
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
  g_registry.m_charstarstars.push_back(names);
  for (size_t var=0; var<vnum; var++) {
    names[var] = getNthSymbolNameOfType(moduleName, rtype, var);
  }
  return names;
}

LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype)
{
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = (char**) malloc(vnum*sizeof(char*));
  g_registry.m_charstarstars.push_back(equations);
  for (size_t var=0; var<vnum; var++) {
    equations[var] = getNthSymbolEquationOfType(moduleName, rtype, var);
  }
  return equations;
}

LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n)
{
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  char* retval = strdup(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
  g_registry.m_charstars.push_back(retval);
  return retval;
}

LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n)
{
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  char* retval = strdup(var->GetFormulaStringDelimitedBy(g_registry.GetCC()).c_str());
  g_registry.m_charstars.push_back(retval);
  return retval;
}




LIB_EXTERN size_t getNumReactions(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_rxnleftvarnames.size();
}

LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t rxn)
{
  const Module* mod = g_registry.GetModule(moduleName); 
  if (mod->m_rxnleftvarnames.size() <= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return mod->m_rxnleftvarnames[rxn].size();
}

LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t rxn)
{
  if (g_registry.GetModule(moduleName)->m_rxnrightvarnames.size() <= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return g_registry.GetModule(moduleName)->m_rxnrightvarnames[rxn].size();
}

LIB_EXTERN char*** getReactantNames(const char* moduleName)
{
  vector<vector<string> >* lnames = &g_registry.GetModule(moduleName)->m_rxnleftvarnames;
  char*** allnames = (char***) malloc(lnames->size()*sizeof(char**));
  g_registry.m_charstarstarstars.push_back(allnames);
  for (size_t reaction=0; reaction<lnames->size(); reaction++) {
    allnames[reaction] = (char**) malloc((*lnames)[reaction].size()*sizeof(char*));
    g_registry.m_charstarstars.push_back(allnames[reaction]);
    for (size_t reactant=0; reactant<(*lnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = strdup((*lnames)[reaction][reactant].c_str());
      g_registry.m_charstars.push_back(allnames[reaction][reactant]);
    }
  }
  return allnames;
}

LIB_EXTERN char*** getProductNames(const char* moduleName)
{
  vector<vector<string> >* rnames = &g_registry.GetModule(moduleName)->m_rxnrightvarnames;
  char*** allnames = (char***) malloc(rnames->size()*sizeof(char**));
  g_registry.m_charstarstarstars.push_back(allnames);
  for (size_t reaction=0; reaction<rnames->size(); reaction++) {
    allnames[reaction] = (char**) malloc((*rnames)[reaction].size()*sizeof(char*));
    g_registry.m_charstarstars.push_back(allnames[reaction]);
    for (size_t reactant=0; reactant<(*rnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = strdup((*rnames)[reaction][reactant].c_str());
      g_registry.m_charstars.push_back(allnames[reaction][reactant]);
    }
  }
  return allnames;
}

LIB_EXTERN double** getReactantStoichiometries(const char* moduleName)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnleftstoichiometries;
  double** alllstoichs = (double**) malloc(lsrs->size()*sizeof(double*));
  g_registry.m_doublestarstars.push_back(alllstoichs);
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
  g_registry.m_doublestars.push_back(lstoichs);
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    lstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return lstoichs;
}

LIB_EXTERN double** getProductStoichiometries(const char* moduleName)
{
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnrightstoichiometries;
  double** allrstoichs = (double**) malloc(lsrs->size()*sizeof(double*));
  g_registry.m_doublestarstars.push_back(allrstoichs);
  for (size_t rxn=0; rxn<lsrs->size(); rxn++) {
    allrstoichs[rxn] = getNthReactionProductStoichiometries(moduleName, rxn);
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
  g_registry.m_doublestars.push_back(rstoichs);
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    rstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return rstoichs;
}

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName)
{
  size_t nspecies   = getNumSymbolsOfType(moduleName, varSpecies);
  size_t nreactions = getNumSymbolsOfType(moduleName, allReactions);
  double** matrix = (double**) malloc (nspecies*sizeof (double *));
  g_registry.m_doublestarstars.push_back(matrix);
  for (size_t i=0; i<nspecies; i++) {
    matrix[i] = (double *) malloc (nreactions*sizeof (double));
    g_registry.m_doublestars.push_back(matrix[i]);
  }
  for (size_t rxn=0; rxn<nreactions; rxn++) {
    const Reaction* reaction = g_registry.GetModule(moduleName)->GetNthVariableOfType(allReactions, rxn)->GetReaction();
    for (size_t sp=0; sp<nspecies; sp++) {
      const Variable* species = g_registry.GetModule(moduleName)->GetNthVariableOfType(varSpecies, sp);
      matrix[sp][rxn] = reaction->GetStoichiometryFor(species);
    }
  }
  return matrix;
}

LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, varSpecies);
}

LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, varSpecies);
}

LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN char** getReactionRates(const char* moduleName)
{
  return getSymbolEquationsOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionRate(const char* moduleName, size_t n)
{
  return getNthSymbolEquationOfType(moduleName, allReactions, n);
}

LIB_EXTERN char** getReactionNames(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionName(const char* moduleName, size_t n)
{
  return getNthSymbolNameOfType(moduleName, allReactions, n);
}

LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName)
{
  size_t numints = g_registry.GetModule(moduleName)->GetNumVariablesOfType(allInteractions);
  rd_type* typelist = (rd_type*) malloc(numints*sizeof(rd_type));
  g_registry.m_rd_typestars.push_back(typelist);
  for (size_t i=0; i<numints; i++) {
    typelist[i] = getNthInteractionDivider(moduleName, i);
  }
  return typelist;
}

LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(allInteractions, n)->GetReaction()->GetType();
}

LIB_EXTERN char*** getDNAStrands(const char* moduleName)
{
  size_t numDNA = getNumDNAStrands(moduleName);
  char*** retval = (char***) malloc(numDNA*sizeof(char**));
  g_registry.m_charstarstarstars.push_back(retval);
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
  g_registry.m_charstarstars.push_back(retval);
  for (size_t dnabit=0; dnabit<g_registry.GetModule(moduleName)->m_dna[n].size(); dnabit++) {
    retval[dnabit] = strdup(g_registry.GetModule(moduleName)->m_dna[n][dnabit].c_str());;
    g_registry.m_charstars.push_back(retval[dnabit]);
  }
  return retval;
}

LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName)
{
  size_t numDNA = getNumDNAStrands(moduleName);
  size_t* retval = (size_t*) malloc(numDNA*sizeof(size_t));
  g_registry.m_size_tstars.push_back(retval);
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->m_dna[strand].size();
  }
  return retval;
}

LIB_EXTERN size_t getNumDNAStrands(const char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_dna.size();
}


LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName)
{
  var_type vtype = g_registry.GetModule(moduleName)->GetTypeFor(symbolName);
  bool isconst = g_registry.GetModule(moduleName)->IsConst(symbolName);
  switch(vtype) {
  case varSpeciesUndef:
    if (isconst) return constSpecies;
    return varSpecies;
  case varSpeciesProtein:
    if (isconst) return constProteins;
    return varProteins;
  case varFormulaUndef:
    if (isconst) return constFormulas;
    return varFormulas;
  case varDNA:
    if (isconst) return constAnyDNA;
    return varAnyDNA;
  case varFormulaPromoter:
    if (isconst) return constPromoters;
    return varPromoters;
  case varFormulaOperator:
    if (isconst) return constOperators;
    return varOperators;
  case varReactionGene:
    if (isconst) return constGenes;
    return varGenes;
  case varReactionUndef:
    return allReactions;
  case varInteraction:
    return allInteractions;
  case varUndefined:
    return allUnknown;
  case varModule:
    return subModules;
  }
  assert(false); //uncaught var_type
  //LS DEBUG throw error
  return allUnknown;
}


LIB_EXTERN void freeAll()
{
  g_registry.FreeAll();
}


LIB_EXTERN void printAllDataFor(const char* moduleName)
{
  if (!checkModule(moduleName)) {
    cout << "Couldn't find module: '" << moduleName << "'" << endl;
    return;
  }
  
  cout << "All variables for module " << moduleName << ":" << endl;
  char **symbolnames = getSymbolNamesOfType(moduleName, allSymbols);
  char **symbolequations = getSymbolEquationsOfType(moduleName, allSymbols);
  size_t numvars = getNumSymbolsOfType(moduleName, allSymbols);
  for (size_t var=0; var<numvars; var++) {
    cout << symbolnames[var] << " [" << ReturnTypeToString(getTypeOfSymbol(moduleName, symbolnames[var])) << "] : " << symbolequations[var] << endl;
  }
  if (getNumDNAStrands(moduleName) > 0) {
    char ***dnanames = getDNAStrands(moduleName);
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
  char ***leftrxnnames = getReactantNames(moduleName);
  char ***rightrxnnames = getProductNames(moduleName);
  char **rxnnames = getReactionNames(moduleName);
  char **rxnrates = getReactionRates(moduleName);
  
  double **leftrxnstoichs = getReactantStoichiometries(moduleName);
  double **rightrxnstoichs = getProductStoichiometries(moduleName);

  for (size_t rxn=0; rxn<getNumReactions(moduleName); rxn++) {
    cout << rxnnames[rxn] << ": ";
    for (size_t var=0; var<getNumReactants(moduleName,rxn); var++) {
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
    cout << " -> ";
    for (size_t var=0; var<getNumProducts(moduleName,rxn); var++) {
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

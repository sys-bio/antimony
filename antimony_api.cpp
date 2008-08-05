#include <string>

#include "antimony_api.h"
#include "registry.h"


using namespace std;
extern int yyparse();

LIB_EXTERN int loadModel(const char* filename)
{
  g_registry.ClearModels();  
  g_registry.input.open(filename, ios::in);
  if (!g_registry.input.is_open()) {
    string error = "Could not open \"";
    error += filename;
    error += "\".  "
      "Please check that this file:\n" 
      "	1) exists in directory that antimony is being run from,\n"
      "	2) is read enabled, and\n"
      "	3) is not in use by another program.\n";
    g_registry.SetError(error);	
    return 3;
  }

  if (!g_registry.input.good())
  {
    string error = "Input file ";
    error += filename;
    error += " is open, but not able to be read from.  This should not happen, and is probably a programming error on our part, but just in case, check the permissions on the file and try again.  If that still does not work, contact us letting us know how you got this error.";
    g_registry.SetError(error);
    return 4;
  }

  g_registry.SetMainModuleName(filename);
  int retval = yyparse();
  g_registry.input.close();
  g_registry.CompileAllExportLists();
  //cout << "Return value: " << retval << endl;
  if (retval == 1) {
    //LS DEBUG:  We might know the error--try to eke it out of the parser.
    g_registry.SetError("Parsing failed because of invalid input.");
  }
  if (retval == 2) {
    g_registry.SetError("Parsing failed due to memory exhaution.");
  }
  if (retval > 2) {
    g_registry.SetError("Unknown parsing error.");
  }
  return retval;
}

char* getCharStar(const char* orig)
{
  char* ret = strdup(orig);
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstars.push_back(ret);
  return ret;
}

char** getCharStarStar(size_t size)
{
  char** ret = (char**) malloc(size*sizeof(char*));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstarstars.push_back(ret);
  return ret;
}

char*** getCharStarStarStar(size_t size)
{
  char*** ret = (char***) malloc(size*sizeof(char**));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_charstarstarstars.push_back(ret);
  return ret;
}

double* getDoubleStar(size_t size)
{
  double* ret = (double*) malloc(size*sizeof(double));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_doublestars.push_back(ret);
  return ret;
}

double** getDoubleStarStar(size_t size)
{
  double** ret = (double**) malloc(size*sizeof(double*));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_doublestarstars.push_back(ret);
  return ret;
}

rd_type* getRDTypeStar(size_t size)
{
  rd_type* ret = (rd_type*) malloc(size*sizeof(rd_type));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_rd_typestars.push_back(ret);
  return ret;
}

size_t* getSizeTStar(size_t size)
{
  size_t* ret = (size_t*) malloc(size*sizeof(size_t));
  if (ret == NULL) {
    g_registry.SetError("Out of memory error.");
    return NULL;
  }
  g_registry.m_size_tstars.push_back(ret);
  return ret;
}


LIB_EXTERN char* getJarnac(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  char* jarnac = getCharStar(g_registry.GetJarnac(moduleName).c_str());
  return jarnac;
}

LIB_EXTERN char** getModuleNames()
{
  size_t nummods = getNumModules();
  char** retval = getCharStarStar(nummods);
  if (retval == NULL) return NULL;
  for (size_t mod=0; mod<nummods; mod++) {
    retval[mod] = getNthModuleName(mod);
  }
  return retval;
}

LIB_EXTERN char*  getNthModuleName(size_t n)
{
  size_t nummods = g_registry.GetNumModules();
  if (nummods > n-1) {
    string error = "There is no module with index " + n;
  }
  char* retval = getCharStar(g_registry.GetNthModuleName(n).c_str());
  return retval;
}

LIB_EXTERN size_t getNumModules()
{
  return g_registry.GetNumModules();
}

LIB_EXTERN bool checkModule(const char* moduleName)
{
  if (g_registry.GetModule(moduleName) == NULL) {
    string error = "No such module: '";
    error += moduleName;
    error += "'.  Existing modules: ";
    if (g_registry.GetNumModules()==0) {
      error += "[none]";
    }
    else {
      error += "'" + g_registry.GetNthModuleName(0) + "'";
      for (size_t mod=1; mod<g_registry.GetNumModules(); mod++) {
        error += ", '" + g_registry.GetNthModuleName(mod) + "'";
      }
    }
    g_registry.SetError(error);
    return false;
  }
  return true;
}


LIB_EXTERN size_t getNumSymbolsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
}

LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** names = getCharStarStar(vnum);
  if (names == NULL) return NULL;
  for (size_t var=0; var<vnum; var++) {
    names[var] = getNthSymbolNameOfType(moduleName, rtype, var);
  }
  return names;
}

LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** equations = getCharStarStar(vnum);
  if (equations == NULL) return NULL;
  for (size_t var=0; var<vnum; var++) {
    equations[var] = getNthSymbolEquationOfType(moduleName, rtype, var);
  }
  return equations;
}

LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  if (var==NULL) {
    string error = "There is no variable of type " + ReturnTypeToString(rtype);
    size_t numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
    if (numvars > 0) {
      error += " with index " + n;
    }
    error += " in module ";
    error +=  moduleName;
    error +=  ".";
    if (numvars == 1) {
      error += "  There is a single variable of this type with index 0.";
    }
    else if (numvars > 1) {
      error += "  Valid index values are 0 through ";
      error += numvars-1;
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  char* retval = getCharStar(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
  return retval;
}

LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  if (var==NULL) {
    string error = "There is no variable of type " + ReturnTypeToString(rtype);
    size_t numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
    if (numvars > 0) {
      error += " with index " + n;
    }
    error += " in module ";
    error += moduleName;
    error += ".";
    if (numvars == 1) {
      error += "  There is a single variable of this type with index 0.";
    }
    else if (numvars > 1) {
      error += "  Valid index values are 0 through ";
      error += numvars-1;
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  char* retval = getCharStar(var->GetFormulaStringDelimitedBy(g_registry.GetCC()).c_str());
  return retval;
}




LIB_EXTERN size_t getNumReactions(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return g_registry.GetModule(moduleName)->m_rxnleftvarnames.size();
}

LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t rxn)
{
  if (!checkModule(moduleName)) return NULL;
  const Module* mod = g_registry.GetModule(moduleName); 
  if (mod->m_rxnleftvarnames.size() <= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return mod->m_rxnleftvarnames[rxn].size();
}

LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t rxn)
{
  if (!checkModule(moduleName)) return NULL;
  if (g_registry.GetModule(moduleName)->m_rxnrightvarnames.size() <= rxn) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  return g_registry.GetModule(moduleName)->m_rxnrightvarnames[rxn].size();
}

LIB_EXTERN char*** getReactantNames(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<string> >* lnames = &g_registry.GetModule(moduleName)->m_rxnleftvarnames;
  char*** allnames = getCharStarStarStar(lnames->size());
  if (allnames == NULL) return NULL;
  for (size_t reaction=0; reaction<lnames->size(); reaction++) {
    allnames[reaction] = getCharStarStar((*lnames)[reaction].size());
    if (allnames[reaction] == NULL) return NULL;
    for (size_t reactant=0; reactant<(*lnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = getCharStar((*lnames)[reaction][reactant].c_str());
      if (allnames[reaction][reactant] == NULL) return NULL;
    }
  }
  return allnames;
}

LIB_EXTERN char*** getProductNames(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<string> >* rnames = &g_registry.GetModule(moduleName)->m_rxnrightvarnames;
  char*** allnames = getCharStarStarStar(rnames->size());
  if (allnames == NULL) return NULL;
  for (size_t reaction=0; reaction<rnames->size(); reaction++) {
    allnames[reaction] = getCharStarStar((*rnames)[reaction].size());
    if (allnames[reaction] == NULL) return NULL;
    for (size_t reactant=0; reactant<(*rnames)[reaction].size(); reactant++) {
      allnames[reaction][reactant] = getCharStar((*rnames)[reaction][reactant].c_str());
      if (allnames[reaction][reactant] == NULL) return NULL;
    }
  }
  return allnames;
}

LIB_EXTERN double** getReactantStoichiometries(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnleftstoichiometries;
  double** alllstoichs = getDoubleStarStar(lsrs->size());
  if (alllstoichs == NULL) return NULL;
  for (size_t rxn=0; rxn<lsrs->size(); rxn++) {
    alllstoichs[rxn] = getNthReactionReactantStoichiometries(moduleName, rxn);
  }
  return alllstoichs;
}

LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnleftstoichiometries;
  if (n >= lsrs->size()) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  double* lstoichs = getDoubleStar((*lsrs)[n].size());
  if (lstoichs == NULL) return NULL;
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    lstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return lstoichs;
}

LIB_EXTERN double** getProductStoichiometries(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnrightstoichiometries;
  double** allrstoichs = getDoubleStarStar(lsrs->size());
  if (allrstoichs == NULL) return NULL;
  for (size_t rxn=0; rxn<lsrs->size(); rxn++) {
    allrstoichs[rxn] = getNthReactionProductStoichiometries(moduleName, rxn);
  }
  return allrstoichs;
}

LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  vector<vector<double> >* lsrs = &g_registry.GetModule(moduleName)->m_rxnrightstoichiometries;
  if (n >= lsrs->size()) {
    //LS DEBUG THROW ERROR
    assert(false);
  }
  double* rstoichs = getDoubleStar((*lsrs)[n].size());
  if (rstoichs == NULL) return NULL;
  for (size_t stoich=0; stoich<(*lsrs)[n].size(); stoich++) {
    rstoichs[stoich] = (*lsrs)[n][stoich];
  }
  return rstoichs;
}

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t nspecies   = getNumSymbolsOfType(moduleName, varSpecies);
  size_t nreactions = getNumSymbolsOfType(moduleName, allReactions);
  double** matrix = getDoubleStarStar(nspecies);
  if (matrix == NULL) return NULL;
  for (size_t i=0; i<nspecies; i++) {
    matrix[i] = getDoubleStar(nreactions);
    if (matrix[i] == NULL) return NULL;
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
  if (!checkModule(moduleName)) return NULL;
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getSymbolNamesOfType(moduleName, varSpecies);
}

LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getNumSymbolsOfType(moduleName, varSpecies);
}

LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN char** getReactionRates(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getSymbolEquationsOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionRate(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  return getNthSymbolEquationOfType(moduleName, allReactions, n);
}

LIB_EXTERN size_t getNumReactionRates(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN char** getReactionNames(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getSymbolNamesOfType(moduleName, allReactions);
}

LIB_EXTERN char*  getNthReactionName(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  return getNthSymbolNameOfType(moduleName, allReactions, n);
}

LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numints = g_registry.GetModule(moduleName)->GetNumVariablesOfType(allInteractions);
  rd_type* typelist = getRDTypeStar(numints);
  if (typelist == NULL) return NULL;
  for (size_t i=0; i<numints; i++) {
    typelist[i] = getNthInteractionDivider(moduleName, i);
  }
  return typelist;
}

LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return rdBecomes;
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(allInteractions, n)->GetReaction()->GetType();
}

LIB_EXTERN char*** getDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numDNA = getNumDNAStrands(moduleName);
  char*** retval = getCharStarStarStar(numDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthDNAStrand(moduleName, strand);
  }
  return retval;
}

LIB_EXTERN char** getNthDNAStrand(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  if (g_registry.GetModule(moduleName)->m_dna.size() < n) {
    //LS DEBUG:  THROW AN ERROR
    assert(false);
    return NULL;
  }
  size_t dna_length = g_registry.GetModule(moduleName)->m_dna[n].size();
  char** retval = getCharStarStar(dna_length);
  if (retval == NULL) return NULL;
  for (size_t dnabit=0; dnabit<g_registry.GetModule(moduleName)->m_dna[n].size(); dnabit++) {
    retval[dnabit] = getCharStar(g_registry.GetModule(moduleName)->m_dna[n][dnabit].c_str());;
    if (retval[dnabit] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numDNA = getNumDNAStrands(moduleName);
  size_t* retval = getSizeTStar(numDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->m_dna[strand].size();
  }
  return retval;
}

LIB_EXTERN size_t getNumDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return g_registry.GetModule(moduleName)->m_dna.size();
}


LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return allUnknown;
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

  cout << "Stoichiometry matrix" << endl;
  double** matrix = getStoichiometryMatrix(moduleName);
  char** columns  = getStoichiometryMatrixColumnLabels(moduleName);
  char** rows     = getStoichiometryMatrixRowLabels(moduleName);
  cout << "\t";
  for (size_t col=0; col<getStoichiometryMatrixNumColumns(moduleName); col++) {
    cout << "\t" << columns[col];
  }
  cout << endl;
  for (size_t row=0; row<getStoichiometryMatrixNumRows(moduleName); row++) {
    cout << rows[row] << "\t";
    for (size_t col=0; col<getStoichiometryMatrixNumColumns(moduleName); col++) {
      cout << "\t" << matrix[row][col];
    }
    cout << endl;
  }
  cout << endl;

  cout << "Reaction rates" << endl;
  for (size_t rate=0; rate<getNumReactionRates(moduleName); rate++) {
    cout << rxnrates[rate] << endl;
  }
  cout << endl;
}

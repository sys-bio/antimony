#include <string>
#include <iostream>

#include <sbml/SBMLTypes.h>

#include "antimony_api.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"


using namespace std;
extern int yyparse();
extern int yylloc_first_line;

//Useful functions for later routines:
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

void reportReactionIndexProblem(size_t n, size_t actualsize, const char* moduleName, bool reaction=true)
{
  string name = "reaction";
  if (!reaction) {
    name = "interaction";
  }
    
  string error = "There is no " + name + "with index " + SizeTToString(n) + " in module ";
  error += moduleName;
  error += ".";
  if (actualsize == 0) {
    error += "  In fact, there are no " + name + "s at all in that module.";
  }
  else if (actualsize == 1) {
    error += "  There is a single " + name + " with index 0.";
  }
  else if (actualsize > 1) {
    error += "  Valid "+ name + " index values are 0 through " + SizeTToString(actualsize-1) + ".";
  }
  g_registry.SetError(error);
}

void reportVariableTypeIndexProblem(size_t n, return_type rtype, size_t actualsize, const char* moduleName)
{
  if (rtype == allReactions) {
    return reportReactionIndexProblem(n, actualsize, moduleName);
  }
  string error = "There is no variable of type " + ReturnTypeToString(rtype);
  if (actualsize > 0) {
    error += " with index " + SizeTToString(n);
  }
  error += " in module ";
  error +=  moduleName;
  error +=  ".";
  if (actualsize == 1) {
    error += "  There is a single variable of this type with index 0.";
  }
  else if (actualsize > 1) {
    error += "  Valid index values are 0 through " + SizeTToString(actualsize-1) + ".";
  }
  g_registry.SetError(error);
}

//Exported routines:

LIB_EXTERN long loadFile(const char* filename)
{
  g_registry.ClearModules();
  int ofreturn = g_registry.OpenFile(filename);
  if (ofreturn==0) return -1; //file read failure
  if (ofreturn==2) {
    //SBML file
    g_registry.FinalizeModules();
    return g_registry.SaveModules();
  }
  assert(ofreturn==1); //antimony file
  int yyreturn = yyparse();
  if (yyreturn != 0) {
    if (g_registry.GetError().size() == 0) {
      assert(false); //Need to fill in the reason why we failed explicitly, if possible.
      if (yyreturn == 1) {
        g_registry.SetError("Parsing failed because of invalid input.");
      }
      else if (yyreturn == 2) {
        g_registry.SetError("Parsing failed due to memory exhaution.");
      }
      else {
        g_registry.SetError("Unknown parsing error.");
      }
    }
    g_registry.AddErrorPrefix("Error in file '" + g_registry.GetLastFile() + "', line " + SizeTToString(yylloc_first_line) + ":  ");
    return -1;
  }
  if (g_registry.FinalizeModules()) return -1;
  return g_registry.SaveModules();
}

LIB_EXTERN long loadSBMLFile(const char* filename)
{
  g_registry.ClearModules();
  SBMLDocument* document = readSBML(filename);
  document->checkConsistency();
  if (document->getErrorLog()->getNumFailsWithSeverity(2) > 0) {
    stringstream errorstream;
    document->printErrors(errorstream);
    string file(filename);
    g_registry.SetError("Unable to read SBML file '" + file + "' due to errors encountered when parsing the file.  Error from libSBML:\n" +  errorstream.str());
    return -1;
  }
  const Model* sbml = document->getModel();
  string sbmlname = getNameFromSBMLObject(sbml, "file");
  g_registry.NewCurrentModule(&sbmlname);
  g_registry.CurrentModule()->LoadSBML(sbml);

  delete(document);
  return g_registry.SaveModules();
}

LIB_EXTERN size_t getNumFiles()
{
  return g_registry.GetNumFiles();
}

LIB_EXTERN bool revertTo(long handle)
{
  return g_registry.RevertToModuleSet(handle);
}

LIB_EXTERN void clearPreviousLoads()
{
  g_registry.ClearAll();
}

LIB_EXTERN char* getLastError()
{
  return getCharStar((g_registry.GetError()).c_str());
}

LIB_EXTERN char** getModuleNames()
{
  size_t nummods = getNumModules();
  char** retval = getCharStarStar(nummods);
  if (retval == NULL) return NULL;
  for (size_t mod=0; mod<nummods; mod++) {
    retval[mod] = getNthModuleName(mod);
    if (retval[mod] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char*  getNthModuleName(size_t n)
{
  size_t nummods = g_registry.GetNumModules();
  if (n >= nummods) {
    string error = "There is no module with index " + SizeTToString(n) + ".";
    if (nummods == 1) {
      error += "  There is a single module with index 0.";
    }
    else if (nummods > 1) {
      error += "  Valid module index values are 0 through " + SizeTToString(nummods-1) + ".";
    }
    if (nummods == 0) {
      error += "  In fact, there are no modules at all.  Try running loadModule(filename).";
    }
    g_registry.SetError(error);
    return NULL;
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
    if (names[var] == NULL) return NULL;
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
    if (equations[var]==NULL) return NULL;
  }
  return equations;
}

LIB_EXTERN char** getSymbolCompartmentsOfType(const char* moduleName, return_type rtype)
{
  if (!checkModule(moduleName)) return NULL;
  size_t vnum = getNumSymbolsOfType(moduleName, rtype);
  char** compartments = getCharStarStar(vnum);
  if (compartments == NULL) return NULL;
  for (size_t var=0; var<vnum; var++) {
    compartments[var] = getNthSymbolCompartmentOfType(moduleName, rtype, var);
    if (compartments[var]==NULL) return NULL;
  }
  return compartments;
}

LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  if (var==NULL) {
    size_t numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
}

LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  if (var==NULL) {
    size_t numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  return getCharStar(var->GetFormulaStringDelimitedBy(g_registry.GetCC()).c_str());
}

LIB_EXTERN char*  getNthSymbolCompartmentOfType(const char* moduleName, return_type rtype, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n);
  if (var==NULL) {
    size_t numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype);
    reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
    return NULL;
  }
  const Variable* compartment = var->GetCompartment();
  if (compartment == NULL) {
    return getCharStar("default_compartment");
  }
  return getCharStar(compartment->GetNameDelimitedBy(g_registry.GetCC()).c_str());
}




LIB_EXTERN size_t getNumReactions(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getNumSymbolsOfType(moduleName, allReactions);
}

LIB_EXTERN size_t getNumInteractions(const char* moduleName)
{ 
  if (!checkModule(moduleName)) return NULL;
  return getNumSymbolsOfType(moduleName, allInteractions);
}

size_t getNumReactOrProdForRxnOrInt(const char* moduleName, size_t n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return 0;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  if (n >= getNumSymbolsOfType(moduleName, rtype)) {
    reportReactionIndexProblem(n, getNumSymbolsOfType(moduleName, rtype), moduleName, reaction);    
  }
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n);
  if (rxn->GetReaction() == NULL) {
    return 0;
  }
  if (reactant) {
    return rxn->GetReaction()->GetLeft()->Size();
  }
  else {
    return rxn->GetReaction()->GetRight()->Size();
  }
}

LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, true, true);
}

LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, true, false);
}

LIB_EXTERN size_t getNumInteractors(const char* moduleName, size_t n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, false, true);
}

LIB_EXTERN size_t getNumInteractees(const char* moduleName, size_t n)
{
  return getNumReactOrProdForRxnOrInt(moduleName, n, false, false);
}

char** getNthRxnOrIntReactantOrProductNames(const char* moduleName, size_t n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  size_t numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);    
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n);
  if (rxn->GetReaction() == NULL) {
    return NULL;
  }
  vector<string> names;
  if (reactant) {
    names = rxn->GetReaction()->GetLeft()->ToStringVecDelimitedBy(g_registry.GetCC());
  }
  else {
    names = rxn->GetReaction()->GetRight()->ToStringVecDelimitedBy(g_registry.GetCC());
  }
  char** retnames = getCharStarStar(names.size());
  for (size_t name=0; name<names.size(); name++) {
    char* rname = getCharStar(names[name].c_str());
    if (rname == NULL) return NULL;
    retnames[name] = rname;
  }
  return retnames;
}

char*** getReactantOrProductNamesForRxnOrInt(const char* moduleName, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  size_t numlines = getNumSymbolsOfType(moduleName, rtype);
  char*** allnames = getCharStarStarStar(numlines);
  if (allnames == NULL) return NULL;
  for (size_t rxn=0; rxn<numlines; rxn++) {
    char** rxnnames = getNthRxnOrIntReactantOrProductNames(moduleName, rxn, reaction, reactant);
    if (rxnnames == NULL) return NULL;
    allnames[rxn] = rxnnames;
  }
  return allnames;
}

LIB_EXTERN char*** getReactantNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, true, true);
}

LIB_EXTERN char** getNthReactionReactantNames(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, true, true);
}

LIB_EXTERN char*** getProductNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, true, false);
}

LIB_EXTERN char** getNthReactionProductNames(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, true, false);
}

LIB_EXTERN char*** getInteractorNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, false, true);
}

LIB_EXTERN char** getNthReactionInteractorNames(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, false, true);
}

LIB_EXTERN char*** getInteracteeNames(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrInt(moduleName, false, false);
}

LIB_EXTERN char** getNthReactionInteracteeNames(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductNames(moduleName, n, false, false);
}

double* getNthRxnOrIntReactantOrProductStoichiometries(const char* moduleName, size_t n, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  size_t numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return NULL;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n);
  if (rxn->GetReaction() == NULL) {
    return NULL;
  }
  vector<double> stoichiometries;
  if (reactant) {
    stoichiometries = rxn->GetReaction()->GetLeft()->GetStoichiometries();
  }
  else {
    stoichiometries = rxn->GetReaction()->GetRight()->GetStoichiometries();
  }
  double* retstoichiometries = getDoubleStar(stoichiometries.size());
  for (size_t stoichiometry=0; stoichiometry<stoichiometries.size(); stoichiometry++) {
    retstoichiometries[stoichiometry] = stoichiometries[stoichiometry];
  }
  return retstoichiometries;
}

double** getReactantOrProductStoichiometriesForRxnOrInt(const char* moduleName, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  size_t numlines = getNumSymbolsOfType(moduleName, rtype);
  double** allstoichiometries = getDoubleStarStar(numlines);
  if (allstoichiometries == NULL) return NULL;
  for (size_t rxn=0; rxn<numlines; rxn++) {
    double* rxnstoichiometries = getNthRxnOrIntReactantOrProductStoichiometries(moduleName, rxn, reaction, reactant);
    if (rxnstoichiometries == NULL) return NULL;
    allstoichiometries[rxn] = rxnstoichiometries;
  }
  return allstoichiometries;
}

LIB_EXTERN double** getReactantStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, true, true);
}

LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, n, true, true);
}

LIB_EXTERN double** getProductStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, true, false);
}

LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, n, true, false);
}

LIB_EXTERN double** getInteractorStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, false, true);
}

LIB_EXTERN double* getNthReactionInteractorStoichiometries(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, n, false, true);
}

LIB_EXTERN double** getInteracteeStoichiometries(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrInt(moduleName, false, false);
}

LIB_EXTERN double* getNthReactionInteracteeStoichiometries(const char* moduleName, size_t n)
{
  return getNthRxnOrIntReactantOrProductStoichiometries(moduleName, n, false, false);
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
    const AntimonyReaction* reaction = g_registry.GetModule(moduleName)->GetNthVariableOfType(allReactions, rxn)->GetReaction();
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

LIB_EXTERN size_t getNumReactionRates(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allReactions);
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
  size_t numlines = getNumSymbolsOfType(moduleName, allInteractions);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, false);
    return rdBecomes;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(allInteractions, n)->GetReaction()->GetType();
}

LIB_EXTERN size_t getNumEvents(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, allEvents);
}

LIB_EXTERN char** getEventNames(const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, allEvents);
}

LIB_EXTERN char* getNthEventName(const char* moduleName, size_t eventno)
{
  return getNthSymbolNameOfType(moduleName, allEvents, eventno);
}

LIB_EXTERN size_t getNumAssignmentsForEvent(const char* moduleName, size_t eventno)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno);
  if (var==NULL) return NULL;
  return var->GetEvent()->GetNumAssignments();
}

LIB_EXTERN char* getTriggerForEvent(const char* moduleName, size_t eventno)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno);
  if (var==NULL) return NULL;
  string trig = var->GetEvent()->GetTrigger()->ToDelimitedStringWithEllipses(g_registry.GetCC());
  return getCharStar(trig.c_str());
}

LIB_EXTERN char* getNthAssignmentVariableForEvent(const char* moduleName, size_t eventno, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno);
  if (var==NULL) return NULL;
  string asnt = var->GetEvent()->GetNthAssignmentVariableName(n, g_registry.GetCC());
  if (asnt=="") return NULL;
  return getCharStar(asnt.c_str());
}

LIB_EXTERN char* getNthAssignmentEquationForEvent(const char* moduleName, size_t eventno, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(allEvents, eventno);
  if (var==NULL) return NULL;
  string formula = var->GetEvent()->GetNthAssignmentFormulaString(n, g_registry.GetCC(), false);
  if (formula=="") return NULL;
  return getCharStar(formula.c_str());
}

LIB_EXTERN char*** getDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numDNA = getNumDNAStrands(moduleName);
  char*** retval = getCharStarStarStar(numDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthDNAStrand(moduleName, strand);
    if (retval[strand]==NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char** getNthDNAStrand(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  size_t actualsize = getNumDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no DNA strand with index " + n;
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid DNA strand index values are 0 through ";
      error += actualsize-1;
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  vector<string> strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC());
  size_t dna_length = strand.size();
  char** retval = getCharStarStar(dna_length);
  if (retval == NULL) return NULL;
  for (size_t dnabit=0; dnabit<dna_length; dnabit++) {
    retval[dnabit] = getCharStar(strand[dnabit].c_str());;
    if (retval[dnabit] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN bool getIsNthDNAStrandOpen(const char* moduleName, size_t n, bool upstream)
{
  const DNAStrand* strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n)->GetDNAStrand();
  if (upstream) {
    return strand->GetUpstreamOpen();
  }
  else {
    return strand->GetDownstreamOpen();
  }
}

LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numDNA = getNumDNAStrands(moduleName);
  size_t* retval = getSizeTStar(numDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, strand)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC()).size();
  }
  return retval;
}

LIB_EXTERN size_t getNumDNAStrands(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, expandedStrands);
}


LIB_EXTERN char*** getModularDNAStrands(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numDNA = getNumModularDNAStrands(moduleName);
  char*** retval = getCharStarStarStar(numDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numDNA; strand++) {
    retval[strand] = getNthModularDNAStrand(moduleName, strand);
    if (retval[strand]==NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN char** getNthModularDNAStrand(const char* moduleName, size_t n)
{
  if (!checkModule(moduleName)) return NULL;
  size_t actualsize = getNumModularDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no ModularDNA strand with index " + n;
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no ModularDNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single ModularDNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid ModularDNA strand index values are 0 through ";
      error += actualsize-1;
      error += ".";
    }
    g_registry.SetError(error);
    return NULL;
  }
  vector<string> strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC());
  size_t dna_length = strand.size();
  char** retval = getCharStarStar(dna_length);
  if (retval == NULL) return NULL;
  for (size_t dnabit=0; dnabit<dna_length; dnabit++) {
    retval[dnabit] = getCharStar(strand[dnabit].c_str());;
    if (retval[dnabit] == NULL) return NULL;
  }
  return retval;
}

LIB_EXTERN bool getIsNthModularDNAStrandOpen(const char* moduleName, size_t n, bool upstream)
{
  const DNAStrand* strand = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n)->GetDNAStrand();
  if (upstream) {
    return strand->GetUpstreamOpen();
  }
  else {
    return strand->GetDownstreamOpen();
  }
}

LIB_EXTERN size_t* getModularDNAStrandSizes(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  size_t numModularDNA = getNumModularDNAStrands(moduleName);
  size_t* retval = getSizeTStar(numModularDNA);
  if (retval == NULL) return NULL;
  for (size_t strand=0; strand<numModularDNA; strand++) {
    retval[strand] = g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, strand)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC()).size();
  }
  return retval;
}

LIB_EXTERN size_t getNumModularDNAStrands(const char* moduleName)
{
  return getNumSymbolsOfType(moduleName, modularStrands);
}


LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return allUnknown;
  const Variable* var = g_registry.GetModule(moduleName)->GetVariableFromSymbol(symbolName);
  if (var == NULL) {
    return allUnknown;
  }
  var_type vtype = var->GetType();
  bool isconst = var->GetIsConst();
  switch(vtype) {
  case varSpeciesUndef:
    if (isconst) return constSpecies;
    return varSpecies;
  case varFormulaUndef:
    if (isconst) return constFormulas;
    return varFormulas;
  case varDNA:
    if (isconst) return constAnyDNA;
    return varAnyDNA;
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
  case varEvent:
    return allEvents;
  case varCompartment:
    if (isconst) return constCompartments;
    return varCompartments;
  case varStrand:
    return modularStrands;
  }
  assert(false); //uncaught var_type
  g_registry.SetError("Coding error:  Didn't include a return type for variable type " + VarTypeToString(vtype) + " in getTypeOfSymbol; antimony_api.cpp.  Email the author to fix.");
  return allUnknown;
}

LIB_EXTERN char* getCompartmentForSymbol(const char* moduleName, const char* symbolName)
{
  if (!checkModule(moduleName)) return NULL;
  const Variable* var = g_registry.GetModule(moduleName)->GetVariableFromSymbol(symbolName);
  if (var == NULL) return NULL;
  const Variable* varcomp = var->GetCompartment();
  string retval;
  if (varcomp == NULL) {
    retval = "default_compartment";
  }
  else {
    retval = varcomp->GetNameDelimitedBy(g_registry.GetCC());
  }
  return getCharStar(retval.c_str());
}

LIB_EXTERN int writeAntimonyFile(const char* filename, const char* moduleName)
{
  if (!checkModule(moduleName)) return 0;
  string antimony = g_registry.GetAntimony(moduleName);
  ofstream afile(filename);
  if (!afile.good()) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
    return 0;
  }
  afile << antimony;
  afile.close();
  return 1;
}

LIB_EXTERN char* getAntimonyString(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  char* antimony = getCharStar(g_registry.GetAntimony(moduleName).c_str());
  return antimony;
}

LIB_EXTERN int writeJarnacFile(const char* filename, const char* moduleName)
{
  if (!checkModule(moduleName)) return 0;
  string jarnac = g_registry.GetJarnac(moduleName);
  ofstream jfile(filename);
  if (!jfile.good()) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
    return 0;
  }
  jfile << jarnac;
  jfile.close();
  return 1;
}

LIB_EXTERN char* getJarnacString(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  char* jarnac = getCharStar(g_registry.GetJarnac(moduleName).c_str());
  return jarnac;
}

LIB_EXTERN int writeSBMLFile(const char* filename, const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  SBMLDocument sbmldoc;
  Model sbml = g_registry.GetModule(moduleName)->GetSBMLModel();
  sbmldoc.setModel(&sbml);
  int sbmlret = writeSBML(&sbmldoc, filename);
  if (sbmlret == 0) {
    string error = "Unable to open file ";
    error += filename;
    error += " for writing.";
    g_registry.SetError(error);
  }
  return sbmlret;
}

LIB_EXTERN char* getSBMLString(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  SBMLDocument sbmldoc;
  Model sbml = g_registry.GetModule(moduleName)->GetSBMLModel();
  sbmldoc.setModel(&sbml);
  char* sbmlstring = writeSBMLToString(&sbmldoc);
  g_registry.m_charstars.push_back(sbmlstring);
  return sbmlstring;
}

LIB_EXTERN char* getSBMLInfoMessages(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getCharStar(g_registry.GetModule(moduleName)->GetSBMLInfo().c_str());
}

LIB_EXTERN char* getSBMLWarnings(const char* moduleName)
{
  if (!checkModule(moduleName)) return NULL;
  return getCharStar(g_registry.GetModule(moduleName)->GetSBMLWarnings().c_str());
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
  char **symbolcompartments = getSymbolCompartmentsOfType(moduleName, allSymbols);
  size_t numvars = getNumSymbolsOfType(moduleName, allSymbols);
  for (size_t var=0; var<numvars; var++) {
    cout << symbolnames[var] << " [" << ReturnTypeToString(getTypeOfSymbol(moduleName, symbolnames[var]));
    string compartmentname(symbolcompartments[var]);
    if (compartmentname != "default_compartment") {
      cout << ", in " << compartmentname.c_str();
    }
    cout << "] : " << symbolequations[var] << endl;
  }
  if (getNumDNAStrands(moduleName) > 0) {
    char ***dnanames = getDNAStrands(moduleName);
    const size_t *dnanums = getDNAStrandSizes(moduleName);
    cout << endl << "DNA strands:" << endl;
    for (size_t strand=0; strand<getNumDNAStrands(moduleName); strand++) {
      cout << getNthSymbolNameOfType(moduleName, expandedStrands, strand) << ": ";
      for (size_t element=0; element<dnanums[strand]; element++) {
        if (element != 0 || getIsNthDNAStrandOpen(moduleName, strand, true)) {
          cout << "--";
        }
        cout << dnanames[strand][element];
      }
      if (getIsNthDNAStrandOpen(moduleName, strand, false)) {
        cout << "--";
      }
      cout << endl;
    }
  }

  if (getNumModularDNAStrands(moduleName) > getNumDNAStrands(moduleName))  {
    char ***dnanames = getModularDNAStrands(moduleName);
    const size_t *dnanums = getModularDNAStrandSizes(moduleName);
    cout << endl << "Modular DNA strands:" << endl;
    for (size_t strand=0; strand<getNumModularDNAStrands(moduleName); strand++) {
      cout << getNthSymbolNameOfType(moduleName, modularStrands, strand) << ": ";
      for (size_t element=0; element<dnanums[strand]; element++) {
        if (element != 0 || getIsNthModularDNAStrandOpen(moduleName, strand, true)) {
          cout << "--";
        }
        cout << dnanames[strand][element];
      }
      if (getIsNthModularDNAStrandOpen(moduleName, strand, false)) {
        cout << "--";
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

  if (getNumSymbolsOfType(moduleName, allInteractions) > 0) {
    cout << endl << "Interactions:" << endl;
    char ***leftrxnnames = getInteractorNames(moduleName);
    char ***rightrxnnames = getInteracteeNames(moduleName);
    char **rxnnames = getSymbolNamesOfType(moduleName, allInteractions);
    rd_type *rxndividers = getInteractionDividers(moduleName);  
  
    double **leftrxnstoichs = getInteractorStoichiometries(moduleName);
    double **rightrxnstoichs = getInteracteeStoichiometries(moduleName);

    for (size_t rxn=0; rxn<getNumInteractions(moduleName); rxn++) {
      cout << rxnnames[rxn] << ": ";
      for (size_t var=0; var<getNumInteractors(moduleName,rxn); var++) {
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
      cout << " " << RDToString(rxndividers[rxn]).c_str() << " ";
      for (size_t var=0; var<getNumInteractees(moduleName,rxn); var++) {
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
      cout << " ; " << endl;
    }
  }
  if (getNumEvents(moduleName) > 0) {
    char** eventnames = getEventNames(moduleName);
    
    cout << endl << "Events" << endl;
    for (size_t event=0; event<getNumEvents(moduleName); event++) {
      cout << eventnames[event] << ": @(" << getTriggerForEvent(moduleName, event) << "): ";
      for (size_t asnt=0; asnt<getNumAssignmentsForEvent(moduleName, event); asnt++) {
        if (asnt > 0) {
          cout << ", ";
        }
        cout << getNthAssignmentVariableForEvent(moduleName, event, asnt);
        cout << "=";
        cout << getNthAssignmentEquationForEvent(moduleName, event, asnt);
      }
      cout << endl;
    }
  }
  cout << endl;
}

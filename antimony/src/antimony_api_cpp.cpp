#include <cassert>
#include <string>
#include <cstdlib>
#include <string.h>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifndef NCELLML
#include "cellmlx.h"
#endif

#include "antimony_api_cpp.h"
#include "antimony_api.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "typex.h"

using namespace std;

#define DEFAULTCOMP "default_compartment" //Also defined in module.cpp

extern void reportReactionIndexProblem(unsigned long n, unsigned long actualsize, const char* moduleName, bool reaction=true);

extern void reportReactionSubIndexProblem(unsigned long n, unsigned long actualsize, unsigned long rxnnum, const char* moduleName, bool reaction, bool reactant);

extern void reportVariableTypeIndexProblem(unsigned long n, return_type rtype, unsigned long actualsize, const char* moduleName);

extern unsigned long getNumReactOrProdForRxnOrInt(const char* moduleName, unsigned long n, bool reaction, bool reactant);

LIB_EXTERN vector<string> getModuleNamesAsVector()
{
  unsigned long nummods = getNumModules();
  vector<string> retval;
  for (unsigned long mod=0; mod<nummods; mod++) {
    retval.push_back(getNthModuleName(mod));
  }
  return retval;
}

LIB_EXTERN vector<string> getSymbolNamesInInterfaceOfAsVector(const char* moduleName)
{
  vector<string> names;
  if (!checkModule(moduleName)) return names;
  Module* mod = g_registry.GetModule(moduleName);
  unsigned long intnum = mod->GetNumExportVariables();
  for (unsigned long var=0; var<intnum; var++) {
    names.push_back(getNthSymbolNameInInterfaceOf(moduleName, var));
  }
  return names;
}

LIB_EXTERN vector<vector<string> > getAllReplacementSymbolPairsAsVector(const char* moduleName)
{
  vector<vector<string> > ret;
  if (!checkModule(moduleName)) return ret;
  vector<pair<string, string> > replacements = g_registry.GetModule(moduleName)->GetAllSynchronizedVariablePairs();
  for (size_t n=0; n<replacements.size(); n++) {
    vector<string> two;
    two.push_back(replacements[n].first);
    two.push_back(replacements[n].second);
    ret.push_back(two);
  }
  return ret;
}

LIB_EXTERN vector<string> getNthReplacementSymbolPairAsVector(const char* moduleName, unsigned long n)
{
  vector<string> ret;
  if (!checkModule(moduleName)) return ret;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablePair(n);
  ret.push_back(replacement.first);
  ret.push_back(replacement.second);
  return ret;
}

LIB_EXTERN vector<vector<string> > getAllReplacementSymbolPairsBetweenAsVector(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  vector<vector<string> > ret;
  if (!checkModule(moduleName)) return ret;
  vector<pair<string, string> > replacements = g_registry.GetModule(moduleName)->GetSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName);
  for (size_t n=0; n<replacements.size(); n++) {
    vector<string> two;
    two.push_back(replacements[n].first);
    two.push_back(replacements[n].second);
    ret.push_back(two);
  }
  return ret;
}

LIB_EXTERN vector<string> getNthReplacementSymbolPairBetweenAsVector(const char* moduleName, const char* formerSubmodName, const char* replacementSubmodName, unsigned long n)
{
  vector<string> ret;
  if (!checkModule(moduleName)) return ret;
  pair<string, string> replacement = g_registry.GetModule(moduleName)->GetNthSynchronizedVariablesBetween(formerSubmodName, replacementSubmodName, n);
  ret.push_back(replacement.first);
  ret.push_back(replacement.second);
  return ret;
}

LIB_EXTERN vector<string> getSymbolNamesOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> names;
  if (!checkModule(moduleName)) return names;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      names.clear();
      return names;
    }
    names.push_back(var->GetNameDelimitedBy(g_registry.GetCC()).c_str());
  }
  return names;
}

LIB_EXTERN vector<string> getSymbolDisplayNamesOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> names;
  if (!checkModule(moduleName)) return names;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      names.clear();
      return names;
    }
    names.push_back(var->GetDisplayName());
  }
  return names;
}

LIB_EXTERN vector<string> getSymbolEquationsOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> equations;
  if (!checkModule(moduleName)) return equations;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      equations.clear();
      return equations;
    }
    equations.push_back(var->GetFormula()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()));
  }
  return equations;
}

LIB_EXTERN vector<string> getSymbolInitialAssignmentsOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> equations;
  if (!checkModule(moduleName)) return equations;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      equations.clear();
      return equations;
    }
    equations.push_back(var->GetInitialAssignment()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()));
  }
  return equations;
}

LIB_EXTERN vector<string> getSymbolAssignmentRulesOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> equations;
  if (!checkModule(moduleName)) return equations;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      equations.clear();
      return equations;
    }
    equations.push_back(var->GetAssignmentRuleOrKineticLaw()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()));
  }
  return equations;
}

LIB_EXTERN vector<string> getSymbolRateRulesOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> equations;
  if (!checkModule(moduleName)) return equations;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      equations.clear();
      return equations;
    }
    equations.push_back(var->GetRateRule()->ToDelimitedStringWithStrands(g_registry.GetCC(), var->GetStrandVars()));
  }
  return equations;
}

LIB_EXTERN vector<string> getSymbolCompartmentsOfTypeAsVector(const char* moduleName, return_type rtype)
{
  vector<string> compartments;
  if (!checkModule(moduleName)) return compartments;
  unsigned long vnum = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long n=0; n<vnum; n++) {
    const Variable* var = g_registry.GetModule(moduleName)->GetNthVariableOfType(rtype, n, false);
    if (var==NULL) {
      unsigned long numvars = g_registry.GetModule(moduleName)->GetNumVariablesOfType(rtype, false);
      reportVariableTypeIndexProblem(n, rtype, numvars, moduleName);
      compartments.clear();
      return compartments;
    }
    const Variable* compartment = var->GetCompartment();
    if (compartment == NULL) {
      compartments.push_back(DEFAULTCOMP);
    }
    else {
      compartments.push_back(compartment->GetNameDelimitedBy(g_registry.GetCC()));
    }
  }
  return compartments;
}

string getNthRxnorIntMthReactantOrProductNameAsString(const char* moduleName, unsigned long n, unsigned long m, bool reaction, bool reactant)
{
  if (!checkModule(moduleName)) return NULL;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return NULL;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
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
  if (m >= names.size()) {
    reportReactionSubIndexProblem(m, names.size(), n, moduleName, reaction, reactant);
    return NULL;
  }
  return names[m];
}

vector<string> getNthRxnOrIntReactantOrProductNamesAsVector(const char* moduleName, unsigned long n, bool reaction, bool reactant)
{
  vector<string> names;
  if (!checkModule(moduleName)) return names;
  unsigned long vnum = getNumReactOrProdForRxnOrInt(moduleName, n, reaction, reactant);
  for (unsigned long var=0; var<vnum; var++) {
    names.push_back(getNthRxnorIntMthReactantOrProductNameAsString(moduleName, n, var, reaction, reactant));
  }
  return names;
}

vector<vector<string> > getReactantOrProductNamesForRxnOrIntAsVector(const char* moduleName, bool reaction, bool reactant)
{
  vector<vector<string> > allnames;
  if (!checkModule(moduleName)) return allnames;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long rxn=0; rxn<numlines; rxn++) {
    vector<string> rxnnames = getNthRxnOrIntReactantOrProductNamesAsVector(moduleName, rxn, reaction, reactant);
    allnames.push_back(rxnnames);
  }
  return allnames;
}

LIB_EXTERN vector<vector<string> > getReactantNamesAsVector(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrIntAsVector(moduleName, true, true);
}

LIB_EXTERN vector<string> getNthReactionReactantNamesAsVector(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNamesAsVector(moduleName, n, true, true);
}

LIB_EXTERN vector<vector<string> > getProductNamesAsVector(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrIntAsVector(moduleName, true, false);
}

LIB_EXTERN vector<string> getNthReactionProductNamesAsVector(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNamesAsVector(moduleName, n, true, false);
}

LIB_EXTERN vector<vector<string> > getInteractorNamesAsVector(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrIntAsVector(moduleName, false, true);
}

LIB_EXTERN vector<string> getNthInteractionInteractorNamesAsVector(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNamesAsVector(moduleName, n, false, true);
}

LIB_EXTERN vector<vector<string> > getInteracteeNamesAsVector(const char* moduleName)
{
  return getReactantOrProductNamesForRxnOrIntAsVector(moduleName, false, false);
}

LIB_EXTERN vector<string> getNthInteractionInteracteeNamesAsVector(const char* moduleName, unsigned long n)
{
  return getNthRxnOrIntReactantOrProductNamesAsVector(moduleName, n, false, false);
}

vector<double> getNthRxnOrIntReactantOrProductStoichiometriesAsVector(const char* moduleName, unsigned long n, bool reaction, bool reactant)
{
  vector<double> retstoichiometries;
  if (!checkModule(moduleName)) return retstoichiometries;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  if (n >= numlines) {
    reportReactionIndexProblem(n, numlines, moduleName, reaction);
    return retstoichiometries;
  }
  const Module* mod = g_registry.GetModule(moduleName);
  const Variable* rxn = mod->GetNthVariableOfType(rtype, n, false);
  if (rxn->GetReaction() == NULL) {
    return retstoichiometries;
  }
  vector<double> stoichiometries;
  if (reactant) {
    return rxn->GetReaction()->GetLeft()->GetStoichiometries();
  }
  else {
    return rxn->GetReaction()->GetRight()->GetStoichiometries();
  }
}

vector<vector<double> > getReactantOrProductStoichiometriesForRxnOrIntAsVector(const char* moduleName, bool reaction, bool reactant)
{
  vector<vector<double> > allstoichiometries;
  if (!checkModule(moduleName)) return allstoichiometries;
  return_type rtype = allReactions;
  if (!reaction) {
    rtype = allInteractions;
  }
  unsigned long numlines = getNumSymbolsOfType(moduleName, rtype);
  for (unsigned long rxn=0; rxn<numlines; rxn++) {
    vector<double> rxnstoichiometries = getNthRxnOrIntReactantOrProductStoichiometriesAsVector(moduleName, rxn, reaction, reactant);
    allstoichiometries.push_back(rxnstoichiometries);
  }
  return allstoichiometries;
}

LIB_EXTERN vector<vector<double> > getReactantStoichiometriesAsVector(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrIntAsVector(moduleName, true, true);
}

LIB_EXTERN vector<double> getNthReactionReactantStoichiometriesAsVector(const char* moduleName, unsigned long rxn)
{
  return getNthRxnOrIntReactantOrProductStoichiometriesAsVector(moduleName, rxn, true, true);
}

LIB_EXTERN vector<vector<double> > getProductStoichiometriesAsVector(const char* moduleName)
{
  return getReactantOrProductStoichiometriesForRxnOrIntAsVector(moduleName, true, false);
}

LIB_EXTERN vector<double> getNthReactionProductStoichiometriesAsVector(const char* moduleName, unsigned long rxn)
{
  return getNthRxnOrIntReactantOrProductStoichiometriesAsVector(moduleName, rxn, true, false);
}

LIB_EXTERN vector<vector<double> > getStoichiometryMatrixAsVector(const char* moduleName)
{
  vector<vector<double> > matrix;
  if (!checkModule(moduleName)) return matrix;
  unsigned long nspecies   = getNumSymbolsOfType(moduleName, varSpecies);
  unsigned long nreactions = getNumSymbolsOfType(moduleName, allReactions);
  for (unsigned long rxn=0; rxn<nreactions; rxn++) {
    const AntimonyReaction* reaction = g_registry.GetModule(moduleName)->GetNthVariableOfType(allReactions, rxn, false)->GetReaction();
    vector<double> speciesstoichs;
    for (unsigned long sp=0; sp<nspecies; sp++) {
      const Variable* species = g_registry.GetModule(moduleName)->GetNthVariableOfType(varSpecies, sp, false);
      speciesstoichs.push_back(reaction->GetStoichiometryFor(species));
    }
    matrix.push_back(speciesstoichs);
  }
  return matrix;
}

LIB_EXTERN vector<string>   getStoichiometryMatrixColumnLabelsAsVector(const char* moduleName)
{
  return getSymbolNamesOfTypeAsVector(moduleName, allReactions);
}

LIB_EXTERN vector<string>   getStoichiometryMatrixRowLabelsAsVector(const char* moduleName)
{
  return getSymbolNamesOfTypeAsVector(moduleName, varSpecies);
}

LIB_EXTERN vector<string> getReactionRatesAsVector(const char* moduleName)
{
  return getSymbolEquationsOfTypeAsVector(moduleName, allReactions);
}

LIB_EXTERN vector<string> getReactionNamesAsVector(const char* moduleName)
{
  return getSymbolNamesOfTypeAsVector(moduleName, allReactions);
}

LIB_EXTERN vector<rd_type> getInteractionDividersAsVector(const char* moduleName)
{
  vector<rd_type> typelist;
  if (!checkModule(moduleName)) return typelist;
  unsigned long numints = g_registry.GetModule(moduleName)->GetNumVariablesOfType(allInteractions, false);
  for (unsigned long i=0; i<numints; i++) {
    typelist.push_back(getNthInteractionDivider(moduleName, i));
  }
  return typelist;
}

LIB_EXTERN vector<string> getEventNamesAsVector(const char* moduleName)
{
  return getSymbolNamesOfTypeAsVector(moduleName, allEvents);
}

LIB_EXTERN vector<unsigned long> getDNAStrandSizesAsVector(const char* moduleName)
{
  vector<unsigned long> retval;
  if (!checkModule(moduleName)) return retval;
  unsigned long numDNA = getNumDNAStrands(moduleName);
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval.push_back(g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, strand, false)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC()).size());
  }
  return retval;
}

LIB_EXTERN vector<vector<string> > getDNAStrandsAsVector(const char* moduleName)
{
  vector<vector<string> > retval;
  if (!checkModule(moduleName)) return retval;
  unsigned long numDNA = getNumDNAStrands(moduleName);
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval.push_back(getNthDNAStrandAsVector(moduleName, strand));
  }
  return retval;
}

LIB_EXTERN vector<string> getNthDNAStrandAsVector(const char* moduleName, unsigned long n)
{
  vector<string> strand;
  if (!checkModule(moduleName)) return strand;
  unsigned long actualsize = getNumDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no DNA strand with index " + SizeTToString(n);
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
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return strand;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(expandedStrands, n, false)->GetDNAStrand()->ToExpandedStringVecDelimitedBy(g_registry.GetCC());
}

LIB_EXTERN vector<unsigned long> getModularDNAStrandSizesAsVector(const char* moduleName)
{
  vector<unsigned long> retval;
  if (!checkModule(moduleName)) return retval;
  unsigned long numModularDNA = getNumModularDNAStrands(moduleName);
  for (unsigned long strand=0; strand<numModularDNA; strand++) {
    retval.push_back(g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, strand, false)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC()).size());
  }
  return retval;
}

LIB_EXTERN vector<vector<string> > getModularDNAStrandsAsVector(const char* moduleName)
{
  vector<vector<string> > retval;
  if (!checkModule(moduleName)) return retval;
  unsigned long numDNA = getNumModularDNAStrands(moduleName);
  for (unsigned long strand=0; strand<numDNA; strand++) {
    retval.push_back(getNthModularDNAStrandAsVector(moduleName, strand));
  }
  return retval;
}

LIB_EXTERN vector<string> getNthModularDNAStrandAsVector(const char* moduleName, unsigned long n)
{
  vector<string> strand;
  if (!checkModule(moduleName)) return strand;
  unsigned long actualsize = getNumModularDNAStrands(moduleName);
  if (actualsize <= n) {
    string error = "There is no Modular DNA strand with index " + SizeTToString(n);
    error += " in module ";
    error += moduleName;
    error += ".";
    if (actualsize == 0) {
      error += "  In fact, there are no Modular DNA strands at all in that module.";
    }
    else if (actualsize == 1) {
      error += "  There is a single Modular DNA strand with index 0.";
    }
    else if (actualsize > 1) {
      error += "  Valid Modular DNA strand index values are 0 through ";
      error += SizeTToString(actualsize-1);
      error += ".";
    }
    g_registry.SetError(error);
    return strand;
  }
  return g_registry.GetModule(moduleName)->GetNthVariableOfType(modularStrands, n, false)->GetDNAStrand()->ToModularStringVecDelimitedBy(g_registry.GetCC());
}

#include <string>

#include "antimony_api.h"
#include "simpleantimonyapi.h"
#include "registry.h"

using namespace std;
extern int yyparse();


LIB_EXTERN size_t getNumFloatingSpecies (char* moduleName)
{
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(varSpecies);
}

LIB_EXTERN size_t getNumBoundarySpecies (char* moduleName)
{
  return g_registry.GetModule(moduleName)->GetNumVariablesOfType(constSpecies);
}


LIB_EXTERN const char* getNthFloatingSpeciesName (char* moduleName, size_t n)
{
  return getNthSymbolNameOfType(moduleName, varSpecies, n);
}

LIB_EXTERN const char* getNthBoundarySpeciesName (char* moduleName, size_t n) 
{
  return getNthSymbolNameOfType(moduleName, constSpecies, n);
}


LIB_EXTERN const char** getFloatingSpeciesList (const char* moduleName)
{
  return getSymbolNamesOfType(moduleName, varSpecies);
}

LIB_EXTERN const char** getBoundarySpeciesList (const char* moduleName)
{
  return getConstSymbolNames(moduleName);
}

// ----------------------------------------------------------------------------


LIB_EXTERN const char** getReactionNameList (const char* moduleName)
{
  return getReactionNames (moduleName);
  //return getVariableNamesOfType(moduleName, varReactions);
}

LIB_EXTERN size_t getNumKineticLaws (char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers.size();
}

LIB_EXTERN const char* getNthKineticLaw (char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnrates[n];
}


LIB_EXTERN size_t getNumberReactants (char* moduleName, size_t reactionId)
{
  const size_t *leftnums = getNumReactants(moduleName);
  return leftnums[reactionId];
}


LIB_EXTERN size_t getNumberProducts (char* moduleName, size_t reactionId)
{
  const size_t *leftnums = getNumProducts(moduleName);
  return leftnums[reactionId];
}


// Get the Nth (reactantId) reactant name in reaction reactionId
LIB_EXTERN const char* getNthReactantName (char* moduleName, size_t reactionId, size_t reactantId)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers[reactionId][reactantId];
}

// Get the reactant stoichiometry for the reactantId in reactionId
LIB_EXTERN double getNthReactantStoichiometry (char* moduleName, size_t reactionId, size_t reactantId)
{
  const double* list = getNthReactionReactantStoichiometries(moduleName, reactionId);
  return list[reactantId];
}

LIB_EXTERN const char* getNthProductName (char* moduleName, size_t reactionId, size_t productId)
{
  return g_registry.GetModule(moduleName)->m_rightnamepointers[reactionId][productId];
}

// Get the product stoichiometry for the productId in reactionId
LIB_EXTERN double getNthProductStoichiometry (char* moduleName, size_t reactionId, size_t productId)
{
  const double* list = getNthReactionProductStoichiometries(moduleName, reactionId);
  return list[productId];
}


// Searches for the name of the species 'name' in the floating
// species list. Returns -1 if it can't find the species
// else it returns the location of the species name in 
// the floating species list.
size_t findFloatingSpecies (char* moduleName, const char* name) {

  const char* speciesName;
  for (size_t i=0; i<getNumFloatingSpecies (moduleName); i++) {
    speciesName = getNthFloatingSpeciesName (moduleName, i);
    if (strcmp (speciesName, name) == 0) {
      return i;
    }
  }
  // We didn't find anything so return -1. 
  return -1;
  //LS NOTE:  'size_t' is implemented as 'unsigned' on some architectures.  This should work OK anyway, since, this is a flag value and you don't check '<0' anywhere.
}

// Allows an external caller to free up space created when 
// generating matrices such as the stoichiometry matrix.
LIB_EXTERN void freeMatrix (double** mat, size_t nRows) {
  for (size_t i=0; i<nRows; i++)
    free (mat[i]);
  free (mat);
}


// Rows are ordered according to the list that comes back from getFloatingSpeciesList
// Colums are ordered according to the list that comes back from getReactionNameList
LIB_EXTERN double** myGetStoichiometryMatrix (char* moduleName) {
	
  size_t numReactions = getNumReactions (moduleName);
  size_t numFloatingSpecies = getNumFloatingSpecies (moduleName);
  // Need to check of out of memory error here.....
  double** smat = (double**) malloc (numFloatingSpecies*sizeof (double *));
  for (size_t i=0; i<numFloatingSpecies; i++)
    smat[i] = (double *) malloc (numReactions*sizeof (double));

  // Zero the matrix
  for (size_t i=0; i<numFloatingSpecies; i++)
    for (size_t j=0; j<numReactions; j++)
      smat[i][j] = 0.0;

  for (size_t i=0; i<numReactions; i++) {
    // get the reactants for this reaction
    for (size_t j=0; j<getNumberReactants (moduleName, i); j++) {
      // get the name of this reactant
      const char* name = getNthReactantName (moduleName, i, j);
      // Find out where this reactant is in the species list
      size_t index = findFloatingSpecies (moduleName, name);
      // Only work with species names you find in the floating species list
      if (index != -1) {
        size_t st = getNthReactantStoichiometry (moduleName, i, j);
        smat[index][i] = smat[index][i] - st;
      }
    }
    // get the products for this reaction
    for (size_t j=0; j<getNumberProducts (moduleName, i); j++) {
      // get the name of this reactant
      const char* name = getNthProductName (moduleName, i, j);
      // Find out where this reactant is in the species list
      size_t index = findFloatingSpecies (moduleName, name);
      // Only work with species names you find in the floating species list
      if (index != -1) {
        double st = getNthProductStoichiometry (moduleName, i, j);
        smat[index][i] = smat[index][i] + st;
      }
    }
  }
  return smat;
}


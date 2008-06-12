#include <string>

#include "antimony_api.h"
#include "simpleAntimonyAPI.h"
#include "registry.h"

using namespace std;
extern int yyparse();


LIB_EXTERN int getNumFloatingSpecies (char* moduleName)
{
	return g_registry.GetModule(moduleName)->GetNumVariablesOfType(varSpecies);
}

LIB_EXTERN int getNumBoundarySpecies (char* moduleName)
{
	return g_registry.GetModule(moduleName)->GetNumVariablesOfType(constSpecies);
}


LIB_EXTERN const char* getNthFloatingSpeciesName (char* moduleName, size_t n)
{
  n += g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(varSpecies);
  return g_registry.GetModule(moduleName)->m_variablenames[n];
}

LIB_EXTERN const char* getNthBoundarySpeciesName (char* moduleName, size_t n) 
{
  n += g_registry.GetModule(moduleName)->GetFirstVariableIndexForType(constSpecies);
  return g_registry.GetModule(moduleName)->m_variablenames[n];
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

LIB_EXTERN int getNumKineticLaws (char* moduleName)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers.size();
}

LIB_EXTERN const char* getNthKineticLaw (char* moduleName, size_t n)
{
  return g_registry.GetModule(moduleName)->m_rxnrates[n];
}


LIB_EXTERN int getNumberReactants (char* moduleName, int reactionId)
{
  const size_t *leftnums = getNumReactants(moduleName);
  return leftnums[reactionId];
}


LIB_EXTERN int getNumberProducts (char* moduleName, int reactionId)
{
  const size_t *leftnums = getNumProducts(moduleName);
  return leftnums[reactionId];
}


// Get the Nth (reactantId) reactant name in reaction reactionId
LIB_EXTERN const char* getNthReactantName (char* moduleName, int reactionId, int reactantId)
{
  return g_registry.GetModule(moduleName)->m_leftnamepointers[reactionId][reactantId];
}

// Get the reactant stoichiometry for the reactantId in reactionId
LIB_EXTERN int getNthReactantStoichiometry (char* moduleName, int reactionId, int reactantId)
{
	const double* list = getNthReactionReactantStoichiometries(moduleName, reactionId);
	return list[reactantId];
}

LIB_EXTERN const char* getNthProductName (char* moduleName, int reactionId, int productId)
{
  return g_registry.GetModule(moduleName)->m_rightnamepointers[reactionId][productId];
}

// Get the product stoichiometry for the productId in reactionId
LIB_EXTERN int getNthProductStoichiometry (char* moduleName, int reactionId, int productId)
{
	const double* list = getNthReactionProductStoichiometries(moduleName, reactionId);
	return list[productId];
}


// Searches for the name of the species 'name' in the floating
// species list. Returns -1 if it can't find the species
// else it returns the location of the species name in 
// the floating species list.
int findFloatingSpecies (char* moduleName, const char* name) {

	const char* speciesName;
	for (int i=0; i<getNumFloatingSpecies (moduleName); i++) {
		speciesName = getNthFloatingSpeciesName (moduleName, i);
		if (strcmp (speciesName, name) == 0) {
			return i;
		}
	}
    // We didn't find anything so return -1. 
	return -1;
}

// Allows an external caller to free up space created when 
// generating matrices such as the stoichiometry matrix.
LIB_EXTERN void freeMatrix (double** mat, int nRows) {
		for (int i=0; i<nRows; i++)
			free (mat[i]);
		free (mat);
}


// Rows are ordered according to the list that comes back from getFloatingSpeciesList
// Colums are ordered according to the list that comes back from getReactionNameList
LIB_EXTERN double** myGetStoichiometryMatrix (char* moduleName) {
	
	int numReactions = getNumReactions (moduleName);
	int numFloatingSpecies = getNumFloatingSpecies (moduleName);
    // Need to check of out of memory error here.....
	double** smat = (double**) malloc (numFloatingSpecies*sizeof (double *));
	for (int i=0; i<numFloatingSpecies; i++)
		smat[i] = (double *) malloc (numReactions*sizeof (double));

	// Zero the matrix
	for (int i=0; i<numFloatingSpecies; i++)
		for (int j=0; j<numReactions; j++)
			smat[i][j] = 0.0;

	for (int i=0; i<numReactions; i++) {
		// get the reactants for this reaction
		for (int j=0; j<getNumberReactants (moduleName, i); j++) {
			// get the name of this reactant
			const char* name = getNthReactantName (moduleName, i, j);
			// Find out where this reactant is in the species list
			int index = findFloatingSpecies (moduleName, name);
			// Only work with species names you find in the floating species list
			if (index != -1) {
				int st = getNthReactantStoichiometry (moduleName, i, j);
				smat[index][i] = smat[index][i] - st;
			}
		}
		// get the products for this reaction
		for (int j=0; j<getNumberProducts (moduleName, i); j++) {
			// get the name of this reactant
			const char* name = getNthProductName (moduleName, i, j);
			// Find out where this reactant is in the species list
			int index = findFloatingSpecies (moduleName, name);
			// Only work with species names you find in the floating species list
			if (index != -1) {
				int st = getNthProductStoichiometry (moduleName, i, j);
				smat[index][i] = smat[index][i] + st;
			}
		}
	}
	return smat;
}


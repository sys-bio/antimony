#ifndef SIMPLE_ANTIMONY_API_H
#define SIMPLE_ANTIMONY_API_H

#include "libutil.h"

BEGIN_C_DECLS;

LIB_EXTERN int getNumFloatingSpecies (char* moduleName);
LIB_EXTERN int getNumBoundarySpecies (char* moduleName);

LIB_EXTERN const char* getNthFloatingSpeciesName (char* moduleName, size_t n); 
LIB_EXTERN const char* getNthBoundarySpeciesName (char* moduleName, size_t n); 

LIB_EXTERN const char** getFloatingSpeciesList (const char* moduleName);
LIB_EXTERN const char** getBoundarySpeciesList (const char* moduleName);

LIB_EXTERN const char** getReactionNameList (const char* moduleName);
LIB_EXTERN int getNumKineticLaws (char* moduleName);
LIB_EXTERN const char* getNthKineticLaw (char* moduleName, size_t n);

LIB_EXTERN int getNumberReactants (char* moduleName, int reactionId);
LIB_EXTERN int getNumberProducts (char* moduleName, int reactionId);

LIB_EXTERN int getNthReactantStoichiometry (char* moduleName, int reactionId, int reactantId);
LIB_EXTERN int getNthProductStoichiometry (char* moduleName, int reactionId, int productId);

LIB_EXTERN void freeMatrix (double** mat, int nRows);
LIB_EXTERN double** myGetStoichiometryMatrix (char* moduleName);

END_C_DECLS;

#endif //ANTIMONY_API_H
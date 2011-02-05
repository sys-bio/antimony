#ifndef SIMPLE_ANTIMONY_API_H
#define SIMPLE_ANTIMONY_API_H

#include "libutil.h"

BEGIN_C_DECLS;

LIB_EXTERN size_t getNumFloatingSpecies (char* moduleName);
LIB_EXTERN size_t getNumBoundarySpecies (char* moduleName);

LIB_EXTERN const char* getNthFloatingSpeciesName (char* moduleName, size_t n); 
LIB_EXTERN const char* getNthBoundarySpeciesName (char* moduleName, size_t n); 

LIB_EXTERN const char** getFloatingSpeciesList (const char* moduleName);
LIB_EXTERN const char** getBoundarySpeciesList (const char* moduleName);

LIB_EXTERN const char** getReactionNameList (const char* moduleName);
LIB_EXTERN size_t getNumKineticLaws (char* moduleName);
LIB_EXTERN const char* getNthKineticLaw (char* moduleName, size_t n);

LIB_EXTERN size_t getNumberReactants (char* moduleName, size_t reactionId);
LIB_EXTERN size_t getNumberProducts (char* moduleName, size_t reactionId);

LIB_EXTERN double getNthReactantStoichiometry (char* moduleName, size_t reactionId, size_t reactantId);
LIB_EXTERN double getNthProductStoichiometry (char* moduleName, size_t reactionId, size_t productId);

LIB_EXTERN void freeMatrix (double** mat, size_t nRows);
LIB_EXTERN double** myGetStoichiometryMatrix (char* moduleName);

END_C_DECLS;

#endif //ANTIMONY_API_H

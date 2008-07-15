#ifndef ANTIMONY_API_H
#define ANTIMONY_API_H

#include "libutil.h"
#include "rd_type.h"

BEGIN_C_DECLS;

/* Return types (declared in rd_type.h) are as follows:
num return_type {allSymbols,
                  varSpecies,
                  varProteins,
                  varFormulas,
                  varAnyDNA,
                  varPromoters,
                  varOperators,
                  varGenes,
                  varReactions,
                  varInteractions,
                  varUnknown,
                  constSpecies,
                  constProteins,
                  constFormulas,
                  constAnyDNA,
                  constPromoters,
                  constOperators,
                  constGenes,
                  subModules};
*/

LIB_EXTERN const int loadModel(const char* filename);
LIB_EXTERN const char* getJarnac(const char* moduleName);

LIB_EXTERN size_t getNumModules();
LIB_EXTERN char** getModuleNames();
LIB_EXTERN char*  getNthModuleName(size_t n);
LIB_EXTERN bool checkModule(char* moduleName);

LIB_EXTERN size_t getNumSymbolsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n);
LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n);

LIB_EXTERN size_t getNumReactions(const char* moduleName);
LIB_EXTERN size_t getNumReactants(const char* moduleName, size_t rxn);
LIB_EXTERN size_t getNumProducts(const char* moduleName, size_t rxn);

LIB_EXTERN char*** getReactantNames(const char* moduleName);
LIB_EXTERN char*** getProductNames(const char* moduleName);
LIB_EXTERN double** getReactantStoichiometries(const char* moduleName);
LIB_EXTERN double** getProductStoichiometries(const char* moduleName);

LIB_EXTERN double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n);
LIB_EXTERN double* getNthReactionProductStoichiometries(const char* moduleName, size_t n);

LIB_EXTERN rd_type* getInteractionDividers(const char* moduleName);
LIB_EXTERN rd_type  getNthInteractionDivider(const char* moduleName, size_t n);

LIB_EXTERN double** getStoichiometryMatrix(const char* moduleName);
LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName);
LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName);

LIB_EXTERN char*** getDNAStrands(const char* moduleName);
LIB_EXTERN char**  getNthDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName);
LIB_EXTERN size_t  getNumDNAStrands(const char* moduleName);

LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName);

LIB_EXTERN void freeAll();

LIB_EXTERN void printAllDataFor(const char* moduleName);


END_C_DECLS;

#endif //ANTIMONY_API_H

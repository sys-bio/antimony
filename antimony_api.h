#ifndef ANTIMONY_API_H
#define ANTIMONY_API_H

#include "libutil.h"

BEGIN_C_DECLS;

enum return_type {allSymbols,
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
                  constUnknown,
                  subModules};


LIB_EXTERN const int loadModel(const char* filename);
LIB_EXTERN const char* getJarnac(const char* moduleName);

LIB_EXTERN const size_t getNumModules();
LIB_EXTERN const char** getModuleNames();
LIB_EXTERN const char*  getNthModuleName(size_t n);
LIB_EXTERN bool checkModule(const char* moduleName);

LIB_EXTERN const size_t getNumSymbolsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN const char** getSymbolNamesOfType(const char* moduleName, return_type rtype);
LIB_EXTERN const char** getSymbolEquationsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN const char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n);
LIB_EXTERN const char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n);

LIB_EXTERN const size_t getNumReactions(const char* moduleName);
LIB_EXTERN const size_t getNumReactants(const char* moduleName, size_t rxn);
LIB_EXTERN const size_t getNumProducts(const char* moduleName, size_t rxn);

LIB_EXTERN const char*** getReactantNames(const char* moduleName);
LIB_EXTERN const char*** getProductNames(const char* moduleName);
LIB_EXTERN const double** getReactantStoichiometries(const char* moduleName);
LIB_EXTERN const double** getProductStoichiometries(const char* moduleName);

LIB_EXTERN const char*   getNthReactionMthReactantName(const char* moduleName, size_t n, size_t m);
LIB_EXTERN const char*   getNthReactionMthProductName(const char* moduleName, size_t n, size_t m);
LIB_EXTERN const double* getNthReactionReactantStoichiometries(const char* moduleName, size_t n);
LIB_EXTERN const double* getNthReactionProductStoichiometries(const char* moduleName, size_t n);

LIB_EXTERN const char** getReactionDividers(const char* moduleName);
LIB_EXTERN const char*  getNthReactionDivider(const char* moduleName, size_t n);


//Note:  unimplemented!
LIB_EXTERN const double** getStoichiometryMatrix(const char* moduleName);
LIB_EXTERN const double*  getStoichiometryMatrixNthRow(const char* moduleName, size_t n);
LIB_EXTERN const char**   getStoichiometryMatrixColumnLabels(const char* moduleName);
LIB_EXTERN const char**   getStoichiometryMatrixRowLabels(const char* moduleName);
LIB_EXTERN const char*    getStoichiometryMatrixNthColumnLabel(const char* moduleName, size_t n);
LIB_EXTERN const char*    getStoichiometryMatrixNthRowLabel(const char* moduleName, size_t n);
LIB_EXTERN const char**   getStoichiometryMatrixColumnFormulas(const char* moduleName);
LIB_EXTERN const char*    getStoichiometryMatrixNthColumnFormula(const char* moduleName, size_t n);
LIB_EXTERN const size_t   getStoichiometryMatrixNumRows(const char* moduleName);
LIB_EXTERN const size_t   getStoichiometryMatrixNumColumns(const char* moduleName);
//(end unimplemented section)

LIB_EXTERN const char*** getDNAStrands(const char* moduleName);
LIB_EXTERN const char**  getNthDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN const size_t* getDNAStrandSizes(const char* moduleName);
LIB_EXTERN const size_t  getNumDNAStrands(const char* moduleName);

LIB_EXTERN void printAllDataFor(const char* moduleName);


END_C_DECLS;

#endif //ANTIMONY_API_H

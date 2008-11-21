#ifndef ANTIMONY_API_H
#define ANTIMONY_API_H

#include "libutil.h"
#include "rd_type.h"

BEGIN_C_DECLS;

/* Return types (declared in rd_type.h) are as follows:
enum return_type {allSymbols,
                  allReactions,
                  allInteractions,
                  allUnknown,
                  varSpecies,
                  varFormulas,
                  varAnyDNA,
                  varOperators,
                  varGenes,
                  constSpecies,
                  constFormulas,
                  constAnyDNA,
                  constOperators,
                  constGenes,
                  subModules};
*/

LIB_EXTERN long   loadFile(const char* filename);
LIB_EXTERN long   loadSBMLFile(const char* filename);

LIB_EXTERN size_t getNumFiles();
LIB_EXTERN bool   revertTo(long handle);
LIB_EXTERN void   clearPreviousLoads();
LIB_EXTERN char*  getLastError();

LIB_EXTERN size_t getNumModules();
LIB_EXTERN char** getModuleNames();
LIB_EXTERN char*  getNthModuleName(size_t n);
LIB_EXTERN bool   checkModule(const char* moduleName);

LIB_EXTERN size_t getNumSymbolsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char** getSymbolNamesOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char** getSymbolEquationsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char** getSymbolCompartmentsOfType(const char* moduleName, return_type rtype);
LIB_EXTERN char*  getNthSymbolNameOfType(const char* moduleName, return_type rtype, size_t n);
LIB_EXTERN char*  getNthSymbolEquationOfType(const char* moduleName, return_type rtype, size_t n);
LIB_EXTERN char*  getNthSymbolCompartmentOfType(const char* moduleName, return_type rtype, size_t n);

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
LIB_EXTERN char**   getStoichiometryMatrixRowLabels(const char* moduleName);
LIB_EXTERN char**   getStoichiometryMatrixColumnLabels(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumRows(const char* moduleName);
LIB_EXTERN size_t   getStoichiometryMatrixNumColumns(const char* moduleName);

LIB_EXTERN char**   getReactionRates(const char* moduleName);
LIB_EXTERN char*    getNthReactionRate(const char* moduleName, size_t n);
LIB_EXTERN size_t   getNumReactionRates(const char* moduleName);


LIB_EXTERN size_t  getNumEvents(const char* moduleName);
LIB_EXTERN char**  getEventNames(const char* moduleName);
LIB_EXTERN char*   getNthEventName(const char* moduleName, size_t event);
LIB_EXTERN size_t  getNumAssignmentsForEvent(const char* moduleName, size_t event);
LIB_EXTERN char*   getTriggerForEvent(const char* moduleName, size_t event);
LIB_EXTERN char*   getNthAssignmentVariableForEvent(const char* moduleName, size_t event, size_t n);
LIB_EXTERN char*   getNthAssignmentEquationForEvent(const char* moduleName, size_t event, size_t n);

LIB_EXTERN char*** getDNAStrands(const char* moduleName);
LIB_EXTERN char**  getNthDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN bool    getIsNthDNAStrandOpen(const char* moduleName, size_t n, bool upstream);
LIB_EXTERN size_t* getDNAStrandSizes(const char* moduleName);
LIB_EXTERN size_t  getNumDNAStrands(const char* moduleName);

LIB_EXTERN char*** getModularDNAStrands(const char* moduleName);
LIB_EXTERN char**  getNthModularDNAStrand(const char* moduleName, size_t n);
LIB_EXTERN bool    getIsNthModularDNAStrandOpen(const char* moduleName, size_t n, bool upstream);
LIB_EXTERN size_t* getModularDNAStrandSizes(const char* moduleName);
LIB_EXTERN size_t  getNumModularDNAStrands(const char* moduleName);

LIB_EXTERN return_type getTypeOfSymbol(const char* moduleName, const char* symbolName);
LIB_EXTERN char*   getCompartmentForSymbol(const char* moduleName, const char* symbolName);

//File reading and writing
LIB_EXTERN int   writeAntimonyFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getAntimonyString(const char* moduleName);

LIB_EXTERN int   writeJarnacFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getJarnacString(const char* moduleName);

LIB_EXTERN int   writeSBMLFile(const char* filename, const char* moduleName);
LIB_EXTERN char* getSBMLString(const char* moduleName);

LIB_EXTERN void freeAll();

LIB_EXTERN void printAllDataFor(const char* moduleName);


END_C_DECLS;

#endif //ANTIMONY_API_H

#ifndef SBMLX_H
#define SBMLX_H
#include <string>
#include <vector>
#include "unitdef.h"
#include "enums.h"

#ifndef NSBML
#ifdef WIN32
#define WIN32 1
#endif
#include <sbml/SBMLTypes.h>
class DistribFunctionDefinitionPlugin;

#ifdef USE_COMP
#include <sbml/packages/comp/common/CompExtensionTypes.h>
Model* getModelFromExternalModelDefinition(const ExternalModelDefinition* extmoddef);
#endif //USE_COMP

std::string getNameFromSBMLObject(const SBase* sbml, std::string basename);
//std::string getNameFromSBMLObject(std::string ID, std::string name, std::string basename);
std::string parseASTNodeToString(const ASTNode* ASTform, bool carat=true);
ASTNode* parseStringToASTNode(const std::string& formula);
void makeUnitlessNumbersDimensionless(ASTNode* node);
void caratToPower(ASTNode* node);
void powerToCarat(ASTNode* node);
void GetUnitNames(ASTNode* astn, std::set<std::string>& names);
void GetFunctionNames(ASTNode* astn, std::set<std::string>& names);
bool UsesDistrib(ASTNode* astn);
double GetValueFrom(const ASTNode* astn);
ASTNodeType_t ConstraintTypeToASTType(constraint_type type);

UnitDef GetUnitDefFrom(const UnitDefinition* unitdefinition, std::string modulename);
#endif

void removeBooleanErrors(SBMLDocument* doc);

/// Remove all metaids from document - allows comparisons without metaids
void elideMetaIds(SBMLDocument* doc);
/// Same thing using sbml string as input / output
std::string elideMetaIdsFromSBMLstring(std::string sbml);


constraint_type getConstraintTypeFrom(ASTNodeType_t asttype);
#ifdef LIBSBML_HAS_PACKAGE_FBC
#include "sbml/packages/fbc/common/FbcExtensionTypes.h"
FluxBoundOperation_t getFBOperationFrom(constraint_type ctype);
FluxBoundOperation_t getReverseFBOperationFrom(constraint_type ctype);
FluxBoundOperation_t getFBOperationFrom(ASTNodeType_t asttype);
FluxBoundOperation_t getReverseFBOperationFrom(ASTNodeType_t asttype);
constraint_type getConstraintTypeFrom(FluxBoundOperation_t fbtype);
bool FluxesMatch(const FluxBound* fb1, const FluxBound* fb2);
#endif

#endif

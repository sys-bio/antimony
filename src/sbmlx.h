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
libsbml::Model* getModelFromExternalModelDefinition(const libsbml::ExternalModelDefinition* extmoddef);
#endif //USE_COMP

std::string getNameFromSBMLObject(const libsbml::SBase* sbml, std::string basename);
//std::string getNameFromSBMLObject(std::string ID, std::string name, std::string basename);
std::string parseASTNodeToString(const libsbml::ASTNode* ASTform, bool carat=true);
libsbml::ASTNode* parseStringToASTNode(const std::string& formula);
void makeUnitlessNumbersDimensionless(libsbml::ASTNode* node);
void caratToPower(libsbml::ASTNode* node);
void powerToCarat(libsbml::ASTNode* node);
void GetUnitNames(libsbml::ASTNode* astn, std::set<std::string>& names);
void GetFunctionNames(libsbml::ASTNode* astn, std::set<std::string>& names);
bool UsesDistrib(const libsbml::ASTNode* astn);
double GetValueFrom(const libsbml::ASTNode* astn);
libsbml::ASTNodeType_t ConstraintTypeToASTType(constraint_type type);

UnitDef GetUnitDefFrom(const libsbml::UnitDefinition* unitdefinition, std::string modulename);
#endif

void removeBooleanErrors(libsbml::SBMLDocument* doc);

/// Remove all metaids from document - allows comparisons without metaids
void elideMetaIds(libsbml::SBMLDocument* doc);
/// Same thing using sbml string as input / output
std::string elideMetaIdsFromSBMLstring(std::string sbml);

constraint_type getConstraintTypeFrom(libsbml::ASTNodeType_t asttype);
#ifdef LIBSBML_HAS_PACKAGE_FBC
#include <sbml/packages/fbc/common/FbcExtensionTypes.h>
libsbml::FluxBoundOperation_t getFBOperationFrom(constraint_type ctype);
libsbml::FluxBoundOperation_t getReverseFBOperationFrom(constraint_type ctype);
libsbml::FluxBoundOperation_t getFBOperationFrom(libsbml::ASTNodeType_t asttype);
libsbml::FluxBoundOperation_t getReverseFBOperationFrom(libsbml::ASTNodeType_t asttype);
constraint_type getConstraintTypeFrom(libsbml::FluxBoundOperation_t fbtype);
bool FluxesMatch(const libsbml::FluxBound* fb1, const libsbml::FluxBound* fb2);
#endif

#endif

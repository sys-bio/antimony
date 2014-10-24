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
void caratToPower(ASTNode* node);
void powerToCarat(ASTNode* node);
void GetUnitNames(ASTNode* astn, std::set<std::string>& names);
void GetFunctionNames(ASTNode* astn, std::set<std::string>& names);
double GetValueFrom(ASTNode* astn);

UnitDef GetUnitDefFrom(const UnitDefinition* unitdefinition, std::string modulename);
#endif

void addDistributionToModel(Model* model, distribution_type dtype);

#ifdef LIBSBML_HAS_PACKAGE_DISTRIB
distribution_type GetExactTypeOf(const DistribFunctionDefinitionPlugin* dfdp);
ASTNode* GetAntimonyFormOf(const DistribFunctionDefinitionPlugin* dfdp);
#endif
distribution_type GetDistributionFromAnnotation(const std::string& annot, unsigned int numargs);

#endif

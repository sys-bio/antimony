#ifndef SBMLX_H
#define SBMLX_H
#include <string>
#include <vector>

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#ifdef USE_COMP
#include <sbml/packages/comp/common/CompExtensionTypes.h>
#endif //USE_COMP

std::string getNameFromSBMLObject(const SBase* sbml, std::string basename);
//std::string getNameFromSBMLObject(std::string ID, std::string name, std::string basename);
std::string parseASTNodeToString(const ASTNode* ASTform, bool carat=true);
ASTNode* parseStringToASTNode(const std::string& formula);
void caratToPower(ASTNode* node);
void powerToCarat(ASTNode* node);
#endif


#endif

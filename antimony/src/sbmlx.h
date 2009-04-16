#ifndef SBMLX_H
#define SBMLX_H
#include <string>
#include <vector>

#ifndef NSBML
#include <sbml/SBMLTypes.h>

class Formula;

std::string getNameFromSBMLObject(const SBase* sbml, std::string basename);
//std::string getNameFromSBMLObject(std::string ID, std::string name, std::string basename);
void setFormulaWithString(std::string formulastring, Formula* formula);
string parseASTNodeToString(const ASTNode* ASTform);
ASTNode* parseStringToASTNode(const string& formula);
#endif

void FixName(std::string& name);
void FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);


#endif

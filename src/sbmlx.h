#ifndef SBMLX_H
#define SBMLX_H
#include <string>
#include <vector>

#ifndef NSBML
#include <sbml/SBMLTypes.h>

class Formula;
class Variable;

std::string getNameFromSBMLObject(const SBase* sbml, std::string basename);
//std::string getNameFromSBMLObject(std::string ID, std::string name, std::string basename);
void setFormulaWithString(std::string formulastring, Formula* formula);
std::string parseASTNodeToString(const ASTNode* ASTform);
ASTNode* parseStringToASTNode(const std::string& formula);
#endif

bool FixName(std::string& name);
bool FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);
void FixName(std::map<std::vector<std::string>, Variable*>& varmap);


#endif

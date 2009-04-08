#ifndef SBMLX_H
#define SBMLX_H
#include <string>
#include <vector>
#ifndef NSBML
#include <sbml/SBMLTypes.h>

class Formula;

//std::string getNameFromSBMLObject(const SBase* sbml, std::string basename);
void setFormulaWithString(std::string formulastring, Formula* formula);
#endif

void FixName(std::string& name);
void FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);


#endif

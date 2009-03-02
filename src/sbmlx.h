#ifndef SBMLX_H
#define SBMLX_H

#ifndef NSBML
#include <sbml/SBMLTypes.h>

class Formula;

string getNameFromSBMLObject(const SBase* sbml, string basename);
void setFormulaWithString(std::string formulastring, Formula* formula);
#endif

void FixName(std::string& name);
void FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);


#endif

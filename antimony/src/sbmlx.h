#ifndef SBMLX_H
#define SBMLX_H

#include <sbml/SBMLTypes.h>

class Formula;

string getNameFromSBMLObject(const SBase* sbml, string basename);
void setFormulaWithString(string formulastring, Formula* formula);


#endif

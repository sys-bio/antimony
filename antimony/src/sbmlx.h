#ifndef SBMLX_H
#define SBMLX_H

#ifndef NSBML
#include <sbml/SBMLTypes.h>

class Formula;

string getNameFromSBMLObject(const SBase* sbml, string basename);
void setFormulaWithString(string formulastring, Formula* formula);

#endif

#endif

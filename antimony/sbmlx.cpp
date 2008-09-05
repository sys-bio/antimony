#include "sbmlx.h"
#include "formula.h"
#include "variable.h"
#include "registry.h"

string getNameFromSBMLObject(const SBase* sbml, string basename)
{
  string name = sbml->getId();
  if (name == "") {
    name = sbml->getName();
  }
  if (name=="") {
    long num=0;
    Variable* foundvar = NULL;
    do {
      char charnum[50];
      sprintf(charnum, "%li", num);
      num++;
      name = basename;
      name += charnum;
      vector<string> fullname;
      fullname.push_back(name);
      foundvar = g_registry.CurrentModule()->GetVariable(fullname);
    } while (foundvar != NULL);
  }
  assert(name != "");
  return name;
}

void setFormulaWithString(string formulastring, Formula* formula)
{
  if (formulastring.size()==0) return;
  string formpart = "";
  formpart.push_back(formulastring[0]);
  bool isword((isalpha(formulastring[0]) || formulastring[0]=='_'));
  for (size_t ch=1; ch<formulastring.size(); ch++) {
    char ccurr = formulastring[ch];
    if (isword) {
      if (isalpha(ccurr) || isdigit(ccurr) || ccurr=='_') {
        //continue word
        formpart.push_back(ccurr);
      }
      else {
        //end of word
        if (g_registry.IsFunction(formpart) == NULL) {
          Variable* subvar = g_registry.CurrentModule()->AddOrFindVariable(&formpart);
          formula->AddVariable(subvar);
        }
        else {
          formula->AddText(&formpart);
        }
        formpart.clear();
        formpart.push_back(ccurr);
        isword = false;
      }
    }
    else {
      if (isalpha(ccurr) || ccurr=='_') {
        //new word
        formula->AddText(&formpart);
        formpart.clear();
        formpart.push_back(ccurr);
        isword = true;
      }
      else {
        //continue non-word
        formpart.push_back(ccurr);
      }
    }
  }
  if (isword && g_registry.IsFunction(formpart) == NULL) {
    Variable* subvar = g_registry.CurrentModule()->AddOrFindVariable(&formpart);
    formula->AddVariable(subvar);
  }
  else {
    formula->AddText(&formpart);
  }
}


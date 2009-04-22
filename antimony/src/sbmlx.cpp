#include <cassert>
#include <string>
#include <vector>
#ifndef NSBML
#include "sbmlx.h"
#include "formula.h"
#include "variable.h"
#include "registry.h"

// SBase objects no longer have IDs :( //update: now they do again!
string getNameFromSBMLObject(const SBase* sbml, string basename)
{
  string name = sbml->getId();
  if (name == "") {
    name = sbml->getName();
    //Names can have spaces, so...
    while (name.find(" ") != string::npos) {
      name.replace(name.find(" "), 1, "_");
    }
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

/*
string getNameFromSBMLObject(string ID, string name, string basename)
{
  if (ID != "") return ID;
  if (name != "") return name;
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
  assert(name != "");
  return name;
}
*/
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

void setTimeName(ASTNode *node)  
{
  if (node->getType() == AST_NAME_TIME) {
    node->setName("time");
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    setTimeName(node->getChild(c));
  }
}

string parseASTNodeToString(const ASTNode* ASTform) {
  if (ASTform==NULL) return "";
  ASTNode clone(*ASTform);
  setTimeName(&clone);
  return SBML_formulaToString(&clone);
}


void setTimeType(ASTNode_t* node)  
{
  if (node->isOperator() == false && node->isNumber() == false) {
    if (string(node->getName()) == "time") {
      node->setType(AST_NAME_TIME);
    }
  }
  for (unsigned int c = 0; c < node->getNumChildren() ; c++) {
    setTimeType(node->getChild(c));
  }
}

ASTNode* parseStringToASTNode(const string& formula) {
  ASTNode* rootnode = SBML_parseFormula(formula.c_str());
  if (rootnode == NULL) return NULL;
  if (formula.find("time") != string::npos) {
    setTimeType(rootnode);
  }
  return rootnode;
}

#endif

extern bool CaselessStrCmp(const string& lhs, const string& rhs);

//SBML models might have variable names in them that are reserved keywords in Antimony (like 'compartment', to take a huge example).  FixName fixes this so that you can output readable Antimony again.
void FixName(std::string& name)
{
  const char* keywords[] = {
  "DNA",
  "at",
  "compartment",
  "const",
  "end",
  "event",
  "ext",
  "formula",
  "function",
  "gene",
  "import",
  "in",
  "is",
  "model",
  "module",
  "operator",
  "reaction",
  "species",
  "var",

  "abs"
  , "and"
  , "annotation"
  , "annotation-xml"
  , "apply"
  , "arccos"
  , "arccosh"
  , "arccot"
  , "arccoth"
  , "arccsc"
  , "arccsch"
  , "arcsec"
  , "arcsech"
  , "arcsin"
  , "arcsinh"
  , "arctan"
  , "arctanh"
  , "bvar"
  , "ceiling"
  //  , "ci"
  , "cn"
  , "cos"
  , "cosh"
  , "cot"
  , "coth"
  , "csc"
  , "csch"
  , "csymbol"
  , "degree"
  , "divide"
  , "eq"
  , "exp"
  , "exponentiale"
  , "factorial"
  , "false"
  , "floor"
  , "geq"
  , "gt"
  , "infinity"
  , "lambda"
  , "leq"
  , "ln"
  , "log"
  , "logbase"
  , "lt"
  , "math"
  , "minus"
  , "neq"
  , "not"
  , "notanumber"
  , "or"
  , "otherwise"
  , "pi"
  , "piece"
  , "piecewise"
  , "plus"
  , "power"
  , "root"
  , "sec"
  , "sech"
  , "semantics"
  , "sep"
  , "sin"
  , "sinh"
  , "tan"
  , "tanh"
  , "times"
  , "true"
  , "xor"
  , "acos"
  , "asin"
  , "atan"
  , "ceil"
  , "delay"
  , "log10"
  , "pow"
  , "sqr"
  , "sqrt"
  , "time"
  };
  for (size_t kw=0; kw<97; kw++) {
    if (CaselessStrCmp(name, keywords[kw])) {
      name += "_";
      return;
    }
  }
}

void FixName(std::vector<std::string>& names)
{
  for (size_t n=0; n<names.size(); n++) {
    FixName(names[n]);
  }
}

void FixName(std::vector<std::vector<std::string> >& allnames) 
{
  for (size_t n=0; n<allnames.size(); n++) {
    FixName(allnames[n]);
  }
}



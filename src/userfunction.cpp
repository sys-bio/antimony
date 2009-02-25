#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#include "module.h"
#include "registry.h"

using namespace std;

UserFunction::UserFunction(string name)
  : Module(name),
    m_formula()
{
}

bool UserFunction::SetFormula(const Formula& formula)
{
  string formstring = formula.ToSBMLString();
#ifndef NSBML
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = SBML_parseFormula(formstring.c_str());
    if (ASTform == NULL) {
      g_registry.SetError("The formula \"" + formula.ToDelimitedStringWithEllipses('.') + "\" seems to be incorrect, and cannot be parsed into an Abstract Syntax Tree (AST).");
      return true;
    }
    else {
      delete ASTform;
    }
  }
#endif
  m_formula = formula;
  formstring = formula.ToDelimitedStringWithEllipses('.');
  vector<vector<string> > formvars = formula.GetVariables();
  for (size_t fv=0; fv<formvars.size(); fv++) {
    bool foundvar = false;
    for (size_t ufv=0; ufv<m_exportlist.size(); ufv++) {
      if (formvars[fv] == m_exportlist[ufv]) {
        foundvar = true;
        break;
      }
    }
    if (foundvar == false) {
      g_registry.SetError("In the user-defined function '" + m_modulename + "', the variable '" + formvars[fv][0] + "' was found in the formula itself, but was not exported.  All variables in user-defined functions must be exported, or you end up with formulas with undefined elements.");
      return true;
    }
  }
  for (size_t ufv=0; ufv<m_exportlist.size(); ufv++) {
    bool foundvar = false;
    for (size_t fv=0; fv<formvars.size(); fv++) {
    if (formvars[fv] == m_exportlist[ufv]) {
        foundvar = true;
        break;
      }
    }
    if (foundvar == false) {
      g_registry.SetError("In the user-defined function '" + m_modulename + "', the variable '" + m_exportlist[ufv][0] + "' was found in the function's export list, but not in the formula itself ('" + formula.ToDelimitedStringWithEllipses('.') + "').  This means that any variable assigned to this function would be ignored, and is probably not what you meant.  In any event, it's an illegal Antimony construction.");
      return true;
    }
  }
  return false;
}

string UserFunction::ToSBMLString() const
{
  string lambda = "lambda(";
  for (size_t expv = 0; expv<m_exportlist.size(); expv++) {
    lambda += m_exportlist[expv][0] + ", ";
  }
  lambda += m_formula.ToSBMLString() + ")";
  return lambda;
}

string UserFunction::GetAntimony() const
{
  string func = "function " + m_modulename + "(";
  for (size_t expv = 0; expv<m_exportlist.size(); expv++) {
    func += m_exportlist[expv][0];
    if (expv < m_exportlist.size()-1) {
      func += ", ";
    }
  }
  func += ")\n  " + m_formula.ToDelimitedStringWithEllipses('.') + ";\nend\n";
  return func;
}

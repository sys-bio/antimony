#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#include "module.h"
#include "registry.h"
#include "sbmlx.h"

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
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
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

void UserFunction::FixNames()
{
  Module::FixNames();
  m_formula.FixNames();
}

//True if we need to change the signature of this function, false if not.
bool UserFunction::ChangeTimeToRef()
{
  if (m_formula.ContainsFunction("time")) {
    string trstring = "time_ref";
    Variable* timeref = AddOrFindVariable(&trstring);
    m_formula.ChangeTimeTo(timeref);
    for (size_t exp=0; exp<m_exportlist.size(); exp++) {
      if (GetVariable(m_exportlist[exp])->GetName() == timeref->GetName()) {
        return false; //time_ref already in the export list, for some reason.
      }
    }
    AddVariableToExportList(timeref);
    return true; //time_ref added to export list
  }
  return false; //'time' not in function at all.
}

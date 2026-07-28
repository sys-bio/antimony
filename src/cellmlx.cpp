#ifndef NCELLML

#include "cellmlx.h"

#include <memory>

#include <sbml/math/MathML.h>
#include <sbml/xml/XMLNode.h>

#include "libcellml/component.h"
#include "libcellml/model.h"
#include "libcellml/variable.h"

#include "registry.h"
#include "sbmlx.h"
#include "stringx.h"

using namespace std;
using namespace libsbml;

const char* const CELLML_MATHML_NS = "http://www.w3.org/1998/Math/MathML";

namespace {

// libsbml's MathML writer always returns a complete '<math ...>...</math>'
// document.  CellML component math is built up by concatenating fragments
// like 'x = <rhs>' or 'd(x)/d(t) = <rhs>' inside our own <math> wrapper, so
// we need just the inner content of libsbml's output.
string StripMathWrapper(const string& fullMathML)
{
  size_t start = fullMathML.find("<math");
  if (start == string::npos) return "";
  size_t tagEnd = fullMathML.find('>', start);
  if (tagEnd == string::npos) return "";
  size_t end = fullMathML.rfind("</math>");
  if (end == string::npos || end <= tagEnd) return "";
  return fullMathML.substr(tagEnd + 1, end - tagEnd - 1);
}

}  // namespace

string FormulaStringToMathML(const string& sbmlFormula)
{
  ASTNode* astn = parseStringToASTNode(sbmlFormula);
  if (astn == NULL) {
    return "";
  }
  string fullMathML = writeMathMLToStdString(astn);
  delete astn;
  return StripMathWrapper(fullMathML);
}

string WrapAssignmentMath(const string& varname, const string& rhsMathML)
{
  if (rhsMathML.empty()) return "";
  return "<math xmlns=\"" + string(CELLML_MATHML_NS) + "\"><apply><eq/><ci>" +
         varname + "</ci>" + rhsMathML + "</apply></math>";
}

string WrapRateMath(const string& varname, const string& bvarname, const string& rhsMathML)
{
  if (rhsMathML.empty()) return "";
  return "<math xmlns=\"" + string(CELLML_MATHML_NS) +
         "\"><apply><eq/><apply><diff/><bvar><ci>" + bvarname +
         "</ci></bvar><ci>" + varname + "</ci></apply>" + rhsMathML +
         "</apply></math>";
}

string WrapAlgebraicMath(const string& rhsMathML)
{
  if (rhsMathML.empty()) return "";
  return "<math xmlns=\"" + string(CELLML_MATHML_NS) + "\"><apply><eq/>" +
         rhsMathML + "<cn>0</cn></apply></math>";
}

namespace {

// Concatenates and trims the text content of an element (e.g. the variable
// name inside a <ci>x</ci>).
string GetElementText(XMLNode& node)
{
  string text;
  for (unsigned int i = 0; i < node.getNumChildren(); i++) {
    text += node.getChild(i).getCharacters();
  }
  trim(text);
  return text;
}

// Re-serialises a MathML subtree, wraps it back into a standalone <math>
// document, and hands it to libsbml to turn into an Antimony-side formula
// string.  This is the read-side mirror of FormulaStringToMathML: libsbml
// is only ever asked to understand ordinary content MathML (the same subset
// its own writer produces), never the <diff>/<bvar> wrapper, which we
// recognise ourselves in ParseOneCellMLEquation.
string XMLNodeToFormulaString(XMLNode& node)
{
  string wrapped = "<math xmlns=\"" + string(CELLML_MATHML_NS) + "\">" + node.toXMLString() + "</math>";
  ASTNode* astn = readMathMLFromString(wrapped.c_str());
  if (astn == NULL) {
    g_registry.AddWarning("Unable to parse the MathML expression \"" + node.toXMLString() + "\".");
    return "";
  }
  string formulastring = parseASTNodeToString(astn);
  delete astn;
  return formulastring;
}

// Recognises '<apply><eq/> LHS RHS </apply>'.  If LHS is '<ci>x</ci>' it's a
// plain assignment; if it's '<apply><diff/><bvar><ci>b</ci></bvar><ci>x</ci>
// </apply>' it's a first-derivative rate rule.  Anything else (an
// expression on both sides, e.g. 'x + y = 3') becomes an Antimony algebraic
// rule, stored as the single expression 'LHS - RHS' (which equals zero)--
// the same form Antimony's algebraic rules and SBML's <algebraicRule>
// already use internally.
bool ParseOneCellMLEquation(XMLNode& node, CellMLMathEquation& out)
{
  if (node.getName() != "apply" || node.getNumChildren() < 3) {
    g_registry.AddWarning("Unable to translate the CellML equation \"" + node.toXMLString() + "\" because Antimony only understands simple assignments, first-derivative rate rules, and algebraic equations.");
    return false;
  }
  XMLNode& op = node.getChild(0);
  if (op.getName() != "eq") {
    g_registry.AddWarning("Unable to translate the CellML equation \"" + node.toXMLString() + "\" because it isn't a simple equality.");
    return false;
  }
  XMLNode& lhs = node.getChild(1);
  XMLNode& rhs = node.getChild(2);

  if (lhs.getName() == "apply" && lhs.getNumChildren() >= 3 && lhs.getChild(0).getName() == "diff") {
    XMLNode& bvarNode = lhs.getChild(1);
    if (bvarNode.getName() != "bvar" || bvarNode.getNumChildren() < 1) {
      g_registry.AddWarning("Unable to translate the CellML derivative \"" + lhs.toXMLString() + "\" because Antimony does not handle partial or higher-order derivatives.");
      return false;
    }
    out.kind = CellMLMathEquation::RATE_RULE;
    out.bvarName = GetElementText(bvarNode.getChild(0));
    out.targetVariable = GetElementText(lhs.getChild(2));
    if (out.targetVariable.empty()) return false;
    out.rhsFormula = XMLNodeToFormulaString(rhs);
    return !out.rhsFormula.empty();
  }

  if (lhs.getName() == "ci") {
    out.kind = CellMLMathEquation::ASSIGNMENT;
    out.targetVariable = GetElementText(lhs);
    if (out.targetVariable.empty()) return false;
    out.rhsFormula = XMLNodeToFormulaString(rhs);
    return !out.rhsFormula.empty();
  }

  //A general algebraic equation: neither side is a plain variable.
  string lhsFormula = XMLNodeToFormulaString(lhs);
  string rhsFormula = XMLNodeToFormulaString(rhs);
  if (lhsFormula.empty() || rhsFormula.empty()) return false;
  out.kind = CellMLMathEquation::ALGEBRAIC_RULE;
  out.rhsFormula = "(" + lhsFormula + ") - (" + rhsFormula + ")";
  return true;
}

}  // namespace

vector<CellMLMathEquation> ParseCellMLMath(const string& mathml)
{
  vector<CellMLMathEquation> equations;

  //Component::math() may hold one or more concatenated <math>...</math>
  //blocks (e.g. our own exporter appends one per equation); find each one.
  size_t pos = 0;
  while (true) {
    size_t start = mathml.find("<math", pos);
    if (start == string::npos) break;
    size_t end = mathml.find("</math>", start);
    if (end == string::npos) break;
    end += 7; //length of "</math>"
    string block = mathml.substr(start, end - start);
    pos = end;

    //convertStringToXMLNode wraps non-html/body/annotation/notes top-level
    //elements (like <math>) in a dummy root container--the real element is
    //its first (only) child.
    XMLNode* root = XMLNode::convertStringToXMLNode(block);
    if (root == NULL || root->getNumChildren() == 0) {
      delete root;
      continue;
    }
    XMLNode& mathElement = root->getChild(0);
    for (unsigned int i = 0; i < mathElement.getNumChildren(); i++) {
      CellMLMathEquation equation;
      if (ParseOneCellMLEquation(mathElement.getChild(i), equation)) {
        equations.push_back(equation);
      }
    }
    delete root;
  }
  return equations;
}

namespace {

string GetOwningModelName(const libcellml::ComponentPtr& component)
{
  libcellml::ParentedEntityPtr p = component;
  while (p != nullptr) {
    libcellml::ModelPtr m = std::dynamic_pointer_cast<libcellml::Model>(p);
    if (m != nullptr) {
      return m->name();
    }
    p = p->parent();
  }
  return "";
}

}  // namespace

string CellMLModuleNameFor(const libcellml::ComponentPtr& component)
{
  string modname = GetOwningModelName(component);
  FixName(modname);
  string compname = component->name();
  FixName(compname);
  string cellmlname = modname + "__" + compname;
  FixName(cellmlname);
  return cellmlname;
}

#endif

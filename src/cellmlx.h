#ifndef CELLMLX_H
#define CELLMLX_H

#ifndef NCELLML

#include <string>
#include <vector>

#include "libcellml/types.h"

// The MathML namespace CellML embeds its <math> content in.
extern const char* const CELLML_MATHML_NS;

// --- Export: Antimony formula -> CellML MathML -------------------------

// Converts an Antimony-side formula string (the same infix syntax
// Formula::ToSBMLString() produces) into a CellML MathML fragment, i.e.
// the content of a <math> element without the <math> wrapper itself.
// Returns an empty string if the formula couldn't be parsed.
std::string FormulaStringToMathML(const std::string& sbmlFormula);

// Wraps a MathML expression fragment (as returned by FormulaStringToMathML)
// into a complete CellML <math> block that assigns it to 'varname':
//   varname = <rhsMathML>
// Returns an empty string if rhsMathML is empty.
std::string WrapAssignmentMath(const std::string& varname, const std::string& rhsMathML);

// Wraps a MathML expression fragment into a complete CellML <math> block
// that assigns it to the derivative of 'varname' with respect to 'bvarname':
//   d(varname)/d(bvarname) = <rhsMathML>
// Returns an empty string if rhsMathML is empty.
std::string WrapRateMath(const std::string& varname, const std::string& bvarname, const std::string& rhsMathML);

// Wraps a MathML expression fragment into a complete CellML <math> block
// representing the implicit/algebraic equation '<rhsMathML> = 0'.  This is
// exactly the form Antimony's algebraic rules (and SBML's <algebraicRule>)
// already store internally, so no special CellML-side tagging is needed--
// it's just an ordinary equation.
// Returns an empty string if rhsMathML is empty.
std::string WrapAlgebraicMath(const std::string& rhsMathML);

// --- Import: CellML MathML -> Antimony formula --------------------------

// One equation found inside a CellML component's math.  rhsFormula is a
// formula string in the same infix syntax Formula::ToSBMLString() produces,
// ready for setFormulaWithString():
//  - ASSIGNMENT:      targetVariable = rhsFormula
//  - RATE_RULE:        d(targetVariable)/d(bvarName) = rhsFormula
//  - ALGEBRAIC_RULE:   rhsFormula = 0   (targetVariable/bvarName unused;
//                       this is Antimony's algebraic-rule form)
struct CellMLMathEquation {
  enum Kind { ASSIGNMENT, RATE_RULE, ALGEBRAIC_RULE };
  Kind kind;
  std::string targetVariable;
  std::string bvarName;   // only meaningful when kind == RATE_RULE
  std::string rhsFormula;
};

// Parses the raw math string returned by libcellml::Component::math() (which
// may hold one or more concatenated <math> blocks, each with one or more
// top-level equations) into a list of equations.  Equations that aren't a
// simple equality (e.g. involving a relational operator other than '=', or
// something libSBML's MathML reader itself can't parse) are skipped, with a
// warning.
std::vector<CellMLMathEquation> ParseCellMLMath(const std::string& mathml);

// Antimony's module-name for a (non-imported) CellML component: derived
// deterministically from the component's own name and its owning model's
// name, so it can be recomputed consistently from multiple places without
// needing a lookup table.
std::string CellMLModuleNameFor(const libcellml::ComponentPtr& component);

#endif //NCELLML

#endif //CELLMLX_H

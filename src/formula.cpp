#include <cassert>
#include <iostream>
#include <cassert>

#include "formula.h"
#include "module.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "variable.h"

using namespace std;

void Formula::AddVariable(Variable* var)
{
  pair<string, vector<string> > newvar;
  newvar = make_pair(var->GetNamespace(), var->GetName());
  m_components.push_back(newvar);
}

void Formula::AddNum(double num)
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  stringstream convert;
  convert.precision(15);
  string strnum;
  convert << num;
  convert >> strnum;
  newvar = make_pair(strnum, novar);
  m_components.push_back(newvar);
}

void Formula::AddText(const string* function)
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  newvar = make_pair(*function, novar);
  m_components.push_back(newvar);
}

void Formula::AddMathThing(char maththing)
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  string math = " "; // Make this "   " and the subsequent 0 a 1 for spacing.
  math[0] = maththing;
  newvar = make_pair(math, novar);
  m_components.push_back(newvar);
}

void Formula::AddFormula(const Formula* form2)
{
  m_components.insert(m_components.end(), form2->m_components.begin(), form2->m_components.end());
}

void Formula::AddEllipses()
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  string ellipses = "...";
  newvar = make_pair(ellipses, novar);
  //assert(m_components.size()==0);
  m_components.push_back(newvar);
}

void Formula::AddParentheses()
{
  vector<string> novar;
  pair<string, vector<string> > newvar;
  string math = "(";
  newvar = make_pair(math, novar);
  m_components.insert(m_components.begin(), newvar);
  math = ")";
  newvar = make_pair(math, novar);
  m_components.push_back(newvar);
}

void Formula::SetNewTopName(string newmodname, string newtopname)
{
  for (size_t component=0; component<m_components.size(); component++) {
    if (m_components[component].second.size() > 0) {
      m_components[component].first = newmodname;
      m_components[component].second.insert(m_components[component].second.begin(), newtopname);
    }
  }
}

bool Formula::IsEmpty() const
{
  return m_components.size() == 0;
}

bool Formula::IsDouble() const
{
  if (m_components.size() == 1) {
    if (m_components[0].second.size() == 0) {
      if (IsReal(m_components[0].first)) {
        return true;
      }
    }
  }
  if (m_components.size() == 2) {
    if (m_components[0].second.size() == 0 && m_components[0].first == "-" &&
        m_components[1].second.size() == 0 && IsReal(m_components[1].first) ) {
      return true;
    }
  }
  return false;
}

bool Formula::IsAmountIn(const Variable* compartment) const
{
  if (compartment==NULL) return false;
  size_t check=0;
  if (m_components.size() == 3) {
    if (m_components[0].second.size() == 0) {
      if (IsReal(m_components[0].first)) {
        check = 1;
      }
    }
  }
  else if (m_components.size() == 4) {
    if (m_components[0].second.size() == 0 && m_components[0].first == "-" &&
        m_components[1].second.size() == 0 && IsReal(m_components[1].first) ) {
      check = 2;;
    }
  }
  if (check==0) return false;
  if (m_components[check].second.size() == 0 && m_components[check].first == "/" &&
      m_components[check+1].second == compartment->GetName()) {
    return true;
  }
  return false;
}

double Formula::ToAmount() const
{
  //We will assume that 'IsAmountIn' returned true.
  if (m_components.size() == 3) {
    return atof(m_components[0].first.c_str());
  }
  else if (m_components.size() == 4) {
    return 0 - atof(m_components[1].first.c_str());
  }
  assert(false);
  return 0;
}

bool Formula::IsOne() const
{
  if (m_components.size() == 1) {
    if (m_components[0].second.size() == 0) {
      if (m_components[0].first == "1") {
        return true;
      }
    }
  }
  return false;
}

bool Formula::IsEllipsesOnly() const
{
  if (m_components.size() == 1 &&
      m_components[0].second.size() == 0 &&
      m_components[0].first == "...") {
    return true;
  }
  return false;
}

bool Formula::GetIsConst() const
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0 ) {
      vector<string> varname = m_components[comp].second;
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL);
      const Variable* actualvar = module->GetVariable(varname);
      if (actualvar == NULL) {
        return false; //Can't find the variable in question, so assume.
      }
      else if (!actualvar->GetIsConst()) {
        return false;
      }
    }
  }
  return true;
}

bool Formula::CheckIncludes(string modname, const ReactantList* rlist) const
{
  vector<vector<string> > varlist = rlist->GetVariableList();
  for (size_t var=0; var<varlist.size(); var++) {
    if (!ContainsVar(modname, varlist[var])) {
      g_registry.SetError("should include the variable '" + g_registry.GetModule(modname)->GetVariable(varlist[var])->GetNameDelimitedBy('_') + "' (either directly or indirectly), but it does not.");
      return true;
    }
  }
  return false;
}

bool Formula::ContainsVar(string modname, vector<string> vname) const
{
  Module* module = g_registry.GetModule(modname);
  if (module == NULL) return false;
  Variable* var = module->GetVariable(vname);
  if (var==NULL) return false;
  return ContainsVar(var);
}

bool Formula::ContainsVar(const Variable* outervar) const
{
  for (size_t var=0; var<m_components.size(); var++) {
    if (m_components[var].second.size() > 0) {
      Module* module = g_registry.GetModule(m_components[var].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(m_components[var].second);
      assert(subvar != NULL);
      if (subvar->GetIsEquivalentTo(outervar)) {
        return true;
      }
      const Formula* subformula = subvar->GetFormula();
      if (subformula != NULL) {
        if (subformula->ContainsVar(outervar)) {
          return true;
        }
      }
    }
  }
  return false;
}

bool Formula::ContainsFunction(const std::string& function) const
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() == 0  &&
        m_components[comp].first == function) {
      return true;
    }
  }
  return false;
}


void Formula::Clear()
{
  m_components.clear();
}

string Formula::ToDelimitedStringWithStrands(char cc, vector<pair<Variable*, size_t> > strands) const
{
  string retval;
  if (strands.size() == 0) {
    Variable* novar = NULL;
    strands.push_back(make_pair(novar, 0));
  }
  if (m_components.size() == 0) return "";
  for (size_t strand=0; strand<strands.size(); strand++) {
    if (strand > 0) {
      retval += " + (";
    }
    for (size_t comp=0; comp < m_components.size(); comp++) {
      if (m_components[comp].first == "...") {
        if (strands[strand].second ==0) {
          if (strands[strand].first==NULL) {
            retval += "0";
          }
          else {
            vector<pair<Variable*, size_t> > supervars = strands[strand].first->GetStrandVars();
            assert(supervars.size() < 2);
            if (supervars.size() == 0 || supervars[0].second == 0) {
              retval += "0";
            }
            else {
              retval += "(" + supervars[0].first->GetFormulaForNthEntryInStrand(cc, supervars[0].second-1) + ")";
            }
          }
        }
        else {
          retval += "(" + strands[strand].first->GetFormulaForNthEntryInStrand(cc, strands[strand].second-1) + ")";
        }
      }
      else {
        vector<string> varname = m_components[comp].second;
        Module* module = g_registry.GetModule(m_components[comp].first);
        Variable* actualvar = NULL;
        if (module != NULL) {
          actualvar = module->GetVariable(varname);
        }
        if (actualvar != NULL) {
          retval += actualvar->GetNameDelimitedBy(cc);
        }
        else if (varname.size() > 0) {
          assert(false); //Can't find the variable; should be impossible
        }
        else {
          retval += m_components[comp].first;
        }
      }
    }
    if (strand > 0) {
      retval += ")";
    }
  }
  return retval;
}

string Formula::ToDelimitedStringWithEllipses(char cc) const
{
  string retval;
  for (size_t comp=0; comp < m_components.size(); comp++) {
    vector<string> varname = m_components[comp].second;
    Module* module = g_registry.GetModule(m_components[comp].first);
    Variable* actualvar = NULL;
    if (module != NULL) {
      actualvar = module->GetVariable(varname);
    }
    if (actualvar != NULL) {
      retval += actualvar->GetNameDelimitedBy(cc);
    }
    else {
      assert(varname.size() == 0);
      retval += m_components[comp].first;
    }
  }
  return retval;
}

string Formula::ToSBMLString() const
{
  vector<pair<Variable*, size_t> > nostrands;
  return ToSBMLString(nostrands);
}

string Formula::ToSBMLString(vector<pair<Variable*, size_t> > strands) const
{
  string formula = ToDelimitedStringWithStrands('_', strands);
  //cout << "Original: " << formula << endl;
  string revform = ConvertOneSymbolToFunction(formula);
  while (formula != revform) {
    //cout << "Changing to '" << revform << endl << endl;
    formula = revform;
    revform = ConvertOneSymbolToFunction(formula);
  }
  return formula;
}

string Formula::ConvertOneSymbolToFunction(string formula) const
{
  size_t mid = string::npos;
  string whichfn = "";
  const char* symbols[] = {"<=", ">=", "==", "&&", "||", "!=", "<>", "<", ">", "!"};
  const char* symnames[] = {"leq", "geq", "eq", "and", "or", "neq", "neq", "lt", "gt", "not"};

  for (size_t sym=0; sym<10; sym++) {
    size_t ltgt = formula.find(symbols[sym]);
    if (ltgt != string::npos) {
      mid = ltgt;
      whichfn = symnames[sym];
      break;
    }
  }
  if (mid == string::npos) {
    return formula;
  }
  if (whichfn == "not") {
    formula.replace(mid, 1, "not");
    return formula;
  }
  vector<size_t> openparens;
  openparens.push_back(-1);
  for (size_t chpos=0; chpos<mid; chpos++) {
    if (formula[chpos] == '(') {
      openparens.push_back(chpos);
    }
    else if (formula[chpos] == ')') {
      openparens.pop_back();
    }
  }
  if (openparens.size() == 0) return formula; //error condition--too many )'s
  size_t start = openparens[openparens.size()-1]+1;
  size_t end = formula.size();
  int numnewopens = 0;
  for (size_t chpos=mid; chpos<formula.size(); chpos++) {
    if (formula[chpos] == '(') {
      numnewopens++;
    }
    else if (formula[chpos] == ')') {
      if (numnewopens == 0) {
        end = chpos;
        break;
      }
      numnewopens--;
    }
  }
  formula.insert(end, ")");
  formula[mid] = ',';
  if (whichfn != "lt" && whichfn != "gt") {
    formula.erase(mid+1, 1);
  }
  whichfn += "(";
  formula.insert(start, whichfn);
  //cout << formula << endl;
  return formula;
}

vector<const Variable*> Formula::GetVariablesFrom(string formula, string module) const
{
  vector<const Variable*> retval;
  set<const Variable*> varset;
  string varname = "";
  bool foundname = false;
  for (size_t pos=0; pos<formula.size(); pos++) {
    if (isalpha(formula[pos]) || formula[pos]=='_' ||
        (foundname && (isdigit(formula[pos]))) ||
        (foundname && (formula[pos] == g_registry.GetCC())) ) {
      foundname = true;
      varname += formula[pos];
    }
    else if (foundname) {
      varset.insert(g_registry.GetModule(module)->GetVariableFromSymbol(varname));
      foundname = false;
      varname = "";
    }
  }
  if (foundname) {
    varset.insert(g_registry.GetModule(module)->GetVariableFromSymbol(varname));
  }
  for (set<const Variable*>::iterator var=varset.begin(); var != varset.end(); var++) {
    retval.push_back(*var);
  }
  return retval;
}

vector<vector<string> > Formula::GetVariables() const
{
  vector<vector<string> > vars;
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      vars.push_back(m_components[comp].second);
    }
  }
  return vars;
}

void Formula::FixNames(string modname)
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      FixName(m_components[comp].first);
      FixName(m_components[comp].second);
    }
  }
  /*
  //Check to make sure we're still a legal formula:
#ifndef NSBML
  string formstring = ToSBMLString();
  if (formstring.size() > 0) {
    ASTNode_t* ASTform = parseStringToASTNode(formstring);
    if (ASTform == NULL) {
      //Something went wrong, so maybe something we thought was a function is actually a variable name:
      for (size_t comp=0; comp<m_components.size(); comp++) {
        if (m_components[comp].second.size() == 0) {
          vector<string> possiblevarname;
          possiblevarname.push_back(m_components[comp].first + "_");
          Variable* pvar = g_registry.GetModule(modname)->GetVariable(possiblevarname);
          if (pvar != NULL) {
            m_components[comp].first = modname;
            m_components[comp].second = possiblevarname;
          }
        }
      }
    }
    else {
      delete ASTform;
    }
  }
#endif
  */
}

void Formula::ChangeTimeTo(const Variable* timeref)
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() == 0  &&
        m_components[comp].first == "time") {
      m_components[comp].first = timeref->GetNamespace();
      m_components[comp].second = timeref->GetName();
    }
  }
}

void Formula::InsertTimeInFunction(std::string function)
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() == 0  &&
        m_components[comp].first == function) {
      for (size_t comp2=comp; comp2<m_components.size(); comp2++) {
        if (m_components[comp2].second.size() == 0  &&
            m_components[comp2].first.find(')') != string::npos) {
          m_components[comp2].first.insert(m_components[comp2].first.find(')'), ", time");
          continue;
        }
      }
    }
  }
}

void Formula::ReplaceWith(const Variable* origvar, const Variable* newvar)
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second == origvar->GetName()) {
      m_components[comp].second = newvar->GetName();
    }
  }
}


bool Formula::IsStraightCopyOf(const Formula* origform) const
{
  if (m_components.size() != origform->m_components.size()) {
    //cout << "Different sizes" << endl;
    return false;
  }
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      vector<string> orig = origform->m_components[comp].second;
      vector<string> copy = m_components[comp].second;
      int diff = copy.size() - orig.size();
      assert(diff > 0);
      for (size_t element = 0; element<orig.size(); element++) {
        if (orig[element] != copy[element+diff]) {
          //cout << "Different variable in this spot" << endl;
          return false;
        }
      }
    }
    else {
      if (m_components[comp].first != origform->m_components[comp].first) {
        //cout << "Different texts" << endl;
        return false;
      }
    }
  }
  return true;
}

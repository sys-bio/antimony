#include <cassert>
#include <iostream>
#include <cassert>
#include <cstdlib>

#include "formula.h"
#include "module.h"
#include "registry.h"
#include "stringx.h"
#include "sbmlx.h"
#include "typex.h"
#include "variable.h"

using namespace std;
extern bool CaselessStrCmp(const string& lhs, const string& rhs);

void Formula::AddVariable(const Variable* var)
{
  pair<string, vector<string> > newvar;
  newvar = make_pair(var->GetNamespace(), var->GetName());
  m_components.push_back(newvar);
  m_module = var->GetNamespace();
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

void Formula::AddConversionFactor(const Variable* cf)
{
  if (IsEmpty()) return;
  if (cf==NULL) return;
  AddParentheses();
  AddMathThing('*');
  AddVariable(cf);
  m_conversionFactors.push_back(make_pair(cf->GetNamespace(), cf->GetName()));
}

void Formula::AddInvTimeConversionFactor(const Variable* tcf)
{
  if (IsEmpty()) return;
  if (tcf==NULL) return;
  AddParentheses();
  AddMathThing('/');
  AddVariable(tcf);
  m_timeConversionFactors.push_back(make_pair(tcf->GetNamespace(), tcf->GetName()));
}

void Formula::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  for (size_t component=0; component<m_components.size(); component++) {
    if (m_components[component].second.size() > 0) {
      m_components[component].first = newmodname;
      m_components[component].second.insert(m_components[component].second.begin(), newtopname);
    }
  }
  for (size_t cf=0; cf<m_conversionFactors.size(); cf++) {
    if (m_conversionFactors[cf].second.size() > 0) {
      m_conversionFactors[cf].first = newmodname;
      m_conversionFactors[cf].second.insert(m_conversionFactors[cf].second.begin(), newtopname);
    }
  }
  for (size_t cv=0; cv<m_convertedVariables.size(); cv++) {
    m_convertedVariables[cv].first.insert(m_convertedVariables[cv].first.begin(), newtopname);
    m_convertedVariables[cv].second.insert(m_convertedVariables[cv].second.begin(), newtopname);
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
  else if (m_components.size() == 2) {
    if (m_components[0].second.size() == 0 && m_components[0].first == "-" &&
        m_components[1].second.size() == 0 && IsReal(m_components[1].first) ) {
      return true;
    }
  }
  return false;
}

bool Formula::IsBoolean() const
{
  if (m_components.size() == 1) {
    if (m_components[0].second.size() == 0) {
      if (CaselessStrCmp(m_components[0].first, "true") ||
          CaselessStrCmp(m_components[0].first, "false")) {
        return true;
      }
    }
  }
  return false;
}

bool Formula::GetBoolean() const
{
  assert(IsBoolean());
  if (m_components.size() == 1) {
    if (m_components[0].second.size() == 0) {
      if (CaselessStrCmp(m_components[0].first, "true")) {
        return true;
      }
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

bool Formula::IsSingleVariable() const
{
  if (m_components.size() == 1 &&
      m_components[0].second.size() != 0) {
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
  string cc = g_registry.GetCC();
  vector<vector<string> > varlist = rlist->GetVariableList();
  for (size_t var=0; var<varlist.size(); var++) {
    if (!ContainsVar(modname, varlist[var])) {
      g_registry.SetError("should include the variable '" + g_registry.GetModule(modname)->GetVariable(varlist[var])->GetNameDelimitedBy(cc) + "' (either directly or indirectly), but it does not.");
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

bool Formula::ContainsFunction(const string& function) const
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

string Formula::ToDelimitedStringWithStrands(string cc, vector<pair<Variable*, size_t> > strands) const
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
          if (!retval.empty() && retval[retval.size()-1] != ' ' && retval[retval.size()-1] != '(' && retval[retval.size()-1] != '^') {
            retval += " ";
          }
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

string Formula::ToDelimitedStringWithEllipses(string cc) const
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
      if (!retval.empty() && retval[retval.size()-1] != ' ' && retval[retval.size()-1] != '(' && retval[retval.size()-1] != '^') {
        retval += " ";
      }
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
  return ToDelimitedStringWithStrands(g_registry.GetCC(), strands);
}

//Now only need this for CellML (for now).
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
  openparens.push_back(string::npos);
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
        (foundname && (formula[pos] == g_registry.GetCC()[0])) ) {
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

void Formula::InsertTimeInFunction(string function)
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

void Formula::ReplaceWith(std::vector<std::string> origname, std::vector<std::string> newname)
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second == origname) {
      m_components[comp].second = newname;
    }
  }
}


bool Formula::Matches(const Formula* newform) const
{
  Formula orig(*this);
  //First apply the conversion factors:
  vector<pair<string, vector<string> > > tcfs = newform->m_timeConversionFactors;
  for (size_t tcf=0; tcf<tcfs.size(); tcf++) {
    if (orig.m_timeConversionFactors.size() > tcf) continue;
    //The time conversion is complicated enough it's worth it to find the variable and add it.
    Module* module = g_registry.GetModule(tcfs[tcf].first);
    assert(module != NULL);
    const Variable* timecf = module->GetVariable(tcfs[tcf].second);
    assert(timecf != NULL);
    orig.AddInvTimeConversionFactor(timecf);
  }

  vector<pair<string, vector<string> > > cfs = newform->m_conversionFactors;
  for (size_t cf=0; cf<cfs.size(); cf++) {
    if (orig.m_conversionFactors.size() > cf) continue;
    orig.AddParentheses();
    orig.AddMathThing('*');
    orig.m_conversionFactors.push_back(cfs[cf]);
    orig.m_components.push_back(cfs[cf]);
  }

  vector<pair<vector<string>, vector<string> > > cvs = newform->m_convertedVariables;
  for (size_t cv=0; cv<cvs.size(); cv++) {
    if (orig.m_convertedVariables.size() > cv) continue;
    Module* module = g_registry.GetModule(m_module);
    Variable* converted = module->GetVariable(cvs[cv].first);
    Variable* cf = module->GetVariable(cvs[cv].second);
    if (cvs[cv].first[cvs[cv].first.size()-1] == "time") {
      orig.ConvertTime(cf);
    }
    else {
      orig.Convert(converted, cf);
    }
  }

  //Now see if the components match:
  if (orig.m_components.size() != newform->m_components.size()) return false;
  for (size_t c=0; c<orig.m_components.size(); c++) {
    if (orig.m_components[c].second.size() > 0) {
      Module* module = g_registry.GetModule(orig.m_components[c].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(orig.m_components[c].second);
      assert(subvar != NULL);
      subvar = subvar->GetSameVariable();
      Variable* newvar = module->GetVariable(newform->m_components[c].second);
      if (newvar == NULL || subvar != newvar->GetSameVariable()){
        return false;
      }
    }
    else {
      if (orig.m_components[c] != newform->m_components[c]) {
        return false;
      }
    }
  }
  return true;
}

void Formula::Convert(Variable* converted, Variable* cf)
{
  converted = converted->GetSameVariable();
  vector<pair<string, vector<string> > > oldcomponents = m_components;
  m_components.clear();
  bool usedConverted = false;
  for (size_t comp=0; comp<oldcomponents.size(); comp++) {
    if (oldcomponents[comp].second.size() > 0) {
      Module* module = g_registry.GetModule(oldcomponents[comp].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(oldcomponents[comp].second);
      subvar = subvar->GetSameVariable();
      if (subvar==converted) {
        AddMathThing('(');
        m_components.push_back(oldcomponents[comp]);
        AddMathThing('/');
        AddVariable(cf);
        AddMathThing(')');
        usedConverted = true;
      }
      else {
        m_components.push_back(oldcomponents[comp]);
      }
    }
    else {
      m_components.push_back(oldcomponents[comp]);
    }
  }
  if (usedConverted) {
    m_convertedVariables.push_back(make_pair(converted->GetName(), cf->GetName()));
  }
}

void Formula::ConvertTime(Variable* tcf)
{
  vector<pair<string, vector<string> > > oldcomponents = m_components;
  m_components.clear();
  bool hasTime = false;
  int watchForComma = false;
  int parencount = -1;
  for (size_t comp=0; comp<oldcomponents.size(); comp++) {
    if (oldcomponents[comp].first=="time") {
        AddMathThing('(');
        m_components.push_back(oldcomponents[comp]);
        AddMathThing('/');
        AddVariable(tcf);
        AddMathThing(')');
        hasTime = true;
    }
    else if (oldcomponents[comp].second.size() > 0) {
        //We need to convert references to reactions, too.
        Module* module = g_registry.GetModule(oldcomponents[comp].first);
        assert(module != NULL);
        Variable* subvar = module->GetVariable(oldcomponents[comp].second);
        if (IsReaction(subvar->GetType()) && !subvar->IsReplacedFormRxn()) {
          subvar = subvar->GetSameVariable();
          AddMathThing('(');
          m_components.push_back(oldcomponents[comp]);
          AddMathThing('*');
          AddVariable(tcf);
          AddMathThing(')');
          hasTime = true;
        }
        else {
          m_components.push_back(oldcomponents[comp]);
        }
    }
    else {
      m_components.push_back(oldcomponents[comp]);
    }
    if (oldcomponents[comp].first=="delay") {
      watchForComma = true;
    }
    if (watchForComma && oldcomponents[comp].first=="(") {
      parencount++;
    }
    if (watchForComma && oldcomponents[comp].first==")") {
      parencount--;
    }
    if (watchForComma && parencount==0 && oldcomponents[comp].first==",") {
      AddVariable(tcf);
      AddMathThing('*');
      hasTime = true;
      watchForComma = false;
      parencount = -1;
    }
  }
  if (hasTime) {
    vector<string> timename;
    timename.push_back("time");
    m_convertedVariables.push_back(make_pair(timename, tcf->GetName()));
  }
}

void Formula::UnConvertTimeExtent(Variable* tcf, Variable* xcf)
{
  assert (tcf != NULL || xcf != NULL);
  vector<pair<string, vector<string> > > oldcomponents = m_components;
  m_components.clear();
  for (size_t comp=0; comp<oldcomponents.size(); comp++) {
    if (oldcomponents[comp].second.size() > 0) {
        //We might need to unconvert references to some reactions.
        Module* module = g_registry.GetModule(oldcomponents[comp].first);
        assert(module != NULL);
        Variable* subvar = module->GetVariable(oldcomponents[comp].second);
        if (subvar->IsReplacedFormRxn()) {
          pair<string, vector<string> > oldcomp = oldcomponents[comp];
          m_components.pop_back();
          comp = comp+3;
          if (tcf != NULL && xcf != NULL) {
            m_components.pop_back();
            comp = comp+3;
          }
          m_components.push_back(oldcomp);
          //Have to remove it from our list of conversion factors
          for (vector<pair<vector<string>, vector<string> > >::iterator cv=m_convertedVariables.begin(); 
            cv != m_convertedVariables.end(); ) {
              if ((*cv).first == oldcomp.second) {
                cv = m_convertedVariables.erase(cv);
              }
              else {
                cv++;
              }
          }
        }
        else {
          m_components.push_back(oldcomponents[comp]);
        }
    }
    else {
      m_components.push_back(oldcomponents[comp]);
    }
  }
}

bool Formula::MakeAllVariablesUnits()
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(m_components[comp].second);
      if (subvar->SetType(varUnitDefinition)) return true;
    }
  }
  return false;
}

bool Formula::MakeUnitVariablesUnits()
{
#ifdef NSBML
  //Can't do it.
  return false;
#else
  string formula = ToSBMLString();
  ASTNode* root = parseStringToASTNode(formula);
  set<string> allunits = GetUnitNames(root);
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(m_components[comp].second);
      string unitname = subvar->GetNameDelimitedBy(g_registry.GetCC());
      if (allunits.find(unitname) != allunits.end()) {
        if (subvar->SetType(varUnitDefinition)) return true;
      }
    }
  }
  return false;
#endif
}

#ifndef NSBML
void Formula::SetNewTopNameWith(const SBase* from, const string& modname)
{
  //Only need to do anything if 'from' is in a submodel, which only happens in comp-sbml.
#ifdef USE_COMP
  while (from != NULL) {
    if (from->getTypeCode()==SBML_COMP_SUBMODEL) {
      string submodname = from->getId();
      SetNewTopName(modname, submodname);
    }
    from = from->getParentSBMLObject();
  }
#endif
}

#endif

bool Formula::ClearReferencesTo(Variable* deletedvar)
{
  if (ContainsVar(deletedvar)) {
    Clear();
    return true;
  }
  return false;
}

void Formula::AddReferencedVariablesTo(set<pair<string, const Variable*> >& referencedVars) const
{
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 1) {
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(m_components[comp].second);
      referencedVars.insert(make_pair(subvar->GetNameDelimitedBy(g_registry.GetCC()), subvar));
    }
  }
}

void Formula::UseInstead(string newname, const Variable* oldvar)
{
  vector<string> newfullname;
  newfullname.push_back(newname);
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      Module* module = g_registry.GetModule(m_components[comp].first);
      assert(module != NULL);
      Variable* subvar = module->GetVariable(m_components[comp].second);
      if (subvar==NULL) continue; //Each time we do this, we break the scheme, so if it's broken, it's because of THIS EXACT FUNCTION a nanosecond ago.
      if (subvar->GetIsEquivalentTo(oldvar)) {
        m_components[comp].second = newfullname;
      }
    }
  }
}

string Formula::ToCellML() const
{
  string formula = "";
  //Don't check the variables; just concatenate strings.
  for (size_t comp=0; comp<m_components.size(); comp++) {
    if (m_components[comp].second.size() > 0) {
      assert(m_components[comp].second.size()==1); //CellML formulas can't refer to subvariables.
      formula += ToStringFromVecDelimitedBy(m_components[comp].second, g_registry.GetCC());
    }
    else {
      formula += m_components[comp].first;
    }
  }
  return CellMLify(formula);
}

string Formula::ToCellMLString(vector<pair<Variable*, size_t> > strands) const
{
  string formula = ToDelimitedStringWithStrands(g_registry.GetCC(), strands);
  return CellMLify(formula);
}

string Formula::CellMLify(string formula) const
{
  string revform = ConvertOneSymbolToFunction(formula);
  while (formula != revform) {
    //cout << "Changing to '" << revform << endl << endl;
    formula = revform;
    revform = ConvertOneSymbolToFunction(formula);
  }
#ifndef NSBML
  //Convert through the SBML formula thingy, since it'll do x^y -> pow(x,y) and maybe other stuff.
  ASTNode_t* ASTform = parseStringToASTNode(formula);
  caratToPower(ASTform);
  formula = parseASTNodeToString(ASTform, false);
  delete ASTform;
#endif
  size_t pow = formula.find("pow(");
  while (pow != string::npos) {
    formula.insert(pow+3, "er");
    pow = formula.find("pow(");
  }
  return formula;
}

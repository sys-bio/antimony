#include <sstream>
#include <assert.h>
#include <iostream>
#include "stringx.h"
#include "registry.h"
extern bool CaselessStrCmp(const std::string& lhs, const std::string& rhs);

using namespace std;

string SizeTToString(size_t number)
{
  ostringstream ostr;
  ostr << number;
  string s(ostr.str());
  return s;
}

string ToStringFromVecDelimitedBy(vector<string> name, char cc)
{
  string retval = "";
  for (size_t nn=0; nn<name.size(); nn++) {
    if (nn>0) {
      retval += cc;
    }
    retval += name[nn];
  }
  return retval;
}

bool IsReal(const string& src)
{
  if (src.empty()) return false;

  long i;
  long end = src.size();
  bool pointfound = false;
  for (i = 0; i < end; ++i) {
    if (!isdigit(src[i])) {
      if (isspace(src[i])) continue; // whitespace is okay
      if (src[i] == '-') continue; // minus is okay
      if (src[i] == '+') continue; // plus is okay
      if (src[i] == 'e') continue; // e is okay
      if (src[i] != '.') return false;  // neither digit nor point
      if (pointfound) return false;   // a second decimal point?!
      pointfound = true;              // okay, first decimal point
    }
  }
  return true;
} /* IsReal */

wstring ToWString(std::string in)
{
  wstring out;
  for (size_t ch=0; ch<in.size(); ch++) {
    out.push_back(in[ch]);
  }
  return out;
}
  
string ToThinString(std::wstring in)
{
  string out;
  for (size_t ch=0; ch<in.size(); ch++) {
    out.push_back(in[ch]);
  }
  return out;
}

string Trim(std::string in)
{
  string out = in;
  while (out.size() && out[0] == ' ') {
    out.erase(0,1);
  }
  while (out.size() && out[out.size()-1] == ' ') {
    out.erase(out.size()-1, 1);
  }
  size_t retpos;
  while ((retpos = out.find('\n')) != string::npos) {
    out.replace(retpos, 1, " ");
  }
  while ((retpos = out.find('\r')) != string::npos) {
    out.replace(retpos, 1, " ");
  }
  return out;
}

std::string AndsAndOrs(std::string& in)
{
  string out = in;
  size_t andpos;
  while ((andpos = out.find(" and ")) != string::npos) {
    string left, right;
    left.assign(out, 0, andpos);
    right.assign(out, andpos+5, out.size()-andpos-5);
    out = "(" + left + ") && (" + right + ")";
  }

  size_t orpos;
  while ((orpos = out.find(" or ")) != string::npos) {
    string left, right;
    left.assign(out, 0, orpos);
    right.assign(out, orpos+4, out.size()-orpos-4);
    out = "(" + left + ") || (" + right + ")";
  }
  return out;
}


void setFormulaWithString(string formulastring, Formula* formula, Module* module)
{
  //Note:  this function is a version of the antimony.ypp lexer.
  if (formulastring.size()==0) return;
  string formpart = "";
  stringstream input;
  input << formulastring;

  while (input.good()) {
    char cc = 0;
    input.get(cc);

    // Skip white space.
    bool somewhite = false;
    string white = " ";
    while ((cc == ' ' || cc == '\t') &&
           input.good()) {
      input.get(cc);
      somewhite = true;
    }
    if (!input.good()) continue;
    if (somewhite) formula->AddText(&white);

    // Parse words
    if (isalpha(cc) || cc == '_') {
      string word;
      vector<string> fullname;
      while ((isalpha(cc) || isdigit(cc) || cc == '_' || cc == '.') && !input.eof()) {
        word += cc;
        input.get(cc);
      }
      if (input.good()) {
        input.unget();
      }
      if (g_registry.IsFunction(word) != NULL) {
        fullname.push_back(word);
        Variable* subvar = module->GetVariable(fullname);
        if (subvar == NULL) {
          formula->AddText(&word);
        }
        else {
          formula->AddVariable(subvar);
        }
        continue;
      }
      if (g_registry.IsModuleName(word)) {
        FixName(word);
      }
      /*  Apparantly this is a bad idea, for some reason.  We'll FixName stuff later, instead.
      if ((CaselessStrCmp(word, "module")) || (CaselessStrCmp(word, "model")) || (CaselessStrCmp(word, "end")) ||
          (CaselessStrCmp(word, "species")) || (CaselessStrCmp(word, "formula")) || (CaselessStrCmp(word, "reaction")) ||
          (CaselessStrCmp(word, "DNA")) || (CaselessStrCmp(word, "gene")) || (CaselessStrCmp(word, "operator")) ||
          (CaselessStrCmp(word, "compartment")) || (CaselessStrCmp(word, "in")) || (CaselessStrCmp(word, "is")) ||
          (CaselessStrCmp(word, "var")) || (CaselessStrCmp(word, "const")) || (CaselessStrCmp(word, "ext")) ||
          (CaselessStrCmp(word, "import")) || (CaselessStrCmp(word, "event")) || (CaselessStrCmp(word, "at")) ||
          (CaselessStrCmp(word, "after")) || (CaselessStrCmp(word, "function"))) {
        //FixName(word);
      }
      */
      size_t pointpos;
      while ((pointpos = word.find('.')) != string::npos) {
        string onebit = word;
        onebit.erase(pointpos, word.size()-pointpos);
        fullname.push_back(onebit);
        word.erase(0, pointpos+1);
      }
      fullname.push_back(word);
      Variable* subvar = module->GetVariable(fullname);
      if (subvar == NULL) {
        assert(fullname.size() == 1);
        subvar = module->AddOrFindVariable(&word);
      }
      assert (subvar != NULL);
      formula->AddVariable(subvar);
      continue;
    }

    // Parse numbers
    else if (isdigit(cc)) {
      double number;
      input.unget();
      streampos prenum = input.tellg();
      input >> number;
      streampos postnum = input.tellg();

      //Now check to see if the last thing read was an 'E'/'e'
      input.unget();
      input.get(cc);
      if (cc == 'e' || cc == 'E') {
        input.unget();
        postnum = input.tellg();
      }
      string num;
      num.assign(formulastring, prenum, postnum-prenum);
      //cout << "Text: '" << num << "'" << endl;
      //cout << "Number: '" << number << "'" << endl;
      formula->AddText(&num);
      continue;
    }

    //Parse ellipses
    if (cc == '.') {
      char c1, c2;
      input.get(c1);
      input.get(c2);
      if (c1=='.' && c2=='.') {
        formula->AddEllipses();
        continue;
      }
      input.unget();
      input.unget();
    }
    string text;
    text.push_back(cc);
    formula->AddText(&text);
  }
}


#include <sstream>
#include <assert.h>
#include <iostream>
#include "stringx.h"
#include "typex.h"
#include "registry.h"
#include <limits>
#include <stdlib.h>

using namespace std;
extern bool CaselessStrCmp(bool caseless, const string& lhs, const string& rhs);

string SizeTToString(size_t number)
{
  ostringstream ostr;
  ostr << number;
  return ostr.str();
}

string DoubleToString(double number)
{
  ostringstream ostr;
  ostr << number;
  return ostr.str();
}

string ToStringFromVecDelimitedBy(vector<string> name, std::string cc)
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
  if (CaselessStrCmp(true, src, "inf")) return true;
  if (CaselessStrCmp(false, src, "infinity")) return true;
  if (CaselessStrCmp(true, src, "NaN")) return true;
  if (CaselessStrCmp(true, src, "-inf")) return true;
  if (CaselessStrCmp(false, src, "-infinity")) return true;

  long i;
  size_t end = src.size();
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

double GetReal(const string& src)
{
  if (src.empty()) return false;
  if (CaselessStrCmp(true, src, "inf")) return numeric_limits<double>::infinity();
  if (CaselessStrCmp(false, src, "infinity")) return numeric_limits<double>::infinity();
  if (CaselessStrCmp(true, src, "-inf")) return -numeric_limits<double>::infinity();
  if (CaselessStrCmp(false, src, "-infinity")) return -numeric_limits<double>::infinity();
  if (CaselessStrCmp(true, src, "NaN")) return numeric_limits<double>::quiet_NaN();
  if (CaselessStrCmp(false, src, "notanumber")) return numeric_limits<double>::quiet_NaN();
  if (CaselessStrCmp(true, src, "-NaN")) return numeric_limits<double>::quiet_NaN();
  if (CaselessStrCmp(false, src, "-notanumber")) return numeric_limits<double>::quiet_NaN();

  return atof(src.c_str());
} /* IsReal */

wstring ToWString(string in)
{
  wstring out;
  for (size_t ch=0; ch<in.size(); ch++) {
    out.push_back(in[ch]);
  }
  return out;
}
  
string ToThinString(wstring in)
{
  string out;
  for (size_t ch=0; ch<in.size(); ch++) {
	  out.push_back(static_cast<char>(in[ch]));
  }
  return out;
}

string Trim(string in)
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

string AndsAndOrs(string& in)
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

string StripMsgXML(string& in)
{
  string out = in;
  size_t xhtmlpos = out.find("xhtml\">");
  if (xhtmlpos != string::npos) {
    out.erase(0,xhtmlpos+7);
  }
  size_t slashppos = out.find("</p>");
  if (slashppos != string::npos) {
    out.erase(slashppos, out.size()-slashppos+1);
  }
  return out;
}

string NormalizeLineEndings(string in) {
  string out;
  for(int i=0; i<in.size(); ++i) {
    if (in[i] != '\r')
      out.push_back(in[i]);
  }
  return out;
}


void setFormulaWithString(string formulastring, Formula* formula, Module* module)
{
  //Note:  this function is a version of the antimony.ypp lexer.
  formula->Clear();
  if (formulastring.size()==0) return;
  string formpart = "";
  stringstream input;
  input << formulastring;

  while (input.good()) {
    char cc = 0;
    input.get(cc);

    // Skip white space.
    //bool somewhite = false;
    //string white = " ";
    while ((cc == ' ' || cc == '\t') &&
           input.good()) {
      input.get(cc);
      //somewhite = true;
    }
    if (!input.good()) continue;
    //if (somewhite) formula->AddText(&white);

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
      if (g_registry.IsFunction(word) != NULL || g_registry.IsConstant(word)) {
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
      //if (module->IsRateOfSymbol(word)) {
      //  formula->AddText(&word);
      //  continue;
      //}
      //if (StringToDistributionType(word) != distUNKNOWN) {
      //  formula->AddText(&word);
      //  continue;
      //}
      if (g_registry.IsModuleName(word)) {
        FixName(word);
      }
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
      num.assign(formulastring, static_cast<size_t>(prenum), static_cast<size_t>(postnum-prenum));
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

bool CaselessStrCmp(bool caseless, const string& lhs, const string& rhs)
{
    if (caseless) {
        if (lhs.size() != rhs.size()) return false;

        for (size_t i = 0; i < lhs.size(); ++i) {
            if (toupper(lhs[i]) != toupper(rhs[i])) return false;
        }
        return true;
    }
    return lhs == rhs;

} /* CaselessStrCmp */

void FixUnitName(string& name)
{
  if (name.size()>2 && name[name.size()-1]=='s' && name[name.size()-2]!='_' 
      && name != "dimensionless"
      && name.find("siemens") == string::npos
      && name.find("per_nM") == string::npos) //Biomodels 223 (sigh) 
  {
    name.erase(name.size()-1, name.size());
  }
  if (CaselessStrCmp(false, name, "meter")) {
    name = "metre";
  }
  if (CaselessStrCmp(false, name, "liter")) {
    name = "litre";
  }
  if (CaselessStrCmp(false, name, "time")) {
    name = "time_unit";
  }
}

string escapeDoubleQuotes(string s)
{
  string::size_type n=0;
  while((n=s.find("\"",n)) < string::npos) {
    s.insert(n, "\\");
    n+=2;
  }
  return s;
}

void gitdiffit(const std::string& before, const std::string& after)
{
  system(("git -c color.ui=always diff $(echo \"" +
    escapeDoubleQuotes(before) +
    "\" | git hash-object -w --stdin) $(echo \"" +
    escapeDoubleQuotes(after) +
    "\" | git hash-object -w --stdin) --color-words | tail -n +6").c_str());
}

//From https://stackoverflow.com/questions/216823/how-to-trim-an-stdstring
// trim from start (in place)
void ltrim(std::string& s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
}

// trim from end (in place)
void rtrim(std::string& s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), s.end());
}

// trim from both ends (in place)
void trim(std::string& s) {
    rtrim(s);
    ltrim(s);
}

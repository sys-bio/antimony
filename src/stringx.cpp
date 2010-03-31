#include <sstream>
#include <assert.h>
#include <iostream>
#include "stringx.h"

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

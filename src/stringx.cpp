#include <sstream>
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

#ifndef NCELLML
std::string ToThinString(const PRUnichar* in)
{
  string out;
  for (size_t ch=0; (in[ch] != '\0'); ch++) {
    out.push_back(in[ch]);
  }
  return out;
}

nsString ToNSString(const std::string in)
{
  PRUnichar out[in.size()+1];
  
  for (size_t ch=0; ch<in.size(); ch++) {
    out[ch] = in[ch];
  }

  return nsDependentString(out, in.size());
}

#endif

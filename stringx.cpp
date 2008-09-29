#include <sstream>
#include "stringx.h"

using namespace std;

string ToString(size_t number)
{
  ostringstream ostr;
  ostr << number;
  string s(ostr.str());
  return s;
}

string ToStringDelimitedBy(vector<string> name, char cc)
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


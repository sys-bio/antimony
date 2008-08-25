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


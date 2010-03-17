#ifndef STRINGX_H
#define STRINGX_H

#include <string>
#include <vector>
#include "enums.h"

std::string SizeTToString(size_t num);
std::string ToStringFromVecDelimitedBy(std::vector<std::string> name, char cc);
std::wstring ToWString(std::string in);
std::string ToThinString(std::wstring in);
std::string Trim(std::string in);
std::string AndsAndOrs(std::string& in);

bool IsReal(const std::string& src);

#endif //STRINGX_h

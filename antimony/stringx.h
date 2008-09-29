#ifndef STRINGX_H
#define STRINGX_H

#include <string>
#include <vector>

std::string ToString(size_t num);
std::string ToStringDelimitedBy(std::vector<std::string> name, char cc);
bool IsReal(const std::string& src);

#endif //STRINGX_h

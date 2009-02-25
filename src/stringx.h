#ifndef STRINGX_H
#define STRINGX_H

#include <string>
#include <vector>

std::string SizeTToString(size_t num);
std::string ToStringFromVecDelimitedBy(std::vector<std::string> name, char cc);
bool IsReal(const std::string& src);

#endif //STRINGX_h


#ifndef STRINGX_H
#define STRINGX_H

#include <string>
#include <vector>
#include <map>
#include "enums.h"

class Formula;
class Module;
class Variable;

std::string SizeTToString(size_t num);
std::string DoubleToString(double num);
std::string ToStringFromVecDelimitedBy(std::vector<std::string> name, std::string cc);
std::wstring ToWString(std::string in);
std::string ToThinString(std::wstring in);
std::string Trim(std::string in);
std::string AndsAndOrs(std::string& in);

bool IsReal(const std::string& src);
void setFormulaWithString(std::string formulastring, Formula* formula, Module* module);
bool FixName(std::string& name);
bool FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);
void FixName(std::map<std::vector<std::string>, Variable*>& varmap);
void FixUnitName(std::string& name);

bool CaselessStrCmp(const std::string& lhs, const std::string& rhs);

#endif //STRINGX_h

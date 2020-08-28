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
std::string StripMsgXML(std::string& in);
// removes the \r in \r\n
std::string NormalizeLineEndings(std::string in);

bool IsReal(const std::string& src);
double GetReal(const std::string& src);
void setFormulaWithString(std::string formulastring, Formula* formula, Module* module);
bool FixName(std::string& name);
bool FixName(std::vector<std::string>& names);
void FixName(std::vector<std::vector<std::string> >& allnames);
void FixName(std::map<std::vector<std::string>, Variable*>& varmap);
void FixUnitName(std::string& name);

bool CaselessStrCmp(bool caseless, const std::string& lhs, const std::string& rhs);

// JKM escapes double quotes for use with gitdiffit
std::string escapeDoubleQuotes(std::string s);
// JKM performs a git diff of the two strings (used in debugging, not in production code)
void gitdiffit(const std::string& before, const std::string& after);

#endif //STRINGX_h

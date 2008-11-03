#ifndef FORMULA_H
#define FORMULA_H

#include <string.h>
#include <utility>
#include <vector>

class ReactantList;
class Variable;

class Formula
{
private:
  //Formula(const Formula& src); //Undefined
  //Formula& operator=(const Formula& src); //Undefined

  std::vector<std::pair<std::string, std::vector<std::string> > > m_components;

public:
  Formula() {};
  ~Formula() {};

  void AddVariable(Variable* var);
  void AddNum(double num);
  void AddMathThing(char maththing);
  void AddText(const std::string* function);
  void AddEllipses();

  void SetNewTopName(std::string newmodname, std::string newtopname);

  bool IsEmpty() const;
  bool IsSimpleVariable() const;
  bool IsDouble() const;
  bool IsEllipsesOnly() const;
  bool GetIsConst() const;
  bool CheckIncludes(std::string modname, ReactantList* rlist) const;
  bool ContainsVar(std::string modname, std::vector<std::string> vname) const;
  bool ContainsVar(const Variable* outervar) const;

  size_t GetNumVariables() const;
  const Variable* GetNthVariable(size_t n) const;

  void Clear();

  std::vector<std::string> GetSimpleVariable() const;

  std::string ToStringDelimitedBy(char cc) const { return ToDelimitedStringWithUpvar(cc, NULL);} ;
  std::string ToDelimitedStringWithUpvar(char cc, Variable* var) const;
  std::string ToDelimitedStringWithEllipses(char cc) const;
};


#endif //FORMULA_H

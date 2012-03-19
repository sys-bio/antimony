#ifndef UNITDEF_H
#define UNITDEF_H

#include <string>
#include <utility>
#include <vector>
#include "unitelement.h"

class ReactantList;
class Variable;

class UnitDef
{
private:
  //UnitDef(const UnitDef& src); //Undefined
  //UnitDef& operator=(const UnitDef& src); //Undefined

  std::vector<UnitElement> m_components;
  std::string m_name;
  bool m_nameautogenerated;
  std::string m_module; //The name of the high-level module we're in.

public:
  UnitDef(std::string name);
  ~UnitDef() {};

  void SetName(std::string name);
  void MultiplyUnitDef(UnitDef* unitdef);
  void RaiseTo(double pow);
  void MultiplyBy(double mult);
  void AddUnitElement(const UnitElement& ue);
  bool GetNameAutoGenerated();

  bool Matches(UnitDef* unitdef);
  bool ComponentsMatch(UnitDef* unitdef);
  bool IsOnlyKind();

  std::string GetName();
  void Invert();
  UnitDef* GetCanonical(std::set<std::string> usednames);

private:

};


#endif //UNITDEF_H

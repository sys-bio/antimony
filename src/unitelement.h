#ifndef UNITELEMENT_H
#define UNITELEMENT_H

#include <string>
#include <utility>
#include <vector>

#ifndef NSBML
#include <sbml/Unit.h>
#endif


class UnitElement
{
private:

  std::string m_kind;
  double m_exponent;
  double m_multiplier;
  long m_scale;

public:
  UnitElement(std::string kind);
#ifndef NSBML
  UnitElement(const Unit* unit);
#endif
  ~UnitElement() {};
  bool operator<(const UnitElement& ue) const;

  void SetKind(std::string name);
  void SetExponent(double exponent);
  void SetMultiplier(double multiplier);
  void SetScale(long scale);
  void MultiplyBy(double newmult);
  void Invert();

  std::string GetKind() const;
  double GetExponent() const;
  double GetMultiplier() const;
  long GetScale() const;

  bool Matches(const UnitElement& ue) const;
  bool KindIsCanonical() const;
  
  std::string ToString() const;
  std::string ToInvString() const;
};


#endif //UNITELEMENT_H

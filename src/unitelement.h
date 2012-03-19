#ifndef UNITELEMENT_H
#define UNITELEMENT_H

#include <string>
#include <utility>
#include <vector>


class UnitElement
{
private:

  std::string m_kind;
  double m_exponent;
  double m_multiplier;
  long m_scale;

public:
  UnitElement(std::string kind);
  ~UnitElement() {};
  bool operator<(const UnitElement& ue) const;

  void SetKind(std::string name);
  void SetExponent(double exponent);
  void SetMultiplier(double multiplier);
  void SetScale(long scale);
  void MultiplyBy(double newmult);
  void Invert();

  std::string GetKind();
  double GetExponent();
  double GetMultiplier();
  long GetScale();

  bool Matches(const UnitElement& ue) const;
  bool KindIsCanonical() const;
  
};


#endif //UNITELEMENT_H

#include "unitelement.h"
#include <cmath>
#include <sbml/UnitKind.h>

using namespace std;

UnitElement::UnitElement(std::string kind)
  : m_kind(kind)
  , m_exponent(1)
  , m_multiplier(1)
  , m_scale(0)
{
}

bool UnitElement::operator<(const UnitElement& ue) const
{
  if (m_kind != ue.m_kind) {
    return m_kind<ue.m_kind;
  }
  if (m_exponent != ue.m_exponent) {
    return m_exponent < ue.m_exponent;
  }
  if (m_multiplier != ue.m_multiplier) {
    return m_multiplier < ue.m_multiplier;
  }
  return m_scale < ue.m_scale;
}

void UnitElement::SetKind(std::string name)
{
  m_kind = name;
}

void UnitElement::SetExponent(double exponent)
{
  m_exponent = exponent;
}

void UnitElement::SetMultiplier(double multiplier)
{
  m_multiplier = multiplier;
}

void UnitElement::SetScale(long scale)
{
  m_scale = scale;
}

void UnitElement::MultiplyBy(double newmult)
{
  newmult = newmult * m_multiplier * pow(10, m_scale);
  m_scale = floor(log10(newmult));
  m_multiplier = newmult/pow(10, m_scale);
}

void UnitElement::Invert()
{
  m_exponent = -m_exponent;
}

string UnitElement::GetKind()
{
  return m_kind;
}

double UnitElement::GetExponent()
{
  return m_exponent;
}

double UnitElement::GetMultiplier()
{
  return m_multiplier;
}

long UnitElement::GetScale()
{
  return m_scale;
}

bool UnitElement::Matches(const UnitElement& ue) const
{
  if (m_kind != ue.m_kind) return false;
  if (m_multiplier != ue.m_multiplier) return false;
  if (m_exponent != ue.m_exponent) return false;
  if (m_scale != ue.m_scale) return false;
  return true;
}

bool UnitElement::KindIsCanonical() const
{
#ifdef NSBML
  return true;
#else
  int kind = UnitKind_forName(m_kind.c_str());
  return kind!=UNIT_KIND_INVALID;
#endif
}

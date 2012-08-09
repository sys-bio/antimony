#include "unitelement.h"
#include "stringx.h"
#include <cmath>
#include <cassert>
#include <sbml/UnitKind.h>

using namespace std;

UnitElement::UnitElement(string kind)
  : m_kind(kind)
  , m_exponent(1)
  , m_multiplier(1)
  , m_scale(0)
{
  FixUnitName(m_kind);
}

#ifndef NSBML
UnitElement::UnitElement(const Unit* unit)
  : m_kind(UnitKind_toString(unit->getKind()))
  , m_exponent(unit->getExponent())
  , m_multiplier(unit->getMultiplier())
  , m_scale(unit->getScale())
{
}
#endif

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

void UnitElement::SetKind(string name)
{
  m_kind = name;
  FixUnitName(m_kind);
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
  double ten=10;
  newmult = newmult * m_multiplier * pow(ten, m_scale);
  m_scale = static_cast<long>(floor(log10(newmult)));
  m_multiplier = newmult/pow(ten, m_scale);
}

void UnitElement::Invert()
{
  m_exponent = -m_exponent;
}

string UnitElement::GetKind() const
{
  return m_kind;
}

double UnitElement::GetExponent() const
{
  return m_exponent;
}

double UnitElement::GetMultiplier() const
{
  return m_multiplier;
}

long UnitElement::GetScale() const
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
  return false;
#else
  int kind = UnitKind_forName(m_kind.c_str());
  return (kind!=UNIT_KIND_INVALID && kind!=UNIT_KIND_METER);
#endif
}

string UnitElement::ToString() const
{
  stringstream ret;
  bool needparens = false;
  if (m_scale != 0) {
    ret << m_multiplier << "e" << m_scale << " ";
    needparens = true;
  }
  else if (m_multiplier != 1) {
    ret << m_multiplier << " ";
    needparens = true;
  }
  ret << m_kind;
  if (m_exponent != 1) {
    if (needparens) {
      ret << ")";
    }
    ret << "^" << m_exponent;
    if (needparens) {
      return "(" + ret.str();
    }
  }
  return ret.str();
}

string UnitElement::ToInvString() const
{
  assert(m_exponent<0);
  stringstream ret;
  bool needparens = false;
  if (m_scale != 0) {
    ret << m_multiplier << "e" << m_scale << " ";
    needparens = true;
  }
  else if (m_multiplier != 1) {
    ret << m_multiplier << " ";
    needparens = true;
  }
  ret << m_kind;
  if (m_exponent != -1) {
    if (needparens) {
      ret << ")";
    }
    ret << "^" << -m_exponent;
    if (needparens) {
      return "(" + ret.str();
    }
  }
  return ret.str();
}

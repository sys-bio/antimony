#include "annotated.h"

using namespace std;
#ifndef NSBML
bool Annotated::TransferAnnotationTo(SBase* sbmlobj) const
{
  if (HasAnnotation()) {
    sbmlobj->setMetaId(m_metaid);
    return sbmlobj->setAnnotation(&m_annotation);
  }
  return true;
}

void Annotated::SetAnnotation(const SBase* sbmlobj)
{
  m_metaid = sbmlobj->getMetaId();
  if (sbmlobj->isSetAnnotation()) {
    m_annotation = *(const_cast<SBase*>(sbmlobj)->getAnnotation());
  }
}

void Annotated::ClearAnnotation()
{
  if (!HasAnnotation()) return;
  XMLNode newnode;
  m_annotation = newnode;
  m_metaid = "";
}

bool Annotated::HasAnnotation() const
{
  return m_annotation.getNumChildren()>0;
}

#endif

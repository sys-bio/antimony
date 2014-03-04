#ifndef ANNOTATED_H
#define ANNOTATED_H

#include "sbmlx.h"

class Annotated
{
private:
#ifndef NSBML
  XMLNode m_annotation;
  std::string m_metaid;
#endif

public:
  Annotated() {};
  ~Annotated() {};

#ifndef NSBML
  bool TransferAnnotationTo(SBase* sbmlobj) const;
  void SetAnnotation(const SBase* sbmlobj);
  void ClearAnnotation();
  bool HasAnnotation() const;
#endif

};


#endif //ANNOTATED_H

#include "annotated.h"

using namespace std;
#ifndef NSBML
void Annotated::Synchronize(Annotated * clone)
{
  if (!clone->m_metaid.empty()) {
    m_metaid = clone->m_metaid;
  }
  else {
    clone->m_metaid = m_metaid;
  }
  if (!clone->m_model_quals.empty()) {
    m_model_quals = clone->m_model_quals;
  }
  else {
    clone->m_model_quals = m_model_quals;
  }

  if (!clone->m_biol_quals.empty()) {
    m_biol_quals = clone->m_biol_quals;
  }
  else {
    clone->m_biol_quals = m_biol_quals;
  }

  if (clone->m_sboTerm != 0) {
    m_sboTerm = clone->m_sboTerm;
  }
  else {
    clone->m_sboTerm = m_sboTerm;
  }

}

bool Annotated::TransferAnnotationTo(SBase* sbmlobj, string metaid) const
{
  if (m_sboTerm != 0) {
    sbmlobj->setSBOTerm(m_sboTerm);
  }
  if (!m_metaid.empty() || HasCVTerms()) {
    if (!m_metaid.empty()) {
      sbmlobj->setMetaId(m_metaid);
    }
    else {
      sbmlobj->setMetaId(metaid);
    }
  }
  if (HasCVTerms()) {
    // convert the stored list of CV terms to an annotation node
    BuildCVTerms(sbmlobj);
  }
  return true;
}

void Annotated::ReadAnnotationFrom(const SBase* sbmlobj)
{
  m_metaid = sbmlobj->getMetaId();
  if (sbmlobj->isSetAnnotation()) {
    m_annotation = *(const_cast<SBase*>(sbmlobj)->getAnnotation());
  }
  if (sbmlobj->isSetSBOTerm()) {
    m_sboTerm = sbmlobj->getSBOTerm();
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

ModelQualifierType_t Annotated::DecodeModelQualifier(const string& qual) const
{
  if(qual == "is" || qual == "identity" || qual == "model_entity_is")
    return BQM_IS;
  else if(qual == "isDescribedBy" || qual == "description")
    return BQM_IS_DESCRIBED_BY;
  else if(qual == "isDerivedFrom" || qual == "origin")
    return BQM_IS_DERIVED_FROM;
  else if(qual == "isInstanceOf" || qual == "class")
    return BQM_IS_INSTANCE_OF;
  else if(qual == "hasInstance" || qual == "instance")
    return BQM_HAS_INSTANCE;
  else
    return BQM_UNKNOWN;
}

string Annotated::EncodeModelQualifier(ModelQualifierType_t q) const
{
  switch(q) {
    case BQM_IS:
      return "model_entity_is";
    case BQM_IS_DESCRIBED_BY:
      return "description";
    case BQM_IS_DERIVED_FROM:
      return "origin";
    case BQM_IS_INSTANCE_OF:
      return "class";
    case BQM_HAS_INSTANCE:
      return "instance";
    case BQM_UNKNOWN:
    default:
      return "unknown_model_qual";
  }
}

BiolQualifierType_t Annotated::DecodeBiolQualifier(const string& qual) const
{
  if(qual == "is" || qual == "identity" || qual == "biological_entity_is")
    return BQB_IS;
  else if(qual == "hasPart" || qual == "part")
    return BQB_HAS_PART;
  else if(qual == "isPartOf" || qual == "parthood")
    return BQB_IS_PART_OF;
  else if(qual == "isVersionOf" || qual == "hypernym")
    return BQB_IS_VERSION_OF;
  else if(qual == "hasVersion" || qual == "version")
    return BQB_HAS_VERSION;
  else if(qual == "isHomologTo" || qual == "homolog")
    return BQB_IS_HOMOLOG_TO;
  else if(qual == "isDescribedBy" || qual == "description")
    return BQB_IS_DESCRIBED_BY;
  else if(qual == "isEncodedBy" || qual == "encoder")
    return BQB_IS_ENCODED_BY;
  else if(qual == "encodes" || qual == "encodement")
    return BQB_ENCODES;
  else if(qual == "occursIn" || qual == "container")
    return BQB_OCCURS_IN;
  else if(qual == "hasProperty" || qual == "property")
    return BQB_HAS_PROPERTY;
  else if(qual == "isPropertyOf" || qual == "propertyBearer")
    return BQB_IS_PROPERTY_OF;
  else if(qual == "hasTaxon" || qual == "taxon")
    return BQB_HAS_TAXON;
  else
    return BQB_UNKNOWN;
}

string Annotated::EncodeBiolQualifier(BiolQualifierType_t q) const
{
  switch (q) {
    case BQB_IS:
      return "identity";
    case BQB_HAS_PART:
      return "part";
    case BQB_IS_PART_OF:
      return "parthood";
    case BQB_IS_VERSION_OF:
      return "hypernym";
    case BQB_HAS_VERSION:
      return "version";
    case BQB_IS_HOMOLOG_TO:
      return "homolog";
    case BQB_IS_DESCRIBED_BY:
      return "description";
    case BQB_IS_ENCODED_BY:
      return "encoder";
    case BQB_ENCODES:
      return "encodement";
    case BQB_OCCURS_IN:
      return "container";
    case BQB_HAS_PROPERTY:
      return "property";
    case BQB_IS_PROPERTY_OF:
      return "propertyBearer";
    case BQB_HAS_TAXON:
      return "taxon";
    case BQB_UNKNOWN:
    default:
      return "unknown_biological_qual";
  }
}

void Annotated::AppendModelQualifiers(const ModelQualifierType_t qual, const std::vector<std::string>& resources)
{
  m_model_quals.push_back(std::make_pair(qual,resources));
}

void Annotated::AppendBiolQualifiers(const BiolQualifierType_t qual, const std::vector<std::string>& resources)
{
  m_biol_quals.push_back(std::make_pair(qual,resources));
}

bool Annotated::HasCVTerms() const
{
  return m_model_quals.size() != 0 || m_biol_quals.size() != 0;
}

std::vector<std::string> Annotated::ResourcesToVector(const CVTerm* t) const
{
  std::vector<std::string> result;
  for (unsigned int i=0; i<t->getNumResources(); ++i) {
    result.push_back(t->getResourceURI(i));
  }
  return result;
}

void Annotated::PopulateCVTerms(SBase* sbmlobj)
{
  for (unsigned int i=0; i<sbmlobj->getNumCVTerms(); ++i) {
    const CVTerm* t = sbmlobj->getCVTerm(i);
    switch(t->getQualifierType()) {
      case MODEL_QUALIFIER:
        AppendModelQualifiers(t->getModelQualifierType(), ResourcesToVector(t));
        break;
      case BIOLOGICAL_QUALIFIER:
        AppendBiolQualifiers(t->getBiologicalQualifierType(), ResourcesToVector(t));
        break;
      default:
        break;
    }
  }
}

void Annotated::BuildCVTerms(SBase* sbmlobj) const
{
  // add the model quals then the biol quals as cv terms
  for(ModelQualsType::const_iterator i(m_model_quals.begin()); i!=m_model_quals.end(); ++i)
  {
    if (!i->second.empty())
    {
      CVTerm *cv = new CVTerm();
      cv->setQualifierType(MODEL_QUALIFIER);
      cv->setModelQualifierType(i->first);
      for(std::vector<std::string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j)
      {
        cv->addResource(*j);
      }
      if (sbmlobj->addCVTerm(cv) != LIBSBML_OPERATION_SUCCESS)
        throw std::runtime_error("Could not add CV term to SBML object");
      delete cv;
    }
  }
  for(BiolQualsType::const_iterator i(m_biol_quals.begin()); i!=m_biol_quals.end(); ++i)
  {
    if (!i->second.empty())
    {
      CVTerm *cv = new CVTerm();
      cv->setQualifierType(BIOLOGICAL_QUALIFIER);
      cv->setBiologicalQualifierType(i->first);
      for(std::vector<std::string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j)
      {
        cv->addResource(*j);
      }
      if (sbmlobj->addCVTerm(cv) != LIBSBML_OPERATION_SUCCESS)
        throw std::runtime_error("Could not add CV term to SBML object");
      delete cv;
    }
  }
}

string Annotated::CreateCVTermsAntimonySyntax(const string& elt_id, const string& indent) const
{
  string result;
  for(ModelQualsType::const_iterator i(m_model_quals.begin()); i!=m_model_quals.end(); ++i) {
    string term = indent+elt_id+" "+EncodeModelQualifier(i->first)+" ";
    string subindent = indent;
    while(subindent.size() < term.size())
      subindent += " ";
    for(vector<string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j) {
      // align each subsequent uri with the first one
      if (j!=i->second.begin())
        term += ",\n"+subindent;
      term += "\""+*j+"\"";
    }
    result += term+"\n";
  }
  for(BiolQualsType::const_iterator i(m_biol_quals.begin()); i!=m_biol_quals.end(); ++i) {
    string term = indent+elt_id+" "+EncodeBiolQualifier(i->first)+" ";
    string subindent = indent;
    while(subindent.size() < term.size())
      subindent += " ";
    for(vector<string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j) {
      // align each subsequent uri with the first one
      if (j!=i->second.begin())
        term += ",\n"+subindent;
      term += "\""+*j+"\"";
    }
    result += term+"\n";
  }
  return result;
}

void Annotated::SetSBOTerm(int sboTerm)
{
  m_sboTerm = sboTerm;
}

int Annotated::GetSBOTerm() const
{
  return m_sboTerm;
}

string Annotated::CreateSBOTermsAntimonySyntax(const string& elt_id, const string& indent, string sboStr) const
{
  if (GetSBOTerm()) {
    stringstream ss;
    ss << GetSBOTerm();
    return indent + elt_id + "." + sboStr + " = " + ss.str() + "\n";
  } 
  else {
    return "";
  }
}

#endif

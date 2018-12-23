#include "annotated.h"

using namespace std;
#ifndef NSBML
bool Annotated::TransferAnnotationTo(SBase* sbmlobj) const
{
  /*
  if (HasAnnotation()) {
    sbmlobj->setMetaId(m_metaid);
    return sbmlobj->setAnnotation(&m_annotation);
  }
  */
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

ModelQualifierType_t Annotated::DecodeModelQualifier(const string& qual)
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

bool Annotated::ModelQualifierURIMatches(const string& uri, const string& qual1, const string& qual2)
{
  string base_uri_http  = "http://biomodels.net/model-qualifiers/";
  string base_uri_https = "https://biomodels.net/model-qualifiers/";
  return uri == base_uri_http +qual1 || uri == base_uri_http +qual2 ||
         uri == base_uri_https+qual1 || uri == base_uri_https+qual2;
}

ModelQualifierType_t Annotated::DecodeModelQualifierURI(const string& uri)
{
  if(ModelQualifierURIMatches(uri, "is", "identity"))
    return BQM_IS;
  else if(ModelQualifierURIMatches(uri, "isDescribedBy", "description"))
    return BQM_IS_DESCRIBED_BY;
  else if(ModelQualifierURIMatches(uri, "isDerivedFrom", "origin"))
    return BQM_IS_DERIVED_FROM;
  else if(ModelQualifierURIMatches(uri, "isInstanceOf", "class"))
    return BQM_IS_INSTANCE_OF;
  else if(ModelQualifierURIMatches(uri, "hasInstance", "instance"))
    return BQM_HAS_INSTANCE;
  else
    return BQM_UNKNOWN;
}

bool Annotated::BiologyQualifierURIMatches(const string& uri, const string& qual1, const string& qual2)
{
  string base_uri_http  = "http://biomodels.net/biology-qualifiers/";
  string base_uri_https = "https://biomodels.net/biology-qualifiers/";
  return uri == base_uri_http +qual1 || uri == base_uri_http +qual2 ||
         uri == base_uri_https+qual1 || uri == base_uri_https+qual2;
}

BiolQualifierType_t Annotated::DecodeBiologyQualifierURI(const string& uri)
{
  if(BiologyQualifierURIMatches(uri, "is", "identity"))
    return BQB_IS;
  else if(BiologyQualifierURIMatches(uri, "hasPart", "part"))
    return BQB_HAS_PART;
  else if(BiologyQualifierURIMatches(uri, "isPartOf", "parthood"))
    return BQB_IS_PART_OF;
  else if(BiologyQualifierURIMatches(uri, "isVersionOf", "hypernym"))
    return BQB_IS_VERSION_OF;
  else if(BiologyQualifierURIMatches(uri, "hasVersion", "version"))
    return BQB_HAS_VERSION;
  else if(BiologyQualifierURIMatches(uri, "isHomologTo", "homolog"))
    return BQB_IS_HOMOLOG_TO;
  else if(BiologyQualifierURIMatches(uri, "isDescribedBy", "description"))
    return BQB_IS_DESCRIBED_BY;
  else if(BiologyQualifierURIMatches(uri, "isEncodedBy", "encoder"))
    return BQB_IS_ENCODED_BY;
  else if(BiologyQualifierURIMatches(uri, "encodes", "encodement"))
    return BQB_ENCODES;
  else if(BiologyQualifierURIMatches(uri, "occursIn", "container"))
    return BQB_OCCURS_IN;
  else if(BiologyQualifierURIMatches(uri, "hasProperty", "property"))
    return BQB_HAS_PROPERTY;
  else if(BiologyQualifierURIMatches(uri, "isPropertyOf", "propertyBearer"))
    return BQB_IS_PROPERTY_OF;
  else if(BiologyQualifierURIMatches(uri, "hasTaxon", "taxon"))
    return BQB_HAS_TAXON;
  else
    return BQB_UNKNOWN;
}

string Annotated::EncodeModelQualifier(ModelQualifierType_t q)
{
  switch(q) {
    case BQM_IS:
      return "is";
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

BiolQualifierType_t Annotated::DecodeBiolQualifier(const string& qual)
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

string Annotated::EncodeBiolQualifier(BiolQualifierType_t q)
{
  switch (q) {
    case BQB_IS:
      return "is";
    case BQB_HAS_PART:
      return "part";
    case BQB_IS_PART_OF:
      return "parthood";
    case BQB_IS_VERSION_OF:
      return "isVersionOf";
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
      return "isPropertyOf";
    case BQB_HAS_TAXON:
      return "taxon";
    case BQB_UNKNOWN:
    default:
      return "unknown_biological_qual";
  }
}

bool Annotated::isBiomodelsQual(const std::string& s)
{
  if (DecodeModelQualifier(s) == BQM_UNKNOWN && DecodeBiolQualifier(s) == BQB_UNKNOWN)
    return false;
  else
    return true;
}

void Annotated::AppendModelQualifiers(const ModelQualifierType_t qual, const std::vector<std::string>& resources)
{
  m_model_quals[qual].insert(m_model_quals[qual].end(),resources.begin(),resources.end());
}

void Annotated::AppendBiolQualifiers(const BiolQualifierType_t qual, const std::vector<std::string>& resources)
{
  m_biol_quals[qual].insert(m_biol_quals[qual].end(),resources.begin(),resources.end());
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

string Annotated::CreateSBOTermsAntimonySyntax(const string& elt_id, const string& indent) const
{
  if (GetSBOTerm()) {
    stringstream ss;
    ss << GetSBOTerm();
    return indent+elt_id+"."+"sboTerm = "+ss.str()+"\n";
  } else {
    return "";
  }
}

#endif

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

// keep a list of biomodels quals so we can extend it as we read the input
// use the list to build an annotation node when writing
typedef std::map< ModelQualifierType_t, std::vector<std::string> > ModelQualsType;
ModelQualsType m_model_quals;
typedef std::map< BiolQualifierType_t,  std::vector<std::string> > BiolQualsType;
BiolQualsType m_biol_quals;

// convert the URIs in resources to a vector of strings
std::vector<std::string> ResourcesToVector(const CVTerm* t) const;

int m_sboTerm;

static bool ModelQualifierURIMatches  (const std::string& uri, const std::string& qual1, const std::string& qual2);
static bool BiologyQualifierURIMatches(const std::string& uri, const std::string& qual1, const std::string& qual2);

public:
  Annotated() : m_sboTerm(0) {};
  ~Annotated() {};

#ifndef NSBML
  bool TransferAnnotationTo(SBase* sbmlobj) const;
  void SetAnnotation(const SBase* sbmlobj);
  void ClearAnnotation();
  bool HasAnnotation() const;

  // * CV terms *
  // converts a string into ModelQualifierType_t
  static ModelQualifierType_t DecodeModelQualifier(const std::string& qual);
  // vice-versa
  static std::string EncodeModelQualifier(ModelQualifierType_t q);
  // converts a string into BiolQualifierType_t
  static BiolQualifierType_t  DecodeBiolQualifier(const std::string& qual);
  static ModelQualifierType_t DecodeModelQualifierURI(const std::string& uri);
  static BiolQualifierType_t DecodeBiologyQualifierURI(const std::string& uri);
  // vice-versa
  static std::string EncodeBiolQualifier(BiolQualifierType_t q);
  // returns true if the string corresponds to a biomodels qualifier
  static bool isBiomodelsQual(const std::string& s);
  // appends a model qualifier to the end of the cv list
  void AppendModelQualifiers(const ModelQualifierType_t qual, const std::vector<std::string>& resources);
  // appends a biological qualifier to the end of the cv list
  void AppendBiolQualifiers(const BiolQualifierType_t qual, const std::vector<std::string>& resources);
  // return true if there are CV terms stored
  bool HasCVTerms() const;
  // read the CV terms from an SBML object and add them to this
  void PopulateCVTerms(SBase* sbmlobj);
  // build an annotation node from the list of BioModels qualifiers in m_bq_annotations
  // adds CV terms to SBML object
  void BuildCVTerms(SBase* sbmlobj) const;
  // writes out the Antimony syntax for the CV terms stored in this object
  std::string CreateCVTermsAntimonySyntax(const std::string& elt_id, const std::string& indent) const;

  // * SBO terms *
  void SetSBOTerm(int sboTerm);
  int GetSBOTerm() const;
  std::string CreateSBOTermsAntimonySyntax(const std::string& elt_id, const std::string& indent) const;
#endif

};


#endif //ANNOTATED_H

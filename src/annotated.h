#ifndef ANNOTATED_H
#define ANNOTATED_H

#include "sbmlx.h"

class Annotated
{
protected:
#ifndef NSBML
    libsbml::XMLNode m_annotation;
  std::string m_metaid;
#endif

// keep a list of biomodels quals so we can extend it as we read the input
// use the list to build an annotation node when writing
typedef std::vector< std::pair<libsbml::ModelQualifierType_t, std::vector<std::string> > > ModelQualsType;
ModelQualsType m_model_quals;
typedef std::vector< std::pair<libsbml::BiolQualifierType_t,  std::vector<std::string> > > BiolQualsType;
BiolQualsType m_biol_quals;
std::vector < std::string> m_notes;
libsbml::Date m_created;
std::vector<libsbml::Date> m_modified;
libsbml::ModelHistory m_history;
int m_sboTerm;

// convert the URIs in resources to a vector of strings
std::vector<std::string> ResourcesToVector(const libsbml::CVTerm* t) const;

public:
  Annotated();
  ~Annotated() {};

  virtual bool Synchronize(Variable * clone, const Variable * conversionFactor);

#ifndef NSBML
  virtual bool TransferAnnotationTo(libsbml::SBase* sbmlobj, std::string metaid) const;
  std::string getNotesString() const;
  bool hasNotes() const;
  bool isSetCreated() const;
  std::string getCreatedString() const;
  bool isSetModifiedTimes() const;
  std::string getModifiedString(std::string indent) const;

  void ReadAnnotationFrom(const libsbml::SBase* sbmlobj);
  void ClearAnnotation();
  bool HasAnnotation() const;

  // * CV terms *
  // converts a string into ModelQualifierType_t
  libsbml::ModelQualifierType_t DecodeModelQualifier(const std::string& qual) const;
  // vice-versa
  std::string EncodeModelQualifier(libsbml::ModelQualifierType_t q) const;
  // converts a string into BiolQualifierType_t
  libsbml::BiolQualifierType_t  DecodeBiolQualifier(const std::string& qual) const;
  // vice-versa
  std::string EncodeBiolQualifier(libsbml::BiolQualifierType_t q) const;
  // appends a model qualifier to the end of the cv list
  void AppendModelQualifiers(const libsbml::ModelQualifierType_t qual, const std::vector<std::string>& resources);
  // appends a biological qualifier to the end of the cv list
  void AppendBiolQualifiers(const libsbml::BiolQualifierType_t qual, const std::vector<std::string>& resources);
  // appends notes (just strings)
  void AppendNotes(const std::vector<std::string>& resources);
  void SetCreated(libsbml::Date* date);
  bool SetCreated(const std::string& date);
  void AppendModified(std::vector<std::string>* dates);
  void AppendModified(libsbml::Date* date);
  bool AppendModified(std::string* datestr);
  void ClearModified(libsbml::Date* date);
  // return true if there are CV terms stored
  bool HasCVTerms() const;
  // read the CV terms from an SBML object and add them to this
  void PopulateCVTerms(libsbml::SBase* sbmlobj);
  // build an annotation node from the list of BioModels qualifiers in m_bq_annotations
  // adds CV terms to SBML object
  bool BuildCVTerms(libsbml::SBase* sbmlobj) const;
  // writes out the Antimony syntax for the CV terms stored in this object
  std::string CreateCVTermsAntimonySyntax(const std::string& elt_id, const std::string& indent) const;

  // * SBO terms *
  virtual void SetSBOTerm(int sboTerm);
  int GetSBOTerm() const;
  virtual std::string CreateSBOTermsAntimonySyntax(const std::string& elt_id, const std::string& indent, std::string ) const;
#endif

};


#endif //ANNOTATED_H

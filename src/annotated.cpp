#include "annotated.h"
#include "registry.h"
#include "stringx.h"
#include "sbml/annotation/Date.h"
#include <string>
#include <regex>

using namespace std;
using namespace libsbml;

Annotated::Annotated()
    : m_annotation()
    , m_metaid("")
    , m_model_quals()
    , m_biol_quals()
    , m_notes()
    , m_created()
    , m_modified()
    , m_history()
    , m_sboTerm(0)
{
    m_created.setYear(1000);
}

bool Annotated::TransferAnnotationToModel(Model* model)
{
    if (model == NULL) {
        return true;
    }
    return TransferAnnotationTo(model, model->getMetaId());
}

bool Annotated::TransferAnnotationTo(SBase* sbmlobj, string metaid) const
{
  if (m_sboTerm != 0) {
    sbmlobj->setSBOTerm(m_sboTerm);
  }
  if (!m_metaid.empty()) {
      metaid = m_metaid;
      sbmlobj->setMetaId(m_metaid);
  }
  if (HasCVTerms()) {
    sbmlobj->setMetaId(metaid);
    // convert the stored list of CV terms to an annotation node
    if (BuildCVTerms(sbmlobj)) {
      return true;
    }
  }
  if (!m_notes.empty()) {
      sbmlobj->setMetaId(metaid);
      string notes = getNotesString();
      if (notes[0] == '<') {
          int ret = sbmlobj->setNotes(notes, false);
          if (ret != libsbml::LIBSBML_OPERATION_SUCCESS) {
              ret = sbmlobj->setNotes(notes, true);
          }
          if (ret != libsbml::LIBSBML_OPERATION_SUCCESS) {
              ret = sbmlobj->setNotes("<notes><body xmlns=\"http://www.w3.org/1999/xhtml\"> " + notes + " </body></notes>");
          }
          if (ret != libsbml::LIBSBML_OPERATION_SUCCESS) {
              ret = sbmlobj->setNotes("<notes><p xmlns=\"http://www.w3.org/1999/xhtml\"> " + notes + " </p></notes>");
              assert(ret == libsbml::LIBSBML_OPERATION_SUCCESS);
          }
          if (ret != libsbml::LIBSBML_OPERATION_SUCCESS) {
              ret = sbmlobj->setNotesFromMarkdown(notes);
              assert(ret == libsbml::LIBSBML_OPERATION_SUCCESS);
          }
      }
      else {
          regex triple_quotes("\"\"\"");
          notes = regex_replace(notes, triple_quotes, "```");
          sbmlobj->setNotesFromMarkdown(notes);
      }
  }
  ModelHistory* mh = const_cast<ModelHistory*>(&m_history);
  if (mh->getNumCreators() > 0) {
      sbmlobj->setMetaId(metaid);
      sbmlobj->setModelHistory(mh);
  }
  if (const_cast<Date*>(&m_created)->getYear() != 1000) {
      sbmlobj->setMetaId(metaid);
      sbmlobj->setCreatedDate(const_cast<Date*>(&m_created));
  }
  sbmlobj->unsetModifiedDates();
  for (size_t i = 0; i < m_modified.size(); i++) {
      sbmlobj->setMetaId(metaid);
      sbmlobj->addModifiedDate(const_cast<Date*>(&m_modified[i]));
  }
  return false;
}

string Annotated::getNotesString() const
{
    string notes = "";
    for (size_t n = 0; n < m_notes.size(); n++) {
        if (n > 0) {
            notes += "\n";
        }
        notes += m_notes[n];
    }
    trimAndRemoveDoubleSpaces(notes);
    return notes;
}

string Annotated::GetCreatorStringFor(const string& id) const
{
    string ret = "";
    ModelHistory* mh = const_cast<ModelHistory*>(&m_history);
    for (unsigned int v = 0; v < mh->getNumCreators(); v++) {
        string left = id + " creator" + to_string(v+1) + ".";
        ModelCreator* mc = mh->getCreator(v);
        if (mc->isSetName()) {
            ret += left + "name " + quoteText(mc->getName()) + "\n";
        }
        if (mc->isSetGivenName()) {
            ret += left + "givenName " + quoteText(mc->getGivenName()) + "\n";
        }
        if (mc->isSetFamilyName()) {
            ret += left + "familyName " + quoteText(mc->getFamilyName()) + "\n";
        }
        if (mc->isSetOrganisation()) {
            ret += left + "organization " + quoteText(mc->getOrganisation()) + "\n";
        }
        if (mc->isSetEmail()) {
            ret += left + "email " + quoteText(mc->getEmail()) + "\n";
        }
    }
    return ret;
}

bool Annotated::hasNotes() const
{
    return !m_notes.empty();
}

bool Annotated::isSetCreated() const
{
    return const_cast<Date*>(&m_created)->getYear() != 1000;
}

std::string Annotated::getCreatedString() const
{
    return const_cast<Date*>(&m_created)->getDateAsString();
}

bool Annotated::isSetModifiedTimes() const
{
    return m_modified.size() > 0;
}

string Annotated::getModifiedString(string indent) const
{
    string ret = "";
    for (size_t i = 0; i < m_modified.size(); i++) {
        if (!ret.empty()) {
            ret += ",\n" + indent;
        }
        ret += quoteText(const_cast<Date*>(&m_modified[i])->getDateAsString());
    }
    return ret + "\n";
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
  if (sbmlobj->isSetNotes()) {
      string notes = sbmlobj->getNotesMarkdown();
      trimAndRemoveDoubleSpaces(notes);
      m_notes.push_back(notes);
  }
  if (sbmlobj->isSetModelHistory()) {
      m_history = *sbmlobj->getModelHistory();
      m_history.unsetParentSBMLObject();
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
  if (qual == "is" || qual == "identity" || qual == "model_entity_is" || qual=="model_source")
    return BQM_IS;
  else if(qual == "isDescribedBy" || qual == "description" || qual == "publication")
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
      return "model_source";
    case BQM_IS_DESCRIBED_BY:
      return "publication";
    case BQM_IS_DERIVED_FROM:
      return "origin";
    case BQM_IS_INSTANCE_OF:
      return "isInstanceOf";
    case BQM_HAS_INSTANCE:
      return "hasInstance";
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
  else if(qual == "isVersionOf" || qual == "hypernym" || qual == "biological_system")
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
      return "hasPart";
    case BQB_IS_PART_OF:
      return "isPartOf";
    case BQB_IS_VERSION_OF:
      return "isVersionOf";
    case BQB_HAS_VERSION:
      return "hasVersion";
    case BQB_IS_HOMOLOG_TO:
      return "isHomologTo";
    case BQB_IS_DESCRIBED_BY:
      return "isDescribedBy";
    case BQB_IS_ENCODED_BY:
      return "isEncodedBy";
    case BQB_ENCODES:
      return "encodes";
    case BQB_OCCURS_IN:
      return "occursIn";
    case BQB_HAS_PROPERTY:
      return "hasProperty";
    case BQB_IS_PROPERTY_OF:
      return "isPropertyOf";
    case BQB_HAS_TAXON:
      return "hasTaxon";
    case BQB_UNKNOWN:
    default:
      return "unknown_biological_qual";
  }
}

void Annotated::AppendModelQualifiers(const ModelQualifierType_t qual, const std::vector<std::string>& resources)
{
  vector<string> addme;
  for (size_t r = 0; r < resources.size(); r++) {
    if (!resources[r].empty()) {
      addme.push_back(resources[r]);
    }
  }
  if (addme.empty()) {
    return;
  }
  m_model_quals.push_back(std::make_pair(qual,addme));
}

void Annotated::AppendNotes(const std::vector<std::string>& resources)
{
    for (size_t r = 0; r < resources.size(); r++) {
        if (!resources[r].empty()) {
            m_notes.push_back(resources[r]);
        }
    }
}

bool Annotated::addCreatorInfo(unsigned int creator_number, const string& creator_substr, const vector<string>& resources)
{
    ModelCreator* creator = NULL;
    if (creator_number <= m_history.getNumCreators()) {
        creator = m_history.getCreator(creator_number - 1);
    }
    else if (creator_number == m_history.getNumCreators() + 1) {
        ModelCreator newcreator;
        newcreator.setName(" ");
        m_history.addCreator(&newcreator);
        creator = m_history.getCreator(creator_number - 1);
    }
    else {
        g_registry.SetError("Unable to set 'creator" + to_string(creator_number) + "." + creator_substr + "' because no creator" + to_string(creator_number-1) + " exists.");
        return true;
    }
    if (CaselessStrCmp(true, creator_substr, "name")) {
        if (resources.size() > 1) {
            g_registry.SetError("Unable to set multiple names for creator" + to_string(creator_number));
            return true;
        }
        creator->setName(resources[0]);
    }
    else if (CaselessStrCmp(true, creator_substr, "givenName")) {
        if (resources.size() > 1) {
            g_registry.SetError("Unable to set multiple given names for creator" + to_string(creator_number));
            return true;
        }
        creator->setGivenName(resources[0]);
        // setUseSingleName(false) suppresses the placeholder name (" ") set
        // when a creator is first created (see newcreator.setName(" ")
        // above), so that a creator with only a given/family name doesn't
        // get a spurious blank "creator.name" line on write-out. But if the
        // user has *also* explicitly set a real name via "creator.name",
        // don't clobber that -- isSetName() would otherwise start
        // (incorrectly) reporting false, silently dropping the name on
        // serialization even though it's still stored.
        if (!creator->isSetName() || creator->getName() == " ") {
            creator->setUseSingleName(false);
        }
    }
    else if (CaselessStrCmp(true, creator_substr, "familyName")) {
        if (resources.size() > 1) {
            g_registry.SetError("Unable to set multiple family names for creator" + to_string(creator_number));
            return true;
        }
        creator->setFamilyName(resources[0]);
        if (!creator->isSetName() || creator->getName() == " ") {
            creator->setUseSingleName(false);
        }
    }
    else if (CaselessStrCmp(true, creator_substr, "organization") || 
        CaselessStrCmp(true, creator_substr, "organisation") ||
        CaselessStrCmp(true, creator_substr, "org")) {
        if (resources.size() > 1) {
            g_registry.SetError("Unable to set multiple organizations for creator" + to_string(creator_number));
            return true;
        }
        creator->setOrganisation(resources[0]);
    }
    else if (CaselessStrCmp(true, creator_substr, "email")) {
        if (resources.size() > 1) {
            g_registry.SetError("Unable to set multiple emails for creator" + to_string(creator_number));
            return true;
        }
        creator->setEmail(resources[0]);
    }
    else {
        g_registry.SetError("Unrecognized creator attribute '" + creator_substr + "'.  Valid options are creator.name, creator.givenName, creator.familyName, creator.organization, and creator.email.");
        return true;
    }
    return false;
}

void Annotated::SetCreated(Date* date)
{
    m_created = *date;
}

bool Annotated::SetCreated(const string& date)
{
    return (m_created.setDateAsString(date) != libsbml::LIBSBML_OPERATION_SUCCESS);
}

bool Annotated::SetCreated(const string& qual, const string& date)
{
    return SetDate(qual, date, m_created);
}

bool Annotated::ResetLastModified(const string& qual, const string& date)
{
    if (m_modified.size() == 0) {
        libsbml::Date newDate;
        m_modified.push_back(newDate);
    }
    return SetDate(qual, date, m_modified[m_modified.size() - 1]);
}

bool Annotated::SetDate(const string& qual, const string& date, libsbml::Date& stored)
{
    if (qual == "year") {
        return stored.setYear(stoi(date));
    }
    else if (qual == "month") {
        return stored.setMonth(stoi(date));
    }
    else if (qual == "day") {
        return stored.setDay(stoi(date));
    }
    else if (qual == "hour") {
        return stored.setHour(stoi(date));
    }
    else if (qual == "minute") {
        return stored.setMinute(stoi(date));
    }
    else if (qual == "second") {
        return stored.setSecond(stoi(date));
    }
    else if (qual == "time") {
        stringstream datestream(date);
        string subs;
        getline(datestream, subs, ':');
        stored.setHour(stoi(subs));
        getline(datestream, subs, ':');
        stored.setMinute(stoi(subs));
        if (datestream) {
            getline(datestream, subs, ':');
            stored.setSecond(stoi(subs));
        }
        return false;
    }
    g_registry.SetError("Unknown date element '" + qual + "'.  Allowed elements are 'year', 'month', 'day', 'hour', 'minute', 'second', or 'time'.");
    return true;
}

void Annotated::AppendModified(vector<string>* dates)
{
    for (size_t d = 0; d < dates->size(); d++) {
        m_modified.push_back((*dates)[d]);
    }
}

void Annotated::AppendModified(Date* date)
{
    m_modified.push_back(*date);
}

bool Annotated::AppendModified(string* datestr)
{
    libsbml::Date date;
    int ret = date.setDateAsString(*datestr);
    if (ret == libsbml::LIBSBML_OPERATION_SUCCESS) {
        m_modified.push_back(date);
        return false;
    }
    else {
        g_registry.SetError("Invalid date format '" + *datestr + "': the format must match 'YYYY-MM-DDThh:mm:ssTZD' where TZD is either Z or +/ -HH:MM");
        return true;
    }
}

void Annotated::ClearModified(Date* date)
{
    m_modified.clear();
}

void Annotated::AppendBiolQualifiers(const BiolQualifierType_t qual, const std::vector<std::string>& resources)
{
  vector<string> addme;
  for (size_t r = 0; r < resources.size(); r++) {
    if (!resources[r].empty()) {
      addme.push_back(resources[r]);
    }
  }
  if (addme.empty()) {
    return;
  }
  m_biol_quals.push_back(std::make_pair(qual,addme));
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
  if (sbmlobj->isSetCreatedDate()) {
      SetCreated(sbmlobj->getCreatedDate());
  }
  for (unsigned int i = 0; i < sbmlobj->getNumModifiedDates(); i++) {
      AppendModified(sbmlobj->getModifiedDate(i));
  }
  if (sbmlobj->isSetModelHistory()) {
      m_history = *sbmlobj->getModelHistory();
  }
  libsbml::XMLNode* annotation = sbmlobj->getAnnotation();
  //annotation->get
}

bool Annotated::BuildCVTerms(SBase* sbmlobj) const
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
      if (sbmlobj->addCVTerm(cv) != LIBSBML_OPERATION_SUCCESS) {
        g_registry.SetError("Could not add CV term to SBML object");
        delete cv;
        return true;
      }
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
      if (sbmlobj->addCVTerm(cv) != LIBSBML_OPERATION_SUCCESS) {
        g_registry.SetError("Could not add CV term to SBML object");
        delete cv;
        return true;
      }
      delete cv;
    }
  }
  return false;
}

string Annotated::CreateCVTermsAntimonySyntax(const string& elt_id, const string& indent) const
{
  string result;
  for(ModelQualsType::const_iterator i(m_model_quals.begin()); i!=m_model_quals.end(); ++i) {
    string term = indent + elt_id + " " + EncodeModelQualifier(i->first) + " ";
    string subindent = indent;
    if (i->first == BQM_UNKNOWN) {
        subindent = "//" + subindent;
        term = "//" + term;
    }
    while(subindent.size() < term.size())
      subindent += " ";
    for(vector<string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j) {
      // align each subsequent uri with the first one
      if (j!=i->second.begin())
        term += ",\n"+subindent;
      term += quoteText(*j);
    }
    result += term+"\n";
  }
  for(BiolQualsType::const_iterator i(m_biol_quals.begin()); i!=m_biol_quals.end(); ++i) {
    string term = indent + elt_id + " " + EncodeBiolQualifier(i->first) + " ";
    string subindent = indent;
    if (i->first == BQB_UNKNOWN) {
        subindent = "//" + subindent;
        term = "//" + term;
    }
    while(subindent.size() < term.size())
      subindent += " ";
    for(vector<string>::const_iterator j(i->second.begin()); j!=i->second.end(); ++j) {
      // align each subsequent uri with the first one
      if (j!=i->second.begin())
        term += ",\n"+subindent;
      term += quoteText(*j);
    }
    result += term+"\n";
  }
  return result;
}

bool Annotated::Synchronize(Variable * clone, const Variable * conversionFactor)
{
  if (m_sboTerm != 0) {
    if (clone->m_sboTerm == 0) {
      clone->m_sboTerm = m_sboTerm;
    }
  }

  if (!m_metaid.empty()) {
    if (clone->m_metaid.empty()) {
      clone->m_metaid = m_metaid;
    }
  }

  if (!m_notes.empty()) {
      if (clone->m_notes.empty()) {
          clone->m_notes = m_notes;
      }
  }

  if (!(m_history.getNumCreators() > 0)) {
      if (clone->m_history.getNumCreators() == 0) {
          clone->m_history = m_history;
      }
  }

  for (vector<pair<ModelQualifierType_t, vector<string> > >::iterator mq = m_model_quals.begin(); mq != m_model_quals.end(); mq++) {
    ModelQualifierType_t mqtype = mq->first;
    bool no_match = true;
    for (vector<pair<ModelQualifierType_t, vector<string> > >::iterator cmq = clone->m_model_quals.begin(); cmq != clone->m_model_quals.end(); cmq++) {
      if (cmq->first == mqtype) {
        no_match = false;
        break;
      }
    }
    if (no_match) {
      clone->m_model_quals.push_back(*mq);
    }
  }
  m_model_quals.clear();
  for (vector<pair<BiolQualifierType_t, vector<string> > >::iterator bq = m_biol_quals.begin(); bq != m_biol_quals.end(); bq++) {
    BiolQualifierType_t bqtype = bq->first;
    bool no_match = true;
    for (vector<pair<BiolQualifierType_t, vector<string> > >::iterator cbq = clone->m_biol_quals.begin(); cbq != clone->m_biol_quals.end(); cbq++) {
      if (cbq->first == bqtype) {
        no_match = false;
        break;
      }
    }
    if (no_match) {
      clone->m_biol_quals.push_back(*bq);
    }
  }
  m_biol_quals.clear();
  return false;
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

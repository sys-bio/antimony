#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>
#include <set>

#include "formula.h"
#include "enums.h"

//Note:  'AntimonyEvent' instead of just 'Event' because libSBML defines a 'Event' class.
class AntimonyEvent
{
private:
  Formula m_trigger;
  Formula m_delay;
  Formula m_priority;
  bool m_useValuesFromTriggerTime;
  bool m_persistent;
  bool m_initialValue;
  std::vector<std::vector<std::string> > m_varresults;
  std::vector<Formula> m_formresults;
  std::vector<std::string> m_name;
  std::string m_module;

public:
  AntimonyEvent(const Formula& delay, const Formula& trigger, Variable* var);
  AntimonyEvent(); //A blank one we don't plan to use.
  ~AntimonyEvent() {};

  bool SetTrigger(const Formula& form);
  bool AddResult(Variable* var, Formula* form);
  void SetNewTopName(std::string modname, std::string newtopname);
  bool SetPriority(const Formula& priority);
  bool SetUseValuesFromTriggerTime(const Formula& priority);
  bool SetPersistent(const Formula& priority);
  bool SetInitialValue(const Formula& priority);
  void SetUseValuesFromTriggerTime(bool fromTrigger) {m_useValuesFromTriggerTime = fromTrigger;};
  void SetPersistent(bool persistent) {m_persistent = persistent;}
  void SetInitialValue(bool initialValue) {m_initialValue = initialValue;}

  const Formula* GetTrigger() const {return &m_trigger;};
  Formula* GetTrigger() {return &m_trigger;};
  const Formula* GetDelay() const {return &m_delay;};
  Formula* GetDelay() {return &m_delay;};
  const Formula* GetPriority() const {return &m_priority;};
  Formula* GetPriority() {return &m_priority;};
  bool GetUseValuesFromTriggerTime() const {return m_useValuesFromTriggerTime;};
  bool GetPersistent() const {return m_persistent;};
  bool GetInitialValue() const {return m_initialValue;};
  bool IsEmpty() const;

  bool Matches(const AntimonyEvent* newevent) const;
  void Convert(Variable* converted, Variable* cf);
  void ConvertTime(Variable* tcf);
  bool ClearReferencesTo(Variable* deletedvar, std::set<std::pair<std::vector<std::string>, deletion_type> >* ret);

  size_t GetNumAssignments() const {return m_varresults.size();};
  std::string GetNthAssignmentVariableName(size_t n, std::string cc) const;
  std::string GetNthAssignmentFormulaString(size_t n, std::string cc, bool SBML) const;
  const Formula* GetAssignmentFormula(size_t n) const;
  std::string ToStringDelimitedBy(std::string cc) const;
  void FixNames();
};


#endif //EVENT_H

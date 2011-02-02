#ifndef EVENT_H
#define EVENT_H

#include <string>
#include <vector>

#include "formula.h"

//Note:  'AntimonyEvent' instead of just 'Event' because libSBML defines a 'Event' class.
class AntimonyEvent
{
private:
  Formula m_trigger;
  Formula m_delay;
  Formula m_priority;
  std::vector<std::vector<std::string> > m_varresults;
  std::vector<Formula> m_formresults;
  std::vector<std::string> m_name;
  std::string m_module;

public:
  AntimonyEvent(const Formula& delay, const Formula& trigger, Variable* var, const Formula& priority);
  AntimonyEvent(); //A blank one we don't plan to use.
  ~AntimonyEvent() {};

  bool SetTrigger(const Formula& form);
  bool AddResult(Variable* var, Formula* form);
  void SetNewTopName(std::string modname, std::string newtopname);

  const Formula* GetTrigger() const {return &m_trigger;};
  Formula* GetTrigger() {return &m_trigger;};
  const Formula* GetDelay() const {return &m_delay;};
  Formula* GetDelay() {return &m_delay;};
  const Formula* GetPriority() const {return &m_priority;};
  Formula* GetPriority() {return &m_priority;};
  bool IsEmpty() const;

  size_t GetNumAssignments() const {return m_varresults.size();};
  std::string GetNthAssignmentVariableName(size_t n, char cc) const;
  std::string GetNthAssignmentFormulaString(size_t n, char cc, bool SBML) const;
  std::string ToStringDelimitedBy(char cc) const;
  void FixNames();
};


#endif //EVENT_H

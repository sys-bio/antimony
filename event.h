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
  std::vector<std::vector<std::string> > m_varresults;
  std::vector<Formula> m_formresults;
  std::vector<std::string> m_name;
  std::string m_module;

public:
  AntimonyEvent(const Formula& trigger, Variable* var);
  AntimonyEvent(); //A blank one we don't plan to use.
  ~AntimonyEvent() {};

  void SetTrigger(const Formula& form);
  bool AddResult(Variable* var, Formula* form);
  void SetNewTopName(std::string modname, std::string newtopname);

  const Formula* GetTrigger() const {return &m_trigger;};
  Formula* GetTrigger() {return &m_trigger;};
  //const std::vector<Formula>* GetResults() const {return &m_results;};
  //bool IsEmpty() const;

  std::string ToStringDelimitedBy(char cc) const;
};


#endif //EVENT_H

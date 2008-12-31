#ifndef DNASTRAND_H
#define DNASTRAND_H

#include <string>
#include <utility>
#include <vector>

class Variable;
class Formula;

class DNAStrand
{
private:
  //DNAStrand(const DNAStrand& src); //Undefined
  //DNAStrand& operator=(const DNAStrand& src); //Undefined

  std::vector<std::vector<std::string> > m_strand;
  bool m_upstreamopen;
  bool m_downstreamopen;
  std::string m_module;

public:
  DNAStrand() {};
  ~DNAStrand() {};

  bool SetDownstream(Variable* var);
  bool SetUpstream(Variable* var);
  void SetDownstream(bool open);
  void SetUpstream(bool open);
  void SetComponentCompartments(Variable* compartment);
  void Clear();

  bool IsEmpty() const;
  Formula* GetFinalFormula() const;
  std::vector<Variable*> GetVariables() const;
  std::vector<size_t> GetOccurrencesOf(std::vector<std::string> var) const;
  size_t GetStrandLength() const {return m_strand.size();};
  bool GetUpstreamOpen() const {return m_upstreamopen;};
  bool GetDownstreamOpen() const {return m_downstreamopen;};
  bool CheckContains(Variable* var) const;

  void SetNewTopName(std::string newmodname, std::string newtopname);
  std::string ToStringDelimitedBy(char cc) const;
  std::vector<std::string> ToExpandedStringVecDelimitedBy(char cc) const;
  std::vector<std::string> ToModularStringVecDelimitedBy(char cc) const;
};


#endif //DNASTRAND_H

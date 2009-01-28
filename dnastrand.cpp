#include "dnastrand.h"
#include "module.h"
#include "registry.h"
#include "variable.h"

bool DNAStrand::SetDownstream(Variable* var)
{
  if (var->GetType() == varModule) {
    var = var->GetModule()->GetUpstreamDNA();
    if (var == NULL) return true;
  }
  if (var->GetType() != varStrand) {
    if (var->SetType(varDNA)) return true;
  }
  else {
    //Check for recursivity
  }
  m_strand.push_back(var->GetName());
  m_module = var->GetNamespace();
  return false;
}

bool DNAStrand::SetUpstream(Variable* var)
{
  if (var->GetType() == varModule) {
    var = var->GetModule()->GetDownstreamDNA();
    if (var == NULL) return true;
  }
  if (var->GetType() != varStrand) {
    if (var->SetType(varDNA)) return true;
  }
  else {
  }
  m_strand.insert(m_strand.begin(), var->GetName());
  m_module = var->GetNamespace();
  return false;
}

void DNAStrand::SetDownstream(bool open)
{
  m_downstreamopen = open;
}

void DNAStrand::SetUpstream(bool open)
{
  m_upstreamopen = open;
}

void DNAStrand::SetComponentCompartments(Variable* compartment, bool frommodule)
{
  var_type supercomp = varStrand;
  if (frommodule) supercomp = varModule;
  for (size_t var=0; var<m_strand.size(); var++) {
    Variable* subvar = g_registry.GetModule(m_module)->GetVariable(m_strand[var]);
    subvar->SetSuperCompartment(compartment, supercomp);
    subvar->SetComponentCompartments(frommodule);
  }
}

void DNAStrand::Clear()
{
  m_strand.clear();
  m_upstreamopen = false;
  m_downstreamopen = false;
}

bool DNAStrand::IsEmpty() const
{
  return (m_strand.size() == 0);
}

Formula* DNAStrand::GetFinalFormula() const
{
  if (m_strand.size()==0) {
    assert(false); //ack
  }
  return g_registry.GetModule(m_module)->GetVariable(m_strand[m_strand.size()-1])->GetFormula();
}

void DNAStrand::SetNewTopName(string newmodname, string newtopname)
{
  m_module = newmodname;
  for (size_t var=0; var<m_strand.size(); var++) {
    m_strand[var].insert(m_strand[var].begin(), newtopname);
  }
}

vector<Variable*> DNAStrand::GetVariables() const
{
  vector<Variable*> vars;
  for (size_t var=0; var<m_strand.size(); var++) {
    vars.push_back(g_registry.GetModule(m_module)->GetVariable(m_strand[var]));
  }
  return vars;
}

vector<size_t> DNAStrand::GetOccurrencesOf(vector<string> varname) const
{
  vector<size_t> retval;
  Variable* testvar = g_registry.GetModule(m_module)->GetVariable(varname);
  if (testvar == NULL) {
    assert(false);
    return retval;
  }
  testvar = testvar->GetSameVariable();
  for (size_t var=0; var<m_strand.size(); var++) {
    Variable* localvar = g_registry.GetModule(m_module)->GetVariable(m_strand[var]);
    assert(localvar != NULL);
    localvar = localvar->GetSameVariable();
    if (localvar == testvar) {
      retval.push_back(var);
    }
  }
  return retval;
}

bool DNAStrand::CheckContains(Variable* var) const
{
  if (GetOccurrencesOf(var->GetName()).size() > 0) return true;
  for (size_t subvar=0; subvar<m_strand.size(); subvar++) {
    Variable* localvar = g_registry.GetModule(m_module)->GetVariable(m_strand[subvar]);
    if (localvar->GetType() == varStrand) {
      if (localvar->GetDNAStrand()->CheckContains(var)) return true;
    }
  }
  return false;
}


string DNAStrand::ToStringDelimitedBy(char cc) const
{
  string retval = "";
  if (m_upstreamopen) {
    retval += "--";
  }
  for (size_t dna=0; dna<m_strand.size(); dna++) {
    if (dna > 0) {
      retval += "--";
    }
    const Variable* var = g_registry.GetModule(m_module)->GetVariable(m_strand[dna]);
    assert(var != NULL);
    retval += var->GetNameDelimitedBy(cc);
  }
  if (m_downstreamopen) {
    retval += "--";
  }
  return retval;
}

vector<string> DNAStrand::ToExpandedStringVecDelimitedBy(char cc) const
{
  vector<string> retval;
  for (size_t dna=0; dna<m_strand.size(); dna++) {
    const Variable* var = g_registry.GetModule(m_module)->GetVariable(m_strand[dna]);
    assert(var != NULL);
    if (var->GetType() == varStrand) {
      vector<string> subvar = var->GetDNAStrand()->ToExpandedStringVecDelimitedBy(cc);
      retval.insert(retval.end(), subvar.begin(), subvar.end());
    }
    else {
      assert(IsDNA(var->GetType()));
      retval.push_back(var->GetNameDelimitedBy(cc));
    }
  }
  return retval;
}

vector<string> DNAStrand::ToModularStringVecDelimitedBy(char cc) const
{
  vector<string> retval;
  for (size_t dna=0; dna<m_strand.size(); dna++) {
    const Variable* var = g_registry.GetModule(m_module)->GetVariable(m_strand[dna]);
    assert(var != NULL);
    retval.push_back(var->GetNameDelimitedBy(cc));
  }
  return retval;
}

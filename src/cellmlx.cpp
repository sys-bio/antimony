#ifndef NCELLML

#include "registry.h"
#include "cellmlx.h"
#include "stringx.h"
#include "sbmlx.h"
#include <assert.h>
#include <iostream>
#include <sstream>

using namespace std;

string ToThinString(const PRUnichar* in)
{
  string out;
  for (size_t ch=0; (in[ch] != '\0'); ch++) {
    out.push_back(in[ch]);
  }
  return out;
}

nsString ToNSString(const string& in)
{
  PRUnichar out[in.size()+1];
  
  for (size_t ch=0; ch<in.size(); ch++) {
    out[ch] = in[ch];
  }

  return nsDependentString(out, in.size());
}

string CellMLPiecewiseToSBML(const string& in)
{
  string out = in;
  //First clear out all the excess spacing
  size_t spacepos;
  while ((spacepos = out.find("  ")) != string::npos) {
    out.replace(spacepos, 2, " ");
  }

  //cout << "Thus far:  " << in << endl;
  //If there are multiple 'piecewise' bits, excise the internal ones and parse them separately.
  size_t piecepos = 5;
  if ((piecepos = out.find("piecewise", piecepos)) != string::npos) {
    size_t endpos = piecepos;
    int numparens=0;
    for (size_t i = piecepos; i<out.size(); i++) {
      if (out[i] == '(') {
        numparens++;
      }
      else if (out[i] == ')') {
        numparens--;
        if (numparens==0) {
          endpos = i;
          break;
        }
      }
    }
    string internal;
    internal.assign(out, piecepos, endpos-piecepos);
    out.replace(piecepos, endpos-piecepos, "ANT_REPLACE");
    internal = CellMLPiecewiseToSBML(internal);
    out = CellMLPiecewiseToSBML(out);
    out.replace(out.rfind("ANT_REPLACE"), 11, internal); //rfind because if multiple replacements, we replace them last-to-first (recursively).
    return out;
  }
  size_t casepos = out.find("case ");
  if (casepos == string::npos) {
    //Done with the case/then lists; now replace "else Z" with "Z"
    size_t elsepos = out.find("else");
    if(elsepos != string::npos) {
      out.replace(elsepos, 4, "");
    }
    else {
      //No 'else'--need to remove the final comma.
      size_t finalcomma = out.rfind(",");
      if (finalcomma != string::npos) {
        out.replace(finalcomma, 1, "");
      }
    }
    //cout << "Final version: " << out << endl;
    return out;
  }

  //Now replace "case X then Y" with "Y, X,"
  size_t thenpos = out.find("then");
  assert(thenpos != string::npos); //Shouldn't have 'case' without 'then'
  size_t thenendpos = out.find("case ", thenpos);
  if (thenendpos == string::npos) {
    thenendpos = out.find("else");
  }
  if (thenendpos == string::npos) {
    //No final 'else'--just find the final ')'
    thenendpos = out.rfind(")");
    assert(thenendpos != string::npos);
    assert(thenpos < thenendpos);
  }
  string casestr, thenstr;
  casestr.assign(out, casepos+4, thenpos-casepos-4);
  thenstr.assign(out, thenpos+4, thenendpos-thenpos-4);
  //cout << "Case pre:  " << casestr << endl;
  casestr = AndsAndOrs(casestr);
  //cout << "Case post: " << casestr << endl;
  //cout << "Then: " << thenstr << endl;
  string replacement = thenstr + ", " + casestr + ", ";
  out.replace(casepos, thenendpos-casepos, replacement);
  //cout << "New version: " << out << endl;
  return CellMLPiecewiseToSBML(out); //recursive call for multiple 'case/then's
}

string GetModuleNameFrom(nsCOMPtr<cellml_apiICellMLComponent> component)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;
  rv = component->GetName(cellmltext);
  cellmlname = ToThinString(cellmltext.get());
  nsCOMPtr<cellml_apiIModel> mod;
  rv = component->GetModelElement(getter_AddRefs(mod));
  rv = mod->GetName(cellmltext);
  cellmlname = ToThinString(cellmltext.get()) + "__" + cellmlname;
  return cellmlname;
}

string GetModuleNameFrom(nsCOMPtr<cellml_apiIImportComponent> impcomponent)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;
  rv = impcomponent->GetComponentRef(cellmltext);
  cellmlname = ToThinString(cellmltext.get());
  nsCOMPtr<cellml_apiICellMLElement> import_as_element;
  rv = impcomponent->GetParentElement(getter_AddRefs(import_as_element));
  nsCOMPtr<cellml_apiICellMLImport> import;
  nsIID nsiid = import->GetIID();
  rv = import_as_element->QueryInterface(nsiid, getter_AddRefs(import));
  nsCOMPtr<cellml_apiIModel> mod;
  rv = import->GetImportedModel(getter_AddRefs(mod));
  rv = mod->GetName(cellmltext);
  cellmlname = ToThinString(cellmltext.get()) + "__" + cellmlname;
  return cellmlname;
}

string GetNameAccordingToEncapsulationParent(nsCOMPtr<cellml_apiICellMLComponent> component, nsCOMPtr<cellml_apiIModel> topmodel)
{
  nsString cellmltext;
  string cellmlname;
  nsresult rv;

  nsCString compid;
  nsCOMPtr<IWrappedPCM> cw(do_QueryInterface(component));
  rv = cw->GetObjid(compid);
  map<string, string>::iterator name = g_registry.m_cellmlnames.find(compid.get());
  if (name != g_registry.m_cellmlnames.end()) {
    return name->second;
  }

  nsCOMPtr<cellml_apiICellMLComponent> encapsulationparent;
  rv = component->GetEncapsulationParent(getter_AddRefs(encapsulationparent));
  nsCOMPtr<cellml_apiIModel> encapsulationmodel;

  if (encapsulationparent == NULL) {
    encapsulationmodel = topmodel;
  }
  else {
    rv = encapsulationparent->GetModelElement(getter_AddRefs(encapsulationmodel));
  }
  //rv = encapsulationmodel->GetName(cellmltext);
  //cout << "Encapsulation model: " << ToThinString(cellmltext.get()) << endl;

  //Now we have the encapsulation model.  This model is what has the name we need.  However, we can't trace from that model down to our component, because somewhere it might have included it more than once.  So instead, we work backward up the tree from the component.  The component may be in the same model; it might be imported; it might be imported by an import; etc.  We're going to discard all the names the component might have had in the path up to the encapsulation model, and instead just claim that the encapsulor included it directly with the name that it uses.

  nsCOMPtr<cellml_apiIModel> compmodel;
  rv = component->GetModelElement(getter_AddRefs(compmodel));
  rv = compmodel->GetName(cellmltext);
  //cout << "Component model: " << ToThinString(cellmltext.get()) << endl;
  rv = component->GetName(cellmltext);
  nsString componentref = cellmltext;
  cellmlname = ToThinString(cellmltext.get());
  FixName(cellmlname);

  cw = do_QueryInterface(compmodel);
  rv = cw->GetObjid(compid);
  nsCString encapmodid;
  cw = do_QueryInterface(encapsulationmodel);
  rv = cw->GetObjid(encapmodid);
  while (compid != encapmodid) {
    nsCOMPtr<cellml_apiICellMLElement> parentel;
    rv = compmodel->GetParentElement(getter_AddRefs(parentel));
    //Now cast 'parentel' as a ImportComponent and get the local name of the imported component.
    assert(parentel != NULL);
    nsCOMPtr<cellml_apiICellMLImport> import;
    nsIID nsiid = import->GetIID();
    rv = parentel->QueryInterface(nsiid, getter_AddRefs(import));
    assert(import != NULL);
    nsCOMPtr<cellml_apiIImportComponentSet> ics;
    rv = import->GetComponents(getter_AddRefs(ics));
    nsCOMPtr<cellml_apiIImportComponentIterator> ici;
    rv = ics->IterateImportComponents(getter_AddRefs(ici));
    nsCOMPtr<cellml_apiIImportComponent> ic;
    rv = ici->NextImportComponent(getter_AddRefs(ic));
    bool found = false;
    while (ic != NULL) {
      rv = ic->GetComponentRef(cellmltext);
      if (componentref == cellmltext) {
        //This is the right subcomponent
        rv = ic->GetName(cellmltext);
        cellmlname = ToThinString(cellmltext.get());
        found = true;
      }
      rv = ici->NextImportComponent(getter_AddRefs(ic));
    }
    assert(found);

    
    rv = parentel->GetModelElement(getter_AddRefs(compmodel));
    cw = do_QueryInterface(compmodel);
    rv = cw->GetObjid(compid);
  }

  FixName(cellmlname);
  return cellmlname;
}


#endif

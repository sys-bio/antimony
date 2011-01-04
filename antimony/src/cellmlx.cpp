#ifndef NCELLML

#include "registry.h"
#include "cellmlx.h"
#include "stringx.h"
#include "sbmlx.h"
#include <assert.h>
#include <iostream>
#include <sstream>

using namespace std;

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

string GetModuleNameFrom(iface::cellml_api::CellMLComponent* component)
{
  RETURN_INTO_WSTRING(wcompname, component->name());
  std::string compname(makeUTF8(wcompname));
  RETURN_INTO_OBJREF(mod, iface::cellml_api::Model, component->modelElement());
  RETURN_INTO_WSTRING(wmodname, mod->name());
  std::string modname(makeUTF8(wmodname));

  std::string cellmlname = modname + "__" + compname;
  FixName(cellmlname);
  return cellmlname;
}

string GetModuleNameFrom(iface::cellml_api::ImportComponent* impcomponent)
{
  RETURN_INTO_WSTRING(wcompRefName, impcomponent->componentRef());
  std::string compRefName(makeUTF8(wcompRefName));

  RETURN_INTO_OBJREF(import_as_element, iface::cellml_api::CellMLElement,
                     impcomponent->parentElement());
  DECLARE_QUERY_INTERFACE_OBJREF(import, import_as_element, cellml_api::CellMLImport);
  RETURN_INTO_OBJREF(mod, iface::cellml_api::Model, import->importedModel());
  RETURN_INTO_WSTRING(wimpModName, mod->name());
  std::string impModName(makeUTF8(wimpModName));
  std::string cellmlname = impModName + "__" + compRefName;
  return cellmlname;
}

// XXX This is *not* a reliable way to get a unique name for a component instance,
// because not all components in an imported model have to be imported (they can
// be encapsulated underneath an imported component) - meaning that if a model is
// imported twice, this function will return the same name for a component that is
// imported indirectly multiple times. -- Andrew Miller
std::string
GetNameAccordingToEncapsulationParent(iface::cellml_api::CellMLComponent* component,
                                      iface::cellml_api::Model* topmodel)
{
  char *oid = component->objid();
  std::string oid_s(oid);
  free(oid);
  map<string, string>::iterator name = g_registry.m_cellmlnames.find(oid_s);
  if (name != g_registry.m_cellmlnames.end()) {
    return name->second;
  }

  RETURN_INTO_OBJREF(encapsulationParent, iface::cellml_api::CellMLComponent,
                     component->encapsulationParent());

  ObjRef<iface::cellml_api::Model> encapsulationModel;
  if (encapsulationParent == NULL) {
    encapsulationModel = topmodel;
  }
  else {
    encapsulationModel = already_AddRefd<iface::cellml_api::Model>
      (encapsulationParent->modelElement());
  }
  //rv = encapsulationmodel->GetName(cellmltext);
  //cout << "Encapsulation model: " << ToThinString(cellmltext.get()) << endl;

  //Now we have the encapsulation model.  This model is what has the name we need.  However, we can't trace from that model down to our component, because somewhere it might have included it more than once.  So instead, we work backward up the tree from the component.  The component may be in the same model; it might be imported; it might be imported by an import; etc.  We're going to discard all the names the component might have had in the path up to the encapsulation model, and instead just claim that the encapsulor included it directly with the name that it uses.

  RETURN_INTO_OBJREF(compmodel, iface::cellml_api::Model, component->modelElement());
  //RETURN_INTO_WSTRING(wcellmltext, compmodel->name());
  //std::string cellmltext(makeUTF8(wcellmltext));
  //cout << "Component model: " << cellmltext << endl;

  RETURN_INTO_WSTRING(wcomponentRef, component->name());

  while (CDA_objcmp(compmodel, encapsulationModel))
  {
    RETURN_INTO_OBJREF(parentel, iface::cellml_api::CellMLElement, compmodel->parentElement());
    assert(parentel != NULL);

    //Now QueryInterface 'parentel' to an ImportComponent and get the local name of the imported component.
    DECLARE_QUERY_INTERFACE_OBJREF(import, parentel, cellml_api::CellMLImport);
    assert(import != NULL);

    RETURN_INTO_OBJREF(ics, iface::cellml_api::ImportComponentSet, import->components());
    RETURN_INTO_OBJREF(ici, iface::cellml_api::ImportComponentIterator, ics->iterateImportComponents());
    bool found = false;
    while (true) {
      RETURN_INTO_OBJREF(ic, iface::cellml_api::ImportComponent, ici->nextImportComponent());
      if (ic == NULL)
        break;

      RETURN_INTO_WSTRING(newComponentRef, ic->componentRef());
      if (newComponentRef == wcomponentRef) {
        //This is the right subcomponent
        RETURN_INTO_WSTRING(newName, ic->name());
        newComponentRef = newName;
        found = true;
      }
    }
    assert(found);
    compmodel = parentel->modelElement();
  }

  std::string cellmlname(makeUTF8(wcomponentRef));
  FixName(cellmlname);
  return cellmlname;
}

iface::cellml_api::CellMLComponent*
GetCellMLComponentOf(iface::cellml_api::CellMLVariable* var)
{
  RETURN_INTO_OBJREF(el, iface::cellml_api::CellMLElement, var->parentElement());

  DECLARE_QUERY_INTERFACE(ret, el, cellml_api::CellMLComponent);
  return ret;
}

iface::cellml_api::Connection*  GetOrCreateConnectionFor(iface::cellml_api::CellMLComponent* comp1, iface::cellml_api::CellMLComponent* comp2, iface::cellml_api::Model* model)
{
  RETURN_INTO_WSTRING(comp1name, comp1->name());
  RETURN_INTO_WSTRING(comp2name, comp2->name());
  RETURN_INTO_OBJREF(conset, iface::cellml_api::ConnectionSet, model->connections());
  RETURN_INTO_OBJREF(coni, iface::cellml_api::ConnectionIterator, conset->iterateConnections());
  RETURN_INTO_OBJREF(connection, iface::cellml_api::Connection, coni->nextConnection());
  while (connection != NULL) {
    RETURN_INTO_OBJREF(mapcomp, iface::cellml_api::MapComponents, connection->componentMapping());
    RETURN_INTO_WSTRING(testcomp1name, mapcomp->firstComponentName());
    RETURN_INTO_WSTRING(testcomp2name, mapcomp->secondComponentName());
    if ((testcomp1name == comp1name && testcomp2name == comp2name) ||
        (testcomp1name == comp2name && testcomp2name == comp1name)) {
      //cout << "Found match!" << endl;
      return connection;
    }
    connection = coni->nextConnection();
  }
  //No connection found--create a new one
  connection = model->createConnection();
  model->addElement(connection);
  return connection;
}

#endif

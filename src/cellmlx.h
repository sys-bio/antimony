#ifndef CELLMLX_H
#define CELLMLX_H

#ifndef NCELLML
#include "IfaceCellML_APISPEC.hxx"
#include "cellml-api-cxx-support.hpp"
#ifdef WIN32
#undef WIN32
#define WIN32 1 //CellML wants this to just be #defined, but SBML wants it to be 1.
#endif

#include <string>
#include <vector>

std::wstring makeUTF16(const std::string& aStr);
std::string makeUTF8(const std::wstring& aStr);
std::string GetNameAccordingToEncapsulationParent(iface::cellml_api::CellMLComponent* component, iface::cellml_api::Model* topmodel);
std::string GetModuleNameFrom(iface::cellml_api::CellMLComponent* component);
std::string GetModuleNameFrom(iface::cellml_api::ImportComponent* impcomponent);
iface::cellml_api::CellMLComponent* GetCellMLComponentOf(iface::cellml_api::CellMLVariable* var);

std::string CellMLPiecewiseToSBML(const std::string& in);

iface::cellml_api::Connection* GetOrCreateConnectionFor(iface::cellml_api::CellMLComponent* comp1, iface::cellml_api::CellMLComponent* comp2, iface::cellml_api::Model* model);

#endif //NCELLML

#endif //CELLMLX_H

#ifndef CELLMLX_H
#define CELLMLX_H

#ifndef NCELLML
#include "IfaceCellML_APISPEC.hxx"
//#include "IfaceTeLICeMS.hxx"
#include "Utilities.hxx"

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

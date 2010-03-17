#ifndef CELLMLX_H
#define CELLMLX_H

#ifndef NCELLML
#include "MathMLInputServices.h"
#include "ICellMLInputServices.h"
#include "ICeVAS.h"
#include <nsStringAPI.h>
#include <nsDebug.h>
#include <nsIID.h>
#include <nsCOMPtr.h>
#include <nsServiceManagerUtils.h>

#include <string>
#include <vector>


std::string ToThinString(const PRUnichar* in);
nsString ToNSString(const std::string& in);
std::string CellMLPiecewiseToSBML(const std::string& in);

std::string GetModuleNameFrom(nsCOMPtr<cellml_apiICellMLComponent> component);
std::string GetModuleNameFrom(nsCOMPtr<cellml_apiIImportComponent> impcomponent);
std::string GetNameAccordingToEncapsulationParent(nsCOMPtr<cellml_apiICellMLComponent> component, nsCOMPtr<cellml_apiIModel> topmodel);


#endif //NCELLML

#endif //CELLMLX_H

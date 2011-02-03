// SBW Translator 

#include "sbwtranslator.h"
#include "antimony_api.h"
#include <SBW/SBW.h>

using namespace std;
using namespace SystemsBiologyWorkbench;

DataBlockWriter SBWTranslator::translate(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << "";
}

int main(int argc, char** argv)
{
  SBWTranslator *trans = new SBWTranslator();
  ModuleImpl modImpl(
			"edu.kgi.matlabTranslator", // module identification
			"matlabTranslator written in C++", // humanly readable name
			UniqueModule); // management scheme

		modImpl.addServiceObject(
			"translator", // service identification
			 "Matlab Translator", // humanly readable name
			"plugin/sbmlTranslator", // category
			trans); // service implementation
  modImpl.run(argc, argv);
  return 0;
}

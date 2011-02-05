// SBW Translator 

#include "sbwtranslator.h"
#include "antimony_api.h"
#include <SBW/SBW.h>

using namespace std;
using namespace SystemsBiologyWorkbench;

const string TRANSLATOR_NAME			= "antimonyTranslator";
const string TRANSLATOR_VERSION			= "1.00";
const string TRANSLATOR_AUTHOR			= "Frank Bergmann";
const string TRANSLATOR_DESCRIPTION		= "Translates SBML to Antimony.";
const string TRANSLATOR_DISPLAYNAME		= "Antimony Translator";
const string TRANSLATOR_COPYRIGHT		= "BSD";
const string TRANSLATOR_URL				= "www.sys-bio.org";

DataBlockWriter SBWTranslator::getName(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_NAME;
}

DataBlockWriter SBWTranslator::getVersion(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_VERSION;
}

DataBlockWriter SBWTranslator::getAuthor(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_AUTHOR;
}

DataBlockWriter SBWTranslator::getDescription(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_DESCRIPTION;
}

DataBlockWriter SBWTranslator::getDisplayName(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_DISPLAYNAME;
}

DataBlockWriter SBWTranslator::getCopyright(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_COPYRIGHT;
}

DataBlockWriter SBWTranslator::getURL(Module from, DataBlockReader reader)
{
	return DataBlockWriter() << TRANSLATOR_URL;
}

DataBlockWriter SBWTranslator::getFileExtension(Module from, DataBlockReader reader)
{
	string file_ext = "txt";
	return DataBlockWriter() << file_ext;
}

DataBlockWriter SBWTranslator::getFileType(Module from, DataBlockReader reader)
{
	string file_type = "Antimony Script File";
	return DataBlockWriter() << file_type;
}

DataBlockWriter SBWTranslator::translate(Module from, DataBlockReader reader)
{
	string sbml; reader >> sbml;
	loadSBMLString(sbml.c_str());	
	string antimony = getAntimonyString(NULL);
	 
	return DataBlockWriter() << antimony;
}

void SBWTranslator::registerMethods(MethodTable<SBWTranslator> &table)
{
	table.addMethod(&SBWTranslator::getName,					"string getName()", false, TRANSLATOR_NAME);
	table.addMethod(&SBWTranslator::getVersion,					"string getVersion()", false, TRANSLATOR_VERSION);
	table.addMethod(&SBWTranslator::getAuthor,					"string getAuthor()", false, TRANSLATOR_AUTHOR);
	table.addMethod(&SBWTranslator::getDescription,				"string getDescription()", false, TRANSLATOR_DESCRIPTION);
	table.addMethod(&SBWTranslator::getDisplayName,				"string getDisplayName()", false, TRANSLATOR_DISPLAYNAME);
	table.addMethod(&SBWTranslator::getCopyright,				"string getCopyright()", false, TRANSLATOR_COPYRIGHT);
	table.addMethod(&SBWTranslator::getURL,						"string getURL()", false, TRANSLATOR_URL);
	table.addMethod(&SBWTranslator::getFileExtension,           "string getFileExtension()", false, "Returns the file extension as a string");
	table.addMethod(&SBWTranslator::getFileType,                "string getFileType()", false, "Returns a string describing the type of file");
	table.addMethod(&SBWTranslator::translate,					"string translate(string)", false, "Antimony Translator, takes SBML as input");
}	


int main(int argc, char** argv)
{
  try 
  {
	  SBWTranslator *trans = new SBWTranslator();
	  ModuleImpl modImpl(
						 TRANSLATOR_NAME,        // module identification
						 TRANSLATOR_DISPLAYNAME, // humanly readable name
						 UniqueModule);          // management scheme
	  
	  modImpl.addServiceObject(
						"translator",            // service identification
						TRANSLATOR_DISPLAYNAME,  // humanly readable name
						"plugin/sbmlTranslator", // category
						trans);                  // service implementation
	  modImpl.run(argc, argv);
	  return 0;
  }
  catch (...) 
  {
	  return 1;
  }
}

// SBW Translator 
#ifndef SBW_TRANSLATOR_H
#define SBW_TRANSLATOR_H

#include <string>
#include <iostream>
#include <SBW/SBW.h>

using namespace std;



const string TRANSLATOR_NAME			= "antimonyTranslator";
const string TRANSLATOR_VERSION			= "1.00";
const string TRANSLATOR_AUTHOR			= "Frank Bergmann";
const string TRANSLATOR_DESCRIPTION		= "Translates SBML to Antimony.";
const string TRANSLATOR_DISPLAYNAME		= "Antimony Translator";
const string TRANSLATOR_COPYRIGHT		= "BSD";
const string TRANSLATOR_URL				= "www.sys-bio.org";

class SBWTranslator
{
public:
	/// this method provides the implementation of getName method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getName(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_NAME;
	}

	/// this method provides the implementation of getVersion method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getVersion(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_VERSION;
	}

	/// this method provides the implementation of getAuthor method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getAuthor(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_AUTHOR;
	}

	/// this method provides the implementation of getDescription method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getDescription(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_DESCRIPTION;
	}

	/// this method provides the implementation of getDisplayName method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getDisplayName(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_DISPLAYNAME;
	}

	/// this method provides the implementation of getCopyright method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getCopyright(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_COPYRIGHT;
	}

	/// this method provides the implementation of getURL method
	/// arguments: from - module calling this method
	/// reader - object containing argument data
	/// returns: object containing result data
	DataBlockWriter getURL(Module from, DataBlockReader reader)
	{
		return DataBlockWriter() << TRANSLATOR_URL;
	}

	/// Returns a string with the name of the file extension. This method
	/// can be called by other tools to save the file as a .cs file
	DataBlockWriter getFileExtension(Module from, DataBlockReader reader)
	{
		string file_ext = "txt";
		return DataBlockWriter() << file_ext;
	}

	/// Returns a string with the name of the file extension. This method
	/// can be called by other tools to save the file as a .cs file
	DataBlockWriter getFileType(Module from, DataBlockReader reader)
	{
		string file_type = "Antimony Script File";
		return DataBlockWriter() << file_type;
	}
	
	string translateSBML(const string &sbmlInput);
	DataBlockWriter translate(Module from, DataBlockReader reader);
	
	/**
	* register methods of this class with a module implementation represented by a
	* given MethodTable
	* argument - table object that provides a simple interface to a module implementation
	*/
	static void registerMethods(MethodTable<SBWTranslator> &table)
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
		table.addMethod(&SBWTranslator::translate,					"string translate(string)", false, "Matlab Translator Module, takes SBML as input");
	}	

};

#endif

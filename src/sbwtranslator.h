// SBW Translator 
#ifndef SBW_TRANSLATOR_H
#define SBW_TRANSLATOR_H

#include <string>
#include <iostream>
#include <SBW/SBW.h>

class SBWTranslator
{
public:
	/** 
	 * this method provides the implementation of getName method
	 * arguments: from - module calling this method
	 * reader - object containing argument data
	 * returns: object containing result data 
	 */
	DataBlockWriter getName(Module from, DataBlockReader reader);

	/**
	 *  this method provides the implementation of getVersion method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getVersion(Module from, DataBlockReader reader);

	/**
	 *  this method provides the implementation of getAuthor method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getAuthor(Module from, DataBlockReader reader);
	
	/**  
	 *  this method provides the implementation of getDescription method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getDescription(Module from, DataBlockReader reader);

	/**  
	 *  this method provides the implementation of getDisplayName method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getDisplayName(Module from, DataBlockReader reader);
	
	/**
	 *  this method provides the implementation of getCopyright method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getCopyright(Module from, DataBlockReader reader);

	/**
	 *  this method provides the implementation of getURL method
	 *  arguments: from - module calling this method
	 *  reader - object containing argument data
	 *  returns: object containing result data 
	 */
	DataBlockWriter getURL(Module from, DataBlockReader reader);

	/**
	 *  Returns a string with the name of the file extension. This method
	 *  can be called by other tools to save the file as a .txt file 
	 */
	DataBlockWriter getFileExtension(Module from, DataBlockReader reader);

	/**
	 *  Returns a string with the name of the file extension. This method
	 *  can be called by other tools to save the file as a .txt file 
	 */
	DataBlockWriter getFileType(Module from, DataBlockReader reader);
	
	/**
	 * The method calling antimony and translates SBML to antimony.
	 */
	DataBlockWriter translate(Module from, DataBlockReader reader);
	
	/**
	 * register methods of this class with a module implementation represented by a
	 * given MethodTable
	 * argument - table object that provides a simple interface to a module implementation
	 */
	static void registerMethods(MethodTable<SBWTranslator> &table);	

};

#endif

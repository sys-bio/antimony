####################################################################
#
# File of common macros for building libantimony (courtesy Frank Bergmann)
#
# $Author$
# $Id$
# $HeadURL$
#

####################################################################
#
# utility macro for copying files
#
macro(copy_files srcDir destDir pattern)
	message(STATUS "Copying files from ${srcDir}")
    make_directory(${destDir})

    file(GLOB templateFiles RELATIVE ${srcDir} ${srcDir}/${pattern})
    foreach(templateFile ${templateFiles})
        set(srcTemplatePath ${srcDir}/${templateFile})
        if(NOT IS_DIRECTORY ${srcTemplatePath})
            #message(STATUS "Copying file ${templateFile}")
            configure_file(
                    ${srcTemplatePath}
                    ${destDir}/${templateFile}
                    COPYONLY)
        endif(NOT IS_DIRECTORY ${srcTemplatePath})
    endforeach(templateFile)
		
endmacro(copy_files)

macro(copy_file srcFile destDir)
    message(STATUS "Copying ${srcFile}")
    make_directory(${destDir})
    get_filename_component(name ${srcFile} NAME)    

	if(NOT IS_DIRECTORY ${srcFile})
		configure_file(
			${srcFile}
			${destDir}/${name}
			COPYONLY)
	endif(NOT IS_DIRECTORY ${srcFile})
		
endmacro(copy_file)

macro(copy_file_to_subdir srcFile destDir)
	get_filename_component(subdir ${srcFile} PATH)
	get_filename_component(name ${srcFile} NAME)
    
	make_directory(${destDir}/${subdir})
	message(STATUS "Copying ${srcFile}")
	
	if(NOT IS_DIRECTORY ${srcFile})
		configure_file(
			${srcFile}
			${destDir}/${subdir}/${name}
			COPYONLY)
	endif(NOT IS_DIRECTORY ${srcFile})
		
endmacro(copy_file_to_subdir)


macro(remove_file srcFile)
	if(EXISTS ${srcFile})
		message(STATUS "Remove ${srcFile}")	
		file(REMOVE ${srcFile})
	else()
		message(STATUS "Cannot remove ${srcFile} it does not exist.")
	endif()
endmacro(remove_file)

macro(remove_file_in_subdir srcFile baseDir)
	get_filename_component(subdir ${srcFile} PATH)
	get_filename_component(name ${srcFile} NAME)
	if(EXISTS ${baseDir}/${subdir}/${name})
		message(STATUS "Remove ${srcFile}")
		file(REMOVE ${baseDir}/${subdir}/${name})
	endif()
endmacro(remove_file_in_subdir)



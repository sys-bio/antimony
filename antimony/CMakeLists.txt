####################################################################
#
# CMake Build Script for libantimony
#

cmake_minimum_required(VERSION 2.8)
project(libantimony)

####################################################################
#
# Set up version information.
#
SET(LIBANTIMONY_VERSION_MAJOR 2)
SET(LIBANTIMONY_VERSION_MINOR 4)
SET(LIBANTIMONY_VERSION_PATCH "")
SET(LIBANTIMONY_VERSION_RELEASE "")


####################################################################
#
# the next lines configure the parameters for packaging the binaries
# they can be invoked with: make package / nmake package or by using 
# cpack -G zip|deb|rpm|dmg|nsis
#

INCLUDE(InstallRequiredSystemLibraries)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An API library for reading, writing, manipulating, and translating Antimony models")
SET(CPACK_PACKAGE_NAME "libAntimony")
SET(CPACK_PACKAGE_VENDOR "Lucian Smith")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "${LIBANTIMONY_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${LIBANTIMONY_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${LIBANTIMONY_VERSION_PATCH}")
SET(CPACK_PACKAGE_VERSION_RELEASE "${LIBANTIMONY_VERSION_RELEASE}")
INCLUDE(CPack)

option(BUILD_SHARED_LIBS  "Build shared library (Set to OFF to build static libraries)" ON)
set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel" )


####################################################################
#
# Here we have the main configuration options for libantimony
#

# which language bindings should be build
option(WITH_SBML            "Generate SBML translations"      ON )
option(WITH_COMP_SBML       "Use the hierarchical composition package in SBML"      ON )
option(WITH_CELLML          "Generate CellML translations"    ON )
option(WITH_QTANTIMONY      "Generate QTAntimony"             ON )
option(WITH_SBW             "QTAntimony integration with SBW" OFF )
option(WITH_SBW_TRANSLATOR  "Generate SBWTranslator"          OFF )
option(WITH_SWIG   "Regenerate SWIG-based language bindings." ON )
option(WITH_PYTHON       "Generate Python language bindings." OFF)

set(EXTRA_LIBS "" CACHE STRING "Libraries the other libraries depend on that are in non-standard locations" )
#set(EXTRA_LIBS "" CACHE_STRING "")

SET(LIBANTIMONY_VERSION_STRING "v${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")
add_definitions( -DLIBANTIMONY_VERSION_STRING="${LIBANTIMONY_VERSION_STRING}" )


####################################################################
#
# Locate libsbml if needed
#

if(WITH_SBML)

	find_library(LIBSBML_LIBRARY 
		NAMES libsbml.lib libsbml.so libsbml
		PATHS /usr/lib /usr/local/lib 
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${CMAKE_SOURCE_DIR}/../libsbml-5/build/src/RelWithDebInfo
        )
	
	find_path(LIBSBML_INCLUDE_DIR
		NAMES sbml/SBMLTypes.h
		PATHS /usr/include /usr/local/include 
              ${CMAKE_SOURCE_DIR}/include 
              ${CMAKE_SOURCE_DIR}/dependencies/include
              ${CMAKE_SOURCE_DIR}/../libsbml-5/release/include/
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBSBML_LIBRARY} )
    if(WIN32)
	find_path(LIBSBML_BIN_DIR
		NAMES libsbml.dll
		PATHS /usr/bin /usr/local/bin
              ${LIBSBML_INCLUDE_DIR}/../bin
              ${CMAKE_SOURCE_DIR}/ 
              ${CMAKE_SOURCE_DIR}/dependencies/libsbml/bin
              ${CMAKE_SOURCE_DIR}/../libsbml-5/release/bin/
        )
        set(LIBSBML_DLL ${LIBSBML_BIN_DIR}/libsbml.dll)
        install(FILES   ${LIBSBML_DLL} DESTINATION ${CMAKE_SOURCE_DIR}/win32)
    endif()
    INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${LIBSBML_INCLUDE_DIR})
	if (WITH_COMP_SBML)
	    add_definitions( -DUSE_COMP )
    endif(WITH_COMP_SBML)
else(WITH_SBML)
    add_definitions( -DNSBML )
endif(WITH_SBML)

####################################################################
#
# Locate the CellML API and attendant libraries if needed
#

if(WITH_CELLML)
        #CellML:
        find_path(CELLML_API_INSTALL_DIR
		NAMES include/IfaceCellML_APISPEC.hxx
		PATHS /usr/include /usr/local/include 
              C:/Program Files (x86)/cellml-sdk-1.11
              C:/Program Files/cellml-sdk-1.11
              ${CMAKE_SOURCE_DIR}/cellml-sdk 
              ${CMAKE_SOURCE_DIR}/dependencies/cellml-sdk
			  )

        find_library(CELLML_API_LIB
		NAMES cellml.lib cellml
		PATHS /usr/lib /usr/local/lib
              ${CELLML_API_INSTALL_DIR}/lib
              C:/build/cellml-api/.libs/
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CELLML_API_LIB})

        find_library(CEVAS_LIB 
		NAMES cevas.lib cevas
		PATHS /usr/lib /usr/local/lib
              ${CELLML_API_INSTALL_DIR}/lib
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CEVAS_LIB})
	
        find_library(ANNOTOOLS_LIB 
		NAMES annotools.lib annotools
		PATHS /usr/lib /usr/local/lib
              ${CELLML_API_INSTALL_DIR}/lib
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${ANNOTOOLS_LIB})
	
	find_library(CUSES_LIB 
		NAMES cuses.lib cuses
		PATHS /usr/lib /usr/local/lib
              ${CELLML_API_INSTALL_DIR}/lib
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CUSES_LIB})

        find_library(TELICEMS_LIB 
		NAMES telicems.lib telicems
		PATHS /usr/lib /usr/local/lib
              ${CELLML_API_INSTALL_DIR}/lib
              ${CMAKE_SOURCE_DIR} 
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${TELICEMS_LIB})

        set(CELLML_INCLUDE_DIRECTORIES ${CELLML_API_INSTALL_DIR}/include )

        set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${ALL_CELLML_LIBS} )
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${CELLML_INCLUDE_DIRECTORIES} )

else(WITH_CELLML)
  add_definitions( -DNCELLML )

endif(WITH_CELLML)

###############################################################################
#
# If WITH_SWIG is selected, we need to find swig
#
if(WITH_SWIG)
    find_program(SWIG_EXECUTABLE
        NAMES swig
        PATHS
              c:/Program Files (x86)/Swig
              c:/Program Files/Swig
              c:/swigwin-2.0.11
              c:/swigwin-2.0.10
              c:/swigwin-2.0.9
              c:/swigwin-2.0.8
              c:/swigwin-2.0.7
              c:/swigwin-2.0.6
              c:/swigwin-2.0.5
              c:/swigwin-2.0.4
              c:/swigwin-2.0.3
              c:/swigwin-2.0.2
              c:/swigwin-2.0.1
              c:/swigwin-2.0.0
              /usr/local/bin
              /opt/local/bin
              /usr/bin
        DOC "The file name of the swig executable."
        )
    find_package(SWIG)
    set(SWIG_EXTRA_ARGS "" CACHE STRING "Extra arguments to SWIG" )
endif(WITH_SWIG)

if(WITH_SWIG)
    message(STATUS "  Using SWIG                    = ${SWIG_EXECUTABLE}")
    
    if (SWIG_FOUND AND SWIG_VERSION VERSION_LESS "2.0.4")
    	message(WARNING "   You are using swig version ${SWIG_VERSION} while we recommend at least version 2.0.4.")
    endif()

endif()

if(WITH_PYTHON)
    message(STATUS "  Using Python                  = ${PYTHON_EXECUTABLE}")
endif()


set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${EXTRA_LIBS} )

####################################################################
#
# Need some variables set up, such as the name for the libAntimony 
# library and the Path and file separator characters
#

if(UNIX)
	set(PATH_SEP "/")
	set(FILE_SEP ":")
	set(LIBANTIMONY_LIBRARY antimony)
else()
	set(PATH_SEP "\\")
	set(FILE_SEP ";")
	set(LIBANTIMONY_LIBRARY libantimony)
endif()

####################################################################
#
# Build the actual libAntimony library
#

set (ANTIMONY_SRC_DIR src/)

file(GLOB LIBANTIMONY_SOURCES 
        ${ANTIMONY_SRC_DIR}antimony_api.cpp
        ${ANTIMONY_SRC_DIR}antimony_api_cpp.cpp
	${ANTIMONY_SRC_DIR}Antimony.cpp
	${ANTIMONY_SRC_DIR}antimony.tab.cpp
	${ANTIMONY_SRC_DIR}annotated.cpp
	${ANTIMONY_SRC_DIR}cellmlx.cpp
	${ANTIMONY_SRC_DIR}dnastrand.cpp
	${ANTIMONY_SRC_DIR}event.cpp
	${ANTIMONY_SRC_DIR}formula.cpp
	${ANTIMONY_SRC_DIR}module.cpp
	${ANTIMONY_SRC_DIR}reactantlist.cpp
	${ANTIMONY_SRC_DIR}reaction.cpp
	${ANTIMONY_SRC_DIR}registry.cpp
	${ANTIMONY_SRC_DIR}sbmlx.cpp
	${ANTIMONY_SRC_DIR}stringx.cpp
	${ANTIMONY_SRC_DIR}typex.cpp
	${ANTIMONY_SRC_DIR}unitdef.cpp
	${ANTIMONY_SRC_DIR}unitelement.cpp
	${ANTIMONY_SRC_DIR}userfunction.cpp
	${ANTIMONY_SRC_DIR}unitdef.cpp
	${ANTIMONY_SRC_DIR}unitelement.cpp
	${ANTIMONY_SRC_DIR}variable.cpp
	)
file(GLOB LIBANTIMONY_TRANSLATORS 
	${ANTIMONY_SRC_DIR}module-sbml.cpp
	${ANTIMONY_SRC_DIR}module-cellml.cpp
        )
SET_SOURCE_FILES_PROPERTIES(
        ${ANTIMONY_SRC_DIR}module-sbml.cpp
	${ANTIMONY_SRC_DIR}module-cellml.cpp
        PROPERTIES HEADER_FILE_ONLY true
        )
source_group(Translators FILES ${LIBANTIMONY_TRANSLATORS})

file(GLOB LIBANTIMONY_HEADERS 
	${ANTIMONY_SRC_DIR}annotated.h
        ${ANTIMONY_SRC_DIR}antimony_api.h
        ${ANTIMONY_SRC_DIR}antimony_api_cpp.h
        ${ANTIMONY_SRC_DIR}dnastrand.h
        ${ANTIMONY_SRC_DIR}cellmlx.h
        ${ANTIMONY_SRC_DIR}enums.h
        ${ANTIMONY_SRC_DIR}event.h
        ${ANTIMONY_SRC_DIR}formula.h
        ${ANTIMONY_SRC_DIR}libutil.h
        ${ANTIMONY_SRC_DIR}module.h
        ${ANTIMONY_SRC_DIR}reactantlist.h
        ${ANTIMONY_SRC_DIR}reaction.h
        ${ANTIMONY_SRC_DIR}registry.h
        ${ANTIMONY_SRC_DIR}sbmlx.h
        ${ANTIMONY_SRC_DIR}stringx.h
        ${ANTIMONY_SRC_DIR}typex.h
        ${ANTIMONY_SRC_DIR}unitdef.h
        ${ANTIMONY_SRC_DIR}unitelement.h
        ${ANTIMONY_SRC_DIR}userfunction.h
	${ANTIMONY_SRC_DIR}unitdef.h
	${ANTIMONY_SRC_DIR}unitelement.h
        ${ANTIMONY_SRC_DIR}variable.h
        )
 
add_library(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_HEADERS} ${LIBANTIMONY_SOURCES} ${LIBANTIMONY_TRANSLATORS})
target_link_libraries(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
add_definitions(-DLIB_EXPORTS)
install(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION bin)
install(FILES   ${LIBANTIMONY_HEADERS} DESTINATION include)

if (NOT UNIX)
  add_definitions(-DWIN32 -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)
  if (WITH_PYTHON)
     INSTALL(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION bindings/python/antimony )
  endif()
endif(NOT UNIX)


####################################################################
#
# Build the bindings.
#

add_subdirectory(src/bindings)


####################################################################
#
# Build the various command-line executables
#

add_executable(rehashantimony ${ANTIMONY_SRC_DIR}rehashantimony.cpp)
add_dependencies(rehashantimony ${LIBANTIMONY_LIBRARY})
target_link_libraries(rehashantimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
install(TARGETS rehashantimony DESTINATION bin)

add_executable(testantimony ${ANTIMONY_SRC_DIR}testantimony.cpp)
add_dependencies(testantimony ${LIBANTIMONY_LIBRARY})
target_link_libraries(testantimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
install(TARGETS testantimony DESTINATION bin)

add_executable(sbtranslate ${ANTIMONY_SRC_DIR}sbtranslate.cpp)
add_dependencies(sbtranslate ${LIBANTIMONY_LIBRARY})
target_link_libraries(sbtranslate ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
install(TARGETS sbtranslate DESTINATION bin)

if(WITH_SBML)
  add_executable(antimony2sbml ${ANTIMONY_SRC_DIR}antimony2sbml.cpp)
  add_dependencies(antimony2sbml ${LIBANTIMONY_LIBRARY})
  target_link_libraries(antimony2sbml ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  install(TARGETS antimony2sbml DESTINATION bin)

  add_executable(sbml2antimony ${ANTIMONY_SRC_DIR}sbml2antimony.cpp)
  add_dependencies(sbml2antimony ${LIBANTIMONY_LIBRARY})
  target_link_libraries(sbml2antimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  install(TARGETS sbml2antimony DESTINATION bin)
endif(WITH_SBML)

if(WITH_CELLML)
  add_executable(antimony2cellml ${ANTIMONY_SRC_DIR}antimony2cellml.cpp)
  add_dependencies(antimony2cellml ${LIBANTIMONY_LIBRARY})
  target_link_libraries(antimony2cellml ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  install(TARGETS antimony2cellml DESTINATION bin)

  add_executable(cellml2antimony ${ANTIMONY_SRC_DIR}cellml2antimony.cpp)
  add_dependencies(cellml2antimony ${LIBANTIMONY_LIBRARY})
  target_link_libraries(cellml2antimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  install(TARGETS cellml2antimony DESTINATION bin)
endif(WITH_CELLML)

####################################################################
#
# Build QT Antimony
#

set (QTANTIMONY_SRC_DIR QTAntimony_src/)

file(GLOB QTANTIMONY_SOURCES
        ${QTANTIMONY_SRC_DIR}AntimonyTab.cpp
        ${QTANTIMONY_SRC_DIR}CellMLTab.cpp
        ${QTANTIMONY_SRC_DIR}ChangeableTextBox.cpp
        ${QTANTIMONY_SRC_DIR}CopyMessageBox.cpp
        ${QTANTIMONY_SRC_DIR}FileWatcher.cpp
        ${QTANTIMONY_SRC_DIR}main.cpp
        ${QTANTIMONY_SRC_DIR}QTAntimony.cpp
        ${QTANTIMONY_SRC_DIR}SBMLTab.cpp
        ${QTANTIMONY_SRC_DIR}SBWIntegration.cpp
        ${QTANTIMONY_SRC_DIR}TabManager.cpp
        ${QTANTIMONY_SRC_DIR}Translator.cpp
        ${QTANTIMONY_SRC_DIR}Tutorial.cpp
        )

file(GLOB QTANTIMONY_HEADERS
        ${QTANTIMONY_SRC_DIR}AntimonyTab.h
        ${QTANTIMONY_SRC_DIR}CellMLTab.h
        ${QTANTIMONY_SRC_DIR}ChangeableTextBox.h
        ${QTANTIMONY_SRC_DIR}CopyMessageBox.h
        ${QTANTIMONY_SRC_DIR}FileWatcher.h
        ${QTANTIMONY_SRC_DIR}QTAntimony.h
        ${QTANTIMONY_SRC_DIR}resource.h
        ${QTANTIMONY_SRC_DIR}SBMLTab.h
        ${QTANTIMONY_SRC_DIR}SBWIntegration.h
        ${QTANTIMONY_SRC_DIR}Settings.h
        ${QTANTIMONY_SRC_DIR}TabManager.h
        ${QTANTIMONY_SRC_DIR}Translator.h
        ${QTANTIMONY_SRC_DIR}Tutorial.h
        )

file(GLOB QTANTIMONY_RESOURCE
        ${QTANTIMONY_SRC_DIR}antimonyicon.rc
        )
if (WITH_QTANTIMONY)
        find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED )
        include(${QT_USE_FILE})
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${ANTIMONY_SRC_DIR} ${QT_INCLUDES})
        QT4_WRAP_CPP(QTANTIMONY_MOC_SRCS ${QTANTIMONY_HEADERS})
        QT4_ADD_RESOURCES(RC_SRC_FILES ${QTANTIMONY_SRC_DIR}antimony.qrc )
        source_group(MOC_sources FILES ${QTANTIMONY_MOC_SRCS})
        if (WIN32)
           link_libraries(${QT_QTMAIN_LIBRARY})
        endif(WIN32)
        set( MACOSX_BUNDLE_ICON_FILE antimony.icns )
        set (QTANTIMONY_LIBRARIES ${QT_LIBRARIES} ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS} )
        if (WITH_SBW)
           set(SBW_DEFINITIONS "-DSBW_INTEGRATION" )
           find_library(SBW_LIBRARY 
		NAMES libsbw.lib sbw.lib libsbw.so libsbw sbw
		PATHS /usr/lib /usr/local/lib 
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
                          ${CMAKE_SOURCE_DIR}/../SBW/install/lib
                          )
           set(QTANTIMONY_LIBRARIES ${QTANTIMONY_LIBRARIES} ${SBW_LIBRARY} )
	
	   find_path(SBW_INCLUDE_DIR
		NAMES SBW/config.h
		PATHS /usr/include /usr/local/include 
			  ${CMAKE_SOURCE_DIR}/include 
			  ${CMAKE_SOURCE_DIR}/dependencies/include
                          ${CMAKE_SOURCE_DIR}/../SBW/install/include/
			  )
           INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${SBW_INCLUDE_DIR})

        endif(WITH_SBW)
        add_executable(QTAntimony WIN32 MACOSX_BUNDLE ${QTANTIMONY_SOURCES} ${QTANTIMONY_MOC_SRCS} ${QTANTIMONY_HEADERS} ${QTANTIMONY_RESOURCE})
        target_link_libraries(QTAntimony ${QTANTIMONY_LIBRARIES} )
        add_definitions(${QT_DEFINITIONS} ${SBW_DEFINITIONS})
        set(MACOSX_BUNDLE_ICON_FILE ${QTANTIMONY_SRC_DIR}antimony.icns)
        install(TARGETS QTAntimony DESTINATION bin)
        install(FILES ${QTANTIMONY_SRC_DIR}antimony.ico DESTINATION bin)

endif(WITH_QTANTIMONY)


####################################################################
#
# Set up remaining variables, add option for universal binaries
#
if(UNIX)
    if(APPLE)
		add_definitions(-DMACOSX)
		#create universal binaries
                option(ENABLE_UNIVERSAL "Create Universal Binaries" OFF)
                
                set(CMAKE_OSX_ARCHITECTURES "${CMAKE_OSX_ARCHITECTURES}" CACHE STRING "A semicolon separated list of build architectures to be used")
                if(ENABLE_UNIVERSAL)
                  # if universal binaries are requested and none defined so far
                  # overwrite them with all three common architectures. If the user 
                  # specified their own list of architectures do not touch!
                  if (CMAKE_OSX_ARCHITECTURES STREQUAL "")                        
                    set(CMAKE_OSX_ARCHITECTURES "i386;ppc;x86_64" CACHE STRING "A semicolon separated list of build architectures to be used" FORCE)                
                  endif()
                endif(ENABLE_UNIVERSAL)
    else(APPLE)
		add_definitions(-DLINUX)
    endif(APPLE)
   # add_definitions( -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME="${PROJECT_NAME}")

else(UNIX)
	add_definitions(-DWIN32 -DLIBANTIMONY_EXPORTS -DLIBLAX_EXPORTS)
	if(MSVC)
	  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	  option(WITH_STATIC_RUNTIME "Compile using the static MSVC Runtime" OFF)
	  if (WITH_STATIC_RUNTIME)
		foreach(flag_var
			CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
			CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
		
			if(${flag_var} MATCHES "/MD")
					string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
			endif(${flag_var} MATCHES "/MD")
		endforeach(flag_var)
		add_definitions( -D_MT)
	  endif(WITH_STATIC_RUNTIME)
	endif(MSVC)
	
	
endif(UNIX)

if (WITH_SBW_TRANSLATOR)
  
    find_library(LIBSBW_LIBRARY 
		NAMES libsbw.lib sbw.lib libsbw.so libsbw sbw
		PATHS /usr/lib /usr/local/lib 
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${CMAKE_SOURCE_DIR}/../libsbml-5/build/src/RelWithDebInfo
    )
    find_path(SBW_INCLUDE_DIR
		NAMES SBW/config.h
		PATHS /usr/include /usr/local/include 
			  ${CMAKE_SOURCE_DIR}/include 
			  ${CMAKE_SOURCE_DIR}/dependencies/include
              ${CMAKE_SOURCE_DIR}/../SBW/include/
    )
  INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${SBW_INCLUDE_DIR})

  if(MSVC)
    set_target_properties(sbwantimony PROPERTIES LINK_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")
    #set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /ENTRY:mainCRTStartup")  
  endif()
  add_executable(sbwantimony WIN32 ${ANTIMONY_SRC_DIR}sbwtranslator.cpp)
  add_dependencies(sbwantimony ${LIBANTIMONY_LIBRARY})
  target_link_libraries(sbwantimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS} ${LIBSBW_LIBRARY})  
  install(TARGETS sbwantimony DESTINATION bin)
  
endif()


###############################################################################
#
# Install win32 dependencies
# 
if (NOT UNIX)
  file(GLOB win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll" "${CMAKE_CURRENT_SOURCE_DIR}/win32/README.txt")
  install(FILES ${win_dependencies} DESTINATION bin/)
endif()

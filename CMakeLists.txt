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
SET(LIBANTIMONY_VERSION_MAJOR 1)
SET(LIBANTIMONY_VERSION_MINOR 4)
SET(LIBANTIMONY_VERSION_PATCH "")
SET(LIBANTIMONY_VERSION_RELEASE "")

SET(VERSION_STRING "${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")
add_definitions( -DVERSION_STRING="${VERSION_STRING}" )


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
INCLUDE(CPack)

option(BUILD_SHARED_LIBS  "Build shared library (Set to OFF to build static libraries)" ON)
set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel" FORCE )


####################################################################
#
# Here we have the main configuration options for libantimony
#

# which language bindings should be build
option(WITH_SBML     "Generate SBML translations"     ON )
option(WITH_CELLML   "Generate CellML translations"   OFF )
option(CREATE_QTANTIMONY       "Generate QTAntimony"   ON )

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

	find_path(LIBSBML_DEPENDENCIES_INCLUDE_DIR
		NAMES libxml/parser.h 
		PATHS /usr/include /usr/local/include 
                      'C:/Program Files (x86)/SBML/libSBML-4.2.0-libxml2-x86/win32/include'
			  /usr/include/libxml2
			  /usr/local/include/libxml2
			  ${CMAKE_SOURCE_DIR}/include 
			  ${CMAKE_SOURCE_DIR}/dependencies/include
			  )		

        set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBSBML_LIBRARY} )
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${LIBSBML_INCLUDE_DIR})
else(WITH_SBML)
    add_definitions( -DNSBML )
endif(WITH_SBML)

####################################################################
#
# Locate the CellML API and attendant libraries if needed
#

if(WITH_CELLML)
        #CellML:
        find_path(CELLML_API_ROOT_DIR
		NAMES sources/Utilities.hxx
		PATHS /usr/include /usr/local/include 
                          C:/build/cellml-api/
			  ${CMAKE_SOURCE_DIR}/include 
			  ${CMAKE_SOURCE_DIR}/dependencies/include
			  )

        find_library(CELLML_API 
		NAMES cellml.lib cellml
		PATHS /usr/lib /usr/local/lib
                          ${CELLML_API_ROOT_DIR}/.libs
                          C:/build/cellml-api/.libs/
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
			    )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CELLML_API})

        find_library(CEVAS_LIB 
		NAMES cevas.lib cevas
		PATHS /usr/lib /usr/local/lib
                          ${CELLML_API_ROOT_DIR}/.libs
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
			    )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CEVAS_LIB})
	
	find_library(CUSES_LIB 
		NAMES cuses.lib cuses
		PATHS /usr/lib /usr/local/lib
                          ${CELLML_API_ROOT_DIR}/.libs
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
			    )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${CUSES_LIB})

        find_library(TELICEMS_LIB 
		NAMES telicems.lib telicems
		PATHS /usr/lib /usr/local/lib
                          ${CELLML_API_ROOT_DIR}/.libs
			  ${CMAKE_SOURCE_DIR} 
			  ${CMAKE_SOURCE_DIR}/dependencies/lib
			    )
        set(ALL_CELLML_LIBS ${ALL_CELLML_LIBS} ${TELICEMS_LIB})

        set(CELLML_INCLUDE_DIRECTORIES ${CELLML_API_ROOT_DIR} ${CELLML_API_ROOT_DIR}/sources ${CELLML_API_ROOT_DIR}/sources/cellml/ ${CELLML_API_ROOT_DIR}/interfaces ${CELLML_API_ROOT_DIR}/TeLICeMS/sources/ ${CELLML_API_ROOT_DIR}/CUSES/sources/ ${CELLML_API_ROOT_DIR}/CeVAS/sources/ )

        set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${ALL_CELLML_LIBS} )
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${CELLML_INCLUDE_DIRECTORIES} )

else(WITH_CELLML)
  add_definitions( -DNCELLML )

endif(WITH_CELLML)

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
	${ANTIMONY_SRC_DIR}Antimony.cpp
	${ANTIMONY_SRC_DIR}antimony.tab.cpp
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
	${ANTIMONY_SRC_DIR}userfunction.cpp
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
        ${ANTIMONY_SRC_DIR}antimony_api.h
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
	${ANTIMONY_SRC_DIR}userfunction.h
	${ANTIMONY_SRC_DIR}variable.h
        )
 
add_library(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_HEADERS} ${LIBANTIMONY_SOURCES} ${LIBANTIMONY_TRANSLATORS})
target_link_libraries(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
add_definitions(-DLIB_EXPORTS)

if (NOT UNIX)
  add_definitions(-DWIN32 -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)
endif(NOT UNIX)
####################################################################
#
# Build the various command-line executables
#

add_executable(rehashantimony ${ANTIMONY_SRC_DIR}rehashantimony.cpp)
add_executable(testantimony ${ANTIMONY_SRC_DIR}testantimony.cpp)
add_dependencies(rehashantimony ${LIBANTIMONY_LIBRARY})
add_dependencies(testantimony ${LIBANTIMONY_LIBRARY})
target_link_libraries(rehashantimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
target_link_libraries(testantimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})

if(WITH_SBML)
  add_executable(antimony2sbml ${ANTIMONY_SRC_DIR}antimony2sbml.cpp)
  add_executable(sbml2antimony ${ANTIMONY_SRC_DIR}sbml2antimony.cpp)
  add_dependencies(antimony2sbml ${LIBANTIMONY_LIBRARY})
  add_dependencies(sbml2antimony ${LIBANTIMONY_LIBRARY})
  target_link_libraries(antimony2sbml ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  target_link_libraries(sbml2antimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
endif(WITH_SBML)

if(WITH_CELLML)
  add_executable(antimony2cellml ${ANTIMONY_SRC_DIR}antimony2cellml.cpp)
  add_executable(cellml2antimony ${ANTIMONY_SRC_DIR}cellml2antimony.cpp)
  add_dependencies(antimony2cellml ${LIBANTIMONY_LIBRARY})
  add_dependencies(cellml2antimony ${LIBANTIMONY_LIBRARY})
  target_link_libraries(antimony2cellml ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
  target_link_libraries(cellml2antimony ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
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
        ${QTANTIMONY_SRC_DIR}SBMLTab.h
        ${QTANTIMONY_SRC_DIR}SBWIntegration.h
        ${QTANTIMONY_SRC_DIR}Settings.h
        ${QTANTIMONY_SRC_DIR}TabManager.h
        ${QTANTIMONY_SRC_DIR}Translator.h
        ${QTANTIMONY_SRC_DIR}Tutorial.h
        )

if (CREATE_QTANTIMONY)
        find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED )
        include(${QT_USE_FILE})
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${ANTIMONY_SRC_DIR} ${QT_INCLUDES})
        QT4_WRAP_CPP(QTANTIMONY_MOC_SRCS ${QTANTIMONY_HEADERS})
        source_group(MOC_sources FILES ${QTANTIMONY_MOC_SRCS})
        add_executable(QTAntimony ${QTANTIMONY_SOURCES} ${QTANTIMONY_MOC_SRCS} ${QTANTIMONY_HEADERS})
        add_dependencies(QTAntimony ${LIBANTIMONY_LIBRARY})
        target_link_libraries(QTAntimony ${QT_LIBRARIES} ${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS} ${LIBANTIMONY_LIBS})
        add_definitions(${QT_DEFINITIONS})
        set(MACOSX_BUNDLE_ICON_FILE ${QTANTIMONY_SRC_DIR}antimony.icns)

endif(CREATE_QTANTIMONY)


####################################################################
#
# Set up remaining variables, add option for universal binaries
#
if(UNIX)
    if(APPLE)
		add_definitions(-DMACOSX)
		#create universal binaries
		option(ENABLE_UNIVERSAL "Create Universal Binaries" ON)
		if(ENABLE_UNIVERSAL)
			set(CMAKE_OSX_ARCHITECTURES "ppc" "i386" "x86_64")
		endif(ENABLE_UNIVERSAL)
    else(APPLE)
		add_definitions(-DLINUX)
    endif(APPLE)
    add_definitions( -DPACKAGE_VERSION=\"${PACKAGE_VERSION}\"  -DPACKAGE_NAME="${PROJECT_NAME}")

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
	
	file(GLOB WIN32_BINARIES ${CMAKE_SOURCE_DIR}/dependencies/bin/*.dll)
	INSTALL(FILES ${WIN32_BINARIES} DESTINATION bin)
	
endif(UNIX)

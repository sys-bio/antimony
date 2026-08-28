####################################################################
#
# CMake Build Script for libantimony
#

cmake_minimum_required(VERSION 3.0...4.0)
project(libantimony)

####################################################################
#
# Set up version information.
#
SET(LIBANTIMONY_VERSION_MAJOR 3)
SET(LIBANTIMONY_VERSION_MINOR 2)
SET(LIBANTIMONY_VERSION_PATCH ".0")
SET(LIBANTIMONY_VERSION_RELEASE "")


####################################################################
#
# the next lines configure the parameters for packaging the binaries
# they can be invoked with: make package / nmake package or by using
# cpack -G zip|deb|rpm|dmg|nsis
#

if(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

#Using 'tuple':
# C++14 minimum: required by the vendored GoogleTest 1.16.x (see
# src/test/googletest/README.md), which uses std::make_index_sequence
# and friends internally.
# MSVC doesn't understand the GNU-style -std= flag (and already
# defaults to a sufficiently modern standard), so only add it for
# GCC/Clang to avoid a D9002 "unknown option" warning on every file.
if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()

include (InstallRequiredSystemLibraries)
include (CMakeTestCCompiler)
include (CheckCSourceCompiles)
include (CheckCXXSourceCompiles)
include (CheckStructHasMember)
include (CheckLibraryExists)
include (CheckFunctionExists)
include (CheckCCompilerFlag)
include (CheckCSourceRuns)
include (CheckSymbolExists)
include (CheckTypeSize)

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "An API library for reading, writing, manipulating, and translating Antimony models")
SET(CPACK_PACKAGE_NAME "libAntimony")
SET(CPACK_PACKAGE_VENDOR "Lucian Smith")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "${LIBANTIMONY_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${LIBANTIMONY_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${LIBANTIMONY_VERSION_PATCH}")
SET(CPACK_PACKAGE_VERSION_RELEASE "${LIBANTIMONY_VERSION_RELEASE}")
INCLUDE(CPack)

SET(LIBANTIMONY_VERSION_STRING "v${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")

# Bare version (no leading 'v'), written to a file so tooling outside of
# CMake itself -- e.g. the GitHub Actions step that packages
# win32/antimonyInstaller.iss via 'iscc /DMyAppVersion=...' -- can pick up
# the current version without parsing this file.
SET(LIBANTIMONY_VERSION_STRING_BARE "${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")
file(WRITE "${CMAKE_BINARY_DIR}/antimony_version.txt" "${LIBANTIMONY_VERSION_STRING_BARE}")


option(BUILD_SHARED_LIBS  "Build shared library (Set to OFF to build static libraries)" ON)
set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel" )

#Turn off:  could never get universal binaries to work.
#set(USE_UNIVERSAL_BINARIES "ON" CACHE BOOL "Build and link to universal binaries on MacOS")

#if (USE_UNIVERSAL_BINARIES)
#    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE INTERNAL "Compile for intel and M1 chips on apple" FORCE)
#    message(STATUS "building on mac with universal binaries")
#endif()

####################################################################
#
# Here we have the main configuration options for libantimony
#

# which language bindings should be build
option(WITH_CELLML          "Generate CellML translations"    OFF )
mark_as_advanced(WITH_CELLML)
if(WITH_CELLML)
  message(FATAL_ERROR "The ability to export Antimony to CellML is not currently functional.")
endif()
option(WITH_QTANTIMONY      "Generate QTAntimony"             ON )
option(WITH_PYTHON       "Generate Python language bindings." OFF)
if (WITH_PYTHON)
  option(PYTHON_SYSTEM_INSTALL  "Install the python bindings using setup.py and distutils.  May require admin privileges."    OFF )
  option(PYTHON_LOCAL_INSTALL   "Install the python bindings in ${CMAKE_INSTALL_PREFIX}/bindings/python/.  Can be installed later via 'setup.py'."    ON )
  option(WITH_CONDA_BUILDER     "Install files required to build Anaconda packages"  OFF)
endif()
option(INSTALL_SYSTEM_RUNTIMES "Install system runtime libraries (e.g. MSVC runtimes)")

set(EXTRA_LIBS "" CACHE STRING "Libraries the other libraries depend on that are in non-standard locations" )
#set(EXTRA_LIBS "" CACHE_STRING "")

set(ANT_DEPENDENCIES_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/dependencies"
        CACHE PATH "Path to dependencies install"
        )


# Enable the generation of unit tests. If enabled, all test runners
# will be created and can be run with "make test" or ctest.
# This won't work in Visual Studio 2003, so we disable this option there.
#
if(NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 6" AND NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
    option(WITH_GTEST    "Compile unit tests. Run with 'make test' or 'ctest'." OFF)
endif()

#Create antimony_api.h from antimony_api.h.in
set(ANTIMONY_API_IN "${CMAKE_CURRENT_SOURCE_DIR}/src/antimony_api.h.in")
set(ANTIMONY_API    "${CMAKE_CURRENT_BINARY_DIR}/antimony_api.h")

configure_file(${ANTIMONY_API_IN} ${ANTIMONY_API} @ONLY)

# Generated antimony_api.h lands in the build dir, not src/, so every target
# built from this CMakeLists.txt (library, static library, executables) needs
# the build dir on its include path. In turn, the generated antimony_api.h 
# file needs libutil.h and enums.h, which are no longer in the same directory.
include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)




add_definitions( -DLIBANTIMONY_VERSION_STRING="${LIBANTIMONY_VERSION_STRING}" )

set(RR_ROOT "${CMAKE_CURRENT_SOURCE_DIR}")
set(DEPENDENCY_CMAKE_CONFIG_PATHS
        "${ANT_DEPENDENCIES_INSTALL_PREFIX}/cmake"
        "${ANT_DEPENDENCIES_INSTALL_PREFIX}/lib/cmake"
        "${ANT_DEPENDENCIES_INSTALL_PREFIX}/lib/cmake/Poco"
        "${ANT_DEPENDENCIES_INSTALL_PREFIX}/lib64/cmake"
        "${ANT_DEPENDENCIES_INSTALL_PREFIX}/lib64/cmake/Poco"
        )
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "${DEPENDENCY_CMAKE_CONFIG_PATHS}")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${DEPENDENCY_CMAKE_CONFIG_PATHS}")
message(STATUS "CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}")
if (WIN32)
    set(SBML_TARGET_NAME "libsbml-static")
else ()
    set(SBML_TARGET_NAME "sbml-static")
endif (WIN32)

####################################################################
#
# Locate libsbml if needed
#

if (NOT DEFINED EXPAT_LIBRARY OR NOT DEFINED EXPAT_INCLUDE_DIR)
    find_package(expat CONFIG REQUIRED)

    set(EXPAT_LIBRARY "expat::expat")
    get_target_property(EXPAT_INCLUDE_DIR expat::expat INTERFACE_INCLUDE_DIRECTORIES)
    get_target_property(EXPAT_LIBRARY expat::expat LOCATION)
    message(STATUS "EXPAT_LIBRARY: ${EXPAT_LIBRARY}")
    set(EXPAT_INCLUDE_DIR "${ANT_DEPENDENCIES_INSTALL_PREFIX}/include/")
endif()

if (NOT DEFINED LIBSBML_INCLUDE_DIR)
    set(LIBSBML_INCLUDE_DIR "${ANT_DEPENDENCIES_INSTALL_PREFIX}/include/")
endif()

if (NOT DEFINED LIBSBML_LIBRARY)
    find_package(${SBML_TARGET_NAME} CONFIG REQUIRED)
    set(LIBSBML_LIBRARY ${SBML_TARGET_NAME})
endif()

set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBSBML_LIBRARY} ${LIBSBML_LIBRARIES} )
INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${LIBSBML_INCLUDE_DIR} ${EXPAT_INCLUDE_DIR})

####################################################################
#
# Antimony has required libSBML's 'comp' (Hierarchical Model Composition)
# package since v2.1, back when 'comp' was optional and libsbml had to be
# specially built with it. It's now a standard part of libsbml, so instead
# of tracking that with our own WITH_COMP_SBML flag (which could drift out
# of sync with what libsbml itself was actually built with), ask libsbml
# directly: its own build writes LIBSBML_HAS_PACKAGE_COMP into
# sbml/common/libsbml-config-packages.h when 'comp' is enabled. If it's
# missing, fail configure now with a clear message rather than failing
# later with confusing compile errors deep in module-sbml.cpp.
#

set(CMAKE_REQUIRED_INCLUDES ${LIBSBML_INCLUDE_DIR})
check_cxx_source_compiles(
"#include <sbml/common/libsbml-config-packages.h>
#ifndef LIBSBML_HAS_PACKAGE_COMP
#error libsbml was not compiled with the comp package
#endif
int main() { return 0; }
"
    LIBSBML_HAS_COMP_PACKAGE)
unset(CMAKE_REQUIRED_INCLUDES)

if (NOT LIBSBML_HAS_COMP_PACKAGE)
    message(FATAL_ERROR
"The libSBML found at '${LIBSBML_INCLUDE_DIR}' was not compiled with the "
"'comp' (Hierarchical Model Composition) package, which antimony requires. "
"Please rebuild/reinstall libSBML with -DENABLE_COMP=ON (or "
"-DWITH_STABLE_PACKAGES=ON).")
endif()

####################################################################
#
# Locate the CellML API and attendant libraries if needed
#

if(WITH_CELLML)
        #CellML:
        find_path(CELLML_API_INSTALL_DIR
        NAMES include/IfaceCellML_APISPEC.hxx
        PATHS /usr/include /usr/local/include
              "C:/Program Files (x86)/cellml-sdk-1.11"
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

find_library(SBMLNETWORK_LIBRARY
    NAMES libsbmlnetwork-static.lib sbmlnetwork-static.lib libsbmlnetwork-static sbmlnetwork-static libsbmlnetwork-staticmdd libsbmlnetwork-staticmd libsbmlnetwork-staticd libsbmlnetwork-staticd.a
    PATHS /usr/lib /usr/local/lib
          ${ANT_DEPENDENCIES_INSTALL_PREFIX}
          ${CMAKE_SOURCE_DIR}
          ${CMAKE_SOURCE_DIR}/dependencies/lib
          ${LIBSBML_INCLUDE_DIR}/../lib
    )
set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${SBMLNETWORK_LIBRARY} )

find_path(SBMLNETWORK_INCLUDE_DIR
    NAMES sbmlnetwork/libsbmlnetwork_common.h
    PATHS /usr/include /usr/local/include ${ANT_DEPENDENCIES_INSTALL_PREFIX}/include
    DOC "The directory containing the SBMLNetwork include files."
          )

INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${SBMLNETWORK_INCLUDE_DIR} )
# SBMLNETWORK uses stuff from the 'dl' library on some platforms.  CMake defines CMAKE_DL_LIBS if so.
set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${CMAKE_DL_LIBS} )

message(STATUS "Antimony libs: ${LIBANTIMONY_LIBS}")

if(WITH_PYTHON)
    message(STATUS "  Using Python                  = ${PYTHON_EXECUTABLE}")
endif()

#message(STATUS "libantimony libs: ${LIBANTIMONY_LIBS}")
set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${EXTRA_LIBS})

# Cheap insurance against duplicate entries.
list(REMOVE_DUPLICATES LIBANTIMONY_LIBS)

###############################################################################
## Enable support for testing ... can be invoked by running ctest
# or make test
#

if(WITH_GTEST)

    # set test timeout to 3000 as the normal time limit is not sufficient
    # for the comp tests
    SET(DART_TESTING_TIMEOUT "3000" CACHE STRING "" FORCE)

    enable_testing()

    # Needed at the top level (before add_subdirectory(src/test)) so that
    # gtest_discover_tests is available to the test CMakeLists.txt files.
    include(GoogleTest)

    if (UNIX)
        # Set up valgrind for `ctest -T memcheck`.
        find_program(MEMORYCHECK_COMMAND valgrind)
        set(MEMORYCHECK_TYPE "Valgrind")
        set(MEMORYCHECK_COMMAND_OPTIONS
           "--error-exitcode=1 --trace-children=yes --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --error-limit=no")
        set(MEMORYCHECK_SUPPRESSIONS_FILE "${CMAKE_SOURCE_DIR}/valgrind.supp")
    endif(UNIX)

    include(CTest)

endif(WITH_GTEST)


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


set(CMAKE_INSTALL_LIBDIR lib CACHE PATH "Full path to the library output directory")
mark_as_advanced(CMAKE_INSTALL_LIBDIR)



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
    ${ANTIMONY_SRC_DIR}constraint.cpp
    ${ANTIMONY_SRC_DIR}dnastrand.cpp
    ${ANTIMONY_SRC_DIR}event.cpp
    ${ANTIMONY_SRC_DIR}formula.cpp
    ${ANTIMONY_SRC_DIR}kineticLawWrapper.cpp
    ${ANTIMONY_SRC_DIR}layoutWrapper.cpp
    ${ANTIMONY_SRC_DIR}module.cpp
    ${ANTIMONY_SRC_DIR}reactantlist.cpp
    ${ANTIMONY_SRC_DIR}reaction.cpp
    ${ANTIMONY_SRC_DIR}registry.cpp
    ${ANTIMONY_SRC_DIR}sbmlx.cpp
    ${ANTIMONY_SRC_DIR}sboTermWrapper.cpp
    ${ANTIMONY_SRC_DIR}stringx.cpp
    ${ANTIMONY_SRC_DIR}typex.cpp
    ${ANTIMONY_SRC_DIR}unitdef.cpp
    ${ANTIMONY_SRC_DIR}unitelement.cpp
    ${ANTIMONY_SRC_DIR}userfunction.cpp
    ${ANTIMONY_SRC_DIR}uncertWrapper.cpp
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
        ${ANTIMONY_API}
        ${ANTIMONY_SRC_DIR}antimony_api_cpp.h
        ${ANTIMONY_SRC_DIR}cellmlx.h
        ${ANTIMONY_SRC_DIR}constraint.h
        ${ANTIMONY_SRC_DIR}dnastrand.h
        ${ANTIMONY_SRC_DIR}enums.h
        ${ANTIMONY_SRC_DIR}event.h
        ${ANTIMONY_SRC_DIR}formula.h
        ${ANTIMONY_SRC_DIR}kineticLawWrapper.h
        ${ANTIMONY_SRC_DIR}layoutWrapper.h
        ${ANTIMONY_SRC_DIR}libutil.h
        ${ANTIMONY_SRC_DIR}module.h
        ${ANTIMONY_SRC_DIR}reactantlist.h
        ${ANTIMONY_SRC_DIR}reaction.h
        ${ANTIMONY_SRC_DIR}registry.h
        ${ANTIMONY_SRC_DIR}sbmlx.h
        ${ANTIMONY_SRC_DIR}sboTermWrapper.h
        ${ANTIMONY_SRC_DIR}stringx.h
        ${ANTIMONY_SRC_DIR}typex.h
        ${ANTIMONY_SRC_DIR}uncertWrapper.h
        ${ANTIMONY_SRC_DIR}unitdef.h
        ${ANTIMONY_SRC_DIR}unitelement.h
        ${ANTIMONY_SRC_DIR}userfunction.h
        ${ANTIMONY_SRC_DIR}unitdef.h
        ${ANTIMONY_SRC_DIR}unitelement.h
        ${ANTIMONY_SRC_DIR}variable.h
        )

##### Build the main library #####
add_library(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_HEADERS} ${LIBANTIMONY_SOURCES} ${LIBANTIMONY_TRANSLATORS})
target_link_libraries(${LIBANTIMONY_LIBRARY} ${LIBANTIMONY_LIBS})
add_definitions(-DLIB_EXPORTS)
install(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION lib)
install(FILES   ${LIBANTIMONY_HEADERS} DESTINATION include)

if (NOT UNIX)
  add_definitions(-DWIN32 -DLIBSBML_EXPORTS -DLIBLAX_EXPORTS)
endif(NOT UNIX)

# Can't put this in bindings/python/CMakeLists pre-CMake 3.13.
if (PYTHON_SYSTEM_INSTALL)
   install(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/antimony/)
endif()

#set(PYTHON_PACKAGE_INSTALL_DIR "${CMAKE_INSTALL_PREFIX}/bindings/python")
set(PYTHON_PACKAGE_INSTALL_DIR "bindings/python")
if (PYTHON_LOCAL_INSTALL)
   install(TARGETS ${LIBANTIMONY_LIBRARY}  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony)
endif()


##### Build the static library #####
add_library (${LIBANTIMONY_LIBRARY}-static STATIC ${LIBANTIMONY_SOURCES} ${LIBANTIMONY_HEADERS} ${LIBANTIMONY_TRANSLATORS})

if (WIN32 AND NOT CYGWIN)
    # don't decorate static library
    set_target_properties(${LIBANTIMONY_LIBRARY}-static PROPERTIES COMPILE_DEFINITIONS "LIBLAX_STATIC=1;LIBSBML_STATIC=1;LIBANTIMONY_STATIC=1")
endif(WIN32 AND NOT CYGWIN)

target_link_libraries(${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})

INSTALL(TARGETS ${LIBANTIMONY_LIBRARY}-static
        DESTINATION lib
  )



####################################################################
#
# Build the bindings.
#

add_subdirectory(src/bindings)



####################################################################
#
# Build the test libraries.
#

if(WITH_GTEST)
    message(STATUS "  Using vendored GoogleTest      = ${CMAKE_CURRENT_SOURCE_DIR}/src/test/googletest")
    add_subdirectory(src/test)
endif()



####################################################################
#
# Build the various command-line executables
#

add_executable(rehashantimony ${ANTIMONY_SRC_DIR}rehashantimony.cpp)
add_dependencies(rehashantimony ${LIBANTIMONY_LIBRARY}-static)
target_link_libraries(rehashantimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
install(TARGETS rehashantimony DESTINATION bin)

add_executable(testantimony ${ANTIMONY_SRC_DIR}testantimony.cpp)
add_dependencies(testantimony ${LIBANTIMONY_LIBRARY}-static)
target_link_libraries(testantimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
install(TARGETS testantimony DESTINATION bin)

add_executable(sbtranslate ${ANTIMONY_SRC_DIR}sbtranslate.cpp)
add_dependencies(sbtranslate ${LIBANTIMONY_LIBRARY}-static)
target_link_libraries(sbtranslate ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
install(TARGETS sbtranslate DESTINATION bin)

add_executable(antimony2sbml ${ANTIMONY_SRC_DIR}antimony2sbml.cpp)
add_dependencies(antimony2sbml ${LIBANTIMONY_LIBRARY}-static)
target_link_libraries(antimony2sbml ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
install(TARGETS antimony2sbml DESTINATION bin)

add_executable(sbml2antimony ${ANTIMONY_SRC_DIR}sbml2antimony.cpp)
add_dependencies(sbml2antimony ${LIBANTIMONY_LIBRARY}-static)
target_link_libraries(sbml2antimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
install(TARGETS sbml2antimony DESTINATION bin)

if(WITH_CELLML)
  add_executable(antimony2cellml ${ANTIMONY_SRC_DIR}antimony2cellml.cpp)
  add_dependencies(antimony2cellml ${LIBANTIMONY_LIBRARY}-static)
  target_link_libraries(antimony2cellml ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
  install(TARGETS antimony2cellml DESTINATION bin)

  add_executable(cellml2antimony ${ANTIMONY_SRC_DIR}cellml2antimony.cpp)
  add_dependencies(cellml2antimony ${LIBANTIMONY_LIBRARY}-static)
  target_link_libraries(cellml2antimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
  install(TARGETS cellml2antimony DESTINATION bin)
endif(WITH_CELLML)

####################################################################
#
# Build QT Antimony
#

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (QTANTIMONY_SRC_DIR QTAntimony_src/)
set (QTANTIMONY_DIALOG_DIR QTAntimony_src/qtfindreplacedialog-1.1/dialogs/)

file(GLOB QTANTIMONY_SOURCES
        ${QTANTIMONY_SRC_DIR}AntimonyTab.cpp
        ${QTANTIMONY_SRC_DIR}CellMLTab.cpp
        ${QTANTIMONY_SRC_DIR}ChangeableTextBox.cpp
        ${QTANTIMONY_SRC_DIR}CopyMessageBox.cpp
        ${QTANTIMONY_SRC_DIR}FileWatcher.cpp
        ${QTANTIMONY_SRC_DIR}LineNumberArea.cpp
        ${QTANTIMONY_SRC_DIR}main.cpp
        ${QTANTIMONY_SRC_DIR}QTAntimony.cpp
        ${QTANTIMONY_SRC_DIR}SBMLTab.cpp
        ${QTANTIMONY_SRC_DIR}TabManager.cpp
        ${QTANTIMONY_SRC_DIR}Translator.cpp
        ${QTANTIMONY_SRC_DIR}Tutorial.cpp
        ${QTANTIMONY_SRC_DIR}GoToLineDialog.cpp
        ${QTANTIMONY_SRC_DIR}GoToLineForm.cpp
        ${QTANTIMONY_DIALOG_DIR}finddialog.cpp
        ${QTANTIMONY_DIALOG_DIR}findform.cpp
        ${QTANTIMONY_DIALOG_DIR}findreplacedialog.cpp
        ${QTANTIMONY_DIALOG_DIR}findreplaceform.cpp
        )

file(GLOB QTANTIMONY_HEADERS
        ${QTANTIMONY_SRC_DIR}AntimonyTab.h
        ${QTANTIMONY_SRC_DIR}CellMLTab.h
        ${QTANTIMONY_SRC_DIR}ChangeableTextBox.h
        ${QTANTIMONY_SRC_DIR}CopyMessageBox.h
        ${QTANTIMONY_SRC_DIR}FileWatcher.h
        ${QTANTIMONY_SRC_DIR}QTAntimony.h
        ${QTANTIMONY_SRC_DIR}LineNumberArea.h
        ${QTANTIMONY_SRC_DIR}resource.h
        ${QTANTIMONY_SRC_DIR}SBMLTab.h
        ${QTANTIMONY_SRC_DIR}Settings.h
        ${QTANTIMONY_SRC_DIR}TabManager.h
        ${QTANTIMONY_SRC_DIR}Translator.h
        ${QTANTIMONY_SRC_DIR}Tutorial.h
        ${QTANTIMONY_SRC_DIR}GoToLineDialog.h
        ${QTANTIMONY_SRC_DIR}GoToLineForm.h
        ${QTANTIMONY_DIALOG_DIR}finddialog.h
        ${QTANTIMONY_DIALOG_DIR}findform.h
        ${QTANTIMONY_DIALOG_DIR}findreplace_global.h
        ${QTANTIMONY_DIALOG_DIR}findreplacedialog.h
        ${QTANTIMONY_DIALOG_DIR}findreplaceform.h
        )

file(GLOB QTANTIMONY_FORMS
        ${QTANTIMONY_DIALOG_DIR}findreplacedialog.ui
        ${QTANTIMONY_DIALOG_DIR}findreplaceform.ui
        ${QTANTIMONY_SRC_DIR}GoToLineDialog.ui
        ${QTANTIMONY_SRC_DIR}GoToLineForm.ui
        )

file(GLOB QTANTIMONY_RESOURCES
        ${QTANTIMONY_SRC_DIR}antimonyicon.rc
        ${QTANTIMONY_SRC_DIR}antimony.qrc
        )

## https://stackoverflow.com/questions/32183975/how-to-print-all-the-properties-of-a-target-in-cmake/56738858#56738858
## https://stackoverflow.com/a/56738858/3743145

## Get all properties that cmake supports
execute_process(COMMAND cmake --help-property-list OUTPUT_VARIABLE CMAKE_PROPERTY_LIST)
## Convert command output into a CMake list
STRING(REGEX REPLACE ";" "\\\\;" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")
STRING(REGEX REPLACE "\n" ";" CMAKE_PROPERTY_LIST "${CMAKE_PROPERTY_LIST}")

list(REMOVE_DUPLICATES CMAKE_PROPERTY_LIST)

function(print_target_properties tgt)
    if(NOT TARGET ${tgt})
      message("There is no target named '${tgt}'")
      return()
    endif()

    foreach (prop ${CMAKE_PROPERTY_LIST})
        string(REPLACE "<CONFIG>" "${CMAKE_BUILD_TYPE}" prop ${prop})
        get_target_property(propval ${tgt} ${prop})
        if (propval)
            message ("${tgt} ${prop} = ${propval}")
        endif()
    endforeach(prop)
endfunction(print_target_properties)


if (WITH_QTANTIMONY)
        set(CMAKE_AUTOMOC ON)
        set(CMAKE_AUTORCC ON)
        set(CMAKE_AUTOUIC ON)

        cmake_policy(SET CMP0020 NEW)

        find_package(Qt5 COMPONENTS Widgets PrintSupport REQUIRED )
        INCLUDE_DIRECTORIES(${INCLUDE_DIRECTORIES} ${ANTIMONY_SRC_DIR} ${QTANTIMONY_SRC_DIR} ${QTANTIMONY_DIALOG_DIR} ${QT_INCLUDES})
        QT5_WRAP_CPP(QTANTIMONY_MOC_SRCS ${QTANTIMONY_HEADERS})
        QT5_ADD_RESOURCES(RC_SRC_FILES ${QTANTIMONY_SRC_DIR}antimony.qrc )
        QT_WRAP_UI(QTANTIMONY_FORMS_HEADERS ${QTANTIMONY_FORMS})
        source_group(MOC_sources FILES ${QTANTIMONY_MOC_SRCS})
        if (WIN32)
           link_libraries(${QT_QTMAIN_LIBRARY})
        endif(WIN32)
        set( MACOSX_BUNDLE_ICON_FILE antimony.icns )
        INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR})
        INCLUDE_DIRECTORIES(${QTANTIMONY_DIALOG_DIR})
        INCLUDE_DIRECTORIES(${Qt5PrintSupport_INCLUDE_DIRS})
        add_executable(QTAntimony WIN32 MACOSX_BUNDLE ${QTANTIMONY_SOURCES} ${QTANTIMONY_MOC_SRCS} ${QTANTIMONY_FORMS_HEADERS} ${QTANTIMONY_HEADERS} ${QTANTIMONY_RESOURCES})
        target_link_libraries(QTAntimony Qt5::Widgets Qt5::PrintSupport ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS} )
        add_definitions(${QT_DEFINITIONS})
        set(MACOSX_BUNDLE_ICON_FILE ${QTANTIMONY_SRC_DIR}antimony.icns)
        install(TARGETS QTAntimony DESTINATION bin)
        install(FILES ${QTANTIMONY_SRC_DIR}antimony.ico ${QTANTIMONY_SRC_DIR}antimony_ico.png DESTINATION bin)
        if (WIN32)
          install(FILES ${CMAKE_SOURCE_DIR}/win32/README.txt DESTINATION bin)
        endif (WIN32)

        set_target_properties(QTAntimony PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/QTAntimony/$<0:>")

        message(STATUS "QT dir: ${Qt5_DIR}")
        message(STATUS "Binary dir: ${CMAKE_BINARY_DIR}")
        message(STATUS "Runtime output dir: ${RUNTIME_OUTPUT_DIRECTORY}")
        message(STATUS "CMake install dir: ${CMAKE_INSTALL_PREFIX}")
        #print_target_properties(QTAntimony)
        if (WIN32)
           add_custom_command(TARGET QTAntimony POST_BUILD
                                     COMMAND dir
                                     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
                                     COMMENT "get directory contents.")
           add_custom_command(TARGET QTAntimony POST_BUILD
                                     COMMAND ${Qt5_DIR}/../../../bin/windeployqt.exe QTAntimony.exe
                                     WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/QTAntimony
                                     COMMENT "Running windeployqt on QTAntimony to copy DLLs.")
           install(CODE "execute_process(COMMAND ${Qt5_DIR}/../../../bin/windeployqt.exe ${CMAKE_INSTALL_PREFIX}/bin/QTAntimony.exe)")
        endif(WIN32)


endif(WITH_QTANTIMONY)


####################################################################
#
# Set up remaining variables, add option for universal binaries
#


if(NOT UNIX)
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


endif(NOT UNIX)

if(WIN32 AND INSTALL_SYSTEM_RUNTIMES)
  include(InstallRequiredSystemLibraries)
  INSTALL(FILES ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION bin COMPONENT Libraries)
endif()

####################################################################
#
# 'docs' target: regenerate doc/AntimonyTutorial.{htm,docx,rst,pdf} from
# doc/AntimonyTutorial.md using pandoc, then (if 'xxd' is available)
# regenerate QTAntimony_src/Tutorial.xxd, then (if Doxygen is available) regenerate
# the Doxygen API docs from the /** */ comments in src/antimony_api.h and
# src/enums.h, plus the doc/antimony-*.txt pages, per doc/doxygen.antimony.cfg.
# Not part of the default build -- run it explicitly, e.g.
# 'cmake --build . --target docs'.
#

find_program(PANDOC_EXECUTABLE
    NAMES pandoc
    DOC "The pandoc executable, used by the 'docs' target to regenerate AntimonyTutorial.* from AntimonyTutorial.md."
    )

find_program(XXD_EXECUTABLE
    NAMES xxd
    DOC "The xxd executable, used by the 'docs' target to regenerate QTAntimony_src/Tutorial.xxd from AntimonyTutorial.htm."
    )

set(ANTIMONY_TUTORIAL_MD ${CMAKE_SOURCE_DIR}/doc/AntimonyTutorial.md)
set(ANTIMONY_TUTORIAL_HTM ${CMAKE_SOURCE_DIR}/doc/AntimonyTutorial.htm)
set(ANTIMONY_TUTORIAL_DOCX ${CMAKE_SOURCE_DIR}/doc/AntimonyTutorial.docx)
set(ANTIMONY_TUTORIAL_RST ${CMAKE_SOURCE_DIR}/doc/AntimonyTutorial.rst)

if(PANDOC_EXECUTABLE)
    message(STATUS "  Using pandoc                  = ${PANDOC_EXECUTABLE}")

    # OUTPUT/DEPENDS makes this a real file-level rule (like a .cpp -> .o
    # compile step): pandoc only reruns when AntimonyTutorial.md is newer
    # than the generated .htm/.docx/.rst. AntimonyTutorial.pdf is produced
    # by the same command but left out of OUTPUT since pandoc_optional_pdf.cmake
    # may skip it (no PDF engine available) without failing the build.
    add_custom_command(
        OUTPUT ${ANTIMONY_TUTORIAL_HTM} ${ANTIMONY_TUTORIAL_DOCX} ${ANTIMONY_TUTORIAL_RST}
        COMMAND ${PANDOC_EXECUTABLE} --toc -s --lua-filter=pandoc_strip_toc_marker.lua AntimonyTutorial.md -o AntimonyTutorial.htm
        COMMAND ${PANDOC_EXECUTABLE} --toc -s --lua-filter=pandoc_strip_toc_marker.lua AntimonyTutorial.md -o AntimonyTutorial.docx
        COMMAND ${PANDOC_EXECUTABLE} --toc -s --lua-filter=pandoc_strip_toc_marker.lua AntimonyTutorial.md -o AntimonyTutorial.rst
        COMMAND ${CMAKE_COMMAND} -DPANDOC_EXECUTABLE=${PANDOC_EXECUTABLE} -P ${CMAKE_SOURCE_DIR}/doc/pandoc_optional_pdf.cmake
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
        DEPENDS ${ANTIMONY_TUTORIAL_MD}
        COMMENT "Regenerating AntimonyTutorial.htm, .docx, .rst, and .pdf from AntimonyTutorial.md"
        VERBATIM
        )

    set(DOCS_DEPENDS ${ANTIMONY_TUTORIAL_HTM} ${ANTIMONY_TUTORIAL_DOCX} ${ANTIMONY_TUTORIAL_RST})
else()
    message(STATUS "  pandoc not found -- the 'docs' target will report an error instead of regenerating AntimonyTutorial.*")
endif()

set(ANTIMONY_TUTORIAL_XXD ${CMAKE_SOURCE_DIR}/QTAntimony_src/Tutorial.xxd)

if(XXD_EXECUTABLE AND PANDOC_EXECUTABLE)
    message(STATUS "  Using xxd                     = ${XXD_EXECUTABLE}")

    # Same OUTPUT/DEPENDS treatment as the pandoc step above: only regenerate
    # Tutorial.xxd when AntimonyTutorial.htm is newer than it.
    add_custom_command(
        OUTPUT ${ANTIMONY_TUTORIAL_XXD}
        COMMAND ${CMAKE_COMMAND} -DXXD_EXECUTABLE=${XXD_EXECUTABLE} -P ${CMAKE_SOURCE_DIR}/doc/xxd_tutorial.cmake
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
        DEPENDS ${ANTIMONY_TUTORIAL_HTM}
        COMMENT "Regenerating QTAntimony_src/Tutorial.xxd from AntimonyTutorial.htm"
        VERBATIM
        )

    list(APPEND DOCS_DEPENDS ${ANTIMONY_TUTORIAL_XXD})
elseif(XXD_EXECUTABLE)
    message(STATUS "  xxd found but pandoc not found -- the 'docs' target will not update QTAntimony_src/Tutorial.xxd")
else()
    message(STATUS "  xxd not found -- the 'docs' target will not update QTAntimony_src/Tutorial.xxd")
endif()

add_custom_target(docs DEPENDS ${DOCS_DEPENDS})

if(NOT PANDOC_EXECUTABLE)
    add_custom_command(TARGET docs POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "pandoc was not found (install it from https://pandoc.org/installing.html and re-run cmake) -- cannot regenerate AntimonyTutorial.*."
        )
endif()

if(NOT XXD_EXECUTABLE OR NOT PANDOC_EXECUTABLE)
    add_custom_command(TARGET docs POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "xxd was not found -- QTAntimony_src/Tutorial.xxd was not updated (install xxd, e.g. via vim/Git for Windows, and re-run cmake)."
        )
endif()

find_package(Doxygen)

# A Cygwin-built doxygen doesn't recognize 'C:/...' as an absolute path (only
# POSIX-style paths), so convert to Cygwin's '/cygdrive/c/...' form when
# doxygen itself is a Cygwin build. Used for every generated file path handed
# to doxygen via an environment variable below.
function(antimony_doxygen_path OUT_VAR IN_PATH)
    string(TOLOWER "${DOXYGEN_EXECUTABLE}" DOXYGEN_EXECUTABLE_LOWER)
    # Deliberately nested rather than 'if(IN_PATH MATCHES ... AND
    # DOXYGEN_EXECUTABLE_LOWER MATCHES "cygwin")': evaluating a second
    # MATCHES in the same compound condition clobbers CMAKE_MATCH_1/2 from
    # the first (that second pattern has no capture groups, so it clears
    # them), leaving both empty by the time they're read below.
    if(DOXYGEN_EXECUTABLE_LOWER MATCHES "cygwin")
        if(IN_PATH MATCHES "^([A-Za-z]):(.*)$")
            string(TOLOWER "${CMAKE_MATCH_1}" DOXYGEN_PATH_DRIVE)
            set(${OUT_VAR} "/cygdrive/${DOXYGEN_PATH_DRIVE}${CMAKE_MATCH_2}" PARENT_SCOPE)
            return()
        endif()
    endif()
    set(${OUT_VAR} "${IN_PATH}" PARENT_SCOPE)
endfunction()

if(DOXYGEN_FOUND)
    message(STATUS "  Using Doxygen                 = ${DOXYGEN_EXECUTABLE}")

    # antimony_api.h no longer lives in src/ -- it's generated from
    # src/antimony_api.h.in into the build directory (see ANTIMONY_API above).
    antimony_doxygen_path(ANTIMONY_API_FOR_DOXYGEN "${ANTIMONY_API}")

    # Likewise, antimony-mainpage.txt.in gets its @LIBANTIMONY_VERSION_STRING@
    # placeholder substituted into the build directory (see
    # LIBANTIMONY_VERSION_STRING above).
    set(ANTIMONY_MAINPAGE_IN "${CMAKE_SOURCE_DIR}/doc/antimony-mainpage.txt.in")
    set(ANTIMONY_MAINPAGE    "${CMAKE_CURRENT_BINARY_DIR}/antimony-mainpage.txt")
    configure_file(${ANTIMONY_MAINPAGE_IN} ${ANTIMONY_MAINPAGE} @ONLY)
    antimony_doxygen_path(ANTIMONY_MAINPAGE_FOR_DOXYGEN "${ANTIMONY_MAINPAGE}")

    # Generated HTML goes to a build-directory staging folder and then gets installed.
    set(ANTIMONY_DOXYGEN_OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/doxygen-html")
    antimony_doxygen_path(ANTIMONY_DOXYGEN_OUTPUT_FOR_DOXYGEN "${ANTIMONY_DOXYGEN_OUTPUT}")

    set(ANTIMONY_DOXYFILE_IN "${CMAKE_SOURCE_DIR}/doc/doxygen.antimony.cfg")
    set(ANTIMONY_DOXYFILE    "${CMAKE_CURRENT_BINARY_DIR}/doxygen.antimony.cfg")
    configure_file(${ANTIMONY_DOXYFILE_IN} ${ANTIMONY_DOXYFILE} @ONLY)
    antimony_doxygen_path(ANTIMONY_DOXYFILE_FOR_DOXYGEN "${ANTIMONY_DOXYFILE}")

    add_custom_command(TARGET docs POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Regenerating Doxygen API docs from antimony_api.h, enums.h, and doc/antimony-*.txt"
        COMMAND ${DOXYGEN_EXECUTABLE} ${ANTIMONY_DOXYFILE_FOR_DOXYGEN}
        COMMAND ${CMAKE_COMMAND} -DDOC_DIR=${CMAKE_SOURCE_DIR}/doc -DOUTPUT_DIR=${ANTIMONY_DOXYGEN_OUTPUT} -P ${CMAKE_SOURCE_DIR}/doc/copy_docs_assets.cmake
        COMMAND ${CMAKE_COMMAND} -E echo "-- Regenerated Doxygen API docs"
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/doc
        COMMENT "Regenerating Doxygen API docs from antimony_api.h, enums.h, and doc/antimony-*.txt"
        VERBATIM
        )

    # 'cmake --build . --target docs' regenerates the staging folder above;
    # 'cmake --install .' (a separate step) copies it to <prefix>/doc/.
    # OPTIONAL, since the staging folder won't exist until 'docs' has been
    # built at least once.
    install(DIRECTORY "${ANTIMONY_DOXYGEN_OUTPUT}/" DESTINATION doc OPTIONAL)
else()
    message(STATUS "  Doxygen not found -- the 'docs' target will not regenerate the Doxygen API docs")

    add_custom_command(TARGET docs POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "Doxygen was not found -- API docs were not regenerated (install Doxygen from https://www.doxygen.nl/download.html and re-run cmake)."
        )
endif()

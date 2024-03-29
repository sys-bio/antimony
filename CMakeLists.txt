####################################################################
#
# CMake Build Script for libantimony
#

cmake_minimum_required(VERSION 3.0)
project(libantimony)

####################################################################
#
# Set up version information.
#
SET(LIBANTIMONY_VERSION_MAJOR 2)
SET(LIBANTIMONY_VERSION_MINOR 14)
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
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

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
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.txt")
SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt")
SET(CPACK_PACKAGE_VERSION_MAJOR "${LIBANTIMONY_VERSION_MAJOR}")
SET(CPACK_PACKAGE_VERSION_MINOR "${LIBANTIMONY_VERSION_MINOR}")
SET(CPACK_PACKAGE_VERSION_PATCH "${LIBANTIMONY_VERSION_PATCH}")
SET(CPACK_PACKAGE_VERSION_RELEASE "${LIBANTIMONY_VERSION_RELEASE}")
INCLUDE(CPack)

SET(LIBANTIMONY_VERSION_STRING "v${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")


option(BUILD_SHARED_LIBS  "Build shared library (Set to OFF to build static libraries)" ON)
set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING "Choose the type of build, options are: None (CMAKE_CXX_FLAGS or CMAKE_C_FLAGS are used), Debug, Release, RelWithDebInfo, MinSizeRel" )

set(USE_UNIVERSAL_BINARIES "ON" CACHE BOOL "Build and link to universal binaries on MacOS")

if (USE_UNIVERSAL_BINARIES)
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64" CACHE INTERNAL "Compile for intel and M1 chips on apple" FORCE)
    message(STATUS "building on mac with universal binaries")
endif()

####################################################################
#
# Here we have the main configuration options for libantimony
#

# which language bindings should be build
option(WITH_SBML            "Generate SBML translations"      ON )
if (WITH_SBML)
    option(WITH_STATIC_SBML     "Use the static version of the libsbml library"      ON )
    option(WITH_COMP_SBML       "Use the hierarchical composition package API"      ON )
    OPTION(WITH_LIBSBML_EXPAT   "Set if libsbml was compiled with a separate expat library."  ON)
    OPTION(WITH_LIBSBML_LIBXML  "Set if libsbml was compiled with a separate libxml library." OFF)
    OPTION(WITH_LIBSBML_XERCES  "Set if libsbml was compiled with a separate xerces library." OFF)
    OPTION(WITH_LIBSBML_COMPRESSION "Set if libsbml was compiled with separate zdll and bzip libraries." ON)
endif()
option(WITH_CELLML          "Generate CellML translations"    OFF )
option(WITH_QTANTIMONY      "Generate QTAntimony"             ON )
option(WITH_SWIG   "Regenerate SWIG-based language bindings." OFF )
option(WITH_PYTHON       "Generate Python language bindings." OFF)
if (WITH_PYTHON)
  option(PYTHON_SYSTEM_INSTALL  "Install the python bindings using setup.py and distutils.  May require admin privileges."    OFF )
  option(PYTHON_LOCAL_INSTALL   "Install the python bindings in ${CMAKE_INSTALL_PREFIX}/bindings/python/.  Can be installed later via 'setup.py'."    ON )
  option(WITH_CONDA_BUILDER     "Install files required to build Anaconda packages"  OFF)
endif()
option(INSTALL_SYSTEM_RUNTIMES "Install system runtime libraries (e.g. MSVC runtimes)")

set(EXTRA_LIBS "" CACHE STRING "Libraries the other libraries depend on that are in non-standard locations" )
#set(EXTRA_LIBS "" CACHE_STRING "")

# Enable the generation of unit tests. If enabled, all test runners
# will be created and can be run with "make test" or ctest.
# This won't work in Visual Studio 2003, so we disable this option there.
#
if(NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 6" AND NOT ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
    if (WITH_COMP_SBML)
        option(WITH_CHECK    "Compile unit tests. Run with 'make test' or 'ctest'." OFF)
    endif()
endif()



add_definitions( -DLIBANTIMONY_VERSION_STRING="${LIBANTIMONY_VERSION_STRING}" )


####################################################################
#
# Locate libsbml if needed
#

if(WITH_SBML)

    find_path(LIBSBML_INSTALL_DIR
    NAMES include/sbml/SBMLTypes.h
    PATHS /usr /usr/local /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/
              ${CMAKE_SOURCE_DIR}/../libsbml-5/release/
              ${CMAKE_SOURCE_DIR}/../
              )

    if(WITH_STATIC_SBML)
        find_library(LIBSBML_LIBRARY
             NAMES libsbml-static.lib libsbml-static.so libsbml-static sbml-static.lib sbml-static.so sbml-static libsbml-staticd.lib libsbml-staticmd.lib libsbml-staticmdd.lib libsbml-staticd.so libsbml-staticd sbml-staticd.lib sbml-staticd.so sbml-staticd
             PATHS /usr/lib /usr/local/lib
               ${LIBSBML_INSTALL_DIR}/lib
               ${LIBSBML_INSTALL_DIR}/lib64
               ${CMAKE_SOURCE_DIR}
               ${CMAKE_SOURCE_DIR}/dependencies/lib
               ${CMAKE_SOURCE_DIR}/../libsbml-5/release/lib/
             )
    else()
        find_library(LIBSBML_LIBRARY
            NAMES libsbml.lib libsbml.so libsbml sbml.lib sbml.so sbml
            PATHS /usr/lib /usr/local/lib
              ${LIBSBML_INSTALL_DIR}/lib
              ${LIBSBML_INSTALL_DIR}/lib64
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${CMAKE_SOURCE_DIR}/../libsbml-5/release/lib/
            )
    endif()
    find_path(LIBSBML_INCLUDE_DIR
        NAMES sbml/SBMLTypes.h
        PATHS /usr/include /usr/local/include
              ${LIBSBML_INSTALL_DIR}/include
              ${CMAKE_SOURCE_DIR}/include
              ${CMAKE_SOURCE_DIR}/dependencies/include
              ${CMAKE_SOURCE_DIR}/../libsbml-5/release/include/
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBSBML_LIBRARY} )
    if(WIN32 AND NOT WITH_STATIC_SBML)
        find_path(LIBSBML_BIN_DIR
            NAMES libsbml.dll
            PATHS /usr/bin /usr/local/bin
                  ${LIBSBML_INSTALL_DIR}/bin
                  ${LIBSBML_INCLUDE_DIR}/../bin
                  ${CMAKE_SOURCE_DIR}/
                  ${CMAKE_SOURCE_DIR}/dependencies/libsbml/bin
                  ${CMAKE_SOURCE_DIR}/../libsbml-5/release/bin/
            )
        set(LIBSBML_DLL ${LIBSBML_BIN_DIR}/libsbml.dll)
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

###############################################################
#
# Locate the libraries libsbml depends on, for static linking.
#

if(WITH_LIBSBML_EXPAT)
    find_library(EXPAT_LIBRARY
        NAMES libexpat.lib libexpat.so libexpat.dylib libexpat expat.lib expat.so expat.dylib expat
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${EXPAT_LIBRARY} )
endif()

if(WITH_LIBSBML_LIBXML)
    find_library(LIBXML_LIBRARY
        NAMES libxml2.lib libxml2.so libxml2.dylib libxml2 libxml2s libxml2sd
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBXML_LIBRARY} )

    #The libxml library requires the libz library, too.
    find_library(ZDLL_LIBRARY
        NAMES zdll.lib zdll.so zdll.dylib zdll z zlibd.lib zlibstaticd.lib zlibmd.lib zlibstatic.lib
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
              ${LIBSBML_INSTALL_DIR}/lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${ZDLL_LIBRARY} )

    if(WIN32)
      find_library(ICONV_LIBRARY
          NAMES iconv.lib iconv.so iconv.dylib iconv libiconv.lib libiconv.so libiconv.dylib libiconv libiconv-static.lib libiconv-staticd.lib
          PATHS /usr/lib /usr/local/lib
                ${CMAKE_SOURCE_DIR}
                ${CMAKE_SOURCE_DIR}/dependencies/lib
                ${LIBSBML_INCLUDE_DIR}/../lib
          )
      set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${ICONV_LIBRARY})
      find_library(LIBCHARSET_LIBRARY
          NAMES libcharset.lib libcharsetd.lib libcharsetmd.lib libcharsetmdd.lib
          PATHS /usr/lib /usr/local/lib
                ${CMAKE_SOURCE_DIR}
                ${CMAKE_SOURCE_DIR}/dependencies/lib
                ${LIBSBML_INCLUDE_DIR}/../lib
          )
      set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${LIBCHARSET_LIBRARY})
    endif()
endif()

if(WITH_LIBSBML_XERCES)
    find_library(XERCES_LIBRARY
        NAMES xerces-c_static_3.lib xerces-c_static_3.so xerces-c_static_3.dylib xerces-c_static_3
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${XERCES_LIBRARY} )
endif()

if(WITH_LIBSBML_COMPRESSION)
    find_library(ZDLL_LIBRARY
        NAMES zdll.lib zdll.so zdll.dylib zdll z zlibd.lib zlibstaticd.lib zlibmd.lib zlibstatic.lib
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
              ${LIBSBML_INSTALL_DIR}/lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${ZDLL_LIBRARY} )

    find_library(BZIP_LIBRARY
        NAMES bzip2.lib bzip2.so bzip2.dylib bzip2 bz2 bz2d bz2md bz2mdd
	PATHS /usr/lib /usr/local/lib
              ${CMAKE_SOURCE_DIR}
              ${CMAKE_SOURCE_DIR}/dependencies/lib
              ${LIBSBML_INCLUDE_DIR}/../lib
              ${LIBSBML_INSTALL_DIR}/lib
        )
    set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${BZIP_LIBRARY} )
endif()

###############################################################################
#
# If WITH_SWIG is selected, we need to find swig
#
if(WITH_SWIG)
    find_program(SWIG_EXECUTABLE
        NAMES swig
        PATHS
              "c:/Program Files (x86)/Swig"
              c:/Program Files/Swig
              c:/Program Files/swigwin-3.0.10
              c:/Program Files/swigwin-4.0.2
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

#message(STATUS "libantimony libs: ${LIBANTIMONY_LIBS}")
set(LIBANTIMONY_LIBS ${LIBANTIMONY_LIBS} ${EXTRA_LIBS})

###############################################################################
## Enable support for testing ... can be invoked by running ctest
# or make test
#

if(WITH_CHECK)

    # we do use tests, that require 2.8.4
    cmake_minimum_required(VERSION 2.8.4)

    # set test timeout to 3000 as the normal time limit is not sufficient
    # for the comp tests
    SET(DART_TESTING_TIMEOUT "3000" CACHE STRING "" FORCE)

    enable_testing()

    find_library(LIBCHECK_LIBRARY
        NAMES check libcheck
        PATHS /usr/lib /usr/local/lib ${LIBSBML_DEPENDENCY_DIR}/lib
        DOC "The file name of the libcheck library."
    )

    find_path(LIBCHECK_INCLUDE_DIR
        NAMES check.h
        PATHS /usr/include /usr/local/include  ${LIBSBML_DEPENDENCY_DIR}/include
        DOC "The directory containing the libcheck include files."
              )

    if(NOT EXISTS "${LIBCHECK_INCLUDE_DIR}/check.h")
        message(FATAL_ERROR "The 'check' include directory appears to be invalid. It should contain the file check.h, but it does not.")
    endif()

    if(${CMAKE_GENERATOR} MATCHES "Visual Studio 6" OR ${CMAKE_GENERATOR} MATCHES "Visual Studio 7")
        message(WARNING "Libcheck is not compatible with Visual Studio 2003 (or earlier versions).")
    endif()

  if (UNIX)
      # setup valgrind
      set(CMAKE_MEMORYCHECK_COMMAND valgrind)
      set(CMAKE_MEMORYCHECK_COMMAND_OPTIONS
         "--error-exitcode=1 --trace-children=yes --leak-check=full --show-reachable=yes --leak-resolution=high --track-origins=yes --error-limit=no ")

      set(MEMCHECK_COMMAND
         "${CMAKE_MEMORYCHECK_COMMAND} ${CMAKE_MEMORYCHECK_COMMAND_OPTIONS}")
      separate_arguments(MEMCHECK_COMMAND)

      # check that check compiles/links - needs cmake 3+

      if(${CMAKE_VERSION} VERSION_GREATER 3.0.0)
        set(CHECK_CHECK_CODE
        "
        #include <check.h>
        
        START_TEST (sanity_check)
        {
            fail_unless(5 == 5, \"this should succeed\");
            fail_unless(6 == 5, \"this should fail\");
        }
        END_TEST
        
        int 
        main(void)
        {
            Suite *s1 = suite_create(\"Core\");
            TCase *tc1_1 = tcase_create(\"Core\");
            SRunner *sr = srunner_create(s1);
            int nf;
        
            suite_add_tcase(s1, tc1_1);
            tcase_add_test(tc1_1, sanity_check);
        
            srunner_run_all(sr, CK_ENV);
            nf = srunner_ntests_failed(sr);
            srunner_free(sr);
            ;
            return nf == 0 ? 0 : 1;
        }
        " 
        )

        set(CMAKE_REQUIRED_LIBRARIES_CACHE ${CMAKE_REQUIRED_LIBRARIES})
        unset(CHECK_CHECK_TEST CACHE)
        unset(CHECK_CHECK_TEST2 CACHE)

        set(CHECK_CHECK_TEST)
        set(CMAKE_REQUIRED_LIBRARIES "-lcheck -lm ${EXTRA_LIBS}")
        CHECK_C_SOURCE_COMPILES("${CHECK_CHECK_CODE}" CHECK_CHECK_TEST)

        if (NOT CHECK_CHECK_TEST)
            set(CHECK_CHECK_TEST2)
            set(CMAKE_REQUIRED_LIBRARIES "-lcheck -lm -pthread -lrt -lsubunit ${EXTRA_LIBS}")
            CHECK_C_SOURCE_COMPILES("${CHECK_CHECK_CODE}" CHECK_CHECK_TEST2)
            
            if (CHECK_CHECK_TEST2)
                set(CHECK_TMP_LIBS "-pthread -lrt -lsubunit ${EXTRA_LIBS}")
                string(STRIP "${CHECK_TMP_LIBS}" CHECK_TMP_LIBS)
                set(EXTRA_LIBS "${CHECK_TMP_LIBS}" CACHE STRING
                "List of additional libraries to link against.  Separate multiple
                names using semicolons." FORCE)                
                unset(CHECK_TMP_LIBS)
                message(STATUS "Check requires the following EXTRA_LIBS : ${EXTRA_LIBS}")
            else ()
                message(WARNING
"Check cannot compile tests, please specify the correct EXTRA_LIBS for your operating system.")            
            endif (CHECK_CHECK_TEST2)
            unset(CHECK_CHECK_TEST2 CACHE)

        endif (NOT CHECK_CHECK_TEST)

        unset(CHECK_CHECK_TEST CACHE)
        set(CMAKE_REQUIRED_LIBRARIES ${CMAKE_REQUIRED_FLAGS_CACHE})

      endif(${CMAKE_VERSION} VERSION_GREATER 3.0.0)

  endif(UNIX)

    include(CTest)

endif(WITH_CHECK)


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
    ${ANTIMONY_SRC_DIR}uncertWrapper.cpp
    ${ANTIMONY_SRC_DIR}event.cpp
    ${ANTIMONY_SRC_DIR}formula.cpp
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
        ${ANTIMONY_SRC_DIR}cellmlx.h
        ${ANTIMONY_SRC_DIR}constraint.h
        ${ANTIMONY_SRC_DIR}dnastrand.h
        ${ANTIMONY_SRC_DIR}uncertWrapper.h
        ${ANTIMONY_SRC_DIR}enums.h
        ${ANTIMONY_SRC_DIR}event.h
        ${ANTIMONY_SRC_DIR}formula.h
        ${ANTIMONY_SRC_DIR}libutil.h
        ${ANTIMONY_SRC_DIR}module.h
        ${ANTIMONY_SRC_DIR}reactantlist.h
        ${ANTIMONY_SRC_DIR}reaction.h
        ${ANTIMONY_SRC_DIR}registry.h
        ${ANTIMONY_SRC_DIR}sbmlx.h
        ${ANTIMONY_SRC_DIR}sboTermWrapper.h
        ${ANTIMONY_SRC_DIR}stringx.h
        ${ANTIMONY_SRC_DIR}typex.h
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

if(WITH_CHECK)
    message(STATUS "  Using libcheck                = ${LIBCHECK_LIBRARY}")
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

if(WITH_SBML)
  add_executable(antimony2sbml ${ANTIMONY_SRC_DIR}antimony2sbml.cpp)
  add_dependencies(antimony2sbml ${LIBANTIMONY_LIBRARY}-static)
  target_link_libraries(antimony2sbml ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
  install(TARGETS antimony2sbml DESTINATION bin)

  add_executable(sbml2antimony ${ANTIMONY_SRC_DIR}sbml2antimony.cpp)
  add_dependencies(sbml2antimony ${LIBANTIMONY_LIBRARY}-static)
  target_link_libraries(sbml2antimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS})
  install(TARGETS sbml2antimony DESTINATION bin)
endif(WITH_SBML)

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

set(CMAKE_CXX_STANDARD 11)
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

###############################################################################
#
# Install win32 dependencies
#
#if (NOT UNIX)
#   file(GLOB win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll" "${CMAKE_CURRENT_SOURCE_DIR}/win32/README.txt")
#   if (NOT WITH_STATIC_SBML)
#      list(APPEND win_dependencies ${LIBSBML_DLL})
#   endif()
#   install(FILES ${win_dependencies} DESTINATION bin/)
#   install(FILES "${CMAKE_SOURCE_DIR}/win32/platforms/qwindows.dll" DESTINATION bin/platforms/)
#endif()

if(WIN32 AND INSTALL_SYSTEM_RUNTIMES)
  include(InstallRequiredSystemLibraries)
  INSTALL(FILES ${CMAKE_INSTALL_SYSTEM_RUNTIME_LIBS} DESTINATION bin COMPONENT Libraries)
endif()

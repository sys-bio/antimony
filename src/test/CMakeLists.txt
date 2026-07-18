####################################################################
#
# CMake Build Script for libantimony tests (GoogleTest)
#
#
include(${CMAKE_SOURCE_DIR}/common.cmake)

include_directories(BEFORE ${CMAKE_SOURCE_DIR}/src)
include_directories(${CMAKE_BINARY_DIR})
if (EXTRA_INCLUDE_DIRS)
    include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

########################################################
#   Add the (vendored) googletest framework as a subdirectory
#
# Force the vendored googletest to build as static libraries regardless of
# the project-wide BUILD_SHARED_LIBS setting (antimony itself is often built
# with BUILD_SHARED_LIBS=ON for libantimony.dll). If gtest were built as
# gtest.dll/gtest_main.dll, every test executable would need those DLLs on
# its runtime search path; since the test binaries and the gtest DLLs land
# in different output directories, that fails with STATUS_DLL_NOT_FOUND
# (0xc0000135) -- including when CMake itself runs the exe post-build to
# discover individual tests. A plain (non-cache) set() here shadows the
# cached BUILD_SHARED_LIBS value only for this subdirectory, so the rest of
# the project is unaffected.
set(BUILD_SHARED_LIBS OFF)

# Make gtest's static libraries link against the dynamic (/MD or /MDd) CRT
# instead of the static CRT, matching what the rest of the project (and the
# MSVC default) uses. Without this, linking gtest's static libs alongside
# libantimony-static/libsbml can trip a runtime-library mismatch.
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(googletest)

# Sources shared by every antimony test binary: main() plus the
# TestDataDirectory/srcdir setup that each TestAntimony*.cpp relies on, plus
# comparison helpers (compareFileTranslation & friends) that used to be
# reachable across files via `extern` when everything linked into one
# test_antimony binary. Now that each suite is its own executable, they need
# to be compiled into every target instead. See TestAntimonyUtil.h.
set(SharedTestFiles
        "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp"
        "${CMAKE_CURRENT_SOURCE_DIR}/TestAntimonyUtil.h"
        "${CMAKE_CURRENT_SOURCE_DIR}/TestAntimonyUtil.cpp"
)

############################################################
#   Function for creating antimony test binaries
#
# Adds a new executable target, links it against libantimony (static)
# and GoogleTest, and registers it with ctest via gtest_discover_tests
# so that every individual TEST() case shows up as its own ctest entry.
#
# Parameters:
#   - TEST_TARGET: name of the binary
#   - All further arguments are source files specific to this suite.
function(add_test_executable TEST_TARGET)
    add_executable(${TEST_TARGET} ${ARGN} ${SharedTestFiles})

    target_link_libraries(${TEST_TARGET} PRIVATE
            ${LIBANTIMONY_LIBRARY}-static
            ${LIBANTIMONY_LIBS}
            ${EXTRA_LIBS}
            gtest
            gtest_main
            )

    add_dependencies(${TEST_TARGET} ${LIBANTIMONY_LIBRARY}-static gtest gtest_main)

    set_target_properties(${TEST_TARGET} PROPERTIES LINKER_LANGUAGE CXX)

    # Bake the absolute path to this directory into the binary so
    # setTestDataDirectory() (see main.cpp) can find test-data/ even when
    # the test isn't launched via ctest (e.g. Visual Studio's Test Explorer,
    # or running the .exe directly) and no one has set the "srcdir"
    # environment variable for us.
    target_compile_definitions(${TEST_TARGET} PRIVATE
            "ANTIMONY_TEST_SRC_DIR=\"${CMAKE_CURRENT_SOURCE_DIR}\""
    )

    # Still set "srcdir" for ctest-driven runs too, so CI/distcheck-style
    # invocations that want to point at a different checkout can override it.
    gtest_discover_tests(
            ${TEST_TARGET}
            DISCOVERY_TIMEOUT 500
            DISCOVERY_MODE PRE_TEST
            PROPERTIES
            TIMEOUT 500
            ENVIRONMENT "srcdir=${CMAKE_CURRENT_SOURCE_DIR}"
    )
endfunction()

#########################################################
#   One executable per suite
#
add_test_executable(test_antimony_API           TestAntimonyAPI.cpp)
add_test_executable(test_antimony_Basic         TestAntimonyBasic.cpp)
add_test_executable(test_antimony_Constraints   TestAntimonyConstraints.cpp)
add_test_executable(test_antimony_CVTerms       TestAntimonyCVTerms.cpp)
add_test_executable(test_antimony_Distrib       TestAntimonyDistrib.cpp)
add_test_executable(test_antimony_Errors        TestAntimonyErrors.cpp)
add_test_executable(test_antimony_FBC           TestAntimonyFBC.cpp)
add_test_executable(test_antimony_Flattening    TestAntimonyFlattening.cpp)
add_test_executable(test_antimony_Hierarchy     TestAntimonyHierarchy.cpp)
add_test_executable(test_antimony_Import        TestAntimonyImport.cpp)
add_test_executable(test_antimony_LayoutRender  TestAntimonyLayoutRender.cpp)
add_test_executable(test_antimony_NamedStoich   TestAntimonyNamedStoich.cpp)
add_test_executable(test_antimony_SBO           TestAntimonySBO.cpp)
add_test_executable(test_antimony_Uncert        TestAntimonyUncert.cpp)
add_test_executable(test_antimony_Units         TestAntimonyUnits.cpp)

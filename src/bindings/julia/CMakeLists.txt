###############################################################################
#
# Description  : CMake build script for the antimony Julia bindings
#
# The bindings are a pure-Julia package that calls libantimony through its C
# API, so nothing is compiled here: the package is assembled in the build tree
# for testing and installed next to the library.
#
###############################################################################

set(ANTIMONY_JULIA_VERSION "${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")

set(JULIA_PACKAGE_BUILD_DIR   "${CMAKE_BINARY_DIR}/bindings/julia/Antimony")
set(JULIA_PACKAGE_INSTALL_DIR "bindings/julia/Antimony")

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/Project.toml.in"      "${JULIA_PACKAGE_BUILD_DIR}/Project.toml"      @ONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/Antimony.jl"      "${JULIA_PACKAGE_BUILD_DIR}/src/Antimony.jl"   COPYONLY)
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/test/runtests.jl"     "${JULIA_PACKAGE_BUILD_DIR}/test/runtests.jl"  COPYONLY)

# A copy of the library goes inside the package, so the installed package is self-contained.
install(PROGRAMS "$<TARGET_FILE:${LIBANTIMONY_LIBRARY}>" DESTINATION ${JULIA_PACKAGE_INSTALL_DIR}/lib)

install(FILES "${JULIA_PACKAGE_BUILD_DIR}/Project.toml"     DESTINATION ${JULIA_PACKAGE_INSTALL_DIR})
install(FILES "${JULIA_PACKAGE_BUILD_DIR}/src/Antimony.jl"  DESTINATION ${JULIA_PACKAGE_INSTALL_DIR}/src)
install(FILES "${JULIA_PACKAGE_BUILD_DIR}/test/runtests.jl" DESTINATION ${JULIA_PACKAGE_INSTALL_DIR}/test)
install(FILES "${CMAKE_SOURCE_DIR}/NOTICE.txt" DESTINATION ${JULIA_PACKAGE_INSTALL_DIR})

find_program(JULIA_EXECUTABLE julia)
if (WITH_GTEST AND JULIA_EXECUTABLE)
    message(STATUS "  Julia binding tests will run with        = ${JULIA_EXECUTABLE}")
    add_test(NAME julia_antimony_bindings
        COMMAND ${CMAKE_COMMAND} -E env "ANTIMONY_LIBRARY=$<TARGET_FILE:${LIBANTIMONY_LIBRARY}>"
                "${JULIA_EXECUTABLE}" "--project=${JULIA_PACKAGE_BUILD_DIR}" "${JULIA_PACKAGE_BUILD_DIR}/test/runtests.jl")
    set_tests_properties(julia_antimony_bindings PROPERTIES LABELS "julia")
else ()
    message(STATUS "  The Julia binding tests will not be registered (needs WITH_GTEST and julia on the path)")
endif ()

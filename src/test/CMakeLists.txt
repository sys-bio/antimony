####################################################################
#
# CMake Build Script for libantimony tests
#
# 
include(${CMAKE_SOURCE_DIR}/common.cmake)

file(GLOB CPP_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp )
file(GLOB H_FILES ${CMAKE_CURRENT_SOURCE_DIR}/*.h )

set(TEST_FILES ${CPP_FILES} ${H_FILES})

include_directories(BEFORE ${CMAKE_SOURCE_DIR}/src)
if (EXTRA_INCLUDE_DIRS)
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

include_directories(${LIBCHECK_INCLUDE_DIR})
add_executable(test_antimony ${TEST_FILES})
target_link_libraries(test_antimony ${LIBANTIMONY_LIBRARY}-static ${LIBANTIMONY_LIBS} ${LIBCHECK_LIBRARY} )
add_test(test_antimony_run ${CMAKE_CURRENT_BINARY_DIR}/test_antimony )
set_tests_properties(test_antimony_run PROPERTIES ENVIRONMENT 
	"srcdir=${CMAKE_CURRENT_SOURCE_DIR}")

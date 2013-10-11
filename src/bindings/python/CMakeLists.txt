###############################################################################
#
# Description  : CMake build script for antimony Python bindings
# Author(s)    : Lucian Smith, from libsbml and Frank Bergmann
#
###############################################################################

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})
include(FindPythonLibs)
include(FindPythonInterp)


####################################################################
#
# determine local dependencies, so as to re-swig if one of them changed
# 

file(GLOB SWIG_DEPENDENCIES 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.i 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h 
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.i
        ${CMAKE_CURRENT_SOURCE_DIR}/../swig/*.h
        )


#
# Remove SWIG wrappers if requested
#
if (ANTIMONY_REMOVE_WRAPPERS)
  foreach(file 
    ${CMAKE_CURRENT_BINARY_DIR}/antimony_wrap.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/pydoc-normal.i
    ${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i
  )
  if (EXISTS ${file})
      FILE(REMOVE ${file})
  endif()
  endforeach()
endif(ANTIMONY_REMOVE_WRAPPERS)

ADD_CUSTOM_COMMAND(        
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/antimony_wrap.cpp
    COMMAND "${PYTHON_EXECUTABLE}"
    ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/../swig/swigdoc.py"
            python
            -I"${CMAKE_CURRENT_SOURCE_DIR}/../.."
            -D"${CMAKE_CURRENT_SOURCE_DIR}/../../../doc"
            "${CMAKE_CURRENT_SOURCE_DIR}/../swig/antimony.i"
            "${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i"
    COMMAND "${PYTHON_EXECUTABLE}"
    ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/doc-converter/rewrite_pydoc.py"
            -f "${CMAKE_CURRENT_BINARY_DIR}/pydoc-doxygen.i"
            -o "${CMAKE_CURRENT_BINARY_DIR}/pydoc-normal.i"
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc-doxygen.i pydoc.i
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS    -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
            -I${CMAKE_CURRENT_SOURCE_DIR} 
            -I${CMAKE_CURRENT_BINARY_DIR} 
            -I${CMAKE_SOURCE_DIR}/src
            -I${CMAKE_SOURCE_DIR}/include
            -c++
            -python        
            ${SWIG_EXTRA_ARGS}         
            -o ${CMAKE_CURRENT_BINARY_DIR}/antimony_wrap.cpp 
            ${CMAKE_CURRENT_SOURCE_DIR}/antimony.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc.i pydoc-doxygen.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename libantimony.py antimony-doxygen.py
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc-normal.i pydoc.i
    COMMAND "${SWIG_EXECUTABLE}"
    ARGS    -I${CMAKE_CURRENT_SOURCE_DIR}/../swig/
            -I${CMAKE_CURRENT_SOURCE_DIR} 
            -I${CMAKE_CURRENT_BINARY_DIR} 
            -I${CMAKE_SOURCE_DIR}/src
            -I${CMAKE_SOURCE_DIR}/include
            -c++
            -python        
            ${SWIG_EXTRA_ARGS}         
            -o ${CMAKE_CURRENT_BINARY_DIR}/antimony_wrap.cpp 
            ${CMAKE_CURRENT_SOURCE_DIR}/antimony.i
    COMMAND "${CMAKE_COMMAND}"
    ARGS    -E rename pydoc.i pydoc-normal.i 
    MAIN_DEPENDENCY ${CMAKE_CURRENT_SOURCE_DIR}/antimony.i
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/CMakeLists.txt
            ${CMAKE_CURRENT_SOURCE_DIR}/doc-converter/rewrite_pydoc.py
            ${CMAKE_CURRENT_SOURCE_DIR}/../swig/swigdoc.py
            ${SWIG_DEPENDENCIES}
    COMMENT "Swig Python source") 

add_custom_target(binding_python_swig ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/antimony_wrap.cpp)

####################################################################
#
# Build native library
#

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../swig)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${PYTHON_INCLUDE_DIRS})
if (EXTRA_INCLUDE_DIRS) 
 include_directories(${EXTRA_INCLUDE_DIRS})
endif(EXTRA_INCLUDE_DIRS)

if (MSVC)
  # the build fails when compiled with packages as the object file is too 
  # big adding the big flag makes it work!
  add_definitions(/bigobj)
endif(MSVC)

add_library(binding_python_lib SHARED antimony_wrap.cpp)
add_dependencies( binding_python_lib binding_python_swig) 

set_target_properties (binding_python_lib PROPERTIES OUTPUT_NAME "_libantimony")
if (UNIX)
        set_target_properties (binding_python_lib PROPERTIES PREFIX "")
        set_target_properties (binding_python_lib PROPERTIES SUFFIX ".so")
else()                
        if (CYGWIN)
                set_target_properties (binding_python_lib PROPERTIES PREFIX "")
                set_target_properties (binding_python_lib PROPERTIES SUFFIX ".dll")
        else()
                set_target_properties (binding_python_lib PROPERTIES SUFFIX ".pyd")        
        endif()
endif()

#message(STATUS "libraries: ${LIBANTIMONY_LIBS}\nantimony:${LIBANTIMONY_LIBRARY}")
target_link_libraries(binding_python_lib ${LIBANTIMONY_LIBS} ${LIBANTIMONY_LIBRARY} ${PYTHON_LIBRARIES})

# 
# Determine the python installation directory
#
set(PYTHON_PACKAGE_INSTALL_DIR)
if (UNIX OR CYGWIN) 
  execute_process(COMMAND "${PYTHON_EXECUTABLE}" -c "import sys;import platform; sys.stdout.write(platform.python_version()[:3])"
    OUTPUT_VARIABLE PYTHON_VERSION)
  set(PYTHON_PACKAGE_INSTALL_DIR ${CMAKE_INSTALL_LIBDIR}/python${PYTHON_VERSION}/site-packages)
else()
  set(PYTHON_PACKAGE_INSTALL_DIR ${MISC_PREFIX}bindings/python)
endif()

INSTALL(TARGETS binding_python_lib DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony )

file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth" "antimony\n")
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libantimony.py  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony )

if (NOT UNIX)
  file(GLOB new_win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll")
  install(FILES ${new_win_dependencies} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony )
endif()

####################################################################
#
# testing
#

if(WITH_CHECK)

        # copy test files to build dir
        file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

        # run python tests
        add_test(NAME test_python_binding 
                 COMMAND ${PYTHON_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/test.py
                 -p $<TARGET_FILE_DIR:binding_python_lib> -b ${CMAKE_CURRENT_SOURCE_DIR}/test)

endif()

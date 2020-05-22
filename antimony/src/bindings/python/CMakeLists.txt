###############################################################################
#
# Description  : CMake build script for antimony Python bindings
# Author(s)    : Lucian Smith, from libsbml and Frank Bergmann
#
###############################################################################

find_package(PythonInterp)
# specify that the same python library should be found
# as the one the selected interpreter uses
set (Python_ADDITIONAL_VERSIONS ${PYTHON_VERSION_STRING})

SET(LIBANTIMONY_VERSION_STRING_NO_V "${LIBANTIMONY_VERSION_MAJOR}.${LIBANTIMONY_VERSION_MINOR}${LIBANTIMONY_VERSION_PATCH}${LIBANTIMONY_VERSION_RELEASE}")

SET(PYTHON_CTYPES_FILE "${CMAKE_CURRENT_BINARY_DIR}/antimony.py")

#Create the 'antimony.py' ctypes-based library from 'createAntimonyLib.py'.
ADD_CUSTOM_COMMAND(
    OUTPUT   ${PYTHON_CTYPES_FILE}
    COMMAND "${PYTHON_EXECUTABLE} "
    ARGS    "${CMAKE_SOURCE_DIR}/src/bindings/python/createAntimonyLib.py" "${CMAKE_SOURCE_DIR}/src/"
    COMMENT "Convert header file to ctypes Python bindings.")

ADD_CUSTOM_TARGET(python_ctypes_lib DEPENDS ${PYTHON_CTYPES_FILE})

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/antimony.py PROPERTIES GENERATED TRUE)

#Create setup.py from setup.py.in
set(SETUP_PY_IN "${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in")
set(SETUP_PY    "${CMAKE_CURRENT_BINARY_DIR}/setup.py")

configure_file(${SETUP_PY_IN} ${SETUP_PY})



####################################################################
#For installation, we can run setup.py for people automatically (on by default):

file(GLOB win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll")
list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtCore4.dll)
list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtGui4.dll)
if (NOT WITH_STATIC_SBML)
    list(APPEND win_dependencies ${LIBSBML_DLL})
endif()

#Create the 'libantimony.pth' file (which lets users 'import libantimony').
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth" "antimony\n")

#All the files that need to be installed in the python library directory.
file (GLOB antimony_python_files
    ${CMAKE_SOURCE_DIR}/src/bindings/python/__init__.py
    ${CMAKE_CURRENT_BINARY_DIR}/antimony.py
    ${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth
    ${CPACK_PACKAGE_DESCRIPTION_FILE}
    ${CPACK_RESOURCE_FILE_LICENSE}
    ${win_dependencies}
)


if (PYTHON_SYSTEM_INSTALL)
   #Copy all the files into a local 'antimony' directory.
   INSTALL(FILES ${antimony_python_files} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/antimony)
   install(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/antimony)

   #Now run 'python setup.py install' with that directory as the target.
   INSTALL(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E chdir ${CMAKE_CURRENT_BINARY_DIR} ${PYTHON_EXECUTABLE} ${SETUP_PY} install)")
endif()

#...and/or we instead copy antimony_python_files into the install directory, along with setup.py, and let the user run that directly.

set(PYTHON_PACKAGE_INSTALL_DIR "bindings/python")
if (PYTHON_LOCAL_INSTALL)

   INSTALL(FILES ${antimony_python_files}  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony)
   install(TARGETS ${LIBANTIMONY_LIBRARY}  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony)
   INSTALL(FILES ${SETUP_PY}  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})

endif()

if (NOT PYTHON_SYSTEM_INSTALL)
   if (NOT PYTHON_LOCAL_INSTALL)
        message(WARNING "   Python bindings will be created, but not installed.  Install them by hand from ${CMAKE_CURRENT_BINARY_DIR},\n   or turn on PYTHON_SYSTEM_INSTALL and/or PYTHON_LOCAL_INSTALL.")
   endif()
endif()


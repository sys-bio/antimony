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

ADD_CUSTOM_COMMAND(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/antimony.py
    COMMAND "${PYTHON_EXECUTABLE}"
    ARGS    "${CMAKE_CURRENT_SOURCE_DIR}/createAntimonyLib.py"
    COMMENT "Convert header file to ctypes Python bindings.")

set_source_files_properties(${CMAKE_CURRENT_BINARY_DIR}/antimony.py PROPERTIES GENERATED TRUE)

####################################################################
#For installation, we can run setup.py for people automatically (on by default):

file(GLOB win_dependencies "${CMAKE_SOURCE_DIR}/win32/*.dll")
list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtCore4.dll)
list(REMOVE_ITEM win_dependencies ${CMAKE_SOURCE_DIR}/win32/QtGui4.dll)
if (NOT WITH_STATIC_SBML)
    list(APPEND win_dependencies ${LIBSBML_DLL})
endif()

if (PYTHON_SYSTEM_INSTALL)
   INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/antimony.py DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/antimony)
   if (NOT UNIX)
      install(FILES ${win_dependencies} DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/antimony)
   endif()
   INSTALL(CODE "execute_process(COMMAND \"${CMAKE_COMMAND}\" -E chdir ${CMAKE_CURRENT_BINARY_DIR} ${PYTHON_EXECUTABLE} ${SETUP_PY} install)")
endif()

#...and/or we can let them install python bindings in a local directory (off by default).

if (PYTHON_LOCAL_INSTALL)
   set(PYTHON_PACKAGE_INSTALL_DIR "bindings/python")

   file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth" "antimony\n")
   INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/libantimony.pth  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
   INSTALL(FILES ${SETUP_PY}  DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR})
   file(GLOB antimony_python_files "${CMAKE_CURRENT_BINARY_DIR}/antimony/*.*")
   install(FILES ${antimony_python_files} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony )
   INSTALL(FILES ${CMAKE_CURRENT_BINARY_DIR}/antimony.py DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony)
   INSTALL(FILES ${win_dependencies} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony )
   INSTALL(TARGETS ${LIBANTIMONY_LIBRARY} DESTINATION ${PYTHON_PACKAGE_INSTALL_DIR}/antimony)

endif()

if (NOT PYTHON_SYSTEM_INSTALL)
   if (NOT PYTHON_LOCAL_INSTALL)
        message(WARNING "   Python bindings will be created, but not installed.  Install them by hand from ${CMAKE_CURRENT_BINARY_DIR},\n   or turn on PYTHON_SYSTEM_INSTALL and/or PYTHON_LOCAL_INSTALL.")
   endif()
endif()


###############################################################################
#
# Description       : CMake build script for antimony language bindings
# Original author(s): Lucian Smith, from libsbml and Frank Bergmann
#
###############################################################################

#
# When checked removes all generated SWIG wrappers upon configure
#
option(ANTIMONY_REMOVE_WRAPPERS   "Remove generated SWIG wrappers." OFF)
mark_as_advanced(ANTIMONY_REMOVE_WRAPPERS)

#
# and build selected language bindings
#

# antimony_api.h has a couple includes, which are easy enough to follow, and
#  means we don't have to explicitly include them all the time otherwise.
SET(SWIG_EXTRA_ARGS "-includeall")

if(WITH_CSHARP)
add_subdirectory(csharp)
endif()

if(WITH_JAVA)
add_subdirectory(java)
endif()

if(WITH_PERL)
add_subdirectory(perl)
endif()

if(WITH_MATLAB)
add_subdirectory(matlab)
endif()

if(WITH_OCTAVE)
add_subdirectory(octave)
endif()

if(WITH_PYTHON)
add_subdirectory(python)
endif()

if(WITH_RUBY)
add_subdirectory(ruby)
endif()

if(WITH_R)
add_subdirectory(r)
endif()


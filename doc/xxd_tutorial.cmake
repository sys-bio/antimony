# Regenerates QTAntimony_src/Tutorial.xxd (the copy of AntimonyTutorial.htm
# compiled directly into QTAntimony's Help > Tutorial pane, see
# QTAntimony_src/Tutorial.cpp) from the freshly-regenerated
# doc/AntimonyTutorial.htm. Invoked as a 'cmake -P' step from the 'docs'
# target so a missing 'xxd' only warns instead of failing the whole target.
#
# Run from QTAntimony_src with the exact relative path used historically
# (see the comment in Tutorial.cpp) so xxd derives the same C identifiers
# ('___doc_AntimonyTutorial_htm' / '_htm_len') that Tutorial.cpp expects,
# without needing to touch Tutorial.cpp.

execute_process(
    COMMAND ${XXD_EXECUTABLE} -i ../doc/AntimonyTutorial.htm
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/../QTAntimony_src
    OUTPUT_VARIABLE XXD_OUTPUT
    RESULT_VARIABLE XXD_RESULT
    ERROR_VARIABLE XXD_ERROR
    )

# RESULT_VARIABLE may be a non-numeric string (e.g. "No such file or
# directory") if the process couldn't even be launched, rather than an
# integer exit code -- STREQUAL, not EQUAL, so that case compares reliably.
if(NOT XXD_RESULT STREQUAL "0")
    string(LENGTH "${XXD_OUTPUT}" XXD_OUTPUT_LEN)
    if(XXD_OUTPUT_LEN GREATER 500)
        string(SUBSTRING "${XXD_OUTPUT}" 0 500 XXD_OUTPUT_PREVIEW)
        set(XXD_OUTPUT_PREVIEW "${XXD_OUTPUT_PREVIEW}...(truncated)")
    else()
        set(XXD_OUTPUT_PREVIEW "${XXD_OUTPUT}")
    endif()
    message(WARNING "Could not regenerate QTAntimony_src/Tutorial.xxd.\nCommand: ${XXD_EXECUTABLE} -i ../doc/AntimonyTutorial.htm\nWorking directory: ${CMAKE_CURRENT_LIST_DIR}/../QTAntimony_src\nResult: ${XXD_RESULT}\nStderr: ${XXD_ERROR}\nStdout (first 500 chars): ${XXD_OUTPUT_PREVIEW}")
else()
    # Match the hand-edited types Tutorial.cpp expects (see the comment there):
    # xxd's default 'unsigned char ...[]' and 'unsigned int ..._len' become
    # 'const static char ...[]' and 'const static unsigned int ..._len'.
    string(REPLACE "unsigned char " "const static char " XXD_OUTPUT "${XXD_OUTPUT}")
    string(REPLACE "unsigned int " "const static unsigned int " XXD_OUTPUT "${XXD_OUTPUT}")
    file(WRITE ${CMAKE_CURRENT_LIST_DIR}/../QTAntimony_src/Tutorial.xxd "${XXD_OUTPUT}")
    message(STATUS "Regenerated QTAntimony_src/Tutorial.xxd from AntimonyTutorial.htm")
endif()

# Regenerates AntimonyTutorial.pdf via pandoc, invoked as a separate
# 'cmake -P' step (see the 'docs' target in the top-level CMakeLists.txt) so
# that a missing PDF engine only produces a warning instead of failing the
# whole 'docs' target -- pandoc needs a separate PDF engine (a LaTeX
# distribution, wkhtmltopdf, or weasyprint) that may not be installed,
# whereas the .htm/.docx/.rst outputs have no such extra dependency.

execute_process(
    COMMAND ${PANDOC_EXECUTABLE} --toc -s --lua-filter=pandoc_strip_toc_marker.lua AntimonyTutorial.md -o AntimonyTutorial.pdf
    WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
    RESULT_VARIABLE PANDOC_PDF_RESULT
    ERROR_VARIABLE PANDOC_PDF_ERROR
    )

if(NOT PANDOC_PDF_RESULT EQUAL 0)
    message(WARNING "Could not regenerate AntimonyTutorial.pdf -- pandoc needs a PDF engine (a LaTeX distribution, wkhtmltopdf, or weasyprint) installed and on PATH. AntimonyTutorial.htm, .docx, and .rst were still regenerated. Pandoc reported:\n${PANDOC_PDF_ERROR}")
endif()

# Copies assets referenced via raw <img>/<A HREF> tags (rather than
# doxygen's own \image or \include commands, which doxygen would copy
# itself) into the Doxygen output directory. Mirrors the same copy step in
# doc/readthedocs_build.py, used for the Read the Docs build.
# Expects DOC_DIR and OUTPUT_DIR to be set via -D.

file(COPY ${DOC_DIR}/examples DESTINATION ${OUTPUT_DIR}
    PATTERN "cellml_files" EXCLUDE
    PATTERN "cellml_files.zip" EXCLUDE
    )

foreach(name
    Screenshot-windows.png
    Screenshot-macosx.png
    Screenshot-linux.png
    AntimonyTutorial.pdf
    )
    file(COPY ${DOC_DIR}/${name} DESTINATION ${OUTPUT_DIR})
endforeach()

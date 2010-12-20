Thank you for using Antimony, a human-readable, human-writable modular model definition language.

The documentation for this project is in the doc/ subdirectory, and was created with Doxygen.  Described there is information about the Antimony model language and the libAntimony library, including compilation instructions.

To enable full functionality in libAntimony, you first need to install libSBML, available from http://sbml.org/Software/libSBML/.  Beyond that, 'make' will probably work on UNIX and MacOS, there are .vcproj files available for Visual Studio, and you can re-generate both as well as Makefiles for other systems and configurations using qmake.  More details are available in the doc/ subdirectory.

For CellML:

If you want to compile Antimony for CellML, you'll need to figure out a way to compile the CellML API for your system, as well as (currently) OpenCell.  For that, you'll need xulrunner, and *not* the latest version.  This creates problems for me on ubuntu, which I was able to solve by setting the LD_LIBRARY_PATH environment variable:

declare -x LD_LIBRARY_PATH="/home/lpsmith/xulrunner-sdk/lib:/home/lpsmith/xulrunner-sdk/bin"

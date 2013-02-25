Thank you for using Antimony, a human-readable, human-writable modular model definition language.

The documentation for this project is in the doc/ subdirectory, and was created with Doxygen.  Described there is information about the Antimony model language and the libAntimony library, including compilation instructions.

To enable full functionality in libAntimony, you first need to install libSBML, available from http://sbml.org/Software/libSBML/.  Both libSBML and libAntimony now use CMake as their build systems.  For full functionality, be sure to enable the 'comp' package in libsbml, as this enables full hierarchical modeling support.  As of antimony v2.4, all binary releases of the library and executables use the 'comp' package by default.

For CellML:

The CellML API v1.11 SDK was used in this version of Antimony (and QTAntimony) and seems to work OK (despite producing 2.33 billion warnings during compile).  As of this writing, the URL to download the SDK was http://www.cellml.org/tools/downloads/cellml_api/releases/1.11  All that is needed in CMake is to set CELLML_API_INSTALL_DIR to this SDK, and the other CELLML_* variables will be set automatically.

If downloading the SDK does not work (or if it is unavailable for your operating system) it too now uses CMake as its build system, and we have had reasonable success using this on linux-based systems.

What's new in v2.4:
  - Because the SBML 'Hierarchical Model Composition' package has been accepted and is now officially part of SBML (yay!), support for it is now on by default, and has moved out of beta.  Models created using this package should be fully compatible with other programs who also support SBML hierarchy.  Support for 'flattened' models also remains, so core SBML L3v1 models as well as SBML L2 and L1 models can still be exported and imported.)
  - The Tutorial has been updated to include information on all the most recent features.

What's new in v2.3-beta:
  - The ability to import and export SBML models with all the new 2.2 capabilities to 'hierarchical model composition' package constructs.

What's new in v2.2:
  - The ability to define units and use them in mathematical equations.
  - The ability to define conversion factors when synchronizing elements between submodels.
  - The ability to define time and extent conversion factors when importing submodels.
  - The ability to delete submodel elements.

The syntax for each is:

Deletions:
  
  delete A1.x;
  
which will delete the variable 'x' from submodel A1, and will clear any
equations or reactions that had 'x' in it:  if a reaction rate was 'p1*x',
that reaction rate will be cleared entirely (and may be reset using normal
Antimony constructs).

Time and extent conversion factors in submodels:

  A1: submodel(), timeconv=60, extentconv=100;
  
or
  
  A1: submodel(), timeconv=tc, extentconv=xc;
  
(where 'tc' and 'xc' are parameters that may be defined elsewhere) may be
used.

Conversion factors for synchronized variables:

  A1.y * cf is x;
  
or
  
  A1.y is x / cf;




What's new in v2.0:
  - The ability to translate to and from CellML
  - The ability to define events more specifically (following their modification for SBML Level 3)
  - The ability to define irreversible reactions with '=>' instead of '->'.

What's new in v2.1-beta:
  - The ability to import and export SBML models with 'hierarchical model composition' package constructs.


By default, libAntimony will compile as version 2.0.  To compile v2.1-beta from source, you will need the working SVN version of libSBML:

https://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml

plus the working SVN version of the 'comp' package, from:

https://sbml.svn.sourceforge.net/svnroot/sbml/branches/libsbml-packages/comp/

both of which use CMake.  Check out both, then run CMake on the comp package first, telling it where the libsbml source is.  Then make the 'integrate' target, which will copy the source code from the comp package into the libsbml source.  Then run CMake on the libsbml source, making sure to turn on 'ENABLE_COMP', and build the library.

Finally, run CMake on this Antimony distribution, pointing it at your newly-built libsbml-with-comp library, and checking 'WITH_COMP_SBML'.  Assuming everything compiles for you, the library that is then built should call itself 'v2.1-beta', and will be able to read and write comp-enabled SBML models.

# libAntimony
[![GitHub version](https://badge.fury.io/gh/sys-bio%2Fantimony.svg)](http://badge.fury.io/gh/sys-bio%2Fantimony)
[![Build Status](https://github.com/sys-bio/antimony/actions/workflows/main.yml/badge.svg)](https://github.com/sys-bio/antimony/actions/workflows/main.yml/badge.svg)
[![PyPI version](https://badge.fury.io/py/antimony.svg)](https://badge.fury.io/py/antimony)
[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

 <table style="width:100%">
  <tr>
    <td><img alt="PyPI - Downloads", src="https://img.shields.io/pypi/dm/antimony"></td>
    <td><img alt="Funding", src="https://img.shields.io/badge/Funding-NIH%20(GM081070)-blue"></td>
    <td><img alt="Funding", src="https://img.shields.io/badge/Funding-NIH%20(GM123032)-blue"></td>
    <td><img alt="Funding", src="https://img.shields.io/badge/Funding-NIBIB%20(EB028887)-blue"></td>
    <td><img alt="Funding", src="https://img.shields.io/badge/Funding-NSF%20(1933453)-blue"></td>
    <td><img alt="Funding", src="https://img.shields.io/badge/Funding-NIH%20(P41GM109824)-blue"></td>
   </tr>
</table>

# Summary
Antimony is a human-readable, human-writable modular model definition language, letting you create SBML models with a simple text interface, i.e.

```
   S1 -> S2; k1*S1;
   S2 -> S3; k2*S2;
   S1 = 10
   k1 = 0.3
   k2 = 0.1
```

For a working online example, see [MakeSBML](https://sys-bio.github.io/makesbml/)

Antimony is free to use in any application: a simple API is provided to allow Antimony strings to be converted to and from SBML, so the application's users can interact with their models in an easy-to-comprehend format.  C/C++ applications can use the library directly, and Python applications can use the Python bindings.

Documentation can be found:
* [In the doc/ subdirectory](https://github.com/sys-bio/antimony/blob/develop/doc/AntimonyTutorial.md) 
* As part of the [Tellurium Antimony documentation](https://tellurium.readthedocs.io/en/latest/antimony.html)

Since Antimony is used within Tellurium, the general [Tellurium documentation](https://tellurium.readthedocs.io/en/latest/index.html) may also be of interest.

Python bindings are available via pypi, and can be installed with pip:

```pip install antimony```

Other binaries are available from https://github.com/sys-bio/antimony/releases



Antimony depends on the libSBML and SBMLNetwork libraries.  The currently-used versions of each will always be available from https://github.com/sys-bio/libroadrunner-deps/releases/.

Antimony has been supported by NIH/NIGMS Grants GM081070, GM123032, and NIBIB EB028887.


# Building from Source

Here we describe how to build libAntimony from source.  *Note: if these instructions don't work for any reason, look at [the github build instructions](https://github.com/sys-bio/antimony/blob/develop/.github/workflows/main.yml), which will always be up-to-date out of necessity.*

## Install Required Build Tools

Install [CMake](https://cmake.org/). On Windows, you also need to install **Visual Studio** with the **Desktop development with C++** workload, which enables you to run CMake from an MSVC x64 development environment.

To build the Python bindings, install Python and ensure that CMake can locate it.

To build the QtAntimony (the standalone Antimony editor), install Qt 5.15 (or a later version of Qt5) and ensure that CMake can locate it.

If you are actually developing Antimony, you will need the [Bison](https://www.gnu.org/software/bison/) parser to re-generate [src/antimony.tab.cpp](https://github.com/sys-bio/antimony/blob/develop/src/antimony.tab.cpp) from [src/antimony.ypp](https://github.com/sys-bio/antimony/blob/develop/src/antimony.ypp) when the latter changes.

## Download Prebuilt Dependencies

Download the latest version of prebuilt Antimony dependencies that match your operating system, and build type from the [libroadrunner-deps releases page](https://github.com/sys-bio/libroadrunner-deps/releases).  Make sure you get the 'release' version if you are building the release version of Antimony.

If no pre-built dependencies match your operating system, you'll need to find libsbml with the released packages enabled (in particular: comp, fbc, and distrib) and SBMLNetwork.  Libsbml in turn requires an XML library; we recommend using expat.  A CMake system that builds these and a few others is available at [libroadrunner-deps](https://github.com/sys-bio/libroadrunner-deps/); see that repository (and its github build files) for more information.

## Obtain Antimony Source Code

Clone the Antimony repository and enter the source directory:

```bash
git clone https://github.com/sys-bio/antimony.git
cd antimony
```

## Configure with CMake

From the command line (i.e. PowerShell in an MSVC x64 development environment, or a terminal window in MacOS or Linux), enter the following.  Replace `/path/to/libroadrunner-deps-install` with the location of the extracted prebuilt dependencies.

### Windows
```
cmake -S . -B build-antimony `
  -DCMAKE_INSTALL_PREFIX="./install-antimony" `
  -DANT_DEPENDENCIES_INSTALL_PREFIX="C:/path/to/libroadrunner-deps-install" `
  -DCMAKE_BUILD_TYPE=Release `
  -DWITH_PYTHON=ON `
  -DWITH_QTANTIMONY=OFF `
  -DWITH_GTEST=OFF 
```

### MacOS/Linux
```
cmake -S . -B build-antimony \
  -DCMAKE_INSTALL_PREFIX="./install-antimony" \
  -DANT_DEPENDENCIES_INSTALL_PREFIX="/path/to/libroadrunner-deps-install" \
  -DCMAKE_BUILD_TYPE=Release \
  -DWITH_PYTHON=ON \
  -DWITH_QTANTIMONY=OFF \
  -DWITH_GTEST=OFF 
```

### Making changes

The above represents a typical build, but modifications are available:
* If you want to compile for a different architecture than the environment where you're running CMake, use (for example) `-A x86` or `DCMAKE_OSX_ARCHITECTURES="$(uname -m)` 
* If you do want to build QTAntimony, change WITH_QTANTIMONY to ON, and set QT5_DIR to the location of the CMake files where you installed QT5 (i.e. `Qt5.15.16/5.15.16/msvc2019_64/lib/cmake/Qt5`).
* If you don't want the python bindings, change WITH_PYTHON to OFF.
* If you want to build the tests, change WITH_GTEST to ON

## Build and Install

### Windows

```powershell
cmake --build build-antimony --config Release --target install --parallel
```

### macOS and Linux

```bash
cmake --build build-antimony --target install --parallel
```

### Location of files

The compiled files will be installed in the `install-antimony` directory. This directory should now include:

- Antimony libraries in `lib`,
- Public C/C++ header files in `include`,
- If `WITH_PYTHON=ON`, Python bindings in `bindings/python`. This directory can be used to build a Python wheel (see [these instructions](https://packaging.python.org/en/latest/flow/#the-built-distributions-wheels)),
- If `WITH_QTANTIMONY=ON`, the QtAntimony graphical application in `bin`.


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

Here we describe how to build libAntimony from source.

## Install Required Build Tools

Install [CMake](https://cmake.org/). On Windows, you also need to install **Visual Studio** with the **Desktop development with C++** workload, which enables you to run CMake from an MSVC x64 development environment.

To build the Python bindings, install Python and ensure that CMake can locate it.

To build the QtAntimony, install Qt 5.15.2 or later and ensure that CMake can locate it.

## Download Prebuilt Dependencies

Download the latest version of prebuilt Antimony dependencies that match your operating system, and build type from the [libroadrunner-deps releases page](https://github.com/sys-bio/libroadrunner-deps/releases).

## Obtain Antimony Source Code

Clone the Antimony repository and enter the source directory:

```bash
git clone https://github.com/sys-bio/antimony.git
cd antimony
```

## Configure with CMake

### Windows

Run PowerShell in an MSVC x64 development environment, then configure Antimony as follows:

```powershell
cmake -S . -B build-antimony `
  -A x64 `
  -DCMAKE_INSTALL_PREFIX="D:/dev/ant/antimony-install" `
  -DANT_DEPENDENCIES_INSTALL_PREFIX="C:/path/to/libroadrunner-deps" `
  -DWITH_PYTHON=ON `
  -DWITH_QTANTIMONY=OFF `
  -DWITH_GTEST=OFF `
  -DWITH_CELLML=OFF `
  -DBUILD_SHARED_LIBS=ON
```

Replace `C:/path/to/libroadrunner-deps` with the location of the extracted prebuilt dependencies (Remember to use forward slashes in paths passed to CMake).


### macOS

Configure Antimony from the source directory:

```bash
cmake -S . -B build-antimony \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_OSX_ARCHITECTURES="$(uname -m)" \
  -DCMAKE_INSTALL_PREFIX="$PWD/install-antimony" \
  -DANT_DEPENDENCIES_INSTALL_PREFIX="/path/to/libroadrunner-deps" \
  -DWITH_PYTHON=ON \
  -DWITH_QTANTIMONY=OFF \
  -DWITH_GTEST=OFF \
  -DWITH_CELLML=OFF \
  -DBUILD_SHARED_LIBS=ON
```

Replace `/path/to/libroadrunner-deps` with the location of the extracted prebuilt dependencies.

### Linux

Configure Antimony from the source directory:

```bash
cmake -S . -B build-antimony \
  -DCMAKE_BUILD_TYPE=Release \
  -DCMAKE_INSTALL_PREFIX="$PWD/install-antimony" \
  -DANT_DEPENDENCIES_INSTALL_PREFIX="/path/to/libroadrunner-deps" \
  -DWITH_PYTHON=ON \
  -DWITH_QTANTIMONY=OFF \
  -DWITH_GTEST=OFF \
  -DWITH_CELLML=OFF \
  -DBUILD_SHARED_LIBS=ON
```

Replace `/path/to/libroadrunner-deps` with the location of the extracted prebuilt dependencies.


## Build and Install

### Windows

```powershell
cmake --build build-antimony --config Release --target install --parallel
```

### macOS and Linux

```bash
cmake --build build-antimony --target install --parallel
```

The compiled files will be installed in the `install-antimony` directory. This directory should now include:

- Antimony libraries in `lib`,
- Public C/C++ header files in `include`,
- If `WITH_PYTHON=ON`, Python bindings in `bindings/python`. This directory can be used to build a Python wheel (see [these instructions](https://packaging.python.org/en/latest/flow/#the-built-distributions-wheels)),
- If `WITH_QTANTIMONY=ON`, the QtAntimony graphical application in `bin`.


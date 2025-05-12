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

Documentation can be found:
* [In the doc/ subdirectory](https://github.com/sys-bio/antimony/blob/develop/doc/AntimonyTutorial.md) 
* As part of the [Tellurium Antimony documentation](https://tellurium.readthedocs.io/en/latest/antimony.html)

Antimony is free to use in any application: a simple API is provided to allow Antimony strings to be converted to and from SBML, so the application's users can interact with their models in an easy-to-comprehend format.  C/C++ applications can use the library directly, and Python applications can use the Python bindings.

Since Antimony is used within Tellurium, the general [Tellurium documentation](https://tellurium.readthedocs.io/en/latest/index.html) may also be of interest.

Python bindings are available via pypi, and can be installed with pip:

```pip install antimony```

Other binaries are available from https://github.com/sys-bio/antimony/releases



Antimony depends on the libSBML and SBMLNetwork libraries.  The currently-used versions of each will always be available from https://github.com/sys-bio/libroadrunner-deps/.

Antimony has been supported by NIH/NIGMS Grants GM081070, GM123032, and NIBIB EB028887.

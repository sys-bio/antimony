/**
 * @file    local-normal.i
 * @brief   Python-specific SWIG directives for wrapping the antimony API
 * @author  Lucian Smith, from libsbml 
 */


/**
 * Turn on (minimal) Python docstrings and then append our own.
 */
%feature("autodoc", "1");
%include "pydoc.i"


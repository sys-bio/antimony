"""
Julia bindings for libAntimony, a thin layer over the Antimony C API (antimony_api.h).

The shared library is looked up, in order, at:
  1. the path in the ANTIMONY_LIBRARY environment variable,
  2. <install prefix>/lib, when this package sits in <install prefix>/bindings/julia/Antimony,
  3. the system library search path.

Functions are not exported; call them as `Antimony.loadAntimonyString(...)`.
Module indices passed to the library are 0-based, as in the C API.
"""
module Antimony

using Libdl

const _lib = Ref{Ptr{Cvoid}}(C_NULL)

_libname() = "libantimony." * Libdl.dlext

function _library_candidates()
    candidates = String[]
    if haskey(ENV, "ANTIMONY_LIBRARY")
        push!(candidates, ENV["ANTIMONY_LIBRARY"])
    end
    push!(candidates, normpath(joinpath(@__DIR__, "..", "..", "..", "..", "lib", _libname())))
    push!(candidates, _libname())
    return candidates
end

function __init__()
    candidates = _library_candidates()
    for candidate in candidates
        handle = Libdl.dlopen(candidate; throw_error=false)
        if handle !== nothing
            _lib[] = handle
            return
        end
    end
    error("Unable to load libantimony. Tried:\n  " * join(candidates, "\n  ") *
          "\nSet the ANTIMONY_LIBRARY environment variable to the full path of the library.")
end

_sym(name::Symbol) = Libdl.dlsym(_lib[], name)

# Copy of a C string; NULL becomes "".
_str(p::Ptr{UInt8}) = p == C_NULL ? "" : unsafe_string(p)

# Copy of a C string; NULL means the call failed and the library holds the reason.
_checked_str(p::Ptr{UInt8}) = p == C_NULL ? error(getLastAntimonyError()) : unsafe_string(p)

# The load functions return -1 on failure.
function _checked_load(status)
    if status == -1
        error(getLastAntimonyError())
    end
    return Int(status)
end

# The write functions return 0 on failure.
function _checked_write(status)
    if status == 0
        error(getLastAntimonyError())
    end
    return Int(status)
end

###############################################################################
##### Version #####
###############################################################################

"""
    getVersionStr()
Returns the version of libAntimony in use.
"""
function getVersionStr()
    return _str(ccall(_sym(:getVersionStr), Ptr{UInt8}, ()))
end

###############################################################################
##### Input #####
###############################################################################

"""
    loadFile(filename::AbstractString)
Load a file of any format libAntimony knows about (potentially Antimony, SBML, or CellML).
Returns the index of the loaded file.
"""
function loadFile(filename::AbstractString)
    return _checked_load(ccall(_sym(:loadFile), Clong, (Cstring,), filename))
end

"""
    loadString(model::AbstractString)
Load a string of any format libAntimony knows about (potentially Antimony, SBML, or CellML).
Returns the index of the loaded string.
"""
function loadString(model::AbstractString)
    return _checked_load(ccall(_sym(:loadString), Clong, (Cstring,), model))
end

"""
    loadAntimonyFile(filename::AbstractString)
Loads a file and parses it as an Antimony file.
"""
function loadAntimonyFile(filename::AbstractString)
    return _checked_load(ccall(_sym(:loadAntimonyFile), Clong, (Cstring,), filename))
end

"""
    loadAntimonyString(antModel::AbstractString)
Loads a string and parses it as an Antimony set of modules.
"""
function loadAntimonyString(antModel::AbstractString)
    return _checked_load(ccall(_sym(:loadAntimonyString), Clong, (Cstring,), antModel))
end

"""
    loadSBMLFile(filename::AbstractString)
Load a file known to be SBML.
"""
function loadSBMLFile(filename::AbstractString)
    return _checked_load(ccall(_sym(:loadSBMLFile), Clong, (Cstring,), filename))
end

"""
    loadSBMLString(model::AbstractString)
Load a string known to be SBML.
"""
function loadSBMLString(model::AbstractString)
    return _checked_load(ccall(_sym(:loadSBMLString), Clong, (Cstring,), model))
end

"""
    loadSBMLStringWithLocation(model::AbstractString, location::AbstractString)
Load a string known to be SBML, with its file location.
"""
function loadSBMLStringWithLocation(model::AbstractString, location::AbstractString)
    return _checked_load(ccall(_sym(:loadSBMLStringWithLocation), Clong, (Cstring, Cstring), model, location))
end

"""
    loadCellMLFile(filename::AbstractString)
Load a file known to be CellML.
"""
function loadCellMLFile(filename::AbstractString)
    return _checked_load(ccall(_sym(:loadCellMLFile), Clong, (Cstring,), filename))
end

"""
    loadCellMLString(model::AbstractString)
Load a string known to be CellML.
"""
function loadCellMLString(model::AbstractString)
    return _checked_load(ccall(_sym(:loadCellMLString), Clong, (Cstring,), model))
end

"""
    getNumFiles()
Returns the number of files loaded into memory so far.
"""
function getNumFiles()
    return Int(ccall(_sym(:getNumFiles), Culong, ()))
end

"""
    revertTo(index::Integer)
Change the 'active' set of modules to the ones from the given index (as received from 'load<file/string>').
"""
function revertTo(index::Integer)
    if !ccall(_sym(:revertTo), Bool, (Clong,), index)
        error(getLastAntimonyError())
    end
    return nothing
end

"""
    checkModule(moduleName::AbstractString)
Returns true if the submitted module name exists in the current active set, false if not.
"""
function checkModule(moduleName::AbstractString)
    return ccall(_sym(:checkModule), Bool, (Cstring,), moduleName)
end

"""
    clearPreviousLoads()
Clears memory of all files loaded.
"""
function clearPreviousLoads()
    ccall(_sym(:clearPreviousLoads), Cvoid, ())
    return nothing
end

"""
    addDirectory(directory::AbstractString)
Add a directory in which imported files may be found,
and in which to look for a '.antimony' file
(which contains rules about where to look locally for imported antimony and sbml files).
"""
function addDirectory(directory::AbstractString)
    ccall(_sym(:addDirectory), Cvoid, (Cstring,), directory)
    return nothing
end

"""
    clearDirectories()
Clears the list of directories added with the 'addDirectory' function.
"""
function clearDirectories()
    ccall(_sym(:clearDirectories), Cvoid, ())
    return nothing
end

###############################################################################
##### Output #####
###############################################################################

"""
    writeAntimonyFile(filename::AbstractString, moduleName::AbstractString)
Writes out an antimony-formatted file containing the given module.
"""
function writeAntimonyFile(filename::AbstractString, moduleName::AbstractString)
    return _checked_write(ccall(_sym(:writeAntimonyFile), Cint, (Cstring, Cstring), filename, moduleName))
end

"""
    getAntimonyString(moduleName::AbstractString)
Returns the same output as writeAntimonyFile, but as a string instead of to a file.
"""
function getAntimonyString(moduleName::AbstractString)
    return _checked_str(ccall(_sym(:getAntimonyString), Ptr{UInt8}, (Cstring,), moduleName))
end

"""
    writeSBMLFile(filename::AbstractString, moduleName::AbstractString)
Writes out a SBML-formatted XML file to the file indicated.
"""
function writeSBMLFile(filename::AbstractString, moduleName::AbstractString)
    return _checked_write(ccall(_sym(:writeSBMLFile), Cint, (Cstring, Cstring), filename, moduleName))
end

"""
    getSBMLString(moduleName::AbstractString)
Returns the same output as writeSBMLFile, but as a string instead of to a file.
"""
function getSBMLString(moduleName::AbstractString)
    return _checked_str(ccall(_sym(:getSBMLString), Ptr{UInt8}, (Cstring,), moduleName))
end

"""
    writeCompSBMLFile(filename::AbstractString, moduleName::AbstractString)
Writes out a SBML-formatted XML file to the file indicated,
using the 'Hierarchical Model Composition' package.
"""
function writeCompSBMLFile(filename::AbstractString, moduleName::AbstractString)
    return _checked_write(ccall(_sym(:writeCompSBMLFile), Cint, (Cstring, Cstring), filename, moduleName))
end

"""
    getCompSBMLString(moduleName::AbstractString)
Returns the same output as writeCompSBMLFile, but as a string instead of to a file.
"""
function getCompSBMLString(moduleName::AbstractString)
    return _checked_str(ccall(_sym(:getCompSBMLString), Ptr{UInt8}, (Cstring,), moduleName))
end

"""
    writeCellMLFile(filename::AbstractString, moduleName::AbstractString)
Writes out a CellML-formatted XML file to the file indicated,
retaining the same Antimony hierarchy using the CellML 'component' hierarchy.
"""
function writeCellMLFile(filename::AbstractString, moduleName::AbstractString)
    return _checked_write(ccall(_sym(:writeCellMLFile), Cint, (Cstring, Cstring), filename, moduleName))
end

"""
    getCellMLString(moduleName::AbstractString)
Returns the same output as writeCellMLFile, but as a string instead of to a file.
"""
function getCellMLString(moduleName::AbstractString)
    return _checked_str(ccall(_sym(:getCellMLString), Ptr{UInt8}, (Cstring,), moduleName))
end

"""
    printAllDataFor(moduleName::AbstractString)
An example function that prints to stdout all the information in the given module.
"""
function printAllDataFor(moduleName::AbstractString)
    ccall(_sym(:printAllDataFor), Ptr{UInt8}, (Cstring,), moduleName)
    return nothing
end

###############################################################################
##### Errors and Warnings #####
###############################################################################

"""
    getLastAntimonyError()
When any function returns an error condition, a longer description of the problem is
stored in memory, and is obtainable with this function.
"""
function getLastAntimonyError()
    return _str(ccall(_sym(:getLastError), Ptr{UInt8}, ()))
end

"""
    getWarnings()
When translating some other format to Antimony, elements that are unable to be
translated are saved as warnings, retrievable with this function
(returns an empty string if no warnings are present).
"""
function getWarnings()
    return _str(ccall(_sym(:getWarnings), Ptr{UInt8}, ()))
end

"""
    getSBMLInfoMessages(moduleName::AbstractString)
Returns the 'info' messages from libSBML.
"""
function getSBMLInfoMessages(moduleName::AbstractString)
    return _str(ccall(_sym(:getSBMLInfoMessages), Ptr{UInt8}, (Cstring,), moduleName))
end

"""
    getSBMLWarnings(moduleName::AbstractString)
Returns the 'warning' messages from libSBML.
"""
function getSBMLWarnings(moduleName::AbstractString)
    return _str(ccall(_sym(:getSBMLWarnings), Ptr{UInt8}, (Cstring,), moduleName))
end

###############################################################################
##### Modules #####
###############################################################################

"""
    getNumModules()
Returns the number of modules in the current active set
(the last file successfully loaded, or whichever file was returned to with 'revertTo').
"""
function getNumModules()
    return Int(ccall(_sym(:getNumModules), Culong, ()))
end

"""
    getModuleNames()
Returns an array of all the current module names.
"""
function getModuleNames()
    n = getNumModules()
    if n == 0
        return String[]
    end
    names = ccall(_sym(:getModuleNames), Ptr{Ptr{UInt8}}, ())
    return String[unsafe_string(unsafe_load(names, i)) for i in 1:n]
end

"""
    getNthModuleName(n::Integer)
Returns the nth module name (0-based).
"""
function getNthModuleName(n::Integer)
    return _checked_str(ccall(_sym(:getNthModuleName), Ptr{UInt8}, (Culong,), n))
end

"""
    getMainModuleName()
Returns the 'main' module name.
"""
function getMainModuleName()
    return _checked_str(ccall(_sym(:getMainModuleName), Ptr{UInt8}, ()))
end

###############################################################################
##### Memory management #####
###############################################################################

"""
    freeAll()
Frees all pointers handed to you by libAntimony.
"""
function freeAll()
    ccall(_sym(:freeAll), Cvoid, ())
    return nothing
end

end # module Antimony

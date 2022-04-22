"""
Finds and renames the local Antimony wheel file to work with any Python version.

Usage:

    python renameWheel.py

For example:

    python renameWheel.py

"""


from os import walk, rename

wfiles = []
for __, _, files in walk("."):
    wfiles += files

for file in wfiles:
    if ".whl" not in file:
        continue
    fvec = file.split("-")
    fvec[2] = "py3"
    fvec[3] = "none"
    if "linux_" in fvec[4]:
        fvec[4] = fvec[4].replace("linux_", "manylinux2014_")
    newname = ""
    for fpart in fvec:
        newname += "-" + fpart
    newname = newname[1:]
    rename(file, newname)


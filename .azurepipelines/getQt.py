"""
Get qt from url.

Usage:

    python getQt.py <qt_download_link> <qt_install_prefix?

For example:

    python getQt.py https://github.com/sys-bio/antimony/releases/download/libcheck/Qt5.15.2.msvc.zip qt

"""


import glob
import argparse
import os
from os.path import join, splitext, isdir, isfile
import zipfile
import tarfile
import requests
import io
import shutil

# command line arguments
parser = argparse.ArgumentParser()
parser.add_argument("qt_download_link", type=str, help="Url to compressed qt link to download")
parser.add_argument("qt_install_prefix", type=str, help="Where to install qt (directory that will contain bin, include, lib etc")
args = parser.parse_args()

# filename of downloaded zip, qt-[debug|release].zip
compressed_qt_filename = args.qt_download_link.split('/')[-1]

# absolute path to compressed_qt_filename
abs_compressed_qt_filename = join(args.qt_install_prefix, compressed_qt_filename)

# e.g. ('qt--[debug|release]', '.zip')
downloaded_qt_folder, ext = splitext(compressed_qt_filename)
# when link is tar.gz, get rid of extra .tar
if ".tar" in downloaded_qt_folder:
    downloaded_qt_folder = downloaded_qt_folder.replace(".tar", "")

# make install prefix if not exists
if not isdir(args.qt_install_prefix):
    os.makedirs(args.qt_install_prefix)

print("compressed_qt_filename".ljust(20), compressed_qt_filename)
print("abs_compressed_qt_filename".ljust(20), abs_compressed_qt_filename)
print("downloaded_qt_folder".ljust(20), downloaded_qt_folder)
print("args.qt_download_link".ljust(20), args.qt_download_link)
print("downloaded_qt_folder, ext".ljust(20), downloaded_qt_folder, ext)

# we expect a folder called bin in
abs_downloaded_qt_folder = join(args.qt_install_prefix, downloaded_qt_folder)

# Don't download if we already have it
if not isdir(join(abs_downloaded_qt_folder, "5.15.2")):
    print("downloading qt from {}".format(args.qt_download_link))
    r = requests.get(args.qt_download_link, stream=True)
    if ext == ".zip":
        z = zipfile.ZipFile(io.BytesIO(r.content))
        z.extractall(args.qt_install_prefix)
    elif ext == ".gz":
        z = tarfile.open(fileobj=r.raw, mode="r|gz")
        z.extractall(args.qt_install_prefix)
    else:
        raise ValueError("Unsupported extension")
else :
    print("Found existing qt, not downloading qt")

# move from unzip dir to qt_install_prefix
folders = glob.glob(join(abs_downloaded_qt_folder, "*"))
print(folders)
for f in folders:
    shutil.move(f, args.qt_install_prefix)


if isfile(abs_compressed_qt_filename):
    os.remove(abs_compressed_qt_filename)







"""
Get check from url.

Usage:

    python getCheck.py <check_download_link> <check_install_prefix?

For example:

    python getcheck.py https://github.com/sys-bio/check-13.x/releases/download/checkorg-13.0.0/check13-ubuntu-gcc10-rel.tar.gz /mnt/d/roadrunner/roadrunner/check-download-test/ubuntu

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
parser.add_argument("check_download_link", type=str, help="Url to compressed check link to download")
parser.add_argument("check_install_prefix", type=str, help="Where to install check (directory that will contain bin, include, lib etc")
args = parser.parse_args()

# filename of downloaded zip, check-[debug|release].zip
compressed_check_filename = args.check_download_link.split('/')[-1]

# absolute path to compressed_check_filename
abs_compressed_check_filename = join(args.check_install_prefix, compressed_check_filename)

# e.g. ('check--[debug|release]', '.zip')
downloaded_check_folder, ext = splitext(compressed_check_filename)
# when link is tar.gz, get rid of extra .tar
if ".tar" in downloaded_check_folder:
    downloaded_check_folder = downloaded_check_folder.replace(".tar", "")

# make install prefix if not exists
if not isdir(args.check_install_prefix):
    os.makedirs(args.check_install_prefix)

print("compressed_check_filename".ljust(20), compressed_check_filename)
print("abs_compressed_check_filename".ljust(20), abs_compressed_check_filename)
print("downloaded_check_folder".ljust(20), downloaded_check_folder)
print("args.check_download_link".ljust(20), args.check_download_link)
print("downloaded_check_folder, ext".ljust(20), downloaded_check_folder, ext)

# we expect a folder called bin in
abs_downloaded_check_folder = join(args.check_install_prefix, downloaded_check_folder)

# Don't download if we already have it
if not isdir(join(abs_downloaded_check_folder, "bin")):
    print("downloading check from {}".format(args.check_download_link))
    r = requests.get(args.check_download_link, stream=True)
    if ext == ".zip":
        z = zipfile.ZipFile(io.BytesIO(r.content))
        z.extractall(args.check_install_prefix)
    elif ext == ".gz":
        z = tarfile.open(fileobj=r.raw, mode="r|gz")
        z.extractall(args.check_install_prefix)
    else:
        raise ValueError("Unsupported extension")
else :
    print("Found existing check, not downloading check")

# move from unzip dir to check_install_prefix
folders = glob.glob(join(abs_downloaded_check_folder, "*"))
print(folders)
for f in folders:
    shutil.move(f, args.check_install_prefix)


if isfile(abs_compressed_check_filename):
    os.remove(abs_compressed_check_filename)







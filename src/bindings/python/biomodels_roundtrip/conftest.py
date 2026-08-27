import os

import pytest


def pytest_addoption(parser):
    parser.addoption(
        "--biomodels-dir",
        action="store",
        default=os.environ.get("BIOMODELS_DIR"),
        help="Path to a temp-biomodels checkout produced by fetch_biomodels.py "
             "(the directory containing 'final/'). May also be set via the "
             "BIOMODELS_DIR environment variable.",
    )

import os

import pytest


def pytest_addoption(parser):
    parser.addoption(
        "--sbml-test-suite-dir",
        action="store",
        default=os.environ.get("SBML_TEST_SUITE_DIR"),
        help="Path to the SBML Test Suite 'semantic' cases directory (the one "
             "containing numbered subdirectories like 00001/, 00002/, ...). "
             "May also be set via the SBML_TEST_SUITE_DIR environment variable.",
    )

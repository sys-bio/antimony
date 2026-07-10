/**
 * \file    main.cpp
 * \brief   Shared main() and test-data-directory setup for all antimony
 *          GoogleTest binaries. Compiled into every test_antimony_* target.
 * ---------------------------------------------------------------------- -->*/

#include <cstdlib>
#include <cstring>
#include <string>

#include "libutil.h"
#include "registry.h"

#include "gtest/gtest.h"

using std::string;

/**
 * Global.
 *
 * Declared extern in the various TestAntimony* files. A plain std::string
 * (rather than a heap-allocated char*) so it cleans up after itself via its
 * own destructor when the program exits -- no manual free() to remember,
 * and valgrind doesn't see it as "still reachable" at exit the way a raw
 * calloc'd buffer would be.
 */
string TestDataDirectory;

/**
 * Sets TestDataDirectory for the TestReadFromFileN suites.
 *
 * Preference order:
 *   1. The "srcdir" environment variable, if set (lets CI/ctest/distcheck
 *      point at a different checkout).
 *   2. ANTIMONY_TEST_SRC_DIR, a compile-time constant baked in by
 *      src/test/CMakeLists.txt (see target_compile_definitions) that holds
 *      the absolute path to this source directory. This is what makes the
 *      tests work when launched by something other than ctest (e.g. Visual
 *      Studio's Test Explorer, or double-clicking the .exe), where no one
 *      sets "srcdir" for us.
 */
void
setTestDataDirectory(void)
{
    const char *srcdir = getenv("srcdir");
#if defined(ANTIMONY_TEST_SRC_DIR)
    if (srcdir == NULL || strlen(srcdir) == 0)
    {
        srcdir = ANTIMONY_TEST_SRC_DIR;
    }
#endif
    if (srcdir != NULL)
    {
        TestDataDirectory = srcdir;
        TestDataDirectory += "/";
    }

    TestDataDirectory += "test-data/";
}

int
main(int argc, char **argv)
{
    g_registry.SetWriteNameToSBML(false);
    g_registry.SetRemoveFunctionDefinitions(false);

    setTestDataDirectory();

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

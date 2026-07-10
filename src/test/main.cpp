/**
 * \file    main.cpp
 * \brief   Shared main() and test-data-directory setup for all antimony
 *          GoogleTest binaries. Compiled into every test_antimony_* target.
 * ---------------------------------------------------------------------- -->*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "libutil.h"
#include "registry.h"

#include "gtest/gtest.h"

/**
 * Global.
 *
 * Declared extern in the various TestAntimony* files.
 */
char *TestDataDirectory;

/**
 * Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory. The memory is set to zero.
 * If the memory could not be allocated, prints an error message and exits.
 */
void *
ant_safe_calloc(size_t nmemb, size_t size)
{
    void *p = (void *)calloc(nmemb, size);

    if (p == NULL)
    {
        fprintf(stderr, "libantimony error:  out of memory.");
        exit(-1);
    }

    return p;
}

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
    size_t length = (srcdir == NULL) ? 0 : strlen(srcdir);

    /**
     * strlen("/test-data/") = 11 + 1 (for NULL) = 12
     */
    TestDataDirectory = (char *)ant_safe_calloc(length + 12, sizeof(char));

    if (srcdir != NULL)
    {
        strcpy(TestDataDirectory, srcdir);
        strcat(TestDataDirectory, "/");
    }

    strcat(TestDataDirectory, "test-data/");
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

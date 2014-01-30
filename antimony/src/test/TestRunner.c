/**
 * \file    TestRunner.c
 * \brief   Runs all unit tests in the sbml module
 * \author  Ben Bornstein
 * 
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2013 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <string.h>
#include <stdlib.h>

#include "libutil.h"
#include "registry.h"

#include <check.h>


/**
 * Test suite creation function prototypes.
 *
 * These functions are needed only for calls in main() below.  Therefore a
 * separate header file is not necessary and only adds a maintenance burden
 * to keep the two files synchronized.
 */
BEGIN_C_DECLS


Suite *create_suite_Basic(void);
Suite *create_suite_Hierarchy(void);
Suite *create_suite_Flattening(void);
Suite *create_suite_FlatteningFailures(void);
/**
 * Global.
 *
 * Declared extern in TestReadFromFileN suites.
 */
char *TestDataDirectory;

/**
 * Allocates memory for an array of nmemb elements of size bytes each and
 * returns a pointer to the allocated memory.  The memory is set to zero.
 * If the memory could not be allocated, prints an error message and exits.
 */
void *
safe_calloc (size_t nmemb, size_t size)
{
  void *p = (void *) calloc(nmemb, size);


  if (p == NULL)
  {
    fprintf(stderr, "libantimony error:  out of memory.");
    exit(-1);
  }

  return p;
}


/**
 * Sets TestDataDirectory for the the TestReadFromFileN suites.
 *
 * For Automake's distcheck target to work properly, TestDataDirectory must
 * begin with the value of the environment variable SRCDIR.
 */
void
setTestDataDirectory (void)
{
  char *srcdir = getenv("srcdir");
  int  length  = (srcdir == NULL) ? 0 : strlen(srcdir);


  /**
   * strlen("/test-data/") = 11 + 1 (for NULL) = 12
   */
  TestDataDirectory = (char *) safe_calloc( length + 12, sizeof(char) );

  if (srcdir != NULL)
  {
    strcpy(TestDataDirectory, srcdir);
    strcat(TestDataDirectory, "/");
  }

  strcat(TestDataDirectory, "test-data/");
}


int
main (int argc, char* argv[]) 
{ 
  int num_failed;
  g_registry.SetWriteNameToSBML(false);

  setTestDataDirectory();

  SRunner *runner = srunner_create( create_suite_Basic() );
  //SRunner *runner = srunner_create( create_suite_Hierarchy() );
  //SRunner *runner = srunner_create( create_suite_Flattening() );
  srunner_add_suite( runner, create_suite_Hierarchy() );
  //srunner_add_suite( runner, create_suite_Flattening() );
  //srunner_add_suite( runner, create_suite_FlatteningFailures() );


#ifdef TRACE_MEMORY
  srunner_set_fork_status(runner, CK_NOFORK);
#else
  if (argc > 1 && !strcmp(argv[1], "-nofork"))
  {
    srunner_set_fork_status( runner, CK_NOFORK );
  }
#endif

  srunner_run_all(runner, CK_NORMAL);
  num_failed = srunner_ntests_failed(runner);

#ifdef TRACE_MEMORY

  if (MemTrace_getNumLeaks() > 0)
  {
    MemTrace_printLeaks(stdout);
  }

  MemTrace_printStatistics(stdout);

#endif

  srunner_free(runner);

  return num_failed;
}

END_C_DECLS

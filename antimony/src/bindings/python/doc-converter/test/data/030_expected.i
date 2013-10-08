%feature("docstring") SBMLDocument "
 Container for an SBML document and interface for global operations
 on SBML documents.

 LibSBML uses the class SBMLDocument as a  top-level container for
 storing SBML content and data associated with it  (such as warnings
 and error messages).  The two primary means of reading  an SBML
 model, SBMLReader.readSBML() and  SBMLReader.readSBMLFromString(),
 both return a pointer to an  SBMLDocument object.  From there,
 callers can inquire about any errors  encountered (e.g., using
 SBMLDocument.getNumErrors()), access the Model  object, and perform
 other actions such as consistency-checking and model  translation.

 When creating fresh models programmatically, the starting point is
 typically the creation of an SBMLDocument object instance.  The
 SBMLDocument constructor accepts arguments for the SBML Level and
 Version of the model to be created.  After creating the SBMLDocument
 object, calling programs then typically call
 SBMLDocument.createModel()  almost immediately, and then proceed to
 call the methods on the Model  object to fill out the model's
 contents.

 SBMLDocument corresponds roughly to the class Sbml defined in the
 SBML Level 2 specification and SBML in the Level 3  specification.
 It does not have a direct correspondence in SBML  Level 1.  (However,
 to make matters simpler for applications,  libSBML creates an
 SBMLDocument no matter whether the model is  Level 1, Level 2 or
 Level 3.)  In its barest form, when written out in  XML format for
 (e.g.) SBML Level 2 Version 4, the corresponding  structure is the
 following:

     <sbml xmlns=\'http://www.sbml.org/sbml/level2/version4\' level=\'2\' version=\'4\'>
        ...
      </sbml>

  SBMLDocument is derived from SBase, and therefore contains the usual
 SBase  attributes (in SBML Level 2 and Level 3) of 'metaid' and
 'sboTerm', as  well as the subelements 'notes' and 'annotation'.  It
 also contains the  attributes 'level' and 'version' indicating the
 Level and Version of the  SBML data structure.  These can be accessed
 using the methods defined by  the SBase class for that purpose.

 Checking consistency and adherence to SBML  specifications
 ======================================================================

 One of the most important features of libSBML is its ability to
 perform  SBML validation to ensure that a model adheres to the SBML
 specification  for whatever Level+Version combination the model uses.
 SBMLDocument  provides the methods for running consistency-checking
 and validation  rules on the SBML content.

 First, a brief explanation of the rationale is in order.  In libSBML
 versions up to and including the version 3.3.x series, the
 individual methods for creating and setting attributes and other
 components were quite lenient, and allowed a caller to compose SBML
 entities that might not, in the end, represent valid SBML.  This
 allowed  applications the freedom to do things such as save
 incomplete models  (which is useful when models are being developed
 over long periods of  time).  In the version 4.x series, libSBML is
 somewhat stricter,  but still permits structures to be created
 independently and the results  to be combined in a separate step.  In
 all these cases, it means that a  separate validation step is
 necessary when a calling program finally  wants to finish a complete
 SBML document.

 The primary interface to this validation facility is SBMLDocument's
 SBMLDocument.checkInternalConsistency() and
 SBMLDocument.checkConsistency().  The former verifies the basic
 internal consistency and syntax of an SBML document, and the latter
 implements more elaborate validation rules (both those defined by the
 SBML specifications, as well as additional rules offered by libSBML).

 The checks performed by SBMLDocument.checkInternalConsistency() are
 hardwired and cannot be changed by calling programs, but the
 validation  performed by SBMLDocument.checkConsistency() is under
 program control  using the method
 SBMLDocument.setConsistencyChecks().  Applications can  selectively
 disable specific kinds of checks that they may not be  interested in,
 by calling SBMLDocument.setConsistencyChecks() with  appropriate
 parameters.

 These methods have slightly different relevance depending on whether
 a  model is created programmaticaly from scratch, or whether it is
 read in  from a file or data stream.  The following table summarizes
 the possible  scenarios.

 <center>  <table border='0' class='text-table width80 normal-font
 alt-row-colors'>   <tr style='background: lightgray; font-size:
 14px;'>       <th align='left' width='200'>Scenario</th>       <th
 align='left'>Relevant methods</th>   </tr>  <tr><td>Creating a model
 from scratch</td>  <td>Before writing out the model:<ol>

 * Call  SBMLDocument.checkInternalConsistency(), then inquire about
 the results by  calling SBMLDocument.getNumErrors()</li>

 *   Call SBMLDocument.setConsistencyChecks()  to configure which
 checks  will be performed by SBMLDocument.checkConsistency()</li>

 * Call SBMLDocument.checkConsistency(), then inquire about the
 results by  calling SBMLDocument.getNumErrors()</li>  </ol>  </td>
 <tr><td>Reading a model from a file or data stream</td>  <td>After
 reading the model:<ol>

 * Basic consistency checks will have been  performed automatically by
 libSBML upon reading the content -- only need  to inquire about the
 results by using SBMLDocument.getNumErrors()</li>

 *   Call SBMLDocument.setConsistencyChecks()  to configure which
 checks are performed by SBMLDocument.checkConsistency()</li>

 * Call SBMLDocument.checkConsistency(), then inquire about the
 results  by calling SBMLDocument.getNumErrors()</li>  </ol>  </td>
 </table>  </center>

   Converting documents between Levels and  Versions of SBML
 ======================================================================

 LibSBML provides facilities for limited translation of SBML between
 Levels and Versions of the SBML specifications.  The method for doing
 is  is setLevelAndVersion() .  In   general, models can be converted
 upward without difficulty (e.g., from  SBML Level 1 to Level 2, or
 from an earlier Version of  Level 2 to the latest Version of Level
 2).  Sometimes models  can be translated downward as well, if they do
 not use constructs  specific to more advanced Levels of SBML.

 Calling SBMLDocument.setLevelAndVersion()  will not necessarily lead
 to a successful conversion.  The method will return a boolean value
 to indicate success or failure.  Callers must check the error log
 (see   next section) attached to the SBMLDocument object after
 calling  SBMLDocument.setLevelAndVersion()  in order to assess
 whether any  problems arose.

 If an application is interested in translating to a lower Level
 and/or  Version of SBML within a Level, the following methods allow
 for prior  assessment of whether there is sufficient compatibility to
 make a  translation possible:

     *  SBMLDocument.checkL1Compatibility(),

   *  SBMLDocument.checkL2v1Compatibility(),

   *  SBMLDocument.checkL2v2Compatibility(),

   *  SBMLDocument.checkL2v3Compatibility(),

   *  SBMLDocument.checkL2v4Compatibility(), and

   *  SBMLDocument.checkL3v1Compatibility().

 Some changes between Versions of SBML Level 2 may lead to  unexpected
 behaviors when attempting conversions in either direction.  For
 example, SBML Level 2 Version 4 relaxed the requirement  for
 consistency in units of measurement between expressions annd
 quantities in a model.  As a result, a model written in Version 4,
 if converted to Version 3 with no other changes, may fail  validation
 as a Version 3 model because Version 3 imposed  stricter requirements
 on unit consistency.

 Other changes between SBML Level 2 and Level 3 make downward
 conversions  challenging.  In some cases, it means that a model
 converted to  Level 2 from Level 3 will contain attributes that were
 not  explicitly given in the Level 3 model, because in Level 2  these
 attributes may have been optional or have default values.

 Error handling
 ======================================================================

 Upon reading a model, SBMLDocument logs any problems encountered
 while  reading the model from the file or data stream.  The log
 contains  objects that record diagnostic information about any
 notable issues that  arose.  Whether the problems are warnings or
 errors, they are both  reported through a single common interface
 involving the object class  SBMLError.

 The methods SBMLDocument.getNumErrors(), SBMLDocument.getError()  and
 SBMLDocument.printErrors() allow callers to interact with the
 warnings  or errors logged.  Alternatively, callers may retrieve the
 entire log as  an SBMLErrorLog object using the method
 SBMLDocument.getErrorLog().  The SBMLErrorLog object provides some
 alternative methods for  interacting with the set of errors and
 warnings.  In either case,  applications typically should first call
 SBMLDocument.getNumErrors() to  find out if any issues have been
 logged after specific libSBML  operations such as the ones discussed
 in the sections above.  If they  have, then an application will
 should proceed to inspect the individual  reports using either the
 direct interfaces on SBMLDocument or using the  methods on the
 SBMLErrorLog object.
";


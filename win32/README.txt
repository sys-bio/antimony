To use these Windows executables:
   * QTAntimony is a simple editor that can convert models between Antimony, SBML, 
     and CellML.  It can read Antimony, SBML, and CellML files, and you can 
     edit any and translate between them.  Do note that if you convert one 
     format to the other, modify the latter, then translate it back, you will 
     often lose information in the process--any annotation or unit definitions
     in the SBML file will not survive the round-trip, for example.  However, 
     it should be enough to get started with the language and start to 
     experiment.

   * Example models are available in the Antimony directory.  Assuming you
     installed this in the default location, you'll find them in:

     C:\Program Files\Antimony

     and the suite of antimony-translated BioModels (http://biomodels.net/) in:

     C:\Program Files\Antimony\biomodels

   * The easiest way to run the converters is from the command line (just 
     double-clicking on the .exe will pop up a window with an error). 
     To do this:
       - Copy any models you want to convert into this folder.
       - Click 'Start', then 'Run', and type 'cmd'.  A window will pop up.
       - Type 'cd <directory>' where <directory> is where you put the folder
         (for example, 'cd Desktop\antimony\')
       - To convert SBML files to Antimony, type:

       sbml2antimony.exe <inputfile.xml> [<inputfile2.xml>] [...]

       This will produce antimony files with the same names as the inputfiles
       with '.xml' removed (if it was there) and '.txt' appended.  It will
       also create the antimony file in the current (working) directory,
       even if the original files are in a different directory.

       For example, to convert the provided SBML input file (an oscillator) 
       from the doc/examples/ directory, type:

       sbml2antimony.exe ex_sbml_input.xml

       - To convert all models in Antimony files to SBML files, type:

       antimony2sbml.exe <inputfile.txt> [<inputfile2.xml>] [...]

       This will create one or more output files, each with the same name
       as the inputfiles, with '.txt' removed (if present), and 
       '_<modelname>.xml' appended, where <modelname> is the name of the
       model in the Antimony file.  As Antimony files may have more than one
       model in them, converting a single Antimony file to SBML can create
       multiple SBML files.

       For example, to convert the provided Antimony input file models (in
       the doc/examples/ directory) to SBML, copy the file to this
       directory and type:

       antimony2sbml.exe ex_antimony_input.txt

       Which will create the files:

        ex_sbml_input_bistable_sbml.xml
        ex_sbml_input_combined_model_sbml.xml
        ex_sbml_input_ffn_sbml.xml
        ex_sbml_input_ringoscil_sbml.xml
        ex_sbml_input___main_sbml.xml

       If you don't want to create models in this folder all the time,
       you can cd into a directory containing the models you want to
       convert and run the converter from there by calling it explicitly by
       typing (for example) "c:\Program Files\Antimony\antimony2sbml.exe",
       depending on where you put the  folder.  (It is also possible to
       install the dll's somewhere or add the converter folder's name to
       your PATH, but if you know what I'm talking about, you know how to
       do it.)  


If you have any questions or problems, please feel free to contact us at 

lpsmith@u.washington.edu

For more information, visit the Antimony web site at

http://antimony.sf.net/

Thank you!

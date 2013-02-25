To use these Windows executables:
   * QTAntimony is a simple editor that can convert models between Antimony,
     SBML, and CellML.  It can read Antimony, SBML, and CellML files, and you
     can edit any and translate between them.  Do note that if you convert one 
     format to the other, modify the latter, then translate it back, you will 
     often lose information in the process--any annotation or unit definitions
     in the SBML file will not survive the round-trip, for example.  However, 
     it should be enough to get started with the language and start to 
     experiment.

   * While specific translators still exist, 'sbtranslate' can be used to
     convert between formats that Antimony understands.  The precompiled
     binary can be used to convert files between Antimony, SBML, and CellML.

     You must use at least one of the following options to set the output format
     of this translator:

        -o antimony : Output all models in Antimony format
        -o sbml     : Output the 'main' model as SBML
        -o sbml-comp: Output all models in a single SBML file using the
                       (unoffical) 'comp' package.
        -o allsbml  : Output each model and submodel as a separate SBML model
        -o cellml   : Output the 'main' model as CellML

     Each file will be exported to the desired format separately.  Multiple output
     formats are possible; a separate '-o [format]' is needed for each output format.
     This means that if you give sbtranslate two input files and two output formats,
     it will write four files by default: one for each file in each format.

     sbtranslate takes as input any number of valid model files in any of the
     formats it understands.  If no files are provided, it reads input from stdin
     and attempts to parse that in one of its known model formats.

     By default, sbtranslate will output files in the working directory with the
     same name as the original file, minus that file's extention, plus '.txt' for
     antimony output, '.xml' for SBML output, and '.cellml' for CellML output (when
     available).  If the file was originally in the same format as the desired
     output, '_rt' (for 'roundtrip') is appended to the filename before the
     extention.  If the input was stdin, output will by default be written to
     stdout.

     To change this behavior, the following options may be used:
        -outfile [filename] : All output is written to the given file.
        -prefix [prefix]    : All outfiles are prepended with the given
                              prefix.
        -d [directory]      : This directory will be used to search for
                              imported files if the normal import routines do
                              not work.  This directory is also used to
                              search for any '.antimony' files, which are used
                              to map import directives to actual files.
        -stdin    : Input is read from stdin, in addition to any files that
                    might be listed.
        -stdout   : All output is written to standard output.  No files are
                    created.
        -dirsort  : If the input filenames include the name of the directory
                    they are in, the corresponding output files are written out
                    to a subdirectory of the working directory with the same
                    name.  If '-prefix' is used in conjunction with this
                    option, that prefix is prepended to the directory name
                    (and if it includes a slash, may itself be a directory).

   * Example models are available in the Antimony directory.  Assuming you
     installed this in the default location, you'll find them in:

     C:\Program Files\Antimony

     and the suite of antimony-translated BioModels (http://biomodels.net/) in:

     C:\Program Files\Antimony\biomodels


If you have any questions or problems, please feel free to contact the author at 

lpsmith@u.washington.edu

For more information, visit the Antimony web site at

http://antimony.sf.net/

Thank you!

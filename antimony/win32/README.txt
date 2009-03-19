To use these Windows executables:
   * Copy this folder where you want it, keeping the .exe's and the .dll's 
     together in the same directory.

   * If you do *not* have Visual Studio 2008 installed, you will need to run 
     the provided executable 'vcredist_x86.exe'.  This was obtained from 
     Microsoft's web site 

     http://www.microsoft.com/downloads/details.aspx?FamilyID=9B2DA534-3E03-4391-8A4D-074B9F2BC1BF

     If you are a developer using a different version of Visual Studio, you 
     should probably just compile libAntimony yourself.  But if all you want 
     is to run the two converters (antimony2sbml and sbml2antimony), run this 
     to install the required libraries.

   * The easiest way to run the converters is from the command line (just 
     double-clicking on the .exe will pop up a window with an error). 
     To do this:
       - Copy any models you want to convert into this folder.
       - Click 'Start', then 'Run', and type 'cmd'.  A window will pop up.
       - Type 'cd <directory>' where <directory> is where you put the folder
         (for example, 'cd Desktop\antimony\')
       - To convert an SBML file to Antimony, type:

       sbml2antimony.exe <inputfile.xml> <outputfile.txt>

       For example, to convert the provided SBML input file (an oscillator) 
       type:

       sbml2antimony.exe ex_sbml_input.xml ex_antimony_output.txt

       - To convert all models in an Antimony file to SBML files, type:

       antimony2sbml.exe <inputfile.txt> <outputfileprefix>

       This will create one or more output files of the format:

       outputfileprefix_[model1].xml
       outputfileprefix_[model2].xml
       [etc.]

       where [model1] and [model2] are the actual names of the models in the 
       Antimony file.

       For example, to convert the provided Antimony input file models to 
       SBML, type:

       antimony2sbml.exe ex_antimony_input.txt ex_sbml_output

       Which will create the files:

        ex_sbml_output_bistable_sbml.xml
        ex_sbml_output_combined_model_sbml.xml
        ex_sbml_output_ffn_sbml.xml
        ex_sbml_output_ringoscil_sbml.xml
        ex_sbml_output___main_sbml.xml

        If you don't include the output file name or prefix, the program will 
        remove '.xml' from SBML files (if present) and add '.txt', or will 
        remove '.txt' from Antimony files (if present) and use the result as 
        the output file prefix instead.


If you don't want to copy the models into this folder all the time, you can cd 
into a directory containing the models you want to convert and run the
converter from there by calling it explicitly by typing (for example) 
"c:\Program Files\Antimony\antimony2sbml.exe", depending on where you put the 
folder.  (It is also possible to install the dll's somewhere or add the 
converter folder's name to your PATH, but if you know what I'm talking about, 
you know how to do it.)  

If you have any questions or problems, please feel free to contact us at 

lpsmith@u.washington.edu

Thank you!
#include <iostream>
#include <sstream>
#include <vector>
#include "antimony_api.h"

#ifdef WIN32
#include <conio.h>
#endif

using namespace std;
bool CaselessStrCmp(const string& lhs, const string& rhs);

int main(int argc, char** argv)
{
  int retval = 0;
  string instructions = "This version of sbtranslate can be used to convert files between Antimony";
  string options = "";
  options += "\n\t-o antimony : Output all models in Antimony format";
#ifndef NSBML
  options += "\n\t-o sbml     : Output the 'main' model as SBML";
  options += "\n\t-o allsbml  : Output each model and submodel as a separate SBML model";
#ifndef NCELLML
  options += "\n\t-o cellml   : Output the 'main' model as CellML";
  instructions += ", SBML, and CellML.";
#else
  instructions += " and SBML.";
#endif
#else
#ifndef NCELLML
  instructions += " and CellML.";
  options += "\n\t-o cellml   : Output the 'main' model as CellML";
#else
  instructions += " and... Antimony.  Because this program was compiled without using either libsbml or libcellml, which kind of makes translation to those formats difficult.  But hey!  You can still use it to round-trip your models to regularize them and clean up any bits where you might have defined an element multiple times or something.  I guess.  You still have to use '-o antimony' to set the output format, because if you got used to round-tripping your models with the program compiled this way, sure enough someone (like you) would come along and recompile the program with SBML and/or CellML support back in, and then your old scripts wouldn't work.  So I'm saving you from yourself here; you should thank me.";
#endif
#endif
  instructions += "\n\nYou must use at least one of the following options to set the output format of this translator:\n";
  instructions += options;
  instructions += "\n\nEach file will be exported to the desired format separately.  Multiple output formats are possible; a separate '-o [format]' is needed for each output format.  This means that if you give sbtranslate two input files and two output formats, it will write four files by default: one for each file in each format.";
  instructions += "\n\nsbtranslate takes as input any number of valid model files in any of the formats it understands.  If no files are provided, it reads input from stdin and attempts to parse that in one of its known model formats.";
  instructions += "\n\nBy default, sbtranslate will output files in the working directory with the same name as the original file, minus that file's extention, plus '.txt' for antimony output, '.xml' for SBML output, and '.cellml' for CellML output (when available).  If the file was originally in the same format as the desired output, '_rt' (for 'roundtrip') is appended to the filename before the extention.  If the input was stdin, output will by default be written to stdout.";
  instructions += "\n\nTo change this behavior, the following options may be used:";
  instructions += "\n\t-outfile [filename]     : All output is written to the given file.";
  instructions += "\n\t-outfileprefix [prefix] : All outfiles are prepended with the given prefix.";
  instructions += "\n\t-stdin    : Input is read from stdin, in addition to any files that might be listed.";
  instructions += "\n\t-stdout   : All output is written to standard output.  No files are created.";
  instructions += "\n\t-dirsort  : If the input filenames include the name of the directory they are in, the corresponding output files are written out to a subdirectory of the working directory with the same name.  If '-outfileprefix' is used in conjunction with this option, that prefix is prepended to the directory name (and if it includes a slash, may itself be a directory).";

  bool outputantimony = false;
  bool outputsbml = false;
  bool outputallsbml = false;
  bool outputcellml = false;
  string outfilename = "";
  string outfileprefix = "";
  bool readstdin = false;
  bool writestdout = false;
  bool dirsort = false;
  vector<string> files;
  for (int arg=0; arg<argc; arg++) {
    string sarg = argv[arg];
    if (sarg == "-o") {
      arg++;
      if (arg<argc) {
        cerr << "You must provide an option for the '-o' flag.  Valid options are:\n" << options << "\nUse '-h' for more options." << endl;
        retval = 1;
      }
      else {
        string outfmt = argv[arg];
        if (CaselessStrCmp(outfmt, "antimony")) {
          outputantimony = true;
        }
        else if (CaselessStrCmp(outfmt, "cellml")) {
#ifndef NCELLML
          outputcellml = true;
#else
          cerr << "CellML output is not supported in this version of sbtranslate.  You must recompile the program and include the CellML API library.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else if (CaselessStrCmp(outfmt, "sbml")) {
#ifndef SBML
          outputsbml = true;
#else
          cerr << "SBML output is not supported in this version of sbtranslate.  You must recompile the program and include the libSBML library.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else if (CaselessStrCmp(outfmt, "allsbml")) {
#ifndef SBML
          outputallsbml = true;
#else
          cerr << "SBML output is not supported in this version of sbtranslate.  You must recompile the program and include the libSBML library.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else {
          cerr << "Invalid output format '" << outfmt << "'.  Valid output formats are:\n" << options << "\nUse '-h' for more options." << endl;
          retval = 1;
        }
      }
    }
    else if (CaselessStrCmp(sarg, "-outfile")) {
      arg++;
      if (arg<argc) {
        cerr << "You must provide a filename for the '-outfile' flag.  Use '-h' for more options." << endl;
        retval = 1;
      }
      else {
        outfilename = argv[arg];
      }
    }
    else if (CaselessStrCmp(sarg, "-outfileprefix")) {
      arg++;
      if (arg<argc) {
        cerr << "You must provide an prefix for the '-outfileprefix' flag.  Use '-h' for more options." << endl;
        retval = 1;
      }
      else {
        outfileprefix = argv[arg];
      }
    }
    else if (CaselessStrCmp(sarg, "-stdin")) {
      readstdin = true;
    }
    else if (CaselessStrCmp(sarg, "-stdout")) {
      writestdout = true;
    }
    else if (CaselessStrCmp(sarg, "-dirsort")) {
      dirsort = true;
    }
    else {
      files.push_back(sarg);
    }
    if (retval == 1) {
#ifdef WIN32
      cerr << "(Press any key to exit.)" << endl;
      getch();
#endif
      return retval;
    }
  }
  if (files.size()==0) {
    readstdin = true;
  }

  vector<long> handles;
  for (int file=1; file<files.size(); file++) {
    handles.push_back(loadFile(files[file].c_str()));
    if (handles[file] == -1) {
      cerr << "Unable to load file '" << files[file] << "':  " << getLastError() << endl;
      retval = 1;
    }
  }
  if (readstdin) {
    string model = "";
    while(cin) {
      string input_line;
      getline(cin, input_line);
      model += input_line + "\n";
    }
    handles.push_back(loadString(model.c_str()));
    if (handles[handles.size()-1] == -1) {
      cerr << "Error reading in model from standard input: " << getLastError() << endl;
    }
  }

  /*
  }
    else {
      handles
      retval=loadFile(argv[file]);
      if (retval == -1) {
        cout << getLastError() << endl;
        retval = 1;
      }
      else {
        cout << argv[file] << " read successfully." << endl;
        size_t nummods = getNumModules();
        char** modnames = getModuleNames();
        string filename(argv[file]);
        if (filename.find(".txt") != string::npos) {
          filename.erase(filename.find(".txt"), 4);
        }
        while (filename.find("/") != string::npos) {
          filename.erase(0, filename.find("/")+1);
        }
        while (filename.find("\\") != string::npos) {
          filename.erase(0, filename.find("\\")+1);
        }
        for (size_t mod=0; mod<nummods; mod++) {
          if (getNumSymbolsOfType(modnames[mod], allSymbols) == 0) continue; //most likely for the 'main' module.
          string sbmlname = filename + "_" + modnames[mod] + "_sbml.xml";
          if (writeSBMLFile(sbmlname.c_str(), modnames[mod])) {
            cout << "Successfully wrote file " << sbmlname.c_str() << endl;
          }
          else {
            cout << "Problem writing file " << sbmlname.c_str() << endl;
            retval = 1;
          }
        }
      }
      freeAll();
    }
  }
  */
#ifdef WIN32
  if (retval == 1) {
    cout << "(Press any key to exit.)" << endl;
    getch();
  }
#endif

  return retval;
}


bool CaselessStrCmp(const string& lhs, const string& rhs)
{

  if (lhs.size() != rhs.size()) return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (toupper(lhs[i]) != toupper(rhs[i])) return false;
  }
  return true;

} /* CaselessStrCmp */

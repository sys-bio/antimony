#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cassert>
#include <cstdlib>
#include "antimony_api.h"

#ifndef NSBML
#include <sbml/SBMLTypes.h>
#endif

#ifdef WIN32
#include <conio.h>
#include <direct.h> //for Windows mkdir
#else
#include <sys/stat.h> //for UNIX mkdir
#include <cerrno>
#endif

using namespace std;
bool CaselessStrcmp(const string& lhs, const string& rhs);
enum file_type {FT_ANTIMONY, FT_SBML, FT_CELLML, FT_UNKNOWN};
file_type GetFileType(string filename);

int main(int argc, char** argv)
{
  int retval = 0;
  string instructions = "This version of sbtranslate can be used to convert files between Antimony";
  string options = "";
  options += "\n\t-o antimony : Output all models in Antimony format";
#ifndef NSBML
  options += "\n\t-o sbml     : Output the 'main' model as SBML";
#ifdef USE_COMP
  options += "\n\t-o sbml-comp: Output all models in a single SBML file using the\n\t               'comp' package.";
#endif
  options += "\n\t-o allsbml  : Output each model and submodel as a separate SBML model";
#ifndef NCELLML
  options += "\n\t-o cellml   : Output the 'main' model as CellML";
  instructions += ",\nSBML, and CellML.";
#else
  instructions += "\nand SBML.";
#endif
#else
#ifndef NCELLML
  instructions += "\nand CellML.";
  options += "\n\t-o cellml   : Output the 'main' model as CellML";
#else
  instructions += "\nand... Antimony.  Because this program was compiled without using either\nlibsbml or libcellml, which kind of makes translation to those formats\ndifficult.  But hey!  You can still use it to round-trip your models to\nregularize them and clean up any bits where you might have defined an element\nmultiple times or something.  I guess.  You still have to use '-o antimony' to\nset the output format, because if you got used to round-tripping your models\nwith the program compiled this way, sure enough someone (like you) would come\nalong and recompile the program with SBML and/or CellML support back in, and\nthen your old scripts wouldn't work.  So I'm saving you from yourself here; you\nshould thank me.";
#endif
#endif
  instructions += "\n\nYou must use at least one of the following options to set the output format\nof this translator:\n";
  instructions += options;
  instructions += "\n\nEach file will be exported to the desired format separately.  Multiple output\nformats are possible; a separate '-o [format]' is needed for each output format.\nThis means that if you give sbtranslate two input files and two output formats,\nit will write four files by default: one for each file in each format.";
  instructions += "\n\nsbtranslate takes as input any number of valid model files in any of the\nformats it understands.  If no files are provided, it reads input from stdin\nand attempts to parse that in one of its known model formats.";
  instructions += "\n\nBy default, sbtranslate will output files in the working directory with the\nsame name as the original file, minus that file's extention, plus '.txt' for\nantimony output, '.xml' for SBML output, and '.cellml' for CellML output (when\navailable).  If the file was originally in the same format as the desired\noutput, '_rt' (for 'roundtrip') is appended to the filename before the\nextention.  If the input was stdin, output will by default be written to\nstdout.";
  instructions += "\n\nTo change this behavior, the following options may be used:";
  instructions += "\n\t-outfile [filename] : All output is written to the given file.";
  instructions += "\n\t-prefix [prefix]    : All outfiles are prepended with the given\n\t\t\t      prefix.";
  instructions += "\n\t-d [directory]      : This directory will be used to search for \n\t\t\t      imported files if the normal import routines do\n\t\t\t      not work.  This directory is also used to\n\t\t\t      search for any '.antimony' files, which are used\n\t\t\t      to map import directives to actual files.";
  instructions += "\n\t-stdin    : Input is read from stdin, in addition to any files that\n\t\t    might be listed.";
  instructions += "\n\t-stdout   : All output is written to standard output.  No files are\n\t\t    created.";
  instructions += "\n\t-dirsort  : If the input filenames include the name of the directory\n\t\t    they are in, the corresponding output files are written out\n\t\t    to a subdirectory of the working directory with the same\n\t\t    name.  If '-prefix' is used in conjunction with this\n\t\t    option, that prefix is prepended to the directory name\n\t\t    (and if it includes a slash, may itself be a directory).";

  bool outputantimony = false;
  bool outputsbml = false;
  bool outputcompsbml = false;
  bool outputallsbml = false;
  bool outputcellml = false;
  string outfilename = "";
  string prefix = "";
  bool readstdin = false;
  bool writestdout = false;
  bool dirsort = false;
  vector<string> files;
  if (argc==1) {
    cerr << instructions << endl;
#ifdef WIN32
    cerr << endl << "(Press any key to exit.)" << endl;
    getch();
#endif
    return 1;
  }
  for (int arg=1; arg<argc; arg++) {
    string sarg = argv[arg];
    if (sarg == "-o") {
      arg++;
      if (arg>=argc) {
        cerr << "You must provide an option for the '-o' flag.  Valid options are:\n" << options << "\n\nUse '-h' for more options." << endl;
        retval = 1;
      }
      else {
        string outfmt = argv[arg];
        if (CaselessStrcmp(outfmt, "antimony")) {
          outputantimony = true;
        }
        else if (CaselessStrcmp(outfmt, "cellml")) {
#ifndef NCELLML
          outputcellml = true;
#else
          cerr << "CellML output is not supported in this version of sbtranslate.  You must recompile the program and include the CellML API library.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else if (CaselessStrcmp(outfmt, "sbml")) {
#ifndef SBML
          outputsbml = true;
#else
          cerr << "SBML output is not supported in this version of sbtranslate.  You must recompile the program and include the libSBML library.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else if (CaselessStrcmp(outfmt, "sbml-comp")) {
#ifdef USE_COMP
          outputcompsbml = true;
#else
          cerr << "SBML 'comp' output (the format used in the Hierarchical Model Composition package for SBML Level 3) is not supported in this version of sbtranslate.  You must recompile the program and include a beta version of the libSBML library, together with the 'comp' package enabled.  Use '-h' for more information.";
          retval = 1;
#endif
        }
        else if (CaselessStrcmp(outfmt, "allsbml")) {
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
    else if (CaselessStrcmp(sarg, "-outfile")) {
      arg++;
      if (arg>=argc) {
        cerr << "You must provide a filename for the '-outfile' flag.  Use '-h' for more options." << endl;
        retval = 1;
      }
      else {
        outfilename = argv[arg];
      }
    }
    else if (CaselessStrcmp(sarg, "-d")) {
      arg++;
      if (arg>=argc) {
        cerr << "You must provide a filename for the '-outfile' flag.  Use '-h' for more options." << endl;
        retval = 1;
      }
      else {
        addDirectory(argv[arg]);
      }
    }
    else if (CaselessStrcmp(sarg, "-prefix")) {
      arg++;
      if (arg>=argc) {
        cerr << "You must provide an prefix for the '-prefix' flag.  Use '-h' for more options." << endl;
        retval = 1;
      }
      else {
        prefix = argv[arg];
      }
    }
    else if (CaselessStrcmp(sarg, "-stdin")) {
      readstdin = true;
    }
    else if (CaselessStrcmp(sarg, "-stdout")) {
      writestdout = true;
    }
    else if (CaselessStrcmp(sarg, "-dirsort")) {
      dirsort = true;
    }
    else if (CaselessStrcmp(sarg, "-h") || CaselessStrcmp(sarg, "--help")) {
      cout << instructions << endl;
      retval = 1;
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
  if (!(outputantimony || outputsbml || outputallsbml || outputcompsbml || outputcellml)) {
        cerr << "You must provide an output option using the '-o' flag.  Valid options are:\n" << options << "\n\nUse '-h' for more options." << endl;
        return 1;
  }
  if (files.size()==0) {
    readstdin = true;
  }

  vector<long> handles;
  size_t numstdin = 0;
  if (readstdin) {
    numstdin = 1;
  }
  for (size_t file=0; file<files.size() + numstdin; file++) {
    //Input:
    if (file == files.size()) {
      //stdin
      string model = "";
      while(cin) {
        string input_line;
        getline(cin, input_line);
        model += input_line + "\n";
      }
      handles.push_back(loadString(model.c_str()));
      if (handles[handles.size()-1] == -1) {
        handles.pop_back();
        cerr << "Error reading in model from standard input: " << getLastError() << endl;
        continue;
      }
    }
    else {
      switch(GetFileType(files[file])) {
      case FT_ANTIMONY:
        handles.push_back(loadAntimonyFile(files[file].c_str()));
        break;
      case FT_SBML:
#ifndef NSBML
        handles.push_back(loadSBMLFile(files[file].c_str()));
#endif
        break;
      case FT_CELLML:
#ifndef NCELLML
        handles.push_back(loadCellMLFile(files[file].c_str()));
#endif
        break;
      case FT_UNKNOWN:
        handles.push_back(loadFile(files[file].c_str()));
        break;
      }
      if (handles[file] == -1) {
        cerr << getLastError() << endl;
        continue;
      }
      else if (!writestdout) {
        cout << "Successfully read file " << files[file] << endl;
      }
    }
    //Output:
    string infile = "";
    string infilenodir = "";
    string fullprefix = prefix;
    bool   use_stdin = false;
    if (file < files.size()) {
      infile = files[file];
      infilenodir = infile;
      size_t lastslash = infilenodir.find_last_of("/\\");
      if (lastslash != string::npos) {
        infilenodir = infilenodir.substr(lastslash+1, string::npos);
        if (dirsort) {
          string subdir = infile.substr(0, lastslash);
          lastslash = subdir.find_last_of("/\\");
          if (lastslash != string::npos) {
            subdir = subdir.substr(lastslash+1, string::npos);
          }
          if (subdir != "") {
            subdir += "/";
          }
          fullprefix = subdir + prefix;
        }
      }
      if (!writestdout) {
        string subdir = fullprefix;
        size_t lastslash = subdir.find_last_of("/\\");
        if (lastslash != string::npos) {
          subdir = subdir.substr(0, lastslash+1);
#ifdef WIN32
          if (mkdir(subdir.c_str()) == -1) {
            cerr << "Unable to create directory " << subdir << endl;
            retval = 1;
          }
#else
          if (mkdir(subdir.c_str(), 0777) == -1 && errno != EEXIST) {  // Create the directory
            cerr << "Unable to create directory " << subdir << endl;
            retval = 1;
          }
          //string command = "mkdir -p " + subdir;
          //system(command.c_str());
#endif
        }
      }
    }
    else {
      use_stdin = true;
    }
    if (outputantimony) {
      if (writestdout) {
        cout << getAntimonyString(NULL) << endl;
      }
      else {
        string antoutname = outfilename;
        if (antoutname == "") {
          if (use_stdin) {
            antoutname = fullprefix + "antimony.txt";
          }
          else {
            antoutname = fullprefix + infilenodir;
            size_t lastperiod = antoutname.find_last_of('.');
            antoutname = antoutname.substr(0, lastperiod);
            antoutname += ".txt";
            if (antoutname == infile) {
              antoutname.insert(lastperiod, "_rt");
            }
          }
        }
        if (writeAntimonyFile(antoutname.c_str(), NULL)) { //NULL for 'all models'
          cout << "Successfully wrote " << antoutname << endl;
        }
        else {
          cerr << getLastError() << endl;
        }
      }
    }
#ifndef NSBML
    if (outputsbml || outputcompsbml) {
      if (writestdout) {
        if (outputcompsbml) {
#ifdef USE_COMP
          cout << getCompSBMLString(NULL) << endl;
#endif
        }
        else {
          cout << getSBMLString(NULL) << endl;
        }
      }
      else {
        string sbmloutname = outfilename;
        if (sbmloutname == "") {
          if (use_stdin) {
            sbmloutname = fullprefix + "sbml.xml";
          }
          else {
            sbmloutname = fullprefix + infilenodir;
            size_t lastperiod = sbmloutname.find_last_of('.');
            sbmloutname = sbmloutname.substr(0, lastperiod);
            sbmloutname += ".xml";
            if (sbmloutname == infile) {
              sbmloutname.insert(lastperiod, "_rt");
            }
          }
        }
        if (outputcompsbml) {
#ifdef USE_COMP
          if (writeCompSBMLFile(sbmloutname.c_str(), NULL))  { //NULL for 'all models'
            cout << "Successfully wrote " << sbmloutname << endl;
          }
          else {
            cerr << getLastError() << endl;
          }
#endif
        }
        else {
          if (writeSBMLFile(sbmloutname.c_str(), NULL))  { //NULL for 'all models'
            cout << "Successfully wrote " << sbmloutname << endl;
          }
          else {
            cerr << getLastError() << endl;
          }
        }
      }
    }
    else if (outputallsbml) {
      unsigned long nummods = getNumModules();
      for (unsigned long mod=0; mod<nummods; mod++) {
        char* modname = getNthModuleName(mod);
        assert(modname != NULL);
        string modnamestr(modname);
        if (writestdout) {
          cout << getSBMLString(modname) << endl;
        }
        else {
          string sbmloutname = outfilename;
          if (sbmloutname == "") {
            if (use_stdin) {
              sbmloutname = fullprefix + "sbml_" + modnamestr + ".xml";
            }
            else {
              sbmloutname = fullprefix + infilenodir;
              size_t lastperiod = sbmloutname.find_last_of('.');
              sbmloutname = sbmloutname.substr(0, lastperiod);
              sbmloutname += "_" + modnamestr + ".xml";
              if (sbmloutname == infile) {
                sbmloutname.insert(lastperiod, "_rt");
              }
            }
          }
          if (writeSBMLFile(sbmloutname.c_str(), modname))  {
            cout << "Successfully wrote " << sbmloutname << endl;
          }
          else {
            cerr << getLastError() << endl;
          }
        }
      }
    }
#endif //NSBML
#ifndef NCELLML
    if (outputcellml) {
      if (writestdout) {
        cout << getCellMLString(NULL) << endl;
      }
      else {
        string cellmloutname = outfilename;
        if (cellmloutname == "") {
          if (use_stdin) {
            cellmloutname = fullprefix + "cellml.cellml";
          }
          else {
            cellmloutname = fullprefix + infilenodir;
            size_t lastperiod = cellmloutname.find_last_of('.');
            cellmloutname = cellmloutname.substr(0, lastperiod);
            cellmloutname += ".cellml";
            if (cellmloutname == infile) {
              cellmloutname.insert(lastperiod, "_rt");
            }
          }
        }
        if (writeCellMLFile(cellmloutname.c_str(), NULL))  { //NULL for 'all models'
          cout << "Successfully wrote " << cellmloutname << endl;
        }
        else {
          cerr << getLastError() << endl;
        }
      }
    }
#endif //NCELLML
  }

  if (handles.size()==0) {
    cerr << "No models successfully read!" << endl;
    retval = 1;
  }
#ifdef WIN32
  if (retval == 1) {
    cout << "(Press any key to exit.)" << endl;
    getch();
  }
#endif

  return retval;
}

bool CaselessStrcmp(const string& lhs, const string& rhs)
{

  if (lhs.size() != rhs.size()) return false;

  for (size_t i = 0; i < lhs.size(); ++i) {
    if (toupper(lhs[i]) != toupper(rhs[i])) return false;
  }
  return true;

} /* CaselessStrcmp */

file_type GetFileType(string filename)
{
  ifstream infile;
  infile.open(filename.c_str());
  string line;
  getline(infile, line);
  bool isxml = false;
  while (infile) {
    if (line.find("<?xml") != string::npos) {
      isxml = true;
    }
    else if (isxml == false && (line.find("model") != string::npos
             || line.find("module") != string::npos)) {
      if (line.rfind(' ')==5 || line.rfind(' ')==6 || line[line.size()-1] == ')') {
        //cout << "Antimony by finding 'model/module'" << endl;
        return FT_ANTIMONY;
      }
    }
    if (isxml) {
      if (line.find("cellml.org") != string::npos) {
        //cout << "CellML by finding cellml.org" << endl;
        return FT_CELLML;
      }
      if (line.find("<sbml") != string::npos) {
        //cout << "SBML by finding '<sbml'" << endl;
        return FT_SBML;
      }
    }
    getline(infile, line);
  }
  //Didn't find anything obvious, so:
  if (filename.rfind(".cellml") == filename.size()-7 && filename.size() != 6) {
    //cout << "CellML by file extension" << endl;
    return FT_CELLML;
  }
  if (filename.rfind(".xml") == filename.size()-4 && filename.size() != 3) {
    //cout << "SBML by file extension" << endl;
    return FT_SBML;
  }
  if (filename.rfind(".sbml") == filename.size()-5 && filename.size() != 4) {
    //cout << "SBML by file extension" << endl;
    return FT_SBML;
  }
  if (filename.rfind(".txt") == filename.size()-4 && filename.size() != 3) {
    //cout << "Antimony by file extension" << endl;
    return FT_ANTIMONY;
  }
   cout << "Unknown type" << endl;
  return FT_UNKNOWN;
}

#include <iostream>
#include <cstdlib>
#include "antimony_api.h"

#ifdef WIN32
#include <conio.h>
#endif

using namespace std;

int main(int argc, char** argv)
{
  int retval = 0;
  if (argc < 2) {
    cout << "To use cellml2antimony, give it a list of one or more CellML files to convert.  In Windows, you can associate .cellml files with this program to convert it that way." << endl;
    retval = 1;
  }
  else {
    for (int file=1; file<argc; file++) {
      retval=loadCellMLFile(argv[file]);
      if (retval == -1) {
        cout << getLastError() << endl;
        retval = 1;
      }
      else {
        cout << argv[file] << " read successfully";
        char* warnings = getWarnings();
        if (warnings == NULL) {
          cout << "." << endl;
        }
        else {
          cout << ", with the following warnings:" << endl << warnings << endl;
        }
        size_t nummods = getNumModules();
        char** modnames = getModuleNames();
        string filename(argv[file]);
        if (filename.find(".xml") != string::npos) {
          filename.erase(filename.find(".xml"), 4);
        }
        if (filename.find(".cellml") != string::npos) {
          filename.erase(filename.find(".cellml"), 7);
        }
        string dirname = filename;
        while (filename.find("/") != string::npos) {
          filename.erase(0, filename.find("/")+1);
        }
        while (filename.find("\\") != string::npos) {
          filename.erase(0, filename.find("\\")+1);
        }
        size_t lastslash = dirname.rfind("/");
        while (dirname.find("/") != lastslash) {
          dirname.erase(0, dirname.find("/")+1);
          lastslash = dirname.rfind("/");
        }
        dirname.erase(lastslash, dirname.size()-lastslash);
        //cout << "Dirname = " << dirname << endl;
        string command = "mkdir -p cellml/" + dirname;
        system(command.c_str());
        size_t modnum = nummods-1;
        string antimonyname = "cellml/" + dirname + "/" + filename + ".txt";
        string sbmlname     = "cellml/" + dirname + "/" + filename + "_sbml.xml";
        //antimonyname += ".txt";
        retval = 0;
        if (writeAntimonyFile(antimonyname.c_str(), modnames[modnum])) {
          cout << "Successfully wrote file " << antimonyname << endl;
        }
        else {
          cout << "Problem writing file " << antimonyname.c_str() << endl;
          retval = 1;
        }
        if (writeSBMLFile(sbmlname.c_str(), modnames[modnum])) {
          cout << "Successfully wrote file " << sbmlname << endl;
        }
        else {
          cout << "Problem writing file " << sbmlname.c_str() << endl;
          retval = 1;
        }
        freeAll();
      }
      clearPreviousLoads();
    }
  }
#ifdef WIN32
  if (retval == 1) {
    cout << "(Press any key to exit.)" << endl;
    getch();
  }
#endif
  return retval;
}

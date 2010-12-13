#include <iostream>
#include <sstream>
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
    cout << "To use rehashantimony, give it a list of one or more antimony files to read in and regularize." << endl;
    retval = 1;
  }
  else {
    for (int file=1; file<argc; file++) {
      retval=loadFile(argv[file]);
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
        string dirname = filename;
        while (filename.find("/") != string::npos) {
          filename.erase(0, filename.find("/")+1);
        }
        while (filename.find("\\") != string::npos) {
          filename.erase(0, filename.find("\\")+1);
        }
        size_t lastslash = dirname.rfind("/");
        if (lastslash != string::npos) {
          while (dirname.find("/") != lastslash) {
            dirname.erase(0, dirname.find("/")+1);
            lastslash = dirname.rfind("/");
          }
          dirname.erase(lastslash, dirname.size()-lastslash);
        }
        //cout << "Dirname = " << dirname << endl;
        string command = "mkdir -p rehash/" + dirname;
        system(command.c_str());
        size_t modnum = nummods-1;
        string antimonyname = "rehash/" + dirname + "/" + filename;
        //antimonyname += ".txt";
        retval = 0;
        if (writeAntimonyFile(antimonyname.c_str(), modnames[modnum])) {
          cout << "Successfully wrote file " << antimonyname << endl;
        }
        else {
          cout << "Problem writing file " << antimonyname.c_str() << endl;
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

#include <iostream>
#include <sstream>
#include "antimony_api.h"

#ifdef WIN32
#include <conio.h>
#endif

using namespace std;

int main(int argc, char** argv)
{
  int retval = 0;
  if (argc < 2) {
    cout << "To use antimony2sbml, give it a list of valid antimony files.  In Windows, you can associate .txt files (or .ant or whatever extention you want to use) with this program to convert them that way" << endl;
    retval = 1;
  }
  for (int file=1; file<argc; file++) {
    if (loadSBMLFile(argv[file]) != -1) {
      cout << argv[file] << " is already an SBML file--no conversion is necessary." << endl;
      retval = 1;
    }
    else {
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
      retval = 0;
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

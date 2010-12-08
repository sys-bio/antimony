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
    cout << "To use antimony2cellml, give it a list of valid antimony files.  In Windows, you can associate .txt files (or .ant or whatever extention you want to use) with this program to convert them that way" << endl;
    retval = 1;
  }
  for (int file=1; file<argc; file++) {
    /* CellML writes errors to the screen, which is not what we want, so don't do this check.
    if (loadCellMLFile(argv[file]) != -1) {
      cout << argv[file] << " is already an CellML file--no conversion is necessary." << endl;
      retval = 1;
    }
    */
    //else {
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
        if (filename.find(".txt") != string::npos) {
          filename.erase(filename.find(".txt"), 4);
        }
        while (filename.find("/") != string::npos) {
          filename.erase(0, filename.find("/")+1);
        }
        while (filename.find("\\") != string::npos) {
          filename.erase(0, filename.find("\\")+1);
        }
        string cellmlname = filename + ".cellml";
        if (writeCellMLFile(cellmlname.c_str(), modnames[nummods-1])) {
          cout << "Successfully wrote file " << cellmlname.c_str() << endl;
        }
        else {
          cout << "Problem writing file " << cellmlname.c_str() << endl;
          retval = 1;
        }
      }
      freeAll();
      retval = 0;
      //}
  }
#ifdef WIN32
  if (retval == 1) {
    cout << "(Press any key to exit.)" << endl;
    getch();
  }
#endif

  return retval;
}

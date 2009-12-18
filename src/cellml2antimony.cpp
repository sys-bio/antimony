#include <iostream>
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
        cout << argv[file] << " read successfully." << endl;
        size_t nummods = getNumModules();
        char** modnames = getModuleNames();
        string filename(argv[file]);
        if (filename.find(".xml") != string::npos) {
          filename.erase(filename.find(".xml"), 4);
        }
        while (filename.find("/") != string::npos) {
          filename.erase(0, filename.find("/")+1);
        }
        while (filename.find("\\") != string::npos) {
          filename.erase(0, filename.find("\\")+1);
        }
        size_t modnum = nummods-1;
        string antimonyname = filename;
        antimonyname += ".txt";
        if (writeAntimonyFile(antimonyname.c_str(), modnames[modnum])) {
          cout << "Successfully wrote file " << antimonyname.c_str() << endl;
          retval = 0;
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

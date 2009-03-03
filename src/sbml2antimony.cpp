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
    cout << "To use sbml2antimony, the first command line argument should be the name of a valid SBML file, and if you wish, you may supply a name for the produced Antimony file as a second argument." << endl;
    return 1;
  }
  if (argc > 3) {
    cout << "You must supply the filename of a single SBML file and, optionally, may supply the name for the produced Antimony file to be written.  You supplied more than that, so I don't know what you meant." << endl;
    return 1;
  }
  retval=loadSBMLFile(argv[1]);
  if (retval == -1) {
    cout << getLastError() << endl;
    return 1;
  }
  else {
    cout << argv[1] << " read successfully." << endl;
  }
  size_t nummods = getNumModules();
  char** modnames = getModuleNames();
  string filename(argv[1]);
  if (filename.find(".xml") != string::npos) {
    filename.erase(filename.find(".xml"), 4);
  }
  size_t modnum = nummods-1;
  string antimonyname = filename;
  antimonyname += ".txt";
  if (argc == 3) {
    antimonyname = argv[2];
  }
  if (writeAntimonyFile(antimonyname.c_str(), modnames[modnum])) {
    cout << "Successfully wrote file " << antimonyname.c_str() << endl;
  }
  else {
    cout << "Problem writing file " << antimonyname.c_str() << endl;
    return 1;
  }
  freeAll();
#ifdef WIN32
  cout << "(Press any key to exit.)" << endl;
  getch();
#endif
  return 0;
}

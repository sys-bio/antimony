#include <iostream>
#include "antimony_api.h"
#include <conio.h>
using namespace std;

int main(int argc, char** argv)
{
  int retval = 0;
  if (argc < 2) {
    cout << "To use antimony2sbml, the first command line argument should be the name of a valid Antimony file, and if you wish, you may supply the prefix for the produced SBML file(s) as a second argument." << endl;
    return 1;
  }
  if (argc > 3) {
    cout << "You must supply the filename of a single antimony file and, optionally, may supply a prefix for the SBML file to be written.  You supplied more than that, so I don't know what you meant." << endl;
    return 1;
  }
  /*if (loadSBMLFile(argv[1]) != -1) {
    cout << argv[1] << " is already an SBML file--no conversion is necessary." << endl;
    return 1;
  }*/
  retval=loadFile(argv[1]);
  if (retval == -1) {
	cout << "Uops something is badly wrong with the file ... ";
    cout << getLastError() << endl;
    return 1;
  }
  else {
    cout << argv[1] << " read successfully." << endl;
  }
  size_t nummods = getNumModules();
  char** modnames = getModuleNames();
  string filename(argv[1]);
  if (filename.find(".txt") != string::npos) {
    filename.erase(filename.find(".txt"), 4);
  }
  for (size_t mod=0; mod<nummods; mod++) {
    string sbmlname = filename;
    if (argc == 3) {
      sbmlname = argv[2];
    }
    sbmlname += "_";
    sbmlname += modnames[mod];
    sbmlname += "_sbml.xml";
    if (writeSBMLFile(sbmlname.c_str(), modnames[mod])) {
      cout << "Successfully wrote file " << sbmlname.c_str() << endl;
    }
    else {
      cout << "Problem writing file " << sbmlname.c_str() << endl;
      return 1;
    }
  }
  freeAll();

	getch();

  return 0;
}

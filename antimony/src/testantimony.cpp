#include <iostream>
#include <cstring>

#include "antimony_api.h"
using namespace std;

int main(int argc, char** argv)
{
  //yydebug = 1;
  int retval = 0;
  for (long file=1; file<argc; file++) {
#ifndef NSBML
    if (strstr(argv[file], ".xml") != NULL) {
      retval = loadSBMLFile(argv[file]);
    }
    else {
      retval=loadFile(argv[file]);
    }
#else
    retval=loadFile(argv[file]);
#endif
    if (retval == -1) {
      cout << getLastError() << endl;
    }
    else {
      cout << argv[file] << " read successfully with file handle " << retval << "." << endl;
    }
  }
  for (size_t file=0; file<getNumFiles(); file++) {
    revertTo(file+1);
    size_t nummods = getNumModules();
    char** modnames = getModuleNames();
    string filename(argv[file+1]);
    size_t slash = filename.find("/");
    while (slash != string::npos) {
      filename.erase(0, slash+1);
      slash = filename.find("/");
    }
    
    if (filename.find(".txt") != string::npos) {
      filename.erase(filename.find(".txt"), 4);
    }
    if (filename.find(".xml") != string::npos) {
      filename.erase(filename.find(".xml"), 4);
    }
    for (size_t mod=0; mod<nummods; mod++) {
      cout << "Information for file " << file+1 <<", module '" << modnames[mod] << "'" << endl;
      /* If you have a static library and #include registry.h above, you can uncomment this: 
      cout << "***ToString (" << modnames[mod] << ") ***" << endl;
      cout << g_registry.GetModule(modnames[mod])->ToString().c_str() << endl << endl;
      */
      cout << "***Jarnac (" << modnames[mod] << ") ***" << endl;
      cout << getJarnacString(modnames[mod]) << endl;
      cout << endl << "***printAllDataFor (" << modnames[mod] << ") (from the API):***" << endl;
      printAllDataFor(modnames[mod]);
      cout << endl << "***Antimony (" << modnames[mod] << ")" << endl;
      cout << getAntimonyString(modnames[mod]) << endl;
      cout << endl;
      cout << endl;
      string antname = "output/" + filename + "_" + modnames[mod] + "_ant.txt";
      string sbmlname = "output/" + filename + "_" + modnames[mod] + "_sbml.xml";
      string jarname = "output/" + filename + "_" + modnames[mod] + "_jar.txt";
      if (writeAntimonyFile(antname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << antname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << antname.c_str() << endl;
      }
#ifndef NSBML
      if (writeSBMLFile(sbmlname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << sbmlname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << sbmlname.c_str() << endl;
      }
#endif
      if (writeJarnacFile(jarname.c_str(), modnames[mod])) {
        cout << "Successfully wrote file " << jarname.c_str() << endl;
      }
      else {
        cout << "Problem writing file " << jarname.c_str() << endl;
      }
        
    }
    freeAll();
  }
  /* Just for testing: */
  clearPreviousLoads();
  if (argc>1) {
    int ret2 = loadFile(argv[1]);
    if (ret2 == -1) {
      cout << "Error when re-reading file " << argv[1] << ":  " << getLastError() << endl;
    }
    else {
      cout << argv[1] << " re-read successfully." << endl;
    }
#ifndef NSBML
    cout << "SBML Info from main module in last file:" << endl << getSBMLInfoMessages("__main") << endl;
    cout << "SBML Warning messages from main module in last file:" << endl << getSBMLWarnings("__main") << endl;
#endif
  }
  else {
    cout << "No files specified." << endl;
  }
  freeAll();
  if (retval == -1) return 1;
  return 0;
}

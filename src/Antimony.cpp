// Antimony.cpp : Defines the entry point for the DLL application.
//

#include "stdlib.h"

#ifdef WIN32
#include <windows.h>

BOOL APIENTRY DllMain( HMODULE /*hModule*/,
                       DWORD  /*ul_reason_for_call*/,
                       LPVOID /*lpReserved*/
                                         )
{
    return TRUE;
}
#endif


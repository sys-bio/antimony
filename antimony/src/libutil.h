#ifndef LIB_UTIL_H
#define LIB_UTIL_H

//#if  ( defined WIN32 && (! defined MINGW && ! defined CYGWIN))
//#if defined(WIN32)
#ifdef WIN32
#if LIB_EXPORTS
#  define LIB_EXTERN __declspec(dllexport)
#else
#  define LIB_EXTERN __declspec(dllimport)
#endif
#else
#  define LIB_EXTERN
#endif
 
#if __cplusplus
#  define BEGIN_C_DECLS extern "C" { //
#  define END_C_DECLS   } //
#else
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#endif

#endif //LIB_UTIL_H


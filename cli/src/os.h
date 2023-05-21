#ifndef _SOUNDSTRETCH_OS_H
#define _SOUNDSTRETCH_OS_H

#if defined(_WIN32) || defined(_WIN64) || defined(__MINGW32__) || defined(__MINGW64__)
    #include <shlwapi.h>
    #include <wchar.h>
    #include <windows.h>
    #define IS_WINDOWS
    #define PATHCHAR wchar_t
    #define PATHLEN wcslen
    #define PATHCMP wcscmp
    #define PATHTOF _wtof
#else
    #include <string.h>
    #define PATHCHAR char
    #define PATHLEN strlen
    #define PATHCMP strcmp
    #define PATHTOF atof
#endif

#endif

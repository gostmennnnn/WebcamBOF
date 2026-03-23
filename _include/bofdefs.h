#pragma once
/*
 * BOF definitions for Adaptix C2 - WebcamBOF
 * Trimmed to only include imports used by this BOF.
 */
#include <windows.h>
#include <gdiplus.h>

#ifdef BOF

#include "adaptix.h"

void go(char* buff, int len);

/* MSVCRT */
DECLSPEC_IMPORT void* __cdecl  MSVCRT$malloc(size_t);
DECLSPEC_IMPORT void  __cdecl  MSVCRT$free(void* _Memory);
DECLSPEC_IMPORT void* __cdecl  MSVCRT$memcpy(LPVOID, LPVOID, size_t);
DECLSPEC_IMPORT int   __cdecl  MSVCRT$memcmp(LPVOID, LPVOID, size_t);
DECLSPEC_IMPORT void  __cdecl  MSVCRT$memset(void*, int, size_t);
DECLSPEC_IMPORT int   __cdecl  MSVCRT$_snprintf(LPSTR, size_t, LPCSTR, ...);
DECLSPEC_IMPORT void  __cdecl  MSVCRT$sprintf(char*, char[], ...);
DECLSPEC_IMPORT int   __cdecl  MSVCRT$strcmp(const char* _Str1, const char* _Str2);
DECLSPEC_IMPORT size_t __cdecl MSVCRT$strlen(const char* str);
DECLSPEC_IMPORT void  __cdecl  MSVCRT$srand(int initial);
DECLSPEC_IMPORT int   __cdecl  MSVCRT$rand();
DECLSPEC_IMPORT time_t __cdecl MSVCRT$time(time_t* time);
DECLSPEC_IMPORT int   __cdecl  MSVCRT$fclose(FILE* stream);
DECLSPEC_IMPORT FILE* __cdecl  MSVCRT$fopen(const char* filename, const char* mode);
DECLSPEC_IMPORT size_t __cdecl MSVCRT$fwrite(const void* ptr, size_t size, size_t count, FILE* stream);

/* Kernel32 */
DECLSPEC_IMPORT HMODULE WINAPI KERNEL32$LoadLibraryA(LPCSTR lpLibFileName);
DECLSPEC_IMPORT HMODULE WINAPI KERNEL32$GetModuleHandleA(LPCSTR lpModuleName);
DECLSPEC_IMPORT FARPROC WINAPI KERNEL32$GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
DECLSPEC_IMPORT HANDLE  WINAPI KERNEL32$CreateFileA(LPCSTR lpFileName, DWORD dwDesiredAccess, DWORD dwShareMode, LPSECURITY_ATTRIBUTES lpSecurityAttributes, DWORD dwCreationDisposition, DWORD dwFlagsAndAttributes, HANDLE hTemplateFile);
DECLSPEC_IMPORT BOOL    WINAPI KERNEL32$WriteFile(HANDLE hFile, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite, LPDWORD lpNumberOfBytesWritten, LPOVERLAPPED lpOverlapped);
DECLSPEC_IMPORT BOOL    WINAPI KERNEL32$CloseHandle(HANDLE);
DECLSPEC_IMPORT LPVOID  WINAPI KERNEL32$HeapAlloc(HANDLE hHeap, DWORD dwFlags, SIZE_T dwBytes);
DECLSPEC_IMPORT BOOL    WINAPI KERNEL32$HeapFree(HANDLE, DWORD, PVOID);
DECLSPEC_IMPORT HANDLE  WINAPI KERNEL32$GetProcessHeap();
DECLSPEC_IMPORT VOID    WINAPI KERNEL32$Sleep(DWORD dwMilliseconds);
DECLSPEC_IMPORT DWORD   WINAPI KERNEL32$GetLastError(VOID);

/* OLE32 */
DECLSPEC_IMPORT HRESULT WINAPI OLE32$CreateStreamOnHGlobal(HGLOBAL hGlobal, BOOL fDeleteOnRelease, LPSTREAM * ppstm);
DECLSPEC_IMPORT HRESULT WINAPI OLE32$CoInitializeEx(LPVOID, DWORD);
DECLSPEC_IMPORT VOID    WINAPI OLE32$CoUninitialize();

/* GDI32 */
DECLSPEC_IMPORT HGDIOBJ WINAPI GDI32$DeleteObject(HGDIOBJ ho);

/* USER32 */
DECLSPEC_IMPORT int     WINAPI USER32$GetSystemMetrics(int nIndex);

/* ---- MACRO DEFINITIONS ---- */

#define malloc                    MSVCRT$malloc
#define free(addr)                MSVCRT$free((void*)addr)
#define memcpy                    MSVCRT$memcpy
#define memcmp                    MSVCRT$memcmp
#define memset                    MSVCRT$memset
#define strcmp                    MSVCRT$strcmp
#define strlen                    MSVCRT$strlen
#define sprintf                   MSVCRT$sprintf
#define snprintf                  MSVCRT$_snprintf
#define srand                     MSVCRT$srand
#define rand                      MSVCRT$rand
#define time                      MSVCRT$time
#define fclose                    MSVCRT$fclose
#define fopen                     MSVCRT$fopen
#define fwrite                    MSVCRT$fwrite

#define LoadLibraryA              KERNEL32$LoadLibraryA
#define GetModuleHandleA          KERNEL32$GetModuleHandleA
#define GetProcAddress            KERNEL32$GetProcAddress
#define CreateFileA               KERNEL32$CreateFileA
#define WriteFile                 KERNEL32$WriteFile
#define CloseHandle               KERNEL32$CloseHandle
#define HeapAlloc                 KERNEL32$HeapAlloc
#define HeapFree                  KERNEL32$HeapFree
#define GetProcessHeap            KERNEL32$GetProcessHeap
#define Sleep                     KERNEL32$Sleep
#define GetLastError              KERNEL32$GetLastError

#define CreateStreamOnHGlobal     OLE32$CreateStreamOnHGlobal
#define CoInitializeEx            OLE32$CoInitializeEx
#define CoUninitialize            OLE32$CoUninitialize

#define DeleteObject              GDI32$DeleteObject

#define GetSystemMetrics          USER32$GetSystemMetrics

#define ZeroMemory(address, size) memset(address, 0, size);

#else

#endif

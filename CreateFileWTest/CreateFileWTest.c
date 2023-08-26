#include <stdio.h>
#include "Windows.h"

int main()
{
  LPCWSTR const lpFileName = L"LPT1";
  DWORD const dwDesiredAccess = GENERIC_WRITE;
  DWORD const dwShareMode = 0;
  SECURITY_ATTRIBUTES* const lpSecurityAttributes = NULL;
  DWORD const dwCreationDisposition = CREATE_NEW;
  DWORD const dwFlagsAndAttributes = FILE_ATTRIBUTE_NORMAL;
  HANDLE const hTemplateFile = NULL;

  HANDLE h = CreateFileW(
    lpFileName,
    dwDesiredAccess,
    dwShareMode,
    lpSecurityAttributes,
    dwCreationDisposition,
    dwFlagsAndAttributes,
    hTemplateFile
  );

  if (h == INVALID_HANDLE_VALUE)
  {
    DWORD const error = GetLastError();
    printf("Failed to create file. Windows error %lu\n", error);
    return 1;
  }

  printf("File created!\n");

  return 0;
}

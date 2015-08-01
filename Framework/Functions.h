#ifndef FUNCTIONS
#define FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include "Overlay.h"
#include <time.h>

namespace ProcessFunctions
{
	template < class TypeValue > TypeValue ReadMemory(DWORD Address);
	template < class TypeValue > TypeValue WriteMemory(DWORD Address);
	void CheckDWM();
	void CreateConsole();
	DWORD GetModuleBase(DWORD dwProcessIdentifier, TCHAR *lpszModuleName);
	HANDLE GetHandle();
}



template <class TypeValue>
TypeValue ProcessFunctions::ReadMemory(DWORD Address)
{
	TypeValue Value;
	ReadProcessMemory(pHandle, (LPCVOID*)Address, &Value, sizeof(TypeValue), 0);
	return Value;
}

template <class TypeValue>
TypeValue ProcessFunctions::WriteMemory(DWORD Address)
{
	TypeValue Value;
	WriteProcessMemory(pHandle, (LPCVOID*)Address, &Value, sizeof(TypeValue), 0);
	return Value;
}

#endif
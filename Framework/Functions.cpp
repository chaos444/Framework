#include "Functions.h"
#include <TlHelp32.h>


void ProcessFunctions::CheckDWM()
{
	BOOL Enabled;
	HRESULT Result = DwmIsCompositionEnabled(&Enabled);
	if (!SUCCEEDED(Enabled) && Enabled)
	{
		printf("Please make sure your Windows Aero is enabled!\n\nSupported Systems:\n* Windows Vista\n* Windows 7\n* Windows 8 / 8.1", "Warning!");
		Sleep(1000);
	}
}

DWORD ProcessFunctions::GetModuleBase(DWORD dwProcessIdentifier, TCHAR *lpszModuleName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessIdentifier);
	DWORD dwModuleBaseAddress = 0;
	if (hSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32 = { 0 };
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hSnapshot, &ModuleEntry32))
		{
			do
			{
				if (strcmp(ModuleEntry32.szModule, lpszModuleName) == 0)
				{
					dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
					break;
				}
			} while (Module32Next(hSnapshot, &ModuleEntry32));
		}
		CloseHandle(hSnapshot);
	}
	return dwModuleBaseAddress;
}

void ProcessFunctions::CreateConsole()
{
	int hConHandle = 0;
	HANDLE lStdHandle = 0;
	FILE *fp = 0;
	AllocConsole();
	lStdHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	hConHandle = _open_osfhandle(PtrToUlong(lStdHandle), _O_TEXT);
	fp = _fdopen(hConHandle, "w");
	*stdout = *fp;
	setvbuf(stdout, NULL, _IONBF, 0);
	SetConsoleTitle("Meher Framework");
}

HANDLE ProcessFunctions::GetHandle()
{
	pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	return pHandle;
}

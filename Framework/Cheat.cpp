#include "Cheat.h"

void Click()
{
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, NULL, NULL);
	Sleep(1);
	mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, NULL, NULL);
	Sleep(1);
}


void Yarin(LocalPlayer* lPlayer, InCrosshair* InCH)
{
	ReadProcessMemory(pHandle, (LPVOID)(Module + OFFSET_LOCALPLAYER), &lPlayer->clientPlayer, sizeof(lPlayer->clientPlayer), NULL);
	ReadProcessMemory(pHandle, (LPVOID)(lPlayer->clientPlayer + 0x2410), &lPlayer->incrossid, sizeof(lPlayer->incrossid), NULL);
	ReadProcessMemory(pHandle, (LPVOID)(Module + OFFSET_ENTITYLIST + ((lPlayer->incrossid - 1) * 0x10)), &InCH->clientPlayer, sizeof(InCH->clientPlayer), NULL);
	ReadProcessMemory(pHandle, (LPVOID)(InCH->clientPlayer + 0xF0), &InCH->teamid, sizeof(InCH->teamid), NULL);
	ReadProcessMemory(pHandle, (LPVOID)(InCH->clientPlayer + 0x0FC), &InCH->health, sizeof(InCH->health), NULL);

	if (lPlayer->teamid != InCH->teamid && InCH->health > 0)
	{
		Click();
	}
	else
	{
		Sleep(1);
	}
}
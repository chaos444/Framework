#ifndef CHEATS_H
#define CHEATS_H

#include "Main.h"
#include "Drawing.h"

#include <Windows.h>
#include <iostream>

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#include <dwmapi.h>
#pragma comment(lib, "dwmapi.lib")


#define OFFSET_LOCALPLAYER 0xA7AFAC
#define OFFSET_ENTITYLIST 0x4A1D384


class LocalPlayer
{
public:
	int clientPlayer;
	int incrossid;
	int teamid;
	int health;

};


class InCrosshair : public LocalPlayer
{
public:

};

void Yarin(LocalPlayer* lPlayer, InCrosshair* InCH);

#endif
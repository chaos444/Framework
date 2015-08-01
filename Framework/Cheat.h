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

class TestClass
{
public :
	int TestInt; 
};

void Test(TestClass* TestClass1);

#endif
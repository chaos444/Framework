#include "DirectX.h"
#include "Cheat.h"
#include "MenuManager.h"

directx_t DirectX;
MenuManager mMenuManager;
LocalPlayer lPlayer;
InCrosshair InCH;

bool crosshair = true;
bool trigger = true;


void DirectxFunctions::MenuItems()
{
	Menu* menu1 = mMenuManager.createMenu(150, 300, 170, "Meher Framework ", true, Color::White, Color::White, Color::Red);
   menu1->addItem(&crosshair, TEXT("Crosshair"), ITEM_TYPES::ITEM_BOOL);
   menu1->addItem(&trigger, TEXT("Trigger Bot"), ITEM_TYPES::ITEM_BOOL);
}


void DirectxFunctions::DirectXInit(HWND hwnd)
{
	if (FAILED(Direct3DCreate9Ex(D3D_SDK_VERSION, &DirectX.Object)))
		exit(1);

	ZeroMemory(&DirectX.Param, sizeof(DirectX.Param));
	DirectX.Param.Windowed = true;
	DirectX.Param.BackBufferFormat = D3DFMT_A8R8G8B8;
	DirectX.Param.BackBufferHeight = Overlay.Height;
	DirectX.Param.BackBufferWidth = Overlay.Width;
	DirectX.Param.EnableAutoDepthStencil = true;
	DirectX.Param.AutoDepthStencilFormat = D3DFMT_D16;
	DirectX.Param.MultiSampleQuality = D3DMULTISAMPLE_NONE;
	DirectX.Param.SwapEffect = D3DSWAPEFFECT_DISCARD;
	

	if (FAILED(DirectX.Object->CreateDeviceEx(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &DirectX.Param, 0, &DirectX.Device)))
		exit(1);


	D3DXCreateFont(DirectX.Device, 16, 0, 0, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, "Arial", &DirectX.Font);

	if (!DirectX.Line)
		D3DXCreateLine(DirectX.Device, &DirectX.Line);
}


void DirectxFunctions::RenderDirectX()
{
	DirectX.Device->BeginScene();
	if (GetForegroundWindow() == Target.Window)
	{
		mMenuManager.Render();

		if (crosshair == true)
		{
			float centerx = Overlay.Width / 2, centery = Overlay.Height / 2;
			Drawing::Line(centerx - 3, centery, centerx - 10, centery, Color::Red);
			Drawing::Line(centerx + 3, centery, centerx + 10, centery, Color::Red);
			Drawing::Line(centerx, centery - 3, centerx, centery - 10, Color::Red);
			Drawing::Line(centerx, centery + 3, centerx, centery + 10, Color::Red);
		}

		if (trigger == true)
		{
			Yarin(&lPlayer, &InCH);
		}
		
	
	}


	DirectX.Device->EndScene();
	DirectX.Device->PresentEx(0, 0, 0, 0, 0);
	DirectX.Device->Clear(0, 0, D3DCLEAR_TARGET, 0, 1.0f, 0);
}

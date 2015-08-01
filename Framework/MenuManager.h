#ifndef MENU_MANAGER_H
#define MENU_MANAGER_H

#include "Direct.h"
#include "Drawing.h"
#include "Menu.h"
#include <vector>


//-----------------------------------------------------------------------------
// ============ MenuManager Class ================
//-----------------------------------------------------------------------------


class MenuManager
{
	int moveSelectedMenu;

	int menuNbrs;
	std::vector<Menu> menuList;

	POINT cursorPos;	//Current mouse point
	POINT diffCursorPos; //Offset From Mouse Last Point
	bool mouseMovement;

	clock_t elapsedTime, checkTime;

public:
	MenuManager();

	Menu* createMenu(int x, int y, int menuWidth, std::string menuTitle, bool isMovable, D3DCOLOR backgroundColor, D3DCOLOR textColor, D3DCOLOR selectedColor);	//create a Menu
	void menuMovement(int menuId);
	void playSound();
	void Render();


};

//////////////////////////////////////////////////////////////////////////////

#endif
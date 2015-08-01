#ifndef MENU_H
#define MENU_H

#include "Direct.h"
#include "Drawing.h"
#include <vector>
#pragma comment(lib, "WinMM.Lib")

//-----------------------------------------------------------------------------
// MENU DEFINE
//-----------------------------------------------------------------------------

#define MENU_ITEM_SIZE 15 //MENU_ITEM_SIZE
#define MENU_CHECKBOX_SIZE 10 //MENU_ITEM_SIZE
#define MENU_BORDER_RIGHT 20 //MENU_ITEM_SIZE

//-----------------------------------------------------------------------------
// Desc: ITEM Types Enumeration
//-----------------------------------------------------------------------------

enum ITEM_TYPES
{
	ITEM_BOOL = 0,
	ITEM_TEXT = 1,
	ITEM_FLOAT = 2
};

//////////////////////////////////////////////////////////////////////////////


//-----------------------------------------------------------------------------
// ITEM STRUCT
//-----------------------------------------------------------------------------

struct Item
{
	bool* b;
	float* value;
	char cItemName[16];
	int type;
};

//////////////////////////////////////////////////////////////////////////////


//-----------------------------------------------------------------------------
// ============ Menu Class ================
//-----------------------------------------------------------------------------


class Menu
{
	int posX, posY;		 // TOP LEFT OF MENU
	int nbrItems;		 // Number of items of the menu
	int currentItem;	 // Current item drawing
	int menuWidth;		 // Width of the menu
	bool isMovable;		 // Menu is allowed to be moved
	char cMenuName[32];  // Title of Menu

	D3DCOLOR backgroundColor;
	D3DCOLOR textColor;
	D3DCOLOR selectedColor;

public:
	void init(int x, int y, int _menuWidth, std::string menuTitle, bool movable, D3DCOLOR _backgroundColor, D3DCOLOR _textColor, D3DCOLOR _selectedColor);

	void addItem(bool* bActive, std::string itemName, int itemType);
	void addItem(float* value, std::string itemName, int itemType);

	void moveMenu(int x, int y);
	void drawItem(Item &item);

	bool containsMouseCursor(POINT mouseCoords);
	bool isMoveAllowed();

	int getX(); // get X coordinate of the menu (top left)
	int getY();	// get y coordinate of the menu (top left)
	int getItemsNbrs();
	int getWitdh();

	void drawGui(); //draw menu 

	bool switchItem(Item &item);

	bool deployed; // menu is deployed
	std::vector<Item> itemsTab; //This contain all items
};


//////////////////////////////////////////////////////////////////////////////

#endif
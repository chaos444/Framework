#include "Menu.h"

//-----------------------------------------------------------------------------
// Init a new Menu
//-----------------------------------------------------------------------------


void Menu::init(int x, int y, int _menuWidth, std::string menuTitle, bool movable, D3DCOLOR _backgroundColor, D3DCOLOR _textColor, D3DCOLOR _selectedColor)
{
	posX = x;
	posY = y;
	isMovable = movable;
	menuWidth = _menuWidth;
	backgroundColor = _backgroundColor;
	textColor = _textColor;
	selectedColor = _selectedColor;
	deployed = true;
	sprintf(cMenuName, "%s", menuTitle.c_str());
	nbrItems = 0;
}

//-----------------------------------------------------------------------------
// getItemsNbrs
//-----------------------------------------------------------------------------


int Menu::getItemsNbrs()
{
	return nbrItems;
}

//-----------------------------------------------------------------------------
// Add a new Item
//-----------------------------------------------------------------------------


void Menu::addItem(bool* bActive, std::string itemName, int itemType)
{
	Item it;
	it.b = bActive;
	it.type = itemType;
	sprintf(it.cItemName, "%s", itemName.c_str());
	itemsTab.push_back(it);
	nbrItems++;
}

void Menu::addItem(float* value, std::string itemName, int itemType)
{
	Item it;
	it.value = value;
	it.type = itemType;
	sprintf(it.cItemName, "%s", itemName.c_str());
	itemsTab.push_back(it);
	nbrItems++;
}

//-----------------------------------------------------------------------------
// Move the Menu to new Position
//-----------------------------------------------------------------------------


void Menu::moveMenu(int x, int y)
{
	posX = x;
	posY = y;
}

//-----------------------------------------------------------------------------
// Get Menu Pos
//-----------------------------------------------------------------------------


int Menu::getX()
{
	return posX;
}

int Menu::getY()
{
	return posY;
}

int Menu::getWitdh()
{
	return menuWidth;
}

//-----------------------------------------------------------------------------
// Get isMoveAllowed
//-----------------------------------------------------------------------------

bool Menu::isMoveAllowed()
{
	return isMovable;
}

//-----------------------------------------------------------------------------
// Switch On/Off an Item
//-----------------------------------------------------------------------------

bool Menu::switchItem(Item &item)
{
	*item.b = !*item.b;


	return *item.b;
}

//-----------------------------------------------------------------------------
// Draw an Item
//-----------------------------------------------------------------------------


void Menu::drawItem(Item &item)
{
	switch (item.type)
	{
	case ITEM_TYPES::ITEM_BOOL:

		Drawing::String(posX + 5, posY + ((currentItem + 1) * MENU_ITEM_SIZE), item.cItemName, textColor);
		Drawing::FilledRect(posX + menuWidth - MENU_BORDER_RIGHT, posY + ((currentItem + 1) * MENU_ITEM_SIZE), MENU_CHECKBOX_SIZE, MENU_CHECKBOX_SIZE, D3DCOLOR_ARGB(0, 0, 0, 0));
		Drawing::Rect(posX + menuWidth - MENU_BORDER_RIGHT, posY + ((currentItem + 1) * MENU_ITEM_SIZE), MENU_CHECKBOX_SIZE, MENU_CHECKBOX_SIZE, Color::White);

		if (item.b && *item.b)
		{
			Drawing::FilledRect(posX + menuWidth - MENU_BORDER_RIGHT + 2, posY + 2 + ((currentItem + 1) * MENU_ITEM_SIZE), MENU_CHECKBOX_SIZE - 3, MENU_CHECKBOX_SIZE - 3, selectedColor);
			//textColor = D3DCOLOR_ARGB(255, 255, 0, 0);
		}

		break;
	case ITEM_TYPES::ITEM_FLOAT:

		Drawing::String(posX + 5, posY + ((currentItem + 1) * MENU_ITEM_SIZE), item.cItemName, textColor);
		char t[20];
		sprintf(t, "%.2f", *item.value);
		Drawing::String(posX + menuWidth - MENU_BORDER_RIGHT * 2, posY + ((currentItem + 1) * MENU_ITEM_SIZE), t, textColor);

	default:
		break;
	}

	currentItem++;
}

//-----------------------------------------------------------------------------
// Draw Gui
//-----------------------------------------------------------------------------


void Menu::drawGui()
{
	currentItem = 0;

	if (deployed)
	{
		Drawing::Rect(posX, posY, menuWidth, (nbrItems + 1) * MENU_ITEM_SIZE, backgroundColor);
		//DrawBox(posX, posY, menuWidth, MENU_ITEM_SIZE - 1, backgroundColor);
		//DrawRadarArrowUp(posX, posY, true, White);
	}
	else
	{
		Drawing::Rect(posX, posY, menuWidth, MENU_ITEM_SIZE, backgroundColor);
		//DrawBox(posX, posY, menuWidth, MENU_ITEM_SIZE - 1, backgroundColor);
		//DrawRadarArrowDown(posX, posY, true, White);
	}

	Drawing::String(posX + 15, posY, cMenuName, Color::Orange);
}

//-----------------------------------------------------------------------------
// If this Menu contain Mouse
//-----------------------------------------------------------------------------

bool Menu::containsMouseCursor(POINT mouseCoords)
{
	int tempItem = nbrItems;
	if (!deployed) //////////////////////// Don't allow to move if we selected a invisible item pos
	{
		tempItem = 0;
	}

	return ((mouseCoords.x > posX && mouseCoords.x < posX + menuWidth) && (mouseCoords.y > posY && mouseCoords.y < posY + (tempItem + 1) * MENU_ITEM_SIZE));
}

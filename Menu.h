#pragma once
#include "ItemList.h"
#include "Item.h"
#include <vector>

//child class of itemList
class Menu : public ItemList
{
	//public methods
public:
	//constructor takes menu as a reference
	Menu(const string& menu);
	//deconstructor
	~Menu();
	//to String method from menu 
	string toString() const;
};


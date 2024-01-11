#pragma once
#include "ItemList.h"
#include "Item.h"
#include <vector>

class Menu : public ItemList
{
public:
	Menu(const string& filename);
	~Menu();
	string toString() const;
};


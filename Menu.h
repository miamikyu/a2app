#pragma once
#include "ItemList.h"
#include "Item.h"

class Menu : public ItemList
{
public:
	Menu(const string& filename);
	~Menu();
	string toString() const;
	Item* getItem(int itemNum)const;
	int getSize() const;
private:
	vector<Item*> items;
};


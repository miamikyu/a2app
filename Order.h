#pragma once
#include "ItemList.h"
#include "Item.h"

class Order : public ItemList
{
public:
	void add(Item* itemAdd);
	void remove(Item* itemRemove);
	void calculateTotal();
	void checkout();
	void help();
	Order();
	~Order();
private:
	vector<Item*>items;
};


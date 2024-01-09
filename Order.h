#pragma once
#include "ItemList.h"
#include "Item.h"

class Order : public ItemList
{
public:
	void add(Item* itemAdd);
	void remove(Item* itemRemove);
	float calculateTotal();

	void checkout();
	
	void help();
	Order();
	~Order();
	int getSize() const;
private:
	vector<Item*>items;
	float calculateDiscount(float total, int numofDiscounts);
	int eligibleItemCount;

};


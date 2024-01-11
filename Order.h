#pragma once
#include "ItemList.h"
#include "Item.h"
#include <vector>

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
private:
	float calculateDiscount(float total, int numofDiscounts);
	int eligibleItemCount;

};


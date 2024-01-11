#pragma once
#include "ItemList.h"
#include "Item.h"
#include <vector>
//othre child class of itemlist
class Order : public ItemList
{
	//public methods
public:
	//all the functions that the user needs to interact with the takeaway app
	//add items - takes an item from reference to add
	void add(Item* itemAdd);
	//removes items in the same way as add but removes from the order
	void remove(Item* itemRemove);
	//calculates the user's total
	float calculateTotal();
	//checkout the user giving them their discount and reciept
	void checkout();
	//gives the user help on what actions mean what
	void help();
	//constructor
	Order();
	//deconstructor
	~Order();
	//private methods
private:
	//private function to caluclate discount - takes a total and number of discounts 
	float calculateDiscount(float total, int numofDiscounts);
	//private attribute to see whether an item is eligible
	int eligibleItemCount;

};


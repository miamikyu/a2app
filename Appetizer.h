#pragma once
#include "Item.h"
//creates a child class of item
class Appetizer :public Item
{
	//public methods
public:
	//constructor
	Appetizer();
	//deconstructor
	~Appetizer();
	//to string method to display the shareable and two41 attributes
	string toString() const override;
	//two boolean attributes 
	bool shareable;
	bool two41;
};


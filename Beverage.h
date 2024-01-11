#pragma once
#include "Item.h"
//another child class of item
class Beverage : public Item
{
	//public methods and attributes
public:
	//the same toString method to output beverages own attributes
	string toString() const override;
	//function to determine whether a drink is alcoholic
	void isAlcoholic();
	//tow attributes special to beverage
	int abv;
	float volume;
};


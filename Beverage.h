#pragma once
#include "Item.h"
class Beverage : public Item
{
public:
	string toString() const override;
	void isAlcoholic();
	int abv;
	float volume;
};


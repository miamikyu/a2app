#pragma once
#include "Item.h"
class Appetizer :public Item
{
public:
	Appetizer();
	~Appetizer();
	string toString() const override;
	bool shareable;
	bool two41;
};


#pragma once
#include "Item.h"
class Appetizer :public Item
{
public:
	string toString() const override;
	bool shareable;
	bool two41;
};


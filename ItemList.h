#pragma once
#include <string>
#include <vector>
#include "Item.h";


using namespace std;

class ItemList
{
public:
	virtual void toString();
	virtual ~ItemList();
	vector<const Item*> items;
};


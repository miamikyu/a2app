#pragma once
#include <string>
#include <vector>
#include "Item.h";


using namespace std;

//Parent class - abstract clas
class ItemList
{
	//public methods
public:
	//another virtual function as order and menu need to overwrite
	virtual void toString();
	//virtual deconstructor
	virtual ~ItemList();
	//vector that the child classes will use to hold items
	vector<const Item*> items;
};


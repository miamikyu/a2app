#pragma once
#include <string>

using namespace std;
//parent class item
class Item
{
	//public methods
public:
	//use of a virtual string so that the child classes can override the parent class with their own attributes
	//using the toString method
	virtual string toString() const;
	//attributes that the parent and child class have 
	string name;
	int calories;
	float price;
};
//child class of item, but doesn't have any special attributes 
//will just inherit original attributes from item
class Main : public Item {

};


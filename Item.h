#pragma once
#include <string>

using namespace std;

class Item
{
public:
	virtual string toString() const;
	string name;
	int calories;
	float price;
};

class Main : public Item {

};


#include "Menu.h"
#include "ItemList.h"
#include "Appetizer.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

Menu::Menu(const string& menu) {
	ifstream file(menu);
	if (!file.is_open()) {
		cout << "Error opening file: " << menu << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
		Item* newItem = nullptr;

		stringstream ss(line);
		string type, name;
		int abv, calories;
		float price, volume;
		bool shareable, two41;
		getline(ss, type, ',');
		getline(ss, name, ',');
		ss >> price;
		ss.ignore();
		ss >> calories;
		ss.ignore();
		ss >> shareable;
		ss.ignore();
		ss >> two41;
		ss.ignore();
		ss >> volume;
		ss.ignore();
		ss >> abv;

		if (type == "a") {

			newItem = new Appetizer;
			dynamic_cast<Appetizer*>(newItem)->name = name;
			dynamic_cast<Appetizer*>(newItem)->price = price;
			dynamic_cast<Appetizer*>(newItem)->calories = calories;
			dynamic_cast<Appetizer*>(newItem)->shareable = shareable;
			dynamic_cast<Appetizer*>(newItem)->two41 = two41;
		}
		else if (type == "m") {
			newItem->name = name;
			newItem->price = price;
			newItem->calories = calories;
		}
		else if (type == "b") {
			newItem = new Beverage;
			dynamic_cast<Beverage*>(newItem)->name = name;
			dynamic_cast<Beverage*>(newItem)->price = price;
			dynamic_cast<Beverage*>(newItem)->calories = calories;
			dynamic_cast<Beverage*>(newItem)->abv = abv;
			dynamic_cast<Beverage*>(newItem)->volume = volume;
		}
		items.push_back(newItem);


		

	}

}
Menu::~Menu() {

}
string Menu::toString() const {
	string field;
	int index = 1;

	for (const Item* item : items) {
		field += to_string(index) + ". "+ item->toString() + "\n";
		index++;
	}
	return field;
}
Item* Menu::getItem(int itemNum)const {
	if (itemNum >= 1 && itemNum <= items.size()) {
		return items[itemNum - 1]; 
	}

	return nullptr;
}
int Menu::getSize() const {
	return items.size();
}

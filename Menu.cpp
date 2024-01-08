#include "Menu.h"
#include "ItemList.h"
#include "Appetizer.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

Menu::Menu(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "Error opening file: " << filename << endl;
		return;
	}
	string line;
	while (getline(file, line)) {
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
		ss >> abv;
		ss.ignore();
		ss >> volume;

		if (type == "a") {
			Appetizer* appetizer = new Appetizer;
			appetizer->name = name;
			appetizer->price = price;
			appetizer->calories = calories;
			appetizer->shareable = shareable;
			appetizer->two41 = two41;
			items.push_back(appetizer);
		}
		else if (type == "m") {
			Main* main = new Main;
			main->name = name;
			main->price = price;
			main->calories = calories;
			items.push_back(main);
		}
		else if (type == "b") {
			Beverage* beverage = new Beverage;
			beverage->name = name;
			beverage->price = price;
			beverage->calories = calories;
			beverage->abv = abv;
			beverage->volume = volume;
			items.push_back(beverage);
		}

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

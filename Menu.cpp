#include "Menu.h"
#include "ItemList.h"
#include "Appetizer.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>


Menu::Menu(const string& menu) {
	cout <<"menu to string";
	istringstream file(menu);
	string line;
	while (getline(file, line)) {
		cout << line << endl;
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

			Appetizer* a = new Appetizer;
			a->name = name;
			a->calories = calories;
			a->price = price;
			a->shareable = shareable;
			a->two41 = two41;
			items.push_back(a);
		}
		else if (type == "m") {
			Main* m = new Main;
			m->name = name;
			m->calories = calories;
			m->price = price;
			items.push_back(m);
		}
		else if (type == "b") {
			Beverage* b = new Beverage;
			b->name = name;
			b->calories = calories;
			b->price = price;
			b->volume = volume;
			b->abv = abv;
			items.push_back(b);
		}
		


		

	}

}
Menu::~Menu() {

}
string Menu::toString() const {
	string output;
	int index = 1;
	cout << items.size();
	for (const Item* item : items) {
		output +=index + ". " + items[index]->toString() + "\n";
		index++;
	}
	return output; 
}


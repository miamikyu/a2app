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
	ifstream file(menu);
	string line;
	vector<string>store;
	while (getline(file, line)) {
		store.push_back(line + ",");
	}
	file.close();
	vector<string>hold;
	string current_word;
	string type, name;
	bool shareable = false;
	bool two41 = false;
	int calories, abv;
	float price, volume;

	for(string line : store){
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ',')
			{
				hold.push_back(current_word);
				current_word = "";
			}
			else {
				current_word += line[i];
			}
		}


		if (hold[0] == "a") {
			Appetizer* a = new Appetizer;
			name = hold[1];
			calories = stoi(hold[3]);
			price = stof(hold[2]);
			if (shareable == 'y') {
				shareable = true;
			}
			else {
				shareable = false;
			}
			if (two41 == 'y') {
				two41 = true;
			}
			else {
				two41 = false;
			}
			a->name = name;
			a->calories = calories;
			a->price = price;
			a->shareable = shareable;
			a->two41 = two41;
			items.push_back(a);
		}
		else if (hold[0] == "m") {
			Main* m = new Main;
			name = hold[1];
			calories = stoi(hold[3]);
			price = stof(hold[2]);
			m->name = name;
			m->calories = calories;
			m->price = price;
			items.push_back(m);
		}
		else if (hold[0] == "b") {
			Beverage* b = new Beverage;
			name = hold[1];
			calories = stoi(hold[3]);
			price = stoi(hold[2]);
			volume = stoi(hold[6]);
			abv = stof(hold[7]);
			b->name = name;
			b->calories = calories;
			b->price = price;
			b->volume = volume;
			b->abv = abv;
			items.push_back(b);
		}
		else {
			cout << "Error" << endl;
		}
		hold.clear();
	}
}


Menu::~Menu() {

}
string Menu::toString() const {
	string output = "";
	int index = 1;
	for (const Item* item : items) {
		output += index + ". " + item->toString() + "\n";

		index++;
	}
	return output; 
}


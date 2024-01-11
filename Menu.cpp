#include "Menu.h"
#include "ItemList.h"
#include "Appetizer.h"
#include "Beverage.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

//constructor that opens the csv file and sets the attributes
Menu::Menu(const string& menu) {
	//used to open file
	ifstream file(menu);
	//string for reading line
	string line;
	//creating new vector to hold each line
	vector<string>store;
	//while loop to get each line
	while (getline(file, line)) {
		//push back line and "," to make sure commas are seen. pushback into vector
		store.push_back(line + ",");
	}
	//close file
	file.close();
	//new vector to hold each individual word
	vector<string>hold;
	//string to hold current char and push into hold
	string current_word;
	//setting all the attributes variables
	string type, name;
	bool shareable = false;
	bool two41 = false;
	int calories, abv;
	float price, volume;
	//for each line in the store vector
	for(string line : store){
		//another for loop until the size of line is met
		for (int i = 0; i < line.size(); i++) {
			//if line is a comma 
			if (line[i] == ',')
			{
				//pushback current word which is "," into hold
				hold.push_back(current_word);
				//resets current word
				current_word = "";
			}
			else {
				//else then current word is equal to line[i]
				current_word += line[i];
			}
		}

		//the first index holds the type of class needed to be instantiated
		if (hold[0] == "a") {
			//creates a new instance of class
			Appetizer* a = new Appetizer;
			//sets attributes to each index of hold
			name = hold[1];
			calories = stoi(hold[3]);
			price = stof(hold[2]);
			//if statement to see whether shareable is true or false
			if (hold[4] == "y") {
				shareable = true;
			}
			else {
				shareable = false;
			}
			//if statement to determine whether two41 is true or false
			if (hold[5] == "y") {
				two41 = true;
			}
			else {
				two41 = false;
			}
			//pushes the value into the class so theyre not empty
			a->name = name;
			a->calories = calories;
			a->price = price;
			a->shareable = shareable;
			a->two41 = two41;
			items.push_back(a);
		}
		//the first index holds the type of class needed to be instantiated
		else if (hold[0] == "m") {
			//creates a new instance of class
			Main* m = new Main;
			//sets attributes to each index of hold
			name = hold[1];
			calories = stoi(hold[3]);
			price = stof(hold[2]);
			m->name = name;
			m->calories = calories;
			m->price = price;
			items.push_back(m);
		}
		//the first index holds the type of class needed to be instantiated
		else if (hold[0] == "b") {
			//creates a new instance of class
			Beverage* b = new Beverage;
			//sets attributes to each index of hold
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
			//else it will produce an error
			cout << "Error" << endl;
		}
		//will clear hold
		hold.clear();
	}
}

//deconstructor
Menu::~Menu() {

}
//tostring function to print menu
string Menu::toString() const {
	//outputs empty string that will be filled with menu items
	string output = "";
	//creates an index for the menu so people can choose a number to order
	int index = 1;
	//for each item in item
	for (const Item* item : items) {
		//outputs the number index, then the value in toString then new line
		output +=to_string(index)+". " + item->toString() + "\n";
		//increments index for the next item
		index++;
	}
	//returns output
	return output; 
}


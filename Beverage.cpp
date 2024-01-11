#include "Beverage.h"
#include <iostream>

using namespace std;
//function to determine wether the beverage is alcoholic 
void Beverage::isAlcoholic() {
	//sets to false
	bool alcoholic = false;
	//if the attributes are greater than 0
	if (abv > 0 && volume > 0) {
		//will set to true
		alcoholic = true;
		//prints is alcoholic
		cout << "Drink is Alcoholic" << endl;
	}
	//else will print not alcoholic 
	else {
		cout << "Drink is not Alcoholic" << endl;
	}
}
//beveragees toString method
string Beverage::toString() const {
	//items attributes in Item toString
	string field = Item::toString();
	//abv attribute
	field += "Abv: " + to_string(abv);
	//placeholder for comma 
	field += ", ";
	//volume attribute
	field += "Volume: " + to_string(volume);
	//returns the strings
	return field;
	}
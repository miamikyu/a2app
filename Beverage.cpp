#include "Beverage.h"
#include <iostream>

using namespace std;

void Beverage::isAlcoholic() {
	bool alcoholic = false;
	if (abv > 0 && volume > 0) {
		alcoholic = true;
		cout << "Drink is Alcoholic" << endl;
	}
	else {
		cout << "Drink is not Alcoholic" << endl;
	}
}
string Beverage::toString() const {
	string field = Item::toString();
	field += "Abv: " + (abv);
	field += "Volume: " + to_string(volume);
	return field;
}
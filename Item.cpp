#include "Item.h"
#include <iostream>
using namespace std; 
string Item::toString() const {
    cout << "item to string";
    string field = "Name: " + name + "\n";
    field += "Calories: " + to_string(calories) + "\n";
    field += "Price: £" + to_string(price) + "\n";
    return field;
}
#include "Item.h"
#include <iostream>
using namespace std; 
string Item::toString() const {
    string field = "Name: " + name + ", ";
    field += "Calories: " + to_string(calories) + ", ";
    field += "Price: \x9C" + to_string(price) + ", ";
    return field;
}
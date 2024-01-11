#include "Item.h"
#include <iostream>
using namespace std; 
//items to string
string Item::toString() const {
    //this displays the name price and calories in strings for the child classes to use
    string field = "Name: " + name + ", ";
    field += "Calories: " + to_string(calories) + ", ";
    field += "Price: \x9C" + to_string(price) + ", ";
    //returns the strings
    return field;
}
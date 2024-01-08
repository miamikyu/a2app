#include "Item.h"
string Item::toString() const {
    string field = "Name: " + name + "\n";
    field += "Calories: " + to_string(calories) + "\n";
    field += "Price: £" + to_string(price) + "\n";
    return field;
}
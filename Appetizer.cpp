#include "Appetizer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std; 

string Appetizer::toString() const {
    string field = Item::toString();
    field += "Shareable: " + (shareable ? string("Yes") : string("No")) + "\n";
    field += "Two For One: " + (two41 ? string("Yes") : string("No")) + "\n";
    return field;
}
Appetizer::Appetizer(){

}
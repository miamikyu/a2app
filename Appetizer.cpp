#include "Appetizer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std; 

string Appetizer::toString() const {
    string field = Item::toString();
    field += "Shareable: " + (shareable ? string("Yes") : string("No")) + ", ";
    field += "Two For One: " + (two41 ? string("Yes") : string("No")) + ", ";
    return field;
}
Appetizer::Appetizer(){

}
Appetizer::~Appetizer() {
}
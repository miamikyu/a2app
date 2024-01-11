#include "Appetizer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std; 
//appetizers override toString
string Appetizer::toString() const {
    //this will print Items toString function
    string field = Item::toString();
    //then creates the field strings to display their attributes
    //shareable
    field += "Shareable: " + (shareable ? string("Yes") : string("No")) + ", ";
    //two41
    field += "Two For One: " + (two41 ? string("Yes") : string("No")) + ", ";
    //returns it 
    return field;
}
//constructor
Appetizer::Appetizer(){

}
//deconstructor
Appetizer::~Appetizer() {
}
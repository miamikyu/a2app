#include "Order.h"
#include <iostream>

using namespace std;
//constructor
Order::Order() {
	//holds variable to set as 0
	eligibleItemCount = 0;
}
//deconstructor
Order::~Order() {

}
//add item
void Order::add(Item* itemAdd) {
	//add item 
	//asks to enter quantity of item
	cout << "Enter quantity of item: " << endl;
	//creates an input for the answer
	int quantity;
	cin >> quantity;
	//takes the chosen item from parameters
	Item* chosenItem = itemAdd;
	//for loop until quantity is met - item is pushed back onto vector
	for (int i = 0; i < quantity; i++) {
		items.push_back(chosenItem);
	}
	//tels user item been added
	cout << "Item has been added" << endl;
	//asks to checkout
	cout << "Would you like to 'c' checkout?" << endl;
	//takes in input
	string cchoice;
	cin >> cchoice;
	//compares to make sure right choice
	if (cchoice == "c") {
		checkout();
	}
	else {
		//else error message
		cout << "Error" << endl;
	}
}
//thsi removes an item
void Order::remove(Item* itemRemove) {
	//uses lambda function to remove from the end of the item vector
	items.erase(std::remove_if(items.begin(), items.end(),
		[itemRemove](const Item* item) { return item == itemRemove; }),
		items.end());
	//tells user its removed from order
	cout << "Item removed from the order." << endl;

}
//calculates total function
float Order::calculateTotal() {
	//sets total
	float total = 0.0;
	//for loop item in items
	for (const Item* item : items) {
		//sets total to item attribute price
		total += item->price;
	}
	//returns total
	return total;
	
}
//checkout
void Order::checkout() {
	//total is taken from calculate total
	float total = calculateTotal();
	//tells user theyre checking out
	cout << "Checkout: " << endl;
	//creates a for loop to output what user ordered 
	cout << "Items ordered: " << endl;
	for (int i = 0; i < items.size(); i++) {
		int index = 1;
		cout <<to_string(index)<< items[i]->toString() << endl;
		index++;
	}
	//for item in item 
	for (const Item* item : items) {
		//this determines any eligible items for discount 
		if (eligibleItemCount >= 2) {
			int numofDiscounts = eligibleItemCount / 2;
			float discountAmount = calculateDiscount(total, numofDiscounts);
			//if they do then they will get a print of how much they saved
			cout << "Discount applied" << endl;
			cout << "Savings: \x9c" << discountAmount << endl;
			total - +discountAmount;
		}
	}
	//else the total will be dispalyed
	cout << "Total: \x9c" << total << endl;

}
//function to calculate discount
float Order::calculateDiscount(float total, int numofDiscounts) {
	//item price is fixed
	float itemPrice = 3.99;
	//returns 
	return itemPrice * numofDiscounts;
	}
//help menu
void Order::help() {
	cout << "Menu: View Menu \n Add: Add menu items to your order \n Remove: Remove menu items from your order \n Checkout: See your receipt and finish your order!" << endl;
}

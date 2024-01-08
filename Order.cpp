#include "Order.h"
#include <iostream>

using namespace std;

Order::Order() {

}
Order::~Order() {

}
void Order::add(Item* itemAdd) {
	//add itemy stuff 
	cout << "Would you like to 'r' or 'c' checkout?" << endl;
	string addchoice;
	cin >> addchoice;
	if (addchoice == "r") {
		order.remove();
	}
	else if (addchoice == "c") {
		order.checkout();
	}
	else {
		cout << "Please enter a choice" << endl;
	}
}
void Order::remove(Item* itemRemove) {

}
void Order::calculateTotal() {

}
void Order::checkout(/*insert from total*/) {
	cout << "Checkout: " << endl;
	for (Item* item : items) {
		//insert pointer shit for the actual order
		if (two41 == true) {
			cout << "Two - for - 1 discount applied" << endl;
			cout << "Savings: £3.99" << endl;
		}
		cout << "Total: £" << total << endl;
		cout << "Do you want to place your order?" << endl;
		cout << "'y' to confirm, or 'n' to modify" << endl;
		string answer;
		cin >> answer;
		if (answer == "y") {
			//save to txt file
			cout << "Your reciept has been saved" << endl;
		}
		else {
			cout << "Would you like to 'a' add or 'r' remove from order" << endl;
			string answer2;
			cin >> answer2;
			if (answer2 == "a") {
				order.add();
			}
			else if (answer2 == "r") {
				order.remove();
			}
		}
	}
	
}
void Order::help() {
	cout << "Menu: View Menu '\n' Add: Add menu items to your order '\n' Remove: Remove menu items from your order '\n' Checkout: See your receipt and finish your order!" << endl;
}
#include "Order.h"
#include <iostream>

using namespace std;

Order::Order() {
	eligibleItemCount = 0;
}
Order::~Order() {

}
void Order::add(Item* itemAdd) {
	//add item 
	cout << "Enter quantity of item: " << endl;
	int quantity;
	cin >> quantity;
	Item* chosenItem = itemAdd;
	for (int i = 0; i < quantity; i++) {
		items.push_back(chosenItem);
	}
	cout << "Item has been added" << endl;
	cout << "Would you like to 'c' checkout?" << endl;
	string addchoice;
	cin >> addchoice;
	if (addchoice == "c") {
		checkout();
	}
	else {
		cout << "Please enter a choice" << endl;
	}
}
void Order::remove(Item* itemRemove) {
	items.erase(std::remove_if(items.begin(), items.end(),
		[itemRemove](const Item* item) { return item == itemRemove; }),
		items.end());

	cout << "Item removed from the order." << endl;

}
float Order::calculateTotal() {
	float total = 0.0;
	for (const Item* item : items) {
		total += item->price;
	}
	return total;
	
}
void Order::checkout(/*insert from total*/) {
	
	float total = calculateTotal();

	cout << "Checkout: " << endl;
	for (int i = 0; i < items.size(); i++) {
		cout << "Items ordered" << i + 1 << ":" << endl;
		cout << items[i]->toString() << endl;
	}
	for (const Item* item : items) {
		//insert pointer shit for the actual order
		if (eligibleItemCount >= 2) {
			int numofDiscounts = eligibleItemCount / 2;
			float discountAmount = calculateDiscount(total, numofDiscounts);
			cout << "Discount applied" << endl;
			cout << "Savings: £" << discountAmount << endl;
			total - +discountAmount;
		}
	}
	cout << "Total: £" << total << endl;

}
float Order::calculateDiscount(float total, int numofDiscounts) {
	float itemPrice = 3.99;
	return itemPrice * numofDiscounts;
	}

void Order::help() {
	cout << "Menu: View Menu '\n' Add: Add menu items to your order '\n' Remove: Remove menu items from your order '\n' Checkout: See your receipt and finish your order!" << endl;
}

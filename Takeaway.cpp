/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();
	//output for the user to choose 
	cout << "menu" << endl;
	cout << "add" << endl;
	cout << "remove" << endl;
	cout << "checkout" << endl;
	cout << "help" << endl;
	cout << "exit" << endl;
	cout << "Please choose from the following: ";
	while (userCommand != "exit")
	{
		getline(cin, userCommand);
		parameters.clear();
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " ");

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " ");
		}

		string command = parameters[0];

		if (command.compare("menu") == 0) {
			cout << menu.toString();
		}
		else if (command.compare("add") == 0)
		{
			cout << "Please enter the item number you want to add: ";
			int itemNumber;
			cin >> itemNumber;

			Item* choice = menu.getItem(itemNumber); // you need to instantiate this using the menu object!
			if (choice != nullptr){
				order.add(choice);
			}
			else {
				cout << "Invalid number item" << endl;

			}
		}


		// You may also wish to implement the ability to add multiple items at once!
		// e.g. add 1 5 9 
		else if (command.compare("remove") == 0)
		{
			cout << "Enter the number of item remove: ";
			int itemnum;
			cin >> itemnum;
			if (itemnum >= 1 && itemnum <= order.getSize()) {
				Item* rchoice = menu.getItem(itemnum);
				order.remove(rchoice);
			}
			

		}
		else if (command.compare("checkout") == 0)
		{
			order.checkout();
		}
		else if (command.compare("help") == 0)
		{
			order.help();
		}
		else {
			cout << "Please choose an option: " << endl;
		}
	}

	cout << "Press any key to quit...";
	std::getchar();

}
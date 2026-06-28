/*
* Name: Idin Hall
* Date: June 6th 2026
* Course: CS-210
* Desciption: An Item-tracking program for a Grocery Store
*/
#include "grocery.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function to get integer input and manage invalid entries
int getMenuSelection() {
	int selection = 0; // Variable to store

	// Loop until valid integer from 1 and 4 
	while (!(cin >> selection) || selection < 1 || selection > 4) {
		    cout << "Invalid selection. Please select menu option (1-4): ";
		    cin.clear();										 // Error flag 
		    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discad invalid input 
	}
	return selection;
}

int main() {
	GroceryTracker tracker;  // GroceryTracke instantiate
	int userChoice = 0;      //	User's menu choise variable
	string searchItem = ""; // Store item to seach for variable 
	int itemFreq = 0;        // Store the returned frequency 

	// From a text file load the initial data
	tracker.loadData("CS210_Project_Three_Input_File.txt");
	
// Backup the data from data file
	tracker.backupData("frequency.dat");

	// Main menu loop using while(condition)
	while (userChoice != 4) {
		// Display menu
		cout << "\n ==============================" << endl;
		cout << "    Corner Groce menu" << endl;
		cout << "==============================" << endl;
		cout << "1. Find item frequency" << endl;
		cout << "2. Print all items frequency" << endl;
		cout << "3. Print histogram" << endl;
		cout << "4. Exit" << endl;
		cout << "Please select menu option:";

		// Get validated input
		userChoice = getMenuSelection();

		// Process the user's choice
		if (userChoice == 1) {
			cout << "Enter the item you wish to look for";
			cin.ignore(); // Clear the newline character from buffer
			getline(cin, searchItem);

			itemFreq = tracker.getItemFrequency(searchItem);
			cout << "\n>>> " << searchItem << " was purchased " << itemFreq << "times." << endl;
		}
		else if (userChoice == 2) {
			cout << "\n--- Frequency of All Item ___" << endl;
			tracker.printAllFrequencies();
		}
		else if (userChoice == 3) {
			cout << "\n--- Item Histogram ---" << endl;
	tracker.printHistogram();
		}
		else if (userChoice == 4) {
			cout << "Exiting program. Goodbye!" << endl;
		}
	}

	return 0;
}
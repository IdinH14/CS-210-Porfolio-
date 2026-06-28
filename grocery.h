/*
* Name: Idin Hall
* Date: June 6th 2026
* Course: CS-210
* Desciption: An Item-tracking program for a Grocery Store 
*/

#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <string>
#include <map>

// Frequencies and backups to manage the grocery store item
class GroceryTracker {
private:
	// Ordered map to store the grocery items
	std::map<std::string, int> grocList;

public:
	// Reads the input 
	void loadData(std::string fileName);

	// Creates the data file
	void backupData(std::string fileName);

	// Menu Option 1: Returns frequency 
	int getItemFrequency(std::string item);

	// Menu Option 2: Prints all frequencies
	void printAllFrequencies();

	// Menu Option 3: Prints frequencies
	void printHistogram();
};

#endif



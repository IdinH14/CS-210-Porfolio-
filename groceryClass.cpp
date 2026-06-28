/*
* Name: Idin Hall
* Date: June 6th 2026
* Course: CS-210
* Desciption: An Item-tracking program for a Grocery Store
*/

#include "grocery.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// Loads data form file into map 
void GroceryTracker::loadData(string fileName) {
	ifstream inputFile; // Input steam 
	string item = ""; // String to hold each item from the file 

	// Open the input file 
	inputFile.open(fileName);

	// Verify file opened 
	if (!inputFile.is_open()) {
		cout << "Error: Could not open file" << fileName << endl;
		exit(EXIT_FAILURE);
	}

	// Read each file line 
	while (getline(inputFile, item)) {
		grocList[item]++; // Increase the count 
	}

	// Close the file when finish
	inputFile.close();
}

// Backs up the data map to the output file 
void GroceryTracker::backupData(string fileName) {
	ofstream outputFile; // Stream object 

	// Output file open
	outputFile.open(fileName);

	// Confirm file opened
	if (!outputFile.is_open()) {
		cout << "ERROR: Could not open file" << fileName << endl;
		exit(EXIT_FAILURE);
	}

	// Write the file through the map 
	for (auto const& pair : grocList) {
		outputFile << pair.first << " " << pair.second << endl;
	}

	// Close output file
	outputFile.close();
}

// Frequency of a specific item returns 
int GroceryTracker::getItemFrequency(string item) {
	// Use count to check if the item exits in the map 
	if (grocList.count(item) > 0) {
		return grocList[item];
	}
	return 0; // If return 0 Item was not found 
}

// Prints all item and frequencies 
void GroceryTracker::printAllFrequencies() {
	// Write through the map 
	for (auto const& pair : grocList) {
		cout << pair.first << " " << pair.second << endl;
	}
}

// Write a histogram of the frequencies 
void GroceryTracker::printHistogram() {
	int numStars = 0; // Variable to count the frequency for the histogram 

	// Write through the map and create a histogram 
	for (auto const& pair : grocList) {
		numStars = pair.second;
		cout << pair.first << " ";
		// Write stars with the string constructor trick
		cout << string(numStars, '*') << endl;
	}
}
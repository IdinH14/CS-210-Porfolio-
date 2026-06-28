/**
* Name: Idin Hall
* Activity: CS 210 Poject two 
* Description: An application  that accepts finacial parameters
*/

#include <iostream>
#include <limits>
#include "InvestmentCalculator.h"

// Input validation 
double getValidDouble(std::string t_prompt) {
	double value;
	while (true) {
		std::cout << t_prompt;
		if (std::cin >> value && value >= 0.0) {
			return value;
		} else {
			std::cout << "Invalid entry. Please enter a valid non-negative number. \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

int main() {
	char userChoice = 'y';

	while (userChoice == 'y' || userChoice == 'Y') {
		std::cout << "=======================================\n";
		std::cout << "************** Data Input *************\n";
		std::cout << "=======================================\n";

		double initInv = getValidDouble("Initial Investment Amount: $");
		double monthlyDep = getValidDouble("Monthly Deposit: $");
		double interestRate = getValidDouble("Annual Interest (Persentage %): ");

		int years;
		while (true) {
			std::cout << "Number of Years: ";
			if (std::cin >> years && years > 0) {
				break;
			}
			else {
				std::cout << "Invalid entry. Please enter an interger greater than 0. \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits < std::streamsize>::max(), '\n');
			}
		}

		std::cout << "\nPress Enter to calculate your report...";
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin.get();

		// Map input 
		InvestmentCalculator myCalc;
		myCalc.setInitialInvestment(initInv);
		myCalc.setMonthlyDeposit(monthlyDep);
		myCalc.setAnnualInterest(interestRate);
		myCalc.setNumYears(years);

		// Run display 
		myCalc.displayReportWithoutDeposits();
		myCalc.displayReportWithDeposits();

		std::cout << "\nWould you like to run another calculation? (y/n): ";
		std::cin >> userChoice;
	}

	std::cout << "\nThank you for using the Airgead Banking System. Goodbye!\n";
	return 0;
}
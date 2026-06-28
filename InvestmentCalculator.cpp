#include "InvestmentCalculator.h"
#include <iostream>
#include<iomanip>

// Constructor Initial
InvestmentCalculator::InvestmentCalculator() {
	m_initialInvestment = 0.0;
	m_monthlyDeposit = 0.0;
	m_annualInterest = 0.0;
	m_numYears = 0;
}

// Setters definition
void InvestmentCalculator::setInitialInvestment(double t_amount) { m_initialInvestment = t_amount; }
void InvestmentCalculator::setMonthlyDeposit(double t_amount) { m_monthlyDeposit = t_amount; }
void InvestmentCalculator::setAnnualInterest(double t_rate) { m_annualInterest = t_rate; }
void InvestmentCalculator::setNumYears(int t_years) { m_numYears = t_years; }

// Getters Definition
double InvestmentCalculator::getInitialInvestment() const { return m_initialInvestment; }
double InvestmentCalculator::getMonthlyDeposit() const { return m_monthlyDeposit; }
double InvestmentCalculator::getAnnualInterest() const { return m_annualInterest; }
int InvestmentCalculator::getNumYears() const { return m_numYears; }

// Report
void InvestmentCalculator::displayReportWithoutDeposits() const {
	std::cout << "\n Balance and Interest without Additional Monthly Deposits   \n";
	std::cout << "============================================================\n";
	std::cout << std::setw(6) << "Year" << std::setw(26) << "Year-End Balance" << std::setw(28) << "Year-End Earned Interest\n";
	std::cout << "-----------------------------------------------------------\n";

	double currentBalance = m_initialInvestment;
	double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

	for (int i = 1; i <= m_numYears; ++i) {
		double yearlyInterestEarned = 0.0;

		for (int m = 1; m <= 12; ++m) {
			double monthlyInterest = currentBalance * monthlyInterestRate;
			yearlyInterestEarned += monthlyInterest;
			currentBalance += monthlyInterest;
		}

		std::cout << std::setw(6) << 1
			      << std::setw(26) << std::fixed << std::setprecision(2) << "$" << currentBalance
			      << std::setw(28) << std::fixed << std::setprecision(2) << "$" << yearlyInterestEarned << "\n";
	}
}

// Report 
void InvestmentCalculator::displayReportWithDeposits() const {
	std::cout << "\n    Balance and Interest with Additional Monthly Deposits    \n";
	std::cout << "=============================================================\n";
	std::cout << std::setw(6) << "Year" << std::setw(26) << "Year-End Balance" << std::setw(28) << "Year_End Earned Interest\n";
	std::cout << "--------------------------------------------------------------\n";

	double currentBalance = m_initialInvestment;
	double monthlyInterestRate = (m_annualInterest / 100.0) / 12.0;

	for (int i = 1; i <= m_numYears; ++i) {
		double yearlyInterestEarned = 0.0;

		for (int m = 1; m <= 12; ++m); {
			// Deposit 
			currentBalance += m_monthlyDeposit;
			double monthlyInterest = currentBalance * monthlyInterestRate;
			yearlyInterestEarned += monthlyInterest;
			currentBalance += monthlyInterest;
		}

		std::cout << std::setw(6) << i
			      << std::setw(26) << std::fixed << std::setprecision(2) << "$" << currentBalance
			      << std::setw(28) << std::fixed << std::setprecision(2) << "$" << yearlyInterestEarned << "\n";
	} 

}
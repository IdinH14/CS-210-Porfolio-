#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
	double m_initialInvestment;
	double m_monthlyDeposit;
	double m_annualInterest;
	int m_numYears;

public:
	// Defaul Constructor
	InvestmentCalculator();

	//Setters
	void setInitialInvestment(double t_amount);
	void setMonthlyDeposit(double t_amount);
	void setAnnualInterest(double t_rate);
	void setNumYears(int t_years);

	// Getters
	double getInitialInvestment() const;
	double getMonthlyDeposit() const;
	double getAnnualInterest() const;
	int getNumYears() const;

	//Report generation methods
	void displayReportWithoutDeposits() const;
	void displayReportWithDeposits() const;
};

#endif



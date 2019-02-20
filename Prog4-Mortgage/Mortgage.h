#pragma once
// header file for Mortgage class

class Mortgage
{
private:
	double monthlyPayment;		// the monthly payment
	double loan;				// the dollar amount of the loan
	double rate;				// the annual interest rate
	int years;					// the number of years of the loan
	double totalPaid;			// total paid to the bank at the end of the loan period
public:
	Mortgage(double Loan, int Years, double Rate); // constructor to get initial values
	void setLoan(double Loan);		// function for setting the loan amount
	void setRate(double Rate);		// for setting interest rate
	void setYear(int Years);		// for setting number of years of the loan
	double getMonthlyPayment();		// get monthly payment amount
	double getTotalPaid();			// get total paid to bank 
	
};
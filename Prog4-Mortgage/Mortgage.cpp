// implementation file for Mortgage class
#include <iostream>
#include <cmath>
using namespace std;

#include "Mortgage.h"
double calcTerm(int Years, int rate);
double calcPayment(double term, double Loan, double Rate);

// constructor to get initial values
Mortgage::Mortgage(double Loan, int Years, double Rate)
{
	loan = Loan;
	rate = Rate;
	years = Years;
}

// function for setting the loan amount
void Mortgage::setLoan(double Loan)
{
	loan = Loan;
}

// for setting interest rate
void Mortgage::setRate(double Rate)
{
	rate = Rate;
}

// for setting number of years of the loan
void Mortgage::setYear(int Years)
{
	years = Years;
}

// get monthly payment amount
double Mortgage::getMonthlyPayment() 
{
	double term = calcTerm(years, rate);
	monthlyPayment = calcPayment(term, loan, rate);
	return monthlyPayment;
}

// get total paid to bank 
double Mortgage::getTotalPaid() 
{
	int t = 12.0 * years;
	double term = calcTerm(years, rate);
	monthlyPayment = calcPayment(term, loan, rate);
	totalPaid = monthlyPayment * t;

	return totalPaid;
}

/*===================================
name: calcTerm
function: calculates TERM value needed to calculate monthly payment
parameters: years - number of years for the loan; rate - interest rate
return: true if input is an int
=====================================*/
double calcTerm(int Years, int Rate) 
{
	double x = (1.0 + (Rate / 12.0));
	double y = (12.0 * Years);
	double term = pow(x, y);
	return term;
}

/*===================================
name: calcPayment
function: calculates monthly payment amount
parameters: term - value calculated in calcTerm; Loan - loan amount; Rate - interest rate
return: true if input is an int
=====================================*/
double calcPayment(double term, double Loan, double Rate) 
{
	double payment = ((Loan * term * (Rate / 12.0)) / (term - 1.0));
	return payment;
}
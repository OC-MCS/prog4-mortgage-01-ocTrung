// implementation file for Mortgage class
#include <iostream>
#include <cmath>
using namespace std;

#include "Mortgage.h"

double calcTerm(int Years, int rate);
double calcPayment(double term, double Loan, double Rate);

Mortgage::Mortgage(double Loan, int Years, double Rate)
{
	loan = Loan;
	rate = Rate;
	years = Years;
}

void Mortgage::setLoan(double Loan)
{
	loan = Loan;
}

void Mortgage::setRate(double Rate)
{
	rate = Rate;
}

void Mortgage::setYear(int Years)
{
	years = Years;
}

double Mortgage::getMonthlyPayment()
{
	double term = calcTerm(years, rate);
	monthlyPayment = calcPayment(term, loan, rate);
	return monthlyPayment;
}

double Mortgage::getTotalPaid()
{
	int t = 12 * years;
	double term = calcTerm(years, rate);
	monthlyPayment = calcPayment(term, loan, rate);
	totalPaid = monthlyPayment * t;

	return totalPaid;
}

double calcTerm(int Years, int rate) // calculates TERM value needed to calculate monthly payment
{
	double x = (1.0 + (rate / 12.0));
	double y = (12.0 * Years);
	double term = pow(x, y);
	return term;
}

double calcPayment(double term, double Loan, double Rate) // calculates monthly payment amount
{
	double payment = ((Loan * term * (Rate / 12.0)) / (term - 1.0));
	cout << "monthly payment: " << payment << endl;
	return payment;
}
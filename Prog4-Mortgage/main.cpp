//============================================================
// Trung Nguyenvo
// due: 2.20.19
// Programming Assignment #4
// Description: Mortgage
//============================================================
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "Mortgage.h"
bool parseInt(string sval, int& val);
bool parseFloat(string sval, float& val);
bool verify(string inputyear, int &years);
bool verify(string input, float &val);

int main()
{
	float loan = 20;		// holds loan value, initialized to test constructor
	int years = 1;			// holds year value, initialized to test constructor
	float rate = 1;			// holds rate value, initialized to test constructor
	bool validYear = true;	// returns true if input for years is true
	bool validLoan = true;	// returns true if input for loan amount is true
	bool validRate = true;	// returns true if input for interest rate is true
	string sloan;			// holds loan input from user to convert to float
	string syears;			// holds year input from user to convert to float
	string srate;			// holds rate input from user to convert to float
	Mortgage a(loan, years, rate); // creating mortgage instance 'a' and testing constructor

// get input from user	
	cout << "What is your loan amount?" << endl;
	validLoan = verify(sloan, loan);
	cout << "Number of years for the loan?" << endl;
	validYear = verify(syears, years);
	cout << "Annual interest rate?" << endl;
	validRate = verify(srate, rate);

// tell user which input is valid, calculate mortgage if all inputs are valid 
	if (!validLoan || !validYear || !validRate)
	{
		if (!validLoan)
		{
			cout << "Input for loan is invalid, please enter a non-negative number" << endl;
		}
		if (!validYear)
		{
			cout << "Input for year(s) is invalid, please enter a non-negative number" << endl;
		}
		if (!validRate)
		{
			cout << "Input for interest rate is invalid, please enter a non-negative number" << endl;
		}
	}
	else
	{
		// tests set and get member functions
		a.setLoan(loan); 
		a.setRate(rate);
		a.setYear(years);
		cout << fixed << setprecision(2);
		cout << "monthly payment: " << a.getMonthlyPayment() << endl;
		cout << "total payment overall: " << a.getTotalPaid() << endl;
	}

	return 0;
}

/*===================================
name: verify 
function: verifies that user input is an int
parameters: inputyear - user input as a string; years - user input converted to int
return: true if input is an int
=====================================*/
bool verify(string inputyear, int &years)
{
	bool validInput = true;

	getline(cin, inputyear);
	if (!parseInt(inputyear, years))
	{
		validInput = false;
	}
	else if (years < 0)
	{
		validInput = false;
	}

	return validInput;
}

/*===================================
name: verify
function: verifies that user input is a float
parameters: inputyear - user input as a string; years - user input converted to float
return: true if input is a float
=====================================*/
bool verify(string input, float &val)
{
	bool validInput = true;

	getline(cin, input);
	if (!parseFloat(input, val))
	{
		validInput = false;
	}
	else if (val < 0)
	{
		validInput = false;
	}

	return validInput;
}

/*===================================
name: parseInt
function: validates input is an int
return: true if it is an int, false if not
=====================================*/
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}

/*===================================
name: parseFloat
function: validates input is a float
return: true if it is a float, false if not
=====================================*/
bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval);   // or use stof for string-to-float
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;
}
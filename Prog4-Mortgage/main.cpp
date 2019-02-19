#include <iostream>
#include <string>
using namespace std;

#include "Mortgage.h"
bool parseInt(string sval, int& val);
bool parseFloat(string sval, float& val);
bool verify(string inputyear, int &years);
bool verify(string input, float &val);

int main()
{
	float loan;
	int years;
	float rate;
	bool validYear = true;
	bool validLoan = true;
	bool validRate = true;
	string sloan;
	string syears;
	string srate;

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
		Mortgage a(loan, years, rate);
		cout << "monthly payment: " << a.getMonthlyPayment() << endl;
		cout << "total payment overall: " << a.getTotalPaid() << endl;
	}

	return 0;
}

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
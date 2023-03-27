// Codey Sivley for CS 318, Dr. Rimes
// 01/08/2020
// Homework01-08.cpp
// Problem: 16. Senior Citizen Property Tax

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//prototypes

//GLOBAL FILE ACCESS
//file in/out
ifstream infi;
ofstream oufi;

int main() {

	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Senior Citizen Property Tax\n";
	cout << "----------------\n";

	//file I/O setup
	oufi.precision(2);
	oufi << fixed;
	oufi.open("PropertyTax.txt");
	oufi << "Codey Sivley\n";
	oufi << "Senior Citizen Property Tax\n";
	oufi << "01/08/2020\n" << endl;
	oufi << "=======================================\n";

	//table breakout
	const char tab = ' ';
	const char spc = '.';
	const int t1 = 18;
	const int t2 = 20;

	//program start
	float houseValue = 158000.00;
	float perHundred = 2.64;
	float assessedVal = houseValue * .6;
	float payable = assessedVal - 5000;
	float taxDue = (payable / 100) * perHundred;
	float payments = taxDue * .25;


	//output to file
	oufi << "Property Value : $" << houseValue << endl;
	oufi << "Assessed Value : $" << assessedVal << endl;
	oufi << "Payable : $" << payable << endl;
	oufi << "Tax Due : $" << taxDue << endl;
	oufi << "Four quarterly payments: $" << payments << " each." << endl;
	oufi << "---------------------------------------\n";

	return 0;
}//end main

//Toolbox

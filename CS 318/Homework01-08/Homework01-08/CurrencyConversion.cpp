// Codey Sivley for CS 318, Dr. Rimes
// 01/08/2020
// Homework01-08.cpp
// Problem: 13. Currency

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
	cout << "Currency Conversion\n";
	cout << "----------------\n";

	//file I/O setup
	oufi.precision(2);
	oufi << fixed;
	oufi.open("CurrencyConversions.txt");
	oufi << "Codey Sivley\n";
	oufi << "Currency Conversion\n";
	oufi << "01/08/2020\n" << endl;
	oufi << "=======================================\n";

	//table breakout
	const char tab = ' ';
	const char spc = '.';
	const int t1 = 18;
	const int t2 = 20;

	//program start
	float usd = 1.00;
	float krona = 9.47;
	float belDol = 2.02;
	float paanga = 2.29;

	//output to file
	oufi << left << setw(t2) << setfill('.') << "Currency";
	oufi << left << setw(t1) << setfill(tab) << "Value in US Dollars" << endl;
	oufi << "---------------------------------------\n";
	oufi << left << setw(t2) << setfill(tab) << "US Dollars";
	oufi << left << setw(t1) << setfill(tab) << 100 * usd << endl;
	oufi << left << setw(t2) << setfill(tab) << "Swedish Krona";
	oufi << left << setw(t1) << setfill(tab) << 100 * krona << endl;
	oufi << left << setw(t2) << setfill(tab) << "Belize Dollar";
	oufi << left << setw(t1) << setfill(tab) << 100 * belDol << endl;
	oufi << left << setw(t2) << setfill(tab) << "Tonga Paanga";
	oufi << left << setw(t1) << setfill(tab) << 100 * paanga << endl;
	oufi << "---------------------------------------\n";

	return 0;
}//end main

//Toolbox

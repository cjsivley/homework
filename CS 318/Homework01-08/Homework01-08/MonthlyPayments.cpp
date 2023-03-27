// Codey Sivley for CS 318, Dr. Rimes
// 01/08/2020
// Homework01-08.cpp
// Problem: 19. Monthly Payments

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

	float rate, annRate, rateTrue, Y, L, N, payment, totalPaid; // r= monthly interest, l = amount of loan

	//UI start
	cout << "Codey Sivley\n";
	cout << "Chapter 3 Problem 19: Monthly Payments\n";
	cout << "----------------\n";
	cout << "Enter Loan Amount:";
	cin >> L;
	cout << "Enter Annual Interest Rate:";
	cin >> annRate;
	cout << "Enter Years:";
	cin >> Y;
	cout << "-----------------\n";

	//calculation
	N = Y * 12;
	rate = annRate / 12;
	rateTrue = rate / 100;
	payment = ((rateTrue * (pow((1 + rateTrue), N))) / (pow((1 + rateTrue), N) - 1)) * L;
	totalPaid = (payment * N);

	//file I/O setup
	oufi.precision(2);
	oufi << fixed;
	oufi.open("MonthlyPayments.txt");
	oufi << "Codey Sivley\n";
	oufi << "Monthly Payments\n";
	oufi << "01/08/2020\n" << endl;
	oufi << "=======================================\n";

	//table breakout
	const char tab = ' ';
	const int t1 = 10;
	const int t2 = 30;

	//output to file

	oufi << left << setw(t2) << setfill(tab) << "Loan Amount: ";
	oufi << right << setw(t1) << setfill(tab) << L << endl;
	oufi << left << setw(t2) << setfill(tab) << "Monthly interest rate: ";
	oufi << right << setw(t1) << setfill(tab) << rate << endl;
	oufi << left << setw(t2) << setfill(tab) << "Number of payments: ";
	oufi << right << setw(t1) << setfill(tab) << N << endl;
	oufi << left << setw(t2) << setfill(tab) << "Monthly payment: ";
	oufi << right << setw(t1) << setfill(tab) << payment << endl;
	oufi << left << setw(t2) << setfill(tab) << "Amount paid back: ";
	oufi << right << setw(t1) << setfill(tab) << totalPaid << endl;
	oufi << left << setw(t2) << setfill(tab) << "Interest paid: ";
	oufi << right << setw(t1) << setfill(tab) << totalPaid - L << endl;
	oufi << "---------------------------------------\n";

	return 0;
}//end main

//Toolbox

// Codey Sivley for CS 318, Dr. Rimes
// 01/08/2020
// Homework01-08.cpp
// Problem: 21. How Many Pizzas?

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//prototypes
void pizzaCalc();

//GLOBAL FILE ACCESS
//file in/out
ifstream infi;
ofstream oufi;

int main() {

	//console formatting
	cout.precision(1);
	cout << fixed;
	cout << showpoint;

	//file I/O setup
	oufi.precision(2);
	oufi << fixed;
	oufi.open("HowManyPizzas.txt");
	oufi << "Codey Sivley\n";
	oufi << "How Many Pizzas?\n";
	oufi << "01/08/2020\n" << endl;
	oufi << "=======================================\n";

	//run program 3 times
	int runs = 0;
	while (runs < 3) {
		pizzaCalc();
		++runs;
	}

	return 0;
}//end main

//Toolbox
void pizzaCalc() {
	//takes in pizza size and party attendees, calculates number of pizzas needed.
	int dia = 0;
	int peeps = 0;

	//UI start
	cout << "Enter diameter of pizza: ";
	cin >> dia;
	cout << "Enter number of party attendees: ";
	cin >> peeps;
	cout << "-----------------\n";

	//calculation
	float r = dia / 2;
	float area = 3.14 * (r * r);
	float slices = area / 14.125;
	int slicesNeeded = peeps * 4;
	int pizzasNeeded = slicesNeeded / slices;

	oufi << "For " << peeps << " people, order " << pizzasNeeded << " " << dia << " inch pizzas.\n" << endl;
	oufi << "=======================================\n";

	return;

}
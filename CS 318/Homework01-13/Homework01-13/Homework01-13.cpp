// Codey Sivley for CS 318, Dr. Rimes
// 01/13/2020
// Homework01-13.cpp
// Problem: Fibonacci Loops

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//prototypes
void fiboFor();
void fiboDo();
void fiboWhile();

//GLOBAL FILE ACCESS
//file in/out
ofstream oufi;

int main() {
	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;
	cout << "Codey Sivley\n";
	cout << "----------------\n";
	cout << "Fibonacci Loops\n";

	oufi.precision(2);
	oufi << fixed;
	oufi.open("FibonacciLoops.txt");
	oufi << "Codey Sivley\n";
	oufi << "Fibonacci Loops\n01/13/2020\n";
	oufi << "=======================================\n";

	//START//

	//to save on paper, creating each loop as a function
	//each run is labeled in the output
	fiboFor();
	fiboDo();
	fiboWhile();

	oufi.close();
	return 0;
}//main end

//Toolbox
void fiboFor() {
	//fibonacci using for loop
	oufi << "For Loop Version" << endl;
	int n1, n2, nSum;
	n1 = 0;
	n2 = 10;

	for (int i = 5; i < 88; i = i + 5) {
		nSum = n1 + n2;
		n1 = n2;
		n2 = nSum;
	}
	oufi << "At the end of day 88, there are " << n2 << " pounds of green crud." << endl;
			oufi << "=======================================\n";
}

void fiboDo() {
	//fibonacci using do while loop
	oufi << "Do While Version" << endl;
	int i, n1, n2, nSum;
	n1 = 0;
	n2 = 10;
	i = 5;

	do {
		nSum = n1 + n2;
		n1 = n2;
		n2 = nSum;
		i = i + 5;
	} while (i < 88);
	oufi << "At the end of day 88, there are " << n2 << " pounds of green crud." << endl;
	oufi << "=======================================\n";
}

void fiboWhile() {
	//fibonacci using while loop
	oufi << "While Version" << endl;
	int i, n1, n2, nSum;
	i = 5;
	n1 = 0;
	n2 = 10;

	while (i < 88) {
		nSum = n1 + n2;
		n1 = n2;
		n2 = nSum;
		i = i + 5;
	}
	
	oufi << "At the end of day 88, there are " << n2 << " pounds of green crud." << endl;
	oufi << "=======================================\n";
}
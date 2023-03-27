// Codey Sivley for CS 318, Dr. Rimes
// 01/08/2020
// Homework01-15.cpp
// Problem: Function Program

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//GLOBAL FILE ACCESS
ifstream infi;
ofstream oufi;

//prototypes
float Read();
void Print(float);
float Sum(float, float);
float Avg(float, float);
float Dif(float, float);
float Pow(float, float);
float Lar(float, float);
float Sma(float, float);

int main() {
	//console formatting
	cout.precision(3);
	cout << fixed;
	cout << showpoint;

	//file formatting
	oufi.precision(3);
	oufi << fixed;
	oufi << showpoint;

	oufi.open("FunctionProgram.txt");
	oufi << "Codey Sivley\n";
	oufi << "Function Program\n01/15/2020\n";
	oufi << "=======================================\n";

	////////////////////Start///////////////////////
	float n1, n2, n3, n4, n5;
	//read in 5 numbers
	n1 = Read();
	n2 = Read();
	n3 = Read();
	n4 = Read();
	n5 = Read();
	//print out 5 numbers
	oufi << "print out 5 numbers" << endl;
	Print(n1);
	Print(n2);
	Print(n3);
	Print(n4);
	Print(n5);

	//print out sum of 5 numbers
	oufi << "print out sum of 5 numbers" << endl;
	Print(Sum(Sum(Sum(Sum(n1, n2), n3), n4), n5));

	//print out average of 5 numbers
	oufi << "print out average of 5 numbers" << endl;
	Print(Avg(Sum(Sum(Sum(Sum(n1, n2), n3), n4), n5), 5));

	//print difference between the first number and the fifth number
	oufi << "print difference between the first number and the fifth number" << endl;
	Print(Dif(n1, n5));

	//print difference between second and fourth number
	oufi << "print difference between second and fourth number" << endl;
	Print(Dif(n2, n4));

	//print first number raised to the third number power
	oufi << "print first number raised to the third number power" << endl;
	Print(Pow(n1, n3));

	//print second number raised to the fifth number power
	oufi << "print second number raised to the fifth number power" << endl;
	Print(Pow(n2, n5));

	//print largest of 5 numbers
	oufi << "print largest of 5 numbers" << endl;
	Print(Lar(Lar(Lar(Lar(n1, n2), n3), n4), n5));

	//print smallest of 5 numbers
	oufi << "print smallest of 5 numbers" << endl;
	Print(Sma(Sma(Sma(Sma(n1, n2), n3), n4), n5));

	//print average of four largest values
	oufi << "print average of four largest values" << endl;
	Print(Avg((Dif(Sum(Sum(Sum(Sum(n1, n2), n3), n4), n5), Sma(Sma(Sma(Sma(n1, n2), n3), n4), n5))), 4));

	//print average of four smallest values
	oufi << "print average of four smallest values" << endl;
	Print(Avg((Dif(Sum(Sum(Sum(Sum(n1, n2), n3), n4), n5), Lar(Lar(Lar(Lar(n1, n2), n3), n4), n5))), 4));

	//print running total of the five numbers
	oufi << "print running total of the five numbers" << endl;
	Print(n1);
	Print(Sum(n1, n2));
	Print(Sum(Sum(n1, n2), n3));
	Print(Sum(Sum(Sum(n1, n2), n3), n4));
	Print(Sum(Sum(Sum(Sum(n1, n2), n3), n4), n5));

	//end formatting and cleanup
	oufi << "=======================================\n";
	oufi.close();

	return 0;
}//end main

//toolbox
float Read() {
	//reads in a float from cin
	float x;
	cout << "Enter numbers:>";
	cin >> x;
	return x;
}

void Print(float x) {
	//prints supplied float
	oufi << x << endl;
	return;
	}

float Sum(float x, float y) {
	//sums two floats, returns sum
	float z = x + y;
	return z;
}

float Avg(float x, float y) {
	//accepts total as x, divisor as y, returns average
	float z = x / y;
	return z;
}

float Dif(float x, float y) {
	//accepts two floats, subtracts and returns difference
	float z = x - y;
	return z;
}

float Pow(float x, float y) {
	//accepts x as float, exponent as y, raises x to the power of y
	float z;
	z = x;
	for (int i = 1; i < y; i++) {
		z = z * x;
	}
	return z;
}

float Lar(float x, float y) {
	//accepts x and y, returns larger
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

float Sma(float x, float y) {
	//accepts x and y, returns smaller
	if (x < y) {
		return x;
	}
	else {
		return y;
	}
}

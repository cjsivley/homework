// Codey Sivley for CS 318, Dr. Rimes
// 02/10/2020 Late Submission
// BubbaAdd.cpp
// Problem: Bubba Add C-Strings

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

//prototypes
void LoadCString(int[]);
void InitCString(int[]);
void AddCStrings(int[], int[], int[]);
void PrintCString(int[]);

int main() {
	//console formatting
	oufi.precision(2);
	oufi << fixed;
	oufi << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Bubba Add 318\n";
	cout << "----------------\n";

	//file I/O setup
	infi.open("BigNumber4.dat");
	if (!infi) {
		oufi << "Error reading file" << endl;
		return 0;
	}

	oufi.precision(2);
	oufi << fixed;
	oufi.open("BubbaAddResult.txt");
	oufi << "Codey Sivley\n";
	oufi << "Bubba Add 318 Result\n02/10/2020\nLate Submission" << endl;
	oufi << "=======================================" << endl;

	//variable declaration
	const int MAX = 36;
	int numA[MAX];
	int numB[MAX];
	int total[MAX];

	//sketchpad
	while (!infi.eof()) {
		InitCString(numA);
		InitCString(numB);
		InitCString(total);


		LoadCString(numA);
		oufi << "  ";
		PrintCString(numA);
		LoadCString(numB);
		oufi << "+ ";
		PrintCString(numB);
		oufi << "--------------------------------------\n";
		AddCStrings(numA, numB, total);
		oufi << "= ";
		PrintCString(total);

		oufi << endl;
		oufi << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	}
	infi.close();
	oufi.close();

	return 0;
}
//toolbox
void InitCString(int cString[]) {
	const int MAX = 36;
	for (int k = 0; k < MAX; k++) {
		cString[k] = 0;
	}
}
void LoadCString(int cString[]) {
	const int MAX = 36;
	char FILO[MAX]; //for loading in numbers
	char x;
	int count = 0;

	infi.get(x);
	while (x != '\n' && !infi.eof()) {
		FILO[count] = x;
		infi.get(x);
		count++;
	}

	//convert to right-justified
	for (int i = 0; i < count; i++) {
		cString[MAX - 1 - i] = (FILO[count - 1 - i] - '0'); //converts to int
	}
	return;
}

void AddCStrings(int a[], int b[], int total[]) {
	int MAX = 35;
	int num;
	//loop goes backwards!
	for (int i = MAX; i > 0; i--) {
		int num = a[i] + b[i] + total[i];
		total[i] = num % 10;
		if (num >= 10) {
			total[i - 1] = num / 10; //carry, avoids i = 0 with if
		}
	}
	return;
}

void PrintCString(int x[]) {
	int MAX = 36;
	int j = 0;
	while (x[j] == 0) {
		oufi << ' ';
		j++;
	}
	for (j; j < MAX; j++) {
		oufi << x[j];
	}
	oufi << endl;
	return;
}
// Codey Sivley for CS 318, Dr. Rimes
// 02/10/2020 Late Submission
// HomeworkWoolyCarSalesmen.cpp
// Problem: Wild and Wooly Car Salesmen 2D Arrays

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
int Read(float[][14]); //reads from .txt into array, returns number of entries
void FillResults(float[][14], float[][5], int); //processes data into results chart
void PrintResults(float[][5], int); //outputs data in a nice chart
void RaiseCheck(float[][5], int); //checks if that row deserves a raise, flags them
int FindWorst(float[][5], int); //finds the worst employee, returns row number
char Interperter(int val); // converts ints from raise/fire flags into chars for chart
void CalculateTotal(float[][14], float[], int); //fills monthly totals
void PrintTotal(float[]); // prints second table as requested
float Avg(float, int); //args: total, divisor
float Sum(float[][14], int, int, int); //args: array, length
int FindSmallest(float[][14], int); //args: array, length

int main() {

	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Wooly Wild Car Dealers 318\n";
	cout << "----------------\n";

	//file I/O setup
	infi.open("WildSalesman.dat");
	if (!infi) {
		cout << "Error reading file" << endl;
		return 0;
	}

	oufi.precision(2);
	oufi << fixed;
	oufi.open("Wooly2dArrayResult.txt");
	oufi << "Codey Sivley\n";
	oufi << "Wild Wooly Car Salesmen 318 Result\n02/10/2020\nLate Submission" << endl;
	oufi << "=======================================" << endl;

	//variable declarations
	float arr[15][14];
	int len = Read(arr);
	float results[15][5];
	float total[12];

	FillResults(arr, results, len);
	PrintResults(results, len);
	CalculateTotal(arr, total, len);
	PrintTotal(total);
	system("pause");
	infi.close();
	oufi.close();

	return 0;
}//end main

//toolbox

int Read(float arr[][14]) {
	//loads the file into the array, and returns the number of ints in the array

	int i = 0;
	float n;
	infi >> n;
	while (!infi.eof()) {
		for (int j = 0; j < 14; j++) {
			arr[i][j] = n;
			infi >> n;
		}
		i++;
	}
	return i;
}

void PrintChart(float arr[][14], int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 14; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

void FillResults(float arr[][14], float res[][5], int len) {
	//fills results array with adjusted values for ease of computation
	int smallest;
	for (int i = 0; i < len; i++) {
		res[i][0] = arr[i][0]; //ID number
		res[i][1] = arr[i][13]; //Last years avg
		res[i][2] = Avg(Sum(arr, i, 1, 13), (12)); //raw avg
		smallest = FindSmallest(arr, i);
		res[i][3] = Avg((Sum(arr, i, 1, 13) - arr[i][smallest]), (11)); //adjusted avg
		RaiseCheck(res, i);
	}
	int worst = FindWorst(res, len);
	res[worst][4] = -1;
	return;
}

void PrintResults(float res[][5], int len) {
	oufi << "Wild and Wooley Sales Report\nSalesmen with a \"!\" are eligible for a raise.\n";
	oufi << "Worst performing salesman marked with a \"?\"." << endl;
	oufi << "ID\t" << "Last Avg\t" << "Year Avg\t" << "Adj Avg\t" << "\tStatus" << endl;
	oufi << "================================================================" << endl;
	for (int i = 0; i < len; i++) {
		oufi << static_cast<int>(res[i][0]) << "\t";
		oufi << res[i][1] << "\t";
		oufi << res[i][2] << "\t";
		oufi << res[i][3] << "\t";
		oufi << Interperter(res[i][4]) << endl;
	}
	oufi << "================================================================" << endl;
	return;
}

void CalculateTotal(float arr[][14], float total[12], int len) {
	float currentTotal;
	for (int i = 1; i < 13; i++) {
		currentTotal = 0.0;
		for (int j = 0; j < len; j++) {
			currentTotal = currentTotal + arr[j][i]; //Positions reversed! To go through Columns
		}
		total[i-1] = currentTotal;
	}
	return;
}

void PrintTotal(float total[12]) {
	oufi << "Total Monthly Sales" << endl;
	oufi << "----------------------------------------------------------------" << endl;
	oufi << "Jan\t\tFeb\t\tMar\t\tApr\t\tMay\t\tJun\n";
	int i = 0;
	while (i < 6) {
		oufi << total[i] << "\t";
		i++;
	}
	oufi << "\nJul\t\tAug\t\tSep\t\tOct\t\tNov\t\tDec\n";
	while (i < 12) {
		oufi << total[i] << "\t";
		i++;
	}
	oufi << "\n----------------------------------------------------------------" << endl;
	return;
}
void RaiseCheck(float ray[][5], int row) {
	//checks to see if employees did 10% better
	if ((ray[row][1] * 1.1) <= (ray[row][2])) {
		ray[row][4] = 1;
	}
	else {
		ray[row][4] = 0;
	}
	return;
}

int FindWorst(float ray[][5], int len) {
	//let's find the dead weight

	int sma;
	int n = 1;
	sma = 0;

	while (n < len) {
		if (((ray[sma][1] + ray[sma][2]) / 2) > ((ray[n][1] + ray[n][2]) / 2)) {
			sma = n;
		}
		n++;
	}
	return sma;
}

char Interperter(int val) {
	//takes in an integer, returns a character
	char result;
	if (val > 0) {
		result = '!';
	}
	else if (val < 0) {
		result = '?';
	}
	else {
		result = ' ';
	}
	return result;
}


float Sum(float arr[][14], int row, int x, int y) {
	//sums a slice of an array row
	//x = start index, y = end index
	float s;
	int n = x;
	s = 0; //sum
	while (n < y) {
		s = s + arr[row][n];
		n++;
	}
	return s;
}

float Avg(float sum, int len) {
	//takes in length, returns average
	float avg;
	float div = len; //typecasting as a float for accuracy
	avg = (sum / div);

	return avg;
}

int FindSmallest(float arr[][14], int row) {
	//finds position of smallest element in array
	int sma;
	int n = 2;
	sma = 1;

	while (n < 14) { 
		//we don't have to omit the avg because it's impossible 
		//for the average number to be the smallest number
		if (arr[row][n] < arr[row][sma]) {
			sma = n; //note this saves position, not actual number value
		}
		n++;
	}
	return sma;
}


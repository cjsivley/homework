// Codey Sivley for CS 318, Dr. Rimes
// 01/13/2020
// Homework01-13.cpp
// Problem: Average w/ Sentinal Exercise

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//prototypes
int Read();
float Average(int);
int Sum(int);
float Average(int);
void Print(int);

//GLOBAL FILE ACCESS
//file in/out
ofstream oufi;

int ray[50];

int main() {
	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;
	
	int run;
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Sentinal Average Exercise\n";
	cout << "Please enter run number: ";
	cin >> run;
	cout << "----------------\n";

	oufi.precision(2);
	oufi << fixed;
	oufi.open("SentinalAverageExercise.txt");
	oufi << "Codey Sivley\n";
	oufi << "Sentinal Average Exercise\n01/13/2020\n";
	oufi << "Run Number " << run << endl;
	oufi << "=======================================\n";

	//table breakout
	const char tab = ' ';
	const int t1 = 10;

	//START// "Who dares, wins"-SAS
	int length, total;
	float avg;
	length = Read();
	total = Sum(length);
	avg = Average(length);

	//print format
	oufi << left << setw(t1) << setfill(tab) << "Numbers";
	oufi << right << setw(t1) << setfill(tab) << "Sum";
	oufi << right << setw(t1) << setfill(tab) << "Average" << endl;
	oufi << "---------------------------------------\n";

	//print results
	oufi << left << setw(t1) << setfill(tab) << length;
	oufi << right << setw(t1) << setfill(tab) << total;
	oufi << right << setw(t1) << setfill(tab) << avg << endl;
	oufi << "---------------------------------------\n";
	oufi << "Numbers entered: " << endl;
	Print(length);

	oufi.close();
	return 0;
}//main end

//Toolbox
int Read() {
	//reads user input into the array, and returns the number of ints in the array

	int count = 0;
	int n;
	//prompt
	cout << "Please enter digits, \"0\" to exit.\n>";
	cin >> n;
	while (!n == 0) {
		ray[count] = n;
		count++;
		cout << ">";
		cin >> n;
	}
	return count;
}//read end

int Sum(int len) {
	//takes in length, returns sum
	int sum = 0;
	int count = 0;
	while (count < len) {
		sum = sum + ray[count];
		count++;
	}
	return sum;
}//sum end

float Average(int len) {
	//takes in length, returns average
	float avg;
	float sum = 0.0;
	int count = 0;
	while (count < len) {
		sum = sum + ray[count];
		count++;
	}
	avg = (sum / count);

	return avg;
}//avg end

void Print(int len) {
	//simply prints out each entry in the array. Line break at position 8.
	//len is length of array
	int count = 0;
	int br = 8;
	while (count < len) {
		oufi << ray[count] << " ";
		count++;
		if (count % br == 0) {
			oufi << '\n';
		}
	}
	oufi << endl; //for cleanliness
}//print end
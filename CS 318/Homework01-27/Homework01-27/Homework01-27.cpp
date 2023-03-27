// Codey Sivley for CS 317, Dr. Rimes
// 01/27/2020
// Homework01-27.cpp
// Problem: Array Work-Out 1D Program

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

ifstream instruct;
ifstream param;

//prototypes
int Read(int[]); //reads from .txt into array, returns number of entries
int ReadParameters(int[]); //reads from .dat into new array, returns number of entries
void Print(int[], int); //args: array, length
float Avg(int, int); //args: total, divisor
int Sum(int[], int); //args: array, length
int LarThan(int[], int, float); //args: array, length, comparator
int SmaThan(int[], int, float); //args: array, length, comparator
void NegativeFix(int[], int); //args: array, length
void ZeroXs(int[], int, int); //args: array, length, mod divisor
void Instruct(); //prints line of instructions
int FindLargest(int[], int); //args: array, length
int FindSmallest(int[], int); //args: array, length
int Multiples(int[], int, int); //args: array, length, mod divisor
void CopyArray(int[], int[], int); //args, array1, array2, length
void ReverseArray(int[], int[], int); //args, array1, array2, length

int main() {

	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Array Workout 1D 318\n";
	cout << "----------------\n";

	//file I/O setup
	infi.open("array.txt");
	if (!infi) {
		cout << "Error reading file" << endl;
		return 0;
	}
	instruct.open("instructions.txt");
	if (!instruct) {
		cout << "Error reading instruction file" << endl;
		return 0;
	}
	param.open("AryParams.dat");
	if (!param) {
		cout << "Error reading parameter file" << endl;
		return 0;
	}

	oufi.precision(2);
	oufi << fixed;
	oufi.open("Array1D318Result.txt");
	oufi << "Codey Sivley\n";
	oufi << "Array Workout 1D 318 Result\n01/27/2020\n" << endl;
	oufi << "=======================================" << endl;

	//Artists who seek perfection in everything are those who cannot attain it in anything. -Gustave Flaubert
	///////////////////////////BEGIN//////////////////////////////

	int ray[100];
	Instruct();
	Instruct();
	int len = Read(ray);
	Print(ray, len);

	Instruct();
	oufi << "Average: " << Avg(Sum(ray, len), len) << endl;

	Instruct();
	oufi << "Larger: " << LarThan(ray, len, Avg(Sum(ray, len), len)) << endl;
	oufi << "Smaller: " << SmaThan(ray, len, Avg(Sum(ray, len), len)) << endl;

	Instruct();
	NegativeFix(ray, len);
	Print(ray, len);

	Instruct();
	oufi << "Average: " << Avg(Sum(ray, len), len) << endl;

	Instruct();
	int larPos = FindLargest(ray, len);
	oufi << "The largest number is " << ray[larPos] << " at position " << larPos << ".\n";
	
	Instruct();
	int smaPos = FindSmallest(ray, len);
	oufi << "The smallest number is " << ray[smaPos] << " at position " << smaPos << "." << endl;

	Instruct();
	ZeroXs(ray, len, 2);
	Print(ray, len);

	Instruct();
	oufi << "Average: " << Avg(Sum(ray, len), len) << endl;

	Instruct();
	int parameters[100];
	int NumOfParams = ReadParameters(parameters);
	oufi << "There are " << SmaThan(ray, len, parameters[0]) << " items less than " << parameters[0] << ".\n";

	Instruct();
	oufi << "There are " << LarThan(ray, len, parameters[1]) << " items larger than " << parameters[1] << ".\n";

	Instruct();
	oufi << "There are " << LarThan(ray, len, ray[parameters[2]-1]) << " items larger than " << ray[parameters[2]-1] << ".\n";

	Instruct();
	oufi << "There are " << Multiples(ray, len, (parameters[3])) << " items that are multiples of " << parameters[3] << ".\n";
	oufi << "There are " << Multiples(ray, len, (parameters[4])) << " items that are multiples of " << parameters[4] << ".\n";

	Instruct();
	int ray2[100];
	CopyArray(ray, ray2, len);
	Print(ray2, len);

	Instruct();
	ReverseArray(ray, ray2, len);
	Print(ray2, len);

	return 0;

}///////////////////////////// end main ///////////////////////////////

//toolbox
int Read(int arr[]) {
	//loads the file into the array, and returns the number of ints in the array

	int count = 0;
	int n;
	while (infi >> n) {
		arr[count] = n;
		count++;
	}
	return count;
}

int ReadParameters(int parameters[]) {
	//loads the parameters into the array, and returns the number of ints in the array

	int count = 0;
	int n;
	while (param >> n) {
		parameters[count] = n;
		count++;
	}
	return count;
}

void Print(int arr[], int len) {
	//simply prints out each entry in the array. Line break at position 10.
	//len is length of array
	int count = 0;
	int br = 10;
	while (count < len) {
		oufi << arr[count] << " ";
		count++;
		if (count % br == 0 && count != 0) {
			oufi << '\n';
		}
	}
	return;
}

float Avg(int sum, int len) {
	//takes in length, returns average
	float avg;
	float div = len; //typecasting as a float for accuracy
	avg = (sum / div);

	return avg;
}

int Sum(int arr[], int len) { 
	//sums an array
	int s, n;
	s = 0;
	n = 0;
	while (n < len) {
		s = s + arr[n];
		n++;
	}
	return s;
}

int LarThan(int arr[], int len, float y) {
	//takes in array, length of array, and y
	//returns number of tiems larger than the y

	int n = 0;
	int lar = 0;
	while (n < len) {
		if (arr[n] > y) {
			lar++;
		}
		n++;
	}
	return lar;
}

int SmaThan(int arr[], int len, float y) {
	//takes in array, length of array, y
	//returns number of items smaller than y

	int n = 0;
	int sma = 0;
	while (n < len) {
		if (arr[n] < y) {
			sma++;
		}
		n++;
	}
	return sma;
}

void Instruct() {
	//prints a line from the instruction sheet
	string x;
	getline(instruct, x);
	oufi << "\n" << x << endl;
	return;
}

void NegativeFix(int arr[], int len) {
	//takes in length of array
	//simply converts all negatives to positives
	//like Biggie Smalls in Juicy

	int n = 0;
	while (n < len) {
		if (arr[n] < 0) {
			arr[n] = arr[n] * -1;
		}
		n++;
	}
	return;
}

int FindLargest(int arr[], int len) {
	//finds position of largest element in array
	int lar;
	int n = 1;
	lar = 0;

	while (n < len) {
		if (arr[n] > arr[lar]) {
			lar = n; //note this saves position, not actual number value
		}
		n++;
	}
	return lar;
}

int FindSmallest(int arr[], int len) {
	//finds position of smallest element in array
	int sma;
	int n = 1;
	sma = 0;

	while (n < len) {
		if (arr[n] < arr[sma]) {
			sma = n; //note this saves position, not actual number value
		}
		n++;
	}
	return sma;
}

void ZeroXs(int arr[], int len, int x) {
	//zeros all arrays divisible by x
	int n = 0;
	while (n < len) {
		if (arr[n] % x == 0) {
			arr[n] = 0;
		}
		n++;
	}
	return;
}

int Multiples(int arr[], int len, int x) {
	//returns number of elements divisible by x
	int n = 0;
	int count = 0;
	while (n < len) {
		if (arr[n] % x == 0 && arr[n] != 0) {
			count++;
		}
		n++;
	}
	return count;
}

void CopyArray(int arr1[], int arr2[], int len) {
	//copies one array to another
	int n = 0;
	while (n < len) {
		arr2[n] = arr1[n];
		n++;
	}
	return;
}

void ReverseArray(int arr1[], int arr2[], int len) {
	//reverses order of array elements
	int n = 0;
	while (n < len) {
		arr2[n] = arr1[len - n - 1];
		n++;
	}
	return;
}
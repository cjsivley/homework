// Codey Sivley for CS 318, Dr. Rimes
// 03/02/2020
// LinkListWorkout.cpp
// Problem: Link List Program

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

//global structure
struct NODE {
	int val; //value
	int n; //counter
	int* linky; //pointer to next value in the link list
};

//prototypes
void insert(NODE*, NODE*, int); //requires head pointer, and target
NODE NewNode();

int main() {

	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "Link Lists 318\n";
	cout << "----------------\n";

	//file I/O setup
	infi.open("LinkNbrs.dat");
	if (!infi) {
		cout << "Error reading file" << endl;
		return 0;
	}

	oufi.precision(2);
	oufi << fixed;
	oufi.open("LinkListResult.txt");
	oufi << "Codey Sivley\n";
	oufi << "Link List 318 Result\n03/02/2020" << endl;
	oufi << "=======================================" << endl;

	//variable declarations

	//sketchpad

	




	//cleanup
	
	infi.close();
	oufi.close();

	return 0;
}//end main

void insertSketch(NODE* cp, int targ) {
	//inserts a node at it's sorted position
	NODE* t; //target pointer
	NODE* p; //previous position pointer

	while ((*cp).val < targ) {
		p = cp;
		cp = (*cp).linky; //bumps to next node
	}

	t = &NewNode();
	return;
}

void insertSketch() {
	
}

NODE NewNode() {
	NODE x;
	x.val = 0;
	x.n = 0;
	x.linky = NULL;
	return x;
}

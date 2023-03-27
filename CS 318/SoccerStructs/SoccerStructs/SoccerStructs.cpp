// Codey Sivley for CS 318, Dr. Rimes
// 02/17/2020
// SoccerStructs.cpp
// Problem: Soccer Statistics 318

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

struct PLAYER
{
	string name;
	int id;
	int goals[10] = { 0 };
	int total;
};
//prototypes
void RosterPrint(PLAYER);
int Sum(int[], int);
void Load(PLAYER[]);
void RosterSort(PLAYER[]);
void br(); //linebreak
int TotalGoals(PLAYER[]);
PLAYER HighScore(PLAYER[]);

int main() {
	//console formatting
	oufi.precision(2);
	oufi << fixed;
	oufi << showpoint;

	//file I/O setup
	infi.open("Soccer.txt");
	if (!infi) {
		oufi << "Error reading file" << endl;
		return 0;
	}

	oufi.precision(2);
	oufi << fixed;
	oufi.open("SoccerStatResults.txt");
	oufi << "Codey Sivley\n";
	oufi << "Soccer Statistics 318 Result\n02/17/2020" << endl;
	oufi << "========================================" << endl;

	//variable declaration
	PLAYER roster[12];
	PLAYER* rosterStart; //start position
	PLAYER* rosterPos; //position tracker
	PLAYER hi; //reserved for highest scorer
	rosterStart = roster;
	rosterPos = rosterStart;

	//start it up

	Load(roster);
	RosterSort(roster);

	oufi << "Name\t\tID\tTotal Goals" << endl;
	br();

	for (int l = 0; l < 12; l++) {
		RosterPrint(*rosterPos);
		rosterPos++;
	}
	rosterPos = rosterStart;

	br();

	oufi << "Team Total Goals: " << TotalGoals(rosterStart) << " goals." << endl;
	hi = HighScore(roster);
	oufi << "Highest Scorer: " << hi.name << ", " << hi.total << " goals." << endl;

	//main end, cleanup
	infi.close();
	oufi.close();
	return 0;
}

//toolbox
void RosterPrint(PLAYER dude) {
	//prints it out boi
	oufi << dude.name << "\t";
	oufi << dude.id << "\t";
	oufi << dude.total << "\t";
	oufi << endl;
}

int Sum(int* arr, int len) {
	//sums an array
	int s = 0;
	for (int i = 0; i < 10; i++) {
		s = s + *arr;
		arr++;
	}
	return s;
}

int TotalGoals(PLAYER* roster) {
	//totals all goals from all players
	int s = 0;
	for (int i = 0; i < 12; i++) {
		s = s + (*roster).total;
		roster++;
	}
	return s;
}

PLAYER HighScore(PLAYER roster[]) {
	//returns index of highest scoring player
	PLAYER* ros;
	PLAYER High;
	ros = roster;
	High = *ros;
	for (int i = 0; i < 12; i++) {
		if ((*ros).total > High.total) {
			High = *ros;
		}
		ros++;
	}
	return High;
}

void Load(PLAYER* ros) {
	//loads info from file into array of structs
	for (int i = 0; i < 12; i++) {
		char x;
		int n = 0;
		int* goalptr;
		goalptr = (*ros).goals;
		getline(infi, (*ros).name); //name
		infi >> (*ros).id; //id
		//score read (it's gonna be messy)
		infi.get(x); //first char is a \n leftover from infi/cin
		infi.get(x);
		while (x != '\n' && !infi.eof()) { //until we hit newline
			if (isdigit(x)) { //if x is a digit
				*goalptr = (x - '0'); //add to goals as int
				goalptr++;
			}
			infi.get(x); //next char
		}
		(*ros).total = Sum((*ros).goals, 10); //total goals
		ros++;
	}
	return;
}

void RosterSort(PLAYER* ros) {
	//bubble sorts roster
	
	PLAYER temp;
	PLAYER* ptr1 = ros;
	PLAYER* ptr2 = ros + 1;
	for (int i = 0; i < 12; i++) {

		ptr1 = ros;
		ptr2 = ros + 1;
		int y = 1;
		for (int j = 0; j < 11; j++) {
			if ((*ptr1).name > (*ptr2).name) {
				temp = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = temp;
			}
			ptr1++;
			ptr2++;
		}
	}
	return;
}

void br() {
	//prints a line break
	oufi << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	return;
}
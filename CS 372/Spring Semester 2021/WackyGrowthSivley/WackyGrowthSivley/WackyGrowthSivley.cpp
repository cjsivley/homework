// WackyGrowthSivley.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h> //random number seed

using namespace std;

#define AGE 50 //length of array for simulation
//15 starter weeks + 15 reps(-1 week minimum die off + 4 weeks stable) = 50 weeks max

//global file access
ofstream oufi;

//prototypes
int d4(); //returns random number ranged (1 - 4)
void zeroArr(int*); //initializes array with zeroes
void printArr(int*); //prints array, sentinal value of zero

int main()
{
    oufi.open("WackyGrowthSivleyResults.txt");
    oufi << "Bacterial Fibonacci Simulation\nCodey Sivley 2/23/2021\nCS372 Spring 2021\n";
    srand(time(NULL)); //random number seed
    int* head; //start of array
    int* c; //current position
    head = new int[AGE];
    c = head;
    int r; //random number
    int* NewEnd;
    zeroArr(head);
    printArr(head);

    //STEP 1: 15 weeks uninterrupted growth (first two weeks defined)
    oufi << "Initial Weeks" << endl;
    *c = 2;
    c++;
    *c = 2;
    for (int i = 0; i < 13; i++) {
        c++; //iterate first, so c is always on an occupied spot.
        *c = (*(c - 1) + *(c - 2)); //current node = previous two nodes added
    }
    printArr(head);
    oufi << "=====================" << endl; //line break for readability

    //STEP 2: 15 cycles of die off
    for (int j = 0; j < 15; j++) {
        oufi << "Simulation #" << j + 1 << endl;
        r = d4();
        NewEnd = c - r;//select NewEnd position
        printArr(head);
        oufi << "random: " << r << ", NewEnd value: " << *NewEnd;
        if (NewEnd - head < 3) { //if -3 would underflow
            /*interesting pointer rules regarding operators in arrays. See: 
            https://stackoverflow.com/questions/3599645/pointer-addition-vs-subtraction
            https://stackoverflow.com/questions/44397784/is-operator-less-than-on-pointers-consistent
            */
            *NewEnd = *(head);
        }
        else {
            *NewEnd = *(NewEnd - 3); //NewEnd is equal to three weeks prior
        }
        oufi << ", Replace with " << *NewEnd << endl;

        //STEP 3: Delete past NewEnd
        for (int i = 1; i < r + 1; i++) { //c is the last position filled.
            *(NewEnd + i) = 0; //delete by filling with zero
        }

        //STEP 4: New growth, 4 weeks.
        for (int i = 0; i < 4; i++) {
            NewEnd++;
            *NewEnd = (*(NewEnd - 1) + *(NewEnd - 2));
        }
        c = NewEnd; //set up for next loop
        oufi << "=====================" << endl; //line break for readability
    } // end 15 die offs
} //end main

//Toolbox
int d4() {
    return rand() % 4 + 1;
}

void zeroArr(int* pos) {
    for (int i = 0; i < AGE; i++) {
        *pos = 0;
        pos++;
    }
}

void printArr(int* pos) {
    int line = 9;
    int n = 0;
    while (*pos != 0) {
        oufi << *pos << "\t";
        pos++;
        n++;
        //formatting
        if (n == line) {
            oufi << endl;
            n = 0;
        }
    }
    oufi << endl;
}
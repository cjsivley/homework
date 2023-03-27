//Codey Sivley
//CS 372 Spring 2021, Dr Rimes
//Stack Program


#include <iostream>
#include <iomanip>
#include <fstream>
#include "SivList.h"
#include "Stack.h"

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

int main()
{

    //file setup
    infi.open("StackMaxNbrsV2.txt");
    if (!infi) {
        cout << "Error opening file." << endl;
        return 0;
    }

    oufi.open("SivleyStackResults.txt");

    //output header
    oufi << "Codey Sivley\nFor Dr. Rimes CS 372\n02/06/2021";
    oufi << "\n";
    oufi << "------------------------------------------------\n";
    oufi << "Stack Program Result\n";
    oufi << "------------------------------------------------\n";

    /*
    Method:
    Push
    1: read in new number, push to stack1
    2: if larger than or equal to top of stack2, push to stack2
    Pop
    1: if the pop from stack1 < stack2 top, do nothing
    2: else, pop stack2 top
    3: Print stack2 top to report current largest
    */

    //variable declarations
    string cmd;
    int val;
    int popReturn;

    Stack stack1; //holds all numbers
    Stack stack2; //holds current largest
    do {
        infi >> cmd;
        if (cmd == "Push") {
            infi >> val;
            oufi << "Push " << val << endl;
            stack1.push(val);
            if (val >= stack2.peek()) {
                stack2.push(val);
            }
        }
        else if (cmd == "Pop") {
            popReturn = stack1.pop();
            oufi << "Pop off " << popReturn << ", ";
            if (popReturn == stack2.peek()) {
                stack2.pop();
            }
            oufi << "Max value: " << stack2.peek() << endl;
        }
        val = infi.peek(); //look for EOF
    } while (val != EOF);

    return 0;
} //end main

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

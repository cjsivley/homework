// Codey Sivley
// CS372, Dr Rimes
// 11/15/2020

// StackAndQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Stack.h"
#include "Queue.h"

using namespace std;

//global files
ofstream oufi;

//prototypes
void stackTester(string); //checks bracket matching with a stack
void qTester(string); //compares the pushes and pops for a string and queue to see if they're identical

int main()
{
    //file I/O setup
    oufi.open("StackAndQueue-CS372-Sivley.txt");

    //output header
    oufi << "Codey Sivley\nFor Dr. Rimes CS 372\n11/10/2020";
    oufi << "\n";
    oufi << "--------------------\n";
    oufi << "Stack And Queue\n";
    oufi << "--------------------\n";

    stackTester("()");
    stackTester("[]()[]");
    stackTester("[{()}]");
    stackTester("[[))");
    stackTester("[()]][");
    stackTester("((()))[()()]");
    stackTester("{()[()]}");

    qTester("ABCDEDCBA");
    qTester("NOTAPALINDROME");
    qTester("ISAPALINILAPASI");
    qTester("2A3MEAS");
    qTester("ATOYOTA");
    qTester("(({}[][]{}((");
    qTester("Tattarrattat");
    qTester("racecar");


}
//toolbox
void stackTester(string sample) {
    Stack cs; //char stack
    char input;
    char output;
    int i = 0;
    oufi << "Checking " << sample << endl;
    input = sample[i];
    while (input) {
        if (input == '(' || input == '[' || input == '{') {
            cs.push(input);
        }
        else {
            output = cs.pop();
            switch (output) {
            case '(':
                if (input == ')') {
                    oufi << output << ", " << input << " @ index " << i << ". Match." << endl;
                    
                }
                else {
                    oufi << output << ", " << input << " @ index " << i << ". ";
                    oufi << "Mismatch.";
                    oufi << endl;
                }
                break;
            case '{':
                if (input == '}') {
                    oufi << output << ", " << input << " @ index " << i << ". Match." << endl;
                }
                else {
                    oufi << output << ", " << input << " @ index " << i << ". ";
                    oufi << "Mismatch.";
                    oufi << endl;
                }
                break;
            case '[':
                if (input == ']') {
                    oufi << output << ", " << input << " @ index " << i << ". Match." << endl;
                }
                else {
                    oufi << output << ", " << input << " @ index " << i << ". ";
                    oufi << "Mismatch.";
                    oufi << endl;
                }
                break;
            } //end switch
        } //end close bracket check
        input = sample[++i];
    } //end while loop
    oufi << "-----------------------" << endl;
}//end stackTester()

void qTester(string sample) {
    Stack fw;
    Queue bw; //forward and backward
    char x;
    char y;
    int i = 0;

    oufi << "Is " << sample << " a palindrome?" << endl;
    char input = sample[i];
    //load up the lists
    while (input) {
        fw.push(input);
        bw.push(input);
        input = sample[++i];
    }
    fw.printStk();
    bw.printQ();
    while (fw.size() > 0) {
        x = fw.pop();
        y = bw.pop();
        oufi << x << " , " << y << ": ";
        if (x == y) {
            oufi << "Match.";
        }
        else {
            oufi << "Mismatch.";
        }
        oufi << endl;
    }
    oufi << "-----------------------" << endl;
}



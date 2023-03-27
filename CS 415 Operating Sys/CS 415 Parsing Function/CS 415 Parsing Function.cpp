// CS 415 Parsing Function.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Codey Sivley Spring 2022
// Assignment 1: Basic Parsing Function

#include <iostream>
#include <string.h>
#include <cstring>
#include <sstream>

using namespace std;

//prototypes
char** parseCommandLine(string aCommandLine); //recieves a string as an argument, returns a pointer

int main()
{
    cout << "Hello World!\n";
    string commandLine = "hello darkness my old friend";
    char** listy = parseCommandLine(commandLine);
    cout << "hello again" << endl;
}

char** parseCommandLine(string aCommandLine) {
    char* arrayOfTokens[100]; //how to dynamically allocate? Count whitespaces?
    const char delim[2] = " "; //basic whitespace delimiter
    //using method from c_str page
    //convert string to cstring
    char* cstrCmd = new char[aCommandLine.length() + 1];
    strcpy(cstrCmd, aCommandLine.c_str());

    // cstrCmd now is a cstr of command line argument

    //break cstring into array of cstrings
    char* token = strtok(cstrCmd, delim);
    int pos = 0;
    while (token != 0)
    {
        arrayOfTokens[pos] = token;
        ++pos;
        token = strtok(NULL, delim); //why search for token in null string? Confused.
    }

    return arrayOfTokens; //not sure why I'm allowed to return
}

// References:
// https://www.cplusplus.com/reference/string/string/c_str/
// https://www.tutorialspoint.com/c_standard_library/c_function_strtok.htm
// https://www.geeksforgeeks.org/strtok-strtok_r-functions-c-examples/


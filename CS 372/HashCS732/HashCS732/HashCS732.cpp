// HashCS732.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <math.h>
#include "entry.h"

using namespace std;

#define LIM 79

//global file access
ifstream infi;
ofstream oufi;


//prototypes
int genHash(string, int); //generates a hash based on the string and limit int
void printTable(entry* []); //prints table for display
void printKey(entry*); //recursive, prints all items that that key
int search(string, entry* []); //searches for results in hash table, returns probes.
void report(entry*); //prints entry

int main()
{
    //initialize static member collisions
    entry::collisions = 0;

    //Open files
    infi.open("HashNamesAndNumbers.txt");
    if (!infi) {
        oufi << "Error in file open.";
        return 0;
    }
    oufi.open("HashResultsSivley.txt");

    //header
    oufi << "Codey Sivley\n";
    oufi << "Hash Table CS372 Result\n11/01/2020" << endl;
    oufi << "========================================" << endl;

    //variables
    string currentLine;
    string fullName;
    string phoneNumber;


    //debug tools
    int ticker = 0;
    entry* testTable[LIM]; //array of pointers to entries
    for (int i = 0; i < LIM; i++) { //initialize array to NULLs
        testTable[i] = NULL;
    }
    int testHashKey;
    entry* current;
    int collisions = 0;

    //load into table
    while (!infi.eof()) {//for each line in the file
        entry* temp = new entry;
        testHashKey = 0;
        fullName = "";
        ticker++;
        infi >> fullName; //first name
        infi >> currentLine; //middle or last name

        while (isalpha(currentLine[0])) { //capture full name
            fullName = fullName + " " + currentLine;
            infi >> currentLine;
        }
        temp->setName(fullName);
        temp->setPhone(currentLine);
        phoneNumber = currentLine;
        testHashKey = genHash(fullName, LIM);
        temp->setIndex(testHashKey);

        //insert into list
        if (testTable[testHashKey] == NULL) { //first in the key position
            testTable[testHashKey] = temp;
        }
        else { //collisions
            current = testTable[testHashKey];
            while (current->getNext()) {
                entry::collisions++;
                current = current->getNext();
            }
            current->setNext(temp);
        }

    }
    oufi << "Ticker: " << ticker << endl;
    oufi << "Collisions: " << entry::collisions << endl;

    //efficiency check
    float waste = 0.0;
    oufi << "Wasted Space: ";
    for (int i = 0; i < LIM; i++) {
        if (!testTable[i]) {
            waste++;
        }
    }
    oufi << waste << endl;
    oufi << 1 - waste/LIM << "% full" << endl;

    //print table
    oufi << "--- Display Table ---" << endl;
    printTable(testTable);
    oufi << "--- End Display ---" << endl;
    //search test
    oufi << "--- Search Test ---" << endl;
    oufi << "Search for 'Antoney Wenner':\n" << endl;
    search("Antoney Wenner", testTable);

    oufi << "Search for 'R Wee Phinish':\n" << endl;
    search("R Wee Phinish", testTable);

    oufi << "Search for 'I'm Not Here':\n" << endl;
    search("I'm Not Here", testTable);

    //cleanup
    infi.close();
    oufi.close();
}

//toolbox
int genHash(string key, int limit) {
    unsigned int hk = 0; //hashed key
    int keySize;
    int hashToken = 7917; // 1000th prime

    //hash algorithm
    keySize = key.length();
    for (int i = 0; i < keySize; i++) { //for each char
        hk = hk + ((key[i] - 0) * i); //sum of each char * its place in string
        if ((key[i] - 0) == 32) { //if blankspace, cube
            hk = pow(hk, 3);
        }
    }
    hk = hk % limit; //mod to get index
   
    return hk;
}

void printTable(entry* table[]) {
    for (int i = 0; i < LIM; i++) {
        if (table[i] == NULL) {
            oufi << i << ": Empty. \n" << endl;
        }
        else {
            printKey(table[i]);
            oufi << endl;
        }
    }
}

void printKey(entry* pos) {
    if (pos == NULL) {
        return;
    }
    report(pos);
    pos = pos->getNext();
    printKey(pos);
}

void tableInsert(entry* position, int index) {

}

int search(string input, entry* table[]) {
    int key = genHash(input, LIM);
    int probes = 1;
    entry* pos = table[key];
    if (pos) {
        while (pos->getNext()) {
            if (pos->getName() == input) { 
                report(pos);
                oufi << "Probes: " << probes << endl;
                return probes;
            }
            pos = pos->getNext();
            probes++;
        }
    }

    oufi << "No match found for " << input << "." << endl;
    oufi << "Key: " << key << ", Probes: " << probes << endl;
    return probes;
}

void report(entry* pos){ //outputs to cout, moved outside class due to fstream errors
    oufi << "Index: " << pos->getIndex();
    oufi << " || Name: " << pos->getName();
    oufi << " || Phone: " << pos->getPhone() << endl;
}
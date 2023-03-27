// Codey Sivley
// CS372, Dr Rimes
// 11/10/2020

//SortSamplerCS372.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

#define LEN 16

using namespace std;

//prototypes
void setup(int*); //resets array to inital values
void display(int*, int); //displays array at each step.
void swap(int*, int*); //swaps two ints
//sort prototype functions
void bubble(int*, int);
void selection(int*, int);
void insertion(int*, int);
void shell(int*, int);
void quick(int*, int);
void heap(int*, int);

//global file access
ofstream oufi;

int main()
{
    //file I/O setup
    oufi.open("SortSampler-CS372-Sivley.txt");

    //output header
    oufi << "Codey Sivley\nFor Dr. Rimes CS 372\n11/10/2020";
    oufi << "\n";
    oufi << "------------------------------------------------\n";
    oufi << "Sort Algorithm Sampler\n";
    oufi << "------------------------------------------------\n";

    int arr[16];
    setup(arr);

    oufi << "Working Array:\n";
    display(arr, LEN);
    oufi << endl;

    oufi << "Bubble Sort:" << endl;
    bubble(arr, LEN);
    setup(arr); //reset array

    oufi << "Selection Sort:" << endl;
    selection(arr, LEN);
    setup(arr); //reset array

    oufi << "Insertion Sort:" << endl;
    insertion(arr, LEN);
    setup(arr); //reset array

    oufi << "Shell Sort:" << endl;
    shell(arr, LEN);

}

//toolbox
void shell(int* array, int len) {
    int pass = 0;
    oufi << "Start: \t\t";
    display(array, len);
    oufi << endl;

    for (int k = 5; k > 0; k = k - 2) { //shell size 5, 3, 1
        for (int i = k; i < len; i++) { //for each element in each sub-array
            for (int j = i - k; j >= 0; j = j - k) {
                if (array[j + k] < array[j]) { //compare with corresponding element of next sub-array
                    swap(&array[j + k], &array[j]);
                }
            }
            oufi << "K=" << k << ", pass " << ++pass << ": \t";
            display(array, len);
            oufi << endl;
        }
    }
}
void insertion(int* array, int len) {
    int count = 0;
    int cur;
    oufi << "Start: \t\t";
    display(array, len);
    oufi << endl;
    for (int i = 1; i < len; i++) { //note we start on the second index
        int j = i - 1;
        cur = array[i];
        //make space for current value
        //move everything bigger than i one space over
        while (array[j] > cur && j >= 0) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = cur; //insert current into spot after the next smallest
        oufi << "Pass " << i << ": \t";
        display(array, len);
        oufi << endl;
    }
}
void selection(int* array, int len) {
    int count = 0;
    int min;
    oufi << "Start: \t\t";
    display(array, len);
    oufi << endl;
    for (int i = 0; i < len-1; i++) {
        //each pass (n-1), find smallest element
        min = i;
        for (int j = i + 1; j < len; j++) {
            if (array[j] < array[min]) { min = j; }; //note smallest element position
        }
        //swap the smallest element found with the next available space
        swap(&array[i], &array[min]);
        oufi << "Pass " << i+1 << ": \t";
        display(array, len);
        oufi << endl;
    }
}
void bubble(int* array, int len) {
    int count = 0;
    oufi << "Start: \t\t";
    display(array, len);
    oufi << endl;
    for (int i = 0; i < len - 1; i++) { //n-1 passes
        //if each element is larger than the next, swap them
        for (int j = 0; j < len - i - 1; j++) { 
            if (array[j] > array[j + 1]) { swap(&array[j], &array[j + 1]); } //pass by reference because arrays
        }
        oufi << "Pass " << i+1 << ": \t";
        display(array, len);
        oufi << endl;
    }
}
void display(int* array, int len) {
    oufi << "{";
    for (int i = 0; i < len; i++) {
        oufi << *array;
        array++;
        if (i < len - 1) {
            oufi << ",";
        }
    }
    oufi << "}";
}
void swap(int* x, int* y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void setup(int* array) {

    int starter[16] = { 12,8,4,13,7,9,17,15,2,11,5,14,6,1,3,7 };
    for (int i = 0; i < 16; i++) {
        array[i] = starter[i];
    }
}


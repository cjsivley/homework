#pragma once

#include <iostream>
#include "codex.h"

using namespace std;

//Adjustables
const unsigned int CAP = 20;
typedef int ET;

class List
{
	/*invariants:
	*Data is left justified.
	*Keep track of position with pos, and length with mySize.
	*pos is always between 0 and mySize -1
	*/
private:
	ET myAry[CAP];
	int mySize;
	int pos;
public:
	//constructors
	List(); //default constructor
	List(const List& l);
	//Assignment operator
	void operator = (List l);

	//getters
	ET getElement() const;

	int size() const;

	int getPos() const;

	ET getAt(int x) const;

	bool empty() const;
	//setters
	void setPos(int);
	void setSize(int);
	void setAt(int, ET);

	//utility

	void first();

	void last();

	void prev();

	void next();

	void insertBefore(ET x);

	void insertAfter(ET x);

	void replace(ET x);

	void erase();

	void clear();

	void reverse();

	void swap(List x);

	void swapAt(int, int);

	void shiftR(int);

	void shiftL(int);

};


//external operator overloads
bool operator == (List a, List b);

bool operator != (List a, List b);

List operator + (List a, List b);

//friends
ostream& operator << (ostream& outs, List x);
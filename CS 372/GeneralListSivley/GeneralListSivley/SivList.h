#pragma once

#include <iostream>

using namespace std;

//Adjustables
const unsigned int CAP = 20;
//typedef int ET;
template <typename ET>
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

	//internal operator overloads
	List operator += (List a);

	// Assignment = operator near top

};


//external operator overloads
template <typename ET>
bool operator == (List<ET> a, List<ET> b);
template <typename ET>
bool operator != (List<ET> a, List<ET> b);
template <typename ET>
List<ET> operator + (List<ET> a, List<ET> b);

//friends
template <typename ET>
ostream& operator << (ostream& outs, List<ET> x);

#include "SivListImplementation.h" //implementation of template
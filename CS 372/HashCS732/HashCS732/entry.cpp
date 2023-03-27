#include "entry.h"
#include <iostream>
#include <fstream>

using namespace std;

entry::entry()
{
	name = "";
	phone = "";
	index = 0;
	nextNode = NULL;
}

void entry::setName(string x)
{
	name = x;
}

void entry::setPhone(string x)
{
	phone = x;
}

void entry::setIndex(int x)
{
	index = x;
}

void entry::setNext(entry* x)
{
	nextNode = x;
}

string entry::getName()
{
	return string(name);
}

string entry::getPhone()
{
	return string(phone);
}

entry* entry::getNext()
{
	return nextNode;
}

int entry::getIndex()
{
	return index;
}

void entry::consoleDisplay()
{
	cout << "Index: " << index;
	cout << " || Name: " << name;
	cout << " || Phone: " << phone << endl;
	
}

int entry::collisions;


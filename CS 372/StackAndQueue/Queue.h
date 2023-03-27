#pragma once
#include "SivList.h"
class Queue :
	public List
{
private:
	List q;
	int mySize;

public:
	void printQ();

	void push(ET);

	ET pop();
};


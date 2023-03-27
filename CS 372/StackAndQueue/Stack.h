#pragma once
#include "SivList.h"
class Stack :
	public List
{
private:
	List stk;
	int mySize;
	
public:
	void printStk();

	void push(ET);

	ET pop();

	int size();
};


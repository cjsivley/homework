#pragma once
#include <iostream>
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

	int size() const;

	ET peek() const;

};

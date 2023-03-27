#include "Stack.h"

void Stack::printStk() {
	cout << stk << endl;
}

void Stack::push(ET x) {
	stk.first();
	stk.insertBefore(x);
}

ET Stack::pop() {
	ET result;
	result = stk.getAt(0);
	stk.shiftL(0);
	return result;
}

int Stack::size() const
{
	return stk.size();
}

ET Stack::peek() const
{
	if (stk.size() == 0) {
		return 0;
	}
	else return stk.getAt(0);
}
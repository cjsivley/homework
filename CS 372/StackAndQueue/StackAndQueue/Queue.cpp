#include "Queue.h"

void Queue::printQ()
{
	cout << q << endl;
}

void Queue::push(ET x)
{
	q.last();
	q.insertAfter(x);
}

ET Queue::pop()
{
	ET result;
	result = q.getAt(0);
	q.shiftL(0);
	return result;
}

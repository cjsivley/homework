#include "SivList.h"
#include "codex.h"

//constructors
List::List() { //default
	mySize = 0;
	pos = 0;
	//myAry;
	//fill(myAry, myAry + CAP, NULL);
}
List::List(const List& l) { // copy constructor
	for (int i = 0; i < l.size(); i++)
		myAry[i] = l.getAt(i);
	mySize = l.size();
	pos = l.getPos();
}
//Assignment operator
void List::operator = (List l) {
	for (int i = 0; i < l.size(); i++)
		myAry[i] = l.getAt(i);
	mySize = l.size();
	pos = l.getPos();
}

//getters
ET List::getElement() const {
	return myAry[pos];
}

int List::size() const {
	return mySize;
}

int List::getPos() const {
	return pos;
}

ET List::getAt(int x) const {
	return myAry[x];
}

bool List::empty() const {
	if (mySize == 0)
		return true;
	else
		return false;
}

//setters
void List::setPos(int x) {
	//sets current position
	if (x < 0) {
		errPrint("setPos() Boundary condition, cannot set pos less than 0.\n");
		return;
	}
	if (x >= mySize) {
		errPrint("setPos() Invariant condition, cannot set pos >= mySize.\n");
		return;
	}
	pos = x;
	return;
}
void List::setSize(int x) {
	//manually sets size, used in operator overloads
	mySize = x;
	return;
}
void List::setAt(int position, ET value) {
	//manually sets element, used in operator overloads
	myAry[position] = value;
	return;
}

//utility

void List::first() {
	//sets current position to beginning of list
	pos = 0;
	return;
}

void List::last() {
	//sets current position to last occupied place in list
	if (pos == 0){ //boundary condition, underflow
		errPrint("last(): No occupied places \n");
		return;
	}
	pos = mySize - 1;
	return;
}

void List::prev() {
	//sets current at previous position
	if (pos == 0) { //boundary condition: underflow
		errPrint("prev() Boundary Underflow: Stuck at 0.\n");
		return;
	}
	pos--;
	return;
}

void List::next() {
	//sets current at next position
	if (pos + 1 >= mySize) {
		//errPrint("next() Invariant conflict, pos must point to data: ");
		//cerr << pos << endl;
		return;
	}
	pos++;
	return;
}

void List::insertBefore(ET x) {
	//inserts a new element before the current position
	if (pos == mySize) { //if the first element
		//errPrint("insertBefore() cannot insert before first position.\n");
		insertAfter(x);
		return;
	}
	if (mySize >= CAP) { //if the list is full
		errPrint("insertBefore(): list is full, ignoring\n");
		return;
	}
	//otherwise, push everything one space right, then insert at pos.
	//cout << "insertBefore() trig" << endl;
	for (int i = mySize; i > pos; i--) {
		myAry[i] = myAry[i - 1];
	}
	myAry[pos] = x;
	//pos++;
	mySize++;
	return;
}

void List::insertAfter(ET x) {
	//inserts a new element after the current position
	if (pos == mySize) { //if the first element
		//cout << "insertAter() first element" << endl;
		myAry[pos] = x;
		mySize++;
		return;
	}
	if (mySize >= CAP) { //if the list is full
		errPrint("insertAfter() list is full, ignoring\n");
		return;
	}
	//otherwise push everything one space right, then insert after pos.
	//cout << "insertAfter() trig" << endl;
	for (int i = mySize; i > pos + 1; i--) {
		myAry[i] = myAry[i - 1];
	}
	myAry[pos + 1] = x;
	pos++;
	mySize++;
	return;
}

void List::replace(ET x) {
	//replaces current position with new value
	myAry[pos] = x;
	return;
}

void List::erase() {
	//deletes current position, replaces with last element in list, shortens length
	if (mySize == 0) {
		errPrint("erase() cannot operate on empty list.\n");
		return;
	}
	myAry[pos] = myAry[mySize - 1];
	mySize--;
	return;
}

void List::clear() {
	//clears list by setting size to 0;
	mySize = 0;
	return;
}

void List::reverse() {
	//reverses elements in list
	if (mySize <= 1) {
		//can't reverse a single or no entries. No errors though.
		return;
	}
	List temp;
	temp = *this;
	for (int i = 0; i < mySize; i++) {
		myAry[i] = temp.getAt(mySize - 1 - i);
	}
	return;
}

void List::swap(List x) {
	//swaps all of the elements of one list with another list
	List temp(x);
	x = *this;
	*this = temp;
	return;
}

void List::swapAt(int x, int y) {
	//swaps elements at two spaces in list
	if (x > mySize || y > mySize) {
		errPrint("swapAt(): out of bounds\n");
		return;
	}
	ET z;
	z = myAry[x];
	myAry[x] = myAry[y];
	myAry[y] = z;
	return;
}

//void List::shiftR(int pos) {
//	//moves everything from pos to end right one space
//	//if full, overwrites element at end!
//	//otherwise, increases mySize by 1.
//	//item at pos must be replaced, or there will be a duplicate
//	if (mySize < CAP) { mySize = mySize + 1; }
//	for (int i = mySize; i > pos; i--) {
//		myAry[i] = myAry[i - 1];
//	}
//}
//
//void List::shiftL(int pos) {
//	//moves everything from pos to end left one space
//	//deletes whatever is at pos!
//	//then trims mySize by 1
//	for (pos; pos < mySize - 1; pos++) {
//		myAry[pos] = myAry[pos + 1];
//	}
//	mySize--;
//}

List List::operator+=(List a){
	//adds each element of list b to list a
	//new size is the same as the larger of the lists
	List temp;
	temp.setSize(this->size());
	ET sum; //placeholder for addition
	if (this->size() < a.size()) temp.setSize(a.size()); //extend size of list if needed
	for (int i = 0; i < a.size(); i++) { //only for length of second list! This prevents adding junk data.
		sum = this->getAt(i) + a.getAt(i);
		temp.setAt(i, sum);
	}
	return temp;
}

//external operator overloads
bool operator == (List a, List b) {
	//compares list to another list
	//quick check
	if (a.size() != b.size()) return false;
	//full check
	for (int i = 0; i < a.size(); i++) {
		if (a.getAt(i) != b.getAt(i)) return false;
	}
	//if all the above doesn't return false, then...
	return true;
}

bool operator != (List a, List b) {
	//might as well, while we're here
	if (a == b) return false;
	else return true;
}

List operator + (List a, List b) {
	//adds each element of list b to list a
	//new size is the same as the larger of the lists
	ET sum; //placeholder for addition
	List total;
	if (a.size() < b.size()) a.setSize(b.size()); //extend size of list a if needed
	total.setSize(a.size()); //make space for sum to fit.
	for (int i = 0; i < b.size(); i++) { //only for length of second list! This prevents adding junk data.
		sum = a.getAt(i) + b.getAt(i);
		total.setAt(i, sum);
	}
	return total;
}

//friends
ostream& operator << (ostream& outs, List x) {
	outs << "( ";
	for (int i = 0; i < x.size(); i++) {
		outs << x.getAt(i) << " ";
	}
	outs << ")";
	return outs;
}
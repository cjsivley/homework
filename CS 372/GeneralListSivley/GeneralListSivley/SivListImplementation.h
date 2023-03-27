#pragma once

//constructors
template <typename ET>
List<ET>::List() { //default
	mySize = 0;
	pos = 0;
	//myAry;
	//fill(myAry, myAry + CAP, NULL);
}

template <typename ET>
List<ET>::List(const List& l) { // copy constructor
	for (int i = 0; i < l.size(); i++)
		myAry[i] = l.getAt(i);
	mySize = l.size();
	pos = l.getPos();
}

//Assignment operator
template <typename ET>
void List<ET>::operator = (List l) {
	for (int i = 0; i < l.size(); i++)
		myAry[i] = l.getAt(i);
	mySize = l.size();
	pos = l.getPos();
}

//getters
template <typename ET>
ET List<ET>::getElement() const {
	return myAry[pos];
}

template <typename ET>
int List<ET>::size() const {
	return mySize;
}

template <typename ET>
int List<ET>::getPos() const {
	return pos;
}

template <typename ET>
ET List<ET>::getAt(int x) const {
	return myAry[x];
}

template <typename ET>
bool List<ET>::empty() const {
	if (mySize == 0)
		return true;
	else
		return false;
}

//setters
template <typename ET>
void List<ET>::setPos(int x) {
	//sets current position
	if (x < 0) {
		cerr << "setPos() Boundary condition, cannot set pos less than 0.\n";
		return;
	}
	if (x >= mySize) {
		cerr << "setPos() Invariant condition, cannot set pos >= mySize.\n";
		return;
	}
	pos = x;
	return;
}

template <typename ET>
void List<ET>::setSize(int x) {
	//manually sets size, used in operator overloads
	mySize = x;
	return;
}

template <typename ET>
void List<ET>::setAt(int position, ET value) {
	//manually sets element, used in operator overloads
	myAry[position] = value;
	return;
}

//utility

template <typename ET>
void List<ET>::first() {
	//sets current position to beginning of list
	pos = 0;
	return;
}

template <typename ET>
void List<ET>::last() {
	//sets current position to last occupied place in list
	if (pos == 0 && mySize == 0) { //boundary condition, underflow
		cerr << "last(): No occupied places \n";
		return;
	}
	pos = mySize - 1;
	return;
}

template <typename ET>
void List<ET>::prev() {
	//sets current at previous position
	if (pos == 0) { //boundary condition: underflow
		cerr << "prev() Boundary Underflow: Stuck at 0.\n";
		return;
	}
	pos--;
	return;
}

template <typename ET>
void List<ET>::next() {
	//sets current at next position
	if (pos + 1 >= mySize) {
		//cerr << "next() Invariant conflict, pos must point to data: ");
		//cerr << pos << endl;
		return;
	}
	pos++;
	return;
}

template <typename ET>
void List<ET>::insertBefore(ET x) {
	//inserts a new element before the current position
	if (pos == mySize) { //if the first element
		//cerr << "insertBefore() cannot insert before first position.\n");
		insertAfter(x);
		return;
	}
	if (mySize >= CAP) { //if the list is full
		cerr << "insertBefore(): list is full, ignoring\n";
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

template <typename ET>
void List<ET>::insertAfter(ET x) {
	//inserts a new element after the current position
	if (pos == mySize) { //if the first element
		myAry[pos] = x;
		mySize++;
		return;
	}
	if (mySize >= CAP) { //if the list is full
		cerr << "insertAfter() list is full, ignoring\n";
		return;
	}
	//otherwise push everything one space right, then insert after pos.
	for (int i = mySize; i > pos + 1; i--) {
		myAry[i] = myAry[i - 1];
	}
	myAry[pos + 1] = x;
	pos++;
	mySize++;
	return;
}

template <typename ET>
void List<ET>::replace(ET x) {
	//replaces current position with new value
	myAry[pos] = x;
	return;
}

template <typename ET>
void List<ET>::erase() {
	//deletes current position, replaces with last element in list, shortens length
	if (mySize == 0) {
		cerr << "erase() cannot operate on empty list.\n";
		return;
	}
	myAry[pos] = myAry[mySize - 1];
	mySize--;
	return;
}

template <typename ET>
void List<ET>::clear() {
	//clears list by setting size to 0;
	mySize = 0;
	return;
}

template <typename ET>
void List<ET>::reverse() {
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

template <typename ET>
void List<ET>::swap(List x) {
	//swaps all of the elements of one list with another list
	List temp(x);
	x = *this;
	*this = temp;
	return;
}

template <typename ET>
void List<ET>::swapAt(int x, int y) {
	//swaps elements at two spaces in list
	if (x > mySize || y > mySize) {
		cerr << "swapAt(): out of bounds\n";
		return;
	}
	ET z;
	z = myAry[x];
	myAry[x] = myAry[y];
	myAry[y] = z;
	return;
}

template <typename ET>
List<ET> List<ET>::operator+=(List a) {
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
template <typename ET>
bool operator == (List<ET> a, List<ET> b) {
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

template <typename ET>
bool operator != (List<ET> a, List<ET> b) {
	//might as well, while we're here
	if (a == b) return false;
	else return true;
}

template <typename ET>
List<ET> operator + (List<ET> a, List<ET> b) {
	//adds each element of list b to list a
	//new size is the same as the larger of the lists
	ET sum; //placeholder for addition
	List<ET> total;
	if (a.size() < b.size()) a.setSize(b.size()); //extend size of list a if needed
	total.setSize(a.size()); //make space for sum to fit.
	for (int i = 0; i < b.size(); i++) { //only for length of second list! This prevents adding junk data.
		sum = a.getAt(i) + b.getAt(i);
		total.setAt(i, sum);
	}
	return total;
}

//friends
template <typename ET>
ostream& operator << (ostream& outs, List<ET> x) {
	outs << "( ";
	for (int i = 0; i < x.size(); i++) {
		outs << x.getAt(i) << " ";
	}
	outs << ")";
	return outs;
}
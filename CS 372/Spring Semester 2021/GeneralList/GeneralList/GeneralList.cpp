// Codey Sivley, CS372 General List
// 2/2/2021
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include "SivList.h"
#include "codex.h"

using namespace std;

//global file access
ofstream oufi;

int main()
{
	oufi.open("GeneralListResultsSivley.txt");

	oufi << "General List Results\nCodey Sivley 2/2/2021\nCS372" << endl;

	List a, b;  int endit;

	for (int i = 1; i <= 20; i++)
		a.insertAfter(i);
	oufi << "List a : " << endl;
	oufi << "  " << a << endl;
	oufi << "Number of elements in a - " << a.size() << endl;

	for (int i = 1; i <= 10; i++)
		b.insertBefore(i);
	oufi << "List b : " << endl;
	oufi << "  " << b << endl;
	oufi << "Number of elements in b - " << b.size() << endl;

	if (a == b)
		oufi << "List a & b are equal" << endl;
	else
		oufi << "List a & b are Not equal" << endl;

	a.first();
	b.first();
	oufi << "First elmenet in list a & b: " << a.getElement() << ", "
		<< b.getElement() << endl;
	a.last();
	b.last();
	oufi << "Last elmenet in list a & b: " << a.getElement() << ", "
		<< b.getElement() << endl;

	oufi << endl << endl << " Start of new stuff" << endl;

	b.clear();
	oufi << "Empty List b:  " << b << endl;

	if (a == b)
		oufi << "List a & b are equal" << endl;
	else
		oufi << "List a & b are Not equal" << endl;

	for (int i = 1; i <= 10; i++)
		b.insertBefore(i * 5);
	oufi << "List b : " << endl << b << endl;

	a.setPos(5);
	b.first();
	for (int i = 1; i < 4; i++)
	{
		b.replace(a.getElement());
		a.erase();
		b.next();
	}

	oufi << "Modified Object 'a' (shorter) " << endl;
	oufi << "List a: " << a << endl;
	oufi << "Modified Object 'b' " << endl;
	oufi << "List b: " << b << endl;

	for (int i = 1; i <= 10; i++)
		b.insertBefore(i);

	List c(b);
	oufi << "Copy Constructor c(b)" << endl;
	oufi << "List b : " << b << endl;
	oufi << "List c : " << c << endl;

	if (c == b)
		oufi << "List c & b are equal" << endl;
	else
		oufi << "List c & b are Not equal" << endl;


	List e;
	e = c;
	oufi << "Object 'c' assigned to Object 'e':" << endl;
	oufi << "List c : " << c << endl;
	oufi << "List e : " << e << endl;

	b.first();
	endit = b.size();
	for (int i = 1; i < endit; b.next(), i++)
	{
		b.insertBefore(b.getElement() * (-1));
		b.next(); b.next();
	}
	oufi << "Results after some inserts on b " << endl;
	oufi << "List b : " << b << endl;

	a.first();
	endit = a.size();
	for (int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos() + a.getElement());
		a.next();
	}
	oufi << "Results after some weird stuff on list a" << endl;
	oufi << "List a : " << a << endl;

	List alist;
	alist.clear();
	for (int i = 1; i <= 10; i++)
		alist.insertAfter(i);
	alist.first();
	oufi << "New List alist with positions above: " << endl;
	for (int i = 1; i <= 10; i++) {
		oufi << setw(5) << alist.getPos();
		alist.next();
	}
	oufi << endl;
	alist.first();
	for (int i = 1; i <= 10; i++) {
		oufi << setw(5) << alist.getElement();
		alist.next();
	}
	oufi << endl;

	List d(alist);
	d += alist;

	alist.first();
	endit = alist.size();
	oufi << "show 'alist' object after 'd+= alist' " << alist << endl;
	for (int i = 1; i <= endit; i++) {
		oufi << setw(5) << alist.getElement();
		alist.next();
	}

	d.first();
	endit = d.size();
	oufi << "show 'd' object after 'd+= alist' " << d << endl;
	for (int i = 1; i <= endit; i++) {
		oufi << setw(5) << d.getElement();
		d.next();
	}

	oufi << endl << "  check out boundary conditions" << endl;
	List sq;
	oufi << "number of elements in empty sq list = " << sq.size() << endl;
	sq.first();
	sq.prev();
	sq.erase();
	sq.last();
	sq.setPos(5);
	oufi << "empty sq values " << sq << endl;
	sq.insertBefore(3333);
	oufi << "sq values " << sq << endl;
	sq.next(); sq.next();
	oufi << "sq.getElement() = " << sq.getElement() << endl;
	oufi << "sq list = " << sq << endl;
	return 0;
}
// GeneralList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>
#include <string>
#include "SivList.h" //general list

using namespace std;

//global file access
ofstream oufi;

int main()
{
	oufi.open("GenListTemplateResultsSivley.txt");
	oufi << "General List Template\nCodey Sivley, CS372 Spring 2021" << endl;

	List<int> a, b;  int endit;

	for (int i = 1; i <= 20; i++) {
		//oufi << "i: " << i << endl;
		a.insertAfter(i * 2);
	}
	oufi << "List a : " << endl;
	oufi << "  " << a << endl;
	oufi << "Number of elements in a - " << a.size() << endl;

	for (int i = 1; i <= 10; i++) {
		b.insertBefore(i * 3);
	}
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
		a.erase();
		b.replace(i);
		b.next();
	}

	oufi << "Modified Object 'a' (shorter) " << endl;
	oufi << "List a: " << a << endl;
	oufi << "Modified Object 'b' " << endl;
	oufi << "List b: " << b << endl;

	List<int> c(b);
	oufi << "Copy Constructor c(b)" << endl;
	oufi << "List b : " << b << endl;
	oufi << "List c : " << c << endl;

	if (c == b)
		oufi << "List c & b are equal" << endl;
	else
		oufi << "List c & b are Not equal" << endl;


	List<int> e;
	e = c;
	oufi << "Object 'c' assigned to Object 'e':" << endl;
	oufi << "List c : " << c << endl;
	oufi << "List e : " << e << endl;

	List<int> f;

	for (int i = 0; i < 20; i++) {
		f.insertAfter(i);
		oufi << f << endl;
	}

	List<int> g(f+f);
	//g = f + f;
	oufi << f << endl;
	oufi << g << endl;


	
	List<int> d;
	d = a;

	d.first();
	endit = d.size();
	for (int i = 1; i < endit; d.next(), i++)
	{
		d.insertBefore(d.getElement() * (-2));
		d.next();
	}
	oufi << "Results after some Replaces on d " << endl;
	oufi << "List d : " << d << endl;

	a.first();
	endit = a.size();
	for (int i = 1; i < endit; a.next(), i++)
	{
		a.replace(a.getPos() + a.getElement());
		a.next();
	}
	oufi << "Results after some weird stuff on list a" << endl;
	oufi << "List a : " << a << endl;

	List<int> alist(b);
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

	oufi << endl << "  check out boundary conditions" << endl;
	List<int> sq;
	oufi << "number of elements in empty sq list = " << sq.size() << endl;
	sq.first();
	sq.erase();
	sq.setPos(5);
	oufi << "empty sq values " << sq << endl;
	sq.insertBefore(777);
	oufi << "sq values " << sq << endl;
	sq.next(); sq.next();
	oufi << "sq.getElement() = " << sq.getElement() << endl;
	oufi << "sq list = " << sq << endl;
	
	return 0;
}
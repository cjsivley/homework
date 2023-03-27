// LinkListPractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//global file access
ifstream infi;
ofstream oufi;

struct NODE {
    int val;
    int count;
    NODE* linky;

};

//prototypes
NODE* CreateNode(int);
void PrintAllNodes(NODE*);
NODE* LoadNodes();
NODE* NewNode();
void insert(NODE**, int);
void SendToBack(NODE**, int);
void ReversedPrint(NODE*);
void foo(NODE*);

NODE* head;
int main()
{
	//console formatting
	cout.precision(2);
	cout << fixed;
	cout << showpoint;

	//UI start (only used for debug here)
	cout << "Codey Sivley\n";
	cout << "\n";
	cout << "----------------\n";
	cout << "LinkList Practice 318\n";
	cout << "----------------\n";

	//file I/O setup
	infi.open("LinkNbrsEdit.dat");
	if (!infi) {
		cout << "Error reading file" << endl;
		return 0;
	}

	NODE* head;
	head = NULL;

	cout << "head before load " << head << endl;
	//head = LoadNodes();
	int val;
	infi >> val;
	//begin loop
	while (!infi.eof()) {
		insert(&head, val);
		infi >> val;
	}
	cout << "head after load " << head << endl;
	PrintAllNodes(head);

	//cout << "sending 25 to the back" << endl;

	//SendToBack(&head, 25);
	//check list again
	//PrintAllNodes(head);
	//cout << "reversed recursively " << endl;
	//ReversedPrint(head);
	foo(head);
	PrintAllNodes(head);


	system("pause");
    return 0;
    


	//todo
	//rewatch link list lecture, look at working link list code
}

//toolbox
void foo(NODE* head) {
	NODE* c;
	NODE* n;
	NODE* t;
	c = head;
	n = c->linky;
	cout << "n :" << n;
	c->linky = NULL;
	while (n != NULL) {
		t = n->linky;
		n->linky = c;
		c = n;
		n = t;
	}
	head = c;
}

NODE* CreateNode(int num) {
	NODE* temp = new NODE;
	temp->val = num;
	temp->linky = NULL;
	temp->count = 1;

	//cout << "returning address " << temp << endl;
	return temp;
}

void PrintAllNodes(NODE* pos) {
	NODE* cur;
	cur = pos;
	while (cur) {
		cout << cur->val << " @ " << cur << " x " << cur->count << endl;
		cur = cur->linky;
	}
	cout << "End of list" << endl;
}

NODE* LoadNodes() {
	NODE* head;
	NODE* pre;
	NODE* cur;
	int val;
	infi >> val;
	//create first node
	cur = CreateNode(val);
	//cout << "current point " << cur << endl;
	//step to next node
	head = cur;
	pre = head;
	cur = NULL;
	infi >> val;
	//begin loop
	while (!infi.eof()) {
		cur = CreateNode(val);
		pre->linky = cur;
		//step to next node
		pre = cur;
		cur = NULL;
		infi >> val;
	}
	cout << "final position " << pre << endl;
	cout << "should be null: " << pre->linky << endl;

	return head;
}


NODE* NewNode() {
	NODE* t;
	t = new NODE;
	(*t).val = 0;
	(*t).count = 1;
	(*t).linky = NULL;
	return t;
}

void insert(NODE** head, int targ) {
	NODE* cp;
	NODE* t;
	NODE* p;

	cp = *head;
	p = NULL;
	//cout << "current head " << *head << endl;
	//cout << "current point " << cp << endl;

	while ((cp != NULL) && (cp->val < targ)) {
		p = cp;
		cp = cp->linky; //bumps to next node
	}
	if (cp != NULL && cp->val == targ) {
		cp->count = cp->count + 1;
	}
	else {
		t = NewNode();
		t->val = targ;

		//link up
		t->linky = cp;

		if (p != NULL) {
			p->linky = t;
		}
		else {
			*head = t;
		}
	}
	//report for DEBUG
	//cout << "p " << p << endl;
	//cout << "head " << head << endl;
	//cout << "t val " << t->val << endl;
	//cout << "t count" << t->count << endl;
	//cout << "t linky " << t->linky << endl;
}

void SendToBack(NODE** head, int targ) {
	NODE* cp;
	NODE* t;
	NODE* p;
	//find target
	cp = *head;
	p = NULL;
	cout << "current head " << *head << endl;
	cout << "current point " << cp << endl;

	while ((cp != NULL) && (cp->val != targ)) {
		p = cp;
		cp = cp->linky; //bumps to next node
	}
	//have we found it
	cout << "found target at " << cp << endl;
	//cut from current position
	p->linky = cp->linky;
	//traverse to end
	t = cp; //hold for me
	while (cp != NULL) {
		p = cp;
		cp = cp->linky; //bumps to next node
	}
	//we're at NULL, glue it in
	p->linky = t;
	t->linky = NULL;
	return;
}

void ReversedPrint(NODE* pos) {

	if (pos == NULL) {
		return;
	}
	ReversedPrint(pos->linky);
	cout << pos->val << endl;
}

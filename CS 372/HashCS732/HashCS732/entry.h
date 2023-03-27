#pragma once

#include <string>

using namespace std;

class entry
{
private:
	string name; //name, which is key for hash
	string phone; //phone number
	int index; //hash's integer return
	entry* nextNode; //next node in link list for each array point

public:
	static int collisions;
	entry(); //default constructor
	void setName(string); //sets Name
	void setPhone(string); //sets phone number
	void setIndex(int); //sets index
	void setNext(entry*); //sets next node
	string getName(); //returns name
	string getPhone(); //returns phone number
	entry* getNext(); //returns nextNode
	int getIndex(); //returns index
	void consoleDisplay(); //couts the entry

};


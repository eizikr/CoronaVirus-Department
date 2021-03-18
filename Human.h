#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;
#ifndef _HUMAN_H
#define _HUMAN_H

class Human {	//A class that describes a person
protected:
	string first_name;
	string last_name;
	string id;
public:
	//ctors
	Human(string = "Undefined", string = "Undefined", string = "No-id");
	Human(const Human&);
	virtual ~Human() = 0 {};

	//methods
	virtual void print();	//print full name and id
	string getId() { return id; }
};
#endif // !_HUMAN_H

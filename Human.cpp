#include "Human.h"

Human::Human(string f_name, string l_name, string _id) :first_name(f_name), last_name(l_name), id(_id) {}

Human::Human(const Human& obj) : first_name(obj.first_name), last_name(obj.last_name), id(obj.id) {}

void Human::print()
{//print full name and id 
	cout << "Name: "<< first_name << " " << last_name << endl;
	cout << "ID: " << id << endl;
}

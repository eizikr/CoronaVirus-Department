#include "Employee.h"

Employee::Employee(string f_name, string l_name, string _id, int _seniority) :seniority(_seniority), Human(f_name, l_name, _id), salary(BASE_SALARY) {}

Employee::Employee(const Employee& obj) : seniority(obj.seniority), Human(obj.first_name, obj.last_name, obj.id){}

void Employee::print()
{
	Human::print();//print name and id
	cout << "Seniority: " << seniority << endl;
	cout << "Salery: " << salary << endl;
}



#include "Human.h"
#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#define BASE_SALARY 6500

class Employee :public Human {	//A class that describes a employee
protected:
	int seniority;
	int salary;
public:
	//c'tors
	Employee(string = "Undefined", string = "Undefined", string = "No-id", int = 0);
	Employee(const Employee&);
	~Employee() {};

	//methods
	void print();	//print details
	virtual bool is_Distinguished_Employee() { return false; }	//dont do nothing yet
	int getSeniority()const { return seniority; }	
	const int getSalary()const { return salary; }
	void setSalary(int num) { salary = num; }
};

#endif // !_EMPLOYEE_H

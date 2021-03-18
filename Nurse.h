#include "Employee.h"
#ifndef _NURSE_H
#define _NURSE_H
#define TRAINING_BONUS 50

class Nurse :public Employee {	//A class that describes a nurse
	string hospital_name;
	int trainings_number;
public:
	//c'tors
	Nurse(string = "Undefined", string = "Undefined", string = "No-id", int = 0, string = "Undefined", int = 0);
	Nurse(const Nurse&);
	~Nurse();

	//methods
	bool is_Distinguished_Employee();	//checking if trainings number bigget then seniority
	const int getNurseSalary()const { return this->getSalary(); }
	void print(); //printing all details about the nurse
	void updateSalery();	//calculate the salery and update it
	void setHospital(string hospital) { hospital_name = hospital; }

	//operstors
	friend istream& operator>>(istream&, Nurse&);
};

#endif // !_EMPLOYEE_H
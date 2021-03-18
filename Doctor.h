#include "Employee.h"
#ifndef _DOCTOR_H
#define _DOCTOR_H
#define PROFESSOR_BONUS 2000
#define EVALUATIONS_BONUS 50
#define SENIORITY_BONUS 200

class Doctor :public Employee {	//A class that describes a nurse
	string hospital_name;
	bool is_a_professor;	
	int evaluations;	//good evaluations
public:
	//c'tors
	Doctor(string = "Undefined", string = "Undefined", string = "No-id", int = 0, string = "Undefined", bool = 0, int = 0);
	Doctor(const Doctor&);
	~Doctor();

	//methods
	const int getDoctorSalary() { return this->getSalary(); }
	bool is_Distinguished_Employee();	//check if evaluations is bigget then 10
	void print();	//printing all details about the doctor
	void updateSalery();	//calculate salery again
	void setHospital(string hospital) { hospital_name = hospital; }
	
	//operators
	friend istream& operator>> (istream&, Doctor&);
};


#endif // !_DOCTOR_H

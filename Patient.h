#include "Human.h"
#ifndef _PATIENT_H
#define _PATIENT_H

class Patient:public Human {
	string hospital_name;
	int corona_tests;	//number of tests that patient did
	int negative_tests;	//number of negative corona tests
public:
	//c'tors
	Patient(string = "Undefined", string = "Undefined", string = "No-id", string = "Undefined", int = 0, int = 0);
	Patient(const Patient&);
	~Patient();

	//methods
	int getNegativeTestsNumber() { return negative_tests; }
	void print();	//print patient details
	void setHospital(string hospital) { hospital_name = hospital; }
	void addCoronaTest() { corona_tests++; }	//add a corona test
	void addNegativeCoronaTest() { negative_tests++; }	//add a negative corona test
	string getHospitalName() { return hospital_name; }

	//operators
	friend istream& operator>>(istream&, Patient&);
};

#endif // !_PATIENT_H

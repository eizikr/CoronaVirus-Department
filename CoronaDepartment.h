#include "Patient.h"
#include "Nurse.h"
#include "Doctor.h"
#ifndef _CORONA_DEPARTMENT_H
#define _CORONA_DEPARTMENT_H

class CoronaDepartment {
	string hospital_name;
	Patient** patient;
	Doctor** doctor;
	Nurse** nurse;
	int patient_number;
	int doctors_number;
	int nurses_number;
public:
	//c'tors
	CoronaDepartment(string = "Undefined");
	CoronaDepartment(const CoronaDepartment&);
	~CoronaDepartment();

	//methods
	void addDoctor(Doctor*);	//get doctor by addres and add him to department
	void addNurse(Nurse*);		//get nurse by addres and add him to department
	void addPatient(Patient*);	//get patient by addres and add him to dapartment
	void print();	//print department details
	Patient* getPatient(int index) { return patient[index]; }	//get patient by id
	Doctor* getDoctor(int index) { return doctor[index]; }	//get doctor by id
	Nurse* getNurse(int index) { return nurse[index]; }	//get nurse by id
	int getNursesNumber() { return nurses_number; }
	string getHospitalName() { return hospital_name; }
	void setHospital(string hospital) { hospital_name = hospital; }
	void releasePatient(string id);	//search the patient by id and delete him from department

	//operators
	friend ostream& operator<<(ostream&, const CoronaDepartment&);

};
#endif // !_CORONA_DEPARTMENT_H


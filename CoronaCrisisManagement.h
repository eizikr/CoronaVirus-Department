#include "CoronaDepartment.h"
#include <typeinfo>
#ifndef _CORONA_CRISIS_MANEGEMENT_H
#define _CORONA_CRISIS_MANEGEMENT_H
#define HOSPITAL_NUM 5

class CoronaCrisisManagement {
	Patient** patient;
	CoronaDepartment** department;
	Employee** worker;
	int patients_number;
	int departments_number;
	int workers_nuber;

	//private methods
	void printOptions();	//print the manu
	void AddNurse();		//add nurse to department
	void AddDoctor();		//add doctor to department
	void AddDepartment();	//open a department 				
	void PrintDepartmentDetails();			
	void PrintDoctorsDetails();				
	void PrintSalary();		//print the salery of employee by id				
	void AddPatient();		//add patient to department				
	void AddCoronaTestToPatientById();		
	void Releasing();		//releasing all patient witn 2 or more negative tests				
	void PrintExcellenceWorker();
	void PrintNurseWithSmallestSalary();

	int CheckDepartmentIsExist(string);		//check if hospital
	bool CheckWorkerID(string);		//check if worker id is already exist
	bool CheckPatientID(string);	//check if patient id is already exist
	bool HospitalIsInTheList(string);	//check if the hospital is in the list
	bool DepartmentIsExist(string);	//check if department is opend by hospital
	void printHospitalNames();
	void fixString(string&);
	void addWorker(Employee*);	//add a new worker to employee

public:
	//c'tors
	CoronaCrisisManagement();
	CoronaCrisisManagement(const CoronaCrisisManagement&);
	~CoronaCrisisManagement();

	//methods
	void Menu();	//print manu and manage program
};
#endif // !_CORONA_CRISIS_MANEGEMENT_H

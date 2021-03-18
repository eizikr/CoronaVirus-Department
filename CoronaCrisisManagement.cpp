#include "CoronaCrisisManagement.h"
enum Test {
	Positive,
	Negative
};

enum Option
{	ADD_NURSE =1, 
	ADD_DOCTOR, 
	ADD_DEPARTMENT, 
	PRINT_DEPARTMENT_DETAILS, 
	PRINT_DOCTORS_DETAILS, 
	PRINT_SALARY_BY_ID, 
	ADD_PATIENT, 
	ADD_CORONA_TEST_TO_PATIENT_ID,
	RELEASING_PATIENTS,
	PRINT_EXCELLENCE_WORKER,
	PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY,
	EXIT
};

CoronaCrisisManagement::CoronaCrisisManagement():workers_nuber(3), departments_number(1), patients_number(0)
{
	string hospital;
	cout << "Lets open our first corona-department!" << endl;
	cout << "Please choose hospital from the list to create a corona-department there: " << endl;
	printHospitalNames();
	cout << "Enter hospital name: ";
	getline(cin, hospital);
	fixString(hospital);
	while (!HospitalIsInTheList(hospital))
	{//make sure he choose optieon from the list
		cout << "~ You can only choose hospital from the list! ~" << endl;
		cout << "Enter hospital name: ";
		getline(cin, hospital);
		fixString(hospital);
	} 
	//open department
	patient = NULL;
	department = new CoronaDepartment*[departments_number];
	department[0] = new CoronaDepartment(hospital);
	//copy adresses
	worker = new Employee*[workers_nuber];
	worker[0] = department[0]->getDoctor(0);
	worker[1] = department[0]->getNurse(0);
	worker[2] = department[0]->getNurse(1);
}

CoronaCrisisManagement::CoronaCrisisManagement(const CoronaCrisisManagement& obj) :patients_number(obj.patients_number), departments_number(obj.departments_number), workers_nuber(obj.workers_nuber)
{
	patient = new Patient*[patients_number];
	for (int i = 0; i < patients_number; i++)
	{
		patient[i] = new Patient(*obj.patient[i]);
	}
	
	worker = new Employee*[workers_nuber];
	for (int i = 0; i < workers_nuber; i++)
	{
		worker[i] = new Employee(*obj.worker[i]);
	}

	department = new CoronaDepartment*[departments_number];
	for (int i = 0; i < departments_number; i++)
	{
		department[i] = new CoronaDepartment(*obj.department[i]);
	}
}

CoronaCrisisManagement::~CoronaCrisisManagement()
{//free pointers and departments
	for (int i = 0; i < departments_number; i++)
	{
		delete department[i];
	}
	delete department;
	delete[] patient;
	delete[] worker;
}

void CoronaCrisisManagement::printOptions()
{
	cout << "\n Menu: " << endl;
	cout << " 1. ADD NURSE" << endl;
	cout << " 2. ADD DOCTOR" << endl;
	cout << " 3. ADD DEPARTMENT" << endl;
	cout << " 4. PRINT DEPARTMENT DETAILS" << endl;
	cout << " 5. PRINT DOCTORS DETAILS" << endl;
	cout << " 6. PRINT SALARY BY ID" << endl;
	cout << " 7. ADD PATIENT" << endl;
	cout << " 8. ADD CORONA TEST TO PATIENT ID" << endl;
	cout << " 9. RELEASING PATIENTS" << endl;
	cout << " 10. PRINT EXCELLENCE WORKER" << endl;
	cout << " 11. PRINT NURSE DETAILS WITH SMALLEST SALARY" << endl;
	cout << " 12. EXIT\n" << endl;
	
}


void CoronaCrisisManagement::Menu()
{	//menu
	int option;
	bool run = true;
	while (run)
	{
		printOptions();
		cout << "Your choice: ";
		cin >> option;
		switch (option)
		{
		case ADD_NURSE:
			AddNurse();
			break;
		case ADD_DOCTOR:
			AddDoctor();
			break;
		case ADD_DEPARTMENT:
			AddDepartment();
			break;
		case PRINT_DEPARTMENT_DETAILS:
			PrintDepartmentDetails();
			break;
		case PRINT_DOCTORS_DETAILS:
			PrintDoctorsDetails();
			break;
		case PRINT_SALARY_BY_ID:
			PrintSalary();
			break;
		case ADD_PATIENT:
			AddPatient();
			break;
		case ADD_CORONA_TEST_TO_PATIENT_ID:
			AddCoronaTestToPatientById();
			break;
		case RELEASING_PATIENTS:
			Releasing();
			break;
		case PRINT_EXCELLENCE_WORKER:
			PrintExcellenceWorker();
			break;
		case PRINT_NURSE_DETAILS_WITH_SMALLEST_SALARY:
			PrintNurseWithSmallestSalary();
			break;
		case EXIT:
			run = false;
			break;

		}
	}
}

	//functions from the menu//

void CoronaCrisisManagement::AddNurse()
{
	string hospital;
	int index;
	cin.ignore();
	printHospitalNames();
	cout << "Choose a department: " << endl;
	getline(cin, hospital);
	fixString(hospital);
	index = CheckDepartmentIsExist(hospital); //get department index
	if (index != -1)	//if index is -1, department isnt exist
	{
		cout << "\n---------- Creating a nurse -----------\n" << endl;
		Nurse* new_nurse = new Nurse;
		cin >> *new_nurse;
		if (CheckWorkerID(new_nurse->getId()))
		{//check if id of the new nurse is already exist
			delete new_nurse;
			cout << "\n~ Nurse ID is already exist ~\n" << endl;
		}
		else
		{
			addWorker(new_nurse);	//add new nurse to employee
			department[index]->addNurse(new_nurse);	//add new nurse to department
		}
	}
	else

		cout << "\n~ The department is not exist! ~\n" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::AddDoctor()
{
	string hospital;
	int index;
	cin.ignore();
	printHospitalNames();
	cout << "Choose a department: " << endl;
	getline(cin, hospital);
	fixString(hospital);
	index = CheckDepartmentIsExist(hospital);	//get department index
	if (index != -1)	//if index is -1, department isnt exist
	{
		cout << "\n------- Creating a new doctor ---------\n" << endl;
		Doctor* new_doc = new Doctor;
		cin >> *new_doc;
		if (CheckWorkerID(new_doc->getId()))
		{//check if id of the new doctor is already exist
			delete new_doc;
			cout << "\n~ Doctor ID is already exist ~" << endl;
		}
		else
		{
			addWorker(new_doc);	//add new doctor to employee
			department[index]->addDoctor(new_doc);	//add doctor nurse to department
		}
	}
	else
		cout << "\n~ The department is not exist! ~" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::AddDepartment()
{
	string hospital;
	cin.ignore();
	printHospitalNames();
	cout << "Choose a hospital: " << endl;
	getline(cin, hospital);
	fixString(hospital);
	if (HospitalIsInTheList(hospital))
	{//check if the hospitale is in the list
		if (!DepartmentIsExist(hospital))
		{//check if department is exist by hospital name
			cout << "\n------- Creating a department ---------\n" << endl;
			CoronaDepartment** temp = department;
			department = new CoronaDepartment*[++departments_number];
			for (int i = 0; i < departments_number - 1; i++)
			{//copy department
				department[i] = temp[i];
			}
			department[departments_number - 1] = new CoronaDepartment(hospital);	//open new department in this hospital
			addWorker(department[departments_number - 1]->getDoctor(0));
			addWorker(department[departments_number - 1]->getNurse(0));
			addWorker(department[departments_number - 1]->getNurse(1));
		}
		else
			cout << "\n~ This department is already exist! ~\n" << endl;
	}
	else
		cout << "\n~ The hospital you entered is not on the list ~" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::PrintDepartmentDetails()
{
	string hospital;
	cin.ignore();
	printHospitalNames();
	cout << "Choose a department: " << endl;
	getline(cin, hospital);
	fixString(hospital);
	int index = CheckDepartmentIsExist(hospital);
	if (index != -1)//check if department is exist
	{
		cout << "\n----- Printing department details -----\n" << endl;
		department[index]->print();
	}
	else
	{
		cout << "\n~ Department isn't exist! ~\n" << endl;
	}
	cout << "\n------------ function end -------------" << endl;;
}

void CoronaCrisisManagement::PrintDoctorsDetails()
{
	cout << "\n--------- Printing doctor details --------\n" << endl;
	for (int i = 0; i < workers_nuber; i++)
	{//run on all workers
		Doctor* temp = dynamic_cast <Doctor*>(worker[i]);
		if (temp)
		{//if worker is a doctor, print his details
			temp->print();
			cout << endl;
		}
	}
	cout << "\n------------ function end -------------\n" << endl;;
}

void CoronaCrisisManagement::PrintSalary()
{
	string id;
	cout << "\nEnter id: ";
	cin >> id;
	if (CheckWorkerID(id))	//check if id is exist
	{
		cout << "\n----------- Printing salery --------------\n" << endl;
		for (int i = 0; i < workers_nuber; i++)
		{
			if (worker[i]->getId() == id)	//catch the worker with this id and print his salary
			{
				cout << "The salery is: " << worker[i]->getSalary() << endl;
			}
		}
	}
	else
		cout << "~ There is no much for this id ~" << endl;
	cout << "\n------------ function end -------------" << endl;;
}

void CoronaCrisisManagement::AddPatient()
{
	int index;
	string hospital;
	printHospitalNames();
	cout << "Choose a department: " << endl;
	cin.ignore();
	getline(cin, hospital);
	fixString(hospital);
	index = CheckDepartmentIsExist(hospital);	//get department index
	if (index != -1)	//if index is -1, department isnt exist
	{
		Patient* new_patient = new Patient;
		cin >> *new_patient;
		if (CheckPatientID(new_patient->getId()))	//check if id of the new patient is already exist
		{
			delete new_patient;
			cout << "\n~ Patient ID is already exist ~" << endl;
		}
		else
		{
			cout << "\n---------- Creating patient -----------\n" << endl;
			department[index]->addPatient(new_patient);
			Patient** temp = patient;
			patient = new Patient*[++patients_number];
			for (int i = 0; i < patients_number - 1; i++)
			{
				patient[i] = temp[i];
			}
			patient[patients_number - 1] = new_patient;	//add new patient to patient array
			delete[] temp;
		}
	}
	else
		cout << "\n~ The department is not exist! ~\n" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::AddCoronaTestToPatientById()
{
	string id;
	int test;
	cout << "\nEnter id: ";
	cin >> id;
	if (CheckPatientID(id))	//check if patient id is exist
	{
		cout << "\n--------- adding a corona test ---------\n" << endl;
		cout << "The new test is negative?(1-yes/0-no): ";
		cin >> test;
		while (test != Negative && test != Positive)
		{//make sure the user entering only 1 or 0
			cout << "Enter only 1 or 0: ";
			cin >> test;
		}
		for (int i = 0; i < patients_number; i++)
		{
			if (patient[i]->getId() == id)	//catch the patient with this id
			{
				patient[i]->addCoronaTest();	//add a corona test
				if (test)	//if test is negative (1)
					patient[i]->addNegativeCoronaTest();
			}
		}
	}
	else
		cout << "\n~ Patient ID is not exist! ~" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::Releasing()
{
	cout << "\n------------ Realising --------------\n" << endl;
	int count = 0;
	for (int i = 0; i < patients_number; i++)
	{//run on all patient
		if (patient[i]->getNegativeTestsNumber() > 1)
		{//if patient have 2 or more negative corona tests
			count++;//count him
			for (int j = 0; j < departments_number; j++)
			{//run on all departments
				if (patient[i]->getHospitalName() == department[j]->getHospitalName())
				{//release patient from department
					department[j]->releasePatient(patient[i]->getId());
				}
			}
			//release patient from patients array
			Patient** temp = patient;
			patient = new Patient*[--patients_number];
			for (int j = 0, k = 0; k < patients_number; j++)
			{
				if (temp[j] != temp[i])
				{
					patient[k++] = temp[j];
				}
			}
			delete temp;
		}
	}
	cout << "We released " << count << " patients" << endl;
	cout << "\n------------ function end -------------" << endl;
}

void CoronaCrisisManagement::PrintExcellenceWorker()
{
	cout << "\n----- Printing Excellence Workers -----\n" << endl;
	for (int i = 0; i < workers_nuber; i++)
	{
		if (worker[i]->is_Distinguished_Employee())
		{//check if worker is distinguished employee
			Doctor* temp = dynamic_cast <Doctor*>(worker[i]);
			if (temp)
			{	//if worker is doctor, print doctor
				cout << "   --Doctor--" << endl;
			}
			else	//if worker is nurse, print nurse
				cout << "   --Nurse--" << endl;
			worker[i]->print();
		}
	}
	cout << "------------ function end -------------" << endl;
}

void CoronaCrisisManagement::PrintNurseWithSmallestSalary()
{
	cout << "\n--------- Nurse smaller salery ----------\n" << endl;
	int i = 0, smaller, index;
	bool flag = false;
	while (!flag)
	{//find first nurse salery
		Nurse* temp = dynamic_cast <Nurse*>(worker[i]);
		if (temp)
		{//save that salery, and get out
			smaller = temp->getSalary();
			flag = true;
		}
		i++;
	}
	for (int i = 0; i < workers_nuber; i++)
	{
		Nurse* temp = dynamic_cast <Nurse*>(worker[i]);
		if (temp)
		{//check every nurse salery
			if (temp->getSalary() < smaller)
			{//save salery and save index
				smaller = worker[i]->getSalary();
				index = i;	
			}
		}
	}
	cout << "Nurse with the smaller sallery:" << endl;
	worker[index]->print();	//print nurse with this index
	cout << "\n------------ function end -------------\n" << endl;
}

		//my functions//

void CoronaCrisisManagement::printHospitalNames()
{//print hospital names
	string HospitalNames[HOSPITAL_NUM] = { "Sheba\t     |", "Wolfson\t     |" , "Rambam\t     |", "Assaf Harofeh   |", "Soroka\t     |" };
	cout << "\n----Hospital Names----" << endl;
	for (int i = 0; i < HOSPITAL_NUM; i++)
	{
		cout << "| " << i + 1 << ". " << HospitalNames[i] << endl;
	}
	cout << "----------------------\n" << endl;
}

void CoronaCrisisManagement::fixString(string & word)
{
	if (word[0] >= 'a' && word[0] <= 'z')
		word[0] -= 32;
}

void CoronaCrisisManagement::addWorker(Employee* new_worker)
{
	Employee** temp = worker;
	worker = new Employee*[++workers_nuber];
	for (int i = 0; i < workers_nuber - 1; i++)
	{
		worker[i] = temp[i];
	}
	worker[workers_nuber - 1] = new_worker;
}

int CoronaCrisisManagement::CheckDepartmentIsExist(string hospital)
{
	for (int i = 0; i < departments_number; i++)
	{//check if department is exist 
		if (department[i]->getHospitalName() == hospital)
			return i;
	}
	return -1;
}

bool CoronaCrisisManagement::CheckWorkerID(string id)
{
	for (int i = 0; i < workers_nuber; i++)
	{//check if worker id is already exist
		if (worker[i]->getId() == id)
			return true;
	}
	return false;
}

bool CoronaCrisisManagement::CheckPatientID(string id)
{
	for (int i = 0; i < patients_number; i++)
	{//check if patient id is already exist

		if (patient[i]->getId() == id)
			return true;
	}
	return false;
}

bool CoronaCrisisManagement::HospitalIsInTheList(string hospital)
{
	string HospitalNames[HOSPITAL_NUM] = { "Sheba", "Wolfson" , "Rambam", "Assaf Harofeh", "Soroka" };
	for (int i = 0; i < HOSPITAL_NUM; i++)
	{//check if hospital is on the list
		if (HospitalNames[i] == hospital)
			return true;
	}
	return false;
}

bool CoronaCrisisManagement::DepartmentIsExist(string hospital)
{
	for (int i = 0; i < departments_number; i++)
	{//run on all departments and check if department is exist by hospital name
		if (department[i]->getHospitalName() == hospital)
			return true;
	}
	return false;
}

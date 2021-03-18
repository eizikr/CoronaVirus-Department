#include "CoronaDepartment.h"

CoronaDepartment::CoronaDepartment(string hospital) :doctors_number(1), nurses_number(2), patient_number(0), hospital_name(hospital)
{//we start the department with 2 nurses ,1 doctor, and no patient
	patient = NULL;//no patient

	doctor = new Doctor*[doctors_number];	///////////////////////
	doctor[0] = new Doctor;					// allocate 1 doctor //
	cin >> *doctor[0];						//and set his details//
	doctor[0]->setHospital(hospital_name);	///////////////////////
	cout << endl;
	nurse = new Nurse*[nurses_number];
	for (int i = 0; i < nurses_number; i++)
	{
		cin.ignore();						 ///////////////////////
		nurse[i] = new Nurse;				 // allocate 1 nurse  //
		cin >> *nurse[i];					 //and set her details//
		nurse[i]->setHospital(hospital_name);///////////////////////
		cout << endl;
	}
}

CoronaDepartment::CoronaDepartment(const CoronaDepartment& obj) :patient_number(obj.patient_number), doctors_number(obj.doctors_number), nurses_number(obj.nurses_number)
{
	if (!patient_number)
		patient = NULL;
	else
	{
		patient = new Patient*[patient_number];
		for (int i = 0; i < patient_number; i++)
		{
			patient[i] = new Patient(*(obj.patient)[i]);
		}
	}
	nurse = new Nurse*[nurses_number];
	for (int i = 0; i < nurses_number; i++)
	{
		nurse[i] = new Nurse(*(obj.nurse)[i]);
	}
	doctor = new Doctor*[doctors_number];
	for (int i = 0; i < doctors_number; i++)
	{
		doctor[i] = new Doctor(*(obj.doctor)[i]);
	}
}

CoronaDepartment::~CoronaDepartment()
{//delete all memory from department
	for (int i = 0; i < patient_number; i++)
	{
		delete patient[i];
	}
	delete[] patient;
	
	for (int i = 0; i < nurses_number; i++)
	{
		delete nurse[i];
	}
	delete[] nurse;

	for (int i = 0; i < doctors_number; i++)
	{
		delete doctor[i];
	}
	delete[] doctor;
}

void CoronaDepartment::addDoctor(Doctor* new_doc)
{
	Doctor** temp = doctor;
	doctors_number++;
	doctor = new Doctor*[doctors_number];
	for (int i = 0; i < doctors_number - 1; i++)
	{//add all old doctors
		doctor[i] = temp[i];
	}
	doctor[doctors_number - 1] = new_doc; //get the new doctor
	doctor[doctors_number - 1]->setHospital(hospital_name);//set his hospital name
	delete[] temp;
}

void CoronaDepartment::addNurse(Nurse* new_nurse)
{
	Nurse** temp = nurse;
	nurses_number++;
	nurse = new Nurse*[nurses_number];
	for (int i = 0; i < nurses_number; i++)
	{//add all old nurses
		nurse[i] = temp[i];
	}
	nurse[nurses_number - 1] = new_nurse; //add new nurse
	nurse[nurses_number - 1]->setHospital(hospital_name);//set her hospital name
	delete[] temp;
}

void CoronaDepartment::addPatient(Patient* new_patient)
{
	if (patient_number < 10)
	{//make sure there is no more then 10 patient in the department
		Patient** temp = patient;
		patient_number++;
		patient = new Patient*[patient_number];
		for (int i = 0; i < patient_number - 1; i++)
		{//add all old patient
			patient[i] = temp[i];
		}
		patient[patient_number - 1] = new_patient; //add new patient
		patient[patient_number - 1]->setHospital(hospital_name); //set his hospital name
		delete[] temp;
	}
	else
		cout << "\n~Sorry... every department is able to have maximum 10 patient~\n" << endl;
}

void CoronaDepartment::print()
{//print all department employee and number of patient
	cout << hospital_name << ":" << endl;
	cout << "\t~Dcotors~" << endl;
	for (int i = 0; i < doctors_number; i++)
	{
		cout << "Doctor ";
		doctor[i]->print();
	}
	cout << "\n\t~Nurses~" << endl;
	for (int i = 0; i < nurses_number; i++)
	{
		cout << "Nurse ";
		nurse[i]->print();
	}
	cout << "\nPatients number: " << patient_number << endl;
}

void CoronaDepartment::releasePatient(string id)
{
	for (int i = 0; i < patient_number; i++)
	{//run on all patients
		if (patient[i]->getId() == id)
		{//catch the patient with this id
			Patient** temp = patient; //copy address
			patient = new Patient*[--patient_number];	//allocate less 1 patient number
			for (int j = 0, k = 0; k < patient_number; j++)
			{
				if (temp[j] != temp[i])
				{//copy all patient except the patient with this id
					patient[k++] = temp[j];
				}
			}
			delete temp[i];
			delete[] temp;
		}
	}
}

ostream & operator<<(ostream& output, const CoronaDepartment& obj)
{//no use
	cout << "\n-----------------------------" << endl;
	cout << obj.hospital_name << ":\nWorkers:" << endl;
	cout << "\tDcotors" << endl;
	for (int i = 0; i < obj.doctors_number; i++)
	{
		cout << "Doctor ";
		obj.doctor[i]->print();
	}
	cout << "\n\n\tNurses" << endl;
	for (int i = 0; i < obj.nurses_number; i++)
	{
		cout << "Nurse ";
		obj.nurse[i]->print();
	}
	cout << "\n\nPatients number: " << obj.patient_number << endl;
	return output;
}//no use

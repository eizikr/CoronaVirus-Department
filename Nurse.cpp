#include "Nurse.h"

Nurse::Nurse(string f_name, string l_name, string _id, int _seniority, string h_name, int t_number) :Employee(f_name, l_name, _id, _seniority), hospital_name(h_name), trainings_number(t_number)
{
	this->setSalary(BASE_SALARY + (trainings_number * TRAINING_BONUS));
}

Nurse::Nurse(const Nurse& obj) : Employee(obj.first_name, obj.last_name, obj.id, obj.getSeniority()), hospital_name(obj.hospital_name), trainings_number(obj.trainings_number) {
	this->setSalary(obj.getSalary());
}

Nurse::~Nurse() {}

bool Nurse::is_Distinguished_Employee()
{//check if nurst is distinguished employee
	if (this->getSeniority() <= trainings_number)
		return true;
	return false;
}

void Nurse::print()
{
	Employee::print();//print name and id
	cout << "Hospital: " << hospital_name << endl;
	cout << "Trainings number: " << trainings_number << "\n" << endl;
}

void Nurse::updateSalery()
{//calculate salery and update it
	this->setSalary(BASE_SALARY + (trainings_number * TRAINING_BONUS));
}

istream& operator>>(istream& input, Nurse& obj)
{//get new details from user
	cout << "-Enter nurse details-\nFirst name:";
	getline(cin, obj.first_name);
	cout << "Last name:";
	getline(cin, obj.last_name);
	cout << "ID:";
	cin >> obj.id;
	cout << "Seniority:";
	cin >> obj.seniority;
	cout << "Trainings number:";
	cin >> obj.trainings_number;
	obj.updateSalery();
	return input;
}

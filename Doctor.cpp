#include "Doctor.h"

Doctor::Doctor(string f_name, string l_name, string _id, int _seniority, string h_name, bool is_a_prof, int _evaluations) :Employee(f_name, l_name, _id, _seniority), hospital_name(h_name), is_a_professor(is_a_prof), evaluations(_evaluations)
{//update salary
	if (is_a_professor)
		this->setSalary(BASE_SALARY + (SENIORITY_BONUS * this->getSeniority()) + (EVALUATIONS_BONUS * evaluations) + PROFESSOR_BONUS);
	else
		this->setSalary(BASE_SALARY + (SENIORITY_BONUS * this->getSeniority()) + (EVALUATIONS_BONUS * evaluations));
}

Doctor::Doctor(const Doctor& obj) : Employee(obj.first_name, obj.last_name, obj.id, obj.getSeniority()), hospital_name(obj.hospital_name), is_a_professor(obj.is_a_professor), evaluations(obj.evaluations)
{//copy salery
	this->setSalary(obj.getSalary());
}

Doctor::~Doctor(){}

bool Doctor::is_Distinguished_Employee()
{//check if doctor is distinguished
	if (evaluations > 10)
		return true;
	return false;
}

void Doctor::print()
{
	Employee::print();//print name and id
	cout << "Rank: ";
	if (is_a_professor)
		cout << "Professor" << endl;
	else
		cout << "Doctor" << endl;
	cout << "Hospital: " << hospital_name << endl;
	cout << "Good evaluations: " << evaluations << "\n" << endl;
}

void Doctor::updateSalery()
{//calculate the salery and update it
	if (is_a_professor)
		this->setSalary(BASE_SALARY + (SENIORITY_BONUS * this->getSeniority()) + (EVALUATIONS_BONUS * evaluations) + PROFESSOR_BONUS);
	else
		this->setSalary(BASE_SALARY + (SENIORITY_BONUS * this->getSeniority()) + (EVALUATIONS_BONUS * evaluations));
}

istream& operator>>(istream& input, Doctor& obj)
{//get new details from user
	cout << "-Enter doctor details-\nFirst name:";
	getline(cin, obj.first_name); 
	cout << "Last name:";
	getline(cin, obj.last_name);
	cout << "ID:";
	cin >> obj.id;
	cout << "Seniority:";
	cin >> obj.seniority;
	cout << "He is a professor?(1-yes/0-no):";
	cin >> obj.is_a_professor;
	cout << "Evaluations:";
	cin >> obj.evaluations;
	obj.updateSalery();
	return input;
}
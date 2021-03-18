#include "Patient.h"

Patient::Patient(string f_name, string l_name, string _id, string h_name, int c_tests, int n_tests) :Human(f_name, l_name, _id), hospital_name(h_name), corona_tests(c_tests), negative_tests(n_tests){}

Patient::Patient(const Patient& obj) : Human(obj.first_name, obj.last_name, obj.id), hospital_name(obj.hospital_name), corona_tests(obj.corona_tests), negative_tests(obj.negative_tests){}

Patient::~Patient(){}

void Patient::print()
{
	Human::print();//print name and id
	cout << "Tests number: " << corona_tests << endl;
	cout << "Negative tests: " << negative_tests << "\n" << endl;
}

istream & operator>>(istream& input, Patient& obj)
{//get new details from user
	cout << "\n-Enter patient details-\nFirst name:";
	getline(cin, obj.first_name);
	cout << "Last name:";
	getline(cin, obj.last_name);
	cout << "ID:";
	cin >> obj.id;
	cout << "Corona tests:";
	cin >> obj.corona_tests;
	cout << "Negative tests:";
	cin >> obj.negative_tests;
	while (obj.negative_tests > obj.corona_tests)
	{
		cout << "Patient cant have more negative tests then tests!" << endl;
		cout << "Negative tests: ";
		cin >> obj.negative_tests;
	}
	return input;
}

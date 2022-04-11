#include <string>

#include "Student.h"

Student::Student()
{
	this->name = "null";
	this->id = -1;
	this->birthday = "null";
	this->sex = 'x';
	this->homeAddress = "null";
}

Student::Student(int id, string name, char sex, string birthday, string homeAddress)
{
	this->id = id;
	this->name = name;
	this->sex = sex;
	this->birthday = birthday;
	this->homeAddress = homeAddress;
}

Student::Student(const Student &rhs) // copy constructor
{
    id = rhs.id;
    name = rhs.name;
    sex = rhs.sex;
    birthday = rhs.birthday;
    homeAddress = rhs.homeAddress;
}

void Student::print() const
{
    cout << "ID: " << id << "\nName: " << name << "\nSex: " << sex
         << "\nBirthday: " << birthday << "\nHomeAddress: " << homeAddress;
}



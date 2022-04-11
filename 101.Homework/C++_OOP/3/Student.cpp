#include <string>
#include <iostream>

#include "Student.h"


Student::Student(int id, string name, char sex, string birthday, string homeAddress)
    : id(id), name(name), sex(sex), birthday(birthday), homeAddress(homeAddress) {}

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



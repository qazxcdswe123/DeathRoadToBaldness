#include <string>
#include <iostream>

#include "Student.h"

using namespace std;

Studnet::Student(int id, string name, char sex, string birthday, string homeAddress)
    : id(id), name(name), sex(sex), birthday(birthday), homeAddress(homeAddress) {}

Student::Student(const Student &rhs)
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

Student Student::create()
{
    int id, string name, char sex, string birthday, string homeAddress;
    cout << "Please Input Your ID: ";
    cin >> id;
    cout << "Please Input Your Name: ";
    cin >> name;
    cout << "Please Input Your Gender: ";
    cin >> sex;
    cout << "Please Input Your Birthday: ";
    cin >> birthday;
    cout << "Please Input Your HomeAddress: ";
    cin >> homeAddress;
    Student(id, name, sex, birthday, homeAddress);
}
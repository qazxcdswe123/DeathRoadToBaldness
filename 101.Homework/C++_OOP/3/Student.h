/* 1. 设计一个学校在册人员类(Person)。
数据成员包括身份证号(IdPerson)、姓名(Name)、性别(Sex)、生日(Birth-day)和家庭住址(HomeAddress)。
成员函数包括人员信息的录入和显示，还包括构造函数与复制构造函数。设计一个合适的初始值。
*/
#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student
{
private:
    int id;
    string name;
    char sex;
    string birthday;
    string homeAddress;

public:
    Student(int id = -1, string name = "ERROR", char sex = '?', string birthday = "NULL", string homeAddress = "NULL");
    ~Student();
    Student(const Student &s);
    void print();
    Student create();
};

#endif // STUDENT_H
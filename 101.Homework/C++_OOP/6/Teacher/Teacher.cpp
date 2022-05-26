#include "Teacher.h"

Teacher::Teacher(int classPerMonth)
{
    this->classPerMonth = classPerMonth;
}
int Teacher::getClassPerMonth() const { return classPerMonth; }

int Professor::baseSalary = 5000;
int Professor::salaryPerClass = 50;
Professor::Professor(int classPerMonth, int baseSalary, int salaryPerClass) : Teacher(classPerMonth)
{
    this->baseSalary = baseSalary;
    this->salaryPerClass = salaryPerClass;
}
int Professor::getTotalSalary() const
{
    return baseSalary + salaryPerClass * getClassPerMonth();
}

int AssociateProfessor::baseSalary = 3000;
int AssociateProfessor::salaryPerClass = 30;
AssociateProfessor::AssociateProfessor(int classPerMonth, int baseSalary, int salaryPerClass) : Teacher(classPerMonth)
{
    this->baseSalary = baseSalary;
    this->salaryPerClass = salaryPerClass;
}
int AssociateProfessor::getTotalSalary() const
{
    return baseSalary + salaryPerClass * getClassPerMonth();
}

int Lecturer::baseSalary = 2000;
int Lecturer::salaryPerClass = 20;
Lecturer::Lecturer(int classPerMonth, int baseSalary, int salaryPerClass) : Teacher(classPerMonth)
{
    this->baseSalary = baseSalary;
    this->salaryPerClass = salaryPerClass;
}
int Lecturer::getTotalSalary() const
{
    return baseSalary + salaryPerClass * getClassPerMonth();
}

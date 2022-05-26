#include "Teacher.h"

Teacher::Teacher(int classPerMonth, int salary) : classPerMonth(classPerMonth), salary(salary) {}

int Professor::baseSalary = 5000;
int Professor::salaryPerClass = 50;
Professor::Professor(int classPerMonth, int salary) : Teacher(classPerMonth, salary) {}

int AssociateProfessor::baseSalary = 3000;
int AssociateProfessor::salaryPerClass = 30;
AssociateProfessor::AssociateProfessor(int classPerMonth, int salary) : Teacher(classPerMonth, salary) {}

int Lecturer::baseSalary = 2000;
int Lecturer::salaryPerClass = 20;
Lecturer::Lecturer(int classPerMonth, int salary) : Teacher(classPerMonth, salary) {}
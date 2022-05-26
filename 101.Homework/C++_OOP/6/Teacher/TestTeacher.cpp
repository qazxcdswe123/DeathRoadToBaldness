#include "Teacher.h"
#include <iostream>

int main(void)
{
    Professor professor(10, 5000, 50);
    std::cout << "Professor's salary: " << professor.getTotalSalary() << std::endl;
    AssociateProfessor associateProfessor(10, 3000, 30);
    std::cout << "AssociateProfessor's salary: " << associateProfessor.getTotalSalary() << std::endl;
    Lecturer lecturer(10, 2000, 20);
    std::cout << "Lecturer's salary: " << lecturer.getTotalSalary() << std::endl;
}
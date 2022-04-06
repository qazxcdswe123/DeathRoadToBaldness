#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int time;
    double salaryPerHour, salary;
    cout << "Gime the work time and salary per hour: ";
    cin >> time >> salaryPerHour;
    salary = salaryPerHour * time * 0.9;
    cout << "The salary after tax is: " << salary << '\n';
}
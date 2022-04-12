#include "CStaff.h"

int CStaff::m_Count = 0;

int CStaff::GetCount()
{
	return m_Count;
}

void CStaff::Display()
{
	cout << "The ID is " << m_ID << endl;
	cout << "The Name is " << m_Name << endl;
	cout << "The Salary is " << m_Salary << endl;
	cout << "The total number of staff is: " << GetCount() << endl;
}

CStaff::CStaff(int ID, int Salary, string Name)
{
	m_ID = ID;
	m_Salary = Salary;
	m_Name = Name;
	m_Count++;
}



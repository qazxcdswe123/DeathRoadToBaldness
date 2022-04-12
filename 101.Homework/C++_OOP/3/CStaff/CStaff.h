#include <iostream>
#include <string>

using namespace std;

class CStaff {
private:
	int m_ID;
	int m_Salary;
	string m_Name;
	static int m_Count;
public:
	CStaff(int ID, int Salary, string Name);
	void Display();
	static int GetCount();
};


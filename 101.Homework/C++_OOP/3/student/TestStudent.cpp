#include "Student.h"

int main()
{
	Student s1; // default value
    Student s2(1, "Tom", 'M', "1999-01-01", "Beijing"); // parameterized value
    Student s3(s2); // copy constructor
    s1.print();
	cout << endl;
    s2.print();
	cout << endl;
    s3.print();
}

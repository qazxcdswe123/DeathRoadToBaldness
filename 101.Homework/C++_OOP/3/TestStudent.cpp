#include "Student.h"

int main()
{
    Student s1;
    Student s2(1, "Tom", 'M', "1999-01-01", "Beijing");
    Student s3(s2);
    s1.print();
    s2.print();
    s3.print();
    Student s4;
    s4.create();
    s4.print();
    return 0;
}
#include <iostream>

using namespace std;

class Student
{
public:
    Student(int n, char s, string nam) : num(n), sex(s), name(nam) {}
    // {
    //     strcpy(name, nam);
    // }

private:
    int num;
    char sex;
    string name;
};

int main()
{
    Student stud1(10100, 'c', "Wang_li");
}
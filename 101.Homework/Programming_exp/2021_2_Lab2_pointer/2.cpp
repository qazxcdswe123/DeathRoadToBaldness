/*用传指针参数的方式，对一个一维数组进行操作，包括查找查找、排序、插入、删除操作，
数组的每个元素为学生信息，包含学号、姓名、性别、年龄。*/

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    int id;
    string name;
    char gender;
    int age;

    Student() = default;
    Student(int inputID, int inputAge, char inputGender, string inputName)
    {
        id = inputID;
        age = inputAge;
        gender = inputGender;
        name = inputName;
    }
};

void printStudentArray(Student *studentArray, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "Student " << i << "\n Name:" << studentArray[i].name << "\n ID: "
             << studentArray[i].id << "\n Gender:" << studentArray[i].gender << "\n Age:"
             << studentArray[i].age << endl;
    }
    cout << endl;
}

// find over id

bool Find(Student *studentArray, int id)
{
    for (int i = 0; i < 5; i++)
    {
        if (studentArray[i].id = id)
        {
            return true;
        }
    }
    return false;
}

// delete over id
void delete_student(Student *studentArray, int id)
{
    for (int i = 0; i < 5; i++)
    {
        if (studentArray[i].id = id)
        {
            studentArray[i] = studentArray[i + 1];
        }
    }
}

// 插入通过 Class constructer 实现
void insert_student(Student *studentArray, int position, int id, int age, char gender, string name)
{
    Student student_1(id, age, gender, name);
    studentArray[position] = student_1;
}

void insertionSort_over_id(Student *studentArray)
{
    for (int i = 1; i < 5; i++)
    {
        int j = i - 1;
        int key = studentArray[i].id;
        Student temp = studentArray[i];
        while (j >= 0 && studentArray[j].id > key)
        {
            studentArray[j + 1] = studentArray[j];
            j--;
        }
        studentArray[j + 1] = temp;
    }
}

int main(void)
{
    Student studentArray[5];
    insert_student(studentArray, 0, 10, 18, 'M', "Tom");
    insert_student(studentArray, 1, 2, 19, 'M', "Jack");
    insert_student(studentArray, 2, 3, 20, 'F', "Lucy");
    insert_student(studentArray, 3, 41, 21, 'F', "Lily");
    insert_student(studentArray, 4, 5, 22, 'M', "Jerry");

    cout << "Before sort:" << endl;
    printStudentArray(studentArray, 5);
    insertionSort_over_id(studentArray);
    cout << "After sort:" << endl;
    printStudentArray(studentArray, 5);
    if (Find(studentArray, 2))
    {
        cout << "Find success" << endl;
    }
    else
    {
        cout << "Find fail" << endl;
    }
}
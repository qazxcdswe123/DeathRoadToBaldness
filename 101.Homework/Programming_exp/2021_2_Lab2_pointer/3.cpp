/* 用指针实现一个链表，并对链表执行查找、排序、插入、删除操作。
指针节点为学生信息，包含学号、姓名、性别、年龄。*/

#include <iostream>
#include <string>

using namespace std;

class Student
{
public:
    int id;
    int age;
    string name;
    char gender;
    Student *next;

    Student()
    {
        id = 0;
        age = 0;
        name = "default";
        gender = 'M';
        Student *next = nullptr;
    }
    Student(int inputID, int inputAge, char inputGender, string inputName)
    {
        id = inputID;
        age = inputAge;
        gender = inputGender;
        name = inputName;
        Student *next = nullptr;
    }
};

class Student_linked_list
{
    Student *head;

public:
    Student_linked_list()
    {
        head = nullptr;
    }

    void insertStudentTail(int, int, char, string);

    bool findStudent(int);

    void printLinkedList();

    void deleteStudent(int);

    void sortLinkedListByID();
};

void Student_linked_list::deleteStudent(int id)
{
    Student *p = head;
    Student *q = head;
    while (p != nullptr)
    {
        if (p->id == id)
        {
            if (p == head)
            {
                head = p->next;
                delete p;
                return;
            }
            else
            {
                q->next = p->next;
                delete p;
                return;
            }
        }
        q = p;
        p = p->next;
    }
}

bool Student_linked_list::findStudent(int id)
{
    Student *p = head;
    while (p != nullptr)
    {
        if (p->id == id)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void Student_linked_list::insertStudentTail(int inputID, int inputAge, char inputGender, string inputName)
{
    Student *p = new Student(inputID, inputAge, inputGender, inputName);
    if (head == nullptr)
    {
        head = p;
        return;
    }
    Student *q = head;
    while (q->next != nullptr)
    {
        q = q->next;
    }
    q->next = p;
}

void Student_linked_list::printLinkedList()
{
    Student *p = head;
    if (head == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }

    while (p != nullptr)
    {
        cout << "id: " << p->id << " age: " << p->age << " name: " << p->name << " gender: " << p->gender << endl;
        p = p->next;
    }
}

void Student_linked_list::sortLinkedListByID()
{
    // sort linked list via selection sort
    if (head == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }
    Student *current_sorting = head;
    Student *min_find = head;
    Student *q = head;
    while (current_sorting != nullptr)
    {
        while (q != nullptr) // use q to find the min value
        {
            if (q->id < min_find->id)
            {
                min_find = q;
            }
            q = q->next;
        }
        if (min_find != current_sorting)
        {
            int tempID = current_sorting->id;
            int tempAge = current_sorting->age;
            char tempGender = current_sorting->gender;
            string tempName = current_sorting->name;

            current_sorting->id = min_find->id;
            current_sorting->age = min_find->age;
            current_sorting->gender = min_find->gender;
            current_sorting->name = min_find->name;

            min_find->id = tempID;
            min_find->age = tempAge;
            min_find->gender = tempGender;
            min_find->name = tempName;
        }
        if (current_sorting != nullptr)
        {
            current_sorting = current_sorting->next;
        }

        q = current_sorting;
        min_find = current_sorting;
    }
}

int main()
{
    Student_linked_list list;
    // insert 5 students
    list.insertStudentTail(1, 20, 'M', "Tom");
    list.insertStudentTail(4, 21, 'M', "Jack");
    list.insertStudentTail(3, 22, 'F', "Mary");
    list.insertStudentTail(2, 23, 'F', "Lily");
    list.insertStudentTail(5, 24, 'M', "Jerry");

    // print students
    list.printLinkedList();

    // delete student with id = 3
    list.deleteStudent(3);

    // print students
    cout << endl;
    list.printLinkedList();

    // find student
    if (list.findStudent(4))
    {
        cout << endl
             << "Student Found!" << endl;
    }

    // sort students by id
    list.sortLinkedListByID();

    // print students
    cout << endl;
    list.printLinkedList();
}
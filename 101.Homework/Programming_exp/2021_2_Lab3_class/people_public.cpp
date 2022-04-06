#include <iostream>

using namespace std;

class people_public
{
public:
    int age;
    double height;
    double weight;
    people_public(int age, double height, double weight);
    ~people_public();
    void eat();
    void sleep();
    void sport();
    void print();
};

people_public::people_public(int age, double height, double weight)
    : age(age), height(height), weight(weight)
{
}

void people_public::print()
{
    cout << "age: " << age << endl;
    cout << "height: " << height << endl;
    cout << "weight: " << weight << endl;
}

people_public::~people_public()
{
}

void people_public::sleep()
{
    age += 1;
    height += 1;
    weight += 1;
    cout << "sleep" << endl;
}

void people_public::eat()
{
    weight += 1;
    cout << "eat" << endl;
}

void people_public::sport()
{
    height += 1;
    cout << "sport" << endl;
}

int main()
{
    people_public p1(20, 1.8, 60);
    p1.print();
    p1.eat();
    p1.sleep();
    p1.sport();
    p1.print();
    return 0;
}
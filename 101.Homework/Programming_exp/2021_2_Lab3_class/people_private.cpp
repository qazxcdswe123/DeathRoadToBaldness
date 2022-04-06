#include <iostream>

using namespace std;

class people_private
{
private:
    int age;
    double weight;
    double height;

public:
    people_private(int age, double height, double weight);
    ~people_private();
    void eat();
    void sleep();
    void sport();
    void growth();
    void print();
};

people_private::people_private(int age, double height, double weight)
    : age(age), height(height), weight(weight)
{
}

people_private::~people_private()
{
}

void people_private::print()
{
    cout << "age: " << age << endl;
    cout << "height: " << height << endl;
    cout << "weight: " << weight << endl;
}

void people_private::growth()
{
    sleep();
    eat();
    sport();
    cout << "growth" << endl;
}

void people_private::sleep()
{
    age += 1;
    height += 1;
    weight += 1;
    cout << "sleep" << endl;
}

void people_private::eat()
{
    weight += 1;
    cout << "eat" << endl;
}

void people_private::sport()
{
    height += 1;
    cout << "sport" << endl;
}

int main()
{
    people_private p1(20, 1.8, 60);
    p1.print();
    p1.eat();
    p1.sleep();
    p1.sport();
    p1.growth();
    p1.print();
    return 0;
}
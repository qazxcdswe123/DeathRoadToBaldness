#include <iostream>

using namespace std;

struct people_struct
{
    int age;
    double height;
    double weight;
};

void print(struct people_struct *p)
{
    cout << "age: " << p->age << endl;
    cout << "height: " << p->height << endl;
    cout << "weight: " << p->weight << endl;
}

void sleep(struct people_struct *p)
{
    p->age += 1;
    p->height += 1;
    p->weight += 1;
    cout << "sleep" << endl;
}

void eat(struct people_struct *p)
{
    p->weight += 1;
    cout << "eat" << endl;
}

void sport(struct people_struct *p)
{
    p->height += 1;
    cout << "sport" << endl;
}

void growth(struct people_struct *p)
{
    p->age += 1;
    p->height += 1;
    p->weight += 1;
    cout << "growth" << endl;
}

int main()
{
    struct people_struct p;
    p.age = 20;
    p.height = 170;
    p.weight = 60;
    print(&p);
    sleep(&p);
    eat(&p);
    sport(&p);
    growth(&p);
    print(&p);
    return 0;
}
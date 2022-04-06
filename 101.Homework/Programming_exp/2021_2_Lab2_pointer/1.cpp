#include <iostream>
using namespace std;

int main()
{
    int a = 15, b = 20, t;
    int *p1 = &a, *p2 = &b, *pt;
    int &p3 = a, &p4 = b;
    cout << *p1 << '\t' << *p2 << endl;
    t = *p1;
    *p1 = *p2;
    *p2 = t;
    cout << *p1 << '\t' << *p2 << endl;
    pt = p1;
    p1 = p2;
    p2 = pt;
    cout << *p1 << '\t' << *p2 << endl;
    cout << *(&a) << '\t' << *(&b) << endl;
    cout << p3 << '\t' << p4 << endl;
    t = *(&p3);
    *(&p3) = *(&p4);
    *(&p4) = t;
    cout << a << '\t' << b << endl;
}
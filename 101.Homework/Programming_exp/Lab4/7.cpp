#include <iostream>
using namespace std;
void increment();

int main()
{
    increment();
    increment();
    increment();
}
void increment()
{
    int x = 0;
    x += 1;
    cout << x;
}

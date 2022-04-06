#include <iostream>
using namespace std;
int max(int, int);
int main()
{
    int a = 1, b = 2, c;
    c = max(a, b);
    cout << "max is " << c << endl;
}
int max(int x, int y)
{
    int z;
    z = (x > y) ? x : y;
    return (z);
}

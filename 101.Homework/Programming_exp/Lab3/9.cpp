#include <iostream>
using namespace std;

int main(void)
{
    int a, b, s, t;
    cout << "Intput a b: ";
    cin >> a >> b;
    s = t = 1;
    if (a > 0)
    {
        s = s + 1;
    }
    if (a > b)
    {
        t = t + s;
    }
    else if (a == b)
    {
        t = 5;
    }
    else
    {
        t = 2 * s;
    }
    cout << "t = " << t << endl;
}
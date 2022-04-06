#include <iostream>
using namespace std;
int power(int y, int n);

int main()
{
    int x = 1, n = 1, s;
    s = power(x, n);
    cout << s;
}

int power(int y, int n)
{
    int i, p = 1;
    for (i = 1; i <= n; i++)
        p = p * y;
    return p;
}

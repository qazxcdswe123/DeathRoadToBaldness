#include <iostream>
using namespace std;
int main()
{
    int a, e[10], c, i = 0;
    cout << "输入一整数";
    cin >> a;
    while (a != 0)
    {
        c = a % 2;
        a = a / 2;
        e[i] = c;
        i++;
    }
    for (; i > 0; i--)
        cout << e[i - 1];
}

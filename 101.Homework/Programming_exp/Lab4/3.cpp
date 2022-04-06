#include <iostream>
using namespace std;
int main()
{
    int hcf(int, int);      /*说明最大公约数 hcf函数*/
    int lcd(int, int, int); /*说明lcd 函数*/
    int m, n, h, l;
    cout << "please input m,n:";
    cin >> m >> n;
    h = hcf(m, n);
    cout << "H.C.F=" << h << endl;
    l = lcd(m, n, h);
    cout << "L.C.D=" << l << endl;
}

int hcf(int m, int n) /*定义求最大公约数的函数*/
{
    int t, r;
    if (n > m)
    {
        t = n;
        n = m;
        m = t;
    }
    while ((r = m % n) != 0)
    {
        m = n;
        n = r;
    }
    return (n);
}

int lcd(int m, int n, int h) /*定义求最小公倍数函数*/
{
    return (m * n / h);
}

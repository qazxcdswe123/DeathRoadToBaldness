#include <iostream>
using namespace std;
int h, l; /*定义全局变量*/
int main()
{
    void hcf(int, int); /*说明 hcf 函数*/
    void lcd(int, int); /*说明 lcd函数*/
    int m, n;
    cout << "please input m,n:";
    cin >> m >> n;
    hcf(m, n);
    lcd(m, n);
    cout << "H.C.F=" << h << endl;
    cout << "L.C.D=" << l << endl;
}

void hcf(int m, int n) /*定义求最大公约数的函数*/
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
    h = n;
}

void lcd(int m, int n) /*定义求最小公倍数函数*/
{
    l = m * n / h;
}
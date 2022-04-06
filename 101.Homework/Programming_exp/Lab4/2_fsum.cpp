#include <iostream>
using namespace std;
int main()
{
    int facsum(int); /*函数原型*/
    int m, n, s = 0;
    cout << "qinmishudui:\n";
    for (m = 2; m <= 500; m++)
    {
        n = facsum(m); /*函数调用*/
        if ((m == facsum(n)) && (m <= n))
            cout << "[" << m << "," << n << "]" << endl; /*按要求输出亲密数对*/
        if (n == m)
            s = s + m;
    }
    cout << "wanshuzihe:" << s << "\n";
}

int facsum(int m1) /*函数定义facsum，求m的所有因子之和*/
{
    int f = 1, k;
    for (k = 2; k <= m1 / 2; k++)
    {
        if (m1 % k == 0)
        {
            f = f + k;
        }
    }
    return f;
}

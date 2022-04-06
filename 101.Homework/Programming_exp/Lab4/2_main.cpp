#include <iostream>
#include "2_myheader.h"
using namespace std;
int facsum(int n);
int main()
{
    int m, n, s = 0;
    cout << "qinmishudui:\n";
    for (n = 2; n <= 500; n++)
    {
        m = facsum(n); /*函数调用*/
        if ((n == facsum(m)) && (n <= m))
            cout << "[" << n << "," << m << "]\n"; //输出亲密数对
        if (m == n)
            s = s + n;
    }
    cout << "wanshuzihe:" << s << endl; /*按要求输出完数之和*/
}

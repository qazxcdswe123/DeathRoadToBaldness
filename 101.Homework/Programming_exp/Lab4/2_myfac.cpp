#include <iostream>
#include "2_myheader.h"

using namespace std;
int facsum(int n) /*定义函数 facsum，求 n 的所有因子之和*/
{
    int f = 1, k;
    for (k = 2; k <= n / 2; k++)
    {
        if (n % k == 0)
            f = f + k;
    }
    return f;
}
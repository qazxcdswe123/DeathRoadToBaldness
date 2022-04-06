#include <iostream>
using namespace std;

int main()
{
    int sum, evenSum, oddSum;
    for (int i = 1; i <= 100; i++)
    {
        sum += i;
        if (i % 2 == 1)
            oddSum += i;
        else
            evenSum += i;
    }
    cout << "1-100之和：" << sum << '\n'
         << "1-100偶数之和：" << evenSum << '\n'
         << "1-100奇数之和:" << oddSum << endl;
}
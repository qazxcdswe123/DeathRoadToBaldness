#include <iostream>
using namespace std;

int main()
{
    int sum = 0;
    for (int i = 1; i <= 7; i++)
    {
        if (i % 2 == 0)
        {
            sum += i;
        }
    }
    cout << "小于等于7的自然数中的偶数之和为：" << sum << endl;
}
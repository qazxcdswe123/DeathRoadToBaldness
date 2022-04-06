// 找出所有各位数字之和为15的三位数, 并统计这样的三位数的个数
#include <iostream>
using namespace std;

int main()
{
    int count = 0;
    for (int i = 100; i <= 999; i++)
    {
        int a = i / 100;
        int b = i / 10 % 10;
        int c = i % 10;
        if (a + b + c == 15)
        {
            count++;
            cout << i << endl;
        }
    }
    cout << "There are " << count << " numbers." << endl;
    return 0;
}
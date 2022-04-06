#include <iostream>
using namespace std;

int main()
{
    int x, sum = 0;
    cout << "请输入数字：";
    cin >> x;
    if (x == 0)
    {
        sum = 1;
    }
    while (x != 0)
    {
        x /= 10;
        sum++;
    }
    cout << "位数：" << sum << endl;
}
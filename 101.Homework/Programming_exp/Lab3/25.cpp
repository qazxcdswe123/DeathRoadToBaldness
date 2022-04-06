#include <iostream>
using namespace std;

int main()
{
    int x, flag = 0;
    cout << "请输入要判断的数 ";
    cin >> x;
    for (int i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "这个数不是素数" << endl;
    }
    else
    {
        cout << "这个数是素数" << endl;
    }
}
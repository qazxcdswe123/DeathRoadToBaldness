#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "请输入n: ";
    cin >> n;
    cout << "符合条件的结果有：" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 10 == 3)
        {
            cout << i << ' ';
        }
    }
}
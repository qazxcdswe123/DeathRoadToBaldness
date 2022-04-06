#include <iostream>
using namespace std;

int main()
{
    double r, c, s;
    char ch;

    cout << "请输入半径：";
    cin >> r;
    cout << "请输入类型：";
    cin >> ch;
    c = 3.14 * r * 2;
    s = 3.14 * r * r;
    switch (ch)
    {
    case 'C':
    {
        cout << "周长为：" << c << endl;
        break;
    }
    case 'A':
    {
        cout << "面积为：" << s << endl;
        break;
    }
    case 'B':
    {
        cout << "周长为：" << c << " 面积为：" << s << endl;
        break;
    }
    }
}

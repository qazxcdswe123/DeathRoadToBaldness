#include <iostream>
using namespace std;

int main()
{
    int a, b, sum;
    char ch;
    cout << "两门课的成绩：";
    cin >> a >> b;
    if (a > 100 || b > 100)
    {
        cout << "成绩有误";
    }
    else
    {
        sum = a + b;
        if (sum >= 180)
        {
            ch = 'A';
        }
        else if (sum >= 160)
        {
            ch = 'B';
        }
        else if (sum >= 140)
        {
            ch = 'C';
        }
        else if (sum >= 120)
        {
            ch = 'D';
        }
        else
        {
            ch = 'E';
        }
        cout << sum << "---->" << ch;
    }
}
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            int a = i * 10 + 2, b = 70 + j;
            if (a * b == 3848)
            {
                cout << a << '*' << b << '=' << "3848" << endl;
            }
        }
    }
}
#include <iostream>
using namespace std;

int main(void)
{
    for (int i = 1; i <= 3; i++)
    {
        int x = 3 - i + 1;
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        for (int j = 7 - 2 * x; j >= 1; j--)
        {
            cout << '*';
        }
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= 7; i++)
    {
        cout << '*';
    }
    cout << endl;
    for (int i = 1; i <= 3; i++)
    {
        int x = i;
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        for (int j = 7 - 2 * x; j >= 1; j--)
        {
            cout << '*';
        }
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;

int main()
{
    for (int i = 1; i <= 6; i++)
    {
        int x = i - 1;
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        for (int j = 11 - 2 * x; j >= 1; j--)
        {
            cout << 'M';
        }
        for (int j = 1; j <= x; j++)
        {
            cout << ' ';
        }
        cout << endl;
    }
}
#include <iostream>
using namespace std;
int main(void)
{
    for (int i = 1; i <= 6; i++)
    {
        double a, b, c;
        cout << "input a, b, c: ";
        cin >> a >> b >> c;
        if ((a > b) || (a > c))
        {
            if (b < c)
            {
                cout << "min=" << b << '\n';
            }
            else
            {
                cout << "min=" << c << '\n';
            }
        }
        if ((a < b) && (a < c))
        {
            cout << "min=" << a << endl;
        }
    }
}
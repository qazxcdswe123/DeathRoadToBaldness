#include <iostream>
using namespace std;
int main()
{
    int a = 1, b = 2, c = 3;
    cout << "a=" << a << "\t"
         << "b=" << b << "\t"
         << "c=" << c << endl;
    {
        int b = 4, c = 5;
        cout << "a=" << a << "\t"
             << "b=" << b << "\t"
             << "c=" << c << endl;
        a = b;
        {
            int c = b;
            cout << "a=" << a << "\t"
                 << "b=" << b << "\t"
                 << "c=" << c << endl;
        }
        cout << "a=" << a << "\t"
             << "b=" << b << "\t"
             << "c=" << c << endl;
    }
    cout << "a=" << a << "\t"
         << "b=" << b << "\t"
         << "c=" << c << endl;
}

#include <iostream>
using namespace std;

bool isSingleDigit(int x)
{
    return (x >= 0 && x < 10);
}

int main()
{
    cout << isSingleDigit(2) << endl;
    if (isSingleDigit(2))
    {
        cout << "x is little" << endl;
    }
    else
    {
        cout << "x is big" << endl;
    }
    return EXIT_SUCCESS;
}


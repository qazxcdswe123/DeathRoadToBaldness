#include <iostream>

using namespace std;

int main()
{
    int x = -1;
    int b = 1;

    // Some code
    cout << "Before try \n";
    try
    {
        cout << "Inside try \n";
        if (b > x)
        {
            b -= x;
        }
        else
        {
            throw x;
            cout << "After throw (Never executed) \n";
        }
    }
    catch (int x)
    {
        cout << "Exception Caught \n";
    }

    cout << b;
    return 0;
}

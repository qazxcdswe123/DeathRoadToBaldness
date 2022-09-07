#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

bool isEven(int n)
{
    return (n & 1) == 0;
}

// assuming b >= 0
int simpleMultiplyIterative(int a, int b)
{
    int res = 0;
    int multiplier = 1;
    while (b != 0)
    {
        if (isEven(b))
        {
            multiplier *= 2;
            b /= 2;
        }
        else
        {
            res += a * multiplier;
            multiplier *= 2;
            b /= 2;
        }
    }
    return res;
}

int main()
{
    // use bitwise operators to check if there is only a 1 in the binary representation of the number
    int notPowerOfTwo = 3;
    int powerOfTwo = 4;

    cout << isPowerOfTwo(notPowerOfTwo) << endl;
    cout << isPowerOfTwo(powerOfTwo) << endl;

    cout << isEven(notPowerOfTwo) << endl;
    cout << isEven(powerOfTwo) << endl;

    cout << simpleMultiplyIterative(-2, 3) << endl;
}
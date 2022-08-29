#include <iostream>

using namespace std;

bool isPowerOfTwo(int n)
{
    return (n & (n - 1)) == 0;
}

int main()
{
    // use bitwise operators to check if there is only a 1 in the binary representation of the number
    int notPowerOfTwo = 3;
    int powerOfTwo = 4;

    cout << isPowerOfTwo(notPowerOfTwo) << endl;
    cout << isPowerOfTwo(powerOfTwo) << endl;
}
#include <iostream>
using namespace std;

// a function to find if the number is prime or not
bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// a function to prove goldbach's theorem
void goldbach(int n)
{
    for (int i = 2; i <= n / 2; i++)
    {
        if (isPrime(i) && isPrime(n - i))
        {
            cout << n << " = " << i << " + " << n - i << endl;
            return;
        }
    }
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    goldbach(n);
    return 0;
}
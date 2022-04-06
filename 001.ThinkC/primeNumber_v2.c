#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num)
{
    if (num <= 1)
    {
        return false;
    }
    for (int i = 2; i < num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int num = 4;
    if (isPrime(num) == 0)
    {
        printf("%i is not a prime num.\n", num);
    }
    else if (isPrime(num) == 1)
    {
        printf("%i is a prime num.\n", num);
    }
}
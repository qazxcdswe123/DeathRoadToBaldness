#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int num)
{
    int half = num / 2;
    for (int i = 3; i < half; i++)
    {
        if (half % i == 0)
        {
            return true;
        }
    }
    return false;
}

int main(void)
{
    int num = 89;
    if (isPrime(num))
    {
        printf("%i is a prime num\n", num);
    }
    else
    {
        printf("%i is not a prime num\n", num);
    }
}
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool checkPerfectNumber(int num)
{
    int half = num / 2;
    int sum = 0;
    for (int i = 1; i <= half; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return true;
    }
    return false;
}

int main(void)
{
    for (int i = 1; i < 10000; i++)
    {
        if (checkPerfectNumber(i) == 1)
        {
            printf("%i\n", i);
        }
    }
}
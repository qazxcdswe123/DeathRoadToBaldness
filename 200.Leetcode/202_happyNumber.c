#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isHappy(int input)
{
    for (int i = 0; i < 100; i++)
    {
        int sum = 0;
        while (input != 0)
        {
            sum += (input % 10) * (input % 10);
            input /= 10;
        }
        input = sum;
        if (sum == 1)
        {
            return true;
        }
    }
    return false;
}

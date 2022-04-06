#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool canMeasureWater(int x, int y, int z)
{
    if (x + y < z)
    {
        return false;
    }
    else if (x + y == z)
    {
        return true;
    }
    else if (x > 2 * y)
    {
        for (int i = 1; x - i * y >= z; i++)
        {
            if (x - i * y == z)
            {
                return true;
            }
        }
        return false;
    }
    else if (x == 2 * y)
    {
        if (x == z || y == z)
        {
            return true;
        }
        return false;
    }
    else
    {
        for (int i = 1; (i + 1) * y - i * x <= z; i++)
        {
            if ((i + 1) * y - i * x == z)
            {
                return true;
            }
        }
        return false;
    }
}

int main(void)
{
    int num = canMeasureWater(5, 3, 4);
    printf("%i\n", num);
}

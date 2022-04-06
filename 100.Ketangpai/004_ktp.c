#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int gcd(int x, int y)
{
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

bool canMeasureWater(int x, int y, int z)
{
    if (x + y < z)
    {
        return false;
    }

    int k = gcd(x, y);
    return z % k == 0;
}

int main(void)
{
    printf("%i \n", canMeasureWater(3, 5, 4));
}

/* bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
    if (jug1Capacity + jug2Capacity < targetCapacity)
    {
        return false;
    }
    for (int a = -100; a < jug1Capacity + 1000; a++)
    {
        for (int b = -100; b < jug2Capacity + 1000; b++)
        {
            if (targetCapacity == a * jug1Capacity + b * jug2Capacity)
            {
                return true;
            }
        }
    }
    return false;
}
*/

/* bool canMeasureWater(int x, int y, int z)
{
    if (x + y < z)
    {
        return false;
    }

    for (int i = 1; i <= x && i <= y; i++)
    {
        if (x % i == 0 && y % i == 0)
        {
            ;
        }
    }
}
*/

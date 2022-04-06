#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int histogram(int x, int y)
{
    int count = 0;
    while (y != 0)
    {
        int temp = y;
        y = x % y;
        x = temp;
        count++;
    }
    return count;
}

int main(void)
{
    time_t t;
    srand((unsigned)time(&t));
    int count;
    int histo[25] = {0};
    for (int i = 0; i < 500000; i++)
    {
        int x = rand() % 50000;
        int y = rand() % 50000;
        if (x >= y)
        {
            count = histogram(x, y);
            histo[count]++;
        }
        else
        {
            count = histogram(y, x);
            histo[count]++;
        }
    }
    for (int i = 0; i < 25; i++)
    {
        printf("%i\t%i\n", i, histo[i]);
    }
}
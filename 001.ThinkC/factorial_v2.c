#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
    if (num < 0)
    {
        printf("Plz enter a positive number.\n");
        exit(0);
    }
    else if (num == 0)
    {
        printf("Specially, 0! = 1");
        exit(0);
    }
    else
    {
        int result = 1;
        for (int i = 1; i <= +num; i++)
        {
            result *= i;
        }
        return result;
    }
}

int main(void)
{
    int num;
    printf("Plz enter an integer: ");
    scanf("%i", &num);
    printf("%i! = %i", num, factorial(num));
}
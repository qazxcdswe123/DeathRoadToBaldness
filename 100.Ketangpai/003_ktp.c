#include <stdio.h>
#include <stdlib.h>

int iteration(int input)
{
    int result = 1;
    for (int i = 1; i <= input; i++)
    {
        result *= i;
    }
    return result;
}

int recursion(int input)
{
    if (input == 0)
    {
        return 1;
    }
    else
    {
        int result = input * recursion(input - 1);
        return result;
    }
}

int main(void)
{
    int input = 10;
    printf("%i! = %i\n", input, iteration(input));
    printf("%i! = %i\n", input, recursion(input));
}
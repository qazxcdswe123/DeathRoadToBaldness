#include <stdio.h>

int factorial_bad(int n)
{
    return n * factorial_bad(n - 1);
}

int factorial_recursize(int n)
{
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial_recursize(n - 1);
    }
}

int factorial_iteration(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Recursion: Factorial of %d is %d\n", n, factorial_recursize(n));
    printf("Iteration: Factorial of %d is %d\n", n, factorial_iteration(n));
    return 0;
}
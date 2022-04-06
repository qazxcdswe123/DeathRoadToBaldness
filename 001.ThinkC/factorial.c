#include <stdio.h>
#include <stdlib.h>

void factorial(int n)
{ 
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    printf("%i! = %i\n", n, result);
}

int numberCheck(int n)
{
    if (n < 0)
    {
        printf("The number can't be negetive number like %i\n", n);
        return EXIT_SUCCESS;
    }
    else if (n == 0)
    {
        printf("%i! = 1\n", n);
        return EXIT_SUCCESS;
    }
    else
    {
        return n;
    }
}

int userInput(void)
{
    int flag, n;
    printf("Enter an integer : ");
    flag = scanf("%i", &n);
    if (flag != 1)
    {
        printf("Plz enter a integer");
        exit(0);    
    }
    else
    {
        return n;
    }
}

int main(void)
{
    factorial(numberCheck(userInput()));
}
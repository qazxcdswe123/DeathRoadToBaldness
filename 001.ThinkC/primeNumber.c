#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{    
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            printf("%i is not a prime number\n", n);
            return EXIT_SUCCESS;                
        }
        else
        {
            printf("%i is a prime number\n", n);
            return EXIT_SUCCESS;
        }
    }
}

int numberCheck(int n)
{
    if (n <= 1)
    {
        printf("%i is not a prime number\n", n);
        return EXIT_FAILURE;
    }
    else
    {
        isPrime(n);
    }
}

int userInput(void)
{
    int flag, n;
    printf("Enter an integer : ");
    flag = scanf("%i", &n);
    if (flag != 1)
    {
        printf("Plz enter an integer");
        exit(0);    
    }
    else
    {
        numberCheck(n);
    }
}

int main(void)
{
    userInput();
}
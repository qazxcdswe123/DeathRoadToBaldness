#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char ch;
    int success, x;
    printf("Enter an interger: ");
    success = scanf("%i", &x);
    if (success == 1)
    {
        printf("Your input: %i\n", x);
        return EXIT_SUCCESS;
    }
    if (success != 1)
    {
        while (success != 1)
        {
            printf("That isn’t a number. \nPlease try again:");
            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                success = scanf("%i", &x);
            }
        }
        printf("Your input is: %i", x);
    }
}

// int main(void)
// {
//     // char ch;
//     // int success, x;
//     // printf("Enter an interger: ");
//     // success = scanf("%i", &x);
//     // if (success == 1)
//     int ch;
//     while ((ch = getchar()) != EOF)
//         printf("%c", ch);
// }
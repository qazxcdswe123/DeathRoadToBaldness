#include <stdio.h>
#include <stdlib.h>

void generateArray(int array[], int length, int upperBound)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % upperBound;
    }
}

int returnBigger(int array[], int length, int upperBound)
{
    int max = array[0];
    for (int i = 1; i < length; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void printArray(int array[], int length, int upperBound)
{
    for (int i = 0; i < length; i++)
    {
        printf("%i ", array[i]);
    }
}

int main(void)
{
    int array[20];
    int upperBound = 20;
    int length = sizeof(array) / sizeof(array[0]);
    int max;

    generateArray(array, length, upperBound);
    printArray(array, length, upperBound);
    max = returnBigger(array, length, upperBound);

    printf("\nThe biggest one in the array is %i.\n", max);
    return EXIT_SUCCESS;
}
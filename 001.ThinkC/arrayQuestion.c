#include <stdlib.h>
#include <stdio.h>

void generateArray(int array[], int length, int upperbound)
{
    for (int i = 0; i < length; i++)
    {
        array[i] = rand() % upperbound + 1;
    }
}

int multiplyElements(int array[], int length, int upperbound)
{
    int result = 1;
    int element;
    for (int i = 0; i < length; i++)
    {
        element = array[i];
        result = result * element;
    }
    return result;
}

int main(void)
{
    int array[20]; // int overflow
    int upperbound = 5;
    int length = sizeof(array) / sizeof(array[0]);

    generateArray(array, length, upperbound);
    printf("The final result is %i.", multiplyElements(array, length, upperbound));
}
#include <stdio.h>

int main(void)
{
    int age = 0;
    int *address = &age;
    *address = 37;
    printf("%d ", *address);
}
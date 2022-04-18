// #include <stdio.h>

// #define square(x) (x) * (x)

// int main(void)
// {
//     int i = 3;
//     printf("%d\n", square(++i));
//     return 0;
// }

#include <iostream>

using namespace std;

int main(void)
{
    int pi[10] = {65};
    char *pc = (char *)pi;
    cout << pc;
}
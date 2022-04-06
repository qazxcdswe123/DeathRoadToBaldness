#include <iostream>

int main()
{
    int cmp(int, int);
    std::cout << cmp(3, 4) << '\n';
}

int cmp(int x, int y)
{
    int a;
    if (x > y)
        a = 1;
    else if (x == y)
        a = 0;
    else
        a = -1;
    return a;
}

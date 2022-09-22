#include <iostream>

// calculate x^y mod m
int rec_mod_exp(int x, int y, int m)
{
    if (y == 0)
    {
        return 1;
    }
    int z = rec_mod_exp(x, y / 2, m);
    if ((y & 1) == 0)
    {
        return z * z % m;
    }
    else
    {
        return x * z * z % m;
    }
}

int main()
{
    int res = rec_mod_exp(7, 10, 11);
    std::cout << res << std::endl;
}
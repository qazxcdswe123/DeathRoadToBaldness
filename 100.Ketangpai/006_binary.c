#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isEven(int input)
{
    if (input % 2 == 0)
    {
        return true;
    }
    return false;
}

int power(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    int temp = power(base, exp / 2);
    if (exp % 2 == 0)
    {
        return temp * temp;
    }
    else
    {
        return base * temp * temp;
    }
}

int getBinLength(int input)
{
    int length = 0;
    if (input == 0)
    {
        length = 1;
    }

    while (input != 0)
    {
        input /= 2;
        length++;
    }
    return length;
}

int bin2dec(int input)
{
    int times = 0, dec = 0;
    while (input != 0)
    {
        if (isEven(input))
        {
            ;
        }
        else
        {
            dec += power(2, times);
        }
        times++;
        input /= 10;
    }
    return dec;
}

int dec2bin(int input)
{
    if (input == 0)
    {
        return 0;
    }
    int sum = 1;
    int length = getBinLength(input);
    return power(10, length - 1) + dec2bin(input - power(2, length - 1));
}

int binary_reverse(int input)
{
    int bin = dec2bin(input);
    int length = getBinLength(input);
    int res = 0;
    while (bin != 0)
    {
        if (isEven(bin))
        {
            ;
        }
        else
        {
            res += power(10, length - 1);
        }
        length--;
        bin /= 10;
    }
    return res;
}

int add(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return add(a ^ b, (a & b) << 1);
}

int mul(int a, int b)
{
    int res;
    if (b == 0)
    {
        return 0;
    }
    if (b == 1)
    {
        return a;
    }
    if (isEven(b))
    {
        res = mul(a, b >> 1) << 1;
        return res;
    }
    else
    {
        res = mul(a, b >> 1) << 1 + a;
    }
}

int main(void)
{
    printf("%i\n", mul(3, 8));
}
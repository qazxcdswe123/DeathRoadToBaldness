#include <iostream>
#include "15_headf.h"
using namespace std;

int calculation2()
{
    int s = 0;
    for (int i = 1; i < 10; i++)
    {
        s += factorial(i);
    }
    return s;
}
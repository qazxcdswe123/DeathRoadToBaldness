#include <iostream>
#include <cmath>

using namespace std;

int array[48] = {0};

int main()
{
    int n = 48;
    while (n)
    {
        int num1, num2, num3 = 0;
        cin >> num1 >> num2 >> num3;
        array[--n] = num1;
        array[--n] = num2;
        array[--n] = num3;
    }
    for (int i = 0; i < 16; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double d = 0;
        double min = 1000000;
        for (int j = 0; j < 3; j++)
        {
            d = sqrt(pow())
        }
        }
}
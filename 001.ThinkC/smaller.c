#include <stdio.h>
#include <stdlib.h>

double chooseSmallerOne(double x, double y)
{
    if (x > y)
    {
        return y;
    }
    else if (x == y)
    {
        printf("They are the same\n");
        exit(0);
    }
    else
    {
        return x;
    }
}

int main()
{
    double x, y; // or float with %f
    printf("Plz enter ur 1st number : ");
    scanf("%lf", &x);
    printf("Plz enter ur 2nd number : ");
    scanf("%lf", &y);
    double z = chooseSmallerOne(x, y);
    printf("The smaller one is %g\n", z);
}

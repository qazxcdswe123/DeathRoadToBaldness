#include <stdio.h>
typedef struct
{
    double x;
    double y;
} Point_t;

void printPoint(Point_t point)
{
    printf("(%0.1f, %0.1f)\n", point.x, point.y);
}

int main(void)
{
    Point_t blank = {3.0, 4.0};

    double x = blank.x;
    printf("%f\n", x);
    printPoint(blank);
}

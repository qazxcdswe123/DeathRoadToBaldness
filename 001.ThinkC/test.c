#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double x;
    double y;
} Point_t;

void reflectPoint(Point_t *ptr)
{
    double temp = ptr->x;
    ptr->x = ptr->y;
    ptr->y = temp;
}

int main(void)
{
    Point_t p1 = {0.1, 0.2};
    Point_t p2 = p1; // it works
    printf("%f, %f\n", p2.x, p2.y);
}

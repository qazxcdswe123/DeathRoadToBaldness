#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    // const float threehalfs = 1.5F;

    y = number;
    x2 = number * 0.5F;
    i = *(long *)&y;           // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1); // what the F?
    y = *(float *)&i;
    y = y * (1.5F - (x2 * y * y)); // 1st iteration
    // y = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

float normal_rsqrt(float number)
{
    float result = 1.0f / sqrt(number);
    return result;
}

int main(void)
{
    const unsigned int test_count = 100000;
    // benchmark both function with the same randomized input

    float number[100000];
    for (int i = 0; i < test_count; i++)
    {
        number[i] = (float)rand() / (float)(RAND_MAX / 100);
    }

    clock_t start = clock();
    for (unsigned int i = 0; i < test_count; i++)
    {
        float result = Q_rsqrt(number[i]);
    }
    clock_t end = clock();
    printf("Q_rsqrt: %f\n", (float)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (unsigned int i = 0; i < test_count; i++)
    {
        float result = normal_rsqrt(number[i]);
    }
    end = clock();
    printf("normal_rsqrt: %f\n", (float)(end - start) / CLOCKS_PER_SEC);
}
// the result is: 3 times slower than normal_rsqrt
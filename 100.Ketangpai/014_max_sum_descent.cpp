#include <iostream>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define side 4

using namespace std;

int input[4][4] = {{2, 0, 0, 0}, {5, 4, 0, 0}, {3, 4, 7, 0}, {1, 6, 9, 6}};

void dp(int layer, int table[side + 1][side + 1])
{
    if (layer > side - 1)
        return;

    for (int i = 1; i <= layer + 1; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            table[i][j] = MAX(table[i - 1][j - 1] + input[i - 1][j - 1], table[i - 1][j] + input[i - 1][j - 1]);
        }
    }
    layer++;
    dp(layer, table);
}

int main(void)
{
    int table[side + 1][side + 1] = {0};
    dp(0, table);
    for (int i = 1; i < side + 1; i++)
    {
        cout << table[side][i] << endl; // then find max in the last table
    }
    /* output
    11
    17
    22
    19
    */
}
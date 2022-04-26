#include <bits/stdc++.h>
int ma = 0;
char s[4][5];
int n;

using namespace std;

bool canPut(int row, int col);

void dfs(int index, int max)
{
    if (index == n * n)
    {
        if (max > ma)
        {
            ma = max;
            return;
        }
    }
    else
    {
        int row = index / n;
        int col = index % n;
        if (canPut(row, col) == true && s[row][col] == '.')
        {
            s[row][col] = 'O';
            dfs(index + 1, max + 1);
            s[row][col] = '.';
        }
        dfs(index + 1, max);
    }
}

bool canPut(int row, int col)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (s[i][col] == 'X')
        {
            break;
        }

        if (s[i][col] == 'O')
        {
            return false;
        }
    }

    for (int i = col - 1; i >= 0; i--)
    {
        if (s[row][i] == 'X')
        {
            break;
        }
        if (s[row][i] == 'O')
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    // freopen("input.in", "r", stdin);
    while (cin >> n && n != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                s[i][j] = '\0';
                cin >> s[i][j];
            }
        }
        ma = 0;
        dfs(0, 0);
        cout << ma << endl;
    }
}
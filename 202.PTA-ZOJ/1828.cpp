#include <bits/stdc++.h>

using namespace std;

int fb[6000][1000] = {0};

int main()
{
    int n;
    int len[6000];
    fb[1][0] = 1;
    fb[2][0] = 1;
    len[1] = 1;
    len[2] = 1;
    for (int i = 3; i < 6000; i++)
    {
        memcpy(fb[i], fb[i - 1], sizeof(fb[i - 1]));
        int tmpLen = max(len[i - 1], len[i - 2]);
        for (int k = 0; k < tmpLen; k++)
        {
            fb[i][k] += fb[i - 2][k];
        }
        for (int k = 0; k < tmpLen; k++)
        {
            if (fb[i][k] >= 10)
            {
                fb[i][k + 1]++;
                fb[i][k] %= 10;
            }
        }
        if (fb[i][tmpLen] != 0)
            tmpLen++;
        len[i] = tmpLen;
    }
    while (cin >> n)
    {
        for (int i = len[n] - 1; i >= 0; i--)
        {
            cout << fb[n][i];
        }
        cout << '\n';
    }
}

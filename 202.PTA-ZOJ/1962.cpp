#include <iostream>
#include <cstring>

using namespace std;

int cmpb(int len, int input[], int fb[][101], int lenOfFb[])
{
    for (int i = 0; i < 500; i++)
    {
        if (lenOfFb[i] < len)
        {
            continue;
        }
        else if (lenOfFb[i] == len)
        {
            int re = len - 1;
            while (re != -1)
            {
                if (fb[i][re] < input[re])
                {
                    break;
                }
                else if (fb[i][re] > input[re])
                {
                    return i;
                }
                re--;
            }
            if (re == -1)
            {
                return i + 1;
            }
        }
        else
            return i;
    }
}

int cmp(int len, int input[], int fb[][101], int lenOfFb[])
{
    for (int i = 0; i < 500; i++)
    {
        if (lenOfFb[i] < len)
        {
            continue;
        }
        else if (lenOfFb[i] == len)
        {
            int re = len - 1;
            while (re != -1)
            {
                if (fb[i][re] < input[re])
                {
                    break;
                }
                else if (fb[i][re] > input[re])
                {
                    return i;
                }
                re--;
            }
            if (re == -1)
            {
                return i;
            }
        }
        else
            return i;
    }
}

int main()
{
    // freopen("input.in", "r", stdin);
    char a[101], b[101];
    int ia[101], ib[101];
    while (cin >> a >> b)
    {
        int len1, len2;
        if (a[0] == '0' && b[0] == '0')
        {
            return 0;
        }
        len1 = strlen(a);
        len2 = strlen(b);
        for (int i = 0; i < len1; i++)
        {
            ia[len1 - i - 1] = a[i] - '0';
        }
        for (int i = 0; i < len2; i++)
        {
            ib[len2 - i - 1] = b[i] - '0';
        }

        int fb[500][101], lenOfFb[500], maxLen;
        memset(fb, 0, sizeof(fb));
        fb[0][0] = 1;
        fb[1][0] = 2;
        maxLen = lenOfFb[1] = lenOfFb[0] = 1;
        for (int i = 2; i < 500; i++)
        {
            for (int j = 0; j < maxLen; j++)
            {
                fb[i][j] = fb[i - 1][j] + fb[i - 2][j] + fb[i][j];
                if (fb[i][j] > 9)
                {
                    fb[i][j + 1] += 1;
                    fb[i][j] %= 10;
                }
            }
            if (fb[i][maxLen] != 0)
            {
                maxLen++;
            }
            lenOfFb[i] = maxLen;
        }
        int n1 = cmp(len1, ia, fb, lenOfFb);
        int n2 = cmpb(len2, ib, fb, lenOfFb);
        cout << (n2 - n1) << '\n';
        for (int i = 0; i < 101; i++)
        {
            a[i] = '\0';
            b[i] = '\0';
        }
    }
}
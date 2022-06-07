/*
You are to calculate Σik (1 <= i <= n).

Input:

There are multiple cases in the input.

Each case begins with two integer n and k (0 <= n <= 10^50, 1 <= k <= 100).

Output:

For each test, print the answer in a single line.

Sample Input:

2 3
3 2
Sample Output:

9
14
*/
#include <string>
#include <iostream>
#include <cstring>

using namespace std;
int inputNum[51];
int currentNum[51];
int tmp[2000];
int ans[2000];
int len;
int kk;
int lenOfCurrentNum = 1;

void power()
{
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < lenOfCurrentNum; i++)
    {
        for (int j = 0; j < lenOfCurrentNum; j++)
        {
            tmp[i + j] += currentNum[i] * currentNum[j];
        }
    }
    for (int i = 2; i < kk; i++)
    {
        for (int j = 0; j < lenOfCurrentNum; j++)
        {
            for (int k = 0; k < lenOfCurrentNum; k++)
            {
                tmp[j + k] += tmp[j] * currentNum[k];
            }
        }
    }

    for (int i = 0; i < 2 * lenOfCurrentNum; i++)
    {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
    }
}

void add()
{
    for (int i = 0; tmp[i] != 0; i++)
    {
        ans[i] += tmp[i];
        ans[i + 1] += ans[i] / 10;
        ans[i] %= 10;
    }
}

void addOneToCurrentNum()
{
    if (len == lenOfCurrentNum)
    {
        for (int i = 0; i < len; i++)
        {
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    string n, k;
    while (cin >> n >> k)
    {
        memset(currentNum, 0, sizeof(currentNum));
        memset(ans, 0, sizeof(ans));
        memset(inputNum, 0, sizeof(inputNum));
        len = n.length();
        kk = stoi(k);
        for (int i = 0; i < len; i++)
        {
            inputNum[i] = n[i] - '0';
        }

        while (lenOfCurrentNum <= len)
        {
            for (int i = 0; i < 10; i++)
            {
                currentNum[lenOfCurrentNum - 1] = i;
                power();
                add();
            }
            lenOfCurrentNum++;
        }
    }
}
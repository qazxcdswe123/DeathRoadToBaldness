#include <bits/stdc++.h>

using namespace std;

int n, m, sum, ways;
int cards[1001];

void dfs(int start)
{
    if (sum == n)
    {
        ways++;
        return;
    }
    else
    {
        for (int i = start; i <= n; i++)
        {
            if (cards[i] && sum + i <= n)
            {
                sum += i;
                cards[i]--;
                dfs(i);
                cards[i]++;
                sum -= i;
            }
        }
    }
}

int main()
{
    // freopen("input.in", "r", stdin);
    int value, num;
    bool flag = false;
    while (cin >> n >> m)
    {
        if (flag)
            cout << '\n';
        flag = true;
        memset(cards, 0, sizeof(cards));
        ways = sum = 0;
        while (m--)
        {
            cin >> value >> num;
            cards[value] = num;
        }
        dfs(1);
        cout << ways << '\n';
    }
}
#include <bits/stdc++.h>

using namespace std;

int n;
bool flag, vis[31];
int input[31];
int ans;

void dfs(int start, int len, int sum)
{
    if (len == 0) // base case
    {
        for (int i = start; i < n && sum >= input[i]; i++)
        {
            if (sum == input[i]) // have match
            {
                flag = true;
                for (int j = 0; j <= i; j++)
                {
                    if (vis[j])
                    {
                        if (sum == input[j])
                            cout << input[j] << "=" << input[i] << '\n';
                        else
                            cout << input[j] << "+";
                        sum -= input[j];
                    }
                }
            }
        }
    }
    else
    {
        for (int i = start; i < n; i++)
        {
            if (sum + input[i] <= input[n - 1])
            {
                sum += input[i];
                vis[i] = true;
                --len; // add i
                dfs(i + 1, len, sum);
                sum -= input[i];
                vis[i] = false;
                ++len;
            }
        }
    }
}

int main()
{
    freopen("input.in", "r", stdin);
    int N;
    cin >> N;
    while (N--)
    {
        cin >> n;
        flag = false;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            cin >> input[i];
        }
        sort(input, input + n);
        flag = false;
        for (int i = 2; i < n; i++)
        {
            dfs(0, i, 0);
        }
        if (!flag)
            cout << "Can't find any equations.\n\n";
        else
            cout << '\n';
    }
}
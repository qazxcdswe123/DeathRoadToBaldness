#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> g;
int n;

bool check(int x)
{
    int i, j, k, t1, t2;

    for (i = 0; i < n; i++)
    {
        if (i == x)
            continue;
        for (j = i + 1; j < n; j++)
        {
            if (j == x)
                continue;
            t1 = g[i] + g[j];
            for (k = j + 1; k < n; k++)
            {
                if (k == x)
                    continue;
                t2 = t1 + g[k];
                if (t2 == g[x])
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int i, t;
    freopen("input.in", "r", stdin);

    while (cin >> n && n)
    {
        g.clear();
        for (i = 0; i < n; i++)
        {
            cin >> t;
            g.push_back(t);
        }
        if (n < 4)
        {
            cout << "no solution" << endl;
            continue;
        }
        sort(g.begin(), g.end());
        for (i = n - 1; i >= 0; i--)
        {
            if (check(i))
            {
                cout << g[i] << endl;
                break;
            }
        }
        if (i == -1)
        {
            cout << "no solution" << endl;
        }
    }
    return 0;
}
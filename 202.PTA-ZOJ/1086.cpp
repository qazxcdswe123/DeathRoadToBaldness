#include <bits/stdc++.h>

using namespace std;

int main()
{
    // freopen("input.in", "r", stdin);
    string str;
    double ans;
    while (cin >> str)
    {
        ans = 0;
        int len = str.length();
        for (int i = 2; i < len; i++)
        {
            ans += (str[i] - '0') / pow(8, i - 1);
        }
        cout << str << " [8] = " << setprecision(3 * (len - 2)) << ans << " [10]" << '\n';
    }
}
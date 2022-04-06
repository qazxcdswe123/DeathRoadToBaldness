#include <bits/stdc++.h>
using namespace std;

// #define int long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        int num;
        cin >> num;
        v.clear();
        while (num)
        {
            int tmp = num % 2;
            v.push_back(tmp);
            num /= 2;
        }
        int flag = 1;
        int len = v.size();
        for (int i = 0; i < len; i++)
        {
            if (v[i] == 1 && flag)
            {
                flag = 0;
                cout << i;
            }
            else if (v[i] == 1)
            {
                cout << ' ' << i;
            }
        }
        cout << '\n';
    }
}
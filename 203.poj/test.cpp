#include <bits/stdc++.h>
using namespace std;

// #define int long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int i = 0;
    cin >> n;
    vector<string> name;
    string tmp;
    while (n--)
    {
        cin >> tmp;
        name.push_back(tmp);
    }
    cout << name.size();
    for (auto x : name)
    {
        cout << x;
    }
}
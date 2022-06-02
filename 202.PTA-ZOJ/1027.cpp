#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int matrix[5][5] = {
    {5, -1, -2, -1, -3},
    {-1, 5, -3, -2, -4},
    {-2, -3, 5, -2, -2},
    {-1, -2, -2, 5, -1},
    {-3, -4, -2, -1, -999999}};

int dp[101][101] = {0};

map<char, int> mp = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}, {'-', 4}};

int main()
{
    // freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    while (n--)
    {
        string s1;
        string s2;
        int len1, len2;
        cin >> len1 >> s1;
        cin >> len2 >> s2;
        for (int i = 1; i < len1; i++)
        {
            for (int j = 1; j < len2; j++)
            {
                dp[i][j] = max(dp[i - 1][j - 1] + matrix[mp[s1[j]]][mp[s2[j]]], dp[i - 1][j] + matrix)
            }
        }
    }
}
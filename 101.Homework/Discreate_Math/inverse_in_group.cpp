/*
Description

给定一张 n x n 的二元运算表 f, 其中 f_i,j 表示 ij = f_ij，问该二元运算是否构成群，如果是，输出每个数的逆元。


Input
第一行一个正整数 t ，表示数据组数。

每组数据第一行一个正整数 n ，表示表的大小。

接下来 n 行，每行 n 个整数，表示 f_i,j, 1 < f_i,j < n

Output
对于每组数据，如果不构成群，输出一行 "NO" ， 否则第一行输出 "YES"，第二行输出每个数的逆元。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isGroup(const vector<vector<int>> &v)
{
    bool hasIdentity = false;
    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // check identity
            if (!hasIdentity && v[i][j] == 1)
            {
                hasIdentity = true;
            }
            
            // check associativity
            for (int k = 0; k < n; k++)
            {
                if (v[i][v[j][k] - 1] != v[v[i][j] - 1][k])
                {
                    return false;
                }
            }
            
            // check inverse
            if (v[i][j] == 1 && v[j][i] != 1)
            {
                return false;
            }
        }
    }
    return hasIdentity;
}

vector<int> getInverse(const vector<vector<int>> &v)
{
    int n = v.size();
    vector<int> inverse(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1)
            {
                inverse[i] = j + 1;
                break;
            }
        }
    }
    return inverse;
}


int main()
{
    freopen("input.in", "r", stdin);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        
        if (!isGroup(v))
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            cout << "YES" << endl;
            vector<int> inverse = getInverse(v);
            for (int i = 0; i < n; i++)
            {
                cout << inverse[i] << " ";
            }
            cout << endl;
        }
    }
}
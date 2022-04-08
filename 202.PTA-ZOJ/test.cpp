#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, i;
    cin >> a >> b >> i;
    if ((i * b / a) / i == (double)b / (double)a)
        cout << "Yes" << endl;
}
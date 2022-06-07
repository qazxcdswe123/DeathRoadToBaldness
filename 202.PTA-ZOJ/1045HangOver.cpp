#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    double res = 0;
    int i;
    while (cin >> a)
    {
        if (a == 0)
        {
            break;
        }

        for (i = 2; res < a; i++)
        {
            res += 1.0 / i;
        }
        cout << i - 2 << " card(s)" << endl;
        res = 0;
    }
}

#include <iostream>
#include <algorithm>

using namespace std;

struct dna
{
    char s[51];
    int num;
} a[101];

bool bigger(dna x, dna y)
{
    return x.num < y.num;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int len, n;
    cin >> len >> n;
    for (int i = 0; i < n; i++)
    {
        int A, C, G, ans;
        A = C = G = ans = 0;
        cin >> a[i].s;
        for (int j = len - 1; j >= 0; j--)
        {
            if (a[i].s[j] == 'A')
            {
                A++;
            }
            else if (a[i].s[j] == 'C')
            {
                C++;
                ans += A;
            }
            else if (a[i].s[j] == 'G')
            {
                G++;
                ans += A + C;
            }
            else if (a[i].s[j] == 'T')
            {
                ans += A + C + G;
            }
        }
        a[i].num = ans;
    }
    stable_sort(a, a + n, bigger);
    for (size_t i = 0; i < n; i++)
    {
        cout << a[i].s << '\n';
    }
}
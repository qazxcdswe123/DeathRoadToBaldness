#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    while (getline(cin, s))
    {
        if (s[0] == '#')
        {
            break;
        }
        int l = s.length(), sum = 0;
        for (int i = 0; i < l; i++)
        {
            if (s[i] != ' ')
            {
                int t = (int)(s[i] - 'A') + 1;
                sum += (i + 1) * t;
            }
        }
        cout << sum << endl;
    }
}
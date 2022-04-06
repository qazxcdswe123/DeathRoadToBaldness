#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, string> dict;
    string input, a, b;
    int i = 0, length;
    getline(cin, input);
    while (input != "")
    {
        length = input.size();
        a = "";
        for (i = 0; i < length; i++)
        {
            if (input[i] == ' ')
                break;
            a += input[i];
        }
        i++;
        b = "";
        for (; i < length; i++)
            b += input[i];
        dict[b] = a;
        getline(cin, input);
    }
    while (getline(cin, input))
    {
        if (dict[input] != "")
            cout << dict[input] << "\n";
        else
            cout << "eh\n";
    }
}
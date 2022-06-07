#include <iostream>
#include <stack>

using namespace std;

int main()
{
    // freopen("input.in", "r", stdin);
    int n, i, count;
    int target[1000];
    stack<int> st;
    while (cin >> n && n != 0)
    {
        while (cin >> target[0] && target[0])
        {
            for (i = 1; i < n; i++)
            {
                cin >> target[i];
            }
            count = 1;
            i = 0;
            while (i < n)
            {
                if (count == target[i]) // in order
                {
                    count++;
                    i++;
                }
                else
                {
                    if (!st.empty() && st.top() == target[i])
                    {
                        st.pop();
                        i++;
                    }
                    else
                    {
                        if (count <= n) // add coaches to stack
                            st.push(count++);
                        else
                            break;
                    }
                }
            }
            if (i == n)
                cout << "Yes" << '\n';
            else
                cout << "No" << '\n';
            while (!st.empty())
                st.pop();
        }
        cout << '\n';
    }
}

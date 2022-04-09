#include <bits/stdc++.h>

using namespace std;

struct node
{
    int row;
    int col;
};

int main()
{
    int n;
    // freopen("input.in", "r", stdin);
    scanf("%i", &n);
    node list[26];
    int sum = 0;
    node n1, n2;
    char s[1000] = {'\0'};
    bool errorFlag;
    stack<node> st;


    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char tmp;
        scanf(" %c", &tmp);
        scanf("%i %i", &list[i].row, &list[i].col);
    }

    while (scanf("%s", s) != EOF)
    {
        errorFlag = false;
        if (s[1] == '\0')
        {
            printf("0\n");
        }
        else
        {
            int i = 0;
            while (s[i] != '\0')
            {
                if (s[i] == '(')
                {
                    i++;
                }
                else if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    n1 = list[s[i] - 'A'];
                    st.push(n1);
                    i++;
                }
                else
                {
                    n2 = st.top();
                    st.pop();
                    n1 = st.top();
                    st.pop();
                    if (n1.col != n2.row)
                    {
                        errorFlag = true;
                        break;
                    }
                    sum += n1.row * n1.col * n2.col;
                    n1.col = n2.col;
                    st.push(n1);
                    i++;
                }
            }
            if (errorFlag == true)
            {
                printf("error\n");
            }
            else
            {
                printf("%i\n", sum);
            }
            sum = 0;
            while (!st.empty())
            {
                st.pop();
            }
        }
    }
}

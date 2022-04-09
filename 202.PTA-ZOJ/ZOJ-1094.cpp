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
    freopen("input.in", "r", stdin);
    scanf("%i", &n);
    stack<node> st;
    node list[26]; 
    int sum = 0;
    node n1, n2;
    char s[1000] = {'\0'};

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char tmp;
        scanf("%c", &tmp);
        scanf("%i %i", &list[i].row, &list[i].col);
        getchar();
    }
    
    while (scanf("%s", s))
    {
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
                    n1 = st.top();
                    st.pop();
                    n2 = st.top();
                    st.pop();
                    if (n1.row != n2.col)
                    {
                        printf("error\n");
                        break;
                    }
                    sum += n1.row* n1.col * n2.col;
                    n1.col = n2.col;
                    st.push(n1);
                    i++;
                }
			}
            printf("%i\n", &sum);
            sum = 0;
		}
    }
    
}

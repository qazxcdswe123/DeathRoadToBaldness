#include <iostream>
#include <stack>

using namespace std;

int cnt = 1;
void calc(stack<bool> &num, char op)
{
    bool a, b;
    if (op == '!')
    {
        a = num.top();
        num.pop();
        num.push(!a);
    }
    else if (op == '|')
    {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a || b);
    }
    else if (op == '&')
    {
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a && b);
    }
}

int main()
{
    // freopen("input.in", "r", stdin);
    char input[101];
    for (int i = 0; i < 101; i++)
    {
        input[i] = '\0';
    }

    while (cin.getline(input, 101))
    {
        stack<char> op;
        stack<bool> num;
        for (int i = 0; input[i] != '\0'; i++)
        {
            char c = input[i];
            if (c == ' ')
                continue;
            else if (c == 'F' || c == 'V')
            {
                num.push(c == 'V');
                while (!op.empty() && op.top() == '!')
                {
                    char tmpOP = op.top();
                    op.pop();
                    calc(num, tmpOP);
                }
            }
            else if (c == '(' || c == '!')
            {
                op.push(c);
            }
            else if (c == ')')
            {
                while (op.top() != '(')
                {
                    char tmpOP = op.top();
                    op.pop();
                    calc(num, tmpOP);
                }
                op.pop(); // for (
                while (!op.empty() && op.top() == '!')
                {
                    char tmpOP = op.top();
                    op.pop();
                    calc(num, tmpOP);
                }
            }
            else if (c == '|')
            {
                while (!op.empty() && op.top() != '(') // reverse to (
                {
                    char tmpOP = op.top();
                    op.pop();
                    calc(num, tmpOP);
                }
                op.push(c);
            }
            else if (c == '&')
            {
                while (!op.empty() && op.top() != '(' && op.top() != '|')
                {
                    char tmpOP = op.top();
                    op.pop();
                    calc(num, tmpOP);
                }
                op.push(c);
            }
        }
        while (!op.empty())
        {
            char tmpOP = op.top();
            op.pop();
            calc(num, tmpOP);
        }
        char ans = num.top() ? 'V' : 'F';
        cout << "Expression " << cnt++ << ": " << ans << '\n';

        for (int i = 0; i < 101; i++)
        {
            input[i] = '\0';
        }
    }
}
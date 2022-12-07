#include "calculator.h"
#include <iostream>
#include <string>
#include <ctype.h>
#include <stack>

// change regular expression to reverse polish notation
int getPriority(char ch)
{
    switch (ch)
    {
    case '(':
        return 0;
    case '+':
        return 1;
    case '-':
        return 1;
    case '*':
        return 2;
    case '/':
        return 2;
    default: // for space
        return 3;
    }
}

string changeToRPN(string original)
{
    string rpn = "";
    std::stack<char> op_stack;
    int length = original.length();
    for (int i = 0; i < length; i++)
    {
        // if its negative, use 0 - num
        if ((original[i - 1] == '(' && original[i] == '-') || (i == 0 && original[i] == '-'))
        {
            rpn += "0 ";
            while (isdigit(original[++i]) || original[i] == '.')
            {
                rpn += original[i];
            }
            rpn += " -";
        }

        char ch = original[i];
        if (isdigit(ch) || ch == '.')
        {
            rpn += ch;
        }
        else if (ch == '(')
        {
            op_stack.push(ch);
        }
        else if (ch == ')')
        {
            while (!op_stack.empty() && op_stack.top() != '(')
            {
                rpn += ' ';
                rpn += op_stack.top();
                op_stack.pop();
            }
            op_stack.pop(); // pop (
        }
        else // + - * / and space
        {
            if (ch == ' ' && rpn.back() != ' ')
            {
                rpn += ' ';
            }

            if (op_stack.empty())
            {
                if (ch == ' ')
                {
                    continue;
                }
                op_stack.push(ch);
            }
            else
            {
                // not empty and lower priority
                // pop until found bigger priority
                while (!op_stack.empty() && getPriority(ch) <= getPriority(op_stack.top()))
                {
                    rpn += op_stack.top();
                    op_stack.pop();
                }
                if (ch == ' ')
                {
                    continue;
                }
                op_stack.push(ch);
            }
        }
    }

    while (!op_stack.empty())
    {
        if (op_stack.top() != '(')
        {
            rpn += ' ';
            rpn += op_stack.top();
        }
        op_stack.pop();
    }
    return rpn;
}
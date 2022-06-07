/*
You have typed the report of your term project in your personal computer. There are several one line arithmetic expressions in your report. There is no redundant parentheses in the expressions (omitting a pair of redundant matching parentheses does not change the value of the expression). In your absence, your little brother inserts some redundant matching parentheses in the expressions of your report. Assume that the expressions remain syntactically correct and evaluate to their original value (the value before inserting redundant parentheses). To restore your report to its original form, you are to write a program to omit all redundant parentheses.

To make life easier, consider the following simplifying assumptions:

1. The input file contains a number of expressions, each in one separate line.

2. Variables in the expressions are only single uppercase letters.

3. Operators in the expressions are only binary '+' and binary '-'.

Note that the only transformation allowed is omission of redundant parentheses, and no algebraic simplification is allowed.


Input

The input file consists of several test cases. The first line of the file contains a single number M, which is the number of test cases (1 <= M <= 10). Each of the following M lines, is exactly one correct expression. There may be arbitrarily space characters in each line. The length of each line (including spaces) is at most 255 characters.


Output

The output for each test case is the same expression without redundant parentheses. Notice that the order of operands in an input expression and its corresponding output should be the same. Each output expression must be on a separate line. Space characters should be omitted in the output expressions.


Sample Input

3
(A-B + C) - (A+(B - C)) - (C-(D- E) )
((A)-( (B)))
A-(B+C)


Sample Output

A-B+C-(A+B-C)-(C-(D-E))
A-B
A-(B+C)
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <cctype>
#include <vector>

using namespace std;

// char st[256] = {'\0'};

int main()
{
    freopen("input.in", "r", stdin);
    int n;
    cin >> n;
    n++;
    while (n--)
    {
        char s[256] = {'\0'};
        cin.getline(s, 256);
        vector<char> ss;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] != ' ')
                ss.push_back(s[i]);
        }

        stack<int> parenIndex;
        for (int i = 0; i < ss.size(); i++)
        {
            if (ss[i] == '(')
                parenIndex.push(i);
            else if (ss[i] == ')')
            {
                int j = parenIndex.top();
                parenIndex.pop();
                if (j == 0)
                {
                    ss[j] = ' ';
                    ss[i] = ' ';
                }
                else
                {
                    if (ss[j - 1] != '-')
                    {
                        ss[j] = ' ';
                        ss[i] = ' ';
                    }
                    else if (ss[j - 1] == '-')
                    {
                        vector<char> v; // store upper case letters
                        for (int k = j + 1; k < i; k++)
                        {
                            if (isupper(ss[k]))
                                v.push_back(ss[k]);
                        }
                        bool haveNoSameFlag = false;
                        for (int k = j; k < i; k++)
                        {
                            for (int kk = k; kk < i; kk++)
                            {
                                if (ss[kk] != ss[k] && isupper(ss[kk]) && isupper(ss[k]))
                                {
                                    haveNoSameFlag = true;
                                    break;
                                }
                            }
                        }
                        if (!haveNoSameFlag)
                        {
                            ss[j] = ' ';
                            ss[i] = ' ';
                        }
                    }
                }
            }
        }
        // vector<char> ans;
        for (auto &&i : ss)
        {
            if (i != ' ')
                cout << i;
        }
        cout << '\n';
        // for (auto &&i : ans)
        // {
        //     cout << i;
        // }
        // if (n)
        //     cout << '\n';
    }
}
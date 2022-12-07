#include "calculator.h"
#include <iostream>
#include <string>
#include <stack>
#include <cmath>

// calculate using reverse polish notation
// sample input: 0 9.9 - 10 *
// sample input: 0 0.9999 - 1 +

double calculate(string rpn)
{
    std::stack<double> double_stack;
    string input = changeToRPN(rpn);
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (isdigit(input[i])) // there was no .9 so must have a digit before .
        {
            double num = 0;
            while (isdigit(input[i]) || input[i] == '.')
            {
                if (isdigit(input[i]))
                {
                    num = num * 10 + input[i] - '0';
                    i++;
                }
                else if (input[i] == '.')
                {
                    int scale = -1;             // 小数位数
                    while (isdigit(input[++i])) // after .
                    {
                        num += pow(10, scale) * (input[i] - '0');
                        scale--;
                    }
                }
            }
            double_stack.push(num);
        }
        else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
        {
            double num1 = double_stack.top();
            double_stack.pop();
            double num2 = double_stack.top();
            double_stack.pop();
            switch (input[i])
            {
            case '+':
                double_stack.push(num2 + num1);
                break;
            case '-':
                double_stack.push(num2 - num1);
                break;
            case '*':
                double_stack.push(num2 * num1);
                break;
            case '/':
                double_stack.push(num2 / num1);
                break;
            }
        }
    }
    return double_stack.top();
}
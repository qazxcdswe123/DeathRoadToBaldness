#include "calculator.h"
#include <iostream>
#include <string>

// check if the input expression has paired parentheses or invalid characters
bool checkUserInput(string input)
{
    int parentheses = 0;
    bool have_operator = false;
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        if (input[i] == '(')
        {
            parentheses++;
        }
        else if (input[i] == ')')
        {
            parentheses--;
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '(' || input[i] == ')' || input[i] == ' ')
        {
            if ((i == 0 && input[i] == '-') || input[i] == ' ') // negative first number case & space
            {
                continue;
            }
            else // have at least one operator
            {
                have_operator = true;
            }
        }
        else if (isdigit(input[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    if (parentheses == 0 || have_operator)
    {
        return true;
    }
    else
    {
        return false;
    }
}
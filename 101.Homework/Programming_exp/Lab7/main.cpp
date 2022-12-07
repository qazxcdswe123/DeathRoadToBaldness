#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

int main(void)
{
    bool stopFlag = false;

    while (!stopFlag)
    {
        cout << "Please input the expression: ";
        string expression;
        getline(cin, expression);
        if (expression == "quit")
        {
            stopFlag = true;
        }
        else
        {
            if (checkUserInput(expression))
            {
                double result = calculate(expression);
                if (isinf(result)) // check if inf (overflow)
                {
                    cout << "Invalid input!" << endl;
                }
                else
                {
                    print_like_LCD(result);
                    cout << "Type 'quit' to exit." << endl;
                }
            }
            else
            {
                cout << "Invalid input!" << endl;
                return -1;
            }
        }
    }
}
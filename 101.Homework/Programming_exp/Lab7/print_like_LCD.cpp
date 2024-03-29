#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

/*   1
   2   3
     4
   5   6
     7
*/

// [0-9][7 position]
const int array[10][7] = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1},
};

void print_first_layer(string str, int length, bool is_negative)
{
    int i = 0;
    if (is_negative)
    {
        std::cout << "  ";
        i++;
    }

    for (; i < length; i++)
    {
        int num = str[i] - '0';
        if (str[i] == '.')
        {
            std::cout << "  ";
            continue;
        }
        if (array[num][0])
        {
            std::cout << " _  "; // one extra space at the end
        }
        else
        {
            std::cout << "    ";
        }
    }
    std::cout << endl;
}

void print_second_layer(string str, int length, bool is_negative)
{
    int i = 0;
    if (is_negative)
    {
        std::cout << "_ ";
        i++;
    }

    for (; i < length; i++)
    {
        if (str[i] == '.')
        {
            std::cout << "  ";
            continue;
        }

        int num = str[i] - '0';
        if (array[num][1])
        {
            std::cout << "|";
        }
        else
        {
            std::cout << " ";
        }

        if (array[num][3])
        {
            std::cout << "_";
        }
        else
        {
            std::cout << " ";
        }

        if (array[num][2])
        {
            std::cout << "| ";
        }
        else
        {
            std::cout << "  ";
        }
    }
    std::cout << endl;
}

void print_third_layer(string str, int length, bool is_negative)
{
    int i = 0;
    if (is_negative)
    {
        std::cout << "  ";
        i++;
    }

    for (; i < length; i++)
    {
        if (str[i] == '.')
        {
            std::cout << ". ";
            continue;
        }

        int num = str[i] - '0';
        if (array[num][4])
        {
            std::cout << "|";
        }
        else
        {
            std::cout << " ";
        }

        if (array[num][6])
        {
            std::cout << "_";
        }
        else
        {
            std::cout << " ";
        }

        if (array[num][5])
        {
            std::cout << "| ";
        }
        else
        {
            std::cout << "  ";
        }
    }
    std::cout << endl;
}

void print_like_LCD(double num)
{
    num = ceil(num * 100) / 100;
    // to string contain trailing zeros
    string str = to_string(num);
    str.erase(str.find_last_not_of('0') + 1, string::npos);
    // add 00 if dot is the last element
    if (str.back() == '.')
    {
        str += "00";
    }
    bool is_negative = false;
    if (str[0] == '-')
    {
        is_negative = true;
    }

    int length = str.length();
    print_first_layer(str, length, is_negative);
    print_second_layer(str, length, is_negative);
    print_third_layer(str, length, is_negative);
}
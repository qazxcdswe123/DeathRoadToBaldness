#include <iostream>
using namespace std;

int InsertPositionInArray(int array[], int value, int length)
{
    int left = 0, right = length - 1, position;

    // find the position using binary search
    while (left <= right)
    {
        position = left + (right - left) / 2;
        if (array[position] >= value && array[position - 1] <= value)
        {
            break;
        }
        else if (array[position] < value)
        {
            left = position + 1;
        }
        else
        {
            right = position - 1;
        }
    }
    return position;
}

int PositionInDecreasingArray(int array[], int value, int length)
{
    int left = 0, right = length - 1, position;

    // find the position using binary search
    while (left <= right)
    {
        position = left + (right - left) / 2;
        if (array[position] == value)
        {
            break;
        }
        else if (array[position] > value)
        {
            left = position + 1;
        }
        else
        {
            right = position - 1;
        }
    }
    return position;
}

void InsertionInAnSortedArray(int array[], int value, int length)
{
    int position = InsertPositionInArray(array, value, length);
    // insert the value in the position
    // assuing the array is 4 bytes larger
    for (int i = length - 1; i > position; i--)
    {
        array[i] = array[i - 1];
    }
    array[position] = value;
}

void PrintArray(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

void SaddlePointInTwoDimensionalArray(int twoDimesionalArray[3][4], int row, int column)
{

    int maxInRow[row] = {0}, minInColumn[column] = {0};

    // find the max and min in each row and column
    for (int i = 0; i < row; i++)
    {
        int pivot = twoDimesionalArray[i][0];
        for (int j = 0; j < column; j++)
        {
            if (twoDimesionalArray[i][j] > pivot)
            {
                pivot = twoDimesionalArray[i][j];
            }
        }
        maxInRow[i] = pivot;
    }

    for (int i = 0; i < column; i++)
    {
        int pivot = twoDimesionalArray[0][i];
        for (int j = 0; j < row; j++)
        {
            if (twoDimesionalArray[j][i] < pivot)
            {
                pivot = twoDimesionalArray[j][i];
            }
        }
        minInColumn[i] = pivot;
    }

    // print the saddle point
    // throw a null if not found
    int hasSaddlePoint = 0;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (twoDimesionalArray[i][j] == maxInRow[i] && twoDimesionalArray[i][j] == minInColumn[j])
            {
                cout << "(" << i << "," << j << ")" << endl;
                hasSaddlePoint = 1;
            }
        }
    }
    if (hasSaddlePoint == 0)
    {
        cout << "null" << endl;
    }
}

char FirstNonRepeatingCharacter(string str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    // Check input
    if (length == 1 || length == 0)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (str[i] == str[j])
            {
                break;
            }
            else if (j == length - 1)
            {
                return str[i];
            }
        }
    }

    // if no non repeating character
    cout << "null" << endl;
    return 0;
}

bool IsPalindrome(string str)
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }

    // Check input
    if (length == 1 || length == 0)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }

    // check if the string is a palindrome
    for (int i = 0; i < length / 2; i++)
    {
        if (str[i] != str[length - i - 1])
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    int array[10] = {1, 2, 3, 4, 5, 11, 18, 19, 20};
    int value = 5;
    int length = sizeof(array) / sizeof(array[0]);
    PrintArray(array, length);
    InsertionInAnSortedArray(array, value, length);
    PrintArray(array, length);

    cout << "-------------------------" << endl;
    int twoDimensionalArray[3][4] = {{9, 80, 205, 40}, {90, 60, 96, 1}, {210, 3, 101, 89}};
    int row = sizeof(twoDimensionalArray) / sizeof(twoDimensionalArray[0]);
    int column = sizeof(twoDimensionalArray[0]) / sizeof(twoDimensionalArray[0][0]);
    SaddlePointInTwoDimensionalArray(twoDimensionalArray, row, column);

    cout << "-------------------------" << endl;
    int decreasingArray[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}; // 怎么会有人用降序数组啊...
    int lenghtOfDecreasingArray = sizeof(decreasingArray) / sizeof(decreasingArray[0]);
    int position = PositionInDecreasingArray(decreasingArray, value, lenghtOfDecreasingArray); // value = 5
    cout << "The position of " << value << " in the decreasing array is " << position << " (Starting from 0)" << endl;

    cout << "-------------------------" << endl;
    string str = "abcabd";
    char c = FirstNonRepeatingCharacter(str);
    cout << c << endl;

    cout << "-------------------------" << endl;
    string str2 = "abcdedcba";
    bool isPalindrome = IsPalindrome(str2);
    if (isPalindrome)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
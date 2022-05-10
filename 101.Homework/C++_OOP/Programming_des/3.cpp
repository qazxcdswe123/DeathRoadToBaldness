#include <iostream>
#include <cmath>
using namespace std;

// a function to find how many times a digit appears in a number
int findDigit(int num, int digit)
{
    int count = 0;
    while (num > 0)
    {
        if (num % 10 == digit)
        {
            count++;
        }
        num /= 10;
    }
    return count;
}

// a function to find if the number is prime or not
bool isPrime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

// a function to validate the Goldbach's conjecture
void goldbach(int n)
{
    if (n % 2 == 1 || n < 6)
    {
        cout << "Goldbach's conjecture is not applicable in this case" << endl;
        // 其实应该是 < 4 || < 2的，按题目要求吧。。
        return;
    }

    for (int i = 2; i <= n / 2; i++)
    {
        if (isPrime(i) && isPrime(n - i))
        {
            cout << n << " = " << i << " + " << n - i << endl;
            return;
        }
    }
}

// a recursive function to find the sum of squares of all the numbers from 1 to n
int sumOfSquares(int n)
{
    if (n == 1)
        return 1;
    return n * n + sumOfSquares(n - 1);
}

// a recursive function to calculate the given equaltion
double equaltion(double x, int n)
{
    if (n == 1)
        return sqrt(1 + x);
    return sqrt(equaltion(sqrt(x + n - 1), n - 1) + n);
}

// given the date(YYYYMMDD)
// return how many days have passed since the first day of the year
int daysPassed(int date)
{
    int length = log10(date) + 1;
    if (length != 8)
    {
        cout << "Invalid Input!\n";
        return -1;
    }

    int year = date / 10000;
    int month = (date % 10000) / 100;
    int day = date % 100;
    int days = 0;
    for (int i = 1; i < month; i++)
    {
        if (i == 2)
        {
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
                days += 29;
            else
                days += 28;
        }
        else if (i == 4 || i == 6 || i == 9 || i == 11)
            days += 30;
        else
            days += 31;
    }
    days += day;
    return days;
}

// given how many days have passed in a year
// print the date(YYYYMMDD)
void printDate(int year, int days)
{
    if (days <= 0)
    {
        cout << "Invalid Input\n";
    }

    int month;
    for (month = 1; days > 0; month++)
    {
        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0 || year % 400 == 0) && days > 29)
                days -= 29;
            else if (days > 28)
                days -= 28;
            else
                break;
        }
        else if ((month == 4 || month == 6 || month == 9 || month == 11) && days > 30)
            days -= 30;
        else if (days > 31)
            days -= 31;
        else
            break;
    }
    // print out
    cout << year;
    if (month < 10)
        cout << '0' << month;
    else
        cout << month;
    if (days < 10)
        cout << '0' << days << endl;
    else
        cout << days << endl;
}

int main(void)
{
    int count = findDigit(114514, 1);
    cout << count << endl;
    cout << "----------------" << endl;

    goldbach(6);
    cout << "----------------" << endl;

    double res = equaltion(4.2, 10);
    printf("%.2f\n", res);
    cout << "----------------" << endl;

    int days = daysPassed(20200229);
    cout << days << endl;
    cout << "----------------" << endl;

    printDate(2020, 52);
}
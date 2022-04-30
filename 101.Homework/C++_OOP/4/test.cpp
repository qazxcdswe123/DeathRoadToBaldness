#include <iostream>

using namespace std;

int main()
{
    int seconds = 1651226715;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int second = seconds % 60;
    seconds -= second;

    int minite = seconds / 60 % 60;
    seconds -= minite * 60;

    int hour = seconds / 3600 % 12;
    seconds -= hour * 3600;

    int month = 1, day = 1;
    int year = 1970;

    auto isLeapYear = [](int year)
    {
        return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
    }; // lambda expreesion
    int secondsInYear = 31536000;
    int secondsInLeapYear = 31622400;
    while (seconds >= secondsInYear)
    {
        if (isLeapYear(year))
        {
            seconds -= secondsInLeapYear;
        }
        else
        {
            seconds -= secondsInYear;
        }
        ++year;
    }

    if (isLeapYear(year))
    {
        daysInMonth[1] = 29; // Feb
    }
    int secondsInDay = 86400;
    for (int i = 0; seconds > daysInMonth[i] * secondsInDay; i++)
    {
        month++;
        seconds -= daysInMonth[i] * secondsInDay;
    }
    day += seconds / 86400;
    cout << year << endl;
    cout << month << endl;
    cout << day << endl;
    cout << hour << endl;
    cout << minite << endl;
    cout << second << endl;
}

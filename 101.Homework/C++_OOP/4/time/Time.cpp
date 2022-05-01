#include <stdexcept>
#include <iomanip>

#include "Time.h"

Time::Time(int ss)
{
    this->second = ss;
}

Time &Time::operator++()
{
    ++second;
    return *this;
}

const Time Time::operator++(int dummy)
{
    Time old(*this);
    ++second;
    return old;
}

Time &Time::operator--()
{
    try
    {
        if (second > 0)
        {
            --second;
        }
        else
        {
            throw std::invalid_argument("Error: Current Time can not be negative");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return *this;
}

const Time Time::operator--(int dummy)
{
    Time old(*this);
    try
    {
        if (second > 0)
        {
            --second;
        }
        else
        {
            throw std::invalid_argument("Error: Current Time can not be negative");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return old;
}

Time &Time::operator+=(const Time &other)
{
    second += other.second;
    return *this;
}

Time &Time::operator-=(const Time &other)
{
    try
    {
        if (second >= other.second)
        {
            this->second -= other.second;
        }
        else
        {
            throw std::invalid_argument("Error: Current Time can not be negative");
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return *this;
}

int operator-(const Time &t1, const Time &t2)
{
    int diff = abs(t1.second - t2.second);
    return diff;
}

std::ostream &operator<<(std::ostream &os, const Time &t)
{
    // Unix timestamp
    // GMT + 0
    int seconds = t.second;
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int second = t.second % 60;
    seconds -= second;

    int minite = t.second / 60 % 60;
    seconds -= minite * 60;

    int hour = t.second / 3600 % 12;
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

    // ISO 8601
    os << year << '-' << std::setw(2) << std::setfill('0') << month << '-' << std::setw(2) << day << ' ' << std::setw(2) << hour << ':' << std::setw(2) << minite << ':' << std::setw(2) << second;
    return os;
}

bool operator>(const Time &t1, const Time &t2)
{
    return (t1.second > t2.second);
}
bool operator>=(const Time &t1, const Time &t2)
{
    return (t1.second >= t2.second);
}
bool operator==(const Time &t1, const Time &t2)
{
    return (t1.second == t2.second);
}
bool operator!=(const Time &t1, const Time &t2)
{
    return (t1.second != t2.second);
}
bool operator<(const Time &t1, const Time &t2)
{
    return (t1.second < t2.second);
}
bool operator<=(const Time &t1, const Time &t2)
{
    return (t1.second <= t2.second);
}
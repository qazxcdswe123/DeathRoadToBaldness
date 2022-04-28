#include <stdexcept>

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
    --second;
    return *this;
}

const Time Time::operator--(int dummy)
{
    Time old(*this);
    --second;
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
    os << t.second;
    return os;
}

bool operator>(const Time &t1, const Time &t2)
{
}

bool operator>=(const Time &t1, const Time &t2);
bool operator==(const Time &t1, const Time &t2);
bool operator!=(const Time &t1, const Time &t2);
bool operator<(const Time &t1, const Time &t2);
bool operator<=(const Time &t1, const Time &t2);
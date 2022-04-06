#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

struct Time
{
    int hour, minutes;
    double second;

    void Time::print();
    void Time::increment(double secs);
};

void Time::increment(double secs)
{
    second += secs;

    while (second >= 60.0)
    {
        second -= 60.0;
        minute += 1;
    }
    
    while (minute >= 60)
    {
        minute -= 60;
        hour += 1;
    }
    
}

void Time::print()
{
    Time time = *this;
    cout << time.hour << ':' << time.minutes << ':' << time.second << endl;
}


int main()
{
    Time currentTime = {9, 14, 30.0};
    currentTime.print();
}

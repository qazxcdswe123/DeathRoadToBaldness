/* 1、定义一个时间类Time，通过运算符重载实现时间的比较(关系运算)、时间增加/减少若干秒(+=和-=)、时间增加/减少1秒(++和--)、计算两个时间相差的秒数(-)以及输出时间对象的值(时—分—秒)。*/

#ifndef TIME_H
#define TIME_H

# include <iostream>

class Time {
private:
	friend int operator-(const Time &t1, const Time &t2);
	friend std::ostream &operator<<(std::ostream &os, const Time &t);
	friend bool operator>(const Time &t1, const Time &t2);
	friend bool operator>=(const Time &t1, const Time &t2);
	friend bool operator==(const Time &t1, const Time &t2);
	friend bool operator!=(const Time &t1, const Time &t2);
	friend bool operator<(const Time &t1, const Time &t2);
	friend bool operator<=(const Time &t1, const Time &t2);
	int second;

public:
	Time(int ss = 0);

	Time &operator++();// 前缀++

	Time operator++(int x);// 后缀++

	Time &operator--(); // 前缀--

	Time operator--(int x); // 后缀--

	Time &operator+=(const Time &other);

	Time &operator-=(const Time &other);
};

#endif

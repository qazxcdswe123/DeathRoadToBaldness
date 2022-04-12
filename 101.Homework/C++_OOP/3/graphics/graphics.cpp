#include "graphics.h"

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}

Line::Line(const Point & p1, const Point & p2 ) : p1(p1), p2(p2) {}

Triangle::Triangle(const Line &l1, const Line &l2, const Line &l3) 
	: l1(l1), l2(l2), l3(l3) {}

// copy constructor
Point::Point(const Point &p) : x(p.x), y(p.y) {}

Line::Line(const Line &l) : p1(l.p1), p2(l.p2) {}

Triangle::Triangle(const Triangle &t) : l1(t.l1), l2(t.l2), l3(t.l3) {}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

Point Line::getP1() const
{
	return this->p1;
}

Point Line::getP2() const
{
	return this->p2;
}

Line Triangle::getL1() const
{
	return this->l1;
}

Line Triangle::getL2() const
{
	return this->l2;
}

Line Triangle::getL3() const
{
	return this->l3;
}

double Line::getLength() const
{
	return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
}

bool Triangle::isTriangle() const 
{
	double l1 = this->l1.getLength();
	double l2 = this->l2.getLength();
	double l3 = this->l3.getLength();
	if (l1 + l2 > l3 && l1 + l3 > l2 && l2 + l3 > l1)
		return true;
	else
		return false;
}

double Triangle::getArea() const
{
	// Heron's formula
	double s = (this->l1.getLength() + this->l2.getLength() + this->l3.getLength()) / 2;
	return sqrt(s * (s - this->l1.getLength()) \
			* (s - this->l2.getLength() ) \
			* (s - this->l3.getLength() ) );
}

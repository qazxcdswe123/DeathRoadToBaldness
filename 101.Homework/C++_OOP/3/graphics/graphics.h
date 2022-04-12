// 建立一个Point类，表示平面中的一个点；建立一个Line类，表示平面中的一条线端，内含两个Point类的对象；建立Triangle类，表示一个三角形，内含三个Line类的对象构成一个三角形。
// 设计三个类的相应的构造函数、复制构造函数，完成初始化和对象复制
// 设计Triangle类的成员函数完成三条边是否能构成三角形的检验和三角形面积计算，面积显示。

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
	double x, y;
public:
	Point();
	Point(double x, double y);
	Point(const Point & rhs); // copy constructor
	double getX() const;
	double getY() const;
};

class Line
{
private:
	Point p1, p2;
public:
	Line(const Point & p1, const Point & p2);
	Line(const Line & rhs); // copy constructor
	Point getP1() const;
	Point getP2() const;
	double getLength() const;
};

class Triangle
{
private:
	Line l1, l2, l3;
public:
	Triangle(const Line & l1, const Line & l2, const Line & l3);
	Triangle(const Triangle & rhs); // copy constructor
	Line getL1() const;
	Line getL2() const;
	Line getL3() const;
	bool isTriangle() const;
	double getArea() const;
};

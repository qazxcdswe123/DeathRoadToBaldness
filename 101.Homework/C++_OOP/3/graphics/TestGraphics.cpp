#include "graphics.h"

int main()
{
	// Test isTriangle False
	Point p1(1, 2);
	Point p2(3, 4);
	Line l1(p1, p2);
	Point p3(2, 3);
	Line l2(p2, p3);
	Line l3(p3, p1); 
	Triangle t1(l1, l2, l3); // Should be false
	if (t1.isTriangle())
	{
		cout << "t1 is a triangle" << endl;
		cout << "t1 has area " << t1.getArea() << endl;
	}
	else
		cout << "t1 is not a triangle" << endl;

	// Test isTriangle True
	Point p4(8, 2);
	Point p5(3, 3);
	Line l4(p4, p5);
	Line l5(p1, p4);
	Triangle t2(l1, l4, l5); // Should be true
	if (t2.isTriangle())
	{
		cout << "t2 is a triangle" << endl;
		cout << "t2 has area " << t2.getArea() << endl;
	}
	else
		cout << "t2 is not a triangle" << endl;
}


#include "Rectangle.h"
#include "Circle.h"
#include "Square.h"
#include <iostream>

using namespace std;

int main(void)
{
    Rectangle r1(10, 20);
    Circle c1(5);
    Square s1(10);

    cout << "Rectangle r1 width: " << r1.getWidth() << endl;
    cout << "Rectangle r1 height: " << r1.getHeight() << endl;
    cout << "Area of Rectangle r1: " << r1.getArea() << endl;

    cout << endl;

    cout << "Circle c1 radius: " << c1.getRadius() << endl;
    cout << "Area of Circle c1: " << c1.getArea() << endl;
    cout << endl;

    cout << "Square s1 side: " << s1.getSide() << endl;
    cout << "Area of Square s1: " << s1.getArea() << endl;
    cout << endl;

    cout << "Now change the width of r1 to 20 and height to 30" << endl;
    r1.setWidth(20);
    r1.setHeight(30);
    cout << "Area of Rectangle r1: " << r1.getArea() << endl;
}
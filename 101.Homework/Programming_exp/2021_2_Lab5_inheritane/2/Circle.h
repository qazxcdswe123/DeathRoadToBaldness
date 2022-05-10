#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
private:
    int radius;

public:
    Circle(int r);
    virtual ~Circle() = default;
    int getRadius() const;
    void setRadius(int r);
};

Circle::Circle(int r)
{
    radius = r;
    Shape::setArea(3.14 * radius * radius);
}

int Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(int r)
{
    radius = r;
    Shape::setArea(3.14 * radius * radius);
}

#endif
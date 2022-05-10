#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    int radius;

public:
    Circle(int r);
    virtual ~Circle() = default;
    int getRadius() const;
    double getArea() const;
};

Circle::Circle(int r) : radius(r)
{
}

int Circle::getRadius() const
{
    return radius;
}

double Circle::getArea() const
{
    return 3.14 * radius * radius;
}

#endif
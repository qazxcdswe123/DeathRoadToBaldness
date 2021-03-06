#ifndef SHAPE_H
#define SHAPE_H

class Shape
{
private:
    int area;

public:
    Shape() = default;
    virtual ~Shape() = default;
    int getArea() const; // realized that I can make this virtual
    void setArea(int a);
};

int Shape::getArea() const
{
    return area;
}

void Shape::setArea(int a)
{
    area = a;
}

#endif
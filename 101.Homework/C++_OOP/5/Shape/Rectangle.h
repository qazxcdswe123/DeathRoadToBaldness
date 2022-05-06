#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
private:
    int width;
    int height;

public:
    Rectangle(int w, int h);
    virtual ~Rectangle() = default;
    int getWidth() const;
    int getHeight() const;
    void setWidth(int w);
    void setHeight(int h);
};

Rectangle::Rectangle(int w, int h)
{
    width = w;
    height = h;
    Shape::setArea(width * height);
}

int Rectangle::getWidth() const
{
    return width;
}

int Rectangle::getHeight() const
{
    return height;
}

void Rectangle::setWidth(int w)
{
    width = w;
    Shape::setArea(width * height);
}

void Rectangle::setHeight(int h)
{
    height = h;
    Shape::setArea(width * height);
}
#endif
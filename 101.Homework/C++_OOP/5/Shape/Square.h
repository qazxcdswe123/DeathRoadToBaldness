#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
private:
    int side;

public:
    Square(int s);
    virtual ~Square() = default;
    int getSide() const;
    void setSide(int s);
};

Square::Square(int s) : Rectangle(s, s)
{
    side = s;
    Shape::setArea(side * side);
}

int Square::getSide() const
{
    return side;
}

void Square::setSide(int s)
{
    side = s;
    Shape::setArea(side * side);
}

#endif
#ifndef ROUNDTABLE_H
#define ROUNDTABLE_H

#include "Table.h"
#include "Circle.h"
#include <string>
#include <iostream>

class RoundTable : public Table, public Circle
{
private:
    std::string color;

public:
    RoundTable(int h, int r, std::string c);
    virtual ~RoundTable() = default;
    void print() const;
};

RoundTable::RoundTable(int h, int r, std::string c) : Table(h), Circle(r), color(c)
{
}

void RoundTable::print() const
{
    std::cout << "The Height of the RoundTable is " << getHeight() << std::endl;
    std::cout << "The Radius of the RoundTable is " << getRadius() << std::endl;
    std::cout << "The Area of the RoundTable is " << getArea() << std::endl;
    std::cout << "The Color of the RoundTable is " << color << std::endl;
}

#endif
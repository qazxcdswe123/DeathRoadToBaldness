#ifndef MAMMAL_H
#define MAMMAL_H

#include <iostream>

class Mammal
{
public:
    Mammal();
    virtual ~Mammal();
};

Mammal::Mammal()
{
    std::cout << "Mammal constructor called" << std::endl;
}

Mammal::~Mammal()
{
    std::cout << "Mammal destructor called" << std::endl;
}

#endif
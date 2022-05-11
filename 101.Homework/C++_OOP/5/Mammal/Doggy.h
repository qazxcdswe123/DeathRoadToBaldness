// Test the derived class of derived class

#ifndef DOGGY_H
#define DOGGY_H

#include "Dog.h"
#include <iostream>

class Doggy : public Dog
{
public:
    Doggy();
    virtual ~Doggy();
};

Doggy::Doggy() : Dog()
{
    std::cout << "Doggy constructor called" << std::endl;
}

Doggy::~Doggy()
{
    std::cout << "Doggy destructor called" << std::endl;
}

#endif // DOGGY_H
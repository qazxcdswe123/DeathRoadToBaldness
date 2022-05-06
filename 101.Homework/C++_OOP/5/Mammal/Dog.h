#include "Mammal.h"

class Dog : public Mammal
{
public:
    Dog();
    virtual ~Dog();
};

Dog::Dog() : Mammal()
{
    std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

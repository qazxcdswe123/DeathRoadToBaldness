#include <iostream>

class BaseRun
{
public:
    BaseRun() = default;
    virtual ~BaseRun() = default;
    virtual void run();
};

void BaseRun::run()
{
    std::cout << "\n…………class BaseRun::Run()……\n";
}

class DogRun : public BaseRun
{
public:
    DogRun() = default;
    virtual ~DogRun() = default;
    void run() final override;
};

void DogRun::run()
{
    std::cout << "\n…………class DogRun::Run()……\n";
}

class CarRun : public BaseRun
{
public:
    CarRun() = default;
    virtual ~CarRun() = default;
    void run() final override;
};

void CarRun::run()
{
    std::cout << "\n…………class CarRun::Run()……\n";
}

class DogRun : public BaseRun
{
public:
    DogRun() = default;
    virtual ~DogRun() = default;
    void run() final override;
};

void DogRun::run()
{
    std::cout << "\n…………class DogRun::Run()……\n";
}
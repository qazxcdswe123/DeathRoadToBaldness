/*
2．BaseRun类定义如下：
  class BaseRun
  { public:
    void Run(){cout<<〝\n…………class BaseRun::Run()……\n〞;}
};
定义DogRun,CarRun和PeopleRun类，都继承自BaseRun类，并重载Run()函数，使各类中的Run()函数分别输出不同的内容。
3．将BaseRun:: Run()函数声明成虚函数，用基类指针分别指向派生类对象，并通过基类指针调用派生类对象的Run()函数，体会继承中的多态性。
*/
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

class PeopleRun : public BaseRun
{
public:
    PeopleRun() = default;
    virtual ~PeopleRun() = default;
    void run() final override;
};

void PeopleRun::run()
{
    std::cout << "\n…………class PeopleRun::Run()……\n";
}
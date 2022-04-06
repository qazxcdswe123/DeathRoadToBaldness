#include <iostream>

using namespace std;

class test
{
private:
    int a;

public:
    test(int a = 10);
    ~test();
};

test::test(int a)
{
    this->a = a;
}

test::~test()
{
}

int main()
{
    test t1[5];
    // test t2(20);
    return 0;
}
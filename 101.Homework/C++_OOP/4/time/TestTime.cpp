#include "Time.h"

int main()
{
    Time t1(1651314549);
    std::cout << t1 << std::endl;
    t1++;
    std::cout << t1 << std::endl;
    t1--;
    std::cout << t1 << std::endl;
    --t1;
    std::cout << t1 << std::endl;
    ++t1;
    std::cout << t1 << std::endl;
    -- --t1;
    std::cout << t1 << std::endl;
    ++ ++t1;
    std::cout << t1 << std::endl;
    // t1-- --; error cuz const

    Time t2(111);
    t1 -= t2;
    std::cout << t1 << std::endl;
    t1 += t2;
    std::cout << t1 << std::endl;
    t2 -= t1; // error
    int diff = t2 - t1;
    std::cout << "The time difference of t1 and t2 is " << diff << std::endl;

    Time t3(0);
    --t3;
    t3--;
    std::cout << t1 << std::endl;
    std::cout << t2 << std::endl;
    std::cout << t3 << std::endl;

    // Test operator
    if (t1 > t2)
    {
        std::cout << "t1 > t2" << std::endl;
    }
    else if (t1 < t2)
    {
        std::cout << "t1 < t2" << std::endl;
    }
    else
    {
        std::cout << "t1 == t2" << std::endl;
    }

    Time t4 = t1;
    if (t1 == t4)
    {
        std::cout << "t1 == t4" << std::endl;
    }
    else if (t1 != t4)
    {
        std::cout << "t1 != t4" << std::endl;
    }
}
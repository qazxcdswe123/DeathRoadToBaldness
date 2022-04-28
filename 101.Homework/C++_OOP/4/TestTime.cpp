#include "Time.h"

int main()
{
    Time t1(122313123);
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
    std::cout << "The time difference is " << diff << std::endl;
}
#include "String.h"

int main()
{
    String s1("1c23");
    String s2(s1);
    String s3 = s2;
    std::cout << s1 << s2;
    std::cout << s1[0] << std::endl;
    std::cout << s3;
    std::cout << s3(1, 2);
    std::cout << s3(2, 1);
    std::cin >> s3;
    std::cout << s3;

    if (s1 > s2)
    {
        std::cout << "s1 > s2" << std::endl;
    }
    else if (s1 >= s2)
    {
        std::cout << "s1 >= s2" << std::endl;
    }

    if (s1 == s2)
    {
        std::cout << "s1 == s2" << std::endl;
    }

    if (s1 != s3)
    {
        std::cout << "s1 != s3" << std::endl;
    }

    if (s1 < s3)
    {
        std::cout << "s1 < s3" << std::endl;
    }
    else if (s1 <= s3)
    {
        std::cout << "s1 <= s3" << std::endl;
    }
}
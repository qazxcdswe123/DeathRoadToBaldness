// 6) 在下面程序中的空格中填入适当内容，使得运行结果是A+B=9 。
// _________________
#include <iostream>
int a = 5;
int b = 7;
int plus(int, int);
int main()
{
    int a = 1, b = 8;
    int c = plus(a, b);
    std::cout << "A+B=" << c << std::endl;
}
int plus(int x, int y)
{
    int z;
    z = x + y;
    return z;
}

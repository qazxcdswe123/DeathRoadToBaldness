// 10) 从键盘上输入五个整数分别存放到变量a，b，c，d，e中，将这五个数按升序排列并且输出。
//  将a，b，c，d，e进行升序排列的算法可以用：
//    从a，b，c，d，e中找出最小值，用对调法使其置于变量a；
//    从b，c，d，e中找出最小值，用对调法使其置于变量b；
//    从c，d，e中找出最小值，用对调法使其置于变量c；
//    从d，e中找出最小值，用对调法使其置于变量d；
//  输入输出时均需加上提示信息，才能在运行程序时有清晰的说明。
#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d, e;
    cout << "Please input five integer: ";
    cin >> a >> b >> c >> d >> e;
    cout << "The original order is: " << a << " " << b << " " << c << " " << d << " " << e << endl;
    int temp;
    if (a > b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if (a > c)
    {
        temp = a;
        a = c;
        c = temp;
    }
    if (a > d)
    {
        temp = a;
        a = d;
        d = temp;
    }
    if (a > e)
    {
        temp = a;
        a = e;
        e = temp;
    }
    if (b > c)
    {
        temp = b;
        b = c;
        c = temp;
    }
    if (b > d)
    {
        temp = b;
        b = d;
        d = temp;
    }
    if (b > e)
    {
        temp = b;
        b = e;
        e = temp;
    }
    if (c > d)
    {
        temp = c;
        c = d;
        d = temp;
    }
    if (c > e)
    {
        temp = c;
        c = e;
        e = temp;
    }
    if (d > e)
    {
        temp = d;
        d = e;
        e = temp;
    }
    cout << "The new order is: " << a << " " << b << " " << c << " " << d << " " << e << endl;
    return 0;
}
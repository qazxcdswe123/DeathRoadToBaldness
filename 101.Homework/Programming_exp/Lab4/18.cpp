/*16) 编写程序：判别一个输入的整数数组中各元素的值，若大于0 则输出该值，若小于等于0则输出0。
实验指导：本程序中可先定义一个无返回值函数用以判断各元素的值，并说明其形参为整型变量，在函数体中根据形参的值输出相应的结果。在main函数中定义一个有若干元素的数组，用循环控制语句输入数组各元素，每输入一个就以该元素作实参调用一次函数，即把元素的值传送给形参，供函数使用。
*/

#include <iostream>
using namespace std;

void solve(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (array[i] > 0)
        {
            cout << array[i] << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
}

int main()
{
    int array[10] = {100, 200, -9, 1, -2, -3, -4, -5, -6, 0};
    solve(array, 10);
}

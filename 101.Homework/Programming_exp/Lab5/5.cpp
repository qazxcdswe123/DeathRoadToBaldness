// 4) 输入4个人的成绩组成一个数组, 然后输出其总和。有人编出如下的程序：
// 按照编程序的人原来的设计目的, 是能够输入4个人的成绩, 其过程如下 : 请输入第1个人的成绩 : 90 请输入第2个人的成绩 : 70 请输入第3个人的成绩 : 60 请输入第4个人的成绩 : 80 sum = 300 但是实际运行时, 其过程是 : 请输入第0个人的成绩 : 90 请输入第2个人的成绩 : 70 sum = 150 请阅读分析以上的程序, 找出其中的错误并改正。

#include <iostream>
using namespace std;
int main()
{
    int i, a[4], sum = 0;
    for (i = 0; i < 4; i++)
    {
        cout << "请输入第" << i + 1 << "个人的成绩: ";
        cin >> a[i];
        sum = sum + a[i];
    }
    cout << "sum=" << sum;
}

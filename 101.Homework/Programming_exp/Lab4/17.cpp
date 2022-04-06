// 14) 鸡兔同笼, 鸡和兔的头共有h个，腿共有g条。输入h和g，用循环结构求出鸡兔各多少只？
#include <iostream>
using namespace std;

// 鸡兔同笼函数
void jitongchonglang(int h, int g)
{
    int j = 0, t = 0;
    for (int i = 1; i <= h; i++)
    {
        if (i % 2 == 0)
        {
            j++;
        }
        else
        {
            t++;
        }
    }
    cout << "鸡兔同笼：" << j << "只鸡，" << t << "只兔。" << endl;
}

int main()
{
    int h, g;
    cout << "请输入鸡兔同笼的头数和腿数：" << endl;
    cin >> h >> g;
    jitongchonglang(h, g);
    return 0;
}
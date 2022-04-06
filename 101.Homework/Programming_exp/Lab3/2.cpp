#include <iostream>
#include <iomanip> //控制输出格式的控制符在此头文件中定义
using namespace std;

int main()
{
    double c, f;
    cout << "请输入摄氏温度：";
    cin >> c;
    f = 9.0 * c / 5 + 32;
    cout << setiosflags(ios::fixed) << setprecision(2);
    //设置小数形式输出，2位小数
    cout << "华氏温度为：" << f << endl;
}
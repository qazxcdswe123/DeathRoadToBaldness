#include <iostream>
using namespace std;

int main(void)
{
    double money, ans;
    cout << "请输入购物金额：";
    cin >> money;
    cout << "折扣率：";
    if (money < 100)
    {
        cout << "不打折 ";
        ans = money;
    }
    else if (money < 300)
    {
        cout << "9折 ";
        ans = money * 0.9;
    }
    else if (money < 500)
    {
        cout << "8.5折 ";
        ans = money * 0.85;
    }
    else
    {
        cout << "8折 ";
        ans = money * 0.8;
    }
    cout << "应付金额：";
    printf("%.2lf\n", ans);
}
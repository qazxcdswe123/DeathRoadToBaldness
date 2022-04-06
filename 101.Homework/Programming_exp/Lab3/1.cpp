#include <iostream>
using namespace std;

int main()
{
    double r, s, v;
    double pi = 3.14;
    cout << "input r:"; /*输入球的半径*/
    cin >> r;
    s = 4.0 * pi * r * r;             /*计算球体的表面积*/
    v = 4.0 * pi * r * r * r / 3.0; /*计算球体的体积*/
    cout << "r = " << r << endl;
    cout << "s = " << s << ",v = " << v << endl;
}
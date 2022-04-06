#include <iostream>
using namespace std;

int main(void)
{
    double x, ans;
    cout << "x = ";
    cin >> x;
    if (x < 0)
    {
        ans = x + 1;
    }
    else if (x < 1)
    {
        ans = 1;
    }
    else
    {
        ans = -x + 1;
    }
    cout << "x = " << x << " f(x)= " << ans << endl;
}
#include <iostream>
using namespace std;

int main(void)
{
    cout << "100-1000各位数上和是5的数为：";
    for (int i = 100; i <= 1000; i++)
    {
        int x = i, sum = 0;
        while (x != 0)
        {
            sum += x % 10;
            x /= 10;
        }
        if (sum == 5)
        {
            cout << i << ' ';
        }
    }
    cout << endl;
}
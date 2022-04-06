#include <iostream>

using namespace std;

class Ratio
{
    int num;
    int den;

public:
    Ratio()
    {
        num = 0;
        den = 1;
    }
    Ratio(int n)
    {
        num = n;
        den = 1;
    }
    Ratio(int n, int d)
    {
        num = n;
        den = d;
    }
    void disp()
    {
        cout << "num/den=" << num / den << endl;
    }
};

int main()
{
    Ratio r1(1, 2);
    Ratio r2 = Ratio();
    Ratio r3(3);
    r1.disp();
    r2.disp();
    r3.disp();
}
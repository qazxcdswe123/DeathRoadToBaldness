#include <iostream>

using namespace std;

class ratio2
{
    int num;
    int den;

public:
    ratio2(int num = 2, int den = 1)
    {
        this->num = num;
        this->den = den;
    }

    void disp()
    {
        cout << "num/den=" << num / den << endl;
    }

    // copy constructor
    ratio2(const ratio2 &r)
    {
        num = r.num;
        den = r.den;
    }
};

int main()
{
    ratio2 r1 = ratio2();
    r1.disp();
    ratio2 r2 = ratio2(r1);
    r2.disp();
}
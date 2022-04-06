#include "iostream"
using namespace std;

int main()
{
    for (int i = 100; i <= 200; i++)
    {
        if (i % 4 == 2 && i % 7 == 3 && i % 9 == 5)
        {
            cout << i << endl;
        }
    }
}
#include <iostream>
using namespace std;

// a function to print every digit reversely
void reversePrinting(int n)
{
    if (n == 0)
        return;
    cout << n % 10;

    reversePrinting(n / 10);
}

int main(void)
{
    int num = 114514;
    reversePrinting(num);
}
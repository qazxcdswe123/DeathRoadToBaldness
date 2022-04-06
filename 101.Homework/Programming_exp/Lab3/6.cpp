#include <iostream>
using namespace std;

int main(void)
{
    int num;
    cin >> num;
    for (int i = 0; i < 5; i++)
    {
        cout << "The " << i + 1 << "th digit is " << num % 10 << endl;
        num /= 10;
    }
}
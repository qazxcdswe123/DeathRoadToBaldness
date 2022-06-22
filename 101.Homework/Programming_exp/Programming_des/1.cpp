#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

void swapPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap()
{
    int a, b;
    cout << "(swap)" << endl;
    cout << "Plz input the 2 integer: ";
    cin >> a >> b;
    cout << "Current numbers are: ";
    cout << a << " and " << b << endl;
    swapPointer(&a, &b);
    cout << "After swapping, the numbers are: ";
    cout << a << " and " << b << endl;
}

void average()
{
    int a, b;
    cout << "(average)" << endl;
    cout << "Plz input the 2 integer: ";
    cin >> a >> b;

    float ans = (a + b) / 2.0;
    cout << "The average is: ";
    cout << ans << endl;
}

void bankInterest()
{
    int years;
    double money;
    cout << "(bankInterest)" << endl;
    cout << "Enter your principal: ";
    cin >> money;

    for (int i = 0; i < 3; i++)
    {
        money = money + 0.033 * money;
    }

    cout << "The money you will get is: ";
    cout << money << endl;
}

void volumeOfBall()
{
    cout << "(volumeOfBall)" << endl;
    double r, v;
    cout << "Gime the radius of the ball: ";
    cin >> r;
    v = PI * pow(r, 3.0) * 4.0 / 3.0;
    cout << "The volume of the ball is " << v << endl;
}

void reversePrint()
{
    cout << "(reversePrint)" << endl;
    int num, renum = 0, length = 0, last;
    cout << "Gime the number: ";
    cin >> num;

    int cpnum = num;
    while (cpnum != 0)
    {
        cpnum /= 10;
        length++;
    }

    while (length--)
    {
        last = num % 10;
        cout << last;
        num /= 10;
    }
    cout << "\n";
}

int main()
{
    average();
    swap();
    bankInterest();
    volumeOfBall();
    reversePrint();
    return 0;
}

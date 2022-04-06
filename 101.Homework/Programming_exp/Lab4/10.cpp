// 7) 以下程序的功能是根据输入的"y"("Y")与"n"("N")，
// 在屏幕上分别显示出"This is YES."与"This is NO."。请填空，进行上机验证。
#include <iostream>
using namespace std;
void YesNo(char ch)
{
    switch (ch)
    {
    case 'y':
    case 'Y':
        cout << "\nThis is YES.\n";
        break;
    case 'n':
    case 'N':
        cout << "\nThis is NO.\n";
    }
}

int main()
{
    char ch;
    cout << "Enter a char 'y', 'Y' or 'n', 'N' : ";
    cin >> ch;
    YesNo(ch);
}

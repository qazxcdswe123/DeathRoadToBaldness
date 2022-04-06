#include <iostream>
using namespace std; //程序的功能是输出字母A到Z

int main(void)
{
    char c = 'A';
    while (c <= 'Z')
    {
        cout << c;
        c++;
    }
    cout << endl;
}
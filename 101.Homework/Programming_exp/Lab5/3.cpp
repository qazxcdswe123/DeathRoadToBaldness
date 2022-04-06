#include <iostream>
using namespace std;
int main()
{
    char *p, s[] = "ABCDEFG";
    for (p = s; *p != '\0'; p++)
        cout << p << endl;
}

#include <iostream>
using namespace std;
int main()
{
    int a[10] = {3, 2, 6, 8, 7, 4, 5, 10, 12, 11};
    int sum = 0, i;
    for (i = 0; (i < 10) && (a[i] % 2 == 0); i++)
    {
        sum = sum + a[i];
    }
    cout << "sum=" << sum << endl;
}
// #include <iostream>
// using namespace std;
// int main()
// {
//     int a[10] = {3, 2, 6, 8, 7, 4, 5, 10, 12, 11};
//     int sum = 0, i;
//     for (i = 0; i < 10; i++)
//         if (a[i] % 2 == 0)
//             sum = sum + a[i];
//     cout << "sum=" << sum << endl;
// }

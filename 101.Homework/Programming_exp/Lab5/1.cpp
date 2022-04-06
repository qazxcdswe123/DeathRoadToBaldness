#include <iostream>
using namespace std;
int main()
{
    int array[5];
    // input
    cout << "Enter the originl array:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> array[i];
    }
    cout << endl;
    // output
    for (int i = 0; i < 5; i++)
    {
        cout << array[i] << "   ";
    }
    cout << endl;

    int i, j, k, t, n = 5;
    for (i = 0; i < n - 1; i++)
    {
        k = i;
        for (j = i + 1; j < n; j++)
        {
            if (array[j] < array[k])
            {
                k = j;
            }
        }
        t = array[k];
        array[k] = array[i];
        array[i] = t;
    }

    cout << "The sorted array:\n";
    for (i = 0; i < 5; i++)
        cout << array[i] << "   ";
    cout << endl;
}

#include <iostream>
using namespace std;

int main()
{
    char str[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    enum week
    {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };
    for (int a = Sunday; a <= Saturday; a++)
    {
        for (int b = Sunday; b <= Saturday; b++)
        {
            for (int c = Sunday; c <= Saturday; c++)
            {
                for (int d = Sunday; d <= Saturday; d++)
                {
                    for (int e = Sunday; e <= Saturday; e++)
                    {
                        for (int g = Sunday; g <= Saturday; g++)
                        {
                            int f = Thursday;
                            if ((a == (c + 1) % 7) && (d == (e + 2) % 7) && (g == (b + 3) % 7) && ((f > b) && (f < c) || (f > c) && (f < b)) && (a != b) && (a != c) && (a != d) && (a != e) && (a != f) && (a != g) && (b != c) && (b != d) && (b != e) && (b != f) && (b != g) && (c != d) && (c != e) && (c != f) && (c != g) && (c != e) && (d != e) && (d != f) && (d != g) && (e != f) && (e != g) && (f != g))
                            {
                                cout << "Doctor A is on duty " << str[a] << '.' << endl;
                                cout << "Doctor B is on duty " << str[b] << '.' << endl;
                                cout << "Doctor C is on duty " << str[c] << '.' << endl;
                                cout << "Doctor D is on duty " << str[d] << '.' << endl;
                                cout << "Doctor E is on duty " << str[e] << '.' << endl;
                                cout << "Doctor F is on duty " << str[f] << '.' << endl;
                                cout << "Doctor G is on duty " << str[g] << '.' << endl;
                                cout << endl;
                            }
                        }
                    }
                }
            }
        }
    }
}